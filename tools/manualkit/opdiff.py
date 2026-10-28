"""opdiff.py SYM FILE MW [FLAGS...]: opcode-level difflib of our compile vs retail.

Shows inserted/deleted instruction blocks, so a structural misplacement (error paths laid out
in a different order, a missing copy) stands out from register noise. objdump spells some
encodings differently (addis/subis, rlwinm/extrwi, unrelocated bl): ignore those rows."""
import sys, re, json, glob, subprocess, difflib, tempfile
from pathlib import Path
sys.path.insert(0, 'tools')
from fzgx import oracle
from fzgx.project import Project
sym, src, mw = sys.argv[1], Path(sys.argv[2]), sys.argv[3]
flags = " ".join(sys.argv[4:]) or None
p = Project(); s = p.resolve(sym)
out = Path(tempfile.mkdtemp(prefix='opdiff'))
objs = oracle.compile_many(p, s.module, [src], out, mw_version=mw, extra_cflags=flags)
obj = objs[src]
dis = subprocess.run(['build/binutils/powerpc-eabi-objdump', '-d', '--no-show-raw-insn', str(obj)], capture_output=True, text=True).stdout
ours = []; on = False
for l in dis.split('\n'):
    if re.match(r'^[0-9a-f]+ <%s>:' % re.escape(sym), l): on = True; continue
    if on and re.match(r'^[0-9a-f]+ <', l): break
    m = re.match(r'\s+([0-9a-f]+):\s+(\S+)\s*(.*)', l)
    if on and m: ours.append((int(m.group(1), 16), m.group(2), m.group(3)))
ret = []
for f in glob.glob('.fzgx/asm_index_GFZE01_*.json'):
    d = json.load(open(f))['functions']
    if sym in d:
        for l in d[sym]['asm']:
            m = re.match(r'([0-9A-F]+): (\S+)\s*(.*)', l)
            if m: ret.append((int(m.group(1), 16), m.group(2), m.group(3)))
base = ret[0][0]
A = [x[1] for x in ret]; B = [x[1] for x in ours]
sm = difflib.SequenceMatcher(None, A, B, autojunk=False)
print('retail', len(A), 'ours', len(B), 'ratio', round(sm.ratio(), 4))
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal': continue
    print(f'{tag:7} R[{(ret[i1][0]-base) if i1 < len(ret) else -1:#06x}+{i2-i1}] O[{ours[j1][0] if j1 < len(ours) else -1:#06x}+{j2-j1}]  R: {" ; ".join(a+" "+b for _,a,b in ret[i1:min(i2,i1+4)])}  | O: {" ; ".join(a+" "+b for _,a,b in ours[j1:min(j2,j1+4)])}')
