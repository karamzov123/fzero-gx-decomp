"""alts.py TEMPLATE OUTDIR [MAX]: expand alternative spellings into candidate sources.

Write alternatives inline as  @{first@|second@|third@}  (may span lines, no nesting).
Every combination is written to OUTDIR/vNNNN.c (capped at MAX, default 4096) with a
manifest OUTDIR/choices.json mapping file -> chosen index per site. Rank with
`tools/manual.py try SYMBOL OUTDIR` or `tools/manualkit/fast.py`.
"""
import itertools
import json
import re
import sys
from pathlib import Path

PAT = re.compile(r'@\{(.*?)@\}', re.S)


def expand(text):
    sites = [m.group(1).split('@|') for m in PAT.finditer(text)]
    pieces = PAT.split(text)  # literal, alt, literal, alt, ...
    for combo in itertools.product(*[range(len(s)) for s in sites]):
        out = []
        for k, piece in enumerate(pieces):
            out.append(piece if k % 2 == 0 else sites[k // 2][combo[k // 2]])
        yield combo, ''.join(out)


def main():
    tpl, outdir = Path(sys.argv[1]), Path(sys.argv[2])
    cap = int(sys.argv[3]) if len(sys.argv) > 3 else 4096
    outdir.mkdir(parents=True, exist_ok=True)
    for old in outdir.glob('v*.c'):
        old.unlink()
    manifest = {}
    for n, (combo, text) in enumerate(expand(tpl.read_text())):
        if n >= cap:
            break
        name = f'v{n:04d}.c'
        (outdir / name).write_text(text)
        manifest[name] = combo
    (outdir / 'choices.json').write_text(json.dumps(manifest))
    print(f'{len(manifest)} variants')


if __name__ == '__main__':
    main()
