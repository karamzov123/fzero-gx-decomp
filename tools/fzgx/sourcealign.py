"""Find source relatives despite changed layouts, registers, or instruction scheduling.

Discovery scores never certify a match. Imported candidates still require the object
oracle and the ordinary submit/16-target verification path.
"""

from __future__ import annotations

import difflib
import json
import math
import struct
import re
import shlex
import hashlib
import subprocess
from fractions import Fraction
from collections import Counter, defaultdict
from pathlib import Path

from .ledger import Ledger
from .poolfix import Elf, masked_code
from .project import ROOT, STATE_DIR, Project
from . import api, oracle, sdkimport, sdkmatch


def source_license(sdk: str) -> dict:
    root = ROOT / 'build/tools' / sdk
    for name in ('LICENSE', 'LICENSE.md', 'LICENSE.MD', 'LICENSE.txt', 'COPYING'):
        path = root / name
        if path.is_file():
            body = path.read_bytes()
            if b'CC0 1.0 Universal' in body and b'Statement of Purpose' in body:
                return dict(spdx='CC0-1.0', path=name, sha256=hashlib.sha256(body).hexdigest())
    raise ValueError(f'{sdk}: no supported source license; excluded from reuse')


def instructions(obj: Path, minimum: int = 256) -> dict:
    elf = Elf(obj.read_bytes())
    sections = {s['index']: s for s in elf.sections if s['name'] in ('.text', '.init')}
    buffers = {i: masked_code(elf, s) for i, s in sections.items()}
    result = {}
    for symbol in elf.symbols():
        if symbol['info'] & 15 != 2 or symbol['shndx'] not in buffers or symbol['size'] < minimum:
            continue
        data = buffers[symbol['shndx']][symbol['value']:symbol['value'] + symbol['size']]
        if len(data) == symbol['size'] and len(data) % 4 == 0:
            result[symbol['name']] = struct.unpack('>' + 'I' * (len(data) // 4), data)
    return result


def operation(word: int) -> int:
    op = word >> 26
    if op in (19, 31):
        return word & 0xFC0007FF
    if op in (4, 59, 63):
        # A-form arithmetic uses the upper five XO bits as a third register.
        # X-form moves, compares and paired merges retain their full XO.
        arithmetic = {18, 20, 21, 22, 23, 24, 25, 26, 28, 29, 30, 31}
        if op == 4:
            arithmetic = {10, 11, 12, 13, 14, 15, 18, 20, 21, 23, 24, 25, 26, 28, 29, 30, 31}
        return word & (0xFC00003F if (word >> 1) & 31 in arithmetic else 0xFC0007FF)
    if op == 16:
        return word & 0xFFE00003
    if op == 18:
        return word & 0xFC000003
    return word & 0xFC000001 if op in (20, 21, 23) else word & 0xFC000000


def grams(words: tuple) -> Counter:
    ops = tuple(map(operation, words))
    return Counter(zip(ops, ops[1:], ops[2:], ops[3:]))


def operand_shape(word: int) -> int:
    op = word >> 26
    if op in (7, 8, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, *range(32, 56)):
        return word & 0xFFFF0000
    if op == 16:
        return word & 0xFFFF0003
    if op == 18:
        return word & 0xFC000003
    return word


def aligned_words(source: tuple, target: tuple) -> dict:
    # Register operands disambiguate repeated loads and calls once a source
    # relative has been identified. Opcode-only alignment is for discovery.
    match = difflib.SequenceMatcher(None, tuple(map(operand_shape, source)),
                                   tuple(map(operand_shape, target)), autojunk=False)
    return {a + i: b + i for a, b, count in match.get_matching_blocks() for i in range(count)}


def call_bindings(left: dict, right: dict, known: dict) -> dict:
    source = [(off, name) for off, (name, addend, kind) in sorted(left.items())
              if kind == 10 and addend == 0 and not re.fullmatch(r'_(?:save|rest)[gf]pr_\d+', name)]
    target = [(off, name) for off, (name, addend, kind) in sorted(right.items()) if kind == 10 and addend == 0]
    match = difflib.SequenceMatcher(None, [known.get(name, 'source:' + name) for _, name in source],
                                   [name for _, name in target], autojunk=False)
    proposals = defaultdict(set)
    a_start = b_start = 0
    for a, b, size in match.get_matching_blocks():
        if a - a_start == b - b_start:
            for (_, name), (_, dest) in zip(source[a_start:a], target[b_start:b]):
                proposals[name].add(dest)
        a_start, b_start = a + size, b + size
    return {name: next(iter(values)) for name, values in proposals.items() if len(values) == 1}


def callee_bindings(p: Project, module: str, left: dict, right: dict, donors: dict) -> dict:
    source_names = {name for name, _, kind in left.values() if kind == 10 and name in donors}
    targets = {}
    objects = {}
    for name, _, kind in right.values():
        sym = sdkimport.retail_symbol(p, module, name) or p.resolve(name)
        if kind != 10 or sym is None or sym.kind != 'function' or sym.size < 16:
            continue
        obj = p.target_object_for(sym)
        if obj:
            if obj not in objects:
                objects[obj] = instructions(obj, 16)
            if sym.name in objects[obj]:
                targets[name] = objects[obj][sym.name]
    scores = []
    for source in source_names:
        for name, target in targets.items():
            best = 0
            for donor in donors[source]:
                if not 0.7 * len(target) <= len(donor) <= 1.4 * len(target):
                    continue
                score = difflib.SequenceMatcher(None, tuple(map(operand_shape, donor)),
                                               tuple(map(operand_shape, target)), autojunk=False).ratio()
                best = max(best, score)
            if best >= 0.9:
                scores.append((best, source, name))
    result = {}
    for score, source, name in sorted(scores, reverse=True):
        competitors = [value for value, other, dest in scores if (other == source or dest == name)
                       and (other, dest) != (source, name)]
        if not competitors or score - max(competitors) >= 0.05:
            result[source] = name
    return result


def proven_bindings(p: Project, rec: dict) -> dict:
    path = STATE_DIR / 'sourcealign/matches.json'
    if not path.exists():
        return {}
    candidates = defaultdict(set)
    module = p.resolve(rec['symbol']).module
    for result in json.loads(path.read_text()).values():
        if result['sdk'] != rec['sdk'] or p.resolve(result['symbol']).module != module:
            continue
        candidates[result['sdk_symbol']].add(result['symbol'])
        if result['source'] == rec['source']:
            for name, target in result['bindings'].items():
                candidates[name].add(target)
    return {name: next(iter(targets)) for name, targets in candidates.items() if len(targets) == 1}


def extra_calls(text: str, names: set) -> tuple:
    """A source-version candidate: omit standalone void calls absent from the aligned call graph."""
    void = set()
    for piece in sdkimport.declarations(text):
        if piece.kind == 'prototype' and re.match(r'^(?:extern\s+)?void\s+\w+\s*\(', piece.text):
            void.update(piece.names & names)
    removed = []
    code = sdkimport.masked(text)
    spans = []
    for match in re.finditer(r'(?m)^[ \t]*(\w+)\s*\(', code):
        if match[1] not in void:
            continue
        depth, end = 1, match.end()
        while end < len(code) and depth:
            depth += (code[end] == '(') - (code[end] == ')')
            end += 1
        tail = re.match(r'[ \t]*;', code[end:])
        if tail:
            spans.append((match.start(), end + tail.end()))
            removed.append(match[1])
    for start, end in reversed(spans):
        text = text[:start] + text[end:]
    return text, removed


def catalog(p: Project, minimum: int) -> list:
    rows = []
    seen = set()
    for obj in sorted((p.build_dir / 'sdkmatch').rglob('*.o')):
        relative = obj.relative_to(p.build_dir / 'sdkmatch')
        sdk = relative.parts[0]
        if sdk == 'libs':
            continue  # Old cache without compiler provenance.
        root = ROOT / 'build/tools' / ('smb-decomp' if sdk == 'smb-132' else sdk)
        try:
            source_license(root.name)
        except ValueError:
            continue
        source = Path(*relative.parts[1:]).with_suffix('.c')
        stamp = obj.with_suffix('.command.json')
        if not (root / source).exists():
            continue
        if stamp.exists():
            command = json.loads(stamp.read_text())
            compiler = Path(command[1]).parent
            mw = str(compiler.relative_to(ROOT / 'build/compilers'))
        else:
            seed = ROOT / 'state/seeds' / f'sdkmatch_{sdk}.json'
            if sdk == 'smb-132':
                mw = 'GC/1.3.2'
            elif seed.exists():
                mw = json.loads(seed.read_text())['mw']
            else:
                continue
        for name, words in instructions(obj, minimum).items():
            identity = (name, words)
            if identity in seen:
                continue
            seen.add(identity)
            rows.append(dict(sdk=root.name, source=str(source), object=str(obj), sdk_symbol=name,
                             mw=mw, flags=source_flags(root.name, str(source)), words=words))
    root = ROOT / 'build/tools/mk-deception'
    sources = {s.stem: s for s in (root / 'src/libmwsfdg').rglob('*.c')}
    for tag, flags in [('default', ''), ('stmw', '-use_lmw_stmw on')]:
        for obj in sorted((STATE_DIR / 'cri' / tag).glob('*.o')):
            if obj.stem not in sources:
                continue
            for name, words in instructions(obj, minimum).items():
                identity = (name, words)
                if identity in seen:
                    continue
                seen.add(identity)
                rows.append(dict(sdk=root.name, source=str(sources[obj.stem].relative_to(root)),
                                 object=str(obj), sdk_symbol=name, mw='GC/1.3.2', flags=flags, words=words))
    manifest = STATE_DIR / 'sourcealign/libraries.json'
    if manifest.exists():
        for entry in json.loads(manifest.read_text()):
            try:
                source_license(entry['sdk'])
            except ValueError:
                continue
            for name, words in instructions(Path(entry['object']), minimum).items():
                identity = (name, words)
                if identity not in seen:
                    seen.add(identity)
                    rows.append(entry | dict(sdk_symbol=name, words=words))
    return rows


def source_flags(sdk: str, source: str) -> str:
    if sdk == 'mk-deception':
        return ''
    flags = sdkmatch.SMB_FLAGS if sdk == 'smb-decomp' else sdkmatch.RUNTIME_FLAGS if any(
        name in source for name in ('PowerPC_EABI', 'runtime_libs', 'MetroTRK')) else sdkmatch.DOLPHIN_FLAGS
    return shlex.join(flags)


def compile_library(p: Project, sdk: str, roots: list, functions=False) -> dict:
    source_license(sdk)
    root = ROOT / 'build/tools' / sdk
    sources = sorted({source for relative in roots for source in
                      ([(root / relative)] if (root / relative).is_file() else (root / relative).rglob('*.c'))})
    if not sources:
        raise ValueError('no SDK C sources in the requested roots')
    directory = STATE_DIR / 'sourcealign/libraries' / sdk
    records, failures = [], []
    # the DOL's AX/MIX/DVD-era library functions carry the MWCC 1.1 prologue order
    for mw in ('GC/1.2.5n', 'GC/1.3.2', 'GC/1.1'):
        origins = {source: source for source in sources}
        prepared = sources
        if functions:
            prepared, origins = [], {}
            for source in sources:
                relative = str(source.relative_to(root))
                try:
                    pieces = sdkimport.declarations(sdkimport.preprocess(root, relative, mw))
                except (ValueError, RuntimeError, SyntaxError) as error:
                    failures.append(dict(source=relative, error=str(error)))
                    continue
                names = set().union(*(piece.names for piece in pieces if piece.kind == 'function'))
                output = directory / 'functions' / mw.replace('/', '_') / source.relative_to(root).with_suffix('')
                output.mkdir(parents=True, exist_ok=True)
                for name in sorted(names):
                    try:
                        body = source_body(pieces, name, names - {name})
                    except (ValueError, StopIteration):
                        continue
                    path = output / (name + '.c')
                    path.write_text(body)
                    prepared.append(path)
                    origins[path] = source
        compiler_failed = False
        for module in ('main', 'movie_module'):
            if compiler_failed:
                break
            for stmw in (False, True):
                flags = f'-sdata {8 if module == "main" else 0} -sdata2 {8 if module == "main" else 0}'
                flags += ' -use_lmw_stmw ' + ('on' if stmw else 'off')
                if not functions:
                    flags += ' ' + shlex.join(sdkimport.preprocessor_flags(root))
                tag = mw.replace('/', '_') + '_' + module + ('_stmw' if stmw else '')
                output = directory / tag
                if functions:
                    output /= 'functions'
                groups = []
                for source in prepared:
                    group = next((g for g in groups if all(s.stem != source.stem for s in g)), None)
                    if group is None:
                        group = []
                        groups.append(group)
                    group.append(source)
                objects = {}
                for i, group in enumerate(groups):
                    objects.update(oracle.compile_many(p, module, group, output / str(i), mw, flags,
                                                       include_dirs=None if functions else sdkimport.include_directories(root)))
                for source, obj in objects.items():
                    records.append(dict(sdk=sdk, source=str(origins[source].relative_to(root)), object=str(obj), mw=mw, flags=flags,
                                        mode='functions' if functions else 'files'))
                failures.append(dict(profile=tag, failed=[str(s) for s in prepared if s not in objects]))
                print(tag, len(objects), '/', len(prepared), 'compiled', flush=True)
                if not objects:
                    compiler_failed = True
                    break
    manifest = STATE_DIR / 'sourcealign/libraries.json'
    previous = json.loads(manifest.read_text()) if manifest.exists() else []
    keys = {(r['sdk'], r['source'], r['mw'], r['flags'], r.get('mode', 'files')) for r in records}
    previous = [r for r in previous if (r['sdk'], r['source'], r['mw'], r['flags'], r.get('mode', 'files')) not in keys]
    manifest.write_text(json.dumps(previous + records, indent=2) + '\n')
    return dict(sources=len(sources), objects=len(records), profiles=failures)


def discover(p: Project, minimum: int = 256, roots=(), rel_only=False) -> dict:
    donors = catalog(p, minimum)
    if roots:
        donors = [row for row in donors if any(Path(row['source']).is_relative_to(root) for root in roots)]
    index = defaultdict(list)
    for i, row in enumerate(donors):
        for gram, count in grams(row['words']).items():
            index[gram].append((i, count))
    weights = {g: math.log1p(len(donors) / len(rows)) for g, rows in index.items()}
    totals = [sum(weights[g] * n for g, n in grams(row['words']).items()) for row in donors]
    targets = defaultdict(dict)
    ledger = Ledger()
    for module in p.modules:
        if rel_only and module == 'main':
            continue
        for sym in p.functions(module):
            row = ledger.get(p.key(sym))
            if sym.size >= minimum and row and row['status'] == 'unmatched':
                obj = p.target_object_for(sym)
                if obj:
                    targets[obj][sym.name] = sym
    results = []
    count = 0
    for obj, names in targets.items():
        for name, words in instructions(obj, minimum).items():
            if name not in names:
                continue
            count += 1
            hits = defaultdict(float)
            query = grams(words)
            total = sum(weights.get(g, math.log1p(len(donors))) * n for g, n in query.items())
            for gram, n in query.items():
                for i, other in index.get(gram, []):
                    if 0.7 * len(words) <= len(donors[i]['words']) <= 1.4 * len(words):
                        hits[i] += weights[gram] * min(n, other)
            ranked = sorted(((2 * overlap / (total + totals[i]), i) for i, overlap in hits.items()), reverse=True)[:8]
            candidates = []
            ops = tuple(map(operation, words))
            for overlap, i in ranked:
                if overlap < 0.65:
                    break
                donor = donors[i]
                other = tuple(map(operation, donor['words']))
                matcher = difflib.SequenceMatcher(None, other, ops, autojunk=False)
                score = matcher.ratio()
                if score < 0.8:
                    continue
                candidates.append({k: v for k, v in donor.items() if k != 'words'} | dict(
                    score=score, overlap=overlap, source_size=len(other) * 4,
                    aligned=[[a * 4, b * 4, n * 4] for a, b, n in matcher.get_matching_blocks() if n]))
            if candidates:
                candidates.sort(key=lambda r: (-r['score'], -r['overlap']))
                sym = names[name]
                results.append(dict(symbol=p.key(sym), module=sym.module, size=sym.size, candidates=candidates))
    results.sort(key=lambda r: -r['size'])
    out = dict(donors=len(donors), targets=count, functions=len(results), bytes=sum(r['size'] for r in results),
               roots=list(roots), rel_only=rel_only, results=results)
    directory = STATE_DIR / 'sourcealign'
    directory.mkdir(exist_ok=True)
    (directory / 'discovery.json').write_text(json.dumps(out, indent=2) + '\n')
    return out


def source_body(pieces: list, name: str, external: set) -> str:
    function = next(x for x in pieces if x.kind == 'function' and name in x.names)
    # Calls remain external while compiling layout probes; do not pull in callee
    # bodies or their unrelated data layouts merely because their C is available.
    mapped = {n: n for n in external}
    types, externs = sdkimport.dependency_closure(pieces, function, mapped)
    for piece in pieces:
        if (piece.kind == 'object' and '=' in piece.text and re.search(r'\bconst\b', piece.text)
                and not re.search(r'[\[*]', piece.text.split('=', 1)[0]) and not piece.names & external):
            declaration = 'extern ' + re.sub(r'^(?:static\s+|extern\s+)+', '', piece.text.split('=', 1)[0].strip()) + ';'
            externs = [piece.text if item == declaration else item for item in externs]
    types = [t for t in types if not any(x.names & sdkimport.BASE_TYPES and x.text == t for x in pieces)]
    signature = re.sub(r'^(?:static\s+|inline\s+)+', '', function.signature) + ';'
    text = '#include "types.h"\n\n' + '\n\n'.join(types + [signature] + externs + [re.sub(r'^static\s+', '', function.text)]) + '\n'
    text = re.sub(r'(?m)^(.*\bDSPSendMailToDSP\(0x80F30000\s*\|[^;]+;)',
                  r'\1 // fzgx-allow: A1 DSP mailbox command, not an address', text)
    if re.search(r'\basm\b', sdkimport.masked(text)):
        raise ValueError('source depends on inline assembly')
    return text


def padding_sites(text: str) -> list:
    sites = []
    accessed = set(re.findall(r'(?:->|\.)\s*(\w+)', sdkimport.masked(text)))
    start = 0
    for piece in sdkimport.declarations(text):
        location = text.find(piece.text, start)
        if location < 0:
            continue
        start = location + len(piece.text)
        if piece.kind != 'type':
            continue
        for match in re.finditer(r'\b((?:sdk_)?(?:reserved|unknown|padding|pad)\w*)\s*\[\s*(0[xX][\da-fA-F]+|\d+)\s*\]', piece.text):
            value = int(match[2], 0)
            if value > 0:
                sites.append(dict(start=location + match.start(2), end=location + match.end(2), value=value,
                                  field=match[1], type=sorted(piece.names), step=4))
        if re.search(r'\bstruct\b[^;{]*\{', piece.text):
            for match in re.finditer(r'(?m)^[ \t]*[^;{}\n]+\b(\w+)\s*(?:\[[^;\]]*\]\s*)*;', piece.text):
                if match[1] in accessed:
                    sites.append(dict(start=location + match.start(), end=location + match.start(), value=0,
                                      field=match[1], type=sorted(piece.names), step=1, insert=True))
    return sites


def render_site(site: dict, value: int) -> str:
    if site.get('insert'):
        return f'unsigned char sdk_padding_before_{site["field"]}[{value}];\n' if value else ''
    return str(value)


def solve(equations: list, variables: int, order=None) -> list:
    """Solve measured affine offset constraints; unobserved dimensions stay unchanged."""
    rows = [[Fraction(v) for v in coefficients] + [Fraction(value)] for coefficients, value in equations]
    pivot = 0
    columns = []
    # A later padding member is the narrowest explanation for a changed field
    # offset. Prefer it over moving all earlier, unobserved members of the type.
    for column in order if order is not None else reversed(range(variables)):
        found = next((i for i in range(pivot, len(rows)) if rows[i][column]), None)
        if found is None:
            continue
        rows[pivot], rows[found] = rows[found], rows[pivot]
        scale = rows[pivot][column]
        rows[pivot] = [x / scale for x in rows[pivot]]
        for i in range(len(rows)):
            if i != pivot and rows[i][column]:
                factor = rows[i][column]
                rows[i] = [x - factor * y for x, y in zip(rows[i], rows[pivot])]
        columns.append(column)
        pivot += 1
        if pivot == len(rows):
            break
    if any(not any(row[:-1]) and row[-1] for row in rows):
        raise ValueError('inconsistent layout constraints')
    result = [Fraction(0)] * variables
    for row, column in zip(rows, columns):
        result[column] = row[-1]
    return result


def layout(p: Project, rec: dict, text: str, directory: Path) -> tuple:
    """Perturb C padding and let MWCC identify the accesses each field controls."""
    directory.mkdir(parents=True, exist_ok=True)
    name, module = rec['sdk_symbol'], p.resolve(rec['symbol']).module
    baseline = directory / 'baseline.c'
    baseline.write_text(text)
    sites = padding_sites(text)
    sources = [baseline]
    for i, site in enumerate(sites):
        source = directory / f'padding_{i}.c'
        source.write_text(text[:site['start']] + render_site(site, site['value'] + site['step']) + text[site['end']:])
        sources.append(source)
    objects = oracle.compile_many(p, module, sources, directory / 'obj', rec['mw'], rec.get('flags') or None)
    if baseline not in objects:
        raise ValueError(f'baseline does not compile: {directory / "obj"}')
    base = instructions(objects[baseline], 0)[name]
    target = instructions(p.target_object_for(p.resolve(rec['symbol'])), 0)[p.resolve(rec['symbol']).name]
    pairs = aligned_words(base, target)
    probes = []
    active = []
    for source, site in zip(sources[1:], sites):
        if source not in objects:
            continue
        words = instructions(objects[source], 0).get(name, ())
        if len(words) != len(base) or any((a ^ b) & 0xFFFF0000 for a, b in zip(base, words)):
            continue
        probes.append(words)
        active.append(site)
    equations = []
    evidence = []
    confidence = {}
    run = []
    for off, to in sorted(pairs.items()):
        if run and (off != run[-1] + 1 or to != pairs[run[-1]] + 1):
            confidence.update({i: len(run) for i in run})
            run = []
        run.append(off)
    confidence.update({i: len(run) for i in run})
    for off, to in pairs.items():
        word, actual = base[off], target[to]
        op = word >> 26
        # Offset changes in arithmetic/addressing instructions, excluding branches
        # and relocated symbols. The final recompile checks all other differences.
        if op not in (7, 10, 11, 12, 13, 14, 15, *range(32, 56)):
            continue
        if (word ^ actual) & 0xFFFF0000:
            continue
        coefficients = [Fraction((probe[off] & 65535) - (word & 65535), site['step']) for probe, site in zip(probes, active)]
        if not any(coefficients):
            continue
        delta = (actual & 65535) - (word & 65535)
        evidence.append(dict(source_offset=off * 4, target_offset=to * 4, delta=delta,
                             confidence=confidence[off], coefficients=list(map(str, coefficients))))
    groups = defaultdict(lambda: defaultdict(list))
    for row in evidence:
        groups[tuple(row['coefficients'])][row['delta']].append(row)
    for coefficients, values in groups.items():
        # Repeated allocator/error blocks can have identical instructions but
        # different meanings. Prefer the offset supported by the longest aligned
        # context, then verify even the discarded observations in the recompile.
        delta = max(values, key=lambda value: (sum(r['confidence'] for r in values[value]),
                                               len(values[value]), value == 0,
                                               -min(abs(r['target_offset'] - r['source_offset']) for r in values[value])))
        equations.append(([Fraction(v) for v in coefficients], delta))
    solutions = []
    (directory / 'constraints.json').write_text(json.dumps(dict(sites=active, evidence=evidence), indent=2) + '\n')
    orders = [sorted(range(len(active)), key=lambda i: (-active[i]['value'], -i)),
              list(reversed(range(len(active)))), list(range(len(active)))]
    for order in orders:
        values = solve(equations, len(active), order)
        if all(d.denominator == 1 and s['value'] + d >= int(not s.get('insert')) for s, d in zip(active, values)):
            solutions.append(values)
    if not solutions:
        raise ValueError('layout constraints require nonpositive or fractional padding')
    values = min(solutions, key=lambda values: (sum(abs(d) for d in values), sum(bool(d) for d in values)))
    changes = []
    for site, delta in zip(active, values):
        if delta.denominator != 1 or site['value'] + delta < int(not site.get('insert')):
            raise ValueError(f'nonpositive or fractional padding: {site["field"]} {delta}')
        if delta:
            changes.append(site | dict(new=site['value'] + int(delta)))
    for site in sorted(changes, key=lambda s: -s['start']):
        text = text[:site['start']] + render_site(site, site['new']) + text[site['end']:]
    (directory / 'layout.json').write_text(json.dumps(dict(changes=changes, evidence=evidence), indent=2) + '\n')
    candidate = directory / 'adapted.c'
    candidate.write_text(text)
    compiled = oracle.compile_many(p, module, [candidate], directory / 'adapted', rec['mw'], rec.get('flags') or None)
    if candidate not in compiled:
        raise ValueError('recovered layout does not compile')
    words = instructions(compiled[candidate], 0)[name]
    score = oracle.word_score(list(target), list(words))[0]
    return text, compiled[candidate], score, changes


def constants(p: Project, rec: dict, text: str, obj: Path, directory: Path) -> tuple:
    """Infer literal corrections from measured instruction sensitivity, without a spelling sweep."""
    sym = p.resolve(rec['symbol'])
    base = instructions(obj, 0)[rec['sdk_symbol']]
    target = instructions(p.target_object_for(sym), 0)[sym.name]
    pairs = aligned_words(base, target)
    directory.mkdir(parents=True, exist_ok=True)
    sites, sources = [], []
    cursor = 0
    for piece in sdkimport.declarations(text):
        offset = text.find(piece.text, cursor)
        if offset < 0:
            continue
        cursor = offset + len(piece.text)
        if piece.kind != 'function':
            continue
        code = sdkimport.masked(piece.text)
        for match in re.finditer(r'(?<![\w.])(?:0[xX][\da-fA-F]+|\d+)(?:[uUlL]*)\b(?!\.)', code):
            token = match[0]
            value = int(re.sub(r'[uUlL]+$', '', token), 0)
            if value >= 0xFFFFFFFF:
                continue
            start, end = offset + match.start(), offset + match.end()
            site = dict(start=start, end=end, value=value, suffix=re.search(r'[uUlL]*$', token)[0])
            path = directory / f'literal_{len(sites)}.c'
            path.write_text(text[:start] + str(value + 1) + site['suffix'] + text[end:])
            sites.append(site)
            sources.append(path)
    objects = oracle.compile_many(p, sym.module, sources, directory / 'obj', rec['mw'], rec.get('flags') or None) if sources else {}
    proposals = []
    for site, path in zip(sites, sources):
        if path not in objects:
            continue
        words = instructions(objects[path], 0).get(rec['sdk_symbol'], ())
        if len(words) != len(base):
            continue
        affected = [i for i, (a, b) in enumerate(zip(base, words)) if a != b]
        if not affected or any(i not in pairs for i in affected):
            continue
        ratios = {Fraction(target[pairs[i]] - base[i], words[i] - base[i]) for i in affected}
        if len(ratios) != 1:
            continue
        delta = ratios.pop()
        if not delta or delta.denominator != 1:
            continue
        value = site['value'] + int(delta)
        if not 0 <= value <= 0xFFFFFFFF:
            continue
        proposals.append(site | dict(new=value, instructions=[i * 4 for i in affected]))
    if not proposals:
        return text, obj, []
    variants = [(proposal,) for proposal in proposals]
    if len(proposals) > 1:
        variants.append(tuple(proposals))
    sources = []
    bodies = {}
    for i, changes in enumerate(variants):
        body = text
        for site in sorted(changes, key=lambda s: -s['start']):
            body = body[:site['start']] + str(site['new']) + site['suffix'] + body[site['end']:]
        path = directory / f'candidate_{i}.c'
        path.write_text(body)
        bodies[path] = body, changes
        sources.append(path)
    compiled = oracle.compile_many(p, sym.module, sources, directory / 'candidates', rec['mw'], rec.get('flags') or None)
    best = oracle.word_score(list(target), list(base))[0]
    selected = []
    for path, candidate in compiled.items():
        words = instructions(candidate, 0)[rec['sdk_symbol']]
        score = oracle.word_score(list(target), list(words))[0]
        if score > best:
            best, text, obj = score, bodies[path][0], candidate
            selected = list(bodies[path][1])
    (directory / 'corrections.json').write_text(json.dumps(selected, indent=2) + '\n')
    return text, obj, selected


def import_candidate(p: Project, rec: dict, pieces: list, directory: Path, donors: dict) -> dict:
    external = {r[0] for r in sdkimport.relocations(Path(rec['object']), rec['sdk_symbol']).values()}
    text = source_body(pieces, rec['sdk_symbol'], external)
    donor = instructions(Path(rec['object']), 0)[rec['sdk_symbol']]
    sym = p.resolve(rec['symbol'])
    target_object = p.target_object_for(sym)
    target = instructions(target_object, 0)[sym.name]
    right = sdkimport.relocations(target_object, sym.name)
    pairs = aligned_words(donor, target)
    operations = difflib.SequenceMatcher(None, tuple(map(operation, donor)), tuple(map(operation, target)), autojunk=False)
    operation_pairs = {a + i: b + i for a, b, count in operations.get_matching_blocks() for i in range(count)}
    anchors = defaultdict(Counter)
    calls = defaultdict(set)
    left = sdkimport.relocations(Path(rec['object']), rec['sdk_symbol'])
    for off, (name, addend, kind) in left.items():
        to = pairs.get(off // 4, operation_pairs.get(off // 4))
        if name.startswith('.') and to is not None and to * 4 in right:
            dest, da, dk = right[to * 4]
            if kind == dk:
                target_symbol = sdkimport.retail_symbol(p, sym.module, dest)
                if target_symbol:
                    base = target_symbol.addr + da - addend
                    bases = [s for s in p.symbols(sym.module).values()
                             if s.section == target_symbol.section and s.addr == base and s.name.isidentifier()]
                    if bases:
                        anchors[name][bases[0].name] += 1
        if kind == 10 and to is not None and to * 4 in right:
            dest, da, dk = right[to * 4]
            if (addend, kind) == (da, dk):
                calls[name].add(dest)
    elf = Elf(Path(rec['object']).read_bytes())
    for item in elf.symbols():
        if item['name'] not in external or not item['name'].startswith('.') or item['shndx'] == 0:
            continue
        section = elf.sections[item['shndx']]['name']
        destinations = {dest for dest, _, kind in right.values() if kind != 10
                        and (s := sdkimport.retail_symbol(p, sym.module, dest)) and s.section == section}
        if len(destinations) == 1:
            anchors[item['name']].update(destinations)
    mapping = {name: ranked[0][0] for name, destinations in anchors.items()
               if (ranked := destinations.most_common()) and (len(ranked) == 1 or ranked[0][1] > ranked[1][1])}
    proven = proven_bindings(p, rec)
    mapping.update({name: target for name, target in proven.items() if name.startswith('.') and name in external})
    if mapping:
        text = sdkimport.shared_storage(p, rec, pieces, text, mapping)
        text = sdkimport.replace_c_symbols(sdkimport.isolate_parameters(text, mapping), mapping)
    known = {name: next(iter(destinations)) for name, destinations in calls.items() if len(destinations) == 1}
    for item in elf.symbols():
        if item['name'] not in external or item['info'] & 15 != 1 or item['shndx'] == 0:
            continue
        section = elf.sections[item['shndx']]['name']
        destinations = {dest for dest, addend, kind in right.values() if kind != 10 and addend == 0
                        and (s := sdkimport.retail_symbol(p, sym.module, dest)) and s.section == section}
        if len(destinations) == 1:
            known[item['name']] = next(iter(destinations))
    callees = callee_bindings(p, sym.module, left, right, donors)
    known = {name: dest for name, dest in known.items() if dest not in callees.values() or callees.get(name) == dest}
    known.update(callees)
    for name, _, _ in left.values():
        existing = sdkimport.retail_symbol(p, sym.module, name)
        if existing:
            known[name] = existing.name if existing.scope != 'local' else name
    known.update(call_bindings(left, right, known))
    known.update(proven)
    absolutes = oracle.abs_symbols()
    for piece in pieces:
        if isinstance(piece.address, int):
            for name in piece.names:
                dest = name if absolutes.get(name) == piece.address else next(
                    (symbol for symbol, address in absolutes.items() if address == piece.address), None)
                if dest:
                    known[name] = dest
    absent = {name for off, (name, _, kind) in left.items() if kind == 10 and name not in known
              and off // 4 not in operation_pairs}
    bound_calls = [known[name] for _, (name, _, kind) in sorted(left.items()) if kind == 10 and name in known]
    target_calls = [name for _, (name, _, kind) in sorted(right.items()) if kind == 10]
    if bound_calls == target_calls:
        absent.update(name for name, _, kind in left.values() if kind == 10 and name not in known)
    text, omitted = extra_calls(text, absent)
    pragmas = sdkimport.source_pragmas(rec['sdk'], rec['source'], rec['sdk_symbol'])
    text = '\n'.join(pragmas) + '\n' + text
    original_text = text
    independent_error = None
    try:
        text, obj, score, changes = layout(p, rec, text, directory)
    except ValueError as error:
        if not str(error).startswith(('inconsistent layout', 'layout constraints require')):
            raise
        from .layoutviews import independent
        text = independent(p, rec, text, directory / 'independent')
        text, obj, score, changes = layout(p, rec, text, directory / 'independent/recovered')
        original_text = None
    if score < 100 and original_text is not None:
        from .layoutviews import independent
        try:
            expanded = independent(p, rec, original_text, directory / 'independent')
            other = layout(p, rec, expanded, directory / 'independent/recovered')
            if other[2] > score:
                text, obj, score, changes = other
        except ValueError as error:
            independent_error = str(error)
    text, obj, corrections = constants(p, rec, text, obj, directory / 'constants')
    source = instructions(obj, 0)[rec['sdk_symbol']]
    sym = p.resolve(rec['symbol'])
    target = instructions(p.target_object_for(sym), 0)[sym.name]
    offsets = {4 * a: 4 * b for a, b in aligned_words(source, target).items()}
    compiled = rec | dict(object=str(obj))
    for _, (name, _, _) in sdkimport.relocations(obj, rec['sdk_symbol']).items():
        existing = sdkimport.retail_symbol(p, sym.module, name)
        if existing:
            known[name] = existing.name if existing.scope != 'local' else name
    compiled['known_bindings'] = known
    mapping = sdkimport.bindings(p, compiled, offsets)
    text = sdkimport.externalize_statics(text, mapping)
    text = sdkimport.replace_c_symbols(sdkimport.isolate_parameters(text, mapping), mapping)
    text, addresses = sdkimport.absolute_declarations(pieces, text)
    if any(absolutes.get(name) != address for name, address in addresses.items()):
        raise ValueError('candidate requires absolute symbols; use the SDK address importer')
    text = sdkimport.finish_source(sdkimport.format_c(text))
    text = re.sub(r'(?m)^([^\n]*&=?\s*0x800[fF]{5}[uUlL]*[^\n]*)$',
                  r'\1 // fzgx-allow: A1 IEEE-754 sign and mantissa mask', text)
    path = directory / 'bound.c'
    path.write_text(text)
    result = oracle.check(p, rec['symbol'], 6, source=path, mw_version=rec['mw'], extra_cflags=rec.get('flags') or None)
    return dict(symbol=rec['symbol'], sdk=rec['sdk'], source=rec['source'], sdk_symbol=rec['sdk_symbol'],
                size=rec['size'], mw=rec['mw'], flags=rec.get('flags') or None, path=str(path), changes=changes,
                bindings=mapping, corrections=corrections, omitted_calls=omitted, instruction_percent=score, percent=result.percent,
                matched=not oracle.unit_fully_matches(result), error=result.error, diff=result.diff, independent_error=independent_error)


def recheck_saved(p: Project, symbols=(), do_submit=True) -> dict:
    """Recheck bound candidates after oracle repairs without repeating layout probes."""
    directory = STATE_DIR / 'sourcealign'
    records = json.loads((directory / 'imports.json').read_text())
    ledger, results, accepted = Ledger(), [], []
    for row in records:
        if (symbols and row['symbol'] not in symbols) or ledger.get(row['symbol'])['status'] != 'unmatched':
            continue
        attempts = []
        for candidate in row['attempts']:
            if not candidate.get('path') or not Path(candidate['path']).exists():
                continue
            source_license(candidate['sdk'])
            result = oracle.check(p, row['symbol'], 6, source=Path(candidate['path']),
                                  mw_version=candidate['mw'], extra_cflags=candidate.get('flags'))
            match = result.ok and (result.matched or result.matched_pool) and oracle.unit_fully_matches(result) is None
            attempts.append(dict(path=candidate['path'], percent=result.percent, matched=match, error=result.error))
            if match:
                save_match(candidate | dict(percent=result.percent, matched=True, error='', diff=result.diff))
                accepted.append(row['symbol'])
                break
        if attempts:
            results.append(dict(symbol=row['symbol'], size=row['size'], attempts=attempts))
            print(row['symbol'], max(a['percent'] for a in attempts), row['symbol'] in accepted, flush=True)
    (directory / 'rechecked.json').write_text(json.dumps(results, indent=2) + '\n')
    output = dict(attempted=len(results), matched=len(accepted),
                  bytes=sum(row['size'] for row in results if row['symbol'] in accepted), symbols=accepted)
    if do_submit and accepted:
        output['submitted'] = submit_saved(p, accepted)
    return output


def save_match(result: dict) -> None:
    path = STATE_DIR / 'sourcealign/matches.json'
    matches = json.loads(path.read_text()) if path.exists() else {}
    body = Path(result['path']).read_text()
    source = STATE_DIR / 'sourcealign' / result['symbol'].replace(':', '__') / 'verified.c'
    source.write_text(body)
    result = result | dict(path=str(source))
    sdk = ROOT / 'build/tools' / result['sdk']
    revision = subprocess.run(['git', '-C', str(sdk), 'rev-parse', 'HEAD'], text=True, capture_output=True, check=True).stdout.strip()
    result['revision'] = revision
    result['license'] = source_license(result['sdk'])
    result['source_sha256'] = hashlib.sha256((sdk / result['source']).read_bytes()).hexdigest()
    result['generated_sha256'] = hashlib.sha256(body.encode()).hexdigest()
    matches[result['symbol']] = result
    path.write_text(json.dumps(matches, indent=2, sort_keys=True) + '\n')


def submit_saved(p: Project, symbols=()) -> dict:
    path = STATE_DIR / 'sourcealign/matches.json'
    matches = json.loads(path.read_text())
    manifest_path = ROOT / 'state/sdkimports/sourcealign.json'
    manifest = json.loads(manifest_path.read_text()) if manifest_path.exists() else {}
    ledger = Ledger()
    accepted, failed = [], []
    for symbol, result in matches.items():
        if symbols and symbol not in symbols or ledger.get(symbol)['status'] != 'unmatched':
            continue
        result['license'] = source_license(result['sdk'])
        body = Path(result['path']).read_text()
        if hashlib.sha256(body.encode()).hexdigest() != result['generated_sha256']:
            raise ValueError(f'saved verified source changed: {symbol}')
        work = p.work_path(symbol)
        work.parent.mkdir(parents=True, exist_ok=True)
        work.write_text(body)
        submitted = api.submit(p, symbol, agent='sourcealign', message='Recover SDK layouts from compiler offset constraints',
                               harness='fzgx', model='none', mw_version=result['mw'], extra_cflags=result['flags'])
        if submitted.get('ok'):
            license_path = ROOT / 'state/sdkimports/licenses' / (result['sdk'] + '.txt')
            license_path.parent.mkdir(parents=True, exist_ok=True)
            license_path.write_bytes((ROOT / 'build/tools' / result['sdk'] / result['license']['path']).read_bytes())
            accepted.append(symbol)
            manifest[symbol] = {k: v for k, v in result.items() if k not in ('path', 'diff', 'error', 'matched', 'percent')}
            manifest_path.write_text(json.dumps(manifest, indent=2, sort_keys=True) + '\n')
        else:
            failed.append(dict(symbol=symbol, error=submitted))
    # Historical provenance is pinned to its imported source revision/license.
    # Do not rewrite it from a newer (or absent) checkout, and do not let an
    # unrelated legacy donor fail a batch after its new imports were submitted.
    for symbol in accepted:
        result = manifest[symbol]
        root = ROOT / 'build/tools' / result['sdk']
        result['repository'] = subprocess.run(['git', '-C', str(root), 'remote', 'get-url', 'origin'],
                                               text=True, capture_output=True, check=True).stdout.strip()
    manifest_path.write_text(json.dumps(manifest, indent=2, sort_keys=True) + '\n')
    return dict(accepted=accepted, failed=failed)


def apply_names(p: Project) -> dict:
    from . import tu, verify
    ledger = Ledger()
    if verify.pending(ledger):
        raise ValueError('verify pending imports before applying donor names')
    manifests = {path: json.loads(path.read_text()) for path in (ROOT / 'state/sdkimports').glob('*.json')}
    proposals = defaultdict(set)
    targets = defaultdict(set)
    for records in manifests.values():
        for symbol, result in records.items():
            row = ledger.get(symbol)
            if not row or row['status'] != 'matched' or row['link_state'] != 'verified':
                continue
            source_license(result['sdk'])
            name = result['sdk_symbol']
            if re.fullmatch(r'[A-Za-z_]\w*', name):
                proposals[symbol].add(name)
                targets[name].add(symbol)
    taken = {name for module in p.modules for name in p.symbols(module)}
    mapping, skipped = {}, {}
    for symbol, names in sorted(proposals.items()):
        if not p.resolve(symbol).name.startswith('fn_'):
            continue
        if len(names) != 1:
            skipped[symbol] = 'conflicting donor names'
            continue
        name = next(iter(names))
        if len(targets[name]) != 1 or name in taken:
            skipped[symbol] = f'ambiguous or occupied donor name: {name}'
            continue
        mapping[symbol] = name
        taken.add(name)
    renamed = tu.rename_many(p, mapping, verify=True) if mapping else dict(ok=True, applied=0, results=[])
    applied = {row['old']: row['new'] for row in renamed['results'] if row.get('ok')}
    if applied:
        def update_record(result):
            old = result['symbol']
            if old in applied:
                result.setdefault('original_symbol', old)
                result['symbol'] = applied[old]
            result['bindings'] = {name: sdkimport.replace_c_symbols(target, applied)
                                  for name, target in result.get('bindings', {}).items()}
        for path, records in manifests.items():
            for result in records.values():
                update_record(result)
            records = {applied.get(name, name): result for name, result in records.items()}
            path.write_text(json.dumps(records, indent=2, sort_keys=True) + '\n')
        path = STATE_DIR / 'sourcealign/matches.json'
        matches = json.loads(path.read_text()) if path.exists() else {}
        for result in matches.values():
            update_record(result)
            source = Path(result['path'])
            body = sdkimport.replace_c_symbols(source.read_text(), applied)
            source.write_text(body)
            result['generated_sha256'] = hashlib.sha256(body.encode()).hexdigest()
        matches = {applied.get(name, name): result for name, result in matches.items()}
        path.write_text(json.dumps(matches, indent=2, sort_keys=True) + '\n')
        manifest_path = ROOT / 'state/sdkimports/sourcealign.json'
        manifest = json.loads(manifest_path.read_text())
        for symbol in manifest.keys() & matches.keys():
            manifest[symbol]['generated_sha256'] = matches[symbol]['generated_sha256']
        manifest_path.write_text(json.dumps(manifest, indent=2, sort_keys=True) + '\n')
        path = STATE_DIR / 'sourcealign/discovery.json'
        if path.exists():
            discovery = json.loads(path.read_text())
            for row in discovery['results']:
                row['symbol'] = applied.get(row['symbol'], row['symbol'])
            path.write_text(json.dumps(discovery, indent=2) + '\n')
    return dict(ok=renamed['ok'], applied=renamed['applied'], names=applied, skipped=skipped)


def run(p: Project, minimum=256, symbols=(), saved=False, do_submit=True, discover_only=False, roots=(), rel_only=False) -> dict:
    directory = STATE_DIR / 'sourcealign'
    discovery = json.loads((directory / 'discovery.json').read_text()) if saved else discover(p, minimum, roots, rel_only)
    if discover_only:
        return {k: v for k, v in discovery.items() if k != 'results'}
    cache, results = {}, []
    donors = defaultdict(lambda: defaultdict(list))
    for donor in catalog(p, 16):
        donors[donor['sdk']][donor['sdk_symbol']].append(donor['words'])
    ledger = Ledger()
    for row in discovery['results']:
        if symbols and row['symbol'] not in symbols:
            continue
        if ledger.get(row['symbol'])['status'] != 'unmatched':
            continue
        attempts = []
        for candidate in row['candidates']:
            rec = {k: v for k, v in row.items() if k != 'candidates'} | candidate
            rec.setdefault('flags', source_flags(rec['sdk'], rec['source']))
            key = rec['sdk'], rec['source'], rec['mw']
            try:
                source_license(rec['sdk'])
                if key not in cache:
                    cache[key] = sdkimport.declarations(sdkimport.preprocess(ROOT / 'build/tools' / rec['sdk'], rec['source'], rec['mw']))
                tag = rec['sdk'] + '_' + rec['sdk_symbol'] + '_' + rec['mw'].replace('/', '_')
                tag += '_stmw' if '-use_lmw_stmw on' in rec.get('flags', '') else ''
                tag += '_' + hashlib.sha256(rec['flags'].encode()).hexdigest()[:8]
                path = directory / row['symbol'].replace(':', '__') / tag
                result = import_candidate(p, rec, cache[key], path, donors[rec['sdk']])
            except (ValueError, RuntimeError, StopIteration) as exc:
                result = dict(symbol=row['symbol'], sdk_symbol=rec['sdk_symbol'], error=str(exc) or type(exc).__name__)
            attempts.append(result)
            if result.get('matched'):
                save_match(result)
                if do_submit:
                    submitted = submit_saved(p, [row['symbol']])
                    result['submitted'] = submitted
                    if submitted['failed']:
                        result['matched'] = False
                break
        if attempts:
            results.append(dict(symbol=row['symbol'], size=row['size'], attempts=attempts))
            last = attempts[-1]
            print(row['symbol'], row['size'], last.get('percent'), last.get('matched', False), last.get('error'), flush=True)
            (directory / 'imports.json').write_text(json.dumps(results, indent=2) + '\n')
    matched = [r for r in results if any(a.get('matched') for a in r['attempts'])]
    return dict(attempted=len(results), matched=len(matched), bytes=sum(r['size'] for r in matched),
                results=str(directory / 'imports.json'))
