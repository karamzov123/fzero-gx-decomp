.include "macros.inc"
.file "lbl_8006DD7C.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# mtxA = inverse of mtxA (SMB: mathutil_mtxA_invert).
# mtxA and mtxB are the locked-cache matrices at 0xE0000000 and 0xE0000030.
# - Uses f14-f24 as scratch and preserves them by hand in the locked cache next to mtxA (stfd and
#   psq_st of both halves, restored with psq_l and lfd) with no stack frame. Measured 2026-11-12:
#   around any asm statement that writes callee-saved FPRs MWCC builds a frame and saves every one
#   (166 words against retail's 114) under every compiler tried.
# - Source: the engine math library (Amusement Vision's mathutil, shared with Super Monkey Ball,
#   where these routines are nofralloc asm functions).

# 0x8006DD7C..0x8006DF44 | size: 0x1C8
.text
.balign 4

# .text:0x0 | 0x8006DD7C | size: 0x1C8
.fn lbl_8006DD7C, global
/* 8006DD7C 0006AD7C  3C 60 E0 00 */	lis r3, 0xe000
/* 8006DD80 0006AD80  D9 C3 00 98 */	stfd f14, 0x98(r3)
/* 8006DD84 0006AD84  D9 E3 00 A0 */	stfd f15, 0xa0(r3)
/* 8006DD88 0006AD88  DA 03 00 A8 */	stfd f16, 0xa8(r3)
/* 8006DD8C 0006AD8C  DA 23 00 B0 */	stfd f17, 0xb0(r3)
/* 8006DD90 0006AD90  DA 43 00 B8 */	stfd f18, 0xb8(r3)
/* 8006DD94 0006AD94  DA 63 00 C0 */	stfd f19, 0xc0(r3)
/* 8006DD98 0006AD98  DA 83 00 C8 */	stfd f20, 0xc8(r3)
/* 8006DD9C 0006AD9C  DA A3 00 D0 */	stfd f21, 0xd0(r3)
/* 8006DDA0 0006ADA0  DA C3 00 D8 */	stfd f22, 0xd8(r3)
/* 8006DDA4 0006ADA4  DA E3 00 E0 */	stfd f23, 0xe0(r3)
/* 8006DDA8 0006ADA8  DB 03 00 E8 */	stfd f24, 0xe8(r3)
/* 8006DDAC 0006ADAC  F1 C3 00 F0 */	psq_st f14, 0xf0(r3), 0, qr0
/* 8006DDB0 0006ADB0  F1 E3 00 F8 */	psq_st f15, 0xf8(r3), 0, qr0
/* 8006DDB4 0006ADB4  F2 03 01 00 */	psq_st f16, 0x100(r3), 0, qr0
/* 8006DDB8 0006ADB8  F2 23 01 08 */	psq_st f17, 0x108(r3), 0, qr0
/* 8006DDBC 0006ADBC  F2 43 01 10 */	psq_st f18, 0x110(r3), 0, qr0
/* 8006DDC0 0006ADC0  F2 63 01 18 */	psq_st f19, 0x118(r3), 0, qr0
/* 8006DDC4 0006ADC4  F2 83 01 20 */	psq_st f20, 0x120(r3), 0, qr0
/* 8006DDC8 0006ADC8  F2 A3 01 28 */	psq_st f21, 0x128(r3), 0, qr0
/* 8006DDCC 0006ADCC  F2 C3 01 30 */	psq_st f22, 0x130(r3), 0, qr0
/* 8006DDD0 0006ADD0  F2 E3 01 38 */	psq_st f23, 0x138(r3), 0, qr0
/* 8006DDD4 0006ADD4  F3 03 01 40 */	psq_st f24, 0x140(r3), 0, qr0
/* 8006DDD8 0006ADD8  C1 43 00 24 */	lfs f10, 0x24(r3)
/* 8006DDDC 0006ADDC  C0 E3 00 18 */	lfs f7, 0x18(r3)
/* 8006DDE0 0006ADE0  ED AA 01 F2 */	fmuls f13, f10, f7
/* 8006DDE4 0006ADE4  C0 43 00 04 */	lfs f2, 0x4(r3)
/* 8006DDE8 0006ADE8  C1 63 00 28 */	lfs f11, 0x28(r3)
/* 8006DDEC 0006ADEC  ED C2 02 F2 */	fmuls f14, f2, f11
/* 8006DDF0 0006ADF0  C0 C3 00 14 */	lfs f6, 0x14(r3)
/* 8006DDF4 0006ADF4  C0 63 00 08 */	lfs f3, 0x8(r3)
/* 8006DDF8 0006ADF8  ED E6 00 F2 */	fmuls f15, f6, f3
/* 8006DDFC 0006ADFC  C0 A3 00 10 */	lfs f5, 0x10(r3)
/* 8006DE00 0006AE00  EE 2B 01 72 */	fmuls f17, f11, f5
/* 8006DE04 0006AE04  EE E5 00 B2 */	fmuls f23, f5, f2
/* 8006DE08 0006AE08  C1 23 00 20 */	lfs f9, 0x20(r3)
/* 8006DE0C 0006AE0C  EE 43 02 72 */	fmuls f18, f3, f9
/* 8006DE10 0006AE10  EE A9 01 B2 */	fmuls f21, f9, f6
/* 8006DE14 0006AE14  C0 23 00 00 */	lfs f1, 0x0(r3)
/* 8006DE18 0006AE18  EE 67 00 72 */	fmuls f19, f7, f1
/* 8006DE1C 0006AE1C  EE C1 02 B2 */	fmuls f22, f1, f10
/* 8006DE20 0006AE20  C0 83 00 0C */	lfs f4, 0xc(r3)
/* 8006DE24 0006AE24  ED A6 6A F8 */	fmsubs f13, f6, f11, f13
/* 8006DE28 0006AE28  C1 03 00 1C */	lfs f8, 0x1c(r3)
/* 8006DE2C 0006AE2C  ED CA 70 F8 */	fmsubs f14, f10, f3, f14
/* 8006DE30 0006AE30  C1 83 00 2C */	lfs f12, 0x2c(r3)
/* 8006DE34 0006AE34  ED E2 79 F8 */	fmsubs f15, f2, f7, f15
/* 8006DE38 0006AE38  EE 27 8A 78 */	fmsubs f17, f7, f9, f17
/* 8006DE3C 0006AE3C  EE 4B 90 78 */	fmsubs f18, f11, f1, f18
/* 8006DE40 0006AE40  EE 63 99 78 */	fmsubs f19, f3, f5, f19
/* 8006DE44 0006AE44  EE A5 AA B8 */	fmsubs f21, f5, f10, f21
/* 8006DE48 0006AE48  EE C9 B0 B8 */	fmsubs f22, f9, f2, f22
/* 8006DE4C 0006AE4C  EE E1 B9 B8 */	fmsubs f23, f1, f6, f23
/* 8006DE50 0006AE50  EC 01 03 72 */	fmuls f0, f1, f13
/* 8006DE54 0006AE54  C0 23 01 9C */	lfs f1, 0x19c(r3)
/* 8006DE58 0006AE58  EE 04 03 72 */	fmuls f16, f4, f13
/* 8006DE5C 0006AE5C  EE 84 04 72 */	fmuls f20, f4, f17
/* 8006DE60 0006AE60  EC 05 03 BA */	fmadds f0, f5, f14, f0
/* 8006DE64 0006AE64  EF 04 05 72 */	fmuls f24, f4, f21
/* 8006DE68 0006AE68  EE 08 83 BA */	fmadds f16, f8, f14, f16
/* 8006DE6C 0006AE6C  EC 09 03 FA */	fmadds f0, f9, f15, f0
/* 8006DE70 0006AE70  EE 88 A4 BA */	fmadds f20, f8, f18, f20
/* 8006DE74 0006AE74  EF 08 C5 BA */	fmadds f24, f8, f22, f24
/* 8006DE78 0006AE78  EC 01 00 24 */	fdivs f0, f1, f0
/* 8006DE7C 0006AE7C  EE 0C 83 FE */	fnmadds f16, f12, f15, f16
/* 8006DE80 0006AE80  EE 8C A4 FE */	fnmadds f20, f12, f19, f20
/* 8006DE84 0006AE84  EF 0C C5 FE */	fnmadds f24, f12, f23, f24
/* 8006DE88 0006AE88  EC 2D 00 32 */	fmuls f1, f13, f0
/* 8006DE8C 0006AE8C  D0 23 00 00 */	stfs f1, 0x0(r3)
/* 8006DE90 0006AE90  EC 4E 00 32 */	fmuls f2, f14, f0
/* 8006DE94 0006AE94  D0 43 00 04 */	stfs f2, 0x4(r3)
/* 8006DE98 0006AE98  EC 6F 00 32 */	fmuls f3, f15, f0
/* 8006DE9C 0006AE9C  D0 63 00 08 */	stfs f3, 0x8(r3)
/* 8006DEA0 0006AEA0  EC 90 00 32 */	fmuls f4, f16, f0
/* 8006DEA4 0006AEA4  D0 83 00 0C */	stfs f4, 0xc(r3)
/* 8006DEA8 0006AEA8  EC B1 00 32 */	fmuls f5, f17, f0
/* 8006DEAC 0006AEAC  D0 A3 00 10 */	stfs f5, 0x10(r3)
/* 8006DEB0 0006AEB0  EC D2 00 32 */	fmuls f6, f18, f0
/* 8006DEB4 0006AEB4  D0 C3 00 14 */	stfs f6, 0x14(r3)
/* 8006DEB8 0006AEB8  EC F3 00 32 */	fmuls f7, f19, f0
/* 8006DEBC 0006AEBC  D0 E3 00 18 */	stfs f7, 0x18(r3)
/* 8006DEC0 0006AEC0  ED 14 00 32 */	fmuls f8, f20, f0
/* 8006DEC4 0006AEC4  D1 03 00 1C */	stfs f8, 0x1c(r3)
/* 8006DEC8 0006AEC8  ED 35 00 32 */	fmuls f9, f21, f0
/* 8006DECC 0006AECC  D1 23 00 20 */	stfs f9, 0x20(r3)
/* 8006DED0 0006AED0  ED 56 00 32 */	fmuls f10, f22, f0
/* 8006DED4 0006AED4  D1 43 00 24 */	stfs f10, 0x24(r3)
/* 8006DED8 0006AED8  ED 77 00 32 */	fmuls f11, f23, f0
/* 8006DEDC 0006AEDC  D1 63 00 28 */	stfs f11, 0x28(r3)
/* 8006DEE0 0006AEE0  ED 98 00 32 */	fmuls f12, f24, f0
/* 8006DEE4 0006AEE4  D1 83 00 2C */	stfs f12, 0x2c(r3)
/* 8006DEE8 0006AEE8  E1 C3 00 F0 */	psq_l f14, 0xf0(r3), 0, qr0
/* 8006DEEC 0006AEEC  E1 E3 00 F8 */	psq_l f15, 0xf8(r3), 0, qr0
/* 8006DEF0 0006AEF0  E2 03 01 00 */	psq_l f16, 0x100(r3), 0, qr0
/* 8006DEF4 0006AEF4  E2 23 01 08 */	psq_l f17, 0x108(r3), 0, qr0
/* 8006DEF8 0006AEF8  E2 43 01 10 */	psq_l f18, 0x110(r3), 0, qr0
/* 8006DEFC 0006AEFC  E2 63 01 18 */	psq_l f19, 0x118(r3), 0, qr0
/* 8006DF00 0006AF00  E2 83 01 20 */	psq_l f20, 0x120(r3), 0, qr0
/* 8006DF04 0006AF04  E2 A3 01 28 */	psq_l f21, 0x128(r3), 0, qr0
/* 8006DF08 0006AF08  E2 C3 01 30 */	psq_l f22, 0x130(r3), 0, qr0
/* 8006DF0C 0006AF0C  E2 E3 01 38 */	psq_l f23, 0x138(r3), 0, qr0
/* 8006DF10 0006AF10  E3 03 01 40 */	psq_l f24, 0x140(r3), 0, qr0
/* 8006DF14 0006AF14  C9 C3 00 98 */	lfd f14, 0x98(r3)
/* 8006DF18 0006AF18  C9 E3 00 A0 */	lfd f15, 0xa0(r3)
/* 8006DF1C 0006AF1C  CA 03 00 A8 */	lfd f16, 0xa8(r3)
/* 8006DF20 0006AF20  CA 23 00 B0 */	lfd f17, 0xb0(r3)
/* 8006DF24 0006AF24  CA 43 00 B8 */	lfd f18, 0xb8(r3)
/* 8006DF28 0006AF28  CA 63 00 C0 */	lfd f19, 0xc0(r3)
/* 8006DF2C 0006AF2C  CA 83 00 C8 */	lfd f20, 0xc8(r3)
/* 8006DF30 0006AF30  CA A3 00 D0 */	lfd f21, 0xd0(r3)
/* 8006DF34 0006AF34  CA C3 00 D8 */	lfd f22, 0xd8(r3)
/* 8006DF38 0006AF38  CA E3 00 E0 */	lfd f23, 0xe0(r3)
/* 8006DF3C 0006AF3C  CB 03 00 E8 */	lfd f24, 0xe8(r3)
/* 8006DF40 0006AF40  4E 80 00 20 */	blr
.endfn lbl_8006DD7C
