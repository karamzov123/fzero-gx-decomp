#pragma push
#pragma force_active on

extern unsigned char lbl_801A73F0[4];
extern unsigned char lbl_801A73F4[4];
extern unsigned char lbl_801A73FC[4];
extern unsigned char lbl_801A6618[4];
extern unsigned char lbl_801A661C[4];
extern unsigned char lbl_801A7400[8];
extern unsigned char lbl_801A7408[4];
extern unsigned char lbl_801A740C[4];

asm void mtx_gpstack_push(void);
extern asm void lbl_8006E1C0(void);
extern asm void atan2f(void);
extern asm void sqrtf(void);
extern asm void PSMTXRotRad(void);
extern asm void PSMTXRotTrigVariant(void);
extern asm void PSMTXMultVecSS(void);
extern asm void mtx_gpstack_pop(void);
extern asm void lbl_8006E1B0(void);

asm void C_MTXLookAtInPlace(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    mr	r31, r3
    bl      mtx_gpstack_push
    lfs	f0, lbl_801A73F0(r2)
    addi	r3, r1, 8
    lfs	f1, lbl_801A73F4(r2)
    mr	r4, r3
    stfs	f0, 0xc(r1)
    stfs	f1, 8(r1)
    stfs	f0, 0x10(r1)
    stfs	f0, 0x14(r1)
    stfs	f1, 0x18(r1)
    stfs	f0, 0x1c(r1)
    bl      lbl_8006E1C0
    addi	r3, r1, 0x14
    mr	r4, r3
    bl      lbl_8006E1C0
    lfs	f1, 0xc(r1)
    lfs	f2, 8(r1)
    bl      atan2f
    sth	r3, 4(r31)
    lfs	f1, 0xc(r1)
    lfs	f0, 8(r1)
    fmuls	f1, f1, f1
    fmadds	f1, f0, f0, f1
    bl      sqrtf
    fmr	f2, f1
    lfs	f1, 0x10(r1)
    bl      atan2f
    neg	r0, r3
    sth	r0, 2(r31)
    lha	r3, 4(r31)
    bl      PSMTXRotRad
    lha	r3, 2(r31)
    bl      PSMTXRotTrigVariant
    addi	r3, r1, 0x14
    mr	r4, r3
    bl      PSMTXMultVecSS
    lfs	f1, 0x1c(r1)
    lfs	f2, 0x18(r1)
    bl      atan2f
    sth	r3, 0(r31)
    bl      mtx_gpstack_pop
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void PSMTXScaleConst(void)
{
    nofralloc
    lfs	f0, lbl_801A73FC(r2)
    fmuls	f1, f1, f0
    fmuls	f0, f2, f0
    stfs	f1, lbl_801A6618(r13)
    stfs	f0, lbl_801A661C(r13)
    blr	
}

asm void PSQUATSlerp_a(void)
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
    lfs	f2, 8(r31)
    lfd	f0, lbl_801A7400(r2)
    fabs	f1, f2
    fcmpo	cr0, f1, f0
    ble	_8006f800
    fmuls	f2, f2, f31
    lfs	f3, lbl_801A661C(r13)
    lfs	f0, 0(r31)
    lfs	f1, lbl_801A6618(r13)
    fdivs	f2, f3, f2
    fneg	f0, f0
    fmuls	f0, f0, f2
    fadds	f0, f1, f0
    stfs	f0, 0(r31)
    lfs	f0, 4(r31)
    lfs	f1, lbl_801A661C(r13)
    fmuls	f0, f0, f2
    fadds	f0, f1, f0
    stfs	f0, 4(r31)
    b	_8006f80c
_8006f800:
    lfs	f0, lbl_801A7408(r2)
    stfs	f0, 0(r31)
    stfs	f0, 4(r31)
_8006f80c:
    psq_l f31, 0x18(r1), 0, 0
    lwz	r0, 0x24(r1)
    lfd	f31, 0x10(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void PSQUATSlerp_b(void)
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
    lfs	f2, 8(r31)
    lfd	f0, lbl_801A7400(r2)
    fabs	f1, f2
    fcmpo	cr0, f1, f0
    ble	_8006f8d8
    fmuls	f2, f2, f31
    lfs	f3, lbl_801A661C(r13)
    lfs	f0, 0(r31)
    lfs	f1, lbl_801A6618(r13)
    fdivs	f3, f3, f2
    lfs	f2, lbl_801A740C(r2)
    fneg	f0, f0
    fmuls	f0, f0, f3
    fadds	f0, f1, f0
    stfs	f0, 0(r31)
    lfs	f0, 4(r31)
    lfs	f1, lbl_801A661C(r13)
    fmuls	f0, f0, f3
    fadds	f0, f1, f0
    stfs	f0, 4(r31)
    lfs	f0, lbl_801A6618(r13)
    lfs	f3, 0(r31)
    fmuls	f0, f2, f0
    fcmpo	cr0, f3, f0
    bge	_8006f8d8
    lfs	f1, lbl_801A73F0(r2)
    fcmpo	cr0, f3, f1
    ble	_8006f8d8
    lfs	f0, lbl_801A661C(r13)
    lfs	f3, 4(r31)
    fmuls	f0, f2, f0
    fcmpo	cr0, f3, f0
    bge	_8006f8d8
    fcmpo	cr0, f3, f1
    bgt	_8006f8e4
_8006f8d8:
    lfs	f0, lbl_801A7408(r2)
    stfs	f0, 0(r31)
    stfs	f0, 4(r31)
_8006f8e4:
    psq_l f31, 0x18(r1), 0, 0
    lwz	r0, 0x24(r1)
    lfd	f31, 0x10(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
