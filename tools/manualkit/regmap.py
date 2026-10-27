"""regmap.py SYM FILE [MW]: retail -> ours callee-saved GPR correspondence per 0x200-byte block.

Reads the objdiff rows of FILE against SYM and, for every row with the same register count on
both sides, counts which of our registers sits where retail has r14..r31. Only mismatched pairs
are printed. A consistent shift (retail r24..r30 -> ours r25..r31, retail r31 -> ours r24) says
one web is claimed in the wrong order; a per-block change points at one loop's variables."""
import sys, re, collections
sys.path.insert(0, 'tools')
from fzgx.project import Project
from fzgx import oracle

p = Project()
r = oracle.check(p, sys.argv[1], 5000, source=sys.argv[2],
                 mw_version=sys.argv[3] if len(sys.argv) > 3 else 'GC/1.3.2')
m = collections.defaultdict(collections.Counter)
for line in r.diff:
    if '|' not in line or line[0] in '<>':
        continue
    try:
        off = int(line[2:6], 16)
    except ValueError:
        continue
    a, b = line[6:].split('|', 1)
    ra, rb = re.findall(r'\br(\d+)\b', a), re.findall(r'\br(\d+)\b', b)
    if len(ra) == len(rb):
        for x, y in zip(ra, rb):
            if int(x) >= 14:
                m[(off // 0x200, int(x))][int(y)] += 1
print(r.percent)
for k in sorted(m):
    if any(y != k[1] for y in m[k]):
        print('blk%02x r%d ->' % k, dict(m[k]))
