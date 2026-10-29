# fn_1_BD54 (camera): camera update — decoded end to end, best body 62.5%

588 B, 147 instructions, `main_rel/rel/main_rel/camera`, compiler GC/1.3.2 with no
extra command-line flags. No fleet settings were changed; the function is not
matched and no canonical gameplay source was submitted. This session decoded the
whole body from the retail object and measured new spellings against the best
saved attempt.

## Best known body: 62.5%

A body saved in an earlier session (`fn_1_BD54.1792967008`, 62.5% raw) is better
than anything produced this session, and the decode below confirms it is
structurally right. Resume from that file rather than from scratch: its typed
`StateBD`/`CamBD` view, the `psvec_set` translate, and the inline `smooth()` /
`blend_delta()` helpers all match the retail instruction stream.

The bodies this session rebuilt independently reached 44.3 → 51.0 (after finding
`psvec_set`) → 56.1 (`fp_contract off`, one `.bss` section base, look-target
vector corrected) → 56.2 (translate components as live locals). Those numbers are
only useful as a record of which structural facts each one pinned down; the
62.5% body already had them.

## What the function does

1. `lbl_1_bss_1010 += 0.02 * (f64)(s8)lbl_1_bss_A48.unk_2` — the `0x4330` /
   `xoris 0x8000` signed int-to-double bias, `fmul`, `fadd`, `frsp`.
   `lbl_1_data_4068 += (s8)unk_3 << 1` (retail `slwi r0,r3,1`), then
   `mathutil_mtxA_rotate_x((s16)lbl_1_data_4068)`.
2. `flags = fn_1_10780C(&frame28, &frame1c, &frame10, &frame0c)`, then
   `fn_80008C20(&frame28, &frame1c, &frame10)` — same three vectors, same order.
3. `andis. r0,r30,0x140` + `clrlwi. r0,r30,31`, i.e.
   `if ((flags & 0x01400000) && !(flags & 1))` selects
   `lbl_8006E0B4(angle, frame0c, 60.0f)`, else `lbl_8006E0B4(angle, 15.0f, 60.0f)`.
   The second argument in the taken branch is the loaded fourth output, not a
   constant.
4. `psvec_set(&t, mtxZ, mtxY, mtxX)` — see below — then a six-component lerp of
   `state+8+4 .. +0x18` toward that translate (the `eye` triple, also written to
   the locked-cache translation `0xC/0x1C/0x2C`) and toward the first call output
   at frame `0x28` (the `at` triple). Each component is
   `old + 0.1 * (target - old)`: `fsubs` for the difference, `fmul`/`fadd` in
   double, `frsp` before each `stfs`.
5. `fn_8006FB20(...)`, `lbl_8006DB74(state+0x4C)`,
   `fn_8006F3E4(&s16_08, &s16_0A, state+0x28)`, `lbl_8006DF44()`,
   `lbl_8006DB74(state+0x7C)`. The two `lbl_8006DB74` arguments are `0x30` apart:
   two `Mtx` (3x4) members.

## The opcode-4 words are `psvec_set`

`0x13BDF420` and `0xF3A10034` decode as garbage under a plain capstone pass. With
the A-form fields from `tools/fzgx/mwconstraints.py` (frD 21-25, frA 16-20,
frC 11-15, frB 6-10, extended opcode 1-5) they are:

    0000BE7C  13BDF420  ps_merge00 f29, f29, f30     ; bits 10..1 = 528
    0000BE90  F3A10034  psq_st f29, 0x34(r1), 0, qr0
    0000BECC  F3A1003C  stfs f31, 0x3c(r1)

with `f29/f30/f31` loaded from the locked cache at `0xC/0x1C/0x2C`. That is
`psvec_set(&t, mtxZ, mtxY, mtxX)` from `include/psvec.h`: the matrix translation
`{mtxX[3], mtxY[3], mtxZ[3]}` built on the stack. It is also the reason the
prologue saves three FPR pairs — the triple stays live across the lerp.

The other quoted paired-single words (`0xF3E10088`, `0xE3E10088`, …) are the
standard `stfd` + `psq_st` double-save/restore of an FPR, which matched camera
functions (`fn_1_1212C`, `fn_1_C770`) carry identically; no other paired-single
instruction appears in the body.

## Pool constants (read from the decoded retail data)

    lbl_1_rodata_400 + 0x68  f64 0.1                      (the lerp factor)
    lbl_1_rodata_400 + 0x80  f64 4503601774854144.0       (compiler int->double bias)
    lbl_1_rodata_400 + 0x88  f64 0.02                     (the angle step)
    lbl_1_rodata_400 + 0x90  f32 60.0                     (two loads)
    lbl_1_rodata_400 + 0x94  f32 15.0
    lbl_1_rodata_400 + 0x98  f32 0.9

`+0x98` explains the load at `0x184` that looks dead in a linear scan: it is
`fn_8006FB20`'s float argument, hoisted well before the call. Dropping the
pointer argument and passing only `0.9f` measures **61.6%**, below the 62.5%
baseline, so the matrix pointer in the saved body is carrying rows elsewhere.

## Residual: 62.5%, register and schedule only

    regalloc 48, ins 41, imm 14, frame 11, op 11

Retail holds the translate triple in `f29/f30/f31` (x, y, z ascending) and keeps
frame `0x90` with all three saved. Every spelling measured here — inline locked
cache loads, three live locals, `opt_lifetimes off`, `fp_contract` on and off —
leaves the merge pair in `f30/f31` and the third value in a volatile register, so
the frame stays `0x80` and the `0x28..0x3c` stack offsets shift with it. This is
the same `psvec_set` register-binding limit recorded for `fn_1_9FA18`
(findings 317): the header's parameter order fixes the registers the asm operands
take, and no argument or liveness spelling measured so far reproduces retail's
arrangement. The structure is decoded end to end, so only that binding remains.

Resume from `.fzgx/attempts/fn_1_BD54.1792967008.c` (62.5%; the sibling `.json`
records the measured percent of each saved attempt) with GC/1.3.2.
