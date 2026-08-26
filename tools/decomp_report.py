#!/usr/bin/env python3
"""Add public mission metrics to an objdiff v2 progress report.

The original objdiff measures remain untouched and are exposed as ``diagnostic``.
Two additional categories are derived from report functions and committed source:

* ``natural-c``: non-asm functions, with exact byte matches counted strictly.
* ``c-expressed``: non-asm functions with source bodies, with fuzzy progress
  retained as a supplemental view.

This script needs only the public checkout, report JSON, and source files. It
never reads a DOL, private cache, supervisor state, or local environment path.
"""
import argparse
import copy
import json
import re
from pathlib import Path

ASM_DEF = re.compile(
    r"(?<!extern\s)\b(?:static\s+)?asm\s+(?:static\s+)?"
    r"[A-Za-z_][\w \t*]*?\b(\w+)\s*\(", re.MULTILINE,
)
GAP_NAME = re.compile(r"^gap_|_pad(?:$|_)", re.IGNORECASE)


def asm_names(path):
    if not path or not path.exists():
        return set()
    return {m.group(1) for m in ASM_DEF.finditer(path.read_text(errors="replace"))}


def number(value):
    return float(value or 0)


def measures(functions, total_code, total_functions, fuzzy=False):
    matched_code = 0.0
    complete_code = 0
    matched_functions = 0
    for f in functions:
        size = int(f.get("size", 0) or 0)
        pct = number(f.get("fuzzy_match_percent"))
        if fuzzy:
            matched_code += size * pct / 100.0
        elif pct >= 100.0:
            matched_code += size
        if pct >= 100.0:
            complete_code += size
            matched_functions += 1
    matched_code = int(round(matched_code))
    return {
        "fuzzy_match_percent": round(100.0 * matched_code / total_code, 5) if total_code else 100.0,
        "total_code": str(total_code),
        "matched_code": str(matched_code),
        "matched_code_percent": round(100.0 * matched_code / total_code, 5) if total_code else 100.0,
        "total_functions": total_functions,
        "matched_functions": matched_functions,
        "matched_functions_percent": round(100.0 * matched_functions / total_functions, 5) if total_functions else 100.0,
        "complete_code": str(complete_code),
        "complete_code_percent": round(100.0 * complete_code / total_code, 5) if total_code else 100.0,
        "total_units": total_functions,
        "complete_units": matched_functions,
    }


def build_categories(report, root):
    natural = []
    expressed = []
    for unit in report.get("units", []):
        source = unit.get("metadata", {}).get("source_path")
        names = asm_names(root / source) if source else set()
        for function in unit.get("functions", []):
            name = function.get("name", "")
            if not name or GAP_NAME.search(name) or name in names:
                continue
            expressed.append(function)
            natural.append(function)
    diagnostic = copy.deepcopy(report.get("measures", {}))
    totals = report.get("measures", {})
    total_code = int(totals.get("total_code", 0) or 0)
    total_functions = int(totals.get("total_functions", 0) or 0)
    return [
        {"id": "diagnostic", "name": "Diagnostic objdiff", "measures": diagnostic},
        {"id": "natural-c", "name": "Exact natural C", "measures": measures(natural, total_code, total_functions)},
        {"id": "c-expressed", "name": "C-expressed (fuzzy supplemental)", "measures": measures(expressed, total_code, total_functions, fuzzy=True)},
    ]


def dol_data_measures(root, total_data):
    """Compare initialized DOL data and account for structurally equal BSS."""
    original = root / "orig" / "GFZE01" / "sys" / "main.dol"
    built = root / "build" / "GFZE01" / "main.dol"
    if not original.is_file() or not built.is_file():
        raise FileNotFoundError(f"DOL pair required for data progress: {original}, {built}")

    original_bytes = original.read_bytes()
    built_bytes = built.read_bytes()
    if len(original_bytes) < 0xe0 or len(built_bytes) < 0xe0:
        raise ValueError("DOL header is truncated")

    initialized_total = 0
    initialized_matched = 0
    for index in range(7):
        file_offset = int.from_bytes(original_bytes[0x1c + index * 4:0x20 + index * 4], "big")
        size = int.from_bytes(original_bytes[0xac + index * 4:0xb0 + index * 4], "big")
        if not size:
            continue
        end = file_offset + size
        if end > len(original_bytes) or end > len(built_bytes):
            raise ValueError("DOL data section exceeds file size")
        initialized_total += size
        initialized_matched += sum(
            left == right
            for left, right in zip(original_bytes[file_offset:end], built_bytes[file_offset:end])
        )

    bss_address = int.from_bytes(original_bytes[0xd8:0xdc], "big")
    bss_size = int.from_bytes(original_bytes[0xdc:0xe0], "big")
    built_bss_address = int.from_bytes(built_bytes[0xd8:0xdc], "big")
    built_bss_size = int.from_bytes(built_bytes[0xdc:0xe0], "big")
    report_total = int(total_data or 0)
    bss_report_size = max(0, report_total - initialized_total)
    bss_matched = bss_report_size if (bss_address, bss_size) == (built_bss_address, built_bss_size) else 0
    matched = min(report_total, initialized_matched + bss_matched)
    return {
        "total_data": str(report_total),
        "matched_data": str(matched),
        "matched_data_percent": round(100.0 * matched / report_total, 5) if report_total else 100.0,
        "complete_data": str(matched),
        "complete_data_percent": round(100.0 * matched / report_total, 5) if report_total else 100.0,
    }


def apply_mission_headline(report, categories, root):
    """Make decomp.dev's headline the honest mission metric.

    Keep the original objdiff measures untouched in ``diagnostic`` and add a
    byte-weighted data comparison from the original and rebuilt DOLs.
    """
    natural = next(c["measures"] for c in categories if c["id"] == "natural-c")
    total_data = report.get("measures", {}).get("total_data", 0)
    natural.update(dol_data_measures(root, total_data))
    report["measures"] = natural


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--report", required=True, type=Path)
    parser.add_argument("--root", required=True, type=Path)
    parser.add_argument("--out", required=True, type=Path)
    args = parser.parse_args()
    report = json.loads(args.report.read_text())
    if report.get("version") != 2:
        raise SystemExit("expected objdiff report version 2")
    categories = build_categories(report, args.root)
    report["categories"] = categories
    apply_mission_headline(report, categories, args.root)
    args.out.write_text(json.dumps(report, indent=2) + "\n")


if __name__ == "__main__":
    main()
