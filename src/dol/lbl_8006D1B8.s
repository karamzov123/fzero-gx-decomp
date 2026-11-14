.include "macros.inc"
.file "lbl_8006D1B8.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# Table sine/cosine of an s16 angle (quarter-wave table lbl_80132820). Entries lbl_8006D1BC (sin/cos
# stored through r4/r5) and lbl_8006D1C4 (returned in f1/f2, called by the rotation routines and many
# main_rel functions); the result form is selected by cr1[eq] set by the entry (crclr/crset).
# - Entry points reached directly, lbl_8006D1C4 after an unconditional `b`; a cr1 argument no C calling
#   convention expresses (SMB: mathutil_sin_cos_v).
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006D1B8..0x8006D21C | size: 0x64
.text
.balign 4

# .text:0x0 | 0x8006D1B8 | size: 0x64
.fn lbl_8006D1B8, global
/* 8006D1B8 0006A1B8  38 A4 00 04 */	addi r5, r4, 0x4
# .text:0x4 | 0x8006D1BC | size: 0x0
.sym lbl_8006D1BC, global
/* 8006D1BC 0006A1BC  4C C6 31 82 */	crclr cr1eq
/* 8006D1C0 0006A1C0  48 00 00 08 */	b .L_8006D1C8
# .text:0xC | 0x8006D1C4 | size: 0x0
.sym lbl_8006D1C4, global
/* 8006D1C4 0006A1C4  4C C6 32 42 */	crset cr1eq
.L_8006D1C8:
/* 8006D1C8 0006A1C8  54 68 80 02 */	extlwi r8, r3, 2, 16
/* 8006D1CC 0006A1CC  54 66 04 BE */	clrlwi r6, r3, 18
/* 8006D1D0 0006A1D0  7D 08 01 20 */	mtcrf 128, r8
/* 8006D1D4 0006A1D4  4C 40 09 82 */	crxor eq, lt, gt
/* 8006D1D8 0006A1D8  40 81 00 08 */	ble .L_8006D1E0
/* 8006D1DC 0006A1DC  20 C6 40 00 */	subfic r6, r6, 0x4000
.L_8006D1E0:
/* 8006D1E0 0006A1E0  20 E6 40 00 */	subfic r7, r6, 0x4000
/* 8006D1E4 0006A1E4  3D 00 80 13 */	lis r8, lbl_80132820@h
/* 8006D1E8 0006A1E8  54 C6 10 3A */	slwi r6, r6, 2
/* 8006D1EC 0006A1EC  61 08 28 20 */	ori r8, r8, lbl_80132820@l
/* 8006D1F0 0006A1F0  54 E7 10 3A */	slwi r7, r7, 2
/* 8006D1F4 0006A1F4  7C 28 34 2E */	lfsx f1, r8, r6
/* 8006D1F8 0006A1F8  7C 48 3C 2E */	lfsx f2, r8, r7
/* 8006D1FC 0006A1FC  40 80 00 08 */	bge .L_8006D204
/* 8006D200 0006A200  FC 20 09 10 */	fnabs f1, f1
.L_8006D204:
/* 8006D204 0006A204  40 82 00 08 */	bne .L_8006D20C
/* 8006D208 0006A208  FC 40 11 10 */	fnabs f2, f2
.L_8006D20C:
/* 8006D20C 0006A20C  4D 86 00 20 */	beqlr cr1
/* 8006D210 0006A210  D0 24 00 00 */	stfs f1, 0x0(r4)
/* 8006D214 0006A214  D0 45 00 00 */	stfs f2, 0x0(r5)
/* 8006D218 0006A218  4E 80 00 20 */	blr
.endfn lbl_8006D1B8
