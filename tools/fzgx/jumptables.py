"""Give each switch jump table to the function unit that emits it.

MWCC writes a switch's jump table into the TU's .data at the function's position, so
the table is the function's own data. A per-function unit compiles that table (`@N`)
too, but while the retail table sat in an auto object the unit's pool map
(`@N=jumptable_X`) retargeted the code to it and poolfix dropped our copy.

This pass moves a table into its function's unit: the unit's split takes the table's
.data range and the unit's pool map stops retargeting it, so the object keeps MWCC's
own table, under MWCC's own name. objdiff pairs it with the retail table by position
and contents (the oracle then sees no differing row, so re-derived pool maps agree).
Nothing is patched or renamed: the bytes and relocations are the compiler's, and the
16 hashes are the gate.

A unit's .data starts at MWCC's section alignment (8), so a lone table can start its
unit only at an 8-aligned address. Consecutive tables of one function go together.
A table at 4 mod 8 needs the data before it in the same unit (the block must define
it) or the previous function's table (both functions in one unit): reported, not done.
"""
from __future__ import annotations

import re
import struct
import sys
from typing import Dict, List

from . import oracle, poolfix
from .carve import _align_for, _section_default_align
from .dataimport import reference_index, regions, relocated_between
from .project import Project

DATA_ALIGN = 8  # MWCC's .data section alignment


def plan(p: Project, module: str | None = None) -> Dict[str, list]:
    """Group unowned jump tables by owning function; say why a group cannot move."""
    ready, refused = [], []
    for mod in [module] if module else p.modules:
        refs = reference_index(p, mod)
        syms = p.symbols(mod)
        tables = sorted((s for s in syms.values() if s.kind == 'object' and s.section == '.data'
                         and s.name.startswith('jumptable_') and s.size and not p.unit_of(s)),
                        key=lambda s: s.addr)
        groups: List[list] = []
        for s in tables:
            users = sorted(set(refs.get(s.name, [])))
            fn = users[0] if len(users) == 1 else None
            if groups and fn and groups[-1][0] == fn and groups[-1][1][-1].end + 4 >= s.addr \
                    and not _symbols_between(p, mod, groups[-1][1][-1].end, s.addr):
                groups[-1][1].append(s)
            else:
                groups.append([fn or ','.join(users), [s]])
        for fn_name, members in groups:
            first, last = members[0], members[-1]
            row = dict(module=mod, function=fn_name, tables=[s.name for s in members],
                       start=first.addr, end=last.end, bytes=sum(s.size for s in members))
            reason = _refusal(p, mod, fn_name, first)
            if reason:
                row['reason'] = reason
                refused.append(row)
                continue
            row['unit'] = p.unit_of(p.find_symbol(fn_name, mod))
            row['end'] = _padded_end(p, mod, last.end)
            row['align'] = _align_for(first.addr, _section_default_align(p, mod, '.data'))
            ready.append(row)
        rows = [r for r in ready if r['module'] == mod]
        while True:
            count = len(rows)
            _refuse_boxed_gaps(p, mod, rows, ready, refused)
            _refuse_private_remainder(p, rows, ready, refused)
            if len(rows) == count:
                break
    return dict(ready=ready, refused=refused)


def _refuse_boxed_gaps(p, module, rows, ready, refused):
    """dtk reads a gap before a split as that split's alignment padding when aligning the gap's
    start reaches the split; padding must be zero, so data there fails the split (measured:
    "Unsplit data in .data from rel/main_rel/font/fn_1_49B70.c 0x1C0B4 to next split 0x1C0B8":
    lbl_1_data_1C0B4, 4 B at 4 mod 8 behind jumptable_1_data_1BFD8). A new range must not
    leave such a gap on either side, counting the other new ranges; refuse until none does."""
    default = _section_default_align(p, module, '.data')
    existing = [(sp.start, sp.end, sp.align or default) for sp in p.splits(module) if sp.section == '.data']
    while rows:
        spans = existing + [(r['start'], r['end'], r['align']) for r in rows]
        bad = None
        for r in rows:
            before = max((e for s, e, _ in spans if e <= r['start']), default=None)
            after = min(((s, a) for s, e, a in spans if s >= r['end']), default=None)
            gaps = []
            if before is not None and _padding(before, r['start'], r['align']):
                gaps.append((before, r['start']))
            if after is not None and _padding(r['end'], after[0], after[1]):
                gaps.append((r['end'], after[0]))
            for lo, hi in gaps:
                if not _zero_gap(p, module, lo, hi):
                    bad = (r, lo, hi)
                    break
            if bad:
                break
        if not bad:
            return
        r, lo, hi = bad
        rows.remove(r)
        ready.remove(r)
        names = [s.name for s in _symbols_between(p, module, lo, hi)]
        refused.append(dict(r, reason=f'would leave data {names or ""} in padding 0x{lo:X}-0x{hi:X} '
                                      'between splits: dtk rejects it'))


def _refuse_private_remainder(p, rows, ready, refused):
    """Run the unit's remaining pool map through poolfix, as ninja's mwcc_pool rule will, and
    refuse the unit's tables unless every private section still empties. Measured: fn_8007CF18
    compiles its string `@694` into .data in front of its table `@695`; retail keeps the string
    in .rodata (lbl_80094ED8), so with the table owned .data can never empty and poolfix fails
    the build (`rodata_emptied: false`). Cutting the string out would be patching the object.
    What stays in .data must be exactly the tables' span, the range the split takes."""
    for unit in sorted({r['unit'] for r in rows}):
        mine = [r for r in rows if r['unit'] == unit]
        tables = {t for r in mine for t in r['tables']}
        rest = {k: v for k, v in (p.unit_record(unit).get('pool') or {}).items() if v not in tables}
        module = mine[0]['module']
        ends = [p.find_symbol(r['tables'][-1], module).end for r in mine]
        span = max(ends) - min(r['start'] for r in mine)
        scratch = oracle.STATE_DIR / 'work' / ('jumptables__' + unit.replace('/', '__') + '.o')
        scratch.parent.mkdir(parents=True, exist_ok=True)
        cp = oracle.compile_unit(p, p.objdiff_unit_name(module, unit), unit, None, output=scratch)
        if cp.returncode or not scratch.exists():
            reason = f'{unit}: does not compile ({(cp.stdout + cp.stderr)[-200:]})'
        else:
            res = poolfix.apply(scratch, rest) if rest else dict(rodata_emptied=True, skipped=[])
            data = poolfix.Elf(scratch.read_bytes()).section('.data')
            size = data['size'] if data else 0
            if not res['rodata_emptied'] or res['skipped']:
                reason = (f'its other pool bindings ({len(rest)}) leave a private section that cannot '
                          f'empty once the unit keeps its own table (poolfix: skipped {res["skipped"]})')
            elif size != span:
                reason = f'its .data would be 0x{size:X} bytes, not the 0x{span:X} of its tables'
            else:
                reason = _table_disagrees(p, module, mine, poolfix.Elf(scratch.read_bytes()))
        if reason:
            for r in mine:
                rows.remove(r)
                ready.remove(r)
                refused.append(dict(r, reason=reason))


def _relocations(elf, section):
    """{offset: (symbol, addend)} of the RELA section that patches `section`."""
    syms = elf.symbols()
    out = {}
    for rs in elf.sections:
        if rs['type'] == 4 and rs['info'] == section['index']:  # SHT_RELA
            for pos in range(rs['offset'], rs['offset'] + rs['size'], 12):
                offset, info, addend = struct.unpack_from('>IIi', elf.data, pos)
                out[offset] = (syms[info >> 8], addend)
    return out


def _retail_tables(p, module):
    """{table name: (retail split object, its symbol)} over the current split's auto objects."""
    cache = p.__dict__.setdefault('_jumptable_objects', {})
    if module not in cache:
        found = {}
        listed = re.findall(r'"object":\s*"([^"]*/obj/auto_[^"]*)"', (p.build_dir / 'config.json').read_text())
        for rel in listed:
            path = oracle.ROOT / rel
            parts = path.relative_to(p.build_dir).parts
            if ('main' if parts[0] == 'obj' else parts[0]) != module or not path.exists():
                continue
            elf = poolfix.Elf(path.read_bytes())
            for s in elf.symbols():
                if s['name'].startswith('jumptable_') and 0 < s['shndx'] < len(elf.sections):
                    found[s['name']] = (path, s)
        cache[module] = found
    return cache[module]


def _table_disagrees(p, module, mine, ours):
    """Why the unit's own tables would not reproduce retail's, or None. The code can match while
    the switch's cases disagree: with the table retargeted, the code read retail's table (measured:
    fn_80028164's table compiles as retail's rotated by one entry, jumptable_8015B7C0's permuted)."""
    fn = next(s for s in ours.symbols() if s['name'] == mine[0]['function'])
    text_base = p.find_symbol(mine[0]['function'], module).addr - fn['value']
    data_base = min(r['start'] for r in mine)
    data = ours.section('.data')
    compiled = {}
    for offset, (sym, addend) in _relocations(ours, data).items():
        if 0 < sym['shndx'] < len(ours.sections) and ours.sections[sym['shndx']]['flags'] & 4:  # SHF_EXECINSTR
            compiled[data_base + offset] = text_base + sym['value'] + addend
        else:
            return f'its table entry at 0x{data_base + offset:X} targets {sym["name"]}, not its own code'
    retail = {}
    known = _retail_tables(p, module)
    for name in (t for r in mine for t in r['tables']):
        if name not in known:
            return f'no retail split object defines {name}'
        path, tsym = known[name]
        elf = poolfix.Elf(path.read_bytes())
        start = p.find_symbol(name, module).addr
        for offset, (sym, addend) in _relocations(elf, elf.sections[tsym['shndx']]).items():
            if tsym['value'] <= offset < tsym['value'] + tsym['size']:
                target = p.find_symbol(sym['name'], module) if sym['shndx'] == 0 else None
                if target is None:
                    return f'cannot resolve retail entry {sym["name"]} of {name}'
                retail[start + offset - tsym['value']] = target.addr + addend
    if compiled != retail:
        wrong = sorted(a for a in set(compiled) | set(retail) if compiled.get(a) != retail.get(a))
        return (f'its switch compiles a different table: {len(wrong)} of {len(retail)} entries differ '
                f'from retail (first 0x{wrong[0]:X}); the code matched only against the retail table')
    return None


def _padding(start, end, align):
    return start < end and (start + align - 1) // align * align >= end


def _zero_gap(p, module, start, end):
    if _symbols_between(p, module, start, end) or relocated_between(p, module, '.data', start, end):
        return False
    return any(base <= start and end <= base + len(raw) and not any(raw[start - base:end - base])
               for base, raw in regions(p, module, '.data'))


def _symbols_between(p, module, start, end):
    return [s for s in p.symbols(module).values() if s.section == '.data' and start <= s.addr < end]


def _refusal(p, module, fn_name, first):
    fn = p.find_symbol(fn_name, module) if fn_name and ',' not in fn_name else None
    if fn is None:
        return f'referenced by {fn_name or "no function"}; needs one owning function'
    unit = p.unit_of(fn)
    record = p.unit_record(unit) if unit else None
    if not record or record.get('status') != 'matching' or record.get('asm') or record.get('data') \
            or not isinstance(record.get('pool'), dict):
        return f'{fn_name}: not a matched C unit with a pool binding'
    if first.addr % DATA_ALIGN:
        prev = max((s for s in p.symbols(module).values() if s.section == '.data' and s.end <= first.addr),
                   key=lambda s: s.addr, default=None)
        kind = 'another jump table' if prev and prev.name.startswith('jumptable_') else 'data'
        return f'at 4 mod 8 after {kind} {prev.name if prev else "?"}: the unit cannot start there'
    if any(sp.section == '.data' and sp.unit == unit for sp in p.splits(module)):
        return f'{unit} already has a .data range'
    return None


def _padded_end(p, module, end):
    """Own zero padding up to a split that follows within one alignment step, as the data
    importer does: no auto object would carry it."""
    following = [sp.start for sp in p.splits(module) if sp.section == '.data' and sp.start >= end]
    if not following or not 0 < min(following) - end < DATA_ALIGN:
        return end
    gap_end = min(following)
    if _symbols_between(p, module, end, gap_end) or relocated_between(p, module, '.data', end, gap_end):
        return end
    if not any(base <= end and gap_end <= base + len(raw) and not any(raw[end - base:gap_end - base])
               for base, raw in regions(p, module, '.data')):
        return end
    return gap_end


def _add_range(text: str, unit: str, start: int, end: int, align: int) -> str:
    lines = text.split('\n')
    head = lines.index(f'{unit}:')
    at = head + 1
    while at < len(lines) and lines[at].startswith('\t'):
        at += 1
    lines.insert(at, f'\t{".data":<11} start:0x{start:08X} end:0x{end:08X} align:{align}')
    return '\n'.join(lines)


def apply(p: Project, rows: List[dict]) -> Dict[str, object]:
    """Give each row's tables to its unit, drop their retail bindings, build and check all hashes.
    Any failure restores every file this touched and rebuilds the previous tree."""
    modules = sorted({r['module'] for r in rows})
    paths = [p.units_path] + [p.module_config_dir(m) / 'splits.txt' for m in modules]
    before = {path: path.read_bytes() for path in paths}
    done = []
    try:
        with oracle.build_lock('units.lock'):
            units = p.load_units()
            for u in units:
                tables = {t for r in rows if r['unit'] == u['source'] for t in r['tables']}
                if not tables:
                    continue
                bound = [k for k, v in u['pool'].items() if v in tables]
                if len(bound) != len(tables):
                    raise ValueError(f"{u['source']}: its pool map does not retarget {sorted(tables)}")
                # the unit now defines the table itself: stop retargeting it to the retail copy
                for k in bound:
                    del u['pool'][k]
                if not u['pool']:
                    u.pop('pool')
            p.save_units(units)
        for m in modules:
            path = p.module_config_dir(m) / 'splits.txt'
            text = path.read_text()
            # one unit's adjacent tables (a whole-TU unit with several switches) are one range
            ranges: List[list] = []
            for r in sorted((r for r in rows if r['module'] == m), key=lambda r: r['start']):
                if ranges and ranges[-1][0] == r['unit'] and ranges[-1][2] == r['start']:
                    ranges[-1][2] = r['end']
                else:
                    ranges.append([r['unit'], r['start'], r['end'], r['align']])
            for unit, start, end, align in ranges:
                text = _add_range(text, unit, start, end, align)
            path.write_text(text)
        p.__dict__.pop('_splits_cache', None)
        from .api import _reconfigure_and_split
        _reconfigure_and_split(p)
        for r in rows:
            res = oracle.check(p, f"{r['module']}:{r['function']}" if r['function'].startswith('_') else r['function'], 20)
            if not (res.ok and res.matched) or set(r['tables']) & set(res.pool_map.values()):
                raise ValueError(f"{r['function']}: does not match with its own table "
                                 f"({res.percent}%, pool {res.pool_map}, error {res.error[-300:] if res.error else None})")
        for command in ([sys.executable, 'configure.py', '--version', p.version], ['ninja'],
                        ['build/tools/dtk', 'shasum', '-q', '-c', f'config/{p.version}/build.sha1']):
            cp = oracle.run(command, timeout=1800)
            if cp.returncode:
                raise ValueError(' '.join(command) + ' failed:\n' + (cp.stdout + cp.stderr)[-4000:])
        done = [dict(r) for r in rows]
    except BaseException:
        for path, data in before.items():
            path.write_bytes(data)
        p.__dict__.pop('_splits_cache', None)
        configured = oracle.configure(p)
        rebuilt = oracle.relink(p) if configured.returncode == 0 else configured
        if rebuilt.returncode:
            print('Jump-table ownership rolled back, but rebuilding the previous tree failed:\n'
                  + (rebuilt.stdout + rebuilt.stderr)[-3000:], file=sys.stderr)
        raise
    return dict(owned=done, bytes=sum(r['bytes'] for r in done))


def own(p: Project, module: str | None = None, functions: List[str] | None = None,
        do_apply: bool = False) -> Dict[str, object]:
    with oracle.build_lock():
        result = plan(p, module)
    rows = [r for r in result['ready'] if not functions or r['function'] in functions]
    out = dict(ready=rows, refused=result['refused'], bytes=sum(r['bytes'] for r in rows))
    if do_apply and rows:
        out.update(apply(p, rows))
    return out
