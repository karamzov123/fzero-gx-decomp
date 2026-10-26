"""Import identified SDK C with declarations and relocation bindings derived from objects."""

from __future__ import annotations

import json
import ast
import operator
import re
import struct
import subprocess
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path

from . import api, oracle, sdkmatch
from .ledger import Ledger
from .poolfix import Elf, code_reloc_offset
from .project import ROOT, STATE_DIR, Project
from .reuse import replace_symbols

LEXICAL = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'', re.S)
IDENT = re.compile(r"\b[A-Za-z_]\w*\b")
FLAGS = '-use_lmw_stmw on -fp fmadd -fp_contract off -char signed -common off'
BASE_TYPES = {'s8', 's16', 's32', 's64', 'u8', 'u16', 'u32', 'u64', 'f32', 'f64', 'BOOL', 'size_t'}


def replace_c_symbols(text: str, mapping: dict) -> str:
    clean = masked(text)
    members = set()
    for record in re.finditer(r'\b(?:struct|union)\s*(?:\w+\s*)?\{', clean):
        depth = 1
        end = record.end()
        while end < len(clean) and depth:
            depth += (clean[end] == '{') - (clean[end] == '}')
            end += 1
        body = clean[record.end():end - 1]
        for member in re.finditer(r'\b(\w+)\s*(?:\[[^\]]*\]\s*)*;', body):
            members.add(record.end() + member.start(1))
        for member in re.finditer(r'\(\s*\*\s*(\w+)\s*\)', body):
            members.add(record.end() + member.start(1))
    edits = [(m.start(), m.end(), mapping[m[0]]) for m in IDENT.finditer(clean)
             if m[0] in mapping and m.start() not in members
             and not re.search(r'(?:\.|->)\s*$', clean[:m.start()])]
    for start, end, value in reversed(edits):
        text = text[:start] + value + text[end:]
    return text


def masked(text: str) -> str:
    return LEXICAL.sub(lambda m: ''.join('\n' if c == '\n' else ' ' for c in m[0]), text)


def isolate_parameters(text: str, mapping: dict) -> str:
    """Parameter names have function scope even when an SDK global has the same name."""
    for piece in declarations(text):
        if piece.kind not in ('function', 'prototype'):
            continue
        signature = piece.signature if piece.kind == 'function' else piece.text
        parameters = signature[signature.find('(') + 1:signature.rfind(')')]
        local = {}
        for parameter in parameters.split(','):
            name = re.search(r'[\s*](\w+)\s*(?:\[[^\]]*\]\s*)*$', parameter)
            if name and name[1] in mapping:
                local[name[1]] = 'sdk_arg_' + name[1]
        if local:
            text = text.replace(piece.text, replace_c_symbols(piece.text, local))
    return text


@dataclass
class Piece:
    kind: str
    names: set
    text: str
    signature: str = ""
    address: int | str | None = None


def integer_expression(text: str) -> int:
    text = re.sub(r'\(\s*(?:void|u32|s32|unsigned\s+(?:int|long)|signed\s+(?:int|long))\s*\*?\s*\)', '', text)
    text = re.sub(r'\b(0[xX][\da-fA-F]+|\d+)[uUlL]+\b', r'\1', text)
    ops = {ast.LShift: operator.lshift, ast.RShift: operator.rshift,
           ast.BitOr: operator.or_, ast.BitAnd: operator.and_, ast.Add: operator.add,
           ast.Sub: operator.sub, ast.Mult: operator.mul}
    def value(node):
        if isinstance(node, ast.Constant) and isinstance(node.value, int):
            return node.value
        if isinstance(node, ast.BinOp) and type(node.op) in ops:
            return ops[type(node.op)](value(node.left), value(node.right))
        if isinstance(node, ast.UnaryOp) and isinstance(node.op, (ast.USub, ast.UAdd, ast.Invert)):
            return {ast.USub: operator.neg, ast.UAdd: operator.pos, ast.Invert: operator.invert}[type(node.op)](value(node.operand))
        raise ValueError(f'unsupported SDK address expression: {text}')
    return value(ast.parse(text, mode='eval').body)


def declarations(text: str) -> list:
    """Split compiler-preprocessed C at top-level declarations/function definitions."""
    text = re.sub(r"^[ \t]*#(?:[^\n]*\\\n)*[^\n]*(?:\n|$)", "", text, flags=re.M)
    text = LEXICAL.sub(lambda m: ' ' if m[0].startswith('/') else m[0], text)
    text = re.sub(r'__declspec\s*\((?:weak|section\s+"[^"]*")\)\s*', '', text)
    # MWCC -E joins this typedef and parameter name in the SDK error header.
    text = re.sub(r'\bOSError(error|code)\b', r'OSError \1', text)
    clean = masked(text)
    out = []
    start = depth = parens = 0
    function = None
    for i, ch in enumerate(clean):
        if ch == '(':
            parens += 1
        elif ch == ')':
            parens -= 1
        elif ch == '{':
            if depth == 0:
                prefix = clean[start:i].strip()
                m = re.search(r"\b(\w+)\s*\([^;{}]*\)\s*$", prefix)
                if m and not re.match(r"(?:typedef|struct|union|enum)\b", prefix) and '=' not in prefix:
                    function = (m[1], text[start:i].strip())
            depth += 1
        elif ch == '}':
            depth -= 1
            if depth == 0 and function:
                name, signature = function
                out.append(Piece('function', {name}, text[start:i + 1].strip(), signature))
                start = i + 1
                function = None
        elif ch == ';' and depth == 0 and parens == 0:
            part = text[start:i + 1].strip()
            part = re.sub(r'__attribute__\s*\(\(aligned\(\d+\)\)\)', '', part).strip()
            start = i + 1
            if not part:
                continue
            # SDK math files group constants under one type declaration. Split
            # only declarator commas, keeping array initializers and calls intact.
            if not part.startswith(('typedef', 'struct', 'union', 'enum')):
                nesting = 0
                commas = []
                for pos, char in enumerate(masked(part)):
                    nesting += (char in '([{') - (char in ')]}')
                    if char == ',' and nesting == 0:
                        commas.append(pos)
                if commas:
                    first = re.fullmatch(r'((?:\w+\s+)+)(\**\s*\w+.*)', part[:commas[0]], re.S)
                    if first:
                        chunks = [first[2]] + [part[a + 1:b] for a, b in zip(commas, commas[1:] + [len(part) - 1])]
                        for chunk in chunks:
                            out.extend(declarations(first[1] + chunk.strip() + ';'))
                        continue
            names = set()
            address = None
            if part.startswith('typedef'):
                fp = re.search(r"\(\s*\*\s*(\w+)\s*\)", part.split('{', 1)[0])
                tail = re.search(r"\b(\w+)\s*(?:\[[^\]]*\]\s*)*;\s*$", part)
                if fp:
                    names.add(fp[1])
                elif tail:
                    names.add(tail[1])
                names.update(re.findall(r"\b(?:struct|union|enum)\s+(\w+)", part.split('{')[0]))
                kind = 'type'
            elif re.match(r"(?:struct|union|enum)\s+\w+\s*[;{]", part):
                names.add(re.match(r"\w+\s+(\w+)", part)[1])
                kind = 'type'
            else:
                pointer = re.search(r"\(\s*\*\s*(\w+)\s*\)\s*\(", part.split('=', 1)[0])
                proto = re.search(r"\b(\w+)\s*\([^;{}]*\)\s*;\s*$", part)
                if pointer:
                    names.add(pointer[1])
                    kind = 'object'
                elif proto and '=' not in part:
                    names.add(proto[1])
                    kind = 'prototype'
                else:
                    absolute = re.fullmatch(r'([^:{}=]+)\s*:\s*([^{}]+);', masked(part), re.S)
                    if absolute:
                        address = absolute[2].strip() if re.fullmatch(r'\s*\w+\s*', absolute[2]) else integer_expression(absolute[2])
                        if isinstance(address, str) and not address.isidentifier():
                            address = integer_expression(address)
                        part = absolute[1].strip() + ';'
                    decl = part.split('=', 1)[0].rstrip().rstrip(';')
                    decl = re.sub(r'__attribute__\s*\(\(aligned\(\d+\)\)\)', '', decl).strip()
                    var = re.search(r"\b(\w+)\s*(?:\[[^\]]*\]\s*)*$", decl)
                    if var:
                        names.add(var[1])
                    kind = 'object'
            enumeration = re.search(r'\benum\s*(?:\w+\s*)?\{([^{}]*)\}', masked(part), re.S)
            if enumeration:
                names.update(re.findall(r'(?:^|,)\s*(\w+)', enumeration[1]))
                kind = 'type'
            out.append(Piece(kind, names, part, address=address))
    return out


def include_directories(sdk: Path) -> list:
    includes = ['include', '.', 'src', 'src/dolphin', 'libs/dolphin']
    if sdk.name == 'fzerox':
        includes += ['include/PR', 'include/leo']
    includes += [str(d.relative_to(sdk)) for d in sdk.rglob('*')
                 if d.is_dir() and d.name.lower() in ('include', 'inc') and '.git' not in d.parts
                 and len(d.relative_to(sdk).parts) <= 6]
    # Embedded MSL math headers sit deeper than the generic Include scan.
    # float.h includes fdlibm.h, including when compiling non-math SDK units.
    for header in ('stddef.h', 'fdlibm.h'):
        includes += [str(path.parent.relative_to(sdk)) for path in sorted(sdk.rglob(header))]
    return [sdk / inc for inc in dict.fromkeys(includes) if (sdk / inc).is_dir()]


def preprocessor_flags(sdk: Path) -> list:
    if sdk.name == 'fzerox':
        # The N64 build normally supplies these through IDO and its Makefile.
        return ['-D_LANGUAGE_C', '-D_MIPS_SZLONG=32', '-D_MIPS_SZINT=32', '-D_MIPS_SZPTR=32',
                '-DF3DEX_GBI_2', '-DVERSION_US=1', '-DBUILD_REVISION=REVISION_B',
                '-DLANGUAGE=LANGUAGE_ENG', '-DOS_TV_TYPE=OS_TV_TYPE_NTSC',
                '-DBUILD_VERSION=VERSION_I', '-DASSET_VERSION=us', '-DASSET_REVISION=rev0']
    return []


def preprocess(sdk: Path, source: str, mw: str) -> str:
    scratch = STATE_DIR / 'sdkimport' / sdk.name
    scratch.mkdir(parents=True, exist_ok=True)
    output = scratch / (Path(source).stem + '.i')
    cmd = [str(ROOT / 'build/tools/wibo'), str(ROOT / 'build/compilers' / mw / 'mwcceppc.exe')]
    cmd += sdkmatch.DOLPHIN_FLAGS + ['-cwd', 'source'] + preprocessor_flags(sdk)
    for inc in include_directories(sdk):
        cmd += ['-i', str(inc)]
    input_source = source
    if sdk.name == 'fzerox':
        # Asset declarations require an N64 ROM extraction. Their identifiers stay
        # unresolved, so only functions whose declaration closure is complete can
        # enter the donor catalog; no asset types or values are invented.
        body = (sdk / source).read_text()
        body = re.sub(r'^\s*#include\s+ASSET_HEADER\([^\n]+\)\s*$', '', body, flags=re.M)
        wrapper = scratch / (Path(source).stem + '.input.c')
        wrapper.write_text('#line 1 ' + json.dumps(source) + '\n' + body)
        input_source = str(wrapper)
        cmd += ['-i', str((sdk / source).parent)]
    cp = subprocess.run(cmd + ['-E', input_source], cwd=sdk, text=True, capture_output=True, timeout=120)
    if cp.returncode:
        raise RuntimeError((cp.stdout + cp.stderr)[-3000:])
    output.write_text(cp.stdout)
    return cp.stdout


def source_pragmas(sdk: str, source: str, name: str) -> list:
    text = masked((ROOT / 'build/tools' / sdk / source).read_text())
    location = re.search(r'\b' + re.escape(name) + r'\s*\([^;{}]*\)\s*\{', text)
    active = {}
    preceding = text[:location.start()] if location else ''
    if re.search(r'\basm\b', preceding):
        # MWCC disables its peephole pass for source files containing asm definitions.
        active['peephole'] = 'off'
    for match in re.finditer(r'^\s*#pragma\s+(scheduling|peephole|dont_inline|opt_loop_invariants)\s+(on|off|reset)',
                             preceding, re.M):
        if match[2] == 'reset':
            active.pop(match[1], None)
        else:
            active[match[1]] = match[2]
    return [f'#pragma {key} {value}' for key, value in active.items()]


def relocations(obj: Path, name: str) -> dict:
    elf = Elf(obj.read_bytes())
    symbols = elf.symbols()
    fn = next(s for s in symbols if s['name'] == name and s['info'] & 15 == 2)
    out = {}
    for section in elf.sections:
        if section['type'] != 4 or section['info'] != fn['shndx']:
            continue
        for off in range(section['offset'], section['offset'] + section['size'], 12):
            addr, info, addend = struct.unpack_from('>IIi', elf.data, off)
            if fn['value'] <= addr < fn['value'] + fn['size']:
                symbol = symbols[info >> 8]
                out[code_reloc_offset(addr, info & 255) - fn['value']] = (symbol['name'], addend, info & 255)
    return out


def candidates(p: Project, library: str) -> list:
    by_addr = {s.addr: s for s in p.functions('main')}
    ledger = Ledger()
    result = []
    for sdk in ('mkdd', 'tww'):
        path = ROOT / 'state/seeds' / f'sdkmatch_{sdk}.json'
        data = json.loads(path.read_text())
        for hit in data['hits']:
            sym = by_addr.get(hit.get('addr'))
            if sym is None or sym.size != hit['size']:
                continue
            row = ledger.get(p.key(sym))
            if row is None or row['status'] != 'unmatched':
                continue
            for source in hit['sources']:
                if f'/{library}/' in source:
                    result.append(dict(symbol=sym.name, size=sym.size, sdk=sdk, source=source,
                                       sdk_symbol=hit['sdk'][0], mw=data['mw']))
    return result


def source_object(p: Project, rec: dict) -> Path:
    if rec.get('object'):
        return Path(rec['object'])
    return p.build_dir / 'sdkmatch' / rec['sdk'] / Path(rec['source']).with_suffix('.o')


def bindings(p: Project, rec: dict, offsets: dict | None = None) -> dict:
    source_obj = source_object(p, rec)
    sym = p.resolve(rec['symbol'])
    target = p.target_object_for(sym)
    left = relocations(source_obj, rec['sdk_symbol'])
    right = relocations(target, sym.name)
    source_symbols = {s['name']: s for s in Elf(source_obj.read_bytes()).symbols()}
    known = rec.get('known_bindings', {})
    mapping = dict(known) | {rec['sdk_symbol']: sym.name}
    for off, (name, addend, kind) in left.items():
        if name.startswith('@') or re.fullmatch(r'_(?:save|rest)[gf]pr_\d+', name):
            continue
        if name in oracle.abs_symbols():
            mapping[name] = name
            continue  # The object oracle compares these against the resolved retail instruction.
        if name in known:
            continue  # Earlier aligned source references; the oracle checks every use.
        target_off = offsets.get(off) if offsets is not None else off
        if target_off not in right:
            raise ValueError(f'{off:#x}: source relocation {name} has no retail relocation')
        dest, dest_addend, dest_kind = right[target_off]
        dest_sym = retail_symbol(p, sym.module, dest)
        if dest_sym and dest_sym.scope != 'local':
            dest = dest_sym.name
        if kind == dest_kind and (addend != dest_addend or name in mapping and mapping[name] != dest):
            target_sym = retail_symbol(p, sym.module, dest)
            previous = retail_symbol(p, sym.module, mapping[name]) if name in mapping else None
            if target_sym:
                address = target_sym.addr + dest_addend - addend
                if previous and previous.addr == address:
                    continue
                if not previous:
                    base = next((s for s in p.symbols(sym.module).values()
                                 if s.addr == address and s.name.isidentifier()), None)
                    if base:
                        mapping[name] = base.name
                        continue
                own = source_symbols.get(name)
                delta = address - target_sym.addr
                if (target_sym.kind == 'object' and target_sym.name.isidentifier() and own
                        and own['info'] & 15 == 1 and own['size'] > 0
                        and 0 < delta and delta + own['size'] <= target_sym.size):
                    alias = f'{target_sym.name}__fzgx_offset_{delta:X}'
                    if name not in mapping or mapping[name] == alias:
                        # The ordinary oracle proves this subobject relocation;
                        # poolfix adjusts only its binding/addend at integration.
                        mapping[name] = alias
                        continue
        if (addend, kind) != (dest_addend, dest_kind):
            raise ValueError(f'{off:#x}: {name}+{addend:#x} -> {dest}+{dest_addend:#x}, relocation {kind}/{dest_kind}')
        if name in mapping and mapping[name] != dest:
            raise ValueError(f'inconsistent binding of {name}: {mapping[name]} / {dest}')
        mapping[name] = dest
    return mapping


def retail_symbol(p: Project, module: str, name: str):
    sym = p.symbols(module).get(name)
    if sym is None:
        sym = next((s for s in p.symbols(module).values() if name == f'{s.name}_{s.addr:08X}'), None)
    return sym


def object_declaration(piece: Piece) -> str:
    decl = piece.text.split('=', 1)[0].strip().rstrip(';')
    if re.search(r'\[\s*\]', decl) and '=' in piece.text:
        initializer = masked(piece.text.split('=', 1)[1]).strip().rstrip(';').strip()
        if initializer.startswith('{') and initializer.endswith('}'):
            depth, count = 0, 0
            for ch in initializer[1:-1].strip().rstrip(','):
                depth += (ch in '{([') - (ch in '})]')
                count += ch == ',' and depth == 0
            decl = re.sub(r'\[\s*\]', f'[{count + 1}]', decl, count=1)
    return decl


def dependency_closure(pieces: list, function: Piece, mapping: dict) -> tuple:
    providers = defaultdict(list)
    for i, piece in enumerate(pieces):
        for name in piece.names:
            providers[name].append(i)
    selected = set()
    todo = set(IDENT.findall(masked(function.text))) - function.names
    seen = set(function.names)
    while todo:
        name = todo.pop()
        if name in seen:
            continue
        seen.add(name)
        for i in providers.get(name, []):
            piece = pieces[i]
            selected.add(i)
            text = (piece.signature if piece.names & mapping.keys() else piece.text) if piece.kind == 'function' else piece.text.split('=', 1)[0] if piece.kind == 'object' else piece.text
            todo.update(set(IDENT.findall(masked(text))) - seen)
    types, externs = [], []
    for i in sorted(selected):
        piece = pieces[i]
        if piece.kind == 'type':
            types.append(piece.text)
        elif piece.kind == 'function':
            if piece.names & mapping.keys():
                externs.append(re.sub(r'^(?:static\s+|inline\s+)+', '', piece.signature) + ';')
            else:
                externs.append('static inline ' + re.sub(r'^(?:static\s+|inline\s+)+', '', piece.text))
        elif piece.kind == 'object':
            # sizeof(array) remains meaningful after its initializer is removed.
            decl = object_declaration(piece)
            externs.append('extern ' + re.sub(r'^(?:static\s+|extern\s+)+', '', decl) + ';')
        elif piece.kind == 'prototype' and piece.names & mapping.keys():
            externs.append(re.sub(r'^(?:static\s+|inline\s+)+', '', piece.text))
        else:
            externs.append(piece.text)
    if any(function.names & set(IDENT.findall(masked(text))) for text in externs):
        # An inline helper may register this function as a callback before its
        # definition. The closure's cycle guard must not discard its prototype.
        externs.insert(0, re.sub(r'^(?:static\s+|inline\s+)+', '', function.signature) + ';')
    return list(dict.fromkeys(types)), list(dict.fromkeys(externs))


def prepare(p: Project, library: str) -> dict:
    records = candidates(p, library)
    by_source = defaultdict(list)
    for rec in records:
        by_source[(rec['sdk'], rec['source'], rec['mw'])].append(rec)
    result = {'library': library, 'candidates': len({r['symbol'] for r in records}), 'prepared': [], 'errors': []}
    root = STATE_DIR / 'sdkimport' / library
    root.mkdir(parents=True, exist_ok=True)
    for (sdk_name, source, mw), group in by_source.items():
        sdk = ROOT / 'build/tools' / sdk_name
        pieces = declarations(preprocess(sdk, source, mw))
        functions = {next(iter(piece.names)): piece for piece in pieces if piece.kind == 'function'}
        for rec in group:
            try:
                function = functions[rec['sdk_symbol']]
                if re.search(r'\basm\b', masked(function.text)):
                    raise ValueError('assembly definition')
                mapping = bindings(p, rec)
                types, externs = dependency_closure(pieces, function, mapping)
                text = '\n\n'.join(types + externs + [re.sub(r'^static\s+', '', function.text)]) + '\n'
                if re.search(r'\basm\s*\{', masked(text)):
                    raise ValueError('inline assembly dependency')
                text = externalize_statics(text, mapping)
                text, absolutes = absolute_declarations(pieces, text)
                for storage, aggregate in (('aggregate', True), ('direct', False), ('native', None)):
                    bound = dict(mapping)
                    raw = shared_storage(p, rec, pieces, text, bound, aggregate=aggregate)
                    raw = replace_c_symbols(isolate_parameters(raw, bound), bound)
                    for messages in (False, True):
                        body = literal_storage(p, rec, raw) if messages else raw
                        variant = storage + ('-messages' if messages else '')
                        path = root / f"{rec['symbol']}.{sdk_name}.{variant}.c"
                        path.write_text(body)
                        result['prepared'].append({**rec, 'path': str(path), 'bindings': bound, 'absolutes': absolutes,
                                                   'variant': variant,
                                                   'pragmas': source_pragmas(sdk_name, source, rec['sdk_symbol'])})
            except (KeyError, ValueError, StopIteration) as e:
                result['errors'].append({**rec, 'error': str(e)})
    (root / 'prepare.json').write_text(json.dumps(result, indent=2) + '\n')
    return result


def externalize_statics(text: str, mapping: dict) -> str:
    """Bind function-local static objects using their compiler-emitted symbol identities."""
    locals_by_name = defaultdict(set)
    for name, target in mapping.items():
        if '$' in name:
            locals_by_name[name.split('$')[0]].add(target)
    clean = masked(text)
    edits = []
    for match in re.finditer(r'\bstatic\s+[^;]+;', clean):
        original = text[match.start():match.end()]
        pieces = declarations(original)
        if len(pieces) != 1 or pieces[0].kind != 'object':
            continue
        piece = pieces[0]
        name = next(iter(piece.names), '')
        targets = locals_by_name.get(name, set())
        if len(targets) != 1:
            continue
        decl = re.sub(r'^static\s+', 'extern ', original.split('=', 1)[0].strip().rstrip(';')) + ';'
        mapping[name] = next(iter(targets))
        edits.append((match.start(), match.end(), decl))
    # Keep declarations in their original scope, after the headers and private
    # typedefs they use. Hoisting them ahead of types.h breaks otherwise valid imports.
    for start, end, declaration in reversed(edits):
        text = text[:start] + declaration + text[end:]
    return text


MEMORY_NAMES = {
    0x80000028: '__OSPhysicalMemSize', 0x800000F0: '__OSSimulatedMemSize',
    0x800000C4: '__OSGlobalInterruptMask', 0x800000C8: '__OSLocalInterruptMask',
    0x800000F4: '__OSBI2Pointer', 0x800030E8: '__OSBI2DebugFlag',
    0x800030E9: '__OSPadSpecByte',
    0x800030D8: '__OSTimeAdjust', 0x80000C00: '__OSSystemCallVectorAddress',
    0x81000000: '__OSAudioInitBuffer', 0x81800000: '__OSUnmappedMemory',
}


def memory_declarations(text: str) -> tuple:
    """Replace constant SDK pointer expressions with linker-generated address constants."""
    addresses, edits = {}, []
    clean = masked(text)
    for cast in re.finditer(r'\(\s*\w+\s*\*\s*\)\s*', clean):
        start = cast.end()
        if any(lo <= cast.start() < hi for lo, hi, _ in edits):
            continue
        if start == len(clean):
            continue
        end = start
        if clean[start] == '(':
            depth = 0
            for end in range(start, len(clean)):
                depth += (clean[end] == '(') - (clean[end] == ')')
                if depth == 0:
                    end += 1
                    break
        else:
            number = re.match(r'0[xX][0-9a-fA-F]+', clean[start:])
            if not number:
                continue
            end = start + len(number[0])
        expression = re.sub(r'\(\s*(?:void|u32|s32|unsigned long)\s*\*?\s*\)', '', clean[start:end])
        try:
            address = integer_expression(expression)
        except (ValueError, SyntaxError):
            continue
        if address not in MEMORY_NAMES:
            continue
        name = MEMORY_NAMES[address]
        addresses[name] = address
        edits.append((start, end, 'FZGX_ADDR_' + name))
    for start, end, name in reversed(edits):
        text = text[:start] + name + text[end:]
    return text, addresses


def absolute_declarations(pieces: list, text: str) -> tuple:
    """Preserve MWCC absolute declarations; constants come from the linker script."""
    text, addresses = memory_declarations(text)
    for piece in pieces:
        if piece.address is None:
            continue
        name = next(iter(piece.names))
        decl = 'extern ' + re.sub(r'^(?:static\s+|extern\s+)+', '', piece.text)
        if decl not in text:
            continue
        text = text.replace(decl, piece.text.rstrip(';') + f' : FZGX_ADDR_{name};')
        addresses[name] = piece.address
    if addresses:
        text = '#include "sdk_addresses.h"\n\n' + text
    return text, addresses


def native_storage(p: Project, rec: dict, pieces: list, text: str, mapping: dict,
                   elf: Elf, source: dict, dest, objects: list) -> str:
    """Preserve measured TU object offsets, including unreferenced prefix objects."""
    used = set(IDENT.findall(masked(text)))
    selected = []
    for obj in objects:
        name = obj['name']
        local = name.split('$')[0]
        if local not in used or name.startswith('@'):
            continue
        piece = next((x for x in pieces if x.kind == 'object' and name in x.names), None)
        if piece is not None:
            decl = object_declaration(piece)
            external = 'extern ' + re.sub(r'^(?:static\s+|extern\s+)+', '', decl) + ';'
            if external not in text:
                continue
            text = text.replace(external, '')
        elif '$' in name:
            matches = [m for m in re.finditer(r'\bstatic\s+[^;{}]+;', masked(text))
                       if re.search(r'\b' + re.escape(local) + r'\b', m[0])]
            if len(matches) != 1:
                continue
            match = matches[0]
            parsed = declarations(text[match.start():match.end()])
            if len(parsed) != 1 or parsed[0].kind != 'object':
                continue
            piece = parsed[0]
            text = text[:match.start()] + text[match.end():]
        else:
            continue
        selected.append((obj['value'] - source['value'], obj, local, piece.text))
    if not selected:
        return text
    section = elf.sections[source['shndx']]
    definitions, accesses, cursor = [], [], 0
    tag = re.sub(r'\W', '_', source['name'])
    for offset, obj, name, definition in sorted(selected):
        if offset < cursor:
            raise ValueError(f'overlapping native objects: {name}')
        while cursor < offset:
            # Keep the base object's identity and extent for the BSS oracle.
            end = min(offset, dest.size) if cursor == 0 else offset
            if end <= cursor:
                raise ValueError(f'empty native anchor: {dest.name}')
            gap = mapping[source['name']] if cursor == 0 else f'sdk_gap_{tag}_{cursor:x}'
            declaration = f'static unsigned char {gap}[{end - cursor}]'
            if section['type'] != 8:
                lo, hi = source['value'] + cursor, source['value'] + end
                if any(rel['type'] == 4 and rel['info'] == source['shndx'] and
                       any(lo <= struct.unpack_from('>I', elf.data, at)[0] < hi
                           for at in range(rel['offset'], rel['offset'] + rel['size'], 12))
                       for rel in elf.sections):
                    raise ValueError(f'native gap contains relocations: {gap}')
                layout = p._rel_layout(dest.module)
                regions = layout.values() if dest.module == 'main' else [layout.get(dest.section, (0, b''))]
                raw = next((data[dest.addr + cursor - base:dest.addr + end - base]
                            for base, data in regions
                            if base <= dest.addr + cursor and dest.addr + end <= base + len(data)), None)
                if raw is None:
                    raise ValueError(f'native gap outside retail data: {gap}')
                declaration += ' = {' + ', '.join(str(v) for v in raw) + '}'
            definitions.append(declaration + ';')
            accesses.append(gap)
            cursor = end
        if offset == 0:
            mapping[name] = mapping[source['name']]
        definitions.append(definition)
        accesses.append(name)
        cursor = offset + obj['size']
    block = '\n'.join(definitions) + '\n'
    if section['type'] == 8:
        # BSS follows first access order, even when declarations are in order.
        block += '#pragma section code_type ".fzgxpool"\nstatic void sdk_layout_' + tag + '(void) {\n'
        block += 'volatile unsigned char sink; // fzgx-allow: S2 discarded layout primer\n'
        block += ''.join(f'sink = *(unsigned char *)&{name};\n' for name in accesses)
        block += '}\n#pragma section code_type ".text"\n'
    index = next((i for i in range(len(text)) if text.startswith('static inline ', i)), -1)
    if index < 0:
        signature = next(x.signature for x in pieces if x.kind == 'function' and rec['sdk_symbol'] in x.names)
        index = text.index(re.sub(r'^static\s+', '', signature))
    return text[:index] + block + '\n' + text[index:]


def shared_storage(p: Project, rec: dict, pieces: list, text: str, mapping: dict,
                   aggregate: bool | None = True) -> str:
    """Recover a compiler-generated data base as a typed aggregate, checking retail layout."""
    anchors = [n for n in mapping if n.startswith('.')]
    if not anchors:
        return text
    obj = source_object(p, rec)
    elf = Elf(obj.read_bytes())
    symbols = elf.symbols()
    module = p.resolve(rec['symbol']).module
    retail = list(p.symbols(module).values())
    for anchor in anchors:
        source = next(s for s in symbols if s['name'] == anchor)
        dest = p.symbols(module).get(mapping[anchor])
        if dest is None:
            suffix = re.search(r'_([0-9A-Fa-f]{8})$', mapping[anchor])
            dest = next((s for s in retail if suffix and s.addr == int(suffix[1], 16)), None)
        if dest is None:
            raise ValueError(f'unknown data base: {mapping[anchor]}')
        # Saved SDK signatures can predate local-to-global symbol promotion.
        mapping[anchor] = dest.name + (f'_{dest.addr:08X}' if dest.scope == 'local' else '')
        objects = [s for s in symbols if s['shndx'] == source['shndx'] and s['info'] & 15 == 1
                   and s['value'] >= source['value']]
        if not any(not s['name'].startswith('@') for s in objects):
            continue  # Compiler string pool: keep the original literals for poolfix.
        named = [s for s in objects if not s['name'].startswith('@')]
        if aggregate is None:
            # MWCC addresses independent TU objects through one section base.
            # An extern struct view cannot reproduce every address expression.
            # Keep the donor definitions as a candidate; the object oracle must
            # prove their bytes and bindings before poolfix can remove copies.
            text = native_storage(p, rec, pieces, text, mapping, elf, source, dest, objects)
            continue
        if not aggregate and len(named) == 1 and named[0]['value'] == source['value']:
            mapping[named[0]['name']] = mapping[anchor]
            continue
        fields, cursor, replacements = [], 0, {}
        tag = 'SDK_' + Path(rec['source']).stem + '_' + re.sub(r'\W', '_', anchor)
        local = 'sdk_storage_' + re.sub(r'\W', '_', anchor)
        used = set(IDENT.findall(masked(text)))
        for s in sorted(objects, key=lambda s: s['value']):
            if s['name'].startswith('@') or s['name'] not in used:
                continue
            offset = s['value'] - source['value']
            # DTK may split an SDK aggregate (OSAlarm/OSThread) into smaller symbols.
            # Its fields must fit the retail section, not one guessed symbol extent.
            section_symbols = [t for t in retail if t.section == dest.section]
            if not (min(t.addr for t in section_symbols) <= dest.addr + offset
                    and dest.addr + offset + s['size'] <= max(t.end for t in section_symbols)):
                raise ValueError(f"data-base layout differs: {anchor} + {offset:#x} ({s['name']})")
            piece = next((x for x in pieces if x.kind == 'object' and s['name'] in x.names), None)
            if piece is None:
                continue  # A function-local static is outside this aggregate's accessed fields.
            decl = re.sub(r'^(?:static\s+|extern\s+)+', '', object_declaration(piece))
            decl = re.sub(r'__attribute__\s*\(\(aligned\(\d+\)\)\)', '', decl).strip()
            source_decl = decl
            if re.fullmatch(r'(?:const\s+)?(?:(?:signed|unsigned)\s+)?char\s+\w+\s*\[\s*\]', decl):
                # Initializers supply array bounds in C, but aggregate members
                # have no initializer. The compiled symbol carries that extent.
                decl = re.sub(r'\[\s*\]', f"[{s['size']}]", decl)
            if offset < cursor:
                raise ValueError(f"overlapping data-base fields: {s['name']}")
            if offset > cursor:
                fields.append(f'unsigned char sdk_padding_{cursor}[{offset - cursor}];')
            field = 'sdk_' + s['name']
            fields.append(replace_symbols(decl, {s['name']: field}) + ';')
            replacements[s['name']] = f'({local}->{field})'
            text = re.sub(re.escape('extern ' + source_decl) + r'\s*;', '', text)
            cursor = offset + s['size']
        if not fields:
            continue  # This function only references literals in the shared section.
        # Place the aggregate after its type dependencies and before function bodies.
        # Strings and typed objects can share one anchor. Give it one compatible
        # declaration and cast each view instead of declaring conflicting structs.
        # A retail anchor can have the same name as a donor object (Packet in
        # SIBios). Keep it distinct until the simultaneous symbol substitution,
        # or the anchor declaration itself becomes an aggregate field access.
        base = local + '_base'
        while base in used or base in mapping:
            base += '_'
        mapping[base] = mapping[anchor]
        decl = 'struct ' + tag + ' {\n' + '\n'.join(fields) + '\n};\nextern unsigned char ' + base + '[];\n\n'
        index = next((i for i in range(len(text)) if text.startswith('static inline ', i)), -1)
        if index < 0:
            signature = next(x.signature for x in pieces if x.kind == 'function' and rec['sdk_symbol'] in x.names)
            index = text.index(re.sub(r'^static\s+', '', signature))
        text = text[:index] + decl + text[index:]
        for piece in declarations(text):
            if piece.kind == 'function' and set(IDENT.findall(masked(piece.text))) & replacements.keys():
                body = piece.text.replace('{', '{\nstruct ' + tag + '* ' + local + ' = (struct ' + tag + '*)' + base + ';\n', 1)
                text = text.replace(piece.text, body)
        mapping.update(replacements)
    return text


def literal_storage(p: Project, rec: dict, text: str) -> str:
    """Bind SDK diagnostic strings to their byte-verified retail data layout."""
    tokens = [m[0] for m in LEXICAL.finditer(text) if m[0].startswith('"') and '.h"' not in m[0]]
    if not tokens:
        return text
    obj = source_object(p, rec)
    elf = Elf(obj.read_bytes())
    symbols = {s['name']: s for s in elf.symbols()}
    left = relocations(obj, rec['sdk_symbol'])
    right = relocations(p.target_object_for(p.resolve(rec['symbol'])), rec['symbol'])
    module = p.resolve(rec['symbol']).module
    retail = list(p.symbols(module).values())
    bases = {}
    direct = {}
    for off, (name, addend, kind) in left.items():
        s = symbols[name]
        if s['shndx'] >= len(elf.sections) or elf.sections[s['shndx']]['name'] != '.data' or off not in right:
            continue
        dest, da, _ = right[off]
        target = p.symbols(module).get(dest)
        if target is None:
            suffix = re.search(r'_([0-9A-Fa-f]{8})$', dest)
            target = next((s for s in retail if suffix and s.addr == int(suffix[1], 16)), None)
        if target:
            bases[s['shndx']] = (target.addr + da - s['value'] - addend, target.section)
            if name.startswith('@') and target.name.isidentifier():
                direct[(s['shndx'], s['value'] + addend)] = (dest, da)
    for index, (address, target_section) in bases.items():
        sec = elf.sections[index]
        data = bytes(elf.data[sec['offset']:sec['offset'] + sec['size']])
        replacements, fields, external = {}, {}, {}
        for token in tokens:
            try:
                value = ast.literal_eval(token).encode('latin1') + b'\0'
            except (ValueError, SyntaxError, UnicodeEncodeError):
                continue
            offset = data.find(value)
            if offset < 0:
                continue
            layout = p._rel_layout(module)
            regions = layout.values() if module == 'main' else [layout.get(target_section, (0, b''))]
            actual = next((raw[address + offset - base:address + offset - base + len(value)]
                           for base, raw in regions
                           if base <= address + offset and address + offset + len(value) <= base + len(raw)), None)
            if actual != value:
                # SDK releases embed their build date/time beside otherwise
                # identical diagnostics. Bind the measured retail strings only
                # when both have the same fixed-width timestamp format.
                formats = (rb'(?:Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec) [ \d]\d \d{4}\x00',
                           rb'\d{2}:\d{2}:\d{2}\x00')
                if actual is None or not any(re.fullmatch(fmt, value) and re.fullmatch(fmt, actual)
                                             for fmt in formats):
                    continue
            bound = direct.get((index, offset))
            if bound:
                dest, addend = bound
                external[token] = dest if addend == 0 else f'({dest} + {addend})'
                continue
            field = f'message_{offset:x}'
            fields[offset] = (field, len(value))
            replacements[token] = field
        if external:
            text = LEXICAL.sub(lambda m: external.get(m[0], m[0]), text)
            names = {direct[(index, data.find(ast.literal_eval(token).encode('latin1') + b'\0'))][0]
                     for token in external}
            text = ''.join(f'extern char {name}[];\n' for name in sorted(names)) + text
        if not replacements:
            continue
        anchor = next((s for s in retail if s.addr == address and s.kind == 'object'), None)
        if anchor is None or not anchor.name.isidentifier():
            raise ValueError(f'name the SDK message pool at {address:#x}')
        name = anchor.name + (f'_{anchor.addr:08X}' if anchor.scope == 'local' else '')
        tag = Path(rec['source']).stem + 'Messages'
        layout, cursor = [], 0
        for offset, (field, size) in sorted(fields.items()):
            if offset > cursor:
                layout.append(f'char padding_{cursor:x}[{offset - cursor}];')
            layout.append(f'char {field}[{size}];')
            cursor = offset + size
        decl = f'struct {tag} {{\n' + '\n'.join(layout) + f'\n}};\nextern unsigned char {name}[];\n'
        for piece in declarations(text):
            if piece.kind != 'function' or not any(t in piece.text for t in replacements):
                continue
            body = LEXICAL.sub(lambda m: f'messages->{replacements[m[0]]}' if m[0] in replacements else m[0], piece.text)
            body = body.replace('{', f'{{\nstruct {tag}* messages = (struct {tag}*){name};\n', 1)
            text = text.replace(piece.text, body)
        # All message fields are char arrays, independent of SDK type declarations.
        text = decl + '\n' + text
    return text


def format_c(text: str) -> str:
    import shutil
    formatter = shutil.which('clang-format')
    if formatter is None:
        cp = subprocess.run(['xcrun', '--find', 'clang-format'], text=True, capture_output=True)
        formatter = cp.stdout.strip() if cp.returncode == 0 else None
    if not formatter:
        raise RuntimeError('clang-format is required to format imported SDK C')
    # MWCC's absolute-declaration colon is not a bitfield. Hide it from the formatter.
    text = re.sub(r' : (FZGX_ADDR_\w+);', r' /* SDK_ABSOLUTE \1 */;', text)
    cp = subprocess.run([formatter, '--style={BasedOnStyle: LLVM, IndentWidth: 4, ColumnLimit: 100, SortIncludes: Never}'],
                        input=text, text=True, capture_output=True, check=True)
    return re.sub(r' /\* SDK_ABSOLUTE (FZGX_ADDR_\w+) \*/\s*;', r' : \1;', cp.stdout).rstrip() + '\n'


def materialize(result: dict) -> list:
    """Adapt reference C to the project's Dolphin interface; retain TU-local declarations."""
    header = {'card': 'dolphin/card/CARDPriv.h', 'os': 'dolphin/os.h',
              'exi': 'dolphin/exi/EXIPriv.h', 'si': 'dolphin/si/SIPriv.h'}.get(result['library'], 'types.h')
    if not (ROOT / 'include' / header).exists():
        raise ValueError(f'add the project-owned interface {header} before importing {result["library"]}')
    provided = set(BASE_TYPES)
    owners = {}
    shared_prototypes = set()
    for path in (ROOT / 'include/dolphin').rglob('*.h'):
        for piece in declarations(path.read_text()):
            if piece.kind == 'type':
                provided.update(piece.names)
                for name in piece.names:
                    owners[name] = path.relative_to(ROOT / 'include').as_posix()
            elif piece.kind == 'prototype':
                shared_prototypes.update(piece.names)
                for name in piece.names:
                    owners[name] = path.relative_to(ROOT / 'include').as_posix()
    output = []
    for rec in result['prepared']:
        pieces = declarations(Path(rec['path']).read_text())
        defined = set().union(*(x.names for x in pieces if x.kind == 'function'))
        used = set(IDENT.findall(masked('\n'.join(x.text for x in pieces if x.kind != 'prototype'))))
        body = []
        for piece in pieces:
            if piece.kind == 'type':
                continue
            if piece.kind == 'prototype' and (piece.names & shared_prototypes or not piece.names & used):
                continue
            text = re.sub(r'^asm\s+', '', piece.text)
            if piece.kind == 'prototype' and not piece.names & defined:
                text = re.sub(r'^static\s+', '', text)
            if Path(rec['source']).stem == 'OSAudioSystem':
                text = re.sub(r'\br3 != 42069;', '(void)(r3 != 0x8000); // Retain the mailbox halfword conversion.', text)
            if result['library'] == 'si':
                text = re.sub(r'\b0x80000001\b', '(SI_COMCSR_TCINT | SI_COMCSR_TSTART)', text)
            if piece.address is not None:
                text = text.rstrip(';') + f' : {piece.address};'
            text = re.sub(r'(?m)^(.*\bgoto\b.*)$', r'\1 // fzgx-allow: S1 SDK error cleanup path', text)
            text = re.sub(r'(?m)^(.*\bvolatile\b.*)$', r'\1 // fzgx-allow: S2 SDK asynchronous state', text)
            # This SDK revision uses the public DVDDiskID field names.
            text = re.sub(r'(->|\.)game_name\b', r'\1gameName', text)
            if piece.kind == 'function' and any(name.startswith('sdk_layout_') for name in piece.names):
                text = '#pragma section code_type ".fzgxpool"\n' + text + '\n#pragma section code_type ".text"'
            body.append(text)
        needed = set(IDENT.findall(masked('\n'.join(body)))) - provided
        selected = set()
        while True:
            new = {i for i, piece in enumerate(pieces)
                   if piece.kind == 'type' and piece.names & needed and not piece.names & provided} - selected
            if not new:
                break
            selected.update(new)
            for i in new:
                needed.update(set(IDENT.findall(masked(pieces[i].text))) - provided)
        local_types = [pieces[i].text for i in sorted(selected)]
        declared = set().union(*(x.names for x in pieces if x.kind in ('prototype', 'function'))) | shared_prototypes
        for name, prototype in {
            'memcpy': 'void* memcpy(void* dest, const void* src, size_t n);',
            'memset': 'void* memset(void* dest, int value, size_t n);',
        }.items():
            if name in used and name not in declared:
                body.insert(0, prototype)
        prefix = f'#include <{header}>\n'
        referenced = set(IDENT.findall(masked('\n'.join(local_types + body))))
        for dependency in sorted({owners[n] for n in referenced & owners.keys()} - {header}):
            prefix += f'#include <{dependency}>\n'
        if rec['absolutes']:
            prefix += '#include "sdk_addresses.h"\n'
        prefix += '\n'.join(rec.get('pragmas', [])) + '\n'
        path = Path(rec['path']).with_name(Path(rec['path']).stem + '.import.c')
        path.write_text(format_c(prefix + '\n' + '\n\n'.join(local_types + body)))
        output.append({**rec, 'path': str(path)})
    return output


def storage_variants(text: str) -> list:
    """Express retained field addresses and array bases lost by splitting an SDK TU."""
    variants = []
    retained = re.sub(r'(struct\s+\w+\s*\*)\s*(sdk_storage_\w+)\s*=', r'\1 const \2 =', text)
    if retained != text:
        # Keep the shared base across compiler-generated aggregate copies.
        variants.append(('const-storage', retained))
    pointers = dict(re.findall(r'struct (\w+)\s*\*\s*(sdk_storage_\w+)\s*=', text))
    tags = {local: tag for tag, local in pointers.items()}
    types = {}
    for path in (ROOT / 'include/dolphin').rglob('*.h'):
        for piece in declarations(path.read_text()):
            if piece.kind == 'type':
                for name in piece.names:
                    types[name] = piece.text
    pattern = r'\((sdk_storage_\w+)->(sdk_\w+)\)\.(\w+)'
    for match in re.finditer(pattern, text):
        local, member, field = match.groups()
        expr = match[0]
        if text.count(expr) < 2 or local not in tags:
            continue
        aggregate = next((p.text for p in declarations(text) if p.kind == 'type' and tags[local] in p.names), '')
        member_type = re.search(r'\b(\w+)\s+' + re.escape(member) + r'\s*;', aggregate)
        field_type = re.search(r'\b(BOOL|u32|s32|u16|s16)\s+' + re.escape(field) + r'\s*;',
                               types.get(member_type[1], '') if member_type else '')
        if not field_type:
            continue
        for byte_address in (False, True):
            typ = field_type[1]
            address = f'&{expr}'
            if byte_address:
                address = f'({typ}*)((u8*){local} + (u32)&((struct {tags[local]}*)0)->{member}.{field})'
            modified = text
            for fn in declarations(text):
                if fn.kind != 'function' or expr not in fn.text:
                    continue
                # clang-format can wrap the first access into a continuation
                # line. Initialize after the base declaration, not at the start
                # of that line, which may be inside a return or condition.
                base_decl = re.search(r'\bstruct\s+\w+\s*\*\s*' + re.escape(local) +
                                      r'\s*=[^;]+;', masked(fn.text))
                if not base_decl:
                    continue
                index = base_decl.end()
                body = (fn.text[:index] + f'\n{typ}* {field}Field = {address};\n' +
                        fn.text[index:].replace(expr, f'(*{field}Field)'))
                modified = modified.replace(fn.text, body)
            variants.append((field + ('-bytes' if byte_address else ''), modified))
    # Array fields in the original SDK are independent objects sharing a section base.
    array_pattern = r'&\((sdk_storage_\w+)->(sdk_\w+)\)\[(\w+)\]'
    modified = text
    for match in re.finditer(array_pattern, text):
        local, member, index = match.groups()
        if local not in tags:
            continue
        declaration = next((p.text for p in declarations(text) if p.kind == 'type' and tags[local] in p.names), '')
        field = re.search(r'\b(\w+)\s+' + re.escape(member) + r'\[', declaration)
        if field:
            address = f'(({field[1]}*)((u8*){local} + (u32)&((struct {tags[local]}*)0)->{member}) + {index})'
            modified = modified.replace(match[0], address)
    if modified != text:
        variants.append(('array-base', modified))
        swapped = re.sub(r'(\(sdk_storage_\w+->sdk_\w+\)\[\w+\]) \+ (\w+)', r'\2 + \1', modified)
        if swapped != modified:
            variants.append(('array-base-sum', swapped))
    return list(dict.fromkeys(variants))


def owned_bss_variant(p: Project, rec: dict) -> dict | None:
    """Keep a single SDK BSS object in C when it has an exact, unowned retail range."""
    text = Path(rec['path']).read_text()
    objects = []
    for piece in declarations(text):
        if piece.kind != 'object' or not piece.text.startswith('extern '):
            continue
        for name in piece.names:
            sym = p.find_symbol(name)
            if sym is None:
                sym = next((s for s in p.symbols('main').values() if name == f'{s.name}_{s.addr:08X}'), None)
            if sym and sym.section == '.bss' and not any(s.section == '.bss' and s.start < sym.end and sym.addr < s.end for s in p.splits('main')):
                objects.append((piece, sym))
    if len(objects) != 1:
        return None
    piece, sym = objects[0]
    # Aggregates are views across several objects; ownership is only for the native object.
    if 'struct SDK_' in piece.text:
        return None
    obj = p.build_dir / 'sdkmatch' / rec['sdk'] / Path(rec['source']).with_suffix('.o')
    elf = Elf(obj.read_bytes())
    source_name = next((n for n, dest in rec['bindings'].items() if dest in piece.names and not n.startswith('.')), None)
    original = next((s for s in elf.symbols() if s['name'] == source_name and s['size'] == sym.size), None)
    if original is None or elf.sections[original['shndx']]['name'] != '.bss':
        return None
    align = elf.sections[original['shndx']]['addralign']
    definition = piece.text.removeprefix('extern ').rstrip(';') + f' __attribute__((aligned({align})));'
    path = Path(rec['path']).with_name(Path(rec['path']).stem + '.owned.c')
    path.write_text(text.replace(piece.text, definition))
    return {**rec, 'path': str(path), 'variant': rec['variant'] + '-owned',
            'owned_bss': {'start': sym.addr, 'end': sym.end, 'align': align}}


def install_owned_bss(p: Project, rec: dict) -> None:
    owned = rec.get('owned_bss')
    if not owned:
        return
    unit = p.unit_of(p.resolve(rec['symbol']))
    conflicts = [s for s in p.splits('main') if s.section == '.bss' and s.start < owned['end'] and owned['start'] < s.end]
    if conflicts:
        raise ValueError(f'BSS range already owned: {conflicts}')
    path = p.module_config_dir('main') / 'splits.txt'
    line = f"\t.bss        start:0x{owned['start']:08X} end:0x{owned['end']:08X} align:{owned['align']}\n"
    path.write_text(path.read_text().replace(unit + ':\n', unit + ':\n' + line, 1))


def install_addresses(p: Project, records: list) -> None:
    path = p.module_config_dir('main') / 'ldscript.tpl'
    text = path.read_text()
    existing = {name: int(value, 16) for name, value in
                re.findall(r'^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;', text, re.M)}
    additions = {}
    for rec in records:
        for name, address in rec['absolutes'].items():
            if name in existing and existing[name] != address:
                raise ValueError(f'conflicting absolute binding: {name}')
            if name not in existing:
                additions[name] = address
    if additions:
        lines = '\n    /* SDK absolute globals; configure.py generates their C constants. */\n'
        lines += ''.join(f'    {name} = 0x{value:08X};\n' for name, value in sorted(additions.items()))
        text = text.replace('\n}\n\nFORCEACTIVE', lines + '}\n\nFORCEACTIVE')
        path.write_text(text)
    cp = oracle.configure(p)
    if cp.returncode:
        raise RuntimeError(cp.stdout + cp.stderr)


def finish_source(text: str) -> str:
    names = {}
    for token in IDENT.findall(masked(text)):
        if token.startswith('SDK_'):
            names[token] = re.sub(r'_+(bss|data)_0$', lambda m: m[1].capitalize(), token[4:])
        elif token.startswith('sdk_storage_'):
            names[token] = 'bss' if 'bss' in token else 'data'
        elif token.startswith('sdk_'):
            names[token] = token[4:]
        elif token.endswith('HACK'):
            names[token] = token[:-4] + 'Inline'
    for match in reversed(list(IDENT.finditer(masked(text)))):
        if match[0] in names:
            text = text[:match.start()] + names[match[0]] + text[match.end():]
    text = format_c(text)
    text = re.sub(r'(?m)^([^\n]*\bgoto\s+\w+\s*;[^\n]*)$',
                  lambda m: m[0] if '//' in m[0] else m[0] + ' // Preserve the verified SDK control flow.', text)
    text = re.sub(r'(?m)^(.*\b(?:id|cid)\s*[!=]=\s*0x80000004.*)$',
                  r'\1 // fzgx-allow: A1 CARD device identifier, not a pointer', text)
    return re.sub(r'(?m)^(.*\bvolatile\b.*)$', r'// Hardware or OS state can change asynchronously.\n\1', text)


def run(p: Project, library: str, do_submit: bool = True) -> dict:
    result = prepare(p, library)
    records = materialize(result)
    variants = []
    for rec in records:
        for label, body in storage_variants(Path(rec['path']).read_text()):
            path = Path(rec['path']).with_name(Path(rec['path']).stem + '.' + label + '.c')
            path.write_text(format_c(body))
            variants.append({**rec, 'path': str(path), 'variant': rec.get('variant', '') + '-' + label})
    records += variants
    records += [v for rec in records if rec.get('variant') == 'direct'
                if (v := owned_bss_variant(p, rec)) is not None]
    install_addresses(p, records)
    result.update(matched=[], still=[], bytes=0)
    groups = defaultdict(list)
    for rec in records:
        groups[(rec['sdk'], rec['mw'], rec.get('variant', ''))].append(rec)
    chosen = set()
    for (_, mw, _), group in groups.items():
        group = [r for r in group if r['symbol'] not in chosen]
        checks = oracle.check_many(p, [(r['symbol'], Path(r['path'])) for r in group],
                                   max_diff_lines=10, mw_version=mw, extra_cflags=FLAGS)
        for rec in group:
            check = checks[rec['symbol']]
            reason = oracle.unit_fully_matches(check)
            if reason:
                result['still'].append({**rec, 'reason': reason, 'check': check.to_json()})
                continue
            if do_submit:
                work = p.work_path(rec['symbol'])
                work.parent.mkdir(parents=True, exist_ok=True)
                work.write_text(finish_source(Path(rec['path']).read_text()))
                accepted = api.submit(p, rec['symbol'], agent='sdkimport', harness='fzgx', model='sdkimport',
                                      message=f"SDK C import: {rec['sdk']}/{rec['source']}:{rec['sdk_symbol']}",
                                      mw_version=mw, extra_cflags=FLAGS)
                if not accepted.get('ok'):
                    result['still'].append({**rec, 'reason': accepted})
                    continue
                install_owned_bss(p, rec)
            chosen.add(rec['symbol'])
            result['bytes'] += rec['size']
            sdk = ROOT / 'build/tools' / rec['sdk']
            revision = subprocess.run(['git', 'rev-parse', 'HEAD'], cwd=sdk, text=True,
                                      capture_output=True, check=True).stdout.strip()
            result['matched'].append({**rec, 'revision': revision, 'submitted': do_submit})
            print(f"sdkimport: {rec['symbol']} ({rec['size']} bytes)", flush=True)
    result['still'] = [r for r in result['still'] if r['symbol'] not in chosen]
    report = STATE_DIR / 'sdkimport' / library / 'result.json'
    report.write_text(json.dumps(result, indent=2) + '\n')
    if do_submit and chosen:
        dest = ROOT / 'state/sdkimports' / (library + '.json')
        dest.parent.mkdir(parents=True, exist_ok=True)
        old = json.loads(dest.read_text()) if dest.exists() else {}
        for rec in result['matched']:
            old[rec['symbol']] = {k: v for k, v in rec.items() if k not in ('path', 'submitted')}
        dest.write_text(json.dumps(old, indent=2, sort_keys=True) + '\n')
    return {k: v for k, v in result.items() if k != 'prepared'}


def consolidate(p: Project, library: str) -> dict:
    """Collapse only source files whose emitted functions all have proven retail identities."""
    from . import collapse
    by_addr = {s.addr: s for s in p.functions('main')}
    result = {'collapsed': [], 'partial': [], 'failed': []}
    done = set()
    for sdk in ('mkdd', 'tww'):
        data = json.loads((ROOT / 'state/seeds' / f'sdkmatch_{sdk}.json').read_text())
        sources = sorted({s for hit in data['hits'] for s in hit['sources'] if f'/{library}/' in s})
        for source in sources:
            stem = Path(source).stem
            if stem in done:
                continue
            hits = {h['sdk'][0]: by_addr[h['addr']] for h in data['hits']
                    if source in h['sources'] and h['addr'] in by_addr}
            obj = p.build_dir / 'sdkmatch' / sdk / Path(source).with_suffix('.o')
            functions = sorted((s for s in Elf(obj.read_bytes()).symbols()
                                if s['info'] & 15 == 2 and s['size'] and s['shndx']), key=lambda s: s['value'])
            missing = [s['name'] for s in functions if s['name'] not in hits]
            if missing:
                result['partial'].append({'sdk': sdk, 'source': source, 'missing': missing})
                continue
            members = [hits[s['name']] for s in functions]
            units = p.load_units()
            old = [u for u in units if any(s.name in u['symbols'] for s in members)]
            if len(old) == 1 and old[0].get('collapsed'):
                done.add(stem)
                continue
            if len(old) != len(members) or any(u['status'] != 'matching' or u.get('asm') for u in old):
                continue
            lo, hi = min(s.addr for s in members), max(s.end for s in members)
            if {s.name for s in p.functions('main') if lo <= s.addr < hi} != {s.name for s in members}:
                result['failed'].append({'source': source, 'error': 'retail functions are not contiguous'})
                continue
            pieces = declarations(preprocess(ROOT / 'build/tools' / sdk, source, data['mw']))
            mapping = {}
            rec = dict(sdk=sdk, source=source, mw=data['mw'], symbol=members[0].name,
                       sdk_symbol=functions[0]['name'], size=hi-lo)
            try:
                for fn in functions:
                    m = bindings(p, {**rec, 'symbol': hits[fn['name']].name, 'sdk_symbol': fn['name']})
                    for name, target in m.items():
                        if name in mapping and mapping[name] != target:
                            raise ValueError(f'inconsistent whole-TU binding: {name}')
                        mapping[name] = target
                bodies = [x for x in pieces if x.kind == 'function' and x.names & hits.keys()]
                combined = Piece('function', set(), '\n'.join(x.text for x in bodies))
                types, externs = dependency_closure(pieces, combined, mapping)
                text = '\n\n'.join(types + externs + [re.sub(r'^static\s+', '', x.text) for x in bodies])
                text, absolutes = absolute_declarations(pieces, text)
                text = shared_storage(p, rec, pieces, text, mapping)
                path = STATE_DIR / 'sdkimport' / library / f'{stem}.{sdk}.whole.c'
                path.write_text(replace_c_symbols(text, mapping))
                pragmas = [source_pragmas(sdk, source, fn['name']) for fn in functions]
                if any(x != pragmas[0] for x in pragmas):
                    raise ValueError('source has mixed compiler pragmas')
                row = {**rec, 'path': str(path), 'bindings': mapping, 'absolutes': absolutes, 'pragmas': pragmas[0]}
                imported = materialize({'library': library, 'prepared': [row]})[0]
                Path(imported['path']).write_text(finish_source(Path(imported['path']).read_text()))
                install_addresses(p, [row])
                compiled = path.with_suffix('.o')
                cp = oracle.compile_source(p, 'main', Path(imported['path']), compiled, data['mw'], FLAGS)
                if cp.returncode:
                    raise ValueError((cp.stdout + cp.stderr)[-1000:])
                for sym in members:
                    check = oracle._diff(p, 'main', sym.name, '', 5,
                                         target=p.target_object_for(sym), base=compiled)
                    check.uncarved = True
                    if oracle.unit_fully_matches(check):
                        raise ValueError(f'whole-TU mismatch: {sym.name}: {check.percent}: {check.diff}')
            except (ValueError, KeyError, StopIteration) as e:
                result['failed'].append({'source': source, 'error': str(e)})
                continue
            tu_source = 'dol/' + stem + '.c'
            tu_path = ROOT / 'src' / tu_source
            if tu_path.exists() and tu_source not in {u['source'] for u in old}:
                result['failed'].append({'source': source, 'error': 'TU destination already exists'})
                continue
            previous_source = tu_path.read_text() if tu_path.exists() else None
            tpath = p.module_config_dir('main') / 'tus.json'
            previous_tus = tpath.read_bytes() if tpath.exists() else None
            tus = json.loads(tpath.read_text()) if tpath.exists() else {'module': 'main', 'tus': []}
            entry = {'file': stem + '.c', 'text': [lo, hi], 'functions': [s.name for s in members],
                     'sdk': sdk, 'source': source}
            tus['tus'] = [t for t in tus['tus'] if t['file'] != entry['file']] + [entry]
            tpath.write_text(json.dumps(tus, indent=2) + '\n')
            tu_path.write_text(Path(imported['path']).read_text())
            changed = [dict(u, tu=tu_source, mw_version=data['mw'], extra_cflags=FLAGS.split()) if u in old else u for u in units]
            p.save_units(changed)
            collapsed = collapse.collapse(p, tu_source)
            if not collapsed['ok']:
                p.save_units(units)
                if previous_tus is None:
                    tpath.unlink(missing_ok=True)
                else:
                    tpath.write_bytes(previous_tus)
                if previous_source is None:
                    tu_path.unlink()
                else:
                    tu_path.write_text(previous_source)
                oracle.configure(p)
                oracle.relink(p)
                result['failed'].append({'source': source, 'error': collapsed})
                continue
            ledger = Ledger()
            for sym in members:
                ledger.db.execute('UPDATE functions SET unit=? WHERE symbol=?', (tu_source, p.key(sym)))
            for u in old:
                if u['source'] != tu_source:
                    (ROOT / 'src' / u['source']).unlink(missing_ok=True)
            result['collapsed'].append({'source': source, 'sdk': sdk, 'tu': tu_source,
                                        'functions': len(members), 'bytes': hi-lo})
            done.add(stem)
            print(f'sdkimport: collapsed {tu_source} ({len(members)} functions)', flush=True)
    (STATE_DIR / 'sdkimport' / library / 'consolidated.json').write_text(json.dumps(result, indent=2) + '\n')
    return result
