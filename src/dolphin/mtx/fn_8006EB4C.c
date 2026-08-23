#pragma push
#pragma force_active on

extern asm void fn_80088538(void);
extern asm void fn_800883E8(void);
extern asm void lbl_8006D0B4(void);
extern asm void lbl_8006D24C(void);

asm void fn_8006EB4C(void)
{
    nofralloc
    stwu	r1, -0x90(r1)
    mflr	r0
    stw	r0, 0x94(r1)
    stfd	f31, 0x80(r1)
    psq_st f31, 0x88(r1), 0, 0
    stfd	f30, 0x70(r1)
    psq_st f30, 0x78(r1), 0, 0
    stfd	f29, 0x60(r1)
    psq_st f29, 0x68(r1), 0, 0
    stfd	f28, 0x50(r1)
    psq_st f28, 0x58(r1), 0, 0
    stfd	f27, 0x40(r1)
    psq_st f27, 0x48(r1), 0, 0
    stfd	f26, 0x30(r1)
    psq_st f26, 0x38(r1), 0, 0
    stfd	f25, 0x20(r1)
    psq_st f25, 0x28(r1), 0, 0
    stfd	f24, 0x10(r1)
    psq_st f24, 0x18(r1), 0, 0
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    mr	r31, r4
    lfs	f31, 0(r5)
    lfs	f2, 0(r4)
    fmr	f26, f1
    lfs	f0, 4(r4)
    mr	r30, r3
    lfs	f30, 4(r5)
    fmuls	f1, f2, f31
    lfs	f2, 8(r4)
    fmuls	f0, f0, f30
    lfs	f29, 8(r5)
    lfs	f3, 0xc(r4)
    lfs	f28, 0xc(r5)
    fmuls	f2, f2, f29
    fadds	f1, f1, f0
    fmuls	f3, f3, f28
    lfs	f0, -0x7a6c(r2)
    fadds	f1, f2, f1
    fadds	f1, f3, f1
    fcmpo	cr0, f1, f0
    bge	_8006ec08
    fneg	f1, f1
    fneg	f31, f31
    fneg	f30, f30
    fneg	f29, f29
    fneg	f28, f28
_8006ec08:
    lfs	f3, -0x7a68(r2)
    lfd	f0, -0x7a58(r2)
    fsubs	f2, f3, f1
    fcmpo	cr0, f2, f0
    ble	_8006ec5c
    bl      fn_80088538
    frsp	f25, f1
    fmr	f1, f25
    bl      fn_800883E8
    lfs	f0, -0x7a68(r2)
    frsp	f24, f1
    fsubs	f0, f0, f26
    fmuls	f1, f0, f25
    bl      fn_800883E8
    fdiv	f27, f1, f24
    frsp	f27, f27
    fmuls	f1, f26, f25
    bl      fn_800883E8
    fdiv	f5, f1, f24
    frsp	f5, f5
    b	_8006ec64
_8006ec5c:
    fsubs	f27, f3, f26
    fmr	f5, f26
_8006ec64:
    lfs	f0, 0(r31)
    fmuls	f3, f5, f31
    fmuls	f2, f5, f30
    fmuls	f4, f27, f0
    fmuls	f1, f5, f29
    fmuls	f0, f5, f28
    fadds	f3, f4, f3
    stfs	f3, 0(r30)
    lfs	f3, 4(r31)
    fmuls	f3, f27, f3
    fadds	f2, f3, f2
    stfs	f2, 4(r30)
    lfs	f2, 8(r31)
    fmuls	f2, f27, f2
    fadds	f1, f2, f1
    stfs	f1, 8(r30)
    lfs	f1, 0xc(r31)
    fmuls	f1, f27, f1
    fadds	f0, f1, f0
    stfs	f0, 0xc(r30)
    psq_l f31, 0x88(r1), 0, 0
    lfd	f31, 0x80(r1)
    psq_l f30, 0x78(r1), 0, 0
    lfd	f30, 0x70(r1)
    psq_l f29, 0x68(r1), 0, 0
    lfd	f29, 0x60(r1)
    psq_l f28, 0x58(r1), 0, 0
    lfd	f28, 0x50(r1)
    psq_l f27, 0x48(r1), 0, 0
    lfd	f27, 0x40(r1)
    psq_l f26, 0x38(r1), 0, 0
    lfd	f26, 0x30(r1)
    psq_l f25, 0x28(r1), 0, 0
    lfd	f25, 0x20(r1)
    psq_l f24, 0x18(r1), 0, 0
    lfd	f24, 0x10(r1)
    lwz	r31, 0xc(r1)
    lwz	r0, 0x94(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x90
    blr	
}

asm void fn_8006ED0C(void)
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
    lfs	f2, 0(r3)
    mr	r31, r5
    lfs	f0, 0(r4)
    lfs	f1, 8(r3)
    fsubs	f31, f2, f0
    lfs	f0, 8(r4)
    lfs	f2, 4(r4)
    fsubs	f29, f1, f0
    lfs	f0, 4(r3)
    fmuls	f1, f31, f31
    fsubs	f30, f2, f0
    fmadds	f1, f29, f29, f1
    bl      lbl_8006D0B4
    fmr	f2, f1
    fmr	f1, f30
    bl      lbl_8006D24C
    fmr	f1, f31
    sth	r3, 0(r31)
    fmr	f2, f29
    bl      lbl_8006D24C
    sth	r3, 2(r31)
    li	r0, 0
    sth	r0, 4(r31)
    psq_l f31, 0x38(r1), 0, 0
    lfd	f31, 0x30(r1)
    psq_l f30, 0x28(r1), 0, 0
    lfd	f30, 0x20(r1)
    psq_l f29, 0x18(r1), 0, 0
    lfd	f29, 0x10(r1)
    lwz	r0, 0x44(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

asm void fn_8006EDBC(void)
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
    lfs	f2, 0(r3)
    mr	r30, r5
    lfs	f0, 0(r4)
    mr	r31, r6
    lfs	f1, 8(r3)
    fsubs	f31, f2, f0
    lfs	f0, 8(r4)
    lfs	f2, 4(r4)
    fsubs	f29, f1, f0
    lfs	f0, 4(r3)
    fmuls	f1, f31, f31
    fsubs	f30, f2, f0
    fmadds	f1, f29, f29, f1
    bl      lbl_8006D0B4
    fmr	f2, f1
    fmr	f1, f30
    bl      lbl_8006D24C
    fmr	f1, f31
    sth	r3, 0(r30)
    fmr	f2, f29
    bl      lbl_8006D24C
    sth	r3, 0(r31)
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

asm void fn_8006EE70(void)
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
    lfs	f1, 0(r3)
    mr	r31, r4
    lfs	f0, 8(r3)
    fneg	f31, f1
    lfs	f30, 4(r3)
    fneg	f29, f0
    fmuls	f1, f31, f31
    fmadds	f1, f29, f29, f1
    bl      lbl_8006D0B4
    fmr	f2, f1
    fmr	f1, f30
    bl      lbl_8006D24C
    fmr	f1, f31
    sth	r3, 0(r31)
    fmr	f2, f29
    bl      lbl_8006D24C
    sth	r3, 2(r31)
    li	r0, 0
    sth	r0, 4(r31)
    psq_l f31, 0x38(r1), 0, 0
    lfd	f31, 0x30(r1)
    psq_l f30, 0x28(r1), 0, 0
    lfd	f30, 0x20(r1)
    psq_l f29, 0x18(r1), 0, 0
    lfd	f29, 0x10(r1)
    lwz	r0, 0x44(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

asm void fn_8006EF10(void)
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
    lfs	f1, 0(r3)
    mr	r30, r4
    lfs	f0, 8(r3)
    mr	r31, r5
    fneg	f31, f1
    lfs	f30, 4(r3)
    fneg	f29, f0
    fmuls	f1, f31, f31
    fmadds	f1, f29, f29, f1
    bl      lbl_8006D0B4
    fmr	f2, f1
    fmr	f1, f30
    bl      lbl_8006D24C
    fmr	f1, f31
    sth	r3, 0(r30)
    fmr	f2, f29
    bl      lbl_8006D24C
    sth	r3, 0(r31)
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

#pragma pop
