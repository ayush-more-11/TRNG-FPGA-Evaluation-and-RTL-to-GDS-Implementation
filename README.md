# FPGA-Based Ring-Oscillator True Random Number Generator

A Verilog project implementing and evaluating a hardware true random number generator (TRNG) from RTL to FPGA and ASIC physical implementation.

![TRNG pipeline](figures/fig_pipeline.png)

> This project demonstrates RTL, FPGA, physical-design, and statistical-evaluation workflows. It is a research implementation, not a certification-ready cryptographic entropy source.

## 1. Project in One View

The design uses eight ring oscillators to produce raw entropy:

**Ring-oscillator bank → XOR → two-flop asynchronous sampler → repetition-count test → adaptive-proportion test → Von Neumann debiaser → byte packer → UART**

The repository covers three implementation and evidence tracks:

| Track | What it demonstrates |
|---|---|
| [FPGA](#2-fpga-track) | Xilinx/Vivado RTL implementation, simulation, synthesis, timing, power, and implementation evidence |
| [OpenLane / SKY130](#3-openlane--sky130-track) | Portable ASIC RTL, synthesis, place-and-route, extracted timing/power, GDS, Magic, LVS, and layout evidence |
| [Cadence / 90 nm](#4-cadence--90-nm-track) | Genus/Innovus post-route timing, power, layout, and available implementation artifacts |

## 2. FPGA Track

The FPGA RTL and testbench are in [`rtl/`](rtl/):

- [`rtl/trng_top.v`](rtl/trng_top.v) — FPGA-oriented top level, ring-oscillator cells, health test, sampler, conditioning, and UART logic.
- [`rtl/tb_trng.v`](rtl/tb_trng.v) — functional simulation testbench.

Vivado evidence is in [`results/vivado/`](results/vivado/), with the full summary in [`summary.txt`](results/vivado/summary.txt).

| Reported result | Value |
|---|---:|
| Clock | 100 MHz constraint |
| Worst setup slack | +2.858 ns |
| Worst hold slack | +0.106 ns |
| Worst pulse-width slack | +4.500 ns |
| Estimated total on-chip power | 73 mW |

These are tool reports. The power value is an estimate; no physical board measurement is included.

## 3. OpenLane / SKY130 Track

Use [`openlane/config.json`](openlane/config.json), [`openlane/constraints/base.sdc`](openlane/constraints/base.sdc), and [`openlane/pin_order.cfg`](openlane/pin_order.cfg) as the implementation entry points.

- [`openlane/src/`](openlane/src/) — SKY130-aware and portable RTL wrappers.
- [`openlane/reports/`](openlane/reports/) — synthesis, timing, power, DRC, LVS, and compile evidence.
- [`openlane/physical/`](openlane/physical/) — GDS, LEF, DEF, SPEF, SDF, and post-layout Verilog.

Key checked-in metrics:

| Reported result | Value |
|---|---:|
| Platform | SKY130A / `sky130_fd_sc_hd` |
| Clock constraint | 10 ns (100 MHz) |
| Final extracted setup / hold slack | +5.86 ns / +0.29 ns |
| Estimated typical-corner power | 1.34 mW |
| Final utilization | 47.77% |
| Magic DRC / LVS | 0 violations / 0 errors |

The 100 MHz value is a constraint, not a demonstrated maximum frequency. Review [`openlane/reports/openlane_metrics.csv`](openlane/reports/openlane_metrics.csv) for the complete captured run metrics.

## 4. Cadence / 90 nm Track

The Cadence evidence is summarized in [`results/cadence/summary.txt`](results/cadence/summary.txt). Layout and simulation screenshots are available in [`results/cadence/`](results/cadence/).

| Reported result | Value |
|---|---:|
| Tools | Genus 21.14 / Innovus 21.15 |
| Process / supply | 90 nm / 0.9 V |
| Top-level instances | 679 |
| Clock constraint | 10 ns (100 MHz) |
| Shown setup slack | +6.009 ns |
| Post-route estimated power | 0.37239906 mW |

No DRC/LVS signoff, hold-timing report, die/core dimensions, or independent signoff summary is included. The area unit is not stated, and power is based on default activity assumptions rather than silicon measurements.

## 5. Randomness Evaluation

The NIST evidence summary is [`results/nist/nist_sp80022_summary.txt`](results/nist/nist_sp80022_summary.txt).

- 55 binary bitstreams
- 1,000,000 bits per stream
- 55,000,000 bits captured in total
- Terminal output, collection metadata, and SHA-256 hashes documented in the summary

NIST SP 800-22 is statistical screening, not an entropy-source model or cryptographic certification. The captured streams should not be described as independent entropy-source experiments, and statistical results do not replace continuous health monitoring or environmental characterization.

## 6. Repository Map

| Directory | Purpose |
|---|---|
| [`rtl/`](rtl/) | FPGA RTL and functional testbench |
| [`verification/`](verification/) | Behavioral RTL verification |
| [`openlane/`](openlane/) | SKY130 implementation configuration, source, constraints, reports, and physical outputs |
| [`results/vivado/`](results/vivado/) | FPGA synthesis, implementation, timing, power, schematic, and simulation evidence |
| [`results/cadence/`](results/cadence/) | Cadence 90 nm layout and implementation summary |
| [`results/nist/`](results/nist/) | NIST SP 800-22 testing summary |
| [`figures/`](figures/) | Architecture and timing figures |

## 7. Quick Revision

### What to explain

1. Ring oscillators generate raw jitter-based transitions.
2. XOR combines the oscillator outputs; a two-flop sampler captures asynchronous behavior.
3. RCT and APT provide implementation health checks.
4. Von Neumann correction removes simple paired-bit bias.
5. Bytes are packed and transmitted through an 8-N-1 UART interface.

### What to cite carefully

- Clock values are constraints unless silicon measurements are shown.
- Vivado, OpenLane, and Cadence power values are estimates under their respective assumptions.
- DRC/LVS and timing closure only apply to the tool/report sets identified here.
- Do not call the design production-ready or cryptographically certified.

## 8. Functional Simulation

With Icarus Verilog available, run:

```bash
iverilog -g2012 -DTRNG_BEHAV_SIM -s tb_trng_top \
  -o trng_sim openlane/src/trng_tech_cells.v \
  openlane/src/trng_top.v verification/tb_trng_top_rtl.v
vvp trng_sim
```

This is a behavioral functional check. It does not model entropy and does not prove randomness quality.

OpenLane reruns require a configured SKY130A PDK and compatible OpenLane environment. Cadence reruns require the appropriate Genus/Innovus libraries and licenses.

## 9. Figure Reference

- [Pipeline](figures/fig_pipeline.pdf)
- [Ring oscillator and sampler](figures/fig_ro_sampler.pdf)
- [Von Neumann conditioning](figures/fig_vonneumann.pdf)
- [Sampling and timing](figures/fig_timing.pdf)

## License

This project is licensed under the [MIT License](LICENSE).
