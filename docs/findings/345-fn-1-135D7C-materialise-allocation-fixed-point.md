# 345 — fn_1_135D7C: the conversion residual is coupled to address materialisation; the all-inline wide shape materialises + `mr` but permutes the two scratch registers

Session of 2026-10-16 (opencode/deepseek session, agent `deepseek-opencode`).
Follow-up to 286 (which named this function's single word), 304 (which classified
it as a type-reconstruction defect) and 343 (the same fold-vs-materialise
coupling measured on `fn_1_2D038`). This records the closure campaign: three
reachable fixed points, ~160 measured source shapes, and cross-corpus proof that
the materialise-vs-fold choice is a selector decision source text does not steer
in this context. **The function stays unmatched (not blocked); do not re-derive
the measured shapes below.**

## The residual, exactly (254 words, differing word index [185])

    w181 lis  r4, lbl_1_rodata_8960@ha   | same
    w182 lis  r5, lbl_1_data_41A30@ha    | same
    w183 addi r6, r4, 8960@l             | (s8 world: same; s32 world: absent, @l folds)
    w184 lfs  f0, 0(r6)                  | (s32 world: `lfs f0, 8960@l(r4)`)
    w185 mr   r4, r3                     | extsb r4, r3   <- the named residual
    w186 addi r3, r5, 41A30@l            | same
    w187 fmuls f1, f0, f29               | same
    w188 crset cr1eq                     | same
    w189 bl   fn_1_4CF3C                 | same

`fn_1_14FEAC` itself decides the type: its only write to `r23` is `mr r23, r6`
(its 4th argument) with `mr r3, r23; blr` epilogue, so the caller-visible value
is 32-bit and no extension is needed. The saved best body's `extern s8
fn_1_14FEAC(...)` is stale; retail's source value was wide. This refines 304:
the correct type change alone does **not** close the function — it lands on a
different one-word fixed point (fold instead of materialise).

## The three reachable fixed points (positional word diff, all measured)

| shape | words | differing | note |
|---|---:|---|---|
| narrow return: `s8` (saved best) | 254 | 1 [185] | materialise + **retail-correct scratch allocation**; bad type |
| narrow: `s16` / `u8` / open prototype | 254 | 1 [185] | `extsh` / `clrlwi` / `extsb` respectively |
| wide return: `s32`/`u32`/`int`/`void*`/named `f32`, statement form | 253 | 1 [183:185) | **fold**: `lfs @l(r4)`, no `addi`; `mr` correct |
| wide return, FEAC call inlined into the argument list | 254 | 4 | materialise + `mr` both correct, but `{pool temp, format base}` permute: ours `lis r6(D@ha); addi r5, r4(P@l)` vs retail `lis r5(D@ha); addi r6, r4(P@l)` |
| narrow + all-inline | 254 | 5 | permutation + `extsb` |

The two correct halves live in different fixed points: the narrow world gets the
allocation right and the instruction wrong; the all-inline wide world gets the
instructions right and the allocation wrong; the statement-form wide world folds
the address away.

## Shapes measured (all positionally word-scored; ~160 compiles, sweeps 8–20)

None of the following moved either the fold/materialise choice in the wide
statement world or the `{r5,r6}` permutation in the all-inline world:

- expression texts: `*(const f32 *)&sym`, direct scalar `extern f32`, `p[i]`
  indexing, deref forms, `u8*`/`char*`/`void*` casts, `+0` address arithmetic,
  parenthesisation variants;
- `fn_1_14FEAC` prototype: `s8/s16/u8/u32/s32/int/void*`, `(u32)/(s32)/(void*)`
  casts at the call, comma-operator wrappers (comma forces the fold back);
- local structure: keep/remove/reorder `t18`/`lab_t2`, dead-`v14`
  remove/first/end/swap, extra dummy local, parameter-through-local (`s = arg7`);
- statement structure: statement form, inline-pool form, all-inline form,
  lab-before-inline, source-order swap of the FEAC/pool arguments;
- inlined helpers mirroring `fn_1_13DDB8`'s `operand(left, right)` (pool on the
  left, matching retail's `fmuls f1, f0, f29` operand order), identity helper,
  pointer/value helpers — the helper forms fold like the statement form;
- pragma cells (`opt_lifetimes`, `opt_propagation`, `opt_loop_invariants`,
  `scheduling`, `peephole`, `opt_dead_assignments`, `opt_strength_reduction`,
  `opt_common_subs`) around the statement and as resets before the function;
- the private pool object + `.fzgxpool` primer recipe (the `fn_1_53E40`
  technique, finding 344): no effect on this word;
- comma-assignment forms inside the argument list spill (256–257 words).

Pragma resets before the function *do* reach it (a `opt_propagation reset`
flips `mullw` operand order at w48), so the cells were genuinely exercised; they
do not move this word.

## Cross-corpus: materialise-vs-fold is context-dependent in retail itself

Reloc-aware scan of all 3229 retail per-function objects under
`build/GFZE01/main_rel/obj` (relocations, since immediates are zeroed; kind6
`@ha` on `lis`, kind4 `@l` on `addi` or directly on the load):

- folded float symbol reads (`lfs`/`lfd` carrying `@l` directly): **1405**
- materialised symbol loads (`lis @ha; addi @l; load 0(temp)`) of any width:
  **568**, of which float (`lfs`/`lfd`): **6**

So the form retail uses here is rare but real. Two matched functions show the
selector deciding it context-sensitively inside a single function:

- `fn_1_13DDB8` (matched, `2c8a17d4`, **same TU**, `sel_static_disp.c:3057`):
  twelve symbol reads in one function. The `s = lbl_1_rodata_863C + f;`,
  `t = lbl_1_rodata_880C * s;` and helper-operand `lbl_1_rodata_85F0` reads
  materialise; the same basic block's `p.field_2C = lbl_1_rodata_87B4;` read
  folds — and `lbl_1_rodata_87B4` folds at *both* of its sites while adjacent
  symbols materialise. Same compiler, same pragmas, same symbol kind.
- `fn_1_FDC00` (matched, `d4ce9e3f`, `bg_cas.c:1092`): the expression
  `lbl_1_rodata_761C[0]` (`extern f32 lbl_1_rodata_761C[13];`) appears at four
  call sites; retail folds it at 0x88/0xa0/0xb8 and materialises it at 0xe0 —
  where the emitted form is one instruction **longer** than the fold (5 vs 4).
  It is a genuine lowering decision, not a size optimisation.

Conclusion: the retail form is selected by downstream context (schedule/allocator
state), not by a source idiom we can spell. In this function's context, every
widening that removes `extsb` moves the address lowering to the fold point, and
the only shape that forces materialisation moves the scratch allocation.

## Stopping condition

The campaign stopped under AGENTS.md's coalition rule: sweeps 8–20 produced
zero closures and zero score improvements after the three fixed points were
identified; the same class is already documented as a wall for `fn_1_2D038`
(finding 343). The saved best remains
`.fzgx/attempts/fn_1_135D7C.1791782307.c` (attempt 23975, agent `pin-scan`,
99.61%, verified 254 words / differing `[185]` this session). The function is
left `unmatched` and claimable — the project blocks only unsupported-credit
cases (`blocked=3` in the ledger), and `fn_1_2D038` set the precedent.

If ever revisited, closure needs a tool that can steer *instruction selection*
(not just register fields): a `fixup --capture`-style replay of the allocator
that also commits the materialise/fold decision, a new pragma axis, or an
unmeasured source shape. Do not re-run the measured families above.

## Method note (recreatable)

The two corpus scans are ~40-line scripts: parse each ELF with
`fzgx.poolfix.Elf`, decode `.text` with capstone, read `.rela.text` entries
(`>IIi`; `off &= ~3` for kinds 4/5/6/109 via `poolfix.code_reloc_offset`), then
match (a) kind4 directly on an `lfs`/`lfd` (= folded) or (b) kind6 on `lis` +
kind4 on a following `addi` whose destination is the load's base with
displacement 0 (= materialised). A copy lived at `/tmp/opencode/scan_poolread.py`.
Offline candidate probing used `/tmp/opencode/probe.py` and the sweep drivers
`/tmp/opencode/sweep*.py` (finding 343's free-probe method; no ledger checks).
