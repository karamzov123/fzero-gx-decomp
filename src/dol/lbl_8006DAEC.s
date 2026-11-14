.include "macros.inc"
.file "lbl_8006DAEC.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# Push mtxA onto the locked-cache matrix stack.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Paired-single row copies (psq_l/psq_st, inline assembly only), with the stack pointer at 0x94
#   in the locked cache kept in r4. No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DAEC..0x8006DB30 | size: 0x44
.text
.balign 4

# .text:0x0 | 0x8006DAEC | size: 0x44
.fn lbl_8006DAEC, global
/* 8006DAEC 0006AAEC  3C 60 E0 00 */	lis r3, 0xe000
/* 8006DAF0 0006AAF0  80 83 00 94 */	lwz r4, 0x94(r3)
/* 8006DAF4 0006AAF4  E0 03 00 00 */	psq_l f0, 0x0(r3), 0, qr0
/* 8006DAF8 0006AAF8  E0 23 00 08 */	psq_l f1, 0x8(r3), 0, qr0
/* 8006DAFC 0006AAFC  E0 43 00 10 */	psq_l f2, 0x10(r3), 0, qr0
/* 8006DB00 0006AB00  38 84 FF D0 */	subi r4, r4, 0x30
/* 8006DB04 0006AB04  E0 63 00 18 */	psq_l f3, 0x18(r3), 0, qr0
/* 8006DB08 0006AB08  E0 83 00 20 */	psq_l f4, 0x20(r3), 0, qr0
/* 8006DB0C 0006AB0C  E0 A3 00 28 */	psq_l f5, 0x28(r3), 0, qr0
/* 8006DB10 0006AB10  F0 04 00 00 */	psq_st f0, 0x0(r4), 0, qr0
/* 8006DB14 0006AB14  F0 24 00 08 */	psq_st f1, 0x8(r4), 0, qr0
/* 8006DB18 0006AB18  F0 44 00 10 */	psq_st f2, 0x10(r4), 0, qr0
/* 8006DB1C 0006AB1C  F0 64 00 18 */	psq_st f3, 0x18(r4), 0, qr0
/* 8006DB20 0006AB20  F0 84 00 20 */	psq_st f4, 0x20(r4), 0, qr0
/* 8006DB24 0006AB24  F0 A4 00 28 */	psq_st f5, 0x28(r4), 0, qr0
/* 8006DB28 0006AB28  90 83 00 94 */	stw r4, 0x94(r3)
/* 8006DB2C 0006AB2C  4E 80 00 20 */	blr
.endfn lbl_8006DAEC
