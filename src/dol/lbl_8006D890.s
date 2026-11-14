.include "macros.inc"
.file "lbl_8006D890.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# mtxA = rotation about x by an s16 angle; entry lbl_8006D89C (+0xC, called by main_rel shadowmap.c
# fn_1_568F8) takes sin/cos already in f1/f2.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Calls the sine/cosine routine with a hand-saved link register (mflr r4; bl; mtlr r4) and no
#   frame; the fall-through entry must stay a global symbol at +0xC.
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D890..0x8006D8D8 | size: 0x48
.text
.balign 4

# .text:0x0 | 0x8006D890 | size: 0x48
.fn lbl_8006D890, global
/* 8006D890 0006A890  7C 88 02 A6 */	mflr r4
/* 8006D894 0006A894  4B FF F9 31 */	bl lbl_8006D1C4
/* 8006D898 0006A898  7C 88 03 A6 */	mtlr r4
# .text:0xC | 0x8006D89C | size: 0x0
.sym lbl_8006D89C, global
/* 8006D89C 0006A89C  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D8A0 0006A8A0  FC 60 08 50 */	fneg f3, f1
/* 8006D8A4 0006A8A4  E0 84 21 AE */	psq_l f4, 0x1ae(r4), 0, qr2
/* 8006D8A8 0006A8A8  10 C4 24 E0 */	ps_merge11 f6, f4, f4
/* 8006D8AC 0006A8AC  10 E4 14 A0 */	ps_merge10 f7, f4, f2
/* 8006D8B0 0006A8B0  11 03 24 60 */	ps_merge01 f8, f3, f4
/* 8006D8B4 0006A8B4  11 24 0C A0 */	ps_merge10 f9, f4, f1
/* 8006D8B8 0006A8B8  11 42 24 60 */	ps_merge01 f10, f2, f4
/* 8006D8BC 0006A8BC  F0 84 00 00 */	psq_st f4, 0x0(r4), 0, qr0
/* 8006D8C0 0006A8C0  F0 C4 00 08 */	psq_st f6, 0x8(r4), 0, qr0
/* 8006D8C4 0006A8C4  F1 04 00 18 */	psq_st f8, 0x18(r4), 0, qr0
/* 8006D8C8 0006A8C8  F0 E4 00 10 */	psq_st f7, 0x10(r4), 0, qr0
/* 8006D8CC 0006A8CC  F1 24 00 20 */	psq_st f9, 0x20(r4), 0, qr0
/* 8006D8D0 0006A8D0  F1 44 00 28 */	psq_st f10, 0x28(r4), 0, qr0
/* 8006D8D4 0006A8D4  4E 80 00 20 */	blr
.endfn lbl_8006D890
