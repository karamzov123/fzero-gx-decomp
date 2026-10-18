"""An expired claim must not receive a subsequent worker's attempt telemetry."""
import os
from pathlib import Path
import sys
import tempfile
import unittest

PROJECT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(PROJECT / 'tools'))
from fzgx.ledger import Ledger


class AttemptIsolationTests(unittest.TestCase):
    def setUp(self):
        scratch = Path(os.environ.get('TMPDIR', str(Path.home() / '.hermes/cache/scratch')))
        scratch.mkdir(parents=True, exist_ok=True)
        self.tmp = tempfile.TemporaryDirectory(dir=scratch)
        self.ledger = Ledger(Path(self.tmp.name) / 'ledger.db')
        self.ledger.sync_functions([dict(symbol='fn', module='main', addr=0, size=4)])

    def tearDown(self):
        self.ledger.db.close()
        self.tmp.cleanup()

    def test_reclaimed_attempt_does_not_inherit_or_overwrite_expired_telemetry(self):
        ledger = self.ledger
        ledger.claim('fn', 'old-worker', ttl=1, max_attempts=10)
        ledger.bump_checks('fn', 75.0)
        old = dict(ledger.current_attempt('fn'))
        ledger.db.execute("UPDATE functions SET claimed_at=0 WHERE symbol='fn'")

        ledger.claim('fn', 'new-worker', ttl=3600, max_attempts=10)
        current = ledger.current_attempt('fn')
        self.assertNotEqual(current['id'], old['id'])
        ledger.bump_checks('fn', 90.0)
        ledger.finish('fn', 'released', 'unmatched', notes='new worker evidence',
                      model='new-model', harness='new-harness', tokens_in=17)

        previous = dict(ledger.db.execute('SELECT * FROM attempts WHERE id=?', (old['id'],)).fetchone())
        self.assertEqual(previous['checks'], old['checks'])
        self.assertEqual(previous['final_percent'], old['final_percent'])
        self.assertEqual(previous['best_in_attempt'], old['best_in_attempt'])
        self.assertEqual(previous['stale_checks'], old['stale_checks'])
        self.assertEqual(previous['model'], old['model'])
        self.assertEqual(previous['harness'], old['harness'])
        self.assertEqual(previous['tokens_in'], old['tokens_in'])
        self.assertEqual(previous['notes'], old['notes'])
        self.assertEqual(previous['outcome'], 'expired')
        self.assertIsNotNone(previous['ended'])
        self.assertIsNone(ledger.current_attempt('fn'))
        latest = ledger.db.execute('SELECT * FROM attempts WHERE id=?', (current['id'],)).fetchone()
        self.assertEqual(latest['checks'], 1)
        self.assertEqual(latest['best_in_attempt'], 90.0)
        self.assertEqual(latest['model'], 'new-model')
        self.assertEqual(latest['tokens_in'], 17)

    def test_live_owner_rejection_preserves_its_open_attempt(self):
        ledger = self.ledger
        ledger.claim('fn', 'live-worker', ttl=3600, max_attempts=10)
        before = dict(ledger.current_attempt('fn'))
        with self.assertRaises(PermissionError):
            ledger.claim('fn', 'other-worker', ttl=3600, max_attempts=10)
        self.assertEqual(dict(ledger.current_attempt('fn')), before)
        self.assertEqual(ledger.get('fn')['claimed_by'], 'live-worker')

    def test_attempt_cap_rejection_does_not_seal_history(self):
        ledger = self.ledger
        ledger.claim('fn', 'old-worker', ttl=1, max_attempts=10)
        before = dict(ledger.current_attempt('fn'))
        ledger.db.execute("UPDATE functions SET claimed_at=0, attempts=10 WHERE symbol='fn'")
        with self.assertRaises(PermissionError):
            ledger.claim('fn', 'new-worker', ttl=3600, max_attempts=10)
        self.assertEqual(dict(ledger.current_attempt('fn')), before)
        self.assertEqual(ledger.db.execute('SELECT COUNT(*) FROM attempts').fetchone()[0], 1)

    def test_shadow_claim_preserves_closed_history_and_matching_status(self):
        ledger = self.ledger
        ledger.claim('fn', 'original-worker', ttl=3600, max_attempts=10)
        original_id = ledger.current_attempt('fn')['id']
        ledger.bump_checks('fn', 100.0)
        ledger.finish('fn', 'matched', 'matched', model='original-model')
        before = dict(ledger.db.execute('SELECT * FROM attempts WHERE id=?', (original_id,)).fetchone())
        ledger.claim('fn', 'shadow-worker', ttl=3600, max_attempts=1, shadow=True)
        ledger.bump_checks('fn', 95.0)
        ledger.finish('fn', 'released', 'unmatched', model='shadow-model', shadow=True)
        self.assertEqual(dict(ledger.db.execute('SELECT * FROM attempts WHERE id=?', (original_id,)).fetchone()), before)
        self.assertEqual(ledger.get('fn')['status'], 'matched')
        self.assertEqual(ledger.get('fn')['attempts'], 1)
        self.assertIsNone(ledger.current_attempt('fn'))


if __name__ == '__main__':
    unittest.main()
