#!/usr/bin/env python3
"""Cut a source file down to some of its function definitions (input for tu_recut.py).

  tu_cut.py SRC.c OUT.c FUNCTION [FUNCTION...]

Every top-level declaration, typedef, pragma and static inline helper is kept; a function
definition not listed becomes a prototype (its preceding pragmas stay balanced because only the
body is replaced). Unused leftovers are harmless; compare OUT.c with tu_regions.py before using it.
"""
import re, sys

HEAD = re.compile(r'^(?![ \t#/])(?!typedef\b)(?!struct\b)(?!union\b)(?!enum\b)[^;{}]*?\b(\w+)\s*\(([^;{}]*)\)\s*\{', re.M | re.S)


def definitions(text):
    """(name, start of header, end of body, header text) for each top-level function definition."""
    out, pos = [], 0
    while True:
        m = HEAD.search(text, pos)
        if not m:
            return out
        depth, i = 0, m.end() - 1
        while True:
            c = text[i]
            if c == '{':
                depth += 1
            elif c == '}':
                depth -= 1
                if depth == 0:
                    break
            i += 1
        header = text[m.start():m.end() - 1].rstrip()
        out.append((m[1], m.start(), i + 1, header))
        pos = i + 1


def main():
    src, dst, keep = sys.argv[1], sys.argv[2], set(sys.argv[3:])
    text = open(src).read()
    defs = definitions(text)
    missing = keep - {d[0] for d in defs}
    if missing:
        raise SystemExit(f'not defined in {src}: {sorted(missing)}')
    out, last = [], 0
    for name, start, end, header in defs:
        out.append(text[last:start])
        is_static_inline = re.match(r'static\s+inline\b|inline\b', header.lstrip())
        out.append(text[start:end] if name in keep or is_static_inline else ' '.join(header.split()) + ';')
        last = end
    out.append(text[last:])
    open(dst, 'w').write(''.join(out))


if __name__ == '__main__':
    main()
