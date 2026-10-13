# fn_1_9FA18 (ptclput): z-liveness fix unblocks the previously-typo'd edit; 99.7% with 8 regalloc rows

Selected a carved-but-never-written unit (1116 B, `main_rel/rel/main_rel/ptclput`). A prior session
reached 99.749% with 8 differing rows and logged 15,228 searched variants. No claims remained; no
fleet settings were changed and no canonical gameplay source was submitted. Only `.fzgx` state and
the unit body were touched.

## The edit the search engine never actually measured

The prior attempt's "edits already tried" log contains this entry, marked `did not compile`:

    fzgx_z = cur[11];
    psvec_set(&v.x, fzgx_z, cur[7], (*((cur) + (3)));   <- missing closing paren
    len = lbl_8006D0B4((f32)(v.x * v.x) + v.y * v.y + fzgx_z * fzgx_z);

The missing `)` meant the intended transform was never evaluated. Corrected and measured, it is
the key structural change: the z component must be a **live local** rather than a read-back of
`v.z` after `psvec_set`.

Retail's tail (verified by disassembling the retail object directly):

    0009FD8C: lfs f27, 0xc(r28)      ; x
    0009FD90: lfs f28, 0x1c(r28)      ; y
    0009FD94: lfs f0, 0x2c(r28)       ; z -> f0, loaded before the merge
    0009FD98: ps_merge00 f27, f27, f28
    0009FD9C: stfs f0, 0x10(r1)       ; z stored to the stack by psvec_set
    0009FDA0: psq_st f27, 0x8(r1), 0, qr0
    0009FDA4: lfs f1, 0x8(r1)         ; x read back
    0009FDA8: lfs f2, 0xc(r1)         ; y read back
    0009FDAC: fmuls f1, f1, f1
    0009FDB0: fmadds f1, f2, f2, f1
    0009FDB4: fmadds f1, f0, f0, f1   ; f0 (z) still live -- no reload

The old body did `fzgx_live = v.z;` after `psvec_set`, which forces a reload of z from the struct
into a different register. Holding z in a local (`fzgx_z`) lets the value stay in its register, and
the length expression then uses `fzgx_z * fzgx_z` instead of `v.z * v.z`.

Declaring `fzgx_z` as the **first** float local (before `fzgx_live_`/`fzgx_live`) additionally moved
z from f2 toward f1 and eliminated one differing row (the y read-back now agrees).

## Residual: a stable register permutation, 8 rows

    037C  lfs f0, 0x2c(r28)   | lfs f1, 0x2c(r28)     (z: retail f0, ours f1)
    0384  stfs f0, 0x10(r1)   | stfs f1, 0x10(r1)
    038C  lfs f1, 0x8(r1)     | lfs f0, 0x8(r1)       (x: retail f1, ours f0)
    0394  fmuls f1, f1, f1    | fmuls f0, f0, f0
    0398  fmadds f1, f2, f2, f1 | fmadds f0, f2, f2, f0
    039C  fmadds f1, f0, f0, f1 | fmadds f1, f1, f1, f0
    03BC  fsubs f0, f29, f26  | fsubs f1, f29, f26
    03C0  fdivs f1, f0, f29   | fdivs f2, f1, f29

All 8 rows are `regalloc`. Retail assigns z->f0, x->f1, y->f2; ours assigns z->f1, x->f0, y->f2.
The `fsubs`/`fdivs` rows now match structurally (same operands, different registers), confirming
the liveness fix is correct and only the colouring differs.

Probed offline with real GC/1.3.2 and the unit's exact argv. The z register is bound by the
`psvec_set` inline-asm parameter order (`ps_merge00 x, x, y` then `stfs z`), so z consistently
lands in the last asm-bound register regardless of source order. Getting x/y into f27/f28 (retail's
high registers) is reproducible with the calls placed before the loads, but z still does not reach
f0. Retail's arrangement requires the merge to occupy f27/f28 *and* z to take f0 simultaneously,
which our `psvec_set` spelling does not produce. This is the documented base/first-use register
wall (`docs/REGISTER_REPAIR.md`); a new transform is needed, not a source rewrite.

The corrected body is at `.fzgx/attempts/fn_1_9FA18.best.c`
(SHA-256 `0f7917323295d5f70972bda681c6d0a88d66c331a373e51748b02972bd7c7660`), 99.749% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_1_9FA18.best.c`, compiler GC/1.3.2, no extra
command-line flags.
