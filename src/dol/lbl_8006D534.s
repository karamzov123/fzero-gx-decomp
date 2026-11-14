.include "macros.inc"
.file "lbl_8006D534.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# dot(a, b) / (|a| |b|), with the special-value exits of the square root.
# - mcrfs special-value routing (FPSCR class bits; never emitted from C) and a frameless call to
#   approx_rsqrt with a hand-saved link register (mflr rX; bl; mtlr rX): no MWCC prologue/epilogue.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D534..0x8006D5A4 | size: 0x70
.text
.balign 4

# .text:0x0 | 0x8006D534 | size: 0x70
.fn lbl_8006D534, global
/* 8006D534 0006A534  C0 23 00 00 */	lfs f1, 0x0(r3)
/* 8006D538 0006A538  C0 43 00 04 */	lfs f2, 0x4(r3)
/* 8006D53C 0006A53C  C0 63 00 08 */	lfs f3, 0x8(r3)
/* 8006D540 0006A540  C0 84 00 00 */	lfs f4, 0x0(r4)
/* 8006D544 0006A544  C0 A4 00 04 */	lfs f5, 0x4(r4)
/* 8006D548 0006A548  C0 C4 00 08 */	lfs f6, 0x8(r4)
/* 8006D54C 0006A54C  3C C0 E0 00 */	lis r6, 0xe000
/* 8006D550 0006A550  ED 01 00 72 */	fmuls f8, f1, f1
/* 8006D554 0006A554  ED 24 01 32 */	fmuls f9, f4, f4
/* 8006D558 0006A558  EC E1 01 32 */	fmuls f7, f1, f4
/* 8006D55C 0006A55C  ED 02 40 BA */	fmadds f8, f2, f2, f8
/* 8006D560 0006A560  ED 25 49 7A */	fmadds f9, f5, f5, f9
/* 8006D564 0006A564  EC E2 39 7A */	fmadds f7, f2, f5, f7
/* 8006D568 0006A568  ED 03 40 FA */	fmadds f8, f3, f3, f8
/* 8006D56C 0006A56C  ED 26 49 BA */	fmadds f9, f6, f6, f9
/* 8006D570 0006A570  EC E3 39 BA */	fmadds f7, f3, f6, f7
/* 8006D574 0006A574  EC 28 02 72 */	fmuls f1, f8, f9
/* 8006D578 0006A578  FC 90 00 80 */	mcrfs cr1, cr4
/* 8006D57C 0006A57C  FC 0C 00 80 */	mcrfs cr0, cr3
/* 8006D580 0006A580  C0 46 01 A0 */	lfs f2, 0x1a0(r6)
/* 8006D584 0006A584  41 87 FA EC */	bso cr1, _sqrt_return_special
/* 8006D588 0006A588  41 83 FA C4 */	bso _return_zero
/* 8006D58C 0006A58C  40 85 FA C0 */	ble cr1, _return_zero
/* 8006D590 0006A590  7C A8 02 A6 */	mflr r5
/* 8006D594 0006A594  4B FF FA F5 */	bl approx_rsqrt
/* 8006D598 0006A598  7C A8 03 A6 */	mtlr r5
/* 8006D59C 0006A59C  EC 21 01 F2 */	fmuls f1, f1, f7
/* 8006D5A0 0006A5A0  4E 80 00 20 */	blr
.endfn lbl_8006D534
