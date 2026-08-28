#!/usr/bin/env python3
"""Fixture test for tools/natc_gate.py — pure check helpers (no build/gate run).

Grounded in real callables: provenance_check (changed bodies must carry
'// provenance:'), readability_check (goto/volatile/union require justification),
changed_function_names (body diff). All run against temp files; write_flags=False
so the readability review doc is never dirtied. Non-mutating, <1s.
"""
import importlib.util
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))


def _load():
    spec = importlib.util.spec_from_file_location(
        "natc_gate", REPO / "tools/natc_gate.py"
    )
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


def _pair(src_text, dest_text, base):
    cand = base / "_natc_gate_cand_tmp.c"
    dest = base / "_natc_gate_dest_tmp.c"
    cand.write_text(src_text)
    dest.write_text(dest_text)
    return [(cand, dest)]


def test_provenance_check_flags_missing(tmp_path):
    m = _load()
    # dest has Foo; candidate changes Foo but body lacks // provenance: -> error
    src = "int Foo(void) {\n  return 1;\n}\n"
    dest = "int Foo(void) {\n  return 0;\n}\n"
    pairs = _pair(src, dest, tmp_path)
    errs = m.provenance_check(pairs)
    assert any("Foo" in e and "provenance" in e for e in errs)


def test_provenance_check_passes_with_provenance(tmp_path):
    m = _load()
    src = "int Foo(void) {\n  // provenance: original Foo\n  return 1;\n}\n"
    dest = "int Foo(void) {\n  return 0;\n}\n"
    errs = m.provenance_check(_pair(src, dest, tmp_path))
    assert errs == []  # provenance present within the changed body -> clean


def test_readability_check_goto_requires_justification(tmp_path):
    m = _load()
    src = "int Foo(void) {\n  goto bail;\n  bail: return 0;\n}\n"
    dest = "int Foo(void) {\n  return 0;\n}\n"
    errs, _ = m.readability_check(_pair(src, dest, tmp_path), write_flags=False)
    assert any("goto" in e for e in errs)


def test_readability_check_volatile_advisory_not_error(tmp_path):
    m = _load()
    # volatile without adjacent hardware justification is a FLAG, not an error
    src = "int Foo(void) {\n  volatile int x = 0;\n  return x;\n}\n"
    dest = "int Foo(void) {\n  return 0;\n}\n"
    errs, flags = m.readability_check(_pair(src, dest, tmp_path), write_flags=False)
    assert errs == []  # readability flags must not be refusals
    assert any("volatile" in f[2] for f in flags)


def test_changed_function_names_diff(tmp_path):
    m = _load()
    old = "int A(void){return 0;}\nint B(void){return 1;}\n"
    new = "int A(void){return 0;}\nint B(void){return 2;}\n"
    changed = m.changed_function_names(old, new)
    assert "B" in changed and "A" not in changed
