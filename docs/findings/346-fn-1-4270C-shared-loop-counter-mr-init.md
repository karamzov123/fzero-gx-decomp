# 346 — fn_1_4270C landed: the `li rX, 0; mr rY, rX` loop-offset init is selected by *sharing the loop counter across loops*

Session of 2026-10-16 (opencode/deepseek session, agent `deepseek-opencode`).
Closes the 99.5851% one-word plateau of `fn_1_4270C` (word 205 of 241:
retail `mr r30, r29` after `li r29, 0`; ours folded to `li r30, 0`).
Landed in commit `ce2e3eb4` (claim attempt 31, `--max-attempts 50`, one check;
`write-unit` → 100.0% `MATCH`; `verify` fast path; 16 files OK; lint 0).

## The residual

The function's second outer loop walks `Fn14270CEntry` records (stride 396).
Retail initializes the running bytes-offset register with a *copy* of the
counter's register:

    w203 blt  .L_<first-loop body>      (exit of the first outer loop)
    w204 li   r29, 0                    (counter = 0)
    w205 mr   r30, r29   <- residual    (running offset = counter)
    w206 b    .L_<second-loop test>

Our saved best body (explicit offset local, fresh counter: `v30 = 0;
v31.value = 0;`) and every straight copy spelling (`v31.value = v30;`,
casts, casts through helpers) fold the copy via constant propagation and
emit `li r30, 0` instead.

## What was measured and rejected (offline probes, no checks spent)

| shape | words | differing |
|---|---|---|
| baseline (fresh `v30` counter + explicit `v31.value` offset) | 241 | 1 [205] `li r30, 0` |
| `v31.value = v30;` copy, `(u32)v30`, signedness flips | 241 | 1 [205] — all fold |
| union pun / `*(u32 *)&v30` pointer pun | 243 | 43 / 218 — allocation collapses |
| inline identity helper `copy(v30)` | 241 | 1 [205] — folds |
| `#pragma opt_propagation off` (function-wide) | 249 | 179 — unusable |
| `#pragma opt_lifetimes off` (before or mid-function) | 241 | 1 [205] — no effect |
| mid-function `#pragma opt_propagation off` / `opt_lifetimes off` | 241 | 1 [205] — **inert**: pragma state is captured per function at parse start |
| fresh counter `v30` + multiply addressing `v33 = v32 + v30 * 396` | 241 | 1 [205] — multiply strength-reduces identically, but **init still folds** |
| shared counter `v6` + multiply `v33 = v32 + v6 * 396` | 241 | **0 — MATCH** |
| same, `for`-form / `(u8*)v32 + v6 * 0x18C` / `&((T *)base)[v6]` | 241 | 0 each |
| shared counter `v6` + shared explicit offset `v4` | 241 | 6 — copy appears but the r29/r30 pair is mirrored |

## Corpus evidence: the shape is produced by matched same-TU siblings

A scan of all 2951 retail `main_rel` objects for `li rX, 0` immediately
followed by `or rY, rX, rX` (= `mr`, X-form dest in bits 16–20) found 125
pairs; the `[cond-branch][li][mr][b]` loop-exit shape appears in **matched
functions of the same TU**:

- `fn_1_42E74` (motasglist, matched): three `for` loops share one `s32 i;`
  and use multiply addressing (`(u8 *)entries + i * 0x18c`).
  Loop 1 → `li r29, 0; li r30, 0`; loops **2 and 3** → `li r29, 0; mr r30, r29`.
- `fn_1_41F58` (motasglist, matched): two `for` loops share one `int i;`
  (`data->first_data + i * 0x10`, `data->second_data + i * 0x10`).
  Loop 1 → `li r26, 0; li r27, 0`; loop **2** → `li r26, 0; mr r27, r26`.

Both matched sources compile today with default pragmas and reproduce the
`mr` — the selector decision is real and source-reachable.

## The law

With multiply-addressed loops (`base + i * K` or `base[i]`), MWCC's strength
reduction creates the running bytes-offset shadow and initialises it:

- `li rOffset, 0` when the loop counter variable is **fresh** (first loop of
  the function, or any newly declared counter);
- `mr rOffset, rCounter` when the counter variable is **shared with an earlier
  loop** — the shadow init is then a register copy of the just-zeroed counter.

Both forms are two instructions and otherwise identical; this is not an
allocation accident (fresh + explicit copy texts fold; only counter identity
flips it). This also gives a second, pragma-free instance of the
"copy has its own lifetime" case noted in `docs/MWCC_IDIOMS.md` ("Parameter
above a local"): no pragma is needed when the copy comes from an induction
variable shared across loops.

Fix applied: the second outer loop was rewritten to reuse the first outer
loop's counter (`v6`) with multiply addressing and no explicit offset local:

    v6 = 0;
    while ((u32)v6 < *(u16 *)arg0) {
        v26_2 = *(u32 *)((u8 *)arg0 + 8);
        v32 = v26_2;
        v33 = v32 + v6 * 396;
        ...
        v6++;
    }

Actionable for other one-word tier candidates whose residual is an init copy
(`fn_1_1384C` scan hit shares this shape class): check the same-TU matched
siblings first; prefer reusing the existing counter over a fresh per-loop
counter.

## Addendum (same session): the law's boundary and the fn_1_1384C outcome

The "fresh counter ⇒ `li`" half of the law is measured for the strength-reduced
shadow of a **constant-stride multiply**. It is not universal: `fn_1_152CB4`
(asm, bg_aur) keeps a *first-loop* init copy — w17 `li r30, 0; mr r26, r30`
with a variable-stride accumulator (`add r26, r26, r8`) — so retail's selector
can keep first-loop copies too; the fresh/shared split is one lever among the
downstream materialise-vs-fold decisions, not a rule about all copies.

`fn_1_1384C` cannot use this law at all (the k-loop is nested inside the
tab/j/i loops, so there is no shareable earlier counter) and its explicit
`boff = k` init resisted ~50 further measured shapes (sweeps 25–31: spellings,
pragma cells, CFG joins, declaration orders, all 20 compilers, all `-O` flag
variants). It is now recorded as a selector/allocator fixed point in
finding 347; do not re-run that family there.
