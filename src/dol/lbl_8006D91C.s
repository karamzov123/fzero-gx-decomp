.include "macros.inc"
.file "lbl_8006D91C.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# mtxA = rotation about z.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Calls the sine/cosine routine with a hand-saved link register (mflr r4; bl; mtlr r4) and no
#   frame, which MWCC never emits for a C body; rows built with ps_merge (inline assembly only).
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D91C..0x8006D95C | size: 0x40
.text
.balign 4

# .text:0x0 | 0x8006D91C | size: 0x40
.fn lbl_8006D91C, global
/* 8006D91C 0006A91C  7C 88 02 A6 */	mflr r4
/* 8006D920 0006A920  4B FF F8 A5 */	bl lbl_8006D1C4
/* 8006D924 0006A924  7C 88 03 A6 */	mtlr r4
/* 8006D928 0006A928  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D92C 0006A92C  FC 60 08 50 */	fneg f3, f1
/* 8006D930 0006A930  E0 84 21 AE */	psq_l f4, 0x1ae(r4), 0, qr2
/* 8006D934 0006A934  10 A2 1C 20 */	ps_merge00 f5, f2, f3
/* 8006D938 0006A938  10 C4 24 E0 */	ps_merge11 f6, f4, f4
/* 8006D93C 0006A93C  10 E1 14 20 */	ps_merge00 f7, f1, f2
/* 8006D940 0006A940  F0 A4 00 00 */	psq_st f5, 0x0(r4), 0, qr0
/* 8006D944 0006A944  F0 C4 00 08 */	psq_st f6, 0x8(r4), 0, qr0
/* 8006D948 0006A948  F0 E4 00 10 */	psq_st f7, 0x10(r4), 0, qr0
/* 8006D94C 0006A94C  F0 C4 00 18 */	psq_st f6, 0x18(r4), 0, qr0
/* 8006D950 0006A950  F0 C4 00 20 */	psq_st f6, 0x20(r4), 0, qr0
/* 8006D954 0006A954  F0 84 00 28 */	psq_st f4, 0x28(r4), 0, qr0
/* 8006D958 0006A958  4E 80 00 20 */	blr
.endfn lbl_8006D91C
