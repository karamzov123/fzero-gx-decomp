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


def test_tool_is_report_only():
    """It must never write to src/, build, or commit.

    Checked on the parsed AST, not on the source text: the advice this tool
    prints necessarily mentions `ninja` and committing, and a substring scan
    would flag its own documentation.
    """
    import ast
    tree = ast.parse(TOOL.read_text())
    banned_attrs = {"write_text", "write_bytes", "mkdir", "unlink", "rename",
                    "copy", "copy2", "rmtree", "check_call"}
    for node in ast.walk(tree):
        if isinstance(node, ast.Call):
            fn = node.func
            name = getattr(fn, "attr", None) or getattr(fn, "id", None)
            assert name not in banned_attrs, f"tree check must not call {name}()"
            # the only writing it is allowed to do is opening the gate lock
            # for a non-blocking probe, which needs 'a+' but writes nothing
            if name == "open":
                modes = [a.value for a in node.args[1:] if isinstance(a, ast.Constant)]
                modes += [k.value.value for k in node.keywords
                          if k.arg == "mode" and isinstance(k.value, ast.Constant)]
                assert all(m in ("r", "a+") for m in modes), \
                    f"tree check opened a file for writing: {modes}"
    src = TOOL.read_text()
    assert "subprocess.run" in src, "sanity: the tool does shell out"
    for call in ("\"commit\"", "'commit'", "\"checkout\"", "'checkout'",
                 "\"ninja\"", "'ninja'"):
        assert call not in src, f"tree check must not invoke {call}"
