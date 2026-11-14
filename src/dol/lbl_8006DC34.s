.include "macros.inc"
.file "lbl_8006DC34.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# Upper 3x3 of mtx = mtxA.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Paired-single row copies (psq_l/psq_st), which MWCC emits only from inline assembly; C copies
#   compile to lfs/stfs or lwz/stw (measured). No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DC34..0x8006DC6C | size: 0x38
.text
.balign 4

# .text:0x0 | 0x8006DC34 | size: 0x38
.fn lbl_8006DC34, global
/* 8006DC34 0006AC34  3C 80 E0 00 */	lis r4, 0xe000
/* 8006DC38 0006AC38  E0 04 00 00 */	psq_l f0, 0x0(r4), 0, qr0
/* 8006DC3C 0006AC3C  C0 24 00 08 */	lfs f1, 0x8(r4)
/* 8006DC40 0006AC40  E0 44 00 10 */	psq_l f2, 0x10(r4), 0, qr0
/* 8006DC44 0006AC44  C0 64 00 18 */	lfs f3, 0x18(r4)
/* 8006DC48 0006AC48  E0 84 00 20 */	psq_l f4, 0x20(r4), 0, qr0
/* 8006DC4C 0006AC4C  C0 A4 00 28 */	lfs f5, 0x28(r4)
/* 8006DC50 0006AC50  F0 03 00 00 */	psq_st f0, 0x0(r3), 0, qr0
/* 8006DC54 0006AC54  D0 23 00 08 */	stfs f1, 0x8(r3)
/* 8006DC58 0006AC58  F0 43 00 10 */	psq_st f2, 0x10(r3), 0, qr0
/* 8006DC5C 0006AC5C  D0 63 00 18 */	stfs f3, 0x18(r3)
/* 8006DC60 0006AC60  F0 83 00 20 */	psq_st f4, 0x20(r3), 0, qr0
/* 8006DC64 0006AC64  D0 A3 00 28 */	stfs f5, 0x28(r3)
/* 8006DC68 0006AC68  4E 80 00 20 */	blr
.endfn lbl_8006DC34
