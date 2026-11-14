.include "macros.inc"
.file "lbl_8006DBAC.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# mtxA = mtx.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Paired-single row copies (psq_l/psq_st), which MWCC emits only from inline assembly; C copies
#   compile to lfs/stfs or lwz/stw (measured). No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DBAC..0x8006DBE4 | size: 0x38
.text
.balign 4

# .text:0x0 | 0x8006DBAC | size: 0x38
.fn lbl_8006DBAC, global
/* 8006DBAC 0006ABAC  3C 80 E0 00 */	lis r4, 0xe000
/* 8006DBB0 0006ABB0  E0 03 00 00 */	psq_l f0, 0x0(r3), 0, qr0
/* 8006DBB4 0006ABB4  E0 23 00 08 */	psq_l f1, 0x8(r3), 0, qr0
/* 8006DBB8 0006ABB8  E0 43 00 10 */	psq_l f2, 0x10(r3), 0, qr0
/* 8006DBBC 0006ABBC  E0 63 00 18 */	psq_l f3, 0x18(r3), 0, qr0
/* 8006DBC0 0006ABC0  E0 83 00 20 */	psq_l f4, 0x20(r3), 0, qr0
/* 8006DBC4 0006ABC4  E0 A3 00 28 */	psq_l f5, 0x28(r3), 0, qr0
/* 8006DBC8 0006ABC8  F0 04 00 00 */	psq_st f0, 0x0(r4), 0, qr0
/* 8006DBCC 0006ABCC  F0 24 00 08 */	psq_st f1, 0x8(r4), 0, qr0
/* 8006DBD0 0006ABD0  F0 44 00 10 */	psq_st f2, 0x10(r4), 0, qr0
/* 8006DBD4 0006ABD4  F0 64 00 18 */	psq_st f3, 0x18(r4), 0, qr0
/* 8006DBD8 0006ABD8  F0 84 00 20 */	psq_st f4, 0x20(r4), 0, qr0
/* 8006DBDC 0006ABDC  F0 A4 00 28 */	psq_st f5, 0x28(r4), 0, qr0
/* 8006DBE0 0006ABE0  4E 80 00 20 */	blr
.endfn lbl_8006DBAC
