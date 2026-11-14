.include "macros.inc"
.file "lbl_8006DC6C.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# Upper 3x3 of mtxA = mtx.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Paired-single row copies (psq_l/psq_st), which MWCC emits only from inline assembly; C copies
#   compile to lfs/stfs or lwz/stw (measured). No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DC6C..0x8006DCA4 | size: 0x38
.text
.balign 4

# .text:0x0 | 0x8006DC6C | size: 0x38
.fn lbl_8006DC6C, global
/* 8006DC6C 0006AC6C  3C 80 E0 00 */	lis r4, 0xe000
/* 8006DC70 0006AC70  E0 03 00 00 */	psq_l f0, 0x0(r3), 0, qr0
/* 8006DC74 0006AC74  C0 23 00 08 */	lfs f1, 0x8(r3)
/* 8006DC78 0006AC78  E0 43 00 10 */	psq_l f2, 0x10(r3), 0, qr0
/* 8006DC7C 0006AC7C  C0 63 00 18 */	lfs f3, 0x18(r3)
/* 8006DC80 0006AC80  E0 83 00 20 */	psq_l f4, 0x20(r3), 0, qr0
/* 8006DC84 0006AC84  C0 A3 00 28 */	lfs f5, 0x28(r3)
/* 8006DC88 0006AC88  F0 04 00 00 */	psq_st f0, 0x0(r4), 0, qr0
/* 8006DC8C 0006AC8C  D0 24 00 08 */	stfs f1, 0x8(r4)
/* 8006DC90 0006AC90  F0 44 00 10 */	psq_st f2, 0x10(r4), 0, qr0
/* 8006DC94 0006AC94  D0 64 00 18 */	stfs f3, 0x18(r4)
/* 8006DC98 0006AC98  F0 84 00 20 */	psq_st f4, 0x20(r4), 0, qr0
/* 8006DC9C 0006AC9C  D0 A4 00 28 */	stfs f5, 0x28(r4)
/* 8006DCA0 0006ACA0  4E 80 00 20 */	blr
.endfn lbl_8006DC6C
