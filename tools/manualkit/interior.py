"""interior.py MODULE SLICE OWNER [--dry-run]: fold a dtk-invented interior symbol back into its owner.

dtk cuts a symbol wherever code addresses a field, so one retail object can appear as an owner
plus misaligned slices (a 10-byte "object" at a 2-aligned address cannot be an MWCC array: arrays
and structs are always 4-aligned). Such slices block data import. This removes SLICE from the
module's symbols.txt, grows OWNER to cover it, renames SLICE in every block or unit that uses it
to `OWNER__fzgx_offset_D`, and records `OWNER__fzgx_offset_D -> OWNER+0xD` in those units' pool
maps, so the post-compile retarget gives the exact retail relocation. Code bytes do not change.
Verify with configure + ninja + the 16 hashes afterwards.
"""
import json
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    dry = '--dry-run' in sys.argv
    module, slice_, owner = args
    cfg = ROOT / 'config/GFZE01' / ('' if module == 'main' else module) / 'symbols.txt'
    text = cfg.read_text()
    line = lambda n: re.search(r'^' + re.escape(n) + r' = (\.\w+):0x([0-9A-Fa-f]+); // type:object size:0x([0-9A-Fa-f]+)([^\n]*)$', text, re.M)
    s, o = line(slice_), line(owner)
    if not s or not o or s[1] != o[1]:
        raise SystemExit('both symbols must be objects in the same section')
    s_addr, s_size, o_addr, o_size = int(s[2], 16), int(s[3], 16), int(o[2], 16), int(o[3], 16)
    if o_addr + o_size != s_addr:
        raise SystemExit(f'{slice_} does not follow {owner} directly')
    delta = s_addr - o_addr
    alias = f'{owner}__fzgx_offset_{delta:X}'
    new_size = s_addr + s_size - o_addr
    attrs = re.sub(r'\s*data:\w+', '', o[4])  # the merged object is no longer one scalar kind
    text = text.replace(o[0], f'{owner} = {o[1]}:0x{o_addr:08X}; // type:object size:0x{new_size:X}{attrs}')
    text = text.replace(s[0] + '\n', '')

    files = subprocess.run(['git', 'grep', '-l', '-w', slice_, '--', 'src'], cwd=ROOT,
                           capture_output=True, text=True).stdout.split()
    units = json.loads((ROOT / 'config/GFZE01/units.json').read_text())
    by_source = {u['source']: u for u in units}
    by_tu_symbol = {(u.get('tu'), sym): u for u in units for sym in u.get('symbols', [])}
    touched, edits = [], {}
    word = re.compile(r'\b' + re.escape(slice_) + r'\b')
    # An unused extern emits no symbol, and the retarget rejects a mapping with nothing to retarget.
    used = lambda src: any(word.search(l) for l in src.splitlines() if not l.lstrip().startswith('extern '))
    for f in files:
        path = ROOT / f
        body = path.read_text()
        rel = f[len('src/'):]
        if f.endswith('.s'):
            raise SystemExit(f'{f}: assembly reference, edit by hand ({owner}+0x{delta:X})')
        blocks = list(re.finditer(r'/\* fzgx:begin (\S+)[^*]*\*/(.*?)/\* fzgx:end \1 \*/', body, re.S))
        if blocks:
            for b in blocks:
                if used(b[2]):
                    unit = by_tu_symbol.get((rel, b[1]))
                    if unit is None:
                        raise SystemExit(f'{f}: block {b[1]} has no unit')
                    touched.append(unit)
        elif used(body):
            unit = by_source.get(rel)
            if unit is None:
                raise SystemExit(f'{f}: no unit')
            touched.append(unit)
        edits[path] = word.sub(alias, body)
    for unit in touched:
        unit.setdefault('pool', {})[alias] = f'{owner}+0x{delta:X}'
    print(f'{slice_} -> {owner}+0x{delta:X} (owner size 0x{o_size:X} -> 0x{new_size:X}); '
          f'{len(files)} files, units: {[u["symbols"][0] for u in touched]}')
    if dry:
        return
    cfg.write_text(text)
    for path, body in edits.items():
        path.write_text(body)
    (ROOT / 'config/GFZE01/units.json').write_text(json.dumps(units, indent=2) + '\n')


if __name__ == '__main__':
    main()
