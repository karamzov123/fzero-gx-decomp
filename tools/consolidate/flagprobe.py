"""Does a TU-wide compiler flag explain per-function pragma devices?  Compile every unit of TU
with FLAG appended, (a) unchanged source and (b) with the `#pragma PRAGMA ...` lines removed,
and compare against the current objects.  Usage: flagprobe.py src/rel/x/y.c "-fp_contract off" fp_contract"""
import sys, json, re, tempfile, pathlib
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d
from fzgx import tufile
path, flag, pragma = sys.argv[1], sys.argv[2], sys.argv[3]
rel = str(pathlib.Path(path).relative_to('src'))
text = pathlib.Path(path).read_text()
stripped = re.sub(rf'^[ \t]*#pragma\s+{pragma}\b.*\n', '', text, flags=re.M)
nu = d.ninja_units()
for u in json.load(open('config/GFZE01/units.json')):
    if u.get('tu') != rel: continue
    mv, cf = nu[f"build/GFZE01/gen/{u['source']}"]
    with tempfile.TemporaryDirectory() as td:
        base = d.compile_text(tufile.units_gen_text(tufile.parse(text), u['symbols']), mv, cf, td)
        a = d.compile_text(tufile.units_gen_text(tufile.parse(text), u['symbols']), mv, cf + ' ' + flag, td)
        b = d.compile_text(tufile.units_gen_text(tufile.parse(stripped), u['symbols']), mv, cf + ' ' + flag, td)
    print(u['source'], len(u['symbols']), 'flag:', 'SAME' if a == base else 'diff', ' flag+nopragma:', 'SAME' if b == base else 'diff')
