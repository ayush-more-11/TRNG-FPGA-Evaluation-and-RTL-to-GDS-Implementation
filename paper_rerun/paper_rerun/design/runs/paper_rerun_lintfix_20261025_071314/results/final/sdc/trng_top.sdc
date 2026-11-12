###############################################################################
# Created by write_sdc
# Sun Oct 25 07:13:28 2026
###############################################################################
current_design trng_top
###############################################################################
# Timing Constraints
###############################################################################
create_clock -name clk -period 10.0000 [get_ports {clk}]
set_clock_transition 0.1500 [get_clocks {clk}]
set_clock_uncertainty 0.2500 clk
set_input_delay 2.0000 -clock [get_clocks {clk}] -add_delay [get_ports {rst_n}]
set_output_delay 2.0000 -clock [get_clocks {clk}] -add_delay [get_ports {dbg_raw_bit}]
set_output_delay 2.0000 -clock [get_clocks {clk}] -add_delay [get_ports {dbg_raw_valid}]
set_output_delay 2.0000 -clock [get_clocks {clk}] -add_delay [get_ports {health_fail}]
set_output_delay 2.0000 -clock [get_clocks {clk}] -add_delay [get_ports {tx}]
set_false_path\
    -to [get_pins {u_sampler/_0_/D}]
###############################################################################
# Environment
###############################################################################
set_load -pin_load 0.0334 [get_ports {dbg_raw_bit}]
set_load -pin_load 0.0334 [get_ports {dbg_raw_valid}]
set_load -pin_load 0.0334 [get_ports {health_fail}]
set_load -pin_load 0.0334 [get_ports {tx}]
set_driving_cell -lib_cell sky130_fd_sc_hd__inv_2 -pin {Y} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {clk}]
set_driving_cell -lib_cell sky130_fd_sc_hd__inv_2 -pin {Y} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {rst_n}]
set_timing_derate -early 0.9500
set_timing_derate -late 1.0500
###############################################################################
# Design Rules
###############################################################################
set_max_transition 0.7500 [current_design]
set_max_fanout 10.0000 [current_design]
