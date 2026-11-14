.include "macros.inc"
.file "lbl_8006DCDC.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# mtxB = mtxA.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Paired-single row copies (psq_l/psq_st), which MWCC emits only from inline assembly; C copies
#   compile to lfs/stfs or lwz/stw (measured). No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DCDC..0x8006DD14 | size: 0x38
.text
.balign 4

# .text:0x0 | 0x8006DCDC | size: 0x38
.fn lbl_8006DCDC, global
/* 8006DCDC 0006ACDC  3C 60 E0 00 */	lis r3, 0xe000
/* 8006DCE0 0006ACE0  E0 03 00 00 */	psq_l f0, 0x0(r3), 0, qr0
/* 8006DCE4 0006ACE4  E0 23 00 08 */	psq_l f1, 0x8(r3), 0, qr0
/* 8006DCE8 0006ACE8  E0 43 00 10 */	psq_l f2, 0x10(r3), 0, qr0
/* 8006DCEC 0006ACEC  E0 63 00 18 */	psq_l f3, 0x18(r3), 0, qr0
/* 8006DCF0 0006ACF0  E0 83 00 20 */	psq_l f4, 0x20(r3), 0, qr0
/* 8006DCF4 0006ACF4  E0 A3 00 28 */	psq_l f5, 0x28(r3), 0, qr0
/* 8006DCF8 0006ACF8  F0 03 00 30 */	psq_st f0, 0x30(r3), 0, qr0
/* 8006DCFC 0006ACFC  F0 23 00 38 */	psq_st f1, 0x38(r3), 0, qr0
/* 8006DD00 0006AD00  F0 43 00 40 */	psq_st f2, 0x40(r3), 0, qr0
/* 8006DD04 0006AD04  F0 63 00 48 */	psq_st f3, 0x48(r3), 0, qr0
/* 8006DD08 0006AD08  F0 83 00 50 */	psq_st f4, 0x50(r3), 0, qr0
/* 8006DD0C 0006AD0C  F0 A3 00 58 */	psq_st f5, 0x58(r3), 0, qr0
/* 8006DD10 0006AD10  4E 80 00 20 */	blr
.endfn lbl_8006DCDC
