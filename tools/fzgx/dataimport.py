"""Generate owned C data, prove its object layout, then transfer retail splits.

Data has no function claim or completion dependency. Retail ELF relocations are
part of the oracle: equal zero-filled pointer slots alone are not a match.
"""
from __future__ import annotations

import hashlib
from bisect import bisect_left
import json
import math
import re
import struct
import sys
from pathlib import Path

from . import oracle
from .carve import _section_default_align, order_labels_after_functions
from .poolfix import Elf
from .project import ROOT, STATE_DIR, Project, Symbol

BSS = {'.bss', '.sbss', '.sbss2'}
SECTIONS = BSS | {'.data', '.rodata', '.sdata', '.sdata2'}
BASIC = {'u8': (1, 'B'), 's8': (1, 'b'), 'char': (1, 'B'),
         'u16': (2, 'H'), 's16': (2, 'h'), 'u32': (4, 'I'), 's32': (4, 'i'),
         'u64': (8, 'Q'), 's64': (8, 'q'), 'f32': (4, 'f'), 'float': (4, 'f'),
         'f64': (8, 'd'), 'double': (8, 'd'), 'int': (4, 'i')}


def regions(p, module, section):
    layout = p._rel_layout(module)
    return list(layout.values()) if module == 'main' else [layout.get(section, (0, b''))]


def declarations(p):
    if hasattr(p, '_data_declarations'):
        return p._data_declarations
    out = {}
    for path in sorted((ROOT / 'include').rglob('*.h')) + sorted((ROOT / 'src').rglob('*.c')):
        if '/data/' in str(path):
            continue
        for match in re.finditer(r'^\s*extern\s+([^;{}\n]+);', path.read_text(), re.M):
            body = match[1].strip()
            # Parentheses identify function declarations or function pointers.
            if '(' in body:
                continue
            name = re.search(r'\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*$', body)
            if name:
                out.setdefault(name[1], []).append(dict(declaration=body, path=p.rel(path)))
    p._data_declarations = out
    return out


def reference_index(p, module):
    cache = p.__dict__.setdefault('_data_references', {})
    if module not in cache:
        refs = {}
        for mod in p.modules:
            for fn in p.function_asm(mod).values():
                for name in fn.refs:
                    refs.setdefault(name, []).append(fn.symbol.name if mod == module else f'{mod}:{fn.symbol.name}')
        cache[module] = refs
    return cache[module]


def objects(p, module):
    cache = p.__dict__.setdefault('_data_elfs', {})
    if module not in cache:
        index = {}
        for asm in p._asm_files(module):
            relative = asm.relative_to(p.module_build_dir(module) / 'asm')
            path = (p.module_build_dir(module) / 'obj' / relative).with_suffix('.o')
            elf = Elf(path.read_bytes())
            elf._data_symbols = elf.symbols()
            for sym in elf._data_symbols:
                if sym['shndx'] and (sym['info'] & 15) == 1:
                    index[sym['name']] = (elf, sym)
        cache[module] = index
    return cache[module]


def resolve_target(p, module, name):
    sym = p.find_symbol(name, module) or p.find_symbol(name)
    if sym is None and (m := re.fullmatch(r'(.+)_([0-9A-F]{8})', name)):
        sym = p.find_symbol(m[1], module)
        if sym and sym.addr != int(m[2], 16):
            sym = None
    return sym


def pool_objects(p, module, section, address, extent):
    """Include DTK's anonymous objects when proving an entire initialized pool.

    A `pad_` label can contain a pointer table, despite its name. Its retail
    bytes and relocations require the same proof as named objects.
    """
    result = [s for s in p.symbols(module).values() if s.kind == 'object' and
              s.section == section and s.addr < address + extent and s.end > address]
    named = list(result)
    for elf, own in objects(p, module).values():
        match = re.fullmatch(r'(?:gap|pad)_\d+_([0-9A-Fa-f]{8})_\w+', own['name'])
        if not match or elf.sections[own['shndx']]['name'] != section or not own['size']:
            continue
        start = int(match[1], 16)
        end = start + own['size']
        if (start >= address + extent or end <= address or
                any(s.addr < end and s.end > start for s in named)):
            continue
        result.append(Symbol(own['name'], module, section, start, 'object', own['size'], 'local', {}))
    return result


def payload(p, sym):
    index = objects(p, sym.module)
    pair = index.get(sym.name) or index.get(f'{sym.name}_{sym.addr:08X}')
    if not pair:
        raise ValueError(f'{sym.name}: no active retail data object')
    elf, es = pair
    sec = elf.sections[es['shndx']]
    if es['size'] != sym.size or sec['name'] != sym.section:
        raise ValueError(f'{sym.name}: retail symbol size/section disagrees with config')
    data = bytes(sym.size) if sym.section in BSS else bytes(
        elf.data[sec['offset'] + es['value']:sec['offset'] + es['value'] + es['size']])
    relocs = []
    symbols = elf._data_symbols
    if not hasattr(elf, '_data_relocations'):
        elf._data_relocations = {}
        for rsec in elf.sections:
            if rsec['type'] == 4:
                entries = sorted(struct.unpack_from('>IIi', elf.data, pos)
                                 for pos in range(rsec['offset'], rsec['offset'] + rsec['size'], 12))
                elf._data_relocations[rsec['info']] = ([r[0] for r in entries], entries)
    offsets, entries = elf._data_relocations.get(es['shndx'], ([], []))
    for offset, info, addend in entries[bisect_left(offsets, es['value']):bisect_left(offsets, es['value'] + sym.size)]:
        target = resolve_target(p, sym.module, symbols[info >> 8]['name'])
        if target is None:
            raise ValueError(f'{sym.name}: unresolved relocation {symbols[info >> 8]["name"]}')
        relocs.append(dict(offset=offset - es['value'], kind=info & 255,
                           module=target.module, symbol=target.name, addend=addend))
    return data, sorted(relocs, key=lambda r: r['offset'])


def c_string(data):
    # Fixed-width octal escapes cannot absorb a following hex digit; escaping
    # high bytes also avoids changing the retail encoding through -multibyte.
    tokens = []
    for b in data:
        tokens.append({34: '\\"', 92: '\\\\', 10: '\\n', 13: '\\r', 9: '\\t',
                       63: '\\077'}.get(b, chr(b) if 32 <= b < 127 else f'\\{b:03o}'))
    lines, line = [], ''
    for token in tokens:
        if len(line) + len(token) > 96:
            lines.append('"' + line + '"'); line = ''
        line += token
    lines.append('"' + line + '"')
    return '\n    '.join(lines)


def is_text_pool(data):
    if not data.endswith(b'\0'):
        return False
    strings = [s for s in data.split(b'\0') if s]
    if not strings or any(len(s) < 3 for s in strings):
        return False
    for value in strings:
        try:
            decoded = value.decode('shift_jis')
        except UnicodeDecodeError:
            return False
        if any(not c.isprintable() and c not in '\r\n\t' for c in decoded):
            return False
    return True


def number(raw, kind):
    value = struct.unpack('>' + BASIC[kind][1], raw)[0]
    if kind in ('f32', 'float', 'f64', 'double'):
        if not math.isfinite(value):
            raise ValueError('non-finite floating bits need an explicit union storage layout')
        text = format(value, '.9g' if len(raw) == 4 else '.17g')
        if '.' not in text and 'e' not in text:
            text += '.0'
        return text + ('f' if len(raw) == 4 else '')
    if BASIC[kind][1].isupper():
        return f'0x{value:0{len(raw)*2}X}' + ('ULL' if len(raw) == 8 else 'U')
    return str(value) + ('LL' if len(raw) == 8 else '')


def record_initializer(data, fields, layouts, sizes):
    """Decode recovered record fields without inventing values for padding/pointers."""
    from .signatures import record_tag
    covered = bytearray(len(data)); values = []
    for name, typ, offset, width, dims in fields:
        typ = re.sub(r'\b(?:const|volatile)\b', '', typ).strip()
        count = math.prod(dims) if dims else 1
        end = offset + width * count
        if count <= 0 or end > len(data) or any(covered[offset:end]):
            raise ValueError('overlapping, flexible, or out-of-bounds record field')
        covered[offset:end] = b'\1' * (end - offset)
        def element(raw):
            if typ in BASIC and BASIC[typ][0] == width:
                return number(raw, typ)
            tag = record_tag(typ)
            if '*' not in typ and tag in layouts and sizes[tag][0] == width:
                return record_initializer(raw, layouts[tag], layouts, sizes)
            raise ValueError('record field needs a recovered scalar or record type')
        items = [element(data[i:i+width]) for i in range(offset, end, width)]
        for length in reversed(dims):
            items = ['{' + ', '.join(items[i:i+length]) + '}' for i in range(0, len(items), length)]
        values.append(items[0])
    if any(value and not covered[i] for i, value in enumerate(data)):
        raise ValueError('nonzero record padding needs an explicit recovered field')
    return '{\n    ' + ',\n    '.join(values) + '\n}'


def string_grid(data, spec):
    """A measured layout recipe; every cell must prove terminator and padding."""
    fields, values, offset = [], [], 0
    for region in spec['regions']:
        name, shape = region['field'], region['shape']
        if not name.isidentifier() or not shape or any(n <= 0 for n in shape):
            raise ValueError('invalid string grid shape')
        length = math.prod(shape)
        raw = data[offset:offset + length]
        if len(raw) != length:
            raise ValueError('string grid exceeds symbol')
        width = shape[-1]
        cells = []
        for i in range(0, length, width):
            cell = raw[i:i + width]
            end = cell.find(b'\0')
            if end < 0 or any(cell[end:]):
                raise ValueError(f'string cell at {offset+i:#x} is not zero padded')
            cells.append(c_string(cell[:end]))
        def nest(dims):
            if len(dims) == 1:
                return cells.pop(0)
            return '{\n' + ',\n'.join(nest(dims[1:]) for _ in range(dims[0])) + '\n}'
        fields.append(f'    char {name}' + ''.join(f'[{n}]' for n in shape) + ';')
        values.append(nest(shape))
        offset += length
    if offset != len(data):
        raise ValueError('string grid does not cover entire symbol')
    return 'struct {\n' + '\n'.join(fields) + '\n}', '{\n' + ',\n'.join(values) + '\n}'


def declared_record_initializer(sym, declaration, data):
    """Keep a recovered header record instead of replacing it with scalar bytes."""
    from .sdkimport import integer_expression, masked
    from .signatures import record_layouts, record_tag
    match = re.fullmatch(r'((?:const\s+)?(?:struct\s+)?\w+)\s+' + re.escape(sym.name) +
                         r'\s*((?:\[[^\]]+\])*)', declaration['declaration'])
    if not match:
        return None
    typ = record_tag(re.sub(r'\bconst\s+', '', match[1]))
    # Layout parsing is deliberately conservative. MWCC compilation below still
    # proves the emitted definition's layout and bytes against the retail object.
    code = masked((ROOT / declaration['path']).read_text())
    layouts, sizes = record_layouts(code, len(code))
    if typ not in layouts:
        return None
    dims = [integer_expression(dim) for dim in re.findall(r'\[([^\]]+)\]', match[2])]
    width = sizes[typ][0]
    if any(dim <= 0 for dim in dims) or width * math.prod(dims) != sym.size:
        raise ValueError('recovered header record extent disagrees with retail size')
    values = [record_initializer(data[i:i+width], layouts[typ], layouts, sizes)
              for i in range(0, len(data), width)]
    for length in reversed(dims):
        values = ['{\n' + ',\n'.join(values[i:i+length]) + '\n}'
                  for i in range(0, len(values), length)]
    return declaration['declaration'], values[0], declaration['path'][8:]


def generate(p, sym, recipe=None):
    if sym.kind != 'object' or sym.section not in SECTIONS or not sym.size or not sym.name.isidentifier():
        raise ValueError('not a supported named data object')
    if sym.name.startswith('jumptable_'):
        raise ValueError('jump tables belong with their reconstructed function')
    data, relocs = payload(p, sym)
    for r in relocs:
        target = p.find_symbol(r['symbol'], r['module'])
        if r['kind'] != 1 or r['offset'] % 4 or r['offset'] + 4 > sym.size:
            raise ValueError('only aligned ADDR32 data relocations can be expressed as C pointers')
        if target.kind not in ('object', 'function') or (target.kind == 'function' and r['addend']):
            raise ValueError('code interior/jump table relocations must move with the function')
        if target.scope == 'local':
            raise ValueError(f'{target.name}: local relocation target requires promotion with its owner')
    decls = declarations(p).get(sym.name, [])
    includes = ['types.h']
    extras, method, header = [], '', None
    decl, init = None, None
    recovered = None
    if not recipe and not relocs and sym.section not in BSS:
        for declaration in decls:
            if declaration['path'].startswith('include/'):
                recovered = declared_record_initializer(sym, declaration, data)
                if recovered:
                    break
    if recipe:
        if relocs:
            raise ValueError('string grid must be relocation-free data')
        kind, init = string_grid(data, recipe)
        decl, method = f'{kind} {sym.name}', 'string-grid'
        if sym.section in BSS:
            init, method = None, 'string-buffer'
    elif sym.section in BSS:
        # Headers carry recovered structs. Do not flatten them into byte arrays.
        known = next((d for d in decls if d['path'].startswith('include/')), None)
        if known is None:
            known = next((d for d in decls if re.fullmatch(
                r'(?:volatile\s+)?(?:' + '|'.join(BASIC) + r')\s+\w+\s*(?:\[[0-9a-fA-FxX]+\])*', d['declaration'])), None)
        if known:
            decl = known['declaration']
            if known['path'].startswith('include/'):
                includes.append(known['path'][8:])
            method = 'declared-bss'
        else:
            decl, method = f'u8 {sym.name}[{sym.size}]', 'opaque-bss'
            extras.append('/* Storage extent is known; element/field types are not recovered. */')
    elif recovered:
        decl, init, include = recovered
        includes.append(include)
        method = 'declared-record'
    elif relocs:
        by_offset = {r['offset']: r for r in relocs}
        fields, values, externs = [], [], set()
        offset = 0
        while offset < sym.size:
            r = by_offset.get(offset)
            if r:
                target = p.find_symbol(r['symbol'], r['module'])
                if target.kind == 'function':
                    fields.append(f'    void (*at_{offset:X})(void);')
                    externs.add(f'extern void {target.name}(void);')
                    values.append(target.name)
                else:
                    fields.append(f'    u8 *at_{offset:X};')
                    existing = declarations(p).get(target.name, [])
                    if existing:
                        declaration = existing[0]
                        if declaration['path'].startswith('include/'):
                            includes.append(declaration['path'][8:])
                        else:
                            externs.add('extern ' + declaration['declaration'] + ';')
                    else:
                        kind = {'string': 'char', 'float': 'f32', 'double': 'f64',
                                '4byte': 'u32', '2byte': 'u16'}.get(target.attrs.get('data'), 'u8')
                        externs.add(f'extern {kind} {target.name}[];')
                    values.append(f'(u8 *)&{target.name}' + (f' + {r["addend"]}' if r['addend'] else ''))
                offset += 4
            else:
                width = 4 if offset % 4 == 0 and offset + 4 <= sym.size else 1
                fields.append(f'    u{width*8} at_{offset:X};')
                values.append(number(data[offset:offset+width], f'u{width*8}'))
                offset += width
        extras += sorted(externs)
        decl = 'struct {\n' + '\n'.join(fields) + f'\n}} {sym.name}'
        init, method = '{\n    ' + ',\n    '.join(values) + '\n}', 'relocated-table'
    else:
        kind = {'float': 'f32', 'double': 'f64', 'string': 'char',
                '4byte': 'u32', '2byte': 'u16', 'byte': 'u8'}.get(sym.attrs.get('data'))
        text_pool = not decls and kind is None and is_text_pool(data)
        zero_data = not decls and kind is None and not any(data)
        if text_pool:
            kind = 'char'
        elif zero_data:
            kind = 'u8'
        known = None
        from .sdkimport import integer_expression
        for d in decls:
            match = re.fullmatch(r'(?:const\s+)?(' + '|'.join(BASIC) + r')\s+' + re.escape(sym.name) + r'\s*(\[[^\]]*\])?', d['declaration'])
            if not match or (kind in ('f32', 'f64', 'char') and match[1] != kind):
                continue
            width = BASIC[match[1]][0]
            bound = match[2][1:-1].strip() if match[2] else None
            try:
                count = 1
                if match[2]:
                    count = integer_expression(bound) if bound else sym.size // width
            except (ValueError, SyntaxError):
                continue
            # Inferred externs may cover only a prefix or an oversized view,
            # neither of which defines this retail object's measured extent.
            if count * width == sym.size:
                known = (d, match)
                break
        if not known and kind is None and is_text_pool(data):
            # A prefix-only extern must not hide a measured, terminated string
            # pool when regenerating its already accepted complete definition.
            kind, text_pool = 'char', True
        if known:
            d, match = known
            kind, decl = match[1], d['declaration']
        elif kind:
            width = BASIC[kind][0]
            decl = f'{kind} {sym.name}' + (f'[{sym.size // width}]' if sym.size != width or kind == 'char' else '')
        else:
            raise ValueError('initialized layout needs a type, literal annotation, or string-grid recipe')
        width = BASIC[kind][0]
        if sym.size % width:
            raise ValueError('element width does not divide retail size')
        if kind in ('char', 'u8', 's8') and '[' in decl and (sym.attrs.get('data') == 'string' or text_pool):
            if not data.endswith(b'\0'):
                raise ValueError('string is not terminated')
            init, method = c_string(data[:-1]), 'string-pool' if text_pool else 'string'
        else:
            if kind in ('f32', 'f64', 'float', 'double') and any(
                    not math.isfinite(struct.unpack('>' + BASIC[kind][1], data[i:i+width])[0])
                    for i in range(0, sym.size, width)):
                if known:
                    raise ValueError('non-finite data with an existing scalar declaration needs a recovered union layout')
                count = sym.size // width
                decl = f'union {{\n    u{width*8} bits[{count}];\n    {kind} values[{count}];\n}} {sym.name}'
                values = [number(data[i:i+width], f'u{width*8}') for i in range(0, sym.size, width)]
                init = '{{\n    ' + ', '.join(values) + '\n}}'
                extras.append('/* Preserve non-finite payloads and signed zero without compiler canonicalization. */')
                method = 'float-bits'
            else:
                values = [number(data[i:i+width], kind) for i in range(0, sym.size, width)]
                init = '{\n    ' + ', '.join(values) + '\n}' if '[' in decl else values[0]
                method = 'float-pool' if kind in ('f32', 'f64', 'float', 'double') else 'typed-data'
                if zero_data:
                    method = 'zero-data'
    if decl.startswith(('struct {', 'union {')):
        type_name = (recipe or {}).get('type', 'Data_' + sym.name)
        if not type_name.isidentifier():
            raise ValueError('invalid recovered type name')
        type_body = decl.rsplit(' ', 1)[0]
        header = dict(path=f'{p.module_src_prefix(sym.module)}/data/{sym.name}.h',
                      text=f'#ifndef {type_name.upper()}_H\n#define {type_name.upper()}_H\n\n'
                      '#include "types.h"\n\n' + f'typedef {type_body} {type_name};\n'
                      f'extern {type_name} {sym.name};\n\n#endif\n')
        includes.append(header['path'])
        decl = f'{type_name} {sym.name}'
    if sym.section in ('.rodata', '.sdata2') and not decl.startswith('const '):
        decl = 'const ' + decl
        if header:
            header['text'] = header['text'].replace(f'extern {type_name} ', f'extern const {type_name} ')
    align = int(sym.attrs.get('align', _section_default_align(p, sym.module, sym.section)))
    while align > 1 and sym.addr % align:
        align //= 2
    # Named sections defeat small-data selection and zero-initializer migration.
    prefix = '\n'.join(f'#include "{h}"' for h in dict.fromkeys(includes))
    prefix += '\n\n' + '\n'.join(extras) + '\n'
    if init is not None:
        prefix += '#pragma explicit_zero_data on\n'
    section = {'.bss': '.data', '.sbss': '.sdata', '.sbss2': '.sdata2'}.get(sym.section, sym.section)
    storage = f'__declspec(section "{section}") '
    source = ('/* Generated by fzgx data-import; recipe/provenance in state/dataimports/. */\n'
              + prefix + storage + decl + f' __attribute__((aligned({align})))'
              + (' = ' + init if init is not None else '') + ';\n'
              + ('#pragma explicit_zero_data reset\n' if init is not None else ''))
    record = dict(module=sym.module, symbol=sym.name, section=sym.section,
                  address=sym.addr, size=sym.size, align=align, method=method,
                  declarations=decls, references=reference_index(p, sym.module).get(sym.name, []),
                  sha256=hashlib.sha256(data).hexdigest(), relocations=relocs)
    record['definition'] = decl
    if header:
        record['header'] = header
    if recipe:
        record['recipe'] = recipe
    return source, record


def validate(p, record, obj):
    elf = Elf(obj.read_bytes())
    owned = [s for s in elf.symbols() if s['name'] == record['symbol'] and s['shndx']]
    if len(owned) != 1:
        raise ValueError('compiler did not define exactly one target symbol')
    es = owned[0]; sec = elf.sections[es['shndx']]
    flags = 2 if record['section'] in ('.rodata', '.sdata2', '.sbss2') else 3
    if sec['flags'] != flags:
        raise ValueError('compiler changed the data section permissions')
    start = record.get('unit_start', record['address'])
    size = record.get('section_size', record.get('unit_size', record['size']))
    align = record.get('unit_align', record['align'])
    if (es['size'] != record['size'] or es['value'] != record['address'] - start or sec['name'] != record['section']
            or sec['size'] != size or sec['addralign'] != align):
        raise ValueError(f'compiler layout differs: {es["size"]} bytes at {es["value"]}, '
                         f'{sec["name"]} size {sec["size"]} align {sec["addralign"]}; expected {record["size"]} at {record["address"]-start}, section {size} align {align}')
    if any(s['size'] and s['flags'] & 2 and s['index'] != es['shndx'] for s in elf.sections):
        raise ValueError('compiler emitted additional allocated sections')
    if record['section'] in BSS:
        if sec['type'] != 8:
            raise ValueError('BSS must be NOBITS storage')
        return
    actual = bytearray(elf.data[sec['offset'] + es['value']:sec['offset'] + es['value'] + es['size']])
    target, expected = payload(p, p.find_symbol(record['symbol'], record['module']))
    target = bytearray(target)
    found = []
    symbols = elf.symbols()
    for rsec in elf.sections:
        if rsec['type'] != 4 or rsec['info'] != sec['index']:
            continue
        for pos in range(rsec['offset'], rsec['offset'] + rsec['size'], 12):
            offset, info, addend = struct.unpack_from('>IIi', elf.data, pos)
            if not es['value'] <= offset < es['value'] + es['size']:
                continue
            target_es = symbols[info >> 8]
            target_sym = resolve_target(p, record['module'], target_es['name'])
            if target_sym:
                binding = (target_sym.module, target_sym.section, target_sym.addr + addend)
            elif target_es['shndx'] == sec['index']:
                binding = (record['module'], sec['name'], start + target_es['value'] + addend)
            else:
                raise ValueError(f'unresolved compiler relocation {target_es["name"]}')
            found.append((offset - es['value'], info & 255, *binding))
    bindings = [(r['offset'], r['kind'], r['module'],
                 p.find_symbol(r['symbol'], r['module']).section,
                 p.find_symbol(r['symbol'], r['module']).addr + r['addend']) for r in expected]
    if sorted(found) != sorted(bindings):
        raise ValueError(f'relocation bindings differ: {found} != {expected}')
    for r in expected:
        actual[r['offset']:r['offset']+4] = target[r['offset']:r['offset']+4] = bytes(4)
    if actual != target:
        offset = next(i for i, (a, b) in enumerate(zip(actual, target)) if a != b)
        raise ValueError(f'initialized bytes differ at {offset:#x}')


def import_data(p, names, apply=False, recipes=None, regenerate=False):
    scratch = STATE_DIR / 'dataimport'
    scratch.mkdir(parents=True, exist_ok=True)
    records, skipped, ready = [], [], []
    with oracle.build_lock():
        if not regenerate:
            names = boundary_closure(p, names)
        for name in dict.fromkeys(names):
            sym = p.resolve(name)
            try:
                if sym is None:
                    raise ValueError('unknown symbol')
                owner = p.unit_of(sym)
                owned_data = owner and (p.unit_record(owner) or {}).get('data')
                if owner and not owned_data:
                    raise ValueError('range already has an owner')
                if sym.scope != 'global':
                    raise ValueError('local data must be promoted with its referring sources')
                if any(s.unit != owner and s.section == sym.section and s.start < sym.end and sym.addr < s.end for s in p.splits(sym.module)):
                    raise ValueError('range overlaps an existing split')
                source, record = generate(p, sym, (recipes or {}).get(name, (recipes or {}).get(sym.name)))
                if header := record.get('header'):
                    # The probe prepends this directory to MWCC's include path.
                    path = scratch / header['path']
                    path.parent.mkdir(parents=True, exist_ok=True)
                    path.write_text(header['text'])
                ready.append((record, source))
            except (ValueError, KeyError) as e:
                skipped.append(dict(symbol=name, reason=str(e)))
        for group in data_groups(p, ready, preserve_units=regenerate):
            try:
                first, last = group[0][0], group[-1][0]
                end = last['address'] + last['size']
                # DTK starts residual auto data on a word boundary. The linker
                # supplies trailing zeros when aligning that next input; adding
                # a C padding array would itself align and insert extra bytes.
                padded_end = (end + 3) & -4
                retail_regions = regions(p, first['module'], first['section'])
                if any(base + len(raw) == end for base, raw in retail_regions):
                    padded_end = end
                owner = p.unit_of(p.find_symbol(first['symbol'], first['module']))
                if padded_end != end:
                    if any(s.section == first['section'] and end <= s.addr < padded_end
                           for s in p.symbols(first['module']).values()):
                        raise ValueError('trailing split needs its adjacent data symbol')
                    if any(s.unit != owner and s.section == first['section'] and s.start < padded_end and end < s.end
                           for s in p.splits(first['module'])):
                        raise ValueError('trailing padding belongs to another split')
                    if first['section'] not in BSS and not any(
                            base <= end <= padded_end <= base + len(raw) and not any(raw[end-base:padded_end-base])
                            for base, raw in retail_regions):
                        raise ValueError('trailing padding is not zero or exceeds the section')
                source_name = f'{p.module_src_prefix(first["module"])}/data/{first["symbol"]}.c'
                # MWCC emits unreferenced BSS definitions in reverse order.
                # Data-only units have no code accesses to establish an order;
                # reverse their definitions while retaining the retail layout
                # for validation and split ownership.
                definitions = reversed(group) if first['section'] in BSS else group
                text = '\n'.join(source for _, source in definitions)
                # The group now owns some relocation targets. Their real
                # declarations replace the address-only external fallback.
                for r, _ in group:
                    text = re.sub(r'^extern [^;\n]*\b' + re.escape(r['symbol']) + r'\s*(?:\[[^\]]*\])*;', '', text, flags=re.M)
                forward = []
                for r, _ in group:
                    if header := r.get('header'):
                        forward.append(f'#include "{header["path"]}"')
                    else:
                        forward.append('extern ' + r['definition'] + ';')
                includes = list(dict.fromkeys(re.findall(r'^#include[^\n]+', text, re.M)))
                text = re.sub(r'^#include[^\n]+\n', '', text, flags=re.M)
                text = re.sub(r'^/\* Generated by fzgx data-import;[^\n]+\n', '', text, flags=re.M)
                text = ('/* Generated by fzgx data-import; provenance in state/dataimports/. */\n'
                        + '\n'.join(includes) + '\n\n' + '\n'.join(forward) + '\n\n' + text)
                path = scratch / f'{first["module"]}__{first["symbol"]}.c'
                path.write_text(text)
                obj = path.with_suffix('.o')
                cp = oracle.compile_source(p, first['module'], path, obj, include_dirs=[scratch])
                if cp.returncode:
                    raise ValueError((cp.stdout + cp.stderr)[-1800:])
                section = Elf(obj.read_bytes()).section(first['section'])
                if section is None or first['address'] % section['addralign']:
                    raise ValueError('group must begin at the compiler section alignment')
                for r, _ in group:
                    r.update(source=source_name, unit_start=first['address'],
                             unit_size=padded_end - first['address'],
                             section_size=end - first['address'],
                             unit_align=section['addralign'])
                    validate(p, r, obj)
                validate_padding(group, obj)
                records.extend(r for r, _ in group)
            except ValueError as e:
                skipped.extend(dict(symbol=r['symbol'], reason=str(e)) for r, _ in group)
        applied = bool(apply and records and not (regenerate and skipped))
        if applied:
            _install(p, records, scratch)
    return dict(imported=applied, objects=len(records), bytes=sum(r['size'] for r in records),
                records=records, skipped=skipped)


def boundary_closure(p, names):
    """DTK elides zero-only auto ranges; keep their symbols in generated data.

    Expanding into an existing generated unit includes all of its members, so
    extending a pool cannot orphan previously recovered globals or source.
    """
    selected = {(s.module, s.name): s for name in names if (s := p.resolve(name))}
    pending = list(selected.values())
    boundaries = {}
    for module in {s.module for s in pending}:
        starts, ends = {}, {}
        for s in p.symbols(module).values():
            if s.kind == 'object' and s.size and s.section in SECTIONS - BSS:
                starts.setdefault((s.section, s.addr), []).append(s)
                ends.setdefault((s.section, s.end), []).append(s)
        boundaries[module] = starts, ends
    while pending:
        s = pending.pop()
        if s.section in BSS:
            continue
        starts, ends = boundaries[s.module]
        neighbors = ends.get((s.section, s.addr), []) + starts.get((s.section, s.end), [])
        owner = p.unit_of(s)
        if owner and (unit := p.unit_record(owner)) and unit.get('data'):
            neighbors += [p.find_symbol(name, s.module) for name in unit['symbols']]
        for other in neighbors:
            if (other.module, other.name) in selected:
                continue
            unit = p.unit_record(p.unit_of(other)) if p.unit_of(other) else None
            zero = other.size <= 8 and not any(p.bytes_at(other.module, other.name) or b'\1')
            if zero or (unit and unit.get('data')):
                selected[(other.module, other.name)] = other
                pending.append(other)
    # Keep invalid user names in the error report.
    return [f'{m}:{n}' for m, n in selected] + [n for n in names if p.resolve(n) is None]


def data_groups(p, ready, preserve_units=False):
    """Keep contiguous pool members together, including natural zero padding."""
    groups = []
    for item in sorted(ready, key=lambda item: (item[0]['module'], item[0]['section'], item[0]['address'])):
        r = item[0]
        group = groups[-1] if groups else []
        prev = group[-1][0] if group else None
        join = False
        if prev and (prev['module'], prev['section']) == (r['module'], r['section']):
            end = prev['address'] + prev['size']
            aligned = (end + r['align'] - 1) & -r['align']
            if aligned == r['address'] and not any(
                    s.section == r['section'] and end <= s.addr < r['address']
                    for s in p.symbols(r['module']).values()):
                if r['section'] in BSS:
                    join = True
                else:
                    join = any(base <= end <= r['address'] <= base + len(data)
                               and not any(data[end-base:r['address']-base])
                               for base, data in regions(p, r['module'], r['section']))
                if any(s.section == r['section'] and s.start < r['address'] and end < s.end
                       and s.unit != p.unit_of(p.find_symbol(r['symbol'], r['module']))
                       for s in p.splits(r['module'])):
                    join = False
                old = p.unit_of(p.find_symbol(prev['symbol'], prev['module']))
                new = p.unit_of(p.find_symbol(r['symbol'], r['module']))
                if preserve_units and old != new and (old or new):
                    join = False
        if join:
            group.append(item)
        else:
            groups.append([item])
    return groups


def validate_padding(group, obj):
    first = group[0][0]
    if first['section'] in BSS:
        return
    elf = Elf(obj.read_bytes()); sec = elf.section(first['section'])
    for (prev, _), (nxt, _) in zip(group, group[1:]):
        start = prev['address'] + prev['size'] - first['address']
        end = nxt['address'] - first['address']
        if any(elf.data[sec['offset'] + start:sec['offset'] + end]):
            raise ValueError('compiler changed inter-object zero padding')
    last = group[-1][0]
    start = last['address'] + last['size'] - first['address']
    if any(elf.data[sec['offset'] + start:sec['offset'] + sec['size']]):
        raise ValueError('compiler changed trailing zero padding')


def _install(p, records, scratch):
    provenance = ROOT / 'state/dataimports' / f'{p.version}.json'
    paths = {p.units_path, provenance}
    touched = {p.unit_of(p.find_symbol(r['symbol'], r['module'])) for r in records}
    touched.discard(None)
    old_units = [u for u in p.load_units() if u['source'] in touched]
    for unit in old_units:
        members = {r['symbol'] for r in records if r['module'] == unit['module']}
        if not unit.get('data') or not set(unit['symbols']) <= members:
            raise ValueError('data integration must preserve every member of each existing unit')
        paths.add(ROOT / 'src' / unit['source'])
    for r in records:
        paths.update((p.module_config_dir(r['module']) / 'splits.txt',
                      p.module_config_dir(r['module']) / 'symbols.txt',
                      ROOT / 'src' / r['source']))
        if header := r.get('header'):
            paths.add(ROOT / 'include' / header['path'])
    before = {path: path.read_bytes() if path.exists() else None for path in paths}
    try:
        with oracle.build_lock('units.lock'):
            from .collapse import _splits_without
            units = [u for u in p.load_units() if u['source'] not in touched]
            for module in {u['module'] for u in old_units}:
                path = p.module_config_dir(module) / 'splits.txt'
                path.write_text(_splits_without(path.read_text(), [u['source'] for u in old_units if u['module'] == module]))
            saved = json.loads(provenance.read_text()) if provenance.exists() else {}
            groups = {}
            for r in records:
                groups.setdefault(r['source'], []).append(r)
                if header := r.get('header'):
                    path = ROOT / 'include' / header['path']
                    path.parent.mkdir(parents=True, exist_ok=True)
                    path.write_text(header['text'])
                saved[f'{r["module"]}:{r["symbol"]}'] = r
            for group in groups.values():
                r = group[0]
                path = ROOT / 'src' / r['source']; path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text((scratch / f'{r["module"]}__{r["symbol"]}.c').read_text())
                sp = p.module_config_dir(r['module']) / 'splits.txt'
                with sp.open('a') as stream:
                    stream.write(f'\n{r["source"]}:\n\t{r["section"]:<11} start:0x{r["unit_start"]:08X} '
                                 f'end:0x{r["unit_start"]+r["unit_size"]:08X} align:{r["unit_align"]}\n')
                symbols = p.module_config_dir(r['module']) / 'symbols.txt'
                if r['module'] == 'main':
                    text = symbols.read_text()
                    for member in group:
                        text = re.sub(r'^(' + re.escape(member['symbol']) + r' = [^\n]*)$',
                                      lambda m: m[0] if 'force_active' in m[0] else m[0] + ' force_active', text, flags=re.M)
                    symbols.write_text(text)
                order_labels_after_functions(symbols)
                units.append(dict(module=r['module'], source=r['source'], symbols=[member['symbol'] for member in group],
                                  status='matching', data=True, mw_version=None, extra_cflags=[]))
            for unit in old_units:
                if unit['source'] not in groups:
                    (ROOT / 'src' / unit['source']).unlink()
            p.save_units(units)
            provenance.parent.mkdir(parents=True, exist_ok=True)
            provenance.write_text(json.dumps(saved, indent=2, sort_keys=True) + '\n')
        for command in ([sys.executable, 'configure.py', '--version', p.version], ['ninja'],
                        ['build/tools/dtk', 'shasum', '-q', '-c', f'config/{p.version}/build.sha1']):
            cp = oracle.run(command, timeout=1800)
            if cp.returncode:
                raise ValueError((cp.stdout + cp.stderr)[-6000:])
        # Prove the actual Ninja objects too, including BSS layout (no file bytes).
        fresh = Project(p.version)
        for r in records:
            unit = fresh.objdiff_unit_name(r['module'], r['source'])
            validate(fresh, r, oracle._base_object(fresh, unit))
        for group in groups.values():
            r = group[0]
            unit = fresh.objdiff_unit_name(r['module'], r['source'])
            validate_padding([(item, '') for item in group], oracle._base_object(fresh, unit))
    except BaseException:
        for path, data in before.items():
            if data is None:
                path.unlink(missing_ok=True)
            else:
                path.write_bytes(data)
        configured = oracle.configure(p)
        rebuilt = oracle.relink(p) if configured.returncode == 0 else configured
        if rebuilt.returncode:
            print('Data import rolled back, but rebuilding the previous tree failed:\n'
                  + (rebuilt.stdout + rebuilt.stderr)[-3000:], file=sys.stderr)
        raise


def inventory(p, module=None):
    rows = []
    known = declarations(p)
    for mod in [module] if module else p.modules:
        refs = reference_index(p, mod)
        for s in p.symbols(mod).values():
            if s.kind == 'object' and s.section in SECTIONS and s.size and not p.unit_of(s):
                rows.append(dict(symbol=s.name, module=mod, section=s.section, bytes=s.size,
                                 declarations=known.get(s.name, []), references=len(refs.get(s.name, [])),
                                 annotation=s.attrs.get('data')))
    return sorted(rows, key=lambda r: -r['bytes'])
