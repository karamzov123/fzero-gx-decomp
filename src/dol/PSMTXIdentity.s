.include "macros.inc"
.file "PSMTXIdentity.c"

# 0x80015B24..0x80015B50 | size: 0x2C
.text
.balign 4

# .text:0x0 | 0x80015B24 | size: 0x2C
.fn PSMTXIdentity, global
/* 80015B24 00012B24  C0 02 81 0C */	lfs f0, lbl_801A6F4C@sda21(r0)
/* 80015B28 00012B28  C0 22 81 08 */	lfs f1, lbl_801A6F48@sda21(r0)
/* 80015B2C 00012B2C  F0 03 00 08 */	psq_st f0, 0x8(r3), 0, qr0
/* 80015B30 00012B30  10 40 0C 60 */	ps_merge01 f2, f0, f1
/* 80015B34 00012B34  F0 03 00 18 */	psq_st f0, 0x18(r3), 0, qr0
/* 80015B38 00012B38  10 21 04 A0 */	ps_merge10 f1, f1, f0
/* 80015B3C 00012B3C  F0 03 00 20 */	psq_st f0, 0x20(r3), 0, qr0
/* 80015B40 00012B40  F0 43 00 10 */	psq_st f2, 0x10(r3), 0, qr0
/* 80015B44 00012B44  F0 23 00 00 */	psq_st f1, 0x0(r3), 0, qr0
/* 80015B48 00012B48  F0 23 00 28 */	psq_st f1, 0x28(r3), 0, qr0
/* 80015B4C 00012B4C  4E 80 00 20 */	blr
.endfn PSMTXIdentity
