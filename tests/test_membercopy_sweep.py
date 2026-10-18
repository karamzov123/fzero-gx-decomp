"""Guard the natural-C member-copy repair and frozen sweep contexts."""
import hashlib
import json
import os
from pathlib import Path
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from fzgx import fixup_source, sweep

BODY = '''int fn(void) {
    int result;
    long index;
    result = 0;
    index = result;
    return index + result;
}
'''


class MemberCopyTests(unittest.TestCase):
    def test_copy_is_real_state_with_int_second_member(self):
        variants = fixup_source.member_copy_states(BODY, 'fn')
        self.assertEqual(len(variants), 1)
        text = variants[0][1]
        self.assertIn('struct { int result; int index; }', text)
        self.assertIn('fzgx_copy_state.index = fzgx_copy_state.result;', text)
        self.assertNotIn('long index;', text)

    def test_does_not_rewrite_comments_strings_or_other_members(self):
        body = BODY.replace('    return index + result;',
            '    /* result = index; */\n    log("result = index;");\n'
            '    object->result = index;\n    return object->result;')
        text = fixup_source.member_copy_states(body, 'fn')[0][1]
        self.assertIn('/* result = index; */', text)
        self.assertIn('log("result = index;")', text)
        self.assertIn('object->result = fzgx_copy_state.index;', text)
        self.assertIn('return object->result;', text)

    def test_no_candidate_for_address_escape_shadow_or_qualified_local(self):
        for extra in ('    consume(&result);\n',
                      '    { int result; result = 1; }\n'):
            with self.subTest(extra=extra):
                self.assertEqual(fixup_source.member_copy_states(
                    BODY.replace('    return', extra + '    return'), 'fn'), [])
        self.assertEqual(fixup_source.member_copy_states(
            BODY.replace('int result;', 'volatile int result;'), 'fn'), [])

    def test_address_escape_in_other_local_initializer_is_excluded(self):
        body = BODY.replace('    result = 0;',
                            '    int *escaped = &result;\n    result = 0;')
        self.assertEqual(fixup_source.member_copy_states(body, 'fn'), [])


class SweepContextTests(unittest.TestCase):
    def setUp(self):
        scratch = Path(os.environ.get('TMPDIR', str(Path.home() / '.hermes/cache/scratch')))
        scratch.mkdir(parents=True, exist_ok=True)
        self.tmp = tempfile.TemporaryDirectory(dir=scratch)
        self.root = Path(self.tmp.name)

    def tearDown(self):
        self.tmp.cleanup()

    def test_frozen_seed_hash_is_checked_before_compilation(self):
        source = self.root / 'seed.c'
        source.write_text(BODY)
        seeds = self.root / 'seeds.json'
        seeds.write_text(json.dumps({'fn': dict(path=str(source), percent=99,
                                      sha256='not-the-source-hash', mw='GC/1.2.5n', flags='-O1')}))
        p = SimpleNamespace(resolve=lambda s: SimpleNamespace(name=s, module='main'))
        ledger = SimpleNamespace(get=lambda s: {'status': 'unmatched'})
        with patch.object(sweep, 'Ledger', return_value=ledger), \
             patch.object(sweep, 'climb') as compile_probe:
            with self.assertRaisesRegex(ValueError, 'seed changed'):
                sweep.run(p, 0, 100, self.root / 'out', 1, ['membercopy'], False, seeds=seeds)
            compile_probe.assert_not_called()

    def test_recovery_uses_eligible_history_and_preserves_flag_arguments(self):
        from seeds.recovered import SavedCandidates
        candidate = dict(body=BODY, percent=90, mw='GC/1.2.5n', flags=['-O1', '-use_lmw_stmw', 'off'],
                         sha256=hashlib.sha256(BODY.encode()).hexdigest())
        ineligible = dict(candidate, body='int fn(void) { return 0; }', percent=99, sha256='other')
        fake = SimpleNamespace(collect=lambda: None, rows={'fn': {}},
                               candidates={'fn': [ineligible, candidate]})
        p = SimpleNamespace(resolve=lambda s: SimpleNamespace(name=s))
        with patch('seeds.recovered.SavedCandidates', return_value=fake):
            manifest = sweep.recover_membercopy(p, self.root / 'out', 0, 100)
        result = json.loads(manifest.read_text())['fn']
        self.assertEqual(result['percent'], 90)
        self.assertEqual(result['mw'], 'GC/1.2.5n')
        self.assertEqual(result['flags'], '-O1 -use_lmw_stmw off')
        self.assertEqual(result['original_flags'], candidate['flags'])
        self.assertEqual(Path(result['path']).read_text(), BODY)

    def test_failed_baseline_is_recorded_not_silently_dropped(self):
        source = self.root / 'seed.c'
        source.write_text(BODY)
        failed = SimpleNamespace(ok=False, error='compiler rejected profile')
        with patch.object(sweep.oracle, 'check_many', return_value={'fn': failed}):
            rep = sweep.climb(SimpleNamespace(), {'fn': str(source)}, self.root / 'out', 0)
        self.assertEqual(rep, {})
        errors = json.loads((self.root / 'out/errors.json').read_text())
        self.assertEqual(errors, {'fn': 'compiler rejected profile'})

    def test_saved_import_does_not_rewrite_historical_donor_provenance(self):
        from fzgx import sourcealign
        state = self.root / '.fzgx'
        (state / 'sourcealign').mkdir(parents=True)
        (state / 'sourcealign/matches.json').write_text('{}')
        path = self.root / 'state/sdkimports/sourcealign.json'
        path.parent.mkdir(parents=True)
        historical = {'old': {'sdk': 'historical-donor', 'revision': 'pinned',
                               'license': {'path': 'LICENSE', 'sha256': 'pinned-hash'}}}
        path.write_text(json.dumps(historical))
        with patch.object(sourcealign, 'ROOT', self.root), \
             patch.object(sourcealign, 'STATE_DIR', state), \
             patch.object(sourcealign, 'Ledger'), \
             patch.object(sourcealign, 'source_license', side_effect=ValueError('old checkout unavailable')):
            result = sourcealign.submit_saved(SimpleNamespace())
        self.assertEqual(result, dict(accepted=[], failed=[]))
        self.assertEqual(json.loads(path.read_text()), historical)

    def test_compiler_context_reaches_baseline_variants_and_winner(self):
        source = self.root / 'seed.c'
        source.write_text(BODY)
        options = ('GC/1.2.5n', '-O1 -use_lmw_stmw off')
        checks, compiles = [], []
        baseline = SimpleNamespace(ok=True, percent=99, matched=False,
                                   mw_version=options[0], extra_cflags=options[1])
        winner = SimpleNamespace(ok=True, percent=100, matched=True,
                                 mw_version=options[0], extra_cflags=options[1])
        def check_many(p, items, **kwargs):
            checks.append(kwargs)
            return {'fn': baseline if len(checks) == 1 else winner}
        def compile_many(p, module, sources, outdir, mw, flags):
            compiles.append((module, mw, flags))
            return {path: path.with_suffix('.o') for path in sources}
        p = SimpleNamespace(resolve=lambda s: SimpleNamespace(name=s, module='main'),
                            target_object_for=lambda s: self.root / 'target.o')
        with patch.object(sweep.oracle, 'check_many', side_effect=check_many), \
             patch.object(sweep.oracle, 'compile_many', side_effect=compile_many), \
             patch.object(sweep.oracle, 'words', return_value=[1]), \
             patch.object(sweep, 'generate', return_value=[('membercopy', BODY)]), \
             patch.object(sweep.fixup_source, 'fitness', side_effect=[(100, 100), (99, 99)]):
            rep = sweep.climb(p, {'fn': str(source)}, self.root / 'out', 1,
                              ['membercopy'], {'fn': options})
        self.assertEqual(len(checks), 2)
        self.assertTrue(all(x == dict(mw_version=options[0], extra_cflags=options[1]) for x in checks))
        self.assertEqual(compiles, [('main', *options), ('main', *options)])
        self.assertEqual((rep['fn']['mw'], rep['fn']['flags']), options)
        self.assertTrue(rep['fn']['matched'])


if __name__ == '__main__':
    unittest.main()
