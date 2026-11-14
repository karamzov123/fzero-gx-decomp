.include "macros.inc"
.file "lbl_8006DD14.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# dst = src (3x4 matrix copy).
# - Paired-single row copies (psq_l/psq_st), which MWCC emits only from inline assembly; C copies
#   compile to lfs/stfs or lwz/stw (measured). No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DD14..0x8006DD48 | size: 0x34
.text
.balign 4

# .text:0x0 | 0x8006DD14 | size: 0x34
.fn lbl_8006DD14, global
/* 8006DD14 0006AD14  E0 03 00 00 */	psq_l f0, 0x0(r3), 0, qr0
/* 8006DD18 0006AD18  E0 23 00 08 */	psq_l f1, 0x8(r3), 0, qr0
/* 8006DD1C 0006AD1C  E0 43 00 10 */	psq_l f2, 0x10(r3), 0, qr0
/* 8006DD20 0006AD20  E0 63 00 18 */	psq_l f3, 0x18(r3), 0, qr0
/* 8006DD24 0006AD24  E0 83 00 20 */	psq_l f4, 0x20(r3), 0, qr0
/* 8006DD28 0006AD28  E0 A3 00 28 */	psq_l f5, 0x28(r3), 0, qr0
/* 8006DD2C 0006AD2C  F0 04 00 00 */	psq_st f0, 0x0(r4), 0, qr0
/* 8006DD30 0006AD30  F0 24 00 08 */	psq_st f1, 0x8(r4), 0, qr0
/* 8006DD34 0006AD34  F0 44 00 10 */	psq_st f2, 0x10(r4), 0, qr0
/* 8006DD38 0006AD38  F0 64 00 18 */	psq_st f3, 0x18(r4), 0, qr0
/* 8006DD3C 0006AD3C  F0 84 00 20 */	psq_st f4, 0x20(r4), 0, qr0
/* 8006DD40 0006AD40  F0 A4 00 28 */	psq_st f5, 0x28(r4), 0, qr0
/* 8006DD44 0006AD44  4E 80 00 20 */	blr
.endfn lbl_8006DD14
