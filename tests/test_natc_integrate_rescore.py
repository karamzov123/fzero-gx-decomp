"""Integrator must reject stale/non-exact candidates before the full DOL gate."""
import importlib.util
from pathlib import Path

MODULE = Path(__file__).parents[1] / "tools" / "natc_integrate.py"
SPEC = importlib.util.spec_from_file_location("natc_integrate", MODULE)
integ = importlib.util.module_from_spec(SPEC)
assert SPEC and SPEC.loader
SPEC.loader.exec_module(integ)


def test_integrator_preflight_always_rescores_current_head(tmp_path):
    cmd = integ.preflight_command(tmp_path, "natc3")
    assert cmd[:2] == [integ.sys.executable, str(integ.PREFLIGHT)]
    assert cmd[cmd.index("--batch") + 1] == str(tmp_path)
    assert cmd[cmd.index("--worker") + 1] == "natc3"
    assert "--rescore" in cmd
    assert "--quiet" in cmd


def test_terminal_batch_refreshes_rank_backlog(monkeypatch):
    seen = []

    class Result:
        returncode = 0
        stdout = ""
        stderr = ""

    monkeypatch.setattr(integ, "run", lambda cmd: seen.append(cmd) or Result())
    integ.refresh_backlog()
    assert seen == [[integ.sys.executable, str(integ.RANK), "--refresh"]]
