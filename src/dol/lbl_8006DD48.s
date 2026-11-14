.include "macros.inc"
.file "lbl_8006DD48.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# Upper 3x3 of dst = src.
# - Paired-single row copies (psq_l/psq_st), which MWCC emits only from inline assembly; C copies
#   compile to lfs/stfs or lwz/stw (measured). No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DD48..0x8006DD7C | size: 0x34
.text
.balign 4

# .text:0x0 | 0x8006DD48 | size: 0x34
.fn lbl_8006DD48, global
/* 8006DD48 0006AD48  E0 03 00 00 */	psq_l f0, 0x0(r3), 0, qr0
/* 8006DD4C 0006AD4C  C0 23 00 08 */	lfs f1, 0x8(r3)
/* 8006DD50 0006AD50  E0 43 00 10 */	psq_l f2, 0x10(r3), 0, qr0
/* 8006DD54 0006AD54  C0 63 00 18 */	lfs f3, 0x18(r3)
/* 8006DD58 0006AD58  E0 83 00 20 */	psq_l f4, 0x20(r3), 0, qr0
/* 8006DD5C 0006AD5C  C0 A3 00 28 */	lfs f5, 0x28(r3)
/* 8006DD60 0006AD60  F0 04 00 00 */	psq_st f0, 0x0(r4), 0, qr0
/* 8006DD64 0006AD64  D0 24 00 08 */	stfs f1, 0x8(r4)
/* 8006DD68 0006AD68  F0 44 00 10 */	psq_st f2, 0x10(r4), 0, qr0
/* 8006DD6C 0006AD6C  D0 64 00 18 */	stfs f3, 0x18(r4)
/* 8006DD70 0006AD70  F0 84 00 20 */	psq_st f4, 0x20(r4), 0, qr0
/* 8006DD74 0006AD74  D0 A4 00 28 */	stfs f5, 0x28(r4)
/* 8006DD78 0006AD78  4E 80 00 20 */	blr
.endfn lbl_8006DD48
