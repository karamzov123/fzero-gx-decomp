"""typesweep.py SYMBOL FILE OUTDIR [MW] [ROUNDS]: greedy hill-climb over integer TYPES.

Every integer type token in FILE (u8/s8/u16/s16/u32/s32/int/char/short/long ...) that sits in a
declaration context -- a local or file-scope declaration, a function parameter, an extern
prototype's return or parameter type, a struct member -- is a site. One round compiles every
single-site replacement by every other width/signedness and keeps the best (fewest differing
masked words, objdiff rows as tie-break); rounds repeat from the improved source until nothing
improves. Register colouring and scheduling of MWCC respond to these types (an s16 parameter
closed fn_80069CE4, a u16 return moved a callee-saved web in fn_10_1544), which declaration
order never reaches.

Writes OUTDIR/best.c and prints each accepted change. Words are positional, so the body
should already have the retail instruction count.
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from fzgx.project import Project  # noqa: E402
from fzgx import oracle  # noqa: E402

TYPES = ['u8', 's8', 'u16', 's16', 'u32', 's32']
TOKEN = re.compile(r'\b(u8|s8|u16|s16|u32|s32|int|unsigned int|short|unsigned short|char|unsigned char)\b')


def sites(text):
    """(start, end, token) for type tokens in declaration-like positions."""
    out = []
    for m in TOKEN.finditer(text):
        a, b = m.span()
        line_start = text.rfind('\n', 0, a) + 1
        line_end = text.find('\n', b)
        line = text[line_start:line_end]
        before = text[line_start:a]
        after = text[b:line_end]
        if line.lstrip().startswith(('#', '//', '/*')) or 'typedef' in line:
            continue
        # declarations: "    T name;" / "T name = ..." / params "(T name," / extern protos / casts excluded
        prev = before.rstrip()[-1:] if before.strip() else ''
        if prev in ('(', ',') or before.strip() in ('', 'extern', 'static', 'const', 'volatile',
                                                   'extern const', 'static inline', 'static const'):
            nxt = after.lstrip()[:1]
            if nxt and (nxt.isalpha() or nxt in '_*'):
                # skip casts: "(T)" or "(T *)" followed by ')'
                tail = after.lstrip()
                if prev == '(' and re.match(r'\*?\s*\)', tail):
                    continue
                out.append((a, b, m.group(1)))
    return out


def score(p, sym, tgt, files, mw):
    objs = oracle.compile_many(p, sym.module, files, files[0].parent / 'obj', mw_version=mw)
    res = {}
    for f in files:
        o = objs.get(f)
        w = oracle.words(o, sym.name) if o else None
        res[f] = 10**6 if w is None else len(oracle.word_score(tgt, w)[1]) + 4 * abs(len(tgt) - len(w))
    return res


def main():
    sym_name, src, out = sys.argv[1], Path(sys.argv[2]), Path(sys.argv[3])
    mw = sys.argv[4] if len(sys.argv) > 4 and sys.argv[4] else None
    rounds = int(sys.argv[5]) if len(sys.argv) > 5 else 6
    p = Project()
    sym = p.resolve(sym_name)
    tgt = oracle.words(p.target_object_for(sym), sym.name)
    out.mkdir(parents=True, exist_ok=True)
    text = src.read_text()
    base_f = out / 'base.c'
    base_f.write_text(text)
    best = score(p, sym, tgt, [base_f], mw)[base_f]
    print('start', best)
    for r in range(rounds):
        cands = []
        for k, (a, b, tok) in enumerate(sites(text)):
            for t in TYPES:
                if t == tok:
                    continue
                f = out / f'r{r}_{k}_{t}.c'
                f.write_text(text[:a] + t + text[b:])
                cands.append((f, k, a, b, tok, t))
        if not cands:
            break
        res = score(p, sym, tgt, [c[0] for c in cands], mw)
        cands.sort(key=lambda c: res[c[0]])
        f, k, a, b, tok, t = cands[0]
        if res[f] >= best:
            print(f'round {r}: no improvement (best single {res[f]})')
            break
        line = text[text.rfind(chr(10), 0, a) + 1:text.find(chr(10), b)].strip()
        print(f'round {r}: {best} -> {res[f]}  {tok} -> {t}  in: {line}')
        best = res[f]
        text = f.read_text()
        for c in cands:
            if c[0].exists():
                c[0].unlink()
    (out / 'best.c').write_text(text)
    print('best', best, out / 'best.c')


if __name__ == '__main__':
    main()
