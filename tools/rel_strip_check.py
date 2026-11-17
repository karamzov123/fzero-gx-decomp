#!/usr/bin/env python3
"""Fail when the dead-stripping link of a REL removed a local symbol that is not allowed.

Usage: rel_strip_check.py PLF ALLOW.txt OUT @OBJECTS.rsp

With `-strip_partial`, mwld removes each local symbol that nothing references
(tools/rel_forceactive.py). If the removed code or data had no bytes in retail, the hash check
cannot see the removal. This check compares the local functions and data objects that the
objects define with the local symbols of the PLF. Each named symbol that the link removed must
be in ALLOW.txt (one name per line, `#` starts a comment, a missing file is an empty list).
Names are counted, because a name can occur in many objects.

A compiler-generated name (`@123`, a literal) changes when the compile changes, so ALLOW.txt
cannot list it. Such a symbol can go only with an allowed symbol of the same object: the
number of its removed copies must not be more than the number of its objects that also lost
an allowed symbol. OUT lists the removed symbols.
"""
import sys
from collections import Counter

from rel_forceactive import symbols


def local_symbols(path):
    # Local (binding 0) functions and data objects (type 2 and 1) in a real section.
    return Counter(
        name
        for name, binding, kind, shndx in symbols(path)
        if binding == 0 and kind in (1, 2) and 0 < shndx < 0xFF00
    )


def main():
    plf, allow_path, out, rsp = sys.argv[1:5]
    defined = Counter()
    owners = {}
    for obj in open(rsp.lstrip("@")).read().split():
        for name, count in local_symbols(obj).items():
            defined[name] += count
            owners.setdefault(name, []).append(obj)
    removed = defined - local_symbols(plf)
    try:
        allow = {line.split("#")[0].strip() for line in open(allow_path)} - {""}
    except FileNotFoundError:
        allow = set()
    named = [name for name in removed if not name.startswith("@")]
    errors = [name for name in named if name not in allow]
    helpers = {obj for name in named if name in allow for obj in owners[name]}
    errors += [
        name
        for name in removed
        if name.startswith("@") and removed[name] > len(helpers.intersection(owners[name]))
    ]
    if errors:
        print(f"{plf}: the link removed local symbols that {allow_path} does not allow:")
        for name in sorted(errors):
            print(f"    {name} (defined in {', '.join(owners[name])})")
        sys.exit(1)
    with open(out, "w", newline="\n") as f:
        f.write("".join(f"{name}\n" for name in sorted(removed)))


if __name__ == "__main__":
    main()
