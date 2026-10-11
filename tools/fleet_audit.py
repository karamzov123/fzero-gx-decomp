"""Read-only, repeatable full-project/fleet evidence snapshot (no remote requests)."""
from __future__ import annotations
import argparse
import collections
import datetime
import json
import os
from pathlib import Path
import sqlite3
import time
from typing import Any

from fzgx import progress
from fzgx.project import ROOT
from fzgx.lint import allocator_scaffolding
from fleet_multi import resource_snapshot


def snapshot(days=7):
    ledger = ROOT / '.fzgx/ledger.db'
    if not ledger.is_file():
        raise RuntimeError('Authoritative .fzgx/ledger.db missing; refusing guessed/empty DB')
    with sqlite3.connect(ledger.as_uri() + '?mode=ro', uri=True) as db:
        db.row_factory = sqlite3.Row
        statuses = dict(db.execute('SELECT symbol,status FROM functions'))
        attempts = list(map(dict, db.execute(
            'SELECT agent,model,outcome,checks,started,ended,symbol FROM attempts '
            'WHERE started>=? AND ended IS NOT NULL', (time.time()-days*86400,))))
        verified = dict(db.execute("SELECT symbol,size FROM functions WHERE status='matched' "
                                   "AND link_state='verified' AND matched_commit IS NOT NULL"))
        claims = list(map(dict, db.execute(
            "SELECT symbol,module,claimed_by,claimed_at FROM functions WHERE status='claimed'")))
    measured = progress.measure(statuses)
    grouped: dict[tuple[str, str], dict[str, Any]] = collections.defaultdict(lambda: dict(attempts=0, terminal_matches=0, checks=0,
                                                   zero_check_attempts=0, verified_symbols=set(),
                                                   worker_seconds=0.0, outcomes=collections.Counter()))

    for a in attempts:
        # Distinguish primary/fallback model identities; do not conflate transport with model.
        agent = a['agent'] or ''
        family = agent.split('-')[2] if agent.startswith('fleet-v2-') else 'other'
        r = grouped[(family, a['model'])]
        r['attempts'] += 1
        r['terminal_matches'] += a['outcome'] in ('matched', 'matched-pool')
        r['checks'] += a['checks'] or 0
        r['zero_check_attempts'] += not (a['checks'] or 0)
        if a['outcome'] in ('matched', 'matched-pool') and a['symbol'] in verified:
            r['verified_symbols'].add(a['symbol'])
        r['worker_seconds'] += max(0, a['ended']-a['started'])
        r['outcomes'][a['outcome']] += 1
    yields = []
    for (family, model), r in grouped.items():
        hours = r['worker_seconds']/3600.0
        symbols = sorted(r['verified_symbols'])
        r['verified_symbols'] = symbols
        yields.append(dict(family=family, model=model, **r, worker_hours=round(hours, 3),
                           verified_unique_symbols=len(symbols),
                           verified_bytes=sum(verified[s] for s in symbols),
                           terminal_matches_per_worker_hour=round(r['terminal_matches']/hours, 3) if hours else None))
    units = collections.defaultdict(lambda: dict(functions=0, bytes=0))
    for r in measured['functions']:
        if not r['authored']:
            units[r['module']]['functions'] += 1
            units[r['module']]['bytes'] += r['size']
    total = measured['total']
    hygiene = []
    for path in sorted((ROOT/'src').rglob('*.c')):
        hits = [i for i, line in enumerate(path.read_text(errors='replace').splitlines(), 1)
                if allocator_scaffolding(line)]
        if hits:
            hygiene.append(dict(path=str(path.relative_to(ROOT)), lines=hits))
    return dict(timestamp=datetime.datetime.now(datetime.timezone.utc).isoformat(), days=days,
                historical_allocator_scaffolding=hygiene,
                authored_code_percent=measured['authored_code_percent'], total=total,
                per_module=measured['per_module'], remaining_by_module=dict(units), claims=claims,
                model_yield=sorted(yields,key=lambda x:x['attempts'],reverse=True),
                headroom=resource_snapshot(),
                definitions=dict(terminal_matches='Ledger terminal matched/matched-pool; inspect verification receipt before treating as delivered.',
                                 authored='Ledger matched, registered unit, built object present; full current hash gate must independently pass.',
                                 coverage='Known nonzero symbol bytes, not necessarily every byte in executable text.',
                                 worker_hours='Sum of ended-started per attempt, not wall-clock hours; overhead included.',
                                 warning='Historical routing, difficulty, and quota differ. This is observational, not a randomized model ranking.'))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--days', type=int, default=7)
    ap.add_argument('--output', type=Path, help='Atomically replace a snapshot under .fzgx/')
    args=ap.parse_args()
    if not 1 <= args.days <= 365:
        ap.error('--days must be 1..365')
    data=snapshot(args.days)
    payload=json.dumps(data, indent=2)+'\n'
    if args.output:
        target=args.output.resolve()
        if not target.is_relative_to(ROOT/'.fzgx'):
            ap.error('--output must be under the project .fzgx directory')
        target.parent.mkdir(parents=True,exist_ok=True)
        staging=target.with_name(target.name+f'.{os.getpid()}.tmp')
        try:
            staging.write_text(payload)
            staging.replace(target)
        finally:
            staging.unlink(missing_ok=True)
        print(json.dumps(dict(snapshot=str(target),timestamp=data['timestamp'],
                              authored_code_percent=data['authored_code_percent'])))
    else:
        print(payload,end='')

if __name__ == '__main__':
    main()
