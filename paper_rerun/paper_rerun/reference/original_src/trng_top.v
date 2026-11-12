`timescale 1ns / 1ps
// ============================================================================
// trng_top.v  -  Ring-oscillator True Random Number Generator, ASIC-portable
// ----------------------------------------------------------------------------
// Pipeline:
//   RO bank (XOR) -> 2-FF sampler -> RCT + APT health tests
//                                 -> Von Neumann corrector -> byte packer
//                                 -> UART 8N1 -> tx
//
// Differences from the Vivado version:
//   * No Xilinx primitives (FDRE/LUT1/LUT2) and no Xilinx attributes.
//   * RO built from tech-wrapper cells (trng_tech_cells.v); behavioral RO model
//     is selected ONLY by +define+TRNG_BEHAV_SIM (not by `SYNTHESIS).
//   * Reset synchronizer (async assert, sync deassert).
//   * Distinct RO lengths (3,5,7,...), start-up warm-up, RCT + APT (SP 800-90B).
//   * UART: parameterized baud, immediate start bit, byte hand-off with
//     pending/ready handshake instead of a 1-cycle pulse.
//   * Extra pins: health_fail (alarm), dbg_raw_bit / dbg_raw_valid (raw tap).
//
// Verilog-2001 only. No latches, single clock domain except the intentional
// asynchronous RO -> sampler crossing.
// ============================================================================


// ============================================================================
// 1. Ring oscillator cell
// ============================================================================
module trng_ro_cell #(
    parameter integer N  = 3,   // number of inversions, MUST be odd
    parameter integer ID = 0
)(
    input  wire en,
    output wire y
);

`ifdef TRNG_BEHAV_SIM
    // ------------------------------------------------------------------
    // Behavioral model - SIMULATION ONLY. Pseudo-random half-period
    // (2N ns + 0..4 ns). Proves functionality, NOT entropy.
    // ------------------------------------------------------------------
    reg     sim_osc;
    integer seed;
    integer delay_ns;

    initial begin
        sim_osc = ID % 2;
        seed    = 32'h13579BDF + (ID * 7919) + (N * 101);
    end

    always begin
        if (en === 1'b1) begin
            delay_ns = (2 * N) + ({$random(seed)} % 5);
            #(delay_ns);
            if (en === 1'b1)
                sim_osc = ~sim_osc;
        end
        else begin
            sim_osc = 1'b0;
            @(en);
        end
    end

    assign y = sim_osc;

`else
    // ------------------------------------------------------------------
    // Hardware: NAND2 (enable) + (N-1) inverters in a closed loop.
    // N odd -> loop has odd number of inversions -> oscillates when en=1.
    // ------------------------------------------------------------------
    wire [N-1:0] n;

    trng_tech_nand2 u_nand (.a(n[N-1]), .b(en), .y(n[0]));

    genvar i;
    generate
        for (i = 1; i < N; i = i + 1) begin : g_stg
            trng_tech_inv u_inv (.a(n[i-1]), .y(n[i]));
        end
    endgenerate

    assign y = n[N-1];
`endif

endmodule


// ============================================================================
// 2. RO bank + XOR
// ============================================================================
module trng_ro_bank #(
    parameter integer NUM_RO = 8
)(
    input  wire en,
    output wire x
);
    wire [NUM_RO-1:0] ro_y;

    genvar k;
    generate
        for (k = 0; k < NUM_RO; k = k + 1) begin : g_ro
            // distinct odd lengths: 3,5,7,9,11,13,15,17,...
            trng_ro_cell #(.N(3 + 2*k), .ID(k)) u_ro (.en(en), .y(ro_y[k]));
        end
    endgenerate

    assign x = ^ro_y;
endmodule


// ============================================================================
// 3. Reset synchronizer: asynchronous assert, synchronous de-assert
// ============================================================================
module trng_rst_sync (
    input  wire clk,
    input  wire rst_n_in,
    output wire rst_n_out
);
    reg [1:0] sr;
    always @(posedge clk or negedge rst_n_in) begin
        if (!rst_n_in) sr <= 2'b00;
        else           sr <= {sr[0], 1'b1};
    end
    assign rst_n_out = sr[1];
endmodule


// ============================================================================
// 4. Asynchronous-input 2-FF sampler (metastability filter)
//    Constrain in SDC: set_false_path -to u_sampler/s0_reg   (see notes)
// ============================================================================
(* keep_hierarchy *)
module trng_sampler (
    input  wire clk,
    input  wire x,        // asynchronous
    output wire q
);
    reg s0, s1;
    always @(posedge clk) begin
        s0 <= x;
        s1 <= s0;
    end
    assign q = s1;
endmodule


// ============================================================================
// 5. Repetition Count Test (SP 800-90B 4.4.1)
//    C = 1 + ceil(20/H) for alpha = 2^-20.  H=0.5 -> 41, H=1 -> 21.
//    fail is sticky until reset.
// ============================================================================
module trng_rct #(
    parameter integer C = 41     // must be 2..255
)(
    input  wire clk,
    input  wire rst_n,
    input  wire v,
    input  wire b,
    output reg  fail
);
    reg       last;
    reg [7:0] cnt;               // consecutive identical samples (saturating)

    always @(posedge clk) begin
        if (!rst_n) begin
            last <= 1'b0;
            cnt  <= 8'd0;
            fail <= 1'b0;
        end
        else if (v) begin
            if ((cnt != 8'd0) && (b == last)) begin
                if (cnt != 8'hFF)
                    cnt <= cnt + 8'd1;
                if ((cnt + 8'd1) >= C)
                    fail <= 1'b1;
            end
            else begin
                last <= b;
                cnt  <= 8'd1;
            end
        end
    end
endmodule


// ============================================================================
// 6. Adaptive Proportion Test (SP 800-90B 4.4.2, binary, window W)
//    Counts occurrences of the window's first sample; fail when count >= C.
//    W=1024: C = 1 + CRITBINOM(1024, 2^-H, 1-2^-20)  -> H=1: 589, H=0.5: 793.
// ============================================================================
module trng_apt #(
    parameter integer W = 1024,
    parameter integer C = 793
)(
    input  wire clk,
    input  wire rst_n,
    input  wire v,
    input  wire b,
    output reg  fail
);
    reg        ref_bit;
    reg [15:0] cnt;              // occurrences of ref_bit in current window
    reg [15:0] idx;              // samples consumed in current window

    always @(posedge clk) begin
        if (!rst_n) begin
            ref_bit <= 1'b0;
            cnt     <= 16'd0;
            idx     <= 16'd0;
            fail    <= 1'b0;
        end
        else if (v) begin
            if (idx == 16'd0) begin
                ref_bit <= b;
                cnt     <= 16'd1;
                idx     <= 16'd1;
            end
            else begin
                if (b == ref_bit) begin
                    cnt <= cnt + 16'd1;
                    if ((cnt + 16'd1) >= C)
                        fail <= 1'b1;
                end
                if (idx == W-1) idx <= 16'd0;
                else            idx <= idx + 16'd1;
            end
        end
    end
endmodule


// ============================================================================
// 7. Von Neumann corrector  (01 -> 0, 10 -> 1, 00/11 discarded)
// ============================================================================
module trng_vn (
    input  wire clk,
    input  wire rst_n,
    input  wire v,
    input  wire d,
    output reg  ov,
    output reg  o
);
    reg have;
    reg first;

    always @(posedge clk) begin
        ov <= 1'b0;
        if (!rst_n) begin
            have  <= 1'b0;
            first <= 1'b0;
            o     <= 1'b0;
        end
        else if (v) begin
            if (!have) begin
                first <= d;
                have  <= 1'b1;
            end
            else begin
                have <= 1'b0;
                if (first != d) begin
                    o  <= first;
                    ov <= 1'b1;
                end
            end
        end
    end
endmodule


// ============================================================================
// 8. UART transmitter 8N1.  tx_ready is high only when idle.
//    Start bit is driven immediately when tx_en && tx_ready.
// ============================================================================
module trng_uart_tx #(
    parameter integer BAUD_DIV = 868
)(
    input  wire       clk,
    input  wire       rst_n,
    input  wire       tx_en,
    input  wire [7:0] tx_data,
    output reg        tx,
    output wire       tx_ready
);
    reg        busy;
    reg [15:0] clk_cnt;
    reg [3:0]  bit_cnt;          // 0: start bit, 1..8: data, 9: stop
    reg [7:0]  shreg;

    assign tx_ready = ~busy;

    always @(posedge clk) begin
        if (!rst_n) begin
            busy    <= 1'b0;
            clk_cnt <= 16'd0;
            bit_cnt <= 4'd0;
            shreg   <= 8'd0;
            tx      <= 1'b1;
        end
        else if (!busy) begin
            tx <= 1'b1;
            if (tx_en) begin
                shreg   <= tx_data;
                tx      <= 1'b0;              // start bit
                busy    <= 1'b1;
                clk_cnt <= 16'd0;
                bit_cnt <= 4'd0;
            end
        end
        else begin
            if (clk_cnt == BAUD_DIV-1) begin
                clk_cnt <= 16'd0;
                if (bit_cnt < 4'd8) begin     // data bits, LSB first
                    tx      <= shreg[0];
                    shreg   <= {1'b1, shreg[7:1]};
                    bit_cnt <= bit_cnt + 4'd1;
                end
                else if (bit_cnt == 4'd8) begin   // stop bit
                    tx      <= 1'b1;
                    bit_cnt <= 4'd9;
                end
                else begin                        // stop bit finished
                    busy    <= 1'b0;
                    bit_cnt <= 4'd0;
                end
            end
            else begin
                clk_cnt <= clk_cnt + 16'd1;
            end
        end
    end
endmodule


// ============================================================================
// 9. Top level
// ============================================================================
module trng_top #(
    parameter integer NUM_RO        = 8,
    parameter integer SAMP_DIV      = 2000,         // clocks per raw sample
    parameter integer CLK_HZ        = 100_000_000,
    parameter integer BAUD          = 115200,
    parameter integer WARMUP_CYCLES = 256,          // RO settle time after reset
    parameter integer RCT_C         = 41,           // H = 0.5 bit/sample assumed
    parameter integer APT_W         = 1024,
    parameter integer APT_C         = 793           // H = 0.5, alpha = 2^-20
)(
    input  wire clk,
    input  wire rst_n,           // active-low, asynchronous
    output wire tx,              // UART 8N1
    output wire health_fail,     // sticky alarm (RCT or APT), cleared by reset
    output wire dbg_raw_bit,     // raw sampled bit tap (valid with dbg_raw_valid)
    output wire dbg_raw_valid    // 1-clk strobe per raw sample
);

    localparam integer BAUD_DIV = (CLK_HZ + (BAUD/2)) / BAUD;

`ifdef TRNG_BEHAV_SIM
    // byte hand-off can only overrun if 16 raw samples are shorter than a frame
    initial begin
        if ((16 * SAMP_DIV) <= (10 * BAUD_DIV + 2))
            $display("TRNG WARNING: SAMP_DIV=%0d too small for baud; UART bytes may be dropped", SAMP_DIV);
    end
`endif

    // ------------------------------------------------------------------
    // Reset
    // ------------------------------------------------------------------
    wire rst_ns;
    trng_rst_sync u_rst_sync (.clk(clk), .rst_n_in(rst_n), .rst_n_out(rst_ns));

    // ------------------------------------------------------------------
    // Entropy source + sampler
    // ------------------------------------------------------------------
    reg  ro_en;
    wire x;
    wire s;

    trng_ro_bank #(.NUM_RO(NUM_RO)) u_ro_bank (.en(ro_en), .x(x));
    trng_sampler                    u_sampler (.clk(clk), .x(x), .q(s));

    // ------------------------------------------------------------------
    // Warm-up + sampling divider
    // ------------------------------------------------------------------
    reg [31:0] div;
    reg [15:0] warm;
    wire       warm_done = (warm >= WARMUP_CYCLES);

    always @(posedge clk) begin
        if (!rst_ns) begin
            div   <= 32'd0;
            warm  <= 16'd0;
            ro_en <= 1'b0;
        end
        else begin
            ro_en <= 1'b1;
            if (!warm_done)
                warm <= warm + 16'd1;
            if ((SAMP_DIV <= 1) || (div == SAMP_DIV-1))
                div <= 32'd0;
            else
                div <= div + 32'd1;
        end
    end

    wire raw_valid = warm_done & ((SAMP_DIV <= 1) | (div == SAMP_DIV-1));
    wire raw_bit   = s;

    // registered debug tap (bit and strobe aligned)
    reg dbg_bit_q, dbg_val_q;
    always @(posedge clk) begin
        if (!rst_ns) begin
            dbg_bit_q <= 1'b0;
            dbg_val_q <= 1'b0;
        end
        else begin
            dbg_bit_q <= raw_bit;
            dbg_val_q <= raw_valid;
        end
    end
    assign dbg_raw_bit   = dbg_bit_q;
    assign dbg_raw_valid = dbg_val_q;

    // ------------------------------------------------------------------
    // Health tests + corrector
    // ------------------------------------------------------------------
    wire rct_fail, apt_fail;
    assign health_fail = rct_fail | apt_fail;

    trng_rct #(.C(RCT_C))           u_rct (.clk(clk), .rst_n(rst_ns), .v(raw_valid), .b(raw_bit), .fail(rct_fail));
    trng_apt #(.W(APT_W), .C(APT_C)) u_apt (.clk(clk), .rst_n(rst_ns), .v(raw_valid), .b(raw_bit), .fail(apt_fail));

    wire bit_valid, bit_out;
    trng_vn u_vn (.clk(clk), .rst_n(rst_ns), .v(raw_valid), .d(raw_bit), .ov(bit_valid), .o(bit_out));

    // ------------------------------------------------------------------
    // Byte packer (LSB first) with pending/ready hand-off to UART
    // ------------------------------------------------------------------
    reg [6:0] byte_reg;
    reg [2:0] bit_idx;
    reg [7:0] tx_data;
    reg       tx_pending;
    wire      tx_ready;
    wire      tx_start = tx_pending & tx_ready;

    always @(posedge clk) begin
        if (!rst_ns) begin
            byte_reg   <= 7'd0;
            bit_idx    <= 3'd0;
            tx_data    <= 8'd0;
            tx_pending <= 1'b0;
        end
        else begin
            if (tx_start)
                tx_pending <= 1'b0;

            if (bit_valid && !health_fail) begin
                if (bit_idx == 3'd7) begin
                    bit_idx  <= 3'd0;
                    byte_reg <= 7'd0;
                    // A completed byte is dropped only if the previous one is
                    // still waiting; impossible for 16*SAMP_DIV > 10*BAUD_DIV.
                    if (!(tx_pending && !tx_start)) begin
                        tx_data    <= {bit_out, byte_reg};
                        tx_pending <= 1'b1;
                    end
                end
                else begin
                    byte_reg[bit_idx] <= bit_out;
                    bit_idx           <= bit_idx + 3'd1;
                end
            end
        end
    end

    trng_uart_tx #(.BAUD_DIV(BAUD_DIV)) u_uart (
        .clk      (clk),
        .rst_n    (rst_ns),
        .tx_en    (tx_start),
        .tx_data  (tx_data),
        .tx       (tx),
        .tx_ready (tx_ready)
    );

endmodule
