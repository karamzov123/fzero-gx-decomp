"""Remove block-private declarations that the TU's headers already provide.

Matched blocks written before the headers existed carry their own `extern`
lines and struct typedefs. Inside a per-function unit they are harmless; in the
whole-TU compile they collide with the headers and with each other. This pass
deletes, block by block, the private declarations the headers now cover, and
keeps each edit only if the block's generated unit still compiles and still
matches its retail object (plain or pool match). Nothing else is touched.
"""

from __future__ import annotations

import re
from typing import Dict, List, Optional, Set

from . import oracle, tufile
from .project import ROOT, Project

EXTERN_RE = re.compile(r"^\s*extern\b[^;{]*?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\])*\s*;\s*$")
PROTO_RE = re.compile(r"^\s*(?:extern\s+)?[A-Za-z_][\w\s\*]*?\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*;\s*$")
TYPEDEF_START_RE = re.compile(r"^\s*typedef\s+struct\b")
TYPEDEF_END_RE = re.compile(r"^\s*\}\s*([A-Za-z_]\w*)\s*;\s*$")


def _header_names(p: Project, prologue: str) -> tuple:
    """(extern/prototype names, typedef names) declared by the prologue's includes."""
    names: Set[str] = set()
    typedefs: Set[str] = set()
    seen: Set[str] = set()

    def walk(rel: str) -> None:
        if rel in seen:
            return
        seen.add(rel)
        path = ROOT / "include" / rel
        if not path.exists():
            return
        text = path.read_text()
        for m in re.finditer(r'^\s*#\s*include\s+"([^"]+)"', text, re.M):
            walk(m.group(1))
        for m in re.finditer(r"^extern\s+[^;(]*?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\])*\s*;", text, re.M):
            names.add(m.group(1))
        for m in re.finditer(r"^extern\s+[^;]*?\b([A-Za-z_]\w*)\s*\(", text, re.M):
            names.add(m.group(1))
        for m in re.finditer(r"^\}\s*([A-Za-z_]\w*)\s*;", text, re.M):
            typedefs.add(m.group(1))
        for m in re.finditer(r"^typedef\s+[^{;]*?\b([A-Za-z_]\w*)\s*;", text, re.M):
            typedefs.add(m.group(1))

    for m in re.finditer(r'^\s*#\s*include\s+"([^"]+)"', prologue, re.M):
        walk(m.group(1))
    return names, typedefs


def tidy_block(body: str, names: Set[str], typedefs: Set[str]) -> tuple:
    """Drop covered externs/prototypes and duplicate struct typedefs. Returns (text, removed)."""
    out: List[str] = []
    removed: List[str] = []
    lines = body.splitlines()
    i = 0
    while i < len(lines):
        ln = lines[i]
        if TYPEDEF_START_RE.match(ln) and "{" in ln:
            j, depth = i, 0
            while j < len(lines):
                depth += lines[j].count("{") - lines[j].count("}")
                if depth <= 0 and j > i or (depth == 0 and TYPEDEF_END_RE.match(lines[j])):
                    break
                j += 1
            m = TYPEDEF_END_RE.match(lines[j]) if j < len(lines) else None
            if m and m.group(1) in typedefs:
                removed.append(f"typedef {m.group(1)}")
                i = j + 1
                continue
            out.extend(lines[i:j + 1])
            i = j + 1
            continue
        m = EXTERN_RE.match(ln) or (PROTO_RE.match(ln) if ln.lstrip().startswith("extern") else None)
        if m and m.group(1) in names:
            removed.append(m.group(1))
            i += 1
            continue
        out.append(ln)
        i += 1
    text = "\n".join(out).strip("\n") + "\n"
    text = re.sub(r"\n{3,}", "\n\n", text)
    return text, removed


def _verdict(p: Project, name: str) -> bool:
    res = oracle.check(p, name, 20)
    return res.ok and (res.matched or res.matched_pool) and oracle.unit_fully_matches(res) is None


def tidy(p: Project, tu_source: str, dry_run: bool = False, check_fn=None) -> Dict[str, object]:
    module = tu_source.split("/")[1] if tu_source.startswith("rel/") else "main"
    tf = tufile.load(p, tu_source)
    names, typedefs = _header_names(p, tf.prologue)
    units = {u["symbols"][0]: u for u in p.load_units() if u.get("tu") == tu_source}
    kept, reverted, untouched = [], [], 0
    prologue_incs = {ln.strip() for ln in tf.prologue.splitlines() if tufile.INCLUDE_RE.match(ln)}
    for b in list(tf.blocks):
        inc, rest = tufile.split_includes(b.body)
        # a noprologue block is measured against the TU headers too: the point is to make it
        # compile under the prologue, so its private copies of header declarations must go
        new, removed = tidy_block(rest, names, typedefs)
        keep_inc = [ln for ln in inc if ln.strip() not in prologue_incs]
        was_noprologue = "noprologue" in b.flags
        if not removed and not was_noprologue:
            untouched += 1
            continue
        if dry_run:
            kept.append((b.name, removed))
            continue
        u = units.get(b.name)
        if u is None:
            continue
        old_body, old_flags = b.body, list(b.flags)
        b.body = ("\n".join(keep_inc) + "\n\n" + new) if keep_inc else new
        b.flags = [f for f in b.flags if f != "noprologue"]
        tufile._write_atomic(tufile.tu_path(p, tu_source), tf.render())
        tufile.write_gen(p, u, tf)
        ok = (check_fn or _verdict)(p, b.name)
        if ok:
            kept.append((b.name, removed + (["noprologue"] if was_noprologue else [])))
        else:
            b.body, b.flags = old_body, old_flags
            tufile._write_atomic(tufile.tu_path(p, tu_source), tf.render())
            tufile.write_gen(p, u, tf)
            reverted.append((b.name, removed, "no longer matches"))
    return {"tu": tu_source, "tidied": kept, "reverted": reverted, "untouched": untouched}


# an extern line, or a prototype written without extern: `s32 fn_1_9D260(void);`
# a statement (`else if (c) f(x);`, `return f(x);`) is never a declaration (effect_car.c:
# `else if` call lines were skipped by call adaptation and listed as declarations of `if`)
STMT_KW = r"(?:else|if|while|for|do|switch|return|case|goto|sizeof|break|continue)\b"
DECL_LINE_RE = re.compile(r"^\s*(?!" + STMT_KW + r")(?:extern\b[^{]*;|(?:const\s+)?[A-Za-z_]\w*[\w\s\*]*?\b[A-Za-z_]\w*\s*\([^;{}]*\)\s*;)\s*$")


def _decl_name(line: str) -> Optional[str]:
    if line.lstrip().startswith(("typedef", "static")) or re.match(r"\s*" + STMT_KW, line):
        return None
    m = PROTO_RE.match(line) if "(" in line else EXTERN_RE.match(line)
    return m.group(1) if m else None


def hoist_decls(p: Project, tu_source: str, check_fn=None) -> Dict[str, object]:
    """Move block-level `extern` declarations (data and prototypes) into the TU prologue.

    Per symbol the declaration used by most blocks wins (ties: the longest). Every block
    is re-checked; a block that stops matching keeps its own declaration and is flagged
    `noprologue` so the tree stays green: it is the revise pass's queue, with the
    prologue's declaration as the target."""
    from collections import Counter
    module = tu_source.split("/")[1] if tu_source.startswith("rel/") else "main"
    tf = tufile.load(p, tu_source)
    units = {u["symbols"][0]: u for u in p.load_units() if u.get("tu") == tu_source}
    # types defined inside blocks are invisible to the prologue: declarations naming them stay
    private = set()
    for b in tf.blocks:
        private.update(m.group(1) for m in re.finditer(r"^\}\s*([A-Za-z_]\w*)\s*;", b.body, re.M))
        private.update(m.group(1) for m in re.finditer(r"^typedef\s+[^{;]*?\b([A-Za-z_]\w*)\s*;", b.body, re.M))
    private.update(m.group(1) for m in re.finditer(r"^\}\s*([A-Za-z_]\w*)\s*;", tf.prologue, re.M))
    variants: Dict[str, Counter] = {}
    order: List[str] = []
    unhoistable: set = set()  # declared somewhere with a block-private type: stays in the blocks
    for b in tf.blocks:
        if "noprologue" in b.flags:
            continue
        for ln in b.body.splitlines():
            if DECL_LINE_RE.match(ln):
                n = _decl_name(ln)
                if not n:
                    continue
                if set(re.findall(r"[A-Za-z_]\w*", ln)) & private:
                    unhoistable.add(n)
                    continue
                variants.setdefault(n, Counter())[ln.strip()] += 1
                if n not in order:
                    order.append(n)
    # a function defined in this TU: its prototype comes from the definition, not from what
    # callers guessed (a wrong guess in the prologue would collide with the definition)
    for b in tf.blocks:
        for m in re.finditer(r"^((?:[A-Za-z_][\w\s\*]*?)\b([A-Za-z_]\w*)\s*\([^;{}()]*\))\s*\{", b.body, re.M):
            name = m.group(2)
            if name in variants or name in unhoistable:
                if set(re.findall(r"[A-Za-z_]\w*", m.group(1))) & private:
                    unhoistable.add(name)
                    continue
                unhoistable.discard(name)
                variants[name] = Counter({"extern " + m.group(1).strip() + ";": 10 ** 6})
                if name not in order:
                    order.append(name)
    for n in unhoistable:
        variants.pop(n, None)
    order = [n for n in order if n in variants]
    if not variants:
        return {"hoisted": [], "flagged": [], "conflicts": {}}
    canon = {n: max(c.items(), key=lambda kv: (kv[1], len(kv[0])))[0] for n, c in variants.items()}
    conflicts = {n: sorted(c) for n, c in variants.items() if len(c) > 1}
    old_incs = [ln.strip() for ln in tf.prologue.splitlines() if tufile.INCLUDE_RE.match(ln)]
    pro = tf.prologue.rstrip("\n") + "\n\n" + "\n".join(canon[n] for n in order) + "\n"
    tf.prologue = pro
    flagged, hoisted = [], []
    path = tufile.tu_path(p, tu_source)
    for b in tf.blocks:
        if "noprologue" in b.flags:
            continue
        kept = [ln for ln in b.body.splitlines() if not (DECL_LINE_RE.match(ln) and _decl_name(ln) in canon)]
        if len(kept) == len(b.body.splitlines()):
            continue
        old_body = b.body
        b.body = re.sub(r"\n{3,}", "\n\n", "\n".join(kept)).strip("\n") + "\n"
        u = units.get(b.name)
        if u is None:
            continue
        tufile._write_atomic(path, tf.render())
        tufile.write_gen(p, u, tf)
        ok = (check_fn or _verdict)(p, b.name)
        if ok:
            hoisted.append(b.name)
        else:
            b.body = old_body
            b.flags.append("noprologue")
            inc, body = tufile.split_includes(b.body)
            keep = list(dict.fromkeys(old_incs + [ln.strip() for ln in inc]))
            b.body = "\n".join(keep) + "\n\n" + body
            tufile._write_atomic(path, tf.render())
            tufile.write_gen(p, u, tf)
            flagged.append(b.name)
    tufile._write_atomic(path, tf.render())
    return {"hoisted": hoisted, "flagged": flagged, "conflicts": conflicts, "prologue_decls": len(canon)}
