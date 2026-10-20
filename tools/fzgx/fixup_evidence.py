"""Retail-derived repair candidates and diagnostics; no search or compilation."""
from __future__ import annotations

import ast
import itertools
import json
import math
import re
import struct
import time
from pathlib import Path
from typing import Dict, List, Optional, Tuple

from . import oracle, stuck
from .project import STATE_DIR, Project

BRANCH_INV = {("beq", "bne"), ("bne", "beq"), ("blt", "bge"), ("bge", "blt"), ("bgt", "ble"), ("ble", "bgt")}
FLOAT_PAIRS = {"fsubs", "fsub", "fadds", "fadd", "fmuls", "fmul", "fdivs", "fdiv", "fmadds", "fmadd", "fmsubs", "fmsub", "frsp"}

INT_TYPES = ["s8", "u8", "s16", "u16", "s32", "u32", "int", "unsigned int", "unsigned", "char", "unsigned char",
             "short", "unsigned short", "long", "unsigned long", "signed char"]
FLIP = {"s8": "u8", "u8": "s8", "s16": "u16", "u16": "s16", "s32": "u32", "u32": "s32",
        "int": "u32", "unsigned int": "s32", "unsigned": "s32", "char": "u8", "unsigned char": "s8", "signed char": "u8",
        "short": "u16", "unsigned short": "s16", "long": "u32", "unsigned long": "s32"}
WIDEN = {"s8": ["s16", "s32"], "u8": ["u16", "u32"], "s16": ["s8", "s32"], "u16": ["u8", "u32"],
         "s32": ["s16", "s8"], "u32": ["u16", "u8"], "int": ["s16", "s8"], "char": ["s16", "s32"], "short": ["s8", "s32"]}
TYPE_RE = "|".join(re.escape(t) for t in sorted(INT_TYPES, key=len, reverse=True))
# Pointee signedness matters too: loading through char* versus u8* changes sign
# extension even when the pointer itself occupies the same register.
DECL_RE = re.compile(rf"(?<![\w.>])(?:const\s+)?({TYPE_RE})(?:\s+(?:\*\s*)*|\s*\*+\s*)([A-Za-z_]\w*(?:\s*\[[^\]]*\])?)(?=\s*[;,=()\[])")


def _kinds(res: oracle.CheckResult) -> Dict[str, int]:
    lrows, rrows = getattr(res, "_rows", ([], []))
    return stuck.classify_rows(lrows, rrows)


def _wants_type_flip(counts: Dict[str, int], diffs: List[Tuple[str, str]]) -> bool:
    if any(k.startswith("op:cmp") for k in counts) or counts.get("ins:ext"):
        return True
    text = " ".join(t + " " + o for t, o in diffs)
    return bool(re.search(r"\b(extsh|extsb|clrlwi|cmplw|cmpw|cmplwi|cmpwi|rlwinm)\b", text)) or "@" in text


def _decl_sites(body: str, fn_span: Tuple[int, int]) -> List[Tuple[int, int, str, str]]:
    """Integer locals, fields, globals and called functions' return types affect codegen."""
    out = []
    for m in DECL_RE.finditer(body):
        if m.start() > fn_span[1]:
            break
        typ, name = m.group(1), m.group(2).split("[")[0].strip()
        # must be used inside the function to matter
        if re.search(rf"\b{re.escape(name)}\b", body[fn_span[0]:fn_span[1]]):
            out.append((m.start(1), m.end(1), typ, name))
    return out


def _function_span(text: str, name: str) -> Optional[Tuple[int, int]]:
    m = re.search(rf"\b{re.escape(name)}\s*\([^;{{]*\)\s*\{{", text)
    if not m:
        return None
    depth, i = 0, m.end() - 1
    while i < len(text):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return m.start(), i + 1
        i += 1
    return None


def _tu_of(p: Project, sym) -> Optional[str]:
    """The TU file that holds this function per tus.json, carved or not."""
    try:
        for t in p.tu_map(sym.module).values() if isinstance(p.tu_map(sym.module), dict) else []:
            pass
    except Exception:
        pass
    import json
    path = p.module_config_dir(sym.module) / "tus.json"
    if not path.exists():
        return None
    try:
        d = json.loads(path.read_text())
    except ValueError:
        return None
    for t in d.get("tus", []):
        if sym.name in t.get("functions", []):
            return f"{p.module_src_prefix(sym.module)}/{t['file']}"
    return None


def string_literals(p: Project, module: str, body: str, base: oracle.CheckResult) -> List[Tuple[str, str]]:
    """Correct private string literals using the relocation's retail object.

    Identical instructions do not prove the strings agree. Read both strings
    before proposing an edit, then let the ordinary oracle verify its binding.
    """
    from .poolfix import Elf
    obj = getattr(base, '_object', None)
    if obj is None:
        return []
    elf = Elf(obj.read_bytes())
    own = {s['name']: s for s in elf.symbols()}
    syms = p.symbols(module)
    targets = dict(syms)
    targets.update({f'{s.name}_{s.addr:08X}': s for s in syms.values()})
    pattern = r'([A-Za-z_.$@][\w.$@]*)@(?:ha|l|sda21)\b'
    pairs, references, bindings = set(), set(), {}
    for left, right in zip(*getattr(base, '_rows', ([], []))):
        lt, rt = re.search(pattern, stuck._fmt(left)), re.search(pattern, stuck._fmt(right))
        if not lt or not rt:
            continue
        target, source = targets.get(lt[1]), own.get(rt[1])
        if not target or not source:
            continue
        expected = p.string_at(module, target.name)
        complete_string = expected is not None and len(expected.encode('latin1'))+1 == target.size
        if complete_string and source['shndx'] == 0 and re.fullmatch(r'[A-Za-z_]\w*', source['name']):
            references.add((source['name'], expected))
        if not source['name'].startswith('@') or not 0 < source['shndx'] < len(elf.sections):
            continue
        section = elf.sections[source['shndx']]
        start = section['offset'] + source['value']
        raw = bytes(elf.data[start:start + source['size']])
        if expected is None or not raw.endswith(b'\0') or b'\0' in raw[:-1]:
            continue
        current = raw[:-1].decode('latin1')
        if target.section in ('.rodata', '.sdata2'):
            bindings.setdefault(current, set()).add(target.name)
        if complete_string and current != expected:
            pairs.add((current, expected))
    out = []
    # A literal can be the base of a larger shared string pool. Replacing an
    # external pool with its first NUL-terminated string leaves interior uses
    # out of bounds even when every instruction word still matches.
    for current, names in sorted(bindings.items()):
        if len(names) != 1:
            continue
        name = next(iter(names))
        edits = []
        for token in re.finditer(r'"(?:\\.|[^"\\])*"', body):
            if body[body.rfind('\n', 0, token.start())+1:token.start()].lstrip().startswith('#'):
                continue
            try:
                value = ast.literal_eval(token[0])
            except (ValueError, SyntaxError):
                continue
            if value == current:
                edits.append(token.span())
        if edits:
            text = body
            for start, end in reversed(edits):
                text = text[:start]+name+text[end:]
            if not re.search(r'\bextern\s+(?:const\s+)?(?:char|s8|u8)\s+'+re.escape(name)+r'\s*\[', body):
                text = 'extern char '+name+'[];\n'+text
            out.append(('bind recovered shared-pool strings '+name, text))
            from .evidence import retail_bytes
            raw = retail_bytes(p, module, name, 0, targets[name].size)
            if raw and raw.endswith(b'\0') and all(c == 0 or 32 <= c < 127 or c in (9,10,13) for c in raw):
                # Preserve all string boundaries and pool padding. The oracle
                # must bind the complete initializer to the shared retail data.
                literal = json.dumps(raw[:-1].decode('ascii')).replace('\\u0000', '\\000')
                text = body
                for start, end in reversed(edits):
                    text = text[:start]+literal+text[end:]
                if text != body:
                    out.append(('retain recovered shared-pool strings '+name, text))
    for name, expected in sorted(references):
        for token in re.finditer(rf'\b{re.escape(name)}\b', body):
            line = body[body.rfind('\n', 0, token.start()) + 1:token.start()]
            if line.lstrip().startswith('extern '):
                continue
            if re.match(r'\s*(?:\[|\+|-)', body[token.end():]):
                continue
            out.append((f'retail string for {name}', body[:token.start()] + json.dumps(expected) + body[token.end():]))
    for current, expected in sorted(pairs):
        for token in re.finditer(r'"(?:\\.|[^"\\])*"', body):
            try:
                value = ast.literal_eval(token[0])
            except (ValueError, SyntaxError):
                continue
            if value == current:
                out.append((f'retail string {expected!r}', body[:token.start()] + json.dumps(expected) + body[token.end():]))
    # Pooled strings are addressed through one section base, so later strings
    # have no instruction relocation of their own. Recover their boundaries
    # from the emitted symbols and retain retail padding when literals shrink.
    pools = {}
    reloc = re.compile(r'([A-Za-z_.$@][\w.$@]*?)([+-]0x[0-9a-f]+)?@(?:ha|l|sda21)\b')
    for left, right in zip(*getattr(base, '_rows', ([], []))):
        lt, rt = reloc.search(stuck._fmt(left)), reloc.search(stuck._fmt(right))
        target, anchor = targets.get(lt[1]) if lt else None, own.get(rt[1]) if rt else None
        if not target or not anchor or not rt[1].startswith('...data'):
            continue
        delta = (int(lt[2], 0) if lt[2] else 0) - (int(rt[2], 0) if rt[2] else 0) - anchor['value']
        pools.setdefault(anchor['shndx'], set()).add((target.name, delta))
    replacements = {}
    for index, bindings in pools.items():
        if len(bindings) != 1 or not 0 < index < len(elf.sections):
            continue
        name, delta = next(iter(bindings)); target = targets[name]
        section = elf.sections[index]
        layout = p._rel_layout(module)
        regions = layout.values() if module == 'main' else [layout.get(target.section, (0, b''))]
        for private in own.values():
            if private['shndx'] != index or not private['name'].startswith('@') or private['size'] < 2:
                continue
            start = section['offset'] + private['value']
            raw = bytes(elf.data[start:start + private['size']])
            if not raw.endswith(b'\0') or b'\0' in raw[:-1]:
                continue
            address = target.addr + delta + private['value']
            expected = next((data[address - base:address - base + 4096].split(b'\0', 1)[0]
                             for base, data in regions if base <= address < base + len(data)
                             and b'\0' in data[address - base:address - base + 4096]), None)
            if expected is None or any(c >= 128 for c in expected) or raw[:-1] == expected:
                continue
            replacements.setdefault(raw[:-1].decode('latin1'), set()).add(expected.decode('ascii'))
    edits = []
    for token in re.finditer(r'"(?:\\.|[^"\\])*"', body):
        try:
            current = ast.literal_eval(token[0])
        except (ValueError, SyntaxError):
            continue
        choices = replacements.get(current, set())
        if len(choices) == 1:
            edits.append((token.start(), token.end(), current, next(iter(choices))))
    for padded in (False, True):
        text = body
        for start, end, current, expected in reversed(edits):
            if padded:
                expected += '\0' * max(0, len(current) - len(expected))
            literal = json.dumps(expected).replace('\\u0000', '\\000')
            text = text[:start] + literal + text[end:]
        if text != body:
            out.insert(0, ('recover pooled strings' + (' with padding' if padded else ''), text))
    return out


def optimizer_pragmas(body: str, name: str) -> List[Tuple[str, str]]:
    """Recover optimizer state lost when a function is extracted from its TU.

    These passes can change otherwise correct register allocation and scheduling.
    Keep the state local to the function so a later TU merge does not inherit it.
    """
    from .sdkimport import masked
    code = masked(body)
    span = _function_span(code, name)
    if span is None:
        return []
    start = body.rfind('\n', 0, span[0]) + 1
    out = []
    # opt_pointer_analysis never improved a candidate over twelve corpus reports (0 of 1,205)
    # `scheduling` was missing from this list while 24 functions in this tree already carry
    # `#pragma scheduling off` in their matched source, and findings/110 shows the -O4,p
    # scheduler hoisting independent argument setup out of source order. Proposing it lets the
    # engine try the one optimizer that changes *instruction order* rather than values.
    for option in ('peephole', 'opt_propagation', 'opt_common_subs', 'opt_lifetimes', 'opt_dead_assignments',
                   'opt_strength_reduction', 'opt_loop_invariants', 'scheduling'):
        stack = []
        for pragma in re.finditer(rf'(?m)^[ \t]*#pragma\s+{option}\s+(on|off|reset)\b',code[:span[0]]):
            if pragma[1] == 'reset':
                if stack:
                    stack.pop()
            else:
                stack.append(pragma)
        # Source repairs can make an earlier optimizer workaround obsolete.
        # Preserve nested pragma state while allowing either setting again.
        if stack:
            pragma = stack[-1]
            value = 'on' if pragma[1] == 'off' else 'off'
            a,b = pragma.span(1)
            text = body[:a]+value+body[b:]
        else:
            value = 'off'
            text = (body[:start] + f'#pragma {option} off\n' + body[start:span[1]] +
                    f'\n#pragma {option} reset\n' + body[span[1]:])
        out.append((f'{option} {value}', text))
    return out


def _layout_primer_ranges(body: str, code: str) -> List[Tuple[int, int]]:
    """Layout primers encode measured bytes, not repairable function expressions."""
    ranges, start = [], None
    for directive in re.finditer(r'(?m)^[ \t]*#pragma[ \t]+section[ \t]+code_type[ \t]+"([^"]+)"[^\n]*', body):
        if not code[directive.start():directive.end()].lstrip().startswith('#pragma'):
            continue
        if directive[1] == '.fzgxpool':
            if start is None:
                start = directive.start()
        elif start is not None:
            ranges.append((start, directive.start()))
            start = None
    if start is not None:
        ranges.append((start, len(body)))
    # Explicit section attributes also occur without a surrounding section pragma.
    for declaration in re.finditer(r'__declspec\s*\(\s*section\s+"\.fzgxpool"\s*\)\s+[^;{}]*?\b(\w+)\s*\([^;{}]*\)\s*\{', body):
        if not code[declaration.start():].startswith('__declspec'):
            continue
        span = _function_span(code, declaration[1])
        if span:
            ranges.append((declaration.start(), span[1]))
    return ranges


def float_literals(p: Project, symbol: str, body: str, base: oracle.CheckResult) -> List[Tuple[str, str]]:
    """Recover incorrect floating literals from the retail relocation's bytes.

    Match the emitted literal's exact bits before replacing C tokens. Try each
    occurrence and all equal occurrences together: changing only one can split
    a shared constant load and obscure an otherwise exact repair.
    """
    from .poolfix import Elf
    sym = p.resolve(symbol)
    span = _function_span(body, sym.name)
    if span is None or getattr(base, '_object', None) is None:
        return []
    elf = Elf(base._object.read_bytes())
    own = {s['name']: s for s in elf.symbols()}
    symbols = p.symbols(sym.module)
    targets = dict(symbols)
    targets.update({f'{s.name}_{s.addr:08X}': s for s in symbols.values()})
    reloc = re.compile(r'([A-Za-z_.$@][\w.$@]*?)([+-]0x[0-9a-f]+)?@(?:ha|h|l|sda21)\b')
    floats = set()
    for left, right in zip(*base._rows):
        if (left.get('diff_kind') or 'DIFF_NONE') == 'DIFF_NONE':
            continue
        lt, rt = reloc.search(stuck._fmt(left)), reloc.search(stuck._fmt(right))
        if not lt or not rt:
            continue
        target = targets.get(lt[1])
        offset = int(lt[2], 0) if lt[2] else 0
        old_offset = int(rt[2], 0) if rt[2] else 0
        private = own.get(rt[1])
        width = {'lfs': 4, 'lfd': 8}.get(stuck._mn(left))
        if not target or not private or not width or not private['name'].startswith('@'):
            continue
        raw = p.bytes_at(sym.module, target.name)
        if raw is None or offset < 0 or offset + width > len(raw):
            continue
        if (not 0 < private['shndx'] < len(elf.sections) or old_offset < 0
                or private['size'] < old_offset + width):
            continue
        pos = elf.sections[private['shndx']]['offset'] + private['value'] + old_offset
        current = bytes(elf.data[pos:pos + width])
        expected = raw[offset:offset + width]
        if current != expected:
            floats.add((width, current, expected))
    # A whole-TU pool often has only one lis/addi relocation: its later loads
    # carry ordinary offsets. Follow both objects' bases rather than expecting
    # a relocation on every lfs/lfd. Conflicting alignments are not evidence.
    from .evidence import memory_loads, retail_bytes, object_jump_tables
    inferred, locations = {}, {}
    left_loads = memory_loads(base._rows[0], object_jump_tables(p.target_object_for(sym), sym.name, p, sym.module))
    right_loads = memory_loads(base._rows[1], object_jump_tables(base._object, sym.name))
    for i, target in left_loads.items():
        private = right_loads.get(i)
        if not private or target['op'] not in ('lfs', 'lfd') or target['op'] != private['op']:
            continue
        anchor = own.get(private['symbol'])
        if not anchor or not private['symbol'].startswith(('@', '...rodata')):
            continue
        if not 0 < anchor['shndx'] < len(elf.sections):
            continue
        section = elf.sections[anchor['shndx']]
        offset, width = anchor['value'] + private['offset'], private['width']
        if offset < 0 or offset + width > section['size']:
            continue
        if any(r['type'] == 4 and r['info'] == anchor['shndx'] and
               any(offset <= struct.unpack_from('>I', elf.data, pos)[0] < offset + width
                   for pos in range(r['offset'], r['offset'] + r['size'], 12)) for r in elf.sections):
            continue
        current = bytes(elf.data[section['offset'] + offset:section['offset'] + offset + width])
        expected = retail_bytes(p, sym.module, target['symbol'], target['offset'], width)
        if expected is not None:
            inferred.setdefault((width, current), set()).add(expected)
            locations.setdefault((width, current), set()).add((target['symbol'], target['offset']))
    # Equal values can still occupy the wrong shared-pool offsets. They need
    # symbolic layout candidates even though no literal value needs correcting.
    floats.update((width, current, next(iter(expected))) for (width, current), expected in inferred.items()
                  if len(expected) == 1)
    from .sdkimport import masked
    code = masked(body)
    primers = _layout_primer_ranges(body, code)
    out, all_edits, bound_edits = [], {}, {}
    from .fixup_source import declared_types, record_layouts, record_tag
    _, variables = declared_types(code, span[0])
    declared_layouts = record_layouts(code, span[0], variables)
    views = {}
    for assignment in re.finditer(r'\b(\w+)\s*=\s*(?:\([^();]+\)\s*)*&?\s*(\w+)\s*;',code[span[0]:span[1]]):
        root,anchor = assignment[1],assignment[2]
        if anchor not in targets or len(re.findall(r'\b'+re.escape(root)+r'\s*=(?!=)',code[span[0]:span[1]]))!=1:
            continue
        for field,(offset,ty,count) in declared_layouts.get(record_tag(variables.get(root,'')),{}).items():
            if count is None and ty in ('f32','float','f64','double'):
                views[anchor,offset,4 if ty in ('f32','float') else 8]=root+'->'+field
    view_edits=[]
    # Existing recovered views used to suppress binding altogether. Match bits
    # against the retail loads, then use the already-declared field and base.
    values={}
    for target in left_loads.values():
        key=target['symbol'],target['offset'],target['width']
        if target['op'] in ('lfs','lfd') and key in views:
            raw=retail_bytes(p,sym.module,*key)
            if raw is not None:
                values.setdefault((key[2],raw),set()).add(views[key])
    for token in re.finditer(r'(?<![\w.])-?\d+\.\d*(?:[eE][+-]?\d+)?[fF]?(?![\w.])',code[span[0]:span[1]]):
        width=4 if token[0].lower().endswith('f') else 8
        try:
            raw=struct.pack('>f' if width==4 else '>d',float(token[0].rstrip('fF')))
        except (ValueError,OverflowError):
            continue
        choices=values.get((width,raw),())
        if len(choices)==1:
            view_edits.append((span[0]+token.start(),span[0]+token.end(),next(iter(choices))))
    if view_edits:
        text=body
        for a,b,value in reversed(view_edits):text=text[:a]+value+text[b:]
        out.append(('bind recovered shared-pool existing fields',text))
    ambiguous = set()
    for declaration in re.finditer(r'\bconst\s+(f32|f64|float|double)\s+(\w+)\s*=\s*(-?\d+\.\d*(?:[eE][+-]?\d+)?[fF]?)\s*;', code[:span[0]]):
        if any(a <= declaration.start() < b for a, b in primers):
            continue
        width = 4 if declaration[1] in ('f32', 'float') else 8
        target, private = targets.get(declaration[2]), own.get(declaration[2])
        if not target or not private or private['size'] != width:
            continue
        raw = retail_bytes(p, sym.module, target.name, 0, width)
        if raw is None:
            continue
        value = struct.unpack('>f' if width == 4 else '>d', raw)[0]
        if math.isfinite(value):
            replacement = repr(value) + ('f' if width == 4 else '')
            if replacement != declaration[3]:
                all_edits[declaration.span(3)] = replacement
    for width, current, expected in sorted(floats):
        fmt = '>f' if width == 4 else '>d'
        value = struct.unpack(fmt, expected)[0]
        if not math.isfinite(value):
            continue
        replacement = repr(value) + ('f' if width == 4 else '')
        edits = []
        for token in re.finditer(r'(?<![\w.])-?\d+\.\d*(?:[eE][+-]?\d+)?[fF]?(?![\w.])', code):
            if any(a <= token.start() < b for a, b in primers):
                continue
            if (width == 4) != token[0].lower().endswith('f'):
                continue
            try:
                actual = struct.pack(fmt, float(token[0].rstrip('fF')))
            except (OverflowError, ValueError):
                continue
            if actual == current:
                start, end = token.span()
                edits.append((start, end))
                if current != expected:
                    out.append((f'retail float {token[0]} -> {replacement}', body[:start] + replacement + body[end:]))
                if (start, end) in all_edits and all_edits[start, end] != replacement:
                    ambiguous.add((start, end))
                all_edits[start, end] = replacement
                refs = locations.get((width, current), set())
                if len(refs) == 1:
                    anchor, offset = next(iter(refs))
                    if offset >= 0 and not re.search(r'\b' + re.escape(anchor) + r'\b', code):
                        bound_edits[start, end] = (anchor, offset, width, 'f32' if width == 4 else 'f64')
        if len(edits) > 1 and current != expected:
            combined = body
            for start, end in reversed(edits):
                combined = combined[:start] + replacement + combined[end:]
            out.append((f'all references to retail float {replacement}', combined))
    combined = body
    for (start, end), replacement in sorted(all_edits.items(), reverse=True):
        if (start, end) not in ambiguous:
            combined = combined[:start] + replacement + combined[end:]
    if combined != body:
        out.insert(0, ('recover shared-pool literal values', combined))
    # Integer tables can share the same base as floating literals. Keeping an
    # invented private palette prevents that base from ever matching, even when
    # all float tokens have been rebound. Bind constant-index reads using their
    # emitted object offsets and the aligned retail loads, not guessed values.
    removals = []
    widths = {'u8': 1, 's8': 1, 'u16': 2, 's16': 2, 'u32': 4, 's32': 4, 'f32': 4, 'f64': 8}
    for declaration in re.finditer(r'\bstatic\s+const\s+(u8|s8|u16|s16|u32|s32|f32|f64)\s+(\w+)\s*\[([^\]]*)\]\s*=\s*\{[^{}]*\}\s*;', code):
        if any(a <= declaration.start() < b for a, b in primers):
            continue
        ty, name = declaration[1], declaration[2]
        obj = own.get(name)
        if not obj or not obj['size']:
            continue
        locations_by_index = {}
        for i, private in right_loads.items():
            target = left_loads.get(i)
            anchor = own.get(private['symbol'])
            if not anchor or not target or target['width'] != widths[ty] or private['op'] != target['op']:
                continue
            offset = anchor['value'] + private['offset'] - obj['value']
            if anchor['shndx'] != obj['shndx'] or not 0 <= offset < obj['size'] or offset % widths[ty]:
                continue
            if retail_bytes(p, sym.module, target['symbol'], target['offset'], widths[ty]) is not None:
                locations_by_index.setdefault(offset // widths[ty], set()).add((target['symbol'], target['offset']))
        uses = [m for m in re.finditer(r'\b'+re.escape(name)+r'\s*\[\s*(0x[\da-fA-F]+|\d+)\s*\]', code)
                if not declaration.start() <= m.start() < declaration.end()]
        replacements = {}
        for use in uses:
            options = locations_by_index.get(int(use[1], 0), set())
            if len(options) != 1:
                continue
            anchor, offset = next(iter(options))
            if offset < 0 or re.search(r'\b'+re.escape(anchor)+r'\b', code):
                continue
            replacements[use.span()] = (anchor, offset, widths[ty], ty)
        if replacements:
            bound_edits.update(replacements)
            tokens = [m for m in re.finditer(r'\b'+re.escape(name)+r'\b', code)
                      if not declaration.start() <= m.start() < declaration.end()]
            if len(replacements) == len(tokens):
                removals.append(declaration.span())
    # Express the shared layout in owned C declarations. Code bytes, including
    # load offsets, still have to pass the oracle; this does not patch code or
    # mark unequal pools equivalent.
    layouts = {}
    bound = body
    edits = []
    for (start, end), (anchor, offset, width, ty) in sorted(bound_edits.items(), reverse=True):
        if (start, end) in ambiguous:
            continue
        if any(a <= start < b for a,b in removals):
            continue
        layouts.setdefault(anchor, {})[offset] = (width, ty)
        edits.append((start,end,f'{anchor}.unk_{offset:X}'))
    for start,end in removals:
        edits.append((start,end,''))
    for start,end,value in sorted(edits, reverse=True):
        bound = bound[:start]+value+bound[end:]
    declarations = []
    for anchor, offsets in sorted(layouts.items()):
        cursor = 0
        fields = []
        for offset, (width, ty) in sorted(offsets.items()):
            if offset < cursor or offset % width:
                fields = []
                break
            if offset > cursor:
                fields.append(f'    u8 pad_{cursor:X}[0x{offset - cursor:X}];')
            fields.append(f'    {ty} unk_{offset:X};')
            cursor = offset + width
        if not fields:
            declarations = []
            break
        declarations.append('extern const struct ' + sym.name + '_' + anchor + '_pool {\n'
                            + '\n'.join(fields) + '\n} ' + anchor + ';\n')
    if declarations:
        # Place after includes so the repository's fixed-width types are in scope.
        includes = list(re.finditer(r'^\s*#include[^\n]*\n', bound, re.M))
        pos = includes[-1].end() if includes else 0
        bound = bound[:pos] + '\n' + '\n'.join(declarations) + bound[pos:]
        out.insert(0, ('bind recovered shared-pool fields', bound))
        start = re.search(r'\b' + re.escape(sym.name) + r'\s*\([^;{]*\)\s*\{', bound)
        if start:
            pointers = []
            for anchor in sorted(layouts):
                typ = 'struct ' + sym.name + '_' + anchor + '_pool'
                pointer = 'pool_' + anchor
                pointers.append(f'\n    {typ} *{pointer} = ({typ} *)&{anchor};')
                bound = bound.replace(anchor + '.unk_', pointer + '->unk_')
            start = re.search(r'\b' + re.escape(sym.name) + r'\s*\([^;{]*\)\s*\{', bound)
            bound = bound[:start.end()] + ''.join(pointers) + bound[start.end():]
            out.insert(0, ('retain recovered shared-pool bases', bound))
    return out


def pool_scalar_reads(p, symbol, body, check):
    """Let MWCC pool explicit literals together with its implicit cast biases.

    External struct views preserve offsets but keep generated conversion atoms
    in a separate pool. Recover scalar reads from declared layouts and retail
    bytes; leave dynamic reads and pointer-bearing data alone.
    """
    from .sdkimport import masked, integer_expression
    from .fixup_source import declared_types, record_layouts, member_layout, TYPE
    from .dataimport import BASIC, number
    from .evidence import memory_loads, object_jump_tables, retail_bytes
    sym = p.resolve(symbol)
    code = masked(body)
    span = _function_span(code, sym.name)
    if not span or re.search(r'#pragma\s+(?:pack|options\s+align)\b',code):
        return []
    _, variables = declared_types(code, span[0])
    layouts = record_layouts(code,span[0],variables)
    loads = memory_loads(check._rows[0],object_jump_tables(p.target_object_for(sym),sym.name,p,sym.module))
    # only reads retail makes through a materialised base: a literal retail addresses by its
    # own lis/lo pair is reproduced by the extern declaration, and turning it native pools it
    # behind a base register instead (113 of 405 bodies regressed that way, 2026-09-16)
    displaced = [load for load in loads.values() if load.get('form') == 'displacement']
    # a base read at one offset only is a materialised single literal (`addi r5, r3, sym@l;
    # lfs f0, 0x0(r5)`), also reproduced by the extern; a pool base is read at several offsets
    pools = {load['symbol'] for load in displaced if load['offset'] != 0}
    referenced = {(load['symbol'],load['offset'],load['width']) for load in displaced if load['symbol'] in pools}
    roots = {}
    for name,ty in variables.items():
        obj = p.find_symbol(name,sym.module)
        if obj and obj.section in ('.rodata','.sdata2') and obj.kind == 'object':
            roots[name] = (obj.name,ty)
    # Only a single, fixed initialization qualifies as a constant pool alias.
    for assignment in re.finditer(r'\b(\w+)\s*=\s*(?:\([^();]+\)\s*)*&?\s*(\w+)\s*;',code[span[0]:span[1]]):
        name,owner = assignment[1],assignment[2]
        if owner in roots and len(re.findall(r'\b'+re.escape(name)+r'\s*=(?!=)',code[span[0]:span[1]]))==1:
            roots[name] = (roots[owner][0],variables.get(name,roots[owner][1]))
    for name,owner in re.findall(r'(?m)^#define\s+(\w+)\s+(\w+)\s*$',code[:span[0]]):
        if owner in roots:
            roots[name] = roots[owner]
            variables[name] = roots[owner][1]
    ranges, position, macro = [(span[0],span[1])], 0, None
    for line in code[:span[0]].splitlines(keepends=True):
        if line.lstrip().startswith('#define '):
            macro = position
        position += len(line)
        if macro is not None and not line.rstrip().endswith('\\'):
            ranges.append((macro,position)); macro = None
    edits = []
    for name,(anchor,ty) in roots.items():
        pattern = r'\b'+re.escape(name)+r'((?:\s*(?:->|\.)\s*\w+)*)(?:\s*\[([^]\n]+)\])?'
        for use in re.finditer(pattern,code):
            start,end = use.span()
            if not any(a<=start and end<=b for a,b in ranges):
                continue
            prefix = code[code.rfind('\n',0,start)+1:start]
            wrapper = re.search(r'\(\s*\*\s*\(\s*(?:f32|float|f64|double)\s+(?:volatile\s+)?\*\s*\)\s*&\s*\(\s*$',code[:start])
            closing = re.match(r'\s*\)\s*\)',code[end:]) if wrapper else None
            if (re.match(r'\s*\)*\s*(?:=(?!=)|[+*/&|^-]=|\+\+|--|\[|->|\.)',code[end:])
                    or (re.search(r'(?:&|\+\+|--)\s*\(*\s*$',code[:start]) and not closing)
                    or re.fullmatch(r'\s*(?!return\b)'+TYPE+r'\s+',prefix)
                    or re.search(r'#\s*define\s+$',prefix)):
                continue
            if use[1]:
                field = member_layout(name+re.sub(r'\s+','',use[1]),layouts,variables)
                if not field or field[0]!=name:
                    continue
                _,offset,element,count = field
                if (count is not None) != (use[2] is not None):
                    continue
            else:
                offset,element,count = 0,re.sub(r'\b(?:extern|static|const|volatile)\b|\*','',ty).strip(),None
                if '*' in ty and use[2] is None:
                    continue
            element = re.sub(r'\b(?:const|volatile)\b','',element).strip()
            if element not in ('f32','float','f64','double'):
                continue
            width = BASIC[element][0]
            if use[2]:
                try:
                    index = integer_expression(use[2])
                except (ValueError,SyntaxError):
                    continue
                if index<0 or count is not None and index>=count:
                    continue
                offset += index*width
            if (anchor,offset,width) not in referenced:
                continue
            raw = retail_bytes(p,sym.module,anchor,offset,width)
            if raw is None:
                continue
            try:
                value = number(raw,element)
            except ValueError:
                continue
            edits.append((wrapper.start() if closing else start,end+closing.end() if closing else end,value))
    # the lifter's byte-addressed form: `*(f32 *)((u8 *)root + 0x140)` / `*(f32 *)(root + 0x140)`
    # where root aliases a pool object (fn_1_53830: retail reads the same word through the
    # TU pool base, so the literal must be native for the primer to place it)
    taken = [(a,b) for a,b,_ in edits]
    for name,(anchor,ty) in roots.items():
        pattern = (r'\*\s*\(\s*(?:const\s+)?(f32|float|f64|double)\s*\*\s*\)\s*\(\s*(?:\(\s*(?:const\s+)?u8\s*\*\s*\)\s*)?'
                   + re.escape(name) + r'\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)')
        for use in re.finditer(pattern,code):
            start,end = use.span()
            if not any(a<=start and end<=b for a,b in ranges) or any(a<end and start<b for a,b in taken):
                continue
            if re.match(r'\s*(?:=(?!=)|[+*/&|^-]=|\+\+|--)',code[end:]) or re.search(r'&\s*$',code[:start]):
                continue
            element = use[1]; width = BASIC[element][0]; offset = int(use[2],0)
            if (anchor,offset,width) not in referenced:
                continue
            raw = retail_bytes(p,sym.module,anchor,offset,width)
            if raw is None:
                continue
            try:
                value = number(raw,element)
            except ValueError:
                continue
            edits.append((start,end,value))
    return edits


def native_pool_literals(p, symbol, body, check):
    from .sdkimport import masked
    code = masked(body)
    span = _function_span(code, p.resolve(symbol).name)
    edits = pool_scalar_reads(p, symbol, body, check)
    if not edits or not span:
        return []
    text = body
    for start,end,value in sorted(set(edits),reverse=True):
        text = text[:start]+'('+value+')'+text[end:]
    out = [('recover native shared-pool literals',text)]
    # A readonly pool load can move past unrelated stores. Keep its address
    # expression, so shortening the scalar's lifetime does not split the pool.
    reads = {(a,b) for a,b,_ in edits}
    local = re.compile(r'\b(?:f32|float|f64|double)\s+(\w+)\s*;')
    locals_ = {m[1] for m in local.finditer(code,span[0],span[1])}
    for assignment in re.finditer(r'(?m)^([ \t]*)(\w+)\s*=\s*([^;{}\n]+);',code[span[0]:span[1]]):
        var = assignment[2]
        a,b = span[0]+assignment.start(),span[0]+assignment.end()
        lo,hi = span[0]+assignment.start(3),span[0]+assignment.end(3)
        while code[hi-1:hi].isspace():
            hi -= 1
        if (var not in locals_ or (lo,hi) not in reads
                or re.search(r'&\s*\(*\s*'+re.escape(var)+r'\b',code[span[0]:span[1]])):
            continue
        cursor, count = b, 0
        for following in re.finditer(r'\s*([^;{}]+);',code[b:span[1]]):
            if b+following.start()!=cursor:
                break
            statement = following[1]
            if (re.search(r'\b(?:if|else|while|for|do|switch|case|return|goto|break|continue)\b|\b'+re.escape(var)+r'\b',statement)
                    or ':' in statement or statement.count('(')!=statement.count(')')):
                break
            cursor = b+following.end(); count += 1
            moved = body[:a]+body[b:cursor]+'\n'+body[a:b]+body[cursor:]
            out.append((f'lifetime shared-pool read {var} after {count} statements',moved))
    return out


def numeric_evidence(p, symbol, check):
    from .evidence import conversion_values, object_jump_tables
    if not hasattr(check, '_numeric_values'):
        sym=p.resolve(symbol)
        check._numeric_values=conversion_values(p,sym.module,check._rows[0],
            object_jump_tables(p.target_object_for(sym),sym.name,p,sym.module))
    return check._numeric_values


def rotate_bit_tests(body, name, check):
    """Recover a rotated low-bit test misread as a shifted sign-bit test."""
    from .sdkimport import masked
    code=masked(body);span=_function_span(code,name)
    if not span or not any(re.fullmatch(r'rlwnm\.? r\d+, r\d+, r\d+, 31, 31',stuck._fmt(row)) for row in check._rows[0]):
        return []
    pattern=r'\(\s*(\w+(?:(?:->|\.)\w+)*)\s*<<\s*\(([^();]+)\)\s*\)\s*>>\s*31\b'
    sites=list(re.finditer(pattern,code[span[0]:span[1]]))
    text=body
    for site in reversed(sites):
        value,amount=site.groups()
        replacement='__rlwnm('+value+', ('+amount+') & 31, 31, 31)'
        a,b=span[0]+site.start(),span[0]+site.end();text=text[:a]+replacement+text[b:]
    out = [('retail rotated bit tests intrinsic',text)] if text!=body else []
    from . import fixup_source as source
    operations = []
    source.commutations(body, name, operations)
    edits = []
    for outer in operations:
        if outer['op'] not in ('<', '>=', '&'):
            continue
        rhs = body[slice(*outer['right'])].strip(' ()uUlL')
        if rhs != ('1' if outer['op']=='&' else '0'):
            continue
        lo, hi = outer['left']
        children = [op for op in operations if op['op'] == ('>>' if outer['op']=='&' else '<<')
                    and lo <= op['start'] < op['end'] <= hi]
        if len(children) != 1:
            continue
        shift = children[0]
        value, amount = (body[slice(*shift[k])] for k in ('left','right'))
        value = re.sub(r'^\(\s*(?:s32|u32|int|unsigned int)\s*\)\s*', '', value)
        if outer['op'] == '&':
            amount = '32 - ('+amount+')'
        expression = '__rlwnm('+value+', '+amount+', 31, 31)'
        if outer['op'] != '&':
            expression += ' == 0' if outer['op']=='>=' else ' != 0'
        edits.append((outer['start'], outer['end'], '('+expression+')'))
    for group in ([edits]+[[e] for e in edits] if len(edits)>1 else [edits]):
        text = body
        for a,b,value in sorted(set(group), reverse=True):
            text = text[:a]+value+text[b:]
        if text != body:
            out.append((f'retail rotated low bit ({len(group)} sites)',text))
    out += constant_rotate_bit_tests(body, name, check)
    return list(dict.fromkeys(out))


def constant_rotate_bit_tests(body, name, check):
    """`li rK, N; rlwnm. rD, rS, rK, 31, 31` is `__rlwnm(x, N, 31, 31)` with a constant N:
    a plain `(x & mask)` folds to `rlwinm.` instead. The tested bit is mask 1 << (32 - N);
    lifted bodies often carry the neighbouring bit (fn_3_137AC, fn_1_7F658, fn_3_1A648), so
    single-bit masks one position either side are rewritten too."""
    from .sdkimport import masked
    rows = [stuck._fmt(row) for row in check._rows[0]]
    amounts, consts = set(), {}
    for text in rows:
        m = re.fullmatch(r'li (r\d+), (0x[0-9a-f]+|\d+)', text)
        if m:
            consts[m.group(1)] = int(m.group(2), 0)
        m = re.fullmatch(r'rlwnm\.? r\d+, r\d+, (r\d+), 31, 31', text)
        if m and m.group(1) in consts and 0 < consts[m.group(1)] < 32:
            amounts.add(consts[m.group(1)])
    if not amounts:
        return []
    code = masked(body)
    span = _function_span(code, name)
    if not span:
        return []
    sites = {}
    for site in re.finditer(r'\(\s*((?:\(\s*s32\s*\)\s*)?\w+(?:(?:->|\.)\w+|\[[^\[\]]*\])*)\s*&\s*(0x[0-9A-Fa-f]+|\d+)[uU]?\s*\)',
                            code[span[0]:span[1]]):
        mask = int(site.group(2), 0)
        if mask & (mask - 1) or not mask:
            continue
        bit = mask.bit_length() - 1
        for n in amounts:
            if abs(bit - (32 - n)) <= 1:
                value = re.sub(r'^\(\s*s32\s*\)\s*', '', site.group(1))
                sites.setdefault(n, []).append((span[0] + site.start(), span[0] + site.end(), f'__rlwnm({value}, {n}, 31, 31)'))
    out = []
    for n, edits in sites.items():
        for group in ([edits] + ([[e] for e in edits] if len(edits) > 1 else [])):
            text = body
            for a, b, value in sorted(group, reverse=True):
                text = text[:a] + value + text[b:]
            out.append((f'retail constant rotate bit test by {n} ({len(group)} sites)', text))
    return out


def range_switches(body, name, check):
    """Recover contiguous switch cases flattened into a signed range test."""
    from . import fixup_source as source
    from .sdkimport import masked
    code = masked(body)
    span = source._function_body_span(code, name)
    if not span or not any(stuck._fmt(t).startswith('b ') and not stuck._fmt(o)
                           for t,o in zip(*check._rows)):
        return []
    operations = []
    source.commutations(body, name, operations)
    def atom(value):
        value = value.strip()
        while value.startswith('(') and value.endswith(')'):
            depth = 0
            for i,ch in enumerate(value):
                depth += (ch=='(')-(ch==')')
                if not depth:
                    break
            if i != len(value)-1:
                break
            value = value[1:-1].strip()
        return value
    def statement(start):
        while start < span[2] and code[start].isspace():start += 1
        if start == span[2]:return None
        if code[start] == '{':
            end,depth = start+1,1
            while end < span[2] and depth:
                depth += (code[end]=='{')-(code[end]=='}');end += 1
            return (start,end,body[start+1:end-1]) if not depth else None
        end = code.find(';',start,span[2])
        if end < 0 or re.search(r'[{}]|\b(?:if|for|while|switch)\b',code[start:end]):return None
        return start,end+1,body[start:end+1]
    edits = []
    for callee,start,end,args in source.call_sites(code):
        if callee != 'if' or len(args)!=1 or not span[1]<=start<end<=span[2]:continue
        lo,hi=args[0]
        roots = [o for o in operations if o['op'] in ('&&','||') and lo<=o['start']<o['end']<=hi
                 and atom(code[lo:hi])==atom(code[o['start']:o['end']])]
        if len(roots)!=1:continue
        root=roots[0];bounds=[]
        for side in ('left','right'):
            lo,hi=root[side]
            children=[o for o in operations if o['op'] in ('<','<=','>','>=')
                      and lo<=o['start']<o['end']<=hi and atom(code[lo:hi])==atom(code[o['start']:o['end']])]
            if len(children)!=1:break
            child=children[0];value=atom(code[slice(*child['left'])]);literal=atom(code[slice(*child['right'])])
            if not re.fullmatch(r'-?(?:0x[\da-fA-F]+|\d+)',literal):break
            operator=child['op']
            if root['op']=='||':operator={'<':'>=','<=':'>','>':'<=','>=':'<'}[operator]
            bounds.append((value,operator,int(literal,0)))
        if len(bounds)!=2 or bounds[0][0]!=bounds[1][0]:continue
        lower=[v+(op=='>') for _,op,v in bounds if op in ('>','>=')]
        upper=[v-(op=='<') for _,op,v in bounds if op in ('<','<=')]
        if len(lower)!=1 or len(upper)!=1 or not 0<=upper[0]-lower[0]<32:continue
        yes=statement(end)
        if yes is None:continue
        tail=yes[1];no_text=''
        alternate=re.match(r'\s*else\b',code[tail:span[2]])
        if alternate:
            no=statement(tail+alternate.end())
            if no is None:continue
            tail=no[1];no_text=no[2]
        yes_text=yes[2]
        if re.search(r'\bbreak\b',masked(yes_text+no_text)):continue
        if root['op']=='||':yes_text,no_text=no_text,yes_text
        cases=' '.join('case '+str(i)+':' for i in range(lower[0],upper[0]+1))
        replacement=('switch ('+bounds[0][0]+') {\n'+cases+' {\n'+yes_text+'\n} break;\n'
                     +'default: {\n'+no_text+'\n} break;\n}')
        edits.append((start,tail,replacement))
    out=[]
    groups=[[e] for e in edits]
    ordered=sorted(edits)
    if len(ordered)>1 and all(b<=c for (a,b,_),(c,d,_) in zip(ordered,ordered[1:])):groups.insert(0,ordered)
    for group in groups:
        text=body
        for a,b,value in sorted(group,reverse=True):text=text[:a]+value+text[b:]
        out.append((f'retail contiguous switch cases ({len(group)} sites)',text))
    return list(dict.fromkeys(out))


def conversion_arguments(p, symbol, body, check):
    """Replace a leaked encoding bias using a witnessed integer value at calls."""
    from . import fixup_source as source
    from .sdkimport import masked
    from .signatures import recovered, Signature, parameter
    code = masked(body); span = source._function_body_span(code, p.resolve(symbol).name)
    if not span:
        return []
    typed = numeric_evidence(p,symbol,check)
    if not any(typed.get('calls', {}).values()):
        return []
    _, variables = source.declared_types(code, span[0])
    index = recovered(p); calls = source.call_sites(body)
    target = [stuck._fmt(r) for r in check._rows[0]]
    target_calls = {}
    for i, line in enumerate(target):
        call = re.fullmatch(r'bl (\w+)', line)
        if call:
            target_calls.setdefault(call[1], []).append(i)
    pool = {(a, b): value for a, b, value in pool_scalar_reads(p, symbol, body, check)}

    def resolve(a, b):
        for _ in range(12):
            while a < b and code[a].isspace(): a += 1
            while b > a and code[b - 1].isspace(): b -= 1
            name = re.fullmatch(r'\w+', code[a:b])
            rounded = re.fullmatch(r'\((?:f32|f64|float|double)\)\s*(\w+)',code[a:b])
            if rounded and variables.get(rounded[1],'').strip() in ('f32','f64','float','double'):
                name = re.fullmatch(r'\w+',rounded[1])
            previous = source.reaching_assignment(code, name[0], a, span[1]) if name else None
            if not previous:
                return a, b
            a, b = previous
        return a, b

    def conversions(value):
        if value[0] == 'conversion':
            return [value]
        return [c for part in value[1:] if isinstance(part, tuple) for c in conversions(part)]

    witnesses, missing, precision = [], [], []
    for callee, sites in target_calls.items():
        uses = [c for c in calls if c[0] == callee and span[1] <= c[1] < span[2]]
        prototypes = [c for c in calls if c[0] == callee and c[1] < span[0]]
        if len(uses) != len(sites) or len(prototypes) != 1:
            continue
        types = dict(index.types); types.update(source.declared_types(code, span[0])[0])
        params = [parameter(code[a:b], types) for a, b in prototypes[0][3]]
        if not params or None in params or '...' in params:
            continue
        slots = index.registers(Signature('void', tuple(params)))
        if not slots or len(slots) != len(params):
            continue
        for row, (_, start, end, args) in zip(sites, uses):
            if len(args) != len(slots):
                continue
            for (reg, ty), (a, b) in zip(slots, args):
                lo, hi = resolve(a, b)
                expression = code[lo:hi]
                if reg.startswith('r'):
                    value = re.fullmatch(r'\s*(?:\([\w *]+\)\s*)*(\w+)\s*', expression)
                    if not value or value[1] not in variables:
                        continue
                    current = reg
                    for prior in range(row - 1, max(-1, row - 32), -1):
                        line = target[prior]
                        if line.startswith('b'):
                            break
                        move = re.fullmatch(r'mr '+current+r', (r\d+)', line)
                        if move:
                            current = move[1]
                        elif re.match(r'(?!st|cmp|mt)\w+[.]? '+current+r',', line):
                            break
                    if current != reg:
                        witnesses.append((row, current, value[1], start))
                    continue
                value = typed['calls'].get(row, {}).get(reg)
                found = conversions(value) if value else []
                if len(found) != 1:
                    continue
                conversion = found[0]; integer = conversion[3]
                if integer[0] != 'read':
                    continue
                cast = list(re.finditer(r'\((f32|f64|float|double)\)\s*(?:\((s32|u32|int|unsigned int)\)\s*)?(\w+)\b', expression))
                cast = [m for m in cast if variables.get(m[3], '').strip() in INT_TYPES]
                if len(cast) == 1:
                    m = cast[0]; witnesses.append((row, integer[2], m[3], start))
                    if value[0] == 'conversion' and m[1] != conversion[1]:
                        precision.append((lo + m.start(1), lo + m.end(1), conversion[1]))
                literal = pool.get((lo, hi), expression)
                try:
                    bias = float(literal.rstrip('fF')) in (4503599627370496.0, 4503601774854144.0)
                except ValueError:
                    bias = False
                if value[0] == 'conversion' and bias:
                    missing.append((row, reg, a, b, conversion, start))
    edits = []
    for row, _, a, b, conversion, start in missing:
        wanted = conversion[3][2]; choices = set()
        for witness_row, register, var, position in witnesses:
            if register != wanted or not source.initialized_local(code, var, start, span[1]):
                continue
            lower, upper = sorted((witness_row, row))
            if any(re.match(r'(?!st|cmp|mt)\w+[.]? '+wanted+r',', line) for line in target[lower + 1:upper]):
                continue
            lower, upper = sorted((position, start))
            if re.search(r'\b'+re.escape(var)+r'\s*(?:=(?!=)|[+*/&|^-]=|\+\+|--)|&\s*\b'+re.escape(var)+r'\b', code[lower:upper]):
                continue
            choices.add(var)
        if len(choices) == 1:
            edits.append((a, b, f'({conversion[1]})({conversion[2]}){next(iter(choices))}'))
    out = []
    for label, changes in (('retail conversion arguments', edits), ('retail conversion precision', precision)):
        if changes:
            for group in [changes] + ([[edit] for edit in changes] if len(changes) > 1 else []):
                text = body
                for a, b, value in sorted(set(group), reverse=True):
                    text = text[:a] + value + text[b:]
                out.append((label + f' ({len(group)} sites)', text))
    return list(dict.fromkeys(out))


def scalar_lifetimes(p, symbol, body, check):
    """Give proven double loads and loop invariants their own scalar lifetime."""
    from . import fixup_source as source
    from .sdkimport import masked
    code = masked(body); span = source._function_body_span(code, p.resolve(symbol).name)
    if not span:
        return []
    _, variables = source.declared_types(code, span[0])
    reads = pool_scalar_reads(p, symbol, body, check)
    pool = {(a, b): value for a, b, value in reads}
    assignments = list(re.finditer(r'(?m)^([ \t]*)(\w+)\s*=(?!=)\s*([^;{}\n]+);', code[span[1]:span[2]]))
    groups = []
    for assignment in assignments:
        var = assignment[2]
        if variables.get(var, '').strip() not in ('f32', 'float'):
            continue
        a, b = span[1] + assignment.start(), span[1] + assignment.end()
        lo, hi = span[1] + assignment.start(3), span[1] + assignment.end(3)
        while code[hi - 1].isspace(): hi -= 1
        literal = pool.get((lo, hi))
        if literal is None or literal.endswith(('f', 'F')):
            continue
        if float(literal) in (4503599627370496.0,4503601774854144.0):
            continue
        # Only straight-line uses are rewritten. The old variable remains
        # initialized for any outgoing branch, with its original rounding.
        end = b
        for following in re.finditer(r'\s*([^;{}]+);', code[b:span[2]]):
            if b + following.start() != end:
                break
            statement = following[1]
            if (re.search(r'\b(?:if|else|while|for|do|switch|return|goto|break|continue|case)\b|:', statement)
                    or re.search(r'\b'+re.escape(var)+r'\s*(?:=(?!=)|[+*/&|^-]=|\+\+|--)|&\s*\b'+re.escape(var)+r'\b', statement)):
                break
            end = b + following.end()
        uses = list(re.finditer(r'\b'+re.escape(var)+r'\b', code[b:end]))
        if not uses or re.search(r'&\s*\b'+re.escape(var)+r'\b', code[span[1]:span[2]]):
            continue
        fresh = 'fzgx_double_' + str(a)
        if re.search(r'\b'+fresh+r'\b', code):
            continue
        changes = [(a, b, f'{assignment[1]}{fresh} = {body[lo:hi]};\n{assignment[1]}{var} = (f32){fresh};')]
        changes += [(b + m.start(), b + m.end(), fresh) for m in uses]
        groups.append((f'f64 {fresh};', changes))
    out = []
    # Keep interacting sites together as well as individual sites, without
    # permitting overlapping edits or a global replacement of a reused local.
    disjoint = []
    last = -1
    for group in groups:
        if group[1][0][0] >= last:
            disjoint.append(group); last = max(b for _, b, _ in group[1])
    for selected in ([disjoint] if disjoint else []) + [[g] for g in groups]:
        text = body
        for a, b, value in sorted([e for _, edits in selected for e in edits], reverse=True):
            text = text[:a] + value + text[b:]
        text = text[:span[1]] + '\n    ' + '\n    '.join(decl for decl, _ in selected) + text[span[1]:]
        out.append((f'retail double lifetimes ({len(selected)} sites)', text))
    typed = numeric_evidence(p,symbol,check)
    constants = set()
    target = check._rows[0]
    for i, values in typed.get('comparisons', {}).items():
        address = int(target[i]['instruction']['address'])
        if any(r.get('instruction', {}).get('branch_dest') is not None and int(r['instruction']['branch_dest']) < address
               for r in target[i + 1:i + 4]):
            constants.update(v[1] for v in values if v and v[0] == 'literal')
    for call, start, end, args in source.call_sites(body):
        if call != 'while' or not span[1] <= start < span[2] or len(args) != 1:
            continue
        condition = re.fullmatch(r'\s*(.+?)\s*(>=|<=|>|<|==|!=)\s*(\w+)\s*', code[args[0][0]:args[0][1]])
        if not condition or condition[3] not in variables:
            continue
        var = condition[3]; previous = source.reaching_assignment(code, var, start, span[1])
        if previous not in pool:
            continue
        literal = pool[previous]
        try:
            raw = struct.pack('>f' if literal.endswith(('f','F')) else '>d', float(literal.rstrip('fF'))).hex()
        except (ValueError, OverflowError):
            continue
        if raw not in constants:
            continue
        opening = code.find('{', end)
        if opening < 0 or code[end:opening].strip():
            continue
        depth, stop = 1, opening + 1
        while stop < span[2] and depth:
            depth += (code[stop] == '{') - (code[stop] == '}'); stop += 1
        if not re.search(r'\b'+re.escape(var)+r'\s*=(?!=)', code[opening:stop]):
            continue
        fresh = 'fzgx_invariant_' + str(start)
        if re.search(r'\b'+fresh+r'\b', code):
            continue
        lo, hi = args[0][0] + condition.start(3), args[0][0] + condition.end(3)
        text = body[:lo] + fresh + body[hi:]
        text = text[:start] + fresh + ' = ' + body[previous[0]:previous[1]] + ';\n    ' + text[start:]
        text = text[:span[1]] + '\n    f64 ' + fresh + ';' + text[span[1]:]
        out.append(('retail loop invariant ' + var, text))
    return list(dict.fromkeys(out))


def call_result_types(p, symbol, body, check):
    from . import fixup_source as source
    from .sdkimport import masked
    code=masked(body);span=source._function_body_span(code,p.resolve(symbol).name)
    if not span:
        return []
    locals_={name:(a,b,ty) for a,b,ty,name,dims in source._locals(body,span) if not dims}
    prototypes={m[2]:m[1] for m in re.finditer(r'\bextern\s+(f32|f64|float|double)\s+(\w+)\s*\(',code[:span[0]])}
    target=[stuck._fmt(row) for row in check._rows[0]]
    eligible=set()
    for i,line in enumerate(target):
        call=re.fullmatch(r'bl (\w+)',line)
        if not call or call[1] not in prototypes:
            continue
        for following in target[i+1:i+16]:
            if following.startswith(('b','fctiw')):
                break
            if re.match(r'f\w+ (?:cr\d+|f\d+),.*\bf1\b',following):
                eligible.add(call[1]);break
            if re.match(r'\w+ f1,',following):
                break
    edits=[]
    for callee,start,_,_ in source.call_sites(body):
        if callee not in eligible or not span[1]<=start<span[2]:
            continue
        prefix=code[code.rfind('\n',span[1],start)+1:start]
        assignment=re.fullmatch(r'\s*(\w+)\s*=\s*',prefix)
        if not assignment or assignment[1] not in locals_:
            continue
        var=assignment[1];a,b,ty=locals_[var]
        if ty not in INT_TYPES or len(re.findall(r'\b'+var+r'\s*=(?!=)',code[span[1]:span[2]]))!=1 or re.search(r'&\s*\b'+var+r'\b',code[span[1]:span[2]]):
            continue
        declaration=body[a:b];match=re.search(r'\b'+re.escape(ty)+r'\b',declaration)
        edits.append((a+match.start(),a+match.end(),prototypes[callee]))
    out=[]
    for group in ([edits]+[[e] for e in edits] if edits else []):
        text=body
        for a,b,ty in sorted(set(group),reverse=True):
            text=text[:a]+ty+text[b:]
        out.append((f'retail call result types ({len(group)} sites)',text))
    return list(dict.fromkeys(out))


def floating_expressions(p, symbol, body, check):
    """Recover square/FMA grouping and conversion rounding at estimate inputs."""
    from . import fixup_source as source
    from .sdkimport import masked
    code = masked(body); name = p.resolve(symbol).name
    target = [stuck._fmt(row) for row in check._rows[0]]
    square_fma = False
    for i, line in enumerate(target):
        square = re.fullmatch(r'fmul (f\d+), (f\d+), \2', line)
        if not square:
            continue
        for later in target[i + 1:i + 9]:
            if re.match(r'fnmsub\s', later) and square[1] in later.split(', ')[1:]:
                square_fma = True; break
            if later.startswith('b') or re.match(r'\w+ '+square[1]+',', later):
                break
    groups = {}
    if square_fma:
        operations = []; source.commutations(body, name, operations)
        multiply = [op for op in operations if op['op'] == '*']
        for outer in multiply:
            lo, hi = outer['left']
            child = next((op for op in multiply if lo <= op['start'] and op['end'] <= hi
                          and not body[lo:op['start']].strip(' (\n\t') and not body[op['end']:hi].strip(' )\n\t')), None)
            if not child:
                continue
            x, y, z = [body[a:b] for a,b in (child['left'], child['right'], outer['right'])]
            if re.fullmatch(r'\w+', y.strip()) and y.strip() == z.strip():
                groups.setdefault('square', []).append((outer['start'], outer['end'], f'(({x}) * (({y}) * ({z})))'))
    typed = numeric_evidence(p,symbol,check)
    estimates = list(typed.get('estimates', {}).values())
    calls = [c for c in source.call_sites(body) if c[0] == '__frsqrte' and len(c[3]) == 1
             and source._function_body_span(code, name)[1] <= c[1] < source._function_body_span(code, name)[2]]
    if len(calls) == len(estimates):
        for (_, _, _, args), value in zip(calls, estimates):
            if not value or value[:2] != ('conversion', 'f32'):
                continue
            a,b = args[0]; old = code[a:b].strip()
            if not re.match(r'^\((?:f64|double)\)', old) or re.search(r'\+\+|--|(?<![=!<>])=(?!=)', old):
                continue
            new = re.sub(r'^\((?:f64|double)\)', '(f32)', old)
            span = source._function_body_span(code, name)
            edits = [(m.start(), m.end(), new) for m in re.finditer(re.escape(old), code)
                     if span[1] <= m.start() and m.end() <= span[2]]
            groups.setdefault('conversion', []).extend(edits)
    out = []
    for label, edits in list(groups.items()) + ([('combined', [e for edits in groups.values() for e in edits])] if len(groups)>1 else []):
        # Parent expression and cast edits overlap. Apply the cast inside the
        # replacement expression, rather than splicing overlapping source spans.
        changes = sorted(set(edits), key=lambda e:(e[0],-e[1]))
        merged = []
        for a,b,value in changes:
            if merged and a < merged[-1][1]:
                lo,hi,outer = merged[-1]
                if b <= hi and code[a:b] in outer:
                    merged[-1] = (lo,hi,outer.replace(code[a:b],value))
                continue
            merged.append((a,b,value))
        text = body
        for a,b,value in reversed(merged):
            text = text[:a]+value+text[b:]
        if text != body:
            out.append(('retail floating expression '+label,text))
    return out


FUSED = ("fmadds", "fmsubs", "fnmsubs", "fnmadds", "fmadd", "fmsub", "fnmsub", "fnmadd")


def _product_sites(body, name):
    """Products that are direct operands of an addition or subtraction, with the
    parent operator and the operand span (parentheses included, casts excluded)."""
    from . import fixup_source as source
    operations = []
    source.commutations(body, name, operations)
    products = {(o['start'], o['end']) for o in operations if o['op'] == '*'}

    def bare(a, b):
        while a < b and body[a] == '(' and body[b - 1] == ')':
            depth = 0
            for k in range(a, b):
                if body[k] == '(':
                    depth += 1
                elif body[k] == ')':
                    depth -= 1
                    if depth == 0 and k != b - 1:
                        return a, b
            a += 1; b -= 1
            while a < b and body[a] in ' \t': a += 1
            while a < b and body[b - 1] in ' \t': b -= 1
        return a, b
    span = source._function_body_span(body, name)
    floats = set(re.findall(r'\b(?:f32|f64|float|double)\s+(\w+)', body[:span[2]] if span else body))
    floats |= set(re.findall(r'\b(?:f32|f64|float|double)\s+\*\s*(\w+)', body[:span[2]] if span else body))

    def floating(text):
        if re.search(r'\((?:f32|f64|float|double)\s*\*?\)|\d\.\d*f?\b|\.\d+f?\b', text):
            return True
        return any(w in floats for w in re.findall(r'[A-Za-z_]\w*', text))
    sites = []
    for o in operations:
        if o['op'] not in ('+', '-'):
            continue
        for side in ('left', 'right'):
            a, b = o[side]
            if bare(a, b) in products and floating(body[a:b]):
                sites.append((a, b, o['op'], side))
    return sorted(set(sites))


def fusion_control(p, symbol, body, check):
    """`a + b * c` in one expression lowers to fmadds; a product held in a temporary
    or wrapped in `(f32)` stays a separate fmuls (probe-verified on GC/1.3.2, 2026-09-15).
    Retail's count of fused operations decides the direction: cast every product that
    retail keeps separate, or drop the casts and temporaries where retail fuses."""
    from . import fixup_source as source
    name = p.resolve(symbol).name
    target = [stuck._fmt(row).split(' ')[0] for row in check._rows[0]]
    ours = [stuck._fmt(row).split(' ')[0] for row in check._rows[1]]
    retail_fused = sum(m in FUSED for m in target)
    our_fused = sum(m in FUSED for m in ours)
    out = []
    # counts alone miss a swapped grouping (`x*x + y*y + z*z` accumulated from the first
    # product against ours from the second): any row where a fused and an unfused float
    # opcode face each other is evidence for both directions
    facing = any(((l in FUSED) != (o in FUSED)) and (l in FUSED or o in FUSED) and l != o
                 for l, o in zip(target, ours) if l and o)
    if retail_fused < our_fused or facing or (retail_fused == our_fused and
                                              sum(m.startswith('fnm') for m in target) != sum(m.startswith('fnm') for m in ours)):
        sites = _product_sites(body, name)
        double = bool(re.search(r'\b(?:f64|double)\b', body[source._function_body_span(body, name)[1]:] if source._function_body_span(body, name) else ''))
        for cast in ('(f32)',) + (('(f64)',) if double else ()):
            edits = [(a, b, f'{cast}({body[a:b]})') for a, b, op, side in sites]
            if len(edits) > 1:
                text = body
                for a, b, value in reversed(edits):
                    text = text[:a] + value + text[b:]
                out.append((f'retail unfused products: {cast} at every site', text))
            for a, b, value in edits[:24]:
                out.append((f'retail unfused product: {cast} at {a}', body[:a] + value + body[b:]))
    if retail_fused > our_fused or facing:
        span = source._function_body_span(body, name)
        if not span:
            return out
        inner = body[span[1]:span[2]]
        edits = []
        for m in re.finditer(r'\((?:f32|f64|float|double)\)\s*(\((?:[^()]|\([^()]*\))*\))', inner):
            if '*' in m.group(1) and not re.search(r'[;{}=]', m.group(1)):
                edits.append((span[1] + m.start(), span[1] + m.end(), m.group(1)))
        # a single-use product temporary: `t = a * b; ... x + t` folds back into the expression
        for m in re.finditer(r'(?m)^\s*(?:(?:f32|f64|float|double)\s+)?(\w+)\s*=\s*([^;=]*\*[^;=]*);[ \t]*\n', inner):
            var, expr = m.group(1), m.group(2).strip()
            uses = [u for u in re.finditer(rf'\b{re.escape(var)}\b', inner) if not (m.start() <= u.start() < m.end())]
            if len(uses) != 1 or re.search(r'[;{}]|\+\+|--|\(', expr):
                continue
            u = uses[0]
            if not re.search(rf'[-+]\s*$', inner[:u.start()]) and not re.match(rf'{re.escape(var)}\s*[-+](?!=)', inner[u.start():]):
                continue
            text = inner[:u.start()] + f'({expr})' + inner[u.end():]
            text = text[:m.start()] + text[m.end():]
            out.append((f'retail fused product: fold {var}', body[:span[1]] + text + body[span[2]:]))
        if len(edits) > 1:
            text = body
            for a, b, value in reversed(edits):
                text = text[:a] + value + text[b:]
            out.append(('retail fused products: drop every product cast', text))
        for a, b, value in edits[:24]:
            out.append((f'retail fused product: drop cast at {a}', body[:a] + value + body[b:]))
    return out


def paired_vector_kernels(p, symbol, body, check):
    """Retail's psq_l/psq_st vector kernels come from inline-assembly helpers (include/psvec.h);
    rewrite per-component float statement triples into those calls where retail carries the
    paired-single operations and the candidate does not."""
    from . import psvec
    from . import fixup_source as source
    name = p.resolve(symbol).name
    target = [stuck._fmt(row).split(' ')[0] for row in check._rows[0]]
    ours = [stuck._fmt(row).split(' ')[0] for row in check._rows[1]]
    wanted = {m for m in psvec.KERNEL_MNEMONICS if target.count(m) > ours.count(m)}
    if not wanted:
        return []
    kinds = set()
    if 'ps_sub' in wanted: kinds.add('sub')
    if 'ps_add' in wanted: kinds.add('add')
    if 'ps_muls0' in wanted: kinds.add('scale')
    if 'ps_madds0' in wanted: kinds.add('scale_add')
    if 'ps_merge00' in wanted: kinds.add('set')
    if 'ps_sub' in wanted and 'ps_madds0' in wanted: kinds.add('sub+scale_add')
    span = source._function_body_span(body, name)
    if not span:
        return []
    inner = body[span[1]:span[2]]
    found = [f for f in psvec.kernel_sites(inner) if set(f[2].split('+')) <= kinds]
    out = []
    if not found:
        return out
    every = psvec.rewrite(body, span, sites=[i for i, f in enumerate(psvec.kernel_sites(inner)) if f in found])
    if every:
        out.append((f'paired-single kernels at every site ({len(found)})', every))
    if len(found) > 1:
        allsites = psvec.kernel_sites(inner)
        for f in found[:16]:
            text = psvec.rewrite(body, span, sites=[allsites.index(f)])
            if text:
                out.append((f'paired-single {f[2]} kernel at {span[1] + f[0]}', text))
    return out


def attributed_type_flips(p, symbol, body, check, row_lines):
    """Signedness and width flips targeted by line attribution: a `cmpwi`/`cmplwi` (or
    `lha`/`lhz`, `extsh`/`clrlwi`, `srawi`/`srwi`) row names its source line, the line
    names the operands, and each operand's declaration (local, parameter or struct field
    in the body) is flipped toward retail's signedness."""
    from . import fixup_source as source
    if not row_lines:
        return []
    name = p.resolve(symbol).name
    lrows, rrows = check._rows
    SIGNED = {'cmpwi', 'cmpw', 'lha', 'lhax', 'extsh', 'extsb', 'srawi', 'sraw', 'divw', 'mulhw'}
    UNSIGNED = {'cmplwi', 'cmplw', 'lhz', 'lhzx', 'clrlwi', 'srwi', 'srw', 'divwu', 'mulhwu', 'rlwinm'}
    wants = {}  # line -> 'signed' | 'unsigned'
    for k, ln in row_lines.items():
        l, o = stuck._fmt(lrows[k]).split(' ')[0], stuck._fmt(rrows[k]).split(' ')[0]
        for d in (-1, 0, 1):  # a row's line is exact only to within one scheduled statement
            if l in SIGNED and (o in UNSIGNED or not o):
                wants[ln + d] = 'signed'
            elif l in UNSIGNED and (o in SIGNED or not o):
                wants[ln + d] = 'unsigned'
    if not wants:
        return []
    lines = body.split('\n')
    span = source._function_body_span(body, name)
    if not span:
        return []
    flip_to = {'signed': {'u8': 's8', 'u16': 's16', 'u32': 's32', 'unsigned int': 'int', 'unsigned char': 'char', 'unsigned short': 'short'},
               'unsigned': {'s8': 'u8', 's16': 'u16', 's32': 'u32', 'int': 'u32', 'char': 'u8', 'short': 'u16'}}
    out = []
    grouped = []
    for ln, direction in sorted(wants.items()):
        if ln < 1 or ln - 1 >= len(lines):
            continue
        text = lines[ln - 1]
        operands = set(re.findall(r'(?<![\w.>])([A-Za-z_]\w*)(?![\w(])', text))
        members = set(re.findall(r'(?:->|\.)([A-Za-z_]\w*)', text))
        operands -= {'if', 'else', 'while', 'for', 'return', 'switch', 'case', 'u8', 's8', 'u16', 's16', 'u32', 's32', 'f32', 'f64', 'void', 'struct'}
        edits = []
        line_start = sum(len(x) + 1 for x in lines[:ln - 1])
        # casts on the line itself: `*(u32 *)(p + 244)` and `(u32)x` carry the operand type
        for m in re.finditer(rf'\(\s*({"|".join(map(re.escape, flip_to[direction]))})\s*\**\s*\)', text):
            edits.append((line_start + m.start(1), line_start + m.end(1), flip_to[direction][m.group(1)], f'cast {m.group(1)}'))
        for ident in operands:
            # declaration of a scalar local or parameter in this function, before the statement
            for m in re.finditer(rf'\b({"|".join(map(re.escape, flip_to[direction]))})\s+{re.escape(ident)}\b', body[:span[2]]):
                if m.start() > line_start:
                    break
                edits.append((m.start(1), m.end(1), flip_to[direction][m.group(1)], ident))
                break
        for member in members:
            for m in re.finditer(rf'\b({"|".join(map(re.escape, flip_to[direction]))})\s+{re.escape(member)}\s*(?:\[[^\]]*\])?\s*;', body[:span[0]]):
                edits.append((m.start(1), m.end(1), flip_to[direction][m.group(1)], member))
        for a, b, new, ident in edits:
            out.append((f'attributed {direction} {ident} at line {ln}', body[:a] + new + body[b:]))
        grouped.extend(edits)
    if len(grouped) > 1:
        text = body
        for a, b, new, ident in sorted(set(grouped), reverse=True):
            text = text[:a] + new + text[b:]
        out.append(('attributed signedness at every implicated line', text))
    return out


def attributed_inlines(p, symbol, body, check, row_lines):
    """A single-use local read on an implicated line is folded back into its use: a value
    computed in a separate statement changes evaluation order (a call evaluated before the
    other operands, a load hoisted into its own web) and operand order of the consumer."""
    from . import fixup_source as source
    if not row_lines:
        return []
    name = p.resolve(symbol).name
    span = source._function_body_span(body, name)
    if not span:
        return []
    lines = body.split('\n')
    starts = [0]
    for line in lines:
        starts.append(starts[-1] + len(line) + 1)
    out = []
    # the scheduler interleaves neighbouring statements, so a row's line is exact only to
    # within one statement either side
    implicated = sorted({ln + d for ln in set(row_lines.values()) for d in (-1, 0, 1)})
    for ln in implicated:
        if ln < 1 or ln - 1 >= len(lines):
            continue
        for ident in set(re.findall(r'(?<![\w.>])([A-Za-z_]\w*)(?![\w(])', lines[ln - 1])):
            inner0 = body[span[1]:span[2]]
            decl = re.search(rf'(?m)^[ \t]*(?:const\s+)?[\w ]+?\s*\**\s*{re.escape(ident)}\s*;[ \t]*\n', inner0)
            uses = [m for m in re.finditer(rf'(?<![\w.>])\b{re.escape(ident)}\b(?!\s*\()', inner0)
                    if not (decl and decl.start() <= m.start() < decl.end())]
            assigns = [m for m in re.finditer(rf'(?m)^([ \t]*){re.escape(ident)}\s*=\s*(?![=])([^;{{}}]+);[ \t]*\n', inner0)]
            if len(assigns) != 1 or len(uses) != 2:
                continue
            a = assigns[0]
            value = a.group(2).strip()
            if re.search(r'\+\+|--|(?<![=!<>])=(?!=)', value):
                continue
            use = [m for m in uses if not (a.start() <= m.start() < a.end())]
            if len(use) != 1 or use[0].start() < a.end():
                continue
            u = use[0]
            narrow = re.match(r'\s*(u8|s8|u16|s16)\b', decl.group(0)) if decl else None
            variants = [f'({value})']
            if narrow:
                variants.insert(0, f'(({narrow.group(1)})({value}))')  # the local truncated its value
            for replacement in variants:
                inner = body[span[1]:span[2]]
                inner = inner[:u.start()] + replacement + inner[u.end():]
                inner = inner[:a.start()] + inner[a.end():]
                if decl:
                    inner = inner[:decl.start()] + inner[decl.end():]
                text = body[:span[1]] + inner + body[span[2]:]
                out.append((f'attributed inline {ident} at line {ln}' + (' typed' if replacement != f'({value})' else ''), text))
    return out


def attributed_declaration_swaps(p, symbol, body, check, row_lines):
    """Callee-saved register renames name the locals involved: the rows that differ only by
    register attribute to statements, the locals read or written there are the mis-coloured
    webs, and the allocator colours named locals in declaration order, so only those locals'
    declarations are permuted (pairwise swaps, first and last placement) instead of every
    permutation of every local."""
    from . import fixup_source as source
    if not row_lines:
        return []
    name = p.resolve(symbol).name
    span = source._function_body_span(body, name)
    if not span:
        return []
    locs = source._locals(body, span)
    if len(locs) < 2:
        return []
    lrows, rrows = check._rows
    REG = re.compile(r'\b[rf]\d+\b')
    SAVED = re.compile(r'\b(?:r(?:1[4-9]|2\d|3[01])|f(?:1[4-9]|2\d|3[01]))\b')
    lines = body.split('\n')
    involved = []
    names = [l[3] for l in locs]
    for k, ln in row_lines.items():
        lf, of = stuck._fmt(lrows[k]), stuck._fmt(rrows[k])
        if not lf or not of or REG.sub('R', lf) != REG.sub('R', of):
            continue
        if not (SAVED.search(lf) or SAVED.search(of)):
            continue
        for d in (-1, 0, 1):
            if 0 < ln + d <= len(lines):
                for ident in re.findall(r'(?<![\w.>])([A-Za-z_]\w*)(?![\w(])', lines[ln + d - 1]):
                    if ident in names and ident not in involved:
                        involved.append(ident)
    if not involved:
        return []
    order = list(range(len(locs)))
    idx = {l[3]: i for i, l in enumerate(locs)}
    out = []
    seen = set()
    def emit(label, perm):
        key = tuple(perm)
        if key in seen or key == tuple(order):
            return
        seen.add(key)
        out.append((label, source.reorder(body, locs, key)))
    inv = [idx[n] for n in involved]
    for a in inv:
        for b in range(len(locs)):
            if a == b:
                continue
            perm = list(order); perm[a], perm[b] = perm[b], perm[a]
            emit(f'attributed swap {locs[a][3]}/{locs[b][3]}', perm)
        rest = [i for i in order if i != a]
        emit(f'attributed {locs[a][3]} first', [a] + rest)
        emit(f'attributed {locs[a][3]} last', rest + [a])
    if len(inv) >= 2:
        import itertools
        others = [i for i in order if i not in inv]
        for perm_inv in itertools.permutations(inv):
            if list(perm_inv) == inv:
                continue
            perm = list(order)
            for slot, value in zip(inv, perm_inv):
                perm[slot] = value
            emit(f'attributed permute {"/".join(locs[i][3] for i in perm_inv)}', perm)
            if len(out) > 40:
                break
    return out[:40]


def induction_indexing(p, symbol, body, check, row_lines=None):
    """A loop pointer initialised straight into its callee-saved register (`addi r30, r3,
    sym@l`) with no copy is a strength-reduced induction shadow of an indexed access, not
    a source pointer: MWCC lowers `p = base; ... p = p + K` through a temporary and a copy
    (`addi r0; mr r30, r0`), while `base[i]` / `(u8 *)base + i * K` is initialised in place
    (fn_10_7130, probe-verified 2026-09-16). The same holds for `off = 0; ... off += K`
    against `i * K`. Rewrite each stepped local of a counted loop into its counter form."""
    from . import fixup_source as source
    name = p.resolve(symbol).name
    lrows, rrows = check._rows
    evidence = False
    for k in range(1, len(rrows)):
        of = stuck._fmt(rrows[k])
        if re.match(r'mr r\d+, r0$', of) and stuck._fmt(lrows[k]) != of and any(
                re.match(r'(addi|li) r0,', stuck._fmt(rrows[j])) for j in range(max(0, k - 4), k)):
            evidence = True; break
    if not evidence:
        return []
    span = source._function_body_span(body, name)
    if not span:
        return []
    inner = body[span[1]:span[2]]
    out = []
    # loops with a unit-step counter
    for loop in re.finditer(r'(?m)^([ \t]*)(?:while|for)\s*\(([^\n]*)\)\s*\{', inner):
        indent = loop.group(1)
        # loop body extent by brace depth
        depth, k = 0, loop.end() - 1
        while k < len(inner):
            if inner[k] == '{': depth += 1
            elif inner[k] == '}':
                depth -= 1
                if depth == 0: break
            k += 1
        lbody = inner[loop.end():k]
        counters = re.findall(r'(?m)^[ \t]*(\w+)\s*(?:\+\+|\+=\s*1|=\s*\1\s*\+\s*1)\s*;', lbody)
        counters += re.findall(r'\b(\w+)\+\+', loop.group(2))
        if len(set(counters)) != 1:
            continue
        counter = counters[0]
        # the counter starts at 0 before the loop
        if not re.search(rf'\b{re.escape(counter)}\s*=\s*0\s*;', inner[:loop.start()]) and not re.search(rf'\b{re.escape(counter)}\s*=\s*0\s*;', loop.group(2)):
            continue
        # stepped locals: `v = v + K` / `v += K` / `v = (T *)((u8 *)v + K)` inside, initialised before
        steps = {}
        for m in re.finditer(r'(?m)^[ \t]*(\w+)\s*(?:\+=\s*(0x[0-9A-Fa-f]+|\d+)|=\s*\(?[^;]*?\(u8 \*\)\s*\1\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\)?|=\s*\1\s*\+\s*(0x[0-9A-Fa-f]+|\d+))\s*;[ \t]*\n', lbody):
            v = m.group(1)
            if v == counter:
                continue
            k_ = next(g for g in m.groups()[1:] if g)
            steps[v] = (int(k_, 0), m)
        if not steps:
            continue
        for v, (K, step) in steps.items():
            init = list(re.finditer(rf'(?m)^[ \t]*{re.escape(v)}\s*=\s*([^;]+);[ \t]*\n', inner[:loop.start()]))
            if not init:
                continue
            init = init[-1]
            base = init.group(1).strip()
            if re.search(rf'\b{re.escape(v)}\b', base):
                continue
            uses = [m for m in re.finditer(rf'(?<![\w.>])\b{re.escape(v)}\b', lbody) if not (step.start() <= m.start() < step.end())]
            if not uses or re.search(rf'\b{re.escape(v)}\b', inner[k:]):
                continue  # used after the loop: keep the pointer
            decl = re.search(rf'(?m)^[ \t]*((?:const\s+)?[\w ]+?\s*\**)\s*{re.escape(v)}\s*;[ \t]*\n', inner[:loop.start()])
            dtype = decl.group(1).strip() if decl else ''
            if re.fullmatch(r'0|0x0', base):
                replacement = f'({counter} * {K:#x})'
            elif '*' in dtype:
                replacement = f'(({dtype})((u8 *)({base}) + {counter} * {K:#x}))'
            else:
                replacement = f'(({base}) + {counter} * {K:#x})'
            edits = [(m.start(), m.end(), replacement) for m in uses] + [(step.start(), step.end(), '')]
            new_body = lbody
            for a, b, value in sorted(edits, reverse=True):
                new_body = new_body[:a] + value + new_body[b:]
            text = inner[:loop.end()] + new_body + inner[k:]
            text = text[:init.start()] + text[init.end():]
            if decl and not re.search(rf'\b{re.escape(v)}\b', text[decl.end():]):
                text = text[:decl.start()] + text[decl.end():]
            out.append((f'induction index {v} by {counter}', body[:span[1]] + text + body[span[2]:]))
    if len(out) > 1:
        # every stepped local together: the single texts edit disjoint spans of the body
        combined = body
        changes = []
        for label, text in out:
            ops = source.edits(body, text)
            if any(a < max(d, c + 1) and c < max(b, a + 1) for a, b, _ in ops for c, d, _ in changes):
                continue
            changes.extend(ops)
        for a, b, value in sorted(changes, reverse=True):
            combined = combined[:a] + value + combined[b:]
        if combined != body:
            out.append(('induction index every stepped local', combined))
    return out


def encoded_conversions(p, symbol, body, check):
    """Recover compiler conversion scratch from an explicit lifted union."""
    from .sdkimport import masked
    code=masked(body);span=_function_span(code,p.resolve(symbol).name)
    if not span:return []
    constants={(a,b):value for a,b,value in pool_scalar_reads(p,symbol,body,check)}
    out=[]
    for declaration in re.finditer(r'\bunion\s*\{\s*(?:f64|double)\s+(\w+)\s*;\s*(?:u32|unsigned int)\s+(\w+)\s*\[2\]\s*;\s*\}\s*(\w+)\s*;',code[span[0]:span[1]]):
        member,words,var=declaration.groups();base=span[0]
        pattern=(r'\b'+re.escape(var)+r'\.'+re.escape(words)+r'\[1\]\s*=\s*(.+?)\s*\^\s*0x80000000[uU]?\s*;\s*'
                 +re.escape(var)+r'\.'+re.escape(words)+r'\[0\]\s*=\s*0x43300000[uU]?\s*;')
        assignments=list(re.finditer(pattern,code[base+declaration.end():span[1]],re.S))
        if len(assignments)!=1:continue
        assignment=assignments[0];a=base+declaration.end()+assignment.start();b=base+declaration.end()+assignment.end();value=assignment[1]
        if re.search(r'[;{}]|\+\+|--|(?<![=!<>])=(?!=)',value):continue
        read=re.search(r'\(\s*(f32|float|f64|double)\s*\)\s*\(\s*'+re.escape(var)+r'\.'+re.escape(member)+r'\s*-\s*([^();]+)\s*\)',code[b:span[1]])
        if not read or ';' in code[b:b+read.start()]:continue
        lo,hi=b+read.start(2),b+read.end(2)
        while code[hi-1].isspace():hi-=1
        bias=constants.get((lo,hi))
        try:
            if bias is None or float(bias.rstrip('fF'))!=4503601774854144.0:continue
        except ValueError:continue
        if len(re.findall(r'\b'+re.escape(var)+r'\b',code[base:span[1]]))!=4:continue
        edits=[(base+declaration.start(),base+declaration.end(),''),(a,b,''),
               (b+read.start(),b+read.end(),'('+read[1]+')(s32)('+value.strip()+')')]
        text=body
        for lo,hi,replacement in sorted(edits,reverse=True):text=text[:lo]+replacement+text[hi:]
        out.append(('recover encoded integer conversion '+var,text))
    return out


def aggregate_initializers(p, symbol, body, check):
    """Restore named aggregate bytes using their recovered field types."""
    from .sdkimport import masked
    from .signatures import record_layouts
    from .dataimport import payload, record_initializer
    code = masked(body); span = _function_span(code, p.resolve(symbol).name)
    if not span or re.search(r'#pragma\s+(?:pack|options\s+align)\b', code):
        return []
    layouts, sizes = record_layouts(code, span[0]); out = []
    for declaration in re.finditer(r'\b(?:static\s+)?const\s+struct\s+(\w+)\s+(\w+)\s*=\s*\{', code[:span[0]]):
        typ, name = declaration[1], declaration[2]
        sym = p.find_symbol(name, p.resolve(symbol).module)
        if not sym or typ not in layouts or sizes[typ][0] != sym.size:
            continue
        start = declaration.end() - 1; end, depth = start + 1, 1
        while end < span[0] and depth:
            depth += (code[end] == '{') - (code[end] == '}'); end += 1
        if depth:
            continue
        try:
            raw, relocs = payload(p, sym)
            if relocs:
                continue
            initializer = record_initializer(raw, layouts[typ], layouts, sizes)
        except (ValueError, KeyError):
            continue
        text = body[:start] + initializer + body[end:]
        if text != body:
            out.append(('retail aggregate initializer ' + name, text))
    return out


def native_pool_objects(p, symbol, body, check):
    """Split oversized external views into owned objects and typed interior atoms."""
    from .sdkimport import masked
    from .signatures import record_layouts
    from .dataimport import BASIC, number, payload
    code = masked(body); sym = p.resolve(symbol); span = _function_span(code, sym.name)
    if not span or re.search(r'#pragma\s+(?:pack|options\s+align)\b',code):
        return []
    layouts,sizes = record_layouts(code,span[0]); out=native_bss_objects(p,symbol,body,check)
    # Lifts often retain an array declaration and cast it to a recovered pool
    # view. Normalize that spelling before splitting the same measured layout.
    for alias in re.finditer(r'\bstruct\s+(\w+)\s*\*\s*(\w+)\s*=\s*\(\s*struct\s+\1\s*\*\s*\)\s*(\w+)\s*;',code[span[0]:span[1]]):
        typ,root,anchor=alias.groups()
        declaration=re.search(r'\bextern\s+(?:u8|char|unsigned char)\s+'+re.escape(anchor)+r'\s*\[\s*\]\s*;',code[:span[0]])
        if not declaration or typ not in layouts or len(re.findall(r'\b'+re.escape(anchor)+r'\b',code))!=2:
            continue
        lo,hi=span[0]+alias.start(),span[0]+alias.end()
        text=body[:lo]+f'struct {typ} *{root};\n{root} = &{anchor};'+body[hi:]
        text=text[:declaration.start()]+f'extern struct {typ} {anchor};'+text[declaration.end():]
        out.extend(native_pool_objects(p,symbol,text,check))
    for declaration in re.finditer(r'\bextern\s+(?:const\s+)?(?:struct\s+)?(\w+)\s+(\w+)\s*;',code[:span[0]]):
        typ,anchor=declaration[1],declaration[2]; owner=p.find_symbol(anchor,sym.module)
        if not owner or owner.module!=sym.module or owner.section not in ('.data','.rodata') or typ not in layouts:
            continue
        fields=[f for f in layouts[typ] if not f[0].startswith('pad_')]
        if not fields or sizes[typ][0]<=owner.size:
            continue
        limit=owner.addr+max(offset+width*math.prod(dims or (1,)) for _,_,offset,width,dims in fields)
        objects=sorted((s for s in p.symbols(sym.module).values() if s.kind=='object' and s.section==owner.section
                        and owner.addr<=s.addr),key=lambda s:(s.addr,-s.size))
        table=next((s.addr for s in objects if s.name.startswith('jumptable_') and s.addr>=limit),None)
        if table is not None and table-owner.addr<=0x10000:
            limit=table
        selected=[];cursor=owner.addr
        for obj in objects:
            if obj.addr>=limit:
                break
            if obj.addr<cursor or not obj.size:
                continue
            if obj.addr!=cursor:
                from .evidence import retail_bytes
                gap=obj.addr-cursor
                if gap>7 or retail_bytes(p,sym.module,owner.name,cursor-owner.addr,gap)!=bytes(gap):
                    break
            if obj.name.startswith('jumptable_'):
                break
            selected.append(obj);cursor=obj.addr+obj.size
        if cursor<limit or not selected:
            continue
        roots={anchor:'.'}; assignments=[]
        for assignment in re.finditer(r'\b(\w+)\s*=\s*(?:\(\s*(?:struct\s+)?'+re.escape(typ)+r'\s*\*\s*\)\s*)?&'+re.escape(anchor)+r'\s*;',code[span[0]:span[1]]):
            root=assignment[1]
            if len(re.findall(r'\b'+re.escape(root)+r'\s*=(?!=)',code[span[0]:span[1]]))==1:
                a,b=span[0]+assignment.start(),span[0]+assignment.end()
                prefix=code[code.rfind('\n',span[0],a)+1:a]
                replacement=root+';' if re.fullmatch(r'\s*(?:struct\s+)?'+re.escape(typ)+r'\s*\*\s*',prefix) else ''
                roots[root]='->';assignments.append((a,b,replacement))
        atoms={};valid=True
        for field,kind,offset,width,dims in fields:
            extent=width*math.prod(dims or (1,));address=owner.addr+offset
            parent=next((o for o in selected if o.addr<=address and address+extent<=o.addr+o.size),None)
            if kind not in BASIC or BASIC[kind][0]!=width or not parent or len(dims)>1 or extent<=0:
                valid=False;break
            delta=address-parent.addr
            name=parent.name if not delta else parent.name+f'__fzgx_offset_{delta:X}'
            atoms[address]=(address+extent,name,kind,dims,field)
        if not valid:
            continue
        definitions=[];replacements={}
        try:
            for obj in selected:
                if obj.name!=anchor and re.search(r'\b'+re.escape(obj.name)+r'\b',code):
                    raise ValueError('another declaration already owns this pool object')
                data,relocs=payload(p,obj)
                if relocs:
                    raise ValueError('pointer-bearing pool needs symbolic relocation recovery')
                cuts=sorted({obj.addr,obj.addr+obj.size}|{x for a,v in atoms.items() for x in (a,v[0]) if obj.addr<=x<=obj.addr+obj.size})
                for lo,hi in zip(cuts,cuts[1:]):
                    raw=data[lo-obj.addr:hi-obj.addr];atom=atoms.get(lo)
                    if atom and atom[0]==hi:
                        _,name,kind,dims,field=atom
                        values=[number(raw[i:i+BASIC[kind][0]],kind) for i in range(0,len(raw),BASIC[kind][0])]
                        # MWCC folds a const integer scalar into an immediate (`li r0, -1`) while retail
                        # loaded the pool word; a one-element array keeps the load (probe, 2026-09-16)
                        scalar_word = not dims and kind not in ('f32','float','f64','double')
                        declaration_=kind+' '+name+('['+str(dims[0])+']' if dims else '[1]' if scalar_word else '')
                        initializer='{'+','.join(values)+'}' if dims or scalar_word else values[0]
                        replacements[field]=name+'[0]' if scalar_word else name
                    else:
                        delta=lo-obj.addr;name=obj.name if not delta else obj.name+f'__fzgx_offset_{delta:X}'
                        declaration_=f'u8 {name}[{len(raw)}]';initializer='{'+','.join(f'0x{x:02X}' for x in raw)+'}'
                    definitions.append(('const ' if owner.section=='.rodata' else '')+declaration_+' = '+initializer+';')
        except (ValueError,KeyError):
            continue
        edits=list(assignments)
        for root,operator in roots.items():
            for use in re.finditer(r'\b'+re.escape(root)+r'\s*'+re.escape(operator)+r'\s*(\w+)',code[span[0]:span[1]]):
                if use[1] not in replacements:
                    valid=False;break
                edits.append((span[0]+use.start(),span[0]+use.end(),replacements[use[1]]))
        # Any remaining use of the old base needs its own address/lifetime proof.
        # Check the input spans: a recovered first atom can legitimately have
        # the same name as the old aggregate anchor.
        remaining=code
        for a,b,_ in sorted(edits,reverse=True):remaining=remaining[:a]+' '*(b-a)+remaining[b:]
        remaining=remaining[span[0]:span[1]]
        if any(re.search(r'\b'+re.escape(root)+r'\b', re.sub(r'\b(?:struct\s+)?\w+\s*\*\s*'+re.escape(root)+r'\s*;|\b'+re.escape(root)+r'\s*;','',remaining)) for root in roots):
            continue
        if valid:
            text=body
            for a,b,value in sorted(edits,reverse=True):text=text[:a]+value+text[b:]
            text=text[:declaration.start()]+'\n'.join(definitions)+text[declaration.end():]
            out.append(('recover native shared-pool objects '+anchor,text))
    return out


def native_bss_objects(p, symbol, body, check):
    """Recover separate retail objects hidden by an oversized private BSS view."""
    from .sdkimport import masked
    from .signatures import record_layouts, record_tag
    code=masked(body);sym=p.resolve(symbol);span=_function_span(code,sym.name)
    if not span:
        return []
    layouts,sizes=record_layouts(code,span[0]);out=[]
    for declaration in re.finditer(r'\bextern\s+((?:struct\s+)?\w+)\s+(\w+)\s*;',code[:span[0]]):
        typ,anchor=declaration[1],declaration[2];tag=record_tag(typ);owner=p.find_symbol(anchor,sym.module)
        if not owner or owner.section!='.bss' or tag not in layouts or sizes[tag][0]<=owner.size:
            continue
        used=[f for f in layouts[tag] if not f[0].startswith('pad')]
        if not used:
            continue
        limit=owner.addr+max(off+width*math.prod(dims or (1,)) for _,_,off,width,dims in used)
        objects=sorted((s for s in p.symbols(sym.module).values() if s.kind=='object' and s.section==owner.section
                        and owner.addr<=s.addr<limit and s.size),key=lambda s:s.addr)
        if not objects or objects[0].name!=anchor or any(a.end>b.addr for a,b in zip(objects,objects[1:])):
            continue
        groups={obj.name:[] for obj in objects};valid=True
        for field,kind,offset,width,dims in used:
            address=owner.addr+offset;extent=width*math.prod(dims or (1,))
            obj=next((s for s in objects if s.addr<=address and address+extent<=s.end),None)
            if not obj:
                valid=False;break
            groups[obj.name].append((field,kind,address-obj.addr,width,dims))
        if not valid:
            continue
        roots={anchor:'.'};edits=[];boundary_edits=[]
        for assignment in re.finditer(r'\b(\w+)\s*=\s*(?:\(\s*'+re.escape(typ)+r'\s*\*\s*\)\s*)?&'+re.escape(anchor)+r'\s*;',code[span[0]:span[1]]):
            root=assignment[1]
            if len(re.findall(r'\b'+re.escape(root)+r'\s*=(?!=)',code[span[0]:span[1]]))==1:
                roots[root]='->'
                # Preserve its declaration when this was an initialized local.
                edits.append((span[0]+assignment.start(),span[0]+assignment.end(),root+';'))
                boundary_edits.append((span[0]+assignment.start(),span[0]+assignment.end(),root+' = ('+typ+' *)&'+anchor+';'))
        definitions=[];replacements={}
        for obj in objects:
            if obj.name!=anchor and re.search(r'\b'+re.escape(obj.name)+r'\b',code):
                valid=False;break
            fields=groups[obj.name]
            if not fields:
                if obj.addr%4:
                    definitions.extend('u8 '+(obj.name if not i else obj.name+f'__fzgx_offset_{i:X}')+';'
                                       for i in range(obj.size))
                else:
                    definitions.append(f'u8 {obj.name}[{obj.size}];')
                continue
            if len(fields)==1:
                field,kind,offset,width,dims=fields[0]
                if offset==0 and width*math.prod(dims or (1,))==obj.size:
                    definitions.append(kind+' '+obj.name+''.join('['+str(n)+']' for n in dims)+';')
                    replacements[field]=obj.name
                    continue
            cursor=0;members=[]
            for field,kind,offset,width,dims in fields:
                if offset>cursor:members.append(f'u8 fzgx_pad_{cursor:X}[{offset-cursor}];')
                members.append(kind+' '+field+''.join('['+str(n)+']' for n in dims)+';')
                cursor=offset+width*math.prod(dims or (1,));replacements[field]=obj.name+'.'+field
            if cursor<obj.size:members.append(f'u8 fzgx_pad_{cursor:X}[{obj.size-cursor}];')
            definitions.append('struct { '+' '.join(members)+' } '+obj.name+';')
        if not valid:
            continue
        boundary_fields={field for obj in objects for field,kind,offset,width,dims in groups[obj.name]
                         if offset==0 and obj.name!=anchor}
        for root,operator in roots.items():
            for use in re.finditer(r'\b'+re.escape(root)+re.escape(operator)+r'(\w+)',code[span[0]:span[1]]):
                if use[1] not in replacements:
                    valid=False;break
                edits.append((span[0]+use.start(),span[0]+use.end(),replacements[use[1]]))
            for use in re.finditer(r'&\s*\b'+re.escape(root)+re.escape(operator)+r'(\w+)',code[span[0]:span[1]]):
                if use[1] in boundary_fields:
                    boundary_edits.append((span[0]+use.start(),span[0]+use.end(),'&'+replacements[use[1]]))
        if not valid:
            continue
        text=body
        for a,b,value in sorted(edits,reverse=True):text=text[:a]+value+text[b:]
        remaining=masked(text[_function_span(masked(text),sym.name)[0]:])
        # Replacing the pool is safe only when every old view has been resolved.
        if any(re.search(r'\b'+re.escape(root)+r'\b',re.sub(r'\b'+re.escape(typ)+r'\s*\*\s*'+re.escape(root)+r'\s*;','',remaining)) for root in roots):
            continue
        decls='#pragma explicit_zero_data on\n'+'\n'.join(d[:-1]+' = {0};' for d in definitions)+'\n#pragma explicit_zero_data reset'
        out.append(('recover native BSS objects '+anchor+' initialized',
                    text[:declaration.start()]+decls+text[declaration.end():]))
        if boundary_edits and not re.search(r'\b'+re.escape(anchor)+r'\s*\.',code[span[0]:span[1]]):
            partial=body
            for a,b,value in sorted(boundary_edits,reverse=True):partial=partial[:a]+value+partial[b:]
            out.append(('recover native BSS boundaries '+anchor,
                        partial[:declaration.start()]+decls+partial[declaration.end():]))
    return out


def stack_object_boundaries(p, symbol, body, check):
    """Split a lifted array at proven compiler conversion scratch storage."""
    from . import fixup_source as source
    from .sdkimport import masked
    from .evidence import assembly_rows
    from .lift import integer_float_pairs
    code = masked(body); span = source._function_body_span(code, p.resolve(symbol).name)
    if not span:
        return []
    rows = assembly_rows(p.function_asm(p.resolve(symbol).module)[p.resolve(symbol).name])
    addresses = {r['instruction']['address']:i for i,r in enumerate(rows)}
    ins, labels = [], {}
    for row in rows:
        instruction = row['instruction']; op, _, args = instruction['formatted'].partition(' ')
        args = [a.strip() for a in args.split(',')]
        if instruction.get('branch_dest') in addresses:
            labels[args[-1]] = addresses[instruction['branch_dest']]
        ins.append((op,args))
    pairs = integer_float_pairs(ins,labels)
    scratch = {int(ins[i][1][1].split('(')[0],0) for i in pairs}
    if not scratch:
        return []
    escapes = {int(args[2],0) for op,args in ins if op=='addi' and len(args)==3 and args[1]=='r1'
               and re.fullmatch(r'0x[\da-f]+|\d+',args[2])}
    out = []
    for start,end,ty,name,dims in source._locals(body,span):
        local = re.fullmatch(r'loc_([\dA-F]+)',name)
        array = re.fullmatch(r'struct\s*\{\s*(u32|s32|f32)\s+(\w+)\[(\d+)\];\s*\}',ty.strip())
        if not local or not array or dims:
            continue
        base, count = int(local[1],16), int(array[3])
        cuts = sorted(o for o in scratch if base < o < base+count*4 and (o-base)%4==0)
        if base not in escapes or not cuts:
            continue
        cut = cuts[0]; index = (cut-base)//4; tail = name+'_tail'
        if re.search(r'\b'+tail+r'\b',code):
            continue
        # Pointer arithmetic/casts over the inferred whole object would need
        # their own extent proof. Array element uses have exact known bounds.
        uses = list(re.finditer(r'\b'+re.escape(name)+r'\b',code[end:span[2]]))
        edits = []; valid = True
        for use in uses:
            a = end+use.start(); b = end+use.end()
            element = re.match(r'\.'+re.escape(array[2])+r'\[(\d+)\]',code[b:])
            if element:
                slot = int(element[1])
                if slot >= count:
                    valid = False; break
                if slot >= index:
                    edits.append((a,b+element.end(),f'{tail}[{slot-index}]'))
            elif re.search(r'\*\s*\)\s*&\s*$',code[max(span[1],a-48):a]) or code[b:b+1] in '.[':
                valid = False; break
        if not valid or not edits:
            continue
        declaration = f'    struct {{ {array[1]} {array[2]}[{index}]; }} {name};\n    {array[1]} {tail}[{count-index}];\n'
        text = body
        for a,b,value in reversed(edits):
            text = text[:a]+value+text[b:]
        text = text[:start]+declaration+text[end:]
        out.append((f'retail stack object boundary {name} at {cut:#x}',text))
    return out


def bitmask_arguments(p, symbol, body):
    """Spell scalar flag masks as bits when the retail callee proves their use."""
    from .fixup_source import call_sites
    from .lint import RANGES
    from .sdkimport import masked
    code=masked(body);sym=p.resolve(symbol);span=_function_span(code,sym.name)
    if not span:
        return []
    edits=[];proven={}
    for callee,start,end,args in call_sites(code):
        if not span[0]<=start<end<=span[1] or not args:
            continue
        a,b=args[0];literal=code[a:b].strip()
        if not re.fullmatch(r'0[xX][0-9a-fA-F]{8}[uUlL]*',literal):
            continue
        value=int(literal.rstrip('uUlL'),16)
        if not any(lo<=value<=hi for lo,hi in RANGES):
            continue
        if callee not in proven:
            target=p.find_symbol(callee,sym.module)
            fn=p.callable_asm(target) if target and target.kind=='function' and target.size<=128 else None
            instructions=[line.split(': ',1)[-1] for line in fn.asm] if fn else []
            uses=[text for text in instructions if re.search(r'\br3\b',text)]
            # A straight-line setter must consume its first argument only as a
            # bitwise input. In particular, no address, call or returned pointer
            # can be hidden behind an integer prototype in a saved candidate.
            proven[callee]=bool(instructions and instructions[-1]=='blr' and uses and
                all(re.fullmatch(r'(?:or|and|xor|andc) r(?!3\b)\d+, r\d+, r3',text) or
                    re.fullmatch(r'(?:or|and|xor) r(?!3\b)\d+, r3, r\d+',text) for text in uses) and
                all(text.split()[0] in ('lis','addi','lwz','stw','or','and','xor','andc','blr') for text in instructions) and
                not any(text=='blr' for text in instructions[:-1]))
        if proven[callee]:
            shift=(value&-value).bit_length()-1
            edits.append((a,b,f'(0x{value>>shift:X}u << {shift})'))
    if not edits:
        return []
    text=body
    for a,b,value in reversed(edits):
        text=text[:a]+value+text[b:]
    return [('retail scalar flag masks',text)]


def format_arguments(p, symbol, body):
    """Recover omitted variadic arguments from owned prototypes and retail text."""
    from .fixup_source import call_sites, declared_types, member_type, record_layouts, member_layout
    from .sdkimport import masked, integer_expression
    from .evidence import retail_bytes
    from .dataimport import BASIC
    sym=p.resolve(symbol);code=masked(body);span=_function_span(code,sym.name)
    if not span:
        return []
    fields,variables=declared_types(code,span[0])
    layouts=record_layouts(code,span[0],variables)
    signature=code[span[0]:code.index('{',span[0])]
    parameters={m[1] for part in signature[signature.index('(')+1:signature.rfind(')')].split(',')
                if (m:=re.search(r'(\w+)\s*(?:\[[^]]*\])?\s*$',part))}
    formats={'OSReport':0,'OSPanic':2,'printf':0,'sprintf':1,'snprintf':2}
    calls=call_sites(body)
    for name,start,end,args in calls:
        if start>=span[0] or len(args)<2 or code[args[-1][0]:args[-1][1]].strip()!='...':
            continue
        if re.search(r'\bchar\s*\*',code[args[-2][0]:args[-2][1]]):
            formats[name]=len(args)-2
    # Formatter callbacks often use a generic void* format parameter. Their
    # typedef still proves the variadic boundary; retail text proves the format.
    for pointer in re.finditer(r'(?m)^[ \t]*(typedef\s+)?[^;{}\n]+?\(\s*\*\s*(\w+)\s*\)\s*\(([^;{}]*)\)\s*;',code[:span[0]]):
        pointer_params=[arg.strip() for arg in pointer[3].split(',')]
        if len(pointer_params)<2 or pointer_params[-1]!='...' or not re.search(r'\b(?:char|void)\s*\*',pointer_params[-2]):
            continue
        if pointer[1]:
            formats.update({name:len(pointer_params)-2 for name,ty in variables.items()
                            if re.sub(r'\b(?:const|volatile|register)\b','',ty).strip()==pointer[2]})
        else:
            formats[pointer[2]]=len(pointer_params)-2
    aliases={}
    for match in re.finditer(r'\b(\w+)\s*=\s*([^;{}]+);',code[:span[1]]):
        if len(re.findall(r'\b'+re.escape(match[1])+r'\s*=(?!=)',code[:span[1]]))==1:
            aliases[match[1]]=match[2].strip()
    for name,owner in re.findall(r'(?m)^#define\s+(\w+)\s+(\w+)\s*$',code[:span[0]]):
        aliases[name]=owner
        if owner in variables:
            variables[name]=variables[owner]

    def address(expression,seen=()):
        from .fixup_source import TYPE
        expression=expression.strip()
        while True:
            previous=expression
            cast=re.match(r'^\(\s*'+TYPE+r'\s*\)\s*',expression)
            if cast and cast.end()<len(expression):
                expression=expression[cast.end():].strip()
            if expression.startswith('(') and expression.endswith(')'):
                depth=0
                for i,ch in enumerate(expression):
                    depth+=(ch=='(')-(ch==')')
                    if depth==0:
                        break
                if i==len(expression)-1:
                    expression=expression[1:-1].strip()
            if expression==previous:
                break
        member=re.fullmatch(r'&?\s*(\w+(?:(?:->|\.)\w+)+)',expression)
        if member:
            layout=member_layout(member[1],layouts,variables)
            if not layout or layout[2] not in ('char','u8','s8','unsigned char','signed char') or layout[3] is None:
                return None
            value=address(layout[0],seen)
            return (value[0],value[1]+layout[1]) if value else None
        match=re.fullmatch(r'&?\s*(\w+)\s*(?:\[([^]]+)\]|\+\s*(.+))?',expression)
        if not match or match[1] in seen:
            return None
        root=match[1];target=p.find_symbol(root,sym.module)
        value=(target.name,0) if target and target.kind=='object' else address(aliases[root],(*seen,root)) if root in aliases else None
        if value is None:
            return None
        if match[2] or match[3]:
            ty=re.sub(r'\b(?:const|volatile|struct|union)\b|\*','',variables.get(root,'')).strip()
            if ty not in BASIC:
                return None
            try:
                delta=integer_expression(match[2] or match[3])*BASIC[ty][0]
            except (ValueError,SyntaxError):
                return None
            value=(value[0],value[1]+delta)
        return value

    out=[]
    for callee,start,end,args in calls:
        index=formats.get(callee)
        if index is None or not span[0]<=start<end<=span[1] or len(args)<=index:
            continue
        text=body[args[index][0]:args[index][1]].strip()
        if re.fullmatch(r'"(?:\\.|[^"\\])*"',text):
            try:
                fmt=ast.literal_eval(text)
            except (ValueError,SyntaxError):
                continue
        else:
            location=address(text)
            if location is None:
                continue
            raw=retail_bytes(p,sym.module,*location,1024)
            if not raw or b'\0' not in raw:
                continue
            try:
                fmt=raw.split(b'\0',1)[0].decode('ascii')
            except UnicodeDecodeError:
                continue
        expected=[];valid=True;position=0
        while '%' in fmt[position:]:
            position=fmt.index('%',position)
            spec=re.match(r'%(%|[-+ #0]*([*]|\d+)?(?:\.([*]|\d+))?(hh|ll|[hljztL])?([diuoxXfFeEgGaAcspn]))',fmt[position:])
            if not spec:
                valid=False;break
            position+=spec.end()
            if spec[1]=='%':
                continue
            expected.extend('integer' for width in (spec[2],spec[3]) if width=='*')
            expected.append('pointer' if spec[5] in 'spn' else 'float' if spec[5] in 'fFeEgGaA'
                            else 'integer64' if spec[4] in ('ll','j') else 'integer')
        supplied=len(args)-index-1
        if not valid or supplied>=len(expected):
            continue
        wanted=expected[supplied];candidates=[]
        for use in reversed(list(re.finditer(r'\b\w+(?:(?:->|\.)\w+)*\b',code[span[0]:start]))):
            expression=use[0];ty=member_type(expression,fields,variables).strip()
            kind='pointer' if '*' in ty else 'float' if ty in ('f32','f64','float','double') else 'integer64' if ty in ('u64','s64','long long','unsigned long long') else 'integer' if ty in BASIC else None
            if kind!=wanted or expression in candidates or 'volatile' in ty:
                continue
            if re.match(r'\s*\[',code[span[0]+use.end():]):
                continue
            if '->' not in expression and '.' not in expression and expression not in parameters and not p.find_symbol(expression,sym.module):
                if not re.search(r'\b'+re.escape(expression)+r'\s*=(?!=)',code[span[0]:start]):
                    continue
            candidates.append(expression)
            if len(candidates)>=24:
                break
        for expression in candidates:
            out.append((f'retail format argument {callee} slot {supplied+1}: {expression}',body[:end-1]+', '+expression+body[end-1:]))
    return out



PARAM_COPY_RE = re.compile(r'^(?:mr|fmr) ([rf])(\d+), ([rf])(\d+)$')


def _prologue_parameters(rows):
    """{argument register: callee-saved register} for parameters copied out of r3..r10 /
    f1..f8 before the first branch, call or compare: the prologue's own parameter homes."""
    out = {}
    for text in rows[:80]:
        if not text:
            continue
        if text.startswith(('b', 'cmp')) and not text.startswith('bl _save'):
            break
        m = PARAM_COPY_RE.match(text)
        if not m or m[1] != m[3]:
            continue
        src, dst = int(m[4]), int(m[2])
        first, last = (3, 10) if m[1] == 'r' else (1, 8)
        if first <= src <= last and dst >= 14 and (m[1], src) not in out:
            out[(m[1], src)] = dst
    return out


def _signature_parameters(body, name):
    """[(type, name)] of the function definition's named parameters."""
    m = re.search(r'\b' + re.escape(name) + r'\s*\(([^;{]*)\)\s*\{', body)
    if not m:
        return []
    out = []
    for part in m[1].split(','):
        part = part.strip()
        if not part or part == 'void' or part == '...':
            continue
        dm = re.fullmatch(r'(.*?[\w*])\s*(?<![\w])([A-Za-z_]\w*)((?:\[[^\]]*\])*)', part)
        if not dm:
            return []
        out.append((dm[1].strip(), dm[2]))
    return out


def parameter_copies(p, symbol, body, check):
    """Parameters are numbered below every declared local, so a parameter that retail keeps
    in a callee-saved register above a local's is a local copy of the parameter
    (`s32 id = arg0;`) declared where the register order puts it; a parameter that retail
    keeps below ours is a copy this body made that retail did not (fn_1_A358C, capture-
    verified: arg0 is vr32 under every declaration order, retail holds it in r28 above i)."""
    sym = p.resolve(symbol)
    rows = [(stuck._fmt(t), stuck._fmt(o)) for t, o in zip(*check._rows)]
    retail = _prologue_parameters([t for t, _ in rows])
    ours = _prologue_parameters([o for _, o in rows])
    if not retail or not ours:
        return []
    params = _signature_parameters(body, sym.name)
    if not params:
        return []
    # argument registers in signature order: r3.. for integers/pointers, f1.. for floats
    slots = []
    gpr, fpr = 3, 1
    for typ, nm in params:
        if re.fullmatch(r'(?:const\s+)?(?:f32|f64|float|double)', typ):
            slots.append((('f', fpr), typ, nm)); fpr += 1
        else:
            slots.append((('r', gpr), typ, nm)); gpr += 1
    from . import fixup_source as source
    anchor = source._decl_anchor(body, sym.name)
    if not anchor:
        return []
    span, locs, top, indent = anchor
    inner_start = top
    out = []
    for key, typ, nm in slots:
        if key not in retail or key not in ours or retail[key] == ours[key]:
            continue
        ident = r'(?<![\w.>])' + re.escape(nm) + r'\b'
        inner = body[inner_start:span[2]]
        if retail[key] > ours[key]:
            copy = nm + '_local'
            if re.search(r'\b' + re.escape(copy) + r'\b', body):
                continue
            if not re.search(ident, inner):
                continue
            renamed = re.sub(ident, copy, inner)
            # the copy is numbered like a local at its declaration position: the locals
            # retail colours above it are the first ones declared, so the predicted position
            # is after as many declared scalars as retail keeps registers above the parameter
            above = sum(1 for reg in range(retail[key] + 1, 32) if reg not in retail.values())
            positions = [('first', locs[0][0] if locs else top)] + [(f'after {l[3]}', l[1]) for l in locs]
            order = sorted(range(len(positions)), key=lambda i: abs(i - above))
            for i in order:
                label, pos = positions[i]
                text = body[:pos] + f'{indent}{typ} {copy} = {nm};\n' + body[pos:inner_start] + renamed + body[span[2]:]
                out.append((f'retail parameter copy {nm} declared {label}', text))
        else:
            # a copy this body made: drop it and use the parameter directly
            for s0, e0, ltyp, lname, dims in locs:
                init = re.match(r'\s*' + re.escape(ltyp.strip()) + r'\s*' + re.escape(lname) + r'\s*=\s*(\w+)\s*;', body[s0:e0])
                if not init or init[1] != nm or dims:
                    continue
                rest = body[e0:span[2]]
                if re.search(ident, rest) or re.search(r'(?<![\w.>])' + re.escape(lname) + r'\s*=[^=]', rest):
                    continue
                text = body[:s0] + re.sub(r'(?<![\w.>])' + re.escape(lname) + r'\b', nm, rest) + body[span[2]:]
                out.append((f'retail parameter copy {nm}: drop {lname}', text))
    return out


def missing_call_copies(check):
    """Live argument copies present only in retail, without intervening writes."""
    rows=[(stuck._fmt(t),stuck._fmt(o)) for t,o in zip(*check._rows)]
    copies=set()
    for i,(target,ours) in enumerate(rows):
        move=re.fullmatch(r'(?:mr|fmr) ([rf]\d+), ([rf]\d+)',target)
        if not move or ours:
            continue
        for text,_ in rows[i+1:i+10]:
            call=re.fullmatch(r'bl (\w+)',text)
            if call:
                copies.add((call[1],move[2],move[1]));break
            if text.startswith('b') or re.match(r'\w+[.]?\s+(?:'+re.escape(move[1])+'|'+re.escape(move[2])+r'),',text):
                break
    return copies


def swapped_call_arguments(p, symbol, body, check):
    """An exchanged pair of outgoing values may be wrong C arguments, not allocation.

    Include calls through cast function pointers. They have no identifier for
    the ordinary call-lifetime repair to find. Every proposal needs a stock
    compile and the full object oracle before it can be accepted.
    """
    from .fixup_source import call_sites
    from .sdkimport import masked
    code = masked(body)
    span = _function_span(code, p.resolve(symbol).name)
    if not span:
        return []
    moves, swaps = {}, set()
    for left, right in zip(*check._rows):
        target, ours = stuck._fmt(left).strip(), stuck._fmt(right).strip()
        a = re.fullmatch(r'(mr|fmr) ([rf]\d+), ([rf]\d+)', target)
        b = re.fullmatch(r'(mr|fmr) ([rf]\d+), ([rf]\d+)', ours)
        if a and b and a.group(1, 2) == b.group(1, 2) and a[3] != b[3]:
            moves[a[2]] = (a[3], b[3])
        call = re.fullmatch(r'bl (\w+)', target)
        if call or target in ('bctrl', 'blrl'):
            callee = call[1] if call else '<indirect>'
            for first, second in itertools.combinations(moves, 2):
                if first[0] != second[0] or moves[first] != moves[second][::-1]:
                    continue
                base, end = (3, 11) if first[0] == 'r' else (1, 9)
                slots = sorted((int(first[1:]), int(second[1:])))
                if base <= slots[0] < slots[1] < end:
                    swaps.add((callee, first[0], slots[0] - base, slots[1] - base))
        if target.startswith('b'):
            moves = {}
    groups = {}
    for callee, start, end, args in call_sites(code, indirect=True):
        if not span[0] <= start < end <= span[1]:
            continue
        for wanted, bank, first, second in swaps:
            if callee != wanted or second >= len(args):
                continue
            # Position is unambiguous for a homogeneous prefix. Mixed-bank
            # signatures need the signature-aware ABI recovery instead.
            parts = [code[a:b].strip() for a, b in args[:second + 1]]
            floats = [bool(re.match(r'\((?:f32|f64|float|double)\)', part) or
                           re.fullmatch(r'[-+]?\d+\.\d*(?:[eE][-+]?\d+)?[fF]?', part)) for part in parts]
            if bank == 'r' and any(floats) or bank == 'f' and not all(floats):
                continue
            a, b = args[first], args[second]
            if code[a[0]:a[1]].strip() == code[b[0]:b[1]].strip():
                continue
            groups.setdefault((callee, first, second), []).append(
                [(a[0], a[1], body[b[0]:b[1]]), (b[0], b[1], body[a[0]:a[1]])])
    out = []
    for (callee, first, second), sites in groups.items():
        for selected in ([sites] if len(sites) > 1 else []) + [[site] for site in sites]:
            text = body
            edits = [edit for site in selected for edit in site]
            for a, b, replacement in sorted(edits, reverse=True):
                text = text[:a] + replacement + text[b:]
            out.append((f'retail exchanged arguments {callee} {first},{second} at ' +
                        ('every site' if selected is sites else str(edits[0][0])), text))
    return out


def call_arguments(p, symbol, body, check):
    """Recover argument order, narrow types and missing live ABI copies."""
    from .fixup_source import call_sites, declared_types, argument_lifetimes
    from .sdkimport import masked
    from .signatures import recovered, parameter, Signature
    code=masked(body);span=_function_span(code,p.resolve(symbol).name)
    copies=missing_call_copies(check)
    call_order=set()
    rows=[(stuck._fmt(t),stuck._fmt(o)) for t,o in zip(*check._rows)]
    for i,(target,ours) in enumerate(rows):
        if target==ours or i in getattr(check,'_accepted_rows',()) or not re.match(r'(?:addi|add|li|lis|mr|fmr|extsh|extsb|clrlwi) (?:r[3-9]|r10|f[1-8]),',target):
            continue
        for instruction,_ in rows[i+1:i+12]:
            called=re.fullmatch(r'bl (\w+)',instruction)
            if called:
                call_order.add(called[1]);break
            if instruction.startswith('b'):
                break
    out=[('retail argument order: '+label,text) for label,text in argument_lifetimes(body,p.resolve(symbol).name,call_order)] if call_order else []
    out.sort(key=lambda candidate:'at every site' not in candidate[0])
    narrows={}
    for i,(target,ours) in enumerate(rows):
        cast=re.fullmatch(r'(extsh|extsb) (r\d+), r\d+',target)
        if not cast or target==ours:
            continue
        for instruction,_ in rows[i+1:i+12]:
            called=re.fullmatch(r'bl (\w+)',instruction)
            if called:
                narrows.setdefault(called[1],{})[cast[2]]='s16' if cast[1]=='extsh' else 's8'
                break
            if instruction.startswith('b') or re.match(r'\w+[.]?\s+'+re.escape(cast[2])+',',instruction):
                break
    if not span or not (copies or narrows):
        return out
    index=recovered(p);calls=call_sites(body)
    types=dict(index.types);types.update(declared_types(code,span[0])[0])
    for callee,registers in narrows.items():
        prototypes=[call for call in calls if call[0]==callee and call[1]<span[0]]
        if len(prototypes)!=1:
            continue
        _,start,end,args=prototypes[0]
        params=[parameter(code[a:b],types) for a,b in args]
        if not params or None in params or '...' in params:
            continue
        slots=index.registers(Signature('void',tuple(params)))
        if not slots or len(slots)!=len(params):
            continue
        edits=[(args[i][0],args[i][1],registers[reg]) for i,(reg,ty) in enumerate(slots)
               if reg in registers and ty in ('u32','s32','int','unsigned int')]
        for changes in ([edits]+[[edit] for edit in edits] if edits else []):
            text=body
            for a,b,ty in reversed(changes):
                text=text[:a]+ty+text[b:]
            out.append((f'retail call parameter {callee} '+','.join(ty for _,_,ty in changes),text))
    for callee,source,dest in sorted(copies):
        prototypes=[call for call in calls if call[0]==callee and call[1]<span[0]]
        if len(prototypes)!=1:
            continue
        _,start,end,args=prototypes[0]
        params=[parameter(code[a:b],types) for a,b in args]
        if not params or None in params or '...' in params or params==['void']:
            continue
        slots=index.registers(Signature('void',tuple(params)))
        if not slots or len(slots)!=len(params) or source not in dict(slots) or dest in dict(slots):
            continue
        position=next(i for i,(reg,_) in enumerate(slots) if reg==source)
        extended=index.registers(Signature('void',tuple(params+[params[position]])))
        if not extended or extended[-1][0]!=dest:
            continue
        uses=[call for call in calls if call[0]==callee and span[0]<=call[1]<span[1]]
        if not uses or any(len(arguments)!=len(params) for _,_,_,arguments in uses):
            continue
        edits=[]
        for _,_,stop,arguments in uses:
            a,b=arguments[position];value=body[a:b].strip()
            if call_sites(value) or re.search(r'\+\+|--|(?<![=!<>])=(?!=)',value):
                break
            edits.append((stop-1,stop-1,', '+value))
        else:
            edits.append((end-1,end-1,', '+params[position]))
            text=body
            for a,b,value in sorted(edits,reverse=True):
                text=text[:a]+value+text[b:]
            out.append((f'retail call argument {callee} {source}->{dest}',text))
    return out


def frame_layout_only(check):
    """A uniform ABI frame-size change with identical non-frame instructions."""
    rows=[(stuck._fmt(t),stuck._fmt(o)) for t,o in zip(*check._rows)]
    frame=None;allowed=set()
    for i,(target,ours) in enumerate(rows[:16]):
        t=re.fullmatch(r'stwu r1, -(0x[\da-f]+)\(r1\)',target)
        o=re.fullmatch(r'stwu r1, -(0x[\da-f]+)\(r1\)',ours)
        if t and o and t[1]!=o[1]:frame=(int(t[1],0),int(o[1],0));frame_at=i;allowed.add(i);break
    if not frame:return False
    saved={}
    for i,(target,ours) in enumerate(rows):
        t=re.fullmatch(r'(stw|lwz|stfd|lfd|stmw|lmw) ([rf]\d+), (0x[\da-f]+)\(r1\)',target)
        o=re.fullmatch(r'(stw|lwz|stfd|lfd|stmw|lmw) ([rf]\d+), (0x[\da-f]+)\(r1\)',ours)
        if t and o and t.groups()[:2]==o.groups()[:2]:
            target_offset=int(t[3],0)+(frame[0] if i<frame_at else 0)
            our_offset=int(o[3],0)+(frame[1] if i<frame_at else 0)
            if our_offset-target_offset!=frame[1]-frame[0]:continue
            register=int(t[2][1:])
            if not (t[2]=='r0' or register>=14):continue
            key=(t[2],target_offset,our_offset)
            if i<16 and t[1].startswith('st'):saved[key]=i
            elif i>=len(rows)-16 and t[1].startswith('l') and key in saved:allowed.update((saved[key],i))
        if i>=len(rows)-16 and target==f'addi r1, r1, 0x{frame[0]:x}' and ours==f'addi r1, r1, 0x{frame[1]:x}':allowed.add(i)
    return all(t==o or i in allowed or i in getattr(check,'_accepted_rows',()) for i,(t,o) in enumerate(rows))


def zero_conditions(body, name, diffs):
    """Match signedness at a zero test without changing the value's home type."""
    from .fixup_source import call_sites,declared_types,member_type
    from .sdkimport import masked
    types=set()
    for target,ours in diffs:
        t=re.fullmatch(r'(cmpwi|cmplwi) r\d+, 0x0',target)
        o=re.fullmatch(r'(cmpwi|cmplwi) r\d+, 0x0',ours)
        if t and o and t[1]!=o[1]:types.add('u32' if t[1]=='cmplwi' else 's32')
    code=masked(body);span=_function_span(code,name)
    if not types or not span:return []
    fields,variables=declared_types(code,span[0]);out=[]
    for callee,start,end,args in call_sites(code):
        if callee not in ('if','while') or len(args)!=1 or not span[0]<=start<end<=span[1]:continue
        a,b=args[0];value=code[a:b].strip()
        if not re.fullmatch(r'\w+(?:(?:->|\.)\w+)*',value):continue
        ty=re.sub(r'\b(?:extern|static|register|const|volatile)\b','',member_type(value,fields,variables)).strip()
        if ty not in INT_TYPES:continue
        for target in sorted(types):
            out.append((f'retail zero comparison {value} as {target} at {a}',body[:a]+'('+target+')('+body[a:b]+')'+body[b:]))
            literal='0U' if target=='u32' else '0'
            out.append((f'retail zero comparison {value} != {literal} at {a}',body[:a]+body[a:b]+' != '+literal+body[b:]))
    return out


def float_conditions(body, name, diffs):
    """Recover ordered comparisons and the arm receiving unordered values."""
    if not any(t.startswith('cror ') or o.startswith('cror ') for t,o in diffs):
        return []
    from .fixup_source import call_sites, declared_types, member_type
    from .sdkimport import masked
    code=masked(body);span=_function_span(code,name)
    if not span:
        return []
    fields,variables=declared_types(code,span[0]);out=[]
    ordered={}
    # Nested positive tests encode a different unordered arm from the common
    # min/max clamp. Only propose this when the retail CR merge disagrees.
    clamp = re.compile(r'\b(\w+)\s*=\s*([0-9]+\.[0-9]+[fF]?)\s*;\s*'
        r'if\s*\(\s*(\w+)\s*>=\s*\2\s*\)\s*\{\s*'
        r'\1\s*=\s*([0-9]+\.[0-9]+[fF]?)\s*;\s*'
        r'if\s*\(\s*\3\s*<=\s*\4\s*\)\s*\{\s*'
        r'\1\s*=\s*((?:\(\s*(?:f32|f64|float|double)\s*\)\s*)?\3)\s*;\s*\}\s*\}')
    for match in clamp.finditer(code,span[0],span[1]):
        dest,low,value,high,result=match.groups()
        if member_type(value,fields,variables) not in ('f32','f64','float','double'):
            continue
        replacement=f'{dest} = {value} < {low} ? {low} : ({value} > {high} ? {high} : {result});'
        out.append((f'retail float branch clamp at {match.start()}',body[:match.start()]+replacement+body[match.end():]))
    for target,ours in diffs:
        if target==ours:continue
        merge=re.fullmatch(r'cror eq, (lt|gt), eq',target)
        if merge:
            operator='<=' if merge[1]=='lt' else '>='
            ordered[operator]=ordered.get(operator,0)+1
    def floating(expression):
        if re.search(r'\(\s*(?:f32|float|f64|double)\s*\)',expression):return True
        while expression.startswith('(') and expression.endswith(')'):
            depth=0
            for i,ch in enumerate(expression):
                depth+=(ch=='(')-(ch==')')
                if depth==0:break
            if i!=len(expression)-1:break
            expression=expression[1:-1].strip()
        return member_type(expression,fields,variables) in ('f32','float','f64','double')
    equality_sites=[]
    opposite={'<':'>=','<=':'>','>':'<=','>=':'<'}
    for callee,start,end,args in call_sites(code):
        if callee!='if' or len(args)!=1 or not span[0]<=start<end<=span[1]:
            continue
        # An omitted CR merge can turn <= into == in an old lift. These
        # atoms also occur in compound conditions and need no paired else arm.
        a,b=args[0]
        for atom in re.finditer(r'([^&|]+?)\s+(==)\s+([^&|]+)',code[a:b]):
            if any(floating(atom[i].strip()) for i in (1,3)):
                equality_sites.append((a+atom.start(2),a+atom.end(2)))
        a,b=args[0];comparison=re.fullmatch(r'\s*(.+?)\s+(<=|>=|<|>)\s+(.+?)\s*',code[a:b])
        arms=re.match(r'(\s*\{)([^{}]*)(\}\s*else\s*\{)([^{}]*)(\})',code[end:span[1]])
        if not comparison or not arms:
            continue
        if not any(floating(comparison[i].strip()) for i in (1,3)):
            continue
        condition=body[a:a+comparison.start(2)]+opposite[comparison[2]]+body[a+comparison.end(2):b]
        text=(body[:a]+condition+body[b:end+arms.start(2)]+body[end+arms.start(4):end+arms.end(4)]
              +body[end+arms.end(2):end+arms.start(4)]+body[end+arms.start(2):end+arms.end(2)]+body[end+arms.end(4):])
        out.append((f'retail float branch {comparison[2]}->{opposite[comparison[2]]} at {a}',text))
    for operator in sorted(ordered):
        groups=[[site] for site in equality_sites]
        count=ordered[operator]
        if 1<count<len(equality_sites):
            groups+=list(itertools.islice(itertools.combinations(equality_sites,count),32))
        if len(equality_sites)>1:groups.append(equality_sites)
        for sites in groups:
            text=body
            for a,b in reversed(sites):text=text[:a]+operator+text[b:]
            label=','.join(str(a) for a,_ in sites)
            out.append((f'retail ordered float comparison ==->{operator} at {label}',text))
    return out


def shared_pool_coverage(p, symbol, check):
    """Aligned pool loads and addresses, including proven private bindings."""
    from .evidence import memory_loads, object_jump_tables
    sym = p.resolve(symbol)
    left = memory_loads(check._rows[0], object_jump_tables(p.target_object_for(sym),sym.name,p,sym.module),addresses=True)
    right = memory_loads(check._rows[1], object_jump_tables(check._object,sym.name),addresses=True)
    from .poolfix import Elf, binding_target
    elf = Elf(check._object.read_bytes())
    objects = {s['name']:s for s in elf.symbols()}
    bindings = {private:binding_target(target) for private,target,_ in getattr(check,'_pool_pairs',[])}
    matching = 0
    for i,load in left.items():
        target = p.find_symbol(load['symbol'],sym.module)
        other = right.get(i)
        if not target or target.section not in ('.rodata','.sdata2') or not other:
            continue
        anchor, offset = other['symbol'], other['offset']
        if anchor in bindings:
            own = objects.get(anchor)
            if not own or not 0 < own['shndx'] < len(elf.sections):
                continue
            size = own['size'] or elf.sections[own['shndx']]['size']-own['value']
            if not 0 <= offset <= size-other['width']:
                continue
            anchor, delta = bindings[anchor]
            offset += delta
        candidate = p.find_symbol(anchor,sym.module)
        if candidate and candidate.section == target.section and candidate.module == target.module:
            matching += (target.addr+load['offset'] == candidate.addr+offset and load['op'] == other['op'])
    return matching


def stack_aggregates(body: str, diffs: List[Tuple[str, str]]) -> List[Tuple[str, str]]:
    """Remove a draft's fake aggregate prefix when only the stack copy is biased.

    A pointer before a local array can make field accesses agree while moving the
    aggregate copy into the frame header. Recover the field origin and copy origin
    together; retain the union's array member so its size does not shrink.
    """
    deltas = set()
    for target, ours in diffs:
        pattern = r'addi r\d+, r1, (-?0x[0-9a-f]+|-?\d+)$'
        t, o = re.fullmatch(pattern, target), re.fullmatch(pattern, ours)
        if t and o:
            deltas.add(int(t[1], 0) - int(o[1], 0))
    if len(deltas) != 1 or next(iter(deltas)) <= 0:
        return []
    delta = next(iter(deltas))
    out = []
    union = r'typedef\s+union\s*\{[^{}]*struct\s*\{(?P<fields>[^{}]*)\}\s+\w+;[^{}]*\}\s*(?P<type>\w+)\s*;'
    for declaration in re.finditer(union, body):
        fields = declaration['fields']
        first = re.match(r'\s*(u8|s8|u16|s16|u32|s32)\s+(\w+)(?:\[(0[xX][0-9a-fA-F]+|\d+)\])?\s*;', fields)
        if not first:
            continue
        size = int(first[1][1:]) // 8 * (int(first[3], 0) if first[3] else 1)
        if size != delta or re.search(rf'(?:\.|->){re.escape(first[2])}\b', body[declaration.end():]):
            continue
        assignment = (rf'\b(\w+)\s*=\s*\({re.escape(declaration["type"])}\s*\*\)\s*'
                      r'\(\(u8\s*\*\)\s*(\w+)\s*-\s*(0[xX][0-9a-fA-F]+|\d+)\s*\)')
        for source in re.finditer(assignment, body[declaration.end():]):
            if int(source[3], 0) != delta:
                continue
            start, end = declaration.end() + source.start(), declaration.end() + source.end()
            text = body[:start] + f'{source[1]} = ({declaration["type"]} *){source[2]}' + body[end:]
            at = declaration.start('fields')
            text = text[:at] + fields[first.end():] + text[declaration.end('fields'):]
            pointer, array, typ = source[1], source[2], declaration['type']
            # A real aggregate local rematerializes its address at each call.
            # Keeping the draft's pointer would make MWCC save it across calls.
            split = declaration.end() - first.end()
            prefix, text = text[:split], text[split:]
            text, arrays = re.subn(rf'(?m)^[ \t]*(?:u8|u16|u32)\s+{re.escape(array)}\[[^\]\n]+\];\n', '', text)
            text, pointers = re.subn(rf'\b{re.escape(typ)}\s*\*\s*{re.escape(pointer)}\s*;', f'{typ} {pointer};', text)
            text = re.sub(rf'(?m)^[ \t]*{re.escape(pointer)} = \({re.escape(typ)} \*\){re.escape(array)};\n', '', text)
            text = re.sub(rf'\b{re.escape(pointer)}->', f'{pointer}.', text)
            text = re.sub(rf'\*{re.escape(pointer)}\b', pointer, text)
            if arrays == pointers == 1:
                out.append((f'recover aggregate local with {delta}-byte false prefix', prefix + text))
    return out


def store_values(body, name, base):
    """Swap store operands only when retail shows a reciprocal value conflict.

    These are source candidates, never object patches. The compiler oracle also
    checks that evaluation order and every other use of the values are retained.
    """
    conflicts = base.value_flow
    span = _function_span(body, name)
    if not span or len(conflicts) < 2:
        return []
    stores = []
    for row in conflicts:
        t = re.fullmatch(r'(st\w+) ([rf]\d+), (.+)', row['target'])
        o = re.fullmatch(r'(st\w+) ([rf]\d+), (.+)', row['ours'])
        if t and o and t[1] == o[1] and t[3] == o[3]:
            stores.append((t[1], t[2], o[2]))
    if not any(a == d and b == f and c == e and b != c
               for a,b,c in stores for d,e,f in stores):
        return []
    assignments = []
    for m in re.finditer(r'(?m)^[ \t]*(?P<lhs>[^;\n=]+)\s*=\s*(?P<rhs>[A-Za-z_]\w*)\s*;', body[span[0]:span[1]]):
        if any(x in m['lhs'] for x in ('*', '->', '.', '[')):
            assignments.append((span[0]+m.start('rhs'), span[0]+m.end('rhs'), m['rhs']))
    out = []
    for i,(a,b,x) in enumerate(assignments):
        for c,d,y in assignments[i+1:]:
            if x != y:
                out.append((f'retail store-value swap {x}/{y}', body[:a]+y+body[b:c]+x+body[d:]))
    return out


def stack_locals(body, name, diffs):
    """Pack address-taken scalar locals whose separately allocated slots differ.

    An aggregate expresses shared frame storage and natural subword alignment;
    it does not force machine offsets or alter emitted instructions afterward.
    """
    if not any('(r1)' in t+o and t != o for t,o in diffs):
        return []
    span = _function_span(body, name)
    if not span:
        return []
    start = body.index('{', span[0])+1
    pattern = re.compile(r'(?m)^[ \t]*((?:volatile\s+)?(?:u8|s8|u16|s16|u32|s32|f32|f64|int|float|double))\s+(\w+)\s*;[ \t]*\n')
    sites = [m for m in pattern.finditer(body,start,span[1])
             if re.search(r'&\s*'+re.escape(m[2])+r'\b',body[m.end():span[1]])]
    if not 2 <= len(sites) <= 12:
        return []
    # Do not move a declaration out of a nested lexical scope.
    sites = [m for m in sites if body[start:m.start()].count('{') == body[start:m.start()].count('}')]
    if len(sites) < 2:
        return []
    widths={'u8':1,'s8':1,'u16':2,'s16':2,'u32':4,'s32':4,'f32':4,'f64':8,'int':4,'float':4,'double':8}
    orders=[sites,list(reversed(sites)),sorted(sites,key=lambda m:widths[m[1].split()[-1]]),sorted(sites,key=lambda m:-widths[m[1].split()[-1]])]
    orders += [sites[:i]+[sites[i+1],sites[i]]+sites[i+2:] for i in range(len(sites)-1)]
    var='fzgx_frame'
    while re.search(r'\b'+var+r'\b',body):
        var += '_'
    inner=body[start:span[1]-1]
    for m in reversed(sites):
        inner=inner[:m.start()-start]+inner[m.end()-start:]
    names={m[2] for m in sites}
    inner=re.sub(r'\b[A-Za-z_]\w*\b',lambda m:var+'.'+m[0] if m[0] in names else m[0],inner)
    out=[]
    for order in orders:
        fields=' '.join(m[1]+' '+m[2]+';' for m in order)
        text=body[:start]+'\n    struct { '+fields+' } '+var+';\n'+inner+body[span[1]-1:]
        out.append(('pack stack scalars '+','.join(m[2] for m in order),text))
    # Retail can reuse one address-taken slot across distinct scalar lifetimes.
    # Packing alone cannot express that overlap. Propose equal-width reuse
    # only when the object diff shows two compiler slots mapping to one retail
    # slot; the stock compiler and full oracle decide source realizability.
    slots = {}
    for target, ours in diffs:
        t = re.fullmatch(r'(\w+) [rf]\d+, (0x[0-9a-f]+)\(r1\)', target)
        o = re.fullmatch(r'(\w+) [rf]\d+, (0x[0-9a-f]+)\(r1\)', ours)
        if t and o and t[1] == o[1]:
            slots.setdefault(int(t[2], 0), set()).add(int(o[2], 0))
    if len(sites) <= 7 and any(len(v) > 1 for v in slots.values()):
        merged = []
        def qualified_reuse(keep, drop, lo, hi, remove=False):
            if not keep[1].startswith('volatile ') or drop[1].startswith('volatile '):
                return
            ty = keep[1].removeprefix('volatile ')
            edits = [(keep.start(1), keep.end(1), ty)]
            for token in re.finditer(r'(?<![.\w])(?<!->)'+re.escape(keep[2])+r'\b', body[keep.end():span[1]]):
                a = keep.end()+token.start()
                edits.append((a,a+len(keep[2]),'(*(volatile '+ty+' *)&'+keep[2]+') /* Keep this staged access volatile. */'))
            for token in re.finditer(r'(?<![.\w])(?<!->)'+re.escape(drop[2])+r'\b', body[lo:hi]):
                a = lo+token.start()
                edits.append((a,a+len(drop[2]),keep[2]))
            if remove:
                edits.append((drop.start(),drop.end(),''))
            text = body
            for a,b,value in sorted(edits,reverse=True):
                text = text[:a]+value+text[b:]
            merged.append(('pack stack qualified lifetime '+drop[2]+' as '+keep[2]+f' at {lo}', text))
        for keep, drop in itertools.permutations(sites, 2):
            if widths[keep[1].split()[-1]] != widths[drop[1].split()[-1]]:
                continue
            text = body[:drop.start()] + body[drop.end():]
            fn = _function_span(text, name)
            inner_text = text[fn[0]:fn[1]]
            if keep[1] != drop[1]:
                inner_text = re.sub(r'&\s*'+re.escape(drop[2])+r'\b',
                                    '('+drop[1]+' *)&'+keep[2], inner_text)
            inner_text = re.sub(r'(?<![.\w])(?<!->)'+re.escape(drop[2])+r'\b', keep[2], inner_text)
            merged.append(('pack stack reuse '+drop[2]+' as '+keep[2], text[:fn[0]]+inner_text+text[fn[1]:]))
            qualified_reuse(keep,drop,drop.end(),span[1],True)
            # A temporary may occupy different retail slots in distinct live
            # ranges. Retain its declaration and redirect one assignment/use
            # interval instead of forcing every occurrence into the same slot.
            assigns = list(re.finditer(r'(?m)^\s*'+re.escape(drop[2])+r'\s*=(?!=)', body[drop.end():span[1]]))
            for j, assignment in enumerate(assigns):
                lo = drop.end() + assignment.start()
                hi = drop.end() + assigns[j+1].start() if j+1 < len(assigns) else span[1]
                segment = body[lo:hi]
                if not re.search(r'&\s*'+re.escape(drop[2])+r'\b', segment):
                    continue
                if keep[1] != drop[1]:
                    segment = re.sub(r'&\s*'+re.escape(drop[2])+r'\b', '('+drop[1]+' *)&'+keep[2], segment)
                segment = re.sub(r'(?<![.\w])(?<!->)'+re.escape(drop[2])+r'\b', keep[2], segment)
                merged.append(('pack stack lifetime '+drop[2]+' as '+keep[2]+f' at {lo}', body[:lo]+segment+body[hi:]))
                qualified_reuse(keep,drop,lo,hi)
        out = merged + out
    return list(dict.fromkeys(out))


def stack_field_origins(body, diffs):
    """Move false leading padding to the tail, retaining the aggregate extent."""
    deltas=set()
    for t,o in diffs:
        tm=re.fullmatch(r'(\w+ [rf]\d+, )(-?0x[0-9a-f]+)\(r1\)',t)
        om=re.fullmatch(r'(\w+ [rf]\d+, )(-?0x[0-9a-f]+)\(r1\)',o)
        if tm and om and tm[1]==om[1] and tm[2]!=om[2]:
            deltas.add(int(tm[2],0)-int(om[2],0))
    out=[]
    for m in re.finditer(r'\bstruct\s+(\w+)\s*\{(?P<fields>[^{}]+)\}',body):
        prefix=re.match(r'\s*u8\s+(\w+)\[(0x[0-9a-fA-F]+|\d+)\];',m['fields'])
        if not prefix or re.search(r'(?:\.|->)\s*'+re.escape(prefix[1])+r'\b',body):
            continue
        size=int(prefix[2],0)
        for delta in sorted(deltas):
            if not -size<=delta<0:
                continue
            remaining=size+delta
            first=f'\n    u8 {prefix[1]}[{remaining}];' if remaining else ''
            fields=first+m['fields'][prefix.end():]+f'\n    u8 fzgx_tail_padding[{-delta}];\n'
            out.append((f'recover aggregate field origin {m[1]} {delta}',body[:m.start('fields')]+fields+body[m.end('fields'):]))
    return out


def member_layouts(body, diffs):
    """Recover internal gaps from emitted member offsets, not identifier spelling."""
    pairs = set()
    for target, ours in diffs:
        t = re.fullmatch(r'(\w+) [rf]\d+, (-?0x[0-9a-f]+)\(r\d+\)', target)
        o = re.fullmatch(r'(\w+) [rf]\d+, (-?0x[0-9a-f]+)\(r\d+\)', ours)
        if t and o and t[1] == o[1] and t[2] != o[2] and '(r1)' not in target + ours:
            pairs.add((int(o[2], 0), int(t[2], 0)))
        t = re.fullmatch(r'addi r\d+, r(?!1\b)\d+, (0x[0-9a-f]+)', target)
        o = re.fullmatch(r'addi r\d+, r(?!1\b)\d+, (0x[0-9a-f]+)', ours)
        if t and o and t[1] != o[1]:
            pairs.add((int(o[1], 0), int(t[1], 0)))
    if not pairs:
        return []
    sizes = {'u8': 1, 's8': 1, 'char': 1, 'u16': 2, 's16': 2, 'short': 2,
             'u32': 4, 's32': 4, 'int': 4, 'f32': 4, 'float': 4, 'f64': 8, 'double': 8}
    from .sdkimport import masked
    code = masked(body)
    out = []
    for sm in re.finditer(r'\bstruct\s*\w*\s*\{([^{}]*)\}', code):
        fields, cursor, valid = [], 0, True
        for part in re.finditer(r'([^;]+);', sm[1]):
            field = re.fullmatch(r'\s*(?:const\s+|volatile\s+)*(\w+)\s*(\*)?\s+(\w+)\s*(?:\[\s*(0x[\da-fA-F]+|\d+)\s*\])?\s*;', part[0])
            # Also accept the common `u8 *cur` declarator spelling.
            if not field:
                field = re.fullmatch(r'\s*(?:const\s+|volatile\s+)*(\w+)\s+(\*)?\s*(\w+)\s*(?:\[\s*(0x[\da-fA-F]+|\d+)\s*\])?\s*;', part[0])
            if not field or (not field[2] and field[1] not in sizes):
                valid = False
                break
            width = 4 if field[2] else sizes[field[1]]
            cursor = (cursor + width - 1) // width * width
            start = sm.start(1) + part.start()
            fields.append((field, cursor, start, sm.start(1) + part.end()))
            cursor += width * (int(field[4], 0) if field[4] else 1)
        if not valid:
            continue
        # A wrong argument/member selection is not a missing layout gap. Try
        # the existing, identically typed member before moving any declarations.
        # Apply cycles simultaneously (A->B, B->C, C->A), retaining shared types.
        by_offset = {offset: field for field,offset,_,_ in fields}
        replacements = {}
        for old,new in sorted(pairs):
            before,after = by_offset.get(old),by_offset.get(new)
            if before is None or after is None or (before[1],before[2],before[4]) != (after[1],after[2],after[4]):
                continue
            replacements.setdefault(before[3],set()).add(after[3])
        accesses = []
        for member, choices in replacements.items():
            if len(choices)!=1:
                continue
            replacement = next(iter(choices))
            sites = list(re.finditer(r'(?:\.|->)\s*('+re.escape(member)+r')\b',code))
            text = body
            for site in reversed(sites):
                a,b = site.span(1)
                accesses.append((a,b,replacement))
                text = text[:a]+replacement+text[b:]
            if text != body:
                out.append((f'recover member accesses {member}->{replacement}',text))
        if accesses:
            text = body
            for a,b,replacement in sorted(accesses,reverse=True):
                text = text[:a]+replacement+text[b:]
            out.insert(0,('recover member accesses together',text))
        edits = {}
        for i, (field, offset, start, end) in enumerate(fields):
            if not re.search(r'(?:\.|->)\s*' + re.escape(field[3]) + r'\b', code):
                continue
            for old, new in sorted(pairs):
                if old != offset or new < 0:
                    continue
                delta = new - old
                if i:
                    pad, _, ps, pe = fields[i - 1]
                    if (pad[1] == 'u8' and pad[4] and not pad[2]
                            and not re.search(r'(?:\.|->)\s*' + re.escape(pad[3]) + r'\b', code)):
                        length = int(pad[4], 0) + delta
                        if length >= 0:
                            a, b = ps + pad.start(4), ps + pad.end(4)
                            edit = (a, b, f'0x{length:X}') if length else (ps, pe, '')
                            edits.setdefault(edit[:2], set()).add(edit[2])
                            out.append((f'recover member gap {field[3]} {old:#x}->{new:#x}',
                                        body[:edit[0]] + edit[2] + body[edit[1]:]))
                if delta > 0:
                    text = f'\n    u8 fzgx_pad_before_{field[3]}[0x{delta:X}];'
                    out.append((f'recover member gap before {field[3]} {old:#x}->{new:#x}',
                                body[:start] + text + body[start:]))
        combined = body
        for (a, b), choices in sorted(edits.items(), reverse=True):
            if len(choices) == 1:
                combined = combined[:a] + next(iter(choices)) + combined[b:]
        if combined != body:
            out.insert(0, ('recover member gaps together', combined))
    return list(dict.fromkeys(out))


def interior_references(p, module, body, diffs):
    """Explicit symbolic subobject/entry declarations, proven by the pool oracle."""
    out=[]
    for target,ours in diffs:
        t=re.fullmatch(r'(\w+ .+?, )([A-Za-z_]\w*)\+(0x[0-9a-f]+)@(\w+)',target)
        o=re.fullmatch(r'(\w+ .+?, )([A-Za-z_]\w*)@(\w+)',ours)
        if t and o and t[1]==o[1] and t[4]==o[3]:
            owner=p.find_symbol(t[2],module) or p.resolve(t[2])
            delta=int(t[3],0)
            if owner is None or not 0<delta<owner.size:
                continue
            declaration=re.search(r'(?m)^extern\s+(u32|s32|u16|s16|u8|s8|f32|f64)\s+'+re.escape(o[2])+r'\s*;',body)
            if not declaration or delta+int(declaration[1][1:])//8>owner.size:
                continue
            alias=f'{owner.name}__fzgx_offset_{delta:X}'
            text=re.sub(r'\b'+re.escape(o[2])+r'\b',alias,body)
            out.append((f'interior data {o[2]} -> {owner.name}+{delta}',text))
        t=re.fullmatch(r'bl ([A-Za-z_]\w*)\+(0x[0-9a-f]+)',target)
        if t and ours=='bl '+t[1]:
            owner=p.find_symbol(t[1],module) or p.resolve(t[1])
            delta=int(t[2],0)
            if not owner or not 0<delta<owner.size or delta%4:
                continue
            decl=re.search(r'(?m)^extern\s+([\w *]+?)\s+'+re.escape(t[1])+r'\s*\(([^;{}]*)\);',body)
            alias=f'{owner.name}__fzgx_offset_{delta:X}'
            # An implicit declaration retains C's default argument promotions.
            prototype=f'extern {decl[1] if decl else "int"} {alias}({decl[2] if decl else ""});\n'
            uses=list(re.finditer(r'\b'+re.escape(t[1])+r'(?=\s*\()',body[decl.end() if decl else 0:]))
            start=decl.end() if decl else 0
            for use in uses:
                a,b=start+use.start(),start+use.end()
                text=body[:a]+alias+body[b:]
                pos=decl.end() if decl else (max((m.end() for m in re.finditer(r'^#include[^\n]*\n',body,re.M)),default=0))
                out.append((f'interior call {owner.name}+{delta}',text[:pos]+'\n'+prototype+text[pos:]))
    return list(dict.fromkeys(out))


def hardware_lvalues(body):
    """Use the shared hardware map for fixed-address scratch lvalues."""
    number=r'0[xX][0-9a-fA-F]+'
    pattern=re.compile(r'\(\s*((?:volatile\s+)?(?:f32|f64|u8|u16|u32|s8|s16|s32))\s*\*\s*\)\s*('+number+r'|\(\s*'+number+r'\s*\+\s*'+number+r'\s*\))')
    from .project import ROOT
    header=ROOT/'include/dolphin/hw_regs.h'
    bases=sorted(((int(addr,16),name) for name,addr in re.findall(
        r'^#define (\w+_BASE) (0x[0-9A-Fa-f]+)[uU]?$',header.read_text(),re.M)),reverse=True)
    edits=[]
    hardware_variables=set()
    for m in pattern.finditer(body):
        address=sum(int(n,16) for n in re.findall(number,m[2]))
        owner=next(((addr,name) for addr,name in bases if 0<=address-addr<0x1000),None)
        if owner:
            addr,name=owner
            edits.append((m.start(2),m.end(2),f'({name} + 0x{address-addr:X})'))
    for m in re.finditer(r'\b(\w+)\s*=\s*('+number+r')[uUlL]*(?=\s*;)',body):
        address=int(m[2],16)
        owner=next((name for addr,name in bases if addr==address),None)
        if owner and re.search(r'\([^();]+\*\)\s*'+re.escape(m[1])+r'\b',body[m.end():]):
            edits.append((m.start(2),m.end(2),owner))
            hardware_variables.add(m[1])
    edits=sorted(set(edits))
    if not edits:
        return []
    text=body
    for a,b,replacement in reversed(edits):
        text=text[:a]+replacement+text[b:]
    names=hardware_variables | {name for _,name in bases}
    fifo_macros = {m[1] for m in re.finditer(r'^#define\s+(\w+)\([^\n]+GX_FIFO_BASE[^\n]*', text, re.M)}
    fifo_inputs = {m[1] for macro in fifo_macros for m in re.finditer(r'\b'+re.escape(macro)+r'\((\w+)\)', text)}
    text = re.sub(r'(?m)^extern volatile const (f32|f64) (\w+);$',
                  lambda m: m[0] + (' /* Reload before each ordered FIFO write. */' if m[2] in fifo_inputs else ''), text)
    text='\n'.join(line+' /* Hardware access must remain ordered. */'
                   if 'volatile' in line and not any(c in line for c in ('//','/*'))
                   and any(re.search(r'\b'+re.escape(name)+r'\b',line) for name in names)
                   else line for line in text.split('\n'))
    if '#include "dolphin/hw_regs.h"' not in text:
        text='#include "dolphin/hw_regs.h"\n'+text
    return [('bind hardware lvalues',text)]


def reload_lvalues(body, name, diffs, missing_globals=()):
    """Shorten a cached load's lifetime where retail explicitly loads again."""
    from .fixup_source import declared_types, member_type, record_layouts, member_layout, declarator, DECL_RE
    from .sdkimport import masked
    code = masked(body)
    span = _function_span(code,name)
    if not span:
        return []
    fields, variables = declared_types(code, span[0])
    layouts = record_layouts(code, span[0], variables)
    offsets = {}
    for target, ours in diffs:
        m = re.fullmatch(r'(lwz|lhz|lha|lbz|lfs|lfd) [rf]\d+, (0x[\da-f]+)\(r(?:[2-9]|[12]\d|3[01])\)',target)
        if m and not ours:
            offsets.setdefault(int(m[2],0), set()).add(m[1])
    out, pointers = [], {}
    # Earlier repairs may have forced a read which is now redundant. Permit
    # the compiler to cache it again only for a tool-annotated cast over an
    # otherwise nonvolatile, type-identical field implicated by the diff.
    changed_offsets={int(m[1],0) for _,ours in diffs
                     if (m:=re.fullmatch(r'(?:lwz|lhz|lha|lbz|lfs|lfd) [rf]\d+, (0x[\da-f]+)\(r(?:[2-9]|[12]\d|3[01])\)',ours))}
    reloads={}
    pattern=r'\(\s*\*\s*\(\s*([\w *]+?)\s+volatile\s*\*\s*\)\s*&\s*\((\w+(?:(?:->|\.)\w+)+)\)\s*\)'
    for match in re.finditer(pattern,code[span[0]:span[1]]):
        a,b=span[0]+match.start(),span[0]+match.end();ty,expression=match.groups()
        annotation=re.match(r'(\s*;)?\s*/\* Retail reloads (?:this field|the pointer between statements)\. \*/',body[b:])
        actual=member_type(expression,fields,variables);layout=member_layout(expression,layouts,variables)
        if (not annotation or not layout or layout[1] not in changed_offsets or 'volatile' in actual
                or re.sub(r'\s+','',actual)!=re.sub(r'\s+','',ty)):continue
        reloads.setdefault(expression,[]).append((a,b+annotation.end(),'('+expression+')'+(annotation[1] or '')))
    for expression,sites in reloads.items():
        for positions in [sites]+([[s] for s in sites] if len(sites)>1 else []):
            text=body
            for a,b,value in reversed(positions):text=text[:a]+value+text[b:]
            out.append(('lifetime reload cached '+expression+' at '+('every site' if positions is sites else str(positions[0][0])),text))
    for offset in sorted(offsets,key=lambda n:(n==0,n)):
        field = re.compile(r'\b(unk_?0*'+format(offset,'x')+r')\b',re.I)
        expressions = list(re.finditer(r'\b\w+(?:(?:->|\.)\w+)+',code[span[0]:span[1]]))
        names = {re.split(r'->|\.',m[0])[-1] for m in expressions}
        for member in sorted(names):
            matches = [m for m in expressions if re.split(r'->|\.',m[0])[-1]==member]
            groups = {}
            for match in matches:
                a,b = span[0]+match.start(),span[0]+match.end()
                layout=member_layout(match[0],layouts,variables)
                if (layout and (layout[1]!=offset or layout[3] is not None)) or (not layout and not field.fullmatch(member)):
                    continue
                if not layout and re.search(r'\b'+re.escape(member)+r'\s*\[',code[:span[0]]):
                    continue
                if re.match(r'\s*(?:=(?!=)|[+*/&|^-]=|\+\+|--)',code[b:]) or code[max(0,a-1):a]=='&':
                    continue
                groups.setdefault(match[0],[]).append((a,b))
            for expression, sites in groups.items():
                ty = member_type(expression, fields, variables)
                if not ty or 'volatile' in ty:
                    continue
                op = 'lwz' if '*' in ty else {'u8':'lbz','s8':'lbz','u16':'lhz','s16':'lha',
                     'u32':'lwz','s32':'lwz','int':'lwz','f32':'lfs','f64':'lfd'}.get(ty.strip())
                if op not in offsets[offset]:
                    continue
                if '*' in ty:
                    pointers.setdefault(offset,set()).add((expression,ty))
                # Qualify the loaded object, including a pointer itself, rather
                # than its pointee; otherwise MWCC can still reuse the pointer.
                replacement = '(*('+declarator(ty, 'volatile *')+')&('+expression+')) /* Retail reloads this field. */'
                for positions in [sites]+[[site] for site in sites]:
                    text = body
                    for a,b in reversed(positions):
                        text = text[:a]+replacement+text[b:]
                    out.append((f'lifetime reload {expression} at '+('every site' if positions is sites else str(positions[0][0])),text))
    # A saved draft can hide the missing read behind a block-local pointer.
    # Refresh that alias at complete statements, retaining one pointer value
    # for multiple fields in the same expression and respecting shadowing.
    scopes, stack = [], []
    for token in re.finditer(r'[{}]',code[span[0]:span[1]]):
        at=span[0]+token.start()
        if token[0]=='{':
            stack.append(at)
        elif stack:
            scopes.append((stack.pop(),at))
    declarations=[]
    for line in re.finditer(r'(?m)^[ \t]*[^\n;{}]+;[ \t]*$',code[span[0]:span[1]]):
        declaration=DECL_RE.fullmatch(line[0])
        if declaration:
            declarations.append((span[0]+line.start(),span[0]+line.end(),declaration))
    for start,end,decl in declarations:
        ty,alias,_,initial=decl.groups()
        if '*' not in ty or not initial:
            continue
        expression=initial.strip()
        if not any((expression,ty.strip()) in {(e,t.strip()) for e,t in values} for values in pointers.values()):
            continue
        scope=min((s for s in scopes if s[0]<start<s[1]),key=lambda s:s[1]-s[0],default=None)
        if scope is None:
            continue
        shadows=[min((s for s in scopes if s[0]<a<s[1]),key=lambda s:s[1]-s[0])
                 for a,b,d in declarations if end<a<scope[1] and d[2]==alias]
        uses=[m for m in re.finditer(r'\b'+re.escape(alias)+r'\b',code[end:scope[1]])
              if not any(a<=end+m.start()<b for a,b in shadows)]
        if not uses or any(not re.match(r'\s*->',code[end+m.end():]) for m in uses):
            continue
        edits=[(end+m.start(),end+m.end(),expression) for m in uses]
        text=body
        for a,b,value in reversed(edits):
            text=text[:a]+value+text[b:]
        out.insert(0,(f'lifetime reload alias {alias} from {expression} at {start}',text[:start]+text[end:]))
        grouped={}
        for use in uses:
            a=end+use.start();line=code.rfind('\n',end,a)+1
            grouped.setdefault(line,[]).append(use)
        changes=[];after_stores=[]
        for line,positions in grouped.items():
            stop=code.find('\n',end+positions[-1].end())
            statement=code[line:stop]
            if DECL_RE.fullmatch(statement) or not statement.rstrip().endswith(';') or any(x in statement for x in ('&&','||','?','if ','if(','while','for ')):
                continue
            indent=re.match(r'[ \t]*',body[line:])[0]
            change=(line,line,indent+alias+' = (*('+ty+' volatile *)&('+expression+')); /* Retail reloads the pointer between statements. */\n')
            changes.append(change)
            previous=re.search(r'([^;{}]+);\s*\Z',code[:line])
            if previous and re.search(r'(?:->|\.|\[|\*)[^=]*=(?!=)',previous[1]):
                after_stores.append(change)
        if changes:
            text=body
            for a,b,value in reversed(changes):
                text=text[:a]+value+text[b:]
            out.insert(0,(f'lifetime reload alias {alias} between statements at {start}',text))
        if after_stores and after_stores!=changes:
            text=body
            for a,b,value in reversed(after_stores):
                text=text[:a]+value+text[b:]
            out.insert(0,(f'lifetime reload alias {alias} after stores at {start}',text))
    for expression in sorted(set(missing_globals)):
        ty = variables.get(expression,'')
        if not ty or 'volatile' in ty or re.search(r'\b'+re.escape(expression)+r'\s*\[',code[:span[0]]):
            continue
        uses = [(span[0]+m.start(),span[0]+m.end()) for m in re.finditer(r'\b'+re.escape(expression)+r'\b',code[span[0]:span[1]])]
        sites = [(a,b) for a,b in uses if not code[:a].rstrip().endswith('&') and
                 not re.match(r'\s*(?:=(?!=)|[+*/&|^-]=|\+\+|--|\[|\.)',code[b:])]
        for positions in ([sites]+[[site] for site in sites] if sites else []):
            text = body
            for a,b in reversed(positions):
                text = text[:a]+f'(*({ty} volatile *)&{expression}) /* Retail reloads this object. */'+text[b:]
            out.insert(0,(f'lifetime reload {expression} at '+('every site' if positions is sites else str(positions[0][0])),text))
    # Preserve the ordering dependency between an observed store and a call's
    # pointer reload. Qualifying only the read still lets a nonvolatile store
    # move past it; source-level ordering needs both accesses.
    from .fixup_source import call_sites
    stores, prior = {}, []
    for index,(target, ours) in enumerate(diffs):
        load = re.fullmatch(r'lwz r\d+, (0x[\da-f]+)\(r(?:[2-9]|[12]\d|3[01])\)',target)
        if load and not ours and int(load[1],0) in pointers:
            following = [text for text,_ in diffs[index+1:index+6] if text]
            callee = next((m[1] for text in following if (m := re.fullmatch(r'bl (\w+)',text))),None)
            for before in reversed(prior[-3:]):
                store = re.fullmatch(r'stw r\d+, (0x[\da-f]+)\(r(?:[2-9]|[12]\d|3[01])\)',before)
                if store and callee:
                    stores.setdefault((int(store[1],0),callee),set()).update(pointers[int(load[1],0)])
                    break
                if before.startswith('b'):
                    break
        if target:
            prior.append(target)
    for (offset,callee),loads in sorted(stores.items()):
        for expression,ty in sorted(loads):
            groups = []
            for called,start,end,args in call_sites(code):
                if called != callee or not args or not span[0]<=start<end<=span[1]:
                    continue
                uses = list(re.finditer(r'\b'+re.escape(expression)+r'\b',code[args[0][0]:args[-1][1]]))
                previous = re.search(r'(?m)^[ \t]*(\w+(?:(?:->|\.)\w+)*(?:->|\.)unk_?0*'+format(offset,'x')+r')\s*=[^;\n]+;\s*\Z',code[:start],re.I)
                store_type = member_type(previous[1],fields,variables) if previous else ''
                if not uses or not store_type or 'volatile' in store_type:
                    continue
                edits = [(previous.start(1),previous.end(1),f'(*({store_type} volatile *)&({previous[1]})) /* Retail stores before the call reload. */')]
                edits += [(args[0][0]+use.start(),args[0][0]+use.end(),f'(*({ty} volatile *)&({expression})) /* Retail reloads after the store. */') for use in uses]
                groups.append(edits)
            for edits in ([sum(groups,[])]+groups if groups else []):
                text = body
                for a,b,value in sorted(edits,reverse=True):
                    text = text[:a]+value+text[b:]
                out.insert(0,(f'lifetime ordered reload {expression} after store 0x{offset:X} before {callee} at '+('every site' if len(edits)>2 else str(edits[0][0])),text))
    return out



def relocation_bindings(body, base):
    lrows, rrows = base._rows
    diffs = [(stuck._fmt(a), stuck._fmt(b)) for a, b in zip(lrows, rrows)
             if (a.get("diff_kind") or "DIFF_NONE") != "DIFF_NONE"]
    candidates = []
    from .sdkimport import masked
    # SDK fixed buffers use the same address definition as the linker. Keep
    # constant folding while replacing anonymous addresses in recovered C.
    constants={}
    for name,address in oracle.abs_symbols().items():
        constants.setdefault(address,name)
    edits=[]
    for token in re.finditer(r'\b0[xX][\da-fA-F]+[uUlL]*\b',masked(body)):
        address=int(token[0].rstrip('uUlL'),16)
        if address in constants:
            edits.append((token.start(),token.end(),'FZGX_ADDR_'+constants[address]))
    if edits:
        text=body
        for a,b,value in reversed(edits):text=text[:a]+value+text[b:]
        if not re.search(r'#include\s*[<"]sdk_addresses.h[>"]',text):
            text='#include "sdk_addresses.h"\n'+text
        candidates.append(('bind SDK fixed addresses',text))
    # wrong callee / wrong data symbol: the same instruction with a different relocation target.
    # The retail name is known; the body names ours verbatim, so the substitution is exact.
    subs: Dict[str, str] = {}
    for t, o in diffs:
        if not t or not o or t.split()[0] != o.split()[0]:
            continue
        mt = re.findall(r"\b([A-Za-z_]\w*)(?=@|$|\b)", re.sub(r"^\S+\s+", "", t))
        mo = re.findall(r"\b([A-Za-z_]\w*)(?=@|$|\b)", re.sub(r"^\S+\s+", "", o))
        tn = [x for x in mt if not re.fullmatch(r"[rf]\d+|cr\d|lt|gt|eq|so|ha|l|sda21", x)]
        on = [x for x in mo if not re.fullmatch(r"[rf]\d+|cr\d|lt|gt|eq|so|ha|l|sda21", x)]
        if len(tn) == 1 and len(on) == 1 and tn[0] != on[0] and not on[0].startswith("@"):
            if re.sub(r"\b" + re.escape(on[0]) + r"\b", tn[0], o) == t:
                subs.setdefault(on[0], tn[0])
    # a hardware register block under an invented name: retail's `lis rX, 0xcc00` / `addi rX, rX,
    # 0xNNNN` literal pair against ours `SYM@ha` / `SYM@l` names the address; the link script's
    # canonical symbol for it (config/<v>/ldscript.tpl) is what the oracle accepts
    abs_by_addr: Dict[int, str] = {}
    for name_, addr_ in oracle.abs_symbols().items():
        abs_by_addr.setdefault(addr_, name_)
    for (t1, o1), (t2, o2) in zip(diffs, diffs[1:]):
        m1 = re.match(r"lis r\d+, (0x[0-9a-f]+)$", t1 or ""); n1 = re.match(r"lis r\d+, (\w+)@ha$", o1 or "")
        m2 = re.match(r"(addi|ori) r\d+, r\d+, (-?0x[0-9a-f]+|-?\d+)$", t2 or ""); n2 = re.match(r"(?:addi|ori) r\d+, r\d+, (\w+)@l$", o2 or "")
        if not (m1 and n1 and m2 and n2 and n1.group(1) == n2.group(1)):
            continue
        hi, lo = int(m1.group(1), 16), int(m2.group(2), 0)
        addr = ((hi << 16) + lo) & 0xFFFFFFFF if m2.group(1) == "addi" else (hi << 16) | lo
        canon = abs_by_addr.get(addr)
        if canon and canon != n1.group(1):
            subs.setdefault(n1.group(1), canon)
    for ours, retail in subs.items():
        if re.search(rf"\b{re.escape(ours)}\b", body) and not re.search(rf"\b{re.escape(retail)}\b", body):
            candidates.append((f"symbol {ours} -> {retail}", re.sub(rf"\b{re.escape(ours)}\b", retail, body)))
    if len(subs) > 1:
        text = body
        for ours, retail in subs.items():
            text = re.sub(rf"\b{re.escape(ours)}\b", retail, text)
        candidates.append(("all symbol substitutions", text))
    return sorted(candidates, key=lambda c: c[0] != 'all symbol substitutions')


def candidates(p: Project, symbol: str, body: str, base: oracle.CheckResult):
    sym = p.resolve(symbol)
    counts = _kinds(base)
    lrows, rrows = base._rows
    diffs = [(stuck._fmt(a), stuck._fmt(b)) for a, b in zip(lrows, rrows) if (a.get("diff_kind") or "DIFF_NONE") != "DIFF_NONE"]
    span = _function_span(body, sym.name)
    candidates: List[Tuple[str, str]] = store_values(body, sym.name, base)
    candidates += parameter_copies(p, symbol, body, base)
    candidates += bitmask_arguments(p,symbol,body)
    candidates += format_arguments(p,symbol,body)
    candidates += call_arguments(p,symbol,body,base)
    candidates += float_conditions(body,sym.name,diffs)
    candidates += zero_conditions(body,sym.name,diffs)
    missing_globals = []
    if any(not ours and re.fullmatch(r'(?:lwz|lhz|lha|lbz|lfs|lfd) [rf]\d+, 0x0\(r\d+\)',target) for target,ours in diffs):
        from .evidence import memory_loads, object_jump_tables
        loads = memory_loads(lrows,object_jump_tables(p.target_object_for(sym),sym.name,p,sym.module))
        missing_globals = [load['symbol'] for i,load in loads.items()
                           if not load['offset'] and not stuck._fmt(rrows[i])]
    candidates += reload_lvalues(body, sym.name, [(stuck._fmt(a),stuck._fmt(b)) for a,b in zip(lrows,rrows)], missing_globals)
    candidates += stack_locals(body, sym.name, [(stuck._fmt(a), stuck._fmt(b)) for a,b in zip(lrows,rrows)])
    candidates += stack_field_origins(body, diffs)
    candidates += member_layouts(body, diffs)
    candidates += interior_references(p, sym.module, body, diffs)
    candidates += hardware_lvalues(body)
    candidates += string_literals(p, sym.module, body, base)
    # These candidates are derived from retail bytes. Large functions can
    # exhaust the candidate budget on type permutations before reaching them.
    literals = float_literals(p, symbol, body, base)
    candidates += literals
    candidates += native_pool_literals(p, symbol, body, base)
    candidates += optimizer_pragmas(body, sym.name)
    if span and _wants_type_flip(counts, diffs):
        sites = _decl_sites(body, span)
        for s, e, typ, name in sites:
            alts = [FLIP[typ]] if typ in FLIP else []
            if counts.get("ins:ext") or "@" in " ".join(t + o for t, o in diffs):
                alts += WIDEN.get(typ, [])
            for alt in alts:
                candidates.append((f"{name}:{typ}->{alt}", body[:s] + alt + body[e:]))
    # declaration variants: when a symbol this body declares is declared differently by another
    # block of the same TU (a contested prototype or extern type), each sibling variant is a
    # candidate: a matched neighbour usually already found the spelling the compiler wants
    tu_src = None
    try:
        rec = p.unit_record(p.unit_of(sym)) if p.unit_of(sym) else None
        tu_src = rec.get("tu") if rec else None
        if tu_src is None:
            tu_src = next((t for t in [_tu_of(p, sym)] if t), None)
    except Exception:
        tu_src = None
    if tu_src:
        from . import tufile, tutidy
        try:
            tf = tufile.load(p, tu_src)
        except Exception:
            tf = None
        if tf is not None:
            mine = {}
            for ln in body.splitlines():
                if tutidy.DECL_LINE_RE.match(ln):
                    n = tutidy._decl_name(ln)
                    if n:
                        mine.setdefault(n, ln.strip())
            variants: Dict[str, List[str]] = {}
            for b in tf.blocks:
                if b.name == sym.name:
                    continue
                for ln in b.body.splitlines():
                    if tutidy.DECL_LINE_RE.match(ln):
                        n = tutidy._decl_name(ln)
                        if n in mine and ln.strip() != mine[n] and ln.strip() not in variants.setdefault(n, []):
                            variants[n].append(ln.strip())
            for ln in tf.prologue.splitlines():
                if tutidy.DECL_LINE_RE.match(ln):
                    n = tutidy._decl_name(ln)
                    if n in mine and ln.strip() != mine[n] and ln.strip() not in variants.setdefault(n, []):
                        variants[n].append(ln.strip())
            for n, alts in variants.items():
                for alt in alts[:4]:
                    candidates.append((f"{n}: {mine[n]} -> {alt}", body.replace(mine[n], alt, 1)))
    candidates += literals[3:]
    # float vs double: fsubs/fsub, frsp rows come from f32/f64 declarations and literal suffixes.
    # Pool primers hold measured retail bytes: a suffix or type flip there changes the pool
    # (a double primed as `0.49f` loses its low bits), so these rewrites skip them.
    if any((t.split()[0] if t else "") in FLOAT_PAIRS or (o.split()[0] if o else "") in FLOAT_PAIRS or "frsp" in (t + o) for t, o in diffs):
        from .sdkimport import masked
        primer_ranges = _layout_primer_ranges(body, masked(body))
        def outside(pattern):
            return [m for m in re.finditer(pattern, body) if not any(a <= m.start() < b for a, b in primer_ranges)]
        def substitute(matches, repl):
            text = body
            for m in reversed(matches):
                text = text[:m.start()] + m.expand(repl) + text[m.end():]
            return text
        for a, b in (("f64", "f32"), ("f32", "f64"), ("double", "float"), ("float", "double")):
            sites = outside(rf"\b{a}\b")
            if sites:
                candidates.append((f"all {a}->{b}", substitute(sites, b)))
                for m in sites[:12]:
                    candidates.append((f"{a}->{b} at {m.start()}", body[:m.start()] + b + body[m.end():]))
        lits = outside(r"(?<![\w.])(\d+\.\d*(?:[eE][-+]?\d+)?)(?![\w.f])")
        if lits:
            candidates.append(("float literals get f", substitute(lits, r"\1f")))
        litf = outside(r"(?<![\w.])(\d+\.\d*(?:[eE][-+]?\d+)?)f\b")
        if litf:
            candidates.append(("float literals lose f", substitute(litf, r"\1")))
    # unused leading parameters: retail keeps r3..r5 alive (they were parameters) and uses r6 for a
    # temporary where we used r3; adding parameters the body ignores reproduces that
    if span:
        regs_t = set(re.findall(r"\br(\d+)\b", " ".join(t for t, o in diffs))); regs_o = set(re.findall(r"\br(\d+)\b", " ".join(o for t, o in diffs)))
        hi_t = [int(x) for x in regs_t if 3 <= int(x) <= 10]; lo_o = [int(x) for x in regs_o if 3 <= int(x) <= 10]
        m = re.search(rf"\b{re.escape(sym.name)}\s*\(([^)]*)\)\s*\{{", body)
        if m and hi_t and lo_o and max(hi_t) > max(lo_o):
            cur = m.group(1).strip()
            n_cur = 0 if cur in ("", "void") else cur.count(",") + 1
            for extra in range(1, 4):
                pads = ", ".join(f"u32 unused{n_cur + i}" for i in range(extra))
                newp = pads if cur in ("", "void") else cur + ", " + pads
                candidates.append((f"+{extra} unused parameter(s)", body[:m.start(1)] + newp + body[m.end(1):]))
    candidates += stack_aggregates(body, diffs)
    # target-driven immediates: a row where only an immediate differs names ours and retail's
    # value; the C literal that produced ours (as decimal, hex, or a struct stride) is replaced
    imm_pairs = []
    for t, o in diffs:
        if not t or not o or t.split()[0] != o.split()[0]:
            continue
        ti = re.findall(r"(?<![\w(])(-?0x[0-9a-f]+|-?\d+)(?![\w(])", t); oi = re.findall(r"(?<![\w(])(-?0x[0-9a-f]+|-?\d+)(?![\w(])", o)
        if len(ti) == len(oi) and re.sub(r"\b[rf]\d+\b", "R", re.sub(r"(-?0x[0-9a-f]+|-?\d+)", "#", t)) == re.sub(r"\b[rf]\d+\b", "R", re.sub(r"(-?0x[0-9a-f]+|-?\d+)", "#", o)):
            for a, b in zip(ti, oi):
                if a != b:
                    imm_pairs.append((int(b, 0), int(a, 0), t.split()[0]))
    seen_imm = set()
    for ours_v, retail_v, mn in imm_pairs:
        if (ours_v, retail_v) in seen_imm:
            continue
        seen_imm.add((ours_v, retail_v))
        forms = {str(ours_v), f"0x{ours_v:X}", f"0x{ours_v:x}"}
        if ours_v < 0:
            forms |= {str(ours_v & 0xFFFF), f"0x{ours_v & 0xFFFF:X}"}
        for form in forms:
            for m in list(re.finditer(rf"(?<![\w.]){re.escape(form)}(?![\w.])", body))[:6]:
                rep = f"0x{retail_v:X}" if form.startswith("0x") else str(retail_v)
                candidates.append((f"imm {form} -> {rep} ({mn})", body[:m.start()] + rep + body[m.end():]))
        if mn.rstrip(".") in ("lis", "addis", "subis", "oris", "xoris", "andis"):
            # a high-half immediate: the C literal is a 32-bit constant whose upper half (with the
            # low half's sign carried for addis/subis) is ours; retail's literal differs by the
            # delta in the upper half, e.g. `== 0x1FFFF` (subis 1) where retail has 0x3FFFF (subis 3)
            delta = (retail_v - ours_v) << 16
            for lm in list(re.finditer(r"(?<![\w.])(0[xX][0-9A-Fa-f]+|\d+)(?![\w.])", body))[:64]:
                try:
                    L = int(lm.group(1), 0)
                except ValueError:
                    continue  # a leading-zero decimal (`07`) is not a C literal Python parses with base 0
                if L < 0x10000 or not ((L >> 16) & 0xFFFF == ours_v & 0xFFFF or ((L + 0x8000) >> 16) & 0xFFFF == ours_v & 0xFFFF):
                    continue
                nv = L + delta
                if nv < 0:
                    continue
                rep = f"0x{nv:X}" if lm.group(1).lower().startswith("0x") else str(nv)
                candidates.append((f"imm high half {lm.group(1)} -> {rep} ({mn})", body[:lm.start()] + rep + body[lm.end():]))
        if mn == "mulli" and retail_v > ours_v:
            # a stride: the struct the loop indexes is smaller than retail's; pad its tail
            for sm in re.finditer(r"((?:typedef\s+)?struct\s+\w*\s*\{)([^}]*)(\})", body):
                candidates.append((f"struct tail padding +{retail_v - ours_v} (stride {ours_v}->{retail_v})",
                                   body[:sm.start(2)] + sm.group(2).rstrip() + f"\n    u8 pad_tail[{retail_v - ours_v}];\n" + body[sm.end(2):]))
    # a compare of the wrong signedness where the operand is a header field: cast at the compare
    if any(t and o and (t.split()[0], o.split()[0]) in (("cmpwi", "cmplwi"), ("cmplwi", "cmpwi"), ("cmpw", "cmplw"), ("cmplw", "cmpw")) for t, o in diffs):
        want_signed = any(t and t.split()[0] in ("cmpwi", "cmpw") for t, o in diffs)
        cast = "(s32)" if want_signed else "(u32)"
        for m in list(re.finditer(r"\bif \(([A-Za-z_][\w>.\-\[\]]*) (==|!=|<|>|<=|>=) ", body))[:12]:
            candidates.append((f"cast {cast} at compare of {m.group(1)}", body[:m.start(1)] + cast + m.group(1) + body[m.end(1):]))
    # struct layout: every field offset off by the same delta means padding is missing or extra
    # at the front of the block-private struct; two deltas mean two fields are in the wrong order
    deltas = set()
    for t, o in diffs:
        if not t or not o or t.split()[0] != o.split()[0]:
            continue
        mt = re.search(r"(-?0x[0-9a-f]+|-?\d+)\((r\d+)\)", t); mo = re.search(r"(-?0x[0-9a-f]+|-?\d+)\((r\d+)\)", o)
        if mt and mo and mt.group(2) == mo.group(2) and mt.group(2) != "r1" and mt.group(1) != mo.group(1):
            deltas.add(int(mt.group(1), 0) - int(mo.group(1), 0))
    struct_spans = [(m.start(), m.end(), m.group(1)) for m in re.finditer(r"(?:typedef\s+)?struct\s+\w*\s*\{([^}]*)\}", body)]
    if len(deltas) == 1 and struct_spans:
        delta = next(iter(deltas))
        for s0, e0, inner in struct_spans:
            if delta > 0:
                new_inner = f"\n    u8 _pad_pre[0x{delta:X}];" + inner
                candidates.append((f"struct +{delta} front padding", body[:s0] + body[s0:e0].replace(inner, new_inner, 1) + body[e0:]))
            else:
                m = re.match(r"\s*u8\s+(\w+)\[(0x[0-9A-Fa-f]+|\d+)\];", inner)
                if m and int(m.group(2), 0) + delta >= 0:
                    n = int(m.group(2), 0) + delta
                    rep = "" if n == 0 else f"\n    u8 {m.group(1)}[0x{n:X}];"
                    candidates.append((f"struct {delta} front padding", body[:s0] + body[s0:e0].replace(inner, re.sub(r"^\s*u8\s+\w+\[[^\]]+\];", rep, inner, count=1), 1) + body[e0:]))
    if len(deltas) >= 2 and struct_spans:
        for s0, e0, inner in struct_spans:
            lines = inner.split("\n")
            fl = [i for i, ln in enumerate(lines) if re.match(r"\s*[A-Za-z_][\w ]*\*?\s*\w+(\[[^\]]*\])?;", ln)]
            for a, b in zip(fl, fl[1:]):
                sw = list(lines); sw[a], sw[b] = sw[b], sw[a]
                candidates.append((f"swap fields {lines[a].strip()} <-> {lines[b].strip()}", body[:s0] + body[s0:e0].replace(inner, "\n".join(sw), 1) + body[e0:]))
    # two adjacent independent statements in the other order (the lab closed a function this way)
    if span:
        stmts_ = [(m.start(), m.end(), m.group(0)) for m in re.finditer(r"^[ \t]*[^\n{}]+;\n", body[span[0]:span[1]], re.M)]
        for (s1, e1, t1), (s2, e2, t2) in list(zip(stmts_, stmts_[1:]))[:40]:
            if e1 != s2:
                continue
            ids1 = set(re.findall(r"[A-Za-z_]\w*", t1)); ids2 = set(re.findall(r"[A-Za-z_]\w*", t2))
            if ids1 & ids2 or ("(" in t1 and "(" in t2):
                continue
            candidates.append((f"swap `{t1.strip()[:24]}` / `{t2.strip()[:24]}`", body[:span[0] + s1] + t2 + t1 + body[span[0] + e2:]))
    # inverted branch: negate one `if` condition and swap its then/else blocks
    if any(t and o and (t.split()[0], o.split()[0]) in BRANCH_INV for t, o in diffs):
        for m in list(re.finditer(r"\bif\s*\(", body))[:16]:
            depth, i = 1, m.end()
            while i < len(body) and depth:
                depth += body[i] == "("; depth -= body[i] == ")"; i += 1
            cond = body[m.end():i - 1]
            j = i
            while j < len(body) and body[j] in " \t\r\n": j += 1
            if j >= len(body) or body[j] != "{":
                continue
            d2, k = 1, j + 1
            while k < len(body) and d2:
                d2 += body[k] == "{"; d2 -= body[k] == "}"; k += 1
            then_blk = body[j:k]
            rest = body[k:]
            me = re.match(r"\s*else\s*(\{)", rest)
            if me:
                d3, e = 1, k + me.end()
                while e < len(body) and d3:
                    d3 += body[e] == "{"; d3 -= body[e] == "}"; e += 1
                else_blk = body[k + me.end() - 1:e]
                neg = f"!({cond})" if not re.fullmatch(r"\s*!\((.*)\)\s*", cond) else re.fullmatch(r"\s*!\((.*)\)\s*", cond).group(1)
                text = body[:m.end()] + neg + ") " + else_blk + " else " + then_blk + body[e:]
                candidates.append((f"invert if at {m.start()}", text))
            else:
                # `if (c) { return A; } ... return B;` is equivalent to `if (!c) { rest } return A;` only in
                # simple shapes; the cheap variant that changes codegen: swap == / != in the condition
                if "==" in cond or "!=" in cond:
                    c2 = cond.replace("==", "\0").replace("!=", "==").replace("\0", "!=")
                    candidates.append((f"flip ==/!= at {m.start()}", body[:m.end()] + c2 + body[i - 1:]))
    return candidates

def first_divergence(p: Project, sym, target, obj) -> Optional[Tuple[int, Optional[int], int]]:
    """(row index of the first differing row, our source line at that row, row count)."""
    rows = oracle.function_rows(p, sym.name, target, obj)
    if not rows:
        return None
    l, r, _ = rows
    for k, (a, b) in enumerate(zip(l, r)):
        if (a.get("diff_kind") or "DIFF_NONE") != "DIFF_NONE" or (b.get("diff_kind") or "DIFF_NONE") != "DIFF_NONE":
            line = None
            for j in range(k, -1, -1):
                ln = (r[j].get("instruction") or {}).get("line_number")
                if ln:
                    line = ln; break
            return k, line, len(l)
    if len(l) != len(r):
        return min(len(l), len(r)), None, len(l)
    return None


_POOL_WIDTHS = {}


def _pool_widths(p, module, pool_name):
    """offset -> load width for every `lf[sd]/lwz...` through a base register holding
    `pool_name`, over the whole module's retail disassembly (cached)."""
    key = (module, pool_name)
    if key in _POOL_WIDTHS:
        return _POOL_WIDTHS[key]
    widths = {}
    for fn in p.function_asm(module).values():
        lines = [ln.split(': ', 1)[1] for ln in fn.asm if ': ' in ln]
        regs = set()
        for ln in lines:
            m = re.match(r'addi (r\d+), r\d+, ' + re.escape(pool_name) + r'(?:\+0x[0-9A-Fa-f]+)?@l$', ln)
            if m:
                regs.add(m.group(1))
        if not regs:
            continue
        for ln in lines:
            m = re.match(r'(lfs|lfd|lwz|lha|lhz|lbz|stw|stfs|stfd) [rf]\d+, (-?0x[0-9a-f]+|-?\d+)\((r\d+)\)$', ln)
            if m and m.group(3) in regs:
                off = int(m.group(2), 0)
                if off >= 0:
                    w = 8 if m.group(1) in ('lfd', 'stfd') else 4
                    kind = 'f' if m.group(1) in ('lfs', 'lfd', 'stfs', 'stfd') else 'i'
                    prev = widths.get(off)
                    widths[off] = (kind if prev is None or prev[0] == 'i' else prev[0], max(w, prev[1] if prev else 0))
    _POOL_WIDTHS[key] = widths
    return widths


def frame_padding(p, symbol, body, check):
    """Retail's frame larger than ours by a whole number of words: under 1.2.5-class compilers
    an unreferenced local array reserves its bytes (measured: `u32 pad[4]` grows 0x18 to 0x28
    on 1.2.5n, nothing dead reserves under 1.3.2), so propose a dead pad array of the missing
    size after and before the leading locals; the oracle decides the version."""
    from . import fixup_source as source
    rows = getattr(check, '_rows', None)
    if not rows or 'fzgx_frame_pad' in body:
        return []
    import re as _re
    def frame(side):
        for r in side:
            t = ((r.get('instruction') or {}).get('formatted') or '')
            m = _re.match(r'stwu r1, -(0x[0-9a-f]+)\(r1\)', t)
            if m:
                return int(m.group(1), 16)
        return None
    retail, ours = frame(rows[0]), frame(rows[1])
    if retail is None or ours is None or retail <= ours or (retail - ours) % 4 or retail - ours > 0x400:
        return []
    delta = retail - ours
    a = source._decl_anchor(body, symbol)
    if not a:
        return []
    span, locs, top, indent = a
    out = []
    for label, pos in (("after the locals", top), ("before the locals", locs[0][0] if locs else top)):
        for decl in (f"u32 fzgx_frame_pad[{delta // 4}];", f"u8 fzgx_frame_pad[{delta}];"):
            out.append((f"frame pad {delta:#x} {label}: {decl}", body[:pos] + f"{indent}{decl}  /* fzgx: retail frame home */\n" + body[pos:]))
    return out


def shared_pool_primer(p, symbol, body, check):
    """Retail addresses a translation unit's literal pool through one base register: the pool
    is laid out in first-use order across the whole TU, so a per-function unit's own pool never
    has the same offsets and every `lfs f, off(rB)` differs. A primer reproduces retail's pool
    layout ahead of the function: dummy functions in a section the linker ignores (`.fzgxpool`)
    reference each pooled literal in retail address order, tables between them are private
    `static const` objects; the function's own literals then dedupe onto retail's offsets and
    MWCC's own conversion constants land where retail had them. `poolfix.apply` drops the
    primer section and the private pool at integration; the link places nothing extra."""
    import struct as _struct, math as _math
    sym = p.resolve(symbol)
    # A data-base primer (fixup_layout.initialized_data_views) may already lead the unit: the
    # literal-pool primer then follows it, keeping retail's data-then-pool base order.
    data_primer = re.search(r'#pragma section code_type "\.fzgxpool"\n__declspec\(section "\.fzgxpool"\) static void '
                            r'fzgx_data_base_prime\(void\) \{.*?\n\}\n#pragma section code_type "\.text"\n', body, re.S)
    rest_of_body = body.replace(data_primer[0], '') if data_primer else body
    if sym is None or 'fzgx_pool_prime' in body or '__declspec(section' in rest_of_body or not getattr(check, '_rows', None):
        return []
    lrows, rrows = check._rows
    lfmt = [((r.get('instruction') or {}).get('formatted') or '') for r in lrows]
    rfmt = [((r.get('instruction') or {}).get('formatted') or '') for r in rrows]
    if not any('...rodata' in t or re.match(r'(?:lfs|lfd)\s+f\d+,\s+@\d+@', t) for t in rfmt):
        return []  # the body does not use native literals yet (recover native shared-pool literals first)
    syms = p.symbols(sym.module)
    bases = {}
    for t in lfmt:
        m = re.match(r'addi (r\d+), r\d+, (\w+)(?:\+0x[0-9A-Fa-f]+)?@l$', t)
        if m and m.group(2) in syms and syms[m.group(2)].section == '.rodata' and syms[m.group(2)].kind == 'object':
            bases[m.group(1)] = syms[m.group(2)]
    out = []
    for reg, pool in bases.items():
        own = {}  # offset -> (kind, width) from this function's loads
        for t in lfmt:
            m = re.match(r'(lfs|lfd|lwz|lha|lhz|lbz) [rf]\d+, (-?0x[0-9a-f]+|-?\d+)\(' + reg + r'\)$', t)
            if m:
                off = int(m.group(2), 0)
                if off >= 0:
                    own[off] = ('f' if m.group(1) in ('lfs', 'lfd') else 'i', 8 if m.group(1) == 'lfd' else 4)
        if len(own) < 2:
            continue
        end = (max(o + w for o, (k, w) in own.items()) + 7) & ~7
        # the pool's element types come from every function of the module that addresses it:
        # another function's double must not be read as a float and a zero (the float would
        # dedupe with an equal literal and shift everything after it), and a word only ever
        # loaded as an integer is table data whatever its bits look like
        widths = dict(own)
        for o, kw in _pool_widths(p, sym.module, pool.name).items():
            if o < end:
                widths.setdefault(o, kw)
        own_offsets = {o for o, (k, w) in own.items() if k == 'f'}
        for o, s_ in ((x.addr - pool.addr, x) for x in syms.values() if x.kind == 'object' and x.section == pool.section
                      and pool.addr <= x.addr < pool.addr + end):
            if s_.attrs.get('data') == 'double' and o % 8 == 0:
                widths.setdefault(o, ('f', 8))
        if sym.module == 'main':
            raw = next((data[pool.addr - base:pool.addr - base + end] for base, data in p._rel_layout('main').values()
                        if base <= pool.addr and pool.addr + end <= base + len(data)), None)
        else:
            sec = p._raw_section(sym.module, pool.section); base = p._section_base(sym.module, pool.section)
            raw = sec[pool.addr - base:pool.addr - base + end] if sec is not None else None
        # The 8-byte rounding may pass the end of a pool that closes the section.
        if raw and max(o + w for o, (k, w) in own.items()) <= len(raw) < end:
            end = len(raw) & ~3
        if not raw or len(raw) < end:
            continue
        def cls(off):
            kw = widths.get(off)
            if kw and kw[0] == 'i':
                return 'N'
            if kw and kw[1] == 8:
                return 'D'
            w = raw[off:off + 4]
            if w == b'\0\0\0\0':
                return 'Z'
            v = _struct.unpack('>f', w)[0]
            if kw and kw[0] == 'f':
                return 'F' if _math.isfinite(v) else 'N'
            return 'F' if _math.isfinite(v) and 1e-6 <= abs(v) <= 1e7 else 'N'
        kinds = {off: cls(off) for off in range(0, end, 4)}
        floats = {o for o, kw in widths.items() if kw[0] == 'f'}
        for _ in range(3):  # zero words beside table words belong to the table, unless loaded as a float
            for off in range(0, end, 4):
                if kinds[off] == 'Z' and off not in floats and (kinds.get(off - 4) == 'N' or kinds.get(off + 4) == 'N'):
                    kinds[off] = 'N'
        # MWCC dedupes a literal within one compile unit; retail's rodata block spans the TU's
        # units, so equal values recur. A repeat is raw table bytes unless this function loads
        # it, in which case the earlier copy becomes the table word instead.
        seen = {}
        for off in sorted(kinds):
            k = kinds[off]
            if k not in ('F', 'Z', 'D') or (k == 'D' and off % 8) or (k != 'D' and kinds.get(off - 4) == 'D' and (off - 4) % 8 == 0 and (widths.get(off - 4) or ('', 0))[1] == 8):
                continue
            key = (k, bytes(raw[off:off + (8 if k == 'D' else 4)]))
            if key in seen:
                if off in own_offsets and seen[key] not in own_offsets:
                    kinds[seen[key]] = 'N'; seen[key] = off
                else:
                    kinds[off] = 'N'
            else:
                seen[key] = off
        def flit(v):
            t = repr(v)
            return t if ('.' in t or 'e' in t) else t + '.0'
        segments = []
        off = 0
        own_words = {o for o, (k, w) in own.items() if k == 'i'}
        while off < end:
            k = kinds[off]
            if k == 'N':
                start = off
                # a word this function reads is its own one-element object: MWCC addresses
                # only offset 0 of an object base-relative (`lwz r0, 0x13c(r29)`); `table[1]`
                # materialises the table's address instead
                if off in own_words:
                    off += 4
                else:
                    while off < end and kinds[off] == 'N' and off not in own_words:
                        off += 4
                segments.append(('table', raw[start:off]))
            else:
                if k == 'D':
                    use = f"d = {flit(_struct.unpack('>d', raw[off:off + 8])[0])};"; off += 8
                else:
                    use = f"s = {flit(_struct.unpack('>f', raw[off:off + 4])[0])}f;"; off += 4
                if segments and segments[-1][0] == 'lits':
                    segments[-1][1].append(use)
                else:
                    segments.append(('lits', [use]))
        parts = ['#pragma section code_type ".fzgxpool"']
        for n, (k, v) in enumerate(segments, 1):
            if k == 'lits':
                parts.append(f'__declspec(section ".fzgxpool") static void fzgx_pool_prime{n}(void) {{\n    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */\n    ' + '\n    '.join(v) + '\n}')
            else:
                words = [_struct.unpack('>I', v[i:i + 4])[0] for i in range(0, len(v), 4)]
                parts.append(f'static const u32 fzgx_pool_table{n}[{len(words)}] = {{' + ', '.join(f'0x{w:08X}' for w in words) + '};  /* fzgx-allow: A1 retail pool bytes */')
                parts.append(f'__declspec(section ".fzgxpool") static void fzgx_pool_keep{n}(void) {{ const u32 *volatile cp; cp = fzgx_pool_table{n}; }}  /* fzgx-allow: S2 pool primer sink */')
        parts.append('#pragma section code_type ".text"')
        primer = '\n'.join(parts) + '\n'
        m = re.search(r'^[\w \*]+?\b' + re.escape(sym.name) + r'\s*\([^;{]*\)\s*\{', body, re.M)
        if not m:
            continue
        # a pool word the body reads through its own one-element definition
        # (`const u32 lbl__fzgx_offset_X[1] = {...}` from the object recovery) would be laid out
        # after the primer; it is the primer table's word, so read it there
        table_at = {}
        off = 0
        for n, (k, v) in enumerate(segments, 1):
            if k == 'table':
                for w in range(len(v) // 4):
                    table_at[off + 4 * w] = (n, w)
                off += len(v)
            else:
                for use in v:
                    off += 8 if use.startswith('d =') else 4
        body_ = body
        for definition in list(re.finditer(r'(?m)^const (u32|s32) (\w+?)(?:__fzgx_offset_([0-9A-Fa-f]+))?\[1\] = \{[^}]*\};\n', body_)):
            base_sym = syms.get(definition.group(2))
            if base_sym is None or base_sym.section != pool.section:
                continue
            o = base_sym.addr + int(definition.group(3) or '0', 16) - pool.addr
            if o not in table_at:
                continue
            n, w = table_at[o]
            ident = definition.group(2) + (f'__fzgx_offset_{definition.group(3)}' if definition.group(3) else '')
            body_ = body_.replace(definition.group(0), '')
            body_ = re.sub(r'\b' + re.escape(ident) + r'\[0\]', f'fzgx_pool_table{n}[{w}]', body_)
        # integer reads of pool words through an extern struct view of the pool head
        # (`local.words[k] = pool->unk_2B0`): those words are primer table entries, so read them
        # there; once nothing else uses the view, the extern and its pointer go, and the
        # compiler's section base is the only one left (retail's r30)
        try:
            from .fixup_source import declared_types, record_layouts, member_layout
            from .sdkimport import masked
            code_ = masked(body_)
            span_ = _function_span(code_, sym.name)
            if span_:
                _, variables = declared_types(code_, span_[0])
                layouts = record_layouts(code_, span_[0], variables)
                roots = {}
                for name_, ty in variables.items():
                    if p.find_symbol(name_, sym.module) and p.find_symbol(name_, sym.module).addr == pool.addr:
                        roots[name_] = (0, ty)
                for assignment in re.finditer(r'\b(\w+)\s*=\s*(?:\([^();]+\)\s*)*&?\s*(\w+)\s*;', code_[span_[0]:span_[1]]):
                    if assignment[2] in roots and len(re.findall(r'\b' + re.escape(assignment[1]) + r'\s*=(?!=)', code_[span_[0]:span_[1]])) == 1:
                        roots[assignment[1]] = (span_[0] + assignment.start(), variables.get(assignment[1], ''))
                edits = []
                for root, (assign_at, ty) in roots.items():
                    for use in re.finditer(r'\b' + re.escape(root) + r'((?:\s*(?:->|\.)\s*\w+)+)', code_[span_[0]:span_[1]]):
                        field = member_layout(root + re.sub(r'\s+', '', use[1]), layouts, variables)
                        if not field or field[0] != root:
                            continue
                        _, offset, element, count = field
                        if count is not None or offset not in table_at or element.replace('const ', '').strip() not in ('u32', 's32'):
                            continue
                        n, w = table_at[offset]
                        edits.append((span_[0] + use.start(), span_[0] + use.end(), f'fzgx_pool_table{n}[{w}]'))
                    # the lifter's byte-addressed word read `*(u32 *)((u8 *)root + 0x138)`
                    for use in re.finditer(r'\*\s*\(\s*(?:const\s+)?(?:u32|s32)\s*\*\s*\)\s*\(\s*(?:\(\s*(?:const\s+)?u8\s*\*\s*\)\s*)?'
                                           + re.escape(root) + r'\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)', code_[span_[0]:span_[1]]):
                        offset = int(use[1], 0)
                        if offset not in table_at or re.match(r'\s*(?:=(?!=)|[+*/&|^-]=)', code_[span_[0] + use.end():]):
                            continue
                        n, w = table_at[offset]
                        edits.append((span_[0] + use.start(), span_[0] + use.end(), f'fzgx_pool_table{n}[{w}]'))
                if edits:
                    for a, b, value in sorted(edits, reverse=True):
                        body_ = body_[:a] + value + body_[b:]
                    code_ = masked(body_); span_ = _function_span(code_, sym.name)
                    for root, (assign_at, ty) in roots.items():
                        inner_ = code_[span_[0]:span_[1]]
                        uses = [u for u in re.finditer(r'\b' + re.escape(root) + r'\b', inner_)]
                        if len(uses) <= (1 if assign_at else 0):
                            # only its own assignment (or nothing) is left
                            if assign_at:
                                m_ = re.search(r'(?m)^[ \t]*(?:\w[\w \*]*\s+\**)?' + re.escape(root) + r'\s*=\s*[^;]*;[ \t]*\n?', body_[span_[0]:span_[1]])
                                if m_:
                                    body_ = body_[:span_[0] + m_.start()] + body_[span_[0] + m_.end():]
                                    code_ = masked(body_); span_ = _function_span(code_, sym.name)
                                decl_ = re.search(r'(?m)^[ \t]*(?:struct\s+)?\w+\s*\*\s*' + re.escape(root) + r'\s*;[ \t]*\n', body_[span_[0]:span_[1]])
                                if decl_:
                                    body_ = body_[:span_[0] + decl_.start()] + body_[span_[0] + decl_.end():]
                                    code_ = masked(body_); span_ = _function_span(code_, sym.name)
                    for name_ in list(roots):
                        if p.find_symbol(name_, sym.module) and not re.search(r'\b' + re.escape(name_) + r'\b', code_[span_[0]:span_[1]]):
                            body_ = re.sub(r'(?m)^extern\s+[^;]*\b' + re.escape(name_) + r'\b[^;]*;[ \t]*\n', '', body_)
        except Exception:
            pass
        if body_ != body:
            body = body_
            m = re.search(r'^[\w \*]+?\b' + re.escape(sym.name) + r'\s*\([^;{]*\)\s*\{', body, re.M)
        # ahead of every file-scope definition: a static const object of the body is pool data
        # too, and MWCC lays the section out in definition order
        includes = list(re.finditer(r'^#include[^\n]*\n', body[:m.start()], re.M))
        at = includes[-1].end() if includes else 0
        if not includes:
            # Expanded saved units contain their primitive typedefs instead
            # of types.h. A primer before them cannot compile.
            primitives = list(re.finditer(r'\btypedef\s+[^;{}]+\b(?:u32|f32|f64)\s*;', body[:m.start()]))
            if primitives:
                at = max(declaration.end() for declaration in primitives)
                primer = '\n' + primer
        leading = re.search(r'#pragma section code_type "\.fzgxpool"\n__declspec\(section "\.fzgxpool"\) static void '
                            r'fzgx_data_base_prime\(void\) \{.*?\n\}\n#pragma section code_type "\.text"\n', body, re.S)
        if leading and leading.end() <= m.start():
            at = leading.end()
        text = body[:at] + primer + body[at:]
        out.append((f'prime shared-pool layout ({pool.name}, {end:#x} bytes)', text))
        # A run of pool words this function reads as integers and copies out is often its own
        # initialized local (`Vec pos = {0.0f, -20.0f, 0.0f};`): MWCC emits that aggregate when
        # it compiles the function, after everything already primed. Priming only up to the run
        # leaves its retail offset free (fn_10_12C14: the aggregate at +0x444).
        runs = sorted(o for o in own_words if o + 4 in own_words and o - 4 not in own_words)
        if runs and runs[0] > 0:
            cut = _primer_entry_at(primer, runs[0])
            if cut is not None:
                truncated = primer[:cut] + '#pragma section code_type ".text"\n'
                out.append((f'prime shared-pool layout ({pool.name}) up to the initializer at {runs[0]:#x}',
                            body[:at] + truncated + body[at:]))
    return out


def _primer_entry_at(primer: str, offset: int) -> Optional[int]:
    """Position in a generated pool primer of the top-level entry laid out at `offset`
    (a table definition or a literal function), or None when no entry starts there."""
    off = 0
    for m in re.finditer(r'^\s*(s|d) = [^;]+;|^static const u32 fzgx_pool_table\d+\[(\d+)\]|'
                         r'^__declspec\(section "\.fzgxpool"\) static void fzgx_pool_prime\d+', primer, re.M):
        if m.group(0).startswith('__declspec'):
            nxt = re.search(r'^\s*(s|d) = ', primer[m.end():], re.M)
            if off == offset and nxt and nxt.group(1) == 's':
                return m.start()
            continue
        if m.group(2):
            if off == offset:
                return m.start()
            off += int(m.group(2)) * 4
        elif m.group(1) == 's':
            off += 4
        else:
            off += 4 if off % 8 else 0
            off += 8
    return None
