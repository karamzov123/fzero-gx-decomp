#!/usr/bin/env python3
"""Audit ledger `best_percent` values against the compile path that produced them.

A symbol's unit can be carved AFTER the attempt that recorded its best score.
The attempt then measured a different compile path (usually the pre-carve shared
TU, without the unit's pinned -O level), and the ledger carries a score that is
not reproducible today. `fn_80078360` is the worked example: best_percent
99.87288 from five attempts, but every stored body now compiles to 63.2%.

Read-only. No build, no ledger writes, no claims.

Usage:
    .venv/bin/python tools/stale_score_audit.py                # all >=99% unmatched
    .venv/bin/python tools/stale_score_audit.py --min-pct 95   # wider net
    .venv/bin/python tools/stale_score_audit.py --symbol fn_80078360
"""
import argparse
import json
import sqlite3
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def unit_registered_at(source: str):
    """Unix ts when `source` first appeared in units.json, or None."""
    pat = json.dumps(source)[1:-1]  # embedded quotes without JSON wrapper
    out = subprocess.run(
        ["git", "log", "-1", "--format=%ct", "-S" + pat, "--", "config/GFZE01/units.json"],
        cwd=ROOT, capture_output=True, text=True,
    ).stdout.strip()
    return int(out) if out.isdigit() else None


def best_attempt_ended(cur, symbol, best_pct):
    """Unix ts of the attempt that PRODUCED best_percent, not merely the latest one.

    Using max(ended) is wrong: any later attempt (including a release with no
    score, or a re-measure after the carve) postdates the unit registration and
    hides the staleness. Match on the recorded score instead.
    """
    row = cur.execute(
        "select max(ended) from attempts where symbol=?"
        " and final_percent is not null and final_percent>=?",
        (symbol, best_pct - 0.01),
    ).fetchone()
    if not row or row[0] is None:
        row = cur.execute(
            "select max(ended) from attempts where symbol=? and final_percent is not null",
            (symbol,),
        ).fetchone()
    return row[0] if row else None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--min-pct", type=float, default=99.0)
    ap.add_argument("--symbol")
    ap.add_argument("--json", action="store_true")
    args = ap.parse_args()

    db = sqlite3.connect(f"file:{ROOT / '.fzgx' / 'ledger.db'}?mode=ro", uri=True)
    cur = db.cursor()

    units = {}
    for e in json.load(open(ROOT / "config/GFZE01/units.json")):
        for s in e["symbols"]:
            units[s] = e["source"]

    if args.symbol:
        rows = cur.execute(
            "select symbol,best_percent,attempts,size,status from functions where symbol=?",
            (args.symbol,),
        ).fetchall()
    else:
        rows = cur.execute(
            "select symbol,best_percent,attempts,size,status from functions"
            " where status='unmatched' and best_percent>=? order by best_percent desc",
            (args.min_pct,),
        ).fetchall()

    stale, nounit, fresh = [], [], []
    for sym, pct, att, size, status in rows:
        src = units.get(sym)
        if not src:
            nounit.append((sym, pct, att, size, status))
            continue
        created = unit_registered_at(src)
        ended = best_attempt_ended(cur, sym, pct)
        if created and ended and created > ended + 3600:
            stale.append((sym, pct, att, size, src, round((created - ended) / 86400, 1)))
        else:
            fresh.append((sym, pct, att, size, src))

    if args.json:
        print(json.dumps({"stale": stale, "no_unit": nounit, "fresh_count": len(fresh)}, indent=1))
        return 0

    print(f"scanned {len(rows)} symbols (>= {args.min_pct}% unmatched)\n")
    print(f"STALE - unit carved after the best attempt ({len(stale)}):")
    for sym, pct, att, size, src, days in stale:
        print(f"  {pct:8.4f} {att:3d}a {size:6d}B  {sym:18s} {days:>5}d newer  {src}")
    print(f"\nNO UNIT ENTRY ({len(nounit)}):")
    for sym, pct, att, size, status in nounit:
        print(f"  {pct:8.4f} {att:3d}a {size:6d}B  {sym:18s} status={status}")
    print(f"\nFRESH - unit predates the best attempt ({len(fresh)}); the productive set:")
    for sym, pct, att, size, src in fresh:
        print(f"  {pct:8.4f} {att:3d}a {size:6d}B  {sym:18s} {src}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
