#!/usr/bin/env python3
"""Split a DOL data-import unit at object boundaries (GFZE01).

  data_split.py dol/data/UNIT.c SYMBOL [SYMBOL...] [--apply]

Each SYMBOL starts a new unit `dol/data/SYMBOL.c` holding the definitions from it up to the next
split point. A unit's section is aligned to its most aligned object, so a unit that a TU's data
ownership leaves starting at a weaker boundary than its contents need must be split there first
(tu_own_data.py trims only the head or the tail of a unit). The preamble (includes and extern
declarations) is kept in every part. Updates units.json, splits.txt and state/dataimports.
Run gate.sh afterwards: the link hash is the proof.
"""
import json, pathlib, re, sys

UNITS, SPLITS, IMPORTS = 'config/GFZE01/units.json', 'config/GFZE01/splits.txt', 'state/dataimports/GFZE01.json'
BLOCK = re.compile(r'#pragma explicit_zero_data on\n__declspec\(section "([^"]+)"\)[^\n]*?\b(\w+)(?:\[\w*\])? __attribute__\(\(aligned\((\d+)\)\)\).*?#pragma explicit_zero_data reset\n', re.S)


def main():
    args = [a for a in sys.argv[1:] if a != '--apply']
    unit, cuts = args[0], args[1:]
    src = pathlib.Path('src', unit)
    text = src.read_text()
    blocks = list(BLOCK.finditer(text))
    names = [m[2] for m in blocks]
    if not blocks or any(c not in names for c in cuts):
        raise SystemExit(f'{unit}: cannot find every split symbol among {names}')
    sections = {m[1] for m in blocks}
    if len(sections) != 1:
        raise SystemExit(f'{unit}: more than one section {sections}')
    sec = sections.pop()
    addr = {}
    for line in open('config/GFZE01/symbols.txt'):
        m = re.match(rf'(\S+) = {re.escape(sec)}:0x(\w+);', line)
        if m:
            addr[m[1]] = int(m[2], 16)
    preamble = text[:blocks[0].start()]
    starts = [0] + sorted(names.index(c) for c in cuts)
    parts = []
    for i, first in enumerate(starts):
        last = starts[i + 1] if i + 1 < len(starts) else len(blocks)
        body_start = blocks[first].start() if first else blocks[0].start()
        body_end = blocks[last].start() if last < len(blocks) else len(text)
        # text between blocks (extern prototypes for relocations) travels with the following block
        if first:
            body_start = blocks[first - 1].end()
        if last < len(blocks):
            body_end = blocks[last - 1].end()
        align = max(int(m[3]) for m in blocks[first:last])
        parts.append((names[first], names[first:last], preamble + text[body_start:body_end].lstrip('\n'), align))
    splits = open(SPLITS).read()
    m = re.search(rf'^{re.escape(unit)}:\n\t{re.escape(sec)}\s+start:0x(\w+) end:0x(\w+) align:(\d+)\n', splits, re.M)
    if not m:
        raise SystemExit(f'{unit}: expected one {sec} split')
    lo, hi = int(m[1], 16), int(m[2], 16)
    bounds = [lo] + [addr[p[0]] for p in parts[1:]] + [hi]
    for (first, syms, body, align), a, b in zip(parts, bounds, bounds[1:]):
        if a & (align - 1):
            raise SystemExit(f'{first}: 0x{a:08X} does not satisfy its contents\' alignment {align}')
        print(f'{first}: 0x{a:08X}..0x{b:08X} align {align}, {len(syms)} objects')
    if '--apply' not in sys.argv:
        return
    units = json.load(open(UNITS)); imports = json.load(open(IMPORTS))
    at = next(i for i, u in enumerate(units) if u['source'] == unit)
    old = units[at]
    entries, blocks_txt = [], ''
    for (first, syms, body, align), a, b in zip(parts, bounds, bounds[1:]):
        dest = unit if first == parts[0][0] else f'dol/data/{first}.c'
        pathlib.Path('src', dest).write_text(body)
        entries.append(dict(old, source=dest, symbols=[s for s in old['symbols'] if s in syms]))
        blocks_txt += f'{dest}:\n\t{sec:<11} start:0x{a:08X} end:0x{b:08X} align:{align}\n\n'
        for v in imports.values():
            if v.get('source') == unit and v.get('symbol') in syms:
                v.update(source=dest, unit_start=a, unit_size=b - a, section_size=b - a, unit_align=align)
    units[at:at + 1] = entries
    splits = splits[:m.start()] + blocks_txt + splits[m.end():].lstrip('\n')
    raw = json.dumps(units, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda x: '"matching_for": [' + ', '.join(y.strip() for y in x[1].split(',')) + ']', raw)
    open(UNITS, 'w').write(raw); open(SPLITS, 'w').write(splits)
    open(IMPORTS, 'w').write(json.dumps(imports, indent=2, sort_keys=True) + '\n')
    print('applied')


if __name__ == '__main__':
    main()
