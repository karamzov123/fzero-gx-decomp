#!/usr/bin/env python3
"""Batch-scan carved units for the wrong-compiler bug.

A carve leaves `mw_version: null`, so `version_for()` falls back to the module
default. Pre-carve the same body went through `version_candidates()` and kept the
best-fitting compiler, so a unit can score far below its recorded best purely
because of the pin. `fn_80043798` is the worked example: 78.0% at the module
default `GC/1.2.5n -O4,p`, 99.7% under `GC/1.3.2`.

For each candidate symbol this writes each `main`-module candidate compiler onto
the unit, recompiles the saved best body, and reports the score per compiler. The
units.json edit is always restored, so the scan itself changes nothing; symbols
whose best compiler is not the module default are reported for pinning.

    .venv/bin/python tools/pin_scan.py --symbols fn_80043798,fn_800288C4
    .venv/bin/python tools/pin_scan.py --min-pct 99 --limit 12
    .venv/bin/python tools/pin_scan.py --min-pct 99 --apply          # pin the winners
"""
import argparse
import json
import shutil
import subprocess
import sqlite3
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
UNITS = ROOT / "config/GFZE01/units.json"
PY = ROOT / ".venv/bin/python"
CLI = ROOT / "tools/fzgx.py"


def candidates_for(module):
    sys.path.insert(0, str(ROOT / "tools"))
    from fzgx import oracle  # noqa: E402
    proj = oracle.Project(str(ROOT))
    return oracle.version_candidates(proj, module)


def best_body(symbol):
    db = sqlite3.connect(f"file:{ROOT / '.fzgx' / 'ledger.db'}?mode=ro", uri=True)
    row = db.execute(
        "select best_body_path from attempts where symbol=? and best_body_path is not null"
        " order by final_percent desc limit 1", (symbol,)).fetchone()
    db.close()
    return Path(row[0]) if row and Path(row[0]).exists() else None


def unit_of(symbol):
    for e in json.load(open(UNITS)):
        if symbol in e["symbols"]:
            return e
    return None


def set_pin(symbol, mw, cf):
    data = json.load(open(UNITS))
    for e in data:
        if symbol in e["symbols"]:
            e["mw_version"] = mw
            e["extra_cflags"] = [cf] if cf else []
    UNITS.write_text(json.dumps(data, indent=2))


def score(symbol, body, agent="pin-scan"):
    """Compile `body` under the pin currently written on `symbol`'s unit.

    write-unit requires the caller to hold the claim, so claim and release around
    each compile. --max-attempts is raised because the harness plateau guard would
    otherwise stop the scan after a few non-improving candidates.
    """
    subprocess.run([str(PY), str(CLI), "claim", symbol, "--agent", agent,
                    "--max-attempts", "50"], cwd=ROOT, capture_output=True, text=True)
    try:
        out = subprocess.run([str(PY), str(CLI), "write-unit", symbol,
                              "--file", str(body), "--agent", agent],
                             cwd=ROOT, capture_output=True, text=True, timeout=1800)
        try:
            d = json.loads(out.stdout)
        except Exception:
            return None
        if not d.get("ok"):
            return ("ERR", str(d.get("error"))[:60])
        line = d.get("check", "").split("\n")[0]
        try:
            return (float(line.split("%")[0].split(":")[-1].strip()), line)
        except Exception:
            return (None, line)
    finally:
        subprocess.run([str(PY), str(CLI), "release", symbol, "--agent", agent,
                        "--reason", "pin-scan candidate probe"],
                       cwd=ROOT, capture_output=True, text=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--symbols")
    ap.add_argument("--min-pct", type=float, default=99.0)
    ap.add_argument("--limit", type=int, default=10)
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()

    if args.symbols:
        syms = [s.strip() for s in args.symbols.split(",") if s.strip()]
    else:
        db = sqlite3.connect(f"file:{ROOT / '.fzgx' / 'ledger.db'}?mode=ro", uri=True)
        syms = [r[0] for r in db.execute(
            "select symbol from functions where status='unmatched' and best_percent>=?"
            " order by best_percent desc", (args.min_pct,))]
        db.close()

    backup = UNITS.read_text()
    winners, results, scanned = [], [], []
    try:
        for sym in syms[:args.limit]:
            u = unit_of(sym)
            if not u or u.get("mw_version"):
                continue
            body = best_body(sym)
            if not body:
                continue
            cands = candidates_for(u["module"])
            scores = {}
            try:
                for mw, cf in cands:
                    set_pin(sym, mw, cf)
                    r = score(sym, body)
                    scores[f"{mw} {cf or ''}".strip()] = r
            finally:
                # Always undo the probe pin and drop the claim, even if the run is
                # interrupted, so a killed scan cannot leave the tree or ledger dirty.
                UNITS.write_text(backup)
                subprocess.run([str(PY), str(CLI), "release", sym, "--agent", "pin-scan",
                                "--reason", "pin-scan candidate probe"],
                               cwd=ROOT, capture_output=True, text=True)
            scanned.append(sym)

            nums = {k: v[0] for k, v in scores.items()
                    if isinstance(v, tuple) and isinstance(v[0], float)}
            if not nums:
                continue
            top = max(nums, key=lambda k: nums[k])
            default = candidates_for(u["module"])[0]
            dkey = f"{default[0]} {default[1] or ''}".strip()
            gain = nums[top] - nums.get(dkey, 0)
            results.append((sym, nums, top, gain))
            print(f"{sym:18s} default({dkey})={nums.get(dkey)}  best({top})={nums[top]}  gain={gain:+.1f}")
            if gain > 1.0:
                winners.append((sym, top))
    finally:
        UNITS.write_text(backup)

    print(f"\nscanned {len(scanned)} unit(s); units.json restored")

    if args.apply and winners:
        data = json.load(open(UNITS))
        for sym, spec in winners:
            mw, _, cf = spec.partition(" ")
            for e in data:
                if sym in e["symbols"]:
                    e["mw_version"] = mw
                    e["extra_cflags"] = [cf] if cf else []
        UNITS.write_text(json.dumps(data, indent=2))
        print(f"\npinned {len(winners)} unit(s): " + ", ".join(s for s, _ in winners))
        print("RUN THE GATE: ninja build/GFZE01/ok && sha1sum -c config/GFZE01/build.sha1 && lint && tests")
    return 0


if __name__ == "__main__":
    sys.exit(main())
