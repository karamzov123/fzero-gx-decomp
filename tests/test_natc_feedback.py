#!/usr/bin/env python3
"""Fixture tests for tools/natc_feedback.py (item 4 supporting tool).

Locks the diff-classification precedence from NATC-STRATEGY §4 without
invoking MWCC/objdiff. Each case drives classify() with a hand-built
target/candidate symbol dict exercising exactly one branch, mirrors
natc_feedback.py --self-test, and the round-trip test exercises the JSON
output path through side_symbols().

Run: uv run --with capstone --with pytest python3 -m pytest tests/test_natc_feedback.py -q
"""

import json
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
import natc_feedback as nf  # noqa: E402


def _mk(instrs, relocs=None, score=0, size=0):
    return {"instrs": instrs, "relocs": relocs or [], "score": score, "size": size}


EXACT = _mk(["lwz r5, gx@sda21(0)", "blr"], [("R_PPC_EMB_SDA21", "gx")])
EXACT_C = _mk(["lwz r5, gx@sda21(0)", "blr"], [("R_PPC_EMB_SDA21", "gx")])

RELOC_TEXT = _mk(["lwz r5, gx@sda21(0)", "blr"], [("R_PPC_EMB_SDA21", "gx")])
RELOC_C = _mk(["lwz r5, gx@sda21(0)", "blr"], [("R_PPC_ADDR16_LO", "gx")])

RELOC_SDA = _mk(["addi r3,r3,0", "lwz r5, gx@sda21(0)", "blr"], [("R_PPC_EMB_SDA21", "gx")])
RELOC_SDA_C = _mk(["addi r3,r3,0", "lwz r5, foo@sda21(0)", "blr"], [("R_PPC_EMB_SDA21", "foo")])

PROLOGUE_T = _mk(["stwu r1,-0x10(r1)", "mflr r0", "stmw r28,0x8(r1)", "blr"])
PROLOGUE_C = _mk(["mflr r0", "stmw r28,0x8(r1)", "blr"])

CFG_T = _mk(["addis r3,r3,0"] * 10 + ["a"] * 20)
CFG_C = _mk(["addis r3,r3,0"] * 10 + ["b"] * 18)

SCHED_T = _mk(["add r3,r3,r4", "sub r3,r3,r5", "blr"])
SCHED_C = _mk(["sub r3,r3,r5", "add r3,r3,r4", "blr"])

REGALLOC_T = _mk(["lwz r3,0(r4)", "lwz r5,4(r4)", "blr"])
REGALLOC_C = _mk(["lwz r5,0(r4)", "lwz r3,4(r4)", "blr"])

REGALLOC2_T = _mk(["lwz r3,0(r4)", "addi r3,r3,1", "mullw r3,r3,r3",
                   "oris r3,r3,0", "blr"])
REGALLOC2_C = _mk(["lwz r3,0(r4)", "addi r3,r3,1", "mulli r3,r3,2",
                   "oris r3,r3,0", "blr"])

INSTR_T = _mk(["lwz r3,0(r4)", "add r3,r3,r5", "blr"])
INSTR_C = _mk(["stw r3,0(r4)", "sub r3,r3,r5", "blr"])


@pytest.mark.parametrize("t,c,expected", [
    (EXACT, EXACT_C, "exact"),
    (RELOC_TEXT, RELOC_C, "reloc_shape"),
    (RELOC_SDA, RELOC_SDA_C, "reloc_shape"),
    (PROLOGUE_T, PROLOGUE_C, "prologue"),
    (CFG_T, CFG_C, "cfg"),
    (SCHED_T, SCHED_C, "sched"),
    (REGALLOC_T, REGALLOC_C, "regalloc"),
    (REGALLOC2_T, REGALLOC2_C, "regalloc"),
    (INSTR_T, INSTR_C, "instr_select"),
])
def test_classify_precedence(t, c, expected):
    k, fd, win = nf.classify(t, c)
    assert k == expected, f"{expected} misclassified as {k}"
    if expected == "cfg":
        assert fd == 10, f"first_div wrong: {fd}"
    # non-exact classes must still produce a window
    if expected != "exact":
        assert isinstance(win, list) and len(win) >= 1


def test_exact_requires_reloc_equality():
    # identical text but relocs differ -> reloc_shape, not exact
    t = _mk(["lwz r5, gx@sda21(0)", "blr"], [("R_PPC_EMB_SDA21", "gx")])
    c = _mk(["lwz r5, gx@sda21(0)", "blr"], [("R_PPC_ADDR16_LO", "gx")])
    k, _, _ = nf.classify(t, c)
    assert k == "reloc_shape"


def test_side_symbols_extracts_relocs():
    raw = {"symbols": [
        {"name": "fn_x", "size": 8, "match_percent": 50.0,
         "instructions": [
             {"instruction": {"formatted": "lwz r5, gx@sda21(0)",
                              "relocation": {"type_name": "R_PPC_EMB_SDA21", "target_symbol": "gx"}}},
             {"instruction": {"formatted": "blr", "relocation": None}},
         ]}]}
    out = nf.side_symbols(raw, symbol="fn_x")
    assert "fn_x" in out
    assert out["fn_x"]["relocs"] == [("R_PPC_EMB_SDA21", "gx")]
    assert out["fn_x"]["instrs"][0].startswith("lwz r5, gx@sda21(0)")
    # symbol filter works
    assert nf.side_symbols(raw, symbol="other") == {}


def test_json_roundtrip_classify():
    """classify output is JSON-serialisable (the tool emits JSON per symbol)."""
    k, fd, win = nf.classify(INSTR_T, INSTR_C)
    blob = json.dumps({"class": k, "first_divergence_index": fd, "window": win})
    loaded = json.loads(blob)
    assert loaded["class"] == "instr_select"
    assert loaded["window"][0]["target"].startswith("lwz")
