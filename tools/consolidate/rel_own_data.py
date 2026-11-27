#!/usr/bin/env python3
"""Transfer complete, contiguous REL data imports into their recovered TU.

Specify the already evidenced TU and the complete import units, not an inferred
ownership range. Apply only in an isolated checkout. The three-region link gate
proves payload order, alignment and relocated bindings; verify source selection
and moved symbol extents as well so retail fallback cannot count as ownership.
"""
import argparse
import json
from pathlib import Path
import re
import subprocess
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from fzgx import poolfix, tufile
from fzgx.project import Project, ROOT, VERSIONS, dump_units, unit_matches

IMPORTS = Path('state/dataimports/GFZE01.json')
SECTION_ORDER = ('.text', '.ctors', '.dtors', '.rodata', '.data', '.bss')


def require(cond, message):
    if not cond:
        raise ValueError(message)


def regions(unit):
    return tuple(v for v in VERSIONS if unit_matches(unit, v))


def split_blocks(text):
    return dict(re.findall(r'^([^\s:][^:\n]*):\n((?:[ \t][^\n]*\n)*)', text, re.M))


def move_text(text, target, includes, body, tail):
    if not target.get('tu'):
        header, code = tufile.split_includes(text)
        prefix = tufile.merge_prologue('\n'.join(header), includes).rstrip() + '\n\n'
        return prefix + (code + '\n' + body if tail else body + '\n' + code)
    tf = tufile.parse(text)
    blocks = [b for n in target['symbols'] if (b := tf.get(n)) is not None]
    require(len(blocks) == len(target['symbols']), 'target unit does not own every listed block')
    if any('noprologue' not in b.flags for b in blocks):
        tf.prologue = tufile.merge_prologue(tf.prologue, includes)
        if not tail:
            tf.prologue = tf.prologue.rstrip() + '\n\n' + body
    else:
        header, code = tufile.split_includes(blocks[0].body)
        prefix = tufile.merge_prologue('\n'.join(header), includes).rstrip() + '\n\n'
        blocks[0].body = prefix + (code if tail else body + '\n' + code)
    if tail:
        blocks[-1].body = blocks[-1].body.rstrip() + '\n\n' + body
    return tf.render()


def verify_source(project, target, section, start, records, native):
    for version in regions(target):
        build = project.build_dir.parent / version
        units = json.loads((build / 'objdiff.json').read_text())['units']
        name = project.objdiff_unit_name(target['module'], target['source'])
        unit = next((u for u in units if u['name'] == name), {})
        require(unit.get('metadata', {}).get('complete') and unit.get('base_path'),
                f'{version}: target is not selected from source')
        ours = poolfix.Elf(Path(unit['base_path']).read_bytes())
        retail = poolfix.Elf(Path(unit['target_path']).read_bytes())
        for record in records:
            offset, size = record['address'] - start, record['size']
            for kind, obj in (('compiled', ours), ('retail', retail)):
                name = record['symbol']
                if kind == 'compiled':
                    name = native.get(name, name)
                sec = obj.section(section)
                require(sec and any(s['name'] == name and s['shndx'] == sec['index'] and
                                    s['value'] == offset and s['size'] == size for s in obj.symbols()),
                        f'{version}: {name} has wrong extent in {kind} {section}')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('tu', help='canonical REL source/container, e.g. rel/sample/_prolog.c')
    parser.add_argument('imports', nargs='+', help='complete data-import source paths, relative to src/')
    parser.add_argument('--native-literal', metavar='SYMBOL', help='use a TU literal already bound to the string import')
    parser.add_argument('--apply', action='store_true')
    args = parser.parse_args()
    require(Path.cwd() == ROOT, 'run at the repository root')
    project = Project()
    units = project.load_units()
    targets = [u for u in units if not u.get('data') and (u.get('tu') or u['source']) == args.tu]
    require(len(targets) == 1, 'target must already compile as one unit')
    target = targets[0]
    module = target['module']
    require(module != 'main' and args.tu.startswith(f'rel/{module}/') and not target.get('asm') and
            'GFZE01' in regions(target), 'expected a matching C REL unit')
    require(len(set(args.imports)) == len(args.imports), 'duplicate import source')
    donors = [u for u in units if u['source'] in args.imports and u.get('data') and u['module'] == module]
    require(len(donors) == len(args.imports), 'every import must be a data unit of the same REL')
    require(all(regions(u) == regions(target) and not u.get('pool') for u in donors),
            'donors must have the same regional source coverage and no pool fixups')
    split_path = project.module_config_dir(module) / 'splits.txt'
    splits = project.splits(module)
    owned = {u['source'] for u in donors}
    moved = [s for s in splits if s.unit in owned]
    require(len(moved) == len(donors) and {s.unit for s in moved} == owned and
            len({s.section for s in moved}) == 1, 'expected complete import units in one section')
    section = moved[0].section
    require(section in {'.rodata', '.data', '.bss'}, 'unsupported data section')
    old_ranges = [s for s in splits if s.unit == target['source'] and s.section == section]
    require(len(old_ranges) <= 1, 'target already has multiple ranges in the section')
    tail = bool(old_ranges and all(s.start >= old_ranges[0].end for s in moved))
    require(not old_ranges or tail or all(s.end <= old_ranges[0].start for s in moved),
            'transfer one edge of the target section at a time')
    joined = sorted(moved + old_ranges, key=lambda s: s.start)
    start, end = joined[0].start, joined[-1].end
    require(all(a.end == b.start for a, b in zip(joined, joined[1:])), 'data slices are not contiguous')
    align = max((s.align or 1) for s in joined)
    require(start % align == 0, 'merged split start violates alignment')
    imports = json.loads(IMPORTS.read_text())
    records, definitions, includes = [], [], []
    native = {}
    for split in sorted(moved, key=lambda s: s.start):
        unit = next(u for u in donors if u['source'] == split.unit)
        rows = [imports.get(f'{module}:{n}') for n in unit['symbols']]
        require(all(r and r['source'] == split.unit and split.start <= r['address'] and
                    r['address'] + r['size'] <= split.end for r in rows), f'{split.unit}: missing import provenance')
        records.extend(rows)
        text = Path('src', split.unit).read_text()
        require(text.startswith('/* Generated by fzgx data-import;'), f'{split.unit}: unexpected source format')
        inc, body = tufile.split_includes(text.partition('\n')[2])
        if args.native_literal in unit['symbols']:
            row = imports[f'{module}:{args.native_literal}']
            bindings = [k for k, v in (target.get('pool') or {}).items() if v == args.native_literal]
            require(len(donors) == len(rows) == len(bindings) == 1 and section == '.rodata' and
                    row['method'] == 'string' and row['references'] and
                    set(row['references']) <= set(target['symbols']),
                    'native literal needs one string import, one binding and only TU-local consumers')
            native[args.native_literal] = bindings[0]
        else:
            includes.extend(inc)
            definitions.append(body.strip())
    require(not args.native_literal or native, 'native literal is not in the moved imports')
    source = Path('src', args.tu)
    candidate = source.read_text()
    if definitions:
        candidate = move_text(candidate, target, includes, '\n\n'.join(definitions) + '\n', tail)
    inside = {r['symbol'] for r in records}
    require(not target.get('pool_for') and not inside.intersection(target.get('own') or []),
            'regional/owned bindings need independent verification before removal')
    if 'pool' in target:
        target['pool'] = {k: v for k, v in target['pool'].items() if poolfix.binding_target(v)[0] not in inside}
        if not target['pool']:
            del target['pool']
    original_split = split_path.read_text()
    blocks = split_blocks(original_split)
    old = blocks[target['source']]
    lines = [line for line in old.splitlines(True) if line.split()[0] != section]
    lines.append(f'\t{section:<11} start:0x{start:08X} end:0x{end:08X} align:{align}\n')
    lines.sort(key=lambda s: SECTION_ORDER.index(s.split()[0]))
    updated_split = original_split.replace(f'{target["source"]}:\n{old}',
                                           target['source'] + ':\n' + ''.join(lines), 1)
    for donor in donors:
        block = f'{donor["source"]}:\n{blocks[donor["source"]]}'
        updated_split = updated_split.replace(block + ('\n' if block + '\n' in updated_split else ''), '', 1)
    updated_split = updated_split.rstrip('\n') + '\n'
    print(f'{args.tu}: absorb {len(donors)} import units ({len(records)} symbols) into {section} '
          f'0x{start:X}..0x{end:X}; source regions: {", ".join(regions(target))}', flush=True)
    if not args.apply:
        return
    edits: dict[Path, str | None] = {source: candidate, split_path: updated_split,
                                     project.units_path: dump_units([u for u in units if u['source'] not in owned])}
    for record in records:
        del imports[f'{module}:{record["symbol"]}']
    edits[IMPORTS] = json.dumps(imports, indent=2, sort_keys=True) + '\n'
    edits.update({Path('src', u['source']): None for u in donors})
    baseline = {p: p.read_bytes() for p in edits}
    try:
        for path, text in edits.items():
            if text is None:
                path.unlink()
            else:
                path.write_text(text)
        # Configure again after extraction so newly changed splits are represented in objdiff.
        for _ in range(2):
            subprocess.run(['tools/consolidate/gate.sh'], check=True)
        verify_source(project, target, section, start, records, native)
    except BaseException:
        for path, data in baseline.items():
            path.write_bytes(data)
        raise


if __name__ == '__main__':
    try:
        main()
    except (ValueError, subprocess.CalledProcessError) as exc:
        sys.exit(str(exc))
