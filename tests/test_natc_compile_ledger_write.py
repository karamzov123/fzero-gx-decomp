#!/usr/bin/env python3
"""log_attempt() must actually be able to write a row.

2026-08-28: a `rung` column was added to the INSERT's column list and to its
placeholder list, but not to the values tuple -- 16 placeholders, 15 bindings.
sqlite raises ProgrammingError, log_attempt catches Exception, warns on stderr
and returns [], so:

  * no attempt is ever recorded,
  * `dup` comes back empty, so the "never retry unchanged source" guard and the
    attempt budget both fail OPEN,
  * and the only symptom is one warn line buried in a worker's agent output.

The canonical tree ran with this for ~4 minutes before it was caught; the
worker worktrees had not synced yet, which is the only reason the fleet's
ledger survived. A column/binding mismatch must never again be discoverable
only in production, so this exercises the real function against a real
temporary database.
"""
from __future__ import annotations
import importlib.util
import sqlite3
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TOOL = REPO / "tools/natc_compile.py"


def _load(tmp_db: Path):
    """Import natc_compile with RUNS_DB pointed at a throwaway file."""
    sys.path.insert(0, str(REPO / "tools"))
    spec = importlib.util.spec_from_file_location("natc_compile_ledger", TOOL)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    mod.RUNS_DB = str(tmp_db)
    return mod


def test_log_attempt_writes_a_row_including_rung(tmp_path, capsys):
    db_path = tmp_path / "runs.sqlite"
    mod = _load(db_path)

    mod.log_attempt({
        "worker": "fixture", "model": "fixture-model", "rung": "9",
        "unit": "main/dolphin/os/OSFixture", "symbol": "FixtureFn",
        "attempt": 1, "score": 100.0, "wall_ms": 19, "note": "fixture",
        "src_sha": "deadbeef", "compiler": "GC/1.2.5n", "ok": True,
        "cache_hit": False, "kind": "attempt", "ctx_sha": "cafe",
    })

    # A swallowed exception is the exact failure mode this guards, so assert on
    # the row rather than on the return value.
    con = sqlite3.connect(db_path)
    rows = con.execute(
        "select worker, model, rung, unit, symbol, score, kind from attempts"
    ).fetchall()
    con.close()

    warn = capsys.readouterr().err
    assert rows, f"log_attempt wrote no row; stderr was: {warn!r}"
    assert len(rows) == 1
    worker, model, rung, unit, symbol, score, kind = rows[0]
    assert worker == "fixture"
    assert model == "fixture-model"
    assert rung == "9", "the rung telemetry column must round-trip, not be dropped"
    assert unit == "main/dolphin/os/OSFixture"
    assert symbol == "FixtureFn"
    assert score == 100.0
    assert kind == "attempt"
    assert "telemetry write failed" not in warn


def test_duplicate_detection_still_returns_prior_rows(tmp_path):
    """`dup` is what stops a worker re-submitting unchanged source. If the
    write silently fails, dup is always empty and the guard fails open."""
    mod = _load(tmp_path / "runs.sqlite")
    row = {
        "worker": "fixture", "model": "m", "rung": "1",
        "unit": "main/dolphin/os/OSFixture", "symbol": "FixtureFn",
        "attempt": 1, "score": 88.0, "wall_ms": 19, "note": "",
        "src_sha": "samesha", "compiler": "GC/1.2.5n", "ok": True,
        "cache_hit": False, "kind": "attempt", "ctx_sha": "ctx",
    }
    assert mod.log_attempt(dict(row)) == []          # first sighting
    dup = mod.log_attempt(dict(row, attempt=2))      # same src_sha
    assert dup, "second attempt on identical source must report the prior row"
    assert dup[0][1] == 88.0
