.include "macros.inc"
.file "PSMTXQuat.c"

# 0x80015B78..0x80015C1C | size: 0xA4
.text
.balign 4

# .text:0x0 | 0x80015B78 | size: 0xA4
.fn PSMTXQuat, global
/* 80015B78 00012B78  C0 22 81 08 */	lfs f1, lbl_801A6F48@sda21(r0)
/* 80015B7C 00012B7C  E0 84 00 00 */	psq_l f4, 0x0(r4), 0, qr0
/* 80015B80 00012B80  E0 A4 00 08 */	psq_l f5, 0x8(r4), 0, qr0
/* 80015B84 00012B84  EC 01 08 28 */	fsubs f0, f1, f1
/* 80015B88 00012B88  EC 41 08 2A */	fadds f2, f1, f1
/* 80015B8C 00012B8C  10 C4 01 32 */	ps_mul f6, f4, f4
/* 80015B90 00012B90  11 24 24 A0 */	ps_merge10 f9, f4, f4
/* 80015B94 00012B94  11 05 31 7A */	ps_madd f8, f5, f5, f6
/* 80015B98 00012B98  10 E5 01 72 */	ps_mul f7, f5, f5
/* 80015B9C 00012B9C  10 68 42 14 */	ps_sum0 f3, f8, f8, f8
/* 80015BA0 00012BA0  11 49 01 5A */	ps_muls1 f10, f9, f5
/* 80015BA4 00012BA4  ED 60 18 30 */	fres f11, f3
/* 80015BA8 00012BA8  11 07 32 16 */	ps_sum1 f8, f7, f8, f6
/* 80015BAC 00012BAC  10 63 12 FC */	ps_nmsub f3, f3, f11, f2
/* 80015BB0 00012BB0  10 E5 01 5A */	ps_muls1 f7, f5, f5
/* 80015BB4 00012BB4  10 6B 00 F2 */	ps_mul f3, f11, f3
/* 80015BB8 00012BB8  10 C6 31 94 */	ps_sum0 f6, f6, f6, f6
/* 80015BBC 00012BBC  EC 63 00 B2 */	fmuls f3, f3, f2
/* 80015BC0 00012BC0  11 64 3A 7A */	ps_madd f11, f4, f9, f7
/* 80015BC4 00012BC4  10 E4 3A 78 */	ps_msub f7, f4, f9, f7
/* 80015BC8 00012BC8  F0 03 80 0C */	psq_st f0, 0xc(r3), 1, qr0
/* 80015BCC 00012BCC  10 C6 08 FC */	ps_nmsub f6, f6, f3, f1
/* 80015BD0 00012BD0  11 08 08 FC */	ps_nmsub f8, f8, f3, f1
/* 80015BD4 00012BD4  F0 03 80 2C */	psq_st f0, 0x2c(r3), 1, qr0
/* 80015BD8 00012BD8  11 6B 00 F2 */	ps_mul f11, f11, f3
/* 80015BDC 00012BDC  10 E7 00 F2 */	ps_mul f7, f7, f3
/* 80015BE0 00012BE0  F0 C3 80 28 */	psq_st f6, 0x28(r3), 1, qr0
/* 80015BE4 00012BE4  11 24 51 5C */	ps_madds0 f9, f4, f5, f10
/* 80015BE8 00012BE8  10 AB 44 20 */	ps_merge00 f5, f11, f8
/* 80015BEC 00012BEC  11 4A 48 BC */	ps_nmsub f10, f10, f2, f9
/* 80015BF0 00012BF0  10 88 3C A0 */	ps_merge10 f4, f8, f7
/* 80015BF4 00012BF4  F0 A3 00 10 */	psq_st f5, 0x10(r3), 0, qr0
/* 80015BF8 00012BF8  11 29 00 F2 */	ps_mul f9, f9, f3
/* 80015BFC 00012BFC  11 4A 00 F2 */	ps_mul f10, f10, f3
/* 80015C00 00012C00  F0 83 00 00 */	psq_st f4, 0x0(r3), 0, qr0
/* 80015C04 00012C04  F1 23 80 08 */	psq_st f9, 0x8(r3), 1, qr0
/* 80015C08 00012C08  10 EA 04 A0 */	ps_merge10 f7, f10, f0
/* 80015C0C 00012C0C  11 6A 4C 60 */	ps_merge01 f11, f10, f9
/* 80015C10 00012C10  F0 E3 00 18 */	psq_st f7, 0x18(r3), 0, qr0
/* 80015C14 00012C14  F1 63 00 20 */	psq_st f11, 0x20(r3), 0, qr0
/* 80015C18 00012C18  4E 80 00 20 */	blr
.endfn PSMTXQuat
