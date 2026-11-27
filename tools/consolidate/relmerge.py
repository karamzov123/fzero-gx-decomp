"""Merge every unit of a block-format REL TU file into one unit.

  relmerge.py rel/MODULE/TU.c [--apply]

The whole file is compiled under each compiler and flag set its units use. A set is accepted
when every function's instruction words equal those of its old unit's linked (pool-fixed)
object outside relocated words and branches, and its relocations pair up with the old ones by
offset and type. The merged unit's pool map comes from that pairing: a private literal (@N,
section symbols, layout names) takes the retail target the old object's relocation names.
Then units.json and splits.txt. The link hash is the proof: configure, ninja, gate.sh.
"""
import sys, json, subprocess, pathlib, shlex, re, collections
sys.path.insert(0, 'tools/consolidate'); sys.path.insert(0, 'tools')
import devprobe as d, objsig
from fzgx import tufile
from fzgx.project import dump_units

OD = 'build/binutils/powerpc-eabi-objdump'
W = pathlib.Path('.fzgx/tu_collapse/tmp'); W.mkdir(parents=True, exist_ok=True)


def relocs(obj):
    """{function: [(offset_in_fn, type, symbol, addend)]} for .text"""
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


def code(obj):
    """{function: bytes} for .text"""
    sg = objsig.sig(pathlib.Path(obj))
    t = sg['sections'].get('.text', b'')
    return {n: t[v:v + sz] for n, s, v, sz, _ in sg['defs'] if s == '.text' and sz}


def attempt(us, names, tf, mv, cf):
    c, o = W / 'm.c', W / 'm.o'
    c.write_text(tufile.units_gen_text(tf, names))
    r = subprocess.run(['build/tools/wibo', f'build/compilers/{mv}/mwcceppc.exe'] + shlex.split(cf) + ['-c', str(c), '-o', str(o)],
                       capture_output=True, text=True)
    if r.returncode:
        return None, ['does not compile: ' + r.stdout[-300:]]
    new, newc = relocs(str(o)), code(str(o))
    pool, bad = {}, []
    for u in us:
        oldo = f'build/GFZE01/src/{u["source"][:-2]}.o'
        old, oldc = relocs(oldo), code(oldo)
        for f in u['symbols']:
            a, b = sorted(new.get(f, [])), sorted(old.get(f, []))
            if [x[:2] for x in a] != [x[:2] for x in b]: bad.append((f, 'reloc layout differs')); continue
            x, y = newc.get(f, b''), oldc.get(f, b'')
            masked = {off & ~3 for off, *_ in a}
            words = [i for i in range(0, len(y), 4) if i not in masked and x[i:i + 4] != y[i:i + 4]
                     and not (x[i:i + 1] and x[i] >> 2 == 18 and y[i] >> 2 == 18)]
            if len(x) != len(y) or words: bad.append((f, f'{len(words)} words differ')); continue
            for (off, t, s1, a1), (_, _, s2, a2) in zip(a, b):
                if s1 == s2 and a1 == a2: continue
                if not (s1.startswith('@') or s1.startswith('...') or '__fzgx_offset_' in s1 or s1.startswith('fzgx_')): bad.append((f, off, s1, s2)); continue
                delta = a2 - a1
                tgt = s2 if delta == 0 else f'{s2}+0x{delta:X}' if delta > 0 else None
                if tgt is None: bad.append((f, off, s1, s2, delta)); continue
                if pool.setdefault(s1, tgt) != tgt: bad.append((f, s1, pool[s1], tgt))
    return pool, bad


def main():
    tu = sys.argv[1]; mod = tu.split('/')[1]
    U = json.load(open('config/GFZE01/units.json'))
    us = [u for u in U if u.get('tu') == tu and not u.get('data')]
    nu = d.ninja_units()
    tf = tufile.parse(pathlib.Path('src', tu).read_text())
    names = [b.name for b in tf.blocks]
    if len(us) < 2:
        sys.exit(f'{tu}: fewer than two units')
    choices, pool, bad, model = [], {}, ['no compiler'], us[0]
    for u in us:
        k = nu[f'build/GFZE01/gen/{u["source"]}']
        if k not in [c[0] for c in choices]: choices.append((k, u))
    for (mv, cf), model in choices:
        pool, bad = attempt(us, names, tf, mv, cf)
        print(f'{model.get("mw_version") or "default"} {" ".join(model.get("extra_cflags") or [])}: '
              f'{len(pool or {})} pool entries; {len(bad)} problems'); [print('  ', b) for b in bad[:8]]
        if not bad:
            break
    if bad:
        sys.exit(1)
    if '--apply' not in sys.argv:
        return
    first = us[0]; first['symbols'] = names; first['pool'] = pool
    first['mw_version'] = model.get('mw_version'); first['extra_cflags'] = list(model.get('extra_cflags') or [])
    first.pop('own', None)
    if not pool: first.pop('pool')
    for u in us[1:]: U.remove(u)
    pathlib.Path('config/GFZE01/units.json').write_text(dump_units(U))
    sp = pathlib.Path(f'config/GFZE01/{mod}/splits.txt'); st = sp.read_text(); secs = collections.defaultdict(list)
    for u in us:
        m = re.search(rf'^{re.escape(u["source"])}:\n((?:\t.*\n)*)\n?', st, re.M)
        for s, a, b, al in re.findall(r'\t(\.\w+)\s+start:0x(\w+) end:0x(\w+) align:(\d+)', m[1]): secs[s].append((int(a, 16), int(b, 16), al))
        if u is not first: st = st.replace(m[0], '')
    for s, rr in secs.items():
        rr.sort(); assert all(x[1] == y[0] for x, y in zip(rr, rr[1:])), (s, rr)
    body = ''.join(f'\t{s:<11} start:0x{rr[0][0]:08X} end:0x{rr[-1][1]:08X} align:{rr[0][2]}\n' for s, rr in secs.items())
    m = re.search(rf'^{re.escape(first["source"])}:\n((?:\t.*\n)*)', st, re.M)
    st = st[:m.start(1)] + body + st[m.end(1):]
    sp.write_text(st); print('merged', len(us), 'units')


if __name__ == '__main__':
    main()
