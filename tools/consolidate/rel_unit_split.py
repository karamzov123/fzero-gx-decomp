#!/usr/bin/env python3
"""Split the multi-function units of a block-format REL TU file into one unit per function.

  rel_unit_split.py rel/MODULE/TU.c [--apply]

fzgx tutruth verifies blocks one at a time, each under the TU prologue; a later block of a unit
that holds several functions relies on the declarations of the unit's first block, so tutruth
cannot adapt it. This gives every function its own self-contained block: the unit's text with
the other definitions cut to prototypes (tu_cut.py) and the declarations it no longer names
dropped (decl_prune.py). Each piece must compile to its function's instruction words and
relocations in the old unit's linked object (outside relocated words and branches); its pool
map comes from pairing the relocations, as in relmerge.py. Only .text-only units are split.
Afterwards configure and run gate.sh: the link hash is the proof.
"""
import json, pathlib, re, shlex, subprocess, sys
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, decl_prune, relmerge, tu_cut
from fzgx import tufile
from fzgx.project import dump_units

W = pathlib.Path('.fzgx/tu_collapse/tmp'); W.mkdir(parents=True, exist_ok=True)
PRIVATE = re.compile(r'^(@|\.\.\.|fzgx_)|__fzgx_offset_')


def cut(text, keep):
    out, last = [], 0
    for name, start, end, header in tu_cut.definitions(text):
        out.append(text[last:start])
        inline = re.match(r'static\s+inline\b|inline\b', header.lstrip())
        out.append(text[start:end] if name == keep or inline else ' '.join(header.split()) + ';')
        last = end
    out.append(text[last:])
    return ''.join(out)


def check(piece, sym, old_obj, mv, cf):
    """(pool, problem) for a piece against the old object's function `sym`."""
    c, o = W / 'piece.c', W / 'piece.o'
    c.write_text(piece)
    o.unlink(missing_ok=True)
    r = subprocess.run(['build/tools/wibo', f'build/compilers/{mv}/mwcceppc.exe'] + shlex.split(cf) + ['-c', str(c), '-o', str(o)],
                       capture_output=True, text=True)
    if r.returncode:
        return None, 'does not compile'
    new, old = relmerge.relocs(str(o)), relmerge.relocs(old_obj)
    x, y = relmerge.code(str(o)).get(sym, b''), relmerge.code(old_obj).get(sym, b'')
    a, b = sorted(new.get(sym, [])), sorted(old.get(sym, []))
    if [r_[:2] for r_ in a] != [r_[:2] for r_ in b]:
        return None, 'relocation layout differs'
    masked = {off & ~3 for off, *_ in a}
    words = [i for i in range(0, len(y), 4) if i not in masked and x[i:i + 4] != y[i:i + 4]
             and not (x[i:i + 1] and x[i] >> 2 == 18 and y[i] >> 2 == 18)]
    if not y or len(x) != len(y) or words:
        return None, f'{len(words)} words differ'
    pool = {}
    for (off, t, s1, a1), (_, _, s2, a2) in zip(a, b):
        if s1 == s2 and a1 == a2:
            continue
        if not PRIVATE.search(s1):
            return None, f'relocation to {s1} where the old object has {s2}'
        delta = a2 - a1
        if delta < 0:
            return None, f'{s1}: negative addend'
        tgt = s2 if delta == 0 else f'{s2}+0x{delta:X}'
        if pool.setdefault(s1, tgt) != tgt:
            return None, f'{s1} binds two targets'
    return pool, None


def main():
    tu = sys.argv[1]; mod = tu.split('/')[1]; apply = '--apply' in sys.argv
    cfg = pathlib.Path(f'config/GFZE01/{mod}')
    addr = {}
    for line in open(cfg / 'symbols.txt'):
        m = re.match(r'(\S+) = \.text:0x(\w+); // type:function', line)
        if m:
            addr[m[1]] = int(m[2], 16)
    U = json.load(open('config/GFZE01/units.json'))
    us = [u for u in U if u.get('tu') == tu and not u.get('data') and len(u['symbols']) > 1]
    tf = tufile.parse(pathlib.Path('src', tu).read_text())
    sp = cfg / 'splits.txt'; st = sp.read_text()
    nu = d.ninja_units()
    stem = pathlib.Path(tu).stem
    repl = {}
    for u in us:
        m = re.search(rf'^{re.escape(u["source"])}:\n((?:\t.*\n)*)', st, re.M)
        lines = re.findall(r'\t(\.\w+)\s+start:0x(\w+) end:0x(\w+)', m[1]) if m else []
        if [l[0] for l in lines] != ['.text']:
            print('skip', u['source'], 'not .text-only'); continue
        hi_text = int(lines[0][2], 16)
        mv, cf = nu[f'build/GFZE01/gen/{u["source"]}']
        text = tufile.units_gen_text(tf, u['symbols'])
        syms = sorted(u['symbols'], key=lambda s: addr[s])
        old_obj = f'build/GFZE01/src/{u["source"][:-2]}.o'
        pieces, ok = [], True
        for k, s in enumerate(syms):
            piece, _ = decl_prune.prune(cut(text, s))
            pool, why = check(piece, s, old_obj, mv, cf)
            if why:
                print('no ', u['source'], s, why); ok = False; break
            hi = addr[syms[k + 1]] if k + 1 < len(syms) else hi_text
            nu_ = {key: v for key, v in u.items() if key not in ('symbols', 'source', 'pool')}
            nu_.update(source=f'rel/{mod}/{stem}/{s}.c', symbols=[s])
            if pool:
                nu_['pool'] = pool
            pieces.append((s, piece, nu_, addr[s], hi))
        if not ok:
            continue
        print(f'OK  {u["source"]}: {len(pieces)} units')
        repl[u['source']] = pieces
    if not apply or not repl:
        return
    out = []
    for u in U:
        if u['source'] in repl:
            out += [p[2] for p in repl[u['source']]]
        else:
            out.append(u)
    for src, pieces in repl.items():
        for s, piece, _, _, _ in pieces:
            b = tf.get(s); b.body = piece if piece.endswith('\n') else piece + '\n'; b.flags = ['noprologue']
        m = re.search(rf'^{re.escape(src)}:\n((?:\t.*\n)*)\n?', st, re.M)
        al = re.search(r'align:(\d+)', m[1])
        al = f' align:{al[1]}' if al else ''
        st = st.replace(m[0], ''.join(f'{p[2]["source"]}:\n\t.text       start:0x{p[3]:08X} end:0x{p[4]:08X}{al}\n\n'
                                      for p in pieces), 1)
    pathlib.Path('src', tu).write_text(tf.render())
    pathlib.Path('config/GFZE01/units.json').write_text(dump_units(out))
    sp.write_text(st)
    print('split', len(repl), 'units into', sum(len(p) for p in repl.values()))


if __name__ == '__main__':
    main()
