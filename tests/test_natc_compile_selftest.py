#!/usr/bin/env python3
"""natc_compile must expose a built-in --self-test (house pattern) that locks
the authoritative-command assembly WITHOUT invoking MWCC.

The compile path shells out to mwcc on every conversion-worker attempt. The
most damaging silent failure is a regression in canonical_command() parsing or
the -c/-o substitution: a candidate would then compile under wrong flags and
score 0, looking like a worker plateau rather than a tool bug. Prior to this
test natc_compile was the only core tool with no in-process self-test, so such
a regression could only be caught by an expensive live build. (Finding 259.)"""
from __future__ import annotations
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TOOL = REPO / "tools/natc_compile.py"


def test_self_test_flag_present_and_passes():
    r = subprocess.run(
        [sys.executable, str(TOOL), "--self-test"],
        cwd=REPO, capture_output=True, text=True)
    assert r.returncode == 0, f"self-test failed:\n{r.stderr}"
    assert "SELF-TEST OK" in r.stdout, f"unexpected output:\n{r.stdout}{r.stderr}"


def test_self_test_runs_without_mwcc():
    # must not require --unit/--src and must not invoke the compiler
    r = subprocess.run(
        [sys.executable, str(TOOL), "--self-test"],
        cwd=REPO, capture_output=True, text=True)
    assert "mwcceppc" not in r.stderr.lower()
    assert re.search(r"SELF-TEST OK", r.stdout)


def test_missing_unit_src_errors_outside_self_test():
    r = subprocess.run(
        [sys.executable, str(TOOL)],
        cwd=REPO, capture_output=True, text=True)
    assert r.returncode != 0
    assert "required" in r.stderr
