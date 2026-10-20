"""The oracle: compile one unit, diff it against retail, relink everything.

check(symbol)  -> compile the unit's object, objdiff it, return per-symbol
                  percentages and a compact instruction diff for `symbol`.
relink()       -> full `ninja`; the CHECK step fails unless every target in
                  build.sha1 is byte-identical.
"""

from __future__ import annotations

import base64
import fcntl
import json
import os
import re
import shlex
import shutil
import struct
import subprocess
import sys
from contextlib import contextmanager
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, List, Optional, Tuple

from . import poolfix
from .project import ROOT, STATE_DIR, Project, Symbol

OBJDIFF = ROOT / "build" / "tools" / "objdiff-cli"


@dataclass
class CheckResult:
    ok: bool  # compiled and objdiff ran
    symbol: str
    unit: str
    percent: float = 0.0
    matched: bool = False
    symbols: Dict[str, float] = field(default_factory=dict)  # every function in the unit
    data_sections: Dict[str, float] = field(default_factory=dict)
    diff: List[str] = field(default_factory=list)
    error: str = ""
    missing_in_base: List[str] = field(default_factory=list)
    extra_in_base: List[str] = field(default_factory=list)
    # every remaining diff is a relocation to a literal-pool constant whose value we reproduce
    # privately (an int->float conversion constant, or a literal shared with a neighbour):
    # per-function linking cannot express that; the TU's whole-unit compile will
    matched_pool: bool = False
    pool: List[str] = field(default_factory=list)
    # private literal -> retail pooled symbol, applied to the object after compiling (poolfix);
    # with this the function matches outright and links from C
    pool_map: Dict[str, str] = field(default_factory=dict)
    uncarved: bool = False           # diffed against the retail auto object: this symbol only
    pool_rows: int = 0               # differing rows that are only pool relocations
    percent_adjusted: float = 0.0    # match % with the pool rows counted as matching
    mw_version: Optional[str] = None  # the compiler version this verdict came from (candidates: the best)
    extra_cflags: Optional[str] = None  # the extra flags of that build (e.g. -use_lmw_stmw on)
    instruction_rows: int = 0
    differing_rows: int = 0
    value_flow: List[dict] = field(default_factory=list)
    operand_order: List[dict] = field(default_factory=list)

    def to_json(self) -> dict:
        return {k: v for k, v in self.__dict__.items() if not k.startswith("_")}


def run(cmd: List[str], cwd: Path = ROOT, timeout: int = 600) -> subprocess.CompletedProcess:
    return subprocess.run(cmd, cwd=cwd, text=True, capture_output=True, timeout=timeout)


@contextmanager
def build_lock(name: str = "build.lock", timeout_s: float = 120.0):
    """The build lock. Never waits silently: after `timeout_s` it raises and names the lock,
    so a child of an interrupted run that still holds it is found instead of waited on."""
    import time as _time  # scoped: one polling loop
    path = STATE_DIR / name
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w") as f:
        t0 = _time.time(); warned = False
        while True:
            try:
                fcntl.flock(f, fcntl.LOCK_EX | fcntl.LOCK_NB)
                break
            except BlockingIOError:
                if _time.time() - t0 > timeout_s:
                    raise TimeoutError(f"{path.name}: held by another process for over {int(timeout_s)} s (an interrupted run's child? see `pgrep -fl 'dtk|ninja|mwld'`)")
                if not warned and _time.time() - t0 > 5:
                    print(f"  waiting for {path.name} (held by another process)...", file=sys.stderr, flush=True); warned = True
                _time.sleep(0.2)
        try:
            yield
        finally:
            fcntl.flock(f, fcntl.LOCK_UN)


def clear_stale_index_lock(min_age_s: float = 30.0) -> bool:
    """Remove .git/index.lock left by a git process that died by signal.

    Call with submit.lock held (every tooling commit takes it). The lock is stale
    only when it is old and no git process is running in this repository; one
    such leftover made every later `git add` exit 128 and held the whole fleet.
    """
    import time as _time
    lock = ROOT / ".git" / "index.lock"
    try:
        if _time.time() - lock.stat().st_mtime < min_age_s:
            return False
    except FileNotFoundError:
        return False
    for proc in Path("/proc").glob("[0-9]*"):
        try:
            if (proc / "comm").read_text().strip() == "git" and Path(os.readlink(proc / "cwd")).is_relative_to(ROOT):
                return False
        except OSError:
            continue
    lock.unlink(missing_ok=True)
    print(f"  removed stale {lock.relative_to(ROOT)} (no git process in the repository)", file=sys.stderr, flush=True)
    return True


def configure(project: Project) -> subprocess.CompletedProcess:
    return run([sys.executable, "configure.py", "--version", project.version])


def relink(project: Project, keep_going: bool = False) -> subprocess.CompletedProcess:
    """Relink every target and verify build.sha1.

    Targets `build/<VERSION>/ok` (the dtk shasum check) rather than the default
    target, so only Matching units are compiled: another agent's broken
    in-progress unit cannot fail this step. keep_going reports every failing
    unit instead of stopping at the first.
    """
    jobs = os.environ.get('FZGX_BUILD_JOBS')
    if jobs is not None and int(jobs) < 1:
        raise ValueError('FZGX_BUILD_JOBS must be positive')
    cmd = ["ninja"] + (["-j", str(int(jobs))] if jobs is not None else []) + (["-k", "0"] if keep_going else []) + [project.rel(project.build_dir / "ok")]
    return run(cmd, timeout=1800)


def _has_primer(obj: Path) -> bool:
    """True when `obj` carries a non-empty `.fzgxpool` layout-primer section."""
    if not obj.exists():
        return False
    try:
        sec = poolfix.Elf(obj.read_bytes()).section('.fzgxpool')
    except (ValueError, IndexError, struct.error):
        return False
    return sec is not None and sec['size'] > 0


def _base_object(project: Project, unit: str) -> Path:
    units = project.objdiff_units()
    if unit in units and "base_path" in units[unit]:
        return ROOT / units[unit]["base_path"]
    module, rest = unit.split("/", 1)
    return project.build_dir / "src" / f"{rest}.o"


def _render_diff(left_rows: List[dict], right_rows: List[dict], max_lines: int,
                 pool_rows: Optional[set] = None, addresses: bool = False) -> List[str]:
    """Side-by-side rendering: `target | ours`, with a marker on differing rows
    (`p` = literal-pool relocation the tooling retargets; not yours to fix)."""
    if max_lines <= 0:
        return []
    out: List[str] = []
    n = max(len(left_rows), len(right_rows))
    for i in range(n):
        l = left_rows[i] if i < len(left_rows) else {}
        r = right_rows[i] if i < len(right_rows) else {}
        kind = l.get("diff_kind") or r.get("diff_kind") or "DIFF_NONE"
        lf = l.get("instruction", {}).get("formatted", "")
        rf = r.get("instruction", {}).get("formatted", "")
        mark = " " if kind == "DIFF_NONE" else {"DIFF_REPLACE": "~", "DIFF_DELETE": "<", "DIFF_INSERT": ">",
                                                "DIFF_OP_MISMATCH": "!", "DIFF_ARG_MISMATCH": "?"}.get(kind, "*")
        if pool_rows and i in pool_rows:
            mark = "p"
        if kind != "DIFF_NONE" or len(out) < 4:
            where = f'{i * 4:04X}'
            if addresses:
                def addr(row):
                    value = row.get('instruction', {}).get('address')
                    return f'{int(value):08X}' if value is not None else '--------'
                where += f' T:{addr(l)} C:{addr(r)}'
            out.append(f"{mark} {where}  {lf:<34} | {rf}")
    if len(out) > max_lines:
        head = out[: max_lines - 1]
        head.append(f"... {len(out) - (max_lines - 1)} more differing rows")
        out = head
    return out


def check(project: Project, symbol: str, max_diff_lines: int = 80, source: Optional[Path] = None,
          mw_version: Optional[str] = None, extra_cflags: Optional[str] = None) -> CheckResult:
    """Compile the unit (or `source`, an agent's work copy) into the unit's object and diff it.
    For an uncarved function, `mw_version`/`extra_cflags` are the unit options being proposed.
    For a carved work copy, None inherits unit flags; '' or [] clears the unit override
    while retaining the module's base flags."""
    # Unit manifests store argv lists; saved-body callers can carry that form.
    # Normalize once so result metadata and later submission also receive strings.
    if isinstance(extra_cflags, list):
        extra_cflags = shlex.join(extra_cflags)
    sym = project.resolve(symbol)
    if sym is None:
        return CheckResult(False, symbol, "", error="unknown or ambiguous symbol (use module:name)")
    symbol = sym.name  # objdiff symbol name is the bare C name
    unit_src = project.unit_of(sym)
    if not unit_src:
        # not carved: nothing in the link yet. Diff the work copy against the retail auto
        # object that already contains the function (two-object mode, this symbol only).
        if source is None:
            return CheckResult(False, symbol, "", error="not matched yet and no work copy to check")
        target = project.target_object_for(sym)
        if target is None or not target.exists():
            return CheckResult(False, symbol, "", error="no retail object defines this function (run ninja)")
        base_obj = STATE_DIR / "work" / (project.key(sym).replace(":", "__") + ".o")
        chosen: Tuple[Optional[str], Optional[str]] = (mw_version, extra_cflags)
        cands = [(mw_version, extra_cflags)] if (mw_version or extra_cflags) else version_candidates(project, sym.module)
        if len(cands) > 1:
            # one compile per candidate build, the best by masked words is the one diffed
            tw = words(target, symbol)
            best = None
            for ver, ex in cands:
                o = base_obj.with_name(base_obj.stem + "." + ver.replace("/", "_") + ("_stmw" if ex else "") + ".o")
                cp = compile_source(project, sym.module, source, o, ver, ex)
                if cp.returncode != 0 or not o.exists():
                    continue
                ow = words(o, symbol)
                pct = word_score(tw, ow)[0] if tw and ow else -1.0
                if best is None or pct > best[0]:
                    best = (pct, (ver, ex), o, cp)
            if best is None:
                cp = compile_source(project, sym.module, source, base_obj, cands[0][0], cands[0][1])
            else:
                chosen = best[1]
                shutil.copy(best[2], base_obj); cp = best[3]
        else:
            cp = compile_source(project, sym.module, source, base_obj, cands[0][0], cands[0][1])
        if cp.returncode != 0 or not base_obj.exists():
            err = "\n".join(l for l in (cp.stdout + cp.stderr).splitlines() if "Usage Warning" not in l)
            return CheckResult(False, symbol, "", error=err.strip()[-4000:])
        res = _diff(project, sym.module, symbol, "", max_diff_lines, target=target, base=base_obj)
        res.mw_version, res.extra_cflags = chosen
        if res.ok and res.matched_pool:
            mapping = {private: pooled for private, pooled, _ in res._pool_pairs}
            r = poolfix.apply(base_obj, mapping)
            if not r["skipped"] and r["rodata_emptied"]:
                res2 = _diff(project, sym.module, symbol, "", max_diff_lines, target=target, base=base_obj)
                if res2.ok and res2.matched:
                    res2.pool_map, res2.pool = mapping, res.pool
                    res2.mw_version, res2.extra_cflags = chosen; res2.uncarved = True
                    return res2
        elif res.ok and res.matched and base_obj.exists() and _has_primer(base_obj):
            # A primer-only object needs no literal retargeting, so `apply()` never runs on
            # it and its `.fzgxpool` section survives into the module link, where mwld
            # reports the primer's private BSS copies as multiply-defined. Drop the section
            # here, where the match was just proven; it is a separate section holding primer
            # code, so the matched text is unaffected. Restore it if the re-diff disagrees,
            # so a failed experiment never leaves a mutilated object behind. See
            # docs/findings/279.
            backup = base_obj.read_bytes()
            if poolfix.drop_primer(base_obj):
                res2 = _diff(project, sym.module, symbol, "", max_diff_lines, target=target, base=base_obj)
                if res2.ok and res2.matched:
                    res2.mw_version, res2.extra_cflags = chosen; res2.uncarved = True
                    return res2
                base_obj.write_bytes(backup)
        res.uncarved = True
        if res.ok and res.matched_pool:
            # the pool retarget path returns res2 above; here keep the version on the plain result
            pass
        return res
    unit = project.objdiff_unit_name(sym.module, unit_src)
    base_obj = _base_object(project, unit)

    if source is not None:
        # a body that is not the unit's own text (a candidate, an agent's work copy) never goes
        # into the link's object: ninja would keep the foreign object as up to date and the REL
        # would stop hashing. Scratch object, two-object diff against the retail unit object.
        target = project.target_object_for(sym)
        if target is not None and target.exists():
            scratch_obj = STATE_DIR / "work" / (project.key(sym).replace(":", "__") + ".o")
            scratch_obj.parent.mkdir(parents=True, exist_ok=True)
            ucfg = project.unit_record(unit_src) or {}
            chosen = (mw_version or ucfg.get("mw_version"),
                      extra_cflags if extra_cflags is not None else
                      (" ".join(ucfg.get("extra_cflags") or []) or None))
            cp = compile_source(project, sym.module, source, scratch_obj, *chosen)
            if cp.returncode != 0 or not scratch_obj.exists():
                err = "\n".join(l for l in (cp.stdout + cp.stderr).splitlines() if "Usage Warning" not in l)
                return CheckResult(False, symbol, unit, error=err.strip()[-4000:])
            res = _diff(project, sym.module, symbol, unit, max_diff_lines, target=target, base=scratch_obj)
            res.mw_version, res.extra_cflags = chosen
            if res.ok and res.matched_pool:
                mapping = {private: pooled for private, pooled, _ in res._pool_pairs}
                r = poolfix.apply(scratch_obj, mapping)
                if not r["skipped"] and r["rodata_emptied"]:
                    res2 = _diff(project, sym.module, symbol, unit, max_diff_lines, target=target, base=scratch_obj)
                    if res2.ok and res2.matched:
                        res2.pool_map, res2.pool = mapping, res.pool
                        res2.mw_version, res2.extra_cflags = chosen
                        return res2
            elif res.ok and res.matched and _has_primer(scratch_obj):
                # primer-only object: no literals to retarget, so drop the section here
                # rather than at submit (docs/findings/279)
                backup = scratch_obj.read_bytes()
                if poolfix.drop_primer(scratch_obj):
                    res2 = _diff(project, sym.module, symbol, unit, max_diff_lines, target=target, base=scratch_obj)
                    if res2.ok and res2.matched:
                        res2.mw_version, res2.extra_cflags = chosen
                        return res2
                    scratch_obj.write_bytes(backup)
            return res

    # the unit's own text: direct mwcc compile into this unit's own object, no ninja, no build lock
    cp = compile_unit(project, unit, unit_src, None)
    if cp.returncode != 0 or not base_obj.exists():
        err = "\n".join(l for l in (cp.stdout + cp.stderr).splitlines() if "Usage Warning" not in l)
        return CheckResult(False, symbol, unit, error=err.strip()[-4000:])

    res = _diff(project, sym.module, symbol, unit, max_diff_lines)
    if res.ok and res.matched_pool:
        # retarget the private literals to the pooled symbols and diff again
        mapping = {private: pooled for private, pooled, _ in res._pool_pairs}
        r = poolfix.apply(base_obj, mapping)
        if not r["skipped"] and r["rodata_emptied"]:
            res2 = _diff(project, sym.module, symbol, unit, max_diff_lines)
            if res2.ok and res2.matched:
                res2.pool_map = mapping
                res2.pool = res.pool
                return res2
    elif res.ok and res.matched and _has_primer(base_obj):
        # This is the object that actually enters the module link, so the primer must go
        # now: with no private literals to retarget, `apply()` never runs and mwld would
        # reject the primer's private BSS copies as multiply-defined. See
        # docs/findings/279.
        backup = base_obj.read_bytes()
        if poolfix.drop_primer(base_obj):
            res2 = _diff(project, sym.module, symbol, unit, max_diff_lines)
            if res2.ok and res2.matched:
                return res2
            base_obj.write_bytes(backup)
    return res


def _diff(project: Project, module: str, symbol: str, unit: str, max_diff_lines: int,
          target: Optional[Path] = None, base: Optional[Path] = None) -> CheckResult:
    candidate = base if base is not None else _base_object(project, unit)
    if candidate is not None and candidate.exists():
        try:
            elf = poolfix.Elf(candidate.read_bytes())
            own = next((s for s in elf.symbols() if s['name'] == symbol), None)
            if (own and 0 < own['shndx'] < len(elf.sections) and
                    elf.sections[own['shndx']]['name'] == '.fzgxpool'):
                # Primer filtering must never hide the function being matched.
                return CheckResult(False, symbol, unit, error=(
                    f"target function {module}:{symbol} is in the .fzgxpool primer section; "
                    "restore its code section before checking"))
        except (OSError, ValueError) as exc:
            return CheckResult(False, symbol, unit, error=f"cannot inspect candidate object: {exc}")
    if target is not None:
        expected = project.find_symbol(symbol, module)
        target_words = words(target, symbol)
        if expected and (target_words is None or len(target_words) * 4 != expected.size):
            actual_size = len(target_words) * 4 if target_words is not None else None
            return CheckResult(False, symbol, unit, error=(
                f"retail target identity mismatch for {module}:{symbol}: expected {expected.size} bytes, "
                f"found {actual_size}; regenerate stale target objects"))
        if expected and symbol in project.ambiguous_names():
            canonical = project.target_object_for(expected)
            if canonical is None or (target.resolve() != canonical.resolve() and
                    not function_score(project, symbol, canonical, target)[0]):
                return CheckResult(False, symbol, unit, error=(
                    f"retail target does not match its module binding: {module}:{symbol}"))
        cp = run([str(OBJDIFF), "diff", "-1", str(target), "-2", str(base), "-o", "-", "--format", "json", symbol])
    else:
        base = _base_object(project, unit)
        cp = run([str(OBJDIFF), "diff", "-p", str(ROOT), "-u", unit, "-o", "-", "--format", "json"])
    if cp.returncode != 0:
        return CheckResult(False, symbol, unit, error=(cp.stderr or cp.stdout).strip()[-4000:])
    data = json.loads(cp.stdout)
    left, right = data.get("left", {}), data.get("right", {})
    res = CheckResult(True, symbol, unit)
    res._pool_pairs = []
    res._rows = ([], [])  # objdiff's instruction rows (target, ours) for classifiers
    left_syms = {s["name"]: s for s in left.get("symbols", []) if s.get("kind") == "SYMBOL_FUNCTION"}
    right_syms = {s["name"]: s for s in right.get("symbols", []) if s.get("kind") == "SYMBOL_FUNCTION"}
    if target is not None:  # the retail auto object holds many functions; only ours is in question
        left_syms = {k: v for k, v in left_syms.items() if k == symbol}
        right_syms = {k: v for k, v in right_syms.items() if k == symbol}
    for name, s in left_syms.items():
        res.symbols[name] = float(s.get("match_percent", 0.0))
    res.missing_in_base = sorted(set(left_syms) - set(right_syms))
    res.extra_in_base = sorted(set(right_syms) - set(left_syms))
    for sec in left.get("sections", []):
        if sec.get("kind") in ("SECTION_DATA", "SECTION_BSS") and "match_percent" in sec:
            res.data_sections[sec["name"]] = float(sec["match_percent"])
    res._object = base
    res.percent = res.symbols.get(symbol, 0.0)
    res.percent_adjusted = res.percent
    res.matched = res.percent >= 100.0
    if not res.matched:
        lrows = left_syms.get(symbol, {}).get("instructions", [])
        rrows = right_syms.get(symbol, {}).get("instructions", [])
        res._rows = (lrows, rrows)
        # The flow walker invalidates unsupported regions itself. A different
        # opcode elsewhere must not hide a known wrong store in a supported one.
        from . import regflow
        from .evidence import object_jump_tables
        symbol_info=project.find_symbol(symbol,module)
        retail_object=target or (project.target_object_for(symbol_info) if symbol_info else None)
        tables=(object_jump_tables(retail_object,symbol,project,module),object_jump_tables(base,symbol)) if retail_object and base else None
        flow = regflow.analyse_rows(lrows, rrows, tables)
        res._flow=flow
        res.value_flow = flow['value_flow']
        res.operand_order = flow['operand_order']
        if symbol not in right_syms:
            res.diff = [f"(symbol {symbol} not present in our object: define it, check the name)"]
        else:
            pool_rows, res._pool_pairs = _pool_rows(project, module, left, right, lrows, rrows, base, symbol)
            interior_rows, interior_pairs = _interior_binding_rows(project, module, base, left, right, lrows, rrows)
            pool_rows |= interior_rows
            res._pool_pairs += interior_pairs
            if base is not None:
                data_rows, data_pairs = _data_pool_rows(project, module, base, left, right, lrows, rrows,
                                                       verified_pairs=res._pool_pairs)
                pool_rows |= data_rows
                res._pool_pairs += data_pairs
                ro_rows, ro_pairs = _data_pool_rows(project, module, base, left, right, lrows, rrows, ".rodata")
                pool_rows |= ro_rows
                res._pool_pairs += ro_pairs
                bss_rows, bss_pairs = _bss_base_rows(project, module, base, left, right, lrows, rrows, symbol)
                pool_rows |= bss_rows
                res._pool_pairs += bss_pairs
            res.pool = [d for _, _, d in res._pool_pairs]
            abs_rows = _abs_rows(right, lrows, rrows)
            abs_rows |= _equivalent_reloc_rows(project, module, base, left, right, lrows, rrows)
            res.diff = _render_diff(lrows, rrows, max_diff_lines, pool_rows | abs_rows)
            res._accepted_rows = pool_rows | abs_rows
            # what is left once the pool rows are taken out: what the agent can still act on
            real = sum(1 for i, (l, r) in enumerate(zip(lrows, rrows))
                       if (l.get("diff_kind") or "DIFF_NONE") != "DIFF_NONE" and i not in pool_rows and i not in abs_rows)
            n = max(len(lrows), len(rrows), 1)
            res.instruction_rows = n
            res.differing_rows = sum(
                i not in pool_rows and i not in abs_rows and
                ((l.get('diff_kind') or 'DIFF_NONE') != 'DIFF_NONE' or
                 (r.get('diff_kind') or 'DIFF_NONE') != 'DIFF_NONE')
                for i, (l, r) in enumerate(zip(lrows, rrows))) + abs(len(lrows) - len(rrows))
            res.pool_rows = len(pool_rows)
            res.percent_adjusted = round(100.0 * (n - real - abs(len(lrows) - len(rrows))) / n, 2) if (pool_rows or abs_rows) else res.percent
            res.matched_pool = bool(pool_rows) and real == 0 and len(lrows) == len(rrows)
            if abs_rows and not pool_rows and real == 0 and len(lrows) == len(rrows):
                # only linker-defined absolute symbols differ (ours a relocation, retail the
                # resolved literal): the link produces retail's bytes; verify's hash is the guard
                res.matched = True
    return res


def _interior_binding_rows(project, module, obj, left, right, lrows, rrows):
    """Prove an explicit generated subobject/entry alias against retail relocs."""
    if obj is None:
        return set(), []
    undefined = {s['name'] for s in poolfix.Elf(obj.read_bytes()).symbols() if s['shndx'] == 0}
    rows, pairs = set(), set()
    for i,(l,r) in enumerate(zip(lrows,rrows)):
        li,ri=l.get('instruction',{}),r.get('instruction',{})
        lr,rr=li.get('relocation'),ri.get('relocation')
        if not lr or not rr or lr.get('type_name') != rr.get('type_name'):
            continue
        name=right['symbols'][rr['target_symbol']]['name']
        match=re.fullmatch(r'(.+)__fzgx_offset_([0-9A-F]+)',name)
        if not match or name not in undefined:
            continue
        owner=project.find_symbol(match[1],module) or project.resolve(match[1])
        if owner is None:
            # Promotion preserves the private C identifier but updates its
            # committed relocation binding to the new owning symbol.
            bindings={u['pool'][name] for u in project.load_units()
                      if u.get('module')==module and isinstance(u.get('pool'),dict) and name in u['pool']}
            if len(bindings)==1:
                base,offset=poolfix.binding_target(next(iter(bindings)))
                if offset==int(match[2],16):
                    owner=project.find_symbol(base,module) or project.resolve(base)
        retail=left['symbols'][lr['target_symbol']]['name']
        target=project.find_symbol(retail,module) or project.resolve(retail)
        delta=int(match[2],16)
        if (not owner or not target or owner.module != target.module or owner.section != target.section
                or not 0 < delta < owner.size
                or owner.addr + delta + int(rr.get('addend') or 0) != target.addr + int(lr.get('addend') or 0)):
            continue
        if owner.section == '.text' and delta % 4:
            continue
        if [x for x in li.get('parts',[]) if 'reloc' not in json.dumps(x)] != [x for x in ri.get('parts',[]) if 'reloc' not in json.dumps(x)]:
            continue
        rows.add(i)
        binding=f'{owner.name}+0x{delta:X}'
        pairs.add((name,binding,f'interior symbol {binding}'))
    return rows, sorted(pairs)


def _equivalent_reloc_rows(project, module, obj, left, right, lrows, rrows):
    """A split data label and an external base plus addend resolve to the same address."""
    undefined = {s['name'] for s in poolfix.Elf(obj.read_bytes()).symbols() if s['shndx'] == 0}
    addresses = {s.name: s for s in project.symbols(module).values()}
    addresses.update({f'{s.name}_{s.addr:08X}': s for s in project.symbols(module).values()})
    rows = set()
    for i, (l, r) in enumerate(zip(lrows, rrows)):
        li, ri = l.get('instruction', {}), r.get('instruction', {})
        lr, rr = li.get('relocation'), ri.get('relocation')
        # DTK emits R_PPC_NONE references on some structure displacements.
        # They perform no relocation; retain every decoded instruction operand.
        if (any(rel and rel.get('type_name') == 'R_PPC_NONE' for rel in (lr,rr))
                and all(not rel or rel.get('type_name') == 'R_PPC_NONE' for rel in (lr,rr))
                and li.get('parts') and li.get('parts') == ri.get('parts')
                and li.get('formatted') == ri.get('formatted')):
            rows.add(i)
            continue
        if not lr or not rr or lr.get('type_name') != rr.get('type_name'):
            continue
        if [x for x in li.get('parts', []) if 'reloc' not in json.dumps(x)] != [x for x in ri.get('parts', []) if 'reloc' not in json.dumps(x)]:
            continue
        lname = left['symbols'][lr['target_symbol']]['name']
        rname = right['symbols'][rr['target_symbol']]['name']
        if rname not in undefined or lname not in addresses or rname not in addresses:
            continue
        lsym, rsym = addresses[lname], addresses[rname]
        if (lsym.section == rsym.section and
                lsym.addr + int(lr.get('addend') or 0) == rsym.addr + int(rr.get('addend') or 0)):
            rows.add(i)
    return rows


def _bss_base_rows(project, module, obj, left, right, lrows, rrows, function_name=None):
    """A compiler section base and its named BSS object denote the same storage."""
    elf = poolfix.Elf(obj.read_bytes())
    symbols = {s['name']: s for s in elf.symbols()}
    fn = project.symbols(module).get(function_name)
    unit = project.unit_of(fn) if fn else None
    rows, pairs = set(), []
    def bind_members(section, anchor, retail):
        # Section-relative accesses need no relocation against each member.
        # Still prove every named shared definition before externalizing it.
        origin = retail.addr - anchor['value']
        for own in symbols.values():
            if own['shndx'] != section['index'] or not own['size'] or own['info'] & 15 != 1:
                continue
            name = own['name'].removeprefix('fzgx_obj_')
            known = project.symbols(module).get(name)
            delta = 0
            alias = re.fullmatch(r'(.+)__fzgx_offset_([0-9A-F]+)', name)
            if known is None and alias:
                known = project.symbols(module).get(alias[1]); delta = int(alias[2], 16)
            if (not known or known.kind != 'object' or known.section != retail.section
                    or origin + own['value'] != known.addr + delta
                    or delta + own['size'] > known.size
                    or (unit is not None and project.unit_of(known) == unit)):
                continue
            binding = known.name + (f'+0x{delta:X}' if delta else '')
            pair = (own['name'], binding, f'{binding}=verified BSS object[{own["size"]}]')
            if pair not in pairs:
                pairs.append(pair)
    for i, (l, r) in enumerate(zip(lrows, rrows)):
        li, ri = l.get('instruction', {}), r.get('instruction', {})
        lr, rr = li.get('relocation'), ri.get('relocation')
        if not lr or not rr or lr.get('type_name') != rr.get('type_name') or int(lr.get('addend') or 0) != int(rr.get('addend') or 0):
            continue
        if [x for x in li.get('parts', []) if 'reloc' not in json.dumps(x)] != [x for x in ri.get('parts', []) if 'reloc' not in json.dumps(x)]:
            continue
        lname = left['symbols'][lr['target_symbol']]['name']
        rname = right['symbols'][rr['target_symbol']]['name']
        # a unit may define the retail TU's objects under an alias when the module header
        # already declares the retail name with another layout
        anchor = symbols.get(rname)
        if not anchor or not 0 < anchor['shndx'] < len(elf.sections):
            continue
        section = elf.sections[anchor['shndx']]
        # .data bases bind the same way: the unit's copy is dropped at integration and
        # every displacement off the base is still compared as code.
        if not ((section['name'] in ('.bss', '.sbss') and section['type'] == 8) or
                (section['name'] == '.data' and section['type'] == 1)):
            continue
        retail = project.symbols(module).get(lname)
        if retail is None:
            retail = next((s for s in project.symbols(module).values() if lname == f'{s.name}_{s.addr:08X}'), None)
        if not retail or retail.section not in ('.bss', '.sbss', '.data'):
            continue
        # A split object may retain the local spelling after its symbol is
        # promoted. Resolve both spellings to the same measured BSS object.
        owned = next((symbols[name] for name in
                      (lname, retail.name, f'{retail.name}_{retail.addr:08X}',
                       'fzgx_obj_' + lname, 'fzgx_obj_' + retail.name)
                      if name in symbols), None)
        owned_here = unit is not None and project.unit_of(retail) == unit
        if (anchor['size'] <= retail.size and retail.size > 0
                and (rname in (lname, retail.name, f'{retail.name}_{retail.addr:08X}', 'fzgx_obj_' + retail.name) or
                     ('$' in rname and '$' in retail.name and rname.split('$')[0] == retail.name.split('$')[0]))):
            if owned_here:
                continue
            rows.add(i)
            pair = (rname, retail.name, f'{retail.name}=BSS object[{retail.size}]')
            if pair not in pairs:
                pairs.append(pair)
            bind_members(section, anchor, retail)
            continue
        # The unit's copy is dropped at integration and every displacement off the base is
        # compared as code, so a section base only needs its retail symbol at the same start;
        # dtk's symbol size is a heuristic (a retail TU's first object is often smaller).
        if not rname.startswith(('...bss', '...data')) or not owned or owned['size'] > retail.size:
            continue
        if anchor['shndx'] != section['index'] or owned['shndx'] != section['index'] or anchor['value'] != owned['value']:
            continue
        rows.add(i)
        for private in ((rname,) if owned_here else (rname, owned['name'])):
            pair = (private, retail.name, f'{retail.name}=owned BSS base')
            if pair not in pairs:
                pairs.append(pair)
        bind_members(section, anchor, retail)
    return rows, pairs


def _relocated_pool_matches(project, module, elf, section, address, extent):
    """Compare initialized bytes and symbolic pointer bindings across a shared pool."""
    from .dataimport import payload, pool_objects, resolve_target

    actual = bytearray(elf.data[section['offset']:section['offset'] + extent])
    expected = bytearray(extent)
    covered = bytearray(extent)
    bindings = []
    try:
        for sym in pool_objects(project, module, section['name'], address, extent):
            raw, relocs = payload(project, sym)
            lo, hi = max(address, sym.addr), min(address + extent, sym.end)
            expected[lo - address:hi - address] = raw[lo - sym.addr:hi - sym.addr]
            covered[lo - address:hi - address] = b'\1' * (hi - lo)
            for rel in relocs:
                offset = sym.addr + rel['offset'] - address
                if offset + 4 <= 0 or offset >= extent:
                    continue
                # Pool pointers are full words. Partial pointers and other
                # relocation encodings need their own proof, not byte masking.
                if rel['kind'] != 1 or offset < 0 or offset + 4 > extent:
                    return False
                target = project.find_symbol(rel['symbol'], rel['module'])
                bindings.append((offset, rel['kind'], target.module, target.section, target.addr + rel['addend']))
    except (ValueError, KeyError):
        return False
    if not all(covered):
        return False
    found = []
    symbols = elf.symbols()
    for rsec in elf.sections:
        if rsec['type'] != 4 or rsec['info'] != section['index']:
            continue
        for pos in range(rsec['offset'], rsec['offset'] + rsec['size'], 12):
            offset, info, addend = struct.unpack_from('>IIi', elf.data, pos)
            if offset >= extent:
                continue
            if info & 255 != 1 or offset + 4 > extent:
                return False
            own = symbols[info >> 8]
            target = resolve_target(project, module, own['name'])
            alias = re.fullmatch(r'(.+)__fzgx_offset_([0-9A-F]+)', own['name'])
            if target is None and alias and own['shndx'] == 0:
                target = resolve_target(project, module, alias[1])
                addend += int(alias[2], 16)
            if own['shndx'] == section['index']:
                binding = (module, section['name'], address + own['value'] + addend)
            elif own['shndx'] == 0 and target:
                binding = (target.module, target.section, target.addr + addend)
            else:
                return False
            found.append((offset, info & 255, *binding))
    if sorted(found) != sorted(bindings):
        return False
    for offset, *_ in bindings:
        actual[offset:offset + 4] = expected[offset:offset + 4] = bytes(4)
    return actual == expected


def _data_pool_rows(project, module, obj, left, right, lrows, rrows, section_name=".data",
                    verified_pairs=()):
    """Retarget a private literal pool only when its entire byte range agrees."""
    elf = poolfix.Elf(obj.read_bytes())
    section = elf.section(section_name)
    if not section or not section['size']:
        return set(), []
    symbols = elf.symbols()
    defined = [s for s in symbols if s['shndx'] == section['index'] and s['size']]
    if not defined:
        return set(), []
    extent = section['size']
    relocs = [struct.unpack_from('>IIi', elf.data, pos)
              for rs in elf.sections if rs['type'] == 4 and rs['info'] == section['index']
              for pos in range(rs['offset'], rs['offset'] + rs['size'], 12)]
    if relocs:
        # MWCC appends switch tables to ordinary TU data. Their destinations
        # have already been checked against retail; compare the preceding
        # initialized objects independently instead of rejecting the whole pool.
        table_names = {private for private, retail, _ in verified_pairs
                       if retail.startswith('jumptable_')}
        tables = [s for s in defined if s['name'] in table_names]
        if tables:
            extent = min(t['value'] for t in tables)
            if any(s['value'] + s['size'] > extent and s not in tables for s in defined):
                return set(), []
            covered = bytearray(section['size'] - extent)
            for table in tables:
                covered[table['value'] - extent:table['value'] + table['size'] - extent] = b'\1' * table['size']
            suffix = elf.data[section['offset'] + extent:section['offset'] + section['size']]
            if any(value and not covered[i] for i, value in enumerate(suffix)):
                return set(), []
            if any(offset >= extent and not any(t['value'] <= offset and offset + 4 <= t['value'] + t['size']
                                               for t in tables) for offset, _, _ in relocs):
                return set(), []
            defined = [s for s in defined if s['value'] + s['size'] <= extent]
    if not extent:
        return set(), []
    payload = bytes(elf.data[section['offset']:section['offset'] + extent])
    rows, pairs = set(), []
    for i, (l, r) in enumerate(zip(lrows, rrows)):
        li, ri = l.get('instruction', {}), r.get('instruction', {})
        lr, rr = li.get('relocation'), ri.get('relocation')
        if not lr or not rr or lr.get('type_name') != rr.get('type_name'):
            continue
        if [x for x in li.get('parts', []) if 'reloc' not in json.dumps(x)] != [x for x in ri.get('parts', []) if 'reloc' not in json.dumps(x)]:
            continue
        lname = left['symbols'][lr['target_symbol']]['name']
        rname = right['symbols'][rr['target_symbol']]['name']
        ours = next((s for s in symbols if s['name'] == rname), None)
        target = project.symbols(module).get(lname)
        if target is None:
            suffix = re.fullmatch(r'(.+)_([0-9A-Fa-f]{8})', lname)
            target = project.symbols(module).get(suffix[1]) if suffix else None
            if target and target.addr != int(suffix[2], 16):
                target = None
        if not ours or ours['shndx'] != section['index'] or not target:
            continue
        address = target.addr + int(lr.get('addend') or 0) - ours['value'] - int(rr.get('addend') or 0)
        layout = project._rel_layout(module)
        regions = layout.values() if module == 'main' else [layout.get(target.section, (0, b''))]
        actual = next((raw[address - base:address - base + len(payload)]
                       for base, raw in regions
                       if base <= address and address + len(payload) <= base + len(raw)), None)
        if (target.section in ('.bss','.sbss') and not any(payload)
                and address >= min(s.addr for s in project.symbols(module).values() if s.section==target.section)
                and address+len(payload) <= max(s.end for s in project.symbols(module).values() if s.section==target.section)):
            # Explicit zero initializers preserve MWCC declaration order. Their
            # private copies can bind BSS only after every named object below
            # proves the same module, offset and bounds; no memory is moved.
            actual = bytes(len(payload))
        has_pointers = any(offset < extent for offset, _, _ in relocs)
        if (not _relocated_pool_matches(project, module, elf, section, address, extent)
                if has_pointers else payload != actual):
            continue
        named = []
        for own in defined:
            if own['name'].startswith(('@', 'fzgx_pool_')):
                continue
            known = project.symbols(module).get(own['name'])
            delta = 0
            alias = re.fullmatch(r'(.+)__fzgx_offset_([0-9A-F]+)', own['name'])
            if not known and alias:
                known = project.symbols(module).get(alias[1])
                delta = int(alias[2], 16)
            if (not known or known.kind != 'object' or known.section != target.section
                    or address + own['value'] != known.addr + delta
                    or delta + own['size'] > known.size):
                break
            binding = f'{known.name}+0x{delta:X}' if delta else known.name
            named.append((own['name'], binding, f'{binding}=verified pool object[{own["size"]}]'))
        else:
            rows.add(i)
            if ours['value'] == 0 and (lr.get('addend') or 0) == (rr.get('addend') or 0):
                pair = (rname, lname, f'{lname}=literal pool[{len(payload)}]')
                for item in [pair, *named]:
                    if item not in pairs:
                        pairs.append(item)
    return rows, pairs


_ABS_SYMS: Optional[Dict[str, int]] = None


def abs_symbols() -> Dict[str, int]:
    """Absolute symbols the link script defines (`NAME = 0xADDR;` in config/<v>/ldscript.tpl):
    hardware register blocks retail addressed through the linker."""
    global _ABS_SYMS
    if _ABS_SYMS is None:
        out: Dict[str, int] = {}
        for tpl in (ROOT / "config").glob("*/ldscript.tpl"):
            for m in re.finditer(r"^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", tpl.read_text(), re.M):
                out[m.group(1)] = int(m.group(2), 16)
        _ABS_SYMS = out
    return _ABS_SYMS


def _abs_rows(right: dict, lrows: List[dict], rrows: List[dict]) -> set:
    """Rows where ours relocates against a link-script absolute symbol and retail carries the
    resolved literal: `lis r3, __DIRegs@ha` / `addi r3, r3, __DIRegs@l` vs `lis r3, 0xcc00` /
    `addi r3, r3, 0x6000`. The instruction text must be identical once the symbol is resolved."""
    table = abs_symbols()
    if not table:
        return set()
    rsyms = right.get("symbols", [])
    rows: set = set()
    for i, (l, r) in enumerate(zip(lrows, rrows)):
        if (l.get("diff_kind") or "DIFF_NONE") == "DIFF_NONE":
            continue
        li, ri = l.get("instruction", {}), r.get("instruction", {})
        rrel = ri.get("relocation")
        if not rrel or li.get("relocation"):
            continue
        try:
            name = rsyms[rrel["target_symbol"]]["name"]
        except (IndexError, KeyError, TypeError):
            continue
        if name not in table:
            continue
        addr = table[name] + int(rrel.get("addend") or 0)
        ha = ((addr + 0x8000) >> 16) & 0xFFFF
        lo = addr & 0xFFFF
        lo_s = lo - 0x10000 if lo >= 0x8000 else lo
        ours = ri.get("formatted", "")
        forms = set()
        for hi_txt in (f"0x{ha:x}", f"-0x{(0x10000 - ha) & 0xFFFF:x}" if ha >= 0x8000 else f"0x{ha:x}"):
            for lo_txt in (f"0x{lo:x}", f"-0x{-lo_s:x}" if lo_s < 0 else f"0x{lo_s:x}"):
                ref = re.escape(name) + r"(?:[+-]0x[0-9a-fA-F]+)?"
                rendered = re.sub(ref + r"@(?:ha|h)\b", hi_txt, ours)
                forms.add(re.sub(ref + r"@l\b", lo_txt, rendered))
        if li.get("formatted", "") in forms:
            rows.add(i)
    return rows


def _local_table_matches(project, module, elf, private, retail, function_name):
    """Prove every switch entry against its containing function's code offset."""
    if not elf or not private or not function_name or module != 'main':
        return False
    symbols = elf.symbols()
    fn = next((s for s in symbols if s['name'] == function_name and s['info'] & 15 == 2), None)
    target = project.symbols(module).get(function_name)
    if not fn or not target or private['size'] != retail.size or not retail.size or retail.size % 4:
        return False
    from .evidence import retail_bytes
    data = retail_bytes(project, module, retail.name, 0, retail.size)
    if data is None:
        return False
    entries = {}
    for section in elf.sections:
        if section['type'] != 4 or section['info'] != private['shndx']:
            continue
        for pos in range(section['offset'], section['offset'] + section['size'], 12):
            offset, info, addend = struct.unpack_from('>IIi', elf.data, pos)
            offset -= private['value']
            if not 0 <= offset < private['size']:
                continue
            if info & 255 != 1 or offset % 4 or offset in entries:
                return False
            dest = symbols[info >> 8]
            relative = dest['value'] + addend - fn['value']
            if dest['shndx'] != fn['shndx'] or not 0 <= relative < target.size or relative % 4:
                return False
            entries[offset] = target.addr + relative
    return len(entries) * 4 == retail.size and all(struct.unpack_from('>I', data, off)[0] == value for off, value in entries.items())


def _pool_rows(project: Project, module: str, left: dict, right: dict,
               lrows: List[dict], rrows: List[dict], obj: Optional[Path] = None, function_name=None):
    """Rows that differ only by `relocation to a pooled constant (retail)` vs `relocation to
    our private literal with the same bytes`. Returns (row indices, [(private, pooled, desc)])."""
    lsyms, rsyms = left.get("symbols", []), right.get("symbols", [])
    syms = project.symbols(module)
    rows: set = set()
    pairs: List[tuple] = []
    elf = poolfix.Elf(obj.read_bytes()) if obj else None
    objects = {s['name']: s for s in elf.symbols()} if elf else {}
    for i, (l, r) in enumerate(zip(lrows, rrows)):
        if (l.get("diff_kind") or "DIFF_NONE") == "DIFF_NONE" and (r.get("diff_kind") or "DIFF_NONE") == "DIFF_NONE":
            continue
        li, ri = l.get("instruction", {}), r.get("instruction", {})
        lrel, rrel = li.get("relocation"), ri.get("relocation")
        if not lrel or not rrel or lrel.get("type_name") != rrel.get("type_name"):
            continue
        lp = [x for x in li.get("parts", []) if "reloc" not in json.dumps(x)]
        rp = [x for x in ri.get("parts", []) if "reloc" not in json.dumps(x)]
        if lp != rp:
            continue
        try:
            lname = lsyms[lrel["target_symbol"]]["name"]
            rsym = rsyms[rrel["target_symbol"]]
        except (IndexError, KeyError, TypeError):
            continue
        s = syms.get(lname)
        if s is None:
            local = re.fullmatch(r'(.+)_([0-9A-Fa-f]{8})', lname)
            candidate = syms.get(local[1]) if local else None
            if candidate and candidate.addr == int(local[2], 16):
                s = candidate
        if s and s.kind == "object" and lname.startswith("jumptable_") and rsym.get("name", "").startswith("@") \
                and int(rsym.get("size") or 0) == s.size:
            # a switch jump table: ours is a private data symbol of the same size; the unit owns
            # the retail table's range (carve), so ours is renamed in place, not dropped
            rows.add(i)
            pair = (rsym["name"], lname, f"{lname}=jumptable[{s.size}]")
            if pair not in pairs:
                pairs.append(pair)
            continue
        if (s and s.kind == 'object' and rsym.get('name', '').startswith('@')
                and int(lrel.get('addend') or 0) == int(rrel.get('addend') or 0)
                and _local_table_matches(project, module, elf, objects.get(rsym['name']), s, function_name)):
            rows.add(i)
            pair = (rsym['name'], s.name, f'{s.name}=verified switch[{s.size // 4}]')
            if pair not in pairs:
                pairs.append(pair)
            continue
        if not s or s.kind != "object" or s.section not in (".rodata", ".sdata2", ".data", ".sdata"):
            continue
        private_name = rsym.get('name', '')
        own = objects.get(private_name)
        local_static = '$' in private_name and own and own['info'] >> 4 == 0
        # `...rodata.0`: the whole literal pool addressed through one base register (MWCC
        # CSEs the pool address when a function uses many constants); the primed pool
        # (fixup_evidence.shared_pool_primer) lays it out exactly like retail's
        anonymous = bool(re.fullmatch(r'\.\.\.\w+\.\d+', private_name)) and own is not None and elf is not None
        if not (private_name.startswith('@') or local_static or anonymous):
            continue
        # Private initializer objects include strings and aggregates, not just
        # floating literals. Verify the complete object, including padding, and
        # reject pointer-bearing data whose bytes alone cannot prove equality.
        own = objects.get(rsym['name'])
        if own and elf:
            if not 0 < own['shndx'] < len(elf.sections) or (not own['size'] and not anonymous):
                continue
            section = elf.sections[own['shndx']]
            if section['name'] not in ('.rodata', '.sdata2', '.data', '.sdata'):
                continue
            if anonymous and any(rel['type'] == 4 and rel['info'] == own['shndx'] and rel['size']
                                 for rel in elf.sections):
                continue
            if any(rel['type'] == 4 and rel['info'] == own['shndx'] and
                   any(own['value'] <= struct.unpack_from('>I', elf.data, off)[0] < own['value'] + own['size']
                       for off in range(rel['offset'], rel['offset'] + rel['size'], 12)) for rel in elf.sections):
                continue
            start = section['offset'] + own['value']
            size = own['size']
            if anonymous:
                # up to the end of the last object in the section (tail padding is not retail's),
                # but no further than retail's own displacement reach: a literal of ours that
                # retail keeps elsewhere (bound by its own relocation) is appended after the
                # primed layout and must not fail the pool's comparison
                size = max((o['value'] + o['size'] for o in objects.values()
                            if o['shndx'] == own['shndx'] and o['size']), default=section['size']) - own['value']
                reach = 0
                # The pool base is the register the `addi rD, rS, sym@l` row materialises, i.e.
                # the DESTINATION of the LO row that binds this same anonymous symbol. Only
                # displacements through that register measure the pool's reach: the stack frame
                # is addressed through r1 with displacements up to 0xf4, and counting those
                # inflated the reach past retail's pool, so the comparison ran into our unit's
                # own appended literals and rejected a matching pool.
                pool_base = None
                for row in lrows:
                    rel = (row.get('instruction') or {}).get('relocation') or {}
                    if rel.get('target_symbol') != lrel.get('target_symbol'):
                        continue
                    if rel.get('type') != 4:  # R_PPC_ADDR16_LO
                        continue
                    for part in (row.get('instruction') or {}).get('parts', []):
                        arg = part.get('arg') if isinstance(part, dict) else None
                        if isinstance(arg, dict) and 'opaque' in arg:
                            pool_base = arg['opaque']
                            break
                    if pool_base:
                        break
                for row in lrows:
                    text = (row.get('instruction') or {}).get('formatted') or ''
                    m = re.match(r'(lfs|lfd|lwz|lha|lhz|lbz|stw|stfs|stfd) [rf]\d+, (-?0x[0-9a-f]+|-?\d+)\(r\d+\)$', text)
                    if m and int(m.group(2), 0) >= 0:
                        if pool_base is not None:
                            bm = re.search(r'\((r\d+)\)\s*$', text)
                            if not bm or bm.group(1) != pool_base:
                                continue
                        width = {'lfd': 8, 'stfd': 8, 'lha': 2, 'lhz': 2, 'lbz': 1}.get(m.group(1), 4)
                        reach = max(reach, int(m.group(2), 0) + width)
                if reach:
                    # the exact reach: the word after retail's last pooled access belongs to the
                    # next object, and our unit's pool continues with its own literals there
                    size = min(size, (reach + 3) & ~3)
            # Anonymous section symbols have size zero until the range above
            # is computed. Their pointer relocations still require the full
            # byte-and-binding proof in _data_pool_rows.
            if any(rel['type'] == 4 and rel['info'] == own['shndx'] and
                   any(own['value'] <= struct.unpack_from('>I', elf.data, off)[0] < own['value'] + size
                       for off in range(rel['offset'], rel['offset'] + rel['size'], 12)) for rel in elf.sections):
                continue
            ours = bytes(elf.data[start:start + size])
        else:
            ours = b''.join(base64.b64decode(d.get('data', '')) for d in rsym.get('data_diff', []))
            if len(ours) not in (4, 8):
                continue
        address = s.addr + int(lrel.get('addend') or 0) - int(rrel.get('addend') or 0)
        anchor = s if address == s.addr else next((t for t in syms.values()
                    if t.section == s.section and t.addr == address and t.kind == 'object'), None)
        interior = 0
        if anchor is None and s.addr < address < s.end:
            # a literal inside a coarse retail pool object (objdiff resolves a displacement off
            # the pool base to the object plus an offset): bind to the object with an addend
            anchor, interior = s, address - s.addr
        if anchor is None:
            continue
        if module == 'main':
            retail = next((raw[address - base:address - base + len(ours)]
                           for base, raw in project._rel_layout(module).values()
                           if base <= address and address + len(ours) <= base + len(raw)), None)
        else:
            # REL addresses are section-relative: .text and .rodata can both
            # contain this offset. Only the relocation target's section is valid.
            raw = project._raw_section(module, s.section)
            offset = address - project._section_base(module, s.section)
            retail = raw[offset:offset + len(ours)] if raw is not None and offset >= 0 else None
        if not ours or ours != retail:
            continue
        lname = anchor.name if not interior else f"{anchor.name}+0x{interior:X}"
        rows.add(i)
        pair = (rsym["name"], lname, f"{lname}=initializer[{len(ours)}]")
        if pair not in pairs:
            pairs.append(pair)
    return rows, pairs


_FLAGS_CACHE: Dict[tuple, Tuple[str, str]] = {}
# the DOL holds SDK code built by 1.2.5n next to game code built by 1.3.2, interleaved by address,
# and some of that game code (and movie_module) was built with `-use_lmw_stmw on` (stmw/lmw
# prologues): an uncarved function is compiled under every candidate (version, extra flags)
# pair and the best one is its build
STMW = "-use_lmw_stmw on"
VERSION_CANDIDATES = {"main": [("GC/1.2.5n", None), ("GC/1.3.2", None), ("GC/1.3.2", STMW)],
                      "movie_module": [("GC/1.3.2", None), ("GC/1.3.2", STMW)]}


def version_candidates(project: Project, module: str) -> List[Tuple[str, Optional[str]]]:
    return VERSION_CANDIDATES.get(module, [(module_flags(project, module)[1], None)])


def _join_flags(*parts: Optional[str]) -> Optional[str]:
    joined = " ".join(x for x in parts if x)
    return joined or None


def version_for(project: Project, sym: Symbol, source: Optional[Path] = None) -> Tuple[Optional[str], Optional[str]]:
    """(mw_version, extra_cflags) for compiling candidates of this function: the unit's own
    options when carved; otherwise, in a module with several candidate versions, the one under
    which `source` scores best (one compile per candidate); else the module default."""
    unit_src = project.unit_of(sym)
    if unit_src:
        u = project.unit_record(unit_src) or {}
        return u.get("mw_version"), (" ".join(u.get("extra_cflags") or []) or None)
    cands = version_candidates(project, sym.module)
    if len(cands) == 1 or source is None:
        return None, None
    target = project.target_object_for(sym)
    tw = words(target, sym.name) if target else None
    if not tw:
        return None, None
    best = None
    d = STATE_DIR / "work" / "ver"
    d.mkdir(parents=True, exist_ok=True)
    for ver, ex in cands:
        o = d / f"{project.key(sym).replace(':', '__')}.{ver.replace('/', '_')}{'_stmw' if ex else ''}.o"
        cp = compile_source(project, sym.module, source, o, ver, ex)
        ow = words(o, sym.name) if cp.returncode == 0 and o.exists() else None
        pct = word_score(tw, ow)[0] if ow else -1.0
        if best is None or pct > best[0]:
            best = (pct, ver, ex)
    return (best[1], best[2]) if best else (None, None)


def module_flags(project: Project, module: str) -> Tuple[str, str]:
    """(compiler flags, mw version) of a module, from any configured unit of it. Cached per
    objdiff.json version: the lookup used to parse the whole file on every check."""
    oj = ROOT / "objdiff.json"
    try:
        stamp = oj.stat().st_mtime_ns
    except OSError:
        stamp = None
    key = (project.version, module, stamp)
    hit = _FLAGS_CACHE.get(key)
    if hit:
        return hit
    hit = _module_flags(project, module)
    _FLAGS_CACHE[key] = hit
    return hit


def _module_flags(project: Project, module: str) -> Tuple[str, str]:
    for name, meta in project.objdiff_units().items():
        if name.split("/", 1)[0] == module and meta.get("scratch", {}).get("c_flags"):
            flags = meta["scratch"]["c_flags"].replace(" -lang=c", "") + f" -i include -i build/{project.version}/include"
            return flags, ("GC/1.2.5n" if module == "main" else "GC/1.3.2")
    flags = ("-nodefaults -proc gekko -align powerpc -enum int -fp hardware -Cpp_exceptions off -O4,p -inline auto "
             '-pragma "cats off" -pragma "warn_notinlined off" -maxerrors 1 -nosyspath -RTTI off -fp_contract on '
             f"-str reuse -multibyte -i include -i build/{project.version}/include -DBUILD_VERSION=0 -DVERSION_{project.version} -DNDEBUG=1")
    if module != "main":
        flags += " -sdata 0 -sdata2 0"
    return flags, ("GC/1.2.5n" if module == "main" else "GC/1.3.2")


def compile_many(project: Project, module: str, sources: List[Path], out_dir: Path,
                 mw_version: Optional[str] = None, extra_cflags: Optional[str] = None,
                 include_dirs: Optional[List[Path]] = None) -> Dict[Path, Path]:
    """One mwcc invocation over many standalone sources: the process start dominates a single
    compile (63 ms for one file, 80 ms for ten), so candidate bodies are compiled together.
    Returns {source: object} for the objects that exist afterwards; a source that fails to
    compile is simply absent (mwcc goes on with the next file)."""
    flags, mw = module_flags(project, module)
    if include_dirs is not None:
        flags = shlex.join(flag for flag in shlex.split(flags) if not flag.startswith('-D'))
    mw = mw_version or mw
    if extra_cflags:
        extra = shlex.split(extra_cflags)
        olevel = [f for f in extra if f.startswith("-O")]
        if olevel:
            flags = " ".join(shlex.quote(olevel[-1] if f.startswith("-O") else f) for f in shlex.split(flags))
        flags = " ".join([flags] + [shlex.quote(f) for f in extra if not f.startswith("-O")])
    out_dir.mkdir(parents=True, exist_ok=True)
    out: Dict[Path, Path] = {}
    base_cmd = compile_command(project, module, mw_version, extra_cflags, include_dirs)

    def one_chunk(chunk: List[Path]) -> Dict[Path, Path]:
        return compile_chunk(base_cmd, chunk, out_dir)

    # parallel: chunks of up to COMPILE_CHUNK sources, COMPILE_WORKERS mwcc processes at once
    # (a process start is ~80 ms, a source in a batch ~2-8 ms)
    n = len(sources)
    if n > COMPILE_CHUNK:
        per = min(COMPILE_CHUNK_MAX, max(COMPILE_CHUNK, (n + COMPILE_WORKERS - 1) // COMPILE_WORKERS))
        chunks = [sources[i:i + per] for i in range(0, n, per)]
        from concurrent.futures import ThreadPoolExecutor
        with ThreadPoolExecutor(max_workers=COMPILE_WORKERS) as ex:
            for objects in ex.map(one_chunk, chunks):
                out.update(objects)
    elif n:
        out.update(one_chunk(sources))
    return out


def compile_command(project: Project, module: str, mw_version: Optional[str] = None, extra_cflags: Optional[str] = None,
                    include_dirs: Optional[List[Path]] = None) -> List[str]:
    """The mwcc command line (without sources and -o) for a module's flags and a unit's overrides."""
    flags, mw = module_flags(project, module)
    if include_dirs is not None:
        flags = shlex.join(flag for flag in shlex.split(flags) if not flag.startswith('-D'))
    mw = mw_version or mw
    if extra_cflags:
        extra = shlex.split(extra_cflags)
        olevel = [f for f in extra if f.startswith("-O")]
        if olevel:
            flags = " ".join(shlex.quote(olevel[-1] if f.startswith("-O") else f) for f in shlex.split(flags))
        flags = " ".join([flags] + [shlex.quote(f) for f in extra if not f.startswith("-O")])
    # mwcc names each object after its source in the -o directory; sources must have distinct stems
    base_cmd = [str(ROOT / "build" / "tools" / "wibo"), str(ROOT / "build" / "compilers" / mw / "mwcceppc.exe")]
    # -nofail: a source that fails to compile is skipped and the rest of the batch still compiles
    arguments = shlex.split(flags)
    if include_dirs is not None:
        # Donor SDKs must compile against their own declarations; project headers
        # are only appropriate after the importer has adapted the source.
        isolated = []
        i = 0
        while i < len(arguments):
            if arguments[i] == '-i':
                i += 2
            else:
                isolated.append(arguments[i])
                i += 1
        arguments = isolated + ['-cwd', 'source'] + [arg for path in include_dirs for arg in ('-i', str(path))]
    base_cmd += arguments + ["-nofail", "-c"]
    return base_cmd


def compile_chunk(base_cmd: List[str], chunk: List[Path], out_dir: Path) -> Dict[Path, Path]:
    """One mwcc process over a chunk of sources; {source: object} for the ones that compiled."""
    # Wibo scans directories to resolve Windows paths for new output files.
    # A corpus-sized directory makes each compile progressively slower.
    out_dir.mkdir(parents=True, exist_ok=True)
    chunk_dir = out_dir / chunk[0].stem
    chunk_dir.mkdir(exist_ok=True)
    paths = {s: chunk_dir / (s.stem + '.o') for s in chunk}
    for obj in paths.values():
        obj.unlink(missing_ok=True)
    result = subprocess.run(base_cmd + ['-o', str(chunk_dir)] + [str(s) for s in chunk], cwd=ROOT, text=True, capture_output=True, timeout=900)
    # Retain actual compiler diagnostics for deterministic repair passes.
    (chunk_dir / 'compile.log').write_text(result.stdout + result.stderr)
    return {s: obj for s, obj in paths.items() if obj.exists()}


COMPILE_CHUNK = 24
COMPILE_CHUNK_MAX = 240
COMPILE_WORKERS = int(os.environ.get('FZGX_COMPILE_WORKERS', '16'))
if not 1 <= COMPILE_WORKERS <= 16:
    raise ValueError('FZGX_COMPILE_WORKERS must be between 1 and 16')


def check_many(project: Project, items: List[Tuple[str, Path]], max_diff_lines: int = 0,
               mw_version: Optional[str] = None, extra_cflags: Optional[str] = None) -> Dict[str, CheckResult]:
    """`check` for many (symbol, source) pairs at once: the uncarved ones are compiled in
    parallel batches (one mwcc process per chunk instead of one per function), then diffed
    one by one; carved ones go through `check`. Returns {symbol: result}."""
    if isinstance(extra_cflags, list):
        extra_cflags = shlex.join(extra_cflags)
    results: Dict[str, CheckResult] = {}
    # groups by module and unit options (a unit may carry its own compiler version / flags);
    # carved units are diffed against their own retail object, with their own text when no
    # source is given
    groups: Dict[tuple, List[Tuple[str, Symbol, Optional[Path], str]]] = {}
    for symbol, source in items:
        sym = project.resolve(symbol)
        if sym is None:
            results[symbol] = CheckResult(False, symbol, "", error="unknown or ambiguous symbol (use module:name)")
            continue
        unit_src = project.unit_of(sym)
        if project.target_object_for(sym) is None or (unit_src is None and source is None):
            results[symbol] = check(project, symbol, max_diff_lines, source=source,
                                    mw_version=mw_version, extra_cflags=extra_cflags)
            continue
        ucfg = (project.unit_record(unit_src) or {}) if unit_src else {}
        key = (sym.module, mw_version or ucfg.get("mw_version"),
               extra_cflags if extra_cflags is not None else
               (" ".join(ucfg.get("extra_cflags") or []) or None))
        unit = project.objdiff_unit_name(sym.module, unit_src) if unit_src else ""
        groups.setdefault(key, []).append((symbol, sym, source if source is not None else unit_source_path(project, unit_src), unit))
    for (module, mw, extra), group in groups.items():
        cdir = STATE_DIR / "work" / "many" / module
        cdir.mkdir(parents=True, exist_ok=True)
        srcs: List[Path] = []
        for symbol, sym, source, unit in group:
            f = cdir / (project.key(sym).replace(":", "__") + ".c")
            f.write_text(source.read_text())
            srcs.append(f)
        cands = [(mw, extra)] if (mw or extra) else version_candidates(project, module)
        chosen_ver: Dict[Path, Tuple[Optional[str], Optional[str]]] = {}
        if len(cands) > 1 and any(not unit for _, _, _, unit in group):
            # uncarved functions: every candidate build, the best object per function is kept
            per_ver = {c: compile_many(project, module, srcs, cdir / "obj" / (c[0].replace("/", "_") + ("_stmw" if c[1] else "")), c[0], c[1]) for c in cands}
            objs = {}
            for (symbol, sym, source, unit), f in zip(group, srcs):
                if unit:
                    o = per_ver[cands[0]].get(f)
                    if o: objs[f] = o; chosen_ver[f] = cands[0]
                    continue
                tw = words(project.target_object_for(sym), sym.name)
                best = None
                for c in cands:
                    o = per_ver[c].get(f)
                    if not o: continue
                    ow = words(o, sym.name)
                    pct = word_score(tw, ow)[0] if tw and ow else -1.0
                    if best is None or pct > best[0]:
                        best = (pct, c, o)
                if best:
                    objs[f] = best[2]; chosen_ver[f] = best[1]
        else:
            objs = compile_many(project, module, srcs, cdir / "obj", cands[0][0], cands[0][1])
            chosen_ver = {f: cands[0] for f in objs}

        def diff_one(arg) -> Tuple[str, CheckResult]:
            (symbol, sym, source, unit), f = arg
            obj = objs.get(f)
            if obj is None:
                # name the error the slow way, one process for this function only
                return symbol, check(project, symbol, max_diff_lines, source=source,
                                      mw_version=mw, extra_cflags=extra)
            target = project.target_object_for(sym)
            res = _diff(project, module, sym.name, unit, max_diff_lines, target=target, base=obj)
            if res.ok and res.matched_pool:
                mapping = {private: pooled for private, pooled, _ in res._pool_pairs}
                r = poolfix.apply(obj, mapping)
                if not r["skipped"] and r["rodata_emptied"]:
                    res2 = _diff(project, module, sym.name, unit, max_diff_lines, target=target, base=obj)
                    if res2.ok and res2.matched:
                        res2.pool_map, res2.pool = mapping, res.pool
                        res = res2
            if not unit:
                res.uncarved = True
            res.mw_version, res.extra_cflags = chosen_ver.get(f, (None, None))
            return symbol, res

        from concurrent.futures import ThreadPoolExecutor
        with ThreadPoolExecutor(max_workers=COMPILE_WORKERS) as ex:
            for symbol, res in ex.map(diff_one, zip(group, srcs)):
                results[symbol] = res
    return results


def words(obj: Path, name: str) -> Optional[List[int]]:
    """The function's machine words with every relocation field zeroed: the cheap, exact
    comparison for candidate loops (no objdiff, ~0.3 ms). None when the object or symbol is missing."""
    import struct
    from .poolfix import Elf
    try:
        data = obj.read_bytes()
        elf = Elf(data)
    except (OSError, ValueError):
        return None
    # the symbol's own code section: .text for almost everything, .init for the boot and
    # cache code (dtk keeps retail's section; our objects carry the declspec'd section)
    exec_idx = {sec["index"]: sec for sec in elf.sections if sec["flags"] & 4}
    sym = next((s_ for s_ in elf.symbols() if s_["name"] == name and s_["shndx"] in exec_idx), None)
    if sym is None:
        return None
    text = exec_idx[sym["shndx"]]
    lo, hi = sym["value"], sym["value"] + sym["size"]
    buf = poolfix.masked_code(elf, text, lo, hi - lo)
    n = len(buf) // 4
    return list(struct.unpack(f">{n}I", bytes(buf[:n * 4])))


def word_score(target: List[int], ours: List[int]) -> Tuple[float, List[int]]:
    """(percent of equal words, indices of the unequal ones). Positional: a shifted body
    scores low, which is what candidate loops want (the objdiff verdict runs on the winner)."""
    n = max(len(target), len(ours))
    if n == 0:
        return 0.0, []
    bad = [i for i, (t, o) in enumerate(zip(target, ours)) if t != o]
    extra = abs(len(target) - len(ours))
    return 100.0 * (n - len(bad) - extra) / n, bad


def function_score(project: Project, symbol_name: str, target: Path, obj: Path) -> Tuple[bool, float]:
    """(matched, positional score) from one objdiff run without the rendered diff: the cheap
    verdict for candidate loops (a pool match is not detected here; the full check is run on
    the winner)."""
    cp = run([str(OBJDIFF), "diff", "-1", str(target), "-2", str(obj), "-o", "-", "--format", "json", symbol_name])
    if cp.returncode != 0:
        return False, -1.0
    try:
        data = json.loads(cp.stdout)
    except ValueError:
        return False, -1.0
    for s_ in data.get("left", {}).get("symbols", []):
        if s_.get("name") == symbol_name and "match_percent" in s_:
            pct = float(s_["match_percent"])
            return pct >= 100.0, pct
    return False, 0.0


def function_rows(project: Project, symbol_name: str, target: Path, obj: Path):
    """objdiff's aligned instruction rows (target, ours) for one object, or None."""
    cp = run([str(OBJDIFF), "diff", "-1", str(target), "-2", str(obj), "-o", "-", "--format", "json", symbol_name])
    if cp.returncode != 0:
        return None
    try:
        data = json.loads(cp.stdout)
    except ValueError:
        return None
    l = next((s_ for s_ in data.get("left", {}).get("symbols", []) if s_.get("name") == symbol_name), None)
    r = next((s_ for s_ in data.get("right", {}).get("symbols", []) if s_.get("name") == symbol_name), None)
    if l is None or r is None:
        return None
    return l.get("instructions", []), r.get("instructions", []), float(l.get("match_percent", 0.0))


def compile_source(project: Project, module: str, source: Path, obj: Path,
                   mw_version: Optional[str] = None, extra_cflags: Optional[str] = None,
                   *, include_dirs: Optional[List[Path]] = None) -> subprocess.CompletedProcess:
    """Compile a standalone source with the module's flags into `obj` (no unit involved);
    a unit-specific compiler version or extra flags (last flag wins in mwcc) override them."""
    flags, mw = module_flags(project, module)
    mw = mw_version or mw
    if extra_cflags:
        extra = shlex.split(extra_cflags)
        olevel = [f for f in extra if f.startswith("-O")]
        if olevel:  # mwcc keeps the first -O it sees: replace the module's
            flags = " ".join(shlex.quote(olevel[-1] if f.startswith("-O") else f) for f in shlex.split(flags))
        flags = " ".join([flags] + [shlex.quote(f) for f in extra if not f.startswith("-O")])
    obj.parent.mkdir(parents=True, exist_ok=True)
    cmd = [str(ROOT / "build" / "tools" / "wibo"), str(ROOT / "build" / "compilers" / mw / "mwcceppc.exe")]
    # Regenerated headers must take precedence over their currently owned copy.
    cmd += [arg for path in include_dirs or [] for arg in ('-i', str(path))]
    cmd += shlex.split(flags) + ["-c", str(source), "-o", str(obj)]
    return subprocess.run(cmd, cwd=ROOT, text=True, capture_output=True, timeout=120)


def unit_source_path(project: Project, unit_src: str) -> Path:
    """Where the unit's C lives: src/ for standalone units, build/<v>/gen/ for block units."""
    u = project.unit_record(unit_src)
    if u and u.get("tu"):
        return project.build_dir / "gen" / unit_src
    return ROOT / "src" / unit_src


def compile_unit(project: Project, unit: str, unit_src: str,
                 source: Optional[Path] = None, *, output: Optional[Path] = None) -> subprocess.CompletedProcess:
    """Compile one unit straight with mwcc (via wibo) into its objdiff base object.

    No ninja and no build lock: two agents compile two different files, so nothing
    is shared. The flags come from objdiff.json (the same ones ninja uses) plus the
    include dirs the ninja rule adds. ninja will still consider the object up to
    date at relink time because the object is newer than its source. `source`
    overrides the input; probes must supply a scratch `output` to preserve the link object.
    """
    meta = project.objdiff_units().get(unit, {})
    flags = meta.get("scratch", {}).get("c_flags", "").replace(" -lang=c", "")
    flags += f" -i include -i build/{project.version}/include"
    ucfg = project.unit_record(unit_src) or {}
    mw = ucfg.get("mw_version") or ("GC/1.2.5n" if unit.startswith("main/") else "GC/1.3.2")
    obj = output or _base_object(project, unit)
    obj.parent.mkdir(parents=True, exist_ok=True)
    src = source or unit_source_path(project, unit_src)
    cmd = [str(ROOT / "build" / "tools" / "wibo"), str(ROOT / "build" / "compilers" / mw / "mwcceppc.exe")]
    cmd += shlex.split(flags) + ucfg.get("extra_cflags", []) + ["-c", str(src), "-o", str(obj)]
    return subprocess.run(cmd, cwd=ROOT, text=True, capture_output=True, timeout=120)


# 84 unmatched DOL functions (61 KB, the AX/MIX and other SDK libraries) carry the MWCC 1.0/1.1
# prologue order (`mflr; stw r0, 4(r1); stwu`), which no later compiler emits
CANDIDATE_VERSIONS = ["GC/1.2.5", "GC/1.2.5n", "GC/1.3", "GC/1.3.2", "GC/2.0", "GC/2.5", "GC/2.7", "GC/1.1", "GC/1.0"]


def check_versions(project: Project, symbol: str, versions: List[str],
                   extra_cflags: Optional[str] = None) -> Dict[str, float]:
    """Probe the current candidate, including uncarved functions, in scratch objects."""
    sym = project.resolve(symbol)
    if sym is None:
        return {}
    unit_src = project.unit_of(sym)
    work = project.work_path(project.key(sym))
    source = work if work.exists() else (unit_source_path(project, unit_src) if unit_src else None)
    if source is None:
        return {}
    out: Dict[str, float] = {}
    tmp = STATE_DIR / "versions" / project.key(sym).replace(":", "__")
    tmp.mkdir(parents=True, exist_ok=True)
    for ver in versions:
        if not (ROOT / "build" / "compilers" / ver / "mwcceppc.exe").exists():
            out[ver] = -1.0
            continue
        res = check(project, symbol, 0, source=source, mw_version=ver, extra_cflags=extra_cflags)
        if not res.ok:
            (tmp / (ver.replace("/", "_") + ".err")).write_text(res.error or "check failed")
            out[ver] = -2.0
        else:
            out[ver] = res.percent_adjusted if res.pool_rows else res.percent
    return out


def unit_fully_matches(res: CheckResult) -> Optional[str]:
    """Reason the unit may not be flipped to Matching, or None if it is safe."""
    if not res.ok:
        return res.error or "check failed"
    if res.uncarved:  # only this symbol was compared, against the retail auto object
        return None if (res.matched or res.matched_pool) else f"{res.symbol}={res.percent:.1f}%"
    bad = [f"{n}={p:.1f}%" for n, p in res.symbols.items()
           if p < 100.0 and not ((res.matched or res.matched_pool) and n == res.symbol)]
    if bad:
        return "functions below 100%: " + ", ".join(bad)
    if res.missing_in_base:
        return "missing from our object: " + ", ".join(res.missing_in_base)
    if res.extra_in_base:
        return "extra functions in our object: " + ", ".join(res.extra_in_base)
    bad_data = [f"{n}={p:.1f}%" for n, p in res.data_sections.items()
                if p < 100.0 and not (res.matched_pool and n in (".rodata", ".sdata2"))]
    if bad_data:
        return "data sections differ: " + ", ".join(bad_data)
    return None


def byte_diff(project: Project, module: str) -> Dict[str, object]:
    """Compare the linked module against retail: differing bytes by function, plus section
    size differences. Cheap, and it names the culprit when a hash check fails."""
    import struct as _struct
    from collections import Counter
    cfg = (project.config_dir / "config.yml").read_text().splitlines()
    obj = "sys/main.dol" if module == "main" else None
    for i, line in enumerate(cfg):
        if obj is None and line.strip() == f"name: {module}":
            obj = next(l.split(":", 1)[1].strip() for l in reversed(cfg[:i]) if l.startswith("- object:"))
            break
    if obj is None:
        return {"error": f"{module} not in config.yml"}
    retail = (ROOT / "orig" / project.version / obj).read_bytes()
    ours_path = project.module_build_dir(module) / f"{module}.rel" if module != "main" else project.build_dir / "main.dol"
    if not ours_path.exists():
        return {"error": f"{ours_path} missing"}
    ours = ours_path.read_bytes()
    out: Dict[str, object] = {"size_retail": len(retail), "size_ours": len(ours)}
    if module == "main":
        # DOL header: 7 text + 11 data sections (file offset, load address, size)
        offs = _struct.unpack(">18I", retail[0:72]); addrs = _struct.unpack(">18I", retail[72:144]); sizes = _struct.unpack(">18I", retail[144:216])
        funcs = project.functions(module)
        def fn_at(addr):
            lo, hi = 0, len(funcs) - 1
            while lo <= hi:
                m = (lo + hi) // 2
                f = funcs[m]
                if f.addr <= addr < f.end:
                    return f.name
                if addr < f.addr:
                    hi = m - 1
                else:
                    lo = m + 1
            return None
        c = Counter()
        other = 0
        for i in range(18):
            if not sizes[i]:
                continue
            for k in range(sizes[i]):
                o = offs[i] + k
                if o < len(ours) and retail[o] != ours[o]:
                    if i < 7:
                        c[fn_at(addrs[i] + k)] += 1
                    else:
                        other += 1
        out["text_diffs"] = c.most_common(12)
        out["other_diffs"] = other
        out["sections"] = []
        return out
    def secs(d):
        n, off = _struct.unpack(">II", d[12:20])
        return [(i,) + _struct.unpack(">II", d[off + 8 * i:off + 8 * i + 8]) for i in range(n)]
    sa, sb = secs(retail), secs(ours)
    out["sections"] = [(i, hex(oa & ~3), sza, szb) for (i, oa, sza), (_, ob, szb) in zip(sa, sb) if sza != szb or (oa & ~3) != (ob & ~3)]
    to, ts = sa[1][1] & ~3, sa[1][2]
    funcs = project.functions(module)
    def fn_at(off):
        lo, hi = 0, len(funcs) - 1
        while lo <= hi:
            m = (lo + hi) // 2
            f = funcs[m]
            if f.addr <= off < f.end:
                return f.name
            if off < f.addr:
                hi = m - 1
            else:
                lo = m + 1
        return None
    c = Counter()
    for i in range(to, min(to + ts, len(retail), len(ours))):
        if retail[i] != ours[i]:
            c[fn_at(i - to)] += 1
    out["text_diffs"] = c.most_common(12)
    out["other_diffs"] = sum(1 for i in range(min(len(retail), len(ours))) if retail[i] != ours[i]) - sum(c.values())
    return out

def why_link(project: Project, symbol: str) -> Dict[str, object]:
    """Link with just this function's unit flipped to Matching and name where the bytes
    differ. The unit must exist (a rejected match keeps its split range). Restores the
    status afterwards. Deterministic diagnosis for 'matched at the object, not at link'.

    A rejected match does NOT keep its split range: verify uncarves it, so the unit and
    the range are both gone and this function used to bail with "no unit for this
    function" for exactly the population it exists to diagnose. The rejected body is
    preserved under `.fzgx/attempts/<key>.linkfail.*.c`, so the unit is carved again from
    that body, diagnosed, and uncarved again afterwards.
    """
    from .ledger import Ledger  # scoped: avoid the ledger import at oracle load
    sym = project.resolve(symbol)
    if sym is None:
        return {"ok": False, "error": "unknown symbol"}
    key = project.key(sym)
    unit_src = project.unit_of(sym)
    body = None
    for cand in sorted((STATE_DIR / "attempts").glob(f"{key}.linkfail.*.c"), reverse=True):
        if cand.read_text().strip():
            body = cand.read_text()
            break
    recarved = False
    diagnostic_error = None
    try:
        if not unit_src and body:
            # Rebuild the unit this diagnosis needs from the rejected body. Carve only; the
            # relink below supplies the content, and everything is undone before returning.
            from .api import carve  # scoped: api imports oracle
            from .ledger import Ledger as _Ledger
            try:
                carve(project, symbol)
                unit_src = project.unit_of(sym)
                recarved = True
            except Exception as error:  # a carve needs the build tree; report, do not raise
                return {"ok": False, "error": f"cannot re-carve the rejected unit: {error}",
                        "preserved_body": str(sorted((STATE_DIR / "attempts").glob(f"{key}.linkfail.*.c"))[-1])}
            _Ledger().db.execute("UPDATE functions SET unit=? WHERE symbol=?",
                                 (project.unit_of(sym), key))
            unit_src = project.unit_of(sym)
        if not unit_src:
            return {"ok": False, "error": "no unit for this function",
                    "note": "no preserved link-fail body either; nothing to diagnose"}
        with build_lock():
            rec = project.unit_record(unit_src)
            src_path = unit_source_path(project, unit_src)
            saved_src = src_path.read_text() if src_path.exists() else None
            # A pre-existing block may be an accepted pool reconstruction. Diagnosis
            # must restore the complete TU, not remove that block on its way out.
            tu_path = ROOT / 'src' / rec['tu'] if rec and rec.get('tu') else None
            saved_tu = tu_path.read_text() if tu_path and tu_path.exists() else None
            original_status = rec.get('status', 'nonmatching') if rec else 'nonmatching'
            probe_error = None
            try:
                units = project.load_units()
                for u in units:
                    if u["source"] == unit_src:
                        u["status"] = "matching"
                project.save_units(units)
                if body and rec and not rec.get("tu"):
                    src_path.write_text(body)
                elif body and rec and rec.get("tu"):
                    from . import tufile  # scoped: same reason
                    tufile.splice(project, rec, body)
                configure(project)
                cp = relink(project, keep_going=True)
                diag = byte_diff(project, sym.module)
                diag["relink_rc"] = cp.returncode
                text = cp.stdout + cp.stderr
                diag["failed_units"] = re.findall(r"FAILED: \[code=\d+\] (\S+)", text)[:8]
                diag["errors"] = [l for l in text.splitlines() if
                                  ('error' in l.lower() or 'undefined' in l.lower() or
                                   'multiply-defined' in l.lower() or 'previously defined' in l.lower() or
                                   'not found' in l.lower() or 'failed to' in l.lower()) and
                                  'warning' not in l.lower() and not l.startswith('###')][:40]
                diag["tail"] = text.strip().splitlines()[-4:]
            except BaseException as error:
                probe_error = error
                raise
            finally:
                try:
                    # Restore exactly the ownership and source state present before diagnosis.
                    units = project.load_units()
                    for u in units:
                        if u["source"] == unit_src:
                            u["status"] = original_status
                    project.save_units(units)
                    if saved_tu is not None and tu_path is not None:
                        tu_path.write_text(saved_tu)
                    elif saved_src is not None and rec and not rec.get("tu"):
                        src_path.write_text(saved_src)
                    elif rec and rec.get("tu"):
                        from . import tufile  # scoped
                        tufile.remove(project, rec)
                    configure(project)
                    relink(project)
                except BaseException as cleanup_error:
                    if probe_error is not None:
                        raise BaseExceptionGroup(
                            "diagnostic and restoration both failed",
                            [probe_error, cleanup_error]) from None
                    raise
        return {"ok": True, "symbol": symbol, "unit": unit_src, "recarved": recarved, "diag": diag}
    except BaseException as error:
        diagnostic_error = error
        raise
    finally:
        if recarved and unit_src is not None:
            try:
                from .uncarve import uncarve
                uncarve(project, [unit_src])
            except BaseException as cleanup_error:
                if diagnostic_error is not None:
                    raise BaseExceptionGroup(
                        "diagnostic and temporary-unit cleanup both failed",
                        [diagnostic_error, cleanup_error]) from None
                raise
