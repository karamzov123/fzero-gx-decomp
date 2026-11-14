.include "macros.inc"
.file "lbl_8006DB30.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# Pop the matrix stack into mtxA.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Paired-single row copies (psq_l/psq_st, inline assembly only), with the stack pointer at 0x94
#   in the locked cache kept in r4. No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DB30..0x8006DB74 | size: 0x44
.text
.balign 4

# .text:0x0 | 0x8006DB30 | size: 0x44
.fn lbl_8006DB30, global
/* 8006DB30 0006AB30  3C 60 E0 00 */	lis r3, 0xe000
/* 8006DB34 0006AB34  80 83 00 94 */	lwz r4, 0x94(r3)
/* 8006DB38 0006AB38  E0 04 00 00 */	psq_l f0, 0x0(r4), 0, qr0
/* 8006DB3C 0006AB3C  E0 24 00 08 */	psq_l f1, 0x8(r4), 0, qr0
/* 8006DB40 0006AB40  E0 44 00 10 */	psq_l f2, 0x10(r4), 0, qr0
/* 8006DB44 0006AB44  E0 64 00 18 */	psq_l f3, 0x18(r4), 0, qr0
/* 8006DB48 0006AB48  E0 84 00 20 */	psq_l f4, 0x20(r4), 0, qr0
/* 8006DB4C 0006AB4C  E0 A4 00 28 */	psq_l f5, 0x28(r4), 0, qr0
/* 8006DB50 0006AB50  38 84 00 30 */	addi r4, r4, 0x30
/* 8006DB54 0006AB54  F0 03 00 00 */	psq_st f0, 0x0(r3), 0, qr0
/* 8006DB58 0006AB58  F0 23 00 08 */	psq_st f1, 0x8(r3), 0, qr0
/* 8006DB5C 0006AB5C  F0 43 00 10 */	psq_st f2, 0x10(r3), 0, qr0
/* 8006DB60 0006AB60  F0 63 00 18 */	psq_st f3, 0x18(r3), 0, qr0
/* 8006DB64 0006AB64  F0 83 00 20 */	psq_st f4, 0x20(r3), 0, qr0
/* 8006DB68 0006AB68  F0 A3 00 28 */	psq_st f5, 0x28(r3), 0, qr0
/* 8006DB6C 0006AB6C  90 83 00 94 */	stw r4, 0x94(r3)
/* 8006DB70 0006AB70  4E 80 00 20 */	blr
.endfn lbl_8006DB30
