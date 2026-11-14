.include "macros.inc"
.file "lbl_8006DC20.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1).
# Drops the top entry of the locked-cache matrix stack (pointer at 0xE0000094).
# - The routine has no asm-only instruction. The evidence is the TU compiler and the Super Monkey
#   Ball twin.
# - The TU compiler is GC/1.3.2 -O4,p. The C functions around this block match only under it.
# - Under these settings, all 22 C spellings tried give `lis r4; lwz r3; addi r0, r3, 0x30;
#   stw r0`. 4 of 5 words differ.
# - The same C is exact under GC/1.0-1.2.5n -O4,p and under GC/1.3.2 -O2 (measured 2026-11-13).
#   Thus the TU settings cause the miss, not register allocation in general.
# - The Super Monkey Ball retail incr_mtx_stack ends in `blr; blr`. C never gives two consecutive
#   `blr`.
# - The adjacent stack routines lbl_8006DAEC, lbl_8006DB30 and lbl_8006DBE4 start with the same
#   `lis r3, 0xe000; lwz r4, 0x94(r3)`. No frame.
# - Source: Super Monkey Ball (same engine) has mathutil_incr_mtx_stack as an asm function:
#   https://github.com/camthesaxman/smb-decomp/blob/5cd6ffccf3f8508231c7cd9cce5b722be4465a2b/src/mathutil.c#L1138-L1155
#   Its C version is under `#ifdef C_ONLY`. Only the GCC build sets C_ONLY (Makefile L54),
#   so the matching build uses the asm.

# 0x8006DC20..0x8006DC34 | size: 0x14
.text
.balign 4

# .text:0x0 | 0x8006DC20 | size: 0x14
.fn lbl_8006DC20, global
/* 8006DC20 0006AC20  3C 60 E0 00 */	lis r3, 0xe000
/* 8006DC24 0006AC24  80 83 00 94 */	lwz r4, 0x94(r3)
/* 8006DC28 0006AC28  38 84 00 30 */	addi r4, r4, 0x30
/* 8006DC2C 0006AC2C  90 83 00 94 */	stw r4, 0x94(r3)
/* 8006DC30 0006AC30  4E 80 00 20 */	blr
.endfn lbl_8006DC20
