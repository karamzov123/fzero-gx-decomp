#!/usr/bin/env python3
"""Carry a `fzgx rename --map MAP` to everything it leaves alone (run it right after the rename).

  rename_regions.py MAP.json

`fzgx rename` renames the GFZE01 symbols, sources and units but re-sorts and reformats
config/GFZE01/units.json and leaves the region symbol files and TU maps alone. This rewrites
units.json from git HEAD with only the renames (names and the moved `dol/<old>.c` sources),
requires the result to hold the same units as the rename produced (keeping HEAD's
`matching_for`, which the rename narrows to GFZE01 on units it re-saves, and HEAD's pool keys,
which it leaves under their old names), renames `main:<old>` data-import provenance keys, and renames the
symbols in config/GFZJ01|GFZP01/**/symbols.txt and state/tumap/*.json.
"""
import json, pathlib, re, subprocess, sys

VERSIONS = ('GFZJ01', 'GFZP01')


def main():
    names = json.load(open(sys.argv[1]))
    word = re.compile(r'\b(' + '|'.join(map(re.escape, names)) + r')\b')
    head = subprocess.run(['git', 'show', 'HEAD:config/GFZE01/units.json'], capture_output=True, text=True, check=True).stdout
    text = word.sub(lambda m: names[m[1]], head)
    # the rename re-saves some units with "matching_for": ["GFZE01"]; HEAD's versions stand
    # and renames pool values but not pool keys (the unit's own definitions, renamed in its source)
    key = lambda u: json.dumps({k: v for k, v in u.items() if k not in ('matching_for', 'pool')}, sort_keys=True)
    now = json.load(open('config/GFZE01/units.json'))
    if sorted(map(key, json.loads(text))) != sorted(map(key, now)):
        raise SystemExit('units.json: the rename changed more than names; inspect it by hand')
    open('config/GFZE01/units.json', 'w').write(text)
    for v in VERSIONS:
        for path in pathlib.Path('config', v).rglob('symbols.txt'):
            old = path.read_text()
            new = re.sub(r'^(\S+)(?= = )', lambda m: names.get(m[1], m[1]), old, flags=re.M)
            if new != old:
                path.write_text(new)
                print('renamed in', path)
    imports = pathlib.Path('state/dataimports/GFZE01.json')
    prov = json.loads(imports.read_text()); moved = 0
    for old, new in names.items():
        v = prov.pop(f'main:{old}', None)
        if v is not None:
            v['symbol'] = new
            v['definition'] = word.sub(lambda m: names[m[1]], v.get('definition', ''))
            for d in v.get('declarations', []):
                d['declaration'] = word.sub(lambda m: names[m[1]], d['declaration'])
            prov[f'main:{new}'] = v; moved += 1
    if moved:
        imports.write_text(json.dumps(prov, indent=2, sort_keys=True) + '\n')
        print('renamed', moved, 'provenance keys')
    for path in pathlib.Path('state/tumap').glob('*.json'):
        old = path.read_text()
        new = re.sub(r'"(\w+)"', lambda m: '"' + names.get(m[1], m[1]) + '"', old)
        if new != old:
            path.write_text(new)
            print('renamed in', path)


if __name__ == '__main__':
    main()
