#!/usr/bin/env python3
"""Try a hand-written translation unit against the units it replaces (DOL).

  tu_try.py CANDIDATE.c --units dol/A.c,dol/B.c,...  [--extra "-inline on,noauto"]
            [--apply --as dol/os/OSAlarm.c]

Compiles CANDIDATE.c with the first unit's compiler and flags (every region in the units'
common matching_for) and each unit's current source with its own settings, then requires every
function to have identical instruction bytes and relocations (branches between the TU's own
functions excepted). Relocations to compiler-private literals (@N) are compared through the
units' pool maps; the candidate's own map is derived from the matching relocation sites and
every @N it references must resolve. Other sections must keep their sizes (a section that only
holds remapped literals is exempt: poolfix empties it).
--apply writes the candidate to --as, deletes the replaced sources, merges their split ranges
section by section (each must be contiguous) and replaces their units.json entries with one.
"""
import json, re, sys, tempfile, pathlib, argparse, collections
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, objsig

VERSIONS = ('GFZE01', 'GFZJ01', 'GFZP01')
LOCAL = re.compile(r'^@\d+$')


def target(t):
    m = re.match(r'^(.*?)(?:\+0x([0-9A-Fa-f]+))?$', t)
    return m.group(1), int(m.group(2), 16) if m.group(2) else 0


def funcs(obj, td, tag, pool=None):
    """function -> (bytes, relocs); relocs to @N go through `pool` when given."""
    p = pathlib.Path(td) / f'{tag}.o'; p.write_bytes(obj); sg = objsig.sig(p)
    t = sg['sections'].get('.text', b'')
    fn = {n: (v, sz) for n, s, v, sz, _ in sg['defs'] if s == '.text' and sz}
    rel = collections.defaultdict(list)
    # section-relative references (`...bss.0 + n`) name the symbol defined at that offset
    sec_of = {n: (s, v) for n, s, v, sz, b in sg['defs']}
    named = {(s, v): n for n, s, v, sz, b in sg['defs'] if n and not n.startswith('.') and not LOCAL.match(n) and b != 0 or (n and not n.startswith('.') and not LOCAL.match(n))}
    for off, typ, nm, add in sg['relocs'].get('.text', []):
        if pool is not None and LOCAL.match(nm) and nm in pool:
            nm, extra = target(pool[nm]); add += extra
        elif nm.startswith('.') and nm in sec_of:
            s, v = sec_of[nm]
            if (s, v + add) in named:
                nm, add = named[(s, v + add)], 0
        for f, (v, sz) in fn.items():
            if v <= off < v + sz:
                # MWCC places an SDA21 relocation at +0 or +2 of the instruction: the same field
                rel[f].append(((off - v) & ~3 if typ == 109 else off - v, typ, nm, add))
    secs = {k: (len(v) if isinstance(v, bytes) else v) for k, v in sg['sections'].items() if k != '.comment'}
    local_secs = collections.defaultdict(set)
    for n, s, v, sz, _ in sg['defs']:
        if LOCAL.match(n):
            local_secs[s].add(n)
    return {f: (t[v:v + sz], sorted(rel[f])) for f, (v, sz) in fn.items()}, secs, sg, local_secs


def derive_pool(cand_sg, cand_fn_addr, ref):
    """Map each @N the candidate references to the retail target the ref has at the same site."""
    out, bad = {}, []
    for off, typ, nm, add in cand_sg['relocs'].get('.text', []):
        if not LOCAL.match(nm):
            continue
        f = next((f for f, (v, sz) in cand_fn_addr.items() if v <= off < v + sz), None)
        site = None if f is None or f not in ref else next(
            (r for r in ref[f][1] if r[0] == off - cand_fn_addr[f][0] and r[1] == typ), None)
        if site is None or LOCAL.match(site[2]):
            bad.append(nm); continue
        delta = site[3] - add
        tgt = site[2] if delta == 0 else (f'{site[2]}+0x{delta:X}' if delta > 0 else None)
        if tgt is None or out.get(nm, tgt) != tgt:
            bad.append(nm); continue
        out[nm] = tgt
    return out, bad


def split_blocks(text):
    return {m.group(1): m.group(2) for m in re.finditer(r'^(\S+\.c):\n((?:\t.*\n)*)', text, re.M)}


def parse_block(body):
    return [(m.group(1), int(m.group(2), 16), int(m.group(3), 16), m.group(4))
            for m in re.finditer(r'\t(\.\w+)\s+start:0x([0-9A-Fa-f]+) end:0x([0-9A-Fa-f]+)(?: align:(\d+))?', body)]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('candidate'); ap.add_argument('--units', required=True)
    ap.add_argument('--apply', action='store_true'); ap.add_argument('--as', dest='dest')
    ap.add_argument('--extra', default='', help='extra compiler flags for the TU, e.g. "-inline on,noauto"')
    a = ap.parse_args()
    srcs = a.units.split(',')
    units = json.load(open('config/GFZE01/units.json')); byu = {u['source']: u for u in units}
    us = [byu[s] for s in srcs]
    nu = d.ninja_units()
    mf = [v for v in VERSIONS if all(v in (u.get('matching_for') or VERSIONS) for u in us)]
    lead = dict(us[0], matching_for=mf)
    mv, cf = nu['src/' + srcs[0]]
    if a.extra:
        cf = cf + ' ' + a.extra
    own = set(s for u in us for s in u['symbols'])
    pooled = any(u.get('pool') for u in us)
    cand = pathlib.Path(a.candidate).read_text()
    ok, new_pool = True, None
    with tempfile.TemporaryDirectory() as td:
        new = d.compile_all(cand, mv, cf, td, lead)
        if None in new:
            print('candidate does not compile'); return 1
        for vi, obj in enumerate(new):
            ref, rsecs = {}, collections.Counter()
            for u in us:
                o = d.compile_all(pathlib.Path('src', u['source']).read_text(), *nu['src/' + u['source']], td,
                                  dict(u, matching_for=mf))[vi]
                f, s, _, _ = funcs(o, td, 'r', pool=u.get('pool') or {})
                ref.update({k: v for k, v in f.items() if k in u['symbols']}); rsecs.update(s)
            _, _, csg, _ = funcs(obj, td, f'c{vi}')
            addr = {n: (v, sz) for n, s, v, sz, _ in csg['defs'] if s == '.text' and sz}
            pool, bad = derive_pool(csg, addr, ref) if pooled else ({}, [])
            if bad:
                print(f'[{mf[vi]}] unresolved private literals {sorted(set(bad))[:6]}'); ok = False
            if vi == 0:
                new_pool = pool
            nf, nsecs, _, nlocal = funcs(obj, td, f'n{vi}', pool=pool)
            for s in sorted(own):
                if s not in nf:
                    print(f'[{mf[vi]}] missing {s}'); ok = False; continue
                (b1, r1), (b2, r2) = ref[s], nf[s]
                if len(b1) != len(b2):
                    print(f'[{mf[vi]}] {s}: size {len(b1)} -> {len(b2)}'); ok = False; continue
                words = [i for i in range(0, len(b1), 4) if b1[i:i+4] != b2[i:i+4] and not (b1[i] >> 2 == 18 and b2[i] >> 2 == 18)]
                ext = lambda r: [x for x in r if not (x[1] == 10 and x[2] in own)]
                if words or ext(r1) != ext(r2):
                    print(f'[{mf[vi]}] {s}: {len(words)} words differ; relocs {"same" if ext(r1) == ext(r2) else "differ"}'); ok = False
            extra = [f for f in nf if f not in own]
            if extra:
                print(f'[{mf[vi]}] extra functions {extra}'); ok = False
            for k, v in nsecs.items():
                if k == '.text' or not v or v == rsecs.get(k, 0):
                    continue
                if pooled and nlocal.get(k) and all(n in pool for n in nlocal[k]):
                    continue   # only remapped literals: poolfix empties the private copy
                print(f'[{mf[vi]}] section {k}: {rsecs.get(k, 0)} -> {v}'); ok = False
    print('IDENTICAL' if ok else 'DIFFERENT', f'({len(own)} functions, regions {mf}' + (f', pool {len(new_pool)})' if pooled else ')'))
    if not ok or not a.apply:
        return 0 if ok else 1
    dest = a.dest or srcs[0]
    sp = pathlib.Path('config/GFZE01/splits.txt'); text = sp.read_text(); blocks = split_blocks(text)
    secs = collections.OrderedDict()
    for s in srcs:
        if s not in blocks:
            print('no split for', s); return 1
        for name, lo, hi, al in parse_block(blocks[s]):
            secs.setdefault(name, []).append((lo, hi, al))
    merged_lines = []
    for name, rs in secs.items():
        rs.sort()
        if any(x[1] != y[0] for x, y in zip(rs, rs[1:])):
            print('split ranges not contiguous in', name); return 1
        al = max((int(r[2]) for r in rs if r[2]), default=None)
        merged_lines.append(f'\t{name:<11} start:0x{rs[0][0]:08X} end:0x{rs[-1][1]:08X}' + (f' align:{al}' if al else '') + '\n')
    text_lo = {s: min(lo for n, lo, hi, al in parse_block(blocks[s]) if n == '.text') for s in srcs}
    first = min(srcs, key=lambda s: text_lo[s])
    for s in srcs:
        pat = re.compile(rf'^{re.escape(s)}:\n(?:\t.*\n)*\n?', re.M)
        text = pat.sub((f'{dest}:\n' + ''.join(merged_lines) + '\n') if s == first else '', text, count=1)
    sp.write_text(text)
    syms = [x for s in sorted(srcs, key=lambda s: text_lo[s]) for x in byu[s]['symbols']]
    merged = dict(byu[first], source=dest, symbols=syms, collapsed=True)
    merged['mw_version'] = mv
    if a.extra:
        merged['extra_cflags'] = list(merged.get('extra_cflags') or []) + a.extra.split()
    if mf != list(VERSIONS): merged['matching_for'] = mf
    else: merged.pop('matching_for', None)
    if pooled: merged['pool'] = dict(sorted(new_pool.items(), key=lambda kv: int(kv[0][1:])))
    else: merged.pop('pool', None)
    out = []
    for u in units:
        if u['source'] in srcs:
            if u['source'] == first:
                out.append(merged)
            continue
        out.append(u)
    raw = json.dumps(out, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda mm: '"matching_for": [' + ', '.join(x.strip() for x in mm.group(1).split(',')) + ']', raw)
    pathlib.Path('config/GFZE01/units.json').write_text(raw)
    for s in srcs:
        pathlib.Path('src', s).unlink()
    pathlib.Path('src', dest).parent.mkdir(parents=True, exist_ok=True)
    pathlib.Path('src', dest).write_text(cand)
    print('applied as', dest)
    return 0


if __name__ == '__main__':
    sys.exit(main())
