.include "macros.inc"
.file "approx_rsqrt.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# f1 = 1/sqrt(f1) by frsqrte and two Newton steps; f2 = 0.5f.
# - This frameless leaf changes only f1-f5.
# - Five frameless routines call it with `bl`: lbl_8006D0B4, lbl_8006D118, lbl_8006D5F0,
#   lbl_8006D6FC and lbl_8006DA50. Across the call, they keep values in f0, f6-f13, r3-r6 and a
#   copy of the link register. The EABI makes these registers volatile. Thus the contract is
#   outside the EABI.
# - C cannot give this body. MWCC always adds `frsp` after `__frsqrte` when the result is a float.
#   Plain C gives 13 words against the 11 retail words on six compilers (measured 2026-11-13).
#   An inline frsqrte kernel gives 11 words, but it puts temporaries in f0. The callers keep f0 live.
# - The Super Monkey Ball retail approx_rsqrt ends in `blr; blr`. C never gives two consecutive `blr`.
# - Source: Super Monkey Ball (same engine) has approx_rsqrt as an asm function:
#   https://github.com/camthesaxman/smb-decomp/blob/5cd6ffccf3f8508231c7cd9cce5b722be4465a2b/src/mathutil.c#L101-L144
#   Its C version is under `#ifndef __MWERKS__`, so the MWCC build uses the asm.

# 0x8006D088..0x8006D0B4 | size: 0x2C
.text
.balign 4

# .text:0x0 | 0x8006D088 | size: 0x2C
.fn approx_rsqrt, global
/* 8006D088 0006A088  EC 82 00 72 */	fmuls f4, f2, f1
/* 8006D08C 0006A08C  EC 62 10 2A */	fadds f3, f2, f2
/* 8006D090 0006A090  FC 20 08 34 */	frsqrte f1, f1
/* 8006D094 0006A094  EC 63 10 2A */	fadds f3, f3, f2
/* 8006D098 0006A098  EC A1 00 72 */	fmuls f5, f1, f1
/* 8006D09C 0006A09C  EC A5 19 3C */	fnmsubs f5, f5, f4, f3
/* 8006D0A0 0006A0A0  EC 21 01 72 */	fmuls f1, f1, f5
/* 8006D0A4 0006A0A4  EC A1 00 72 */	fmuls f5, f1, f1
/* 8006D0A8 0006A0A8  EC A5 19 3C */	fnmsubs f5, f5, f4, f3
/* 8006D0AC 0006A0AC  EC 21 01 72 */	fmuls f1, f1, f5
/* 8006D0B0 0006A0B0  4E 80 00 20 */	blr
.endfn approx_rsqrt
