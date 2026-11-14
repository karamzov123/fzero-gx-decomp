.include "macros.inc"
.file "lbl_8006E0A4.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# Translate mtxA in its own frame; entries lbl_8006E0B4, lbl_8006E0C8, lbl_8006E0D8 (SMB:
# mathutil_mtxA_translate, _xyz, _neg, _neg_xyz).
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Every further entry follows an unconditional `b` and is called directly by main.dol and
#   main_rel; paired-single kernel (psq_l, ps_mul/ps_madd) that only inline assembly emits.
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006E0A4..0x8006E13C | size: 0x98
.text
.balign 4

# .text:0x0 | 0x8006E0A4 | size: 0x98
.fn lbl_8006E0A4, global
/* 8006E0A4 0006B0A4  3C 80 E0 00 */	lis r4, 0xe000
/* 8006E0A8 0006B0A8  E0 23 00 00 */	psq_l f1, 0x0(r3), 0, qr0
/* 8006E0AC 0006B0AC  E0 63 80 08 */	psq_l f3, 0x8(r3), 1, qr0
/* 8006E0B0 0006B0B0  48 00 00 40 */	b .L_8006E0F0
# .text:0x10 | 0x8006E0B4 | size: 0x0
.sym lbl_8006E0B4, global
/* 8006E0B4 0006B0B4  3C 80 E0 00 */	lis r4, 0xe000
/* 8006E0B8 0006B0B8  10 21 14 20 */	ps_merge00 f1, f1, f2
/* 8006E0BC 0006B0BC  C0 04 01 9C */	lfs f0, 0x19c(r4)
/* 8006E0C0 0006B0C0  10 63 04 20 */	ps_merge00 f3, f3, f0
/* 8006E0C4 0006B0C4  48 00 00 2C */	b .L_8006E0F0
# .text:0x24 | 0x8006E0C8 | size: 0x0
.sym lbl_8006E0C8, global
/* 8006E0C8 0006B0C8  3C 80 E0 00 */	lis r4, 0xe000
/* 8006E0CC 0006B0CC  C0 63 00 08 */	lfs f3, 0x8(r3)
/* 8006E0D0 0006B0D0  E0 23 00 00 */	psq_l f1, 0x0(r3), 0, qr0
/* 8006E0D4 0006B0D4  48 00 00 0C */	b .L_8006E0E0
# .text:0x34 | 0x8006E0D8 | size: 0x0
.sym lbl_8006E0D8, global
/* 8006E0D8 0006B0D8  3C 80 E0 00 */	lis r4, 0xe000
/* 8006E0DC 0006B0DC  10 21 14 20 */	ps_merge00 f1, f1, f2
.L_8006E0E0:
/* 8006E0E0 0006B0E0  C0 04 01 9C */	lfs f0, 0x19c(r4)
/* 8006E0E4 0006B0E4  FC 60 18 50 */	fneg f3, f3
/* 8006E0E8 0006B0E8  10 20 08 50 */	ps_neg f1, f1
/* 8006E0EC 0006B0EC  10 63 04 20 */	ps_merge00 f3, f3, f0
.L_8006E0F0:
/* 8006E0F0 0006B0F0  E0 84 00 00 */	psq_l f4, 0x0(r4), 0, qr0
/* 8006E0F4 0006B0F4  E0 C4 00 10 */	psq_l f6, 0x10(r4), 0, qr0
/* 8006E0F8 0006B0F8  E1 04 00 20 */	psq_l f8, 0x20(r4), 0, qr0
/* 8006E0FC 0006B0FC  10 84 00 72 */	ps_mul f4, f4, f1
/* 8006E100 0006B100  E0 A4 00 08 */	psq_l f5, 0x8(r4), 0, qr0
/* 8006E104 0006B104  10 C6 00 72 */	ps_mul f6, f6, f1
/* 8006E108 0006B108  E0 E4 00 18 */	psq_l f7, 0x18(r4), 0, qr0
/* 8006E10C 0006B10C  11 08 00 72 */	ps_mul f8, f8, f1
/* 8006E110 0006B110  E1 24 00 28 */	psq_l f9, 0x28(r4), 0, qr0
/* 8006E114 0006B114  10 85 20 FA */	ps_madd f4, f5, f3, f4
/* 8006E118 0006B118  10 C7 30 FA */	ps_madd f6, f7, f3, f6
/* 8006E11C 0006B11C  11 09 40 FA */	ps_madd f8, f9, f3, f8
/* 8006E120 0006B120  10 84 21 14 */	ps_sum0 f4, f4, f4, f4
/* 8006E124 0006B124  D0 84 00 0C */	stfs f4, 0xc(r4)
/* 8006E128 0006B128  10 C6 31 94 */	ps_sum0 f6, f6, f6, f6
/* 8006E12C 0006B12C  D0 C4 00 1C */	stfs f6, 0x1c(r4)
/* 8006E130 0006B130  11 08 42 14 */	ps_sum0 f8, f8, f8, f8
/* 8006E134 0006B134  D1 04 00 2C */	stfs f8, 0x2c(r4)
/* 8006E138 0006B138  4E 80 00 20 */	blr
.endfn lbl_8006E0A4
