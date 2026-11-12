"""Deterministic reconciliation of a TU's blocks into one compile environment.

No agent decides anything here. For every block of a TU file the question is
"does it still match retail when compiled under the file's prologue", and
that is a compile plus an objdiff. So:

  1. Private typedef names that collide (two blocks, or a block and a header)
     are prefixed with the function's name. A rename never changes code.
  2. The TU's headers (globals.h, <tu>.h) join the prologue.
  3. For every symbol declared privately by blocks, the candidate declarations
     are the definition's own signature (when the TU defines it), then the
     variants the blocks wrote. The first candidate under which every block
     still matches goes to the prologue and the private copies go; if none
     does, the symbol stays private and is reported as contested.
  4. A block that cannot compile under the prologue at all is stored
     self-contained (`noprologue`) and reported: that list, and only that
     list, is what a rewrite agent is for.

Every verdict is memoised by the generated unit's text (finish.Verifier).
"""

from __future__ import annotations

import re
import subprocess
from collections import Counter, OrderedDict
from typing import Dict, List, Optional, Set, Tuple

from . import tufile, tutidy
from .project import ROOT, Project

DEF_RE = re.compile(r"^((?:[A-Za-z_][\w\s\*]*?)\b([A-Za-z_]\w*)\s*\(([^;{}()]*)\))\s*\{", re.M)
TYPEDEF_NAME_RE = re.compile(r"^\}\s*([A-Za-z_]\w*)\s*;", re.M)
TAG_RE = re.compile(r"^typedef\s+struct\s+([A-Za-z_]\w*)\s*\{", re.M)
# Private type names a block defines, in every spelling agents write: the closing `} Name;` of a
# multi-line typedef (TYPEDEF_NAME_RE), one-line `typedef struct {...} Name;`, plain
# `typedef T Name;` / `typedef T Name[N];`, function-pointer `typedef R (*Name)(...)`, and any
# `struct|union|enum Tag {` definition. Missing the one-line form hoisted
# `extern const SelectionPanel lbl_1_rodata_26F8;` without its typedef (car_colchg, 2026-11-12).
_ONE_LINE_TYPEDEF_RE = re.compile(r"\btypedef\s+(?:struct|union|enum)\s*\w*\s*\{[^{}]*\}\s*([A-Za-z_]\w*)\s*(?:\[[^\]]*\])*\s*;")
_PLAIN_TYPEDEF_RE = re.compile(r"^\s*typedef\s+[^;{}()]*?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\])*\s*;", re.M)
_FNPTR_TYPEDEF_RE = re.compile(r"\btypedef\s+[^;{}]*?\(\s*\*\s*([A-Za-z_]\w*)\s*\)\s*\(")
_ANY_TAG_RE = re.compile(r"\b(?:struct|union|enum)\s+([A-Za-z_]\w*)\s*\{")


def private_type_names(body: str) -> Set[str]:
    """Every type name (typedef or struct/union/enum tag) a block body defines."""
    names: Set[str] = set()
    for rx in (TYPEDEF_NAME_RE, TAG_RE, _ONE_LINE_TYPEDEF_RE, _PLAIN_TYPEDEF_RE, _FNPTR_TYPEDEF_RE, _ANY_TAG_RE):
        names.update(rx.findall(body))
    return names


_EXTERN_RE = re.compile(r"^\s*extern\s+[^;=]*?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\])*\s*;", re.M)


_BUILTIN_WORDS = {'void', 'int', 'char', 'short', 'long', 'unsigned', 'signed', 'float', 'double',
                  's8', 'u8', 's16', 'u16', 's32', 'u32', 's64', 'u64', 'f32', 'f64', 'BOOL', 'size_t',
                  'extern', 'const', 'volatile', 'static', 'inline', 'register'}


def _type_words(decl: str, name: str) -> Set[str]:
    """Typedef names a declaration needs (struct/union/enum tags excluded: an incomplete tag is
    legal in an extern declaration)."""
    from .tutruth import _sig  # lazy: tutruth imports this module
    sig = _sig(decl)
    text = (sig[0] + ' ' + ' '.join(sig[2])) if sig else re.sub(r'\[[^\]]*\]', '', decl.split('=')[0])
    text = re.sub(r'\b(?:struct|union|enum)\s+[A-Za-z_]\w*', ' ', text)
    return set(re.findall(r'(?<![\w])[A-Za-z_]\w*', text)) - {name, '...'} - _BUILTIN_WORDS


def visible_in(decl: str, name: str, known: Set[str]) -> bool:
    """Whether a declaration can live in the prologue: every typedef name it uses is declared by
    the prologue itself or its headers (winning.c hoisted `extern FontDrawPacket ...;` whose type
    only a block's own #include "font.h" provided)."""
    return not (_type_words(decl, name) - known)


def _declared_in(p: Project, include_line: str) -> Set[str]:
    """Names declared extern by a header, by the text itself (comments and hex sizes included)."""
    m = re.search(r'#include\s+"([^"]+)"', include_line)
    if not m:
        return set()
    path = ROOT / "include" / m.group(1)
    if not path.exists():
        return set()
    return set(_EXTERN_RE.findall(path.read_text()))


def _decls(body: str) -> List[Tuple[str, str]]:
    """(symbol, line) for every extern declaration line of a block body."""
    out = []
    for ln in body.splitlines():
        if tutidy.DECL_LINE_RE.match(ln):
            n = tutidy._decl_name(ln)
            if n:
                out.append((n, ln.strip()))
    return out


def _idents(text: str) -> Set[str]:
    return set(re.findall(r"[A-Za-z_]\w*", text))


def object_views(p: Project, tf: tufile.TuFile, known: Optional[Set[str]] = None) -> List[str]:
    """Bind conflicting object declarations once, retaining each block's typed access.

    A scalar and a recovered record can describe the same retail storage. Dropping
    either declaration changes its user's loads; casting the lvalue preserves them.
    The normal per-block oracle still decides whether these rewrites may be kept.
    """
    from .fixup_source import TYPE
    from .sdkimport import masked

    pattern = re.compile(r'^\s*extern\s+(' + TYPE + r')\s*\b([A-Za-z_]\w*)'
                         r'\s*((?:\[[^\]\n]*\]\s*)*)\s*;', re.M)
    canonical, seen = {}, set()

    def declarations(text):
        return list(pattern.finditer(masked(text)))

    def headers(text):
        for rel in re.findall(r'^\s*#\s*include\s+"([^"]+)"', text, re.M):
            path = ROOT / 'include' / rel
            if path in seen or not path.exists():
                continue
            seen.add(path)
            content = path.read_text()
            headers(content)
            for m in declarations(content):
                canonical.setdefault(m[2], (m[1].strip(), m[3].strip()))

    headers(tf.prologue)
    for m in declarations(tf.prologue):
        canonical.setdefault(m[2], (m[1].strip(), m[3].strip()))
    variants = {}
    for b in tf.blocks:
        for m in declarations(b.body):
            variants.setdefault(m[2], set()).add((m[1].strip(), m[3].strip()))
    conflicts = {n for n, types in variants.items()
                 if len(types | ({canonical[n]} if n in canonical else set())) > 1}
    additions = []
    # a type a block defines for itself is invisible in the prologue: never pick a view that
    # names one (car_colchg's `const SelectionPanel lbl_1_rodata_26F8` broke every block)
    private = set()
    for b in tf.blocks:
        private |= private_type_names(b.body)
    for name in sorted(conflicts):
        sym = p.resolve(name)
        if sym is None or sym.kind != 'object':
            continue
        if name not in canonical:
            public = [t for t in variants[name] if not (_idents(t[0]) & private)
                      and (known is None or visible_in(f'extern {t[0]} {name}{t[1]};', name, known))]
            if public:
                typ, dims = min(public, key=lambda t: (bool(re.search(r'\b(?:struct|union)\b', t[0])), t))
            elif getattr(sym, 'size', 0):
                typ, dims = 'u8', f'[{sym.size:#x}]'  # neutral storage view; each block keeps its typed cast
            else:
                continue
            canonical[name] = typ, dims
            additions.append(f'extern {typ} {name}{dims};')
    repaired = []
    for b in tf.blocks:
        code = masked(b.body)
        edits = []
        for m in declarations(b.body):
            name, typ, dims = m[2], m[1].strip(), m[3].strip()
            if name not in conflicts or name not in canonical:
                continue
            # Only declaration-free uses are rewritten. Local shadowing and
            # preprocessor definitions need scope analysis beyond this pass.
            tail = code[m.end():]
            if re.search(r'\b(?:' + TYPE + r')\s+\b' + re.escape(name) + r'\s*(?:[;=,)]|\[)', tail):
                continue
            if re.search(r'^\s*#.*\b' + re.escape(name) + r'\b', code, re.M):
                continue
            edits.append((m.start(), m.end(), '\n'))
            if (typ, dims) != canonical[name]:
                pointer = f'{typ} (*){dims}' if dims else f'{typ} *'
                for use in re.finditer(r'\b' + re.escape(name) + r'\b', tail):
                    at = m.end() + use.start()
                    if re.search(r'(?:\.|->)\s*$', code[:at]):
                        continue
                    edits.append((at, m.end() + use.end(), f'(*({pointer})&{name})'))
                repaired.append(name)
        for start, end, replacement in sorted(edits, reverse=True):
            b.body = b.body[:start] + replacement + b.body[end:]
    if additions:
        tf.prologue = tf.prologue.rstrip() + '\n' + '\n'.join(additions) + '\n'
    return sorted(set(repaired))


def isolate_typedefs(tf: tufile.TuFile, header_typedefs: Set[str]) -> List[Tuple[str, str, str]]:
    """Prefix colliding private typedef/tag names with the block's function name. Returns
    (block, old, new) renames applied (in memory)."""
    owners: Dict[str, List[str]] = {}
    for b in tf.blocks:
        for n in private_type_names(b.body):
            owners.setdefault(n, []).append(b.name)
    renames = []
    for n, bs in owners.items():
        if len(bs) > 1 or n in header_typedefs:
            for bname in bs:
                b = tf.get(bname)
                new = f"{bname}_{n}"
                b.body = re.sub(rf"\b{re.escape(n)}\b", new, b.body)
                renames.append((bname, n, new))
    return renames


def _committed_block(p: Project, tu_source: str, name: str, body: str, flags: List[str]):
    cp = subprocess.run(["git", "show", f"HEAD:src/{tu_source}"], cwd=ROOT, text=True, capture_output=True)
    if cp.returncode == 0:
        try:
            old = tufile.parse(cp.stdout)
            b = old.get(name)
            if b is not None:
                if "noprologue" in b.flags:
                    return b.body, list(b.flags)
                # it matched under the committed prologue, which this pass may have changed: carry
                # that prologue along, self-contained (exactly the text its unit compiled as)
                return old.prologue.rstrip("\n") + "\n\n" + b.body, list(b.flags) + ["noprologue"]
        except ValueError:
            pass
    return body, flags


def reconcile_tu(p: Project, tu_source: str, v) -> Dict[str, object]:
    module = tu_source.split("/")[1] if tu_source.startswith("rel/") else "main"
    stem = tu_source.rsplit("/", 1)[-1][:-2]
    units = {u["symbols"][0]: u for u in p.load_units() if u.get("tu") == tu_source}
    path = tufile.tu_path(p, tu_source)
    tf = tufile.load(p, tu_source)
    out: Dict[str, object] = {"tu": tu_source, "renamed": 0, "hoisted": [], "contested": {}, "unresolved": [],
                              "included": []}

    def verdicts(names: List[str]) -> Dict[str, bool]:
        """Per-block verdicts under the current prologue, one batched compile for all of them."""
        present = [n for n in names if n in units]
        for n in present:
            tufile.write_gen(p, units[n], tf)
        if not present:
            return {}
        if hasattr(v, "verdicts"):
            return v.verdicts(p, present, module)
        return {n: v.matches(p, n, module) for n in present}

    def verify(names: List[str]) -> bool:
        return all(verdicts(names).values())

    def restore_gens(names: List[str]) -> None:
        for n in names:
            if n in units:
                tufile.write_gen(p, units[n], tf)

    # every block starts as "under the prologue": the self-contained form is only a last resort
    for b in tf.blocks:
        b.flags = [f for f in b.flags if f != "noprologue"]

    # 1. headers
    for h in (f"{p.module_src_prefix(module)}/globals.h", f"{p.module_src_prefix(module)}/{stem}.h"):
        line = f'#include "{h}"'
        if (ROOT / "include" / h).exists() and line not in {ln.strip() for ln in tf.prologue.splitlines()}:
            tf.prologue = tufile.merge_prologue(tf.prologue, [line])
            out["included"].append(h)
    header_names, header_typedefs = tutidy._header_names(p, tf.prologue)
    # the headers are the file's truth: a prologue declaration of a symbol they declare goes
    # (a different spelling would be a redeclaration error in every block)
    kept = []
    for ln in tf.prologue.splitlines():
        n = tutidy._decl_name(ln) if tutidy.DECL_LINE_RE.match(ln) else None
        if n and n in header_names:
            out.setdefault("dropped_from_prologue", []).append(n)
            continue
        kept.append(ln)
    tf.prologue = "\n".join(kept).rstrip("\n") + "\n"

    # 2. private typedefs that collide
    out["renamed"] = len(isolate_typedefs(tf, header_typedefs))
    known = header_typedefs | private_type_names(tufile.prologue_decls(tf)) | _BUILTIN_WORDS
    out["object_views"] = object_views(p, tf, known)

    # 3. declarations, symbol by symbol
    definitions: Dict[str, str] = {}
    definer: Dict[str, str] = {}
    private_typed: Set[str] = set()  # defined with a block-private parameter type: never hoisted
    for b in tf.blocks:
        private_types = private_type_names(b.body)
        for m in DEF_RE.finditer(b.body):
            definer[m.group(2)] = b.name
            if _idents(m.group(1)) & private_types or not visible_in('extern ' + m.group(1).strip() + ';', m.group(2), known):
                private_typed.add(m.group(2))
            else:
                definitions[m.group(2)] = "extern " + m.group(1).strip() + ";"
    variants: Dict[str, Counter] = OrderedDict()
    where: Dict[str, Set[str]] = {}
    for b in tf.blocks:
        private_types = private_type_names(b.body)
        for n, ln in _decls(b.body):
            if _idents(ln) & private_types or n in private_typed or not visible_in(ln, n, known):
                continue  # names a block-private type: cannot leave the block
            variants.setdefault(n, Counter())[ln] += 1
            where.setdefault(n, set()).add(b.name)
    # every block that names the symbol is affected by its prologue declaration: the definer,
    # and callers that never declared it (an implicit declaration is a declaration too)
    for n in list(variants):
        if n in definer:
            where[n].add(definer[n])
        pat = re.compile(rf"\b{re.escape(n)}\b")
        for b in tf.blocks:
            if b.name not in where[n] and pat.search(b.body):
                where[n].add(b.name)
    # bare prototypes (`u16 f(char *, ...);`, no `extern`) declare a name too: missing them
    # hoisted a second, conflicting declaration of fn_1_3F8C in car_colchg.c (2026-11-12)
    prologue_decl_names = set(tufile._header_items(tufile.prologue_decls(tf))) | \
        {n for n, _ in _decls(tufile.prologue_decls(tf))}

    def strip_decl(b, n):
        b.body = "\n".join(ln for ln in b.body.splitlines()
                           if not (tutidy.DECL_LINE_RE.match(ln) and tutidy._decl_name(ln) == n))
        b.body = re.sub(r"\n{3,}", "\n\n", b.body).strip("\n") + "\n"

    def candidates(n):
        cands: List[Optional[str]] = []
        if n in header_names or n in prologue_decl_names:
            cands.append(None)  # already declared for everyone: just drop the private copies
        if n in definitions:
            cands.append(definitions[n])
        cands += [t for t, _ in sorted(variants[n].items(), key=lambda kv: (-kv[1], -len(kv[0])))]
        return cands

    # phase A: every symbol gets its best-guess declaration at once; one verification per block
    chosen: Dict[str, Optional[str]] = {n: candidates(n)[0] for n in variants}
    original = {b.name: b.body for b in tf.blocks}
    base_prologue = tf.prologue
    for b in tf.blocks:
        for n in variants:
            if b.name in where[n]:
                strip_decl(b, n)
    def render_prologue():
        have = {ln.strip() for ln in base_prologue.splitlines()}
        lines = list(dict.fromkeys(c for n, c in chosen.items() if c is not None and c.strip() not in have))
        return base_prologue.rstrip("\n") + ("\n" + "\n".join(lines) + "\n" if lines else "\n")
    tf.prologue = render_prologue()
    first = verdicts([b.name for b in tf.blocks])
    failing = [b.name for b in tf.blocks if b.name in units and not first.get(b.name)]
    # Complete TUs can expose allocation changes once their object declarations
    # agree. Repair that compile environment with the existing engine before
    # misclassifying every declaration used by the block as contested.
    from . import collapse, fixup, oracle
    entry = collapse._tu_entry(p, module, tu_source)
    complete = entry and all(units.get(n, {}).get('status') == 'matching' for n in entry['functions'])
    if complete:
        for bname in list(failing):
            b = tf.get(bname)
            gen = tufile.write_gen(p, units[bname], tf)
            base = oracle.check_many(p, [(f'{module}:{bname}', gen)], 12)[f'{module}:{bname}']
            if not base.ok:
                continue
            repair = fixup.try_fix(p, f'{module}:{bname}', gen.read_text(), base=base, max_candidates=1024)
            prefix = tf.prologue + '\n'
            if repair.get('matched') and repair['body'].startswith(prefix):
                b.body = repair['body'][len(prefix):]
                declarations = '\n'.join(ln for _, ln in _decls(original[bname]))
                original[bname] = declarations + '\n' + b.body
                if verify([bname]):
                    failing.remove(bname)
                    out.setdefault('repaired', []).append(bname)
    # phase B: for a failing block, try the other candidates of the symbols it uses, one symbol at a time
    for bname in failing:
        b = tf.get(bname)
        fixed = False
        for n in [n for n in variants if bname in where[n]]:
            for cand in candidates(n)[1:]:
                prev = chosen[n]
                chosen[n] = cand
                tf.prologue = render_prologue()
                # the change must keep every other user of the symbol matching too
                if verify([bname]) and verify([u for u in sorted(where[n]) if u != bname]):
                    fixed = True
                    break
                chosen[n] = prev
                tf.prologue = render_prologue()
            if fixed:
                break
        if not fixed:
            # the symbols this block names are contested: no prologue declaration for them, and
            # every block that had its private copy stripped in phase A gets it back
            for n in [n for n in variants if bname in where[n]]:
                if n in header_names:
                    continue  # the header declares it for everyone: only this block goes self-contained
                out["contested"][n] = sorted(variants[n])
                chosen[n] = None
            for other in tf.blocks:
                if other.name in original:
                    other.body = original[other.name]
                    for n in variants:
                        if chosen[n] is not None and other.name in where[n]:
                            strip_decl(other, n)
            tf.prologue = render_prologue()
    out["hoisted"] = [n for n, c in chosen.items() if n not in out["contested"]]
    # every block is re-checked once more under the final prologue in step 4
    # 4. what still cannot live under the prologue (one batched verdict for every block)
    final = verdicts([b.name for b in tf.blocks])
    for b in tf.blocks:
        u = units.get(b.name)
        if u is None:
            continue
        if not final.get(b.name):
            b.flags.append("noprologue")
            # from the block's own text as the agent wrote it: its private declarations (stripped
            # in phase A when a header covered them) are what decide which headers it can include
            inc, body = tufile.split_includes(original.get(b.name, b.body))
            incs = [ln.strip() for ln in tf.prologue.splitlines() if tufile.INCLUDE_RE.match(ln)]
            # a header that declares a symbol this block declares itself (differently, or it would
            # have been hoisted) cannot be included: the block stays on its own declarations
            own = {n for n, _ in _decls(body)}
            safe = []
            for ln in incs + [ln.strip() for ln in inc]:  # the prologue's includes and the block's own
                # a self-contained block is one that does not compile under the file's environment:
                # the module's generated headers stay out, every declaration it needs is materialised
                if re.search(r'"rel/[^"]+\.h"', ln) or own & _declared_in(p, ln):
                    out.setdefault("header_excluded", []).append((b.name, ln))
                    continue
                safe.append(ln)
            keep = list(dict.fromkeys(safe))
            # the declarations it matched under are the committed prologue's, not today's
            # (a hoisted declaration the header has since replaced must come back into the block)
            cp = subprocess.run(["git", "show", f"HEAD:src/{tu_source}"], cwd=ROOT, text=True, capture_output=True)
            try:
                old_tf = tufile.parse(cp.stdout) if cp.returncode == 0 else tf
            except ValueError:
                old_tf = tf
            old_decls = tufile.prologue_decls(old_tf)
            cur_decls = tufile.prologue_decls(tf)
            decls = tufile.materialize_old_decls(p, keep, body, old_decls if old_decls else cur_decls)
            b.body = "\n".join(keep) + "\n\n" + (decls + "\n\n" if decls else "") + body
            tufile.write_gen(p, u, tf)
            if not v.matches(p, b.name, module):
                # keep the tree green with the committed block, whatever it was
                b.body, b.flags = _committed_block(p, tu_source, b.name, b.body, b.flags)
                tufile.write_gen(p, u, tf)
            out["unresolved"].append(b.name)
    tufile._write_atomic(path, tf.render())
    return out
