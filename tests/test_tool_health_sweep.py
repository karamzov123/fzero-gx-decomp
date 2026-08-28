#!/usr/bin/env python3
"""Fixture test for tools/tool_health_sweep.py.

Exercises the recogniser without re-running every tool's 200-300s self-test:
it drives run_one() against the sweep's own parser on canned outputs, and
confirms discover() finds the self-test tools in-tree.
"""
from __future__ import annotations

import importlib.util
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parent.parent
TOOLS = REPO / "tools"

spec = importlib.util.spec_from_file_location(
    "tool_health_sweep", TOOLS / "tool_health_sweep.py")
sweep = importlib.util.module_from_spec(spec)
sys.modules["tool_health_sweep"] = sweep
spec.loader.exec_module(sweep)


def test_discover_finds_self_test_tools():
    found = sweep.discover()
    # The four queue tools all ship --self-test and must be discovered.
    for stem in ("find_xrefs", "similar", "emit_m2c_asm", "natc_loop",
                 "carve_guard", "natc_feedback", "natc_gate", "natc_compile",
                 "natc_preflight", "find_slice_unit"):
        assert stem in found, f"{stem} should be discovered as self-test tool"


def test_discover_skips_test_files():
    found = sweep.discover()
    assert not any(t.startswith("test_") for t in found)


def _fake(monkeypatch, ret, out):
    def fake_run(cmd, capture_output=True, text=True, timeout=None):
        class P:
            returncode = ret
            stdout = out
            stderr = ""
        return P()
    monkeypatch.setattr(sweep.subprocess, "run", fake_run)


def test_ok_marker(monkeypatch):
    _fake(monkeypatch, 0, "SELF-TEST OK (context 3195 chars)")
    monkeypatch.setattr(sweep, "has_fixture", lambda t: True)
    r = sweep.run_one("natc_loop")
    assert r["status"] == "OK"


def test_passed_marker(monkeypatch):
    _fake(monkeypatch, 0, "[natc_gate] SELF-TEST PASSED: gate refused and restored")
    monkeypatch.setattr(sweep, "has_fixture", lambda t: True)
    r = sweep.run_one("natc_gate")
    assert r["status"] == "OK"


def test_skip_marker_env_degraded(monkeypatch):
    _fake(monkeypatch, 2, "SKIP: unit not in objdiff.json (probe GXMisc)")
    monkeypatch.setattr(sweep, "has_fixture", lambda t: True)
    r = sweep.run_one("natc_loop")
    assert r["status"] == "SKIP"


def test_fail_crash(monkeypatch):
    _fake(monkeypatch, 1, "Traceback (most recent call last):\n  raise KeyError\n")
    monkeypatch.setattr(sweep, "has_fixture", lambda t: True)
    r = sweep.run_one("natc_loop")
    assert r["status"] == "FAIL"
    assert r["rc"] == 1


def test_quiet_exit_zero_ok(monkeypatch):
    # Tool exits 0, prints no marker -> still OK-ish, BUT the contract requires
    # a fixture; without one it must be flagged NO-FIXTURE (not silently OK).
    _fake(monkeypatch, 0, "done")
    monkeypatch.setattr(sweep, "has_fixture", lambda t: False)
    r = sweep.run_one("quiet")
    assert r["status"] == "NO-FIXTURE"


def test_ok_with_fixture(monkeypatch):
    _fake(monkeypatch, 0, "SELF-TEST OK")
    monkeypatch.setattr(sweep, "has_fixture", lambda t: True)
    r = sweep.run_one("natc_loop")
    assert r["status"] == "OK"


def test_no_fixture_is_yellow_not_red(monkeypatch):
    # NO-FIXTURE must NOT trip the red exit code (only FAIL does).
    _fake(monkeypatch, 0, "SELF-TEST OK")
    monkeypatch.setattr(sweep, "has_fixture", lambda t: False)
    monkeypatch.setattr(sweep, "discover", lambda: ["quiet"])
    monkeypatch.setattr(sys, "argv", ["tool_health_sweep.py"])
    rc = sweep.main()
    assert rc == 0  # yellow gap, not a hard defect
