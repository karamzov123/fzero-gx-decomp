"""One deterministic repair engine for sessions, lifters and whole saved corpora.

All generators share content-addressed compilation, scoring, search budgets and
verification. Source/evidence helpers never compile, search or submit independently.
"""
from __future__ import annotations

from collections import defaultdict
import contextlib
import os
import gzip
import hashlib
import itertools
import json
import re
from pathlib import Path
import shlex
import struct
import time

from . import fixup_evidence as evidence, fixup_layout as layout, fixup_source as source, mwgraph, oracle, poolfix, reuse
from .project import ROOT, STATE_DIR, Project


def digest(value):
    return hashlib.sha256(value).hexdigest()


def source_text(path):
    """Read content-addressed C without normalizing MWCC preprocessor CRLFs."""
    return Path(path).read_bytes().decode('utf-8')


_ENGINE = None


def _generate_in_worker(task):
    """Run one seed's proposal generator in a forked worker: the seed's check result, target
    words and own words come from the parent, which computed them after this process forked."""
    seed, capture, check, target, words, limit = task
    _ENGINE.checks[seed['id']] = check
    _ENGINE.words[seed['id']] = words
    _ENGINE.targets[seed['symbol']] = target
    out = []
    try:
        for label, text in _ENGINE.proposals(seed, capture):
            out.append((label, text))
            if len(out) >= limit * 10:
                break
        return _ENGINE.prioritise(seed, out)[:limit]
    except Exception:
        # a generator fault in one seed must not push the whole round to serial generation;
        # the traceback goes next to the report for repair
        import traceback
        (_ENGINE.output / 'generator_faults.log').open('a').write(f"{seed['symbol']} {seed['id'][:12]}\n{traceback.format_exc()}\n")
        return _ENGINE.prioritise(seed, out)[:limit] if out else []


class Engine:
    def __init__(self, project, output, verbose=False):
        self.project, self.output, self.verbose = project, output, verbose
        self.linkable_only = False
        from . import fixup_gc
        fixup_gc.guard(STATE_DIR)
        self._retention_lease = fixup_gc.acquire(output)
        self.generator_sha256 = digest(Path(__file__).read_bytes() + Path(source.__file__).read_bytes() + Path(evidence.__file__).read_bytes() + Path(layout.__file__).read_bytes() + Path(mwgraph.__file__).read_bytes() + b''.join((ROOT/'tools/fzgx'/name).read_bytes() for name in ('signatures.py','evidence.py','dataimport.py','lift.py','reuse.py','sdkimport.py')))
        output.mkdir(parents=True, exist_ok=True)
        self.headers = mwgraph.header_fingerprint(ROOT, project.version)
        self.environment = digest(('region-frontier-v3-bound-responses' + self.headers + ''.join(digest((ROOT/'tools/fzgx'/f).read_bytes()) for f in
            ('oracle.py', 'poolfix.py', 'project.py', 'regflow.py', 'evidence.py')) +
            digest((ROOT/'config'/project.version/'ldscript.tpl').read_bytes())).encode())
        self.cache_path = output / 'cache.json'
        self.cache = json.loads(self.cache_path.read_text()) if self.cache_path.exists() else {}
        self.targets, self.words, self.checks, self.compilers = {}, {}, {}, {}
        provenance = ROOT/'state/repairs/fixup_imports.json'
        self.rejected = json.loads(provenance.read_text()) if provenance.exists() else {}
        self.compiled = self.cached = 0
        self._new_sources = 0
        self.compile_seconds = 0.0
        self.clones, self.clone_skips, self.clone_shared, self.clone_independent = [], [], set(), set()
        self.declarations = reuse.Declarations(self)

    def __del__(self):
        fd = getattr(self, '_retention_lease', None)
        if fd is not None:
            with contextlib.suppress(OSError):
                os.close(fd)
            self._retention_lease = None

    def emit(self, value):
        if self.verbose:
            print(json.dumps(value), flush=True)

    def matched_symbols(self, history):
        targets={r['symbol'] for group in self.clones for r in group['members'] if r['status']=='unmatched'}
        return {r['symbol'] for r in history if r.get('matched') and (not self.clones or r['symbol'] in targets)}

    def record(self, symbol, body, mw=None, flags=None, **metadata):
        sym = self.project.resolve(symbol)
        if sym is None:
            raise ValueError(f'unknown or ambiguous symbol: {symbol}')
        symbol = self.project.key(sym)
        mw = mw or oracle.module_flags(self.project, sym.module)[1]
        flags = flags or ''
        if mw not in self.compilers:
            self.compilers[mw] = digest((ROOT/'build/compilers'/mw/'mwcceppc.exe').read_bytes())
        if symbol not in self.targets:
            path = self.project.target_object_for(sym)
            if path is None:
                raise ValueError(f'{symbol}: missing retail object')
            self.targets[symbol] = (path, oracle.words(path, sym.name), digest(path.read_bytes()))
        target, words, target_hash = self.targets[symbol]
        if not words or len(words)*4 != sym.size:
            raise ValueError(f'{symbol}: invalid retail target size')
        sha = digest(body.encode())
        identity = digest(json.dumps([self.environment, symbol, sha, mw, flags, oracle.module_flags(self.project, sym.module)[0], self.compilers[mw], target_hash]).encode())
        path = self.output / 'sources' / (identity[:24]+'.c')
        path.parent.mkdir(exist_ok=True)
        if not path.exists():
            if self._new_sources % 128 == 0:
                from .fixup_gc import guard
                guard(STATE_DIR)
            path.write_text(body)
            self._new_sources += 1
        elif digest(path.read_bytes()) != sha:
            raise ValueError(f'changed content-addressed source: {path}')
        return dict(metadata, symbol=symbol, source=str(path), sha256=sha, mw=mw, flags=flags,
                    target=str(target), id=identity)

    timing = {}

    def generate_parallel(self, tasks, limit):
        """[(label, text)...] per task, generated 16 wide in forked workers; serial when a pool
        cannot be used (the generator is identical either way)."""
        global _ENGINE
        if len(tasks) < 2:
            for _, seed, cap in tasks:
                self.check(seed)
            return [self.prioritise(seed, list(itertools.islice(self.proposals(seed, cap), limit * 10)))[:limit] for _, seed, cap in tasks]
        for _, seed, cap in tasks:
            self.check(seed)
        jobs=[(seed, cap, self.checks[seed['id']], self.targets[seed['symbol']], self.words.get(seed['id']), limit) for _, seed, cap in tasks]
        try:
            import multiprocessing
            from concurrent.futures import ProcessPoolExecutor
            _ENGINE = self
            with ProcessPoolExecutor(max_workers=min(oracle.COMPILE_WORKERS, len(jobs)), mp_context=multiprocessing.get_context('fork')) as ex:
                return list(ex.map(_generate_in_worker, jobs, chunksize=1))
        except (OSError, RuntimeError, ValueError, TypeError, ImportError, AttributeError) as error:
            self.emit({'stage': 'generate-serial', 'reason': str(error)[:200]})
            return [self.prioritise(seed, list(itertools.islice(self.proposals(seed, cap), limit * 10)))[:limit] for _, seed, cap in tasks]
        finally:
            _ENGINE = None

    def row_lines(self, seed):
        """{differing row index: source line} for the seed (MWCC's `.line` table from a
        `-sym on` compile of the same source; the code is byte-identical). A retail-only
        row takes the line of the nearest row of ours."""
        from . import linemap
        key = seed['id']
        memo = self.__dict__.setdefault('_row_lines', {})
        if key in memo:
            return memo[key]
        check = self.checks.get(key)
        out = {}
        try:
            if check is not None and check.ok:
                sym = self.project.resolve(seed['symbol'])
                obj = Path(seed['object']).with_suffix('.sym.o')
                if not obj.exists():
                    flags = ' '.join(x for x in [seed.get('flags') or '', '-sym on'] if x)
                    oracle.compile_source(self.project, sym.module, Path(seed['source']), obj, seed.get('mw'), flags)
                table = linemap.tables(obj).get(sym.name, []) if obj.exists() else []
                lrows, rrows = check._rows
                accepted = getattr(check, '_accepted_rows', set())
                for k, (a, b) in enumerate(zip(lrows, rrows)):
                    if k in accepted or (a.get('diff_kind') or 'DIFF_NONE') == 'DIFF_NONE' and (b.get('diff_kind') or 'DIFF_NONE') == 'DIFF_NONE':
                        continue
                    for j in (k, k - 1, k + 1):
                        if 0 <= j < len(rrows):
                            ins = rrows[j].get('instruction') or {}
                            if ins.get('address') is not None:
                                ln = linemap.line_of(table, int(ins['address']))
                                if ln:
                                    out[k] = ln
                                    break
        except Exception:
            out = {}
        memo[key] = out
        return out

    def implicated_lines(self, seed):
        return {ln + d for ln in self.row_lines(seed).values() for d in (-1, 0, 1)}

    def prioritise(self, seed, proposals):
        """Candidates that edit an implicated line (or only declarations and pragmas) first,
        in their family order; edits confined to statements that already match go last."""
        lines = self.implicated_lines(seed)
        if not lines:
            return proposals
        import difflib
        text0 = source_text(seed['source'])
        body = text0.splitlines()
        name = self.project.resolve(seed['symbol']).name
        span = source._function_body_span(text0, name)
        first_stmt = None
        if span:
            decls = source._locals(text0, span)
            first_stmt = text0[:decls[-1][1]].count('\n') + 2 if decls else text0[:span[1]].count('\n') + 2
        relevant, rest = [], []
        for label, text in proposals:
            changed = set()
            new = text.splitlines()
            for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, body, new, autojunk=False).get_opcodes():
                if tag != 'equal':
                    changed.update(range(i1 + 1, max(i2, i1 + 1) + 1))
            if not changed or changed & lines or (first_stmt and all(c < first_stmt for c in changed)):
                relevant.append((label, text))
            else:
                rest.append((label, text))
        return relevant + rest

    def evaluate(self, rows):
        groups = defaultdict(list)
        unique = {r['id']: r for r in rows}
        for row in unique.values():
            cached = self.cache.get(row['id'])
            if cached and (not cached.get('object') or cached.get('word_errors') is not None and Path(cached['object']).exists()):
                row.update(cached); self.cached += 1
                if row.get('object'):
                    self.words[row['id']] = oracle.words(Path(row['object']), self.project.resolve(row['symbol']).name)
                continue
            sym = self.project.resolve(row['symbol'])
            # `flags` reaches here as a list from some saved-candidate records and as a
            # string from others. A list made this group key unhashable and crashed the whole
            # corpus build; a tuple then reached the shell layer, which shlex-splits it.
            # Join to the string form the rest of the engine already expects, so records
            # spelled either way group and compile identically.
            flags = row['flags']
            if not isinstance(flags, str):
                flags = ' '.join(str(f) for f in (flags or []))
            groups[sym.module, row['mw'], flags].append(row)
        tick = time.monotonic()
        progress = time.monotonic()
        # every (module, compiler, flags) group used to be one serial mwcc process over a
        # handful of sources (117 ms each); all groups now share one 16-wide chunk pool
        jobs = []
        total = sum(len(pending) for pending in groups.values())
        # small chunks: the pool's wall time is its slowest chunk, and one slow candidate
        # (a large initializer, an optimizer blow-up) must not hold up a sixteenth of the round
        per = min(48, max(oracle.COMPILE_CHUNK, (total + oracle.COMPILE_WORKERS - 1) // oracle.COMPILE_WORKERS))
        for (module, mw, flags), pending in groups.items():
            group = digest(json.dumps([module,mw,flags]).encode())[:16]
            cmd = oracle.compile_command(self.project, module, mw, flags)
            sources = [Path(r['source']) for r in pending]
            for i in range(0, len(sources), per):
                jobs.append((cmd, sources[i:i + per], self.output/'objects'/group))
        objects = {}
        pool_tick = time.monotonic()
        if len(jobs) > 1:
            from concurrent.futures import ThreadPoolExecutor
            with ThreadPoolExecutor(max_workers=oracle.COMPILE_WORKERS) as ex:
                for result in ex.map(lambda j: oracle.compile_chunk(*j), jobs):
                    objects.update(result)
        elif jobs:
            objects.update(oracle.compile_chunk(*jobs[0]))
        self.timing['compile-pool'] = self.timing.get('compile-pool', 0) + time.monotonic() - pool_tick
        score_tick = time.monotonic()
        for (module, mw, flags), pending in groups.items():
            self.compiled += len(pending)
            for row in pending:
                obj = objects.get(Path(row['source']))
                words = oracle.words(obj, self.project.resolve(row['symbol']).name) if obj else None
                target = self.targets[row['symbol']][1]
                self.words[row['id']] = words
                row.update(object=str(obj) if words else None, score=source.fitness(target, words)[0] if words else -1,
                           bit_errors=(sum((a^b).bit_count() for a,b in zip(target,words))+32*abs(len(target)-len(words))) if words else 10**9)
                row['word_errors'] = source.distance(target, words) if words else None
                row['shape_errors'] = source.distance(source.instruction_shapes(target),source.instruction_shapes(words)) if words else None
                row['aligned_word_percent'] = row['score']
                row['response_sha256'] = self.response_hash(obj, words) if words else None
                if row['score'] == 100:
                    # A word-identical candidate is not yet a match. Its private literal
                    # pool still binds to our own anonymous rodata, so objdiff reports the
                    # relocation rows as differing and the module linker then sees the
                    # primer's private BSS copies as multiply-defined. oracle.check
                    # retargets those literals (`poolfix.apply`) and drops the `.fzgxpool`
                    # primer on all three of its paths; this scoring path calls
                    # `oracle._diff` directly and so did neither, which is how a body
                    # reading 100% here reaches the link and comes back link-mismatch.
                    # Do the same repair here, and keep it only if the re-diff still
                    # matches, so a failed experiment never leaves a mutilated object.
                    self.retarget_pool(row)
                    check = self.check(row)
                    row['matched'] = bool(check.matched or check.matched_pool)
                    row['binding_score'] = check.percent_adjusted
                self.cache[row['id']] = {k:row[k] for k in ('object','score','bit_errors','matched','binding_score','word_errors','shape_errors','aligned_word_percent','response_sha256') if k in row}
            if time.monotonic()-progress >= 10:
                self.cache_path.write_text(json.dumps(self.cache))
                self.emit({'stage': 'compile', 'compiled': self.compiled, 'cached': self.cached})
                progress = time.monotonic()
        self.timing['score-loop'] = self.timing.get('score-loop', 0) + time.monotonic() - score_tick
        self.compile_seconds += time.monotonic()-tick
        cache_tick = time.monotonic()
        self.cache_path.write_text(json.dumps(self.cache))
        self.timing['cache-write'] = self.timing.get('cache-write', 0) + time.monotonic() - cache_tick
        self.emit({'stage': 'evaluate-timing', **{k: (round(v, 2) if isinstance(v, float) else v) for k, v in self.timing.items()}, 'jobs': len(jobs), 'pending': total})
        for row in rows:
            row.update({k:v for k,v in unique[row['id']].items() if k in ('object','score','bit_errors','matched','binding_score','word_errors','shape_errors','aligned_word_percent','response_sha256')})
            row.pop('frame_layout_only',None)
            target=self.targets[row['symbol']][1];words=self.words.get(row['id'])
            if words and len(words)==len(target) and row['score']<100:
                changed=[(t,o) for t,o in zip(target,words) if t!=o]
                if (changed and any(t>>26==37 and (t>>21)&31==1 for t,_ in changed) and
                        all((t^o)&0xffff0000==0 and (t>>16)&31==1 and t>>26 in (14,32,36,37,46,47,50,54) for t,o in changed)):
                    row['frame_layout_only']=evidence.frame_layout_only(self.check(row))
            # An exact function diff ignores other emitted functions. REL links
            # retain static helper copies, shifting text and dependent modules.
            sym = self.project.resolve(row['symbol'])
            if row.get('matched') and row.get('object'):
                from .poolfix import Elf
                elf = Elf(Path(row['object']).read_bytes())
                extras = [s['name'] for s in elf.symbols() if s['info'] & 15 == 2 and s['shndx'] and s['size'] and s['name'] != sym.name
                          and not (0 < s['shndx'] < len(elf.sections) and elf.sections[s['shndx']]['name'] == '.fzgxpool')]
                if extras:
                    row.update(matched=False, object_matched=True, extra_helpers=extras)
            if row.get('matched') and row.get('object'):
                from .poolfix import Elf
                from .carve import exclusive_data
                elf = Elf(Path(row['object']).read_bytes())
                targets = dict(self.project.symbols(sym.module))
                targets.update({f'{s.name}_{s.addr:08X}': s for s in list(targets.values())})
                definitions = [targets[s['name']] for s in elf.symbols()
                               if s['name'] in targets and s['size'] and 0 < s['shndx'] < len(elf.sections)
                               and elf.sections[s['shndx']]['name'] in ('.bss', '.sbss')]
                if definitions:
                    fn = self.project.function(row['symbol'])
                    owned = {s.name for group in exclusive_data(self.project, fn).values() for s in group} if fn else set()
                    mapped = {target for _, target, _ in getattr(self.check(row), '_pool_pairs', [])}
                    shared = [s.name for s in definitions if s.name not in owned and s.name not in mapped]
                    if shared:
                        row.update(matched=False, object_matched=True, extra_data=shared)
            if row.get('matched') and row.get('object') and layout.unused_bss_definitions(
                    self.project, row['symbol'], source_text(row['source']), row['object'], self.check(row)):
                # A function-only oracle match must not hide unused generated
                # storage that still changes the linked module's BSS extent.
                row.update(matched=False, object_matched=True, extra_unused_bss=True)
            if row.get('matched'):
                from .lint import allocator_scaffolding, lint_file
                findings = lint_file(Path(row['source']))
                if findings:
                    row.update(matched=False, object_matched=True, source_lint=findings)
                if allocator_scaffolding(source_text(row['source'])):
                    row.update(matched=False, object_matched=True, allocator_scaffolding=True)
            if self.linkable_only and row.get('matched') and self.check(row).matched_pool:
                row.update(matched=False, pool_only=True)
            failed = self.rejected.get(row['symbol'], {})
            if (failed.get('link') == 'rejected' and failed.get('generated_sha256') == row['sha256']
                    and failed.get('compiler') == row['mw'] and (failed.get('flags') or '') == row['flags']
                    and failed.get('headers_sha256') == self.headers
                    and failed.get('oracle_sha256') == digest(Path(oracle.__file__).read_bytes())):
                row.update(matched=False, link_rejected=True)

    def retarget_pool(self, row):
        """Bind a winning candidate's private literals to retail's, in place.

        A word-identical body can still differ on every row that reads a literal: ours
        binds to our own anonymous rodata, retail's to a pooled symbol. `poolfix.apply`
        rewrites those relocations and drops the `.fzgxpool` primer (whose private BSS
        copies the module linker rejects as multiply-defined). Returns True when the
        object now diffs clean.

        The object is restored when the repair does not produce a match, so a failed
        experiment never leaves a mutilated object behind, and the memo keyed on the
        compiler response is refreshed either way: retargeted and raw objects
        must never share a verdict under the raw compiler response's hash.
        """
        obj = row.get('object')
        if not obj:
            return False
        check = self.check(row)
        if check.matched or not check.ok:
            return False
        pairs = getattr(check, '_pool_pairs', None)
        if not pairs:
            return self._drop_primer_only(row)
        backup = Path(obj).read_bytes()
        result = poolfix.apply(Path(obj), {private: pooled for private, pooled, _ in pairs})
        self._forget(row)
        if result['skipped'] or not result['rodata_emptied'] or not self.check(row).matched:
            Path(obj).write_bytes(backup)
            self._forget(row)
            return False
        row['pool_map'] = {private: pooled for private, pooled, _ in pairs}
        return True

    def _drop_primer_only(self, row):
        """Drop a primer with no literals to retarget; oracle.check:243's case."""
        obj = row.get('object')
        if not obj or not oracle._has_primer(Path(obj)):
            return False
        backup = Path(obj).read_bytes()
        if not poolfix.drop_primer(Path(obj)):
            return False
        self._forget(row)
        if self.check(row).matched:
            return True
        Path(obj).write_bytes(backup)
        self._forget(row)
        return False

    def _forget(self, row):
        """Refresh a mutated object's response and drop its old objdiff verdicts."""
        self.checks.pop(row['id'], None)
        memo = self.__dict__.setdefault('_response_checks', {})
        for key in [k for k in memo if k[0] == row['symbol']]:
            del memo[key]
        obj = Path(row['object'])
        row['response_sha256'] = self.response_hash(obj, self.words[row['id']])

    def check(self, row):
        if row['id'] not in self.checks:
            # identical compiler responses (code, data and bindings) diff identically: one
            # objdiff run per response instead of one per candidate spelling
            memo = self.__dict__.setdefault('_response_checks', {})
            key = (row['symbol'], row.get('response_sha256'))
            if key[1] and key in memo:
                self.checks[row['id']] = memo[key]
            else:
                sym = self.project.resolve(row['symbol'])
                self.checks[row['id']] = oracle._diff(self.project, sym.module, sym.name, '', 0,
                                                    target=self.targets[row['symbol']][0], base=Path(row['object']))
                if key[1]:
                    memo[key] = self.checks[row['id']]
        result = self.checks[row['id']]
        row.update(percent=result.percent if result.ok else 0,
                   raw_percent=result.percent if result.ok else 0,
                   percent_adjusted=result.percent_adjusted if result.ok else 0,
                   differing_rows=result.differing_rows, instruction_rows=result.instruction_rows,
                   value_conflicts=len(result.value_flow), pool_rows=result.pool_rows)
        if result.ok:
            from .regflow import region_scores
            row['regions']=region_scores(*result._rows,getattr(result,'_accepted_rows',()))
        return result

    def response_hash(self, obj, words):
        """Identical code with different data or bindings is a different response."""
        from .poolfix import Elf
        elf = Elf(obj.read_bytes()); symbols = elf.symbols()
        sections = []
        for section in elf.sections:
            if section['flags'] & 2 and section['name'] != '.text':
                payload = bytes(elf.data[section['offset']:section['offset'] + section['size']]).hex() if section['type'] != 8 else ''
                sections.append((section['name'], section['size'], payload))
            elif section['type'] == 4:
                bindings = []
                for offset in range(section['offset'], section['offset'] + section['size'], 12):
                    at, info, addend = struct.unpack_from('>IIi', elf.data, offset)
                    sym = symbols[info >> 8]
                    bindings.append((at, info & 255, sym['name'], addend))
                sections.append((section['name'], bindings))
        # A section-base load has no relocation against each named member.
        # Their definitions still control ownership and subobject proofs.
        definitions = [(s['name'], s['value'], s['size'], s['info'], elf.sections[s['shndx']]['name'])
                       for s in symbols if 0 < s['shndx'] < len(elf.sections)
                       and elf.sections[s['shndx']]['flags'] & 2]
        return digest(json.dumps([words, sections, definitions]).encode())

    def frontier(self, history, beam):
        groups = defaultdict(list)
        winners = {r['symbol'] for r in history if r.get('matched')}
        for row in history:
            if row['symbol'] not in winners and row.get('object'):
                groups[row['symbol']].append(row)
        result = defaultdict(list)
        for symbol, rows in groups.items():
            by_words = sorted(rows, key=lambda r:(r['word_errors'], -r['score'], r['bit_errors'], r['id']))
            measured = [r for r in rows if 'raw_percent' in r]
            preferred = []
            measured_regions=[r for r in measured if r.get('regions')]
            region_winners={}
            for candidate in measured_regions:
                for key,score in candidate['regions'].items():
                    previous=region_winners.get(key)
                    if previous is None or (tuple(score),candidate['word_errors'])<(tuple(previous['regions'][key]),previous['word_errors']):
                        region_winners[key]=candidate
            reference=by_words[0].get('regions',{})
            benefits=defaultdict(int)
            for key,winner in region_winners.items():
                if key in reference and (tuple(winner['regions'][key][:2])<tuple(reference[key][:2])
                        or (not winner['regions'][key][2] and reference[key][2])):
                    benefits[winner['id']]+=1
            preferred.extend(sorted((r for r in measured_regions if r['id'] in benefits),
                                    key=lambda r:(-benefits[r['id']],r['shape_errors'],r['word_errors']))[:max(1,beam-2)])
            bridges = [r for r in rows if any(r.get(k) for k in ('value_flow_fixed','argument_flow_fixed','pool_layout_fixed','frame_layout_only'))]
            if bridges:
                preferred.append(min(bridges, key=lambda r:(-r.get('pool_coverage',0), r['word_errors'], -r['score'])))
            preferred.append(by_words[0])
            # a structural correction (a kernel, an induction index, a call inlined) first
            # perturbs register numbers and lowers the word score; its opcode shape improves.
            # Keep the best-by-shape candidate so the allocator families can finish it.
            shaped = [r for r in rows if r.get('shape_errors') is not None]
            if shaped:
                preferred.append(min(shaped, key=lambda r:(r['shape_errors'], r['word_errors'], r['id'])))
            if measured:
                preferred.append(min(measured,key=lambda r:(r['differing_rows'], -r['raw_percent'],r['id'])))
                preferred.append(max(measured,key=lambda r:(r['raw_percent'], -r['differing_rows'],r['id'])))
            preferred += sorted(rows,key=lambda r:(-r['score'],r['bit_errors'],r['id']))
            shapes = set()
            for row in preferred:
                shape = row['response_sha256']
                if shape in shapes:
                    continue
                shapes.add(shape); result[symbol].append(row)
                if len(result[symbol]) == beam:
                    break
        return result

    def proposals(self, row, capture=None, max_orders=50000):
        body = source_text(row['source'])
        name = self.project.resolve(row['symbol']).name
        families = []
        deferred_graph = []
        operators = {}
        captured_operators = []
        check = self.check(row)
        if self.linkable_only:
            if check.ok:
                yield from layout.legacy_pool_primer_sections(body, row.get('object'))
                yield from evidence.relocation_bindings(body, check)
                yield from layout.bss_member_bindings(self.project, row['symbol'], body, row.get('object'), check)
                yield from layout.split_bss_primer_arrays(self.project, row['symbol'], body, row.get('object'), check)
                yield from layout.unused_bss_primer_objects(self.project, row['symbol'], body, row.get('object'), check)
                yield from layout.unused_bss_definitions(self.project, row['symbol'], body, row.get('object'), check)
                yield from layout.private_data_objects(body, row.get('object'), check)
                yield from layout.unused_pool_objects(self.project, row['symbol'], body, row.get('object'), check)
                if row.get('extra_helpers'):
                    yield from source.inline_helpers(body, name, set(row['extra_helpers']))
            return
        if check.ok:
            yield from layout.legacy_pool_primer_sections(body, row.get('object'))
            yield from layout.initialized_base_order(self.project, row['symbol'], body, row.get('object'), check)
            yield from evidence.range_switches(body, name, check)
            yield from layout.native_string_views(self.project, row['symbol'], body)
            yield from evidence.swapped_call_arguments(self.project, row['symbol'], body, check)
            yield from layout.overlapping_field_views(self.project, row['symbol'], body)
            yield from evidence.relocation_bindings(body, check)
            yield from layout.bss_member_bindings(self.project, row['symbol'], body, row.get('object'), check)
            yield from layout.unused_bss_definitions(self.project, row['symbol'], body, row.get('object'), check)
            yield from layout.private_data_objects(body, row.get('object'), check)
        yield from source.split_declaration_groups(body, name)
        yield from source.accessor_lifetimes(body, name)
        if row.get('score') == 100:
            if row.get('source_lint') and (check.matched or check.matched_pool):
                yield from source.annotate_verified_branches(body, row['source_lint'])
            yield from source.inline_helpers(body,name)
            for helper in row.get('extra_helpers', []):
                if self.project.find_symbol(helper, self.project.resolve(row['symbol']).module):
                    yield from source.external_helper(body,helper)
                    yield from source.split_helper_calls(body,helper)
        if capture:
            constraints = source.web_constraints(capture, self.targets[row['symbol']][1], self.words[row['id']],check)
            decoded = source.decode(self.words[row['id']])
            captured_operators = [decoded[index][0] for index in constraints.get('operand_order_rows', [])]
            decls, _ = source.declaration_candidates(body, name, capture, constraints, max_orders)
            graph = [('graph declaration-order',t) for t in decls]
            carriers = source.carrier_candidates(body,name,capture,constraints)
            scoped = source.scoped_carrier_candidates(body,name,capture,constraints)
            # Large declaration graphs must not consume the entire budget
            # before semantic, ABI and lifetime repairs get a compiler check.
            yield from graph[:32]
            yield from carriers[:32]
            yield from scoped[:32]
            deferred_graph.extend((graph[32:],carriers[32:],scoped[32:]))
        if check.ok:
            yield from evidence.aggregate_initializers(self.project, row['symbol'], body, check)
            yield from evidence.native_pool_objects(self.project, row['symbol'], body, check)
            yield from evidence.shared_pool_primer(self.project, row['symbol'], body, check)
            yield from evidence.frame_padding(self.project, row['symbol'], body, check)
            yield from layout.initialized_data_views(self.project, row['symbol'], body)
            yield from layout.tu_section_layout(self.project, row['symbol'], body, check)
            if re.search(r'(?m)^\s*#define\b', body):
                # Pool fields passed through macro parameters only have a
                # concrete type and offset after the selected compiler expands them.
                try:
                    expanded = self.declarations.expand(row)
                except (ValueError, OSError) as error:
                    self.emit(dict(stage='pool-expansion-rejected',symbol=row['symbol'],error=str(error)))
                else:
                    yield from evidence.native_pool_objects(self.project, row['symbol'], expanded, check)
                    yield from layout.initialized_data_views(self.project, row['symbol'], expanded)
                    yield from layout.tu_section_layout(self.project, row['symbol'], expanded, check)
            yield from evidence.conversion_arguments(self.project, row['symbol'], body, check)
            yield from evidence.rotate_bit_tests(body, name, check)
            yield from evidence.call_result_types(self.project, row['symbol'], body, check)
            yield from evidence.floating_expressions(self.project, row['symbol'], body, check)
            yield from evidence.paired_vector_kernels(self.project, row['symbol'], body, check)
            yield from evidence.attributed_type_flips(self.project, row['symbol'], body, check, self.row_lines(row))
            yield from evidence.attributed_inlines(self.project, row['symbol'], body, check, self.row_lines(row))
            yield from evidence.attributed_declaration_swaps(self.project, row['symbol'], body, check, self.row_lines(row))
            yield from evidence.induction_indexing(self.project, row['symbol'], body, check)
            # structural spellings that change a web's numbering class (carriers, de-CSE,
            # held call results, splits) go before any declaration permutation: order within
            # a class is only worth searching once the class is right
            yield from [('regalloc: ' + l, t) for l, t in source.rewrites(body, name)]
            yield from evidence.fusion_control(self.project, row['symbol'], body, check)
            yield from evidence.encoded_conversions(self.project, row['symbol'], body, check)
            yield from evidence.scalar_lifetimes(self.project, row['symbol'], body, check)
            yield from evidence.stack_object_boundaries(self.project, row['symbol'], body, check)
            yield from source.comparison_lifetimes(body, name)
            yield from source.scalar_square_lifetimes(body, name)
            yield from evidence.optimizer_pragmas(body, name)
            families.append(evidence.candidates(self.project, row['symbol'], body, check))
            # 'retain recovered shared-pool bases' and 'lifetime shared-pool read' never improved a
            # candidate over twelve corpus reports (0 of 1,141 and 0 of 594): they no longer take
            # candidate-cap slots ahead of the productive families
            targeted = [[c for c in families[0] if c[0].startswith(('retail parameter copy', 'retail scalar flag masks', 'retail format argument', 'retail call argument', 'retail call parameter', 'retail argument order:', 'retail float branch', 'retail zero comparison', 'bind recovered shared-pool', 'recover native shared-pool', 'lifetime reload', 'lifetime ordered'))],
                        source.address_expressions(body, name), source.pointer_lifetimes(body, name), source.through_local(body, name),
                        source.wide_member_values(body,name),source.promoted_locals(body,name),source.returned_regions(body,name),source.reuse_temporaries(body,name),source.initialization_orders(body,name),source.flag_stores(body,name),source.loop_lifetimes(body,name)]
            operand_types = {'and':('&',('u32','s32')), 'or':('|',('u32','s32')),
                             'xor':('^',('u32','s32')), 'mullw':('*',('u32','s32')),
                             'fadd':('+',('f64',)), 'fadds':('+',('f32',)),
                             'fmul':('*',('f64',)), 'fmuls':('*',('f32',))}
            for operation in [order['target'].split()[0] for order in check.operand_order] + captured_operators:
                kind = operand_types.get(operation.rstrip('.'))
                if kind:
                    types = operators.setdefault(kind[0],[])
                    types.extend(ty for ty in kind[1] if ty not in types)
            if operators:
                targeted.append(source.operand_lifetimes(body,name,operators))
            if any(word.startswith(('fmul', 'fdiv')) for word in captured_operators) or any(
                    order['target'].startswith(('fmul', 'fdiv')) for order in check.operand_order):
                targeted.append(source.reciprocal_products(body, name))
            policies = []
            for family in targeted:
                for label, text in family:
                    if 'every site' in label or 'shared-pool' in label or label.startswith('lifetime operands'):
                        policies.extend((label+' with '+policy,combined) for policy,combined in evidence.optimizer_pragmas(text,name))
            targeted.append(policies)
            for i in range(max(map(len, targeted), default=0)):
                for family in targeted:
                    if i < len(family):
                        yield family[i]
            # Concrete stores/frame fixes precede generic declaration and flag
            # probes. They used to be buried beyond a session's candidate cap.
            yield from [c for c in families[0] if c[0].startswith(('retail store-value', 'retail format argument', 'retail call argument', 'pack stack', 'imm ', 'swap fields', 'recover aggregate', 'recover member', 'interior ', 'bind hardware'))]
            # Layout/type repairs can increase register differences while fixing
            # the actual memory access or extension. Probe their optimizer
            # interactions before the word-score frontier discards them.
            has_extensions = evidence._kinds(check).get('ins:ext')
            for label, text in families[0]:
                if label.startswith('recover member') or (has_extensions and ':' in label and '->' in label and ' at ' not in label):
                    for policy, combined in evidence.optimizer_pragmas(text, name):
                        yield label + ' with ' + policy, combined
            if check.operand_order or captured_operators:
                commuted=source.commutations(body,name)
                commuted.sort(key=lambda c:not c[0].startswith('coupled scalar operands'))
                # An optimizer can canonicalize both source spellings to the
                # same object. Such zero-response edits disappear from the beam
                # and from linear composition; probe their policy interaction.
                for i,(label,text) in enumerate(commuted):
                    yield label,text
                    if i<8:
                        for policy,combined in evidence.optimizer_pragmas(text,name):
                            yield label+' with '+policy,combined
        families.extend(deferred_graph)
        families.extend([source.missing_values(body,name), source.expression_trees(body,name),
                         source.commutations(body,name), source.probes(body,name,64),
                         [(family+': '+label,text) for family,label,text in source.all_rewrites(body,name)]])
        # Inlined helpers contribute instructions and stack lifetimes to this
        # function. Restricting rewrites to the outer body leaves those regions
        # unreachable even though the same existing generators can repair them.
        for helper in re.findall(r'\bstatic\s+inline\s+[\w *]+?\b(\w+)\s*\([^;{}]*\)\s*\{', body):
            if helper == name:
                continue
            variants = (source.pointer_lifetimes(body,helper) + source.loop_lifetimes(body,helper)
                        + source.initialization_orders(body,helper) + source.reuse_temporaries(body,helper)
                        + source.commutations(body,helper) + source.probes(body,helper,64))
            if capture:
                helper_decls, _ = source.declaration_candidates(body,helper,capture,constraints,max_orders)
                variants = source.carrier_candidates(body,helper,capture,constraints) + [('graph declaration-order',text) for text in helper_decls] + variants
            if operators:
                variants = source.operand_lifetimes(body,helper,operators) + variants
            variants += [(family+': '+label,text) for family,label,text in source.all_rewrites(body,helper)]
            families.insert(0, [('inline '+helper+': '+label,text) for label,text in variants])
        # Round-robin preserves access to each family within the shared budget.
        for i in range(max(map(len,families),default=0)):
            for family in families:
                if i < len(family):
                    yield family[i]

    def refresh_captures(self, frontier, captures):
        from types import SimpleNamespace
        layers=defaultdict(dict)
        for symbol,seeds in frontier.items():
            for rank,row in enumerate(seeds):
                key=(symbol,row['sha256'],row['mw'],row['flags'])
                if key in captures or self.compilers[row['mw']] not in mwgraph.PROFILES:
                    continue
                layers[rank][symbol]=row
        for rows in layers.values():
            key=digest(json.dumps(sorted(r['id'] for r in rows.values())).encode())[:12]
            directory=STATE_DIR/'fixup'/'graphs'/key
            directory.mkdir(parents=True,exist_ok=True)
            (directory/'inputs.json').write_text(json.dumps(rows))
            (directory/'results.json').write_text(json.dumps({s:{'baseline':{'object':r['object']}} for s,r in rows.items()}))
            output=directory/'capture'
            self.emit({'stage':'capture','functions':len(rows)})
            args=SimpleNamespace(corpus=directory,output=output,symbols=None,all_near=True,replay=(output/'report.json').exists())
            mwgraph.capture(self.project,args,locked=True)
            captures.update(load_captures(self,output,list(rows.values())))

    def transfer_clones(self, history, seen, transfers):
        originals = {row['id']: row for row, _ in transfers}
        expanded, pending = {}, []
        for row in originals.values():
            try:
                body = self.declarations.expand(row)
                flat = self.record(row['symbol'], body, row['mw'], row['flags'],
                    label='expand owned clone declarations', parent=row['id'], seed=row.get('seed', row['id']))
                expanded[row['id']] = flat
                if flat['id'] not in seen:
                    seen.add(flat['id']); pending.append(flat)
            except (ValueError, OSError) as error:
                self.clone_skips.append(dict(symbol=row['symbol'], source=row['sha256'], error=str(error)))
        self.evaluate(list(expanded.values()))
        history.extend(pending)
        pending, origins, proofs = [], {}, []
        existing = {r['id']: r for r in history}
        for row, target in transfers:
            flat = expanded.get(row['id'])
            # A preprocessor success is insufficient: __FILE__, compiler pragmas
            # and header definitions can change the actual compiled response.
            if not flat or flat.get('response_sha256') != row.get('response_sha256') or not flat.get('object'):
                self.clone_skips.append(dict(symbol=row['symbol'], source=row['sha256'], error='expanded declarations changed compiler response'))
                continue
            mapping = reuse.bindings(self.project, row['symbol'], target)
            try:
                native = reuse.storage_bindings(self.project, row['symbol'], target,
                                                flat['object'], self.check(flat))
            except (ValueError, OSError) as error:
                self.clone_skips.append(dict(symbol=row['symbol'], recipient=target,
                                             source=row['sha256'], error=str(error)))
                continue
            for name, rebound_name in native.items():
                if name in mapping and mapping[name] != rebound_name:
                    raise ValueError('clone code/storage bindings disagree: ' + name)
                mapping[name] = rebound_name
            body = reuse.rebind(source_text(flat['source']), mapping)
            rebound = self.record(target, body, row['mw'], row['flags'], label='bind exact clone',
                parent=flat['id'], seed=flat.get('seed', flat['id']),
                clone=dict(donor=row['symbol'], recipient=target, bindings=mapping,
                           native_storage=bool(native)))
            origins[rebound['id']] = row
            if rebound['id'] in seen:
                if rebound['id'] in existing:
                    proofs.append(existing[rebound['id']])
            else:
                seen.add(rebound['id']); pending.append(rebound); proofs.append(rebound)
        self.evaluate(pending)
        for row in proofs:
            donor = origins[row['id']]
            pair = donor['symbol'], row['symbol']
            if row.get('object'):
                self.check(row)
                if (self.words[row['id']] == self.words[donor['id']]
                        and abs(row['percent_adjusted'] - self.check(donor).percent_adjusted) < 0.00001):
                    if pair not in self.clone_independent:
                        self.clone_shared.add(pair)
                    continue
            self.clone_shared.discard(pair)
            self.clone_independent.add(pair)
        history.extend(pending)

    def share_clones(self, history, seen, beam, initial=False):
        def choices():
            result = self.frontier(history, beam)
            for row in history:
                if row.get('matched'):
                    result[row['symbol']] = [row]
            return result
        if initial:
            selected = choices(); transfers = []
            for group in self.clones:
                rep = group['representative']
                for member in group['members']:
                    if member['symbol'] != rep:
                        transfers.extend((row, rep) for row in selected.get(member['symbol'], []))
            self.transfer_clones(history, seen, transfers)
        selected = choices(); transfers = []
        for group in self.clones:
            rep = group['representative']
            for member in group['members']:
                if member['status'] == 'unmatched' and member['symbol'] != rep:
                    transfers.extend((row, member['symbol']) for row in selected.get(rep, []))
        self.transfer_clones(history, seen, transfers)
        self.emit(dict(stage='clones', families=len(self.clones), shared=len(self.clone_shared),
                       matches=len(self.matched_symbols(history))))

    def run(self, rows, rounds=2, beam=3, max_candidates=80, budget_s=None, captures=None, stop_on_match=False):
        start=time.monotonic(); history=list(rows); seen={r['id'] for r in rows}; initial={}
        self.evaluate(rows)
        for row in rows:
            if row.get('object'):
                self.check(row)
        self.emit({'stage': 'baseline', 'functions': len({r['symbol'] for r in rows}),
                   'variants': len(rows), 'compiled': self.compiled, 'cached': self.cached})
        for r in rows:
            initial[r['symbol']]=max(initial.get(r['symbol'],-1),r['score'])
        if self.clones:
            self.share_clones(history, seen, beam, initial=True)
        self.save(history, stats=[], start=start)
        stats=[]
        for step in range(rounds):
            if budget_s is not None and time.monotonic()-start >= budget_s:
                break
            frontier=self.frontier(history,beam)
            for group in self.clones:
                rep = group['representative']
                for member in group['members']:
                    key = member['symbol']
                    if key != rep and (rep, key) in self.clone_shared:
                        frontier.pop(key, None)
            if captures is not None:
                self.refresh_captures(frontier,captures)
            pending=[]; parents={}; generated=time.monotonic();progress=generated
            # candidate generation is pure Python per seed (about a third of a round): every
            # seed runs in a forked worker, the parent only records the results
            tasks=[(symbol, seed, (captures or {}).get((symbol,seed['sha256'],seed['mw'],seed['flags']))) for symbol, seeds in frontier.items() for seed in seeds]
            generated_lists=self.generate_parallel(tasks, max_candidates*2)
            for (symbol, seed, cap), proposals in zip(tasks, generated_lists):
                if True:
                    if budget_s is not None and time.monotonic()-start >= budget_s:
                        break
                    count=0
                    for label,text in proposals:
                        row=self.record(symbol,text,seed['mw'],seed['flags'],label=label,parent=seed['id'],seed=seed.get('seed',seed['id']))
                        if row['id'] in seen:
                            continue
                        seen.add(row['id']); pending.append(row);parents[seed['id']]=seed;count+=1
                        if count>=max_candidates:
                            break
                    if time.monotonic()-progress>=10:
                        self.emit({'stage':'generate','symbol':symbol,'candidates':len(pending)})
                        progress=time.monotonic()
            if not pending:
                break
            generation_seconds=time.monotonic()-generated
            self.evaluate(pending)
            progress=time.monotonic()
            def wants_check(row):
                return bool(row.get('object') and (row['label'].startswith(('retail conversion','retail floating','retail loop','retail double','retail call result','retail aggregate','recover native shared-pool objects','recover native BSS','region '))
                        or row['shape_errors']<parents[row['parent']]['shape_errors']
                        or source.closes_region(self.targets[row['symbol']][1],self.words[row['parent']],
                                                self.words[row['id']],parents[row['parent']].get('regions',{}))))
            # every check is one objdiff process: run them 16 wide before the serial passes read them
            from concurrent.futures import ThreadPoolExecutor
            need=[row for row in pending if wants_check(row) and row['id'] not in self.checks]
            need+=[seed for seed in parents.values() if seed.get('object') and seed['id'] not in self.checks]
            with ThreadPoolExecutor(max_workers=16) as ex:
                list(ex.map(self.check, need))
            for index,row in enumerate(pending):
                if wants_check(row):
                    self.check(row)
                if time.monotonic()-progress>=10:
                    self.emit({'stage':'regions','processed':index+1,'candidates':len(pending)})
                    progress=time.monotonic()
            # Fixing a wrong stored value can initially worsen register numbers.
            # Retain that bridge for the allocator pass instead of immediately
            # discarding it in favor of the semantically wrong high-score seed.
            from . import regflow
            for row in pending:
                if row['label'].startswith('retail call argument') and row.get('object'):
                    before=evidence.missing_call_copies(self.check(parents[row['parent']]))
                    after=evidence.missing_call_copies(self.check(row))
                    row['argument_flow_fixed']=bool(before-after) and after<=before
                if row['label'].startswith(('bind recovered shared-pool', 'retain recovered shared-pool')) and row.get('object'):
                    parent = parents[row['parent']]
                    if 'pool_coverage' not in parent:
                        parent['pool_coverage'] = evidence.shared_pool_coverage(self.project,parent['symbol'],self.check(parent))
                    row['pool_coverage'] = evidence.shared_pool_coverage(self.project,row['symbol'],self.check(row))
                    row['pool_layout_fixed'] = row['pool_coverage'] > parent['pool_coverage']
                if not row['label'].startswith('retail store-value') or not row.get('object'):
                    continue
                parent = parents[row['parent']]
                conflicts = {r['row'] for r in self.check(parent).value_flow}
                flow = regflow.analyse_rows(*getattr(self.check(row), '_rows', ([], [])))
                if conflicts and not flow['value_flow'] and conflicts <= set(flow['equivalent_rows']):
                    row['value_flow_fixed'] = True
            # Compose observed independent bit repairs; no private compile loop.
            responses=defaultdict(list);regional=defaultdict(list)
            for row in pending:
                body=source_text(row['source'])
                responses[row['parent']].append((row['label'],body,self.words.get(row['id'])))
                if row.get('regions'):
                    regional[row['parent']].append((row['label'],body,row['regions']))
            combined=[]
            for parent, values in responses.items():
                seed=parents[parent]; body=source_text(seed['source']); target=self.targets[seed['symbol']][1]; baseline=self.words[parent]
                choices=source.region_compositions(body,seed.get('regions',{}),regional[parent])
                if len(baseline)==len(target):
                    choices+=source.linear_compositions(body,target,baseline,values)
                    greedy=source.compose(body,target,baseline,values)
                    if greedy: choices.append(greedy)
                for label,text in choices:
                    row=self.record(seed['symbol'],text,seed['mw'],seed['flags'],label=label,parent=parent,seed=seed.get('seed',parent))
                    if row['id'] not in seen:
                        seen.add(row['id']);combined.append(row)
            self.evaluate(combined);pending+=combined;history+=pending
            if self.clones:
                self.share_clones(history, seen, beam)
            stat=dict(round=step+1,probes=len(pending),generation_seconds=generation_seconds,
                      matches=len(self.matched_symbols(history)),
                      improved=len({r['symbol'] for r in history if r['score']>initial.get(r['symbol'],-1)}))
            stats.append(stat);self.emit(stat)
            self.save(history,stats,start)
            if stop_on_match and stat['matches']:
                break
        return self.save(history,stats,start)

    def save(self,history,stats,start):
        best={}
        for r in sorted(history,key=lambda r:(not r.get('matched',False),-r['score'],-r.get('binding_score',0),r['bit_errors'],r['id'])):
            best.setdefault(r['symbol'],r)
        for row in best.values():
            if row['score'] >= 0:
                self.check(row)
        report=dict(generator_sha256=self.generator_sha256, records=history, best=best, frontier=dict(self.frontier(history,3)), rounds=stats, compiled=self.compiled,cached=self.cached,
                    compile_seconds=self.compile_seconds,seconds=time.monotonic()-start,environment=self.environment)
        if self.clones:
            report.update(clones=self.clones, clone_skips=self.clone_skips, clone_shared=sorted(self.clone_shared),
                          clone_independent=sorted(self.clone_independent))
        (self.output/'report.json').write_text(json.dumps(report))
        return report


def try_fix(p, symbol, body, budget_s=30.0, max_candidates=80, base=None, rounds=2, beam=2):
    """Session/lifter adapter; same engine and transformations as corpus repair."""
    start=time.monotonic()
    if base and not base.ok:
        return dict(matched=False,body=None,tried=0,best=0,secs=0,error=base.error)
    # Function equality alone does not prove that the unit is integrable:
    # exact inputs still need helper-definition, data-ownership and lint checks.
    sym=p.resolve(symbol)
    engine=Engine(p,STATE_DIR/'fixup'/'sessions'/p.key(sym).replace(':','__'))
    mw=base.mw_version if base else None;flags=base.extra_cflags if base else None
    if not mw:
        mw,flags=oracle.version_for(p,sym,p.work_path(symbol))
    row=engine.record(symbol,body,mw,flags,label='input')
    report=engine.run([row],rounds=rounds,beam=beam,max_candidates=max_candidates,budget_s=budget_s,stop_on_match=True)
    best=report['best'][p.key(sym)]; matched=best.get('matched',False)
    check=engine.check(best) if best['score']>=0 else None
    return dict(matched=matched,body=source_text(best['source']) if matched else None,
                best_body=source_text(best['source']),label=best.get('label'),
                best=max(check.percent,check.percent_adjusted) if check and check.ok else 0,
                base=base.percent if base else row['score'],tried=report['compiled'],variants=report['compiled']+report['cached'],secs=time.monotonic()-start,
                mw_version=best['mw'],extra_cflags=best['flags'])


def integrate(project, report, inputs, output):
    from . import api
    from .ledger import Ledger
    ledger = Ledger()
    provenance_path = ROOT / 'state/repairs/fixup_imports.json'
    provenance = json.loads(provenance_path.read_text()) if provenance_path.exists() else {}
    headers_sha256 = mwgraph.header_fingerprint(ROOT, project.version)
    oracle_sha256 = digest(Path(oracle.__file__).read_bytes())
    accepted, failed, skipped, rebound = [], [], [], []
    for row in report['functions']:
        symbol = row['symbol']
        probe = next((p for p in row['probes'] if p.get('matched')), None)
        if probe is None:
            continue
        record = inputs[symbol]
        seed_symbol = symbol
        sym = project.resolve(symbol)
        target = project.target_object_for(sym)
        check = oracle._diff(project, sym.module, sym.name, '', 0, target=target, base=Path(probe['object'])) if target else None
        exact = check and check.ok and (check.matched or check.matched_pool)
        if not exact:
            alternatives = []
            if sym.name in project.ambiguous_names():
                for module in project.modules:
                    other = project.resolve(module + ':' + sym.name)
                    if other is None:
                        continue
                    obj = project.target_object_for(other)
                    if obj and oracle.function_score(project, other.name, obj, Path(probe['object']))[0]:
                        alternatives.append(project.key(other))
            if len(alternatives) != 1:
                failed.append({'symbol': symbol, 'error': 'saved result does not match its module target',
                               'alternatives': alternatives})
                continue
            symbol = alternatives[0]
            rebound.append({'from': seed_symbol, 'to': symbol})
        previous = provenance.get(symbol, {})
        if (previous.get('link') == 'rejected' and previous.get('generated_sha256') == digest(Path(probe['source']).read_bytes())
                and previous.get('compiler') == record['mw'] and (previous.get('flags') or '') == (record['flags'] or '')
                and previous.get('headers_sha256') == headers_sha256 and previous.get('oracle_sha256') == oracle_sha256):
            skipped.append({'symbol': symbol, 'reason': 'this source/settings already failed the link'})
            continue
        state = ledger.get(symbol)
        upgrade = bool(state and state['status'] == 'matched' and state['link_state'] == 'pool')
        if state and state['status'] in ('matched', 'asm') and not upgrade:
            skipped.append({'symbol': symbol, 'reason': 'already integrated'})
            continue
        if upgrade and not check.matched:
            skipped.append({'symbol': symbol, 'reason': 'pool upgrade is not linkable'})
            continue
        if state is None or state['status'] == 'claimed':
            failed.append({'symbol': symbol, 'error': 'not unclaimed/unmatched'})
            continue
        if hashlib.sha256(Path(record['source']).read_bytes()).hexdigest() != record['sha256']:
            failed.append({'symbol': symbol, 'error': 'changed seed'})
            continue
        source = source_text(probe['source'])
        if api.lint(project, [probe['source']]):
            failed.append({'symbol': symbol, 'error': 'source lint'})
            continue
        work = project.work_path(symbol)
        work.parent.mkdir(parents=True, exist_ok=True)
        if work.exists() and source_text(work) != source:
            previous_sha = hashlib.sha256(work.read_bytes()).hexdigest()
            backup = output / (symbol.replace(':', '__') + '.previous-' + previous_sha[:12] + '.c')
            backup.write_bytes(work.read_bytes())
        if not upgrade:
            work.write_text(source)
        mw = record['mw'] or oracle.module_flags(project, project.resolve(symbol).module)[1]
        result = api.submit(project, symbol, agent='deterministic-fixup',
                            message=probe['label'], harness='fixup', mw_version=mw,
                            extra_cflags=record['flags'] or '',
                            expected_pool_seed=record if upgrade else None,
                            pool_upgrade_source=Path(probe['source']) if upgrade else None)
        if not result.get('ok'):
            failed.append({'symbol': symbol, 'result': result})
            continue
        accepted.append(symbol)
        entry = {'seed_symbol': record.get('symbol', seed_symbol), 'generator': 'fzgx fixup', 'transform': probe['label'],
                              'seed': source_text(record['source']), 'seed_sha256': record['sha256'],
                              'generated_sha256': hashlib.sha256(source.encode()).hexdigest(), 'generated_source': source,
                              'compiler': mw, 'flags': record['flags'], 'source': result['unit'],
                              'bytes': project.resolve(symbol).size, 'headers_sha256': headers_sha256, 'oracle_sha256': oracle_sha256, 'recipe': row.get('recipe', []), 'link': result['link']}
        with oracle.build_lock('submit.lock'):
            provenance = json.loads(provenance_path.read_text()) if provenance_path.exists() else {}
            provenance[symbol] = entry
            provenance_path.write_text(json.dumps(provenance, indent=2) + '\n')
    if accepted:
        with (STATE_DIR / 'verify_dependencies.jsonl').open('a') as out:
            out.write(json.dumps([str(provenance_path.relative_to(ROOT))]) + '\n')
    message = 'Integrate deterministic fixup matches'
    verification = api.verify_links(project, message) if accepted else None
    if verification:
        with oracle.build_lock('submit.lock'):
            provenance = json.loads(provenance_path.read_text()) if provenance_path.exists() else {}
            for symbol in verification.get('verified', []):
                if symbol in provenance:
                    provenance[symbol]['link'] = 'verified'
                    provenance[symbol]['commit'] = verification.get('commit')
            for symbol in verification.get('rejected', []):
                if symbol in provenance:
                    provenance[symbol]['link'] = 'rejected'
            provenance_path.write_text(json.dumps(provenance, indent=2) + '\n')
    outcome = {'accepted': accepted, 'failed': failed, 'skipped': skipped, 'rebound': rebound,
               'verification': verification}
    (output / 'integration.json').write_text(json.dumps(outcome, indent=2) + '\n')
    print(json.dumps(outcome, indent=2))
    if failed or (verification and (not verification.get('ok') or verification.get('rejected'))):
        raise SystemExit(1)


def replay_archive(path):
    archive=json.loads(gzip.decompress(path.read_bytes()))
    if archive.get('format')=='fzgx-mwcc-graphs-v1':
        return mwgraph.replay_archive(path)
    if archive.get('format')=='fzgx-source-repairs-v1':
        from .lift import lift_total
        project=Project();engine=Engine(project,STATE_DIR/'fixup'/'replay'/path.name)
        reproduced=[]
        with oracle.build_lock():
            for record in archive['records']:
                symbol=record['symbol']
                if digest(record['body'].encode())!=record['sha256']:
                    raise ValueError(symbol+': archived body hash mismatch')
                if record['generator']=='fzgx lift':
                    sym=project.resolve(symbol)
                    body=lift_total(project,sym.module,sym.name,max_ins=sym.size//4+10)
                else:
                    body=record['seed']
                    if digest(body.encode())!=record['seed_sha256']:
                        raise ValueError(symbol+': archived seed hash mismatch')
                    for step in record['recipe']:
                        if digest(body.encode())!=step['input_sha256']:
                            raise ValueError(symbol+': recipe input hash mismatch')
                        if 'edits' in step:
                            # Replay the measured source response without rerunning
                            # allocator searches or reconstructing composition beams.
                            for start,end,text in sorted(step['edits'],reverse=True):
                                body=body[:start]+text+body[end:]
                            if digest(body.encode())!=step['output_sha256']:
                                raise ValueError(symbol+': recipe output hash mismatch')
                            continue
                        row=engine.record(step.get('input_symbol',symbol),body,record['mw'],record['flags'])
                        engine.evaluate([row])
                        if not row.get('object'):
                            raise ValueError(symbol+': recipe input no longer compiles')
                        if step['label'] == 'expand owned clone declarations':
                            body=engine.declarations.expand(row)
                        elif step['label'] == 'bind exact clone':
                            mapping=reuse.bindings(project,step['input_symbol'],step['output_symbol'])
                            if step['clone'].get('native_storage'):
                                native=reuse.storage_bindings(project,step['input_symbol'],step['output_symbol'],
                                                              row['object'],engine.check(row))
                                if any(name in mapping and mapping[name]!=value for name,value in native.items()):
                                    raise ValueError(symbol+': clone code/storage bindings disagree')
                                mapping.update(native)
                            if mapping != step['clone']['bindings']:
                                raise ValueError(symbol+': clone bindings changed')
                            body=reuse.rebind(body,mapping)
                        else:
                            body=next((text for label,text in engine.proposals(row)
                                       if label==step['label'] and digest(text.encode())==step['output_sha256']),None)
                        if body is None:
                            raise ValueError(symbol+': cannot reproduce '+step['label'])
                if body is None or digest(body.encode())!=record['sha256']:
                    raise ValueError(symbol+': generated body hash mismatch')
                row=engine.record(symbol,body,record['mw'],record['flags'])
                engine.evaluate([row])
                if not row.get('object'):
                    raise ValueError(symbol+': reproduced body no longer compiles')
                engine.check(row);reproduced.append(row)
        result=dict(reproduced=len(reproduced),records=reproduced)
        (engine.output/'replay.json').write_text(json.dumps(result))
        print(json.dumps({'reproduced':len(reproduced)}));return result
    for symbol,record in archive['repairs'].items():
        body=record['seed']
        if digest(body.encode())!=record['seed_sha256']:
            raise ValueError(f'{symbol}: seed hash mismatch')
        if record['transform']=='correct-module-target':
            choices=[('correct-module-target',body)]
        else:
            constraints=source.web_constraints(record['captures'],record['target_words'],record['baseline_words'])
            choices=source.carrier_candidates(body,symbol.split(':')[-1],record['captures'],constraints)
        if not any(label==record['transform'] and digest(text.encode())==record['generated_sha256'] for label,text in choices):
            raise ValueError(f'{symbol}: source not reproduced')
    result=dict(reproduced=len(archive['repairs']),improved_seeds=len(archive['improved_seeds']))
    print(json.dumps(result));return result


def _stuck_modes() -> Dict[str, str]:
    """symbol -> row-level failure mode, from the last `fzgx stuck` run.

    The corpus records one `pure` mode per body so capture can select a failure class.
    stuck.json is written only by an explicit `fzgx stuck` run, so an absent or stale file
    simply yields no modes and capture keeps skipping -- the behaviour before this existed,
    never a wrong classification.
    """
    try:
        data = json.loads((STATE_DIR / 'stuck.json').read_text())
    except (OSError, ValueError):
        return {}
    return {r['symbol']: r['pure'] for r in data.get('results', [])
            if isinstance(r, dict) and r.get('symbol') and r.get('pure')}


def load_records(engine,args):
    from .ledger import Ledger
    from seeds.recovered import SavedCandidates
    p=engine.project;ledger=Ledger();rows=[]
    if getattr(args, 'pool_upgrades', False):
        from . import api
        engine.linkable_only = True
        selected = p.resolve(args.symbol) if args.symbol else None
        if args.symbol and selected is None:
            raise ValueError('unknown or ambiguous function: ' + args.symbol)
        for state in ledger.db.execute("SELECT * FROM functions WHERE status='matched' AND link_state='pool' ORDER BY size DESC, symbol"):
            sym = p.resolve(state['symbol'])
            if (not sym or selected is not None and sym != selected or
                    args.module and sym.module != args.module or
                    args.max_size is not None and sym.size > args.max_size):
                continue
            unit = p.unit_of(sym)
            if unit:
                rows.append(engine.record(state['symbol'], api._canonical_text(p, unit),
                                          *oracle.version_for(p, sym), label='accepted pool source'))
            if args.limit and len(rows) >= args.limit:
                break
        return rows
    clone_members = None
    if getattr(args, 'clones', False):
        groups = reuse.families(p, args.max_size, args.module, args.symbol)
        if args.limit:
            groups = groups[:args.limit]
        engine.clones = [dict(representative=next(r['symbol'] for r in group if r['status']=='unmatched'), members=group) for group in groups]
        clone_members = {r['symbol'] for group in groups for r in group}
        engine.emit(dict(stage='clone-inventory', families=len(groups), functions=sum(r['status']=='unmatched' for g in groups for r in g),
                         bytes=sum(r['size'] for g in groups for r in g if r['status']=='unmatched')))
    read_only_body = bool(args.symbol and args.body and not getattr(args, 'apply', False))
    def add(symbol,body,mw=None,flags=None,**metadata):
        sym=p.resolve(symbol);state=ledger.get(symbol)
        allowed = ('unmatched','matched') if clone_members is not None else ('unmatched',)
        # An explicit read-only source probe must not silently disappear merely
        # because the function is claimed or blocked. Applying repairs retains
        # the original ownership filter; corpus scans still skip active claims.
        if read_only_body:
            allowed += ('claimed','blocked')
        if not sym or not state or state['status'] not in allowed:
            return
        if clone_members is not None and symbol not in clone_members:
            return
        if clone_members is None and (args.module and sym.module!=args.module or args.max_size is not None and sym.size>args.max_size):
            return
        rows.append(engine.record(symbol,body,mw,flags,**metadata))
    if args.symbol and (args.body or not args.corpus) and (clone_members is None or args.body):
        from . import api
        body=source_text(args.body) if args.body else api._attempt_text(p,args.symbol)
        if body is None:
            raise ValueError('no saved C for '+args.symbol)
        sym=p.resolve(args.symbol)
        mw,flags=oracle.version_for(p,sym,Path(args.body) if args.body else p.work_path(args.symbol))
        add(args.symbol,body,mw,flags,label='saved-body')
    elif args.corpus:
        selected = p.resolve(args.symbol) if args.symbol else None
        if args.symbol and selected is None:
            raise ValueError('unknown or ambiguous function: '+args.symbol)
        prepared=args.corpus/'prepared.json'
        if prepared.exists():
            inputs=json.loads(prepared.read_text())['records']
        else:
            inputs=[dict(r,symbol=s) for s,r in json.loads((args.corpus/'inputs.json').read_text()).items()]
        for r in inputs:
            if selected is not None and p.resolve(r['symbol']) != selected:
                continue
            if clone_members is not None and r['symbol'] not in clone_members:
                continue
            body=source_text(r['source'])
            if digest(body.encode())!=r['sha256']:
                raise ValueError(f"{r['symbol']}: frozen source changed")
            add(r['symbol'],body,r['mw'],r['flags'],label='saved-body',origin=r.get('origin'))
    else:
        saved=SavedCandidates(args.min_percent-0.000001, clone_members);saved.collect()
        # select the functions before touching bodies: the limit used to be applied after
        # every saved body of every unmatched function had been read and recorded
        symbols=sorted(saved.candidates)
        if clone_members is None:
            symbols=[s for s in symbols if (sym:=p.resolve(s)) and not (args.module and sym.module!=args.module) and not (args.max_size is not None and sym.size>args.max_size)
                     and any(args.min_percent-0.000001<r['percent']<=args.max_percent for r in saved.candidates[s])]
            if args.limit:
                symbols=symbols[:args.limit]
        for symbol in symbols:
            choices=saved.candidates[symbol]
            options={r['sha256']:r for r in choices if r['settings_recorded']}
            for r in choices:
                if r['percent']>args.max_percent:
                    continue
                chosen=r if r['settings_recorded'] else options.get(r['sha256'],r)
                add(symbol,r['body'],chosen['mw'],chosen['flags'],label='saved-body',origin=r['origin'])
        if args.drafts:
            for symbol,r in json.loads((STATE_DIR/'lift/scores.json').read_text()).items():
                if r.get('text') and args.min_percent<=r.get('percent',0)<=args.max_percent:
                    add(symbol,r['text'],r.get('mw'),r.get('flags'),label='lifted-body')
    if clone_members is not None:
        from . import api
        for group in engine.clones:
            for member in group['members']:
                if member['status'] != 'matched':
                    continue
                sym=p.resolve(member['symbol']);unit=p.unit_of(sym)
                if unit and not (p.unit_record(unit) or {}).get('asm'):
                    mw,flags=oracle.version_for(p,sym)
                    add(member['symbol'],api._canonical_text(p,unit),mw,flags,label='verified clone donor')
    rows=list({r['id']:r for r in rows}.values())
    if args.limit and clone_members is None:
        selected=set(sorted({r['symbol'] for r in rows})[:args.limit]);rows=[r for r in rows if r['symbol'] in selected]
    return rows


def load_captures(engine,path,rows):
    if path is None:
        return {}
    jobs=json.loads((path/'config.json').read_text())['jobs'];result={}
    report_path = path/'replay-report.json'
    if not report_path.exists():
        report_path = path/'report.json'
    reports = {r['symbol']: r for r in json.loads(report_path.read_text())['functions']}
    seeds={(r['symbol'],r['sha256'],r['mw'],r['flags']):r for r in rows}
    for job in jobs:
        matching=[(key,r) for key,r in seeds.items() if key[:3]==(job['symbol'],job['source_sha256'],job['compiler'])]
        for key,row in matching:
            proof = reports.get(job['symbol'], {})
            if (not proof.get('same_code') or not proof.get('same_object')
                    or proof.get('replay_errors') or proof.get('simplify_errors')
                    or proof.get('source_sha256') != row['sha256']):
                engine.emit({'stage': 'capture-rejected', 'symbol': row['symbol'], 'reason': 'capture validation failed'})
                result[key]=None
                continue
            flags,_=oracle.module_flags(engine.project,engine.project.resolve(row['symbol']).module)
            extra=shlex.split(row['flags']);levels=[f for f in extra if f.startswith('-O')]
            expected=[levels[-1] if levels and f.startswith('-O') else f for f in shlex.split(flags)]
            expected += [f for f in extra if not f.startswith('-O')]
            if job['headers_sha256']!=engine.headers or job['args'][1:-4]!=expected:
                raise ValueError(f"{row['symbol']}: stale capture; recapture required")
            capture=json.loads((path/(job['symbol'].replace(':','__')+'.json')).read_text())
            if capture.get('error'):
                continue
            if not all('pcode' in c for c in capture['captures']):
                raise ValueError('capture lacks PCode; recapture required')
            result[key]=capture['captures']
    return result


def repair_recipe(by_id, row):
    recipe=[]; current=row; visited=set()
    while current.get('parent'):
        if current['id'] in visited:
            raise ValueError(f'{row["symbol"]}: cyclic repair provenance at {current["id"]}')
        visited.add(current['id'])
        parent=by_id[current['parent']]
        recipe.append(dict(label=current['label'], input_sha256=parent['sha256'], output_sha256=current['sha256'],
                           input_symbol=parent['symbol'], output_symbol=current['symbol'],
                           edits=source.edits(source_text(parent['source']),source_text(current['source'])),
                           **({'clone':current['clone']} if 'clone' in current else {})))
        current=parent
    return current, list(reversed(recipe))


def archive_sources(report, path):
    """Portable C and replay recipes, including partial results for future passes."""
    by_id={r['id']:r for r in report['records']}
    selected={r['id']:r for r in [*report['best'].values(), *(r for group in report['frontier'].values() for r in group)]}
    # The word frontier can prefer fewer differing instructions to a higher
    # objdiff percentage. Preserve both for the next pass.
    raw_best={}
    for row in report['records']:
        if row.get('object') and 'raw_percent' in row and row['raw_percent']>raw_best.get(row['symbol'],{}).get('raw_percent',-1):
            raw_best[row['symbol']]=row
    selected.update((r['id'],r) for r in raw_best.values())
    targets={r['symbol'] for group in report.get('clones',[]) for r in group['members'] if r['status']=='unmatched'}
    records=[]
    for row in selected.values():
        if not row.get('object') or targets and row['symbol'] not in targets:
            continue
        seed,recipe=repair_recipe(by_id,row)
        records.append(dict(symbol=row['symbol'],body=source_text(row['source']),sha256=row['sha256'],
            seed=source_text(seed['source']),seed_sha256=seed['sha256'],seed_symbol=seed['symbol'],
            generator='fzgx fixup',recipe=recipe,mw=row['mw'],flags=row['flags'],
            **{k:row[k] for k in ('raw_percent','percent','percent_adjusted','score','word_errors','aligned_word_percent','matched') if k in row}))
    path.write_bytes(gzip.compress(json.dumps(dict(format='fzgx-source-repairs-v1',
        generator_sha256=report['generator_sha256'],environment=report['environment'],records=records)).encode(),mtime=0))


def command(p,args):
    if getattr(args, 'pool_upgrades', False) and (args.clones or args.body or args.corpus or args.capture or args.archive):
        raise ValueError('--pool-upgrades selects canonical accepted C; do not combine it with other source selectors')
    if args.min_percent is None:
        args.min_percent = 0 if getattr(args, 'clones', False) else 95
    if args.rounds < 0 or args.beam < 1 or args.max_candidates < 1 or (args.budget is not None and args.budget <= 0):
        raise ValueError('rounds must be nonnegative; beam, max-candidates and budget must be positive')
    if args.archive:
        return replay_archive(args.archive)
    if args.capture:
        if args.corpus is None or args.output is None:
            raise ValueError('--capture requires --corpus and --output')
        args.symbols=[args.symbol] if args.symbol else None;args.all_near=True
        result=mwgraph.capture(p,args)
        if result['errors']:
            raise SystemExit(1)
        return result
    output=(args.output or STATE_DIR/'fixup'/'corpus').resolve()
    if args.saved:
        report=json.loads((output/'report.json').read_text())
    else:
        engine=Engine(p,output,verbose=True);rows=load_records(engine,args)
        captures=load_captures(engine,args.captures,rows) if args.captures else None
        # the search compiles into its own output directory; only a carved function's check
        # writes the unit's object under build/, so the build lock is held only when one is
        # in the corpus (holding it for a whole search blocks every submit and verify)
        carved=any(p.unit_of(p.resolve(r['symbol'])) for r in rows if p.resolve(r['symbol']))
        if carved:
            with oracle.build_lock():
                report=engine.run(rows,args.rounds,args.beam,args.max_candidates,args.budget,captures)
        else:
            report=engine.run(rows,args.rounds,args.beam,args.max_candidates,args.budget,captures)
        # One canonical corpus format for capture and future repair, all variants
        # remain in report.json rather than separate per-algorithm stores.
        best={s:r for s,r in report['best'].items() if r['score']>=0 and not r.get('matched')}
        (output/'inputs.json').write_text(json.dumps(best))
        seeds={r['id']:r for r in [*best.values(),*(r for group in report['frontier'].values() for r in group)]}
        (output/'prepared.json').write_text(json.dumps({'records':list(seeds.values())}))
        # `pure` is the row-level failure mode, and mwgraph.capture() only captures
        # functions classified `regalloc` (mwgraph.py:317). Writing the literal
        # 'unclassified' meant capture skipped the entire corpus, so the allocator-constraint
        # machinery (mwgraph.selection_order -> mwconstraints.declaration_projection) could
        # never fire on anything. stuck.analyse() already computes the mode per body and
        # writes it to stuck.json; read that instead. Absent or unknown symbols stay
        # 'unclassified', which is what capture already skips.
        modes = _stuck_modes()
        (output/'results.json').write_text(json.dumps(
            {s: {'baseline': {'object': r['object'], 'pure': modes.get(s, 'unclassified')}}
             for s, r in best.items()}))
    if report.get('clones'):
        archive_sources(report,output/'sources.json.gz')
    if args.apply:
        by_id={r['id']:r for r in report['records']};inputs={};functions=[]
        for symbol,row in report['best'].items():
            if not row.get('matched'):
                continue
            seed,recipe=repair_recipe(by_id,row)
            inputs[symbol]=seed
            functions.append(dict(symbol=symbol,probes=[dict(row,matched=True)],recipe=recipe))
        try:
            integrate(p,{'functions':functions},inputs,output)
        finally:
            result_path=output/'integration.json'
            if result_path.exists():
                result=json.loads(result_path.read_text())
                rejected=(result.get('verification') or {}).get('rejected', [])
                cache_path=output/'cache.json'
                cache=json.loads(cache_path.read_text()) if cache_path.exists() else {}
                for symbol in rejected:
                    row=report['best'][symbol]
                    row.update(matched=False,link_rejected=True)
                    if row['id'] in cache:
                        cache[row['id']].update(matched=False,link_rejected=True)
                cache_path.write_text(json.dumps(cache))
                (output/'report.json').write_text(json.dumps(report))
    summary={k:report[k] for k in ('compiled','cached','compile_seconds','seconds')}
    targets={r['symbol'] for group in report.get('clones',[]) for r in group['members'] if r['status']=='unmatched'}
    reported={s:r for s,r in report['best'].items() if not report.get('clones') or s in targets}
    summary.update(functions=len(reported),variants=len(report['records']),
                   matches=[s for s,r in reported.items() if r.get('matched')])
    print(json.dumps(summary,indent=2));return summary
