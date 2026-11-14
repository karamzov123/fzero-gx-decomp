.include "macros.inc"
.file "fn_8006D830.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# mtxA = scale by *v; entries lbl_8006D848 (one factor in f1) and lbl_8006D860 (factors in f1-f3).
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - The entries follow an unconditional `b`; rows built with ps_merge and psq_l/psq_st, which only
#   inline assembly emits.
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D830..0x8006D890 | size: 0x60
.text
.balign 4

# .text:0x0 | 0x8006D830 | size: 0x60
.fn fn_8006D830, global
/* 8006D830 0006A830  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D834 0006A834  E0 23 00 00 */	psq_l f1, 0x0(r3), 0, qr0
/* 8006D838 0006A838  C0 84 01 98 */	lfs f4, 0x198(r4)
/* 8006D83C 0006A83C  C0 63 00 08 */	lfs f3, 0x8(r3)
/* 8006D840 0006A840  10 C4 0C 60 */	ps_merge01 f6, f4, f1
/* 8006D844 0006A844  48 00 00 28 */	b .L_8006D86C
# .text:0x18 | 0x8006D848 | size: 0x0
.sym lbl_8006D848, global
/* 8006D848 0006A848  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D84C 0006A84C  FC 60 08 90 */	fmr f3, f1
/* 8006D850 0006A850  C0 84 01 98 */	lfs f4, 0x198(r4)
/* 8006D854 0006A854  10 21 0C 20 */	ps_merge00 f1, f1, f1
/* 8006D858 0006A858  10 C4 0C 60 */	ps_merge01 f6, f4, f1
/* 8006D85C 0006A85C  48 00 00 10 */	b .L_8006D86C
# .text:0x30 | 0x8006D860 | size: 0x0
.sym lbl_8006D860, global
/* 8006D860 0006A860  3C 80 E0 00 */	lis r4, 0xe000
/* 8006D864 0006A864  C0 84 01 98 */	lfs f4, 0x198(r4)
/* 8006D868 0006A868  10 C4 14 20 */	ps_merge00 f6, f4, f2
.L_8006D86C:
/* 8006D86C 0006A86C  10 A1 24 20 */	ps_merge00 f5, f1, f4
/* 8006D870 0006A870  10 E3 24 20 */	ps_merge00 f7, f3, f4
/* 8006D874 0006A874  F0 84 00 08 */	psq_st f4, 0x8(r4), 0, qr0
/* 8006D878 0006A878  F0 84 00 18 */	psq_st f4, 0x18(r4), 0, qr0
/* 8006D87C 0006A87C  F0 84 00 20 */	psq_st f4, 0x20(r4), 0, qr0
/* 8006D880 0006A880  F0 A4 00 00 */	psq_st f5, 0x0(r4), 0, qr0
/* 8006D884 0006A884  F0 C4 00 10 */	psq_st f6, 0x10(r4), 0, qr0
/* 8006D888 0006A888  F0 E4 00 28 */	psq_st f7, 0x28(r4), 0, qr0
/* 8006D88C 0006A88C  4E 80 00 20 */	blr
.endfn fn_8006D830
