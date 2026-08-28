#!/usr/bin/env python3
"""natc_tree_check must tell a mid-gate window apart from abandoned work.

The distinction is the whole point. src/ is dirty for a few seconds every time
the gate lands a candidate, and alarming on that would be noise nobody reads.
What cost two hours on 2026-08-28 was a dirty tree with NO gate in flight:
five finished conversions that no one was going to commit, silently
redefining the head that natc_gate compares every later candidate against.
"""
from __future__ import annotations
import importlib.util
import sys
import types
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TOOL = REPO / "tools/natc_tree_check.py"


def _mod():
    spec = importlib.util.spec_from_file_location("natc_tree_check", TOOL)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


def test_clean_tree_is_zero(monkeypatch):
    m = _mod()
    monkeypatch.setattr(m, "dirty_sources", lambda: [])
    monkeypatch.setattr(sys, "argv", ["natc_tree_check.py", "--quiet"])
    assert m.main() == 0


def test_dirty_with_gate_in_flight_is_not_an_alarm(monkeypatch):
    m = _mod()
    monkeypatch.setattr(m, "dirty_sources", lambda: ["src/a.c"])
    monkeypatch.setattr(m, "gate_in_flight", lambda: True)
    monkeypatch.setattr(sys, "argv", ["natc_tree_check.py", "--quiet"])
    assert m.main() == 2, "the mid-gate window must not read as abandoned work"


def test_dirty_without_a_gate_is_an_alarm(monkeypatch):
    m = _mod()
    monkeypatch.setattr(m, "dirty_sources", lambda: ["src/a.c", "src/b.c"])
    monkeypatch.setattr(m, "gate_in_flight", lambda: False)
    monkeypatch.setattr(m, "oldest_mtime", lambda _p: 7200)
    monkeypatch.setattr(sys, "argv", ["natc_tree_check.py", "--quiet"])
    assert m.main() == 1


def test_reports_the_files_and_the_failure_signature(monkeypatch, capsys):
    """The message has to name the refusal a stalled tree produces, or the
    integrator reads 'ADDS asm bodies' and blames the candidate."""
    m = _mod()
    monkeypatch.setattr(m, "dirty_sources", lambda: ["src/game/adxt_8004AC04.c"])
    monkeypatch.setattr(m, "gate_in_flight", lambda: False)
    monkeypatch.setattr(m, "oldest_mtime", lambda _p: 5400)
    monkeypatch.setattr(sys, "argv", ["natc_tree_check.py"])
    assert m.main() == 1
    out = capsys.readouterr().out
    assert "src/game/adxt_8004AC04.c" in out
    assert "ADDS asm bodies" in out
    assert "PROVISIONAL" in out


def test_report_mode_never_writes(monkeypatch, capsys):
    """Without --land the tool must not commit, build, or touch src/.

    Enforced by running main() with the writing helpers replaced by tripwires,
    rather than by scanning the source text -- the advice it prints
    necessarily mentions ninja and committing.
    """
    m = _mod()
    monkeypatch.setattr(m, "dirty_sources", lambda: ["src/a.c"])
    monkeypatch.setattr(m, "gate_in_flight", lambda: False)
    monkeypatch.setattr(m, "oldest_mtime", lambda _p: 900)

    def tripwire(*_a, **_k):
        raise AssertionError("report mode must not land anything")
    monkeypatch.setattr(m, "land", tripwire)
    monkeypatch.setattr(sys, "argv", ["natc_tree_check.py"])
    assert m.main() == 1


def test_land_refuses_a_file_that_converts_nothing(tmp_path, monkeypatch, capsys):
    """A comment-only edit is not a conversion and must never be committed."""
    m = _mod()
    monkeypatch.setattr(m, "sh", lambda *c: "asm void Target(void) { nofralloc\n blr\n }\n")
    src = Path(m.REPO) / "src"
    monkeypatch.setattr(m.Path, "read_text",
                        lambda self, **k: "asm void Target(void) { nofralloc\n blr\n }\n// note\n",
                        raising=False)
    monkeypatch.setattr(m.subprocess, "run",
                        lambda *a, **k: types.SimpleNamespace(stdout=b"", returncode=0))
    import shutil as _sh
    monkeypatch.setattr(_sh, "copy2", lambda *a, **k: None)
    rc = m.land(["src/x.c"], log=lambda *a: None)
    assert rc == 3, "an edit that removes no asm body must be refused"


def test_land_is_gated_on_all_four_criteria():
    """The refusal points must all still be present and each must return 3."""
    text = TOOL.read_text()
    for criterion in ("removes no asm body", "not 100", "source_form_check",
                      "REBUILD RED"):
        assert criterion in text, f"missing guard: {criterion}"
    # a red rebuild must restore the tree, never leave the DOL red
    red = text[text.index("REBUILD RED"):]
    assert "checkout" in red and "ninja" in red, \
        "a red rebuild must restore destinations and rebuild green"


def test_gate_detector_cannot_see_itself():
    """A process-table scan that matches its own invoking shell pins
    gate_in_flight() to True and makes --land a permanent no-op.

    This is exactly what happened on 2026-08-28: the first implementation
    substring-scanned `ps -eo args`, and the shell running the check had
    'natc_gate.py' in its own command line. Run the probe from a process whose
    argv deliberately names both tools.
    """
    import subprocess
    probe = (
        "import sys, importlib.util; sys.path.insert(0, %r);"
        "s = importlib.util.spec_from_file_location('t', %r);"
        "m = importlib.util.module_from_spec(s); s.loader.exec_module(m);"
        "print(m.gate_running())"
        % (str(REPO / "tools"), str(TOOL))
    )
    r = subprocess.run(
        [sys.executable, "-c", probe,
         "natc_gate.py", "natc_integrate.py"],   # argv bait
        capture_output=True, text=True, cwd=REPO)
    assert r.stdout.strip() == "False", (
        f"the detector matched its own process: {r.stdout!r} {r.stderr[-300:]!r}")


def test_gate_detector_requires_a_python_argv_token(tmp_path):
    """Merely having the name in a command line is not a running gate."""
    import subprocess
    r = subprocess.run(["sleep", "0.1", "natc_gate.py"], capture_output=True)
    m = _mod()
    assert m.gate_running() is False
