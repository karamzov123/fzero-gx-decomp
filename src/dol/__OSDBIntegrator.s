.include "macros.inc"
.file "__OSDBIntegrator.c"

# Assembly in the original: the Dolphin SDK's OS.c writes this routine as a CodeWarrior `asm`
# function. Evidence (docs/ASM_POLICY.md section 1):
# mflr/mtlr through a fixed low-memory save slot and mtmsr (privileged), no MWCC prologue
# or epilogue (a nofralloc body); OSExceptionInit copies it to 0x80000060 between the
# __OSDBINTSTART/__OSDBINTEND labels, so it is position-independent code, not a C function.

# 0x8000AA08..0x8000AA2C | size: 0x24
.text
.balign 4

# .text:0x0 | 0x8000AA08 | size: 0x24
.fn __OSDBIntegrator, local
# .text:0x0 | 0x8000AA08 | size: 0x0
.sym __OSDBINTSTART, global
/* 8000AA08 00007A08  38 A0 00 40 */	li r5, 0x40
/* 8000AA0C 00007A0C  7C 68 02 A6 */	mflr r3
/* 8000AA10 00007A10  90 65 00 0C */	stw r3, 0xc(r5)
/* 8000AA14 00007A14  80 65 00 08 */	lwz r3, 0x8(r5)
/* 8000AA18 00007A18  64 63 80 00 */	oris r3, r3, 0x8000
/* 8000AA1C 00007A1C  7C 68 03 A6 */	mtlr r3
/* 8000AA20 00007A20  38 60 00 30 */	li r3, 0x30
/* 8000AA24 00007A24  7C 60 01 24 */	mtmsr r3
/* 8000AA28 00007A28  4E 80 00 20 */	blr
.endfn __OSDBIntegrator
