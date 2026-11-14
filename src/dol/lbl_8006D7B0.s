.include "macros.inc"
.file "lbl_8006D7B0.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# Upper 3x3 of mtxA = identity (translation column left alone).
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Loads the locked-cache (0, 1) constant as u8 through GQR2 (`psq_l ..., 0, 2`) and stores paired
#   singles; quantized psq forms come only from inline assembly. No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D7B0..0x8006D7DC | size: 0x2C
.text
.balign 4

# .text:0x0 | 0x8006D7B0 | size: 0x2C
.fn lbl_8006D7B0, global
/* 8006D7B0 0006A7B0  3C 60 E0 00 */	lis r3, 0xe000
/* 8006D7B4 0006A7B4  E0 23 21 AC */	psq_l f1, 0x1ac(r3), 0, qr2
/* 8006D7B8 0006A7B8  E0 43 21 AE */	psq_l f2, 0x1ae(r3), 0, qr2
/* 8006D7BC 0006A7BC  10 01 08 28 */	ps_sub f0, f1, f1
/* 8006D7C0 0006A7C0  F0 43 00 00 */	psq_st f2, 0x0(r3), 0, qr0
/* 8006D7C4 0006A7C4  F0 03 80 08 */	psq_st f0, 0x8(r3), 1, qr0
/* 8006D7C8 0006A7C8  F0 23 00 10 */	psq_st f1, 0x10(r3), 0, qr0
/* 8006D7CC 0006A7CC  F0 03 80 18 */	psq_st f0, 0x18(r3), 1, qr0
/* 8006D7D0 0006A7D0  F0 03 00 20 */	psq_st f0, 0x20(r3), 0, qr0
/* 8006D7D4 0006A7D4  F0 43 80 28 */	psq_st f2, 0x28(r3), 1, qr0
/* 8006D7D8 0006A7D8  4E 80 00 20 */	blr
.endfn lbl_8006D7B0
