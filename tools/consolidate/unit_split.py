#!/usr/bin/env python3
"""Split one REL code unit in two at a function (for a TU boundary that falls inside a unit).

  unit_split.py rel/M/X/fn_A.c fn_B [--apply]

Both halves keep the unit's compiler, flags and TU file. Each half's `pool` map is derived from
relocations: the half is compiled, and every relocation of each function is paired by offset with the
same function's relocation in the old unit's linked (pool-fixed) object, which names the retail
target. Split ranges: the old .text range is cut at the function; a unit with other sections is
refused. Run from a GFZE01-configured, built tree; the link hash is the proof.
"""
import collections, copy, json, pathlib, re, shlex, subprocess, sys
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d
from fzgx import tufile
from fzgx.project import dump_units

OD = 'build/binutils/powerpc-eabi-objdump'
LOCAL = re.compile(r'^(@\d+|\.\.\.\w+\.0)$|__fzgx_offset_|^fzgx_')


def relocs(obj):
    """{function: [(offset in function, type, symbol, addend)]} of .text"""
    syms = {}
    for l in subprocess.run([OD, '-t', obj], capture_output=True, text=True).stdout.splitlines():
        m = re.match(r'([0-9a-f]+)\s+\S.*\s(\.text)\s+([0-9a-f]+)\s+(\S+)$', l)
        if m and int(m[3], 16): syms[m[4]] = (int(m[1], 16), int(m[3], 16))
    out = collections.defaultdict(list)
    for l in subprocess.run([OD, '-r', '-j', '.text', obj], capture_output=True, text=True).stdout.splitlines():
        m = re.match(r'([0-9a-f]+)\s+(\S+)\s+(\S+?)(?:([+-])0x([0-9a-f]+))?$', l)
        if not m: continue
        off = int(m[1], 16); add = int(m[5], 16) * (-1 if m[4] == '-' else 1) if m[5] else 0
        for f, (a, s) in syms.items():
            if a <= off < a + s: out[f].append((off - a, m[2], m[3], add)); break
    return out


def derive_pool(tf, names, mv, cf, old, work):
    c = work / 'half.c'; o = work / 'half.o'
    c.write_text(tufile.units_gen_text(tf, names))
    r = subprocess.run(['build/tools/wibo', f'build/compilers/{mv}/mwcceppc.exe'] + shlex.split(cf) + ['-c', str(c), '-o', str(o)], capture_output=True, text=True)
    if r.returncode: raise SystemExit(f'compile failed:\n{r.stdout[-1500:]}')
    new = relocs(str(o)); pool, bad = {}, []
    for f in names:
        a, b = sorted(new.get(f, [])), sorted(old.get(f, []))
        if [x[:2] for x in a] != [x[:2] for x in b]: bad.append((f, 'relocation layout differs')); continue
        for (off, _, s1, a1), (_, _, s2, a2) in zip(a, b):
            if s1 == s2 and a1 == a2: continue
            if not LOCAL.search(s1) or a2 - a1 < 0: bad.append((f, hex(off), s1, s2, a2 - a1)); continue
            tgt = s2 if a2 == a1 else f'{s2}+0x{a2 - a1:X}'
            if pool.setdefault(s1, tgt) != tgt: bad.append((f, s1, pool[s1], tgt))
    return pool, bad


def main():
    src, cut = sys.argv[1], sys.argv[2]
    U = json.loads(pathlib.Path('config/GFZE01/units.json').read_text())
    i = next(i for i, u in enumerate(U) if u['source'] == src)
    u = U[i]; k = u['symbols'].index(cut)
    if k == 0: raise SystemExit('cut is the first symbol')
    mod = u['module']
    mv, cf = d.ninja_units()[f'build/GFZE01/gen/{src}']
    tf = tufile.parse(pathlib.Path('src', u['tu']).read_text())
    old = relocs(f'build/GFZE01/src/{src[:-2]}.o')
    work = pathlib.Path('.fzgx/unit_split'); work.mkdir(parents=True, exist_ok=True)
    halves = [u['symbols'][:k], u['symbols'][k:]]
    pools = []
    for h in halves:
        p, bad = derive_pool(tf, h, mv, cf, old, work)
        if bad: raise SystemExit(f'{h[0]}: {bad[:8]}')
        pools.append(p)
    sp = pathlib.Path(f'config/GFZE01/{mod}/splits.txt'); st = sp.read_text()
    m = re.search(rf'^{re.escape(src)}:\n((?:\t.*\n)*)', st, re.M)
    rows = re.findall(r'\t(\.\w+)\s+start:0x(\w+) end:0x(\w+) align:(\d+)', m[1])
    if [r[0] for r in rows] != ['.text']: raise SystemExit(f'unit has sections {[r[0] for r in rows]}')
    addr = next(int(l.split(':0x')[1].split(';')[0], 16) for l in open(f'config/GFZE01/{mod}/symbols.txt') if l.startswith(f'{cut} = .text:'))
    new_src = src.rsplit('/', 1)[0] + f'/{cut}.c'
    print(f'{src}: {halves[0][0]}..{halves[0][-1]} ({len(pools[0])} pool) | {new_src}: {cut}.. ({len(pools[1])} pool)')
    if '--apply' not in sys.argv: return
    v = copy.deepcopy(u)
    for x, h, p in ((u, halves[0], pools[0]), (v, halves[1], pools[1])):
        x['symbols'] = h
        if p: x['pool'] = p
        else: x.pop('pool', None)
    v['source'] = new_src
    U.insert(i + 1, v)
    pathlib.Path('config/GFZE01/units.json').write_text(dump_units(U))
    _, a, b, al = rows[0]
    st = st[:m.start(1)] + f'\t.text       start:0x{a} end:0x{addr:08X} align:{al}\n' + st[m.end(1):]
    st = st.replace(f'{src}:\n\t.text       start:0x{a} end:0x{addr:08X} align:{al}\n',
                    f'{src}:\n\t.text       start:0x{a} end:0x{addr:08X} align:{al}\n\n{new_src}:\n\t.text       start:0x{addr:08X} end:0x{b} align:{al}\n', 1)
    sp.write_text(st)


if __name__ == '__main__':
    main()
