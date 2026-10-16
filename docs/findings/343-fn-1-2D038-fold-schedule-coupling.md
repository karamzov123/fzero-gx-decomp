# 343 — fn_1_2D038: the one-word fold is schedule-coupled; statement separation gets the register form but the addi hoists two slots

Session of 2026-10-16 (opencode/deepseek session, agent `deepseek-opencode`).
Follow-up to 286 (which named this function's word) and 299 (pragma axis
closed) after the 4ad73314 fn_17_7728 closure reopened the question: a
one-word address-mode residual *was* closed two days earlier, by the
retail-BSS-object layout technique. This records what that technique does and
does not do on fn_1_2D038, so it is not re-derived.

## The residual, exactly (unchanged, 315 words, differing word index [65])

    w61  lbz  r0, 0x1634(r31)      | same
    w62  cmplwi r0, 0              | same
    w63  bne  0x11c                | same
    w64  addi r3, r31, 0x30        | same          <- both materialize r3 for the call
    w65  lbz  r0, 0x5(r3)          | lbz r0, 0x35(r31)   <- retail reaches through r3
    w66  cmplwi r0, 2              | same
    w67  bne  0x1a0                | same
    w68  bl   fn_1_F22D4           | same (r3 = the pointer)

Base body already carries `#pragma opt_propagation off` +
`opt_dead_assignments off` for the function, and the comma form
`(hdr.value = &p_bss->unk_30, hdr.value->unk_5 == 2) && fn_1_F22D4(hdr.value)`.
Both compiles materialize the addi; only the load's addressing mode differs.

## The free probe (reusable; this is the session's method contribution)

The ledger `check` was tripped by the plateau guard after 5 non-improving
checks, and every `write_unit` consumes one. Candidate shapes can instead be
measured with no ledger interaction: `oracle.compile_source` with the unit's
mw/flags into /tmp, then `oracle.words(target_object)` vs `oracle.words(obj)`
and `oracle.word_score`. One shape per ~10 s, exact positional word diff. The
check tool's own `find -s`/pool logic is untouched; the probe only selects
candidates. A working copy of the script lived at `/tmp/opencode/probe.py`
(15 lines; recreate from this description if gone).

## Shapes measured (positional word score; retail = 315 words)

| shape | score | words | what happened |
|---|---:|---:|---|
| base (comma form) | 99.683 | 1 [65] | folded load, otherwise exact |
| plain pointer local, comma form (v3) | 99.683 | 1 | identical object |
| inline helper returning `&bss->unk_30`, no/with pragma (v4, c06a/b/c08) | 99.683 | 1 | helper does not opacity the address |
| assignment-value as base: `(hdr.value = &bss->unk_30)->unk_5` (c12/c16) | 99.683 | 1 | front end collapses it |
| goto-into-true-block restructure (c09/c11) | 99.683 | 1 | re-merged to short-circuit, folded |
| void* / u32 round trips (r01/r02) | 99.683 | 1 | folded |
| **assignment as a statement before the `\|\|` test (c07/v02)** | **99.048** | **3 [62–64]** | **load is `lbz 0,5(r3)` (correct!) but the `addi` schedules into the lbz delay slot, 2 words early** |
| char* `cp[5]` local (v5) | 99.048 | 3 | same hoist |
| two separate `&bss->unk_30` expressions (r03) | 98.730 | 4 | worse |
| private BSS object + `.fzgxpool` primer, `p_bss=&fzgx_obj_...` (u01–u03; the fn_17_7728 recipe applied here) | 99.683 | 1 | **no effect on this word** — the load still folds |
| pointer assigned at function top (v01) | fail shape | 312 | stack frame grew to 0x100 (value live across a call spills) |
| conditional pre-test assignment (t01) | fail shape | 314 | frame 0x100 |
| duplicated true blocks (c10) | 18.97 | 249 | no tail merge, both bodies emitted |

Pragmas on the base body, this function: `opt_common_subs off` 98.730 (harmful
elsewhere in the function), `peephole off` catastrophic, `opt_lifetimes off`
and `opt_strength_reduction off` no change. Consistent with 299; not re-swept.

## What this means

- The fold is **not** address provenance (values vs constants, symbols vs
  interiors, casts, helpers all fold) and **not** pragma-reachable (299, again).
- The one shape that yields the register form is **statement separation**: the
  assignment in a different basic block from the load. MWCC's local
  copy-propagation is what folds; a block boundary makes the load reference a
  value web. But the value's definition then executes *where the statement is*
  — before the `lbz`/`cmplwi`/`bne` — and the list scheduler happily fills the
  load's delay slot with it, costing two words instead of one.
- The remaining gap is therefore **the addi's schedule slot**, not the load's
  addressing mode. No source placement puts a rematerializable address
  definition *after* a conditional branch while keeping its first use in the
  following block — every attempt either hoists the definition or re-merges the
  control flow and re-folds (goto-form, c09).
- The fn_17_7728 close does not transfer as its recipe read: applied to the
  relevant symbol here (u01–u03) it changed nothing. Its load was through a
  *pointer variable materialized at function top and used many times*, not an
  interior `&struct->member` computed at the call site — that difference is
  the untested part of the recipe, and v01 shows the top-assignment form does
  not survive the intervening call in this function (spill changes the frame).

## Cost/traps recorded

- Each `write_unit` **and** each `check` consumes an attempt check; the
  plateau guard trips at 5 non-improving checks, and a tripped attempt refuses
  further `write_unit`s before even writing the file. Probe shapes locally
  first; spend ledger checks only on a 100% candidate.
- The 286 hypothesis ("hoist the check, call it, branch on the result") was
  tested literally (c09/c10): the goto form re-merges; the duplicated-block
  form loses tail merging and inflates the object. The register form arrives
  only via plain statement separation.
- fn_1_2D038 released to the ledger at 99.68% best with this record. If it is
  ever revisited, the only unexplored lever left is the pointer-variable
  materialized across the whole function without spilling (v01 with the call
  removed between definition and use, or the fn_17_7728 full-TU layout
  rewrite), or the asm-unit path.
