`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09.10.2026 11:37:00
// Design Name: 
// Module Name: tb_trng
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

module tb_trng;

    reg  clk;
    reg  rst_n;
    wire tx;

    // Use a smaller sampling divider only for simulation.
    // 2000 clocks at 100 MHz = 20 us between raw samples.
    trng_top #(
        .NUM_RO   (8),
        .SAMP_DIV (2000)
    ) uut (
        .clk   (clk),
        .rst_n (rst_n),
        .tx    (tx)
    );

    // ------------------------------------------------------------------------
    // 100 MHz clock generation (10 ns total period -> 5 ns high, 5 ns low)
    // ------------------------------------------------------------------------
    always #5 clk = ~clk;

    // ------------------------------------------------------------------------
    // Simple counters for functional validation
    // ------------------------------------------------------------------------
    integer raw_count;
    integer corrected_count;
    integer byte_count;

    always @(posedge clk) begin
        if (!rst_n) begin
            // Counters are reset in the initial block below.
        end
        else begin
            if (uut.raw_valid)
                raw_count = raw_count + 1;

            if (uut.bit_valid)
                corrected_count = corrected_count + 1;

            if (uut.tx_en)
                byte_count = byte_count + 1;
        end
    end

    // ------------------------------------------------------------------------
    // Optional visibility of generated corrected bits
    // ------------------------------------------------------------------------
    always @(posedge clk) begin
        if (rst_n && uut.bit_valid) begin
            $display("%0t ns : corrected_bit = %0d", $time, uut.bit_out);
        end

        if (rst_n && uut.health_fail) begin
            $display("%0t ns : WARNING - RCT health_fail asserted", $time);
        end
    end

    // ------------------------------------------------------------------------
    // Test sequence
    // ------------------------------------------------------------------------
    initial begin
        clk             = 1'b0;
        rst_n           = 1'b0;
        raw_count       = 0;
        corrected_count = 0;
        byte_count      = 0;

        // Hold reset for 100 ns.
        #100;
        rst_n = 1'b1;

        // Run for 20 ms so UART bytes can be observed.
        // 20 ms = 20,000,000 ns.
        #20_000_000;

        $display("============================================================");
        $display("TRNG SIMULATION SUMMARY (100 MHz)");
        $display("Raw samples       : %0d", raw_count);
        $display("Corrected bits    : %0d", corrected_count);
        $display("UART byte requests: %0d", byte_count);
        $display("RCT health_fail   : %0d", uut.health_fail);
        $display("Final TX          : %0d", tx);
        $display("============================================================");

        $finish;
    end

endmodule
