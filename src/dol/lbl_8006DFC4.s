.include "macros.inc"
.file "lbl_8006DFC4.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# mtxA = mtxA * mtx; entries lbl_8006DFD8, lbl_8006DFE8, lbl_8006DFFC (SMB: mathutil_mtxA_mult_right,
# _mult_left, _from_mtxB_mult_mtx, mtx_mult).
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Every further entry follows an unconditional `b` and is called directly by main.dol and
#   main_rel; the shared body is a paired-single kernel (ps_muls0/ps_madds0/ps_madds1, psq_l/psq_st)
#   that only inline assembly emits.
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DFC4..0x8006E0A4 | size: 0xE0
.text
.balign 4

# .text:0x0 | 0x8006DFC4 | size: 0xE0
.fn lbl_8006DFC4, global
/* 8006DFC4 0006AFC4  3C C0 E0 00 */	lis r6, 0xe000
/* 8006DFC8 0006AFC8  7C 64 1B 78 */	mr r4, r3
/* 8006DFCC 0006AFCC  38 66 00 00 */	addi r3, r6, 0x0
/* 8006DFD0 0006AFD0  38 A6 00 00 */	addi r5, r6, 0x0
/* 8006DFD4 0006AFD4  48 00 00 2C */	b .L_8006E000
# .text:0x14 | 0x8006DFD8 | size: 0x0
.sym lbl_8006DFD8, global
/* 8006DFD8 0006AFD8  3C C0 E0 00 */	lis r6, 0xe000
/* 8006DFDC 0006AFDC  38 86 00 00 */	addi r4, r6, 0x0
/* 8006DFE0 0006AFE0  38 A6 00 00 */	addi r5, r6, 0x0
/* 8006DFE4 0006AFE4  48 00 00 1C */	b .L_8006E000
# .text:0x24 | 0x8006DFE8 | size: 0x0
.sym lbl_8006DFE8, global
/* 8006DFE8 0006AFE8  3C C0 E0 00 */	lis r6, 0xe000
/* 8006DFEC 0006AFEC  7C 64 1B 78 */	mr r4, r3
/* 8006DFF0 0006AFF0  38 66 00 30 */	addi r3, r6, 0x30
/* 8006DFF4 0006AFF4  38 A6 00 00 */	addi r5, r6, 0x0
/* 8006DFF8 0006AFF8  48 00 00 08 */	b .L_8006E000
# .text:0x38 | 0x8006DFFC | size: 0x0
.sym lbl_8006DFFC, global
/* 8006DFFC 0006AFFC  3C C0 E0 00 */	lis r6, 0xe000
.L_8006E000:
/* 8006E000 0006B000  E0 04 00 00 */	psq_l f0, 0x0(r4), 0, qr0
/* 8006E004 0006B004  E1 63 00 00 */	psq_l f11, 0x0(r3), 0, qr0
/* 8006E008 0006B008  E0 24 00 08 */	psq_l f1, 0x8(r4), 0, qr0
/* 8006E00C 0006B00C  E1 83 00 10 */	psq_l f12, 0x10(r3), 0, qr0
/* 8006E010 0006B010  E0 44 00 10 */	psq_l f2, 0x10(r4), 0, qr0
/* 8006E014 0006B014  10 A0 02 D8 */	ps_muls0 f5, f0, f11
/* 8006E018 0006B018  E1 A3 00 20 */	psq_l f13, 0x20(r3), 0, qr0
/* 8006E01C 0006B01C  10 E0 03 18 */	ps_muls0 f7, f0, f12
/* 8006E020 0006B020  E0 64 00 18 */	psq_l f3, 0x18(r4), 0, qr0
/* 8006E024 0006B024  11 20 03 58 */	ps_muls0 f9, f0, f13
/* 8006E028 0006B028  10 C1 02 D8 */	ps_muls0 f6, f1, f11
/* 8006E02C 0006B02C  E0 84 00 20 */	psq_l f4, 0x20(r4), 0, qr0
/* 8006E030 0006B030  11 01 03 18 */	ps_muls0 f8, f1, f12
/* 8006E034 0006B034  11 41 03 58 */	ps_muls0 f10, f1, f13
/* 8006E038 0006B038  E0 04 00 28 */	psq_l f0, 0x28(r4), 0, qr0
/* 8006E03C 0006B03C  10 A2 2A DE */	ps_madds1 f5, f2, f11, f5
/* 8006E040 0006B040  10 E2 3B 1E */	ps_madds1 f7, f2, f12, f7
/* 8006E044 0006B044  E0 23 00 08 */	psq_l f1, 0x8(r3), 0, qr0
/* 8006E048 0006B048  11 22 4B 5E */	ps_madds1 f9, f2, f13, f9
/* 8006E04C 0006B04C  10 C3 32 DE */	ps_madds1 f6, f3, f11, f6
/* 8006E050 0006B050  E0 43 00 18 */	psq_l f2, 0x18(r3), 0, qr0
/* 8006E054 0006B054  11 03 43 1E */	ps_madds1 f8, f3, f12, f8
/* 8006E058 0006B058  11 43 53 5E */	ps_madds1 f10, f3, f13, f10
/* 8006E05C 0006B05C  E0 63 00 28 */	psq_l f3, 0x28(r3), 0, qr0
/* 8006E060 0006B060  10 A4 28 5C */	ps_madds0 f5, f4, f1, f5
/* 8006E064 0006B064  10 E4 38 9C */	ps_madds0 f7, f4, f2, f7
/* 8006E068 0006B068  E1 66 21 AC */	psq_l f11, 0x1ac(r6), 0, qr2
/* 8006E06C 0006B06C  11 24 48 DC */	ps_madds0 f9, f4, f3, f9
/* 8006E070 0006B070  10 C0 30 5C */	ps_madds0 f6, f0, f1, f6
/* 8006E074 0006B074  F0 A5 00 00 */	psq_st f5, 0x0(r5), 0, qr0
/* 8006E078 0006B078  11 00 40 9C */	ps_madds0 f8, f0, f2, f8
/* 8006E07C 0006B07C  F0 E5 00 10 */	psq_st f7, 0x10(r5), 0, qr0
/* 8006E080 0006B080  11 40 50 DC */	ps_madds0 f10, f0, f3, f10
/* 8006E084 0006B084  F1 25 00 20 */	psq_st f9, 0x20(r5), 0, qr0
/* 8006E088 0006B088  10 CB 30 7A */	ps_madd f6, f11, f1, f6
/* 8006E08C 0006B08C  11 0B 40 BA */	ps_madd f8, f11, f2, f8
/* 8006E090 0006B090  F0 C5 00 08 */	psq_st f6, 0x8(r5), 0, qr0
/* 8006E094 0006B094  11 4B 50 FA */	ps_madd f10, f11, f3, f10
/* 8006E098 0006B098  F1 05 00 18 */	psq_st f8, 0x18(r5), 0, qr0
/* 8006E09C 0006B09C  F1 45 00 28 */	psq_st f10, 0x28(r5), 0, qr0
/* 8006E0A0 0006B0A0  4E 80 00 20 */	blr
.endfn lbl_8006DFC4
