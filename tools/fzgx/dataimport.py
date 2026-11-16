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
         'f64': (8, 'd'), 'double': (8, 'd'), 'int': (4, 'i'),
         'short': (2, 'h'), 'unsigned char': (1, 'B')}


def regions(p, module, section):
    layout = p._rel_layout(module)
    return list(layout.values()) if module == 'main' else [layout.get(section, (0, b''))]


REL_SECTION_INDEX = {'.text': 1, '.ctors': 2, '.dtors': 3, '.rodata': 4, '.data': 5}


def rel_relocation_sites(p, module, section):
    """Offsets in a REL section that the retail relocation tables patch at load time.

    A REL file stores every relocated word as zero, so "all zero" retail bytes are not
    padding when a relocation lands on them (lbl_1_data_5C6C's string pointer at 0x5CBC).
    The DOL has no relocation tables.
    """
    cache = p.__dict__.setdefault('_rel_reloc_sites', {})
    if (module, section) in cache:
        return cache[(module, section)]
    sites = set()
    if module != 'main' and section in REL_SECTION_INDEX:
        layout_cfg = (p.config_dir / 'config.yml').read_text().splitlines()
        obj = None
        for i, line in enumerate(layout_cfg):
            if line.strip() == f'name: {module}':
                obj = next(l.split(':', 1)[1].strip() for l in reversed(layout_cfg[:i]) if l.startswith('- object:'))
                break
        data = (ROOT / 'orig' / p.version / obj).read_bytes() if obj else b''
        if data:
            imp_off, imp_size = struct.unpack_from('>II', data, 0x28)
            want = REL_SECTION_INDEX[section]
            for i in range(imp_size // 8):
                _, pos = struct.unpack_from('>II', data, imp_off + 8 * i)
                current, offset = None, 0
                while True:
                    delta, kind, sec, _ = struct.unpack_from('>HBBI', data, pos)
                    pos += 8
                    if kind == 203:      # R_DOLPHIN_END
                        break
                    if kind == 202:      # R_DOLPHIN_SECTION
                        current, offset = sec, 0
                        continue
                    offset += delta
                    if kind != 201 and current == want:   # R_DOLPHIN_NOP only advances
                        sites.add(offset)
    cache[(module, section)] = sites
    return sites


def relocated_between(p, module, section, start, end):
    return any(start <= site < end for site in rel_relocation_sites(p, module, section))


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
        # U+3000 (ideographic space) is ordinary Japanese text but not str.isprintable().
        if any(not c.isprintable() and c not in '\r\n\t\u3000' for c in decoded):
            return False
    return True


def number(raw, kind):
    value = struct.unpack('>' + BASIC[kind][1], raw)[0]
    if kind in ('f32', 'float', 'f64', 'double'):
        if math.isinf(value):
            # MWCC folds this constant to the exact IEEE infinity (measured on GC/1.3.2).
            one = '1.0f' if len(raw) == 4 else '1.0'
            return f'({"-" if value < 0 else ""}{one} / 0.0{"f" if len(raw) == 4 else ""})'
        if math.isnan(value):
            raise ValueError('NaN floating bits need an explicit union storage layout')
        text = format(value, '.9g' if len(raw) == 4 else '.17g')
        if '.' not in text and 'e' not in text:
            text += '.0'
        return text + ('f' if len(raw) == 4 else '')
    if BASIC[kind][1].isupper():
        return f'0x{value:0{len(raw)*2}X}' + ('ULL' if len(raw) == 8 else 'U')
    return str(value) + ('LL' if len(raw) == 8 else '')


def record_initializer(data, fields, layouts, sizes, relocations=None, base=0, used=None):
    """Decode fields; symbolic relocations must land on complete pointer fields."""
    from .signatures import record_tag
    relocations = {} if relocations is None else relocations
    used = set() if used is None else used
    covered = bytearray(len(data)); values = []
    for name, source_type, offset, width, dims in fields:
        typ = re.sub(r'\b(?:const|volatile)\b', '', source_type).strip()
        count = math.prod(dims) if dims else 1
        end = offset + width * count
        if count <= 0 or end > len(data) or any(covered[offset:end]):
            raise ValueError('overlapping, flexible, or out-of-bounds record field')
        covered[offset:end] = b'\1' * (end - offset)
        def element(raw, at):
            if '*' in typ and width == 4:
                if at in relocations:
                    used.add(at)
                    return f'({source_type})({relocations[at]})'
                if not any(raw):
                    return '0'
                raise ValueError('nonzero pointer field needs a symbolic relocation')
            tag = record_tag(typ)
            if '*' not in typ and tag in layouts and sizes[tag][0] == width:
                return record_initializer(raw, layouts[tag], layouts, sizes, relocations, at, used)
            if any(at <= address < at + width for address in relocations):
                raise ValueError('relocation does not land on a recovered pointer field')
            if typ in BASIC and BASIC[typ][0] == width:
                return number(raw, typ)
            raise ValueError('record field needs a recovered scalar or record type')
        items = [element(data[i:i+width], base+i) for i in range(offset, end, width)]
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


def record_array(p, sym, spec, data, relocs):
    """A measured record layout recipe: the object is an array of one recovered record.

    `record` lists [type, name, *dims] fields in order; `stride` is the record size the
    code indexes by. Every relocation must land on a pointer field and every nonzero
    byte on a field, which record_initializer proves for each element.
    """
    fields, lines, offset, align = [], [], 0, 1
    for item in spec['record']:
        typ, name, dims = item[0], item[1], list(item[2:])
        if not name.isidentifier() or any(not isinstance(n, int) or n <= 0 for n in dims):
            raise ValueError('invalid record field')
        width = 4 if '*' in typ else BASIC[typ][0]
        offset = (offset + width - 1) & -width
        fields.append((name, typ, offset, width, dims))
        lines.append(f'    {typ}{"" if typ.endswith("*") else " "}{name}' + ''.join(f'[{n}]' for n in dims) + ';')
        offset += width * (math.prod(dims) if dims else 1)
        align = max(align, width)
    stride = (offset + align - 1) & -align
    if stride != spec['stride'] or sym.size % stride:
        raise ValueError('record layout does not tile the retail object')
    values, externs = {}, set()
    for r in relocs:
        target = p.find_symbol(r['symbol'], r['module'])
        if target.kind == 'function':
            externs.add(f'extern void {target.name}(void);')
            values[r['offset']] = target.name
            continue
        kind = {'string': 'char', 'float': 'f32', 'double': 'f64',
                '4byte': 'u32', '2byte': 'u16'}.get(target.attrs.get('data'), 'u8')
        externs.add(f'extern {kind} {target.name}[];')
        values[r['offset']] = target.name if kind == 'char' and not r['addend'] else \
            f'(u8 *)&{target.name}' + (f' + {r["addend"]}' if r['addend'] else '')
    used = set()
    items = [record_initializer(data[i:i + stride], fields, {}, {}, values, i, used)
             for i in range(0, sym.size, stride)]
    if used != set(values):
        raise ValueError('relocation is hidden in implicit record padding')
    # A char array already converts to `char *`; the generic cast adds nothing there.
    items = [re.sub(r'\(char \*\)\((\w+)\)', r'\1', item) for item in items]
    return 'struct {\n' + '\n'.join(lines) + '\n}', '{\n' + ',\n'.join(items) + '\n}', sorted(externs)


def declared_record_initializer(sym, declaration, data, relocations=None):
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
    used = set()
    values = [record_initializer(data[i:i+width], layouts[typ], layouts, sizes,
                                 relocations, i, used)
              for i in range(0, len(data), width)]
    if used != set(relocations or {}):
        raise ValueError('relocation is hidden in implicit record padding')
    for length in reversed(dims):
        values = ['{\n' + ',\n'.join(values[i:i+length]) + '\n}'
                  for i in range(0, len(values), length)]
    return declaration['declaration'], values[0], declaration['path'][8:]


def source_view(sym, decls, data):
    """The layout a code block declares an otherwise untyped object with.

    Only for relocation-free initialized data with no literal annotation and no scalar
    declaration (those paths type it already). A record whose members are all scalars
    or scalar arrays, or an array typedef of a scalar, is copied into the generated
    data header; the declaration must cover the retail extent exactly. Members may be
    records of scalars themselves (written as nested anonymous structs), and an array
    declaration (`SelD888 x[]`) is an array of that record tiling the retail extent.
    """
    from .sdkimport import integer_expression, masked
    from .signatures import record_layouts, record_tag
    basic = re.compile(r'(?:const\s+)?(?:' + '|'.join(BASIC) + r')\s+' + re.escape(sym.name) + r'\b.*')
    if sym.attrs.get('data') or not any(data) or is_text_pool(data) or any(
            basic.fullmatch(d['declaration']) for d in decls):
        return None
    def body(layouts, tag, depth=1, seen=()):
        """Member lines when every leaf is a scalar; nested records become anonymous structs."""
        lines = []
        for name, ftype, _, _, dims in layouts[tag]:
            typ = re.sub(r'\b(?:const|volatile)\b', '', ftype).strip()
            inner = record_tag(typ)
            if typ in BASIC:
                pass
            elif '*' not in typ and inner in layouts and inner not in seen:
                nested = body(layouts, inner, depth + 1, (*seen, inner))
                if nested is None:
                    return None
                typ = 'struct {\n' + nested + '    ' * depth + '}'
            else:
                return None
            lines.append('    ' * depth + f'{typ} {name}' + ''.join(f'[{n}]' for n in dims) + ';\n')
        return ''.join(lines)
    for d in decls:
        match = re.fullmatch(r'(?:const\s+)?((?:struct\s+)?\w+)\s+' + re.escape(sym.name) + r'\s*((?:\[[^\]]*\])?)',
                             d['declaration'])
        if not match or not d['path'].startswith('src/'):
            continue
        text = masked((ROOT / d['path']).read_text())
        # A large TU file can define the same tag in several blocks; use the one in scope.
        at = re.search(r'\bextern\s+(?:const\s+)?' + re.escape(match[1]) + r'\s+' + re.escape(sym.name)
                       + r'\s*(?:\[[^\]]*\])?\s*;', text)
        end = at.start() if at else len(text)
        typ = record_tag(match[1])
        try:
            layouts, sizes = record_layouts(text, end)
            if typ not in layouts and not match[2] and len(re.findall(
                    r'\bstruct\s+' + re.escape(typ) + r'\s*\{|\}\s*' + re.escape(typ) + r'\s*;', text)) == 1:
                # The only definition of the tag follows the extern (the block that copies the
                # table defines it): unambiguous, so the whole file's layout is the one in scope.
                layouts, sizes = record_layouts(text, len(text))
            if typ in layouts:
                fields = layouts[typ]
                width = sizes[typ][0]
                count = integer_expression(match[2][1:-1]) if match[2][1:-1].strip() else sym.size // width
                members = body(layouts, typ)
                if members is None or width * count != sym.size or (match[2] and count <= 0):
                    continue
                if not match[2]:
                    return f'struct {{\n{members}}} {sym.name}', record_initializer(data, fields, layouts, sizes)
                items = [record_initializer(data[i:i + width], fields, layouts, sizes)
                         for i in range(0, sym.size, width)]
                return (f'struct {{\n{members}}} {sym.name}[{count}]',
                        '{\n    ' + ',\n    '.join(item.replace('\n', '\n    ') for item in items) + '\n}')
            alias = None
            for alias in re.finditer(r'\btypedef\s+(\w+)\s+' + re.escape(typ) + r'\s*((?:\[[^\]]+\])+)\s*;', text[:end]):
                pass
            if alias is None or alias[1] not in BASIC:
                continue
            dims = [integer_expression(n) for n in re.findall(r'\[([^\]]+)\]', alias[2])]
            width = BASIC[alias[1]][0]
            if width * math.prod(dims) != sym.size:
                continue
            items = [number(data[i:i+width], alias[1]) for i in range(0, sym.size, width)]
            for length in reversed(dims):
                items = ['{' + ', '.join(items[i:i+length]) + '}' for i in range(0, len(items), length)]
            return f'{alias[1]} {sym.name}' + ''.join(f'[{n}]' for n in dims), items[0]
        except (ValueError, SyntaxError):
            continue
    return None


def generate(p, sym, recipe=None, opaque_bss=False, scalar_byte=False, header_bytes=False):
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
    target_includes = {}
    decl, init = None, None
    recovered = None
    if not recipe and not relocs and sym.section not in BSS:
        for declaration in decls:
            if declaration['path'].startswith('include/'):
                try:
                    recovered = declared_record_initializer(sym, declaration, data)
                except ValueError:
                    # An access-derived header record that does not reproduce the retail
                    # extent (globals.h's `u8 unk_0; u8 pad_0[N]` is N+1 bytes) does not type
                    # the object; the annotation or text-pool rules below still can.
                    extras.append(f'/* {declaration["declaration"].split()[0]} (header) does not reproduce '
                                  'the retail extent; the layout follows the retail data. */')
                    recovered = None
                if recovered:
                    break
    if recipe and 'record' in recipe:
        body, init, externs = record_array(p, sym, recipe, data, relocs)
        type_name = recipe['type']
        count = sym.size // recipe['stride']
        const = 'const ' if sym.section in ('.rodata', '.sdata2') else ''
        header = dict(path=f'{p.module_src_prefix(sym.module)}/data/{sym.name}.h',
                      text=f'#ifndef {type_name.upper()}_H\n#define {type_name.upper()}_H\n\n'
                      '#include "types.h"\n\n' + f'typedef {body} {type_name};\n'
                      f'extern {const}{type_name} {sym.name}[{count}];\n\n#endif\n')
        includes.append(header['path'])
        extras += externs
        decl, method = f'{type_name} {sym.name}[{count}]', 'record-array'
    elif recipe:
        if relocs:
            raise ValueError('string grid must be relocation-free data')
        kind, init = string_grid(data, recipe)
        decl, method = f'{kind} {sym.name}', 'string-grid'
        if sym.section in BSS:
            init, method = None, 'string-buffer'
    elif sym.section in BSS:
        # Headers carry recovered structs. Do not flatten them into byte arrays.
        known = next((d for d in decls if d['path'].startswith('include/')), None)
        if known is None and not opaque_bss:
            # Caller declarations can describe only a prefix of the retail object.
            # Accept a fixed-width scalar/array only when its full extent agrees;
            # otherwise retain opaque storage, including during regeneration.
            for d in decls:
                match = re.fullmatch(
                    r'(?:volatile\s+)?(' + '|'.join(k for k in BASIC if k not in ('short', 'unsigned char'))
                    + r')\s+\w+\s*((?:\[(?:0[xX][0-9a-fA-F]+|[0-9]+)\]\s*)*)', d['declaration'])
                if match:
                    dimensions = re.findall(r'\[([^\]]+)\]', match[2])
                    extent = BASIC[match[1]][0] * math.prod(
                        int(n, 16) if n.lower().startswith('0x') else int(n) for n in dimensions)
                    if extent == sym.size:
                        known = d
                        break
        if known:
            decl = known['declaration']
            if known['path'].startswith('include/'):
                includes.append(known['path'][8:])
            method = 'declared-bss'
        elif opaque_bss and scalar_byte and (sym.size == 1 or (sym.size == 2 and sym.addr % 2 == 0)):
            # MWCC 4-aligns every array, even u8[1]; a lone byte or halfword is a scalar.
            decl, method = f'{"u8" if sym.size == 1 else "u16"} {sym.name}', 'opaque-bss-scalar'
            extras.append('/* Storage extent is known; element/field types are not recovered. */')
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
        relocation_values = {}
        # A header that also declares this symbol (an access-derived view) conflicts with the
        # anonymous table below; that header's targets then fall back to address-only externs.
        own_headers = {d['path'][8:] for d in decls if d['path'].startswith('include/')}
        address_only = {}
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
                    # A source file's declaration can name a type only that file defines
                    # (bg_for.c's `State`); only types.h-level ones are portable.
                    if existing and not existing[0]['path'].startswith('include/') and not re.match(
                            r'(?:(?:const|volatile)\s+)*(?:struct|union|enum|void|BOOL|size_t|'
                            + '|'.join(BASIC) + r')\b', existing[0]['declaration']):
                        existing = []
                    kind = {'string': 'char', 'float': 'f32', 'double': 'f64',
                            '4byte': 'u32', '2byte': 'u16'}.get(target.attrs.get('data'), 'u8')
                    if existing:
                        declaration = existing[0]
                        if declaration['path'].startswith('include/'):
                            includes.append(declaration['path'][8:])
                            target_includes.setdefault(declaration['path'][8:], []).append(target.name)
                            if declaration['path'][8:] in own_headers:
                                address_only.setdefault(declaration['path'][8:], set()).add(
                                    f'extern {kind} {target.name}[];')
                        else:
                            externs.add('extern ' + declaration['declaration'] + ';')
                    else:
                        externs.add(f'extern {kind} {target.name}[];')
                    values.append(f'(u8 *)&{target.name}' + (f' + {r["addend"]}' if r['addend'] else ''))
                relocation_values[offset] = values[-1]
                offset += 4
            else:
                width = 4 if offset % 4 == 0 and offset + 4 <= sym.size else 1
                fields.append(f'    u{width*8} at_{offset:X};')
                values.append(number(data[offset:offset+width], f'u{width*8}'))
                offset += width
        extras += sorted(externs)
        recovered = None
        for d in decls:
            if d['path'].startswith('include/'):
                try:
                    recovered = declared_record_initializer(sym, d, data, relocation_values)
                except ValueError:
                    # Access-derived header layouts (padding plus the fields code touches)
                    # need not place every retail pointer; the anonymous table below does.
                    extras.append(f'/* {d["declaration"].split()[0]} (header) does not place every '
                                  'retail pointer; fields follow the relocations. */')
                    recovered = None
                if recovered:
                    break
        known = None
        if sym.size == 4 and len(relocs) == 1 and relocs[0]['offset'] == 0:
            for d in decls:
                if not d['path'].startswith('include/'):
                    continue
                match = re.fullmatch(r'((?:(?:const|volatile)\s+)*(?:(?:struct\s+)?\w+\s*\*+|[us]32))\s*' +
                                     re.escape(sym.name), d['declaration'])
                if match:
                    known = (d, match[1])
                    break
        # A header's string table (`const char *x[N]`, recovered from indexed word loads whose
        # every retail element is a relocation to a string object) is defined as declared.
        table = None
        targets = [p.find_symbol(r['symbol'], r['module']) for r in sorted(relocs, key=lambda r: r['offset'])]
        if len(relocs) * 4 == sym.size and not any(r['addend'] for r in relocs) and all(
                t.kind == 'object' and t.attrs.get('data') == 'string' for t in targets):
            from .sdkimport import integer_expression
            for d in decls:
                mt = re.fullmatch(r'(?:const\s+)?char\s*\*\s*' + re.escape(sym.name) + r'\s*\[\s*([^\]]*)\]',
                                  d['declaration'])
                if mt and d['path'].startswith('include/') and (
                        not mt[1] or integer_expression(mt[1]) * 4 == sym.size):
                    table = d
                    break
        if recovered:
            decl, init, include = recovered
            includes.append(include)
            method = 'declared-relocated-record'
        elif table:
            decl = table['declaration']
            init, method = '{\n    ' + ',\n    '.join(t.name for t in targets) + '\n}', 'declared-string-table'
            for path, fallback in sorted(address_only.items()):
                includes[:] = [h for h in includes if h != path]
                extras += sorted(fallback - externs)
        elif known:
            # A scalar symbolic address is not a one-field anonymous record.
            # Preserve the recovered pointee/address type and its public header.
            d, typ = known
            includes.append(d['path'][8:])
            decl, init = d['declaration'], f'({typ})({values[0]})'
            method = 'declared-relocation'
        else:
            decl = 'struct {\n' + '\n'.join(fields) + f'\n}} {sym.name}'
            init, method = '{\n    ' + ',\n    '.join(values) + '\n}', 'relocated-table'
            for path, fallback in sorted(address_only.items()):
                includes[:] = [h for h in includes if h != path]
                extras += sorted(fallback - externs)
    elif (view := source_view(sym, decls, data)) is not None:
        decl, init = view
        method = 'source-view'
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
            match = re.fullmatch(r'(?:const\s+)?(' + '|'.join(BASIC) + r')\s+' + re.escape(sym.name) + r'\s*((?:\[[^\]]*\]\s*)*)', d['declaration'])
            # Retry only (see import_data): a recovered header may declare a string as a byte
            # array (u8/s8), and a group that includes that header cannot define it as char.
            byte_view = (header_bytes and kind == 'char' and match and match[1] in ('u8', 's8')
                         and d['path'].startswith('include/'))
            if not match or (kind in ('f32', 'f64', 'char') and match[1] != kind and not byte_view):
                continue
            # dtk saw integer accesses and the bits are a NaN: a float extern is a view the
            # code casts back (`*(u32 *)&x`, replay lbl_13_rodata_C = 0xFFFFFFFF), not the type.
            if (kind in ('u32', 'u16') and match[1] in ('f32', 'float', 'f64', 'double')
                    and any(math.isnan(struct.unpack('>' + BASIC[match[1]][1], data[i:i+BASIC[match[1]][0]])[0])
                            for i in range(0, sym.size - BASIC[match[1]][0] + 1, BASIC[match[1]][0]))):
                continue
            width = BASIC[match[1]][0]
            try:
                # Every bound counts (s32 rates[2][4]); only the first may be left empty.
                dims = [b.strip() for b in re.findall(r'\[([^\]]*)\]', match[2])]
                inner = math.prod(integer_expression(b) for b in dims[1:])
                count = inner * (integer_expression(dims[0]) if dims and dims[0]
                                 else sym.size // width // inner if dims else 1)
            except (ValueError, SyntaxError, ZeroDivisionError):
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
                    math.isnan(struct.unpack('>' + BASIC[kind][1], data[i:i+width])[0])
                    for i in range(0, sym.size, width)):
                # A header declaration is a shared type that the union would contradict. A
                # declaration inside a code block is that block's own f32 view; the union's
                # `values` member is the same view, and `bits` keeps the non-float words.
                if known and known[0]['path'].startswith('include/'):
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
        type_body, declarator = decl.rsplit(' ', 1)
        # An array of a recovered record keeps its extent (source-view `SelD888 x[]`).
        dims = declarator[len(sym.name):]
        header = dict(path=f'{p.module_src_prefix(sym.module)}/data/{sym.name}.h',
                      text=f'#ifndef {type_name.upper()}_H\n#define {type_name.upper()}_H\n\n'
                      '#include "types.h"\n\n' + f'typedef {type_body} {type_name};\n'
                      f'extern {type_name} {sym.name}{dims};\n\n#endif\n')
        includes.append(header['path'])
        decl = f'{type_name} {sym.name}{dims}'
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
    record: dict = dict(module=sym.module, symbol=sym.name, section=sym.section,
                  address=sym.addr, size=sym.size, align=align, method=method,
                  declarations=decls, references=reference_index(p, sym.module).get(sym.name, []),
                  sha256=hashlib.sha256(data).hexdigest(), relocations=relocs)
    record['definition'] = decl
    # Headers included only to declare relocation targets. When every such target is
    # defined in the same group, the header is dropped there: a module header's view of
    # a group member (e.g. a 5-byte string seen as u32) conflicts with its definition.
    target_includes = {h: t for h, t in target_includes.items() if includes.count(h) == len(t)}
    if target_includes:
        record['target_includes'] = target_includes
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
    flags = {2} if record['section'] == '.rodata' else {3}
    if record['section'] in ('.sdata2', '.sbss2'):
        # MWCC emits its small constant sections writable in every spelling (measured on
        # GC/1.3.2: const, __declspec and #pragma section all give flags WA), while dtk marks
        # the retail objects read-only. The name places them; the 16 hashes are the gate.
        flags = {2, 3}
    if sec['flags'] not in flags:
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
        pending = list(data_groups(p, ready, preserve_units=regenerate))
        rescued = set()
        byte_retried = set()
        def rescue():
            # An unowned BSS run boxed in by owned splits would be dropped by DTK
            # with its symbols; import it too, retaining recovered header types.
            # Only objects without a header declaration use opaque storage.
            added = False
            for run in isolated_runs(p, records):
                key = tuple(sym.name for sym in run)
                if key in rescued:
                    continue
                rescued.add(key)
                try:
                    if any(sym.scope != 'global' for sym in run):
                        continue
                    # A one-byte run compiles at alignment 1, so the compiler check below
                    # would pass an odd start that dtk cannot carry as a split.
                    # Leave those to isolate_guard (4-aligned rescues are measured to link).
                    if run[0].addr % 4:
                        continue
                    retry = []
                    for sym in run:
                        src, r = generate(p, sym, opaque_bss=True, scalar_byte=True)
                        retry.append((r, src))
                except (ValueError, KeyError):
                    continue
                names_in_run = set(key)
                skipped[:] = [x for x in skipped if x['symbol'].split(':')[-1] not in names_in_run]
                pending.append(retry)
                added = True
            return added
        while True:
            while pending:
                group = pending.pop(0)
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
                    for base, raw in retail_regions:
                        if raw and base <= first['address'] < base + len(raw):
                            if end > base + len(raw):
                                raise ValueError('object extends past the retail section end')
                            # An unaligned section end is the split end; never round past it.
                            padded_end = min(padded_end, base + len(raw))
                    # NOBITS sections have no retail bytes to compare against: a BSS
                    # group that nothing follows is the section tail, and rounding it
                    # up would extend the split past the section (dtk rejects that).
                    # dtk also ends a DOL section at its last symbol (main .data: 0x8015B919, not
                    # the header's 0x8015B920), so the same tail rule holds there.
                    if (first['section'] in BSS or first['module'] == 'main') and not any(
                            s.section == first['section'] and s.addr >= end
                            for s in p.symbols(first['module']).values()):
                        padded_end = end
                    owner = p.unit_of(p.find_symbol(first['symbol'], first['module']))
                    # Zero padding up to an existing split that follows closely (alignment of
                    # that split's unit) has no symbol of its own; own it, or no split would.
                    following = [sp.start for sp in p.splits(first['module'])
                                 if sp.section == first['section'] and sp.unit != owner and sp.start >= padded_end]
                    if following:
                        gap_end = min(following)
                        if (0 < gap_end - padded_end < 8
                                and not any(sm.section == first['section'] and end <= sm.addr < gap_end
                                            for sm in p.symbols(first['module']).values())
                                and (first['section'] in BSS or (any(
                                    base <= end and gap_end <= base + len(raw) and not any(raw[end-base:gap_end-base])
                                    for base, raw in retail_regions)
                                    and not relocated_between(p, first['module'], first['section'], end, gap_end)))):
                            padded_end = gap_end
                    if padded_end != end:
                        if any(s.section == first['section'] and end <= s.addr < padded_end
                               for s in p.symbols(first['module']).values()):
                            raise ValueError('trailing split needs its adjacent data symbol')
                        if any(s.unit != owner and s.section == first['section'] and s.start < padded_end and end < s.end
                               for s in p.splits(first['module'])):
                            raise ValueError('trailing padding belongs to another split')
                        if first['section'] not in BSS and (not any(
                                base <= end <= padded_end <= base + len(raw) and not any(raw[end-base:padded_end-base])
                                for base, raw in retail_regions)
                                or relocated_between(p, first['module'], first['section'], end, padded_end)):
                            raise ValueError('trailing padding is not zero or exceeds the section')
                    source_name = f'{p.module_src_prefix(first["module"])}/data/{first["symbol"]}.c'
                    # MWCC emits unreferenced BSS definitions in reverse order.
                    # Data-only units have no code accesses to establish an order;
                    # reverse their definitions while retaining the retail layout
                    # for validation and split ownership.
                    definitions = reversed(group) if first['section'] in BSS else group
                    # A member's alignment is the largest power of two dividing its address (up
                    # to the section default), so a later member can ask for more than the group
                    # start has (lbl_800909C0 at a 32-aligned address after an 8-aligned string)
                    # and the section would outgrow the start. Cap it at the alignment the start
                    # address allows (its lowest set bit, not the first member's own attribute:
                    # an explicit align:4 on an 8-aligned start must not strip a later member's
                    # padding); groups that already compiled are unchanged.
                    # validate() below still checks every member's offset against retail.
                    cap = (first['address'] & -first['address']) or 1 << 31   # REL offset 0: any
                    definitions = [(r, source.replace(f'aligned({r["align"]}))', f'aligned({cap}))')
                                    if r['align'] > cap else source) for r, source in definitions]
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
                    # A header included only to declare relocation targets cannot be included
                    # when it declares a group member under another type (car.h's u32 view of
                    # a 5-byte string); targets outside the group keep address-only declarations.
                    members = {r['symbol'] for r, _ in group}
                    known = declarations(p)
                    def bare(decl):
                        return re.sub(r'\s+', ' ', re.sub(r'\bconst\s+', '', decl)).strip()
                    for h in sorted({h for r, _ in group for h in r.get('target_includes', {})}):
                        line = f'#include "{h}"'
                        users = [r for r, src in group if re.search('^' + re.escape(line) + '$', src, re.M)]
                        if not all(h in r.get('target_includes', {}) for r in users):
                            continue
                        targets = {t for r in users for t in r['target_includes'][h]}
                        if any(d['path'] == 'include/' + h and bare(d['declaration']) != bare(r['definition'])
                               for r, _ in group for d in known.get(r['symbol'], [])):
                            includes = [i for i in includes if i != line]
                            for t in sorted(targets - members):
                                target = p.find_symbol(t, first['module'])
                                kind = {'string': 'char', 'float': 'f32', 'double': 'f64',
                                        '4byte': 'u32', '2byte': 'u16'}.get(target.attrs.get('data'), 'u8')
                                forward.append(f'extern {kind} {t}[];')
                    # A string member that a still-included header views as u8/s8[N] takes that
                    # element type (bitmap.h's u8 lbl_1_data_1A390[0x1A]); a string initializer is
                    # valid for any character array. Groups that compiled before are unaffected.
                    from .sdkimport import integer_expression
                    views = {}
                    for r, _ in group:
                        if r['method'] not in ('string', 'string-pool') or not r['definition'].startswith('char '):
                            continue
                        for d in known.get(r['symbol'], []):
                            view = re.fullmatch(r'[us]8\s+' + re.escape(r['symbol']) + r'\s*\[([^\]]+)\]', d['declaration'])
                            if (view and f'#include "{d["path"][8:]}"' in includes
                                    and integer_expression(view[1]) == r['size']):
                                views[r['symbol']] = d['declaration']
                                text = text.replace(r['definition'], d['declaration'])
                                forward = [f'extern {d["declaration"]};' if f == f'extern {r["definition"]};' else f
                                           for f in forward]
                                break
                    text = re.sub(r'^#include[^\n]+\n', '', text, flags=re.M)
                    text = re.sub(r'^/\* Generated by fzgx data-import;[^\n]+\n', '', text, flags=re.M)
                    text = ('/* Generated by fzgx data-import; provenance in state/dataimports/. */\n'
                            + '\n'.join(includes) + '\n\n' + '\n'.join(forward) + '\n\n' + text)
                    # A header included for another member can declare a string as u8/s8 of
                    # the same extent; define it with that element type instead of
                    # redeclaring it as char (customize lbl_3_data_35B0 in editor.h).
                    from .sdkimport import integer_expression
                    retyped = {}
                    for r, _ in group:
                        if r['method'] not in ('string', 'string-pool'):
                            continue
                        for d in r['declarations']:
                            view = re.fullmatch(r'(?:const\s+)?([us]8)\s+' + re.escape(r['symbol']) +
                                                r'\s*\[([^\]]+)\]', d['declaration'])
                            if (view and f'#include "{d["path"][8:]}"' in includes
                                    and integer_expression(view[2]) == r['size']):
                                text = re.sub(r'\bchar(\s+' + re.escape(r['symbol']) + r'\s*\[)',
                                              view[1] + r'\1', text)
                                retyped[id(r)] = re.sub(r'\bchar\b', view[1], r['definition'], count=1)
                                break
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
                    for r, _ in group:
                        # Both string-view passes (main_rel's `views`, sel/customize's `retyped`) may apply;
                        # the first one to match wins.
                        r['definition'] = views.get(r['symbol'], retyped.get(id(r), r['definition']))
                    records.extend(r for r, _ in group)
                except ValueError as e:
                    # A contiguous run can span retail objects whose headers conflict, or start
                    # off the compiler's section alignment because its predecessor is owned
                    # elsewhere. Retry it as independent chunks that each begin at an aligned
                    # member: every chunk is still compiled and validated on its own.
                    # Cut only where the previous member's word-rounded end meets the cut:
                    # a padding gap between chunks would belong to no split.
                    # Never cut inside an existing unit's range either: its split is one piece.
                    def _owner(rec):
                        return p.unit_of(p.find_symbol(rec['symbol'], rec['module']))
                    cuts = [i for i, (r, _) in enumerate(group) if i and r['address'] % 8 == 0
                            and ((group[i - 1][0]['address'] + group[i - 1][0]['size'] + 3) & -4) == r['address']
                            and (_owner(r) is None or _owner(r) != _owner(group[i - 1][0]))]
                    retryable = {r['symbol'] for r, _ in group if r['method'] == 'declared-bss'
                                 and not any(d['path'].startswith('include/') for d in r['declarations'])}
                    if not cuts and not regenerate and retryable:
                        # Source-only scalar declarations may have an incorrect extent.
                        # Recovered header types must pass the real layout checks; never
                        # erase them, or retry an unchanged header definition forever.
                        # MWCC 4-aligns every array, even u8[1]: a lone byte or aligned halfword
                        # stays a scalar, or it would move its neighbours (title lbl_8_bss_554/555).
                        retry = []
                        for r, src in group:
                            if r['symbol'] in retryable:
                                src, r = generate(p, p.find_symbol(r['symbol'], r['module']), opaque_bss=True,
                                                  scalar_byte=True)
                            retry.append((r, src))
                        pending.insert(0, retry)
                        continue
                    if (not regenerate and 'redeclared' in str(e)
                            and tuple(r['symbol'] for r, _ in group) not in byte_retried
                            and any(r['method'] in ('string', 'string-pool') for r, _ in group)):
                        # A string whose recovered header declares it u8[] conflicts with that
                        # header when a neighbour's type includes it (winning lbl_15_data_154 next
                        # to lbl_15_data_90): retry the strings with the header's byte type.
                        byte_retried.add(tuple(r['symbol'] for r, _ in group))
                        retry = []
                        for r, src in group:
                            if r['method'] in ('string', 'string-pool'):
                                src, r = generate(p, p.find_symbol(r['symbol'], r['module']),
                                                  header_bytes=True)
                            retry.append((r, src))
                        pending.insert(0, retry)
                        continue
                    if cuts and not regenerate:
                        bounds = [0] + cuts + [len(group)]
                        pending[:0] = [group[a:b] for a, b in zip(bounds, bounds[1:])]
                        continue
                    skipped.extend(dict(symbol=r['symbol'], reason=str(e)) for r, _ in group)
                if not pending and not regenerate:
                    rescue()
            if regenerate:
                break
            # One withdrawal at a time: the run it exposes gets a rescue attempt before
            # the guard withdraws the next chunk, or one bad run cascades over a section.
            before = len(records)
            records = isolate_guard(p, records, skipped, steps=1)
            # An existing data unit is re-imported whole or not at all: if a retry or
            # the isolation guard dropped any of its members, leave the unit as it is.
            while True:
                kept = {(r['module'], r['symbol']) for r in records}
                partial = set()
                for r in records:
                    owner = p.unit_of(p.find_symbol(r['symbol'], r['module']))
                    unit = p.unit_record(owner) if owner else None
                    if unit and unit.get('data') and any((r['module'], name) not in kept for name in unit['symbols']):
                        partial.add(owner)
                if not partial:
                    break
                # Withdraw whole chunks: a chunk's source is generated from its first member.
                starts = {(r['module'], r.get('unit_start')) for r in records
                          if p.unit_of(p.find_symbol(r['symbol'], r['module'])) in partial}
                drop = [r for r in records if (r['module'], r.get('unit_start')) in starts]
                records = [r for r in records if r not in drop]
                skipped.extend(dict(symbol=r['symbol'], reason='existing data unit only partly importable')
                               for r in drop)
                records = isolate_guard(p, records, skipped, steps=1)
            # Withdrawals expose new boxed-in runs; give each one rescue attempt.
            if not rescue() and len(records) == before:
                break
        applied = bool(apply and records and not (regenerate and skipped))
        if applied:
            _install(p, records, scratch)
    return dict(imported=applied, objects=len(records), bytes=sum(r['size'] for r in records),
                records=records, skipped=skipped)


def isolated_runs(p, records):
    """Maximal runs of unowned BSS objects with owned objects on both sides."""
    new = {r['symbol'] for r in records}
    runs = []
    for module, section in sorted({(r['module'], r['section']) for r in records if r['section'] in BSS}):
        syms = sorted((s for s in p.symbols(module).values()
                       if s.section == section and s.kind == 'object' and s.size),
                      key=lambda s: s.addr)
        owned = [s.name in new or p.unit_of(s) is not None for s in syms]
        i = 0
        while i < len(syms):
            if owned[i]:
                i += 1
                continue
            j = i
            while j < len(syms) and not owned[j]:
                j += 1
            if i and j < len(syms):
                runs.append(syms[i:j])
            i = j
    return runs


def isolate_guard(p, records, skipped, steps=None):
    """Never leave a run of unowned objects boxed in by owned splits.

    Outside BSS the same situation is a hard dtk error ("Unsplit data in .rodata from
    X to next split"), e.g. a skipped non-finite word between two imported chunks.

    DTK drops a zero-only auto range that is isolated between splits, and its
    symbols with it, so an unowned BSS run whose neighbours both become owned
    vanishes from the link (measured: lbl_3_bss_20844..2084C, lbl_3_bss_A23D8).
    Withdraw the newly imported chunk on one side instead; repeat until no run
    is isolated.
    """
    changed = True
    while changed and steps != 0:
        changed = False
        new = {r['symbol']: r for r in records}
        for module, section in sorted({(r['module'], r['section']) for r in records}):
            syms = sorted((s for s in p.symbols(module).values()
                           if s.section == section and s.kind == 'object' and s.size),
                          key=lambda s: s.addr)
            owned = [s.name in new or p.unit_of(s) is not None for s in syms]
            i = 0
            while i < len(syms):
                if owned[i]:
                    i += 1
                    continue
                j = i
                while j < len(syms) and not owned[j]:
                    j += 1
                # syms[i:j] is a maximal unowned run
                # Measured: dtk can only carry an unowned run as an auto object when it
                # starts on the section alignment. Withdrawing the chunk on the left moves
                # the run's start back to that chunk's aligned start, which ends the cascade.
                # A boxed-in BSS run vanishes even from an aligned start (measured:
                # lbl_1_bss_8E518..8E51E between two new chunks).
                # The DOL is stricter: an unowned run between splits fails the split even from
                # an aligned start (measured: __DVDVersion/autoInvalidation, .sdata 0x801A6478,
                # "Unsplit data in .sdata ... to next split"). A REL's initialized run is carried
                # as an auto object from any word-aligned start (measured 2026-11-11: main_rel
                # jumptable_1_data_3439C at 4 mod 8 after a data unit; 3,383 objects imported
                # around such runs, all 16 hashes OK). Withdrawing the left group there used to
                # strand whole contiguous tables (24 KB behind that one jump table).
                # The same holds for the DOL's .data and .rodata (measured: 277 objects around
                # VIGetTvFormat's @724 jump table); only its small-data sections stay strict.
                if i and j < len(syms) and (section in BSS or (module == 'main' and section not in ('.data', '.rodata'))):
                    victim = new.get(syms[i - 1].name) or new.get(syms[j].name)
                    if victim is not None:
                        start = victim['unit_start']
                        drop = [r for r in records if r['module'] == module and r.get('unit_start') == start]
                        records = [r for r in records if r not in drop]
                        skipped.extend(dict(symbol=r['symbol'],
                                            reason=f'would isolate unowned {syms[i].name} between splits')
                                       for r in drop)
                        changed = True
                        if steps is not None:
                            steps -= 1
                        break
                i = j
            if changed:
                break
    return records


def boundary_closure(p, names):
    """DTK elides zero-only auto ranges; keep their symbols in generated data.

    Expanding into an existing generated unit includes all of its members, so
    extending a pool cannot orphan previously recovered globals or source.
    """
    selected = {(s.module, s.name): s for name in names if (s := p.resolve(name))}
    pending = list(selected.values())
    boundaries = {}
    for module in {s.module for s in pending}:
        starts, ends, padded = {}, {}, {}
        for s in p.symbols(module).values():
            if s.kind == 'object' and s.size and s.section in SECTIONS - BSS:
                starts.setdefault((s.section, s.addr), []).append(s)
                ends.setdefault((s.section, s.end), []).append(s)
                if s.end % 4:
                    padded.setdefault((s.section, (s.end + 3) & -4), []).append(s)
        boundaries[module] = starts, ends, padded
    while pending:
        s = pending.pop()
        if s.section in BSS:
            continue
        starts, ends, padded = boundaries[s.module]
        neighbors = ends.get((s.section, s.addr), []) + starts.get((s.section, s.end), [])
        # A data unit's split ends on the word boundary after its last member, so an object
        # at that boundary (often 4 mod 8) can only start a group by growing that unit.
        neighbors += [o for o in padded.get((s.section, s.addr), [])
                      if p.unit_of(o) and (p.unit_record(p.unit_of(o)) or {}).get('data')]
        owner = p.unit_of(s)
        if owner and (unit := p.unit_record(owner)) and unit.get('data'):
            neighbors += [p.find_symbol(name, s.module) for name in unit['symbols']]
        for other in neighbors:
            if (other.module, other.name) in selected:
                continue
            unit = p.unit_record(p.unit_of(other)) if p.unit_of(other) else None
            zero = (other.size <= 8 and not any(p.bytes_at(other.module, other.name) or b'\1')
                    and not relocated_between(p, other.module, other.section, other.addr, other.end))
            if zero or (unit and unit.get('data')):
                selected[(other.module, other.name)] = other
                pending.append(other)
    # A BSS member that starts where an existing data unit ends cannot begin its own
    # unit off the section alignment; grow that unit to include it instead.
    grown = True
    while grown:
        grown = False
        for s in list(selected.values()):
            if s.section not in BSS:
                continue
            for other in p.symbols(s.module).values():
                if other.section != s.section or not other.size or other.end != s.addr:
                    continue
                owner = p.unit_of(other)
                unit = p.unit_record(owner) if owner else None
                if not (unit and unit.get('data')):
                    continue
                for name in unit['symbols']:
                    member = p.find_symbol(name, s.module)
                    if member and (member.module, member.name) not in selected:
                        selected[(member.module, member.name)] = member
                        grown = True
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
                               for base, data in regions(p, r['module'], r['section'])) and not \
                        relocated_between(p, r['module'], r['section'], end, r['address'])
                old = p.unit_of(p.find_symbol(prev['symbol'], prev['module']))
                new = p.unit_of(p.find_symbol(r['symbol'], r['module']))
                # The padding between them may belong to either member's own unit,
                # never to a third split.
                if any(s.section == r['section'] and s.start < r['address'] and end < s.end
                       and s.unit not in (old, new)
                       for s in p.splits(r['module'])):
                    join = False
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
                saved[f'{r["module"]}:{r["symbol"]}'] = {k: v for k, v in r.items() if k != 'target_includes'}
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
                # mwld prints one "section ignored" warning per object; keep the real error.
                log = re.sub(r'### mwldeppc\.exe Linker Warning:\n#\s+Section \'[^\']*\' is unknown\. Section ignored\.\n',
                             '', cp.stdout + cp.stderr)
                raise ValueError(log[-6000:])
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
