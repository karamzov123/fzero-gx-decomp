import sys, shutil
from pathlib import Path
sys.path.insert(0, str(__import__('pathlib').Path(__file__).resolve().parents[1]))
from fzgx.project import Project
from fzgx import oracle
p = Project()
syms = sys.argv[1].split(',')
vers = ['GC/1.1','GC/1.2.5n','GC/1.3','GC/1.3.2','GC/2.0','GC/2.5','GC/2.6','GC/2.7']
root = Path('/tmp/fzgx-vsweep')
for s in syms:
    import sqlite3
    db = sqlite3.connect(str(__import__('pathlib').Path(__file__).resolve().parents[2] / '.fzgx/ledger.db'))
    rows = db.execute("select best_body_path, final_percent from attempts where symbol=? and best_body_path is not null and best_body_path != '' order by final_percent desc", (s,)).fetchall()
    src = None
    for bp, _ in rows:
        q = Path(bp) if bp.startswith('/') else __import__('pathlib').Path(__file__).resolve().parents[2] / bp
        if q.exists(): src = q; break
    if src is None: print(s, 'no saved body'); continue
    sym = p.resolve(s)
    tobj = p.target_object_for(sym)
    if sym is None or tobj is None: print(s, 'no target'); continue
    tgt = oracle.words(tobj, sym.name)
    d = root / s; d.mkdir(parents=True, exist_ok=True)
    f = d / 'w.c'; shutil.copy(src, f)
    out = []
    for v in vers:
        try:
            objs = oracle.compile_many(p, sym.module, [f], d / v.replace('/', '_'), mw_version=v)
            w = oracle.words(objs[f], sym.name) if f in objs else None
        except Exception as e:
            w = None
        out.append(f'{v[3:]}:{"ERR" if w is None else len(oracle.word_score(tgt, w)[1]) + abs(len(tgt)-len(w))}')
    print(s, ' '.join(out), flush=True)
