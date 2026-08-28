#!/usr/bin/env python3
"""Fixture test for tools/natc_compile.py — pure helpers (no MWCC invocation).

Grounded in real callables: mispin_suspect (T19 discriminator warning) and
cache_path (content-addressed object cache). Neither touches the compiler or
the canonical tree; this is a regression guard for the contract's "fixture
test required" rule, run in <1s.
"""
import importlib.util
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))


def _load():
    spec = importlib.util.spec_from_file_location(
        "natc_compile", REPO / "tools/natc_compile.py"
    )
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


def test_mispin_suspect_no_signal():
    m = _load()
    # no_signal carries no evidence -> never a suspect (T19)
    assert m.mispin_suspect("GC/1.2.5n", "GC/1.2.5n", no_signal=True) is False


def test_mispin_suspect_agreement():
    m = _load()
    # pin and winner agree -> not a suspect
    assert m.mispin_suspect("GC/1.2.5n", "GC/1.2.5n", no_signal=False) is False


def test_mispin_suspect_disagreement():
    m = _load()
    # winner's tail != pinned tail -> suspect (the fn_80071C04 / MTXHead case)
    assert m.mispin_suspect("GC/1.2.5n", "GC/1.3.2", no_signal=False) is True


def test_cache_path_deterministic(tmp_path):
    m = _load()
    src = tmp_path / "c.c"
    src.write_text("int f(void){return 0;}\n")
    argv_json = '["mwcceppc.exe","-O4","-S","-c","c.c"]'
    a = m.cache_path(str(src), argv_json, "GC/1.2.5n", False)
    b = m.cache_path(str(src), argv_json, "GC/1.2.5n", False)
    assert a == b  # deterministic content-address
    assert a.endswith(".o")
    # sjis flag changes the address (T16 route is distinct)
    c = m.cache_path(str(src), argv_json, "GC/1.2.5n", True)
    assert c != a
