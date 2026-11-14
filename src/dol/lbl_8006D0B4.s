.include "macros.inc"
.file "lbl_8006D0B4.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# sqrt(x) as x * rsqrt(x).
# - mcrfs reads the FPSCR class bits to route NaN, zero and infinity to float_return_values'
#   special-value entries; MWCC never emits mcrfs from C. approx_rsqrt is called with a hand-saved
#   link register (mflr rX; bl; mtlr rX) and no frame: no MWCC prologue/epilogue.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D0B4..0x8006D0E8 | size: 0x34
.text
.balign 4

# .text:0x0 | 0x8006D0B4 | size: 0x34
.fn lbl_8006D0B4, global
/* 8006D0B4 0006A0B4  FC 00 08 18 */	frsp f0, f1
/* 8006D0B8 0006A0B8  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D0BC 0006A0BC  FC 90 00 80 */	mcrfs cr1, cr4
/* 8006D0C0 0006A0C0  FC 0C 00 80 */	mcrfs cr0, cr3
/* 8006D0C4 0006A0C4  C0 44 01 A0 */	lfs f2, 0x1a0(r4)
/* 8006D0C8 0006A0C8  41 87 FF A8 */	bso cr1, _sqrt_return_special
/* 8006D0CC 0006A0CC  41 83 FF 80 */	bso _return_zero
/* 8006D0D0 0006A0D0  40 85 FF 7C */	ble cr1, _return_zero
/* 8006D0D4 0006A0D4  7C 68 02 A6 */	mflr r3
/* 8006D0D8 0006A0D8  4B FF FF B1 */	bl approx_rsqrt
/* 8006D0DC 0006A0DC  7C 68 03 A6 */	mtlr r3
/* 8006D0E0 0006A0E0  EC 21 00 32 */	fmuls f1, f1, f0
/* 8006D0E4 0006A0E4  4E 80 00 20 */	blr
.endfn lbl_8006D0B4
