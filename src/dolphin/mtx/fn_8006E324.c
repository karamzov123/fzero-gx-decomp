#pragma push
#pragma force_active on

extern asm void lbl_8006D1C4(void);

asm void fn_8006E324(void)
{
    nofralloc
    mflr	r4
    bl      lbl_8006D1C4
    mtlr	r4
    lis	r4, -0x2000
    ps_merge00 f0, f2, f1
    psq_l	f3, 0x4(r4), 0, 0
    psq_l	f4, 0x14(r4), 0, 0
    psq_l	f5, 0x24(r4), 0, 0
    ps_mul f6, f3, f0
    ps_mul f7, f4, f0
    ps_mul f8, f5, f0
    fneg	f1, f1
    ps_sum0 f6, f6, f6, f6
    ps_sum0 f7, f7, f7, f7
    ps_sum0 f8, f8, f8, f8
    ps_merge00 f0, f1, f2
    stfs	f6, 4(r4)
    ps_mul f6, f3, f0
    stfs	f7, 0x14(r4)
    ps_mul f7, f4, f0
    stfs	f8, 0x24(r4)
    ps_mul f8, f5, f0
    ps_sum0 f6, f6, f6, f6
    stfs	f6, 8(r4)
    ps_sum0 f7, f7, f7, f7
    stfs	f7, 0x18(r4)
    ps_sum0 f8, f8, f8, f8
    stfs	f8, 0x28(r4)
    blr	
}

asm void fn_8006E398(void)
{
    nofralloc
    mflr	r4
    bl      lbl_8006D1C4
    mtlr	r4
    lis	r4, -0x2000
    ps_merge00 f0, f1, f2
    lfs	f3, 0(r4)
    lfs	f6, 8(r4)
    lfs	f4, 0x10(r4)
    lfs	f7, 0x18(r4)
    lfs	f5, 0x20(r4)
    lfs	f8, 0x28(r4)
    ps_merge00 f3, f3, f6
    ps_merge00 f4, f4, f7
    ps_merge00 f5, f5, f8
    ps_mul f6, f3, f0
    ps_mul f7, f4, f0
    ps_mul f8, f5, f0
    fneg	f1, f1
    ps_sum0 f6, f6, f6, f6
    ps_sum0 f7, f7, f7, f7
    ps_sum0 f8, f8, f8, f8
    ps_merge00 f0, f2, f1
    stfs	f6, 8(r4)
    ps_mul f6, f3, f0
    stfs	f7, 0x18(r4)
    ps_mul f7, f4, f0
    stfs	f8, 0x28(r4)
    ps_mul f8, f5, f0
    ps_sum0 f6, f6, f6, f6
    stfs	f6, 0(r4)
    ps_sum0 f7, f7, f7, f7
    stfs	f7, 0x10(r4)
    ps_sum0 f8, f8, f8, f8
    stfs	f8, 0x20(r4)
    blr	
}

asm void fn_8006E424(void)
{
    nofralloc
    mflr	r4
    bl      lbl_8006D1C4
    mtlr	r4
    lis	r4, -0x2000
    ps_merge00 f0, f2, f1
    psq_l	f3, 0x0(r4), 0, 0
    psq_l	f4, 0x10(r4), 0, 0
    psq_l	f5, 0x20(r4), 0, 0
    ps_mul f6, f3, f0
    ps_mul f7, f4, f0
    ps_mul f8, f5, f0
    fneg	f1, f1
    ps_sum0 f6, f6, f6, f6
    ps_sum0 f7, f7, f7, f7
    ps_sum0 f8, f8, f8, f8
    ps_merge00 f0, f1, f2
    stfs	f6, 0(r4)
    ps_mul f6, f3, f0
    stfs	f7, 0x10(r4)
    ps_mul f7, f4, f0
    stfs	f8, 0x20(r4)
    ps_mul f8, f5, f0
    ps_sum0 f6, f6, f6, f6
    stfs	f6, 4(r4)
    ps_sum0 f7, f7, f7, f7
    stfs	f7, 0x14(r4)
    ps_sum0 f8, f8, f8, f8
    stfs	f8, 0x24(r4)
    blr	
}

asm void fn_8006E498(void)
{
    nofralloc
    lis	r4, -0x2000
    lfs	f0, 0(r3)
    lfs	f1, 4(r3)
    lfs	f5, 0x19c(r4)
    lfs	f2, 8(r3)
    fsubs	f4, f5, f5
    lfs	f3, 0xc(r3)
    fadds	f6, f5, f5
    stfs	f4, 0xc(r4)
    stfs	f4, 0x1c(r4)
    stfs	f4, 0x2c(r4)
    fmuls	f9, f0, f0
    fmuls	f7, f1, f1
    fmuls	f8, f2, f2
    fmadds	f9, f2, f2, f9
    fmadds	f7, f0, f0, f7
    fmadds	f8, f1, f1, f8
    fnmsubs	f9, f9, f6, f5
    stfs	f9, 0x14(r4)
    fnmsubs	f7, f7, f6, f5
    stfs	f7, 0x28(r4)
    fnmsubs	f8, f8, f6, f5
    stfs	f8, 0(r4)
    fadds	f6, f0, f0
    fadds	f4, f1, f1
    fadds	f5, f2, f2
    fmuls	f6, f3, f6
    fmuls	f7, f3, f4
    fmuls	f8, f3, f5
    fmsubs	f9, f1, f5, f6
    stfs	f9, 0x18(r4)
    fmadds	f10, f1, f5, f6
    stfs	f10, 0x24(r4)
    fmsubs	f11, f0, f5, f7
    stfs	f11, 0x20(r4)
    fmadds	f12, f0, f5, f7
    stfs	f12, 8(r4)
    fmsubs	f13, f0, f4, f8
    stfs	f13, 4(r4)
    fmadds	f2, f0, f4, f8
    stfs	f2, 0x10(r4)
    blr	
}

asm void fn_8006E540(void)
{
    nofralloc
    lfs	f4, 0(r4)
    lfs	f5, 4(r4)
    lfs	f6, 8(r4)
    lfs	f7, 0xc(r4)
    lfs	f8, 0(r5)
    lfs	f9, 4(r5)
    lfs	f10, 8(r5)
    lfs	f11, 0xc(r5)
    fmul	f0, f6, f9
    fmul	f1, f4, f10
    fmul	f2, f5, f8
    fmul	f3, f6, f10
    fmsubs	f0, f5, f10, f0
    fmsubs	f1, f6, f8, f1
    fmsubs	f2, f4, f9, f2
    fmadds	f3, f5, f9, f3
    fmadds	f0, f4, f11, f0
    fmadds	f1, f5, f11, f1
    fmadds	f2, f6, f11, f2
    fmadds	f3, f4, f8, f3
    fmadds	f0, f7, f8, f0
    fmadds	f1, f7, f9, f1
    fmadds	f2, f7, f10, f2
    fmsubs	f3, f7, f11, f3
    stfs	f0, 0(r3)
    stfs	f1, 4(r3)
    stfs	f2, 8(r3)
    stfs	f3, 0xc(r3)
    blr	
}

asm void fn_8006E5B4(void)
{
    nofralloc
    ps_merge00 f0, f0, f1
    ps_merge00 f1, f2, f3
    b	_8006e5c8
    psq_l	f0, 0x0(r3), 0, 0
    psq_l	f1, 0x8(r3), 0, 0
_8006e5c8:
    lis	r5, -0x2000
    ps_mul f2, f0, f0
    ps_madd f2, f1, f1, f2
    ps_sum0 f2, f2, f2, f2
    lfs	f4, 0x198(r5)
    fcmpu	cr0, f2, f4
    blt	_8006e5f0
    ps_merge00 f2, f2, f2
    ps_mul f0, f0, f2
    ps_mul f1, f1, f2
_8006e5f0:
    psq_st	f0, 0x0(r3), 0, 0
    psq_st	f1, 0x8(r3), 0, 0
    blr	
}

#pragma pop
