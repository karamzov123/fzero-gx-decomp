.include "macros.inc"
.file "lbl_8006D0E8.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# 1 / sqrt(x).
# - mcrfs reads the FPSCR class bits to route NaN, zero and infinity to float_return_values'
#   special-value entries; MWCC never emits mcrfs from C. approx_rsqrt is called with a hand-saved
#   link register (mflr rX; bl; mtlr rX) and no frame: no MWCC prologue/epilogue.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D0E8..0x8006D118 | size: 0x30
.text
.balign 4

# .text:0x0 | 0x8006D0E8 | size: 0x30
.fn lbl_8006D0E8, global
/* 8006D0E8 0006A0E8  FC 20 08 18 */	frsp f1, f1
/* 8006D0EC 0006A0EC  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D0F0 0006A0F0  FC 90 00 80 */	mcrfs cr1, cr4
/* 8006D0F4 0006A0F4  FC 0C 00 80 */	mcrfs cr0, cr3
/* 8006D0F8 0006A0F8  C0 44 01 A0 */	lfs f2, 0x1a0(r4)
/* 8006D0FC 0006A0FC  41 87 FF 80 */	bso cr1, _rsqrt_return_special
/* 8006D100 0006A100  41 83 FF 54 */	bso _return_inf
/* 8006D104 0006A104  40 85 FF 50 */	ble cr1, _return_inf
/* 8006D108 0006A108  7C 68 02 A6 */	mflr r3
/* 8006D10C 0006A10C  4B FF FF 7D */	bl approx_rsqrt
/* 8006D110 0006A110  7C 68 03 A6 */	mtlr r3
/* 8006D114 0006A114  4E 80 00 20 */	blr
.endfn lbl_8006D0E8
