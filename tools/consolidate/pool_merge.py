#!/usr/bin/env python3
"""Pool map for a candidate that merges pool-mapped units into one TU.

  pool_merge.py CANDIDATE UNIT --from A,B,... [--extra "FLAGS"] [--mw GC/1.3.2]

UNIT supplies the compiler and flags (as in tu_regions.py); --from lists the old units whose
`pool` maps (units.json) are merged. Each old unit is compiled with its own build.ninja flags, and
each of its private `@N` literals is identified by section and bytes; the candidate's `@N` with the
same section and bytes take the same retail target. Keys that are not `@N` (`...bss.0`, named
statics) are carried over as they are. Prints the map in tu_install.py's --pool form, and every
candidate literal it cannot place. The link hash is still the proof.
"""
import argparse, json, pathlib, re, shlex, subprocess, sys, tempfile
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, objsig


def compile_obj(src, mw, flags, td, name):
    obj = pathlib.Path(td, name + '.o')
    r = subprocess.run(['build/tools/wibo', f'build/compilers/{mw}/mwcceppc.exe'] + shlex.split(flags) +
                       ['-c', str(src), '-o', str(obj)], capture_output=True, text=True)
    if r.returncode:
        raise SystemExit(f'{src}: compile failed\n{r.stdout[-900:]}')
    return objsig.sig(obj)


def literals(sig):
    out = {}
    for n, sec, off, size, _ in sig['defs']:
        if re.fullmatch(r'@\d+', n):
            out[n] = (sec, bytes(sig['sections'][sec][off:off + size]))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('candidate'); ap.add_argument('unit'); ap.add_argument('--from', dest='old', required=True)
    ap.add_argument('--extra', default=''); ap.add_argument('--mw')
    a = ap.parse_args()
    units = {u['source']: u for u in json.load(open('config/GFZE01/units.json'))}
    nu = d.ninja_units()
    target, carried = {}, {}
    with tempfile.TemporaryDirectory(prefix='poolm_') as td:
        for i, src in enumerate(a.old.split(',')):
            pool = units[src].get('pool') or {}
            mw, flags = nu['src/' + src]
            lits = literals(compile_obj('src/' + src, mw, flags, td, f'old{i}'))
            for key, value in pool.items():
                if key in lits:
                    prev = target.setdefault(lits[key], value)
                    if prev != value:
                        raise SystemExit(f'{lits[key]} maps to both {prev} and {value}')
                else:
                    carried[key] = value
        mw, flags = nu['src/' + a.unit]
        cand = literals(compile_obj(a.candidate, a.mw or mw, flags + ' ' + a.extra, td, 'cand'))
    out, missing = dict(carried), []
    for key, lit in sorted(cand.items(), key=lambda x: int(x[0][1:])):
        if lit in target:
            out[key] = target[lit]
        else:
            missing.append(f'{key} {lit[0]} {lit[1].hex()}')
    print(','.join(f'{k}={v}' for k, v in out.items()))
    for m in missing:
        print('unplaced:', m, file=sys.stderr)


if __name__ == '__main__':
    main()
