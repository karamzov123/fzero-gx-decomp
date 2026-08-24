// Fused MTX float-math translation unit (analyzer-fused; do not split).
#pragma force_active on

extern void _8006d04c(void);
extern void _8006d054(void);
extern void _8006d070(void);
extern void _8006d07c(void);
extern void _8006d1c8(void);
extern void _8006d2f0(void);
extern void _8006d360(void);
extern void _8006d368(void);
extern void _8006d388(void);
extern void _8006d3ac(void);
extern void _8006d3b4(void);
extern void _8006d3c4(void);
extern void _8006d800(void);
extern void _8006e000(void);
extern void _8006e0f0(void);
extern void _8006e164(void);

asm void fn_8006CFF8(void);
asm void fn_8006D044(void);
asm void fn_8006D088(void);
asm void sqrtf(void);
asm void fn_8006D0E8(void);
asm void fn_8006D188(void);
asm void fn_8006D1C4(void);
asm void atan2f(void);
asm void atanf(void);
asm void fn_8006D368(void);
asm void fn_8006D3D0(void);
asm void fn_8006D46C(void);
asm void fn_8006D5A4(void);
asm void PSVecNormalize3(void);
asm void fn_8006D6FC(void);
asm void fn_8006D758(void);
asm void fn_8006D784(void);
asm void fn_8006D7B0(void);
asm void fn_8006D7DC(void);
asm void fn_8006D7F4(void);
asm void fn_8006D890(void);
asm void fn_8006D8D8(void);
asm void fn_8006D91C(void);
asm void mtx_gpstack_push(void);
asm void mtx_gpstack_pop(void);
asm void fn_8006DB74(void);
asm void fn_8006DBAC(void);
asm void fn_8006DC34(void);
asm void fn_8006DCDC(void);
asm void fn_8006DD14(void);
asm void fn_8006DF44(void);
asm void fn_8006DFC4(void);
asm void fn_8006DFFC(void);
asm void fn_8006E0B0(void);
asm void fn_8006E0C8(void);
asm void fn_8006E14C(void);

asm void fn_8006CFF8(void)
{
    nofralloc
    li	r3, 0
    mtspr	0x390, r3
    li	r3, 4
    oris	r3, r3, 4
    mtspr	0x392, r3
    li	r3, 5
    oris	r3, r3, 5
    mtspr	0x393, r3
    li	r3, 6
    oris	r3, r3, 6
    mtspr	0x394, r3
    li	r3, 7
    oris	r3, r3, 7
    mtspr	0x395, r3
    li	r3, 0
    mtspr	0x396, r3
    li	r3, 0
    mtspr	0x397, r3
    blr
}

asm void fn_8006D044(void)
{
    nofralloc
_8006d044:
    lis	r0, 0x7fff
    b       _8006d060
    entry _8006d04c
_8006d04c:
    li	r0, 0
    b       _8006d060
    entry _8006d054
_8006d054:
    lis	r0, 0x7f80
    b       _8006d060
    lis	r0, -0x80
_8006d060:
    stwu	r0, -0x10(r1)
    lfs	f1, 0(r1)
    addi	r1, r1, 0x10
    blr
    entry _8006d070
    bc      12, 5, _8006d054
    bc      12, 4, _8006d04c
    b       _8006d044
    entry _8006d07c
    bc      12, 5, _8006d04c
    bc      12, 4, _8006d054
    b       _8006d044
}

asm void fn_8006D088(void)
{
    nofralloc
    fmuls	f4, f2, f1
    fadds	f3, f2, f2
    frsqrte	f1, f1
    fadds	f3, f3, f2
    fmuls	f5, f1, f1
    fnmsubs	f5, f5, f4, f3
    fmuls	f1, f1, f5
    fmuls	f5, f1, f1
    fnmsubs	f5, f5, f4, f3
    fmuls	f1, f1, f5
    blr
}

asm void sqrtf(void)
{
    nofralloc
    frsp	f0, f1
    lis	r4, -0x2000
    mcrfs	cr1, 4
    mcrfs	cr0, 3
    lfs	f2, 0x1a0(r4)
    bc      12, 7, _8006d070
    bc      12, 3, _8006d04c
    bc      4, 5, _8006d04c
    mflr	r3
    bl      fn_8006D088
    mtlr	r3
    fmuls	f1, f1, f0
    blr
}

asm void fn_8006D0E8(void)
{
    nofralloc
    frsp	f1, f1
    lis	r4, -0x2000
    mcrfs	cr1, 4
    mcrfs	cr0, 3
    lfs	f2, 0x1a0(r4)
    bc      12, 7, _8006d07c
    bc      12, 3, _8006d054
    bc      4, 5, _8006d054
    mflr	r3
    bl      fn_8006D088
    mtlr	r3
    blr
    frsp	f0, f1
    lis	r4, -0x2000
    mcrfs	cr1, 4
    mcrfs	cr0, 3
    lfs	f2, 0x1a0(r4)
    bc      12, 7, _8006d150
    bc      12, 3, _8006d164
    bc      4, 5, _8006d164
    mflr	r5
    bl      fn_8006D088
    mtlr	r5
    fmuls	f0, f1, f0
    stfs	f0, 0(r3)
    blr
_8006d150:
    bc      13, 5, _8006d164
    bc      13, 4, _8006d170
    lis	r5, 0x7fff
    lis	r6, 0x7fff
    b       _8006d178
_8006d164:
    li	r5, 0
    lis	r6, 0x7f80
    b       _8006d178
_8006d170:
    lis	r5, 0x7f80
    li	r6, 0
_8006d178:
    stw	r5, 0(r3)
    stw	r6, 0x98(r4)
    lfs	f1, 0x98(r4)
    blr
}

asm void fn_8006D188(void)
{
    nofralloc
    andi.	r5, r3, 0x4000
    clrlwi	r4, r3, 0x12
    bc      12, 2, _8006d198
    subfic	r4, r4, 0x4000
_8006d198:
    lis	r6, -0x7fed
    slwi	r4, r4, 2
    ori	r6, r6, 0x2820
    andi.	r5, r3, 0x8000
    lfsx	f1, r6, r4
    beqlr	
    fneg	f1, f1
    blr
    addi	r5, r4, 4
    crxor	6, 6, 6
    b       _8006d1c8
}

asm void fn_8006D1C4(void)
{
    nofralloc
    crset	6
    entry _8006d1c8
    rlwinm	r8, r3, 0x10, 0, 1
    clrlwi	r6, r3, 0x12
    mtcrf	0x80, r8
    crxor	2, 0, 1
    bc      4, 1, _8006d1e0
    subfic	r6, r6, 0x4000
_8006d1e0:
    subfic	r7, r6, 0x4000
    lis	r8, -0x7fed
    slwi	r6, r6, 2
    ori	r8, r8, 0x2820
    slwi	r7, r7, 2
    lfsx	f1, r8, r6
    lfsx	f2, r8, r7
    bc      4, 0, _8006d204
    fnabs	f1, f1
_8006d204:
    bc      4, 2, _8006d20c
    fnabs	f2, f2
_8006d20c:
    beqlr	cr1
    stfs	f1, 0(r4)
    stfs	f2, 0(r5)
    blr
    lis	r4, -0x7fec
    andi.	r6, r3, 0x4000
    rlwinm	r5, r3, 2, 0x10, 0x1d
    ori	r4, r4, 0x2840
    bc      12, 2, _8006d244
    addis	r4, r4, 1
    neg	r5, r5
    lfsx	f1, r5, r4
    fnabs	f1, f1
    blr
_8006d244:
    lfsx	f1, r5, r4
    blr
}

asm void atan2f(void)
{
    nofralloc
    mfcr	r6
    frsp	f2, f2
    mcrfs	cr7, 4
    mcrfs	cr6, 3
    frsp	f1, f1
    bc      12, 31, _8006d360
    mcrfs	cr5, 4
    mcrfs	cr4, 3
    bc      12, 23, _8006d368
    bc      5, 30, _8006d27c
    bc      5, 22, _8006d27c
    b       _8006d3ac
_8006d27c:
    crxor	12, 20, 28
    fabs	f3, f2
    fabs	f4, f1
    fcmpu	cr0, f3, f4
    bc      12, 2, _8006d3b4
    bc      12, 1, _8006d29c
    fabs	f3, f1
    fabs	f4, f2
_8006d29c:
    cror	15, 0, 0
    lis	r7, -0x2000
    fdivs	f5, f4, f3
    b       _8006d2f0
}

asm void atanf(void)
{
    nofralloc
    frsp	f1, f1
    lis	r7, -0x2000
    mcrfs	cr5, 4
    mcrfs	cr4, 3
    bc      5, 23, _8006d2cc
    crand	9, 19, 23
    bc      12, 9, _8006d3ac
    b       _8006d388
_8006d2cc:
    bc      12, 22, _8006d3ac
    lfs	f3, 0x19c(r7)
    fabs	f5, f1
    cror	12, 20, 20
    fcmpu	cr0, f5, f3
    bc      12, 2, _8006d3b4
    bc      12, 0, _8006d2ec
    fdivs	f5, f3, f5
_8006d2ec:
    cror	15, 1, 1
    entry _8006d2f0
    stfs	f5, 0x98(r7)
    lwz	r3, 0x98(r7)
    clrlwi	r5, r3, 9
    oris	r5, r5, 0x80
    rlwinm	r4, r3, 9, 0x18, 0x1f
    subfic	r4, r4, 0x87
    rlwinm.	r0, r4, 0, 0, 0x1a
    bc      12, 2, _8006d314
    ori	r4, r4, 0x20
_8006d314:
    srw	r4, r5, r4
    rlwinm	r4, r4, 0, 0x11, 0x1c
    addis	r4, r4, -0x7feb
    addi	r4, r4, 0x2860
    lfs	f3, 0(r4)
    lfs	f4, 4(r4)
    fmadds	f5, f5, f3, f4
    fctiw	f5, f5
    stfd	f5, 0x98(r7)
    lwz	r3, 0x9c(r7)
    bc      4, 15, _8006d344
    subfic	r3, r3, 0x4000
_8006d344:
    bc      4, 12, _8006d354
    neg	r3, r3
    addi	r3, r3, -0x8000
    addis	r3, r3, 1
_8006d354:
    bc      4, 20, _8006d3c4
    addi	r3, r3, -0x8000
    b       _8006d3c4
    entry _8006d360
_8006d360:
    mcrfs	cr5, 4
    mcrfs	cr4, 3
}

asm void fn_8006D368(void)
{
    nofralloc
    entry _8006d368
_8006d368:
    crand	8, 27, 31
    bc      12, 8, _8006d3ac
    crand	9, 19, 23
    bc      12, 9, _8006d3ac
    bc      4, 31, _8006d388
    bc      4, 23, _8006d39c
    crxor	12, 20, 28
    b       _8006d3b4
    entry _8006d388
_8006d388:
    crxor	12, 20, 28
    mfcr	r3
    rlwinm	r3, r3, 0x1c, 0x10, 0x10
    ori	r3, r3, 0x4000
    b       _8006d3c4
_8006d39c:
    crxor	12, 20, 28
    mfcr	r3
    rlwinm	r3, r3, 0x1c, 0x10, 0x10
    b       _8006d3c4
    entry _8006d3ac
_8006d3ac:
    li	r3, 0
    b       _8006d3c8
    entry _8006d3b4
_8006d3b4:
    cror	21, 12, 12
    mfcr	r3
    rlwinm	r3, r3, 4, 0x10, 0x11
    ori	r3, r3, 0x2000
    entry _8006d3c4
_8006d3c4:
    extsh	r3, r3
_8006d3c8:
    mtcrf	0xff, r6
    blr
}

asm void fn_8006D3D0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stfd	f31, 0x10(r1)
    psq_st	f31, 0x18(r1), 0, 0
    fmr	f31, f1
    lfd	f0, -0x7a88(r2)
    fabs	f1, f31
    fcmpo	cr0, f1, f0
    bc      4, 1, _8006d414
    lfs	f0, -0x7a80(r2)
    fcmpo	cr0, f31, f0
    bc      4, 1, _8006d40c
    li	r3, 0x4000
    b       _8006d454
_8006d40c:
    li	r3, -0x4000
    b       _8006d454
_8006d414:
    fmuls	f0, f31, f31
    lfs	f1, -0x7a7c(r2)
    fsubs	f1, f1, f0
    bl      sqrtf
    lfs	f0, -0x7a78(r2)
    fcmpo	cr0, f1, f0
    bc      4, 1, _8006d43c
    fdivs	f1, f31, f1
    bl      atanf
    b       _8006d454
_8006d43c:
    lfs	f0, -0x7a80(r2)
    fcmpo	cr0, f31, f0
    bc      4, 1, _8006d450
    li	r3, 0x4000
    b       _8006d454
_8006d450:
    li	r3, -0x4000
_8006d454:
    psq_l	f31, 0x18(r1), 0, 0
    lwz	r0, 0x24(r1)
    lfd	f31, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_8006D46C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stfd	f31, 0x10(r1)
    psq_st	f31, 0x18(r1), 0, 0
    fmr	f31, f1
    lfd	f0, -0x7a88(r2)
    fabs	f1, f31
    fcmpo	cr0, f1, f0
    bc      4, 1, _8006d4b0
    lfs	f0, -0x7a80(r2)
    fcmpo	cr0, f31, f0
    bc      4, 1, _8006d4a8
    li	r3, 0
    b       _8006d51c
_8006d4a8:
    li	r3, -0x8000
    b       _8006d51c
_8006d4b0:
    bc      4, 1, _8006d4d0
    lfs	f0, -0x7a80(r2)
    fcmpo	cr0, f31, f0
    bc      4, 1, _8006d4c8
    li	r3, 0x4000
    b       _8006d510
_8006d4c8:
    li	r3, -0x4000
    b       _8006d510
_8006d4d0:
    fmuls	f0, f31, f31
    lfs	f1, -0x7a7c(r2)
    fsubs	f1, f1, f0
    bl      sqrtf
    lfs	f0, -0x7a78(r2)
    fcmpo	cr0, f1, f0
    bc      4, 1, _8006d4f8
    fdivs	f1, f31, f1
    bl      atanf
    b       _8006d510
_8006d4f8:
    lfs	f0, -0x7a80(r2)
    fcmpo	cr0, f31, f0
    bc      4, 1, _8006d50c
    li	r3, 0x4000
    b       _8006d510
_8006d50c:
    li	r3, -0x4000
_8006d510:
    subfic	r0, r3, 0x4000
    clrlwi	r0, r0, 0x10
    extsh	r3, r0
_8006d51c:
    psq_l	f31, 0x18(r1), 0, 0
    lwz	r0, 0x24(r1)
    lfd	f31, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
    lfs	f1, 0(r3)
    lfs	f2, 4(r3)
    lfs	f3, 8(r3)
    lfs	f4, 0(r4)
    lfs	f5, 4(r4)
    lfs	f6, 8(r4)
    lis	r6, -0x2000
    fmuls	f8, f1, f1
    fmuls	f9, f4, f4
    fmuls	f7, f1, f4
    fmadds	f8, f2, f2, f8
    fmadds	f9, f5, f5, f9
    fmadds	f7, f2, f5, f7
    fmadds	f8, f3, f3, f8
    fmadds	f9, f6, f6, f9
    fmadds	f7, f3, f6, f7
    fmuls	f1, f8, f9
    mcrfs	cr1, 4
    mcrfs	cr0, 3
    lfs	f2, 0x1a0(r6)
    bc      12, 7, _8006d070
    bc      12, 3, _8006d04c
    bc      4, 5, _8006d04c
    mflr	r5
    bl      fn_8006D088
    mtlr	r5
    fmuls	f1, f1, f7
    blr
}

asm void fn_8006D5A4(void)
{
    nofralloc
    lfs	f2, 0(r3)
    lfs	f0, 0(r4)
    fsubs	f0, f0, f2
    fmuls	f0, f1, f0
    fadds	f0, f2, f0
    stfs	f0, 0(r5)
    lfs	f2, 4(r3)
    lfs	f0, 4(r4)
    fsubs	f0, f0, f2
    fmuls	f0, f1, f0
    fadds	f0, f2, f0
    stfs	f0, 4(r5)
    lfs	f2, 8(r3)
    lfs	f0, 8(r4)
    fsubs	f0, f0, f2
    fmuls	f0, f1, f0
    fadds	f0, f2, f0
    stfs	f0, 8(r5)
    blr
    lis	r6, -0x2000
    fmr	f0, f1
    lfs	f6, 0(r3)
    lfs	f7, 4(r3)
    lfs	f8, 8(r3)
    fmuls	f1, f6, f6
    fmadds	f1, f7, f7, f1
    fmadds	f1, f8, f8, f1
    mcrfs	cr1, 4
    mcrfs	cr0, 3
    lfs	f2, 0x1a0(r6)
    bc      12, 7, _8006d654
    bc      12, 3, _8006d654
    bc      4, 5, _8006d654
    mflr	r5
    bl      fn_8006D088
    mtlr	r5
    fmuls	f1, f1, f0
    fmuls	f6, f6, f1
    stfs	f6, 0(r4)
    fmuls	f7, f7, f1
    stfs	f7, 4(r4)
    fmuls	f8, f8, f1
    stfs	f8, 8(r4)
    blr
_8006d654:
    lfs	f6, 0x198(r6)
    stfs	f6, 0(r4)
    stfs	f6, 4(r4)
    stfs	f6, 8(r4)
    blr
}

asm void PSVecNormalize3(void)
{
    nofralloc
    lis	r5, -0x2000
    lfs	f6, 0(r3)
    lfs	f7, 4(r3)
    fmuls	f1, f6, f6
    lfs	f8, 8(r3)
    fmadds	f1, f7, f7, f1
    fmadds	f1, f8, f8, f1
    lfs	f2, 0x1a0(r5)
    mcrfs	cr1, 4
    mcrfs	cr0, 3
    bc      12, 7, _8006d6e8
    bc      4, 5, _8006d6e8
    bc      12, 3, _8006d6e8
    fmr	f0, f1
    fmuls	f4, f2, f1
    fadds	f3, f2, f2
    frsqrte	f1, f1
    fadds	f3, f3, f2
    fmuls	f5, f1, f1
    fnmsubs	f5, f5, f4, f3
    fmuls	f1, f1, f5
    fmuls	f5, f1, f1
    fnmsubs	f5, f5, f4, f3
    fmuls	f1, f1, f5
    fmuls	f6, f6, f1
    stfs	f6, 0(r3)
    fmuls	f7, f7, f1
    stfs	f7, 4(r3)
    fmuls	f8, f8, f1
    stfs	f8, 8(r3)
    fmuls	f1, f1, f0
    blr
_8006d6e8:
    lfs	f1, 0x198(r5)
    stfs	f1, 0(r3)
    stfs	f1, 4(r3)
    stfs	f1, 8(r3)
    blr
}

asm void fn_8006D6FC(void)
{
    nofralloc
    lis	r5, -0x2000
    lfs	f6, 0(r3)
    lfs	f9, 0(r4)
    fmuls	f12, f6, f6
    lfs	f7, 4(r3)
    fmuls	f13, f9, f9
    lfs	f10, 4(r4)
    fmuls	f0, f6, f9
    lfs	f8, 8(r3)
    fmadds	f12, f7, f7, f12
    lfs	f11, 8(r4)
    fmadds	f13, f10, f10, f13
    fmadds	f0, f7, f10, f0
    fmadds	f12, f8, f8, f12
    fmadds	f13, f11, f11, f13
    fmadds	f0, f8, f11, f0
    lfs	f2, 0x1a0(r5)
    fmuls	f1, f12, f13
    mflr	r6
    bl      fn_8006D088
    mtlr	r6
    fmuls	f1, f1, f0
    blr
}

asm void fn_8006D758(void)
{
    nofralloc
    lis	r3, -0x2000
    psq_l	f1, 0x1ac(r3), 0, 2
    psq_l	f2, 0x1ae(r3), 0, 2
    ps_sub	f0, f1, f1
    psq_st	f2, 0x0(r3), 0, 0
    psq_st	f0, 0x8(r3), 0, 0
    psq_st	f1, 0x10(r3), 0, 0
    psq_st	f0, 0x18(r3), 0, 0
    psq_st	f0, 0x20(r3), 0, 0
    psq_st	f2, 0x28(r3), 0, 0
    blr
}

asm void fn_8006D784(void)
{
    nofralloc
    lis	r4, -0x2000
    psq_l	f1, 0x1ac(r4), 0, 2
    psq_l	f2, 0x1ae(r4), 0, 2
    ps_sub	f0, f1, f1
    psq_st	f2, 0x0(r3), 0, 0
    psq_st	f0, 0x8(r3), 0, 0
    psq_st	f1, 0x10(r3), 0, 0
    psq_st	f0, 0x18(r3), 0, 0
    psq_st	f0, 0x20(r3), 0, 0
    psq_st	f2, 0x28(r3), 0, 0
    blr
}

asm void fn_8006D7B0(void)
{
    nofralloc
    lis	r3, -0x2000
    psq_l	f1, 0x1ac(r3), 0, 2
    psq_l	f2, 0x1ae(r3), 0, 2
    ps_sub	f0, f1, f1
    psq_st	f2, 0x0(r3), 0, 0
    psq_st	f0, 0x8(r3), 1, 0
    psq_st	f1, 0x10(r3), 0, 0
    psq_st	f0, 0x18(r3), 1, 0
    psq_st	f0, 0x20(r3), 0, 0
    psq_st	f2, 0x28(r3), 1, 0
    blr
}

asm void fn_8006D7DC(void)
{
    nofralloc
    lis	r4, -0x2000
    psq_l	f1, 0x0(r3), 0, 0
    lfs	f4, 0x198(r4)
    lfs	f3, 8(r3)
    ps_merge01	f9, f4, f1
    b       _8006d800
}

asm void fn_8006D7F4(void)
{
    nofralloc
    lis	r4, -0x2000
    lfs	f4, 0x198(r4)
    ps_merge00	f9, f4, f2
    entry _8006d800
    lfs	f7, 0x19c(r4)
    ps_merge00	f8, f4, f1
    ps_merge00	f10, f7, f3
    psq_l	f5, 0x1ac(r4), 0, 2
    psq_l	f6, 0x1ae(r4), 0, 2
    psq_st	f4, 0x20(r4), 0, 0
    psq_st	f8, 0x8(r4), 0, 0
    psq_st	f9, 0x18(r4), 0, 0
    psq_st	f10, 0x28(r4), 0, 0
    psq_st	f5, 0x10(r4), 0, 0
    psq_st	f6, 0x0(r4), 0, 0
    blr
    lis	r4, -0x2000
    psq_l	f1, 0x0(r3), 0, 0
    lfs	f4, 0x198(r4)
    lfs	f3, 8(r3)
    ps_merge01	f6, f4, f1
    b       _8006d86c
    lis	r4, -0x2000
    fmr	f3, f1
    lfs	f4, 0x198(r4)
    ps_merge00	f1, f1, f1
    ps_merge01	f6, f4, f1
    b       _8006d86c
    lis	r4, -0x2000
    lfs	f4, 0x198(r4)
    ps_merge00	f6, f4, f2
_8006d86c:
    ps_merge00	f5, f1, f4
    ps_merge00	f7, f3, f4
    psq_st	f4, 0x8(r4), 0, 0
    psq_st	f4, 0x18(r4), 0, 0
    psq_st	f4, 0x20(r4), 0, 0
    psq_st	f5, 0x0(r4), 0, 0
    psq_st	f6, 0x10(r4), 0, 0
    psq_st	f7, 0x28(r4), 0, 0
    blr
}

asm void fn_8006D890(void)
{
    nofralloc
    mflr	r4
    bl      fn_8006D1C4
    mtlr	r4
    lis	r4, -0x2000
    fneg	f3, f1
    psq_l	f4, 0x1ae(r4), 0, 2
    ps_merge11	f6, f4, f4
    ps_merge10	f7, f4, f2
    ps_merge01	f8, f3, f4
    ps_merge10	f9, f4, f1
    ps_merge01	f10, f2, f4
    psq_st	f4, 0x0(r4), 0, 0
    psq_st	f6, 0x8(r4), 0, 0
    psq_st	f8, 0x18(r4), 0, 0
    psq_st	f7, 0x10(r4), 0, 0
    psq_st	f9, 0x20(r4), 0, 0
    psq_st	f10, 0x28(r4), 0, 0
    blr
}

asm void fn_8006D8D8(void)
{
    nofralloc
    mflr	r4
    bl      fn_8006D1C4
    mtlr	r4
    lis	r4, -0x2000
    fneg	f3, f1
    psq_l	f4, 0x1ac(r4), 0, 2
    ps_merge00	f5, f2, f4
    ps_merge00	f6, f1, f4
    ps_merge00	f8, f4, f4
    ps_merge00	f9, f3, f4
    psq_st	f5, 0x0(r4), 0, 0
    psq_st	f6, 0x8(r4), 0, 0
    psq_st	f4, 0x10(r4), 0, 0
    psq_st	f8, 0x18(r4), 0, 0
    psq_st	f9, 0x20(r4), 0, 0
    psq_st	f5, 0x28(r4), 0, 0
    blr
}

asm void fn_8006D91C(void)
{
    nofralloc
    mflr	r4
    bl      fn_8006D1C4
    mtlr	r4
    lis	r4, -0x2000
    fneg	f3, f1
    psq_l	f4, 0x1ae(r4), 0, 2
    ps_merge00	f5, f2, f3
    ps_merge11	f6, f4, f4
    ps_merge00	f7, f1, f2
    psq_st	f5, 0x0(r4), 0, 0
    psq_st	f6, 0x8(r4), 0, 0
    psq_st	f7, 0x10(r4), 0, 0
    psq_st	f6, 0x18(r4), 0, 0
    psq_st	f6, 0x20(r4), 0, 0
    psq_st	f4, 0x28(r4), 0, 0
    blr
    mflr	r4
    bl      fn_8006D1C4
    mtlr	r4
    lis	r4, -0x2000
    fneg	f3, f1
    psq_l	f4, 0x1ac(r4), 0, 2
    ps_merge00	f5, f2, f4
    ps_merge00	f6, f3, f4
    psq_st	f5, 0x0(r4), 0, 0
    stfs	f1, 8(r4)
    psq_st	f4, 0x10(r4), 0, 0
    psq_st	f4, 0x18(r4), 1, 0
    psq_st	f6, 0x20(r4), 0, 0
    stfs	f2, 0x28(r4)
    blr
    mflr	r4
    bl      fn_8006D1C4
    mtlr	r4
    lis	r4, -0x2000
    psq_l	f4, 0x1ae(r4), 0, 2
    fneg	f3, f1
    ps_merge00	f6, f1, f2
    ps_merge00	f5, f2, f3
    ps_merge11	f7, f4, f4
    psq_st	f6, 0x10(r4), 0, 0
    psq_st	f5, 0x0(r4), 0, 0
    psq_st	f7, 0x8(r4), 1, 0
    psq_st	f7, 0x18(r4), 1, 0
    psq_st	f7, 0x20(r4), 0, 0
    psq_st	f4, 0x28(r4), 1, 0
    blr
    lis	r4, -0x2000
    psq_l	f1, 0x0(r3), 0, 0
    psq_l	f3, 0x8(r3), 1, 0
    b       _8006d9f8
    lis	r4, -0x2000
    lfs	f4, 0x19c(r4)
    ps_merge00	f1, f1, f2
    ps_merge00	f3, f3, f4
_8006d9f8:
    psq_l	f4, 0x30(r4), 0, 0
    psq_st	f4, 0x0(r4), 0, 0
    ps_mul	f4, f4, f1
    psq_l	f6, 0x40(r4), 0, 0
    psq_st	f6, 0x10(r4), 0, 0
    ps_mul	f6, f6, f1
    psq_l	f8, 0x50(r4), 0, 0
    psq_st	f8, 0x20(r4), 0, 0
    ps_mul	f8, f8, f1
    psq_l	f5, 0x38(r4), 0, 0
    ps_madd	f4, f5, f3, f4
    psq_l	f7, 0x48(r4), 0, 0
    ps_madd	f6, f7, f3, f6
    psq_l	f9, 0x58(r4), 0, 0
    ps_madd	f8, f9, f3, f8
    ps_sum1	f5, f4, f5, f4
    psq_st	f5, 0x8(r4), 0, 0
    ps_sum1	f7, f6, f7, f6
    psq_st	f7, 0x18(r4), 0, 0
    ps_sum1	f9, f8, f9, f8
    psq_st	f9, 0x28(r4), 0, 0
    blr
    lis	r3, -0x2000
    mflr	r4
    lfs	f2, 0x1a0(r3)
    psq_l	f6, 0x0(r3), 0, 0
    lfs	f7, 8(r3)
    ps_mul	f12, f6, f6
    psq_l	f8, 0x10(r3), 0, 0
    fmuls	f13, f7, f7
    lfs	f9, 0x18(r3)
    ps_madd	f12, f8, f8, f12
    psq_l	f10, 0x20(r3), 0, 0
    fmadds	f13, f9, f9, f13
    lfs	f11, 0x28(r3)
    ps_madd	f12, f10, f10, f12
    fmadds	f13, f11, f11, f13
    fmr	f1, f12
    bl      fn_8006D088
    frsp	f1, f1
    ps_merge01	f12, f1, f12
    ps_merge11	f1, f12, f12
    bl      fn_8006D088
    frsp	f1, f1
    ps_merge00	f1, f12, f1
    ps_mul	f6, f6, f1
    psq_st	f6, 0x0(r3), 0, 0
    ps_mul	f8, f8, f1
    psq_st	f8, 0x10(r3), 0, 0
    ps_mul	f10, f10, f1
    psq_st	f10, 0x20(r3), 0, 0
    fmr	f1, f13
    bl      fn_8006D088
    mtlr	r4
    fmuls	f7, f7, f1
    stfs	f7, 8(r3)
    fmuls	f9, f9, f1
    stfs	f9, 0x18(r3)
    fmuls	f11, f11, f1
    stfs	f11, 0x28(r3)
    blr
}

asm void mtx_gpstack_push(void)
{
    nofralloc
    lis	r3, -0x2000
    lwz	r4, 0x94(r3)
    psq_l	f0, 0x0(r3), 0, 0
    psq_l	f1, 0x8(r3), 0, 0
    psq_l	f2, 0x10(r3), 0, 0
    addi	r4, r4, -0x30
    psq_l	f3, 0x18(r3), 0, 0
    psq_l	f4, 0x20(r3), 0, 0
    psq_l	f5, 0x28(r3), 0, 0
    psq_st	f0, 0x0(r4), 0, 0
    psq_st	f1, 0x8(r4), 0, 0
    psq_st	f2, 0x10(r4), 0, 0
    psq_st	f3, 0x18(r4), 0, 0
    psq_st	f4, 0x20(r4), 0, 0
    psq_st	f5, 0x28(r4), 0, 0
    stw	r4, 0x94(r3)
    blr
}

asm void mtx_gpstack_pop(void)
{
    nofralloc
    lis	r3, -0x2000
    lwz	r4, 0x94(r3)
    psq_l	f0, 0x0(r4), 0, 0
    psq_l	f1, 0x8(r4), 0, 0
    psq_l	f2, 0x10(r4), 0, 0
    psq_l	f3, 0x18(r4), 0, 0
    psq_l	f4, 0x20(r4), 0, 0
    psq_l	f5, 0x28(r4), 0, 0
    addi	r4, r4, 0x30
    psq_st	f0, 0x0(r3), 0, 0
    psq_st	f1, 0x8(r3), 0, 0
    psq_st	f2, 0x10(r3), 0, 0
    psq_st	f3, 0x18(r3), 0, 0
    psq_st	f4, 0x20(r3), 0, 0
    psq_st	f5, 0x28(r3), 0, 0
    stw	r4, 0x94(r3)
    blr
}

asm void fn_8006DB74(void)
{
    nofralloc
    lis	r4, -0x2000
    psq_l	f0, 0x0(r4), 0, 0
    psq_l	f1, 0x8(r4), 0, 0
    psq_l	f2, 0x10(r4), 0, 0
    psq_l	f3, 0x18(r4), 0, 0
    psq_l	f4, 0x20(r4), 0, 0
    psq_l	f5, 0x28(r4), 0, 0
    psq_st	f0, 0x0(r3), 0, 0
    psq_st	f1, 0x8(r3), 0, 0
    psq_st	f2, 0x10(r3), 0, 0
    psq_st	f3, 0x18(r3), 0, 0
    psq_st	f4, 0x20(r3), 0, 0
    psq_st	f5, 0x28(r3), 0, 0
    blr
}

asm void fn_8006DBAC(void)
{
    nofralloc
    lis	r4, -0x2000
    psq_l	f0, 0x0(r3), 0, 0
    psq_l	f1, 0x8(r3), 0, 0
    psq_l	f2, 0x10(r3), 0, 0
    psq_l	f3, 0x18(r3), 0, 0
    psq_l	f4, 0x20(r3), 0, 0
    psq_l	f5, 0x28(r3), 0, 0
    psq_st	f0, 0x0(r4), 0, 0
    psq_st	f1, 0x8(r4), 0, 0
    psq_st	f2, 0x10(r4), 0, 0
    psq_st	f3, 0x18(r4), 0, 0
    psq_st	f4, 0x20(r4), 0, 0
    psq_st	f5, 0x28(r4), 0, 0
    blr
    lis	r3, -0x2000
    lwz	r4, 0x94(r3)
    psq_l	f0, 0x0(r4), 0, 0
    psq_l	f1, 0x8(r4), 0, 0
    psq_l	f2, 0x10(r4), 0, 0
    psq_l	f3, 0x18(r4), 0, 0
    psq_l	f4, 0x20(r4), 0, 0
    psq_l	f5, 0x28(r4), 0, 0
    psq_st	f0, 0x0(r3), 0, 0
    psq_st	f1, 0x8(r3), 0, 0
    psq_st	f2, 0x10(r3), 0, 0
    psq_st	f3, 0x18(r3), 0, 0
    psq_st	f4, 0x20(r3), 0, 0
    psq_st	f5, 0x28(r3), 0, 0
    blr
    lis	r3, -0x2000
    lwz	r4, 0x94(r3)
    addi	r4, r4, 0x30
    stw	r4, 0x94(r3)
    blr
}

asm void fn_8006DC34(void)
{
    nofralloc
    lis	r4, -0x2000
    psq_l	f0, 0x0(r4), 0, 0
    lfs	f1, 8(r4)
    psq_l	f2, 0x10(r4), 0, 0
    lfs	f3, 0x18(r4)
    psq_l	f4, 0x20(r4), 0, 0
    lfs	f5, 0x28(r4)
    psq_st	f0, 0x0(r3), 0, 0
    stfs	f1, 8(r3)
    psq_st	f2, 0x10(r3), 0, 0
    stfs	f3, 0x18(r3)
    psq_st	f4, 0x20(r3), 0, 0
    stfs	f5, 0x28(r3)
    blr
    lis	r4, -0x2000
    psq_l	f0, 0x0(r3), 0, 0
    lfs	f1, 8(r3)
    psq_l	f2, 0x10(r3), 0, 0
    lfs	f3, 0x18(r3)
    psq_l	f4, 0x20(r3), 0, 0
    lfs	f5, 0x28(r3)
    psq_st	f0, 0x0(r4), 0, 0
    stfs	f1, 8(r4)
    psq_st	f2, 0x10(r4), 0, 0
    stfs	f3, 0x18(r4)
    psq_st	f4, 0x20(r4), 0, 0
    stfs	f5, 0x28(r4)
    blr
    lis	r3, -0x2000
    psq_l	f0, 0x30(r3), 0, 0
    psq_l	f1, 0x38(r3), 0, 0
    psq_l	f2, 0x40(r3), 0, 0
    psq_l	f3, 0x48(r3), 0, 0
    psq_l	f4, 0x50(r3), 0, 0
    psq_l	f5, 0x58(r3), 0, 0
    psq_st	f0, 0x0(r3), 0, 0
    psq_st	f1, 0x8(r3), 0, 0
    psq_st	f2, 0x10(r3), 0, 0
    psq_st	f3, 0x18(r3), 0, 0
    psq_st	f4, 0x20(r3), 0, 0
    psq_st	f5, 0x28(r3), 0, 0
    blr
}

asm void fn_8006DCDC(void)
{
    nofralloc
    lis	r3, -0x2000
    psq_l	f0, 0x0(r3), 0, 0
    psq_l	f1, 0x8(r3), 0, 0
    psq_l	f2, 0x10(r3), 0, 0
    psq_l	f3, 0x18(r3), 0, 0
    psq_l	f4, 0x20(r3), 0, 0
    psq_l	f5, 0x28(r3), 0, 0
    psq_st	f0, 0x30(r3), 0, 0
    psq_st	f1, 0x38(r3), 0, 0
    psq_st	f2, 0x40(r3), 0, 0
    psq_st	f3, 0x48(r3), 0, 0
    psq_st	f4, 0x50(r3), 0, 0
    psq_st	f5, 0x58(r3), 0, 0
    blr
}

asm void fn_8006DD14(void)
{
    nofralloc
    psq_l	f0, 0x0(r3), 0, 0
    psq_l	f1, 0x8(r3), 0, 0
    psq_l	f2, 0x10(r3), 0, 0
    psq_l	f3, 0x18(r3), 0, 0
    psq_l	f4, 0x20(r3), 0, 0
    psq_l	f5, 0x28(r3), 0, 0
    psq_st	f0, 0x0(r4), 0, 0
    psq_st	f1, 0x8(r4), 0, 0
    psq_st	f2, 0x10(r4), 0, 0
    psq_st	f3, 0x18(r4), 0, 0
    psq_st	f4, 0x20(r4), 0, 0
    psq_st	f5, 0x28(r4), 0, 0
    blr
    psq_l	f0, 0x0(r3), 0, 0
    lfs	f1, 8(r3)
    psq_l	f2, 0x10(r3), 0, 0
    lfs	f3, 0x18(r3)
    psq_l	f4, 0x20(r3), 0, 0
    lfs	f5, 0x28(r3)
    psq_st	f0, 0x0(r4), 0, 0
    stfs	f1, 8(r4)
    psq_st	f2, 0x10(r4), 0, 0
    stfs	f3, 0x18(r4)
    psq_st	f4, 0x20(r4), 0, 0
    stfs	f5, 0x28(r4)
    blr
    lis	r3, -0x2000
    stfd	f14, 0x98(r3)
    stfd	f15, 0xa0(r3)
    stfd	f16, 0xa8(r3)
    stfd	f17, 0xb0(r3)
    stfd	f18, 0xb8(r3)
    stfd	f19, 0xc0(r3)
    stfd	f20, 0xc8(r3)
    stfd	f21, 0xd0(r3)
    stfd	f22, 0xd8(r3)
    stfd	f23, 0xe0(r3)
    stfd	f24, 0xe8(r3)
    psq_st	f14, 0xf0(r3), 0, 0
    psq_st	f15, 0xf8(r3), 0, 0
    psq_st	f16, 0x100(r3), 0, 0
    psq_st	f17, 0x108(r3), 0, 0
    psq_st	f18, 0x110(r3), 0, 0
    psq_st	f19, 0x118(r3), 0, 0
    psq_st	f20, 0x120(r3), 0, 0
    psq_st	f21, 0x128(r3), 0, 0
    psq_st	f22, 0x130(r3), 0, 0
    psq_st	f23, 0x138(r3), 0, 0
    psq_st	f24, 0x140(r3), 0, 0
    lfs	f10, 0x24(r3)
    lfs	f7, 0x18(r3)
    fmuls	f13, f10, f7
    lfs	f2, 4(r3)
    lfs	f11, 0x28(r3)
    fmuls	f14, f2, f11
    lfs	f6, 0x14(r3)
    lfs	f3, 8(r3)
    fmuls	f15, f6, f3
    lfs	f5, 0x10(r3)
    fmuls	f17, f11, f5
    fmuls	f23, f5, f2
    lfs	f9, 0x20(r3)
    fmuls	f18, f3, f9
    fmuls	f21, f9, f6
    lfs	f1, 0(r3)
    fmuls	f19, f7, f1
    fmuls	f22, f1, f10
    lfs	f4, 0xc(r3)
    fmsubs	f13, f6, f11, f13
    lfs	f8, 0x1c(r3)
    fmsubs	f14, f10, f3, f14
    lfs	f12, 0x2c(r3)
    fmsubs	f15, f2, f7, f15
    fmsubs	f17, f7, f9, f17
    fmsubs	f18, f11, f1, f18
    fmsubs	f19, f3, f5, f19
    fmsubs	f21, f5, f10, f21
    fmsubs	f22, f9, f2, f22
    fmsubs	f23, f1, f6, f23
    fmuls	f0, f1, f13
    lfs	f1, 0x19c(r3)
    fmuls	f16, f4, f13
    fmuls	f20, f4, f17
    fmadds	f0, f5, f14, f0
    fmuls	f24, f4, f21
    fmadds	f16, f8, f14, f16
    fmadds	f0, f9, f15, f0
    fmadds	f20, f8, f18, f20
    fmadds	f24, f8, f22, f24
    fdivs	f0, f1, f0
    fnmadds	f16, f12, f15, f16
    fnmadds	f20, f12, f19, f20
    fnmadds	f24, f12, f23, f24
    fmuls	f1, f13, f0
    stfs	f1, 0(r3)
    fmuls	f2, f14, f0
    stfs	f2, 4(r3)
    fmuls	f3, f15, f0
    stfs	f3, 8(r3)
    fmuls	f4, f16, f0
    stfs	f4, 0xc(r3)
    fmuls	f5, f17, f0
    stfs	f5, 0x10(r3)
    fmuls	f6, f18, f0
    stfs	f6, 0x14(r3)
    fmuls	f7, f19, f0
    stfs	f7, 0x18(r3)
    fmuls	f8, f20, f0
    stfs	f8, 0x1c(r3)
    fmuls	f9, f21, f0
    stfs	f9, 0x20(r3)
    fmuls	f10, f22, f0
    stfs	f10, 0x24(r3)
    fmuls	f11, f23, f0
    stfs	f11, 0x28(r3)
    fmuls	f12, f24, f0
    stfs	f12, 0x2c(r3)
    psq_l	f14, 0xf0(r3), 0, 0
    psq_l	f15, 0xf8(r3), 0, 0
    psq_l	f16, 0x100(r3), 0, 0
    psq_l	f17, 0x108(r3), 0, 0
    psq_l	f18, 0x110(r3), 0, 0
    psq_l	f19, 0x118(r3), 0, 0
    psq_l	f20, 0x120(r3), 0, 0
    psq_l	f21, 0x128(r3), 0, 0
    psq_l	f22, 0x130(r3), 0, 0
    psq_l	f23, 0x138(r3), 0, 0
    psq_l	f24, 0x140(r3), 0, 0
    lfd	f14, 0x98(r3)
    lfd	f15, 0xa0(r3)
    lfd	f16, 0xa8(r3)
    lfd	f17, 0xb0(r3)
    lfd	f18, 0xb8(r3)
    lfd	f19, 0xc0(r3)
    lfd	f20, 0xc8(r3)
    lfd	f21, 0xd0(r3)
    lfd	f22, 0xd8(r3)
    lfd	f23, 0xe0(r3)
    lfd	f24, 0xe8(r3)
    blr
}

asm void fn_8006DF44(void)
{
    nofralloc
    lis	r3, -0x2000
    lfs	f3, 0xc(r3)
    lfs	f0, 0(r3)
    lfs	f1, 4(r3)
    lfs	f2, 8(r3)
    fmuls	f12, f3, f0
    lfs	f7, 0x1c(r3)
    fmuls	f13, f3, f1
    lfs	f4, 0x10(r3)
    fmuls	f0, f3, f2
    lfs	f5, 0x14(r3)
    lfs	f6, 0x18(r3)
    fmadds	f12, f7, f4, f12
    lfs	f11, 0x2c(r3)
    lfs	f8, 0x20(r3)
    fmadds	f13, f7, f5, f13
    lfs	f9, 0x24(r3)
    lfs	f10, 0x28(r3)
    fmadds	f0, f7, f6, f0
    stfs	f1, 0x10(r3)
    stfs	f2, 0x20(r3)
    fnmadds	f12, f11, f8, f12
    stfs	f6, 0x24(r3)
    stfs	f4, 4(r3)
    fnmadds	f13, f11, f9, f13
    stfs	f8, 8(r3)
    stfs	f9, 0x18(r3)
    fnmadds	f0, f11, f10, f0
    stfs	f12, 0xc(r3)
    stfs	f13, 0x1c(r3)
    stfs	f0, 0x2c(r3)
    blr
}

asm void fn_8006DFC4(void)
{
    nofralloc
    lis	r6, -0x2000
    mr	r4, r3
    addi	r3, r6, 0
    addi	r5, r6, 0
    b       _8006e000
    lis	r6, -0x2000
    addi	r4, r6, 0
    addi	r5, r6, 0
    b       _8006e000
    lis	r6, -0x2000
    mr	r4, r3
    addi	r3, r6, 0x30
    addi	r5, r6, 0
    b       _8006e000
}

asm void fn_8006DFFC(void)
{
    nofralloc
    lis	r6, -0x2000
    entry _8006e000
    psq_l	f0, 0x0(r4), 0, 0
    psq_l	f11, 0x0(r3), 0, 0
    psq_l	f1, 0x8(r4), 0, 0
    psq_l	f12, 0x10(r3), 0, 0
    psq_l	f2, 0x10(r4), 0, 0
    ps_muls0	f5, f0, f11
    psq_l	f13, 0x20(r3), 0, 0
    ps_muls0	f7, f0, f12
    psq_l	f3, 0x18(r4), 0, 0
    ps_muls0	f9, f0, f13
    ps_muls0	f6, f1, f11
    psq_l	f4, 0x20(r4), 0, 0
    ps_muls0	f8, f1, f12
    ps_muls0	f10, f1, f13
    psq_l	f0, 0x28(r4), 0, 0
    ps_madds1	f5, f2, f11, f5
    ps_madds1	f7, f2, f12, f7
    psq_l	f1, 0x8(r3), 0, 0
    ps_madds1	f9, f2, f13, f9
    ps_madds1	f6, f3, f11, f6
    psq_l	f2, 0x18(r3), 0, 0
    ps_madds1	f8, f3, f12, f8
    ps_madds1	f10, f3, f13, f10
    psq_l	f3, 0x28(r3), 0, 0
    ps_madds0	f5, f4, f1, f5
    ps_madds0	f7, f4, f2, f7
    psq_l	f11, 0x1ac(r6), 0, 2
    ps_madds0	f9, f4, f3, f9
    ps_madds0	f6, f0, f1, f6
    psq_st	f5, 0x0(r5), 0, 0
    ps_madds0	f8, f0, f2, f8
    psq_st	f7, 0x10(r5), 0, 0
    ps_madds0	f10, f0, f3, f10
    psq_st	f9, 0x20(r5), 0, 0
    ps_madd	f6, f11, f1, f6
    ps_madd	f8, f11, f2, f8
    psq_st	f6, 0x8(r5), 0, 0
    ps_madd	f10, f11, f3, f10
    psq_st	f8, 0x18(r5), 0, 0
    psq_st	f10, 0x28(r5), 0, 0
    blr
    lis	r4, -0x2000
    psq_l	f1, 0x0(r3), 0, 0
    psq_l	f3, 0x8(r3), 1, 0
}

asm void fn_8006E0B0(void)
{
    nofralloc
    b       _8006e0f0
    lis	r4, -0x2000
    ps_merge00	f1, f1, f2
    lfs	f0, 0x19c(r4)
    ps_merge00	f3, f3, f0
    b       _8006e0f0
}

asm void fn_8006E0C8(void)
{
    nofralloc
    lis	r4, -0x2000
    lfs	f3, 8(r3)
    psq_l	f1, 0x0(r3), 0, 0
    b       _8006e0e0
    lis	r4, -0x2000
    ps_merge00	f1, f1, f2
_8006e0e0:
    lfs	f0, 0x19c(r4)
    fneg	f3, f3
    ps_neg	f1, f1
    ps_merge00	f3, f3, f0
    entry _8006e0f0
    psq_l	f4, 0x0(r4), 0, 0
    psq_l	f6, 0x10(r4), 0, 0
    psq_l	f8, 0x20(r4), 0, 0
    ps_mul	f4, f4, f1
    psq_l	f5, 0x8(r4), 0, 0
    ps_mul	f6, f6, f1
    psq_l	f7, 0x18(r4), 0, 0
    ps_mul	f8, f8, f1
    psq_l	f9, 0x28(r4), 0, 0
    ps_madd	f4, f5, f3, f4
    ps_madd	f6, f7, f3, f6
    ps_madd	f8, f9, f3, f8
    ps_sum0	f4, f4, f4, f4
    stfs	f4, 0xc(r4)
    ps_sum0	f6, f6, f6, f6
    stfs	f6, 0x1c(r4)
    ps_sum0	f8, f8, f8, f8
    stfs	f8, 0x2c(r4)
    blr
    psq_l	f1, 0x0(r3), 0, 0
    lis	r4, -0x2000
    lfs	f3, 8(r3)
    b       _8006e164
}

asm void fn_8006E14C(void)
{
    nofralloc
    lis	r4, -0x2000
    fmr	f3, f1
    ps_merge00	f1, f1, f1
    b       _8006e164
    lis	r4, -0x2000
    ps_merge00	f1, f1, f2
    entry _8006e164
_8006e164:
    psq_l	f0, 0x0(r4), 0, 0
    lfs	f4, 8(r4)
    psq_l	f5, 0x10(r4), 0, 0
    ps_mul	f0, f0, f1
    lfs	f6, 0x18(r4)
    fmuls	f4, f4, f3
    psq_l	f7, 0x20(r4), 0, 0
    lfs	f8, 0x28(r4)
    ps_mul	f5, f5, f1
    psq_st	f0, 0x0(r4), 0, 0
    fmuls	f6, f6, f3
    stfs	f4, 8(r4)
    psq_st	f5, 0x10(r4), 0, 0
    ps_mul	f7, f7, f1
    stfs	f6, 0x18(r4)
    psq_st	f7, 0x20(r4), 0, 0
    fmuls	f8, f8, f3
    stfs	f8, 0x28(r4)
    blr
}

#pragma force_active off
