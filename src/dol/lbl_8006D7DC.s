.include "macros.inc"
.file "lbl_8006D7DC.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# mtxA = translation by *v; entry lbl_8006D7F4 takes the vector in f1-f3.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - The entry follows an unconditional `b`; rows built with ps_merge and psq_l/psq_st, including
#   quantized constant loads through GQR2, which only inline assembly emits.
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D7DC..0x8006D830 | size: 0x54
.text
.balign 4

# .text:0x0 | 0x8006D7DC | size: 0x54
.fn lbl_8006D7DC, global
/* 8006D7DC 0006A7DC  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D7E0 0006A7E0  E0 23 00 00 */	psq_l f1, 0x0(r3), 0, qr0
/* 8006D7E4 0006A7E4  C0 84 01 98 */	lfs f4, 0x198(r4)
/* 8006D7E8 0006A7E8  C0 63 00 08 */	lfs f3, 0x8(r3)
/* 8006D7EC 0006A7EC  11 24 0C 60 */	ps_merge01 f9, f4, f1
/* 8006D7F0 0006A7F0  48 00 00 10 */	b .L_8006D800
# .text:0x18 | 0x8006D7F4 | size: 0x0
.sym lbl_8006D7F4, global
/* 8006D7F4 0006A7F4  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D7F8 0006A7F8  C0 84 01 98 */	lfs f4, 0x198(r4)
/* 8006D7FC 0006A7FC  11 24 14 20 */	ps_merge00 f9, f4, f2
.L_8006D800:
/* 8006D800 0006A800  C0 E4 01 9C */	lfs f7, 0x19c(r4)
/* 8006D804 0006A804  11 04 0C 20 */	ps_merge00 f8, f4, f1
/* 8006D808 0006A808  11 47 1C 20 */	ps_merge00 f10, f7, f3
/* 8006D80C 0006A80C  E0 A4 21 AC */	psq_l f5, 0x1ac(r4), 0, qr2
/* 8006D810 0006A810  E0 C4 21 AE */	psq_l f6, 0x1ae(r4), 0, qr2
/* 8006D814 0006A814  F0 84 00 20 */	psq_st f4, 0x20(r4), 0, qr0
/* 8006D818 0006A818  F1 04 00 08 */	psq_st f8, 0x8(r4), 0, qr0
/* 8006D81C 0006A81C  F1 24 00 18 */	psq_st f9, 0x18(r4), 0, qr0
/* 8006D820 0006A820  F1 44 00 28 */	psq_st f10, 0x28(r4), 0, qr0
/* 8006D824 0006A824  F0 A4 00 10 */	psq_st f5, 0x10(r4), 0, qr0
/* 8006D828 0006A828  F0 C4 00 00 */	psq_st f6, 0x0(r4), 0, qr0
/* 8006D82C 0006A82C  4E 80 00 20 */	blr
.endfn lbl_8006D7DC
