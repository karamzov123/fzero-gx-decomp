import importlib.util
import json
import sqlite3
import tempfile
import time
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location("queue", ROOT / "tools/natc_submission_queue.py")
assert spec is not None and spec.loader is not None
queue = importlib.util.module_from_spec(spec)
spec.loader.exec_module(queue)


class QueueTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        self.batch = self.root / "w1" / "b1"
        self.batch.mkdir(parents=True)
        (self.batch / "CARD.md").write_text("batch\n")
        (self.batch / "foo.c").write_text("int foo(void) { return 1; }\n")
        self.db = queue.open_db(self.root / "queue.sqlite3")

    def tearDown(self):
        self.db.close(); self.tmp.cleanup()

    def test_register_and_sync_are_immutable(self):
        row = queue.register(self.db, "b1", "w1", self.batch)
        self.assertEqual(row["state"], "ready")
        self.assertEqual(queue.sync(self.db, "b1")["content_sha256"], row["content_sha256"])
        (self.batch / "foo.c").write_text("int foo(void) { return 2; }\n")
        with self.assertRaises(ValueError): queue.sync(self.db, "b1")
        with self.assertRaises(ValueError): queue.register(self.db, "b1", "other", self.batch)

    def test_atomic_claim_and_token_guarded_state_machine(self):
        queue.register(self.db, "b1", "w1", self.batch)
        claimed = queue.claim(self.db, "w1", 60)
        self.assertEqual(claimed["state"], "claimed")
        token = claimed["claim_token"]
        with self.assertRaises(PermissionError): queue.transition(self.db, "b1", "gating", "wrong")
        queue.transition(self.db, "b1", "gating", token)
        out = queue.transition(self.db, "b1", "accepted", token, {"gate": "green"})
        self.assertEqual(out["state"], "accepted")
        self.assertEqual(json.loads(out["result_json"]), {"gate": "green"})
        with self.assertRaises(ValueError): queue.transition(self.db, "b1", "rejected", token)

    def test_expired_claim_becomes_recovery_required_and_can_be_reclaimed(self):
        queue.register(self.db, "b1", "w1", self.batch)
        claimed = queue.claim(self.db, "w1", 1)
        count = queue.recover(self.db, time.time() + 2)
        self.assertEqual(count, 1)
        self.assertEqual(queue.get(self.db, "b1")["state"], "recovery-required")
        reclaimed = queue.claim(self.db, "w2", 60)
        self.assertEqual(reclaimed["state"], "claimed")
        self.assertEqual(reclaimed["worker"], "w2")

    def test_tokenless_inflight_claim_is_recoverable(self):
        queue.register(self.db, "b1", "w1", self.batch)
        self.db.execute("UPDATE batches SET state='gating', claim_token=NULL, claim_until=NULL WHERE batch_id='b1'")
        self.db.commit()
        self.assertEqual(queue.recover(self.db), 1)
        row = queue.get(self.db, "b1")
        self.assertEqual(row["state"], "recovery-required")
        reclaimed = queue.claim(self.db, "w2", 60)
        self.assertEqual(reclaimed["state"], "claimed")
        self.assertEqual(reclaimed["worker"], "w2")

    def test_claim_is_single_consumer_across_connections(self):
        queue.register(self.db, "b1", "w1", self.batch)
        other = queue.open_db(self.root / "queue.sqlite3")
        try:
            first = queue.claim(self.db, "w1")
            self.assertIsNotNone(first)
            self.assertIsNone(queue.claim(other, "w2"))
        finally:
            other.close()

    def test_sync_tree_reconciles_missing_batch_without_row_api_crash(self):
        queue.register(self.db, "w1/missing", "w1", self.batch)
        self.batch.rename(self.root / "w1" / "missing-archived")
        rows = queue.sync_tree(self.db, self.root)
        self.assertEqual(rows[0]["batch_id"], "w1/missing-archived")
        row = queue.get(self.db, "w1/missing")
        self.assertEqual(row["state"], "rejected")
        self.assertIn("archived or removed", row["error"])

    def test_sync_tree_discovers_nested_harvest_batches(self):
        nested = self.root / "w1" / "harvest-1" / "unit"
        nested.mkdir(parents=True)
        (nested / "CARD.md").write_text("complete-unit: yes\n")
        (nested / "unit.c").write_text("int target(void) { return 1; }\n")
        rows = queue.sync_tree(self.db, self.root)
        self.assertIn("w1/harvest-1-unit", {row["batch_id"] for row in rows})
        self.assertEqual(queue.get(self.db, "w1/harvest-1-unit")["state"], "ready")

    def test_claim_empty_and_terminal_result_error(self):
        self.assertIsNone(queue.claim(self.db, "w1"))
        queue.register(self.db, "b1", "w1", self.batch)
        row = queue.claim(self.db, "w1")
        row = queue.transition(self.db, "b1", "rejected", row["claim_token"], error="red gate")
        self.assertEqual(row["error"], "red gate")
        self.assertEqual(len(queue.list_batches(self.db, "rejected")), 1)


if __name__ == "__main__": unittest.main()
