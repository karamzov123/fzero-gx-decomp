.include "macros.inc"
.file "lbl_8006D998.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# Upper 3x3 of mtxA = rotation about z.
# The rows are (c, -s, 0), (s, c, 0), (0, 0, 1). The (1, 0) pair comes through GQR2
# from the locked-cache constant bytes at +0x1AE.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Calls the sine/cosine routine with a hand-saved link register (mflr r4; bl; mtlr r4) and no
#   frame, which MWCC never emits for a C body; rows built with ps_merge (inline assembly only).
# - Source: the engine math library. Super Monkey Ball has no 3x3-only form of this routine.
#   Its 4x4 form mathutil_mtxA_from_rotate_z is an asm function:
#   https://github.com/camthesaxman/smb-decomp/blob/5cd6ffccf3f8508231c7cd9cce5b722be4465a2b/src/mathutil.c#L775-L816
#   Its C version is under `#ifdef C_ONLY`. Only the GCC build sets C_ONLY (Makefile L54),
#   so the matching build uses the asm.

# 0x8006D998..0x8006D9D8 | size: 0x40
.text
.balign 4

# .text:0x0 | 0x8006D998 | size: 0x40
.fn lbl_8006D998, global
/* 8006D998 0006A998  7C 88 02 A6 */	mflr r4
/* 8006D99C 0006A99C  4B FF F8 29 */	bl lbl_8006D1C4
/* 8006D9A0 0006A9A0  7C 88 03 A6 */	mtlr r4
/* 8006D9A4 0006A9A4  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D9A8 0006A9A8  E0 84 21 AE */	psq_l f4, 0x1ae(r4), 0, qr2
/* 8006D9AC 0006A9AC  FC 60 08 50 */	fneg f3, f1
/* 8006D9B0 0006A9B0  10 C1 14 20 */	ps_merge00 f6, f1, f2
/* 8006D9B4 0006A9B4  10 A2 1C 20 */	ps_merge00 f5, f2, f3
/* 8006D9B8 0006A9B8  10 E4 24 E0 */	ps_merge11 f7, f4, f4
/* 8006D9BC 0006A9BC  F0 C4 00 10 */	psq_st f6, 0x10(r4), 0, qr0
/* 8006D9C0 0006A9C0  F0 A4 00 00 */	psq_st f5, 0x0(r4), 0, qr0
/* 8006D9C4 0006A9C4  F0 E4 80 08 */	psq_st f7, 0x8(r4), 1, qr0
/* 8006D9C8 0006A9C8  F0 E4 80 18 */	psq_st f7, 0x18(r4), 1, qr0
/* 8006D9CC 0006A9CC  F0 E4 00 20 */	psq_st f7, 0x20(r4), 0, qr0
/* 8006D9D0 0006A9D0  F0 84 80 28 */	psq_st f4, 0x28(r4), 1, qr0
/* 8006D9D4 0006A9D4  4E 80 00 20 */	blr
.endfn lbl_8006D998
