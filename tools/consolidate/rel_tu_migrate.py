#!/usr/bin/env python3
"""Turn the standalone units of mapped REL TUs into one block-format TU file per TU.

  rel_tu_migrate.py MODULE [--apply] [TU_FILE...]

For modules whose units are standalone files (movie_module): every unit of a tus.json TU becomes
blocks of src/rel/MODULE/<tu>.c, one block per function it defines, each flagged `noprologue`
and holding the unit's text from the previous function to its own (the first block also has the
unit's includes and declarations). A unit of several blocks compiles them joined, so every
generated unit is its old source: no object changes. The unit keeps its symbols, compiler and
pool; its source becomes rel/MODULE/<tu stem>/<first symbol>.c (splits.txt and the ledger
follow). `fzgx tutruth rel/MODULE/<tu>.c` can then put the blocks under one prologue.
`fzgx tu-migrate` only moves single-function units; this keeps multi-function ones whole.

TUs with an asm unit, a unit that crosses the TU, or a unit already in a TU file are skipped.
Afterwards configure and run gate.sh.
"""
import json, pathlib, re, sys
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import tu_cut
from fzgx import tufile
from fzgx.project import dump_units


def blocks_of(text, symbols):
    """Blocks (name, body) of a unit source, split before each listed symbol's definition."""
    defs = {name: (start, end) for name, start, end, _ in tu_cut.definitions(text)}
    missing = [s for s in symbols if s not in defs]
    if missing:
        raise ValueError(f'no definition of {missing}')
    order = sorted(symbols, key=lambda s: defs[s][0])
    if order != list(symbols):
        raise ValueError('definitions are not in address order')
    out, pos = [], 0
    for k, s in enumerate(order):
        end = defs[s][1] if k + 1 < len(order) else len(text)
        # a block runs to the end of its function's line; the next block starts on the next line
        if k + 1 < len(order):
            nl = text.find('\n', end)
            end = len(text) if nl < 0 else nl + 1
        out.append((s, text[pos:end]))
        pos = end
    return out


def main():
    args = sys.argv[1:]
    module, apply, partial = args[0], '--apply' in args, '--partial' in args
    only = {a for a in args[1:] if not a.startswith('--')}
    cfg = pathlib.Path(f'config/GFZE01/{module}')
    tus = json.loads((cfg / 'tus.json').read_text())
    tu_of = {f: t['file'] for t in tus['tus'] for f in t['functions']}
    addr = {}
    for line in open(cfg / 'symbols.txt'):
        m = re.match(r'(\S+) = \.text:0x(\w+); // type:function', line)
        if m:
            addr[m[1]] = int(m[2], 16)
    upath = pathlib.Path('config/GFZE01/units.json')
    units = json.loads(upath.read_text())
    mine = [u for u in units if u['module'] == module and not u.get('data')]
    by_tu = {}
    for u in mine:
        t = {tu_of.get(s, '_prolog.c') for s in u['symbols']}
        by_tu.setdefault(t.pop() if len(t) == 1 else None, []).append(u)
    ren, done = {}, []
    for t in tus['tus']:
        name = t['file']
        if only and name not in only:
            continue
        us = sorted(by_tu.get(name, []), key=lambda u: min(addr[s] for s in u['symbols']))
        if len(us) < 2:
            continue   # one unit already: nothing to reconcile
        crossing = [u['source'] for u in by_tu.get(None, []) if any(tu_of.get(s) == name for s in u['symbols'])]
        if partial:
            if any(u.get('tu') for u in us):
                print('skip', name, 'already migrated'); continue
            us = [u for u in us if not u.get('asm')]
            if len(us) < 2:
                continue
        elif crossing or any(u.get('asm') or u.get('tu') for u in us):
            print('skip', name, 'crossing/asm/already migrated'); continue
        stem = name[:-2]
        tu_src = f'rel/{module}/{name}'
        if pathlib.Path('src', tu_src).exists() and tu_src not in [u['source'] for u in us]:
            print('skip', name, 'TU file exists'); continue
        blocks, ok = [], True
        for u in us:
            try:
                bs = blocks_of(pathlib.Path('src', u['source']).read_text(), sorted(u['symbols'], key=lambda s: addr[s]))
            except ValueError as e:
                print('skip', name, u['source'], e); ok = False; break
            blocks += [tufile.Block(s, body if body.endswith('\n') else body + '\n', ['noprologue']) for s, body in bs]
        if not ok:
            continue
        includes = []
        for b in blocks:
            for ln in b.body.splitlines():
                if ln.strip().startswith('#include') and ln.strip() not in includes:
                    includes.append(ln.strip())
        tf = tufile.TuFile('\n'.join(includes) + '\n', blocks)
        # every unit's generated text must be its old source, up to blank lines
        norm = lambda s: re.sub(r'\n\s*\n', '\n', s).strip()
        for u in us:
            gen = tufile.units_gen_text(tf, sorted(u['symbols'], key=lambda s: addr[s]))
            if norm(gen) != norm(pathlib.Path('src', u['source']).read_text()):
                print('skip', name, u['source'], 'generated text differs'); ok = False; break
        if not ok:
            continue
        print(f'OK  {name}: {len(us)} units, {len(blocks)} blocks')
        if not apply:
            continue
        for u in us:
            old = u['source']
            pathlib.Path('src', old).unlink()
            u['source'] = f'rel/{module}/{stem}/{u["symbols"][0]}.c'
            u['tu'] = tu_src
            ren[old] = u['source']
        pathlib.Path('src', tu_src).write_text(tf.render())
        done.append(name)
    if not apply or not ren:
        return
    upath.write_text(dump_units(units))
    sp = cfg / 'splits.txt'
    st = sp.read_text()
    for a, b in ren.items():
        assert f'{a}:\n' in st, a
        st = st.replace(f'{a}:\n', f'{b}:\n', 1)
    sp.write_text(st)
    lp = pathlib.Path('state/ledger.json')
    lt = lp.read_text()
    for a, b in ren.items():
        lt = lt.replace(f'"{a}"', f'"{b}"')
    lp.write_text(lt)
    print('migrated', len(done), 'TUs,', len(ren), 'units')


if __name__ == '__main__':
    main()
