import sys
import json
from types import SimpleNamespace
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parents[1] / 'tools'))
import natc_codegen_search as s


def ev(score=100.0, **kw):
    out = {'accepted': True, 'score': score, 'sections': {'target': {'text': 1}, 'candidate': {'text': 1}},
           'relocations': {'target': [], 'candidate': []},
           'object_layout': {'target': {'text': 4}, 'candidate': {'text': 4}},
           'missing_in_target': [], 'missing_in_candidate': [], 'exact_sibling_regressions': []}
    out.update(kw)
    return out


def test_acceptance_requires_explicit_exact_100_and_complete_matching_evidence():
    assert not s.acceptance_gate(ev(0.0))
    assert not s.acceptance_gate(ev(99.999))
    assert not s.acceptance_gate(ev(100.0, accepted=False, exact=False))
    assert not s.acceptance_gate(ev(100.0, sections={'target': {}, 'candidate': {'text': 1}}))
    assert not s.acceptance_gate(ev(100.0, relocations={'target': [], 'candidate': ['r']}))
    assert not s.acceptance_gate(ev(100.0, object_layout={'target': {}, 'candidate': {'text': 4}}))
    assert s.acceptance_gate(ev())


def test_batch_deduplicates_and_returns_exact_winner_without_repo_write(tmp_path):
    a, b, dup = (tmp_path / x for x in ('a.c', 'b.c', 'dup.c'))
    a.write_text('int a;'); b.write_text('int b;'); dup.write_text('int a;')
    scores = {'int a;': 100.0, 'int b;': 99.999}
    seen = []
    def evaluate(path):
        seen.append(path)
        return ev(scores[path.read_text()])
    scratch = tmp_path / 'scratch'
    # pytest tmp paths are under /tmp and therefore accepted scratch roots.
    result = s.batch([a, b, dup], evaluator=evaluate, context_id='ctx',
                     compiler_id='mwcc', root=scratch)
    assert len(result['results']) == 3
    assert result['results'][2]['duplicate'] is True
    assert result['winner']['candidate_id'] == result['results'][0]['candidate_id']
    assert len(seen) == 2
    assert all(Path(p).parent == scratch for p in seen)
    assert all(Path(p).name.startswith('c') and Path(p).suffix == '.c'
               and len(Path(p).name) <= 15 for p in seen)
    assert len({Path(p).name for p in seen}) == 2
    assert not (Path(__file__).parents[1] / 'canonical-should-not-exist.c').exists()


def test_summary_keeps_decision_and_omits_full_objdiff():
    full = {'winner': {'candidate_id': 'winner'}, 'results': [{
        'candidate_id': 'winner', 'source_id': 'src', 'path': 'a.c',
        'scratch_path': '[temporary path]/a.c', 'accepted': True,
        'acceptance_reason': 'accepted', 'context_id': 'ctx',
        'compiler_id': 'mwcc', 'evaluation': {
            'score': 100.0, 'classification': 'exact', 'tu_safe': True,
            'objdiff': {'instruction_rows': ['very large']}}}]}
    summary = s.summarize_batch(full)
    assert summary['winner_candidate_id'] == 'winner'
    assert summary['results'][0]['score'] == 100.0
    assert 'evaluation' not in summary['results'][0]
    assert 'instruction_rows' not in repr(summary)


def test_inferred_identity_uses_authoritative_context_and_compiler():
    context, compiler = s.inferred_identity(
        'main/test/unit', 'f',
        load_unit=lambda _: {'base_path': None,
                             'scratch': {'compiler': 'mwcc_233_163n'}},
        context_fn=lambda unit, symbol: f'ctx:{unit}:{symbol}')
    assert context == 'ctx:main/test/unit:f'
    assert compiler == 'mwcc_233_163n'

    explicit = s.inferred_identity(
        'main/test/unit', 'f', context_id='ctx-explicit',
        compiler_id='GC/1.2.5n', load_unit=lambda _: {},
        context_fn=lambda *_: 'wrong')
    assert explicit == ('ctx-explicit', 'GC/1.2.5n')

    try:
        s.inferred_identity(
            'main/test/unit', 'f', context_id='ctx', compiler_id='stale',
            load_unit=lambda _: {'base_path': None,
                                 'scratch': {'compiler': 'GC/1.2.5n'}},
            context_fn=lambda *_: 'unused')
    except ValueError as exc:
        assert 'does not match authoritative' in str(exc)
    else:
        raise AssertionError('stale compiler identity was accepted')


def test_authoritative_evaluator_compiles_and_classifies_full_tu(tmp_path):
    candidate = tmp_path / 'candidate.c'
    candidate.write_text('int f(void) { return 1; }')
    calls = []

    def run(cmd, **kw):
        calls.append(cmd)
        if 'natc_compile.py' in ' '.join(cmd):
            return SimpleNamespace(returncode=0, stdout=json.dumps({
                'ok': True, 'obj_path': str(tmp_path / 'candidate.o')}) + '\n', stderr='')
        return SimpleNamespace(returncode=0, stdout=json.dumps({'left': {}, 'right': {}}), stderr='')

    tu = {'missing_in_target': [], 'missing_in_candidate': [],
          'exact_sibling_regressions': [], 'section_layout_changes': {},
          'relocation_changes': [],
          'object_size': {'target': 16, 'candidate': 16}}
    evaluator = s.authoritative_evaluator(
        'main/test/unit', 'f', worker='natc1', model='model', rung='4',
        run_cmd=run, load_unit=lambda _: {'target_path': str(tmp_path / 'target.o')},
        classify=lambda _diff, _symbol: {
            'classification': 'exact', 'score': 100.0, 'tu_safe': True, 'tu': tu},
        repo=tmp_path)
    result = evaluator(candidate)
    assert result['accepted'] is True
    assert result['exact'] is True
    assert result['tu'] == tu
    assert '--worker' in calls[0] and '--model' in calls[0] and '--rung' in calls[0]
    assert calls[1][0].endswith('objdiff-cli')


def test_authoritative_evaluator_fails_closed_on_compile_error(tmp_path):
    def run(_cmd, **_kw):
        return SimpleNamespace(returncode=4,
                               stdout=json.dumps({'ok': False, 'refused': 'duplicate_candidate'}),
                               stderr='')
    evaluator = s.authoritative_evaluator(
        'main/test/unit', 'f', run_cmd=run,
        load_unit=lambda _: {'target_path': str(tmp_path / 'target.o')},
        classify=lambda *_: {}, repo=tmp_path)
    result = evaluator(tmp_path / 'candidate.c')
    assert result['error'] == 'duplicate_candidate'


def test_batch_refuses_more_than_three(tmp_path):
    files = []
    for i in range(4):
        p = tmp_path / f'{i}.c'; p.write_text(str(i)); files.append(p)
    try:
        s.batch(files, evaluator=lambda _: ev(), root=tmp_path / 'scratch')
    except ValueError as e:
        assert 'three' in str(e)
    else:
        raise AssertionError('four candidates were accepted')
