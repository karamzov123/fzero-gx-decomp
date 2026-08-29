import sys
from pathlib import Path
import tempfile

sys.path.insert(0, str(Path(__file__).parents[1] / "tools"))
import natc_codegen_search as s
from natc_loop import classify_objdiff
from natc_diff import classify_tu


def sym(name, text, score):
    return {"name": name, "match_percent": score, "size": 4,
            "instruction_rows": [{"instruction": {"formatted": text}}]}


def spec():
    return {"mutation_class": "literal", "old": "1", "replacements": ["2"],
            "unit": "u", "symbol": "f"}


def complete_eval(score=100.0):
    return {"accepted": True, "score": score, "sections": {},
            "relocations": [], "object_layout": {"target": 4, "candidate": 4},
            "missing_in_target": [], "missing_in_candidate": [],
            "exact_sibling_regressions": []}


def test_loop_score_comes_from_candidate_side():
    diff = {"left": {"symbols": [sym("f", "li r3,1", 100.0)]},
            "right": {"symbols": [sym("f", "li r3,2", 37.5)]}}
    assert classify_objdiff(diff, "f")["score"] == 37.5


def test_loop_rejects_extra_candidate_symbols():
    diff = {"left": {"symbols": [sym("f", "blr", 100.0)]},
            "right": {"symbols": [sym("f", "blr", 100.0), sym("extra", "blr", 0)]}}
    assert classify_objdiff(diff, "f")["tu_safe"] is False


def test_tu_sibling_regressions_exclude_requested_target():
    diff = {"left": {"symbols": [sym("target", "blr", 100.0)]},
            "right": {"symbols": [sym("target", "nop", 100.0)]}}
    assert classify_tu(diff, target_symbol="target")["exact_sibling_regressions"] == []


def test_search_rejects_evaluation_before_recording_it(tmp_path):
    recorded = []
    rows = s.search("int x=1;", spec(), root=tmp_path,
                    compile_candidate=lambda _: {"score": None},
                    ledger=type("L", (), {"record": lambda self, *a, **kw: recorded.append(kw)})())
    assert rows[0]["accepted"] is False
    assert recorded[0]["payload"]["accepted"] is False


def test_only_temp_output_paths_are_allowed(tmp_path):
    assert s.scratch_candidates("int x=1;", spec(), root=tmp_path)
    try:
        s.scratch_candidates("int x=1;", spec(), root=Path(__file__).parents[1])
    except ValueError:
        pass
    else:
        raise AssertionError("canonical repository path was accepted")


def test_acceptance_gate_requires_complete_regression_free_evidence():
    assert s.acceptance_gate(complete_eval()) is True
    incomplete = {"accepted": True, "score": 100.0}
    assert s.acceptance_gate(incomplete) is False
    assert s.acceptance_gate({**complete_eval(), "sections": {".text": "changed"}}) is False
    assert s.acceptance_gate({**complete_eval(), "relocations": ["changed"]}) is False
    assert s.acceptance_gate({**complete_eval(), "object_layout": {"target": 4, "candidate": 8}}) is False


def test_acceptance_gate_none_score_fails_closed():
    assert s.acceptance_gate({**complete_eval(), "score": None}) is False
