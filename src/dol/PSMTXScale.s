.include "macros.inc"
.file "PSMTXScale.c"

# 0x80015B50..0x80015B78 | size: 0x28
.text
.balign 4

# .text:0x0 | 0x80015B50 | size: 0x28
.fn PSMTXScale, global
/* 80015B50 00012B50  C0 02 81 0C */	lfs f0, lbl_801A6F4C@sda21(r0)
/* 80015B54 00012B54  D0 23 00 00 */	stfs f1, 0x0(r3)
/* 80015B58 00012B58  F0 03 00 04 */	psq_st f0, 0x4(r3), 0, qr0
/* 80015B5C 00012B5C  F0 03 00 0C */	psq_st f0, 0xc(r3), 0, qr0
/* 80015B60 00012B60  D0 43 00 14 */	stfs f2, 0x14(r3)
/* 80015B64 00012B64  F0 03 00 18 */	psq_st f0, 0x18(r3), 0, qr0
/* 80015B68 00012B68  F0 03 00 20 */	psq_st f0, 0x20(r3), 0, qr0
/* 80015B6C 00012B6C  D0 63 00 28 */	stfs f3, 0x28(r3)
/* 80015B70 00012B70  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 80015B74 00012B74  4E 80 00 20 */	blr
.endfn PSMTXScale
