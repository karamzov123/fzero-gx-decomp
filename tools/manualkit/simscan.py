"""simscan.py [MIN_RATIO]: open functions whose instruction sequence is close to a matched one.

Mnemonic sequences (calls keep their target) per module, a trigram-Jaccard prefilter, then
difflib ratio. Each hit is a sibling to derive the C from: copy the matched unit's generated
source (build/GFZE01/gen/<unit>) and change what the asm diff shows (operands, a loop, a
constant). `fzgx reuse` only rebinds clones with identical immediates, so these are missed."""
import argparse, json, glob, re, sqlite3, difflib
from collections import Counter

ap = argparse.ArgumentParser(description=__doc__)
ap.add_argument('min_ratio', nargs='?', type=float, default=0.85)
ap.add_argument('--min-gram', type=float, default=0.6,
                help='minimum instruction-trigram Jaccard similarity')
ap.add_argument('--min-length-ratio', type=float, default=0.8,
                help='minimum donor/target instruction-count ratio')
ap.add_argument('--max-length-ratio', type=float, default=1.25,
                help='maximum donor/target instruction-count ratio')
args = ap.parse_args()
if not (0 <= args.min_ratio <= 1 and 0 <= args.min_gram <= 1
        and 0 < args.min_length_ratio <= args.max_length_ratio):
    ap.error('similarities must be in [0, 1] and length ratios positive and ordered')
db = sqlite3.connect('.fzgx/ledger.db')
st = {r[0]: (r[1], r[2]) for r in db.execute('select symbol, status, size from functions')}


def norm(line):
    m = re.match(r'[0-9A-F]+: (\S+)\s*(.*)', line)
    if not m:
        return None
    op, args = m.groups()
    return 'bl ' + args.strip() if op == 'bl' else op


res = []
for f in glob.glob('.fzgx/asm_index_GFZE01_*.json'):
    fn = json.load(open(f))['functions']
    seqs = {s: [x for x in (norm(l) for l in v['asm']) if x] for s, v in fn.items()}
    grams = {s: Counter(zip(q, q[1:], q[2:])) for s, q in seqs.items()}
    matched = [s for s in seqs if st.get(s, ('', 0))[0] == 'matched' and len(seqs[s]) >= 20]
    for u, q in seqs.items():
        if st.get(u, ('', 0))[0] not in ('unmatched', 'blocked') or len(q) < 20:
            continue
        best = None
        for m in matched:
            if not args.min_length_ratio * len(q) <= len(seqs[m]) <= args.max_length_ratio * len(q):
                continue
            inter = sum((grams[u] & grams[m]).values())
            union = sum((grams[u] | grams[m]).values())
            if not union or inter / union < args.min_gram:
                continue
            r = difflib.SequenceMatcher(None, q, seqs[m], autojunk=False).ratio()
            if best is None or r > best[0]:
                best = (r, m)
        if best and best[0] >= args.min_ratio:
            res.append((round(best[0], 3), st[u][1], u, best[1], len(q)))
res.sort(reverse=True)
for r in res:
    print(r)
print(len(res), 'functions', sum(r[1] for r in res), 'bytes')
