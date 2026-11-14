.include "macros.inc"
.file "lbl_8006E13C.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# Scale mtxA's columns; entries lbl_8006E14C, lbl_8006E15C (SMB: mathutil_mtxA_scale, _s, _xyz).
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Every further entry follows an unconditional `b` and is called directly by main.dol and
#   main_rel; paired-single kernel (psq_l/psq_st, ps_mul) that only inline assembly emits.
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006E13C..0x8006E1B0 | size: 0x74
.text
.balign 4

# .text:0x0 | 0x8006E13C | size: 0x74
.fn lbl_8006E13C, global
/* 8006E13C 0006B13C  E0 23 00 00 */	psq_l f1, 0x0(r3), 0, qr0
/* 8006E140 0006B140  3C 80 E0 00 */	lis r4, 0xe000
/* 8006E144 0006B144  C0 63 00 08 */	lfs f3, 0x8(r3)
/* 8006E148 0006B148  48 00 00 1C */	b .L_8006E164
# .text:0x10 | 0x8006E14C | size: 0x0
.sym lbl_8006E14C, global
/* 8006E14C 0006B14C  3C 80 E0 00 */	lis r4, 0xe000
/* 8006E150 0006B150  FC 60 08 90 */	fmr f3, f1
/* 8006E154 0006B154  10 21 0C 20 */	ps_merge00 f1, f1, f1
/* 8006E158 0006B158  48 00 00 0C */	b .L_8006E164
# .text:0x20 | 0x8006E15C | size: 0x0
.sym lbl_8006E15C, global
/* 8006E15C 0006B15C  3C 80 E0 00 */	lis r4, 0xe000
/* 8006E160 0006B160  10 21 14 20 */	ps_merge00 f1, f1, f2
.L_8006E164:
/* 8006E164 0006B164  E0 04 00 00 */	psq_l f0, 0x0(r4), 0, qr0
/* 8006E168 0006B168  C0 84 00 08 */	lfs f4, 0x8(r4)
/* 8006E16C 0006B16C  E0 A4 00 10 */	psq_l f5, 0x10(r4), 0, qr0
/* 8006E170 0006B170  10 00 00 72 */	ps_mul f0, f0, f1
/* 8006E174 0006B174  C0 C4 00 18 */	lfs f6, 0x18(r4)
/* 8006E178 0006B178  EC 84 00 F2 */	fmuls f4, f4, f3
/* 8006E17C 0006B17C  E0 E4 00 20 */	psq_l f7, 0x20(r4), 0, qr0
/* 8006E180 0006B180  C1 04 00 28 */	lfs f8, 0x28(r4)
/* 8006E184 0006B184  10 A5 00 72 */	ps_mul f5, f5, f1
/* 8006E188 0006B188  F0 04 00 00 */	psq_st f0, 0x0(r4), 0, qr0
/* 8006E18C 0006B18C  EC C6 00 F2 */	fmuls f6, f6, f3
/* 8006E190 0006B190  D0 84 00 08 */	stfs f4, 0x8(r4)
/* 8006E194 0006B194  F0 A4 00 10 */	psq_st f5, 0x10(r4), 0, qr0
/* 8006E198 0006B198  10 E7 00 72 */	ps_mul f7, f7, f1
/* 8006E19C 0006B19C  D0 C4 00 18 */	stfs f6, 0x18(r4)
/* 8006E1A0 0006B1A0  F0 E4 00 20 */	psq_st f7, 0x20(r4), 0, qr0
/* 8006E1A4 0006B1A4  ED 08 00 F2 */	fmuls f8, f8, f3
/* 8006E1A8 0006B1A8  D1 04 00 28 */	stfs f8, 0x28(r4)
/* 8006E1AC 0006B1AC  4E 80 00 20 */	blr
.endfn lbl_8006E13C
