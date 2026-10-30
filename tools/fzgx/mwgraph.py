"""Read and replay the stock MWCC interference graph; no compiler mutation.

Layouts and allocator semantics are verified against the named PE binaries.
See docs/REGISTER_REPAIR.md for reverse-engineering provenance and limits.
This module also runs in Apple's LLDB Python 3.9.
"""
from __future__ import annotations

import shutil
import struct
import hashlib
import gzip
import json
import time
from pathlib import Path

PROFILES = {
    'ccf4b465cec73b5aae9c5c5543dcf8cda8a62aba246f89e2e0b200d742f2e55c': {
        'compiler': 'GC/1.2.5n', 'codegen': 0x4351C0, 'select': 0x4CE2D0, 'graph': 0x587E3C,
        'counts': {'gpr': 0x58846E, 'fpr': 0x58846C}, 'count_width': 2,
        'class_global': None, 'register_offset': 12,
        'pcode_blocks': 0x587C74, 'opcode_table': 0x5654B0,
    },
    '4e502c38465500d4fda8d966b268151a6c74c730508e3d9b7efd23d1a6083715': {
        'compiler': 'GC/1.3', 'codegen': 0x433590, 'select': 0x506F50, 'graph': 0x5E67D0,
        'counts': {'gpr': 0x5E6A8C, 'fpr': 0x5E6A88}, 'count_width': 4,
        'class_global': 0x5E7317, 'register_offset': 16,
        'pcode_blocks': 0x5E67B0, 'opcode_table': 0x5BDCF0,
    },
    '7cbae0a5bd81e07d7fa8975bbc4e969b5dea265cc29c5ee6bae0453a6e25f225': {
        'compiler': 'GC/1.3.2', 'codegen': 0x433310, 'select': 0x507A30, 'graph': 0x5E87D0,
        'counts': {'gpr': 0x5E8A8C, 'fpr': 0x5E8A88}, 'count_width': 4,
        'class_global': 0x5E931F, 'register_offset': 16,
        'pcode_blocks': 0x5E87B0, 'opcode_table': 0x5BEE78,
        'spill_cost_offset': 12, 'spill_limit': 0x5DF940, 'spill_fallback': 0x5BBB24,
    },
}
PROFILES['0443b5c02b1aa7b575b61e0e24c4d5ad6bed8fd54cc42de5a2204a5216001914'] = {
    **PROFILES['ccf4b465cec73b5aae9c5c5543dcf8cda8a62aba246f89e2e0b200d742f2e55c'],
    'compiler': 'GC/1.2.5',
}

INITIAL = {'gpr': (0, *range(3, 13)), 'fpr': tuple(range(14))}


def header_fingerprint(root, version):
    digest = hashlib.sha256()
    for directory in (root / 'include', root / 'build' / version / 'include'):
        for path in sorted(directory.rglob('*')):
            if path.is_file():
                digest.update(str(path.relative_to(root)).encode() + b'\0' + path.read_bytes())
    return digest.hexdigest()


def read_graph(read, profile, register_class, head=0):
    def number(address, width=4):
        return int.from_bytes(read(address, width), 'little')

    count = number(profile['counts'][register_class], profile['count_width'])
    if not 32 <= count <= 32767:
        raise ValueError(f'invalid virtual register count: {count}')
    graph = number(profile['graph'])
    pointers = struct.unpack('<' + 'I' * count, read(graph, 4 * count))
    offset = profile['register_offset']
    nodes, addresses = [], {}
    for register, pointer in enumerate(pointers):
        if not pointer:
            continue
        data = read(pointer, offset + 10)
        virtual, degree, physical, flags, neighbors = struct.unpack_from('<hhhhh', data, offset)
        if virtual != register or neighbors < 0 or neighbors > count:
            raise ValueError(f'invalid graph node v{register}: {(virtual, neighbors)}')
        adjacent = list(struct.unpack('<' + 'h' * neighbors, read(pointer + offset + 10, neighbors * 2)))
        if any(n < 0 or n >= count for n in adjacent):
            raise ValueError('invalid interference edge')
        node = {'virtual_register': register, 'physical_register': physical,
                'flags': flags, 'degree': degree, 'neighbors': adjacent}
        if 'spill_cost_offset' in profile:
            node['spill_cost'] = struct.unpack_from('<i', data, profile['spill_cost_offset'])[0]
        obj = struct.unpack_from('<I', data, 4)[0]
        if obj:
            name_record = number(obj + 10)
            if name_record:
                name = bytearray()
                for i in range(1024):
                    byte = read(name_record + 10 + i, 1)
                    if byte == b'\0':
                        break
                    name.extend(byte)
                else:
                    raise ValueError('unterminated compiler object name')
                node['name'] = name.decode('utf-8', errors='replace')
        nodes.append(node)
        addresses[pointer] = (register, struct.unpack_from('<I', data)[0])
    order, seen = [], set()
    while head:
        if head in seen or head not in addresses:
            raise ValueError('invalid simplify linked list')
        seen.add(head)
        register, head = addresses[head]
        order.append(register)
    snapshot = {'register_class': register_class, 'nodes': nodes, 'simplify_order': order}
    if 'spill_limit' in profile:
        snapshot['spill_limit'] = int.from_bytes(read(profile['spill_limit'], 2), 'little', signed=True)
        snapshot['spill_fallback'] = struct.unpack('<f', read(profile['spill_fallback'], 4))[0]
    return snapshot


def replay(snapshot, order=None):
    """Replay SelectColors, including its nonrecursive coalesced-neighbor reads."""
    nodes = {n['virtual_register']: n for n in snapshot['nodes']}
    colors = {r: n['physical_register'] for r, n in nodes.items()}
    mask = sum(1 << c for c in INITIAL[snapshot['register_class']])
    next_saved = 31
    for register in snapshot['simplify_order'] if order is None else order:
        blocked = 0
        for neighbor in nodes[register]['neighbors']:
            color = colors[neighbor]
            if 0 <= color < 32:
                blocked |= 1 << color
        available = mask & ~blocked
        if available:
            color = (available & -available).bit_length() - 1
        else:
            # The stock allocator claims the next saved color directly. It does
            # not re-resolve coalesced parents or recompute the blocked mask.
            while next_saved >= 14 and mask & (1 << next_saved):
                next_saved -= 1
            color = next_saved if next_saved >= 14 else -1
            if color >= 0:
                mask |= 1 << color
                next_saved -= 1
        colors[register] = color
    return colors


def selection_order(snapshot, desired):
    """Construct a sufficient ordering witness, not a C-realizability proof.

    A node is eligible when its desired color is the compiler's current first
    choice. Prefer lower colors already in the pool; open saved colors only
    when none of those nodes is eligible. No permutations or compile probes.
    Failure is inconclusive: coalesced aliases and partial constraints can
    require a different witness. Every returned order is replay-validated.
    """
    nodes = {n['virtual_register']: n for n in snapshot['nodes']}
    remaining = set(snapshot['simplify_order'])
    if set(desired) != remaining or any(not 0 <= c < 32 for c in desired.values()):
        raise ValueError('desired colors must cover every active node without spills')
    colors = {r: n['physical_register'] for r, n in nodes.items()}
    mask = sum(1 << c for c in INITIAL[snapshot['register_class']])
    next_saved, order = 31, []
    while remaining:
        eligible = []
        for register in remaining:
            blocked = 0
            for neighbor in nodes[register]['neighbors']:
                color = colors[neighbor]
                if 0 <= color < 32:
                    blocked |= 1 << color
            available = mask & ~blocked
            color = (available & -available).bit_length() - 1 if available else next_saved
            if color == desired[register]:
                eligible.append((not bool(available), color, register))
        if not eligible:
            return None
        claimed, color, register = min(eligible)
        if claimed:
            if next_saved < 14:
                return None
            mask |= 1 << color
            next_saved -= 1
        colors[register] = color
        remaining.remove(register)
        order.append(register)
    actual = replay(snapshot, order)
    if any(actual[r] != c for r, c in desired.items()):
        raise AssertionError('invalid allocation witness')
    return order


def simplify(snapshot, ranks=None):
    """Replay simplify, including measured cost-based optimistic removals.

    Older captures without spill costs still report unsupported decisions.
    Coalesced ghost edges remain in degree counts, as in the stock compiler.
    """
    nodes = {n['virtual_register']: n for n in snapshot['nodes']}
    remaining = set(snapshot['simplify_order'])
    degree = {r: len(n['neighbors']) for r, n in nodes.items()}
    ranks = ranks or {}
    order = sorted(remaining, key=lambda r: (ranks.get(r, r), r))
    removed = []
    available = 29 if snapshot['register_class'] == 'gpr' else 32
    while remaining:
        changed = False
        for register in order:
            if register not in remaining or degree[register] >= available:
                continue
            remaining.remove(register)
            removed.append(register)
            for neighbor in nodes[register]['neighbors']:
                degree[neighbor] -= 1
            changed = True
        if not changed:
            if 'spill_limit' not in snapshot or any('spill_cost' not in nodes[r] for r in remaining):
                return None
            # Simplify builds its remaining list by prepending nodes in rank
            # order. Its strict-less comparison therefore retains the highest
            # rank on equal costs. Costs belong to the captured value webs;
            # declaration reordering must not reclassify generated registers.
            def score(register):
                if register >= snapshot['spill_limit']:
                    return snapshot['spill_fallback']
                return nodes[register]['spill_cost'] / degree[register]
            register = min((r for r in reversed(order) if r in remaining), key=score)
            remaining.remove(register)
            removed.append(register)
            for neighbor in nodes[register]['neighbors']:
                degree[neighbor] -= 1
    return removed[::-1]


def read_pcode(read, profile):
    """Capture instruction identities, virtual operands and source lines."""
    modern = profile['register_offset'] == 16
    block_global = profile['pcode_blocks']
    table, stride = profile['opcode_table'], 18 if modern else 16
    header_size, opcode_offset = (36, 32) if modern else (28, 20)
    def u32(address):
        return int.from_bytes(read(address, 4), 'little')
    def string(address):
        result = bytearray()
        for i in range(1024):
            byte = read(address + i, 1)
            if byte == b'\0':
                return result.decode('utf-8', errors='replace')
            result.extend(byte)
        raise ValueError('unterminated PCode string')
    block, seen_blocks, rows, descriptors = u32(block_global), set(), [], {}
    while block:
        if block in seen_blocks or len(seen_blocks) > 100000:
            raise ValueError('invalid PCode block list')
        seen_blocks.add(block)
        instruction, seen = u32(block + 20), set()
        block_index = u32(block + 28)
        while instruction:
            if instruction in seen or len(seen) > 100000:
                raise ValueError('invalid PCode instruction list')
            seen.add(instruction)
            header = read(instruction, header_size)
            opcode = struct.unpack_from('<h', header, opcode_offset)[0]
            count = struct.unpack_from('<h', header, header_size - 2)[0]
            if not 0 <= opcode < 512 or not 0 <= count <= 4096:
                raise ValueError(f'invalid PCode instruction: {opcode}, {count}')
            if opcode not in descriptors:
                descriptor = read(table + opcode * stride, stride)
                descriptors[opcode] = (string(int.from_bytes(descriptor[:4], 'little')),
                                       string(int.from_bytes(descriptor[4:8], 'little')))
            operands = []
            for i in range(count):
                raw = read(instruction + header_size + i * 12, 12)
                if modern:
                    kind = {4: 'gpr', 3: 'fpr'}.get(raw[1]) if raw[0] == 0 else None
                    reg = struct.unpack_from('<h', raw, 4)[0]
                    flags = int.from_bytes(raw[2:4], 'little')
                else:
                    kind = {0: 'gpr', 1: 'fpr'}.get(raw[0])
                    reg = struct.unpack_from('<h', raw, 2)[0]
                    flags = raw[1]
                operands.append({'class': kind, 'reg': reg if kind else None,
                                 'flags': flags, 'raw': raw.hex()})
            mnemonic, fmt = descriptors[opcode]
            rows.append({'id': instruction, 'block': block_index, 'mnemonic': mnemonic.lower(),
                         'format': fmt, 'line': struct.unpack_from('<i', header, 28)[0] if modern else None,
                         'operands': operands})
            instruction = int.from_bytes(header[:4], 'little')
        block = u32(block)
    return rows


def replay_archive(path):
    data = json.loads(gzip.decompress(path.read_bytes()))
    if data['format'] != 'fzgx-mwcc-graphs-v1':
        raise ValueError('unsupported graph archive')
    passes = 0
    start = time.perf_counter_ns()
    for record in data['functions']:
        for capture in record['captures']:
            before, after = capture['before'], capture['after']
            order = simplify(before)
            if order != before['simplify_order']:
                raise ValueError(f"{record['symbol']}: simplify replay differs")
            colors = replay(before, order)
            if any(colors[n['virtual_register']] != n['physical_register'] for n in after['nodes']):
                raise ValueError(f"{record['symbol']}: color replay differs")
            passes += 1
    elapsed = time.perf_counter_ns() - start
    print(json.dumps({'functions': len(data['functions']), 'allocation_passes': passes,
                      'replay_ms': elapsed / 1e6, 'errors': 0}, indent=2))


def capture(project, args, locked=False):
    from . import oracle, mwconstraints
    import os, signal, shlex, subprocess, time
    from contextlib import nullcontext
    root = Path(__file__).resolve().parents[2]
    output = args.output.resolve()
    output.mkdir(parents=True, exist_ok=True)
    inputs = json.loads((args.corpus / 'inputs.json').read_text())
    results = json.loads((args.corpus / 'results.json').read_text())
    jobs = []
    compiler_hashes = {}
    headers_sha256 = header_fingerprint(root, project.version)
    for symbol, record in inputs.items():
        if args.symbols and symbol not in args.symbols:
            continue
        if not args.all_near and results[symbol]['baseline']['pure'] != 'regalloc':
            continue
        source = Path(record['source']).resolve()
        if hashlib.sha256(source.read_bytes()).hexdigest() != record['sha256']:
            raise ValueError(f'{symbol}: frozen C changed')
        flags, default_mw = oracle.module_flags(project, project.resolve(symbol).module)
        mw = record['mw'] or default_mw
        compiler = root / 'build/compilers' / mw / 'mwcceppc.exe'
        if compiler not in compiler_hashes:
            compiler_hashes[compiler] = hashlib.sha256(compiler.read_bytes()).hexdigest()
        if compiler_hashes[compiler] not in PROFILES:
            if args.all_near:
                print(json.dumps({'symbol': symbol, 'skipped': 'unsupported compiler', 'compiler': mw}))
                continue
            raise ValueError(f'{symbol}: unsupported compiler {record["mw"]}')
        stem = symbol.replace(':', '__')
        obj = output / (stem + '.o')
        captured_source = output / 'sources' / (stem + '.c')
        if not args.replay:
            captured_source.parent.mkdir(parents=True, exist_ok=True)
            captured_source.write_bytes(source.read_bytes())
        extra = shlex.split(record['flags'] or '')
        levels = [f for f in extra if f.startswith('-O')]
        compiler_flags = [levels[-1] if levels and f.startswith('-O') else f for f in shlex.split(flags)]
        compiler_flags += [f for f in extra if not f.startswith('-O')]
        jobs.append({'symbol': symbol, 'capture': str(output / (stem + '.json')),
                     'compiler': mw, 'name': project.resolve(symbol).name,
                     'source_sha256': record['sha256'], 'headers_sha256': headers_sha256,
                     'args': [str(compiler), *compiler_flags,
                              '-c', str(captured_source), '-o', str(obj)]})
    if not jobs:
        raise ValueError('no register-allocation candidates selected')
    config = output / 'config.json'
    expected = {'root': str(root), 'wibo': str(root / 'build/tools/wibo'),
                'jobs': jobs, 'report': str(output / 'capture-report.json')}
    if args.replay:
        saved = json.loads(config.read_text())
        saved_jobs = {j['symbol']: j for j in saved['jobs']}
        if any(saved_jobs.get(j['symbol']) != j for j in jobs):
            raise ValueError('capture configuration changed; recapture required')
        capture_seconds = None
    else:
        config.write_text(json.dumps(expected))
        start = time.perf_counter()
        script = root / 'tools/fzgx/mwgraph_lldb.py'
        # The allocator graph only exists inside the running compiler, so it has to be read
        # under LLDB. `xcrun lldb` is the macOS launcher; a bare `lldb` is used elsewhere.
        # Neither is present on every host, and a bare FileNotFoundError on 'xcrun' reads like
        # a broken checkout rather than a missing toolchain component.
        launcher = shutil.which('xcrun') and ['xcrun', 'lldb'] or (
            ['lldb'] if shutil.which('lldb') else None)
        if launcher is None:
            raise RuntimeError(
                'allocator capture needs LLDB to read the compiler\'s register graph, and '
                'neither `xcrun lldb` nor `lldb` is on PATH. This host cannot capture, so '
                'mwconstraints.constrain() has no snapshots to work from and regalloc '
                'functions stay blocked; the corpus classification in results.json is still '
                'written and will be used as soon as a host with LLDB captures.')
        with (nullcontext() if locked else oracle.build_lock()), (output / 'lldb.log').open('w') as log:
            command = [*launcher, '-b', '-o', f'command script import "{script}"',
                       '-o', f'script mwgraph_lldb.run(lldb.debugger, {str(config)!r})',
                       '-o', 'quit']
            # Sanitize the env for lldb: leaking the full parent env makes lldb's
            # embedded Python resolve to a broken install (the Hermes tools
            # Python) missing encodings/math/_struct, so every capture dies with
            # "No module named 'encodings'". lldb must use the system Python it
            # was linked against (libpython3.14.so), so give it a minimal clean
            # env: HOME, a system-only PATH, and PYTHONHOME=/usr (Python 3.14 then
            # finds its stdlib at /usr/lib/python3.14). A fully clean env was
            # verified to import mwgraph_lldb without error.
            lldb_env = {'HOME': os.environ.get('HOME', '/tmp'),
                        'PATH': '/usr/bin:/bin:/usr/local/bin',
                        'PYTHONHOME': '/usr'}
            process = subprocess.Popen(command, cwd=root, stdout=log, stderr=subprocess.STDOUT,
                                       start_new_session=True, env=lldb_env)
            try:
                code = process.wait(timeout=max(60, len(jobs) * 20))
                if code:
                    raise subprocess.CalledProcessError(code, command)
            except (subprocess.TimeoutExpired, KeyboardInterrupt):
                os.killpg(process.pid, signal.SIGKILL)
                process.wait()
                raise
        capture_seconds = time.perf_counter() - start
    rows = []
    for job in jobs:
        symbol = job['symbol']
        result = json.loads(Path(job['capture']).read_text())
        if 'error' in result:
            rows.append(result)
            continue
        baseline = Path(results[symbol]['baseline']['object'])
        captured_words = oracle.words(Path(job['args'][-1]), job['name'])
        baseline_words = oracle.words(baseline, job['name'])
        same_code = bool(captured_words) and captured_words == baseline_words
        same_object, object_percent = oracle.function_score(project, job['name'], baseline, Path(job['args'][-1]))
        errors, simplify_errors, simplify_unsupported, witnesses, count = [], [], [], 0, 0
        start = time.perf_counter_ns()
        for capture in result['captures']:
            before, after = capture['before'], capture['after']
            order = simplify(before)
            if order is None:
                simplify_unsupported.append(before['register_class'])
            elif order != before['simplify_order']:
                simplify_errors.append(before['register_class'])
            colors = replay(before)
            errors.extend((n['virtual_register'], colors[n['virtual_register']], n['physical_register'])
                          for n in after['nodes'] if colors[n['virtual_register']] != n['physical_register'])
            count += len(before['simplify_order'])
        replay_ns = time.perf_counter_ns() - start
        start = time.perf_counter_ns()
        for capture in result['captures']:
            before, after = capture['before'], capture['after']
            active = set(before['simplify_order'])
            desired = {n['virtual_register']: n['physical_register'] for n in after['nodes']
                       if n['virtual_register'] in active}
            if all(c >= 0 for c in desired.values()):
                witnesses += selection_order(before, desired) is not None
        inverse_ns = time.perf_counter_ns() - start
        start = time.perf_counter_ns()
        # A corpus built by hand (or any record that predates the field) has no retail
        # target path; resolve it from the project instead of dying with KeyError
        # after a capture that already cost a compiler run.
        target = inputs[symbol].get('target')
        if not target:
            target = project.target_object_for(project.resolve(symbol))
            if target is None:
                raise ValueError(f'{symbol}: capture corpus record has no retail target')
        target_words = oracle.words(Path(target), job['name'])
        constraints = mwconstraints.target_mapping(target_words, baseline_words)
        projections = []
        if constraints['status'] == 'fixed-graph-hypothesis':
            constraints['graphs'] = mwconstraints.constrain(result['captures'], constraints['mapping'])
            for capture, witness in zip(result['captures'], constraints['graphs']):
                candidate = mwconstraints.declaration_projection(
                    Path(inputs[symbol]['source']).read_text(), job['name'], capture, witness)
                if candidate is not None:
                    projections.append(candidate)
        target_ns = time.perf_counter_ns() - start
        if projections:
            for i, candidate in enumerate(dict.fromkeys(projections)):
                (output / (symbol.replace(':', '__') + f'.projection-{i}.c')).write_text(candidate)
        rows.append({'symbol': symbol, 'compiler': job['compiler'],
                     'source_sha256': inputs[symbol]['sha256'], 'same_code': same_code,
                     'same_object': same_object, 'object_percent': object_percent,
                     'passes': len(result['captures']), 'active_nodes': count,
                     'replay_errors': errors, 'simplify_errors': simplify_errors,
                     'simplify_unsupported': simplify_unsupported, 'replay_ns': replay_ns,
                     'baseline_order_witnesses': witnesses, 'inverse_ns': inverse_ns,
                     'target_constraints': constraints, 'target_ns': target_ns,
                     'source_projections': len(set(projections))})
    report = {'capture_seconds': capture_seconds, 'functions': rows}
    (output / ('replay-report.json' if args.replay else 'report.json')).write_text(json.dumps(report, indent=2) + '\n')
    failures = sum(bool(r.get('error') or not r.get('same_code') or not r.get('same_object')
                        or r.get('replay_errors') or r.get('simplify_errors')) for r in rows)
    print(json.dumps({'functions': len(rows), 'capture_seconds': capture_seconds, 'errors': failures,
                      'unsupported_simplify': sum(len(r.get('simplify_unsupported', [])) for r in rows)}), flush=True)
    return dict(report, errors=failures)
