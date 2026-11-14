.include "macros.inc"
.file "lbl_8006D9D8.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# mtxA = mtxB translated by *v; entry lbl_8006D9E8 takes the vector in f1-f3.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - The entry follows an unconditional `b`; paired-single psq_l/psq_st, ps_merge and
#   ps_mul/ps_madd/ps_sum1 rows, which only inline assembly emits.
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D9D8..0x8006DA50 | size: 0x78
.text
.balign 4

# .text:0x0 | 0x8006D9D8 | size: 0x78
.fn lbl_8006D9D8, global
/* 8006D9D8 0006A9D8  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D9DC 0006A9DC  E0 23 00 00 */	psq_l f1, 0x0(r3), 0, qr0
/* 8006D9E0 0006A9E0  E0 63 80 08 */	psq_l f3, 0x8(r3), 1, qr0
/* 8006D9E4 0006A9E4  48 00 00 14 */	b .L_8006D9F8
# .text:0x10 | 0x8006D9E8 | size: 0x0
.sym lbl_8006D9E8, global
/* 8006D9E8 0006A9E8  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D9EC 0006A9EC  C0 84 01 9C */	lfs f4, 0x19c(r4)
/* 8006D9F0 0006A9F0  10 21 14 20 */	ps_merge00 f1, f1, f2
/* 8006D9F4 0006A9F4  10 63 24 20 */	ps_merge00 f3, f3, f4
.L_8006D9F8:
/* 8006D9F8 0006A9F8  E0 84 00 30 */	psq_l f4, 0x30(r4), 0, qr0
/* 8006D9FC 0006A9FC  F0 84 00 00 */	psq_st f4, 0x0(r4), 0, qr0
/* 8006DA00 0006AA00  10 84 00 72 */	ps_mul f4, f4, f1
/* 8006DA04 0006AA04  E0 C4 00 40 */	psq_l f6, 0x40(r4), 0, qr0
/* 8006DA08 0006AA08  F0 C4 00 10 */	psq_st f6, 0x10(r4), 0, qr0
/* 8006DA0C 0006AA0C  10 C6 00 72 */	ps_mul f6, f6, f1
/* 8006DA10 0006AA10  E1 04 00 50 */	psq_l f8, 0x50(r4), 0, qr0
/* 8006DA14 0006AA14  F1 04 00 20 */	psq_st f8, 0x20(r4), 0, qr0
/* 8006DA18 0006AA18  11 08 00 72 */	ps_mul f8, f8, f1
/* 8006DA1C 0006AA1C  E0 A4 00 38 */	psq_l f5, 0x38(r4), 0, qr0
/* 8006DA20 0006AA20  10 85 20 FA */	ps_madd f4, f5, f3, f4
/* 8006DA24 0006AA24  E0 E4 00 48 */	psq_l f7, 0x48(r4), 0, qr0
/* 8006DA28 0006AA28  10 C7 30 FA */	ps_madd f6, f7, f3, f6
/* 8006DA2C 0006AA2C  E1 24 00 58 */	psq_l f9, 0x58(r4), 0, qr0
/* 8006DA30 0006AA30  11 09 40 FA */	ps_madd f8, f9, f3, f8
/* 8006DA34 0006AA34  10 A4 21 56 */	ps_sum1 f5, f4, f5, f4
/* 8006DA38 0006AA38  F0 A4 00 08 */	psq_st f5, 0x8(r4), 0, qr0
/* 8006DA3C 0006AA3C  10 E6 31 D6 */	ps_sum1 f7, f6, f7, f6
/* 8006DA40 0006AA40  F0 E4 00 18 */	psq_st f7, 0x18(r4), 0, qr0
/* 8006DA44 0006AA44  11 28 42 56 */	ps_sum1 f9, f8, f9, f8
/* 8006DA48 0006AA48  F1 24 00 28 */	psq_st f9, 0x28(r4), 0, qr0
/* 8006DA4C 0006AA4C  4E 80 00 20 */	blr
.endfn lbl_8006D9D8
