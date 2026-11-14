.include "macros.inc"
.file "lbl_8006D668.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# Normalizes v in place and returns its old length (Newton steps inline).
# - mcrfs special-value routing (FPSCR class bits; never emitted from C), with approx_rsqrt's
#   frsqrte and Newton steps inline. No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D668..0x8006D6FC | size: 0x94
.text
.balign 4

# .text:0x0 | 0x8006D668 | size: 0x94
.fn lbl_8006D668, global
/* 8006D668 0006A668  3C A0 E0 00 */	lis r5, 0xe000
/* 8006D66C 0006A66C  C0 C3 00 00 */	lfs f6, 0x0(r3)
/* 8006D670 0006A670  C0 E3 00 04 */	lfs f7, 0x4(r3)
/* 8006D674 0006A674  EC 26 01 B2 */	fmuls f1, f6, f6
/* 8006D678 0006A678  C1 03 00 08 */	lfs f8, 0x8(r3)
/* 8006D67C 0006A67C  EC 27 09 FA */	fmadds f1, f7, f7, f1
/* 8006D680 0006A680  EC 28 0A 3A */	fmadds f1, f8, f8, f1
/* 8006D684 0006A684  C0 45 01 A0 */	lfs f2, 0x1a0(r5)
/* 8006D688 0006A688  FC 90 00 80 */	mcrfs cr1, cr4
/* 8006D68C 0006A68C  FC 0C 00 80 */	mcrfs cr0, cr3
/* 8006D690 0006A690  41 87 00 58 */	bso cr1, .L_8006D6E8
/* 8006D694 0006A694  40 85 00 54 */	ble cr1, .L_8006D6E8
/* 8006D698 0006A698  41 83 00 50 */	bso .L_8006D6E8
/* 8006D69C 0006A69C  FC 00 08 90 */	fmr f0, f1
/* 8006D6A0 0006A6A0  EC 82 00 72 */	fmuls f4, f2, f1
/* 8006D6A4 0006A6A4  EC 62 10 2A */	fadds f3, f2, f2
/* 8006D6A8 0006A6A8  FC 20 08 34 */	frsqrte f1, f1
/* 8006D6AC 0006A6AC  EC 63 10 2A */	fadds f3, f3, f2
/* 8006D6B0 0006A6B0  EC A1 00 72 */	fmuls f5, f1, f1
/* 8006D6B4 0006A6B4  EC A5 19 3C */	fnmsubs f5, f5, f4, f3
/* 8006D6B8 0006A6B8  EC 21 01 72 */	fmuls f1, f1, f5
/* 8006D6BC 0006A6BC  EC A1 00 72 */	fmuls f5, f1, f1
/* 8006D6C0 0006A6C0  EC A5 19 3C */	fnmsubs f5, f5, f4, f3
/* 8006D6C4 0006A6C4  EC 21 01 72 */	fmuls f1, f1, f5
/* 8006D6C8 0006A6C8  EC C6 00 72 */	fmuls f6, f6, f1
/* 8006D6CC 0006A6CC  D0 C3 00 00 */	stfs f6, 0x0(r3)
/* 8006D6D0 0006A6D0  EC E7 00 72 */	fmuls f7, f7, f1
/* 8006D6D4 0006A6D4  D0 E3 00 04 */	stfs f7, 0x4(r3)
/* 8006D6D8 0006A6D8  ED 08 00 72 */	fmuls f8, f8, f1
/* 8006D6DC 0006A6DC  D1 03 00 08 */	stfs f8, 0x8(r3)
/* 8006D6E0 0006A6E0  EC 21 00 32 */	fmuls f1, f1, f0
/* 8006D6E4 0006A6E4  4E 80 00 20 */	blr
.L_8006D6E8:
/* 8006D6E8 0006A6E8  C0 25 01 98 */	lfs f1, 0x198(r5)
/* 8006D6EC 0006A6EC  D0 23 00 00 */	stfs f1, 0x0(r3)
/* 8006D6F0 0006A6F0  D0 23 00 04 */	stfs f1, 0x4(r3)
/* 8006D6F4 0006A6F4  D0 23 00 08 */	stfs f1, 0x8(r3)
/* 8006D6F8 0006A6F8  4E 80 00 20 */	blr
.endfn lbl_8006D668
