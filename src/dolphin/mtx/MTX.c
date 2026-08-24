asm void PSMTXMultVec(void);

#pragma push
#pragma force_active on

asm void fn_8006E200(void)
{
    nofralloc
    ps_merge00 f3, f3, f0
    psq_l   f4, 0x0(r5), 0, 0
    psq_l   f6, 0x10(r5), 0, 0
    ps_mul f4, f4, f1
    psq_l   f8, 0x20(r5), 0, 0
    ps_mul f6, f6, f1
    psq_l   f5, 0x8(r5), 0, 0
    ps_mul f8, f8, f1
    psq_l   f7, 0x18(r5), 0, 0
    ps_madd f4, f5, f3, f4
    psq_l   f9, 0x28(r5), 0, 0
    ps_madd f6, f7, f3, f6
    ps_madd f8, f9, f3, f8
    ps_sum0 f4, f4, f4, f4
    stfs    f4, 0(r4)
    ps_sum0 f6, f6, f6, f6
    stfs    f6, 4(r4)
    ps_sum0 f8, f8, f8, f8
    stfs    f8, 8(r4)
    blr     
}

asm void C_MTXMultVec(void)
{
    nofralloc
    lfs     f1, 0(r3)
    lfs     f2, 4(r3)
    lfs     f3, 8(r3)
    b       _8006e270
    ps_merge00 f1, f1, f1
    ps_merge00 f2, f2, f2
    ps_merge00 f3, f3, f3
    mr      r4, r3
_8006e270:
    lis     r5, -0x2000
    crxor   2, 2, 2
    lfs     f10, 0xc(r5)
    lfs     f11, 0x1c(r5)
    lfs     f12, 0x2c(r5)
    fsubs   f1, f1, f10
    fsubs   f2, f2, f11
    fsubs   f3, f3, f12
    b       PSMTXMultVec
}

asm void C_MTXMultVecSS(void)
{
    nofralloc
    lis     r5, -0x2000
    mr      r4, r3
    creqv   2, 2, 2
    lfs     f1, 0xc(r5)
    lfs     f2, 0x1c(r5)
    lfs     f3, 0x2c(r5)
    b       PSMTXMultVec
}

asm void PSMTXMultVecSS(void)
{
    nofralloc
    lfs     f1, 0(r3)
    lfs     f2, 4(r3)
    lfs     f3, 8(r3)
    b       _8006e2d0
    ps_merge00 f1, f1, f1
    ps_merge00 f2, f2, f2
    ps_merge00 f3, f3, f3
    mr      r4, r3
_8006e2d0:
    lis     r5, -0x2000
    crxor   2, 2, 2
}

asm void PSMTXMultVec(void)
{
    nofralloc
    psq_l   f4, 0x0(r5), 0, 0
    lfs     f5, 8(r5)
    ps_mul f4, f4, f1
    psq_l   f6, 0x10(r5), 0, 0
    fmuls   f5, f5, f1
    lfs     f7, 0x18(r5)
    ps_madd f4, f6, f2, f4
    psq_l   f8, 0x20(r5), 0, 0
    fmadds  f5, f7, f2, f5
    lfs     f9, 0x28(r5)
    beq     _8006e310
    ps_madd f4, f8, f3, f4
    fmadds  f5, f9, f3, f5
    b       _8006e318
_8006e310:
    ps_nmadd f4, f8, f3, f4
    fnmadds f5, f9, f3, f5
_8006e318:
    psq_st  f4, 0x0(r4), 0, 0
    stfs    f5, 8(r4)
    blr     
}

