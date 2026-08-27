#!/usr/bin/env python3
"""natc_preflight must expose a built-in --self-test (house pattern) that
exercises the no-traceback refusal path in-process, matching the other core
tools (find_xrefs, emit_m2c_asm, natc_loop, similar).

A regression that crashes the refusal-evidence writer (finding 255 class) must
surface here, not only via the slower pytest path."""
from __future__ import annotations

import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TOOL = REPO / "tools/natc_preflight.py"


def test_preflight_has_working_self_test():
    r = subprocess.run(
        [sys.executable, str(TOOL), "--self-test"],
        cwd=REPO, capture_output=True, text=True)
    assert r.returncode == 0, f"self-test failed:\n{r.stderr}"
    assert "SELF-TEST OK" in r.stdout, f"no OK marker:\n{r.stdout}{r.stderr}"
    assert "Traceback" not in r.stderr, f"traceback leaked:\n{r.stderr}"


def test_preflight_no_self_test_flag_still_refuses_cleanly():
    # The old entrypoint (--batch ...) must still work after the refactor that
    # moved argparse into __main__ and made main(args) take parsed args.
    missing = REPO / "build" / "GFZE01" / "submissions-nonexistent-xyz"
    r = subprocess.run(
        [sys.executable, str(TOOL), "--batch", str(missing), "--worker", "x"],
        cwd=REPO, capture_output=True, text=True)
    # rc 0 (clean) or 1 (refused); contract is NO traceback regardless.
    assert "Traceback" not in r.stderr, f"traceback leaked:\n{r.stderr}"
    assert r.returncode in (0, 1)
