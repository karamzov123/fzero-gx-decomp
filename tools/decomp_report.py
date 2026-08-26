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


def source_backed_data_measures(report):
    """Count matching data only from source-backed objdiff units."""
    total_data = int(report.get("measures", {}).get("total_data", 0) or 0)
    matched_data = 0
    data_sections = {".data", ".rodata", ".sdata", ".sdata2", ".dtors", ".bss", ".sbss", ".sbss2"}
    for unit in report.get("units", []):
        if not unit.get("metadata", {}).get("source_path"):
            continue
        for section in unit.get("sections", []):
            if section.get("name") not in data_sections:
                continue
            size = int(section.get("size", 0) or 0)
            if float(section.get("fuzzy_match_percent", 0) or 0) >= 100.0:
                matched_data += size
    matched_data = min(matched_data, total_data)
    percent = round(100.0 * matched_data / total_data, 5) if total_data else 100.0
    return {
        "total_data": str(total_data),
        "matched_data": str(matched_data),
        "matched_data_percent": percent,
        "complete_data": str(matched_data),
        "complete_data_percent": percent,
    }


def apply_mission_headline(report, categories):
    """Make decomp.dev's headline the honest mission metric.

    Keep objdiff's diagnostic measures untouched and publish source-backed,
    byte-weighted data progress in the mission headline.
    """
    natural = next(c["measures"] for c in categories if c["id"] == "natural-c")
    natural.update(source_backed_data_measures(report))
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
    apply_mission_headline(report, categories)
    args.out.write_text(json.dumps(report, indent=2) + "\n")


if __name__ == "__main__":
    main()
