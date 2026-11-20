"""Compare every unit compiled from SRC (a TU container or a standalone file) between git HEAD
and the working tree: SAME means byte-identical objects under the unit's exact flags.
Usage: unitcmp.py [--version GFZP01] src/rel/option/name_entry.c [...]
(build.ninja must be configured for that version)"""
import sys, json, subprocess, tempfile, pathlib
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d
from fzgx import tufile

def main():
    args = sys.argv[1:]; ver = 'GFZE01'
    if args[:1] == ['--version']: ver, args = args[1], args[2:]
    units = json.load(open('config/GFZE01/units.json'))
    nu = d.ninja_units(); bad = 0
    for path in args:
        rel = str(pathlib.Path(path).relative_to('src'))
        old = subprocess.run(['git', 'show', f'HEAD:{path}'], capture_output=True, text=True).stdout
        new = pathlib.Path(path).read_text()
        for u in units:
            if u.get('tu') == rel:
                g = lambda t: tufile.units_gen_text(tufile.parse(t), u['symbols']); key = f"build/{ver}/gen/{u['source']}"
            elif u['source'] == rel and not u.get('tu'):
                g = lambda t: t; key = f"src/{rel}"
            else:
                continue
            go, gn = g(old), g(new)
            if go == gn: continue
            if key not in nu: continue  # not built for this version
            mv, cf = nu[key]
            with tempfile.TemporaryDirectory() as td:
                a = d.compile_all(go, mv, cf, td, u); b = d.compile_all(gn, mv, cf, td, u)
            st = 'SAME' if a == b and None not in a else ('FAIL' if None in b else 'DIFF')
            bad += st != 'SAME'
            print(f'{st} {u["source"]} ({len(u["symbols"])} fns)')
    sys.exit(1 if bad else 0)

if __name__ == '__main__':
    main()
