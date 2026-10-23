"""primer.py SYM FILE OUTDIR [MW]: put a shared literal-pool primer in front of FILE.

FILE must use native literals (`25.0f`, local aggregate initializers). Runs
fixup_evidence.shared_pool_primer on it, writes OUTDIR/primerN.c and checks each."""
import sys
sys.path.insert(0, 'tools')
from pathlib import Path
from fzgx.project import Project
from fzgx import oracle, fixup_evidence

sym, src, out = sys.argv[1], Path(sys.argv[2]), Path(sys.argv[3])
mw = sys.argv[4] if len(sys.argv) > 4 else None
out.mkdir(parents=True, exist_ok=True)
p = Project()
body = src.read_text()
base = oracle.check(p, sym, 5000, source=src, mw_version=mw)
print('base', base.percent)
for i, cand in enumerate(fixup_evidence.shared_pool_primer(p, sym, body, base)):
    text = cand[1] if isinstance(cand, tuple) else cand
    f = out / f'primer{i}.c'
    f.write_text(text)
    r = oracle.check(p, sym, 5000, source=f, mw_version=mw)
    print(f, r.percent, 'MATCH' if r.matched else 'POOL' if r.matched_pool else '')
