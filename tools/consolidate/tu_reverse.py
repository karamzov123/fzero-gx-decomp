#!/usr/bin/env python3
"""Write a source file with its function definitions in reverse order (MSL's real source order).

  tu_reverse.py SRC.c OUT.c

MWCC's -inline deferred emits a file's functions in reverse source order, so a TU compiled with it
(MSL) is laid out in retail last-defined-first. This keeps the preamble and the text between
definitions with the definition that follows it, adds a prototype for every function ahead of the
first definition, and reverses the definitions. Check the result with tu_order.py and tu_regions.py.
"""
import re, sys, pathlib
sys.path.insert(0, str(pathlib.Path(__file__).parent))
from tu_cut import definitions


def main():
    src, dst = sys.argv[1], sys.argv[2]
    text = open(src).read()
    defs = definitions(text)
    if not defs:
        raise SystemExit('no definitions')
    preamble = [text[:defs[0][1]]]
    chunks, last = [], defs[0][1]
    for i, (name, start, end, header) in enumerate(defs):
        lead = text[last:start].splitlines(True) if i else []
        # a leading `#pragma ... reset` closes the previous definition's pragma; trailing pragmas
        # and comments open this one; declarations in between move to the preamble
        k = 0
        while k < len(lead) and (lead[k].strip() == '' or (lead[k].startswith('#pragma') and 'reset' in lead[k])):
            k += 1
        j = len(lead)
        while j > k and (lead[j - 1].strip() == '' or lead[j - 1].lstrip().startswith(('#pragma', '//', '/*'))):
            j -= 1
        if chunks:
            chunks[-1] += ''.join(lead[:k])
        preamble.append(''.join(lead[k:j]))
        chunks.append(''.join(lead[j:]) + text[start:end])
        last = end
    tail = text[last:]
    tail_lines = tail.splitlines(True)
    k = 0
    while k < len(tail_lines) and (tail_lines[k].strip() == '' or (tail_lines[k].startswith('#pragma') and 'reset' in tail_lines[k])):
        k += 1
    chunks[-1] += ''.join(tail_lines[:k]); tail = ''.join(tail_lines[k:])
    preamble = ''.join(preamble)
    bare = lambda h: ' '.join(re.sub(r'/\*.*?\*/|//[^\n]*', '', h, flags=re.S).split())
    protos = ''.join(bare(h) + ';\n' for _, _, _, h in defs if not bare(h).startswith(('static', 'inline')))
    out = (preamble.rstrip() + '\n\n' + protos + '\n' + '\n\n'.join(c.strip('\n') for c in reversed(chunks)) + '\n' + tail)
    # merge markers (`/* --- dol/x.c --- */`) name the old per-function files; they mean nothing here
    out = re.sub(r'^/\* --- dol/[^*]* --- \*/\n(?=\S)?', '', out, flags=re.M)
    open(dst, 'w').write(re.sub(r'\n{3,}', '\n\n', out))


if __name__ == '__main__':
    main()
