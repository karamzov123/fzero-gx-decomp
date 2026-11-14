.include "macros.inc"
.file "lbl_8006D95C.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# Upper 3x3 of mtxA = rotation about y.
# The rows are (c, 0, s), (0, 1, 0), (-s, 0, c). The (0, 1) pair comes through GQR2
# from the locked-cache constant bytes at +0x1AC.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Calls the sine/cosine routine with a hand-saved link register (mflr r4; bl; mtlr r4) and no
#   frame, which MWCC never emits for a C body; rows built with ps_merge (inline assembly only).
# - Source: the engine math library. Super Monkey Ball has no 3x3-only form of this routine.
#   Its 4x4 form mathutil_mtxA_from_rotate_y is an asm function:
#   https://github.com/camthesaxman/smb-decomp/blob/5cd6ffccf3f8508231c7cd9cce5b722be4465a2b/src/mathutil.c#L731-L773
#   Its C version is under `#ifdef C_ONLY`. Only the GCC build sets C_ONLY (Makefile L54),
#   so the matching build uses the asm.

# 0x8006D95C..0x8006D998 | size: 0x3C
.text
.balign 4

# .text:0x0 | 0x8006D95C | size: 0x3C
.fn lbl_8006D95C, global
/* 8006D95C 0006A95C  7C 88 02 A6 */	mflr r4
/* 8006D960 0006A960  4B FF F8 65 */	bl lbl_8006D1C4
/* 8006D964 0006A964  7C 88 03 A6 */	mtlr r4
/* 8006D968 0006A968  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D96C 0006A96C  FC 60 08 50 */	fneg f3, f1
/* 8006D970 0006A970  E0 84 21 AC */	psq_l f4, 0x1ac(r4), 0, qr2
/* 8006D974 0006A974  10 A2 24 20 */	ps_merge00 f5, f2, f4
/* 8006D978 0006A978  10 C3 24 20 */	ps_merge00 f6, f3, f4
/* 8006D97C 0006A97C  F0 A4 00 00 */	psq_st f5, 0x0(r4), 0, qr0
/* 8006D980 0006A980  D0 24 00 08 */	stfs f1, 0x8(r4)
/* 8006D984 0006A984  F0 84 00 10 */	psq_st f4, 0x10(r4), 0, qr0
/* 8006D988 0006A988  F0 84 80 18 */	psq_st f4, 0x18(r4), 1, qr0
/* 8006D98C 0006A98C  F0 C4 00 20 */	psq_st f6, 0x20(r4), 0, qr0
/* 8006D990 0006A990  D0 44 00 28 */	stfs f2, 0x28(r4)
/* 8006D994 0006A994  4E 80 00 20 */	blr
.endfn lbl_8006D95C
