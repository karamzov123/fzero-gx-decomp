"""structscan.py [OUT.json] [MODULE...]: rank open functions' best saved bodies (fuzzy/GFZE01)
by STRUCTURAL difference: opcodes inserted/deleted/replaced after aligning the mnemonic
sequences, vs. same-opcode words that differ only in operands (registers, offsets).

A body whose residue is mostly operand-only is an allocator problem; a body with a few dozen
structural opcodes is usually a semantic slip (wrong constant, missing statement, wrong
type) that a careful reading of the assembly fixes. Prints the table sorted by structural
count, smallest first, with the function size.
"""
import difflib
import json
import shlex
import sqlite3
import subprocess
import sys
import tempfile
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from fzgx.project import Project  # noqa: E402
from fzgx import oracle  # noqa: E402

import capstone  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
CS = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)


def mnemonics(words):
    out = []
    for w in words:
        ins = list(CS.disasm(w.to_bytes(4, 'big'), 0))
        out.append(ins[0].mnemonic if ins else f'.word')
    return out


def classify(tgt, ours):
    a, b = mnemonics(tgt), mnemonics(ours)
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    structural = operand = 0
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == 'equal':
            operand += sum(1 for k in range(i2 - i1) if tgt[i1 + k] != ours[j1 + k])
        else:
            structural += max(i2 - i1, j2 - j1)
    return structural, operand


def main():
    out = Path(sys.argv[1]) if len(sys.argv) > 1 else None
    mods = set(sys.argv[2:])
    p = Project()
    db = sqlite3.connect(ROOT / '.fzgx/ledger.db')
    open_ = {r[0]: r[1] for r in db.execute(
        "select symbol,size from functions where status in ('unmatched','blocked')")}
    index = json.loads((ROOT / 'fuzzy/GFZE01/index.json').read_text())
    groups = defaultdict(list)
    for e in index:
        if e['symbol'] not in open_ or (mods and e['module'] not in mods):
            continue
        src = ROOT / 'fuzzy/GFZE01' / e['module'] / (e['symbol'].replace(':', '__') + '.c')
        if not src.exists():
            continue
        groups[(e['mw'], tuple(e['flags']))].append((e, src))
    tmp = Path(tempfile.mkdtemp(prefix='structscan'))
    rows = []
    for (mw, flags), items in groups.items():
        base = [str(ROOT / 'build/tools/wibo'), str(ROOT / 'build/compilers' / mw / 'mwcceppc.exe')]
        base += list(flags) + ['-nofail', '-c']
        for i in range(0, len(items), 32):
            chunk = items[i:i + 32]
            od = tmp / f'{abs(hash((mw, flags)))}_{i}'
            od.mkdir(parents=True, exist_ok=True)
            srcs = []
            for k, (e, src) in enumerate(chunk):
                dst = od / f's{k}_{src.name}'
                dst.write_text(src.read_text())
                srcs.append(dst)
            subprocess.run(base + [str(s) for s in srcs] + ['-o', str(od)], cwd=ROOT,
                           capture_output=True, timeout=600)
            for (e, src), s in zip(chunk, srcs):
                sym = p.resolve(e['symbol'])
                obj = od / (s.stem + '.o')
                tgt = oracle.words(p.target_object_for(sym), sym.name)
                ours = oracle.words(obj, sym.name) if obj.exists() else None
                if tgt is None or ours is None:
                    rows.append(dict(symbol=e['symbol'], module=e['module'], size=open_[e['symbol']],
                                     percent=e['percent'], structural=None, operand=None))
                    continue
                st, op = classify(tgt, ours)
                rows.append(dict(symbol=e['symbol'], module=e['module'], size=open_[e['symbol']],
                                 percent=e['percent'], structural=st, operand=op,
                                 length=f'{len(ours)}/{len(tgt)}', mw=mw))
    rows.sort(key=lambda r: (r['structural'] is None, r['structural'] or 0, -r['size']))
    for r in rows:
        print(f"{r['symbol']:22} {r['module']:13} {r['size']:6} {r['percent']:6} "
              f"struct={r['structural']} operand={r['operand']} {r.get('length', '')}")
    if out:
        out.write_text(json.dumps(rows, indent=1))


if __name__ == '__main__':
    main()
