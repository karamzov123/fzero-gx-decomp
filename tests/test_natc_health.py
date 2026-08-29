from __future__ import annotations

import importlib.util
import subprocess
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[1]


def _load_health():
    spec = importlib.util.spec_from_file_location(
        "natc_health", ROOT / "tools" / "natc_health.py"
    )
    assert spec and spec.loader
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def test_project_declares_test_extra():
    text = (ROOT / "pyproject.toml").read_text()
    assert "[project.optional-dependencies]" in text
    assert 'pytest>=' in text
    assert 'capstone>=' in text


def test_run_step_preserves_failure_diagnostics(monkeypatch):
    health = _load_health()

    def fake_run(*args, **kwargs):
        return subprocess.CompletedProcess(args[0], 7, "out\n", "err\n")

    monkeypatch.setattr(health.subprocess, "run", fake_run)
    result = health.run_step("fixture", ["false"])
    assert result == {
        "name": "fixture",
        "ok": False,
        "returncode": 7,
        "stdout": "out\n",
        "stderr": "err\n",
    }


def test_main_uses_project_uv_environment_for_pytest(monkeypatch):
    health = _load_health()
    calls: list[tuple[str, list[str]]] = []

    def fake_step(name, argv, cwd=None):
        calls.append((name, argv))
        return {"name": name, "ok": True, "returncode": 0,
                "stdout": "", "stderr": ""}

    monkeypatch.setattr(health, "run_step", fake_step)
    assert health.main(["--quick"]) == 0
    assert calls[0] == (
        "tests", ["uv", "run", "--extra", "test", "pytest", "-q"]
    )


def test_main_stops_after_first_failed_step(monkeypatch, capsys):
    health = _load_health()
    calls: list[str] = []

    def fake_step(name, argv, cwd=None):
        calls.append(name)
        return {
            "name": name,
            "ok": name != "self-tests",
            "returncode": 0 if name != "self-tests" else 3,
            "stdout": "",
            "stderr": "boom" if name == "self-tests" else "",
        }

    monkeypatch.setattr(health, "run_step", fake_step)
    assert health.main(["--quick"]) == 3
    assert calls == ["tests", "self-tests"]
    assert '"ok": false' in capsys.readouterr().out.lower()
