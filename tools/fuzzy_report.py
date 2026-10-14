"""Fuzzy match for decomp.dev: score the best partial C body of each unmatched function.

objdiff's fuzzy_match_percent only moves for code that has a base object, and an unmatched
function lives in a retail auto object that has none, so the report scores it 0% however close
the best attempt came. `apply` compiles the bodies kept in fuzzy/<VERSION>/, merges them per
auto unit into a base object, and regenerates report.json against a copy of objdiff.json that
points those units at it. Nothing is linked and no split changes: only the fuzzy measure moves.
Every exact measure (matched code, data, functions, complete units) is checked to be unchanged,
and a body that objdiff would score 100% is dropped, because a match is only real once
`fzgx submit` has linked it. The exact report is kept as report.exact.json.

`export` refreshes fuzzy/<VERSION>/ from the local ledger's best attempts (needs .fzgx/, or
--ledger). tools/fuzzy_refresh.py runs it whenever main or the ledger changes.

    python3 tools/fuzzy_report.py apply --version GFZE01 [--compilers DIR] [--binutils DIR]
    uv run tools/fuzzy_report.py export --version GFZE01
"""

from __future__ import annotations

import argparse
import collections
import json
import shlex
import shutil
import sqlite3
import subprocess
import sys
from pathlib import Path
from typing import Dict, List, Optional, Tuple

ROOT = Path(__file__).resolve().parents[1]
EXACT = ("matched_code", "matched_data", "matched_functions", "complete_code", "complete_data",
         "complete_units", "total_code", "total_data", "total_functions", "total_units")
HEADER = "/* Non-matching: best partial attempt ({pct:.2f}% in the project ledger). Scored for the\n" \
         " * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */\n"
PRIVATE = ("/home/", "/tmp/", "armando", ".cache/")


def tool(binutils: Path, name: str) -> str:
    return str(binutils / f"powerpc-eabi-{name}")


def text_globals(binutils: Path, obj: Path) -> List[str]:
    out = subprocess.run([tool(binutils, "nm"), "--defined-only", str(obj)],
                         capture_output=True, text=True).stdout
    return [p[2] for p in (line.split() for line in out.splitlines()) if len(p) == 3 and p[1] == "T"]


def text_symbols(binutils: Path, obj: Path) -> List[str]:
    out = subprocess.run([tool(binutils, "nm"), "--defined-only", str(obj)],
                         capture_output=True, text=True).stdout
    return [p[2] for p in (line.split() for line in out.splitlines()) if len(p) == 3 and p[1] in "Tt"]


def owners(od: dict, binutils: Path) -> Dict[Tuple[str, str], str]:
    """(module, function) -> name of the base-less objdiff unit whose retail object holds it."""
    found: Dict[Tuple[str, str], List[str]] = collections.defaultdict(list)
    for u in od["units"]:
        target = ROOT / u.get("target_path", "")
        if "base_path" in u or not target.is_file():
            continue
        module = u["name"].split("/", 1)[0]
        for name in text_symbols(binutils, target):
            found[(module, name)].append(u["name"])
    return {k: v[0] for k, v in found.items() if len(v) == 1}


def compile_bodies(entries: List[dict], src_dir: Path, out: Path, compilers: Path,
                   wibo: Path) -> Dict[str, Path]:
    """One mwcc process per (module, compiler, flags) group; returns symbol -> object."""
    groups: Dict[Tuple[str, str, Tuple[str, ...]], List[dict]] = collections.defaultdict(list)
    for e in entries:
        groups[(e["module"], e["mw"], tuple(e["flags"]))].append(e)
    objects: Dict[str, Path] = {}
    for n, ((module, mw, flags), group) in enumerate(sorted(groups.items())):
        d = out / f"{n:03d}_{module}"
        d.mkdir(parents=True, exist_ok=True)
        cmd = [str(wibo), str(compilers / mw / "mwcceppc.exe"), *flags, "-nofail", "-c", "-o", str(d)]
        for i in range(0, len(group), 200):
            chunk = group[i:i + 200]
            subprocess.run(cmd + [str(src_dir / e["module"] / f"{e['symbol']}.c") for e in chunk],
                           cwd=ROOT, capture_output=True, text=True, timeout=900)
        for e in group:
            obj = d / f"{e['symbol']}.o"
            if obj.is_file():
                objects[e["symbol"] + "@" + e["module"]] = obj
    return objects


def merge(binutils: Path, objs: List[Path], dest: Path) -> bool:
    dest.parent.mkdir(parents=True, exist_ok=True)
    if len(objs) == 1:
        shutil.copyfile(objs[0], dest)
        return True
    # several bodies may define the same helper data; the first definition is enough to score
    r = subprocess.run([tool(binutils, "ld"), "-r", "-z", "muldefs", "-o", str(dest), *map(str, objs)],
                       capture_output=True, text=True)
    if r.returncode:
        return False
    # ld -r rewrites mwcc's .comment into a form objdiff refuses to parse
    subprocess.run([tool(binutils, "objcopy"), "-R", ".comment", str(dest)], check=True)
    return True


def functions(report: dict) -> Dict[Tuple[str, str], float]:
    return {(u["name"], f["name"]): f.get("fuzzy_match_percent", 0.0)
            for u in report["units"] for f in u.get("functions", [])}


def apply(version: str, compilers: Path, binutils: Path, wibo: Path, objdiff: Path,
          src_dir: Optional[Path] = None, replace: bool = True) -> dict:
    """Score the fuzzy bodies; returns a summary with the symbols that were used and dropped."""
    src_dir = src_dir or ROOT / "fuzzy" / version
    build = ROOT / "build" / version
    work = build / "fuzzy"
    shutil.rmtree(work, ignore_errors=True)
    work.mkdir(parents=True)
    exact_path = build / "report.json"
    exact = json.loads(exact_path.read_text())
    if exact.get("fuzzy_bodies") is not None:
        raise SystemExit("report.json is already a fuzzy report; rebuild it first")
    od = json.loads((ROOT / "objdiff.json").read_text())
    entries = json.loads((src_dir / "index.json").read_text())
    owner = owners(od, binutils)
    dropped: Dict[str, str] = {}
    placed = []
    for e in entries:
        unit = owner.get((e["module"], e["symbol"]))
        if unit:
            placed.append({**e, "unit": unit})
        else:
            dropped[e["symbol"]] = "no base-less unit holds it (carved or matched since export)"
    objects = compile_bodies(placed, src_dir, work / "obj", compilers, wibo)
    by_unit: Dict[str, List[dict]] = collections.defaultdict(list)
    for e in placed:
        obj = objects.get(e["symbol"] + "@" + e["module"])
        if obj is None:
            dropped[e["symbol"]] = "does not compile"
            continue
        defined = text_globals(binutils, obj)
        if e["symbol"] not in defined:
            dropped[e["symbol"]] = "object does not define the function"
            continue
        e["obj"] = obj
        by_unit[e["unit"]].append(e)
    exact_100 = {k for k, v in functions(exact).items() if v >= 100.0}
    for _ in range(4):
        bases: Dict[str, Path] = {}
        for unit, group in by_unit.items():
            if not group:
                continue
            dest = work / "base" / (unit.replace("/", "__") + ".o")
            if merge(binutils, [e["obj"] for e in group], dest):
                bases[unit] = dest
            else:
                for e in group:
                    dropped[e["symbol"]] = "merge failed"
        cfg = json.loads(json.dumps(od))
        for u in cfg["units"]:
            for key in ("target_path", "base_path"):
                if key in u:
                    u[key] = str(ROOT / u[key])
            if u["name"] in bases:
                u["base_path"] = str(bases[u["name"]])
        (work / "objdiff.json").write_text(json.dumps(cfg))
        out = work / "report.json"
        subprocess.run([str(objdiff), "report", "generate", "-o", str(out)], cwd=work, check=True,
                       capture_output=True, text=True)
        fuzzy = json.loads(out.read_text())
        # a body objdiff scores 100% has not been linked: it must not count as matched
        new_100 = {k for k, v in functions(fuzzy).items() if v >= 100.0} - exact_100
        if not new_100:
            break
        for unit, name in new_100:
            dropped[name] = "objdiff scores it 100% (submit it instead)"
            by_unit[unit] = [e for e in by_unit.get(unit, []) if e["symbol"] != name]
    else:
        raise SystemExit("fuzzy report: bodies kept reaching 100%; exact report left in place")
    changed = [k for k in EXACT if str(exact["measures"].get(k, 0)) != str(fuzzy["measures"].get(k, 0))]
    if changed:
        raise SystemExit(f"fuzzy report changed exact measures {changed}; exact report left in place")
    used = sorted(e["symbol"] for g in by_unit.values() for e in g)
    summary = {"bodies": len(entries), "used": len(used), "dropped": len(dropped),
               "fuzzy_match_percent": [exact["measures"].get("fuzzy_match_percent", 0.0),
                                       fuzzy["measures"].get("fuzzy_match_percent", 0.0)],
               "matched_code_percent": fuzzy["measures"].get("matched_code_percent", 0.0)}
    if replace:
        shutil.copyfile(exact_path, build / "report.exact.json")
        shutil.copyfile(out, exact_path)
    summary["used_symbols"], summary["dropped_symbols"] = used, dropped
    return summary


def export(version: str, compilers: Path, binutils: Path, wibo: Path, objdiff: Path,
           out_dir: Path, ledger: Optional[Path] = None) -> None:
    """Write the best saved attempt of every unmatched, uncarved function to fuzzy/<VERSION>/."""
    sys.path.insert(0, str(ROOT / "tools"))
    from fzgx import oracle  # local-only: the ledger and its attempts never leave this machine
    from fzgx.project import Project
    p = Project(version)
    db = sqlite3.connect(f"file:{ledger or ROOT / '.fzgx' / 'ledger.db'}?mode=ro", uri=True)
    rows = db.execute(
        "select f.symbol, a.best_body_path, a.best_in_attempt from functions f "
        "join attempts a on a.symbol = f.symbol where f.status != 'matched' "
        "and coalesce(a.best_body_path, '') != '' order by f.symbol, a.best_in_attempt desc").fetchall()
    best: Dict[str, Tuple[Path, float]] = {}
    for key, path, pct in rows:
        if key not in best and Path(path).is_file():
            best[key] = (Path(path), pct or 0.0)
    staging = ROOT / "build" / version / "fuzzy-export"
    shutil.rmtree(staging, ignore_errors=True)
    entries = []
    skipped = collections.Counter()
    for key, (path, pct) in sorted(best.items()):
        sym = p.resolve(key)
        if sym is None:
            skipped["unresolved"] += 1
            continue
        if p.unit_of(sym):
            skipped["carved"] += 1
            continue
        text = path.read_text(errors="replace")
        if any(marker in text.lower() for marker in PRIVATE):
            skipped["private text"] += 1
            continue
        mw, extra = oracle.version_for(p, sym, path)
        cmd = oracle.compile_command(p, sym.module, mw, extra)
        flags = cmd[2:cmd.index("-nofail")]
        dest = staging / sym.module / f"{sym.name}.c"
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_text(HEADER.format(pct=pct) + text)
        entries.append({"symbol": sym.name, "module": sym.module, "percent": round(pct, 2),
                        "mw": Path(cmd[1]).parent.relative_to(ROOT / "build" / "compilers").as_posix(),
                        "flags": flags})
    (staging / "index.json").write_text(json.dumps(entries, indent=1) + "\n")
    summary = apply(version, compilers, binutils, wibo, objdiff, src_dir=staging, replace=False)
    keep = set(summary["used_symbols"])
    shutil.rmtree(out_dir, ignore_errors=True)
    kept = []
    for e in entries:
        if e["symbol"] in keep:
            (out_dir / e["module"]).mkdir(parents=True, exist_ok=True)
            shutil.copyfile(staging / e["module"] / f"{e['symbol']}.c", out_dir / e["module"] / f"{e['symbol']}.c")
            kept.append(e)
    (out_dir / "index.json").write_text(json.dumps(kept, indent=1) + "\n")
    reasons = collections.Counter(summary["dropped_symbols"].values())
    print(json.dumps({"exported": len(kept), "skipped": dict(skipped), "dropped": dict(reasons),
                      "fuzzy_match_percent": summary["fuzzy_match_percent"]}, indent=1))


def main() -> None:
    global ROOT
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("cmd", choices=["apply", "export"])
    ap.add_argument("--version", default="GFZE01")
    ap.add_argument("--compilers", type=Path, default=ROOT / "build" / "compilers")
    ap.add_argument("--binutils", type=Path, default=ROOT / "build" / "binutils")
    ap.add_argument("--wibo", type=Path, default=ROOT / "build" / "tools" / "wibo")
    ap.add_argument("--objdiff", type=Path, default=ROOT / "build" / "tools" / "objdiff-cli")
    ap.add_argument("--out", type=Path, help="export: destination (default fuzzy/<VERSION>)")
    ap.add_argument("--root", type=Path, help="project checkout to read (default: this one)")
    ap.add_argument("--ledger", type=Path, help="export: ledger.db to read (default .fzgx/ledger.db)")
    a = ap.parse_args()
    if a.root:
        ROOT = a.root.resolve()
        for name in ("compilers", "binutils", "wibo", "objdiff"):
            setattr(a, name, ROOT / getattr(a, name).relative_to(Path(__file__).resolve().parents[1]))
    if a.cmd == "export":
        export(a.version, a.compilers, a.binutils, a.wibo, a.objdiff, a.out or ROOT / "fuzzy" / a.version,
               a.ledger)
    else:
        s = apply(a.version, a.compilers, a.binutils, a.wibo, a.objdiff)
        print(json.dumps({k: v for k, v in s.items() if k != "used_symbols"}, indent=1))


if __name__ == "__main__":
    main()
