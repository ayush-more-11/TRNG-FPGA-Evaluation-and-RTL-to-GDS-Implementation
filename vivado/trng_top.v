`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09.10.2026 11:36:22
// Design Name: 
// Module Name: trng_top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


// ============================================================================
// 1. Ring Oscillator Cell
// ============================================================================
module ro_cell #(
    parameter integer N  = 3,  //odd number of inverters in a closed loop
    parameter integer ID = 0
)(
    input  wire en,
    output wire y
);

`ifndef SYNTHESIS // For Simulation Only

    reg     sim_osc; //stores the simulated output, either 0 or 1
    integer seed; //initializes the pseudorandom delay sequence
    integer delay_ns; //stores the delay before the output toggles

    initial begin
        sim_osc = ID % 2;
        seed = 32'h13579BDF + (ID * 7919) + (N * 101);
    end

    always begin
        if (!en) begin
            sim_osc = 1'b0;
            @(posedge en);
        end
        else begin
            delay_ns = (2 * N)
                     + (($random(seed) & 32'h7FFFFFFF) % 5); //The code calculates a delay, waits, and then flips the output:

            #(delay_ns);

            if (en)
                sim_osc = ~sim_osc;
        end
    end

    assign y = sim_osc;

`else
    // ------------------------------------------------------------------------
    // Synthesized hardware model
    // ------------------------------------------------------------------------
    (* KEEP = "TRUE", DONT_TOUCH = "TRUE", ALLOW_COMBINATORIAL_LOOPS = "TRUE" *) //The attributes tell Vivado to preserve the relevant logic and permit the intentional combinational feedback loop.
    wire [N-1:0] n;

    // LUT is configured to behave as a NAND gate
    LUT2 #(.INIT(4'b0111)) u0 (
        .O  (n[0]),
        .I0 (n[N-1]),
        .I1 (en)
    );

    genvar i;
    generate
        for (i = 1; i < N; i = i + 1) begin : stg
            LUT1 #(.INIT(2'b01)) u_inv (
                .O  (n[i]),
                .I0 (n[i-1])
            );
        end
    endgenerate

    assign y = n[N-1];
`endif

endmodule


// ============================================================================
// 2. Repetition Count Test
// ============================================================================
module rct #(
    parameter integer C = 41
)(
    input  wire clk, // The clock that controls when the test checks a bit
    input  wire rst_n, // Active-low reset. When it is 0, the test resets
    input  wire v, // Says whether a new bit is valid and ready to be checked
    input  wire b, // The actual bit being checked: 0 or 1
    output reg  fail // Becomes 1 when too many identical bits appear consecutively
);
    reg last; // stores the previous bit value
    reg [7:0] cnt;

    always @(posedge clk) begin
        if (!rst_n) begin
            last <= 1'b0;
            cnt  <= 8'd0;
            fail <= 1'b0;
        end
        else if (v) begin
            if ((cnt == 0) || (b != last)) begin
                last <= b;
                cnt  <= 8'd1;
            end
            else begin
                last <= last;
                if (cnt < C)
                    cnt <= cnt + 1'b1;

                if (cnt >= C-1)
                    fail <= 1'b1;
            end
        end
    end
endmodule


// ============================================================================
// 3. Von Neumann Corrector
// ============================================================================
module vn_corrector (
    input  wire clk,
    input  wire rst_n,
    input  wire v,
    input  wire d, // Incoming raw bit from the TRNG
    output reg  ov, // Output-valid signal. Becomes 1 when a corrected bit is produced
    output reg  o // The corrected output bit
);
    reg have;
    // have = 0: No first bit is waiting; the next valid bit will be stored
    // have = 1: The first bit has been stored; the next valid bit completes the pair
    reg first; // stores the first bit of a pair

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
// 4. UART Transmitter - 8N1
// ============================================================================
// 100 MHz clock / 115200 baud = 868.055...
// Integer divider 868 gives about 115207 baud.
// ============================================================================
module uart_tx #(
    parameter integer BAUD_DIV = 868
)(
    input  wire       clk,
    input  wire       rst_n,
    input  wire       tx_en,
    input  wire [7:0] tx_data,
    output reg        tx,
    output reg        tx_ready
);
    reg [15:0] clk_count;
    reg [3:0]  bit_count; // Counts the 10 transmitted frame bits: 1 start bit, 8 data bits and 1 stop bit.
    reg [9:0]  shift_reg; // Stores the entire 10-bit UART frame. Each time a bit is transmitted, the register shifts to prepare the next bit.
    reg        state;

    always @(posedge clk) begin
        if (!rst_n) begin
            clk_count <= 16'd0;
            bit_count <= 4'd0;
            shift_reg <= 10'b1111111111;
            state     <= 1'b0;
            tx        <= 1'b1;
            tx_ready  <= 1'b1;
        end // Wait for a byte
        else if (state == 1'b0) begin // 0 means idle, waiting for data. 1 means a transmission is in progress
            tx       <= 1'b1;
            tx_ready <= 1'b1;

            if (tx_en) begin
                shift_reg <= {1'b1, tx_data, 1'b0};
                clk_count <= 16'd0;
                bit_count <= 4'd0;
                tx_ready  <= 1'b0;
                state     <= 1'b1;
            end
        end
        else begin
            tx_ready <= 1'b0; // Start transmitting

            if (clk_count == BAUD_DIV-1) begin
                clk_count <= 16'd0;
                tx        <= shift_reg[0];
                shift_reg <= {1'b1, shift_reg[9:1]};

                if (bit_count == 4'd9) begin
                    bit_count <= 4'd0;
                    state     <= 1'b0;
                end
                else begin
                    bit_count <= bit_count + 1'b1;
                end
            end
            else begin
                clk_count <= clk_count + 1'b1;
            end
        end
    end
endmodule


// ============================================================================
// 5. TRNG Top Level
// ============================================================================
module trng_top #(
    parameter integer NUM_RO  = 8,
    parameter integer SAMP_DIV = 2000 // A new raw sampling event occurs every 2,000 clock cycles
)(
    input  wire clk,      // Boolean Board: 100 MHz
    input  wire rst_n,    // Active-low reset / switch input
    output wire tx       // UART TX
);

    // ------------------------------------------------------------------------
    // Ring oscillator bank
    // ------------------------------------------------------------------------
    wire [NUM_RO-1:0] ro_y; // creates an 8-bit wire vector, all eight outputs are collected here
    reg  ro_en;

    genvar k; //  build repetitive hardware before the circuit runs
    generate
        for (k = 0; k < NUM_RO; k = k + 1) begin : g_ro
            (* DONT_TOUCH = "TRUE" *)
            ro_cell #(
                .N  (3 + 2*(k % 4)),
                .ID (k)
            ) u_ro (
                .en (ro_en),
                .y  (ro_y[k])
            );
        end
    endgenerate

    (* KEEP = "TRUE", DONT_TOUCH = "TRUE" *)
    wire x = ^ro_y; // combines all eight oscillator outputs into one bit called x

    // ------------------------------------------------------------------------
    // 2-flop asynchronous sampler
    // ------------------------------------------------------------------------
    wire s0;
    wire s1;
// Using two filp flop to reduce metashatbility.
    (* ASYNC_REG = "TRUE", DONT_TOUCH = "TRUE" *)
    FDRE u_s0_ff (
        .C  (clk),
        .CE (1'b1),
        .D  (x),
        .Q  (s0),
        .R  (~rst_n)
    );
//At a rising edge of clk, the first flip-flop captures the value of x and stores it in s0
    (* ASYNC_REG = "TRUE", DONT_TOUCH = "TRUE" *)
    FDRE u_s1_ff (
        .C  (clk),
        .CE (1'b1),
        .D  (s0),
        .Q  (s1),
        .R  (~rst_n)
    );
// The second flip-flop samples the first flip-flop's output on a later clock edge
// Note: the oscillators do not use the 100 MHz clock to create their physical oscillation. 
// The clock is used to sample their combined output.

    // ------------------------------------------------------------------------
    // Sampling divider
    // ------------------------------------------------------------------------
    
    // The purpose of this block is to control how frequently the raw bitstream is consumed by the health test and corrector.
    reg [31:0] div;

    always @(posedge clk) begin
        if (!rst_n) begin
            div   <= 32'd0;
            ro_en <= 1'b0;
        end
        else begin
            ro_en <= 1'b1;

            if (SAMP_DIV <= 1) begin
                div <= 32'd0;
            end
            else if (div == SAMP_DIV-1) begin
                div <= 32'd0;
            end
            else begin
                div <= div + 1'b1;
            end
        end
    end

    wire raw_valid = (SAMP_DIV <= 1) ? 1'b1 : (div == SAMP_DIV-1);
    wire raw_bit   = s1;

    // ------------------------------------------------------------------------
    // Health test + bias correction
    // ------------------------------------------------------------------------
    wire health_fail;
    wire bit_valid;
    wire bit_out;

    rct #(.C(41)) u_rct (
        .clk     (clk),
        .rst_n   (rst_n),
        .v       (raw_valid),
        .b       (raw_bit),
        .fail    (health_fail)
    );

    vn_corrector u_vn (
        .clk     (clk),
        .rst_n   (rst_n),
        .v       (raw_valid),
        .d       (raw_bit),
        .ov      (bit_valid),
        .o       (bit_out)
    );

    // ------------------------------------------------------------------------
    // Byte packer
    // ------------------------------------------------------------------------
    reg [7:0] byte_reg; // Stores the corrected bits being collected
    reg [2:0] bit_idx; // Tracks the next bit position, from 0 through 7
    reg       tx_en;
    reg [7:0] tx_data;
    wire      tx_ready;

    always @(posedge clk) begin
        if (!rst_n) begin
            byte_reg <= 8'd0;
            bit_idx  <= 3'd0;
            tx_en    <= 1'b0;
            tx_data  <= 8'd0;
        end
        else begin
            tx_en <= 1'b0;

            if (bit_valid && !health_fail) begin
                if (bit_idx == 3'd7) begin
                    tx_data   <= {bit_out, byte_reg[6:0]};
                    tx_en     <= 1'b1;
                    byte_reg  <= 8'd0;
                    bit_idx   <= 3'd0;
                end
                else begin
                    byte_reg[bit_idx] <= bit_out;
                    bit_idx            <= bit_idx + 1'b1;
                end
            end
        end
    end

    // ------------------------------------------------------------------------
    // UART
    // ------------------------------------------------------------------------
    uart_tx #(.BAUD_DIV(868)) u_uart (
        .clk       (clk),
        .rst_n     (rst_n),
        .tx_en     (tx_en && tx_ready),
        .tx_data   (tx_data),
        .tx        (tx),
        .tx_ready  (tx_ready)
    );

endmodule