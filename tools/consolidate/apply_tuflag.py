"""Apply a measured TU-wide flag: strip `#pragma KIND` lines from each TU file and add the flag
to every unit of that TU in units.json (textual edit; keeps formatting).
Usage: apply_tuflag.py KIND FLAG1 FLAG2 src/rel/a.c [...]   e.g. fp_contract -fp_contract off ..."""
import sys, re, json, pathlib
kind, f1, f2, files = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4:]
up = pathlib.Path('config/GFZE01/units.json'); u = up.read_text()
units = json.loads(u)
for path in files:
    p = pathlib.Path(path); t = p.read_text()
    t2, n = re.subn(rf'^[ \t]*#pragma\s+{kind}\b.*\n', '', t, flags=re.M); p.write_text(t2)
    rel = str(p.relative_to('src')); cnt = 0
    for x in units:
        if x.get('tu') != rel: continue
        fl = x.get('extra_cflags') or []
        if f'{f1} {f2}' in fl or any(a == f1 and b == f2 for a, b in zip(fl, fl[1:])): continue
        i = u.index(f'"source": "{x["source"]}"'); j = u.index('\n  }', i); seg = u[i:j]
        if '"extra_cflags": []' in seg:
            seg = seg.replace('"extra_cflags": []', f'"extra_cflags": [\n      "{f1}",\n      "{f2}"\n    ]')
        elif '"extra_cflags": [' in seg:
            seg = seg.replace('"extra_cflags": [', f'"extra_cflags": [\n      "{f1}",\n      "{f2}",', 1)
        else:
            seg = seg.rstrip() + f',\n    "extra_cflags": [\n      "{f1}",\n      "{f2}"\n    ]'
        u = u[:i] + seg + u[j:]; cnt += 1
    print(f'{path}: -{n} pragma lines, flag on {cnt} units')
json.loads(u); up.write_text(u)
