"""Like unitcmp.py, but compares objects semantically (section bytes, relocations by symbol,
defined symbols; symbol-table order and compiler-numbered local names ignored)."""
import sys, json, subprocess, tempfile, pathlib
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, objsig
from fzgx import tufile

def sem(obj, td, tag):
    p = pathlib.Path(td) / f'{tag}.o'; p.write_bytes(obj)
    return objsig.canon(objsig.sig(p))[0]

def main():
    units = json.load(open('config/GFZE01/units.json')); nu = d.ninja_units(); bad = 0
    for path in sys.argv[1:]:
        rel = str(pathlib.Path(path).relative_to('src'))
        old = subprocess.run(['git', 'show', f'HEAD:{path}'], capture_output=True, text=True).stdout
        new = pathlib.Path(path).read_text()
        for u in units:
            if u.get('tu') == rel: g = lambda t: tufile.units_gen_text(tufile.parse(t), u['symbols']); key = f"build/GFZE01/gen/{u['source']}"
            elif u['source'] == rel and not u.get('tu'): g = lambda t: t; key = f"src/{rel}"
            else: continue
            if key not in nu: continue
            mv, cf = nu[key]
            with tempfile.TemporaryDirectory() as td:
                a = d.compile_all(g(old), mv, cf, td, u); b = d.compile_all(g(new), mv, cf, td, u)
                if None in b: print('FAIL', rel); bad += 1; continue
                same = all(sem(x, td, 'a') == sem(y, td, 'b') for x, y in zip(a, b))
            print(('SAME' if same else 'DIFF'), rel); bad += not same
    sys.exit(1 if bad else 0)

if __name__ == '__main__':
    main()
