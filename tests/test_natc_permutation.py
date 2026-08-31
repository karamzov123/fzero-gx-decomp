import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parents[1] / 'tools'))
import natc_permutation as p


def exact(score=100.0):
    return {'score': score, 'exact': True, 'accepted': True,
            'sections': {'target': {}, 'candidate': {}},
            'relocations': {'target': [], 'candidate': []},
            'object_layout': {'target': 4, 'candidate': 4},
            'missing_in_target': [], 'missing_in_candidate': [],
            'exact_sibling_regressions': []}


def test_generation_is_deterministic_and_local_only():
    source = 'u32 global_a;\nvoid f(void) {\n    u32 a;\n    u32 b;\n    a = b;\n}\n'
    first = p.generate(source, 'ctx')
    assert first == p.generate(source, 'ctx')
    assert first
    assert all('u32 global_a;' in candidate.splitlines()[0] for candidate in first)
    assert all(candidate != source for candidate in first)
    assert len(first) <= 3


def test_no_safe_run_means_no_candidates():
    assert p.generate('void f(void) { u32 a = 1; u32 b; }', 'ctx') == []
    assert p.generate('u32 a;\nu32 b;\n', 'ctx') == []


def test_high_score_lane_fails_closed_and_evaluates_only_bounded_family():
    source = 'void f(void) {\n    u32 a;\n    u32 b;\n}\n'
    seen = []
    result = p.permutation_search(source, exact(), context_id='ctx',
                                   evaluator=lambda candidate: (seen.append(candidate) or exact()))
    assert result['eligible'] is True
    assert len(seen) == len(result['results']) <= 3
    assert result['winner'] is not None
    low = p.permutation_search(source, exact(94.999), context_id='ctx',
                               evaluator=lambda _: (_ for _ in ()).throw(AssertionError()))
    assert low == {'eligible': False, 'reason': 'base evaluation below high-score gate', 'results': []}


def test_policy_caps_candidates():
    assert len(p.generate('void f(void) {\n u32 a;\n u32 b;\n u32 c;\n}\n', policy=p.PermutationPolicy(max_candidates=1))) == 1
