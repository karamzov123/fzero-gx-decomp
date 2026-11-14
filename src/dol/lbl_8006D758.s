.include "macros.inc"
.file "lbl_8006D758.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# mtxA = identity.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Loads the locked-cache (0, 1) constant as u8 through GQR2 (`psq_l ..., 0, 2`) and stores paired
#   singles; quantized psq forms come only from inline assembly. No frame.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D758..0x8006D784 | size: 0x2C
.text
.balign 4

# .text:0x0 | 0x8006D758 | size: 0x2C
.fn lbl_8006D758, global
/* 8006D758 0006A758  3C 60 E0 00 */	lis r3, 0xe000
/* 8006D75C 0006A75C  E0 23 21 AC */	psq_l f1, 0x1ac(r3), 0, qr2
/* 8006D760 0006A760  E0 43 21 AE */	psq_l f2, 0x1ae(r3), 0, qr2
/* 8006D764 0006A764  10 01 08 28 */	ps_sub f0, f1, f1
/* 8006D768 0006A768  F0 43 00 00 */	psq_st f2, 0x0(r3), 0, qr0
/* 8006D76C 0006A76C  F0 03 00 08 */	psq_st f0, 0x8(r3), 0, qr0
/* 8006D770 0006A770  F0 23 00 10 */	psq_st f1, 0x10(r3), 0, qr0
/* 8006D774 0006A774  F0 03 00 18 */	psq_st f0, 0x18(r3), 0, qr0
/* 8006D778 0006A778  F0 03 00 20 */	psq_st f0, 0x20(r3), 0, qr0
/* 8006D77C 0006A77C  F0 43 00 28 */	psq_st f2, 0x28(r3), 0, qr0
/* 8006D780 0006A780  4E 80 00 20 */	blr
.endfn lbl_8006D758
