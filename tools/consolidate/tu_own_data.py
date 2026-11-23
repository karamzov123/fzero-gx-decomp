#!/usr/bin/env python3
"""Give a collapsed DOL unit native ownership of a data range.

  tu_own_data.py UNIT SECTION LO HI [--apply]

The unit's compiled SECTION must equal the retail bytes at LO..HI (trailing alignment excepted).
Data-import units inside the range are deleted, a unit ending inside it or starting at LO is trimmed, the range
joins the unit's split and pool bindings into it are dropped. Run gate.sh afterwards: the link
hash in every region is the proof.
"""
import json, pathlib, re, struct, sys, tempfile
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, objsig

UNITS, SPLITS, IMPORTS = 'config/GFZE01/units.json', 'config/GFZE01/splits.txt', 'state/dataimports/GFZE01.json'
ORDER = ['.init', '.text', '.ctors', '.dtors', '.rodata', '.data', '.bss', '.sdata', '.sbss', '.sdata2', '.sbss2']


def retail(lo, n):
    b = open('orig/GFZE01/sys/main.dol', 'rb').read()
    off, addr, size = (struct.unpack('>18I', b[i:i + 72]) for i in (0, 72, 144))
    for o, a, s in zip(off, addr, size):
        if s and a <= lo < a + s:
            return b[o + lo - a:o + lo - a + n]
    raise SystemExit(f'0x{lo:08X} is not initialized DOL data')


def drop_definition(text, name):
    text, n = re.subn(rf'^extern [^;\n]*\b{name}\b[^;\n]*;\n', '', text, flags=re.M)
    pat = rf'#pragma explicit_zero_data on\n__declspec\(section "[^"]+"\)[^\n]*\b{name}\b.*?#pragma explicit_zero_data reset\n'
    text, m = re.subn(pat, '', text, count=1, flags=re.S)
    if m != 1:
        raise SystemExit(f'cannot find the definition of {name}')
    return re.sub(r'\n{3,}', '\n\n', text)


def main():
    args = [x for x in sys.argv[1:] if x != '--apply']
    unit, sec, lo, hi = args[0], args[1], int(args[2], 16), int(args[3], 16)
    units = json.load(open(UNITS)); imports = json.load(open(IMPORTS)); text = open(SPLITS).read()
    target = next(u for u in units if u['source'] == unit)
    nu = d.ninja_units(); mv, cf = nu['src/' + unit]
    plain = {k: v for k, v in target.items() if k != 'pool'}
    with tempfile.TemporaryDirectory() as td:
        obj = d.compile_all(pathlib.Path('src', unit).read_text(), mv, cf, td, plain)[0]
        p = pathlib.Path(td, 'u.o'); p.write_bytes(obj); got = objsig.sig(p)['sections'].get(sec, b'')
    if sec in ('.bss', '.sbss'):
        if not got or got > hi - lo:
            raise SystemExit(f'{sec}: compiled size {got} does not fit 0x{lo:X}..0x{hi:X}')
    else:
        want = retail(lo, hi - lo)
        if not isinstance(got, bytes) or not got or len(got) > hi - lo or want[:len(got)] != got or any(want[len(got):]):
            raise SystemExit(f'{sec}: compiled {len(got) if isinstance(got, bytes) else got} bytes differ from retail 0x{lo:X}..0x{hi:X}')
    syms = {m[1]: int(m[2], 16) for m in re.finditer(rf'^(\S+) = {re.escape(sec)}:0x([0-9A-F]+);', open('config/GFZE01/symbols.txt').read(), re.M)}
    inside = {n for n, a in syms.items() if lo <= a < hi}
    delete, trim = [], []
    for u in units:
        if not u.get('data'):
            continue
        b = re.search(rf'^{re.escape(u["source"])}:\n((?:\t.*\n)*)', text, re.M)
        r = b and re.search(rf'\t{re.escape(sec)}\s+start:0x(\w+) end:0x(\w+)', b[1])
        if not r or int(r[2], 16) <= lo or int(r[1], 16) >= hi:
            continue
        (delete if lo <= int(r[1], 16) and int(r[2], 16) <= hi else trim).append((u, int(r[1], 16), int(r[2], 16)))
    print('delete', [u['source'] for u, _, _ in delete], 'trim', [u['source'] for u, _, _ in trim])
    if '--apply' not in sys.argv:
        return
    for u, a, b in trim:
        if a == lo and hi < b:          # the unit keeps its tail, under the name of its new first symbol
            src = pathlib.Path('src', u['source']); body = src.read_text()
            for n in [n for n in u['symbols'] if n in inside]:
                body = drop_definition(body, n); u['symbols'].remove(n); imports.pop(f'main:{n}', None)
            dest = f'dol/data/{u["symbols"][0]}.c'
            pathlib.Path('src', dest).write_text(body); src.unlink()
            text = re.sub(rf'^{re.escape(u["source"])}:\n((?:\t.*\n)*?\t{re.escape(sec)}\s+start:0x)\w+', rf'{dest}:\n\g<1>{hi:08X}', text, flags=re.M)
            u['source'] = dest
            for n in u['symbols']:
                if f'main:{n}' in imports:
                    imports[f'main:{n}'].update(source=dest, unit_start=hi, unit_size=b - hi, section_size=b - hi)
            continue
        if not (a < lo < b <= hi):
            raise SystemExit(f'{u["source"]}: only a unit ending inside the range or starting at it can be trimmed')
        src = pathlib.Path('src', u['source']); body = src.read_text()
        for n in [n for n in u['symbols'] if n in inside]:
            body = drop_definition(body, n); u['symbols'].remove(n); imports.pop(f'main:{n}', None)
        src.write_text(body)
        text = re.sub(rf'(^{re.escape(u["source"])}:\n(?:\t.*\n)*?\t{re.escape(sec)}\s+start:0x\w+ end:0x)\w+', rf'\g<1>{lo:08X}', text, flags=re.M)
        for n in u['symbols']:
            if f'main:{n}' in imports:
                imports[f'main:{n}'].update(unit_size=lo - a, section_size=lo - a)
    for u, _, _ in delete:
        pathlib.Path('src', u['source']).unlink()
        for n in u['symbols']:
            imports.pop(f'main:{n}', None)
            h = pathlib.Path('include/dol/data', n + '.h')
            if h.exists():
                h.unlink()
        text = re.sub(rf'^{re.escape(u["source"])}:\n(?:\t.*\n)*\n?', '', text, flags=re.M)
    gone = {id(u) for u, _, _ in delete}
    units = [u for u in units if id(u) not in gone]
    m = re.search(rf'^{re.escape(unit)}:\n((?:\t.*\n)*)', text, re.M)
    lines = m[1].splitlines(True) + [f'\t{sec:<11} start:0x{lo:08X} end:0x{hi:08X} align:{8 if sec == ".sdata2" else 4}\n']
    lines.sort(key=lambda l: ORDER.index(l.split()[0]))
    text = text[:m.start(1)] + ''.join(lines) + text[m.end(1):]
    pool = {k: v for k, v in target.get('pool', {}).items() if v.split('+')[0] not in inside}
    if pool:
        target['pool'] = pool
    else:
        target.pop('pool', None)
    open(SPLITS, 'w').write(text); raw = json.dumps(units, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda x: '"matching_for": [' + ', '.join(y.strip() for y in x[1].split(',')) + ']', raw)
    open(UNITS, 'w').write(raw)
    open(IMPORTS, 'w').write(json.dumps(imports, indent=2, sort_keys=True) + '\n')
    print('applied')


if __name__ == '__main__':
    main()
