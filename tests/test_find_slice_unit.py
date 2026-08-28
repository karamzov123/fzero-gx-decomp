#!/usr/bin/env python3
"""Fixture test for tools/find_slice_unit.py — slice_unit() read-only behaviour.

Grounded in the real slice_unit(unit_name): it pre-slices a unit's still-asm
functions into the cslice cache (read-only over build/ objects, never writes
src/, idempotent on re-run). We assert it succeeds and is idempotent against a
real unit present in this tree's objdiff.json — no tree mutation, <30s cold.
"""
import importlib.util
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))

# A small, stable unit with asm-bodied functions in this tree's objdiff.json.
_UNIT = "main/dolphin/gx/GXMisc"


def _load():
    spec = importlib.util.spec_from_file_location(
        "find_slice_unit", REPO / "tools/find_slice_unit.py"
    )
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


@pytest.mark.skipif(
    not (REPO / "objdiff.json").exists(),
    reason="objdiff.json absent in this working tree",
)
def test_slice_unit_succeeds_and_idempotent():
    m = _load()
    rc1 = m.slice_unit(_UNIT)
    assert rc1 == 0  # sliced without error
    # Re-run must not crash and must remain a success (cache is idempotent).
    rc2 = m.slice_unit(_UNIT)
    assert rc2 == 0


@pytest.mark.skipif(
    not (REPO / "objdiff.json").exists(),
    reason="objdiff.json absent in this working tree",
)
def test_slice_unit_unknown_unit_returns_2():
    m = _load()
    assert m.slice_unit("this/unit/does/not/exist") == 2
