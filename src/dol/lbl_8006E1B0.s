.include "macros.inc"
.file "lbl_8006E1B0.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# *dst = mtxA * (*src, 1); entries lbl_8006E1C0 (*dst = mtxA * (*src, 0)), lbl_8006E1D8 and
# lbl_8006E1F0 ((f1, f2, f3) as point / vector) and fn_8006E200, all sharing the row products at
# fn_8006E200+4 (SMB: mathutil_mtxA_tf_point with tf_vec, tf_point_xyz, tf_vec_xyz).
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# fn_8006E200 was never a separate routine: it is the last instruction of the tf_vec_xyz entry
# (`ps_merge00 f3, f3, f0`) followed by the shared tail, split off by dtk because a caller enters there;
# this unit absorbs the former asm unit fn_8006E200.
# - Entries follow an unconditional `b`, lbl_8006E1F0 falls through into fn_8006E200, and three
#   entries branch to fn_8006E200+4, an address no symbol names; paired-single psq_l/ps_mul/ps_madd/
#   ps_sum0 kernel.
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006E1B0..0x8006E250 | size: 0xA0
.text
.balign 4

# .text:0x0 | 0x8006E1B0 | size: 0xA0
.fn lbl_8006E1B0, global
/* 8006E1B0 0006B1B0  3C A0 E0 00 */	lis r5, 0xe000
/* 8006E1B4 0006B1B4  E0 23 00 00 */	psq_l f1, 0x0(r3), 0, qr0
/* 8006E1B8 0006B1B8  E0 63 80 08 */	psq_l f3, 0x8(r3), 1, qr0
/* 8006E1BC 0006B1BC  48 00 00 48 */	b .L_8006E204
# .text:0x10 | 0x8006E1C0 | size: 0x0
.sym lbl_8006E1C0, global
/* 8006E1C0 0006B1C0  3C A0 E0 00 */	lis r5, 0xe000
/* 8006E1C4 0006B1C4  C0 63 00 08 */	lfs f3, 0x8(r3)
/* 8006E1C8 0006B1C8  C0 05 01 98 */	lfs f0, 0x198(r5)
/* 8006E1CC 0006B1CC  E0 23 00 00 */	psq_l f1, 0x0(r3), 0, qr0
/* 8006E1D0 0006B1D0  10 63 04 20 */	ps_merge00 f3, f3, f0
/* 8006E1D4 0006B1D4  48 00 00 30 */	b .L_8006E204
# .text:0x28 | 0x8006E1D8 | size: 0x0
.sym lbl_8006E1D8, global
/* 8006E1D8 0006B1D8  3C A0 E0 00 */	lis r5, 0xe000
/* 8006E1DC 0006B1DC  10 21 14 20 */	ps_merge00 f1, f1, f2
/* 8006E1E0 0006B1E0  C0 05 01 9C */	lfs f0, 0x19c(r5)
/* 8006E1E4 0006B1E4  7C 64 1B 78 */	mr r4, r3
/* 8006E1E8 0006B1E8  10 63 04 20 */	ps_merge00 f3, f3, f0
/* 8006E1EC 0006B1EC  48 00 00 18 */	b .L_8006E204
# .text:0x40 | 0x8006E1F0 | size: 0x0
.sym lbl_8006E1F0, global
/* 8006E1F0 0006B1F0  3C A0 E0 00 */	lis r5, 0xe000
/* 8006E1F4 0006B1F4  10 21 14 20 */	ps_merge00 f1, f1, f2
/* 8006E1F8 0006B1F8  C0 05 01 98 */	lfs f0, 0x198(r5)
/* 8006E1FC 0006B1FC  7C 64 1B 78 */	mr r4, r3
# .text:0x50 | 0x8006E200 | size: 0x0
.sym fn_8006E200, global
/* 8006E200 0006B200  10 63 04 20 */	ps_merge00 f3, f3, f0
.L_8006E204:
/* 8006E204 0006B204  E0 85 00 00 */	psq_l f4, 0x0(r5), 0, qr0
/* 8006E208 0006B208  E0 C5 00 10 */	psq_l f6, 0x10(r5), 0, qr0
/* 8006E20C 0006B20C  10 84 00 72 */	ps_mul f4, f4, f1
/* 8006E210 0006B210  E1 05 00 20 */	psq_l f8, 0x20(r5), 0, qr0
/* 8006E214 0006B214  10 C6 00 72 */	ps_mul f6, f6, f1
/* 8006E218 0006B218  E0 A5 00 08 */	psq_l f5, 0x8(r5), 0, qr0
/* 8006E21C 0006B21C  11 08 00 72 */	ps_mul f8, f8, f1
/* 8006E220 0006B220  E0 E5 00 18 */	psq_l f7, 0x18(r5), 0, qr0
/* 8006E224 0006B224  10 85 20 FA */	ps_madd f4, f5, f3, f4
/* 8006E228 0006B228  E1 25 00 28 */	psq_l f9, 0x28(r5), 0, qr0
/* 8006E22C 0006B22C  10 C7 30 FA */	ps_madd f6, f7, f3, f6
/* 8006E230 0006B230  11 09 40 FA */	ps_madd f8, f9, f3, f8
/* 8006E234 0006B234  10 84 21 14 */	ps_sum0 f4, f4, f4, f4
/* 8006E238 0006B238  D0 84 00 00 */	stfs f4, 0x0(r4)
/* 8006E23C 0006B23C  10 C6 31 94 */	ps_sum0 f6, f6, f6, f6
/* 8006E240 0006B240  D0 C4 00 04 */	stfs f6, 0x4(r4)
/* 8006E244 0006B244  11 08 42 14 */	ps_sum0 f8, f8, f8, f8
/* 8006E248 0006B248  D1 04 00 08 */	stfs f8, 0x8(r4)
/* 8006E24C 0006B24C  4E 80 00 20 */	blr
.endfn lbl_8006E1B0
