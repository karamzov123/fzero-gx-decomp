"""nearlist.py [--min-percent P] [--json PATH]: rank every unmatched function's best saved body
by *absolute* differing machine words against the current retail object.

Raw objdiff percentages hide how many words actually differ in a large function: 99.9% on 700
words is 3 words, 97% on 1200 is 36. This compiles each best saved body with its recorded
compiler settings and scores masked words, so the frontier is ordered by the work left.
Output is a JSON list, best first.
"""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from fzgx import oracle
from fzgx.ledger import Ledger
from fzgx.project import Project

ROOT = Path(__file__).resolve().parents[2]
ATTEMPTS = ROOT / '.fzgx' / 'attempts'


def best_body(symbol):
    """(path, mw, flags) of the highest-scoring saved attempt, or None."""
    best = None
    for record in ATTEMPTS.glob(f'{symbol}.*.json'):
        if record.name.count('.') != 2:      # skip `.c.searched.json`, `.shadow.json`
            continue
        body = record.with_suffix('.c')
        if not body.exists():
            continue
        try:
            data = json.loads(record.read_text())
        except ValueError:
            continue
        percent = data.get('percent') or 0.0
        if best is None or percent > best[0]:
            best = (percent, body, data.get('mw'), data.get('flags') or '')
    return None if best is None else best[1:]


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    min_percent = 0.0
    for i, a in enumerate(sys.argv):
        if a == '--min-percent':
            min_percent = float(sys.argv[i + 1])
    out_path = Path(args[0]) if args else ROOT / '.fzgx' / 'nearlist.json'
    p, l = Project(), Ledger()
    rows = l.db.execute("SELECT symbol, module, size, best_percent FROM functions "
                        "WHERE status='unmatched' AND size > 0 AND best_percent >= ?",
                        (min_percent,)).fetchall()
    groups = {}
    for symbol, module, size, percent in rows:
        body = best_body(symbol)
        if body is None:
            continue
        path, mw, flags = body
        groups.setdefault((module, mw or '', flags), []).append((symbol, size, percent, path))
    results = []
    for n, ((module, mw, flags), items) in enumerate(sorted(groups.items())):
        work = Path('/tmp') / 'nearlist' / f'g{n}'
        work.mkdir(parents=True, exist_ok=True)
        copies = {}
        for symbol, size, percent, path in items:
            dst = work / f'{symbol}.c'
            dst.write_text(path.read_text())
            copies[dst] = (symbol, size, percent)
        objs = oracle.compile_many(p, module, list(copies), work / 'obj',
                                   mw_version=mw or None, extra_cflags=flags or None)
        for src, (symbol, size, percent) in copies.items():
            sym = p.resolve(symbol)
            obj = objs.get(src)
            if obj is None or sym is None:
                results.append({'symbol': symbol, 'module': module, 'size': size,
                                'differing': None, 'note': 'no object'})
                continue
            target = oracle.words(p.target_object_for(sym), sym.name)
            ours = oracle.words(obj, sym.name)
            if target is None or ours is None:
                results.append({'symbol': symbol, 'module': module, 'size': size,
                                'differing': None, 'note': 'no words'})
                continue
            score, bad = oracle.word_score(target, ours)
            results.append({'symbol': symbol, 'module': module, 'size': size,
                            'differing': len(bad) + abs(len(target) - len(ours)),
                            'words': len(target), 'percent': round(score, 4),
                            'mw': mw, 'flags': flags})
    results.sort(key=lambda r: (r['differing'] is None, r['differing'] or 0, -(r['size'] or 0)))
    out_path.write_text(json.dumps(results, indent=1))
    for r in results[:40]:
        print(f"{r['symbol']:14} {r['module']:14} {r['size']:5} "
              f"{str(r.get('differing')):>5} {r.get('percent', 0):7.2f} {r.get('words', '')}")


if __name__ == '__main__':
    main()
