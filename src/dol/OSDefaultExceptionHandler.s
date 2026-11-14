.include "macros.inc"
.file "OSDefaultExceptionHandler.c"

# Assembly in the original: the Dolphin SDK's OS.c writes this routine as a CodeWarrior `asm`
# function. Evidence (docs/ASM_POLICY.md section 1):
# mfspr GQR1-GQR7, mfdsisr/mfdar (special-purpose registers MWCC never emits from C),
# stores into the context from the incoming registers with no MWCC prologue, and a hand-made
# stwu frame before the tail branch to __OSUnhandledException.

# 0x8000AAFC..0x8000AB54 | size: 0x58
.text
.balign 4

# .text:0x0 | 0x8000AAFC | size: 0x58
.fn OSDefaultExceptionHandler, global
/* 8000AAFC 00007AFC  90 04 00 00 */	stw r0, 0x0(r4)
/* 8000AB00 00007B00  90 24 00 04 */	stw r1, 0x4(r4)
/* 8000AB04 00007B04  90 44 00 08 */	stw r2, 0x8(r4)
/* 8000AB08 00007B08  BC C4 00 18 */	stmw r6, 0x18(r4)
/* 8000AB0C 00007B0C  7C 11 E2 A6 */	mfspr r0, GQR1
/* 8000AB10 00007B10  90 04 01 A8 */	stw r0, 0x1a8(r4)
/* 8000AB14 00007B14  7C 12 E2 A6 */	mfspr r0, GQR2
/* 8000AB18 00007B18  90 04 01 AC */	stw r0, 0x1ac(r4)
/* 8000AB1C 00007B1C  7C 13 E2 A6 */	mfspr r0, GQR3
/* 8000AB20 00007B20  90 04 01 B0 */	stw r0, 0x1b0(r4)
/* 8000AB24 00007B24  7C 14 E2 A6 */	mfspr r0, GQR4
/* 8000AB28 00007B28  90 04 01 B4 */	stw r0, 0x1b4(r4)
/* 8000AB2C 00007B2C  7C 15 E2 A6 */	mfspr r0, GQR5
/* 8000AB30 00007B30  90 04 01 B8 */	stw r0, 0x1b8(r4)
/* 8000AB34 00007B34  7C 16 E2 A6 */	mfspr r0, GQR6
/* 8000AB38 00007B38  90 04 01 BC */	stw r0, 0x1bc(r4)
/* 8000AB3C 00007B3C  7C 17 E2 A6 */	mfspr r0, GQR7
/* 8000AB40 00007B40  90 04 01 C0 */	stw r0, 0x1c0(r4)
/* 8000AB44 00007B44  7C B2 02 A6 */	mfdsisr r5
/* 8000AB48 00007B48  7C D3 02 A6 */	mfdar r6
/* 8000AB4C 00007B4C  94 21 FF F8 */	stwu r1, -0x8(r1)
/* 8000AB50 00007B50  48 00 1C 90 */	b __OSUnhandledException
.endfn OSDefaultExceptionHandler
