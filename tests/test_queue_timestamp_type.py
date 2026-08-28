#!/usr/bin/env python3
"""Queue timestamps must all be REAL unix epoch.

2026-08-28. natc_queue_sweep wrote `updated_at=datetime('now')` — a TEXT UTC
string — while every other writer used time.time(). The column is declared
`updated_at REAL NOT NULL`, but sqlite's dynamic typing accepts anything, so
50 of 574 rows silently became TEXT.

The damage was not cosmetic. `datetime(updated_at,'unixepoch')` renders blank
for a TEXT row, and a WHERE on `updated_at > strftime('%s',...)` compares a
string against a number — so those rows sorted and filtered wrongly. It made
me read "8 batches gated since 12:40" off a queue whose last activity was
12:09, and any delivery-latency metric over the queue was reading the same
mixed column.
"""
from __future__ import annotations
import sqlite3
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import natc_submission_queue as q  # noqa: E402

SWEEP = REPO / "tools/natc_queue_sweep.py"


def test_sweep_does_not_write_a_text_timestamp():
    src = SWEEP.read_text()
    assert "updated_at=datetime('now')" not in src, (
        "datetime('now') writes TEXT into a REAL column")


def test_live_queue_has_no_text_timestamps():
    db = Path.home() / ".cache/natc/submission-queue.sqlite3"
    if not db.exists():
        return
    con = sqlite3.connect(f"file:{db}?mode=ro", uri=True)
    bad = con.execute(
        "select count(*) from batches where typeof(updated_at)!='real' "
        "or typeof(registered_at)!='real'").fetchone()[0]
    con.close()
    assert bad == 0, f"{bad} row(s) carry a non-REAL timestamp"


def test_register_writes_real_epoch(tmp_path):
    d = tmp_path / "b"
    d.mkdir()
    (d / "u.c").write_text("// dest: src/u.c\nint f(void){return 0;}\n")
    (d / "CARD.md").write_text("# c\n- // provenance: original\n")
    c = q.open_db(str(tmp_path / "q.sqlite3"))
    row = q.register(c, "w/b", "w", str(d))
    for col in ("registered_at", "updated_at"):
        v = row[col]
        assert isinstance(v, float), f"{col} is {type(v).__name__}, want float"
        assert abs(v - time.time()) < 120, f"{col} is not a current epoch"
    c.close()
