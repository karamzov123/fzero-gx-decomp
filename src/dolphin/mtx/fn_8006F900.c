#pragma push
#pragma force_active on

extern asm void lbl_8006E1B0(void);
extern asm void fn_8006DBAC(void);
extern asm void fn_8006E5FC(void);
extern asm void PSMTXQuat_fromMtx(void);
extern asm void fn_8006E498(void);
extern asm void fn_8006DC34(void);
extern asm void fn_8006D5A4(void);
extern asm void fn_8006D668(void);

asm void PSQUATSlerp_c(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stfd	f31, 0x10(r1)
    psq_st f31, 0x18(r1), 0, 0
    stw	r31, 0xc(r1)
    mr	r31, r4
    fmr	f31, f1
    bl      lbl_8006E1B0
    lfs	f3, 8(r31)
    lfd	f0, -0x7a40(r2)
    fabs	f1, f3
    fcmpo	cr0, f1, f0
    ble	_8006f97c
    lfs	f2, -0x7a34(r2)
    fmuls	f3, f3, f31
    lfs	f1, -0x7da4(r13)
    lfs	f0, -0x7da8(r13)
    fmuls	f1, f2, f1
    lfs	f4, -0x7a48(r2)
    fmuls	f0, f2, f0
    lfs	f2, 0(r31)
    fdivs	f3, f4, f3
    fdivs	f0, f1, f0
    fmuls	f0, f2, f0
    fmuls	f0, f3, f0
    stfs	f0, 0(r31)
    lfs	f0, 4(r31)
    fmuls	f0, f0, f3
    stfs	f0, 4(r31)
    b	_8006f988
_8006f97c:
    lfs	f0, -0x7a38(r2)
    stfs	f0, 0(r31)
    stfs	f0, 4(r31)
_8006f988:
    psq_l f31, 0x18(r1), 0, 0
    lwz	r0, 0x24(r1)
    lfd	f31, 0x10(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8006F9A4(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    stfd	f31, 0x48(r1)
    fmr	f31, f1
    stw	r31, 0x44(r1)
    mr	r31, r5
    stw	r30, 0x40(r1)
    mr	r30, r4
    bl      fn_8006DBAC
    addi	r3, r1, 0x28
    bl      fn_8006E5FC
    mr	r3, r30
    bl      fn_8006DBAC
    addi	r3, r1, 0x18
    bl      fn_8006E5FC
    fmr	f1, f31
    addi	r3, r1, 8
    addi	r4, r1, 0x28
    addi	r5, r1, 0x18
    bl      PSMTXQuat_fromMtx
    addi	r3, r1, 8
    bl      fn_8006E498
    mr	r3, r31
    bl      fn_8006DC34
    lwz	r0, 0x54(r1)
    lfd	f31, 0x48(r1)
    lwz	r31, 0x44(r1)
    lwz	r30, 0x40(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void PSMTXConcat(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stfd	f31, 0x20(r1)
    psq_st f31, 0x28(r1), 0, 0
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    fmr	f31, f1
    mr	r29, r3
    mr	r30, r4
    mr	r31, r5
    bl      fn_8006D5A4
    fmr	f1, f31
    addi	r3, r29, 0x10
    addi	r4, r30, 0x10
    addi	r5, r31, 0x10
    bl      fn_8006D5A4
    lfs	f6, 4(r31)
    mr	r3, r31
    lfs	f3, 0x18(r31)
    lfs	f5, 8(r31)
    lfs	f4, 0x10(r31)
    fmuls	f2, f6, f3
    lfs	f0, 0x14(r31)
    lfs	f7, 0(r31)
    fmuls	f1, f5, f4
    fnmsubs	f2, f5, f0, f2
    fmuls	f0, f7, f0
    fnmsubs	f1, f7, f3, f1
    stfs	f2, 0x20(r31)
    fnmsubs	f0, f6, f4, f0
    stfs	f1, 0x24(r31)
    stfs	f0, 0x28(r31)
    lfs	f6, 0x24(r31)
    lfs	f3, 8(r31)
    lfs	f5, 0x28(r31)
    lfs	f4, 0(r31)
    fmuls	f2, f6, f3
    lfs	f0, 4(r31)
    lfs	f7, 0x20(r31)
    fmuls	f1, f5, f4
    fnmsubs	f2, f5, f0, f2
    fmuls	f0, f7, f0
    fnmsubs	f1, f7, f3, f1
    stfs	f2, 0x10(r31)
    fnmsubs	f0, f6, f4, f0
    stfs	f1, 0x14(r31)
    stfs	f0, 0x18(r31)
    bl      fn_8006D668
    addi	r3, r31, 0x10
    bl      fn_8006D668
    addi	r3, r31, 0x20
    bl      fn_8006D668
    psq_l f31, 0x28(r1), 0, 0
    lwz	r0, 0x34(r1)
    lfd	f31, 0x20(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_8006FB20(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stfd	f31, 0x10(r1)
    psq_st f31, 0x18(r1), 0, 0
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    lwz	r31, -0x76c0(r13)
    fmr	f31, f1
    mr	r30, r3
    mr	r3, r31
    mr	r5, r31
    mr	r4, r30
    bl      fn_8006D5A4
    fmr	f1, f31
    addi	r3, r31, 0x10
    mr	r5, r3
    addi	r4, r30, 0x10
    bl      fn_8006D5A4
    lfs	f6, 4(r31)
    mr	r3, r31
    lfs	f3, 0x18(r31)
    lfs	f5, 8(r31)
    lfs	f4, 0x10(r31)
    fmuls	f2, f6, f3
    lfs	f0, 0x14(r31)
    lfs	f7, 0(r31)
    fmuls	f1, f5, f4
    fnmsubs	f2, f5, f0, f2
    fmuls	f0, f7, f0
    fnmsubs	f1, f7, f3, f1
    stfs	f2, 0x20(r31)
    fnmsubs	f0, f6, f4, f0
    stfs	f1, 0x24(r31)
    stfs	f0, 0x28(r31)
    lfs	f6, 0x24(r31)
    lfs	f3, 8(r31)
    lfs	f5, 0x28(r31)
    lfs	f4, 0(r31)
    fmuls	f2, f6, f3
    lfs	f0, 4(r31)
    lfs	f7, 0x20(r31)
    fmuls	f1, f5, f4
    fnmsubs	f2, f5, f0, f2
    fmuls	f0, f7, f0
    fnmsubs	f1, f7, f3, f1
    stfs	f2, 0x10(r31)
    fnmsubs	f0, f6, f4, f0
    stfs	f1, 0x14(r31)
    stfs	f0, 0x18(r31)
    bl      fn_8006D668
    addi	r3, r31, 0x10
    bl      fn_8006D668
    addi	r3, r31, 0x20
    bl      fn_8006D668
    psq_l f31, 0x18(r1), 0, 0
    lwz	r0, 0x24(r1)
    lfd	f31, 0x10(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
