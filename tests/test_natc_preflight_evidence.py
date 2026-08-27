#!/usr/bin/env python3
"""natc_preflight refusal-evidence write must never crash.

Regression: when the batch dir disappears between the refusal decision and the
PREFLIGHT.md write (TOCTOU: gate archives the batch, or the dir is a symlink
whose target vanished), the old code raised FileNotFoundError and polluted the
durable queue record with a traceback instead of a clean refusal. The refusal
is the deliverable; the evidence file is a convenience. (finding: 2026-08-26
queue dump showed ~40 tracebacks from this path.)
"""
from __future__ import annotations
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TOOL = REPO / "tools/natc_preflight.py"


def test_missing_batch_dir_refuses_without_traceback():
    # A batch dir that does not exist: cheap_checks refuses "no .c candidates",
    # and the evidence write must NOT raise.
    missing = REPO / "build" / "GFZE01" / "submissions-nonexistent-xyz"
    r = subprocess.run(
        [sys.executable, str(TOOL), "--batch", str(missing), "--worker", "x"],
        cwd=REPO, capture_output=True, text=True)
    # rc may be 1 (refused) or 0 depending on gate; the contract is NO traceback.
    assert "Traceback" not in r.stderr, f"traceback leaked:\n{r.stderr}"
    assert "REFUSED" in r.stderr or r.returncode == 0


def test_evidence_write_is_oerror_safe(monkeypatch):
    # Directly exercise the helper: if write_text raises OSError, the function
    # must swallow it (stderr note) and not propagate.
    import time
    import importlib.util
    spec = importlib.util.spec_from_file_location("natc_preflight_mod", TOOL)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)

    class BombDir:
        def is_dir(self):
            return True

        def __truediv__(self, name):
            class BombFile:
                def write_text(self, text):
                    raise FileNotFoundError("[Errno 2] simulated TOCTOU")
            return BombFile()

    # Should not raise.
    mod._write_refusal_evidence(BombDir(), "refused reason")


if __name__ == "__main__":
    import pytest
    raise SystemExit(pytest.main([__file__, "-q"]))
