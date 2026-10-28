"""cover.py [K]: for every unmatched function, the fraction of its K-instruction windows
(mnemonics, call targets, immediates; registers masked) found in any matched function of the same
module, with the best donors. Finds partial twins simscan misses (a donor whose body is a block
inside the target): fn_4_8E38 <- fn_4_9C14 landed first try that way."""
import json, glob, re, sqlite3, sys
from collections import defaultdict, Counter
K = int(sys.argv[1]) if len(sys.argv) > 1 else 10
db = sqlite3.connect('.fzgx/ledger.db')
st = {r[0]: (r[1], r[2]) for r in db.execute('select symbol,status,size from functions')}
def norm(l):
    m = re.match(r'[0-9A-F]+: (\S+)\s*(.*)', l)
    if not m: return None
    op, a = m.groups()
    if op in ('bl', 'b') and not a.startswith('.L'): return op + ' ' + a.strip()
    if op.startswith('b'): return op
    # keep immediates of loads/stores displacement (struct offsets) but drop registers
    a = re.sub(r'\br\d+\b', 'r', a); a = re.sub(r'\bf\d+\b', 'f', a)
    return op + ' ' + a
out = []
for f in glob.glob('.fzgx/asm_index_GFZE01_*.json'):
    fn = json.load(open(f))['functions']
    seqs = {s: [x for x in (norm(l) for l in v['asm']) if x] for s, v in fn.items()}
    owner = defaultdict(Counter)
    for s, q in seqs.items():
        if st.get(s, ('',0))[0] in ('matched',):
            for i in range(len(q) - K + 1):
                owner[tuple(q[i:i+K])][s] += 1
    for u, q in seqs.items():
        if st.get(u, ('',0))[0] not in ('unmatched', 'blocked') or len(q) < 80: continue
        cov = [False] * len(q); donors = Counter()
        for i in range(len(q) - K + 1):
            o = owner.get(tuple(q[i:i+K]))
            if o:
                for j in range(i, i + K): cov[j] = True
                for d in o: donors[d] += 1
        c = sum(cov) / len(q)
        out.append((round(c, 3), st[u][1], u, donors.most_common(4)))
out.sort(key=lambda r: -r[1] * r[0] ** 2)
for r in out[:60]: print(r)
