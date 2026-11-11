"""annotate.py MODULE SYMBOL... [--dry-run]: give relocation-free, undeclared data objects a dtk
`data:` element annotation in symbols.txt so `fzgx data-import` can emit a typed array.

The element width is inferred from the retail bytes, conservatively:
  float  every word is zero or a float of ordinary magnitude (1e-6 <= |x| <= 1e7);
  2byte  every halfword is a small signed integer (|h| < 0x1000), e.g. -1-terminated index lists;
  4byte  every word is a small signed integer;
  byte   otherwise (byte lists and mixed records).
Strings and all-zero objects are already handled by the importer and are left alone. The bytes
match whatever width is chosen; the width only decides how the C array reads.
"""
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from fzgx.project import Project  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]


def small(v, bits):
    v = v - (1 << bits) if v >= 1 << (bits - 1) else v
    return abs(v) < 0x1000


def infer(data, addr):
    n = len(data)
    if not any(data) or n < 2:
        return None
    if n % 4 == 0 and addr % 4 == 0:
        words = struct.unpack(f'>{n // 4}I', data)
        floats = struct.unpack(f'>{n // 4}f', data)
        if any(words) and all(w == 0 or 1e-6 <= abs(f) <= 1e7 for w, f in zip(words, floats)):
            return 'float'
    if n % 2 == 0 and addr % 2 == 0:
        halves = struct.unpack(f'>{n // 2}H', data)
        # Byte lists look like small halfwords too; require the high bytes to be sign fill.
        if all(small(h, 16) and (h >> 8) in (0, 0xFF) for h in halves):
            return '2byte'
    if n % 4 == 0 and addr % 4 == 0:
        words = struct.unpack(f'>{n // 4}I', data)
        if all(small(w, 32) for w in words) and any((w & 0xFFFF0000) not in (0,) for w in words):
            return '4byte'
    return 'byte'


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    dry = '--dry-run' in sys.argv
    module, names = args[0], args[1:]
    p = Project()
    path = ROOT / 'config/GFZE01' / ('' if module == 'main' else module) / 'symbols.txt'
    text = path.read_text()
    counts = {}
    for name in names:
        sym = p.find_symbol(name, module)
        if sym is None or sym.attrs.get('data'):
            continue
        data = p.bytes_at(module, name)
        if data is None:
            continue
        kind = infer(data[:sym.size], sym.addr)
        if kind is None:
            continue
        m = re.search(r'^(' + re.escape(name) + r' = [^\n]*?)$', text, re.M)
        if not m or ' data:' in m[1]:
            continue
        text = text.replace(m[1], m[1] + f' data:{kind}', 1)
        counts[kind] = counts.get(kind, 0) + 1
    print(counts)
    if not dry:
        path.write_text(text)


if __name__ == '__main__':
    main()
