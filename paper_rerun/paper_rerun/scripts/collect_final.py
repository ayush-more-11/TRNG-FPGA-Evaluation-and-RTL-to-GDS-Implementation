from pathlib import Path
from datetime import datetime
import csv
import hashlib
import json
import re
import shutil
import sys

ROOT = Path("/openlane/designs/trng_top/paper_rerun")
TAG_FILE = ROOT / "latest_run_tag.txt"

if not TAG_FILE.exists():
    sys.exit("ERROR: latest_run_tag.txt does not exist.")

TAG = TAG_FILE.read_text().strip()
RUN = ROOT / "design" / "runs" / TAG

if not RUN.is_dir():
    sys.exit(f"ERROR: Current run directory does not exist: {RUN}")

FINAL = ROOT / "FINAL"

# Preserve any previous collection instead of mixing results from runs.
if FINAL.exists() and any(FINAL.iterdir()):
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    archive = ROOT / f"FINAL_previous_{stamp}"
    shutil.move(str(FINAL), str(archive))
    print(f"Previous FINAL preserved at: {archive}")

DIRS = [
    "01_Source_and_Configuration",
    "02_Pre_Synthesis",
    "03_Synthesis",
    "04_Timing",
    "05_Power",
    "06_GDS_and_Physical_Outputs",
    "07_Physical_Verification",
    "08_Screenshots",
    "09_Run_Logs_and_Raw_Reports",
    "10_Simulations",
]

for d in DIRS:
    (FINAL / d).mkdir(parents=True, exist_ok=True)

def copy_file(src, dst):
    src, dst = Path(src), Path(dst)
    if not src.is_file():
        return False
    dst.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(src, dst)
    print(f"COPIED: {src} -> {dst.relative_to(FINAL)}")
    return True

def first_match(base, patterns):
    base = Path(base)
    if not base.exists():
        return None
    for pattern in patterns:
        matches = sorted(
            p for p in base.rglob(pattern) if p.is_file()
        )
        if matches:
            return matches[0]
    return None

def copy_found(base, patterns, dst):
    src = first_match(base, patterns)
    if src:
        return copy_file(src, dst), str(src)
    print(f"MISSING: {dst.relative_to(FINAL)}")
    return False, ""

def copy_direct_files(src_dir, dst_dir):
    src_dir, dst_dir = Path(src_dir), Path(dst_dir)
    if not src_dir.is_dir():
        return
    for p in src_dir.iterdir():
        if p.is_file():
            copy_file(p, dst_dir / p.name)

# ------------------------------------------------------------
# 01 - Source and configuration
# ------------------------------------------------------------
source = ROOT / "design" / "src"
out = FINAL / "01_Source_and_Configuration"

for name in ["trng_top.v", "trng_tech_cells.v"]:
    copy_file(source / name, out / name)

for src, name in [
    (ROOT / "design" / "config.json", "Rerun_Config.json"),
    (ROOT / "design" / "constraints" / "base.sdc", "Timing_Constraints.sdc"),
    (ROOT / "design" / "pin_order.cfg", "Pin_Order.cfg"),
    (ROOT / "reference" / "original_config.json", "Original_Config.json"),
]:
    copy_file(src, out / name)

for name in ["config.json", "config.tcl", "config_in.tcl"]:
    copy_file(
        RUN / name,
        FINAL / "09_Run_Logs_and_Raw_Reports" / f"Resolved_{name}"
    )

# ------------------------------------------------------------
# 02 - Pre-synthesis evidence
# ------------------------------------------------------------
copy_direct_files(
    ROOT / "evidence" / "01_pre_synthesis_simulation",
    FINAL / "02_Pre_Synthesis"
)

# Lint result from the current run.
copy_file(
    RUN / "logs" / "synthesis" / "linter.log",
    FINAL / "02_Pre_Synthesis" / "OpenLane_Verilator_Lint.log"
)

# ------------------------------------------------------------
# 03 - Synthesis statistics
# ------------------------------------------------------------
synth = RUN / "reports" / "synthesis"
out = FINAL / "03_Synthesis"

aliases = [
    (["1-synthesis_pre.stat"], "Pre_Synthesis_Statistics.txt"),
    (["1-synthesis_pre_synth.chk.rpt"], "Pre_Synthesis_Design_Check.txt"),
    (["1-synthesis.AREA_0.stat.rpt"], "Cell_Count_and_Area_Report.txt"),
    (["1-synthesis.AREA_0.chk.rpt"], "Synthesis_Check_Report.txt"),
    (["1-synthesis_dff.stat"], "Flip_Flop_Statistics.txt"),
    (["2-syn_sta.summary.rpt"], "Post_Synthesis_Timing_Summary.rpt"),
    (["2-syn_sta.max.rpt"], "Post_Synthesis_Max_Timing_Report.rpt"),
]

for patterns, name in aliases:
    copy_found(synth, patterns, out / name)

copy_found(
    RUN / "reports",
    ["metrics.csv"],
    out / "OpenLane_Metrics.csv"
)

copy_found(
    RUN / "results" / "synthesis",
    ["trng_top.v"],
    out / "Post_Synthesis_Gate_Level_Netlist.v"
)

# ------------------------------------------------------------
# 04 - Timing
# ------------------------------------------------------------
out = FINAL / "04_Timing"
timing_aliases = [
    (["2-syn_sta.summary.rpt"], "Post_Synthesis_Timing_Summary.rpt"),
    (["11-dpl_sta.summary.rpt"], "Placement_Timing_Summary.rpt"),
    (["13-cts_sta.summary.rpt"], "Clock_Tree_Synthesis_Timing_Summary.rpt"),
    (["21-grt_sta.summary.rpt"], "Global_Route_Timing_Summary.rpt"),
    (["18-rsz_timing_sta.summary.rpt"], "Post_Route_Timing_Summary.rpt"),
    (["31-rcx_sta.summary.rpt"], "Final_RC_Extracted_Timing_Summary.rpt"),
    (["31-rcx_sta.checks.rpt"], "Final_RC_Extracted_Timing_Checks.rpt"),
    (["31-rcx_sta.max.rpt"], "Final_RC_Extracted_Max_Timing.rpt"),
    (["31-rcx_sta.min.rpt"], "Final_RC_Extracted_Min_Timing.rpt"),
]

for patterns, name in timing_aliases:
    copy_found(RUN / "reports", patterns, out / name)

# ------------------------------------------------------------
# 05 - Power and IR drop
# ------------------------------------------------------------
out = FINAL / "05_Power"
power_aliases = [
    (["2-syn_sta.power.rpt"], "Post_Synthesis_Power_Report.rpt"),
    (["11-dpl_sta.power.rpt"], "Placement_Power_Report.rpt"),
    (["18-rsz_timing_sta.power.rpt"], "Post_Route_Power_Report.rpt"),
    (["31-rcx_sta.power.rpt"], "Final_RC_Extracted_Power_Report.rpt"),
    (["32-irdrop-VPWR.rpt"], "IR_Drop_VPWR_Report.rpt"),
    (["32-irdrop-VGND.rpt"], "IR_Drop_VGND_Report.rpt"),
]

for patterns, name in power_aliases:
    copy_found(RUN / "reports", patterns, out / name)

# ------------------------------------------------------------
# 06 - Final physical outputs from THIS run only
# ------------------------------------------------------------
out = FINAL / "06_GDS_and_Physical_Outputs"
final_results = RUN / "results" / "final"

output_aliases = [
    (["*.gds"], "Final_TRNG_Layout.gds"),
    (["*.def"], "Final_TRNG_Routed_Design.def"),
    (["*.lef"], "Final_TRNG_Layout.lef"),
    (["*.spef"], "Final_TRNG_Extracted_Parasitics.spef"),
    (["*.sdf"], "Final_Post_Layout_SDF.sdf"),
]

for patterns, name in output_aliases:
    copy_found(final_results, patterns, out / name)

copy_found(
    final_results,
    ["trng_top.v"],
    out / "Final_Post_Layout_Gate_Level_Netlist.v"
)

# ------------------------------------------------------------
# 07 - Physical verification
# ------------------------------------------------------------
out = FINAL / "07_Physical_Verification"
signoff = RUN / "reports" / "signoff"

for src_name, dst_name in [
    ("drc.rpt", "Magic_DRC_Report.txt"),
    ("drc.klayout.xml", "KLayout_DRC_Report.xml"),
]:
    copy_file(signoff / src_name, out / dst_name)

copy_found(
    signoff,
    ["*lvs*.rpt"],
    out / "LVS_Report.txt"
)

copy_found(
    signoff,
    ["*antenna*.rpt"],
    out / "Antenna_Report.txt"
)

# ------------------------------------------------------------
# 08 - Screenshots already present inside evidence
# ------------------------------------------------------------
screenshot_out = FINAL / "08_Screenshots"
for base in [ROOT / "evidence", ROOT / "FINAL_previous_screenshots"]:
    if base.exists():
        for p in base.rglob("*"):
            if p.is_file() and p.suffix.lower() in {".png", ".jpg", ".jpeg"}:
                copy_file(p, screenshot_out / p.name)

# ------------------------------------------------------------
# 09 - Preserve reports and logs from current run
# ------------------------------------------------------------
out = FINAL / "09_Run_Logs_and_Raw_Reports"

for sub in ["reports", "logs"]:
    src = RUN / sub
    dst = out / f"All_OpenLane_{sub.capitalize()}"
    if src.is_dir():
        shutil.copytree(src, dst, dirs_exist_ok=True)
        print(f"Preserved complete raw directory: {src}")

copy_file(
    ROOT / "evidence" / "05_metadata" / "Tool_Versions.txt",
    FINAL / "01_Source_and_Configuration" / "Tool_Versions.txt"
)

for p in (ROOT / "evidence" / "02_openlane_flow").glob(
    f"OpenLane_Flow_{TAG}.*"
):
    copy_file(p, out / p.name)

# ------------------------------------------------------------
# 10 - Copy any existing simulation evidence
# ------------------------------------------------------------
sim_evidence = [
    ("03_post_synthesis_simulation", "Post_Synthesis"),
    ("04_post_layout_simulation", "Post_Layout"),
]

out = FINAL / "10_Simulations"

for dirname, label in sim_evidence:
    src_dir = ROOT / "evidence" / dirname
    dst_dir = out / label
    copy_direct_files(src_dir, dst_dir)

# Search for SKY130 Verilog cell model for host simulation.
pdkpath = ""
cfg_in = RUN / "config_in.tcl"
if cfg_in.exists():
    text = cfg_in.read_text(errors="ignore")
    m = re.search(r'set ::env\(PDKPATH\) "([^"]+)"', text)
    if m:
        pdkpath = m.group(1)

model_candidates = []
if pdkpath:
    model_candidates.append(
        Path(pdkpath) / "libs.ref" / "sky130_fd_sc_hd" /
        "verilog" / "sky130_fd_sc_hd.v"
    )

for base in [
    Path("/home"),
    Path("/root/.ciel"),
    Path("/root/.volare"),
    Path("/openlane/pdks"),
]:
    model_candidates.extend(
        base.glob("**/libs.ref/sky130_fd_sc_hd/verilog/sky130_fd_sc_hd.v")
        if base.exists() else []
    )

model = next((p for p in model_candidates if p.is_file()), None)
if model:
    copy_file(model, out / "sky130_fd_sc_hd.v")
else:
    print("MISSING: SKY130 Verilog cell model was not found.")

# ------------------------------------------------------------
# 00 - Run summary and artifact checklist
# ------------------------------------------------------------
rc_file = (
    ROOT / "evidence" / "02_openlane_flow" /
    f"OpenLane_Flow_{TAG}.exit_code"
)
rc = rc_file.read_text().strip() if rc_file.exists() else "UNKNOWN"

def present(path):
    return Path(path).is_file()

items = [
    ("OpenLane exit code", FINAL / "09_Run_Logs_and_Raw_Reports" /
     f"OpenLane_Flow_{TAG}.exit_code", "Inspect value; 0 means the command returned successfully."),
    ("RTL pre-synthesis simulation log", FINAL / "02_Pre_Synthesis" /
     "Pre_synthesis_simulation.log", "Check for an explicit pass/fail marker."),
    ("Mapped synthesis statistics", FINAL / "03_Synthesis" /
     "Cell_Count_and_Area_Report.txt", "Use as a synthesis measurement only."),
    ("Post-synthesis gate-level netlist", FINAL / "03_Synthesis" /
     "Post_Synthesis_Gate_Level_Netlist.v", "Required for mapped-netlist simulation."),
    ("Post-synthesis timing", FINAL / "04_Timing" /
     "Post_Synthesis_Timing_Summary.rpt", "Check path, clock, corner, WNS/TNS."),
    ("Post-route timing", FINAL / "04_Timing" /
     "Post_Route_Timing_Summary.rpt", "Required for routed timing evidence."),
    ("Final RC-extracted timing", FINAL / "04_Timing" /
     "Final_RC_Extracted_Timing_Summary.rpt", "Final STA evidence if signoff completed."),
    ("Final power report", FINAL / "05_Power" /
     "Final_RC_Extracted_Power_Report.rpt", "Verify units, corner, and activity assumptions."),
    ("Final GDS", FINAL / "06_GDS_and_Physical_Outputs" /
     "Final_TRNG_Layout.gds", "Must come from the current run."),
    ("Final SPEF", FINAL / "06_GDS_and_Physical_Outputs" /
     "Final_TRNG_Extracted_Parasitics.spef", "Required for extracted-parasitic evidence."),
    ("Final SDF", FINAL / "06_GDS_and_Physical_Outputs" /
     "Final_Post_Layout_SDF.sdf", "Required for SDF-annotated simulation attempt."),
    ("Magic DRC report", FINAL / "07_Physical_Verification" /
     "Magic_DRC_Report.txt", "Read violation count; presence alone is not a pass."),
    ("KLayout DRC report", FINAL / "07_Physical_Verification" /
     "KLayout_DRC_Report.xml", "Must show that KLayout DRC ran and report its result."),
    ("LVS report", FINAL / "07_Physical_Verification" /
     "LVS_Report.txt", "Read the actual comparison status."),
    ("IR-drop VPWR", FINAL / "05_Power" / "IR_Drop_VPWR_Report.rpt",
     "Missing if IR-drop analysis was not generated."),
    ("IR-drop VGND", FINAL / "05_Power" / "IR_Drop_VGND_Report.rpt",
     "Missing if IR-drop analysis was not generated."),
    ("Post-synthesis simulation log", FINAL / "10_Simulations" /
     "Post_Synthesis" / "Post_Synthesis_Simulation.log",
     "Run after current mapped netlist is available."),
    ("Post-layout simulation log", FINAL / "10_Simulations" /
     "Post_Layout" / "Post_Layout_SDF_Simulation.log",
     "Run after current netlist and SDF are available."),
]

checklist = FINAL / "Artifact_Checklist.csv"
with checklist.open("w", newline="", encoding="utf-8") as f:
    w = csv.writer(f)
    w.writerow(["Artifact_or_measurement", "Status", "Collected_path", "Interpretation"])
    for label, path, note in items:
        status = "PRESENT_REVIEW_CONTENT" if present(path) else "MISSING"
        w.writerow([label, status, str(path.relative_to(FINAL)), note])

summary = FINAL / "01_Run_Summary.txt"
gds = FINAL / "06_GDS_and_Physical_Outputs" / "Final_TRNG_Layout.gds"

summary.write_text(
    "TRNG OPENLANE RERUN SUMMARY\n"
    "===========================\n\n"
    f"Run tag: {TAG}\n"
    f"Run directory: {RUN}\n"
    f"Flow exit code: {rc}\n"
    f"GDS from current run collected: {'YES' if gds.exists() else 'NO'}\n\n"
    "Important: file presence does not prove that timing, power, DRC, LVS,\n"
    "or SDF annotation passed. Review Artifact_Checklist.csv and the raw logs.\n",
    encoding="utf-8"
)

missing = FINAL / "MISSING_MEASUREMENTS_AND_VALIDATION.md"
with missing.open("w", encoding="utf-8") as f:
    f.write("# Missing measurements and validation checklist\n\n")
    f.write(f"**Current run tag:** `{TAG}`\n\n")
    f.write(f"**Flow exit code recorded:** `{rc}`\n\n")
    f.write("## Artifact status\n\n")
    f.write("See `Artifact_Checklist.csv` for a file-by-file inventory. ")
    f.write("A present file is not automatically a passing result.\n\n")
    f.write("## Measurements to extract and verify manually\n\n")
    f.write("- [ ] Mapped standard-cell count, cell-type breakdown, flip-flop count and synthesized cell area.\n")
    f.write("- [ ] Final die/core area, utilization, total physical-cell count and routed metal/via metrics where available.\n")
    f.write("- [ ] Setup WNS/TNS, hold slack, clock period, critical paths, timing corner and applicable exceptions.\n")
    f.write("- [ ] Total/internal/switching/leakage power, power units, PVT corner and activity-estimation assumptions.\n")
    f.write("- [ ] Magic DRC count and run completion; KLayout DRC count and run completion; LVS comparison result; antenna checks.\n")
    f.write("- [ ] IR-drop values and confirmation that supply-source assumptions are documented.\n")
    f.write("- [ ] Post-synthesis gate-level simulation result, compilation log and waveform, if supported.\n")
    f.write("- [ ] Post-layout SDF annotation result, annotation warnings/errors, simulation log and waveform, if supported.\n")
    f.write("- [ ] Tool versions, PDK revision, source/configuration hashes and exact run tag.\n\n")
    f.write("## Evidence that is not provided by RTL-to-GDS alone\n\n")
    f.write("- [ ] Statistical randomness and entropy assessment using your separate UART/NIST datasets.\n")
    f.write("- [ ] Cadence RTL-to-GDS results for the consolidated comparison.\n\n")
    f.write("## Interpretation rules\n\n")
    f.write("- A GDS that opens in KLayout does not establish that the flow completed.\n")
    f.write("- A missing or empty DRC report is not a zero-violation result.\n")
    f.write("- A positive setup slack does not establish that hold timing is clean.\n")
    f.write("- Power is an estimate unless a documented measurement process was used.\n")
    f.write("- SDF simulation is additional evidence, not a substitute for STA.\n")

# File inventory and SHA-256 manifest.
files = sorted(p for p in FINAL.rglob("*") if p.is_file())
with (FINAL / "File_Inventory.txt").open("w", encoding="utf-8") as f:
    for p in files:
        f.write(f"{p.relative_to(FINAL)}\t{p.stat().st_size} bytes\n")

with (FINAL / "SHA256SUMS.txt").open("w", encoding="utf-8") as f:
    for p in files:
        if p.name == "SHA256SUMS.txt":
            continue
        digest = hashlib.sha256(p.read_bytes()).hexdigest()
        f.write(f"{digest}  {p.relative_to(FINAL)}\n")

(FINAL / "00_READ_ME_FIRST.txt").write_text(
    "TRNG OpenLane paper rerun\n"
    "Start with 01_Run_Summary.txt and Artifact_Checklist.csv.\n"
    "Read MISSING_MEASUREMENTS_AND_VALIDATION.md before reporting results.\n"
    "All raw reports/logs are preserved in 09_Run_Logs_and_Raw_Reports.\n"
    "The complete run remains under design/runs/<RUN_TAG>/.\n"
    f"Current run tag: {TAG}\n",
    encoding="utf-8"
)

print("\nCollection completed.")
print("Run tag:", TAG)
print("Run directory:", RUN)
print("Final folder:", FINAL)
print("Summary:", summary)
print("Checklist:", checklist)
print("Missing-measurements report:", missing)
