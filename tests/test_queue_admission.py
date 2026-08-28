#!/usr/bin/env python3
"""A directory that cannot become a batch must be refused at registration.

`no .c candidates in batch dir` is the largest single refusal class in the
queue's history -- 177 of 422 rejections, every one an empty directory that
was registered `ready`, claimed by the integrator, gated, and only then
refused, minutes to hours after the worker that produced it had moved on and
usually after its session had rotated.

The check is deliberately narrow: it asserts only what no later stage can
repair (no candidate at all, no CARD.md) and leaves every judgement about the
CONTENT of those files to preflight and the gate, which own it.
"""
from __future__ import annotations
import sys
import shutil
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import natc_submission_queue as q  # noqa: E402


def _complete(d: Path):
    d.mkdir(parents=True, exist_ok=True)
    (d / "unit.c").write_text("// dest: src/unit.c\nint f(void) { return 0; }\n")
    (d / "CARD.md").write_text("# card\n\n- // provenance: original\n")
    return d


class QueueAdmissionTests(unittest.TestCase):
    def setUp(self):
        self.td = Path(tempfile.mkdtemp())
        self.c = q.open_db(str(self.td / "queue.sqlite3"))

    def tearDown(self):
        self.c.close()
        shutil.rmtree(self.td, ignore_errors=True)

    def test_empty_directory_is_refused(self):
        empty = self.td / "empty"
        empty.mkdir()
        with self.assertRaises(ValueError) as e:
            q.register(self.c, "w/empty", "w", str(empty))
        self.assertIn("no .c candidate", str(e.exception))

    def test_candidate_without_card_is_refused(self):
        d = self.td / "nocard"
        d.mkdir()
        (d / "unit.c").write_text("int f(void) { return 0; }\n")
        with self.assertRaises(ValueError) as e:
            q.register(self.c, "w/nocard", "w", str(d))
        self.assertIn("CARD.md", str(e.exception))

    def test_complete_batch_is_admitted(self):
        row = q.register(self.c, "w/ok", "w", str(_complete(self.td / "ok")))
        self.assertEqual("ready", row["state"])

    def test_nested_candidate_is_admitted(self):
        """The gate learned to discover nested batch layouts (2026-08-26,
        102 rescued batches); admission must not re-introduce the flat-only
        assumption it removed."""
        d = self.td / "nested"
        _complete(d / "inner")
        row = q.register(self.c, "w/nested", "w", str(d))
        self.assertEqual("ready", row["state"])

    def test_admission_does_not_block_reconciliation(self):
        """Re-registering an id the queue already knows is how the integrator
        recovers in-flight work. Admission must apply to NEW ids only."""
        d = _complete(self.td / "again")
        q.register(self.c, "w/again", "w", str(d))
        for f in d.iterdir():
            f.unlink()                       # now an empty directory
        row = q.register(self.c, "w/again", "w", str(d))
        self.assertIn(row["state"], {"ready", "claimed", "gating"})


if __name__ == "__main__":
    unittest.main()
