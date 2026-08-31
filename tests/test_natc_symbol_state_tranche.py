#!/usr/bin/env python3
"""The tranche lane in the symbol selector (finding 257, item 6).

156 symbols sit in `inline_asm_required`. They are excluded from --next by
design: a worker asking for natural-C work must never be handed a function
that pure C cannot express, or it burns a 12-attempt budget on a problem as
posed that has no solution.

But that also meant NOTHING could ever reach them. --tranche is the opposite
door: it returns only those symbols, so the inline-asm completion lane is
worked deliberately by a worker that asked for it, and the default lane is
byte-for-byte unchanged.
"""
import importlib.util
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))


def _load():
    spec = importlib.util.spec_from_file_location(
        "natc_symbol_state", REPO / "tools/natc_symbol_state.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


SYMS = ["Alpha", "Beta", "Gamma", "Delta"]
STATES = {"Alpha": "terminal", "Beta": "inline_asm_required",
          "Gamma": "inline_asm_required"}
COUNTS = {"Delta": 3}


def test_default_lane_excludes_inline_asm_required():
    m = _load()
    nxt, blocked = m.choose(SYMS, STATES, COUNTS, tranche=False)
    assert nxt == "Delta"
    assert {"Alpha", "Beta", "Gamma"} <= set(blocked)


def test_tranche_lane_returns_only_inline_asm_required():
    m = _load()
    nxt, _ = m.choose(SYMS, STATES, COUNTS, tranche=True)
    assert nxt in ("Beta", "Gamma")


def test_tranche_lane_never_returns_a_terminal_symbol():
    m = _load()
    nxt, _ = m.choose(["Alpha"], {"Alpha": "terminal"}, {}, tranche=True)
    assert nxt is None


def test_tranche_lane_never_returns_an_unclassified_symbol():
    # A symbol with no state has not been shown to need inline asm. Handing it
    # to the tranche would let a worker write inline asm for a function plain C
    # could express -- which the gate refuses anyway (test_natc_gate_inline_asm
    # _tranche), so offering it would only burn the attempt.
    m = _load()
    nxt, _ = m.choose(["Epsilon"], {}, {}, tranche=True)
    assert nxt is None


def test_tranche_lane_respects_the_attempt_budget():
    m = _load()
    nxt, _ = m.choose(["Beta"], {"Beta": "inline_asm_required"}, {"Beta": 12},
                      tranche=True)
    assert nxt is None


def test_default_lane_is_unchanged_when_nothing_is_blocked():
    m = _load()
    nxt, blocked = m.choose(["Zeta"], {}, {}, tranche=False)
    assert nxt == "Zeta" and blocked == []
