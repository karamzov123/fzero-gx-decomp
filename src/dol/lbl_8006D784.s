.include "macros.inc"
.file "lbl_8006D784.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# mtx = identity.
# - Loads the locked-cache (0, 1) constant as u8 through GQR2 (`psq_l ..., 0, 2`) and stores paired
#   singles; quantized psq forms come only from inline assembly. No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D784..0x8006D7B0 | size: 0x2C
.text
.balign 4

# .text:0x0 | 0x8006D784 | size: 0x2C
.fn lbl_8006D784, global
/* 8006D784 0006A784  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D788 0006A788  E0 24 21 AC */	psq_l f1, 0x1ac(r4), 0, qr2
/* 8006D78C 0006A78C  E0 44 21 AE */	psq_l f2, 0x1ae(r4), 0, qr2
/* 8006D790 0006A790  10 01 08 28 */	ps_sub f0, f1, f1
/* 8006D794 0006A794  F0 43 00 00 */	psq_st f2, 0x0(r3), 0, qr0
/* 8006D798 0006A798  F0 03 00 08 */	psq_st f0, 0x8(r3), 0, qr0
/* 8006D79C 0006A79C  F0 23 00 10 */	psq_st f1, 0x10(r3), 0, qr0
/* 8006D7A0 0006A7A0  F0 03 00 18 */	psq_st f0, 0x18(r3), 0, qr0
/* 8006D7A4 0006A7A4  F0 03 00 20 */	psq_st f0, 0x20(r3), 0, qr0
/* 8006D7A8 0006A7A8  F0 43 00 28 */	psq_st f2, 0x28(r3), 0, qr0
/* 8006D7AC 0006A7AC  4E 80 00 20 */	blr
.endfn lbl_8006D784
