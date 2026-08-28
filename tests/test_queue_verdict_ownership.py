#!/usr/bin/env python3
"""A terminal verdict belongs to the integrator, with the gate's evidence.

2026-08-28. Workers were transitioning their own batches straight to
'rejected' with a hand-copied first line. 25 rows carry exactly the 20 bytes
"SOURCE-FORM REFUSAL:" and nothing else, while natc_integrate records the real
6,000-character gate transcript for the same class of refusal.

Two losses at once: the diagnostic is destroyed, so nobody can tell WHY the
batch failed; and the batch is marked dead, so the integrator never gates it.
That is the same shape as every other failure this session — a step that
should be mechanical delegated to an agent, done inconsistently.
"""
from __future__ import annotations
import os
import sys
import pytest
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import natc_submission_queue as q  # noqa: E402

FULL = ("SOURCE-FORM REFUSAL:\n  dvdlow.c:__DVDInitWA: changed body lacks "
        "// provenance: ...\n  dvdlow.c: candidate ADDS asm bodies ['X']\n")


def _batch(tmp_path, name="b"):
    d = tmp_path / name
    d.mkdir()
    (d / "u.c").write_text("// dest: src/u.c\nint f(void){return 0;}\n")
    (d / "CARD.md").write_text("# c\n- // provenance: original\n")
    return d


def _claimed(tmp_path, monkeypatch):
    monkeypatch.delenv("NATC_INTEGRATOR", raising=False)
    c = q.open_db(str(tmp_path / "q.sqlite3"))
    q.register(c, "w/b", "w", str(_batch(tmp_path)))
    row = q.claim(c, "w")
    return c, row


def test_worker_cannot_record_a_terminal_verdict(tmp_path, monkeypatch):
    c, row = _claimed(tmp_path, monkeypatch)
    with pytest.raises(PermissionError) as e:
        q.transition(c, "w/b", "rejected", token=row["claim_token"], error=FULL)
    assert "integrator" in str(e.value)
    assert c.execute("select state from batches").fetchone()[0] != "rejected"
    c.close()


def test_integrator_rejection_needs_real_evidence(tmp_path, monkeypatch):
    c, row = _claimed(tmp_path, monkeypatch)
    monkeypatch.setenv("NATC_INTEGRATOR", "1")
    with pytest.raises(ValueError) as e:
        q.transition(c, "w/b", "rejected", token=row["claim_token"],
                     error="SOURCE-FORM REFUSAL:")
    assert "no evidence" in str(e.value)
    c.close()


def test_integrator_with_the_full_transcript_succeeds(tmp_path, monkeypatch):
    c, row = _claimed(tmp_path, monkeypatch)
    monkeypatch.setenv("NATC_INTEGRATOR", "1")
    out = q.transition(c, "w/b", "rejected", token=row["claim_token"], error=FULL)
    assert out["state"] == "rejected"
    assert "provenance" in out["error"], "the reasons must survive"
    c.close()


def test_non_terminal_transitions_are_untouched(tmp_path, monkeypatch):
    """Workers must still be able to move a batch through the live states."""
    monkeypatch.delenv("NATC_INTEGRATOR", raising=False)
    c = q.open_db(str(tmp_path / "q.sqlite3"))
    q.register(c, "w/b", "w", str(_batch(tmp_path)))
    row = q.claim(c, "w")
    out = q.transition(c, "w/b", "gating", token=row["claim_token"])
    assert out["state"] == "gating"
    c.close()
