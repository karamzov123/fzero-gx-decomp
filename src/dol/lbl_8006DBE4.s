.include "macros.inc"
.file "lbl_8006DBE4.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# mtxA = top of the matrix stack.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Paired-single row copies (psq_l/psq_st, inline assembly only), with the stack pointer at 0x94
#   in the locked cache kept in r4. No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DBE4..0x8006DC20 | size: 0x3C
.text
.balign 4

# .text:0x0 | 0x8006DBE4 | size: 0x3C
.fn lbl_8006DBE4, global
/* 8006DBE4 0006ABE4  3C 60 E0 00 */	lis r3, 0xe000
/* 8006DBE8 0006ABE8  80 83 00 94 */	lwz r4, 0x94(r3)
/* 8006DBEC 0006ABEC  E0 04 00 00 */	psq_l f0, 0x0(r4), 0, qr0
/* 8006DBF0 0006ABF0  E0 24 00 08 */	psq_l f1, 0x8(r4), 0, qr0
/* 8006DBF4 0006ABF4  E0 44 00 10 */	psq_l f2, 0x10(r4), 0, qr0
/* 8006DBF8 0006ABF8  E0 64 00 18 */	psq_l f3, 0x18(r4), 0, qr0
/* 8006DBFC 0006ABFC  E0 84 00 20 */	psq_l f4, 0x20(r4), 0, qr0
/* 8006DC00 0006AC00  E0 A4 00 28 */	psq_l f5, 0x28(r4), 0, qr0
/* 8006DC04 0006AC04  F0 03 00 00 */	psq_st f0, 0x0(r3), 0, qr0
/* 8006DC08 0006AC08  F0 23 00 08 */	psq_st f1, 0x8(r3), 0, qr0
/* 8006DC0C 0006AC0C  F0 43 00 10 */	psq_st f2, 0x10(r3), 0, qr0
/* 8006DC10 0006AC10  F0 63 00 18 */	psq_st f3, 0x18(r3), 0, qr0
/* 8006DC14 0006AC14  F0 83 00 20 */	psq_st f4, 0x20(r3), 0, qr0
/* 8006DC18 0006AC18  F0 A3 00 28 */	psq_st f5, 0x28(r3), 0, qr0
/* 8006DC1C 0006AC1C  4E 80 00 20 */	blr
.endfn lbl_8006DBE4
