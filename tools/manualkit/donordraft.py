"""donordraft.py SYMBOL [OUTDIR] [--all]: bound C draft from the best fuzzy donor (sourcealign).

Runs the importer's `import_candidate` on the top `.fzgx/sourcealign/fuzzy.jsonl` candidates for
one unmatched function and keeps the bound source even when it is not an exact match, so a
manual matcher can finish it. Prints percent and the draft path per candidate; nothing is
submitted and the tree is untouched. --all tries every candidate (default: top 2 by similarity).
"""
import json
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from fzgx.project import Project
from fzgx import sourcealign, sdkimport

ROOT = Path(__file__).resolve().parents[2]


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    symbol = args[0]
    out = Path(args[1]) if len(args) > 1 else ROOT / '.fzgx/donordraft' / symbol
    row = next((json.loads(line) for line in open(ROOT / '.fzgx/sourcealign/fuzzy.jsonl')
                if json.loads(line)['symbol'] == symbol), None)
    if row is None:
        sys.exit(f'{symbol}: no fuzzy donor row')
    candidates = sorted(row['candidates'], key=lambda c: -c['opcode_similarity'])
    if '--all' not in sys.argv:
        candidates = candidates[:2]
    p = Project()
    solved = sourcealign.layout

    def layout(p, rec, text, directory):
        # Keep the unsolved draft when the padding solver gives up: the code is usually
        # right and only the struct offsets need a hand fix.
        try:
            return solved(p, rec, text, directory)
        except ValueError as error:
            print(f'  (layout unsolved: {error}; keeping the donor layout)')
            from fzgx import oracle
            directory.mkdir(parents=True, exist_ok=True)
            source = directory / 'baseline.c'
            source.write_text(text)
            obj = oracle.compile_many(p, p.resolve(rec['symbol']).module, [source], directory / 'obj',
                                      rec['mw'], rec.get('flags') or None).get(source)
            if obj is None:
                raise
            return text, obj, 0.0, []
    sourcealign.layout = layout
    donors = defaultdict(lambda: defaultdict(list))
    for donor in sourcealign.catalog(p, 16):
        donors[donor['sdk']][donor['sdk_symbol']].append(donor['words'])
    cache = {}
    for i, cand in enumerate(candidates):
        rec = {k: v for k, v in row.items() if k != 'candidates'} | cand
        rec.setdefault('flags', sourcealign.source_flags(rec['sdk'], rec['source']))
        key = rec['sdk'], rec['source'], rec['mw']
        try:
            if key not in cache:
                cache[key] = sdkimport.declarations(
                    sdkimport.preprocess(ROOT / 'build/tools' / rec['sdk'], rec['source'], rec['mw']))
            result = sourcealign.import_candidate(p, rec, cache[key], out / f'c{i}', donors[rec['sdk']])
        except Exception as error:  # report and try the next donor
            print(f"{cand['sdk_symbol']:32} {cand['opcode_similarity']:.3f} ERROR {error}")
            continue
        print(f"{cand['sdk_symbol']:32} {cand['opcode_similarity']:.3f} {result['percent']:7.2f}"
              f" {'MATCH' if result['matched'] else ''} mw={rec['mw']} flags={rec.get('flags')!r} {result['path']}")


if __name__ == '__main__':
    main()
