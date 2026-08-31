import sqlite3
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import natc_rank


def test_null_selector_dry_run_does_not_mutate(monkeypatch, capsys):
    c = sqlite3.connect(":memory:")
    c.execute("create table units(unit text primary key, worker text, status text, leased_at real, lease_token text, disposition text, parked_at real, note text)")
    c.execute("insert into units values('main/dolphin/os/SIBios','natc1','leased',?,?,?, ?,?)", (time.time(), 'tok', None, None, None))
    c.commit()
    monkeypatch.setattr(natc_rank, "unit_has_fresh_budget_symbol", lambda *a, **k: False)
    found = natc_rank.reconcile_null_leases(c, worker="natc1", apply=False, protected=set())
    assert found == [("main/dolphin/os/SIBios", "natc1")]
    assert c.execute("select status,worker from units").fetchone() == ("leased", "natc1")
    assert "NULL SELECTOR" in capsys.readouterr().out


def test_null_selector_apply_parks_and_clears_lease(monkeypatch):
    c = sqlite3.connect(":memory:")
    c.execute("create table units(unit text primary key, worker text, status text, leased_at real, lease_token text, disposition text, parked_at real, note text)")
    c.execute("insert into units values('u','w','leased',?,?,?, ?,?)", (time.time(), 'tok', None, None, None))
    c.commit()
    monkeypatch.setattr(natc_rank, "unit_has_fresh_budget_symbol", lambda *a, **k: False)
    natc_rank.reconcile_null_leases(c, worker="w", apply=True, protected=set())
    row = c.execute("select status,worker,lease_token,disposition,note from units").fetchone()
    assert row[:4] == ("plateau", None, None, "plateau")
    assert "selector-null" in row[4]
