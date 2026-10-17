# 361 — fn_1_156C08: the fn_8006B55C caller view — s16 pays one extsh., s32 flips r30/r31 wholesale

Session of 2026-10-17 (opencode, fn_1_707C closure session). Recorded after ~25
offline compiler probes + a fixup pass + a capture projection all failed to close
the last word, so the next session starts from the measured recipe rather than
re-deriving it.

## The residual (exactly, 101 words, differing word index [73] on the archived s16 body)

    w73  cmpwi r3, 0            | extsh. r0, r3     <- ours sign-extends the call
                                                                  result into r0,
                                                                  retail compares r3
                                                                  raw

The window (words 64-79, identical modulo w73):

    65 lwz r4, 0xc(r31)          ; handle value (== -1 test below)
    66 lwz r3, 4(r31)            ; data pointer -> call arg 1
    67 addis r0, r4, 1           ; handle == -1 idiom (add 0x10000, cmplwi 0xffff)
    68 cmplwi r0, 0xffff
    69 bne 0x156d3c              ; else-call path
    70 addi r4, r31, 0xc         ; &handle -> call arg 2
    71 addi r5, r1, 8            ; &loc_8  -> call arg 3
    72 bl fn_8006B55C            ; (verified via .rela.text: R_PPC_REL24 ->
                                 ;  fn_8006B55C; the other two REL24s are
                                 ;  fn_8006B628 @0x13C and fn_8006B6F8 @0x164)
    73 cmpwi r3, 0 / extsh. r0, r3   <- THE residual
    74 blt 0x156d54
    75 li r30, 1                 ; v13 = 1
    ...

## Facts

- The archived body's local view declares
  `extern s16 fn_8006B55C(Sig_fn_8006B55C_Fn8006B55CData *, u32 *, u8 *);`
  (`s16` return). In C an s16-returning callee's result compared `>= 0` MUST be
  sign-extended first, which is exactly the `extsh.` row ours emits.
- The matched DOL unit `src/dol/fn_8006B55C.c` states the real prototype:
  `s32 fn_8006B55C(Fn8006B55CData *data, u32 arg1, u32 arg2)` and returns raw r3
  (`li r3, -2` / a callee result, no trailing `extsh`/`extsb` before `blr`).
  So retail's caller genuinely compared a wide/int-returning call - the s16 view
  in the REL-side body is a wrongly-recovered annotation, not retail truth.
- No promoted header declares fn_8006B55C anywhere in `include/` (grep: no
  matches), so the unit-local extern is free to carry the s32 view.

## The flip blocking the s32 view

Changing the extern to `s32` makes w73 correct but flips the callee-saved roles
wholesale (21 differing rows, every row the same exchange):

    prologue  retail              ours-s32
    4  stw r31, 0x3c(r1)         stw r31, 0x3c(r1)
    5  mr r31, r3    <- arg0     stw r30, 0x38(r1)
    6  addi r3, r4, 0            mr r30, r3     <- arg0 into r30
    7  stw r30, 0x38(r1)         addi r3, r4, 0
    ...
    50 li r30, 0     (counter)  li r31, 0      <- counter into r31
    75 li r30, 1                 li r31, 1
    83 cmpwi r30, 0              cmpwi r31, 0
    + every r31/r30 base access swapped (9 rows).

So: param copy above the local (r31, per the "params above locals" idiom) is what
MWCC GC/1.3.2 produced for the s16 body but NOT for the s32 body - removing the
`extsh.` web from w73 changes the GRA trace and our compile demotes the param
copy below the counter local (r30) while hoisting the counter to r31.

## What was probed (all offline word_diffs, zero ledger checks)

1. Statement-shape variants of the update/compare block (v1-v16): `%=` vs
   `-= (x/100)*100` forms, named temp locals (cent/mod/e), explicit mod formula,
   swapped statement/decl order, else-if chain, no-table-local form, inline mod
   in the return expression: **none closed; most were worse** (`arg0 % 100`
   inline in the return re-schedules the three divisions completely - 19 rows).
2. Extra unused parameters (s32/u8/f32), if/else-if chain, inner-scope shadow
   decl-init q/m: unchanged (2 rows for fn_800288C4 probes, unchanged here).
3. decl-init of the counter (`s32 v13 = 0;`, first/fifth decl, after negative):
   much worse (61 rows) - the counter's zero gets hoisted into the prologue
   (`li r31, 0` at w5) while retail keeps `li r30, 0` mid-body at w50.
4. Explicit entry-copy local (`e = arg0;` statement first, all uses renamed):
   still flipped (21 rows) - the copy web is colored like a local either way.
5. Inline wrappers W1-W3 (s32/int return, exact and void* arg types) over the
   s16 extern: the extsh is semantically mandatory for an s16-returning callee,
   so the inlined compare still emits `extsh.` - 1 row, unchanged, colors fine.
6. Optimization-level sweep (-O3, -O4, -O4,s, -O4,p on both views): level is not
   the lever (s16: 1 row under every -O4 form; s32: 21 rows; -O3 much worse).
7. Fixup engine (73 generated variants): matches = [].
8. Stock-allocator capture (`fixup --capture` wibo/lldb trace of the s32 body):
   ran (2 baseline order witnesses) but the retail-side projection fails with
   `unsupported-instruction` at retail row 12 (the `lis r5, 0x51ec` magic row) -
   source_projections = 0. Recapture needed once the constraint pipeline learns
   that row shape.

## Repro scripts (recreate freely; colon-free /tmp paths required)

- /tmp/opencode/p156C08.py - baseline s16 repro (1 diff, w73)
- /tmp/opencode/r156C08.py - decl-order sweeps R1-R6 (all 21 rows)
- /tmp/opencode/f156C08.py - decl-init hoists F1-F5 (61 rows, worse)
- /tmp/opencode/e156C08.py - explicit entry copy E1 (21 rows), E2 (compile err)
- /tmp/opencode/w156C08.py - inline wrappers W1-W3 (1 row, extsh persists)
- Corpus for a re-capture: /tmp/opencode/mkcapcor156.py builds
  /tmp/opencode/capcor (s32 body, sha256-pinned) -> capture via
  `fzgx fixup fn_1_156C08 --capture --corpus /tmp/opencode/capcor --output /tmp/opencode/capout`

## Next-session entry points (not tried yet)

- Give the constraint pipeline the retail row-12 shape (lis/addi magic pair)
  support in mwconstraints and re-run the capture projection; the capture itself
  is ~0.6s and reproduced above.
- Break the removed-web symmetry differently: any C change adding a dead-traced
  web *without emitting a row* near the call (e.g. a second decoration of the
  call arguments through a comdat-inlined helper) - W1-W3 prove the extsh row
  itself is what must NOT exist, so the flip must be countered by an
  entry-promotion change that keeps the web count.
- Check whether rel/main_rel ranking.c neighbors that also call fn_8006B55C
  (none found in src/ today) exist in retail's split to copy their caller view.
