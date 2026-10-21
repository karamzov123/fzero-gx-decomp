"""perm.py SYMBOL TEMPLATE OUTDIR FIXED_TAIL var:decl ...  -- exhaustive declaration orders (@DECLS@), chunked."""
import sys, itertools
from pathlib import Path
sys.path.insert(0, str(__import__('pathlib').Path(__file__).resolve().parents[1]))
from fzgx.project import Project
from fzgx import oracle
sym_name, tpl, out, tail = sys.argv[1], Path(sys.argv[2]).read_text(), Path(sys.argv[3]), sys.argv[4]
decls = dict(a.split(':', 1) for a in sys.argv[5:])
p = Project(); sym = p.resolve(sym_name)
import os; MW = os.environ.get("MW") or None; FLAGS = os.environ.get("FLAGS") or None
tgt = oracle.words(p.target_object_for(sym), sym.name)
out.mkdir(parents=True, exist_ok=True)
res = []
perms = list(itertools.permutations(decls))
for c in range(0, len(perms), 2000):
    chunk = perms[c:c+2000]; files = []
    for i, o in enumerate(chunk):
        f = out / f'c{i:05d}.c'
        f.write_text(tpl.replace('@DECLS@', ''.join(f'    {decls[v]};\n' for v in o) + tail.replace('\\n', '\n')))
        files.append((o, f))
    objs = oracle.compile_many(p, sym.module, [f for _, f in files], out / "obj", mw_version=MW, extra_cflags=FLAGS)
    for o, f in files:
        w = oracle.words(objs[f], sym.name) if f in objs else None
        res.append((9999 if w is None else len(oracle.word_score(tgt, w)[1]) + abs(len(tgt) - len(w)), o))
res.sort()
from collections import Counter
print(Counter(r[0] for r in res).most_common(8))
for r in res[:5]: print(*r)
best = res[0][1]
(out / 'best.c').write_text(tpl.replace('@DECLS@', ''.join(f'    {decls[v]};\n' for v in best) + tail.replace('\\n', '\n')))
