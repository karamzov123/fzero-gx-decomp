.include "macros.inc"
.file "lbl_8006DF44.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# mtxA = inverse of the rigid transform mtxA (transpose and rotated negative
# translation).
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Hand register allocation. The routine has no asm-only instruction.
# - Element k of mtxA (word offset 4k) stays in f_k for all twelve elements. The load order
#   does not change this: f3 loads first, f7 loads fifth.
# - The accumulators are f12, f13 and f0. f0 becomes free after the last use of m00, which stays
#   in place.
# - The routine stores each transposed element from its load register.
# - MWCC moves each load to its first use and reuses the registers of dead elements. Thus it never
#   holds all twelve elements at once.
# - The best of 8 C spellings under GC/1.3.2 and GC/1.2.5n differs in 28 of 32 words (measured
#   2026-11-13). Earlier probes: decomp/fn-8006d044-mathutil_r2 f1e0a2ee. No frame.
# - Source: Super Monkey Ball (same engine) has only an asm version, mathutil_mtxA_rigid_invert,
#   under `#ifdef __MWERKS__`:
#   https://github.com/camthesaxman/smb-decomp/blob/5cd6ffccf3f8508231c7cd9cce5b722be4465a2b/src/mathutil.c#L1423-L1460

# 0x8006DF44..0x8006DFC4 | size: 0x80
.text
.balign 4

# .text:0x0 | 0x8006DF44 | size: 0x80
.fn lbl_8006DF44, global
/* 8006DF44 0006AF44  3C 60 E0 00 */	lis r3, 0xe000
/* 8006DF48 0006AF48  C0 63 00 0C */	lfs f3, 0xc(r3)
/* 8006DF4C 0006AF4C  C0 03 00 00 */	lfs f0, 0x0(r3)
/* 8006DF50 0006AF50  C0 23 00 04 */	lfs f1, 0x4(r3)
/* 8006DF54 0006AF54  C0 43 00 08 */	lfs f2, 0x8(r3)
/* 8006DF58 0006AF58  ED 83 00 32 */	fmuls f12, f3, f0
/* 8006DF5C 0006AF5C  C0 E3 00 1C */	lfs f7, 0x1c(r3)
/* 8006DF60 0006AF60  ED A3 00 72 */	fmuls f13, f3, f1
/* 8006DF64 0006AF64  C0 83 00 10 */	lfs f4, 0x10(r3)
/* 8006DF68 0006AF68  EC 03 00 B2 */	fmuls f0, f3, f2
/* 8006DF6C 0006AF6C  C0 A3 00 14 */	lfs f5, 0x14(r3)
/* 8006DF70 0006AF70  C0 C3 00 18 */	lfs f6, 0x18(r3)
/* 8006DF74 0006AF74  ED 87 61 3A */	fmadds f12, f7, f4, f12
/* 8006DF78 0006AF78  C1 63 00 2C */	lfs f11, 0x2c(r3)
/* 8006DF7C 0006AF7C  C1 03 00 20 */	lfs f8, 0x20(r3)
/* 8006DF80 0006AF80  ED A7 69 7A */	fmadds f13, f7, f5, f13
/* 8006DF84 0006AF84  C1 23 00 24 */	lfs f9, 0x24(r3)
/* 8006DF88 0006AF88  C1 43 00 28 */	lfs f10, 0x28(r3)
/* 8006DF8C 0006AF8C  EC 07 01 BA */	fmadds f0, f7, f6, f0
/* 8006DF90 0006AF90  D0 23 00 10 */	stfs f1, 0x10(r3)
/* 8006DF94 0006AF94  D0 43 00 20 */	stfs f2, 0x20(r3)
/* 8006DF98 0006AF98  ED 8B 62 3E */	fnmadds f12, f11, f8, f12
/* 8006DF9C 0006AF9C  D0 C3 00 24 */	stfs f6, 0x24(r3)
/* 8006DFA0 0006AFA0  D0 83 00 04 */	stfs f4, 0x4(r3)
/* 8006DFA4 0006AFA4  ED AB 6A 7E */	fnmadds f13, f11, f9, f13
/* 8006DFA8 0006AFA8  D1 03 00 08 */	stfs f8, 0x8(r3)
/* 8006DFAC 0006AFAC  D1 23 00 18 */	stfs f9, 0x18(r3)
/* 8006DFB0 0006AFB0  EC 0B 02 BE */	fnmadds f0, f11, f10, f0
/* 8006DFB4 0006AFB4  D1 83 00 0C */	stfs f12, 0xc(r3)
/* 8006DFB8 0006AFB8  D1 A3 00 1C */	stfs f13, 0x1c(r3)
/* 8006DFBC 0006AFBC  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 8006DFC0 0006AFC0  4E 80 00 20 */	blr
.endfn lbl_8006DF44
