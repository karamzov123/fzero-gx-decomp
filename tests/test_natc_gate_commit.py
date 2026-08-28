#!/usr/bin/env python3
"""A verified-green landing must be committed by the code that verified it.

2026-08-28. There was no `git commit` anywhere in the integration path --
neither natc_gate.py nor natc_integrate.py contained one. The gate accepted a
batch, wrote the candidate into src/, rebuilt, verified the DOL byte-exact,
and stopped. Committing was a PROMPT INSTRUCTION to the integ agent, and the
agent kept dropping it. Measured to the second: pad-ismotorenabled-001 was
accepted at 11:27:58 and committed at 11:32:50 -- five minutes later, by
natc_tree_check --land on the next integration cycle. Every stranded-work
incident that day traces to this one gap.

The two constraints that matter are pinned here: the commit must stage ONLY
the destinations the run landed, and it must fail soft.
"""
from __future__ import annotations
import importlib.util
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TOOL = REPO / "tools/natc_gate.py"


def _mod():
    sys.path.insert(0, str(REPO / "tools"))
    spec = importlib.util.spec_from_file_location("natc_gate_commit", TOOL)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


def _repo(tmp_path):
    r = tmp_path / "repo"
    (r / "src").mkdir(parents=True)
    for cmd in (["init", "-q", "-b", "main"],
                ["config", "user.email", "t@t"],
                ["config", "user.name", "t"]):
        subprocess.run(["git", *cmd], cwd=r, check=True, capture_output=True)
    return r


ASM = "asm void Target(void)\n{\n    nofralloc\n    blr\n}\n"
C = "// provenance: original Target\nvoid Target(void)\n{\n}\n"


def test_commits_only_the_landed_destinations(tmp_path, monkeypatch):
    r = _repo(tmp_path)
    landed = r / "src/landed.c"
    other = r / "src/other.c"
    landed.write_text(ASM)
    other.write_text(ASM)
    subprocess.run(["git", "add", "-A"], cwd=r, check=True, capture_output=True)
    subprocess.run(["git", "commit", "-qm", "base"], cwd=r, check=True,
                   capture_output=True)

    landed.write_text(C)
    other.write_text(C)          # another worker mid-write; must NOT be swept in

    m = _mod()
    monkeypatch.setattr(m, "REPO", r)
    monkeypatch.setattr(m, "sh", lambda cmd, env=None: subprocess.run(
        [str(c) for c in cmd], cwd=r, capture_output=True, text=True, env=env))
    monkeypatch.setattr(m, "log", lambda *a, **k: None)
    m.commit_landed([landed], tmp_path / "batch-x", "natc9")

    committed = subprocess.run(["git", "show", "--name-only", "--format=", "HEAD"],
                               cwd=r, capture_output=True, text=True).stdout.split()
    assert committed == ["src/landed.c"], f"staged too much: {committed}"
    still_dirty = subprocess.run(["git", "status", "--porcelain"], cwd=r,
                                 capture_output=True, text=True).stdout
    assert "src/other.c" in still_dirty, "the other worker's file must be untouched"


def test_subject_names_the_converted_functions(tmp_path, monkeypatch):
    r = _repo(tmp_path)
    f = r / "src/u.c"
    f.write_text(ASM)
    subprocess.run(["git", "add", "-A"], cwd=r, check=True, capture_output=True)
    subprocess.run(["git", "commit", "-qm", "base"], cwd=r, check=True,
                   capture_output=True)
    f.write_text(C)

    m = _mod()
    monkeypatch.setattr(m, "REPO", r)
    monkeypatch.setattr(m, "sh", lambda cmd, env=None: subprocess.run(
        [str(c) for c in cmd], cwd=r, capture_output=True, text=True, env=env))
    monkeypatch.setattr(m, "log", lambda *a, **k: None)
    m.commit_landed([f], tmp_path / "b", "natc9")

    subj = subprocess.run(["git", "log", "-1", "--format=%s"], cwd=r,
                          capture_output=True, text=True).stdout
    assert "Target" in subj, f"subject must name the conversion: {subj!r}"
    assert "1 conversion" in subj


def test_no_changes_is_a_quiet_no_op(tmp_path, monkeypatch):
    """Re-running over already-committed destinations must not create an empty
    commit — the gate can be re-entered after a --land already took the work."""
    r = _repo(tmp_path)
    f = r / "src/u.c"
    f.write_text(C)
    subprocess.run(["git", "add", "-A"], cwd=r, check=True, capture_output=True)
    subprocess.run(["git", "commit", "-qm", "base"], cwd=r, check=True,
                   capture_output=True)
    before = subprocess.run(["git", "rev-parse", "HEAD"], cwd=r,
                            capture_output=True, text=True).stdout

    m = _mod()
    monkeypatch.setattr(m, "REPO", r)
    monkeypatch.setattr(m, "sh", lambda cmd, env=None: subprocess.run(
        [str(c) for c in cmd], cwd=r, capture_output=True, text=True, env=env))
    monkeypatch.setattr(m, "log", lambda *a, **k: None)
    m.commit_landed([f], tmp_path / "b", "natc9")

    after = subprocess.run(["git", "rev-parse", "HEAD"], cwd=r,
                           capture_output=True, text=True).stdout
    assert before == after, "an empty commit was created"


def test_commit_failure_does_not_raise(tmp_path, monkeypatch):
    """The DOL is already verified byte-exact when this runs. A git failure
    must not turn a green landing into an exception — --land is the backstop."""
    m = _mod()
    monkeypatch.setattr(m, "REPO", tmp_path)
    calls = {"n": 0}

    class Fail:
        returncode = 1
        stdout = " M src/u.c"
        stderr = "fatal: simulated"

    def fake_sh(cmd, env=None):
        calls["n"] += 1
        return Fail()

    monkeypatch.setattr(m, "sh", fake_sh)
    logged = []
    monkeypatch.setattr(m, "log", lambda s: logged.append(s))
    (tmp_path / "src").mkdir(exist_ok=True)
    (tmp_path / "src/u.c").write_text(C)
    m.commit_landed([tmp_path / "src/u.c"], tmp_path / "b", "natc9")
    assert any("commit failed" in s for s in logged), logged


def test_both_accept_branches_call_it():
    """A commit helper nothing calls is the failure this replaced."""
    text = TOOL.read_text()
    assert text.count("commit_landed(") >= 3, "helper defined but not wired twice"
    for branch in ('archive_accepted_batch(batch_dir, args.worker, "accepted")',
                   'archive_accepted_batch(batch_dir, args.worker, "partial-accepted")'):
        i = text.index(branch)
        assert "commit_landed(" in text[i - 400:i], f"no commit before {branch}"
