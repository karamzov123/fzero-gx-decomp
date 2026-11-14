.include "macros.inc"
.file "lbl_8006D21C.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# tan(angle) of an s16 angle from the table lbl_80142840. The table spans a quarter turn.
# In the second quadrant, the routine reads the table in reverse (addis +1 on the base,
# negated index). Then it negates the result with fnabs.
# The routine ignores bit 0x8000, because tan repeats every half turn.
# - The routine builds the table address with `lis @h; ori @l`. C makes `lis @ha; addi @l`.
# - The quadrant bit test is `andi. r6`, and no instruction reads r6. C tests one bit with
#   `rlwinm. r0`.
# - Under the TU compiler (GC/1.3.2 -O4,p), plain C gives 17 words against the 12 retail words.
#   15 words differ (measured 2026-11-13). No frame.
# - Source: Super Monkey Ball (same engine) has mathutil_tan as an asm function:
#   https://github.com/camthesaxman/smb-decomp/blob/5cd6ffccf3f8508231c7cd9cce5b722be4465a2b/src/mathutil.c#L321-L350
#   Its C version is under `#ifdef C_ONLY`. Only the GCC build sets C_ONLY (Makefile L54),
#   so the matching build uses the asm.

# 0x8006D21C..0x8006D24C | size: 0x30
.text
.balign 4

# .text:0x0 | 0x8006D21C | size: 0x30
.fn lbl_8006D21C, global
/* 8006D21C 0006A21C  3C 80 80 14 */	lis r4, lbl_80142840@h
/* 8006D220 0006A220  70 66 40 00 */	andi. r6, r3, 0x4000
/* 8006D224 0006A224  54 65 14 3A */	clrlslwi r5, r3, 18, 2
/* 8006D228 0006A228  60 84 28 40 */	ori r4, r4, lbl_80142840@l
/* 8006D22C 0006A22C  41 82 00 18 */	beq .L_8006D244
/* 8006D230 0006A230  3C 84 00 01 */	addis r4, r4, 0x1
/* 8006D234 0006A234  7C A5 00 D0 */	neg r5, r5
/* 8006D238 0006A238  7C 25 24 2E */	lfsx f1, r5, r4
/* 8006D23C 0006A23C  FC 20 09 10 */	fnabs f1, f1
/* 8006D240 0006A240  4E 80 00 20 */	blr
.L_8006D244:
/* 8006D244 0006A244  7C 25 24 2E */	lfsx f1, r5, r4
/* 8006D248 0006A248  4E 80 00 20 */	blr
.endfn lbl_8006D21C
