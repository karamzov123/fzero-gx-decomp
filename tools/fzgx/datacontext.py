"""Relevant owned data declarations and values for shell-less matchers."""
from __future__ import annotations

import json

from .project import ROOT


def imports(project):
    path = ROOT / 'state/dataimports' / f'{project.version}.json'
    stamp = path.stat().st_mtime_ns if path.exists() else None
    cached = project.__dict__.get('_context_data_imports')
    if cached is None or cached[0] != stamp:
        cached = (stamp, json.loads(path.read_text()) if stamp else {})
        project._context_data_imports = cached
    return cached[1]


def lookup(project, symbol):
    return imports(project).get(f'{symbol.module}:{symbol.name}') if symbol else None


def declarations(project, record):
    """Show the actual owned header, including arrays, const and union views."""
    header = record.get('header', {}).get('path')
    if not header:
        header = next((d['path'][8:] for d in record.get('declarations', [])
                       if d['path'].startswith('include/')), None)
    if header:
        from .context import _header_decl
        text = (ROOT / 'include' / header).read_text()
        return f'#include "{header}"\n' + _header_decl(text, record['symbol'])
    return 'extern ' + record['definition'] + ';'


def relevant(project, fn, loads):
    selected = {}
    for name in fn.refs:
        sym = project.find_symbol(name, fn.symbol.module) or project.find_symbol(name)
        if record := lookup(project, sym):
            selected[(record['module'], record['symbol'])] = record
    # Retail often addresses an entire TU pool through its first symbol.
    # A later load may fall into another imported object in the same section.
    for load in loads.values():
        sym = project.find_symbol(load['symbol'], fn.symbol.module) or project.find_symbol(load['symbol'])
        if not sym:
            continue
        address = sym.addr + load['offset']
        for record in imports(project).values():
            if (record['module'] == sym.module and record['section'] == sym.section
                    and record['address'] <= address < record['address'] + record['size']):
                selected[(record['module'], record['symbol'])] = record
                break
    return list(selected.values())


def evidence(project, fn, loads, full=False):
    records = relevant(project, fn, loads)
    if not records:
        return []
    lines = ['Imported data is already defined in separate C units. Include/declare it; do not redefine it.']
    for record in records:
        name, size = record['symbol'], record['size']
        lines.append(f'{name}: {record["section"]}, {size} bytes; {record["method"]}.')
        if record['section'] in ('.bss', '.sbss', '.sbss2'):
            lines.append('  Mutable runtime storage; initial zeros do not establish its value at this call.')
        if full:
            lines += declarations(project, record).splitlines()
        if recipe := record.get('recipe'):
            for region in recipe.get('regions', ()):
                lines.append('  ' + region['field'] + ''.join(f'[{n}]' for n in region['shape']))
            for field in recipe.get('record', ()):
                lines.append('  ' + f'{field[0]} {field[1]}' + (f'[{field[2]}]' if len(field) > 2 else ''))
        if record['method'] in ('string', 'string-pool'):
            raw = project.bytes_at(record['module'], name)
            shown = raw if full else raw[:128]
            lines.append(f'  bytes[0:{len(shown)}] = {shown!r}')
            if len(shown) < len(raw):
                lines.append('  Full bytes: read_evidence(section="data", cursor="0").')
        bindings = record['relocations']
        for entry in bindings if full else bindings[:8]:
            lines.append(f'  +0x{entry["offset"]:X} -> {entry["module"]}:{entry["symbol"]}'
                         + (f'{entry["addend"]:+#x}' if entry['addend'] else ''))
        if not full and len(bindings) > 8:
            lines.append(f'  {len(bindings)} total bindings: read_evidence(section="data", cursor="0").')
    # Only read values actually loaded by this function, not entire large pools.
    from .evidence import retail_bytes
    for load in loads.values():
        if load['op'] in ('lfs', 'lfd'):
            continue
        sym = project.find_symbol(load['symbol'], fn.symbol.module) or project.find_symbol(load['symbol'])
        if not sym or sym.section in ('.bss', '.sbss', '.sbss2'):
            continue
        address = sym.addr + load['offset']
        record = next((r for r in records if r['module'] == sym.module and r['section'] == sym.section
                       and r['address'] <= address and address + load['width'] <= r['address'] + r['size']), None)
        if not record:
            continue
        offset = address - record['address']
        binding = next((r for r in record['relocations'] if r['offset'] == offset), None)
        if binding:
            value = f'&{binding["symbol"]}' + (f'{binding["addend"]:+#x}' if binding['addend'] else '')
        else:
            raw = retail_bytes(project, sym.module, sym.name, load['offset'], load['width'])
            value = '0x' + raw.hex() if raw else 'unavailable'
        lines.append(f'  {load["op"]} at {load["address"]:08X}: {record["symbol"]}+0x{offset:X} = {value}')
    return lines
