.include "macros.inc"
.file "lbl_8006DB74.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# mtx = mtxA.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Paired-single row copies (psq_l/psq_st), which MWCC emits only from inline assembly; C copies
#   compile to lfs/stfs or lwz/stw (measured). No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DB74..0x8006DBAC | size: 0x38
.text
.balign 4

# .text:0x0 | 0x8006DB74 | size: 0x38
.fn lbl_8006DB74, global
/* 8006DB74 0006AB74  3C 80 E0 00 */	lis r4, 0xe000
/* 8006DB78 0006AB78  E0 04 00 00 */	psq_l f0, 0x0(r4), 0, qr0
/* 8006DB7C 0006AB7C  E0 24 00 08 */	psq_l f1, 0x8(r4), 0, qr0
/* 8006DB80 0006AB80  E0 44 00 10 */	psq_l f2, 0x10(r4), 0, qr0
/* 8006DB84 0006AB84  E0 64 00 18 */	psq_l f3, 0x18(r4), 0, qr0
/* 8006DB88 0006AB88  E0 84 00 20 */	psq_l f4, 0x20(r4), 0, qr0
/* 8006DB8C 0006AB8C  E0 A4 00 28 */	psq_l f5, 0x28(r4), 0, qr0
/* 8006DB90 0006AB90  F0 03 00 00 */	psq_st f0, 0x0(r3), 0, qr0
/* 8006DB94 0006AB94  F0 23 00 08 */	psq_st f1, 0x8(r3), 0, qr0
/* 8006DB98 0006AB98  F0 43 00 10 */	psq_st f2, 0x10(r3), 0, qr0
/* 8006DB9C 0006AB9C  F0 63 00 18 */	psq_st f3, 0x18(r3), 0, qr0
/* 8006DBA0 0006ABA0  F0 83 00 20 */	psq_st f4, 0x20(r3), 0, qr0
/* 8006DBA4 0006ABA4  F0 A3 00 28 */	psq_st f5, 0x28(r3), 0, qr0
/* 8006DBA8 0006ABA8  4E 80 00 20 */	blr
.endfn lbl_8006DB74
