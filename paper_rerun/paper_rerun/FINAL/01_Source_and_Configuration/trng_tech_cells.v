



//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/16/2026 02:24:35 PM
// Design Name: 
// Module Name: trng_tech_cells
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


`timescale 1ns / 1ps
// ============================================================================
// trng_tech_cells.v  -  technology wrapper cells for the ring oscillator
// ----------------------------------------------------------------------------
// The ring oscillator MUST be built from hard-instantiated standard cells.
// If it is written as generic logic (assign n = ~n_prev) synthesis sees a
// combinational loop and optimizes it away (verified with Yosys).
//
// Select exactly ONE technology with a compile-time define:
//
//   +define+TRNG_TECH_SKY130   SkyWater SKY130 sky130_fd_sc_hd   (OpenLane/ORFS)
//   +define+TRNG_TECH_GPDK     Cadence GPDK045 / GPDK180 gsclib  (Genus/Innovus)
//   +define+TRNG_TECH_USER     edit the USER section below (e.g. SCL180)
//   +define+TRNG_BEHAV_SIM     RTL simulation only (behavioral RO, see trng_top.v)
//
// If none is defined, the unknown-module instance below makes every tool stop
// with an obvious error instead of silently building a wrong chip.
//
// !! Verify cell names / pin names against YOUR liberty + LEF before use. !!
// ============================================================================

// ---------------------------------------------------------------- inverter --
(* keep_hierarchy *)
module trng_tech_inv (
    input  wire a,
    output wire y
);
`ifdef TRNG_TECH_SKY130
    (* keep *) sky130_fd_sc_hd__inv_1  u_cell (.A(a), .Y(y));
`elsif TRNG_TECH_GPDK
    (* keep *) INVX1                   u_cell (.A(a), .Y(y));
`elsif TRNG_TECH_USER
    // ---- USER SECTION: put your PDK inverter here (e.g. SCL180) ----
    (* keep *) USER_INV_CELL           u_cell (.A(a), .Y(y));
`elsif TRNG_BEHAV_SIM
    assign y = ~a;   // never used in behavioral-RO simulation; keeps file compilable
`else
    trng_tech_not_selected__define_a_TRNG_TECH_macro u_err ();
`endif
endmodule

// ------------------------------------------------------------------- nand2 --
(* keep_hierarchy *)
module trng_tech_nand2 (
    input  wire a,
    input  wire b,
    output wire y
);
`ifdef TRNG_TECH_SKY130
    (* keep *) sky130_fd_sc_hd__nand2_1 u_cell (.A(a), .B(b), .Y(y));
`elsif TRNG_TECH_GPDK
    (* keep *) NAND2X1                  u_cell (.A(a), .B(b), .Y(y));
`elsif TRNG_TECH_USER
    (* keep *) USER_NAND2_CELL          u_cell (.A(a), .B(b), .Y(y));
`elsif TRNG_BEHAV_SIM
    assign y = ~(a & b);
`else
    trng_tech_not_selected__define_a_TRNG_TECH_macro u_err ();
`endif
endmodule



