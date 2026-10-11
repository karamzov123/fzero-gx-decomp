"""Closed compiler-seed batches must not lose pins in mixed fleet selection."""
import hashlib
import json
import os
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch, Mock

PROJECT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(PROJECT / 'tools'))
import fleet_multi as fleet


class SeedBatchTests(unittest.TestCase):
    def setUp(self):
        scratch = Path(os.environ.get('TMPDIR', str(Path.home() / '.hermes/cache/scratch')))
        scratch.mkdir(parents=True, exist_ok=True)
        self.tmp = tempfile.TemporaryDirectory(dir=scratch)
        self.root = Path(self.tmp.name)
        self.records = {'seed': {'source': 'int f(void) { return 0; }', 'mw': 'GC/1.3.2'},
                        'other_seed': {'source': 'int g(void) { return 0; }', 'mw': 'GC/1.2.5n'},
                        'task_only': {'task': {}}}
        for record in self.records.values():
            if record.get('source'):
                record['sha256'] = hashlib.sha256(record['source'].encode()).hexdigest()
        manifest = self.root / 'state/fleet/priority-seeds.json'
        manifest.parent.mkdir(parents=True)
        manifest.write_text(json.dumps(self.records))
        self.root_patch = patch.object(fleet, 'ROOT', self.root)
        self.root_patch.start()

    def tearDown(self):
        self.root_patch.stop()
        self.tmp.cleanup()

    def test_pinned_selection_defers_ordinary_work(self):
        self.assertEqual(fleet.seed_batch_symbols(['seed', 'ordinary', 'other_seed', 'task_only']),
                         ['seed', 'other_seed'])

    def test_ordinary_selection_defers_pinned_work(self):
        self.assertEqual(fleet.seed_batch_symbols(['ordinary', 'seed', 'task_only']),
                         ['ordinary', 'task_only'])

    def test_empty_selection(self):
        self.assertEqual(fleet.seed_batch_symbols([]), [])

    def test_direct_mixed_command_is_rejected(self):
        with self.assertRaisesRegex(ValueError, 'Mixed'):
            fleet.command('gpt', 'fixture', ['seed', 'ordinary'], 2)

    def test_incomplete_pin_is_not_silently_dropped(self):
        self.records['seed'].pop('sha256')
        (self.root / 'state/fleet/priority-seeds.json').write_text(json.dumps(self.records))
        with self.assertRaisesRegex(ValueError, 'Incomplete'):
            fleet.command('gpt', 'fixture', ['seed'], 2)

    def test_homogeneous_command_preserves_seed_manifest(self):
        cmd = fleet.command('gpt', 'fixture', ['seed', 'other_seed'], 2)
        self.assertEqual(cmd[cmd.index('--seeds') + 1], str(self.root / 'state/fleet/priority-seeds.json'))
        self.assertEqual(cmd[cmd.index('--harness') + 1], 'codex')
        self.assertEqual(cmd[cmd.index('--effort') + 1], 'high')
        self.assertNotIn('--seeds', fleet.command('gpt', 'fixture', ['ordinary', 'task_only'], 2))


class BoundBudgetReleaseTests(unittest.TestCase):
    def test_automatic_budget_stop_does_not_launch_full_repair(self):
        from fzgx import api
        ledger = Mock()
        ledger.get.return_value = {'status': 'claimed', 'claimed_by': 'fixture-agent'}
        ledger.current_attempt.return_value = None
        with patch.dict(os.environ, {'FZGX_AGENT_ID': 'fixture-agent'}), \
                patch.object(api, 'Ledger', return_value=ledger), \
                patch.object(api, '_key', return_value='fixture-symbol'), \
                patch.object(api, 'release', return_value={'ok': True}) as release:
            result = api._finish_check(object(), 'fixture-symbol', {'stop': 'plateau'})
        self.assertTrue(result['terminal'])
        self.assertTrue(release.call_args.kwargs.get('save_only', False))


if __name__ == '__main__':
    unittest.main()
