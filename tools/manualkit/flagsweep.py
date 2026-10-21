"""flagsweep.py [MODULE ...] [--max-words N]: rescore every unmatched function's best saved body
under a grid of compiler versions and section/prologue flags, batched per configuration.

Prints functions whose best configuration differs from retail by at most N masked words
(default 12), with the words under each configuration. Scratch objects only.
"""
import sqlite3
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from fzgx.project import Project
from fzgx import oracle

ROOT = Path(__file__).resolve().parents[2]
CONFIGS = [
    ('GC/1.2.5n', None), ('GC/1.2.5n', '-sdata 0 -sdata2 0'),
    ('GC/1.3.2', None), ('GC/1.3.2', '-sdata 0 -sdata2 0'), ('GC/1.3.2', '-use_lmw_stmw on'),
    ('GC/1.3.2', '-sdata 0 -sdata2 0 -use_lmw_stmw on'), ('GC/2.6', None), ('GC/1.1', None),
]


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    limit = int(sys.argv[sys.argv.index('--max-words') + 1]) if '--max-words' in sys.argv else 12
    modules = set(a for a in args if not a.isdigit())
    p = Project()
    db = sqlite3.connect(ROOT / '.fzgx/ledger.db')
    rows = db.execute("select f.symbol, f.module from functions f where f.status = 'unmatched'").fetchall()
    bodies = {}
    for sym, module in rows:
        if modules and module not in modules:
            continue
        for path, _ in db.execute("select best_body_path, final_percent from attempts where symbol=? and "
                                  "best_body_path is not null and best_body_path != '' order by final_percent desc",
                                  (sym,)):
            q = Path(path) if path.startswith('/') else ROOT / path
            if q.exists():
                bodies[sym] = (module, q)
                break
    work = Path('/tmp/claude-1000/fzgx-flagsweep')
    targets = {}
    for sym, (module, _) in bodies.items():
        s = p.resolve(sym)
        obj = p.target_object_for(s) if s else None
        if obj:
            targets[sym] = oracle.words(obj, s.name)
    results = defaultdict(dict)
    by_module = defaultdict(list)
    for sym, (module, src) in bodies.items():
        if sym in targets:
            by_module[module].append((sym, src))
    for module, items in by_module.items():
        for mw, flags in CONFIGS:
            tag = (mw + '_' + (flags or 'default')).replace('/', '_').replace(' ', '')
            d = work / module / tag
            d.mkdir(parents=True, exist_ok=True)
            files = []
            for sym, src in items:
                f = d / (sym.replace(':', '__') + '.c')
                f.write_text(src.read_text())
                files.append((sym, f))
            try:
                objs = oracle.compile_many(p, module, [f for _, f in files], d / 'obj', mw_version=mw,
                                           extra_cflags=flags)
            except Exception as error:
                print('compile failure', module, tag, error, file=sys.stderr)
                continue
            for sym, f in files:
                w = oracle.words(objs[f], p.resolve(sym).name) if f in objs else None
                if w is not None:
                    tgt = targets[sym]
                    results[sym][(mw, flags)] = len(oracle.word_score(tgt, w)[1]) + abs(len(tgt) - len(w))
    size = dict(db.execute("select symbol, size from functions"))
    ranked = sorted(((min(r.values()), sym) for sym, r in results.items() if r), key=lambda x: (x[0], -size[x[1]]))
    for best, sym in ranked:
        if best > limit:
            break
        r = results[sym]
        cfg = min(r, key=r.get)
        print(f"{sym:16} {size[sym]:5} best={best:3} {cfg[0]} {cfg[1] or ''} | "
              + ' '.join(f"{m[3:]}{'+' + f if f else ''}:{v}" for (m, f), v in r.items()))


if __name__ == '__main__':
    main()
