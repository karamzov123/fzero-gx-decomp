.include "macros.inc"
.file "lbl_8006D188.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# sin(angle) of an s16 angle from the quarter-wave table lbl_80132820.
# - The routine builds the table address with `lis @h; ori @l`. C makes `lis @ha; addi @l`.
# - Both quadrant bit tests are `andi. r5`, and no instruction reads r5. C tests one bit with
#   `rlwinm. r0`.
# - The early `beqlr` is not evidence, because MWCC emits it.
# - Under the TU compiler (GC/1.3.2 -O4,p), the best C differs in 6 of 12 words (measured
#   2026-11-13). These words are the two bit tests, the address pair and their registers. No frame.
# - Source: Super Monkey Ball (same engine) has mathutil_sin as an asm function:
#   https://github.com/camthesaxman/smb-decomp/blob/5cd6ffccf3f8508231c7cd9cce5b722be4465a2b/src/mathutil.c#L249-L279
#   Its C version is under `#ifdef C_ONLY`. Only the GCC build sets C_ONLY (Makefile L54),
#   so the matching build uses the asm.

# 0x8006D188..0x8006D1B8 | size: 0x30
.text
.balign 4

# .text:0x0 | 0x8006D188 | size: 0x30
.fn lbl_8006D188, global
/* 8006D188 0006A188  70 65 40 00 */	andi. r5, r3, 0x4000
/* 8006D18C 0006A18C  54 64 04 BE */	clrlwi r4, r3, 18
/* 8006D190 0006A190  41 82 00 08 */	beq .L_8006D198
/* 8006D194 0006A194  20 84 40 00 */	subfic r4, r4, 0x4000
.L_8006D198:
/* 8006D198 0006A198  3C C0 80 13 */	lis r6, lbl_80132820@h
/* 8006D19C 0006A19C  54 84 10 3A */	slwi r4, r4, 2
/* 8006D1A0 0006A1A0  60 C6 28 20 */	ori r6, r6, lbl_80132820@l
/* 8006D1A4 0006A1A4  70 65 80 00 */	andi. r5, r3, 0x8000
/* 8006D1A8 0006A1A8  7C 26 24 2E */	lfsx f1, r6, r4
/* 8006D1AC 0006A1AC  4D 82 00 20 */	beqlr
/* 8006D1B0 0006A1B0  FC 20 08 50 */	fneg f1, f1
/* 8006D1B4 0006A1B4  4E 80 00 20 */	blr
.endfn lbl_8006D188
