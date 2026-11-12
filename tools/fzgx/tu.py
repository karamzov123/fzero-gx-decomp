"""Translation-unit organisation and symbol renames.

organize(): move per-function units into src/<module>/<tu>/ directories from
            tus.json (recovered from __FILE__ anchors), updating splits.txt,
            units.json and the ledger, then relink-verify.
rename():   rename a symbol everywhere it lives (symbols.txt, every source under
            src/, units.json, the ledger, the unit file/path, splits.txt) and
            relink-verify. dtk re-splits with the new name; the retail bytes are
            unaffected by names, so the hash check is the safety net.
"""

from __future__ import annotations

import json
import re
import subprocess
from pathlib import Path
from typing import Dict, List, Optional, Tuple

from . import oracle, tufile
from .ledger import Ledger
from .project import ROOT, STATE_DIR, Project

IDENT_RE = r"(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])"


def tu_map(p: Project, module: str) -> Dict[str, str]:
    """function symbol -> tu file stem (e.g. 'camera'), from tus.json."""
    return p.tu_map(module)


def unit_dir_for(p: Project, sym) -> str:
    """Directory (relative to src/) a unit for this symbol should live in."""
    base = p.module_src_prefix(sym.module)
    stem = tu_map(p, sym.module).get(sym.name)
    return f"{base}/{stem}" if stem else base


def _rewrite_splits(p: Project, module: str, old_unit: str, new_unit: str) -> None:
    path = p.module_config_dir(module) / "splits.txt"
    s = path.read_text()
    s = re.sub(rf"^{re.escape(old_unit)}:", f"{new_unit}:", s, flags=re.M)
    path.write_text(s)


def _move_unit(p: Project, module: str, old_unit: str, new_unit: str) -> None:
    src, dst = ROOT / "src" / old_unit, ROOT / "src" / new_unit
    dst.parent.mkdir(parents=True, exist_ok=True)
    if src.exists():
        subprocess.run(["git", "mv", "-k", str(src), str(dst)], cwd=ROOT, capture_output=True)
        if src.exists():  # untracked file: git mv did nothing
            src.rename(dst)
    _rewrite_splits(p, module, old_unit, new_unit)
    units = p.load_units()
    for u in units:
        if u["source"] == old_unit:
            u["source"] = new_unit
    p.save_units(units)
    l = Ledger()
    l.db.execute("UPDATE functions SET unit=? WHERE unit=?", (new_unit, old_unit))


def organize(p: Project, module: str, verify: bool = True) -> Dict[str, object]:
    """Move every carved unit of `module` into its TU directory."""
    tmap = tu_map(p, module)
    moved = []
    with oracle.build_lock():
        for u in p.load_units():
            if u["module"] != module or u.get("tu"):
                continue
            sym_name = u["symbols"][0]
            stem = tmap.get(sym_name)
            if not stem:
                continue
            want = f"{p.module_src_prefix(module)}/{stem}/{Path(u['source']).name}"
            if u["source"] != want:
                _move_unit(p, module, u["source"], want)
                moved.append((u["source"], want))
        ok = True
        if moved and verify:
            ok = oracle.configure(p).returncode == 0 and oracle.relink(p).returncode == 0
    return {"moved": len(moved), "ok": ok, "sample": moved[:5]}


def rename(p: Project, old: str, new: str, verify: bool = True) -> Dict[str, object]:
    """Rename symbol `old` to `new` everywhere; returns what changed."""
    if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", new):
        return {"ok": False, "error": f"not a C identifier: {new}"}
    sym = p.resolve(old)
    if sym is None:
        return {"ok": False, "error": f"unknown or ambiguous symbol {old}"}
    old = sym.name
    for m in p.modules:
        if new in p.symbols(m):
            return {"ok": False, "error": f"{new} already exists in {m}"}
    module = sym.module
    changed: List[str] = []
    with oracle.build_lock():
        # chosen typedef names are keyed by symbol
        tpath = p.module_config_dir(module) / "typedefs.json"
        if tpath.exists():
            d = json.loads(tpath.read_text())
            if old in d:
                d[new] = d.pop(old)
                tpath.write_text(json.dumps(d, indent=1, sort_keys=True) + "\n")
                changed.append(str(tpath.relative_to(ROOT)))
        # symbols.txt
        spath = p.module_config_dir(module) / "symbols.txt"
        s = spath.read_text()
        s2 = re.sub(rf"^{re.escape(old)} = ", f"{new} = ", s, flags=re.M)
        if s2 != s:
            spath.write_text(s2)
            changed.append(str(spath.relative_to(ROOT)))
        # sources
        pat = re.compile(IDENT_RE % re.escape(old))
        for f in [*(ROOT / "src").rglob("*.c"), *(ROOT / "src").rglob("*.s")]:
            t = f.read_text()
            if pat.search(t):
                f.write_text(pat.sub(new, t))
                changed.append(str(f.relative_to(ROOT)))
        for f in (ROOT / "include").rglob("*.h"):
            t = f.read_text()
            if pat.search(t):
                f.write_text(pat.sub(new, t))
                changed.append(str(f.relative_to(ROOT)))
        # units.json symbols + unit file/path if the unit is named after the function
        units = p.load_units()
        old_unit = new_unit = None
        for u in units:
            if old in u["symbols"]:
                u["symbols"] = [new if x == old else x for x in u["symbols"]]
                if Path(u["source"]).stem == old:
                    old_unit, new_unit = u["source"], str(Path(u["source"]).with_name(f"{new}.c"))
                    u["source"] = new_unit
        p.save_units(units)
        for template in (ROOT / 'config' / p.version).rglob('ldscript.tpl'):
            text = template.read_text()
            rewritten = pat.sub(new, text)
            if rewritten != text:
                template.write_text(rewritten)
                changed.append(str(template.relative_to(ROOT)))
        if old_unit:
            rec = next((u for u in units if u["source"] == new_unit), None)
            if not (rec and rec.get("tu")):  # block units have no file of their own
                src, dst = ROOT / "src" / old_unit, ROOT / "src" / new_unit
                subprocess.run(["git", "mv", "-k", str(src), str(dst)], cwd=ROOT, capture_output=True)
                if src.exists():
                    src.rename(dst)
            else:
                gen = tufile.gen_path(p, old_unit)
                gen.unlink(missing_ok=True)
            _rewrite_splits(p, module, old_unit, new_unit)
            changed.append(new_unit)
        # ledger
        l = Ledger()
        oldkey, newkey = p.key(sym), (f"{module}:{new}" if new in p.ambiguous_names() else new)
        l.db.execute("UPDATE functions SET symbol=?, unit=COALESCE(?, unit) WHERE symbol=?", (newkey, new_unit, oldkey))
        l.db.execute("UPDATE attempts SET symbol=? WHERE symbol=?", (newkey, oldkey))
        l.db.execute("UPDATE names SET target=? WHERE target=?", (newkey, oldkey))
        # tus.json
        tpath = p.module_config_dir(module) / "tus.json"
        if tpath.exists():
            t = tpath.read_text()
            t2 = re.sub(rf'"{re.escape(old)}"', f'"{new}"', t)
            if t2 != t:
                tpath.write_text(t2)
        p._symbols.pop(module, None)  # invalidate cache
        # saved attempt bodies name the symbol too: a rename must not strand them
        pat = re.compile(rf"\b{re.escape(old)}\b")
        for f in (STATE_DIR / "attempts").glob("*.c"):
            try:
                t = f.read_text()
            except OSError:
                continue
            if pat.search(t):
                f.write_text(pat.sub(new, t))
                changed.append(str(f))
        ok = True
        if verify:
            ok = oracle.configure(p).returncode == 0 and oracle.relink(p).returncode == 0
    return {"ok": ok, "old": old, "new": new, "changed": changed}


def rename_many(p: Project, mapping: Dict[str, str], verify: bool = True) -> Dict[str, object]:
    """Apply many renames, one relink at the end."""
    results = []
    for old, new in mapping.items():
        r = rename(p, old, new, verify=False)
        results.append(r)
        if not r.get("ok"):
            break
    ok = True
    if verify:
        ok = oracle.configure(p).returncode == 0 and oracle.relink(p).returncode == 0
    return {"ok": ok, "applied": sum(1 for r in results if r.get("ok")), "results": results}


def migrate(p: Project, module: str, verify: bool = True) -> Dict[str, object]:
    """Stitch the per-function units of every recovered TU of `module` into TU files.

    Matched units become blocks of src/<module>/<tu>.c (retail order; their includes
    form the prologue) and their objects are generated from the file. Nonmatching
    units are dropped from the build: the best body goes to .fzgx/attempts/, the
    split range and units.json entry go away (a later claim re-carves them).
    Standalone units of functions without a TU are left alone.
    """
    tmap = tu_map(p, module)
    units = p.load_units()
    prefix = p.module_src_prefix(module)
    l = Ledger()
    moved, dropped, files = 0, 0, set()
    by_tu: Dict[str, List[dict]] = {}
    keep: List[dict] = []
    drop_units: List[str] = []
    with oracle.build_lock():
        for u in units:
            if u["module"] != module or u.get("tu"):
                keep.append(u)
                continue
            name = u["symbols"][0]
            stem = tmap.get(name)
            if not stem or len(u["symbols"]) != 1:
                keep.append(u)
                continue
            src = ROOT / "src" / u["source"]
            text = src.read_text() if src.exists() else ""
            key = p.key(p.find_symbol(name, module))
            if u["status"] != "matching":
                if text.strip() and "arved by fzgx" not in text:  # a real attempt, not the carve stub
                    best = STATE_DIR / "attempts" / f"{key}.best.c"
                    if not best.exists():
                        best.parent.mkdir(parents=True, exist_ok=True)
                        best.write_text(text)
                drop_units.append(u["source"])
                l.db.execute("UPDATE functions SET unit=NULL WHERE symbol=?", (key,))
                dropped += 1
            else:
                tu_src = f"{prefix}/{stem}.c"
                u = dict(u, tu=tu_src)
                by_tu.setdefault(tu_src, []).append((u, text))
                keep.append(u)
                l.db.execute("UPDATE functions SET unit=? WHERE symbol=?", (u["source"], key))
                moved += 1
            if src.exists():
                subprocess.run(["git", "rm", "-q", "--cached", str(src)], cwd=ROOT, capture_output=True)
                src.unlink()
                files.add(u["source"])
        # split ranges of dropped units go back to the auto units
        if drop_units:
            spath = p.module_config_dir(module) / "splits.txt"
            lines = spath.read_text().split("\n")
            out, skip = [], False
            for ln in lines:
                if ln.endswith(":") and not ln.startswith(("\t", " ")):
                    skip = ln[:-1] in drop_units
                if not skip:
                    out.append(ln)
            spath.write_text(re.sub(r"\n{3,}", "\n\n", "\n".join(out)))
        # TU files, blocks in address order
        for tu_src, items in by_tu.items():
            tf = tufile.load(p, tu_src)
            for u, text in items:
                inc, body = tufile.split_includes(text)
                tf.prologue = tufile.merge_prologue(tf.prologue, inc)
                tf.blocks = [b for b in tf.blocks if b.name != u["symbols"][0]]
                tf.blocks.append(tufile.Block(u["symbols"][0], body))
            tf.blocks.sort(key=lambda b: tufile._addr_of(p, module, b.name))
            path = tufile.tu_path(p, tu_src)
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(tf.render())
            for u, _ in items:
                tufile.write_gen(p, u, tf)
        p.save_units(keep)
        # empty TU directories
        for d in sorted((ROOT / "src" / prefix).glob("*/"), reverse=True):
            if d.is_dir() and not any(d.iterdir()):
                d.rmdir()
        ok = True
        fix = {}
        if moved or dropped:
            oracle.configure(p)
            fix = fix_prologues(p, module)
            if verify:
                ok = oracle.relink(p).returncode == 0
    return {"moved": moved, "dropped": dropped, "tu_files": len(by_tu), "ok": ok, **fix}


def fix_prologues(p: Project, module: str) -> Dict[str, object]:
    """Block units whose generated unit does not compile under the TU prologue (a private
    typedef that clashes with the header, usually) are re-spliced `noprologue` with the
    includes they had as standalone files (from git HEAD when the file was just migrated)."""
    fixed, failed = [], []
    for u in p.load_units():
        if u["module"] != module or not u.get("tu"):
            continue
        unit = p.objdiff_unit_name(module, u["source"])
        cp = oracle.compile_unit(p, unit, u["source"])
        if cp.returncode == 0:
            continue
        cp2 = subprocess.run(["git", "show", f"HEAD:src/{u['source']}"], cwd=ROOT, text=True, capture_output=True)
        if cp2.returncode == 0:
            text = cp2.stdout
        else:
            tf = tufile.load(p, u["tu"])
            b = tf.get(u["symbols"][0])
            text = '#include "types.h"\n#include "rel/%s/globals.h"\n\n' % module + (b.body if b else "")
        tufile.splice(p, u, text, noprologue=True)
        cp = oracle.compile_unit(p, unit, u["source"])
        (fixed if cp.returncode == 0 else failed).append(u["symbols"][0])
    return {"noprologue": fixed, "still_failing": failed}


def regroup(p: Project, module: str, verify: bool = True) -> Dict[str, object]:
    """Make every recovered TU contiguous: a function belongs to the TU whose .text range in
    tus.json contains its address (CodeWarrior links each TU as one contiguous block).

    tus.json's function lists also carry data-vote assignments that put a function in a TU
    whose range does not contain it (title: fn_8_EFA4 listed under name_entry.c but inside
    operation.c's range), which makes the TU uncollapsible. Each such block moves to its
    range's TU file self-contained, carrying the prologue it matched under, so its object is
    byte-identical; its unit path, split entry and ledger row follow. On a failed relink every
    touched file is restored."""
    tpath = p.module_config_dir(module) / "tus.json"
    if not tpath.exists():
        return {"ok": True, "moved": [], "note": "no tus.json"}
    d = json.loads(tpath.read_text())
    syms = p.symbols(module)
    ranges = [(t["text"][0], t["text"][1], t["file"]) for t in d["tus"] if t.get("text")]

    def owner(addr: int) -> Optional[str]:
        return next((f for a, b, f in ranges if a <= addr < b), None)

    moves: List[Tuple[str, str, str]] = []  # (function, old file, new file)
    for t in d["tus"]:
        for f in t["functions"]:
            s = syms.get(f)
            if s is None:
                continue
            new = owner(s.addr)
            if new and new != t["file"]:
                moves.append((f, t["file"], new))
    if not moves:
        return {"ok": True, "moved": []}
    prefix = p.module_src_prefix(module)
    splits_path = p.module_config_dir(module) / "splits.txt"
    units_path = p.units_path
    touched: Dict[Path, Optional[str]] = {}

    def remember(path: Path) -> None:
        if path not in touched:
            touched[path] = path.read_text() if path.exists() else None

    for path in (tpath, splits_path, units_path):
        remember(path)
    l = Ledger()
    ledger_old: List[Tuple[str, Optional[str]]] = []
    moved = []
    with oracle.build_lock():
        units = p.load_units()
        by_sym = {(u["module"], u["symbols"][0]): u for u in units if u.get("symbols")}
        for f, old_file, new_file in moves:
            # tus.json: the function changes lists (kept in address order)
            for t in d["tus"]:
                if t["file"] == old_file:
                    t["functions"] = [x for x in t["functions"] if x != f]
                if t["file"] == new_file:
                    t["functions"] = sorted(set(t["functions"]) | {f}, key=lambda n: syms[n].addr if n in syms else 1 << 40)
            u = by_sym.get((module, f))
            if u is None:
                moved.append((f, old_file, new_file, "map only"))
                continue
            old_stem, new_stem = old_file.rsplit(".", 1)[0], new_file.rsplit(".", 1)[0]
            new_source = f"{prefix}/{new_stem}/{Path(u['source']).name}"
            old_source = u["source"]
            if u.get("tu"):
                old_tu, new_tu = u["tu"], f"{prefix}/{new_stem}.c"
                remember(tufile.tu_path(p, old_tu))
                remember(tufile.tu_path(p, new_tu))
                otf = tufile.load(p, old_tu)
                b = otf.get(f)
                if b is None:
                    moved.append((f, old_file, new_file, "no block"))
                    continue
                if "noprologue" not in b.flags:
                    b = tufile.Block(b.name, otf.prologue.rstrip("\n") + "\n\n" + b.body, list(b.flags) + ["noprologue"])
                otf.blocks = [x for x in otf.blocks if x.name != f]
                tufile._write_atomic(tufile.tu_path(p, old_tu), otf.render())
                ntf = tufile.load(p, new_tu)
                if not ntf.prologue.strip() and not ntf.blocks:
                    ntf.prologue = '#include "types.h"\n'
                ntf.blocks = [x for x in ntf.blocks if x.name != f] + [b]
                ntf.blocks.sort(key=lambda x: tufile._addr_of(p, module, x.name))
                tufile.tu_path(p, new_tu).parent.mkdir(parents=True, exist_ok=True)
                tufile._write_atomic(tufile.tu_path(p, new_tu), ntf.render())
                u["tu"] = new_tu
            else:
                src_old, src_new = ROOT / "src" / old_source, ROOT / "src" / new_source
                if src_old.exists():
                    remember(src_old)
                    remember(src_new)
                    src_new.parent.mkdir(parents=True, exist_ok=True)
                    src_new.write_text(src_old.read_text())
                    src_old.unlink()
            u["source"] = new_source
            s = splits_path.read_text()
            splits_path.write_text(re.sub(rf"^{re.escape(old_source)}:", f"{new_source}:", s, flags=re.M))
            row = l.db.execute("SELECT symbol, unit FROM functions WHERE unit=?", (old_source,)).fetchall()
            ledger_old += [(r[0], r[1]) for r in row]
            l.db.execute("UPDATE functions SET unit=? WHERE unit=?", (new_source, old_source))
            moved.append((f, old_file, new_file, "block"))
        p.save_units(units)
        tpath.write_text(json.dumps(d, indent=1) + "\n")
        if hasattr(p, "_tu_maps"):
            p._tu_maps.pop(module, None)
        for u in units:
            if u.get("module") == module and u.get("tu"):
                tufile.write_gen(p, u)
        ok = True
        if verify:
            ok = oracle.configure(p).returncode == 0 and oracle.relink(p).returncode == 0
        if not ok:
            for path, text in touched.items():
                if text is None:
                    if path.exists():
                        path.unlink()
                else:
                    path.write_text(text)
            for sym, unit in ledger_old:
                l.db.execute("UPDATE functions SET unit=? WHERE symbol=?", (unit, sym))
            if hasattr(p, "_tu_maps"):
                p._tu_maps.pop(module, None)
            tufile.regenerate(p)
            oracle.configure(p)
            oracle.relink(p)
    return {"ok": ok, "moved": moved}
