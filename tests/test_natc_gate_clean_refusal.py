#!/usr/bin/env python3
"""natc_gate must convert a text-only refusal from cheap_checks into a CLEAN
refusal (rc 1, no Traceback), not an uncaught SystemExit that pollutes the
durable queue record.

Regression: main() called cheap_checks() without catching SystemExit. The
helper signals a text-only refusal (no .c candidates / missing CARD / no
provenance / duplicate) by raising SystemExit; because main() let it propagate,
the interpreter printed a Traceback and the integrator's queue wrapper captured
it into the batch error field. 49 of 191 durable-queue batches carried
`[natc_gate] no .c candidates in batch dir` followed by a Traceback. (Finding
258.)"""
from __future__ import annotations
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
GATE = REPO / "tools/natc_gate.py"


def test_empty_batch_refused_cleanly_no_traceback():
    empty = REPO / "build" / "GFZE01" / "submissions-empty-gate-xyz"
    empty.mkdir(parents=True, exist_ok=True)
    r = subprocess.run(
        [sys.executable, str(GATE), "--batch", str(empty), "--worker", "x"],
        cwd=REPO, capture_output=True, text=True)
    assert r.returncode == 1, f"expected rc 1, got {r.returncode}: {r.stderr}"
    assert "Traceback" not in r.stderr, f"traceback leaked:\n{r.stderr}"
    assert "REFUSED" in r.stderr, f"expected clean refusal:\n{r.stderr}"


def test_missing_card_refused_cleanly_no_traceback():
    d = REPO / "build" / "GFZE01" / "submissions-nocard-gate-xyz"
    d.mkdir(parents=True, exist_ok=True)
    (d / "foo.c").write_text("int foo(void){ return 0; }\n")
    r = subprocess.run(
        [sys.executable, str(GATE), "--batch", str(d), "--worker", "x"],
        cwd=REPO, capture_output=True, text=True)
    assert r.returncode == 1, f"expected rc 1, got {r.returncode}: {r.stderr}"
    assert "Traceback" not in r.stderr, f"traceback leaked:\n{r.stderr}"
    assert "REFUSED" in r.stderr, f"expected clean refusal:\n{r.stderr}"
