.include "macros.inc"
.file "lbl_8006D5F0.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# dst = src scaled to length len; zero vector when |src| is not a normal positive number.
# - mcrfs special-value routing (FPSCR class bits; never emitted from C) and a frameless call to
#   approx_rsqrt with a hand-saved link register (mflr rX; bl; mtlr rX): no MWCC prologue/epilogue.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D5F0..0x8006D668 | size: 0x78
.text
.balign 4

# .text:0x0 | 0x8006D5F0 | size: 0x78
.fn lbl_8006D5F0, global
/* 8006D5F0 0006A5F0  3C C0 E0 00 */	lis r6, 0xe000
/* 8006D5F4 0006A5F4  FC 00 08 90 */	fmr f0, f1
/* 8006D5F8 0006A5F8  C0 C3 00 00 */	lfs f6, 0x0(r3)
/* 8006D5FC 0006A5FC  C0 E3 00 04 */	lfs f7, 0x4(r3)
/* 8006D600 0006A600  C1 03 00 08 */	lfs f8, 0x8(r3)
/* 8006D604 0006A604  EC 26 01 B2 */	fmuls f1, f6, f6
/* 8006D608 0006A608  EC 27 09 FA */	fmadds f1, f7, f7, f1
/* 8006D60C 0006A60C  EC 28 0A 3A */	fmadds f1, f8, f8, f1
/* 8006D610 0006A610  FC 90 00 80 */	mcrfs cr1, cr4
/* 8006D614 0006A614  FC 0C 00 80 */	mcrfs cr0, cr3
/* 8006D618 0006A618  C0 46 01 A0 */	lfs f2, 0x1a0(r6)
/* 8006D61C 0006A61C  41 87 00 38 */	bso cr1, .L_8006D654
/* 8006D620 0006A620  41 83 00 34 */	bso .L_8006D654
/* 8006D624 0006A624  40 85 00 30 */	ble cr1, .L_8006D654
/* 8006D628 0006A628  7C A8 02 A6 */	mflr r5
/* 8006D62C 0006A62C  4B FF FA 5D */	bl approx_rsqrt
/* 8006D630 0006A630  7C A8 03 A6 */	mtlr r5
/* 8006D634 0006A634  EC 21 00 32 */	fmuls f1, f1, f0
/* 8006D638 0006A638  EC C6 00 72 */	fmuls f6, f6, f1
/* 8006D63C 0006A63C  D0 C4 00 00 */	stfs f6, 0x0(r4)
/* 8006D640 0006A640  EC E7 00 72 */	fmuls f7, f7, f1
/* 8006D644 0006A644  D0 E4 00 04 */	stfs f7, 0x4(r4)
/* 8006D648 0006A648  ED 08 00 72 */	fmuls f8, f8, f1
/* 8006D64C 0006A64C  D1 04 00 08 */	stfs f8, 0x8(r4)
/* 8006D650 0006A650  4E 80 00 20 */	blr
.L_8006D654:
/* 8006D654 0006A654  C0 C6 01 98 */	lfs f6, 0x198(r6)
/* 8006D658 0006A658  D0 C4 00 00 */	stfs f6, 0x0(r4)
/* 8006D65C 0006A65C  D0 C4 00 04 */	stfs f6, 0x4(r4)
/* 8006D660 0006A660  D0 C4 00 08 */	stfs f6, 0x8(r4)
/* 8006D664 0006A664  4E 80 00 20 */	blr
.endfn lbl_8006D5F0
