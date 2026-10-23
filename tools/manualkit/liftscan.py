"""liftscan.py OUT.json [MW]: score every lifter draft of an open function.

Checks `.fzgx/lift/ctx/SYM_total.c` for each unmatched/blocked function of 200+ bytes
in one oracle.check_many pass and prints (percent, size, attempts, symbol), best first.
Untouched functions often have a draft at 75-90% that a hand rewrite finishes."""
import sys, sqlite3, json
sys.path.insert(0, 'tools')
from pathlib import Path
from fzgx.project import Project
from fzgx import oracle

mw = sys.argv[2] if len(sys.argv) > 2 else 'GC/1.3.2'
p = Project()
db = sqlite3.connect('.fzgx/ledger.db')
rows = db.execute("select symbol, size, attempts from functions "
                  "where status in ('unmatched', 'blocked') and size >= 200").fetchall()
items = [(s, Path(f'.fzgx/lift/ctx/{s}_total.c')) for s, _, _ in rows]
items = [(s, f) for s, f in items if f.exists()]
info = {s: (size, att) for s, size, att in rows}
res = oracle.check_many(p, items, 0, mw_version=mw)
out = sorted(((r.percent or 0, info[s][0], info[s][1], s) for s, r in res.items()), reverse=True)
json.dump(out, open(sys.argv[1], 'w'))
for o in out[:60]:
    print(o)
