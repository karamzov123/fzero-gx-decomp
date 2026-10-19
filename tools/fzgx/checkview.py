"""Paged evidence from the selected compile; reads never compile or spend checks."""
from __future__ import annotations

import hashlib
import json
from . import oracle
from .evidence import data_context
from .ledger import Ledger

PAGE_LINES = 80


def _identity(project, key):
    from .api import _canonical_text, _compiler_options, _search_context_key
    from types import SimpleNamespace
    work = project.work_path(key)
    unit = project.unit_of(project.resolve(key))
    body = work.read_text() if work.exists() else _canonical_text(project, unit) if unit else ''
    attempt = Ledger().current_attempt(key)
    options = _compiler_options(project, key)
    return dict(sha256=hashlib.sha256(body.encode()).hexdigest(),
                compilation_context=_search_context_key(project, key, body, SimpleNamespace(
                    mw_version=options.get('mw'), extra_cflags=options.get('flags'))),
                attempt=attempt['id'] if attempt else None,
                compiler={name: options.get(name) for name in ('mw', 'flags')})


def _path(project, key):
    return project.work_path(key).with_suffix('.diff.json')


def save(project, key, result):
    """Store only the selected version, including failures to invalidate old evidence."""
    rows = getattr(result, '_rows', ([], []))
    lines = oracle._render_diff(*rows, 1 << 30, getattr(result, '_accepted_rows', set()), addresses=True)
    if result.ok and not result.matched:
        # Separate what the matcher can change from what the layout repairs own.
        from . import stuck
        mine = stuck.own_rows(*rows, getattr(result, '_accepted_rows', set()))
        layout = {f'{i * 4:04X}' for i in mine['layout']}
        lines = ['L' + line[1:] if line[2:6] in layout and line[:1] not in ' p' else line for line in lines]
        result.layout_rows, result.own_rows, result.own_kinds = len(layout), mine['own'], mine['kinds']
    sym = project.resolve(key)
    fn = project.function_asm(sym.module).get(sym.name)
    payload = dict(identity=_identity(project, key), result=result.to_json(), diff=lines,
                   data=data_context(project, fn, full=True) if fn else [])
    path = _path(project, key)
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix('.tmp')
    temporary.write_text(json.dumps(payload) + '\n')
    temporary.replace(path)
    if result.ok:
        result.diff = _page(payload, 'diff', 0)['diff']


def _page(payload, section, cursor):
    lines = payload[section]
    end = min(cursor + PAGE_LINES, len(lines))
    result = dict(payload['result'])
    result.pop('budget', None)
    result['evidence'] = dict(section=section, cursor=cursor, next=end if end < len(lines) else None,
                              total=len(lines), sha256=payload['identity']['sha256'])
    result['diff'] = [f'Cached {section}: lines {cursor}..{end} of {len(lines)}.']
    if section == 'diff':
        result['diff'].append('Columns: aligned row*4, T: target object address, C: candidate object address; target | ours.')
    result['diff'] += lines[cursor:end]
    if end < len(lines):
        result['diff'].append(f'Continue with read_evidence(section="{section}", cursor="{end}"). '
                              f'Existing sessions: check(versions="{section}:{end}") reads the same page without compiling.')
    if section == 'diff' and payload['data']:
        result['diff'].append('Decoded retail data is available: read_evidence(section="data", cursor="0"); '
                              'existing sessions: check(versions="data:0").')
    return result


def read(project, key, section='diff', cursor=0):
    if section in ('decision', 'witnesses'):
        if cursor != 0:
            return dict(ok=False, error='decision/witnesses are bounded summaries; cursor must be zero')
        if section == 'witnesses':
            from . import exemplars
            return exemplars.witnesses(project, key)
        from . import work_evidence
        return work_evidence.packet(project, key)
    if section not in ('diff', 'data') or cursor < 0:
        return dict(ok=False, error='section must be diff, data, decision or witnesses; cursor must be nonnegative')
    path = _path(project, key)
    if not path.exists():
        return dict(ok=False, error='No cached check. Write or check the current source first.')
    payload = json.loads(path.read_text())
    payload['identity']['compiler'] = {name: payload['identity']['compiler'].get(name) for name in ('mw', 'flags')}
    if not payload['identity'].get('compilation_context') or payload['identity'] != _identity(project, key):
        return dict(ok=False, error='Cached check belongs to different source, headers, compiler, target, tools or attempt. Check the current source first.')
    if not payload['result']['ok']:
        return payload['result']
    if cursor > len(payload[section]):
        return dict(ok=False, error=f'cursor exceeds {len(payload[section])} available lines')
    result = _page(payload, section, cursor)
    result['diff'][0] += ' Reading this page did not compile or spend a check.'
    return result
