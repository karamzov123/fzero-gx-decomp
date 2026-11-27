"""Merge every unit of a block-format REL TU file into one unit.

  relmerge.py rel/MODULE/TU.c [--keep SYM,...] [--apply]

Regions: when the committed units disagree on matching_for, the merged unit is USA-only and every
committed unit that also matched Japan or PAL is kept for those regions in regional_fragments.json
(its committed blocks in <tu>_regional.c). Commit before merging: git HEAD is the regional source.

--keep leaves the units holding those functions as they are and merges the others (they must be
contiguous): a function that only matches under another compiler stays its own unit. When the
best flag set fails only in edge units, the output names the --keep that would merge the rest.

The whole file is compiled under each compiler and flag set its units use (each also with
`-inline on,noauto` added). A set is accepted
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
    keep = set(sys.argv[sys.argv.index('--keep') + 1].split(',')) if '--keep' in sys.argv else set()
    allus = [u for u in U if u.get('tu') == tu and not u.get('data')]
    us = [u for u in allus if not keep & set(u['symbols'])]
    nu = d.ninja_units()
    tf = tufile.parse(pathlib.Path('src', tu).read_text())
    own = {s for u in us for s in u['symbols']}
    names = [b.name for b in tf.blocks if b.name in own]
    if len(us) < 2:
        sys.exit(f'{tu}: fewer than two units')
    choices, pool, bad, model = [], {}, ['no compiler'], us[0]
    for u in us:
        k = nu[f'build/GFZE01/gen/{u["source"]}']
        if k not in [c[0] for c in choices]: choices.append((k, u))
    # a TU-wide -inline on,noauto: merged, MWCC would inline same-file callees that retail calls
    # (CRI's middleware builds some TUs this way; see the DOL ADX units)
    for (mv, cf), u in list(choices):
        if '-inline' not in (u.get('extra_cflags') or []):
            choices.append(((mv, cf + ' -inline on,noauto'),
                            dict(u, extra_cflags=list(u.get('extra_cflags') or []) + ['-inline', 'on,noauto'])))
    best = None
    for (mv, cf), model in choices:
        pool, bad = attempt(us, names, tf, mv, cf)
        if best is None or len(bad) < len(best):
            best = bad
        print(f'{model.get("mw_version") or "default"} {" ".join(model.get("extra_cflags") or [])}: '
              f'{len(pool or {})} pool entries; {len(bad)} problems'); [print('  ', b) for b in bad[:8]]
        if not bad:
            break
    if bad:
        # the best set's failing functions: if their units are at the edges, --keep them
        if any(not isinstance(b, tuple) for b in best):
            sys.exit(1)   # the merged text does not compile: no unit to keep aside
        fails = {b[0] for b in best}
        order = [b.name for b in tf.blocks if b.name in own]
        unit_of = {s: u['source'] for u in us for s in u['symbols']}
        bad_units = {unit_of[f] for f in fails if f in unit_of}
        seq = [unit_of[n] for n in order]
        seq = [s for k, s in enumerate(seq) if not k or seq[k - 1] != s]
        rest = [s for s in seq if s not in bad_units]
        if len(rest) >= 2 and rest in (seq[len(seq) - len(rest):], seq[:len(rest)]):
            print('try --keep', ','.join(sorted(f for f in fails)))
        sys.exit(1)
    if '--apply' not in sys.argv:
        return
    # splits first: nothing is written unless every section's ranges are contiguous
    sp = pathlib.Path(f'config/GFZE01/{mod}/splits.txt'); st = sp.read_text(); secs = collections.defaultdict(list)
    first = us[0]
    for u in us:
        m = re.search(rf'^{re.escape(u["source"])}:\n((?:\t.*\n)*)\n?', st, re.M)
        if not m:
            sys.exit(f'no split for {u["source"]}')
        for s, a, b, al in re.findall(r'\t(\.\w+)\s+start:0x(\w+) end:0x(\w+)(?: align:(\d+))?', m[1]):
            secs[s].append((int(a, 16), int(b, 16), al))
        if u is not first: st = st.replace(m[0], '')
    for s, rr in secs.items():
        rr.sort()
        if not all(x[1] == y[0] for x, y in zip(rr, rr[1:])):
            sys.exit(f'{s} ranges are not contiguous: ' + ', '.join(f'{a:X}..{b:X}' for a, b, _ in rr))
    body = ''.join(f'\t{s:<11} start:0x{rr[0][0]:08X} end:0x{rr[-1][1]:08X}'
                   + (f' align:{max(int(r[2]) for r in rr if r[2])}' if any(r[2] for r in rr) else '') + '\n'
                   for s, rr in secs.items())
    m = re.search(rf'^{re.escape(first["source"])}:\n((?:\t.*\n)*)', st, re.M)
    st = st[:m.start(1)] + body + st[m.end(1):]
    regions, fragments, regional_text = regional(tu, own, keep)
    first['symbols'] = names; first['pool'] = pool
    first['mw_version'] = model.get('mw_version'); first['extra_cflags'] = list(model.get('extra_cflags') or [])
    first.pop('own', None); first.pop('pool_for', None)
    if regions == list(VERSIONS): first.pop('matching_for', None)
    else: first['matching_for'] = regions
    if not pool: first.pop('pool')
    for u in us[1:]: U.remove(u)
    pathlib.Path('config/GFZE01/units.json').write_text(dump_units(U))
    sp.write_text(st)
    if fragments:
        fp = pathlib.Path('config/GFZE01/regional_fragments.json')
        fp.write_text(json.dumps(json.loads(fp.read_text()) + fragments, indent=2) + '\n')
        rp = pathlib.Path('src', fragments[0]['tu'])
        rp.write_text(regional_text)
    print('merged', len(us), 'units' + (f'; {len(fragments)} retained for {sorted({v for f in fragments for v in f["matching_for"]})} in {fragments[0]["tu"]}' if fragments else ''))


VERSIONS = ('GFZE01', 'GFZJ01', 'GFZP01')


def git_show(path):
    return subprocess.run(['git', 'show', f'HEAD:{path}'], capture_output=True, text=True, check=True).stdout


def regional(tu, own, keep):
    """(merged unit's regions, regional fragments, regional TU text) from the committed units.

    The merge is verified for USA only. When the committed units of the merged functions all build
    for the same regions, the merged unit keeps them (the gate checks every region). Otherwise it is
    USA-only and every committed unit that also matched Japan or PAL is retained for those regions
    as a regional fragment: its committed blocks in <tu>_regional.c, its committed split."""
    mod = tu.split('/')[1]
    head = [u for u in json.loads(git_show('config/GFZE01/units.json')) if u.get('tu') == tu and not u.get('data')
            and set(u['symbols']) & own]
    if any(keep & set(u['symbols']) for u in head):
        sys.exit('a kept function shares a committed unit with merged ones: commit the split first')
    sets = {tuple(v for v in VERSIONS if v in (u.get('matching_for') or VERSIONS)) for u in head}
    if len(sets) == 1:
        return list(sets.pop()), [], ''
    rtu = tu[:-2] + '_regional.c'
    if pathlib.Path('src', rtu).exists():
        sys.exit(f'{rtu} exists: retain these fragments by hand')
    htf = tufile.parse(git_show(f'src/{tu}'))
    hsplits = git_show(f'config/GFZE01/{mod}/splits.txt')
    frags, names = [], []
    for u in head:
        extra = [v for v in VERSIONS[1:] if v in (u.get('matching_for') or VERSIONS)]
        if not extra:
            continue
        m = re.search(rf'^{re.escape(u["source"])}:\n((?:\t.*\n)*)', hsplits, re.M)
        f = {k: v for k, v in u.items() if k not in ('matching_for', 'tu')}
        f.update(tu=rtu, matching_for=extra, regional_split=[l for l in m[1].splitlines() if l.strip()])
        if isinstance(u.get('pool_for'), dict):
            f['pool_for'] = {k: v for k, v in u['pool_for'].items() if k in extra}
        frags.append(f); names += u['symbols']
    rtf = tufile.TuFile(f'/* Previously matched Japan/PAL units of {pathlib.Path(tu).name}, retained until that TU '
                        f'matches those releases as one unit. */\n' + htf.prologue,
                        [b for b in htf.blocks if b.name in names])
    return ['GFZE01'], frags, rtf.render()

if __name__ == '__main__':
    main()
