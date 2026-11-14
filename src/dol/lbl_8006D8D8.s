.include "macros.inc"
.file "lbl_8006D8D8.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# mtxA = rotation about y by an s16 angle; entry lbl_8006D8E4 (+0xC, called by main_rel camera.c
# fn_1_90E0) takes sin/cos already in f1/f2.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Calls the sine/cosine routine with a hand-saved link register (mflr r4; bl; mtlr r4) and no
#   frame; the fall-through entry must stay a global symbol at +0xC.
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D8D8..0x8006D91C | size: 0x44
.text
.balign 4

# .text:0x0 | 0x8006D8D8 | size: 0x44
.fn lbl_8006D8D8, global
/* 8006D8D8 0006A8D8  7C 88 02 A6 */	mflr r4
/* 8006D8DC 0006A8DC  4B FF F8 E9 */	bl lbl_8006D1C4
/* 8006D8E0 0006A8E0  7C 88 03 A6 */	mtlr r4
# .text:0xC | 0x8006D8E4 | size: 0x0
.sym lbl_8006D8E4, global
/* 8006D8E4 0006A8E4  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D8E8 0006A8E8  FC 60 08 50 */	fneg f3, f1
/* 8006D8EC 0006A8EC  E0 84 21 AC */	psq_l f4, 0x1ac(r4), 0, qr2
/* 8006D8F0 0006A8F0  10 A2 24 20 */	ps_merge00 f5, f2, f4
/* 8006D8F4 0006A8F4  10 C1 24 20 */	ps_merge00 f6, f1, f4
/* 8006D8F8 0006A8F8  11 04 24 20 */	ps_merge00 f8, f4, f4
/* 8006D8FC 0006A8FC  11 23 24 20 */	ps_merge00 f9, f3, f4
/* 8006D900 0006A900  F0 A4 00 00 */	psq_st f5, 0x0(r4), 0, qr0
/* 8006D904 0006A904  F0 C4 00 08 */	psq_st f6, 0x8(r4), 0, qr0
/* 8006D908 0006A908  F0 84 00 10 */	psq_st f4, 0x10(r4), 0, qr0
/* 8006D90C 0006A90C  F1 04 00 18 */	psq_st f8, 0x18(r4), 0, qr0
/* 8006D910 0006A910  F1 24 00 20 */	psq_st f9, 0x20(r4), 0, qr0
/* 8006D914 0006A914  F0 A4 00 28 */	psq_st f5, 0x28(r4), 0, qr0
/* 8006D918 0006A918  4E 80 00 20 */	blr
.endfn lbl_8006D8D8
