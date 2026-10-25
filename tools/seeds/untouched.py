#!/usr/bin/env python3
"""Freeze never-give-up lifter seeds for fresh functions without SDK reuse candidates."""
from __future__ import annotations

import argparse
import hashlib
import json
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from fzgx import lift
from fzgx.ledger import Ledger
from fzgx.project import ROOT, STATE_DIR, Project


def sdk_candidates():
    known = defaultdict(set)
    for path in (ROOT / 'state/seeds').glob('sdkmatch*.json'):
        data = json.loads(path.read_text())
        for group in ('hits', 'ambiguous'):
            for row in data.get(group, []):
                known[row['dol']].add(str(path.relative_to(ROOT)))
    paths = list((ROOT / 'state/sdkimports').glob('*.json'))
    paths += [STATE_DIR / 'sourcealign/matches.json']
    for path in paths:
        if path.exists():
            for symbol in json.loads(path.read_text()):
                known[symbol].add(str(path.relative_to(ROOT)))
    for path in (STATE_DIR / 'sdkimport').glob('*/prepare.json'):
        for row in json.loads(path.read_text()).get('prepared', []):
            known[row['symbol']].add(str(path.relative_to(ROOT)))
    # A ranked donor candidate belongs to source reuse even before its import succeeds.
    path = STATE_DIR / 'sourcealign/discovery.json'
    if path.exists():
        for row in json.loads(path.read_text()).get('results', []):
            known[row['symbol']].add(str(path.relative_to(ROOT)))
    return known


def prepare(output: Path, max_size: int):
    p, ledger = Project(), Ledger()
    known = sdk_candidates()
    rows = ledger.db.execute(
        "SELECT * FROM functions WHERE status='unmatched' AND size<=? ORDER BY size,module,addr",
        (max_size,)).fetchall()
    selected, sdk, prior, stale = [], [], [], []
    for row in rows:
        if p.resolve(row['symbol']) is None:
            stale.append(row['symbol'])
            continue
        attempts = ledger.db.execute(
            'SELECT best_body_path,best_in_attempt FROM attempts WHERE symbol=?', (row['symbol'],)).fetchall()
        if (row['best_percent'] or 0) > 0 or any(
                a['best_in_attempt'] > 0 or (a['best_body_path'] and Path(a['best_body_path']).is_file())
                for a in attempts):
            prior.append(row['symbol'])
        elif row['symbol'] in known:
            sdk.append(dict(symbol=row['symbol'], evidence=sorted(known[row['symbol']])))
        else:
            selected.append(dict(row))
    output.mkdir(parents=True, exist_ok=True)
    if (output / 'manifest.json').exists():
        raise ValueError(f'{output}: frozen manifest already exists; use a new output directory')
    selection = dict(max_size=max_size, unmatched=len(rows), excluded_prior=prior,
                     excluded_sdk=sdk, excluded_stale=stale, selected=selected)
    (output / 'selection.json').write_text(json.dumps(selection, indent=2) + '\n')
    manifest, errors = {}, {}
    for i, row in enumerate(selected, 1):
        symbol = row['symbol']
        body = lift.lift_total(p, row['module'], p.resolve(symbol).name)
        if body is None:
            errors[symbol] = 'lift_total returned no draft'
        else:
            path = output / (symbol.replace(':', '__') + '.c')
            path.write_text(body)
            manifest[symbol] = dict(path=str(path.resolve()), sha256=hashlib.sha256(body.encode()).hexdigest(),
                                    kind='lift_total', size=row['size'], unresolved=body.count('???'))
        if i % 20 == 0 or i == len(selected):
            print(f'lifted {i}/{len(selected)}; {len(manifest)} seeds; {len(errors)} failures', flush=True)
    (output / 'errors.json').write_text(json.dumps(errors, indent=2) + '\n')
    if errors:
        raise RuntimeError(f'{len(errors)} functions have no lifter seed; see {output / "errors.json"}')
    (output / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
    return dict(functions=len(manifest), bytes=sum(r['size'] for r in selected),
                excluded_sdk=len(sdk), partial=sum(r['unresolved'] > 0 for r in manifest.values()),
                manifest=str(output / 'manifest.json'))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--max-size', type=int, default=511)
    args = parser.parse_args()
    print(json.dumps(prepare(args.output, args.max_size)), flush=True)


if __name__ == '__main__':
    main()
