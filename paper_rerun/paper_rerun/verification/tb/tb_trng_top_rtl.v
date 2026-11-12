`timescale 1ns/1ps

module tb_trng_top;

    reg clk = 1'b0;
    reg rst_n = 1'b0;

    wire tx;
    wire health_fail;
    wire dbg_raw_bit;
    wire dbg_raw_valid;

    integer raw_sample_count = 0;
    integer tx_fall_count = 0;

    always #5 clk = ~clk;

    trng_top #(
        .NUM_RO(8),
        .SAMP_DIV(2000),
        .CLK_HZ(100_000_000),
        .BAUD(115200),
        .WARMUP_CYCLES(256),
        .RCT_C(41),
        .APT_W(1024),
        .APT_C(793)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .tx(tx),
        .health_fail(health_fail),
        .dbg_raw_bit(dbg_raw_bit),
        .dbg_raw_valid(dbg_raw_valid)
    );

    always @(posedge clk) begin
        if (rst_n && dbg_raw_valid === 1'b1)
            raw_sample_count = raw_sample_count + 1;
    end

    always @(negedge tx) begin
        if (rst_n)
            tx_fall_count = tx_fall_count + 1;
    end

    initial begin
        $dumpfile("Pre_synthesis_simulation.vcd");
        $dumpvars(0, tb_trng_top);

        repeat (10) @(posedge clk);
        rst_n = 1'b1;

        #3000000;

        $display(
            "RTL_SIM_SUMMARY raw_sample_count=%0d tx_fall_count=%0d health_fail=%b",
            raw_sample_count, tx_fall_count, health_fail
        );

        if (raw_sample_count < 100) begin
            $display("RTL_SIM_FAIL: fewer than 100 raw samples");
            $fatal(1);
        end

        if (tx_fall_count < 1) begin
            $display("RTL_SIM_FAIL: no UART activity");
            $fatal(1);
        end

        $display(
            "RTL_SIM_PASS: behavioral functional test only; not an entropy measurement"
        );

        $finish;
    end

endmodule
