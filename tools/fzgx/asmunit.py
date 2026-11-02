"""Assembly units: a function whose retail body no C can produce (a privileged instruction
and `blr`: the SDK wrote it in assembly) links from its own assembly, the file dtk's split
writes for the unit, copied into src/ and assembled by the build. Byte-exact by construction;
the ledger records the function as `asm`, done but not decompiled.
"""

from __future__ import annotations

import glob
import shutil
import subprocess
from pathlib import Path
from typing import Dict, List, Optional

from . import carve, oracle
from .ledger import Ledger
from .project import ROOT, Project
from .uncarve import uncarve


import re

_BRANCH_RE = re.compile(r"^(/\* [0-9A-F]{8} [0-9A-F]{8}  ([0-9A-F]{2}) ([0-9A-F]{2}) ([0-9A-F]{2}) ([0-9A-F]{2}) \*/\t)(b\w+?)([+-])( .*)$")


def fix_branch_hints(text: str) -> tuple:
    """dtk prints the raw branch-hint bit (y=1 as `+`); GNU as reads `+`/`-` relative to the
    branch direction (a backward branch is predicted taken by default, so `+` encodes y=0).
    A hinted backward conditional branch must be spelled `-` to assemble to retail's bytes."""
    out, n = [], 0
    for line in text.splitlines():
        m = _BRANCH_RE.match(line)
        if m:
            word = int("".join(m.group(2, 3, 4, 5)), 16)
            if (word >> 26) == 16 and word & 0x8000 and m.group(7) == "+":  # bc, BD < 0, y=1
                line = f"{m.group(1)}{m.group(6)}-{m.group(8)}  # `+` in dtk's output: raw hint bit, backward branch"
                n += 1
        out.append(line)
    return "\n".join(out) + "\n", n


def _compiler_generated_aliases(p: Project, sym) -> List[str]:
    """Labels at this function's address that mwld generates itself, so we must not define them.

    The SDK's save/restore family is the case: `__save_fpr` and `_savefpr_14` share one address,
    and every `_savefpr_15..31` label follows. Those names are compiler-generated -- mwld
    synthesises them for any prologue that saves f14-f31, and the runtime's own C references
    them. An object that defines them collides with the ones mwld is about to emit:

        ### mwldeppc.exe Linker Warning:
        #   Symbol '_restfpr_14' defined in '__restore_fpr.o' is also defined as a
        #   linker generated symbol.

    and the link fails after a full configure+split cycle. See docs/findings/281.

    The ordinary linker-alias case is the opposite requirement: there our C must *keep*
    retail's label reachable, which is what `carve.retain_entry_labels` does. Here retail's
    labels must not be defined by us at all, because the linker owns them.
    """
    out = []
    for name in p.symbols(sym.module):
        if name == sym.name:
            continue
        if not re.match(r"^_(save|rest)(gpr|fpr)_", name):
            continue
        other = p.symbols(sym.module)[name]
        if other.addr == sym.addr:
            out.append(name)
    return out


def _snapshot_file(snapshot: Dict[Path, Optional[bytes]], path: Path) -> None:
    if path not in snapshot:
        snapshot[path] = path.read_bytes() if path.exists() else None


def _restore_snapshot(p: Project, snapshot: Dict[Path, Optional[bytes]], split: bool = True) -> None:
    with oracle.build_lock("units.lock"):
        for path, data in snapshot.items():
            if data is None:
                path.unlink(missing_ok=True)
            else:
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(data)
    p._symbols.clear()
    p.__dict__.get("_splits_cache", {}).clear()
    if split:
        from .api import _reconfigure_and_split
        _reconfigure_and_split(p)


def make(p: Project, symbols: List[str]) -> Dict[str, object]:
    """Carve each symbol into an assembly-backed unit, split, copy the asm, relink and hash.
    On a hash failure every unit of this call is restored to its exact pre-call state."""
    made: List[tuple] = []
    refused: List[dict] = []
    snapshot: Dict[Path, Optional[bytes]] = {}
    _snapshot_file(snapshot, p.units_path)
    for s in symbols:
        sym = p.resolve(s)
        if sym is None:
            continue
        # A registered unit is only a reason to skip when it already produces bytes. Units left
        # `nonmatching` by a TU migration (a units.json record with a `tu` and no src file at
        # all) are exactly the functions that have no source to build, so the old guard made
        # them permanently unconvertible: `unit_of` is split-based, so it is truthy for any
        # claimed range. Measured on fn_1_10E3B4 and fn_1_120804, 7 KB each of paired-single
        # assembly with no possible C body.
        existing = p.unit_of(sym)
        if existing:
            record = next((u for u in p.load_units()
                           if u.get('module') == sym.module and u.get('source') == existing), None)
            if record is None or record.get('status') == 'matching':
                continue
        aliases = _compiler_generated_aliases(p, sym)
        if aliases:
            # Refuse before carving. Naming the aliases is the useful part: it is the
            # difference between "did not match" and "cannot be represented".
            refused.append({"symbol": s, "reason": "address aliases compiler-generated symbols",
                            "aliases": aliases[:6], "alias_count": len(aliases)})
            continue
        cfg = p.module_config_dir(sym.module)
        for cfg_name in ("splits.txt", "symbols.txt", "ldscript.tpl"):
            _snapshot_file(snapshot, cfg / cfg_name)
        default_src = f"{carve.unit_dir_for(p, sym)}/{sym.name}.c"
        for cand_src in {existing, default_src} - {None}:
            _snapshot_file(snapshot, ROOT / "src" / cand_src)
            _snapshot_file(snapshot, ROOT / "src" / (cand_src[:-2] + ".s"))
            _snapshot_file(snapshot, carve.tufile.gen_path(p, cand_src))
        if sym.scope == "local":
            suffixed = f"{sym.name}_{sym.addr:08X}"
            cand_paths = {(ROOT / "src" / (u.get("tu") or u["source"])).with_suffix(".s" if u.get("asm") else ".c")
                          for u in p.load_units() if sym.module == "main" or u["module"] == sym.module}
            hdr_root = ROOT / "include" if sym.module == "main" else ROOT / "include/rel" / sym.module
            if hdr_root.exists():
                cand_paths.update(hdr_root.rglob("*.h"))
            for cpath in cand_paths:
                if cpath.exists() and suffixed in cpath.read_text(errors="ignore"):
                    _snapshot_file(snapshot, cpath)
        cr = carve.carve(p, s)
        c_src = ROOT / "src" / cr.source
        s_source = cr.source[:-2] + ".s"
        _snapshot_file(snapshot, c_src)
        _snapshot_file(snapshot, ROOT / "src" / s_source)
        # the unit keeps its .c name (the split's unit name, what uncarve knows); `asm` makes
        # configure compile src/<name>.s instead
        with oracle.build_lock("units.lock"):
            units = p.load_units()
            for u in units:
                if u["module"] == cr.module and u["source"] == cr.source:
                    u["status"] = "matching"; u["asm"] = True
                    u.pop("tu", None)
            p.save_units(units)
        if c_src.exists():
            c_src.unlink()  # the carve's stub: the unit is assembly
        made.append((s, cr.module, cr.source, s_source))
    if not made:
        out: Dict[str, object] = {"ok": True, "made": [], "note": "nothing to do"}
        if refused:
            out["refused"] = refused
        return out
    return finalize(p, made, refused, snapshot=snapshot)


def resume(p: Project) -> Dict[str, object]:
    """Finish asm units that were carved but not yet linked and recorded.

    The selector used to be `functions.status != 'asm'`, which assumed every registered asm
    unit that is not recorded as `asm` is unfinished work to redo. That is wrong twice over.

    Measured 2026-10-05: **no ledger row has status 'asm'** -- 0 of 159 -- so every registered
    asm unit looked unfinished, and this would have swept all 159, including SDK symbols such as
    GXLoadNrmMtxImm and DecrementerExceptionHandler that have nothing to do with the REL
    modules and have already been linked correctly for months.

    Unfinished means something observable, not something inferred from a status nobody writes:
    an asm unit is unfinished when its `.text` range is claimed by a split but no object was
    built for it. That is exactly the 16 credited-but-unauthored functions, which objdiff credits
    from the auto object because there is no unit of ours in the link (docs/findings/290).
    Selecting on that condition is also self-limiting: the 143 that did build are left alone.
    """
    made = []
    for u in p.load_units():
        if not u.get("asm") or not u.get("symbols"):
            continue
        sym = u["symbols"][0]
        s = p.resolve(sym)
        if s is None:
            continue
        # already linked: our object exists, so there is nothing to resume
        stem = u["source"][:-2]
        # "already linked" means the current build produces this unit, not that some object
        # file happens to be lying around. configure writes build.ninja at the repository root,
        # not under build/<version>/, so reading the version directory here finds nothing and
        # every asm unit looks unfinished. `build.ninja` is regenerated by configure, so a stale
        # .o from an abandoned carve would otherwise read as finished work forever -- measured:
        # fn_12_33664 still had both src/ and obj/ .o files from a reverted run, and an
        # existence check reported it done while no build rule mentioned it.
        build_ninja = ROOT / "build.ninja"
        if build_ninja.exists() and stem in build_ninja.read_text():
            continue
        # not carved: with no split range there is no .s for finalize to copy, so this unit was
        # never started and belongs to `carve`, not to a resume.
        if not any(sp.section == s.section and sp.start <= s.addr and s.end <= sp.end
                   for sp in p.splits(u["module"])):
            continue
        made.append((sym, u["module"], u["source"], u["source"][:-2] + ".s"))
    if not made:
        return {"ok": True, "made": [], "note": "nothing to resume"}
    return finalize(p, made)


def finalize(p: Project, made: List[tuple], refused: Optional[List[dict]] = None,
             snapshot: Optional[Dict[Path, Optional[bytes]]] = None) -> Dict[str, object]:
    """Relink, hash and record. `refused` are symbols make() declined up front; they ride along
    in every return so a caller sees the whole outcome, including the ones never attempted."""
    import time  # scoped: phase timing
    l = Ledger()
    t0 = time.time()
    def phase(msg: str) -> None:
        print(f"  asm-unit: {msg} ({time.time() - t0:.1f}s)", flush=True)

    def _rollback(split: bool = True) -> None:
        for _, _, _, s_source in made:
            (ROOT / "src" / s_source).unlink(missing_ok=True)
        if snapshot is not None:
            _restore_snapshot(p, snapshot, split=split)
        else:
            uncarve(p, [x[2] for x in made], split=split)

    missing_asm: Optional[str] = None
    try:
        with oracle.build_lock():
            phase("build lock acquired")
            cp = oracle.configure(p)
            if cp.returncode != 0:
                raise RuntimeError(cp.stderr[-1500:])
            phase("configured")
            cp = oracle.run(["ninja", p.rel(p.build_dir / "config.json")])  # the split writes the units' asm
            if cp.returncode != 0:
                raise RuntimeError((cp.stdout + cp.stderr)[-1500:])
            phase("split")
            for s, module, c_source, s_source in made:
                asm = p.module_build_dir(module) / "asm" / s_source
                if not asm.exists():
                    missing_asm = f"{s}: no split assembly at {asm}"
                    break
                dst = ROOT / "src" / s_source
                if snapshot is not None:
                    _snapshot_file(snapshot, dst)
                dst.parent.mkdir(parents=True, exist_ok=True)
                text, n = fix_branch_hints(asm.read_text())
                dst.write_text(text)
                if n:
                    phase(f"{s}: {n} backward branch hint(s) respelled for GNU as")
            if missing_asm is None:
                phase("assembly copied")
                cp = oracle.configure(p)
                if cp.returncode == 0:
                    cp = oracle.relink(p)
                linked = cp.returncode == 0
                phase("relinked" if linked else "relink FAILED")
            else:
                linked = False
    except Exception:
        _rollback(split=True)
        raise
    if missing_asm is not None:
        _rollback(split=True)
        return {"ok": False, "error": missing_asm, "made": [],
                **({"refused": refused} if refused else {})}
    if not linked:
        # outside the lock: rollback takes units.lock / build.lock (flock is not reentrant)
        tail = (cp.stdout + cp.stderr)[-3000:]
        print(tail, flush=True)
        _rollback(split=True)
        return {"ok": False, "error": "the tree no longer hashes with these units; rolled back", "made": [], "log": tail,
                **({"refused": refused} if refused else {})}
    for s, module, c_source, s_source in made:
        l.db.execute("UPDATE functions SET status='asm', claimed_by=NULL, unit=? WHERE symbol=?", (c_source, s))
    l.db.commit()
    files = [str(ROOT / "src" / x[3]) for x in made] + [str(p.units_path)]
    for module in {x[1] for x in made}:
        d = p.module_config_dir(module)
        files += [str(d / "splits.txt"), str(d / "symbols.txt")]
    subprocess.run(["git", "add", *files], cwd=ROOT, capture_output=True)
    subprocess.run(["git", "commit", "-q", "-m", f"asm units: {len(made)} assembly-only functions link from their own assembly ({', '.join(x[0] for x in made[:6])}{'...' if len(made) > 6 else ''})"], cwd=ROOT, capture_output=True)
    return {"ok": True, "made": [x[0] for x in made],
            **({"refused": refused} if refused else {})}
