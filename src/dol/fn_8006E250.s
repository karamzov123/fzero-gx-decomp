.include "macros.inc"
.file "fn_8006E250.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# The inverse transform for a rigid mtxA: *dst = transpose of the mtxA 3x3 times a vector.
# fn_8006E250(src, dst): point *src. The routine subtracts the mtxA translation first.
# fn_8006E294(dst): the negated inverse-rotated translation of mtxA.
# fn_8006E2B0(src, dst): vector *src. lbl_8006E2C0(dst, x, y, z): vector in f1-f3.
# The code at 0x8006E260 is a point entry with x, y, z in f1-f3. No code or symbol refers to it.
# 0x8006E270, lbl_8006E2D0 and fn_8006E2D8 are local labels of this function.
# The shared tail at fn_8006E2D8 gets its sign from cr0[eq]. Each entry sets it with crclr or crset.
# This unit replaces the asm units fn_8006E250, fn_8006E294, fn_8006E2B0 and lbl_8006E2C0.
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Three further global entry points. Callers in main.dol and main_rel reach them directly.
#   Each one follows an unconditional `b`.
# - The code at 0x8006E260 also follows a `b`, and nothing reaches it. Only assembly keeps such code.
# - The shared tail takes a cr0 argument. No C calling convention passes a CR bit.
# - The tail uses paired singles (psq_l/psq_st, ps_mul, ps_madd, ps_nmadd). MWCC makes these only
#   from inline assembly.
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: Super Monkey Ball (same engine) has mathutil_mtxA_rigid_inv_tf_point as one asm
#   function, with entries for rigid_inv_tf_tl, rigid_inv_tf_vec and rigid_inv_tf_vec_xyz:
#   https://github.com/camthesaxman/smb-decomp/blob/5cd6ffccf3f8508231c7cd9cce5b722be4465a2b/src/mathutil.c#L1835-L1942
#   Its C version is under `#ifdef C_ONLY`. Only the GCC build sets C_ONLY (Makefile L54),
#   so the matching build uses the asm.

# 0x8006E250..0x8006E324 | size: 0xD4
.text
.balign 4

# .text:0x0 | 0x8006E250 | size: 0xD4
.fn fn_8006E250, global
/* 8006E250 0006B250  C0 23 00 00 */	lfs f1, 0x0(r3)
/* 8006E254 0006B254  C0 43 00 04 */	lfs f2, 0x4(r3)
/* 8006E258 0006B258  C0 63 00 08 */	lfs f3, 0x8(r3)
/* 8006E25C 0006B25C  48 00 00 14 */	b .L_8006E270
/* 8006E260 0006B260  10 21 0C 20 */	ps_merge00 f1, f1, f1
/* 8006E264 0006B264  10 42 14 20 */	ps_merge00 f2, f2, f2
/* 8006E268 0006B268  10 63 1C 20 */	ps_merge00 f3, f3, f3
/* 8006E26C 0006B26C  7C 64 1B 78 */	mr r4, r3
.L_8006E270:
/* 8006E270 0006B270  3C A0 E0 00 */	lis r5, 0xe000
/* 8006E274 0006B274  4C 42 11 82 */	crclr eq
/* 8006E278 0006B278  C1 45 00 0C */	lfs f10, 0xc(r5)
/* 8006E27C 0006B27C  C1 65 00 1C */	lfs f11, 0x1c(r5)
/* 8006E280 0006B280  C1 85 00 2C */	lfs f12, 0x2c(r5)
/* 8006E284 0006B284  EC 21 50 28 */	fsubs f1, f1, f10
/* 8006E288 0006B288  EC 42 58 28 */	fsubs f2, f2, f11
/* 8006E28C 0006B28C  EC 63 60 28 */	fsubs f3, f3, f12
/* 8006E290 0006B290  48 00 00 48 */	b fn_8006E2D8
# .text:0x44 | 0x8006E294 | size: 0x0
.sym fn_8006E294, global
/* 8006E294 0006B294  3C A0 E0 00 */	lis r5, 0xe000
/* 8006E298 0006B298  7C 64 1B 78 */	mr r4, r3
/* 8006E29C 0006B29C  4C 42 12 42 */	crset eq
/* 8006E2A0 0006B2A0  C0 25 00 0C */	lfs f1, 0xc(r5)
/* 8006E2A4 0006B2A4  C0 45 00 1C */	lfs f2, 0x1c(r5)
/* 8006E2A8 0006B2A8  C0 65 00 2C */	lfs f3, 0x2c(r5)
/* 8006E2AC 0006B2AC  48 00 00 2C */	b fn_8006E2D8
# .text:0x60 | 0x8006E2B0 | size: 0x0
.sym fn_8006E2B0, global
/* 8006E2B0 0006B2B0  C0 23 00 00 */	lfs f1, 0x0(r3)
/* 8006E2B4 0006B2B4  C0 43 00 04 */	lfs f2, 0x4(r3)
/* 8006E2B8 0006B2B8  C0 63 00 08 */	lfs f3, 0x8(r3)
/* 8006E2BC 0006B2BC  48 00 00 14 */	b lbl_8006E2D0
# .text:0x70 | 0x8006E2C0 | size: 0x0
.sym lbl_8006E2C0, global
/* 8006E2C0 0006B2C0  10 21 0C 20 */	ps_merge00 f1, f1, f1
/* 8006E2C4 0006B2C4  10 42 14 20 */	ps_merge00 f2, f2, f2
/* 8006E2C8 0006B2C8  10 63 1C 20 */	ps_merge00 f3, f3, f3
/* 8006E2CC 0006B2CC  7C 64 1B 78 */	mr r4, r3
# .text:0x80 | 0x8006E2D0 | size: 0x0
.sym lbl_8006E2D0, local
/* 8006E2D0 0006B2D0  3C A0 E0 00 */	lis r5, 0xe000
/* 8006E2D4 0006B2D4  4C 42 11 82 */	crclr eq
# .text:0x88 | 0x8006E2D8 | size: 0x0
.sym fn_8006E2D8, local
/* 8006E2D8 0006B2D8  E0 85 00 00 */	psq_l f4, 0x0(r5), 0, qr0
/* 8006E2DC 0006B2DC  C0 A5 00 08 */	lfs f5, 0x8(r5)
/* 8006E2E0 0006B2E0  10 84 00 72 */	ps_mul f4, f4, f1
/* 8006E2E4 0006B2E4  E0 C5 00 10 */	psq_l f6, 0x10(r5), 0, qr0
/* 8006E2E8 0006B2E8  EC A5 00 72 */	fmuls f5, f5, f1
/* 8006E2EC 0006B2EC  C0 E5 00 18 */	lfs f7, 0x18(r5)
/* 8006E2F0 0006B2F0  10 86 20 BA */	ps_madd f4, f6, f2, f4
/* 8006E2F4 0006B2F4  E1 05 00 20 */	psq_l f8, 0x20(r5), 0, qr0
/* 8006E2F8 0006B2F8  EC A7 28 BA */	fmadds f5, f7, f2, f5
/* 8006E2FC 0006B2FC  C1 25 00 28 */	lfs f9, 0x28(r5)
/* 8006E300 0006B300  41 82 00 10 */	beq .L_8006E310
/* 8006E304 0006B304  10 88 20 FA */	ps_madd f4, f8, f3, f4
/* 8006E308 0006B308  EC A9 28 FA */	fmadds f5, f9, f3, f5
/* 8006E30C 0006B30C  48 00 00 0C */	b .L_8006E318
.L_8006E310:
/* 8006E310 0006B310  10 88 20 FE */	ps_nmadd f4, f8, f3, f4
/* 8006E314 0006B314  EC A9 28 FE */	fnmadds f5, f9, f3, f5
.L_8006E318:
/* 8006E318 0006B318  F0 84 00 00 */	psq_st f4, 0x0(r4), 0, qr0
/* 8006E31C 0006B31C  D0 A4 00 08 */	stfs f5, 0x8(r4)
/* 8006E320 0006B320  4E 80 00 20 */	blr
.endfn fn_8006E250
