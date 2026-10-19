"""Context bundle for a matcher: everything it needs, ordered by value per token."""

from __future__ import annotations

import json
import re
import struct
from functools import lru_cache
from pathlib import Path
from typing import List, Optional

from .ledger import Ledger
from . import tufile
from .project import STATE_DIR, ROOT, Function, Project, Symbol

RULES = ROOT / "docs" / "CODING_RULES.md"
IDIOMS = ROOT / "docs" / "MWCC_IDIOMS.md"


def _sig_hint(fn: Function) -> str:
    """Cheap hints from the prologue/epilogue: stack frame, saved regs, float use."""
    body = " ".join(fn.asm)
    hints = []
    if "stwu r1" in body:
        hints.append("has stack frame")
    else:
        hints.append("leaf, no stack frame")
    if any(m in body for m in ("fadds", "fmuls", "fdivs", "lfs ", "stfs", "fcmpu", "frsp", "fmr")):
        hints.append("uses float")
    if "mtctr" in body and "bctr" in body:
        hints.append("has switch/jump table or indirect call")
    if "_savegpr" in body or "stmw" in body:
        hints.append("saves many GPRs (many locals or calls)")
    return "; ".join(hints)


def _decl_for(sym: Symbol, project: Optional[Project] = None, called: bool = False,
              source: Optional[str] = None, index=None) -> str:
    if sym.kind == "function" or called:
        if project is not None:
            from .signatures import recovered
            if index is None:
                index = recovered(project)
            sig = index.get(sym.module, sym.name, source)
            if sig:
                note = ['// Register-flow estimate; confirm against the call sites.'] if 'register-flow' in sig.origin else []
                return "\n".join(index.preamble([sig]) + note + [sig.declaration(sym.name)])
        return f"// {sym.name}: signature unknown; recover arguments and return from call sites."
    dt = sym.attrs.get("data", "")
    ctype = {"byte": "u8", "2byte": "u16", "4byte": "u32", "8byte": "u64", "float": "f32",
             "double": "f64", "string": "char"}.get(dt, "u8")
    n = max(sym.size, 1)
    unit = {"u16": 2, "u32": 4, "u64": 8, "f32": 4, "f64": 8}.get(ctype, 1)
    arr = f"[{n // unit}]" if n // unit > 1 else ""
    return f"extern {ctype} {sym.name}{arr};  // {sym.section}:0x{sym.addr:08X} size 0x{sym.size:X} scope {sym.scope}"


@lru_cache(maxsize=32)
def _header_pieces(hdr):
    from .sdkimport import declarations
    return declarations(hdr)


def _header_decl(hdr: str, name: str) -> str:
    """The complete typedef dependencies and extern, including arrays/unions."""
    from .sdkimport import masked
    pieces = _header_pieces(hdr)
    declaration = next((p.text.strip() for p in pieces if name in p.names
                        and re.match(r'\s*extern\b', p.text)), None)
    if not declaration:
        return ""
    types = {n: p.text.strip() for p in pieces if p.kind == 'type' for n in p.names}
    seen, result = set(), []
    def visit(text):
        for word in re.findall(r'\b[A-Za-z_]\w*\b', masked(text)):
            if word in types and word not in seen:
                seen.add(word)
                visit(types[word])
                result.append(types[word])
    visit(declaration)
    return '\n'.join(result + [declaration])


# failure mode (from stuck.classify_rows / _pure) -> what changed in bodies that then matched
MODE_TIPS = {
    "schedule": "same instructions, different order: MWCC emits argument materialisation and loads in source order; "
                "reorder the statements or the argument expressions, or load a value into a local once and reuse it "
                "(a value used across a call lives in a non-volatile register: `x = g->f; call(); use(x)`).",
    "regalloc": "register numbers only: allocation follows declaration order of locals and the order values are first "
                "used; reorder local declarations, merge two temporaries into one, or split one variable into two.",
    "frame": "stack frame or local offsets differ: a local array/struct is missing or sized differently, or a scalar is "
             "spilled because it lives across a call; compare `stwu` sizes and add/remove/resize locals.",
    "ext": "missing or extra extsh/extsb/clrlwi: a parameter, local or field has the wrong width or signedness "
           "(s16 vs u16 vs s32); the extension appears where a narrow value is used as an int.",
    "signedness": "cmpw vs cmplw / cmpwi vs cmplwi: the compared operand's type (signed vs unsigned) decides it; "
                  "check the variable, the field and the literal (`0x80` vs `0x80u`).",
    "imm": "an immediate differs: a struct field offset (fix the struct layout), a stride (array element size), a "
           "mask (`& 0xFF` vs `& 0x7F`), or a constant folded from an expression.",
    "reloc": "a relocation names another symbol: the wrong global or callee, or a private literal where retail "
             "pools a shared constant (declare the pooled `lbl_*_rodata_*` symbol and use it).",
    "ins:float": "float rows differ: f32 vs f64 arithmetic; a double literal (`1.0`) promotes the expression, `1.0f` "
                 "does not; `frsp` means a double was narrowed.",
    "ins:branch": "branch rows differ: the condition sense or block order; `if (a) X else Y` vs `if (!a) Y else X`, "
                  "`==` vs `!=`, early `return` vs `else`, `&&` chains vs nested ifs.",
    "op:li/addi": "li vs addi: a constant written directly vs derived from another value (`x = 0` vs `x = y - y`, "
                  "or `n = 5` vs `n = m + 1`); also a zero-init reused from another variable.",
    "op:addi/mr": "addi vs mr: the compiler copied a register instead of adding 0; an expression like `p + 0` or a "
                  "different pointer base (`&s->f` vs `s`).",
    "mixed": "several kinds at once: fix the structural ones first (frame, ext, imm, reloc), then scheduling and "
             "registers usually follow.",
}


def _pooled_constant(project: Project, s: Symbol) -> Optional[str]:
    """A float/double literal in .rodata/.sdata2 with its retail value, as a declaration."""
    if (s.kind != "object" or s.section not in (".rodata", ".sdata2") or s.size not in (4, 8)
            or (s.attrs.get('data'), s.size) not in (('float', 4), ('double', 8))):
        return None
    raw = project.bytes_at(s.module, s.name)
    if raw is None:
        return None
    if s.size == 4:
        v = struct.unpack(">f", raw)[0]
        return f"extern const f32 {s.name};  // = {v!r}f (retail literal pool)"
    v = struct.unpack(">d", raw)[0]
    return f"extern const f64 {s.name};  // = {v!r} (retail literal pool)"


def _spell_fitness(tw, ow) -> float:
    import difflib  # scoped: one alignment
    sm = difflib.SequenceMatcher(None, tw, ow, autojunk=False)
    return 100.0 * sum(b.size for b in sm.get_matching_blocks()) / max(len(tw), len(ow))


def _tried_edits(key: str, limit: int = 12, budget: int = 3200) -> List[str]:
    """Edits earlier sessions compiled that did not beat the best score at the time,
    from the archive of checked bodies: the retry should not pay for them again."""
    import difflib
    directory = STATE_DIR / "checks" / key.replace(":", "__")
    try:
        index = [json.loads(line) for line in (directory / "index.jsonl").read_text().splitlines() if line.strip()]
    except (OSError, ValueError):
        return []
    index = index[-40:]
    out: List[str] = []
    seen = set()
    best = None
    previous = None
    for entry in index:
        try:
            body = (directory / f"{entry['n']:03d}.c").read_text()
        except OSError:
            previous = None
            continue
        score = entry.get('percent') if entry.get('ok') else None
        if previous is not None and body != previous[0]:
            changed = [l for l in difflib.unified_diff(previous[0].splitlines(), body.splitlines(), lineterm='', n=0)
                       if l[:1] in '+-' and not l.startswith(('+++', '---'))]
            failed = score is None or (best is not None and score <= best + 1e-6)
            plus = sorted(l[1:].strip() for l in changed if l[0] == '+'); minus = sorted(l[1:].strip() for l in changed if l[0] == '-')
            if plus == minus:
                changed = ['~ reordered: ' + ' / '.join(l[1:].strip() for l in changed if l[0] == '+')]
            text = "\n".join(changed)
            if failed and changed and text not in seen:
                seen.add(text)
                verdict = 'did not compile' if score is None else f"{score:.1f}% (best then {best:.1f}%)"
                shown = changed if len(changed) <= 10 else changed[:10] + [f"  ... {len(changed) - 10} more changed lines (a larger rewrite)"]
                out.append("\n".join(shown) + f"\n# -> {verdict}")
        if score is not None:
            best = score if best is None else max(best, score)
        previous = (body, score)
    out = out[-limit:]
    while out and sum(len(x) for x in out) > budget:
        out.pop(0)
    return out


def build_context(project: Project, ledger: Optional[Ledger], symbol: str,
                  budget_tokens: int = 6000, compiler_options: Optional[dict] = None) -> str:
    sym0 = project.resolve(symbol)
    fn = project.function_asm(sym0.module).get(sym0.name) if sym0 else None
    if fn is None:
        raise LookupError(f"{symbol}: no disassembly (is it a function? ambiguous? run ninja first)")
    sym = fn.symbol
    module = sym.module
    symbol = sym.name
    row = ledger.get(project.key(sym)) if ledger else None
    unit_src = project.unit_of(sym)
    units = {u["source"]: u for u in project.load_units()}
    unit_cfg = units.get(unit_src or "", {})

    parts: List[str] = []
    parts.append(f"# Match task: `{symbol}`")
    parts.append(
        f"- module: `{module}`  section: `{sym.section}`  address: `0x{sym.addr:08X}`  "
        f"size: {sym.size} bytes ({sym.size // 4} instructions)  scope: {sym.scope}"
    )
    if unit_src and unit_cfg.get("tu"):
        parts.append(f"- unit: block `{symbol}` of `src/{unit_cfg['tu']}` (you write the unit; the tooling splices it in)")
        tf = tufile.load(project, unit_cfg["tu"])
        if tf.prologue.strip():
            parts.append(f"\n## Already in scope: the prologue of `src/{unit_cfg['tu']}`\n"
                         "Every block of the file is compiled after these lines. Do not redeclare what they declare; "
                         "if one of them is wrong for the retail bytes of your function, say so in your release reason.\n"
                         "```c\n" + tf.prologue.strip() + "\n```")
    else:
        parts.append(f"- unit: `src/{unit_src}`" if unit_src else "- unit: created when the function matches (write the complete unit; checks diff it against the retail object)")
    if row and not (row["claimed_by"] or "").startswith("shadow-"):
        # best_percent is NULL for a function nobody has attempted yet -- 624 unmatched
        # functions at last count, i.e. every virgin target the fleet is steered toward.
        # Formatting that as a float raised TypeError inside the claim worker, so the claim
        # died before it was recorded: 59 tracebacks in 12h, each losing the whole session.
        # An unattempted function has no best, and "none yet" is the honest thing to print.
        best = row["best_percent"]
        best_text = "none yet" if best is None else f"{float(best):.1f}%"
        parts.append(f"- attempts so far: {row['attempts']}  best: {best_text}")
    parts.append(f"- hints: {_sig_hint(fn)}")
    from .oracle import module_flags
    flags, default_mw = module_flags(project, module)
    options = compiler_options or {}
    supplied_source = bool(options.get('path'))
    mw = options.get('mw') or unit_cfg.get("mw_version") or default_mw
    extra = options.get('flags') or ' '.join(unit_cfg.get('extra_cflags') or [])
    if any(re.search(r"\blis r\d+, 0xcc00\b", ln) for ln in fn.asm) if fn else False:
        parts.append("- hardware registers: the target's `lis rX, 0xcc00` / `addi rX, rX, 0xN000` pair is a link-defined absolute "
                     'symbol; include "dolphin/types.h" for vu32, then declare `extern vu32 __DIRegs[];` '
                     "(0xCC006000; __VIRegs 0xCC002000, __PIRegs 0xCC003000, __MEMRegs "
                     "0xCC004000, __DSPRegs 0xCC005000, __SIRegs 0xCC006400, __EXIRegs 0xCC006800, __AIRegs 0xCC006C00) and index it, "
                     "never a literal address (it folds into the load offset).")
    if sym.section == ".init":
        parts.append('- section: retail placed this function in `.init`; write `__declspec(section ".init")` before the '
                     "return type (the object oracle pairs nothing across sections, and the link needs it there)")
    parts.append(f"- compiler: `{mw}` `{flags}`" + (f" extra overrides: `{extra}`" if extra else ''))
    parts.append('\nA failed experiment is not the end of the task. Try other explanations; '
        'release only for a real blocker or a better target. Evidence tools and structured notes are optional; '
        'spend calls on useful edits and compiler results, not routine bookkeeping.')

    parts.append("\n## Target assembly (retail)\n```asm")
    parts.extend(fn.asm)
    parts.append("```")
    from .evidence import data_context
    data = data_context(project, fn)
    if data:
        parts.append('\n## Decoded retail data\n```text\n' + '\n'.join(data) + '\n```')

    direct_calls = list(dict.fromkeys(m[1] for line in fn.asm
                                     if (m := re.match(r'^[0-9A-Fa-f]+:\s*bl\s+(\w+)$', line))))
    references = list(dict.fromkeys(fn.refs + direct_calls))
    if references:
        signature_index = None
        header = ROOT / "include" / project.module_src_prefix(module) / "globals.h"
        hdr_text = header.read_text() if header.exists() else ""
        tu_stem = None
        tus_path = project.module_config_dir(module) / "tus.json"
        if tus_path.exists():
            for t in json.loads(tus_path.read_text())["tus"]:
                if symbol in t["functions"]:
                    tu_stem = t["file"].rsplit(".", 1)[0]
                    from .signatures import recovered, propagate
                    signature_index = propagate(recovered(project), module, t["functions"])
                    break
        tu_header = ROOT / "include" / project.module_src_prefix(module) / f"{tu_stem}.h" if tu_stem else None
        tu_hdr_text = tu_header.read_text() if tu_header and tu_header.exists() else ""
        hdr_text = hdr_text + "\n" + tu_hdr_text
        shown_from_header = []
        parts.append("\n## Referenced symbols (declare what you use; names are provisional)\n```c")
        pooled = []
        imported = []
        from . import datacontext
        for name in references:
            s = project.find_symbol(name, module) or project.find_symbol(name)
            if not s:
                continue
            if record := datacontext.lookup(project, s):
                imported.append(record)
                continue
            const = _pooled_constant(project, s)
            if const:  # a literal-pool constant beats whatever the header calls it
                parts.append(const)
                pooled.append(name)
                continue
            if hdr_text and _header_decl(hdr_text, name):
                shown_from_header.append(name)
                continue
            source = f'{project.module_src_prefix(module)}/{tu_stem}.c' if tu_stem else None
            if signature_index is None and (s.kind == 'function' or name in direct_calls):
                from .signatures import recovered
                signature_index = recovered(project)
            parts.append(_decl_for(s, project, name in direct_calls, source, signature_index))
        parts.append("```")
        if imported:
            parts.append('\n## Owned data declarations (already defined; include or declare only)\n```c')
            parts.extend(datacontext.declarations(project, record) for record in imported)
            parts.append('```')
        if pooled:
            parts.append("Constant pool: the target loads these from the module's shared literal pool. "
                         "Use the exact values or the declared symbols. The oracle accepts private literals "
                         "only when their bytes and relocation bindings agree with retail.")
        if shown_from_header:
            inc = f"{project.module_src_prefix(module)}/{tu_stem}.h" if tu_hdr_text else f"{project.module_src_prefix(module)}/globals.h"
            parts.append(f"\nThese are declared in `include/{inc}` with recovered struct layouts; "
                         f"`#include \"{inc}\"` and use the typed fields (`unk_XX` names are offsets) "
                         f"instead of casts or your own extern:")
            parts.append("```c")
            for name in shown_from_header:
                parts.append(_header_decl(hdr_text, name))
            parts.append("```")

    # The matcher has no file/assembly reader. Its target and referenced types
    # must survive even when one large function exceeds the auxiliary budget.
    required_chars = len("\n".join(parts))

    # paired-single vector kernels are inline-assembly helpers; name each one the retail code
    # uses with the exact call, since no scalar or __vec2x32float__ spelling can produce it
    try:
        from . import lift as _lift_mod, psvec as _psvec
        ins_, labels_ = [], {}
        for ln in fn.asm:
            t = ln.strip()
            if t.startswith(".L_") and t.endswith(":"):
                labels_[t[:-1]] = len(ins_); continue
            m = _lift_mod.LINE_RE.match(t)
            if m:
                ins_.append((m.group(1), [a.strip() for a in m.group(2).split(",")] if m.group(2) else []))
        kernels_ = _psvec.kernels(ins_, labels_)
        if kernels_:
            lines_ = []
            for anchor, kind, operands, consumed in kernels_:
                first = min(consumed)
                lines_.append(f"- instructions {first}-{anchor} (0x{first * 4:X}-0x{anchor * 4:X}): `psvec_{kind}({', '.join(operands)})`"
                              " with each `off(rN)` written as the vector's address")
            parts.append("\n## Paired-single kernels in the retail code\n"
                         "These `psq_l`/`psq_st`/`ps_*` groups come from the inline-assembly helpers in `include/psvec.h`. "
                         "Write `#include \"psvec.h\"` and call the helper named here (arguments are `void *` addresses such as "
                         "`&v->x`, scalars are `f32`; `psvec_set` takes (dst, z, y, x)). Scalar per-component C and "
                         "`__vec2x32float__` can never match these bytes.\n" + "\n".join(lines_))
    except Exception:
        pass

    callers = project.callers(symbol)
    if callers:
        parts.append(f"\n## Callers: {', '.join(f'`{c}`' for c in callers)}")

    # Matched C in the same module: first the siblings that share callees and globals with this
    # function (their declaration style is what the compiler wanted), then the nearest by address.
    matched_units = [u for u in project.load_units()
                     if u["module"] == module and u["status"] == "matching" and not u.get('data') and u["source"] != unit_src]
    asm_index = project.function_asm(module)
    my_refs = set(fn.refs)
    def overlap(u):
        f2 = asm_index.get(u["symbols"][0])
        return len(my_refs & set(f2.refs)) if f2 else 0
    by_overlap = sorted((u for u in matched_units if overlap(u) >= 2), key=lambda u: -overlap(u))[:2]
    by_addr = sorted(matched_units, key=lambda u: abs((project.find_symbol(u["symbols"][0], module) or sym).addr - sym.addr))
    chosen, seen_src = [], set()
    for u in by_overlap + by_addr:
        if u["source"] not in seen_src and len(chosen) < 3:
            chosen.append(u); seen_src.add(u["source"])
    neigh: List[str] = []
    for u in chosen:
        body = tufile.unit_text(project, u)
        if body and len(body) < 2500:
            label = f"src/{u['tu']}#{u['symbols'][0]}" if u.get("tu") else f"src/{u['source']}"
            shared = sorted(my_refs & set((asm_index.get(u["symbols"][0]).refs if asm_index.get(u["symbols"][0]) else [])))
            note = f"  (shares {', '.join(f'`{r}`' for r in shared[:6])}: declare and call these the same way)" if len(shared) >= 2 else ""
            neigh.append(f"### {label}{note}\n```c\n{body}\n```")
    if neigh:
        parts.append("\n## Matched code in this module (siblings sharing symbols first; copy their declaration style)")
        parts.extend(neigh)

    if unit_src and not supplied_source:
        work = project.work_path(project.key(sym))
        cur = work.read_text() if work.exists() else (tufile.unit_text(project, unit_cfg) if unit_cfg else "")
        if cur.strip():
            parts.append(f"\n## Current unit\n```c\n{cur}\n```")

    if ledger and not supplied_source and not (row and (row["claimed_by"] or "").startswith("shadow-")):
        # The best saved body that exists here: restored upstream rows name absent files.
        att = next((a for a in ledger.db.execute(
            "SELECT * FROM attempts WHERE symbol=? AND ended IS NOT NULL AND best_body_path IS NOT NULL "
            "ORDER BY MAX(COALESCE(final_percent,0), COALESCE(best_in_attempt,0)) DESC, id DESC",
            (symbol,)) if Path(a["best_body_path"]).exists()), None)
        if att:
            body = Path(att["best_body_path"]).read_text()
            score = max(att['final_percent'] or 0, att['best_in_attempt'] or 0)
            parts.append(f"\n## Best prior attempt ({score:.1f}%, notes: {att['notes'] or '-'})\n```c\n{body}\n```")
            # the plateau itself: which rows still differ and what kind of difference they are, so the
            # next attempt changes their cause instead of resubmitting the same body
            try:
                from . import oracle, stuck
                saved = Path(att["best_body_path"]).with_suffix('.json')
                seed = json.loads(saved.read_text()) if saved.exists() else {}
                res = oracle.check(project, symbol, 0, source=Path(att["best_body_path"]),
                                   mw_version=seed.get('mw'), extra_cflags=seed.get('flags'))
                if res.ok and not res.matched:
                    lrows, rrows = getattr(res, "_rows", ([], []))
                    counts = stuck.classify_rows(lrows, rrows)
                    mode = stuck._pure(counts, lrows, rrows)
                    accepted = getattr(res, '_accepted_rows', set())
                    mine = stuck.own_rows(lrows, rrows, accepted)
                    skip = set(mine['layout']) | set(accepted)
                    diffs = [(i, stuck._fmt(a), stuck._fmt(b)) for i, (a, b) in enumerate(zip(lrows, rrows))
                             if i not in skip and ((a.get("diff_kind") or "DIFF_NONE") != "DIFF_NONE" or (b.get("diff_kind") or "DIFF_NONE") != "DIFF_NONE")]
                    kinds = ", ".join(f"{k} {v}" for k, v in mine['kinds'].items()) or 'none'
                    lines = [f"{i:4d}  {t:38s} | {o}" for i, t, o in diffs[:24]]
                    layout = (f" {len(mine['layout'])} more rows differ only by section/pool layout: the tooling repairs those "
                              "mechanically once these match, so they are not shown and not yours to fix.") if mine['layout'] else ''
                    parts.append(f"\n### Why it plateaued: {mode} ({kinds}); {len(diffs)} rows are the real residual (target | prior attempt).{layout}\n```\n"
                                 + "\n".join(lines) + ("\n..." if len(diffs) > 24 else "") + "\n```")
                    try:
                        marker = json.loads(Path(str(att["best_body_path"]) + '.searched.json').read_text())
                        parts.append(f"The deterministic search already compiled {marker.get('tried')} variants of this body "
                                     "(declaration order, type and sign flips, optimizer pragmas, pool and section priming, compiler "
                                     "responses) without closing it. Do not spend checks on those permutations: change the structure "
                                     "that produces the rows above (expression shape, a held or removed local, an inlined helper, control flow).")
                    except (OSError, ValueError):
                        pass
                    tried = _tried_edits(project.key(sym))
                    if tried:
                        parts.append("\n### Edits already tried on this function (do not repeat them)\n```diff\n" + "\n".join(tried) + "\n```")
                    tips = [t for k, t in MODE_TIPS.items() if k in mode or k in counts or any(k in x for x in counts)]
                    if tips:
                        parts.append("What usually causes this kind of row, from functions that went on to match:\n- " + "\n- ".join(dict.fromkeys(tips)))
                    try:
                        from . import exemplars as _ex
                        for e in _ex.nearest(mode, {k: v for k, v in counts.items() if ":" not in k}):
                            parts.append(f"\n### Exemplar: `{e['symbol']}` went from {e.get('from') or 0:.0f}% to a match ({e.get('mode')}) with this edit\n```diff\n" + "\n".join(e["diff"]) + "\n```")
                    except Exception:
                        pass
            except Exception:
                pass

    # the lifter's draft: a mechanical translation of the disassembly, structurally right by
    # construction (calls, layouts, loops), shown with the rows it still misses so the agent
    # starts from it instead of from nothing
    if ledger and row and not supplied_source and row["status"] != "matched" and not (row["claimed_by"] or "").startswith("shadow-"):
        try:
            from . import lift as _lift, oracle as _oracle
            variants = _lift.lift_variants(project, module, symbol)
            tgt = project.target_object_for(sym)
            best = None
            if variants and tgt:
                ddir = STATE_DIR / "lift" / "ctx"; ddir.mkdir(parents=True, exist_ok=True)
                srcs = []
                for vi, vt in enumerate(variants):
                    f = ddir / f"{project.key(sym).replace(':', '__')}_{vi}.c"; f.write_text(vt); srcs.append(f)
                for ver, ex in _oracle.version_candidates(project, module):
                    objs = _oracle.compile_many(project, module, srcs, ddir / "obj" / (ver.replace("/", "_") + ("_stmw" if ex else "")), ver, ex)
                    for vt, f in zip(variants, srcs):
                        o = objs.get(f)
                        rows = _oracle.function_rows(project, symbol, tgt, o) if o else None
                        if rows and (best is None or rows[2] > best[0]):
                            best = (rows[2], vt, rows)
            if best:
                pct, vt, (lr, rr, _) = best
                diffs = [(i, stuck._fmt(a), stuck._fmt(b)) for i, (a, b) in enumerate(zip(lr, rr)) if (a.get("diff_kind") or "DIFF_NONE") != "DIFF_NONE" or (b.get("diff_kind") or "DIFF_NONE") != "DIFF_NONE"]
                lines = [f"{i:4d}  {t:38s} | {o}" for i, t, o in diffs[:20]]
                if pct >= 60:
                    head = (f"\n## Mechanical draft ({pct:.1f}%): lifted from the disassembly, verified to this score\n"
                            "Its calls, layouts, locals and loops are inferred and may need correction. The rows below\n"
                            "show target | draft; use them to decide what to keep and what to repair.\n")
                else:
                    head = (f"\n## Mechanical draft ({pct:.1f}%, low): lifted from the disassembly; the shape is off but the\n"
                            "declarations and call prototypes are also hypotheses. Check them against the disassembly\n"
                            "before repairing the control flow and expressions (first differing rows below).\n")
                parts.append(head + "```c\n" + vt + "\n```\n"
                             + ("```\n" + "\n".join(lines) + ("\n..." if len(diffs) > 20 else "") + "\n```" if diffs else ""))
            else:
                # no full draft: the never-give-up draft (unknown instructions marked `???`) when it
                # compiles, with the first row where it diverges from retail; else the skeleton
                total = _lift.lift_total(project, module, symbol)
                shown_total = False
                if total and tgt:
                    try:
                        from . import fixup_evidence as _repair
                        tdir = STATE_DIR / "lift" / "ctx"; tdir.mkdir(parents=True, exist_ok=True)
                        tf = tdir / f"{project.key(sym).replace(':', '__')}_total.c"; tf.write_text(total)
                        mw_, extra_ = _oracle.version_for(project, sym, tf)
                        to = tdir / "obj" / (tf.stem + ".o"); to.parent.mkdir(parents=True, exist_ok=True)
                        cp_ = _oracle.compile_source(project, module, tf, to, mw_, ((extra_ + " ") if extra_ else "") + "-g")
                        if cp_.returncode == 0 and to.exists():
                            tw_ = _oracle.words(tgt, symbol); ow_ = _oracle.words(to, symbol)
                            aligned = _spell_fitness(tw_, ow_) if tw_ and ow_ else 0.0
                            div = _repair.first_divergence(project, sym, tgt, to)
                            where = f"first divergence at row {div[0]} of {div[2]}, produced by line {div[1]} of the draft" if div and div[1] else ("no divergence found" if div is None else f"first divergence at row {div[0]}")
                            markers = total.count("/* ???")
                            parts.append(f"\n## Mechanical draft, complete but unverified ({aligned:.0f}% of retail words align; {markers} instruction(s) marked `???`)\n"
                                         "Every call, struct layout, loop and branch below is taken from the retail code; instructions the\n"
                                         "lifter could not express are left as `/* ??? mnemonic */` with an `unk_N` local for their result.\n"
                                         f"{where} (line numbers count from the first line of the code block). Start from this text and\n"
                                         "repair it with patch_unit: fix the `???` spots and the first divergence first, then re-check.\n```c\n" + total + "\n```")
                            shown_total = True
                    except Exception:
                        shown_total = False
                sk = None if shown_total else _lift.skeleton(project, module, symbol)
                if sk and "NOT LIFTED" in sk:
                    parts.append("\n## Mechanical skeleton (unverified): what the lifter recovered before it gave up\n"
                                 "Declarations, struct layouts, call prototypes with argument shapes, locals and the leading\n"
                                 "statements are taken from the retail code; the `NOT LIFTED` marker says where it stopped.\n"
                                 "Keep its declarations and layouts, write the rest of the body from the disassembly.\n```c\n" + sk + "\n```")
        except Exception:
            pass

    if IDIOMS.exists():
        parts.append("\n## MWCC idioms\n" + IDIOMS.read_text().strip())
    if RULES.exists():
        rules = RULES.read_text()
        parts.append("\n## Rules (excerpt)\n" + rules[: 1800].strip())

    text = "\n".join(parts)
    # Bound examples/history/idioms, never the assembly or its declarations.
    limit = required_chars + budget_tokens * 4
    if len(text) > limit:
        text = text[:limit] + "\n\n[context truncated to budget]"
    return text
