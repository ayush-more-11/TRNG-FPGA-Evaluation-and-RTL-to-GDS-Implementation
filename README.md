<<<<<<< HEAD
# FPGA-Based Hardware True Random Number Generator

## Cryptographic and Cybersecurity Applications

This repository presents an **FPGA-based hardware true random number generator (TRNG)** from RTL through FPGA evaluation and ASIC-oriented RTL-to-GDS implementation. It uses ring oscillators as a physical entropy source, asynchronous sampling, health monitoring, Von Neumann debiasing, byte packing, and UART output.

The project explores hardware entropy generation, Verilog RTL, FPGA implementation, statistical randomness validation, OpenLane/SKY130 physical design, Cadence implementation, and research evidence.

> **Security note:** This is a research project. Statistical tests and implementation reports do not by themselves establish a production cryptographic entropy source or certification. Production use requires an entropy model, environmental characterization, continuous health monitoring, secure integration, and appropriate certification.

## System architecture

```mermaid
flowchart LR
    A[Ring oscillator bank] --> B[XOR combiner]
    B --> C[2-flop asynchronous sampler]
    C --> D[Sampling divider]
    D --> E[RCT health test]
    D --> F[APT health test]
    D --> G[Von Neumann corrector]
    E --> H[Health alarm]
    F --> H
    G --> I[Byte packer]
    I --> J[UART 8N1]
    J --> K[tx output]
```

Each oscillator is an enabled odd-inversion feedback loop. The FPGA implementation preserves the loop with Xilinx primitives and attributes. The portable/OpenLane implementation uses technology wrapper cells for a NAND enable gate and inverters. Distinct odd lengths are XORed, sampled by a two-flop synchronizer, checked by health tests, debiased, packed, and transmitted.

## Repository navigation

| Section | Location | Contents |
|---|---|---|
| RTL Design and Testbenches | [`Opensource_TRNG/design/src/`](Opensource_TRNG/design/src/), [`vivado/`](vivado/) | Portable RTL, FPGA RTL, technology wrappers, testbenches |
| FPGA Design and Vivado Results | [`vivado/`](vivado/) | Simulation, synthesis, implementation, timing, power, schematics |
| OpenLane Physical Design | [`openlane/`](openlane/), [`Opensource_TRNG/design/runs/`](Opensource_TRNG/design/runs/) | SKY130A RTL-to-GDS configuration and layout evidence |
| Cadence Results and Analysis | [`cadence/`](cadence/) | Genus/Innovus layout, netlist, timing/power evidence |
| NIST Randomness Testing | [`NIST/`](NIST/) | SP 800-22 campaign summary |
| Architecture and Block Diagrams | [`Diagrams/`](Diagrams/) | Pipeline, RO/sampler, timing, conditioning, evidence figures |
| Research Paper and Technical Documentation | [`paper_rerun/`](paper_rerun/), [`paper_rerun.zip`](paper_rerun.zip) | Final evidence bundle, scripts, verification, paper assets |

## RTL design and testbenches

- [`vivado/trng_top.v`](vivado/trng_top.v): FPGA `ro_cell`, repetition-count test, Von Neumann corrector, UART transmitter, and top-level integration.
- [`vivado/tb_trng.v`](vivado/tb_trng.v): 100 MHz functional testbench that counts raw samples, corrected bits, and UART byte requests.
- [`Opensource_TRNG/design/src/trng_top.v`](Opensource_TRNG/design/src/trng_top.v): portable RTL with reset synchronization, warm-up, RCT, APT, debug taps, and UART hand-off.
- [`Opensource_TRNG/design/src/trng_tech_cells.v`](Opensource_TRNG/design/src/trng_tech_cells.v): SkyWater, Cadence/GPDK, user, and behavioral technology wrappers.
- [`paper_rerun/paper_rerun/verification/tb/tb_trng_top_rtl.v`](paper_rerun/paper_rerun/verification/tb/tb_trng_top_rtl.v): behavioral functional verification; it explicitly does not measure entropy.
- [`Opensource_TRNG/design/config.json`](Opensource_TRNG/design/config.json), [`base.sdc`](Opensource_TRNG/design/constraints/base.sdc), and [`pin_order.cfg`](Opensource_TRNG/design/pin_order.cfg): OpenLane configuration and constraints.

## FPGA implementation and Vivado results

Evidence is in [`vivado/`](vivado/), including [schematics](vivado/TRNG_vivado_sch_whole.png), [simulation](vivado/TRNG_vivado_sim_1.png), [implementation](vivado/TRNG_vivado_impl.png), [timing](vivado/TRNG_vivado_timing_rpt.png), and [power](vivado/TRNG_vivado_power_rpt.png). See [`vivado/vivado_summary.txt`](vivado/vivado_summary.txt).

| Metric | Reported result |
|---|---:|
| Estimated total on-chip power | 73 mW |
| Dynamic / static power | 1 mW / 72 mW |
| Worst setup slack | +2.858 ns |
| Worst hold slack | +0.106 ns |
| Worst pulse-width slack | +4.500 ns |
| Timing failures | 0 setup, 0 hold, 0 pulse-width |

These are tool estimates and STA results; power is medium-confidence and not board-level measured power.

## OpenLane RTL-to-GDS results

See [`openlane/openlane_rtl_to_gds_summary.txt`](openlane/openlane_rtl_to_gds_summary.txt), [`openlane/trng_top.v`](openlane/trng_top.v), [`openlane/trng_tech_cells.v`](openlane/trng_tech_cells.v), [Magic evidence](openlane/SS03_magic.png), [layout evidence](openlane/SS04_Final_GDS_Layou.png), and [`Opensource_TRNG/design/runs/`](Opensource_TRNG/design/runs/).

| Metric | Reported result |
|---|---:|
| Flow / platform | Completed / SKY130A, `sky130_fd_sc_hd` |
| Clock constraint | 10 ns (100 MHz constraint) |
| Target / observed utilization | 45% / 47.77% |
| Final extracted setup / hold slack | +5.86 ns / +0.29 ns |
| Final extracted power | approximately 1.34 mW, typical-corner estimate |
| Detailed mapped top-module cells | 840 |
| Magic DRC / LVS | 0 reported violations / 0 reported errors |
| Router violations | 0 |

The checked-in summary states that final GDS is absent from the archived OpenLane report set; KLayout DRC and CVC metrics are `-1`/unavailable; wrapper-cell area is not fully accounted for; one unconstrained endpoint, four max-fanout violations, and eight intentional combinational loops are reported. The 100 MHz value is a constraint, not a demonstrated maximum frequency.

## Cadence implementation results

The [`cadence/`](cadence/) directory contains Genus/Innovus layout, netlist, pre/post-layout simulations, and [`cadence_rtl_to_gds_summary.txt`](cadence/cadence_rtl_to_gds_summary.txt).

| Metric | Reported result |
|---|---:|
| Tools / process | Genus 21.14, Innovus 21.15 / 90 nm |
| Supply | 0.9 V |
| Top-level instances | 679 |
| Reported total area | 4677.642 (unit not stated) |
| Shown setup slack | +6.009 ns |
| Post-route total power | 0.37239906 mW estimate |
| Clock constraint | 10 ns (100 MHz constraint) |

No Cadence DRC/LVS, hold report, die/core dimensions, or independent signoff summary is included. Power depends on default activity assumptions and is not a silicon measurement.

## NIST SP 800-22 statistical testing

[`NIST/nist_sp80022_summary.txt`](NIST/nist_sp80022_summary.txt) documents an STS campaign covering **55 binary bitstreams**, each **1,000,000 bits**, for **55,000,000 bits / 6,875,000 bytes** total. Primary evidence is identified as `collection_summary.json`, `SHA256_manifest.txt`, `TRNG_Terminal.txt`, and `TRNG_Terminal_Op.txt` from the analyzed archive.

The methodology captures long TRNG streams, partitions them into one-million-bit sequences, runs NIST SP 800-22, retains terminal output/metadata/hashes, and reviews per-test p-values and pass proportions. NIST SP 800-22 is statistical screening, not an entropy-source model or certification; the checked-in summary is authoritative for detailed per-test outcomes.

## Diagrams and research evidence

Available figures include the [pipeline](Diagrams/fig_pipeline.pdf), [RO sampler](Diagrams/fig_ro_sampler.pdf), [timing](Diagrams/fig_timing.pdf), [Von Neumann](Diagrams/fig_vonneumann.pdf), and [evidence](Diagrams/fig_evidence.pdf) diagrams. The paper bundle includes [`FINAL/`](paper_rerun/paper_rerun/FINAL/), [`collect_final.py`](paper_rerun/paper_rerun/scripts/collect_final.py), [`latest_run_tag.txt`](paper_rerun/paper_rerun/latest_run_tag.txt), and [KLayout](paper_rerun/paper_rerun/KLayout.png), [Magic](paper_rerun/paper_rerun/Magic.png), and [simulation](paper_rerun/paper_rerun/simulation.png) images.

## Tools and setup

Technologies include Verilog-2001, Xilinx Vivado, OpenLane/Yosys/OpenROAD, Magic, KLayout, Verilator, SKY130A, Cadence Genus/Innovus, and NIST SP 800-22.

For behavioral simulation with Icarus Verilog:

```bash
iverilog -g2012 -DTRNG_BEHAV_SIM -o trng_sim \
  Opensource_TRNG/design/src/trng_top.v \
  Opensource_TRNG/design/src/trng_tech_cells.v \
  paper_rerun/paper_rerun/verification/tb/tb_trng_top_rtl.v
vvp trng_sim
```

This is a functional check only. OpenLane and Cadence reruns require matching PDKs, libraries, licenses, and tool environments.

## Reproducibility and reporting guidance

Do not compare FPGA, OpenLane, and Cadence numbers without stating technology, supply, clock constraint, corner, activity assumptions, and whether a value is estimated or measured. Preserve the documented caveats around intentional oscillator loops, asynchronous sampling, unavailable signoff metrics, unqualified Cadence area units, and the difference between statistical testing and a formal entropy claim.

## License

No license file is currently provided. Treat RTL, reports, figures, and archives as project materials unless a separate license is supplied.
=======
# FPGA & ASIC Ring-Oscillator True Random Number Generator

**An eight-ring-oscillator TRNG implemented in Verilog, with a Xilinx FPGA version and a SkyWater 130 nm OpenLane implementation, plus physical-design evidence and NIST SP 800-22 evaluation.**

![RO-TRNG pipeline](docs/figures/fig_pipeline.png)

## Design

The core pipeline is **ring-oscillator bank → XOR → two-flop sampler → health checks → Von Neumann corrector → byte packer → UART (8-N-1)**.

- **FPGA RTL** (`rtl/fpga/`): Xilinx-oriented implementation. The FPGA version includes the RCT health check and Von Neumann correction.
- **ASIC RTL** (`openlane/src/`): Sky130 technology wrappers, reset synchronizer, RCT and APT health checks, Von Neumann correction and UART. The OpenLane configuration and timing constraints are alongside the source.
- **Verification** (`verification/`): separate functional testbenches for the FPGA and ASIC variants.

The simulation-only ring-oscillator models exercise digital functionality; they do **not** model physical entropy and must not be used as evidence of randomness.

## Results at a glance

| Flow | Selected reported results |
|---|---|
| Vivado FPGA | WNS **+2.858 ns**, WHS **+0.106 ns**; estimated on-chip power **73 mW** |
| OpenLane / Sky130 | Final extracted setup slack **+5.86 ns**, hold slack **+0.29 ns**; estimated power **1.34 mW**; Magic DRC count **0**, LVS errors **0** |
| Cadence Innovus / 90 nm | Reported setup-path slack **+6.009 ns**; estimated post-route power **0.372 mW**; **679** instances |
| NIST SP 800-22 | **55 × 1,000,000-bit** sequences (**55 Mbit** total); one subtest row is marked below the report's approximate passing-proportion threshold |

These are tool reports, not silicon measurements. The 100 MHz OpenLane clock is a design constraint, not a demonstrated maximum operating frequency. The OpenLane area report has custom-wrapper area-accounting limitations. Cadence does not include DRC/LVS or hold reports, and its reported area unit is unspecified; do not compare its values directly with Sky130 or FPGA results.

The NIST sequences are consecutive streams from one capture session, not 55 independent entropy-source experiments. The raw bitstream is not included. The report contains one proportion-flagged row (**51/55**); therefore this project does not claim that every NIST subtest passed or that statistical testing proves cryptographic security.

## Repository map

```text
rtl/fpga/                 FPGA RTL
verification/fpga/        FPGA testbench
verification/asic/        ASIC/OpenLane testbench
openlane/
  src/                    ASIC RTL and technology wrappers
  config.json             OpenLane configuration
  constraints/            SDC timing constraints
  reports/                Selected synthesis, timing, power and signoff reports
  physical/               Final GDS, LEF, DEF, SDF, SPEF and post-layout netlist
results/
  vivado/                 FPGA reports and selected screenshots
  openlane/               OpenLane evidence screenshots
  cadence/                Innovus summary and layout/simulation screenshots
  nist/                   NIST SP 800-22 summary
 docs/figures/             Architecture and timing diagrams
```

## Functional simulation

Run from the repository root with Icarus Verilog installed:

```bash
# FPGA behavioral testbench
mkdir -p build
iverilog -g2012 -s tb_trng -o build/fpga_tb rtl/fpga/trng_top.v verification/fpga/tb_trng.v
vvp build/fpga_tb

# ASIC behavioral testbench (simulation-only RO model)
iverilog -g2012 -DTRNG_BEHAV_SIM -s tb_trng_top -o build/asic_tb \
  openlane/src/trng_tech_cells.v openlane/src/trng_top.v verification/asic/tb_trng_top_rtl.v
vvp build/asic_tb
```

For physical implementation, use `openlane/` as the design directory with the Sky130A PDK and the supplied `config.json`. The checked-in compile logs are retained as evidence: the captured Icarus invocation could not find `iverilog`, and the captured Verilator build stopped because its configured `g++` path was missing. Re-run these checks in a configured local environment before relying on them.

## Figures and reports

- [Pipeline](docs/figures/fig_pipeline.pdf) · [RO sampler](docs/figures/fig_ro_sampler.pdf) · [Von Neumann correction](docs/figures/fig_vonneumann.pdf) · [Sampling/UART timing](docs/figures/fig_timing.pdf)
- Detailed reports and screenshots are grouped by tool under `results/`; final OpenLane physical outputs are under `openlane/physical/`.
>>>>>>> 2a71bc8 (Restructured Repo)
