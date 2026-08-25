#pragma push
#pragma force_active on

extern asm void MTXSinCos(void);
extern asm void PSMTXRotTrig(void);
extern asm void sqrtf(void);
extern asm void atan2f(void);
extern asm void PSMTXRotRad(void);
extern asm void PSMTXRotTrigVariant(void);
extern asm void fn_8006E0C8(void);
extern asm void fn_8006D890(void);
extern asm void PSVecNormalize3(void);
extern asm void PSMTXLoadIdentityFused(void);
extern asm void fn_8006DF44(void);

extern unsigned char lbl_801A6D00[8];
asm void PSMTXRotAxisRadVariant(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stfd	f31, 0x10(r1)
    psq_st f31, 0x18(r1), 0, 0
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    mr	r30, r3
    fmr	f31, f1
    lha	r3, 2(r3)
    mr	r31, r4
    bl      MTXSinCos
    lha	r3, 0(r30)
    bl      PSMTXRotTrig
    lis	r3, -0x2000
    fneg	f3, f31
    lfs	f2, 8(r3)
    lfs	f1, 0x18(r3)
    fmuls	f2, f2, f3
    lfs	f0, 0x28(r3)
    fmuls	f1, f1, f3
    fmuls	f0, f0, f3
    stfs	f2, 0(r31)
    stfs	f1, 4(r31)
    stfs	f0, 8(r31)
    psq_l f31, 0x18(r1), 0, 0
    lwz	r0, 0x24(r1)
    lfd	f31, 0x10(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void PSMTXLookAt(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    stfd	f31, 0x40(r1)
    psq_st f31, 0x48(r1), 0, 0
    stfd	f30, 0x30(r1)
    psq_st f30, 0x38(r1), 0, 0
    stfd	f29, 0x20(r1)
    psq_st f29, 0x28(r1), 0, 0
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    lfs	f0, 0(r4)
    mr	r29, r3
    lfs	f2, 0(r3)
    mr	r31, r5
    lfs	f1, 8(r3)
    fsubs	f29, f2, f0
    lfs	f0, 8(r4)
    lfs	f3, 4(r4)
    fsubs	f31, f1, f0
    lfs	f2, 4(r3)
    fmuls	f1, f29, f29
    fsubs	f30, f3, f2
    fmadds	f1, f31, f31, f1
    bl      sqrtf
    fmr	f2, f1
    fmr	f1, f30
    bl      atan2f
    fmr	f1, f29
    mr	r30, r3
    fmr	f2, f31
    bl      atan2f
    neg	r0, r31
    mr	r31, r3
    extsh	r3, r0
    bl      PSMTXRotRad
    neg	r0, r30
    extsh	r3, r0
    bl      PSMTXRotTrig
    neg	r0, r31
    extsh	r3, r0
    bl      PSMTXRotTrigVariant
    mr	r3, r29
    bl      fn_8006E0C8
    psq_l f31, 0x48(r1), 0, 0
    lfd	f31, 0x40(r1)
    psq_l f30, 0x38(r1), 0, 0
    lfd	f30, 0x30(r1)
    psq_l f29, 0x28(r1), 0, 0
    lfd	f29, 0x20(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r0, 0x54(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void PSMTXLookAtNoUp(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stfd	f31, 0x30(r1)
    psq_st f31, 0x38(r1), 0, 0
    stfd	f30, 0x20(r1)
    psq_st f30, 0x28(r1), 0, 0
    stfd	f29, 0x10(r1)
    psq_st f29, 0x18(r1), 0, 0
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    lfs	f0, 0(r4)
    mr	r30, r3
    lfs	f2, 0(r3)
    lfs	f1, 8(r3)
    fsubs	f29, f2, f0
    lfs	f0, 8(r4)
    lfs	f3, 4(r4)
    fsubs	f31, f1, f0
    lfs	f2, 4(r3)
    fmuls	f1, f29, f29
    fsubs	f30, f3, f2
    fmadds	f1, f31, f31, f1
    bl      sqrtf
    fmr	f2, f1
    fmr	f1, f30
    bl      atan2f
    fmr	f1, f29
    mr	r31, r3
    fmr	f2, f31
    bl      atan2f
    neg	r0, r31
    mr	r31, r3
    extsh	r3, r0
    bl      fn_8006D890
    neg	r0, r31
    extsh	r3, r0
    bl      PSMTXRotTrigVariant
    mr	r3, r30
    bl      fn_8006E0C8
    psq_l f31, 0x38(r1), 0, 0
    lfd	f31, 0x30(r1)
    psq_l f30, 0x28(r1), 0, 0
    lfd	f30, 0x20(r1)
    psq_l f29, 0x18(r1), 0, 0
    lfd	f29, 0x10(r1)
    lwz	r31, 0xc(r1)
    lwz	r0, 0x44(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

asm void PSMTXReflect(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stw	r31, 0x3c(r1)
    mr	r31, r4
    stw	r30, 0x38(r1)
    mr	r30, r3
    lfs	f1, 0(r3)
    addi	r3, r1, 8
    lfs	f0, 0(r5)
    fsubs	f0, f1, f0
    stfs	f0, 8(r1)
    lfs	f1, 4(r30)
    lfs	f0, 4(r5)
    fsubs	f0, f1, f0
    stfs	f0, 0xc(r1)
    lfs	f1, 8(r30)
    lfs	f0, 8(r5)
    fsubs	f0, f1, f0
    stfs	f0, 0x10(r1)
    bl      PSVecNormalize3
    lfs	f0, -0x7a50(r2)
    fcmpu	cr0, f0, f1
    bne	_8006f25c
    mr	r3, r30
    bl      PSMTXLoadIdentityFused
    b	_8006f37c
_8006f25c:
    lfs	f6, 4(r31)
    addi	r3, r1, 0x20
    lfs	f3, 0x10(r1)
    lfs	f5, 8(r31)
    lfs	f4, 8(r1)
    fmuls	f2, f6, f3
    lfs	f0, 0xc(r1)
    lfs	f7, 0(r31)
    fmuls	f1, f5, f4
    fnmsubs	f2, f5, f0, f2
    fmuls	f0, f7, f0
    fnmsubs	f1, f7, f3, f1
    stfs	f2, 0x20(r1)
    fnmsubs	f0, f6, f4, f0
    stfs	f1, 0x24(r1)
    stfs	f0, 0x28(r1)
    bl      PSVecNormalize3
    lfs	f0, -0x7a50(r2)
    fcmpu	cr0, f0, f1
    bne	_8006f2b8
    mr	r3, r30
    bl      PSMTXLoadIdentityFused
    b	_8006f37c
_8006f2b8:
    lfs	f6, 0xc(r1)
    addi	r3, r1, 0x14
    lfs	f3, 0x28(r1)
    lfs	f5, 0x10(r1)
    lfs	f4, 0x20(r1)
    fmuls	f2, f6, f3
    lfs	f0, 0x24(r1)
    lfs	f7, 8(r1)
    fmuls	f1, f5, f4
    fnmsubs	f2, f5, f0, f2
    fmuls	f0, f7, f0
    fnmsubs	f1, f7, f3, f1
    stfs	f2, 0x14(r1)
    fnmsubs	f0, f6, f4, f0
    stfs	f1, 0x18(r1)
    stfs	f0, 0x1c(r1)
    bl      PSVecNormalize3
    lfs	f0, -0x7a50(r2)
    fcmpu	cr0, f0, f1
    bne	_8006f314
    mr	r3, r30
    bl      PSMTXLoadIdentityFused
    b	_8006f37c
_8006f314:
    lwz	r3, lbl_801A6D00
    lfs	f0, 0x20(r1)
    stfs	f0, 0(r3)
    lfs	f0, 0x14(r1)
    stfs	f0, 4(r3)
    lfs	f0, 8(r1)
    stfs	f0, 8(r3)
    lfs	f0, 0(r30)
    stfs	f0, 0xc(r3)
    lfs	f0, 0x24(r1)
    stfs	f0, 0x10(r3)
    lfs	f0, 0x18(r1)
    stfs	f0, 0x14(r3)
    lfs	f0, 0xc(r1)
    stfs	f0, 0x18(r3)
    lfs	f0, 4(r30)
    stfs	f0, 0x1c(r3)
    lfs	f0, 0x28(r1)
    stfs	f0, 0x20(r3)
    lfs	f0, 0x1c(r1)
    stfs	f0, 0x24(r3)
    lfs	f0, 0x10(r1)
    stfs	f0, 0x28(r3)
    lfs	f0, 8(r30)
    stfs	f0, 0x2c(r3)
    bl      fn_8006DF44
_8006f37c:
    lwz	r0, 0x44(r1)
    lwz	r31, 0x3c(r1)
    lwz	r30, 0x38(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

#pragma pop
