"""Translation-unit files made of per-function blocks.

The canonical source of a recovered TU is one file, `src/rel/<module>/<tu>.c`,
holding its matched functions in retail (address) order, each between markers
the tooling owns:

    #include "rel/main_rel/globals.h"        <- prologue: everything before the first block
    #include "rel/main_rel/camera.h"

    /* fzgx:begin fn_1_88D8 */
    ...declarations the function needs, its data, the function...
    /* fzgx:end fn_1_88D8 */

The link and the oracle stay per function: for every block a unit is generated
under build/<VERSION>/gen/<unit>.c as `prologue + block` (or the block alone
when it is flagged `noprologue`) and compiled against its own split range, so a
matched function is linked from C and hash-checked the day it matches, not the
day its TU completes. Blocks therefore never need to agree with each other to
build; `tu_check` reports what keeps the whole file from compiling as one unit,
which the revise pass drives to zero.

Agents never edit the TU file. They edit a private work copy; `submit` splices
it in as a block (a write-only lock held for the copy), and `release` discards
it. Nothing else serialises.
"""

from __future__ import annotations

import fcntl
import re
import shlex
import subprocess
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, List, Optional, Tuple

from .project import ROOT, STATE_DIR, Project, Symbol

BEGIN_RE = re.compile(r"^/\* fzgx:begin (?P<name>[A-Za-z_]\w*)(?P<flags>(?: [a-z]+)*) \*/\s*$")
END_RE = re.compile(r"^/\* fzgx:end (?P<name>[A-Za-z_]\w*) \*/\s*$")
INCLUDE_RE = re.compile(r'^\s*#\s*include\s+[<"][^">]+[">]\s*$')
STUB = "// {name}: not matched yet (fzgx carves a split range; the object comes from retail)\n"


@dataclass
class Block:
    name: str
    body: str                       # text between the markers, without them
    flags: List[str] = field(default_factory=list)

    def render(self) -> str:
        head = f"/* fzgx:begin {self.name}" + "".join(f" {f}" for f in self.flags) + " */\n"
        body = self.body if self.body.endswith("\n") else self.body + "\n"
        return head + body + f"/* fzgx:end {self.name} */\n"


@dataclass
class TuFile:
    prologue: str
    blocks: List[Block]

    def get(self, name: str) -> Optional[Block]:
        return next((b for b in self.blocks if b.name == name), None)

    def render(self) -> str:
        pro = self.prologue.rstrip("\n") + "\n" if self.prologue.strip() else ""
        return pro + "".join("\n" + b.render() for b in self.blocks)


def parse(text: str) -> TuFile:
    lines = text.splitlines()
    prologue: List[str] = []
    blocks: List[Block] = []
    cur: Optional[Block] = None
    body: List[str] = []
    for ln in lines:
        m = BEGIN_RE.match(ln)
        if m and cur is None:
            cur = Block(m.group("name"), "", m.group("flags").split())
            body = []
            continue
        m = END_RE.match(ln)
        if m and cur is not None and m.group("name") == cur.name:
            cur.body = "\n".join(body).strip("\n") + "\n"
            blocks.append(cur)
            cur = None
            continue
        if cur is not None:
            body.append(ln)
        elif not blocks:
            prologue.append(ln)
        # text between blocks (outside any block) is dropped: the file is generated
    if cur is not None:
        raise ValueError(f"unterminated block {cur.name}")
    return TuFile("\n".join(prologue).strip("\n") + "\n", blocks)


def split_includes(text: str) -> Tuple[List[str], str]:
    """(include lines, the rest) — includes anywhere at line start are hoisted."""
    inc, rest = [], []
    for ln in text.splitlines():
        (inc if INCLUDE_RE.match(ln) else rest).append(ln)
    return inc, "\n".join(rest).strip("\n") + "\n"


def merge_prologue(prologue: str, includes: List[str]) -> str:
    have = [ln for ln in prologue.splitlines()]
    norm = {ln.strip() for ln in have}
    new = [ln.strip() for ln in includes if ln.strip() not in norm]
    if not new:
        return prologue
    # includes first, in a stable order: types.h, globals.h, then the rest as they come
    incs = [ln for ln in have if INCLUDE_RE.match(ln)] + new
    other = [ln for ln in have if not INCLUDE_RE.match(ln)]
    key = lambda s: (0 if "types.h" in s else 1 if "globals.h" in s else 2)
    incs = sorted(dict.fromkeys(incs), key=key)
    return "\n".join(incs + ([""] + other if any(o.strip() for o in other) else [])).strip("\n") + "\n"


# ------------------------------------------------------------------ project glue
def tu_source_for(p: Project, sym: Symbol) -> Optional[str]:
    """`rel/<module>/<tu>.c` for a function whose TU is known, else None."""
    stem = p.tu_map(sym.module).get(sym.name)
    return f"{p.module_src_prefix(sym.module)}/{stem}.c" if stem else None


def tu_path(p: Project, tu_source: str) -> Path:
    return ROOT / "src" / tu_source


def gen_path(p: Project, unit_source: str) -> Path:
    return p.build_dir / "gen" / unit_source


def load(p: Project, tu_source: str) -> TuFile:
    path = tu_path(p, tu_source)
    return parse(path.read_text()) if path.exists() else TuFile("", [])


def _lock(path: Path):
    lock = STATE_DIR / "locks" / (str(path.relative_to(ROOT)).replace("/", "__") + ".lock")
    lock.parent.mkdir(parents=True, exist_ok=True)
    f = lock.open("w")
    fcntl.flock(f, fcntl.LOCK_EX)
    return f


def _write_atomic(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    # a per-writer temporary: tu-finish runs TUs in 12 threads, and two writers of one generated
    # unit with a shared `.tmp` name raced (main_rel, fn_1_4E724.c.tmp vanished before its rename)
    import os, threading
    tmp = path.with_suffix(path.suffix + f".{os.getpid()}.{threading.get_ident()}.tmp")
    tmp.write_text(text)
    tmp.replace(path)


def unit_text(p: Project, unit: dict) -> str:
    """The C of a unit as an agent should see it: standalone file, or prologue + block."""
    if unit.get("tu"):
        tf = load(p, unit["tu"])
        b = tf.get(unit["symbols"][0])
        if b is None:
            return ""
        return units_gen_text(tf, unit["symbols"])
    path = ROOT / "src" / unit["source"]
    return path.read_text() if path.exists() else ""


def prologue_decls(tf: TuFile) -> str:
    """The prologue without its includes: declarations hoisted out of the blocks."""
    lines = [ln for ln in tf.prologue.splitlines() if not INCLUDE_RE.match(ln)]
    return "\n".join(lines).strip("\n")


def gen_text(tf: TuFile, name: str) -> str:
    b = tf.get(name)
    if b is None:
        return STUB.format(name=name)
    if "noprologue" in b.flags:
        return b.body  # self-contained: its own includes and declarations
    return tf.prologue + "\n" + b.body


def units_gen_text(tf: TuFile, names: List[str]) -> str:
    """A unit of consecutive blocks of one TU (retail order) compiles them as one object, so
    their .data comes out in the compiler's order: a switch table at 4 mod 8 behind the
    previous function's table, or the next function's strings, can then be owned. The
    prologue leads when any block takes it; the blocks follow as written."""
    if len(names) == 1:
        return gen_text(tf, names[0])
    blocks = [tf.get(n) for n in names]
    if any(b is None for b in blocks):
        return "".join(STUB.format(name=n) for n in names)
    head = [tf.prologue] if any("noprologue" not in b.flags for b in blocks) else []
    return "\n".join(head + [b.body for b in blocks])


def write_gen(p: Project, unit: dict, tf: Optional[TuFile] = None) -> Path:
    """Write the generated unit for one block unit (or one unit of consecutive blocks)."""
    tf = tf or load(p, unit["tu"])
    out = gen_path(p, unit["source"])
    text = units_gen_text(tf, unit["symbols"])
    if not out.exists() or out.read_text() != text:
        _write_atomic(out, text)
    return out


def regenerate(p: Project, units: Optional[List[dict]] = None) -> int:
    """Every generated unit of the project (configure.py calls this); returns the count."""
    units = units if units is not None else p.load_units()
    cache: Dict[str, TuFile] = {}
    n = 0
    for u in units:
        if not u.get("tu"):
            continue
        tf = cache.get(u["tu"])
        if tf is None:
            tf = cache[u["tu"]] = load(p, u["tu"])
        write_gen(p, u, tf)
        n += 1
    return n


def _addr_of(p: Project, module: str, name: str) -> int:
    s = p.symbols(module).get(name)
    return s.addr if s else 1 << 40


def splice(p: Project, unit: dict, text: str, noprologue: bool = False, extra_flags: Optional[List[str]] = None) -> Path:
    """Replace (or insert, in address order) the unit's block with `text` in its TU file.

    The prologue is frozen: a block never changes how its neighbours compile. Includes
    already in the prologue are dropped from the block; any other include stays inside
    the block (header guards make the whole-file view harmless) until `hoist` moves it
    up after proving every block still compiles. Held under the TU file's lock for the
    read-modify-write only.
    """
    path = tu_path(p, unit["tu"])
    name = unit["symbols"][0]
    lock = _lock(path)
    try:
        tf = parse(path.read_text()) if path.exists() else TuFile("", [])
        inc, body = split_includes(text)
        flags: List[str] = list(extra_flags or [])
        if not path.exists() or not tf.blocks and not tf.prologue.strip():
            tf.prologue = merge_prologue("", inc)  # first block of a new file sets the prologue
            inc = []
        if noprologue:
            flags.append("noprologue")
        else:
            have = {ln.strip() for ln in tf.prologue.splitlines()}
            inc = [ln for ln in inc if ln.strip() not in have]
        if inc:
            body = "\n".join(inc) + "\n\n" + body
        tf.blocks = [b for b in tf.blocks if b.name != name]
        tf.blocks.append(Block(name, body, flags))
        tf.blocks.sort(key=lambda b: _addr_of(p, unit["module"], b.name))
        _write_atomic(path, tf.render())
    finally:
        lock.close()
    write_gen(p, unit, tf)
    return path


def hoist(p: Project, tu_source: str, compile_fn) -> Dict[str, object]:
    """Move includes that blocks carry privately into the prologue, keeping the change only
    if every generated unit of the TU still compiles (`compile_fn(unit) -> bool`)."""
    path = tu_path(p, tu_source)
    units = [u for u in p.load_units() if u.get("tu") == tu_source]
    lock = _lock(path)
    try:
        before = path.read_text()
        tf = parse(before)
        moved: List[str] = []
        for b in tf.blocks:
            if "noprologue" in b.flags:
                continue
            inc, body = split_includes(b.body)
            if inc:
                tf.prologue = merge_prologue(tf.prologue, inc)
                b.body = body
                moved.extend(ln.strip() for ln in inc)
        if not moved:
            return {"hoisted": [], "ok": True}
        _write_atomic(path, tf.render())
        for u in units:
            write_gen(p, u, tf)
        ok = all(compile_fn(u) for u in units)
        if not ok:
            _write_atomic(path, before)
            tf = parse(before)
            for u in units:
                write_gen(p, u, tf)
        return {"hoisted": sorted(set(moved)) if ok else [], "ok": ok}
    finally:
        lock.close()


def remove(p: Project, unit: dict) -> Optional[str]:
    """Drop the unit's block from its TU file; returns the block body (or None)."""
    path = tu_path(p, unit["tu"])
    if not path.exists():
        return None
    name = unit["symbols"][0]
    lock = _lock(path)
    try:
        tf = parse(path.read_text())
        b = tf.get(name)
        if b is None:
            return None
        tf.blocks = [x for x in tf.blocks if x.name != name]
        _write_atomic(path, tf.render())
    finally:
        lock.close()
    write_gen(p, unit, tf)
    return b.body


def tu_check(p: Project, tu_source: str) -> Tuple[bool, str]:
    """Compile the whole TU file as one unit (the goal state). Returns (ok, compiler text)."""
    path = tu_path(p, tu_source)
    module = tu_source.split("/")[1] if tu_source.startswith("rel/") else "main"
    units = [u for u in p.load_units() if u.get("tu") == tu_source]
    if not units:
        return False, "no block units"
    meta = p.objdiff_units().get(p.objdiff_unit_name(module, units[0]["source"]), {})
    flags = meta.get("scratch", {}).get("c_flags", "").replace(" -lang=c", "")
    flags += f" -i include -i build/{p.version}/include"
    mw = units[0].get("mw_version") or ("GC/1.2.5n" if module == "main" else "GC/1.3.2")
    out = p.build_dir / "gen" / "tu_check" / (Path(tu_source).stem + ".o")
    out.parent.mkdir(parents=True, exist_ok=True)
    cmd = [str(ROOT / "build/tools/wibo"), str(ROOT / "build/compilers" / mw / "mwcceppc.exe")]
    cmd += shlex.split(flags) + ["-c", str(path), "-o", str(out)]
    cp = subprocess.run(cmd, cwd=ROOT, text=True, capture_output=True, timeout=300)
    text = "\n".join(l for l in (cp.stdout + cp.stderr).splitlines() if "Usage Warning" not in l)
    return cp.returncode == 0, text.strip()[-4000:]


def add_include(p: Project, tu_source: str, include: str, compile_fn) -> Dict[str, object]:
    """Add `#include "<include>"` to the TU prologue. Blocks whose generated unit stops
    compiling under the wider prologue are flagged `noprologue` (they keep their own
    includes) so the tree stays green; they are the revise pass's queue."""
    path = tu_path(p, tu_source)
    units = {u["symbols"][0]: u for u in p.load_units() if u.get("tu") == tu_source}
    line = f'#include "{include}"'
    lock = _lock(path)
    try:
        tf = parse(path.read_text())
        if line in {ln.strip() for ln in tf.prologue.splitlines()}:
            return {"added": False, "flagged": []}
        old_incs = [ln.strip() for ln in tf.prologue.splitlines() if INCLUDE_RE.match(ln)]
        tf.prologue = merge_prologue(tf.prologue, [line])
        flagged: List[str] = []
        for b in tf.blocks:
            if "noprologue" in b.flags:
                continue
            u = units.get(b.name)
            if u is None:
                continue
            write_gen(p, u, tf)
            if not compile_fn(u):
                # keep it building exactly as before: its own copy of the old includes
                b.flags.append("noprologue")
                inc, body = split_includes(b.body)
                keep = list(dict.fromkeys(old_incs + [ln.strip() for ln in inc]))
                b.body = "\n".join(keep) + "\n\n" + body
                write_gen(p, u, tf)
                flagged.append(b.name)
        _write_atomic(path, tf.render())
    finally:
        lock.close()
    return {"added": True, "flagged": flagged}


def reflag(p: Project, tu_source: str, compile_fn) -> Dict[str, object]:
    """After a header change, re-decide every block's include set: under the prologue if
    that compiles (flag dropped), else `noprologue` with the widest include set that does
    (types.h alone always works for a self-contained block)."""
    path = tu_path(p, tu_source)
    units = {u["symbols"][0]: u for u in p.load_units() if u.get("tu") == tu_source}
    lock = _lock(path)
    try:
        tf = parse(path.read_text())
        incs = [ln.strip() for ln in tf.prologue.splitlines() if INCLUDE_RE.match(ln)]
        flagged, unflagged, unresolved = [], [], []
        for b in tf.blocks:
            u = units.get(b.name)
            if u is None:
                continue
            was = "noprologue" in b.flags
            inc, body = split_includes(b.body)
            own = list(dict.fromkeys([ln.strip() for ln in inc] + committed_block_includes(p, tu_source, b.name)))
            extra = [ln for ln in own if ln not in incs]
            # 1. under the prologue
            b.flags = [f for f in b.flags if f != "noprologue"]
            b.body = ("\n".join(extra) + "\n\n" + body) if extra else body
            write_gen(p, u, tf)
            if compile_fn(u):
                if was:
                    unflagged.append(b.name)
                continue
            # 2. on its own, widest include set first, plus the prologue declarations it uses
            b.flags.append("noprologue")
            done = False
            pdecls = materialize_old_decls(p, [], body, prologue_decls(tf))
            for keep in (list(dict.fromkeys(incs + own)),
                         [i for i in dict.fromkeys(incs + own) if "globals.h" in i or "types.h" in i],
                         ['#include "types.h"']):
                b.body = "\n".join(keep) + "\n\n" + (pdecls + "\n\n" if pdecls else "") + body
                write_gen(p, u, tf)
                if compile_fn(u):
                    done = True
                    break
            if not done:
                # 3. self-contained: the declarations it uses, from the prologue (hoisted out of
                # the blocks) and from the last committed headers (the types it matched under)
                decls = materialize_old_decls(p, incs + own, body, prologue_decls(tf))
                b.body = '#include "types.h"\n\n' + decls + ("\n\n" if decls else "") + body
                write_gen(p, u, tf)
                if not compile_fn(u):
                    unresolved.append(b.name)
            if not was:
                flagged.append(b.name)
        _write_atomic(path, tf.render())
    finally:
        lock.close()
    return {"tu": tu_source, "flagged": flagged, "unflagged": unflagged, "unresolved": unresolved}


def committed_block_includes(p: Project, tu_source: str, name: str) -> List[str]:
    """Includes the block carried in the last committed TU file (an earlier reflag may have
    narrowed the working copy's)."""
    cp = subprocess.run(["git", "show", f"HEAD:src/{tu_source}"], cwd=ROOT, text=True, capture_output=True)
    if cp.returncode != 0:
        return []
    try:
        b = parse(cp.stdout).get(name)
    except ValueError:
        return []
    if b is None:
        return []
    inc, _ = split_includes(b.body)
    return [ln.strip() for ln in inc]


def _header_items(text: str) -> Dict[str, str]:
    """name -> declaration text (extern lines and typedef struct blocks) of a header."""
    items: Dict[str, str] = {}
    lines = text.splitlines()
    i = 0
    while i < len(lines):
        ln = lines[i]
        if re.match(r"^typedef\s+struct\b.*\{\s*$", ln):
            j = i
            while j < len(lines) and not re.match(r"^\}\s*[A-Za-z_]\w*\s*;", lines[j]):
                j += 1
            if j < len(lines):
                name = re.match(r"^\}\s*([A-Za-z_]\w*)\s*;", lines[j]).group(1)
                items[name] = "\n".join(lines[i:j + 1])
            i = j + 1
            continue
        m = re.match(r"^extern\s+[^;(]*?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\])*\s*;", ln) or \
            re.match(r"^extern\s+[^;]*?\b([A-Za-z_]\w*)\s*\(", ln)
        if m:
            items[m.group(1)] = ln
        i += 1
    return items


def materialize_old_decls(p: Project, includes: List[str], body: str, prologue_text: str = "") -> str:
    """Declarations the block uses, copied from the TU prologue and from the last committed
    versions of its headers (types.h excluded), with the typedefs those declarations need."""
    # header declarations first (prologue declarations may name header types/symbols, never
    # the reverse), and nothing the block declares itself
    items: Dict[str, str] = {}
    seen: set = set()

    def walk(rel: str) -> None:  # headers include headers (every TU header pulls globals.h)
        if rel in seen or rel == "types.h":
            return
        seen.add(rel)
        cp = subprocess.run(["git", "show", f"HEAD:include/{rel}"], cwd=ROOT, text=True, capture_output=True)
        text = cp.stdout if cp.returncode == 0 else ((ROOT / "include" / rel).read_text() if (ROOT / "include" / rel).exists() else "")
        for k, v in _header_items(text).items():
            items.setdefault(k, v)
        for m2 in re.finditer(r'^\s*#\s*include\s+"([^"]+)"', text, re.M):
            walk(m2.group(1))

    for inc in includes:
        m = re.match(r'#\s*include\s+"([^"]+)"', inc)
        if m:
            walk(m.group(1))
    if prologue_text:
        for k, v in _header_items(prologue_text).items():
            items.setdefault(k, v)
    own = set(_header_items(body))
    own.update(m.group(1) for m in re.finditer(r"^[A-Za-z_][\w\s\*]*?\b([A-Za-z_]\w*)\s*\([^;{}()]*\)\s*\{", body, re.M))
    used = set(re.findall(r"[A-Za-z_]\w*", body))
    need = [k for k in items if k in used and k not in own]
    # typedefs referenced by the chosen declarations, transitively
    changed = True
    while changed:
        changed = False
        for k in list(need):
            for tok in set(re.findall(r"[A-Za-z_]\w*", items[k])):
                if tok in items and tok not in need and tok != k:
                    need.append(tok)
                    changed = True
    order = {k: i for i, k in enumerate(items)}
    # typedefs first (declarations name them), each group in header order
    types = [k for k in need if items[k].startswith("typedef")]
    rest = [k for k in need if k not in types]
    return "\n".join(items[k] for k in sorted(types, key=lambda k: order[k]) + sorted(rest, key=lambda k: order[k]))
