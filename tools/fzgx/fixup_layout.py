"""Retail translation units define their file-scope objects and string literals in one place,
and MWCC then addresses every object of a section off one base register: object addresses are
materialized (`addi rX, rBase, off`, even at offset 0) whenever a pointer value is needed, and
only an object's offset 0 is addressed base-relative. A per-function unit that declares the
cluster as one extern struct can never reproduce that shape. This family defines the retail
objects in the unit, in retail order under MWCC's file-scope layout rules (scalars at natural
alignment, arrays 4-aligned, `.bss` objects emitted in first-access order, string literals in
first-use order), with primers in `.fzgxpool` that fix the emission order. Field offsets and
sizes come from an MWCC probe compile of the body's own declarations. The oracle binds the
anonymous section bases (`...bss.N`, `...data.N`) to the retail symbols; the private copies are
dropped at integration. Names a module header declares with another layout are defined under
the `fzgx_obj_` alias, which the BSS base binding accepts."""
from __future__ import annotations

import hashlib
import re
import struct
from pathlib import Path

from . import oracle, poolfix
from .project import ROOT, STATE_DIR


INCLUDE_TEXT = None
SCALAR = {'u8': 1, 's8': 1, 'char': 1, 'u16': 2, 's16': 2, 'u32': 4, 's32': 4, 'int': 4, 'f32': 4, 'float': 4, 'f64': 8, 'double': 8, 'u64': 8, 's64': 8, 'void': 1}


def include_text():
    global INCLUDE_TEXT
    if INCLUDE_TEXT is None:
        INCLUDE_TEXT = "\n".join(p.read_text(errors='replace') for p in (ROOT / 'include').rglob('*.h'))
    return INCLUDE_TEXT


class Gap:
    def __init__(self, name, addr, end, section):
        self.name, self.addr, self.end, self.size, self.section, self.kind = name, addr, end, end - addr, section, 'object'


def initialized_base_order(p, symbol, body, obj, check):
    """Prime an SDK native .data base before its existing BSS layout primer.

    Object definitions and their order are unchanged. MWCC numbers section
    bases by earlier functions' first accesses, independently of the BSS object
    ordering that sdk_layout already establishes. The oracle still has to prove
    the initialized bytes, BSS layout and every rewritten relocation.
    """
    from .sdkimport import declarations

    if not obj or not check.ok or 'fzgx_initialized_base_prime' in body:
        return []
    primer = re.search(r'#pragma\s+section\s+code_type\s+"\.fzgxpool"\s*'
                       r'static\s+void\s+sdk_layout_\w*bss\w*\s*\(', body)
    if not primer:
        return []
    elf = poolfix.Elf(Path(obj).read_bytes())
    own = {s['name']: s for s in elf.symbols()}
    selected = []
    for piece in declarations(body):
        if piece.kind != 'object' or len(piece.names) != 1:
            continue
        name = next(iter(piece.names))
        native = own.get(name)
        if (not native or native['shndx'] >= len(elf.sections)
                or elf.sections[native['shndx']]['name'] != '.data'
                or not re.match(r'static\s+', piece.text) or '=' not in piece.text):
            continue
        start = body.find(piece.text)
        if start < 0 or body.find(piece.text, start + 1) >= 0:
            return []
        selected.append((start, start + len(piece.text), name, piece.text))
    # Three objects make the compiler use the native section base rather than
    # separate direct symbol addresses. Never invent another object to do so.
    if len(selected) < 3:
        return []
    selected.sort()
    at = primer.start()
    if any(start < at < end for start, end, _, _ in selected):
        return []
    block = '\n'.join(text for _, _, _, text in selected) + '\n'
    block += ('#pragma section code_type ".fzgxpool"\n'
              'static void fzgx_initialized_base_prime(void) {\n'
              '    const void *volatile sink; /* fzgx-allow: S2 discarded section-base layout primer */\n')
    block += ''.join(f'    sink = &{name};\n' for _, _, name, _ in selected)
    block += '}\n#pragma section code_type ".text"\n'
    edits = [(start, end, '') for start, end, _, _ in selected]
    edits.append((at, at, block))
    text = body
    for start, end, replacement in sorted(edits, reverse=True):
        text = text[:start] + replacement + text[end:]
    return [('native initialized section base before BSS', text)]


def legacy_pool_primer_sections(body, obj):
    """Keep uncalled legacy layout primers out of the function's linked text."""
    if not obj:
        return []
    from .sdkimport import masked
    elf = poolfix.Elf(Path(obj).read_bytes())
    code = masked(body)
    edits = []
    for helper in elf.symbols():
        name = helper['name']
        if (helper['info'] & 15 != 2 or not helper['size']
                or not 0 < helper['shndx'] < len(elf.sections)
                or elf.sections[helper['shndx']]['name'] == '.fzgxpool'
                or not re.fullmatch(r'fzgx_pool_primer_[0-9a-fA-F]+|fzgx_bss_layout|primer', name)):
            continue
        # A callable helper is program behavior, not a discarded layout primer.
        if len(re.findall(r'\b' + re.escape(name) + r'\b', code)) != 1:
            continue
        definition = re.search(r'(?m)^[ \t]*static\s+void\s+' + re.escape(name)
                               + r'\s*\(\s*void\s*\)\s*\{', code)
        if definition:
            edits.append(definition.start())
    text = body
    for at in sorted(edits, reverse=True):
        text = text[:at] + '__declspec(section ".fzgxpool") ' + text[at:]
    if edits and not re.search(r'#pragma\s+section\s+code_type\s+"\.fzgxpool"', code):
        # MWCC requires the section to be declared before __declspec uses it.
        at = min(edits)
        text = (text[:at] + '#pragma section code_type ".fzgxpool"\n'
                '#pragma section code_type ".text"\n' + text[at:])
    return [('place legacy literal-pool primers in discarded section', text)] if edits else []


def bss_member_bindings(p, symbol, body, obj, check):
    """Name generated layout pieces using their measured retail subobjects."""
    if not obj or not check.ok:
        return []
    elf = poolfix.Elf(Path(obj).read_bytes())
    section = elf.section('.bss')
    if section is None:
        return []
    own = {s['name']: s for s in elf.symbols()}
    module = p.resolve(symbol).module
    retail = p.symbols(module)
    origins = set()
    for private, target, _ in check._pool_pairs:
        anchor = own.get(private)
        name, offset = poolfix.binding_target(target)
        known = retail.get(name)
        if (private.startswith('...bss') and anchor and known
                and anchor['shndx'] == section['index'] and known.section == '.bss'):
            origins.add(known.addr + offset - anchor['value'])
    if len(origins) != 1:
        return []
    origin = origins.pop()
    objects = [s for s in retail.values() if s.kind == 'object' and s.section == '.bss']
    bound = {private for private, _, _ in check._pool_pairs}
    names = {}
    for name, s in own.items():
        if (s['shndx'] != section['index'] or not s['size'] or s['info'] & 15 != 1
                or name in bound or name.startswith('fzgx_pool_')):
            continue
        generated = re.fullmatch(r'(.+)_(?:gap|fill)_[0-9A-F]+(?:_fill_[0-9A-F]+)?', name)
        padding = generated or re.fullmatch(r'(?:sdk_)?gap____bss_\d+_[0-9A-Fa-f]+', name)
        member = re.fullmatch(r'(.+)_([0-9A-F]+)', name)
        synthetic = name.startswith('lbl_') and name not in retail
        # Generated section members can have global binding and arbitrary C
        # names (for example sprite_8_344). Their measured extent, rather than
        # linkage or spelling, determines whether a retail subobject owns them.
        native = s['info'] & 15 == 1 and name not in retail
        if not generated and not synthetic and not native and not (member and member[1] in retail and name not in retail):
            continue
        address = origin + s['value']
        owner = next((o for o in objects if o.addr <= address and address + s['size'] <= o.end), None)
        if owner:
            alias = owner.name + f'__fzgx_offset_{address-owner.addr:X}'
            if alias != name:
                names[name] = alias
        elif padding and 'gap' in name:
            # The linker drops private padding only after all relocations to
            # its section have gone; live uses still prevent externalization.
            names[name] = 'fzgx_pool_' + name
    if not names:
        return []
    text = re.sub(r'\b\w+\b', lambda m: names.get(m[0], m[0]), body)
    return [('canonical BSS subobjects and private layout padding', text)]


def split_bss_primer_arrays(p, symbol, body, obj, check):
    """Partition primer-only arrays into individually bounded retail BSS objects."""
    if not obj or not check.ok:
        return []
    from .fixup_evidence import _function_span
    from .sdkimport import masked
    elf = poolfix.Elf(Path(obj).read_bytes())
    section = elf.section('.bss')
    if not section or section['type'] != 8:
        return []
    own = {s['name']: s for s in elf.symbols()}
    retail = p.symbols(p.resolve(symbol).module)
    origins = set()
    for private, target, _ in check._pool_pairs:
        anchor = own.get(private)
        name, offset = poolfix.binding_target(target)
        known = retail.get(name)
        if (private.startswith('...bss') and anchor and known and known.section == '.bss'
                and anchor['shndx'] == section['index']):
            origins.add(known.addr + offset - anchor['value'])
    if len(origins) != 1:
        return []
    origin = origins.pop()
    objects = sorted((s for s in retail.values() if s.section == '.bss' and s.kind == 'object'
                      and s.size), key=lambda s: s.addr)
    code = masked(body)
    primers = [span for s in own.values() if s['info'] & 15 == 2 and s['size']
               and 0 < s['shndx'] < len(elf.sections)
               and elf.sections[s['shndx']]['name'] == '.fzgxpool'
               and (span := _function_span(code, s['name']))]
    edits = []
    for name, s in own.items():
        if s['shndx'] != section['index'] or s['info'] & 15 != 1 or not s['size']:
            continue
        decl = re.search(r'(?m)^(static\s+)?(u8|s8|char|u16|s16|u32|s32|f32|f64)\s+'
                         + re.escape(name) + r'\s*\[\s*(0[xX][0-9A-Fa-f]+|[0-9]+)\s*\]\s*;', code)
        if not decl:
            continue
        width = SCALAR[decl[2]]
        count = int(decl[3], 16) if decl[3].lower().startswith('0x') else int(decl[3])
        if count * width != s['size']:
            continue
        uses = [m for m in re.finditer(r'\b' + re.escape(name) + r'\b', code)
                if not decl.start() <= m.start() < decl.end()]
        if len(uses) != 1 or not any(a <= uses[0].start() < b for a, b in primers):
            continue
        line_end = code.find('\n', uses[0].end())
        if line_end < 0 or not code[uses[0].end():line_end].rstrip().endswith(';'):
            continue
        start, end = origin + s['value'], origin + s['value'] + s['size']
        if start % 4:
            continue
        parts = []
        at = start
        while at < end:
            owner = next((o for o in objects if o.addr <= at < o.end), None)
            if owner is None:
                break  # An unknown interval is not proven padding.
            stop = min(end, owner.end)
            if (at - start) % width or (stop - at) % width:
                break
            # MWCC four-aligns even byte arrays and byte-only structs. Use
            # scalar elements until the next array can begin without padding.
            while at < stop:
                scalar = bool(at % 4)
                size = width if scalar else stop - at
                alias = owner.name + f'__fzgx_offset_{at-owner.addr:X}'
                if at % width or (alias in own and alias != name):
                    break
                parts.append((alias, size, scalar))
                at += size
            if at != stop:
                break
        if at != end or len(parts) < 2:
            continue
        replacement = '\n'.join(f'{decl[1] or ""}{decl[2]} {alias}'
                                + (';' if scalar else f'[{size // width}];')
                                for alias, size, scalar in parts)
        reads = ''.join('\n    /* Native section-order primer. */ (void)*(volatile u8 *)&'
                        + alias + ';' for alias, _, _ in parts[1:])
        edits.extend([(decl.start(), decl.end(), replacement),
                      (uses[0].start(), uses[0].end(), parts[0][0]),
                      (line_end, line_end, reads)])
    if not edits:
        return []
    text = body
    for a, b, value in sorted(edits, reverse=True):
        text = text[:a] + value + text[b:]
    return [('split primer-only BSS arrays at proven retail object boundaries', text)]


def unused_bss_primer_objects(p, symbol, body, obj, check):
    """Mark storage used only by discarded layout primers as private copies.

    Live section members still need individual retail bounds and bindings. A
    declaration referenced only by primer code has no live C consumer; retain
    its size/order for MWCC, then let poolfix's relocation guard discard it.
    """
    if not obj or not check.ok:
        return []
    from .fixup_evidence import _function_span
    from .sdkimport import masked

    elf = poolfix.Elf(Path(obj).read_bytes())
    section = elf.section('.bss')
    bound = {a for a, _, _ in check._pool_pairs}
    symbols = elf.symbols()
    # Named-object bindings prove BSS copies too. Some functions address the
    # objects directly and never emit an anonymous section-base relocation.
    if not section or not any(s['name'] in bound and s['shndx'] == section['index']
                              for s in symbols):
        return []
    code = masked(body)
    sym = p.resolve(symbol)
    retail, unit = p.symbols(sym.module), p.unit_of(sym)
    primers = [span for s in symbols if s['info'] & 15 == 2 and s['size']
               and 0 < s['shndx'] < len(elf.sections)
               and elf.sections[s['shndx']]['name'] == '.fzgxpool'
               and (span := _function_span(code, s['name']))]
    names = {}
    for own in symbols:
        name = own['name']
        if (own['shndx'] != section['index'] or own['info'] & 15 != 1 or not own['size']
                or name in bound or name.startswith('fzgx_pool_')):
            continue
        known = retail.get(name.removeprefix('fzgx_obj_'))
        # A saved layout can use an ordinary retail name for a private copy.
        # Primer-only uses do not confer ownership of that retail definition.
        if known and (unit is None or p.unit_of(known) == unit):
            continue
        # Restrict this to plain, uninitialized file-scope declarations. All
        # remaining occurrences must lie in emitted discarded primer functions.
        decl = re.search(r'(?m)^(?:static\s+)?(?:struct\s+)?[A-Za-z_]\w*\s+\**\s*'
                         + re.escape(name) + r'\s*(?:\[[^;=\n]*\])?\s*;', code)
        if not decl or any(a <= decl.start() < b for a, b in primers):
            continue
        uses = [m for m in re.finditer(r'\b' + re.escape(name) + r'\b', code)
                if not decl.start() <= m.start() < decl.end()]
        if not uses or any(not any(a <= m.start() < b for a, b in primers) for m in uses):
            continue
        names[name] = 'fzgx_pool_' + name
    if not names:
        return []
    text = re.sub(r'\b\w+\b', lambda m: names.get(m[0], m[0]), body)
    return [('discard BSS copies used only by layout primers', text)]


def unused_bss_definitions(p, symbol, body, obj, check):
    """Remove unused generated BSS copies left in old standalone sources.

    Keep owned storage and every declaration mentioned by live source or ELF
    relocations. Unowned retail names retain an extern declaration; their
    actual definitions still belong to the retail owner.
    """
    if not obj or not check.ok:
        return []
    from .sdkimport import masked
    from .fixup_evidence import _function_span
    elf = poolfix.Elf(Path(obj).read_bytes())
    section = elf.section('.bss')
    if not section or section['type'] != 8:
        return []
    code = masked(body)
    sym = p.resolve(symbol)
    retail, unit = p.symbols(sym.module), p.unit_of(sym)
    referenced = {struct.unpack_from('>I', elf.data, pos + 4)[0] >> 8
                  for rs in elf.sections if rs['type'] == 4
                  for pos in range(rs['offset'], rs['offset'] + rs['size'], 12)}
    edits = []
    emitted = {s['name'] for s in elf.symbols() if s['info'] & 15 == 2 and s['size']}
    # Old static-inline primers were never called or emitted. Their source
    # references alone kept otherwise unused definition copies alive here.
    for match in re.finditer(r'(?m)^static\s+inline\s+void\s+(fzgx_bss_\w+)\s*\(void\)\s*\{', code):
        name = match[1]
        span = _function_span(code, name)
        if span and name not in emitted and len(re.findall(r'\b' + re.escape(name) + r'\b', code)) == 1:
            edits.append((match.start(), span[1], ''))
    live = code
    for start, end, _ in edits:
        live = live[:start] + re.sub(r'[^\n]', ' ', live[start:end]) + live[end:]
    for own in elf.symbols():
        name = own['name']
        if (own['shndx'] != section['index'] or own['info'] & 15 != 1 or not own['size']
                or own['index'] in referenced
                or not name.startswith(('fzgx_obj_', 'lbl_'))):
            continue
        native = name.removeprefix('fzgx_obj_')
        alias = re.fullmatch(r'(.+)__fzgx_offset_[0-9A-F]+', native)
        known = retail.get(native) or (retail.get(alias[1]) if alias else None)
        if known and unit is not None and p.unit_of(known) == unit:
            continue
        uses = list(re.finditer(r'\b' + re.escape(name) + r'\b', live))
        decl = re.search(r'(?m)^(?:static\s+)?(?:struct\s+)?[A-Za-z_]\w*\s+\**\s*'
                         + re.escape(name) + r'\s*(?:\[[^;=\n]*\])?\s*;[^\S\n]*\n?', code)
        if len(uses) == 1 and decl and decl.start() <= uses[0].start() < decl.end():
            if code[:decl.start()].count('{') != code[:decl.start()].count('}'):
                continue
            replacement = 'extern ' + body[decl.start():decl.end()] if name in retail else ''
            if name in retail and replacement.startswith('extern static '):
                replacement = replacement.replace('extern static ', 'extern ', 1)
            edits.append((decl.start(), decl.end(), replacement))
    text = body
    for start, end, replacement in sorted(edits, reverse=True):
        text = text[:start] + replacement + text[end:]
    return [('remove unused unowned BSS declaration copies', text)] if edits else []


def private_data_objects(body, obj, check):
    """Mark file-local storage inside an oracle-proven shared section copy."""
    if not obj or not check.ok or not any(a.startswith('...data') for a, _, _ in check._pool_pairs):
        return []
    elf = poolfix.Elf(Path(obj).read_bytes())
    section = elf.section('.data')
    if section is None:
        return []
    names = {}
    for s in elf.symbols():
        name = s['name']
        if (s['shndx'] != section['index'] or not s['size'] or s['info'] != 1
                or name.startswith(('@', 'fzgx_pool_'))):
            continue
        if re.search(r'(?m)^static\s+[^;{}=\n]+\b'+re.escape(name)+r'\b\s*(?:\[|=)', body):
            names[name] = 'fzgx_pool_' + name
    if not names:
        return []
    text = re.sub(r'\b\w+\b', lambda m: names.get(m[0], m[0]), body)
    return [('private objects in verified shared data section', text)]


def unused_pool_objects(p, symbol, body, obj, check):
    """Identify unreferenced initializer copies left behind proven pool bindings."""
    if not obj or not check.ok:
        return []
    elf = poolfix.Elf(Path(obj).read_bytes())
    symbols = elf.symbols()
    bound = {a for a, _, _ in check._pool_pairs}
    sym = p.resolve(symbol)
    unit = p.unit_of(sym)
    retail = p.symbols(sym.module)
    names = {}
    local_edits = []
    for section_name in ('.rodata', '.data'):
        section = elf.section(section_name)
        if not section or not any(s['name'] in bound and s['name'].startswith('..' + section_name)
                                  and s['shndx'] == section['index'] for s in symbols):
            continue
        # The oracle replaces bound references and discards primer code. Local
        # initializer references disappear only if the whole section can go.
        referenced = set()
        for reloc in elf.sections:
            if reloc['type'] != 4 or elf.sections[reloc['info']]['name'] in ('.fzgxpool', section_name):
                continue
            for at in range(reloc['offset'], reloc['offset'] + reloc['size'], 12):
                _, info, _ = struct.unpack_from('>IIi', elf.data, at)
                target = symbols[info >> 8]
                if target['name'] not in bound:
                    referenced.add(target['index'])
        for own in symbols:
            name = own['name']
            if (own['shndx'] != section['index'] or own['info'] & 15 != 1 or not own['size']
                    or name.startswith(('@', 'fzgx_pool_')) or name in bound
                    or own['index'] in referenced):
                continue
            known = retail.get(name)
            if known and p.unit_of(known) == unit:
                continue
            local = re.fullmatch(r'([A-Za-z_]\w*)\$[0-9]+', name)
            if local:
                from .fixup_evidence import _function_span
                from .sdkimport import masked
                code = masked(body)
                span = _function_span(code, sym.name)
                declarations = list(re.finditer(r'(?m)^[ \t]*static\s+const\s+[\w \t*]+\b'
                                                + re.escape(local[1]) + r'\b\s*(?:\[[^;=]*\])?\s*=', code))
                # Separate scopes may each declare the same static name (fn_17_9314
                # has one `color` per branch); their compiler symbols differ only by
                # the `$N` suffix. Every use resolves to one of them, so renaming the
                # identifier across the function preserves each scope's meaning. The
                # engine still compiles the result before it is considered.
                if not declarations or not span or any(
                        not span[0] <= d.start() < span[1] for d in declarations):
                    continue
                # MWCC gives static locals ELF-only $N suffixes. Rename their
                # C identifier only inside the function, preserving member names.
                uses = re.compile(r'\b' + re.escape(local[1]) + r'\b')
                for use in uses.finditer(code, span[0], span[1]):
                    prefix = code[span[0]:use.start()].rstrip()
                    if not prefix.endswith(('.', '->')):
                        local_edits.append((use.start(), use.end(), 'fzgx_pool_' + local[1]))
                continue
            # Only rename objects defined in this source, never header declarations.
            if re.search(r'(?m)^(?:static\s+)?(?:const\s+)?[A-Za-z_][\w \t*]*\b' + re.escape(name)
                         + r'\b\s*(?:\[[^;=]*\])?\s*=', body):
                names[name] = 'fzgx_pool_' + name
    if not names and not local_edits:
        return []
    text = body
    for a, b, value in sorted(set(local_edits), reverse=True):
        text = text[:a] + value + text[b:]
    text = re.sub(r'\b\w+\b', lambda m: names.get(m[0], m[0]), text)
    return [('discard unused initializer copies after verified pool binding', text)]


def struct_text(tname, text):
    for src in (text, include_text()):
        m = re.search(r"(?:typedef\s+)?struct\s+%s\s*\{(.*?)\n\}" % re.escape(tname), src, re.S)
        if m:
            return m.group(1)
        m = re.search(r"typedef\s+struct\s*\w*\s*\{([^{}]*)\n\}\s*%s\s*;" % re.escape(tname), src, re.S)
        if m:
            return m.group(1)
    return None


def field_decls(body):
    """field name -> (type text incl. stars, dims list, raw line)."""
    out = {}
    body = re.sub(r"/\*.*?\*/", "", body, flags=re.S)
    body = re.sub(r"//[^\n]*", "", body)
    for line in body.replace('\n', ' ').split(';'):
        line = line.strip() + ';'
        if line == ';':
            continue
        m = re.match(r"((?:const\s+|volatile\s+|unsigned\s+|signed\s+)*(?:struct\s+|union\s+|enum\s+)?\w+(?:\s*\*+)?)\s*(\w+)((?:\[[^\]]+\])*);$", line)
        if m:
            ttext = re.sub(r"\s+", " ", m.group(1)).replace(" *", " *")
            dims = re.findall(r"\[([^\]]+)\]", m.group(3) or '')
            out[m.group(2)] = (ttext, dims, line)
            continue
        pm = re.match(r"([\w\s\*]+)\(\s*\*\s*(\w+)\s*\)\s*(\([^)]*\));$", line)
        if pm:
            out[pm.group(2)] = (None, [], line)
    return out


def probe_layout(p, module, prefix, tname, names, decls, tag):
    """offsets/sizes/elemsizes/aligns of the named fields of struct type tname, from MWCC."""
    lines = []
    for i, n in enumerate(names):
        ttext, dims, raw = decls[n]
        lines.append(f"u8 fzgx_off_{i}[1 + (u32)&(({tname} *)0)->{n}];")
        lines.append(f"u8 fzgx_sz_{i}[sizeof((({tname} *)0)->{n})];")
        sub = ''.join('[0]' for _ in dims)
        lines.append(f"u8 fzgx_esz_{i}[sizeof((({tname} *)0)->{n}{sub})];")
        if ttext is None:
            lines.append(f"u8 fzgx_al_{i}[4];")
        else:
            lines.append(f"struct fzgx_al_{i}_s {{ u8 c; {ttext} t; }};")
            lines.append(f"u8 fzgx_al_{i}[(u32)&((struct fzgx_al_{i}_s *)0)->t];")
    src = prefix + "\n" + "\n".join(lines) + "\n"
    d = STATE_DIR / 'fixup' / 'probe'
    d.mkdir(parents=True, exist_ok=True)
    # REL entrypoint keys include "module:name"; MWCC runs under Windows
    # semantics, where a colon in the source basename is not a valid filename.
    tag = tag.replace(':', '__')
    f = d / f"{tag}_{hashlib.sha1(src.encode()).hexdigest()[:10]}.c"
    f.write_text(src)
    obj = f.with_suffix('.o')
    cp = oracle.compile_source(p, module, f, obj, include_dirs=[ROOT / 'include'])
    if cp.returncode != 0 or not obj.exists():
        return None, re.sub(r"\s+", " ", cp.stdout + cp.stderr)[-300:]
    sizes = {s['name']: s['size'] for s in poolfix.Elf(obj.read_bytes()).symbols()}
    out = {}
    for i, n in enumerate(names):
        try:
            out[n] = (sizes[f'fzgx_off_{i}'] - 1, sizes[f'fzgx_sz_{i}'], sizes[f'fzgx_esz_{i}'], sizes[f'fzgx_al_{i}'])
        except KeyError:
            return None, f'probe symbol missing for {n}'
    return out, None


def filler(prefix, pos, end):
    out, q = [], pos
    while q < end and q % 2:
        out.append((q, f"u8 {prefix}_{q:X};", f"{prefix}_{q:X}")); q += 1
    while q < end and q % 4 and q + 2 <= end:
        out.append((q, f"u16 {prefix}_{q:X};", f"{prefix}_{q:X}")); q += 2
    n = (end - q) // 4
    if n == 1:
        out.append((q, f"u32 {prefix}_{q:X};", f"{prefix}_{q:X}")); q += 4
    elif n > 1:
        out.append((q, f"u32 {prefix}_{q:X}[{n}];", f"{prefix}_{q:X}")); q += 4 * n
    while q + 2 <= end:
        out.append((q, f"u16 {prefix}_{q:X};", f"{prefix}_{q:X}")); q += 2
    while q < end:
        out.append((q, f"u8 {prefix}_{q:X};", f"{prefix}_{q:X}")); q += 1
    return out


def fdef(decl, name):
    ttext, dims, raw = decl
    if ttext is None:
        return re.sub(r"\(\s*\*\s*\w+\s*\)", f"(*{name})", raw)
    return f"{ttext}{'' if ttext.endswith('*') else ' '}{name}{''.join(f'[{d}]' for d in dims)};"


def overlapping_field_views(p, symbol, text):
    """Repair lifted offset-named views that accidentally consume each other's storage.

    Offset names nominate a layout, never prove it. Measure the original with
    MWCC and keep each member's type and stride; only the full retail oracle can
    accept the proposed overlapping layout.
    """
    from .sdkimport import masked
    from .signatures import records, record_layouts
    from .fixup_source import _function_body_span
    code = masked(text)
    sym = p.resolve(symbol)
    span = _function_body_span(code, sym.name)
    if not span:
        return
    layouts, _ = record_layouts(code, span[0])
    edits = []
    for record in records(code, span[0]):
        if record['kind'] != 'struct' or record['parent'] or record['key'] not in layouts:
            continue
        fields = layouts[record['key']]
        members = [f for f in fields if not f[0].startswith('pad_')]
        if not members or not any(f[4] for f in members):
            continue
        offsets = {}
        for name, _, _, _, _ in members:
            match = re.fullmatch(r'unk_([0-9A-Fa-f]+)', name)
            if not match:
                break
            offsets[name] = int(match[1], 16)
        else:
            if all(offsets[n] == off for n, _, off, _, _ in members):
                continue
            decls = field_decls(text[record['opening']:record['end'] - 1])
            if any(n not in decls for n in offsets):
                continue
            typ = 'struct ' + record['tag'] if record['tag'] else record['alias']
            measured, error = probe_layout(p, sym.module, text[:span[0]].rsplit('\n', 1)[0],
                                           typ, list(offsets), decls, symbol)
            if error or any(offsets[n] % measured[n][3] for n in offsets):
                continue
            if all(offsets[n] == measured[n][0] for n in offsets):
                continue
            views = []
            for n in offsets:
                padding = f'u8 pad_view_{n}[0x{offsets[n]:X}]; ' if offsets[n] else ''
                views.append('        struct { ' + padding + fdef(decls[n], n) + ' };')
            replacement = '\n    union {\n' + '\n'.join(views) + '\n    };\n'
            edit = (record['opening'], record['end'] - 1, replacement)
            edits.append(edit)
            yield 'overlapping offset views ' + record['key'], text[:edit[0]] + replacement + text[edit[1]:]
    if len(edits) > 1:
        for lo, hi, replacement in sorted(edits, reverse=True):
            text = text[:lo] + replacement + text[hi:]
        yield 'overlapping offset views in all records', text


def find_models(text):
    """(pvar, tname, base, stmt, kind) for pointer models and direct-global models."""
    models = []
    for m in re.finditer(r"(?:(?:struct\s+)?(\w+)\s*\*\s*)?(\w+)\s*=\s*\((?:struct\s+)?(\w+)\s*\*\)\s*&(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\s*;", text):
        models.append((m.group(2), m.group(3), m.group(4), m.group(0), 'ptr'))
    seen = {m[2] for m in models}
    for m in re.finditer(r"\nextern\s+(\w+)\s+(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\s*((?:\[[^\]]*\])*)\s*;", text):
        tname, base = m.group(1), m.group(2)
        if base in seen or tname not in SCALAR:
            continue
        if re.search(r"&\s*%s\b" % re.escape(base), text) and not re.search(r"\b%s\s*=\s*\(" % re.escape(base), text):
            models.append((None, tname, base, m.group(0), 'bare'))
            seen.add(base)
    for m in re.finditer(r"\nextern\s+(?:struct\s+)?(\w+)\s+(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\s*;", text):
        tname, base = m.group(1), m.group(2)
        if base in seen or tname in ('u8', 'u16', 'u32', 's8', 's16', 's32', 'f32', 'f64', 'int', 'char', 'void'):
            continue
        if re.search(r"\b%s\.\w+" % re.escape(base), text):
            models.append((None, tname, base, m.group(0), 'direct'))
            seen.add(base)
    # declared by an included header: the definition needs the header's extern renamed away
    for base in sorted(set(re.findall(r"\b(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\.\w+", text))):
        if base in seen:
            continue
        hm = re.search(r"\nextern\s+(?:struct\s+)?(\w+)\s+%s\s*;" % re.escape(base), include_text())
        if hm:
            models.append((None, hm.group(1), base, '', 'direct-header'))
            seen.add(base)
    return models


def tu_objects(p, symbol, text, mode, cache, retail_bases=()):
    sym = p.resolve(symbol)
    syms = p.symbols(sym.module)
    notes = []
    models = find_models(text)
    # Saved preprocessed bodies retain spaces around member access. The
    # layout parser below recognizes the pointer token, not that whitespace.
    for pvar, *_ in models:
        if pvar:
            text = re.sub(r'\b' + re.escape(pvar) + r'\s*->\s*', pvar + '->', text)
    # same-module .bss scalars/arrays the body names directly are objects of the retail TU too
    scalars = []
    for m in re.finditer(r"\nextern\s+((?:const\s+)?(?:u8|s8|u16|s16|u32|s32|f32|f64|int|char)(?:\s*\*)?)\s+(lbl_\d+_bss_[0-9A-F]+|lbl_[0-9A-F]{8})\s*((?:\[[^\]]*\])*)\s*;", text):
        s = syms.get(m.group(2))
        if s and s.section == '.bss' and m.group(2) not in {mm[2] for mm in models} and re.search(r"(?<![\w&])%s\b" % re.escape(m.group(2)), text.replace(m.group(0), '')):
            scalars.append((m.group(1), m.group(2), m.group(3), m.group(0), s))
    if not models and not scalars:
        return None, ['no bss model']
    out_text = text
    extra_objs = {s.name: (decl_t, dims, stmt) for decl_t, name, dims, stmt, s in scalars}
    fm = re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), out_text)
    if not fm:
        return None, ['function definition not found']
    prefix = out_text[:fm.start() + 1]
    all_defs, all_typedefs = [], []
    for pvar, tname, base, stmt, kind in models:
        b = syms.get(base)
        if b is None or b.section != '.bss':
            # another module's object (or SDA data): retail addresses it by name, leave it alone
            notes.append(f'{base}: not a same-module .bss object, left as is'); continue
        if kind == 'direct-header':
            kind = 'direct'
        if kind == 'direct':
            pvar = f'fzgx_p_{base}'
            out_text = re.sub(r"\b%s\." % re.escape(base), f"{pvar}->", out_text)
            out_text = re.sub(r"&\s*%s\b(?![\.\w])" % re.escape(base), f"((u8 *){pvar} + 0)", out_text)
            body_only = "\n".join(l for l in out_text.replace(stmt, '').split("\n") if not l.lstrip().startswith('#'))
            if re.search(r"(?<![\w>])%s\b(?!\s*->)" % re.escape(base), body_only):
                notes.append(f'{base}: direct global used as a value'); return None, notes
            stmt_removed = stmt
            stmt = ''
        else:
            stmt_removed = stmt
        synthetic = {}
        decls = {}
        byte_model = tname in SCALAR
        if kind == 'bare':
            esz0 = SCALAR[tname]
            pvar = f'fzgx_p_{base}'
            out_text = re.sub(r"&\s*%s\s*\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\]" % re.escape(base), lambda mm: f"({tname} *)({pvar} + {int(mm.group(1), 0)})", out_text)
            out_text = re.sub(r"(?<![\w&])%s\s*\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\]" % re.escape(base), lambda mm: f"{pvar}[{int(mm.group(1), 0)}]", out_text)
            out_text = re.sub(r"&\s*%s\b(?![\.\[\w])" % re.escape(base), f"({tname} *)({pvar} + 0)", out_text)
            body_only = "\n".join(l for l in out_text.replace(stmt, '').split("\n") if not l.lstrip().startswith('#'))
            if re.search(r"(?<![\w>])%s\b" % re.escape(base), body_only):
                notes.append(f'{base}: bare symbol used as a value'); return None, notes
            stmt_removed = stmt
            kind = 'bytes'
        if byte_model:
            esz = SCALAR[tname]
            def _syn(ttext, n):
                size = SCALAR.get(ttext.replace(' *', '').strip(), 4 if '*' in ttext else None)
                if size is None:
                    return None
                fname = f"fzgx_{re.sub(r'[^A-Za-z0-9]', '_', ttext)}_{n:X}"
                synthetic[fname] = (n, size, size, min(size, 8))
                decls[fname] = (ttext, [], f"{ttext} {fname};")
                return fname
            def _deref(mm):  # *(T *)(p + N)
                f = _syn(mm.group(1).strip(), int(mm.group(2), 0))
                return mm.group(0) if f is None else f"{pvar}->{f}"
            out_text = re.sub(r"\*\s*\(\s*((?:const\s+)?\w+(?:\s*\*)?)\s*\*\s*\)\s*\(\s*%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)" % re.escape(pvar), _deref, out_text)
            def _idx(mm):  # p[N]
                f = _syn(tname, int(mm.group(1), 0) * esz)
                return f"{pvar}->{f}"
            out_text = re.sub(r"\b%s\s*\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\]" % re.escape(pvar), _idx, out_text)
            def _addr(mm):  # (T *)(p + N)  -> (T *)&p->byte_N
                f = _syn('u8', int(mm.group(2), 0))
                return f"({mm.group(1).strip()} *)&{pvar}->{f}"
            out_text = re.sub(r"\(\s*((?:const\s+)?\w+(?:\s*\*)?)\s*\*\s*\)\s*\(\s*%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)" % re.escape(pvar), _addr, out_text)
            def _plus(mm):  # p + N
                f = _syn('u8', int(mm.group(1), 0) * esz)
                return f"({tname} *)&{pvar}->{f}"
            out_text = re.sub(r"\b%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\b" % re.escape(pvar), _plus, out_text)
            def _bare(mm):
                f = _syn('u8', 0)
                return f"({tname} *)&{pvar}->{f}"
            if kind == 'ptr':
                out_text = re.sub(r"\n[ \t]*(?:const\s+)?%s\s*\*\s*%s\s*;" % (re.escape(tname), re.escape(pvar)), '', out_text)
                out_text = re.sub(r"(?<=[;{}]\s)(?:const\s+)?%s\s*\*\s*%s\s*;\s*" % (re.escape(tname), re.escape(pvar)), '', out_text)
            marked = out_text.replace(stmt_removed, '\x00STMT\x00') if stmt_removed else out_text
            out_text = re.sub(r"(?<![\w>])%s\b(?!\s*(?:->|=[^=]))" % re.escape(pvar), _bare, marked).replace('\x00STMT\x00', stmt_removed)
        else:
            st = struct_text(tname, text)
            if st is None:
                notes.append(f'{tname}: struct text not found'); return None, notes
            decls = field_decls(st)

        def _byteoff(mm):
            n = int(mm.group(1), 0)
            fname = f"fzgx_byte_{n:X}"
            synthetic[fname] = n
            return f"(u8 *)&{pvar}->{fname}"
        out_text = re.sub(r"\(u8 \*\)\s*(?:\(u32\)\s*)?\b%s\b\s*\+\s*(0x[0-9A-Fa-f]+|\d+)" % re.escape(pvar), _byteoff, out_text)
        uses = list(re.finditer(r"(&?)\b%s->(\w+)((?:\[[^\]]*\])*)" % re.escape(pvar), out_text))
        other = re.sub(r"\b%s->" % re.escape(pvar), '', out_text).replace(stmt_removed, '')
        other = "\n".join(l for l in other.split("\n") if not l.lstrip().startswith('#'))
        other = re.sub(r"(?:struct\s+)?%s\s*\*\s*%s\s*;" % (re.escape(tname), re.escape(pvar)), '', other)
        if re.search(r"\b%s\b" % re.escape(pvar), other):
            notes.append(f'{pvar}: used other than through ->'); return None, notes
        if not uses:
            notes.append(f'{pvar}: no uses'); return None, notes
        names = sorted({u.group(2) for u in uses if u.group(2) not in synthetic})
        missing = [n for n in names if n not in decls]
        if missing:
            notes.append(f'{tname}: fields without declaration text: {missing[:3]}'); return None, notes
        if names:
            key = (tname, tuple(names))
            if key not in cache:
                is_alias = re.search(r"\}\s*%s\s*;|typedef\s+struct\s+\w+\s+%s\s*;" % (re.escape(tname), re.escape(tname)), prefix + include_text())
                cache[key] = probe_layout(p, sym.module, prefix, tname if is_alias else 'struct ' + tname, names, decls, symbol)
            layout, err = cache[key]
            if layout is None:
                notes.append(f'{tname}: probe failed: {err}'); return None, notes
        else:
            layout = {}
        for fname, v in synthetic.items():
            if isinstance(v, tuple):
                layout[fname] = v
            else:
                layout[fname] = (v, 1, 1, 1)
                decls[fname] = ('u8', [], f'u8 {fname};')
        start = b
        lower = [syms[r] for r in retail_bases if syms.get(r) and syms[r].section == b.section and syms[r].addr < b.addr and b.addr - syms[r].addr <= 0x10000]
        if lower:
            start = max(lower, key=lambda s: s.addr)
        cluster = sorted((s for s in syms.values() if s.section == b.section and s.kind == 'object' and s.addr >= start.addr), key=lambda s: s.addr)
        if not cluster or cluster[0].addr != start.addr:
            notes.append(f'{base}: not an object start'); return None, notes
        # gaps between dtk objects become pseudo-objects
        full = []
        for i, s in enumerate(cluster):
            full.append(s)
            nxt = cluster[i + 1].addr if i + 1 < len(cluster) else None
            if nxt is not None and nxt > s.end:
                full.append(Gap(f"{base}_gap_{s.end:X}", s.end, nxt, b.section))
        cluster = full
        per_obj, rewrites, views = {}, [], {}
        view_end = b.addr
        for um in uses:
            amp, fname, idx = um.group(1), um.group(2), um.group(3)
            foff, fsize, esize, ealign = layout[fname]
            addr = b.addr + foff
            obj = next((s for s in cluster if s.addr <= addr < s.end), None)
            if obj is None:
                notes.append(f'{fname}: offset {foff:#x} outside cluster'); return None, notes
            inner = addr - obj.addr
            if addr + fsize > obj.end:
                ttext, dims, _ = decls[fname]
                if mode != 'split' or not dims or ttext is None or isinstance(obj, Gap):
                    notes.append(f'{fname}: crosses object {obj.name}'); return None, notes
                # A recovered array view can span several retail objects. Keep
                # its type and bounds, but allocate each proven object separately.
                covered = [s for s in cluster if s.addr < addr + fsize and s.end > addr]
                if (not covered or covered[-1].end < addr + fsize
                        or any(a.end != c.addr for a, c in zip(covered, covered[1:]))):
                    notes.append(f'{fname}: incomplete object coverage'); return None, notes
                views[fname] = (ttext, dims)
                view_end = max(view_end, addr + fsize)
                anchor = f'fzgx_byte_{foff:X}'
                decls[anchor] = ('u8', [], f'u8 {anchor};')
                rec = per_obj.setdefault(obj.name, {'sym': obj, 'fields': {}})
                rec['fields'].setdefault(inner, (anchor, 1, 1, 1))
                rewrites.append((um, obj, inner, fname, idx, amp))
                continue
            rec = per_obj.setdefault(obj.name, {'sym': obj, 'fields': {}})
            prev = rec['fields'].get(inner)
            synthetic_name = fname.startswith(('fzgx_byte_', 'fzgx_u8_'))
            if prev and prev[0] != fname and decls[prev[0]] != decls[fname]:
                if synthetic_name:
                    pass  # a byte view of a real field shares the field's object slot
                elif prev[0].startswith(('fzgx_byte_', 'fzgx_u8_')):
                    rec['fields'][inner] = (fname, fsize, esize, ealign)
                else:
                    notes.append(f'{fname}: conflicting field at {obj.name}+{inner:#x}'); return None, notes
            rec['fields'].setdefault(inner, (fname, fsize, esize, ealign))
            rewrites.append((um, obj, inner, fname, idx, amp))
        for name, (decl_t, dims, stmt) in list(extra_objs.items()):
            s = syms[name]
            if s.addr < start.addr or s.addr - start.addr > 0x10000:
                continue
            obj = next((c for c in cluster if c.addr <= s.addr < c.end), None)
            if obj is None or obj.name != name or name in per_obj:
                continue
            fname = f'fzgx_scalar_{name}'
            decls[fname] = (decl_t, [d.strip('[]') for d in re.findall(r'\[[^\]]*\]', dims)], f'{decl_t} {fname}{dims};')
            per_obj[name] = {'sym': obj, 'fields': {0: (fname, obj.size, obj.size, 4 if not dims else 4)}}
            out_text = out_text.replace(stmt, '')
            extra_objs.pop(name)
        last = max(view_end, max(r['sym'].end for r in per_obj.values()))
        before = [s for s in cluster if s.addr < last]
        beyond = [s for s in cluster if s.addr >= last]
        if len(before) < 6 and beyond:
            last = beyond[min(len(beyond), 6 - len(before)) - 1].end
        defs, pos, access = [], b.addr, {}
        for s in cluster:
            if s.addr >= last:
                break
            if s.addr < pos:
                continue
            rec = per_obj.get(s.name)
            if rec is None:
                parts = filler(s.name + '_fill', s.addr, s.end)
                first = f"{s.name}_fill_{s.addr:X}"
                defs += [(a, d.replace(first, s.name) if a == s.addr else d, acc.replace(first, s.name) if a == s.addr else acc) for a, d, acc in parts]
                pos = s.end
                continue
            fl = rec['fields']
            if mode == 'split':
                q = s.addr
                for inner in sorted(fl):
                    fname, fsize, esize, ealign = fl[inner]
                    a = s.addr + inner
                    if a < q:
                        notes.append(f'{s.name}: overlapping fields'); return None, notes
                    if a > q:
                        defs += filler(f'{s.name}_fill', q, a)
                    name = s.name if inner == 0 else f"{s.name}_{inner:X}"
                    dims = decls[fname][1]
                    if a % max(ealign, 1) or (dims and a % 4):
                        notes.append(f'{s.name}: field {fname} misaligned as an object'); return None, notes
                    defs.append((a, fdef(decls[fname], name), name))
                    access[(s.name, inner)] = name
                    q = a + fsize
                if q < s.end:
                    defs += filler(f'{s.name}_fill', q, s.end)
                pos = s.end
                continue
            if list(fl) == [0] and fl[0][0].startswith('fzgx_scalar_'):
                fname, fsize, esize, ealign = fl[0]
                defs.append((s.addr, fdef(decls[fname], s.name), s.name))
                access[(s.name, 0)] = s.name
                pos = s.end
                continue
            if list(fl) == [0]:
                fname, fsize, esize, ealign = fl[0]
                dims = decls[fname][1]
                if fsize == s.size and not (dims and s.addr % 4):
                    defs.append((s.addr, fdef(decls[fname], s.name), s.name))
                    access[(s.name, 0)] = s.name
                    pos = s.end
                    continue
            body, off, align = [], 0, 1
            for inner in sorted(fl):
                fname, fsize, esize, ealign = fl[inner]
                if inner % max(ealign, 1):
                    notes.append(f'{s.name}: field {fname} misaligned'); return None, notes
                if inner > off:
                    body.append(f"    u8 pad_{off:X}[{inner - off:#x}];")
                    off = inner
                elif inner < off:
                    notes.append(f'{s.name}: overlapping fields'); return None, notes
                body.append("    " + fdef(decls[fname], fname))
                access[(s.name, inner)] = f"{s.name}.{fname}"
                off += fsize
                align = max(align, ealign)
            usable = s.size // align * align
            if off > usable:
                notes.append(f'{s.name}: fields exceed aligned size'); return None, notes
            if off < usable:
                body.append(f"    u8 pad_{off:X}[{usable - off:#x}];")
            tobj = f"{s.name}_t"
            all_typedefs.append(f"typedef struct {tobj} {{\n" + "\n".join(body) + f"\n}} {tobj};\n\n")
            defs.append((s.addr, f"{tobj} {s.name};", s.name))
            pos = s.addr + usable
            if usable < s.size:
                defs += filler(s.name + '_tail', pos, s.end)
                pos = s.end
        for um, obj, inner, fname, idx, amp in sorted(rewrites, key=lambda r: -r[0].start()):
            value = access[(obj.name, inner)]
            if fname in views:
                ttext, dims = views[fname]
                value = f"(*({ttext} (*){''.join(f'[{d}]' for d in dims)})&{value})"
            repl = f"{amp}{value}{idx}"
            out_text = out_text[:um.start()] + repl + out_text[um.end():]
        if stmt_removed:
            out_text = out_text.replace(stmt_removed, '')
        if kind == 'ptr':
            out_text = re.sub(r"\n[ \t]*(?:struct\s+)?%s\s*\*\s*%s\s*;" % (re.escape(tname), re.escape(pvar)), '', out_text)
        all_defs += defs
        notes.append(f'{base}: {len(per_obj)} objects referenced, {len(defs)} definitions')
    if not all_defs:
        return None, notes
    all_defs.sort(key=lambda x: x[0])
    for _, d, _ in all_defs:
        dn = re.search(r"(\w+)(?:\[[^\]]*\])*;$", d.replace('(*', '').replace(')(', ''))
        if dn:
            out_text = re.sub(r"\n[^\n]*\bextern\b[^\n;]*\b%s\b[^\n;]*;" % re.escape(dn.group(1)), '', out_text)
    # names a module header declares with its own layout are defined under an alias (the
    # oracle binds the section base through it); every use in this unit follows the alias
    renamed = {}
    for i, (a, d, acc) in enumerate(all_defs):
        dn = re.search(r"(\w+)(?:\[[^\]]*\])*;$", d.replace('(*', '').replace(')(', ''))
        if dn and re.search(r"\bextern\s+[^;\n]*\b%s\b[^;\n]*;" % re.escape(dn.group(1)), include_text()):
            renamed[dn.group(1)] = 'fzgx_obj_' + dn.group(1)
    if renamed:
        pat = re.compile(r"\b(%s)\b" % "|".join(re.escape(k) for k in renamed))
        all_defs = [(a, pat.sub(lambda m: renamed[m.group(1)], d), pat.sub(lambda m: renamed[m.group(1)], acc)) for a, d, acc in all_defs]
        all_typedefs = [pat.sub(lambda m: renamed[m.group(1)], td) for td in all_typedefs]
        body_start = out_text.rfind('\n', 0, re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), out_text).start() + 1)
        out_text = out_text[:body_start] + pat.sub(lambda m: renamed[m.group(1)], out_text[body_start:])
    block = ''.join(all_typedefs) + "/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */\n"
    block += "\n".join(d for _, d, _ in all_defs) + "\n\n"
    block += '#pragma section code_type ".fzgxpool"\nstatic void fzgx_bss_layout(void) {\n    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */\n'
    block += "".join(f"    s = *(u8 *)&{acc};\n" for _, _, acc in all_defs)
    block += '}\n#pragma section code_type ".text"\n\n'
    fm = re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), out_text)
    out_text = out_text[:fm.start() + 1] + block + out_text[fm.start() + 1:]
    return out_text, notes


def _diff_rows(r):
    rows = r._rows if r._rows else ([], [])
    return sum(1 for l, rr in zip(*rows) if (l.get('diff_kind') or 'DIFF_NONE') != 'DIFF_NONE' or (rr.get('diff_kind') or 'DIFF_NONE') != 'DIFF_NONE')





def section_bytes(p, module, section, addr=None):
    if module == 'main':
        for base, raw in p._rel_layout('main').values():
            if addr is not None and base <= addr < base + len(raw):
                return base, raw
        return None
    sec = p._raw_section(module, section)
    base = p._section_base(module, section)
    return (base, sec) if sec is not None else None


def c_literal(b):
    out = ''
    for ch in b:
        if ch == 0x5c:
            out += '\\\\'
        elif ch == 0x22:
            out += '\\"'
        elif ch == 0x0a:
            out += '\\n'
        elif ch == 0x0d:
            out += '\\r'
        elif ch == 0x09:
            out += '\\t'
        elif 0x20 <= ch < 0x7f:
            out += chr(ch)
        else:
            return None
    return '"' + out + '"'


def string_at(raw, off):
    """(bytes without NUL, padded length) of the NUL-terminated string at off, or None."""
    e = raw.find(b'\0', off)
    if e < 0 or e == off:
        return None
    s = raw[off:e]
    if c_literal(s) is None:
        return None
    n = (e - off + 1 + 3) & ~3
    return s, n


def native_string_views(p, symbol, text):
    """Recover string objects obscured by a byte pointer to a TU pool."""
    from .sdkimport import masked
    from .fixup_source import _function_body_span, commutations
    from .dataimport import pool_objects, payload
    code = masked(text)
    sym = p.resolve(symbol)
    span = _function_body_span(code, sym.name)
    if not span:
        return []
    out = []
    for declaration in re.finditer(r'\bextern\s+(?:const\s+)?(char|u8|unsigned char)\s+(\w+)\s*\[[^\]]*\]\s*;', code[:span[0]]):
        typ, anchor = declaration.groups()
        owner = p.find_symbol(anchor, sym.module)
        if not owner or owner.module != sym.module or owner.section not in ('.rodata', '.data'):
            continue
        casts = r'(?:\(\s*(?:const\s+)?(?:char|u8|unsigned char|u32|void)\s*\*?\s*\)\s*)*'
        assignment = list(re.finditer(r'\b(\w+)\s*=\s*'+casts+r'&?'+re.escape(anchor)+r'\s*;', code[span[1]:span[2]]))
        if len(assignment) != 1:
            continue
        assign = assignment[0]
        root = assign[1]
        if len(re.findall(r'\b'+re.escape(root)+r'\s*=(?!=)',code[span[1]:span[2]])) != 1:
            continue
        root_decl = re.search(r'\b(?:const\s+)?(?:char|u8|unsigned char)\s*\*\s*'+re.escape(root)+r'\s*([;=])', code[span[1]:span[2]])
        if not root_decl:
            continue
        edits = [(declaration.start(), declaration.end(), ''),
                 (span[1]+assign.start(),span[1]+assign.end(),''),
                 (span[1]+root_decl.start(),span[1]+root_decl.end(),'')]
        if root_decl[1] == '=':
            edits = [edits[0],(span[1]+root_decl.start(),span[1]+assign.end(),'')]
        uses = []
        operations = []
        commutations(text, sym.name, operations)
        for op in operations:
            if op['op'] != '+':
                continue
            left,right = (code[slice(*op[k])].strip() for k in ('left','right'))
            left = re.sub(casts, '', left).strip(' ()')
            if left != root or not re.fullmatch(r'0x[\da-fA-F]+|\d+',right):
                continue
            uses.append((op['start'],op['end'],int(right,0)))
        for use in re.finditer(r'\b'+re.escape(root)+r'\b(?:\s*\+\s*(0x[\da-fA-F]+|\d+))?', code[span[1]:span[2]]):
            lo, hi = span[1]+use.start(),span[1]+use.end()
            if any(a<=lo<b for a,b,_ in edits):
                continue
            if any(a<=lo<b for a,b,_ in uses):
                continue
            # Dynamic indexing needs a measured aggregate view, not a string.
            if re.match(r'\s*(?:\[|\+|-|->|=)',code[hi:]):
                uses = []; break
            uses.append((lo,hi,int(use[1],0) if use[1] else 0))
        if not uses:
            continue
        section = section_bytes(p, owner.module, owner.section, owner.addr)
        if section is None:
            continue
        base, raw = section
        cursor, limit = owner.addr-base, max(off for _,_,off in uses)
        start = cursor
        objects = {}
        while cursor-start <= limit:
            string = string_at(raw,cursor)
            if string is None:
                break
            value,width = string
            if raw[cursor+len(value)+1:cursor+width] != bytes(width-len(value)-1):
                break
            objects[cursor-start] = (value,width)
            cursor += width
        if any(off not in objects for _,_,off in uses):
            continue
        try:
            physical = pool_objects(p, owner.module, owner.section, owner.addr, cursor-start)
            if not physical or any(owner.addr <= obj.addr+r['offset'] < base+cursor
                                   for obj in physical for r in payload(p,obj)[1]):
                continue
        except (ValueError, KeyError):
            continue
        prefix = 'fzgx_pool_strings_'+anchor
        storage = 'const char' if owner.section == '.rodata' else 'char'
        definitions = [f'static {storage} {prefix}_{off:X}[{width}] = {c_literal(value)};'
                       for off,(value,width) in objects.items()]
        for lo,hi,off in uses:
            edits.append((lo,hi,f'(({typ} *){prefix}_{off:X})'))
        body = text
        for lo,hi,value in sorted(edits,reverse=True):
            body = body[:lo]+value+body[hi:]
        at = declaration.start()
        definitions = '\n'.join(definitions)+'\n'
        out.append(('native string objects '+anchor,body[:at]+definitions+body[at:]))
    return out


def initialized_data_views(p, symbol, text):
    """Recover native data objects hidden behind an extern aggregate view.

    MWCC introduces its shared data base for separate initialized objects.
    Keeping the whole region behind one pointer changes both address folding
    and the order of the data and literal bases in the prologue.
    """
    import struct
    from .dataimport import number, payload, pool_objects
    sym = p.resolve(symbol)
    function = re.search(r'\n[^\n;{}]*\b' + re.escape(sym.name) + r'\s*\([^;{}]*\)\s*\{', text)
    if not function:
        return
    pattern = (r'(?:(?:struct\s+)?\w+\s*\*\s*)?(\w+)\s*=\s*'
               r'\((?:struct\s+)?(\w+)\s*\*\)\s*&?(lbl_\w+)\s*;')
    for model in re.finditer(pattern, text[function.start():]):
        var, tag, base = model.groups()
        known = p.symbols(sym.module).get(base)
        if not known or known.section != '.data':
            continue
        members = struct_text(tag, text)
        if members is None:
            continue
        decls = field_decls(members)
        used = sorted(set(re.findall(r'\b' + re.escape(var) + r'\s*->\s*(\w+)', text)))
        byte_offsets = {int(m[1], 0) for m in re.finditer(
            r'\(\s*u8\s*\*\s*\)\s*' + re.escape(var) + r'\s*\+\s*(0x[\da-fA-F]+|\d+)\b', text)}
        if byte_offsets:
            is_tag = re.search(r'\bstruct\s+' + re.escape(tag) + r'\s*\{', text)
            all_fields, error = probe_layout(p, sym.module, text[:function.start()],
                'struct ' + tag if is_tag else tag, list(decls), decls, symbol)
            if error:
                continue
            used = sorted(set(used) | {n for n, m in all_fields.items() if m[0] in byte_offsets})
        scalar = ('u32', 's32', 'f32', 'char', 'u8', 'char *', 'void *', 'const char *', 'const void *', 'const u8 *')
        # Other member types (struct tables such as {u16, u16, u32, char *} rows) are emitted as
        # retail words through the union view below; their indexed uses keep MWCC's object
        # addressing (`addi rT, base, off; lwzx rD, rT, rI`), which a folded pointer never gives.
        if not used or any(n not in decls or decls[n][0] is None
                           or (decls[n][0] in scalar and len(decls[n][1]) > 1) for n in used):
            continue
        statement = model[0]
        rest = text[:function.start()] + text[function.start():].replace(statement, '', 1)
        rest = re.sub(r'(?m)^[ \t]*(?:struct\s+)?' + re.escape(tag) + r'\s*\*\s*' + re.escape(var) + r'\s*;\n', '', rest)
        rest_function = re.search(r'\n[^\n;{}]*\b' + re.escape(sym.name) + r'\s*\([^;{}]*\)\s*\{', rest)
        is_tag = re.search(r'\bstruct\s+' + re.escape(tag) + r'\s*\{', text)
        measured, error = probe_layout(p, sym.module, text[:function.start()],
                                       'struct ' + tag if is_tag else tag, used, decls, symbol)
        if error:
            continue
        # Lifts mix named fields with byte-offset aliases of the same arrays.
        # Normalize only exact field starts proven by the selected layout.
        for name, (offset, _, _, _) in measured.items():
            address = (var + '->' + name) if decls[name][1] else ('&(' + var + '->' + name + ')')
            pattern = r'\(\s*u8\s*\*\s*\)\s*' + re.escape(var) + r'\s*\+\s*(0x[\da-fA-F]+|\d+)\b'
            rest = re.sub(pattern, lambda m: '(u8 *)' + address if int(m[1], 0) == offset else m[0], rest)
        from .sdkimport import masked
        accesses = re.sub(r'\b' + re.escape(var) + r'\s*->\s*\w+', '', masked(rest[rest_function.start():]))
        if re.search(r'\b' + re.escape(var) + r'\b', accesses):
            continue
        fields = sorted((measured[n][0], measured[n][0] + measured[n][1], n) for n in used)
        extent = fields[-1][1]
        # A trailing string may end unaligned where the retail section itself ends.
        if any(lo % 4 or (hi % 4 and not (i == len(fields) - 1 and decls[n][0] in ('char', 'u8')))
               for i, (lo, hi, n) in enumerate(fields)):
            continue
        if any(a[1] > b[0] for a, b in zip(fields, fields[1:])):
            continue
        raw_section = section_bytes(p, sym.module, '.data')
        if raw_section is None:
            continue
        origin, raw = raw_section
        raw = raw[known.addr - origin:known.addr - origin + extent]
        if len(raw) != extent:
            continue
        relocations = {}
        try:
            for obj in pool_objects(p, sym.module, '.data', known.addr, extent):
                _, relocs = payload(p, obj)
                for rel in relocs:
                    offset = obj.addr + rel['offset'] - known.addr
                    if 0 <= offset < extent:
                        if rel['kind'] != 1 or offset % 4 or rel['addend'] < 0:
                            raise ValueError('unsupported initialized pointer')
                        relocations[offset] = rel
        except (ValueError, KeyError):
            continue
        declarations, definitions = set(), []
        prefix = 'fzgx_pool_native_' + base
        def value(offset):
            rel = relocations.get(offset)
            if rel:
                alias = rel['symbol'] + '__fzgx_offset_%X' % rel['addend']
                declarations.add('extern u8 ' + alias + '[];')
                return '(u32)' + alias
            return '0x%08X' % struct.unpack_from('>I', raw, offset)[0]
        cursor = 0
        valid = True
        for lo, hi, name in fields:
            if cursor < lo:
                definitions.append('static u32 %s_gap_%X[%d] = {%s}; /* fzgx-allow: A1 measured pool bytes and bindings */' %
                                   (prefix, cursor, (lo - cursor) // 4, ', '.join(value(i) for i in range(cursor, lo, 4))))
            ty, dims, declaration = decls[name]
            native = prefix + '_' + name
            if ty not in scalar or ('*' in ty and any(i not in relocations and any(raw[i:i + 4]) for i in range(lo, hi, 4))):
                # Inferred pointer arrays sometimes extend into adjacent text.
                # Keep their bounds, but store non-pointer words as words rather
                # than manufacturing literal pointer casts from string bytes.
                definitions.append('static union {u32 words[%d]; %s} %s = {{%s}}; /* fzgx-allow: A1 measured pool bytes and bindings */' %
                                   ((hi - lo) // 4, fdef(decls[name], 'view'), native,
                                    ', '.join(value(i) for i in range(lo, hi, 4))))
                native += '.view'
                values = None
            elif ty in ('char', 'u8'):
                if any(lo <= i < hi for i in relocations):
                    # A saved string view may span later pointer tables.
                    # Preserve the view while giving their relocations full
                    # word initializers; never turn pointer slots into zeros.
                    definitions.append('static union {u32 words[%d]; %s} %s = {{%s}}; /* fzgx-allow: A1 measured pool bytes and bindings */' %
                                       ((hi - lo) // 4, fdef(decls[name], 'view'), native,
                                        ', '.join(value(i) for i in range(lo, hi, 4))))
                    native += '.view'
                    values = None
                else:
                    values = ', '.join('0x%02X' % byte for byte in raw[lo:hi])
            elif ty == 'f32':
                if any(lo <= i < hi for i in relocations):
                    valid = False
                    break
                try:
                    values = ', '.join(number(raw[i:i + 4], ty) for i in range(lo, hi, 4))
                except ValueError:
                    valid = False
                    break
            else:
                values = ', '.join(('(' + ty + ')' if '*' in ty else '') + value(i) for i in range(lo, hi, 4))
            if values is not None:
                initializer = '{' + values + '}' if dims else values
                definitions.append('static ' + fdef(decls[name], native).rstrip(';') + ' = ' + initializer + '; /* fzgx-allow: A1 measured pool bytes and bindings */')
            rest = re.sub(r'\b' + re.escape(var) + r'\s*->\s*' + re.escape(name) + r'\b', native, rest)
            cursor = hi
        if not valid:
            continue
        block = '\n'.join(sorted(declarations)) + '\n' + '\n'.join(definitions) + '\n'
        at = re.search(r'\n[^\n;{}]*\b' + re.escape(sym.name) + r'\s*\([^;{}]*\)\s*\{', rest).start()
        yield 'native initialized data objects ' + base, rest[:at] + '\n' + block + rest[at:]
        # MWCC numbers a TU's section bases in the order earlier functions first used them: a
        # retail TU that addressed .data off its base before its literal pool gives the data base
        # the higher callee-saved register (winning fn_15_5730, title fn_8_A3A4). A primer that
        # addresses three or more of the objects through the base, ahead of any pool primer,
        # reproduces that order; the .fzgxpool section is dropped at integration.
        sinks = [prefix + '_' + n for _, _, n in fields]
        if len(sinks) < 3:
            sinks += [d.split('[', 1)[0].split()[-1] for d in definitions if '_gap_' in d.split('=', 1)[0]]
        if len(sinks) >= 3:
            primer = ('#pragma section code_type ".fzgxpool"\n'
                      '__declspec(section ".fzgxpool") static void fzgx_data_base_prime(void) {\n'
                      '    const void *volatile s;  /* fzgx-allow: S2 data base primer sink: the retail TU addressed .data '
                      'off its section base before its literal pool; the section is dropped at integration */\n'
                      + ''.join('    s = &%s;\n' % (n.split('.')[0]) for n in sinks) +
                      '}\n#pragma section code_type ".text"\n')
            head = rest[:at]
            lead = head.find('#pragma section code_type ".fzgxpool"')
            includes = list(re.finditer(r'^#include[^\n]*\n', head, re.M))
            top = includes[-1].end() if includes else 0
            if lead >= 0:
                top = min(top, lead) if top <= lead else lead
            # Word-union views name the member's own type: keep the block after that type's definition.
            for tname in set(re.findall(r'\b([A-Za-z_]\w*)\s+view\b', block)):
                defined = list(re.finditer(r'\}\s*' + re.escape(tname) + r'\s*;\n|\bstruct\s+' + re.escape(tname)
                                           + r'\s*\{.*?\n\};\n', head, re.S))
                if defined and defined[-1].end() > top and (lead < 0 or defined[-1].end() <= lead):
                    top = defined[-1].end()
            yield ('native initialized data objects ' + base + ', data base first',
                   rest[:top] + block + primer + rest[top:at] + rest[at:])


def string_run(p, symbol, text, cast=''):
    sym = p.resolve(symbol)
    syms = p.symbols(sym.module)
    first = next((syms[l] for l in re.findall(r"\b(lbl_\d+_data_[0-9A-F]+|lbl_[0-9A-F]{8})\b", text) if syms.get(l) and syms[l].section == '.data'), None)
    sb = section_bytes(p, sym.module, '.data', first.addr if first else None)
    if sb is None:
        return None, ['no raw .data for this module']
    base_addr, raw = sb
    notes = []
    out = text
    uses = {}  # (addr) -> list of (span, replacement builder)
    # byte-pointer models: P = (u8 *)&LBL; ... ((u8 *)(u32)P + N) / (P + N) / P
    for m in re.finditer(r"(\w+)\s*=\s*\(u8 \*\)\s*&(lbl_\d+_data_[0-9A-F]+|lbl_[0-9A-F]{8})\s*;", out):
        pvar, lbl = m.group(1), m.group(2)
        out = out.replace(m.group(0), '')
        out = re.sub(r"\n[ \t]*u8\s*\*\s*%s\s*;" % re.escape(pvar), '', out)
        out = re.sub(r"\(u8 \*\)\s*\(u32\)\s*%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)" % re.escape(pvar), lambda mm: f"{lbl} + {int(mm.group(1), 0)}", out)
        out = re.sub(r"\b%s\s*\+\s*(0x[0-9A-Fa-f]+|\d+)" % re.escape(pvar), lambda mm: f"{lbl} + {int(mm.group(1), 0)}", out)
        out = re.sub(r"\b%s\b" % re.escape(pvar), lbl, out)
    addrs = {}
    def repl_use(mm):
        lbl, off = mm.group(1), int(mm.group(2) or '0', 0)
        s = syms.get(lbl)
        if s is None or s.section != '.data':
            return mm.group(0)
        a = s.addr + off
        st = string_at(raw, a - base_addr)
        if st is None or (a - 1 - base_addr >= 0 and raw[a - 1 - base_addr] != 0 and a != s.addr):
            addrs[a] = None
            return mm.group(0)
        addrs[a] = st[0]
        return c_literal(st[0])
    pat = re.compile(r"(?:\((?:const )?(?:char|u8|void) \*\)\s*)?&?\b(lbl_\d+_data_[0-9A-F]+|lbl_[0-9A-F]{8})\b(?:\s*\+\s*(0x[0-9A-Fa-f]+|\d+))?(?!\s*\[|\s*\.|\w)")
    fm0 = re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), out)
    if not fm0:
        return None, ['function definition not found']
    head, tail = out[:fm0.start()], out[fm0.start():]
    # string literals are `char[]`: uses typed as u8/void pointers keep an explicit cast
    def repl_use2(mm):
        r = repl_use(mm)
        if r.startswith('"') and mm.group(0).lstrip().startswith('('):
            return mm.group(0)[:mm.group(0).index(')') + 1] + r
        if r.startswith('"') and cast:
            return cast + r
        return r
    out = head + pat.sub(repl_use2, tail)
    if not addrs:
        return None, ['no string references']
    if any(v is None for v in addrs.values()):
        return None, [f'non-string reference at {a:#x}' for a, v in addrs.items() if v is None][:3]
    lo, hi = min(addrs), max(addrs)
    # retail addresses the strings off the TU's first .data object: when that object starts
    # before the string run, the unit reproduces the bytes in between as a private pad
    pad = ''
    bases = [syms[l] for l in set(re.findall(r"\b(lbl_\d+_data_[0-9A-F]+|lbl_[0-9A-F]{8})\b", text)) if syms.get(l) and syms[l].section == '.data' and syms[l].addr < lo]
    if bases:
        b0 = min(bases, key=lambda s: s.addr)
        # mwcc parses initializers slowly: a 16 KB byte list held a whole compile chunk for
        # 10 s, so the pad is capped and written as words
        if lo - b0.addr > 0x2000 or (lo - b0.addr) % 4 or b0.addr % 4:
            return None, [f'pad from {b0.name} to the string run is {lo - b0.addr:#x} bytes']
        pb = raw[b0.addr - base_addr:lo - base_addr]
        words = [int.from_bytes(pb[i:i + 4], 'big') for i in range(0, len(pb), 4)]
        lines = ["    " + ", ".join(f"0x{w:08X}" for w in words[i:i + 8]) + "," for i in range(0, len(words), 8)]
        pad = f"static u32 fzgx_data_{b0.name}[{len(words):#x}] = {{  /* fzgx-allow: A1 retail data bytes: the TU's .data objects before its string literals; dropped at integration */\n" + "\n".join(lines) + "\n};\n\n"
    run, a = [], lo
    while a <= hi:
        st = string_at(raw, a - base_addr)
        if st is None:
            return None, [f'string run broken at {a:#x}']
        run.append(st[0])
        a += st[1]
    for lbl in set(re.findall(r"\b(lbl_\d+_data_[0-9A-F]+|lbl_[0-9A-F]{8})\b", text)):
        if syms.get(lbl) and lo <= syms[lbl].addr <= hi:
            out = re.sub(r"\n[^\n]*\bextern\b[^\n;]*\b%s\b[^\n;]*;" % re.escape(lbl), '', out)
    if not re.search(r"\bOSReport\s*\(", out.split('{')[0]) and 'extern void OSReport' not in out:
        decl = "extern void OSReport(const char *, ...);\n"
    else:
        decl = ''
    prim = '#pragma section code_type ".fzgxpool"\nstatic void fzgx_string_layout(void) {\n    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */\n'
    prim += "".join(f"    OSReport({c_literal(s)});\n" for s in run)
    prim += '}\n#pragma section code_type ".text"\n\n'
    fm = re.search(r"\n[^\n;{}]*\b%s\s*\([^;{}]*\)\s*\{" % re.escape(sym.name), out)
    if not fm:
        return None, ['function definition not found']
    out = out[:fm.start() + 1] + decl + pad + prim + out[fm.start() + 1:]
    notes.append(f'{len(addrs)} string uses, run of {len(run)} literals from {lo:#x}')
    return out, notes


def _diff_rows_unused(r):
    rows = r._rows if r._rows else ([], [])
    return sum(1 for l, rr in zip(*rows) if (l.get('diff_kind') or 'DIFF_NONE') != 'DIFF_NONE' or (rr.get('diff_kind') or 'DIFF_NONE') != 'DIFF_NONE')



def tu_section_layout(p, symbol, body, check):
    """Proposals: retail BSS objects defined in the unit (per dtk symbol / per referenced field),
    each also with the TU's string run reproduced, and the string run alone."""
    if not re.search(r"\blbl_(?:\d+_(?:bss|data)_[0-9A-F]+|[0-9A-F]{8})\b", body):
        return []
    out = []
    cache = {}
    bases = []
    retail_bases = set()
    rows = check._rows if check is not None and check._rows else ([], [])
    for r in rows[0]:
        m = re.match(r"addi r\d+, r\d+, (lbl_\w+)@l$", (r.get('instruction') or {}).get('formatted') or '')
        if m:
            retail_bases.add(m.group(1))
    for mode in ('dtk', 'split'):
        try:
            text, notes = tu_objects(p, symbol, body, mode, cache, retail_bases)
        except (ValueError, KeyError, IndexError, AttributeError, OSError):
            text = None
        if text:
            out.append((f'define retail TU bss objects ({mode})', text))
            bases.append((mode, text))
            try:
                for label, dual_text in initialized_data_views(p, symbol, text):
                    out.append((f'{label} + retail TU bss ({mode})', dual_text))
            except (ValueError, KeyError, IndexError, AttributeError, OSError):
                pass
    for name, base in bases + [('body', body)]:
        for cast in ('', '(u8 *)'):
            try:
                text, notes = string_run(p, symbol, base, cast)
            except (ValueError, KeyError, IndexError, AttributeError, OSError):
                text = None
            if text:
                out.append((f'reproduce retail string run ({name}{", cast" if cast else ""})', text))
    return out
