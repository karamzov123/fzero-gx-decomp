"""Helpers for parallel manual matching sessions (see docs/MANUAL.md).

  uv run tools/manual.py queue --shard K/N [--by closeness|bytes] [--top 30]
      This session's slice of the unmatched frontier, best candidates first. Slices are
      disjoint: a function belongs to shard crc32(symbol) % N, so N sessions never pick the same
      function. Claimed and capped-out functions are listed too (attempts column); the claim
      itself is atomic, so a race still cannot double-assign.

  uv run tools/manual.py try SYMBOL DIR [--mw GC/1.3.2] [--flags '...'] [-v]
      Compile and diff every DIR/*.c against SYMBOL's retail code in one go (scratch objects only;
      nothing in the tree changes). -v prints the rows that still differ.
"""
from __future__ import annotations

import argparse
import json
import sqlite3
import sys
import zlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))


def queue(args) -> None:
    k, n = (int(x) for x in args.shard.split('/'))
    db = sqlite3.connect(ROOT / '.fzgx/ledger.db')
    db.row_factory = sqlite3.Row
    fuzzy = {}
    index = ROOT / 'fuzzy/GFZE01/index.json'
    if index.exists():
        fuzzy = {r['symbol']: r.get('percent') or 0.0 for r in json.loads(index.read_text())}
    notes = {}
    noise = ('plateau:', 'harness crash', 'batch interrupted', 'Four-provider recovery', 'expired', 'sweep:')
    for sym, note in db.execute("SELECT symbol, notes FROM attempts WHERE notes IS NOT NULL AND notes != '' ORDER BY id"):
        if not note.startswith(noise):  # keep the last finding a person or model wrote down
            notes[sym] = note
    rows = []
    for r in db.execute("SELECT symbol, module, size, status, attempts, best_percent, claimed_by FROM functions "
                        "WHERE status IN ('unmatched', 'claimed')"):
        if zlib.crc32(r['symbol'].encode()) % n != k:
            continue
        best = max(r['best_percent'] or 0.0, fuzzy.get(r['symbol'], 0.0))
        if args.by == 'bytes':
            key = -(r['size'] * (best / 100) ** 8)
        else:  # closeness: the nearest first, smaller first within half a point
            key = (-round(best * 2) / 2, r['size'])
        rows.append((key, r, best))
    rows.sort(key=lambda x: x[0])
    print(f'shard {k}/{n}: {len(rows)} functions  (by {args.by})')
    print(f"{'symbol':18} {'module':13} {'bytes':>6} {'best%':>6} {'att':>4}  last note")
    for _, r, best in rows[:args.top]:
        state = f' [claimed by {r["claimed_by"]}]' if r['status'] == 'claimed' else ''
        note = (notes.get(r['symbol']) or '').replace('\n', ' ')[:70]
        print(f"{r['symbol']:18} {r['module']:13} {r['size']:6} {best:6.2f} {r['attempts']:4}  {note}{state}")


def try_bodies(args) -> None:
    from fzgx.project import Project
    from fzgx import oracle
    from fzgx.lint import allocator_scaffolding, lint_file
    p = Project()
    for f in sorted(Path(args.dir).glob('*.c')):
        try:
            r = oracle.check(p, args.symbol, 40, source=f, mw_version=args.mw, extra_cflags=args.flags)
        except Exception as error:  # one broken variant never stops the batch
            print(f'{f.name:28} EXC {error}')
            continue
        if not r.ok:
            print(f'{f.name:28} compile error: ' + (r.error or '')[-240:].replace('\n', ' '))
            continue
        lint = [x[0] for x in lint_file(f)] + (['scaffolding'] if allocator_scaffolding(f.read_text()) else [])
        tag = 'MATCH' if r.matched else 'POOL' if r.matched_pool else ''
        print(f'{f.name:28} {r.percent:8.3f} {tag:5} {"lint=" + ",".join(lint) if lint else ""}')
        if args.v and not r.matched:
            for line in r.diff:
                if not line.startswith(('  ', 'p ')):
                    print('    ' + line)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)
    q = sub.add_parser('queue')
    q.add_argument('--shard', default='0/1', help='K/N: this session is K of N (0-based)')
    q.add_argument('--by', choices=('closeness', 'bytes'), default='closeness')
    q.add_argument('--top', type=int, default=30)
    t = sub.add_parser('try')
    t.add_argument('symbol')
    t.add_argument('dir')
    t.add_argument('--mw', default=None, help='compiler, e.g. GC/1.3.2 (default: the function\'s own)')
    t.add_argument('--flags', default=None, help='extra cflags, e.g. "-O4,s"')
    t.add_argument('-v', action='store_true')
    args = ap.parse_args()
    queue(args) if args.cmd == 'queue' else try_bodies(args)


if __name__ == '__main__':
    main()
