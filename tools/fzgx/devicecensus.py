"""Read-only source-debt inventory; lexical review signals are not device verdicts.

Count physical source once, not generated copies or repeated TU prologues. Keep
explicit warning spots, their owner functions, shared headers and review signals
separate. No count here certifies that an unmarked function is natural C.
"""
from __future__ import annotations

import hashlib
import re
import subprocess
from bisect import bisect_right
from collections import Counter

from . import original_assembly, progress, tufile
from .project import ROOT

MARKER = re.compile(r'WARNING:\s*(?:compiler-diff\s+device|device)\b')
PRAGMA = re.compile(r'^[ \t]*#[ \t]*pragma[ \t]+(opt_\w+|optimize_for_size|optimization_level|scheduling|peephole)\b([^\n]*)', re.M)
CARRIER = re.compile(r'\bstruct\s*\{\s*(?:[su](?:8|16|32|64)|f32|f64|int|unsigned|float|double)\s+value\s*;\s*\}\s*[A-Za-z_]\w*\s*;')
DEAD_WRITE = re.compile(r'\bADX_COMPILER_DIFF_DEAD_WRITE\s*\(')
SYNTHETIC_FUNCTION = re.compile(r'\b(fzgx_\w+)\s*\((?:[^(){};]|\([^(){};]*\))*\)\s*\{')
CODE_SECTION = re.compile(r'^[ \t]*#pragma[ \t]+section[ \t]+code_type[ \t]+"([^"]+)"[^\n]*', re.M)
EXPLICIT_POOL = re.compile(r'__declspec\s*\(\s*section\s+"\.fzgxpool"\s*\)\s+[^;{}]*?\b(fzgx_\w+)\s*\((?:[^(){};]|\([^(){};]*\))*\)\s*\{')


def _blocks(text):
    """Physical offsets, including marker comments, without source regeneration."""
    start, current, out = 0, None, []
    for line in text.splitlines(keepends=True):
        begin, end = tufile.BEGIN_RE.match(line.rstrip()), tufile.END_RE.match(line.rstrip())
        if begin and current is None:
            current = (begin['name'], start)
        elif end and current and end['name'] == current[0]:
            out.append((current[0], current[1], start + len(line)))
            current = None
        start += len(line)
    return out


def measure(project):
    active, by_path, forms, unknown = progress.units(), {}, Counter(), []
    for module in project.modules:
        for symbol in project.symbols(module).values():
            if symbol.kind != 'function' or not symbol.size or symbol.section not in ('.text', '.init'):
                continue
            key = f'{module}:{symbol.name}'
            unit = active.get(key)
            if not unit:
                unknown.append(key)
                forms['unregistered'] += 1
                continue
            forms[original_assembly.source_form(unit['source'], symbol.name, bool(unit.get('asm')))] += 1
            if unit.get('status') != 'matching':
                continue
            path = 'src/' + (unit.get('tu') or unit['source'])
            by_path.setdefault(path, {})[symbol.name] = key
    findings, files, digest = [], [], hashlib.sha256()
    scanned = 0
    for directory in ('src', 'include'):
        for path in sorted((ROOT / directory).rglob('*')):
            if not path.is_file() or path.suffix not in ('.c', '.h', '.cpp', '.hpp', '.s', '.S'):
                continue
            relative = path.relative_to(ROOT).as_posix()
            data = path.read_bytes()
            sha = hashlib.sha256(data).hexdigest()
            digest.update((relative + '\0' + sha + '\n').encode())
            scanned += 1
            text = data.decode('utf-8', errors='replace')
            code = original_assembly.masked(text)
            blocks, owners = _blocks(text), by_path.get(relative, {})
            rows = []
            sections = [(m.start(), m[1]) for m in CODE_SECTION.finditer(text)
                        if code[m.start():m.end()].lstrip().startswith('#pragma')]
            section_positions = [position for position, _ in sections]
            explicit_pool = {m.start(1) for m in EXPLICIT_POOL.finditer(text)
                             if code.startswith('__declspec', m.start())}

            def add(category, position, spelling):
                block = next((name for name, start, end in blocks if start <= position < end), None)
                owner = owners.get(block) if block else None
                if owner is None and len(owners) == 1:
                    owner = next(iter(owners.values()))
                rows.append(dict(category=category, path=relative,
                                 line=text.count('\n', 0, position) + 1,
                                 owner=owner, block=block, spelling=spelling.strip()))

            for comment in original_assembly.LEXICAL.finditer(text):
                if comment[0].startswith(('/*', '//')):
                    for marker in MARKER.finditer(comment[0]):
                        add('marked-warning', comment.start() + marker.start(), marker[0])
            for match in PRAGMA.finditer(code):
                state = match[2].strip()
                if state not in ('reset', 'push', 'pop'):
                    add('optimization-pragma-review', match.start(), match[0])
            for match in re.finditer(r'\bvolatile\b', code):
                add('volatile-token-review', match.start(), match[0])
            for match in CARRIER.finditer(code):
                add('single-field-value-carrier-review', match.start(), match[0])
            for match in SYNTHETIC_FUNCTION.finditer(code):
                section_index = bisect_right(section_positions, match.start()) - 1
                pool = match.start(1) in explicit_pool or (section_index >= 0 and sections[section_index][1] == '.fzgxpool')
                category = 'layout-primer-function' if pool else 'synthetic-function-review'
                add(category, match.start(), match[1])
            for match in DEAD_WRITE.finditer(code):
                # Count uses, not the header's macro definition itself.
                line_start = code.rfind('\n', 0, match.start()) + 1
                if not re.match(r'\s*#\s*define\b', code[line_start:match.start()]):
                    add('adx-dead-write-use', match.start(), match[0])
            if rows:
                files.append(dict(path=relative, sha256=sha))
                findings.extend(rows)
    warnings = [r for r in findings if r['category'] == 'marked-warning']
    dead_writes = [r for r in findings if r['category'] == 'adx-dead-write-use']
    marker_owners = sorted({r['owner'] for r in warnings if r['owner']})
    macro_owners = sorted({r['owner'] for r in dead_writes if r['owner']})
    primer_owners = sorted({r['owner'] for r in findings if r['category'] == 'layout-primer-function' and r['owner']})
    categories = {}
    for category in sorted({r['category'] for r in findings}):
        rows = [r for r in findings if r['category'] == category]
        categories[category] = dict(spots=len(rows), files=len({r['path'] for r in rows}),
                                    owner_functions=len({r['owner'] for r in rows if r['owner']}),
                                    unassigned_spots=sum(r['owner'] is None for r in rows))
    config_paths = [project.units_path] + [project.module_config_dir(m) / 'symbols.txt' for m in project.modules]
    config_paths.append(original_assembly.REGISTRY)
    return dict(schema=2, version=project.version,
                source_commit=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
                source_status=subprocess.check_output(['git', 'status', '--porcelain=v1', '--untracked-files=all', '--', 'src', 'include', 'config'], cwd=ROOT, text=True).splitlines(),
                source_tree_sha256=digest.hexdigest(), scanned_files=scanned,
                configuration_sha256={p.relative_to(ROOT).as_posix(): hashlib.sha256(p.read_bytes()).hexdigest()
                                      for p in config_paths},
                source_forms=dict(sorted(forms.items())), unregistered_functions=unknown,
                categories=categories, marked_owner_functions=marker_owners,
                adx_dead_write_owner_functions=macro_owners,
                layout_primer_owner_functions=primer_owners,
                confirmed_debt_owner_functions=sorted(set(marker_owners) | set(macro_owners) | set(primer_owners)),
                unassigned_warning_spots=[r for r in warnings if not r['owner']],
                limits=[
                    'Warning spots are comments, not distinct devices. Multiple warnings can describe one device, and one warning can describe several.',
                    'Owners are physical TU-block owners or single-function source owners, not a complete call graph. Shared primers and headers can affect other consumers.',
                    'ADX dead-write uses are explicit device consumers. Other pragmas, volatile tokens and scalar-carrier shapes are review signals, not confirmed devices.',
                    'Layout primers are physical fzgx_-named definitions in the synthetic .fzgxpool code section, recognized by active section pragmas or explicit attributes. Repeated copies are not deduplicated into inferred original data objects. Other fzgx_-named functions remain review-only.',
                    'Source-form classification uses current configured retail functions and the existing reviewed assembly registry; C form does not certify natural C.',
                    'No preprocessor/call-graph or whole-project semantic audit is claimed. Unmarked devices and unresolved type/data ownership are not a certified total.'
                ], files_with_findings=files, findings=findings)


def summary(report):
    state = ', modified source/config' if report['source_status'] else ''
    lines = [f"Device census ({report['version']}, {report['source_commit'][:9]}{state})"]
    for category, row in report['categories'].items():
        unresolved = f", {row['unassigned_spots']} unassigned" if row['unassigned_spots'] else ''
        lines.append(f"  {category}: {row['spots']} spots, {row['files']} files, {row['owner_functions']} owner functions{unresolved}")
    lines += [f"Confirmed marked/dead-write/layout-primer owner-function union: {len(report['confirmed_debt_owner_functions'])}",
              f"Unassigned/shared warning spots: {len(report['unassigned_warning_spots'])}",
              'Configured source forms: ' + ', '.join(f'{key}={value}' for key, value in report['source_forms'].items()),
              'These are lower-bound marked debt and review signals, not a certified remaining-device or natural-C total.']
    return '\n'.join(lines)
