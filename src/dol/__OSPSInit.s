.include "macros.inc"
.file "__OSPSInit.c"

# Assembly in the original: the Dolphin SDK's OS.c writes this routine as a CodeWarrior `asm`
# function. Evidence (docs/ASM_POLICY.md section 1):
# mtspr GQR0-GQR7 (special-purpose register writes MWCC never emits from C). The frame is
# written by hand (nofralloc with an explicit mflr/stw/stwu prologue) around the bl calls.

# 0x8000AB54..0x8000ABA8 | size: 0x54
.text
.balign 4

# .text:0x0 | 0x8000AB54 | size: 0x54
.fn __OSPSInit, global
/* 8000AB54 00007B54  7C 08 02 A6 */	mflr r0
/* 8000AB58 00007B58  90 01 00 04 */	stw r0, 0x4(r1)
/* 8000AB5C 00007B5C  94 21 FF F8 */	stwu r1, -0x8(r1)
/* 8000AB60 00007B60  4B FF F5 49 */	bl PPCMfhid2
/* 8000AB64 00007B64  64 63 A0 00 */	oris r3, r3, 0xa000
/* 8000AB68 00007B68  4B FF F5 49 */	bl PPCMthid2
/* 8000AB6C 00007B6C  48 00 0B A9 */	bl ICFlashInvalidate
/* 8000AB70 00007B70  7C 00 04 AC */	sync
/* 8000AB74 00007B74  38 60 00 00 */	li r3, 0x0
/* 8000AB78 00007B78  7C 70 E3 A6 */	mtspr GQR0, r3
/* 8000AB7C 00007B7C  7C 71 E3 A6 */	mtspr GQR1, r3
/* 8000AB80 00007B80  7C 72 E3 A6 */	mtspr GQR2, r3
/* 8000AB84 00007B84  7C 73 E3 A6 */	mtspr GQR3, r3
/* 8000AB88 00007B88  7C 74 E3 A6 */	mtspr GQR4, r3
/* 8000AB8C 00007B8C  7C 75 E3 A6 */	mtspr GQR5, r3
/* 8000AB90 00007B90  7C 76 E3 A6 */	mtspr GQR6, r3
/* 8000AB94 00007B94  7C 77 E3 A6 */	mtspr GQR7, r3
/* 8000AB98 00007B98  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8000AB9C 00007B9C  38 21 00 08 */	addi r1, r1, 0x8
/* 8000ABA0 00007BA0  7C 08 03 A6 */	mtlr r0
/* 8000ABA4 00007BA4  4E 80 00 20 */	blr
.endfn __OSPSInit
