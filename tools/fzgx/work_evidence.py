"""Evidence-led triage, not another matching runner or an acceptance gate.

Snapshots and proposed queues are local. Claims, budgets, native-C rules and the
16-target verifier remain authoritative. Observations never grant match credit.
"""
from __future__ import annotations

import hashlib
import json
import re
import shlex
import subprocess
import time
from pathlib import Path

from .project import ROOT, STATE_DIR, Project
from .ledger import Ledger
from . import oracle

DIRECTORY = STATE_DIR / 'work-evidence'


def _sha(data):
    return hashlib.sha256(data).hexdigest()


def _read(path, default):
    try:
        return json.loads(path.read_text())
    except (OSError, ValueError):
        return default


def _write(path, data):
    """Atomic JSON snapshots; caller holds a lock for read/modify/write."""
    import os
    import tempfile
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temporary = tempfile.mkstemp(prefix='.' + path.name, dir=path.parent)
    try:
        with os.fdopen(fd, 'w') as stream:
            json.dump(data, stream, sort_keys=True, indent=2)
            stream.write('\n')
        os.replace(temporary, path)
    finally:
        Path(temporary).unlink(missing_ok=True)


def source_record(p, symbol):
    """Select real saved source and its own compiler metadata, never just a score."""
    from . import api
    sym = p.resolve(symbol)
    if sym is None:
        raise ValueError('unknown or ambiguous function; use module:name')
    key = p.key(sym)
    ledger = Ledger()
    row = ledger.get(key)
    path, options = None, {}
    if row and row['status'] == 'claimed' and p.work_path(key).exists():
        path, options = p.work_path(key), api._compiler_options(p, key)
    elif row and row['status'] == 'matched':
        unit = p.unit_of(sym)
        if unit:
            from . import tufile
            body = tufile.unit_text(p, p.unit_record(unit))
            if body:
                path = DIRECTORY / 'sources' / (key.replace(':', '__') + '.c')
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text(body)
    else:
        for attempt in ledger.db.execute(
                'SELECT * FROM attempts WHERE symbol=? AND best_body_path IS NOT NULL '
                'ORDER BY MAX(COALESCE(final_percent,0),COALESCE(best_in_attempt,0)) DESC,id DESC', (key,)):
            candidate = Path(attempt['best_body_path'])
            if not candidate.exists():
                candidate = STATE_DIR / 'attempts' / candidate.name
            if candidate.exists():
                path = candidate
                options = _read(path.with_suffix('.json'), {})
                # Release and ledger restores rewrite a saved body in place, and an older
                # sidecar then carries a stale digest (104 rows in the local ledger). The
                # body is still the best evidence for this function, so keep it and let
                # oracle.version_for pick the settings from the unit instead of refusing
                # to work the function at all.
                if options.get('sha256') and options['sha256'] != _sha(path.read_text().encode()):
                    options = {}
                break
        if path is None:
            unit = p.unit_of(sym)
            candidate = ROOT / 'src' / unit if unit else None
            if candidate and candidate.exists():
                from . import tufile
                body = tufile.unit_text(p, p.unit_record(unit))
                if body:
                    path = DIRECTORY / 'sources' / (key.replace(':', '__') + '.c')
                    path.parent.mkdir(parents=True, exist_ok=True)
                    path.write_text(body)
    if path is None:
        return dict(path=None, sha256=None, mw=None, flags=None, body=None)
    body = path.read_text()
    digest = _sha(body.encode())
    if options.get('sha256') and options['sha256'] != digest:
        raise ValueError(f'{key}: saved source/metadata hash mismatch')
    mw, flags = oracle.version_for(p, sym, path)
    flags = options.get('flags', flags)
    if isinstance(flags, list):
        flags = shlex.join(flags)
    return dict(path=str(path), sha256=digest, mw=options.get('mw') or mw,
                flags=flags, body=body)


def residual(result):
    lines = [line for line in result.get('diff', [])
             if line[:1] in '~?!+-' and ' | ' in line]
    kinds = result.get('own_kinds') or {}
    mode = ('semantic/value-flow' if result.get('value_flow') else
            'expression/operand-order' if result.get('operand_order') else
            'ABI/type' if any(k in ('ext', 'signedness') for k in kinds) else
            'layout/relocation' if any(k in ('imm', 'reloc') for k in kinds) else
            'frame' if 'frame' in kinds else
            'register-allocation' if kinds and set(kinds) <= {'regalloc'} else
            'mixed: ' + ', '.join(sorted(kinds)) if kinds else 'inspect earliest divergence')
    return dict(first=lines[0] if lines else None, rows=lines[:8], mode=mode,
                fingerprint=_sha(json.dumps(dict(rows=lines, kinds=kinds,
                    value_flow=result.get('value_flow'), operand_order=result.get('operand_order')),
                    sort_keys=True).encode()), kinds=kinds,
                differing_rows=result.get('own_rows', result.get('differing_rows')))


def packet(p: Project, symbol: str, check=False, include_witnesses=False):
    from . import api, checkview, exemplars
    sym = p.resolve(symbol)
    if sym is None:
        raise ValueError('unknown or ambiguous function; use module:name')
    key = p.key(sym)
    source = source_record(p, key)
    result, identity = {}, None
    if source['path'] and check:
        verdict = oracle.check(p, key, 40, source=Path(source['path']),
                               mw_version=source['mw'], extra_cflags=source['flags'])
        result = verdict.to_json()
        if verdict.ok:
            from . import stuck
            mine = stuck.own_rows(*getattr(verdict, '_rows', ([], [])),
                                  getattr(verdict, '_accepted_rows', set()))
            result['own_kinds'], result['own_rows'] = mine['kinds'], mine['own']
        identity = api._search_context_key(p, key, source['body'], verdict)
    else:
        # Cached pages are valid only for the exact current source/attempt/profile.
        cached = checkview.read(p, key)
        payload = _read(checkview._path(p, key), {})
        if cached.get('ok') and payload.get('identity', {}).get('sha256') == source['sha256']:
            result = dict(payload['result'])
            result['diff'] = [line for line in payload['diff'] if line[:1] in '~?!+-' and ' | ' in line][:40]
        if source['body']:
            from types import SimpleNamespace
            identity = api._search_context_key(p, key, source['body'],
                SimpleNamespace(mw_version=source['mw'], extra_cflags=source['flags']))
    row = Ledger().get(key)
    residual_info = residual(result)
    history = _read(DIRECTORY / 'hypotheses' / (key.replace(':', '__') + '.json'), [])
    same = [h for h in history if identity and h.get('experiment_key') == identity]
    target = p.target_object_for(sym)
    output = dict(symbol=key, module=sym.module, size=sym.size,
        source={k: v for k, v in source.items() if k != 'body'},
        experiment_key=identity, residual=residual_info, check=result,
        target_sha256=_sha(target.read_bytes()) if target and target.exists() else None,
        attempts=row['attempts'] if row else None,
        prior_hypotheses=same[-8:], current_context_hypotheses=len(same), historical_hypotheses=len(history),
        next_action=('Repair compiler errors before matching.' if result and not result.get('ok') else
                     'Inspect the real residual and try another plausible source explanation. '
                     'Use witnesses or prior notes when useful; one failed idea does not exhaust the function.'),
        guardrails='Read-only diagnosis. No claim, budget override, submit, block/unblock or match credit.')
    if include_witnesses:
        output['witnesses'] = exemplars.witnesses(p, key)
    return output


def _references(p, sym):
    fn = p.function_asm(sym.module).get(sym.name)
    if not fn:
        return []
    names = list(fn.refs) + re.findall(r'\bbl\s+([A-Za-z_]\w*)\s*$', '\n'.join(fn.asm), re.M)
    result = {}
    for name in names:
        target = p.find_symbol(name, sym.module) or p.find_symbol(name)
        if target:
            result[(target.module, target.name)] = target
    return list(result.values())


def clusters(p: Project, module=None, limit=20):
    """Rank structural cohorts by affected bytes; shared references are not proof."""
    if not 1 <= limit <= 200:
        raise ValueError('limit must be 1..200')
    ledger = Ledger()
    rows = {r['symbol']: dict(r) for r in ledger.db.execute(
        "SELECT * FROM functions WHERE status IN ('unmatched','blocked')")
        if module is None or r['module'] == module}
    totals = {r['symbol']: dict(r) for r in ledger.db.execute(
        'SELECT symbol,COUNT(*) attempts,SUM(checks) checks,SUM(cost_usd) cost FROM attempts GROUP BY symbol')}
    groups = {}
    tu_map = {}
    for mod in p.modules:
        path = p.module_config_dir(mod) / 'tus.json'
        if path.exists():
            for unit in _read(path, {}).get('tus', []):
                for name in unit.get('functions', []):
                    tu_map[(mod, name)] = str(Path(p.module_src_prefix(mod)) / unit['file'])
    for key, row in rows.items():
        sym = p.resolve(key)
        if sym is None:
            continue
        labels = []
        for target in _references(p, sym):
            kind = 'callee' if target.kind == 'function' or target.section in ('.text', '.init') else 'object'
            labels.append((kind, target.module + ':' + target.name))
        unit = p.unit_of(sym)
        record = p.unit_record(unit) if unit else None
        tu = (record or {}).get('tu') or tu_map.get((sym.module, sym.name))
        if tu:
            labels.append(('translation-unit', tu))
        for kind, label in labels:
            identity = row['module'] + ':' + kind + ':' + label
            group = groups.setdefault(identity, dict(id=identity, module=row['module'],
                evidence_kind=kind, shared=label, members=[], bytes=0, checks=0, cost_usd=0.0))
            if key not in group['members']:
                group['members'].append(key)
                group['bytes'] += row['size']
                group['checks'] += totals.get(key, {}).get('checks') or 0
                group['cost_usd'] += totals.get(key, {}).get('cost') or 0
    ranked = [g for g in groups.values() if len(g['members']) >= 2]
    for g in ranked:
        g['members'].sort()
        g['cost_usd'] = round(g['cost_usd'], 6)
        g['broad_reference'] = len(g['members']) > 64
        g['proposed_action'] = ('Recover and validate the shared call ABI against callers.' if g['evidence_kind'] == 'callee' else
            'Compare retail field/stride accesses; propose one evidence-backed shared layout.' if g['evidence_kind'] == 'object' else
            'Compare shared declarations and compiler profile; recheck matched siblings serially.')
    ranked.sort(key=lambda g: (g['broad_reference'], -g['bytes'], -len(g['members']), -g['checks'], g['id']))
    return dict(unfinished=len(rows), total_groups=len(ranked), groups=ranked[:limit],
                note='Shared reference/TU cohorts are leads, not a claim of a common root cause. No claims or headers changed.')


def record_hypothesis(p, symbol, hypothesis, prediction, observation, outcome='tested', unlock=''):
    """Persist a falsifiable experiment/handoff without granting acceptance credit."""
    import fcntl
    if outcome not in ('tested', 'blocked', 'improved') or not all(
            isinstance(x, str) and x.strip() for x in (hypothesis, prediction, observation)):
        raise ValueError('require hypothesis, prediction, observation and tested/blocked/improved outcome')
    evidence = packet(p, symbol)
    if not evidence['experiment_key']:
        raise ValueError('complete source/compiler/target identity unavailable; cannot deduplicate safely')
    key = evidence['symbol']
    path = DIRECTORY / 'hypotheses' / (key.replace(':', '__') + '.json')
    path.parent.mkdir(parents=True, exist_ok=True)
    record = dict(symbol=key, experiment_key=evidence['experiment_key'],
        hypothesis=hypothesis, prediction=prediction, observation=observation,
        outcome=outcome, unlock=unlock, source=evidence['source'],
        residual_fingerprint=evidence['residual']['fingerprint'], time=int(time.time()))
    with path.with_suffix('.lock').open('w') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)
        records = _read(path, [])
        prior = next((r for r in records if r['experiment_key'] == record['experiment_key']
                      and r['hypothesis'] == hypothesis and r['prediction'] == prediction), None)
        if prior:
            return dict(recorded=False, reused=True, record=prior,
                        note='Exact hypothesis/input already recorded; try a different approach rather than repeating it.')
        records.append(record)
        _write(path, records)
    return dict(recorded=True, reused=False, record=record,
                note='Agent observation only; no object match, linked credit or retry-budget override.')


def record_handoff(p, symbol, reason):
    fields = dict(re.findall(r'(?im)^\s*(HYPOTHESIS|PREDICTION|OBSERVATION|UNLOCK):\s*([^\n]+)', reason))
    fields = {key.upper(): value for key, value in fields.items()}
    if not all(fields.get(key) for key in ('HYPOTHESIS', 'PREDICTION', 'OBSERVATION', 'UNLOCK')):
        return None
    return record_hypothesis(p, symbol, fields['HYPOTHESIS'], fields['PREDICTION'],
                             fields['OBSERVATION'], 'tested', fields['UNLOCK'])


def eligibility(p, symbol):
    evidence = packet(p, symbol)
    previous = evidence['prior_hypotheses']
    row = Ledger().get(evidence['symbol'])
    fresh = bool(evidence['experiment_key'] and not previous) if evidence['historical_hypotheses'] else None
    return dict(symbol=evidence['symbol'], experiment_key=evidence['experiment_key'],
        same_context_hypotheses=evidence['current_context_hypotheses'],
        fresh_evidence=fresh,
        retry_advised=bool(evidence['experiment_key'] and row and row['status'] == 'unmatched'
                          and (fresh is True or row['attempts'] == 0)),
        comparison_basis='recorded context' if evidence['historical_hypotheses'] else 'no recorded comparison baseline',
        status=row['status'] if row else None,
        unlock=[h['unlock'] for h in previous if h.get('unlock')],
        note='Advisory about repeating recorded input, not a ban on untested approaches. '
             'No claim, unblock, cap reset, provider request or search is performed.')


def capture_inputs(p):
    """Content hashes only; never archive compilers, ROMs, credentials or binaries."""
    paths = set()
    for root in (ROOT / 'include', ROOT / 'src', p.config_dir, ROOT / 'tools/fzgx',
                 ROOT / 'state/sdkimports', ROOT / 'state/dataimports', p.build_dir / 'include'):
        if root.exists():
            paths.update(path for path in root.rglob('*') if path.is_file()
                         and path.suffix in ('.h', '.c', '.py', '.json', '.txt', '.yml'))
    paths.add(ROOT / 'docs/MWCC_IDIOMS.md')
    paths.update((ROOT / 'build/compilers').rglob('mwcceppc.exe'))
    paths.update((ROOT / 'build/tools' / name) for name in ('wibo', 'dtk'))
    inputs = {str(path.relative_to(ROOT)): _sha(path.read_bytes()) for path in sorted(paths) if path.is_file()}
    from . import sourcealign
    for sdk in sorted({r['sdk'] for r in _read(STATE_DIR / 'sourcealign/libraries.json', [])}):
        try:
            stamp = sourcealign.donor_inputs(ROOT / 'build/tools' / sdk)
            inputs['donors/' + sdk] = _sha(json.dumps(stamp, sort_keys=True).encode())
        except (OSError, ValueError, subprocess.SubprocessError):
            inputs['donors/' + sdk] = 'unavailable-or-unlicensed'
    return inputs


def dependencies(p, sym):
    """Conservative module/type/callee dependency set, without inventing layouts."""
    result = set()
    unit = p.unit_of(sym)
    cfg = p.unit_record(unit) if unit else None
    if cfg:
        result.add('src/' + (cfg.get('tu') or cfg['source']))
    for target in _references(p, sym):
        refunit = p.unit_of(target) if target.kind == 'function' else None
        refcfg = p.unit_record(refunit) if refunit else None
        if refcfg:
            result.add('src/' + (refcfg.get('tu') or refcfg['source']))
    header = ROOT / 'include' / p.module_src_prefix(sym.module)
    if header.exists():
        result.update(str(h.relative_to(ROOT)) for h in header.rglob('*.h'))
    # Transitive literal includes in the actual body are also relevant.
    source = source_record(p, p.key(sym))
    pending = [(source['body'] or '', Path(source['path']).parent if source['path'] else ROOT)]
    visited = set()
    while pending:
        text, parent = pending.pop()
        for inc in re.findall(r'^\s*#\s*include\s*[<\"]([^>\"]+)[>\"]', text, re.M):
            candidates = (parent / inc, ROOT / 'include' / inc, p.build_dir / 'include' / inc,
                          STATE_DIR / 'headers' / inc)
            path = next((c for c in candidates if c.is_file()), None)
            if path and path.resolve() not in visited:
                visited.add(path.resolve())
                try:
                    result.add(str(path.resolve().relative_to(ROOT)))
                except ValueError:
                    continue
                pending.append((path.read_text(), path.parent))
    return result


def _affected(p, sym, changed):
    direct = dependencies(p, sym) & set(changed)
    for name in changed:
        if name.startswith(('tools/fzgx/', 'build/compilers/', 'state/sdkimports/', 'state/dataimports/', 'donors/')) or name in (
                'docs/MWCC_IDIOMS.md', 'build/tools/dtk', 'build/tools/wibo'):
            direct.add(name)
        elif name.startswith(str(p.config_dir.relative_to(ROOT)) + '/'):
            relative = Path(name).relative_to(p.config_dir.relative_to(ROOT))
            # Root config applies globally; module config applies only there.
            if len(relative.parts) == 1 or relative.parts[0] == sym.module:
                direct.add(name)
        elif name.startswith('include/') and '/rel/' not in name and '/dol/' not in name:
            # Global SDK/types headers can affect inferred signatures even if a
            # saved body has not included the eventual shared declaration yet.
            direct.add(name)
    return sorted(direct)


def refresh(p: Project, limit=20):
    """On-demand event detection; queue only, never dispatch/unblock/reset caps."""
    import fcntl
    if not 1 <= limit <= 200:
        raise ValueError('limit must be 1..200')
    DIRECTORY.mkdir(parents=True, exist_ok=True)
    with (DIRECTORY / 'refresh.lock').open('w') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)
        current = capture_inputs(p)
        previous = _read(DIRECTORY / 'inputs.json', None)
        changed = sorted(k for k in set(current) | set(previous or {})
                         if previous is not None and current.get(k) != previous.get(k))
        ledger = Ledger()
        rows = {r['symbol']: dict(r) for r in ledger.db.execute(
            "SELECT * FROM functions WHERE status IN ('unmatched','blocked')")}
        queued = {key: value for key, value in _read(DIRECTORY / 'queue.json', {}).items() if key in rows}
        added = []
        if changed:
            for key, row in rows.items():
                sym = p.resolve(key)
                if sym is None:
                    continue
                relevant = _affected(p, sym, changed)
                if relevant:
                    queued[key] = dict(symbol=key, module=sym.module, size=sym.size,
                        status=row['status'], evidence_paths=relevant, time=int(time.time()),
                        evidence_digest=_sha(json.dumps({k: current.get(k) for k in relevant}, sort_keys=True).encode()),
                        action='Recheck the saved native body; compare new residual before requesting an agent.')
                    added.append(key)
        _write(DIRECTORY / 'inputs.json', current)
        _write(DIRECTORY / 'queue.json', queued)
    return dict(initialized=previous is None, changed_files=changed, newly_affected=len(added),
                affected_symbols=added, pending=len(queued), queue=queue(p, limit),
                note='Evidence recheck proposals only. No matching, provider calls, claim changes or automatic retries.')


def queue(p, limit=20):
    ledger = Ledger()
    records = _read(DIRECTORY / 'queue.json', {})
    records = [r for key, r in records.items() if (row := ledger.get(key))
               and row['status'] in ('unmatched', 'blocked')]
    return sorted(records, key=lambda r: (-r['size'], r['symbol']))[:limit]


def acknowledge(p, symbol):
    import fcntl
    sym = p.resolve(symbol)
    if sym is None:
        raise ValueError('unknown or ambiguous symbol')
    DIRECTORY.mkdir(parents=True, exist_ok=True)
    with (DIRECTORY / 'refresh.lock').open('w') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)
        records = _read(DIRECTORY / 'queue.json', {})
        removed = records.pop(p.key(sym), None)
        _write(DIRECTORY / 'queue.json', records)
    return dict(acknowledged=bool(removed), symbol=p.key(sym))


def yield_report(p: Project, module=None):
    """Verified native yield with explicit attribution/cost gaps, not a leaderboard."""
    from . import progress, tufile
    ledger = Ledger()
    rows = {r['symbol']: dict(r) for r in ledger.db.execute('SELECT * FROM functions')
            if module is None or r['module'] == module}
    native = set()
    for unit in p.load_units():
        if unit.get('status') != 'matching' or unit.get('data') or not progress.gen_built(unit):
            continue
        body = tufile.unit_text(p, unit)
        if not body or re.search(r'\b(?:asm|__asm)\b', body):
            continue
        for name in unit['symbols']:
            sym = p.find_symbol(name, unit['module'])
            if sym and p.key(sym) in rows and rows[p.key(sym)]['link_state'] == 'verified':
                native.add(p.key(sym))
    successes, groups = {}, {}
    attempts = [dict(r) for r in ledger.db.execute('SELECT * FROM attempts ORDER BY id') if r['symbol'] in rows]
    for a in attempts:
        if a['outcome'] in ('matched', 'matched-pool') and a['ended']:
            successes[a['symbol']] = a
        key = (a['harness'] or 'unattributed', a['model'] if a['model'] not in (None, '', 'none') else 'unattributed')
        group = groups.setdefault(key, dict(harness=key[0], model=key[1], attempts=0, checks=0,
            measured_cost_usd=0.0, attempts_without_cost=0, wall_seconds=0,
            verified_native_functions=0, verified_native_bytes=0))
        group['attempts'] += 1
        group['checks'] += a['checks'] or 0
        group['measured_cost_usd'] += a['cost_usd'] or 0
        group['attempts_without_cost'] += int(a['cost_usd'] is None)
        if a['ended'] and a['started']:
            group['wall_seconds'] += max(0, a['ended'] - a['started'])
    unattributed = []
    for symbol in native:
        a = successes.get(symbol)
        if not a:
            unattributed.append(symbol)
            continue
        key = (a['harness'] or 'unattributed', a['model'] if a['model'] not in (None, '', 'none') else 'unattributed')
        groups[key]['verified_native_functions'] += 1
        groups[key]['verified_native_bytes'] += rows[symbol]['size']
    output = list(groups.values())
    for g in output:
        g['measured_cost_usd'] = round(g['measured_cost_usd'], 6)
        g['checks_per_verified_function'] = (round(g['checks'] / g['verified_native_functions'], 3)
                                              if g['verified_native_functions'] else None)
        g['native_bytes_per_measured_dollar'] = (round(g['verified_native_bytes'] / g['measured_cost_usd'], 3)
            if g['measured_cost_usd'] and not g['attempts_without_cost'] else None)
    output.sort(key=lambda g: (-g['verified_native_bytes'], -g['attempts']))
    return dict(module=module, verified_native_functions=len(native),
        verified_native_bytes=sum(rows[s]['size'] for s in native),
        attribution_missing_functions=len(unattributed), groups=output,
        note='Conservative ledger-link-verified native built units only; older unmarked imports are excluded. '
             'Credit goes to the last non-shadow successful attempt, not causal discovery. '
             'Wall times can overlap; missing cost is not zero cost. Different assignments prevent a fair model ranking.')


def donor_report(p):
    from . import sourcealign
    records = _read(STATE_DIR / 'sourcealign/libraries.json', [])
    groups = []
    for sdk in sorted({r['sdk'] for r in records}):
        entries = [r for r in records if r['sdk'] == sdk]
        try:
            current = sourcealign.donor_inputs(ROOT / 'build/tools' / sdk)
            error = None
        except (OSError, ValueError, subprocess.SubprocessError) as exc:
            current, error = None, str(exc)
        fingerprinted = [r for r in entries if r.get('provenance')]
        stale = [r for r in fingerprinted if r['provenance'] != current or not Path(r['object']).exists()
                 or _sha(Path(r['object']).read_bytes()) != r.get('object_sha256')]
        groups.append(dict(sdk=sdk, current=current, error=error, objects=len(entries),
            distinct_sources=len({r['source'] for r in entries}),
            profiles=len({(r['mw'], r['flags'], r.get('mode', 'files')) for r in entries}),
            fingerprinted_objects=len(fingerprinted), stale_objects=len(stale),
            legacy_unfingerprinted_objects=len(entries) - len(fingerprinted)))
    return dict(donors=groups, catalog_health=_read(STATE_DIR / 'sourcealign/catalog-health.json', {}),
        note='Compile snapshots are not target matches. Legacy objects lack source-corpus provenance. '
             'Use sourcealign --compile-sdk with explicit roots to refresh; unchanged batches can reuse hashed objects.')
