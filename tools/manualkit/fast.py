"""fast.py SYMBOL DIR [MW] [FLAGS]: compile DIR/*.c in parallel, rank by differing masked words."""
import sys
from pathlib import Path
sys.path.insert(0, str(__import__('pathlib').Path(__file__).resolve().parents[1]))
from fzgx.project import Project
from fzgx import oracle
sym_name, d = sys.argv[1], Path(sys.argv[2])
mw = sys.argv[3] if len(sys.argv) > 3 and sys.argv[3] else None
fl = sys.argv[4] if len(sys.argv) > 4 else None
p = Project()
sym = p.resolve(sym_name)
tgt = oracle.words(p.target_object_for(sym), sym.name)
srcs = sorted(d.glob('*.c'))
objs = oracle.compile_many(p, sym.module, srcs, d / 'obj', mw_version=mw, extra_cflags=fl)
res = []
for s in srcs:
    o = objs.get(s)
    w = oracle.words(o, sym.name) if o else None
    if w is None:
        res.append((9999, s.name, 'ERR')); continue
    sc, bad = oracle.word_score(tgt, w)
    res.append((len(bad) + abs(len(tgt) - len(w)), s.name, f'{sc:.2f} len={len(w)}/{len(tgt)}'))
res.sort()
for r in res[:int(sys.argv[5]) if len(sys.argv) > 5 else 15]:
    print(*r)
