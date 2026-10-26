"""declsearch.py SYM FILE OUT [--mw GC/1.3.2] [--flags F] [--region START:END] [--rounds N]

Coordinate descent over the order of declaration lines. Callee-saved register
assignment follows declaration (and definition) order, so a near-miss whose only
residue is a register permutation is often one or two line moves away.

The region is the block of lines between the line containing START and the line
containing END (exclusive; default: every run of two or more declaration-looking lines
right after a line that opens a block). Each round tries moving every line of the region to
every other position and swapping every pair (~1.5 n^2 variants, compiled in one batch) and keeps the move with
the fewest differing masked words; it stops when a round improves nothing.
Writes the best source to OUT and prints the score trail. Scratch only."""
import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from fzgx.project import Project  # noqa: E402
from fzgx import oracle  # noqa: E402

DECL = re.compile(r'^\s*(const\s+|volatile\s+|register\s+|static\s+|unsigned\s+|signed\s+|struct\s+|union\s+)*'
                  r'(?!return\b|goto\b|else\b|case\b|do\b)[A-Za-z_]\w*\b'
                  r'[\s\*]+\w+(\[[^\]]*\])*(\s*=[^;]*)?\s*(,\s*\**\w+(\[[^\]]*\])*)*\s*;\s*(/\*.*\*/)?\s*$')


def regions(lines, start, end):
    if start is not None:
        a = next(i for i, l in enumerate(lines) if start in l) + 1
        b = next(i for i in range(a, len(lines)) if end in lines[i])
        return [(a, b)]
    out, i = [], 0
    while i < len(lines):
        if lines[i].rstrip().endswith('{') and not lines[i].rstrip().endswith('\\{'):
            j = i + 1
            while j < len(lines) and DECL.match(lines[j]):
                j += 1
            if j - i - 1 >= 2:
                out.append((i + 1, j))
            i = j
        else:
            i += 1
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('sym'); ap.add_argument('file'); ap.add_argument('out')
    ap.add_argument('--mw', default=None); ap.add_argument('--flags', default=None)
    ap.add_argument('--region', default=None); ap.add_argument('--rounds', type=int, default=8)
    a = ap.parse_args()
    p = Project(); sym = p.resolve(a.sym)
    tgt = oracle.words(p.target_object_for(sym), sym.name)
    lines = Path(a.file).read_text().split('\n')
    st, en = (a.region.split(':', 1) if a.region else (None, None))
    regs = regions(lines, st, en)
    print('regions', [(x + 1, y) for x, y in regs])
    work = Path(a.out).with_suffix('.d'); work.mkdir(parents=True, exist_ok=True)

    def score_all(cands):
        files = []
        for k, c in enumerate(cands):
            f = work / f'c{k:05d}.c'; f.write_text('\n'.join(c)); files.append(f)
        objs = oracle.compile_many(p, sym.module, files, work / 'obj', mw_version=a.mw, extra_cflags=a.flags)
        res = []
        for f in files:
            w = oracle.words(objs[f], sym.name) if f in objs else None
            res.append(9999 if w is None else len(oracle.word_score(tgt, w)[1]) + abs(len(tgt) - len(w)))
        for f in files:
            f.unlink()
        return res

    best = score_all([lines])[0]
    print('start', best)
    for rnd in range(a.rounds):
        cands = []
        for (x, y) in regs:
            for i in range(x, y):
                for j in range(x, y):
                    if i == j:
                        continue
                    c = lines[:]
                    ln = c.pop(i); c.insert(j, ln)
                    cands.append(c)
                    if j > i:  # pairwise swap as well as a move
                        c = lines[:]
                        c[i], c[j] = c[j], c[i]
                        cands.append(c)
        if not cands:
            break
        sc = score_all(cands)
        k = min(range(len(sc)), key=lambda k: sc[k])
        if sc[k] >= best:
            break
        best, lines = sc[k], cands[k]
        print('round', rnd, best, flush=True)
        if best == 0:
            break
    Path(a.out).write_text('\n'.join(lines))
    print('best', best, '->', a.out)


if __name__ == '__main__':
    main()
