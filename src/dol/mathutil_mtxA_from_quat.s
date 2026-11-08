.include "macros.inc"
.file "mathutil_mtxA_from_quat.c"

# 0x8006E498..0x8006E540 | size: 0xA8
.text
.balign 4

# .text:0x0 | 0x8006E498 | size: 0xA8
.fn mathutil_mtxA_from_quat, global
/* 8006E498 0006B498  3C 80 E0 00 */	lis r4, 0xe000
/* 8006E49C 0006B49C  C0 03 00 00 */	lfs f0, 0x0(r3)
/* 8006E4A0 0006B4A0  C0 23 00 04 */	lfs f1, 0x4(r3)
/* 8006E4A4 0006B4A4  C0 A4 01 9C */	lfs f5, 0x19c(r4)
/* 8006E4A8 0006B4A8  C0 43 00 08 */	lfs f2, 0x8(r3)
/* 8006E4AC 0006B4AC  EC 85 28 28 */	fsubs f4, f5, f5
/* 8006E4B0 0006B4B0  C0 63 00 0C */	lfs f3, 0xc(r3)
/* 8006E4B4 0006B4B4  EC C5 28 2A */	fadds f6, f5, f5
/* 8006E4B8 0006B4B8  D0 84 00 0C */	stfs f4, 0xc(r4)
/* 8006E4BC 0006B4BC  D0 84 00 1C */	stfs f4, 0x1c(r4)
/* 8006E4C0 0006B4C0  D0 84 00 2C */	stfs f4, 0x2c(r4)
/* 8006E4C4 0006B4C4  ED 20 00 32 */	fmuls f9, f0, f0
/* 8006E4C8 0006B4C8  EC E1 00 72 */	fmuls f7, f1, f1
/* 8006E4CC 0006B4CC  ED 02 00 B2 */	fmuls f8, f2, f2
/* 8006E4D0 0006B4D0  ED 22 48 BA */	fmadds f9, f2, f2, f9
/* 8006E4D4 0006B4D4  EC E0 38 3A */	fmadds f7, f0, f0, f7
/* 8006E4D8 0006B4D8  ED 01 40 7A */	fmadds f8, f1, f1, f8
/* 8006E4DC 0006B4DC  ED 29 29 BC */	fnmsubs f9, f9, f6, f5
/* 8006E4E0 0006B4E0  D1 24 00 14 */	stfs f9, 0x14(r4)
/* 8006E4E4 0006B4E4  EC E7 29 BC */	fnmsubs f7, f7, f6, f5
/* 8006E4E8 0006B4E8  D0 E4 00 28 */	stfs f7, 0x28(r4)
/* 8006E4EC 0006B4EC  ED 08 29 BC */	fnmsubs f8, f8, f6, f5
/* 8006E4F0 0006B4F0  D1 04 00 00 */	stfs f8, 0x0(r4)
/* 8006E4F4 0006B4F4  EC C0 00 2A */	fadds f6, f0, f0
/* 8006E4F8 0006B4F8  EC 81 08 2A */	fadds f4, f1, f1
/* 8006E4FC 0006B4FC  EC A2 10 2A */	fadds f5, f2, f2
/* 8006E500 0006B500  EC C3 01 B2 */	fmuls f6, f3, f6
/* 8006E504 0006B504  EC E3 01 32 */	fmuls f7, f3, f4
/* 8006E508 0006B508  ED 03 01 72 */	fmuls f8, f3, f5
/* 8006E50C 0006B50C  ED 21 31 78 */	fmsubs f9, f1, f5, f6
/* 8006E510 0006B510  D1 24 00 18 */	stfs f9, 0x18(r4)
/* 8006E514 0006B514  ED 41 31 7A */	fmadds f10, f1, f5, f6
/* 8006E518 0006B518  D1 44 00 24 */	stfs f10, 0x24(r4)
/* 8006E51C 0006B51C  ED 60 39 78 */	fmsubs f11, f0, f5, f7
/* 8006E520 0006B520  D1 64 00 20 */	stfs f11, 0x20(r4)
/* 8006E524 0006B524  ED 80 39 7A */	fmadds f12, f0, f5, f7
/* 8006E528 0006B528  D1 84 00 08 */	stfs f12, 0x8(r4)
/* 8006E52C 0006B52C  ED A0 41 38 */	fmsubs f13, f0, f4, f8
/* 8006E530 0006B530  D1 A4 00 04 */	stfs f13, 0x4(r4)
/* 8006E534 0006B534  EC 40 41 3A */	fmadds f2, f0, f4, f8
/* 8006E538 0006B538  D0 44 00 10 */	stfs f2, 0x10(r4)
/* 8006E53C 0006B53C  4E 80 00 20 */	blr
.endfn mathutil_mtxA_from_quat
