.include "macros.inc"
.file "lbl_8006DA50.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# Normalizes the three basis columns of mtxA.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Hand-scheduled paired-single code (psq_l/psq_st, ps_merge); calls approx_rsqrt with a hand-saved
#   link register (mflr; bl; mtlr) and no frame: no MWCC prologue/epilogue.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DA50..0x8006DAEC | size: 0x9C
.text
.balign 4

# .text:0x0 | 0x8006DA50 | size: 0x9C
.fn lbl_8006DA50, global
/* 8006DA50 0006AA50  3C 60 E0 00 */	lis r3, 0xe000
/* 8006DA54 0006AA54  7C 88 02 A6 */	mflr r4
/* 8006DA58 0006AA58  C0 43 01 A0 */	lfs f2, 0x1a0(r3)
/* 8006DA5C 0006AA5C  E0 C3 00 00 */	psq_l f6, 0x0(r3), 0, qr0
/* 8006DA60 0006AA60  C0 E3 00 08 */	lfs f7, 0x8(r3)
/* 8006DA64 0006AA64  11 86 01 B2 */	ps_mul f12, f6, f6
/* 8006DA68 0006AA68  E1 03 00 10 */	psq_l f8, 0x10(r3), 0, qr0
/* 8006DA6C 0006AA6C  ED A7 01 F2 */	fmuls f13, f7, f7
/* 8006DA70 0006AA70  C1 23 00 18 */	lfs f9, 0x18(r3)
/* 8006DA74 0006AA74  11 88 62 3A */	ps_madd f12, f8, f8, f12
/* 8006DA78 0006AA78  E1 43 00 20 */	psq_l f10, 0x20(r3), 0, qr0
/* 8006DA7C 0006AA7C  ED A9 6A 7A */	fmadds f13, f9, f9, f13
/* 8006DA80 0006AA80  C1 63 00 28 */	lfs f11, 0x28(r3)
/* 8006DA84 0006AA84  11 8A 62 BA */	ps_madd f12, f10, f10, f12
/* 8006DA88 0006AA88  ED AB 6A FA */	fmadds f13, f11, f11, f13
/* 8006DA8C 0006AA8C  FC 20 60 90 */	fmr f1, f12
/* 8006DA90 0006AA90  4B FF F5 F9 */	bl approx_rsqrt
/* 8006DA94 0006AA94  FC 20 08 18 */	frsp f1, f1
/* 8006DA98 0006AA98  11 81 64 60 */	ps_merge01 f12, f1, f12
/* 8006DA9C 0006AA9C  10 2C 64 E0 */	ps_merge11 f1, f12, f12
/* 8006DAA0 0006AAA0  4B FF F5 E9 */	bl approx_rsqrt
/* 8006DAA4 0006AAA4  FC 20 08 18 */	frsp f1, f1
/* 8006DAA8 0006AAA8  10 2C 0C 20 */	ps_merge00 f1, f12, f1
/* 8006DAAC 0006AAAC  10 C6 00 72 */	ps_mul f6, f6, f1
/* 8006DAB0 0006AAB0  F0 C3 00 00 */	psq_st f6, 0x0(r3), 0, qr0
/* 8006DAB4 0006AAB4  11 08 00 72 */	ps_mul f8, f8, f1
/* 8006DAB8 0006AAB8  F1 03 00 10 */	psq_st f8, 0x10(r3), 0, qr0
/* 8006DABC 0006AABC  11 4A 00 72 */	ps_mul f10, f10, f1
/* 8006DAC0 0006AAC0  F1 43 00 20 */	psq_st f10, 0x20(r3), 0, qr0
/* 8006DAC4 0006AAC4  FC 20 68 90 */	fmr f1, f13
/* 8006DAC8 0006AAC8  4B FF F5 C1 */	bl approx_rsqrt
/* 8006DACC 0006AACC  7C 88 03 A6 */	mtlr r4
/* 8006DAD0 0006AAD0  EC E7 00 72 */	fmuls f7, f7, f1
/* 8006DAD4 0006AAD4  D0 E3 00 08 */	stfs f7, 0x8(r3)
/* 8006DAD8 0006AAD8  ED 29 00 72 */	fmuls f9, f9, f1
/* 8006DADC 0006AADC  D1 23 00 18 */	stfs f9, 0x18(r3)
/* 8006DAE0 0006AAE0  ED 6B 00 72 */	fmuls f11, f11, f1
/* 8006DAE4 0006AAE4  D1 63 00 28 */	stfs f11, 0x28(r3)
/* 8006DAE8 0006AAE8  4E 80 00 20 */	blr
.endfn lbl_8006DA50
