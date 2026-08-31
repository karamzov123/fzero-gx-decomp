import json
import sqlite3
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parents[1] / "tools"))
import natc_quality_report as report


def dbs(tmp_path):
    runs = tmp_path / "runs.sqlite"
    c = sqlite3.connect(runs)
    c.execute("create table attempts (id integer, ts real, worker text, model text, unit text, symbol text, attempt integer, score real, note text, src_sha text, ok integer, kind text, ctx_sha text, rung text)")
    c.executemany("insert into attempts values (?,?,?,?,?,?,?,?,?,?,?,?,?,?)", [
        (1, 9900, "w1", "m1", "u", "s", 1, 100, "", "a", 1, "attempt", "ctx1", "r1"),
        (2, 9800, "w1", "m1", "u", "s", 2, 50, "", "a", 0, "attempt", "ctx1", "r1"),
        (3, 9700, "w1", "m1", "u", "s", None, None, "REFUSED duplicate_candidate", None, 0, "refused", "ctx2", "r1"),
        (4, 9600, None, None, "u", "s", None, None, "REFUSED attempt budget", None, 0, "refused", None, None),
        (5, 100, "old", "m", "u", "s", 1, 100, "", "z", 1, "attempt", None, "r"),
    ])
    c.commit(); c.close()
    queue = tmp_path / "queue.sqlite3"
    c = sqlite3.connect(queue)
    c.execute("create table batches (batch_id text, worker text, state text, registered_at real, updated_at real)")
    c.executemany("insert into batches values (?,?,?,?,?)", [("a", "w1", "accepted", 9900, 9901), ("b", "w1", "rejected", 9800, 9801), ("c", "w1", "ready", 100, 100)])
    c.commit(); c.close()
    return runs, queue


def test_fixture_windows_group_metrics_and_old_nulls(tmp_path):
    runs, queue = dbs(tmp_path)
    r = report.build_report(runs, queue, now=10000, since_hours=2)
    assert set(r["windows"]) == {"1", "2", "6", "24"}
    w = r["windows"]["1"]
    assert w["totals"]["attempts"] == 2
    assert w["totals"]["turns"] == 1
    assert w["totals"]["distinct_src_sha"] == 1
    assert w["totals"]["compile_ok"] == 1
    assert w["totals"]["compile_ok_rate"] == .5
    assert w["totals"]["score_positive"] == 2
    assert w["totals"]["raw_exact_score"] == 1
    assert w["totals"]["best_positive_score"] == 100
    assert w["totals"]["median_positive_score"] == 75
    assert w["totals"]["duplicate_refusals"] == 1
    assert w["totals"]["ceiling_refusals"] == 1
    assert w["totals"]["raw_100_scores_per_100_attempts"] == 50
    assert w["queue"] == {"registered": 2, "accepted": 1, "rejected": 1,
                           "verified_accepted_per_100_attempts": 50}
    assert r["windows"]["24"]["totals"]["attempts"] == 3


def test_json_and_read_only(tmp_path):
    runs, queue = dbs(tmp_path)
    before = runs.stat().st_mtime_ns
    out = report.text_report(report.build_report(runs, queue, now=10000))
    assert "1.0h:" in out or "1h:" in out
    assert runs.stat().st_mtime_ns == before
    payload = json.dumps(report.build_report(runs, queue, now=10000))
    assert json.loads(payload)["windows"]["1"]["totals"]["attempts"] == 2
