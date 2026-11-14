.include "macros.inc"
.file "lbl_8006D6FC.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# dot(a, b) / (|a| |b|) without the special-value checks.
# - A frameless call to approx_rsqrt with a hand-saved link register (mflr r6; bl; mtlr r6): no MWCC
#   prologue/epilogue; products hand-allocated in f6-f13.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D6FC..0x8006D758 | size: 0x5C
.text
.balign 4

# .text:0x0 | 0x8006D6FC | size: 0x5C
.fn lbl_8006D6FC, global
/* 8006D6FC 0006A6FC  3C A0 E0 00 */	lis r5, 0xe000
/* 8006D700 0006A700  C0 C3 00 00 */	lfs f6, 0x0(r3)
/* 8006D704 0006A704  C1 24 00 00 */	lfs f9, 0x0(r4)
/* 8006D708 0006A708  ED 86 01 B2 */	fmuls f12, f6, f6
/* 8006D70C 0006A70C  C0 E3 00 04 */	lfs f7, 0x4(r3)
/* 8006D710 0006A710  ED A9 02 72 */	fmuls f13, f9, f9
/* 8006D714 0006A714  C1 44 00 04 */	lfs f10, 0x4(r4)
/* 8006D718 0006A718  EC 06 02 72 */	fmuls f0, f6, f9
/* 8006D71C 0006A71C  C1 03 00 08 */	lfs f8, 0x8(r3)
/* 8006D720 0006A720  ED 87 61 FA */	fmadds f12, f7, f7, f12
/* 8006D724 0006A724  C1 64 00 08 */	lfs f11, 0x8(r4)
/* 8006D728 0006A728  ED AA 6A BA */	fmadds f13, f10, f10, f13
/* 8006D72C 0006A72C  EC 07 02 BA */	fmadds f0, f7, f10, f0
/* 8006D730 0006A730  ED 88 62 3A */	fmadds f12, f8, f8, f12
/* 8006D734 0006A734  ED AB 6A FA */	fmadds f13, f11, f11, f13
/* 8006D738 0006A738  EC 08 02 FA */	fmadds f0, f8, f11, f0
/* 8006D73C 0006A73C  C0 45 01 A0 */	lfs f2, 0x1a0(r5)
/* 8006D740 0006A740  EC 2C 03 72 */	fmuls f1, f12, f13
/* 8006D744 0006A744  7C C8 02 A6 */	mflr r6
/* 8006D748 0006A748  4B FF F9 41 */	bl approx_rsqrt
/* 8006D74C 0006A74C  7C C8 03 A6 */	mtlr r6
/* 8006D750 0006A750  EC 21 00 32 */	fmuls f1, f1, f0
/* 8006D754 0006A754  4E 80 00 20 */	blr
.endfn lbl_8006D6FC
