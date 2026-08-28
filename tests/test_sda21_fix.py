#!/usr/bin/env python3
"""Fixture test for tools/sda21_fix.py — apply_sda21_fix() core logic.

Synthetic, non-mutating. Mirrors the contract's declaration-shape recipe: a
bare sda21 displacement operand must become the SDK symbol name with a sized
extern, and unknown/local symbols must be left untouched (never fabricated).
"""
import importlib.util
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))


def _load():
    spec = importlib.util.spec_from_file_location(
        "sda21_fix", REPO / "tools/sda21_fix.py"
    )
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


def _diff(lfmt, rfmt):
    return {
        "left": {"symbols": [{"instructions": [{"instruction": {"formatted": lfmt}}]}]},
        "right": {"symbols": [{"instructions": [{"instruction": {"formatted": rfmt}}]}]},
    }


def test_replace_known_symbol():
    m = _load()
    syms = {0x801AEE44: ("gx", 4, "global")}
    src = "void f(void) {\n    lwz r5, 0x04(r2);\n}\n"
    new, nrep, nsites, skipped = m.apply_sda21_fix(
        src, _diff("lwz r5, gx@sda21", "lwz r5, 0x04(r2)"), syms
    )
    assert nrep == 1
    assert "gx(r2)" in new
    assert "extern unsigned char gx[4];" in new
    assert skipped == 0


def test_skip_unknown_symbol():
    m = _load()
    syms = {}
    src = "void f(void) {\n    lwz r5, 0x10(r2);\n}\n"
    new, nrep, _, skipped = m.apply_sda21_fix(
        src, _diff("lwz r5, unk@sda21", "lwz r5, 0x10(r2)"), syms
    )
    assert nrep == 0
    assert skipped == 1
    assert "unk(r2)" not in new


def test_skip_offset_suffixed_name():
    m = _load()
    # Offset-suffixed retail names (sym+0x4) are MWCC-unreachable: the site is
    # skipped before any edit is recorded, so the ours-side operand is preserved
    # untouched (the code never invents a name for it).
    syms = {0x801AEE48: ("gx", 4, "global")}
    src = "void f(void) {\n    lwz r5, 0x08(r2);\n}\n"
    new, nrep, nsites, skipped = m.apply_sda21_fix(
        src, _diff("lwz r5, gx+0x4@sda21", "lwz r5, 0x08(r2)"), syms
    )
    assert nrep == 0
    assert "gx(r2)" not in new  # no invented name
    assert "0x08(r2)" in new    # original displacement preserved (not rewritten)


def test_r13_base_resolves():
    m = _load()
    syms = {0x801AE3C4: ("foo", 8, "global")}
    src = "void f(void) {\n    stw r4, 0x04(r13);\n}\n"
    new, nrep, _, _ = m.apply_sda21_fix(
        src, _diff("stw r4, foo@sda21", "stw r4, 0x04(r13)"), syms
    )
    assert nrep == 1
    assert "foo(r13)" in new
    assert "extern unsigned char foo[8];" in new
