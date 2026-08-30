"""Readiness classifier (priority #2): machine-validated symbol-ready gates.

The whole point is that a worker must not generate a candidate when the
evidence to answer is missing. The pure classifier drives every state; the
orchestration is exercised against a throwaway runs.sqlite so no fleet state
is touched (probes for reference index and runtime dir are switched off).
"""
import importlib.util
import sqlite3
from pathlib import Path

ROOT = Path(__file__).parents[1]
SPEC = importlib.util.spec_from_file_location("natc_readiness", ROOT / "tools/natc_readiness.py")
assert SPEC and SPEC.loader
readiness = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(readiness)

Readiness = readiness.Readiness


def _db(tmp_path):
    db = sqlite3.connect(tmp_path / "runs.sqlite")
    db.execute("""create table if not exists symbol_states(
        unit text not null, symbol text not null, status text not null,
        context text, evidence text, updated_at real not null,
        primary key(unit,symbol))""")
    db.execute("""create table if not exists attempts(
        id integer primary key autoincrement, ts real, worker text, model text,
        unit text, symbol text, attempt integer, score real, wall_ms integer,
        note text, kind text, ctx_sha text)""")
    return db


def test_reference_backed_symbol_is_ready():
    r = Readiness(ref_hits=[("dolsdk2001", False)])
    assert r.verdict == "ready"
    assert r.ready and r.reference_backed


def test_runtime_evidence_alone_can_satisfy_ready():
    r = Readiness(runtime_facts=True)
    assert r.verdict == "ready"
    assert r.runtime_facts


def test_no_evidence_is_blocked_not_ready():
    r = Readiness()
    assert r.verdict == "blocked-evidence"
    assert not r.ready
    assert any("no natural-C reference" in x for x in r.reasons)


def test_asm_reference_body_is_not_a_head_start():
    """A reference hit that is itself an asm body must read like no evidence."""
    r = Readiness(ref_hits=[("melee", True)])
    assert not r.reference_backed
    assert r.verdict == "blocked-evidence"


def test_budget_exhaustion_takes_priority_over_evidence():
    r = Readiness(attempts=12, ref_hits=[("dolsdk2001", False)])
    assert r.verdict == "exhausted"


def test_absolute_ceiling_still_exhausted_even_with_fresh_context_flags():
    r = Readiness(attempts=36, runtime_facts=True)
    assert r.verdict == "exhausted"


def test_nonconvergence_is_exhausted():
    r = Readiness(attempts=8, best_score=0.0, ref_hits=[("dolsdk2001", False)])
    assert r.verdict == "exhausted"


def test_mark_statuses_map_to_disjoint_verdicts():
    assert Readiness(status="terminal").verdict == "terminal"
    assert Readiness(status="mispin").verdict == "compiler-mispin-suspected"
    assert Readiness(status="plateau").verdict == "plateau"
    assert Readiness(status="inline_asm_required").verdict == "ineligible-pure-c"
    assert Readiness(ineligible=True).verdict == "ineligible-pure-c"


def test_reasons_bundle_blame_for_blocked_symbol():
    d = Readiness(status="mispin").as_dict()
    assert d["verdict"] == "compiler-mispin-suspected"
    assert "symbol_state=mispin" in d["reasons"]


def test_assess_orchestrates_runs_sqlite_without_touching_fleet():
    import json
    import tempfile
    with tempfile.TemporaryDirectory() as td:
        db = _db(Path(td))
        # terminal state must dominate even with zero attempts.
        db.execute("insert into symbol_states values(?,?,?,?,?,?)",
                   ("u", "s", "terminal", None, "manual", 1.0))
        db.commit(); db.close()
        r = readiness.assess("u", "s", runs_db=Path(td) / "runs.sqlite",
                             probe_refs=False, probe_runtime=False)
        assert r.verdict == "terminal"
        assert r.status == "terminal"


def test_assess_counts_attempts_and_percent():
    import tempfile
    with tempfile.TemporaryDirectory() as td:
        db = _db(Path(td))
        db.executemany(
            "insert into attempts(ts,kind,unit,symbol,attempt,score) "
            "values(?,?,?,?,?,?)",
            [(1.0, "attempt", "u", "s", 1, 90.0),
             (2.0, "attempt", "u", "s", 2, 100.0),
             (3.0, "verify", "u", "other", 1, 20.0)])
        db.commit(); db.close()
        r = readiness.assess("u", "s", runs_db=Path(td) / "runs.sqlite",
                             probe_refs=False, probe_runtime=False)
        assert r.attempts == 2
        assert r.best_score == 100.0
        # attempts < budget and no evidence gathered -> not ready, but not spent.
        assert r.verdict == "blocked-evidence"