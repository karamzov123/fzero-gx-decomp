typedef unsigned int u32;
typedef signed int s32;

asm void fn_80071CC0(void);
asm void fn_80071CE8(void);
asm void fn_80071D0C(void);
asm void fn_80071D30(void);
asm void GXCompareVecDirty(void);
asm void fn_80072014(void);
asm void Snd_SetOutputModeBit0(void);
asm void fn_80072168(void);
asm void fn_800721FC(void);
asm void GXComputeDeltaRatio(void);
asm void fn_80072344(void);
asm void fn_80072378(void);

extern void DVDOpen(void);
extern void DVDCancelSync(void);
extern void DVDReadAsync(void);
extern void fn_80015E18(void);
extern void GXWriteTextureState(void);
extern void GXSetProjectionv(void);
extern void GXBeginDisplayList(void);
extern void GXEndDisplayList(void);
extern void GXClearVtxDesc(void);
extern void GXSetVtxDesc(void);
extern void fn_800793D4(void);
extern void GXSetMatrixIndexA(void);
extern void GXSetMatrixIndexB(void);
extern void* memcpy(void*, const void*, unsigned long);
extern unsigned char lbl_8015AC68[84];
extern unsigned char lbl_8015ACBC[84];
extern unsigned char lbl_8019E250[184];
extern unsigned char lbl_8019F008[28];
extern unsigned char lbl_8019F024[28];

#pragma push
#pragma force_active on

asm void fn_80071CC0(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    bl      DVDOpen
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm u32 fn_80071CE0(register void* a)
{
    nofralloc
    lwz     r3, 0x34(r3)
    blr
}

asm void fn_80071CE8(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    li      r7, 2
    stw     r0, 0x14(r1)
    bl      DVDReadAsync
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void fn_80071D0C(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    bl      DVDCancelSync
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void fn_80071D2C(void)
{
    nofralloc
    blr
}

asm void fn_80071D30(void)
{
    nofralloc
    stwu    r1, -0x20(r1)
    mflr    r0
    lis     r3, lbl_8019E250@ha
    li      r4, 0
    stw     r0, 0x24(r1)
    li      r0, 2
    stw     r31, 0x1c(r1)
    addi    r31, r3, lbl_8019E250@l
    addi    r3, r31, 0
    lwz     r6, -0x7520(r2)
    addi    r7, r31, 0x38
    lwz     r5, -0x79f8(r2)
    stw     r6, 0x14(r1)
    stw     r5, 0x10(r1)
    stw     r4, 0x2c(r3)
    stb     r4, 0(r31)
    stb     r4, 1(r3)
    stb     r4, 2(r3)
    stb     r4, 3(r3)
    stw     r7, -0x7694(r13)
    mtctr   r0
_80071d84:
    li      r0, -1
    stb     r0, 0(r7)
    stb     r0, 1(r7)
    stb     r0, 2(r7)
    stb     r0, 3(r7)
    stb     r0, 4(r7)
    stb     r0, 5(r7)
    stb     r0, 8(r7)
    stb     r0, 9(r7)
    stb     r0, 0xa(r7)
    stb     r0, 0xb(r7)
    stb     r0, 0xc(r7)
    stb     r0, 0xd(r7)
    stb     r0, 0x10(r7)
    stb     r0, 0x11(r7)
    stb     r0, 0x12(r7)
    stb     r0, 0x13(r7)
    stb     r0, 0x14(r7)
    stb     r0, 0x15(r7)
    stb     r0, 0x18(r7)
    stb     r0, 0x19(r7)
    stb     r0, 0x1a(r7)
    stb     r0, 0x1b(r7)
    stb     r0, 0x1c(r7)
    stb     r0, 0x1d(r7)
    stb     r0, 0x20(r7)
    stb     r0, 0x21(r7)
    stb     r0, 0x22(r7)
    stb     r0, 0x23(r7)
    stb     r0, 0x24(r7)
    stb     r0, 0x25(r7)
    stb     r0, 0x28(r7)
    stb     r0, 0x29(r7)
    stb     r0, 0x2a(r7)
    stb     r0, 0x2b(r7)
    stb     r0, 0x2c(r7)
    stb     r0, 0x2d(r7)
    stb     r0, 0x30(r7)
    stb     r0, 0x31(r7)
    stb     r0, 0x32(r7)
    stb     r0, 0x33(r7)
    stb     r0, 0x34(r7)
    stb     r0, 0x35(r7)
    stb     r0, 0x38(r7)
    stb     r0, 0x39(r7)
    stb     r0, 0x3a(r7)
    stb     r0, 0x3b(r7)
    stb     r0, 0x3c(r7)
    stb     r0, 0x3d(r7)
    addi    r7, r7, 0x40
    bdnz    _80071d84
    addi    r3, r31, 0xb8
    li      r4, 0xff
    li      r5, 0xd00
    bl      fn_800793D4
    lwz     r0, 0x14(r1)
    addi    r3, r31, 0
    lfs     f1, -0x79f4(r2)
    stw     r0, 0x20(r3)
    lfs     f2, -0x79f0(r2)
    stw     r0, 0x30(r3)
    lfs     f3, -0x79ec(r2)
    stw     r0, 0x34(r3)
    lfs     f4, -0x79e8(r2)
    bl      fn_800721FC
    lfs     f1, -0x79e4(r2)
    li      r3, 4
    fmr     f2, f1
    bl      GXCompareVecDirty
    li      r3, 0
    bl      Snd_SetOutputModeBit0
    lwz     r0, 0x10(r1)
    addi    r3, r1, 0xc
    stw     r0, 0xc(r1)
    bl      GXSetMatrixIndexA
    lwz     r0, 0x10(r1)
    addi    r3, r1, 8
    stw     r0, 8(r1)
    bl      GXSetMatrixIndexB
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    mtlr    r0
    addi    r1, r1, 0x20
    blr
}

asm void GXCompareVecDirty(void)
{
    nofralloc
    stwu    r1, -0x30(r1)
    mflr    r0
    stw     r0, 0x34(r1)
    stfd    f31, 0x20(r1)
    psq_st  f31, 0x28(r1), 0, 0
    stfd    f30, 0x10(r1)
    psq_st  f30, 0x18(r1), 0, 0
    lis     r4, lbl_8019E250@ha
    fmr     f31, f2
    addi    r7, r4, lbl_8019E250@l
    fmr     f30, f1
    lfs     f0, 0x14(r7)
    lfs     f3, 4(r7)
    fcmpu   cr0, f31, f0
    lfs     f4, 8(r7)
    bne     _80071f44
    lfs     f0, 0x10(r7)
    fcmpu   cr0, f30, f0
    bne     _80071f44
    lfs     f0, 0x18(r7)
    fcmpu   cr0, f4, f0
    bne     _80071f44
    lfs     f0, 0x1c(r7)
    fcmpu   cr0, f3, f0
    bne     _80071f44
    lwz     r0, 0xc(r7)
    cmpw    r3, r0
    beq     _80071ff4
_80071f44:
    cmpwi   r3, 0
    bne     _80071f58
    li      r3, 0
    bl      Snd_SetOutputModeBit0
    b       _80071ff4
_80071f58:
    lis     r4, lbl_8019E250@ha
    fmr     f1, f30
    addi    r6, r4, lbl_8019E250@l
    fmr     f2, f31
    lwz     r4, 0x2c(r6)
    lwz     r0, 0x20(r6)
    ori     r5, r4, 1
    stw     r3, 0xc(r6)
    addi    r4, r1, 8
    stfs    f30, 0x10(r6)
    stfs    f31, 0x14(r7)
    stfs    f4, 0x18(r6)
    stfs    f3, 0x1c(r6)
    stw     r5, 0x2c(r6)
    stw     r0, 8(r1)
    bl      GXWriteTextureState
    fcmpu   cr0, f30, f31
    bne     _80071fa8
    lfs     f0, -0x79e4(r2)
    b       _80071fb0
_80071fa8:
    fsubs   f0, f31, f30
    fdivs   f0, f30, f0
_80071fb0:
    stfs    f0, 0xc(r1)
    lis     r3, lbl_8019E250@ha
    addi    r4, r3, lbl_8019E250@l
    lwz     r5, 0xc(r1)
    lwz     r3, 0x24(r4)
    rlwinm  r0, r5, 0x14, 0x15, 0x1f
    rlwimi  r0, r3, 0, 0, 0x14
    stw     r0, 0x24(r4)
    rlwimi  r0, r5, 0x14, 0xd, 0x14
    stw     r0, 0x24(r4)
    rlwimi  r0, r5, 0x14, 0xc, 0xc
    rlwinm  r3, r0, 0, 0xc, 0xa
    stw     r0, 0x24(r4)
    clrlwi  r0, r3, 8
    oris    r0, r0, 0xf100
    stw     r3, 0x24(r4)
    stw     r0, 0x24(r4)
_80071ff4:
    psq_l   f31, 0x28(r1), 0, 0
    lfd     f31, 0x20(r1)
    psq_l   f30, 0x18(r1), 0, 0
    lwz     r0, 0x34(r1)
    lfd     f30, 0x10(r1)
    mtlr    r0
    addi    r1, r1, 0x30
    blr
}

asm void fn_80072014(void)
{
    nofralloc
    lis     r4, lbl_8019E250@ha
    lbz     r9, 0(r3)
    addi    r8, r4, lbl_8019E250@l
    lbz     r0, 0x20(r8)
    cmplw   r0, r9
    bne     _8007204c
    lbz     r4, 0x21(r8)
    lbz     r0, 1(r3)
    cmplw   r4, r0
    bne     _8007204c
    lbz     r4, 0x22(r8)
    lbz     r0, 2(r3)
    cmplw   r4, r0
    beqlr
_8007204c:
    lbz     r5, 2(r3)
    lis     r4, lbl_8019E250@ha
    lbz     r7, 1(r3)
    addi    r6, r4, lbl_8019E250@l
    rlwinm  r0, r5, 0, 0x18, 0xf
    stb     r5, 0x22(r6)
    mr      r10, r0
    lbz     r3, 0(r3)
    rlwimi  r10, r7, 8, 0x10, 0x17
    stb     r9, 0x20(r8)
    rlwinm  r0, r10, 0, 0x10, 7
    lwz     r4, -0x7de8(r2)
    mr      r10, r0
    stb     r7, 0x21(r6)
    rlwimi  r10, r3, 0x10, 8, 0xf
    li      r0, 0
    clrlwi  r3, r10, 8
    li      r5, 0x61
    oris    r10, r3, 0xf200
    stw     r10, 0x28(r6)
    lis     r3, -0x33ff
    sth     r0, 2(r4)
    stb     r5, -0x8000(r3)
    stw     r10, -0x8000(r3)
    blr
}

asm void Snd_SetOutputModeBit0(void)
{
    nofralloc
    cmpwi   r3, 0
    beq     _80072118
    lis     r3, lbl_8019E250@ha
    addi    r6, r3, lbl_8019E250@l
    lwz     r3, 0x2c(r6)
    clrlwi. r0, r3, 0x1f
    bnelr
    lwz     r5, 0x24(r6)
    ori     r3, r3, 1
    lwz     r4, 0xc(r6)
    rlwinm  r0, r5, 0xb, 0x1d, 0x1f
    stw     r3, 0x2c(r6)
    cmplw   r0, r4
    beqlr
    rlwinm  r3, r5, 0, 0xb, 7
    slwi    r0, r4, 0x15
    or      r5, r3, r0
    lwz     r4, -0x7de8(r2)
    stw     r5, 0x24(r6)
    li      r0, 0
    li      r6, 0x61
    lis     r3, -0x33ff
    sth     r0, 2(r4)
    stb     r6, -0x8000(r3)
    stw     r5, -0x8000(r3)
    blr
_80072118:
    lis     r3, lbl_8019E250@ha
    addi    r6, r3, lbl_8019E250@l
    lwz     r3, 0x2c(r6)
    clrlwi. r0, r3, 0x1f
    beqlr
    lwz     r4, 0x24(r6)
    rlwinm  r0, r3, 0, 0, 0x1e
    stw     r0, 0x2c(r6)
    rlwinm. r0, r4, 0xb, 0x1d, 0x1f
    beqlr
    rlwinm  r5, r4, 0, 0xb, 7
    lwz     r4, -0x7de8(r2)
    stw     r5, 0x24(r6)
    li      r0, 0
    li      r6, 0x61
    lis     r3, -0x33ff
    sth     r0, 2(r4)
    stb     r6, -0x8000(r3)
    stw     r5, -0x8000(r3)
    blr
}

asm void fn_80072168(void)
{
    nofralloc
    lis     r4, lbl_8019E250@ha
    addi    r6, r4, lbl_8019E250@l
    lwz     r0, 0x2c(r6)
    clrlwi. r0, r0, 0x1f
    beqlr
    cmpwi   r3, 0
    beq     _800721c8
    lwz     r3, 0x24(r6)
    lwz     r4, 0xc(r6)
    rlwinm  r0, r3, 0xb, 0x1d, 0x1f
    cmplw   r0, r4
    beqlr
    rlwinm  r3, r3, 0, 0xb, 7
    slwi    r0, r4, 0x15
    or      r5, r3, r0
    lwz     r4, -0x7de8(r2)
    stw     r5, 0x24(r6)
    li      r0, 0
    li      r6, 0x61
    lis     r3, -0x33ff
    sth     r0, 2(r4)
    stb     r6, -0x8000(r3)
    stw     r5, -0x8000(r3)
    blr
_800721c8:
    lwz     r3, 0x24(r6)
    rlwinm. r0, r3, 0xb, 0x1d, 0x1f
    beqlr
    rlwinm  r5, r3, 0, 0xb, 7
    lwz     r4, -0x7de8(r2)
    stw     r5, 0x24(r6)
    li      r0, 0
    li      r6, 0x61
    lis     r3, -0x33ff
    sth     r0, 2(r4)
    stb     r6, -0x8000(r3)
    stw     r5, -0x8000(r3)
    blr
}

asm void fn_800721FC(void)
{
    nofralloc
    stwu    r1, -0x50(r1)
    mflr    r0
    lis     r4, lbl_8019E250@ha
    stw     r0, 0x54(r1)
    addi    r4, r4, lbl_8019E250@l
    addi    r3, r1, 8
    stfs    f3, 4(r4)
    stfs    f4, 8(r4)
    bl      fn_80015E18
    lfs     f6, -0x79e4(r2)
    lis     r3, -0x7fe6
    lfs     f5, 8(r1)
    stfsu   f6, -0xff8(r3)
    lfs     f4, 0x10(r1)
    lfs     f3, 0x1c(r1)
    lfs     f2, 0x20(r1)
    lfs     f1, 0x30(r1)
    lfs     f0, 0x34(r1)
    stfs    f5, 4(r3)
    stfs    f4, 8(r3)
    stfs    f3, 0xc(r3)
    stfs    f2, 0x10(r3)
    stfs    f1, 0x14(r3)
    stfs    f0, 0x18(r3)
    bl      GXSetProjectionv
    lwz     r0, 0x54(r1)
    mtlr    r0
    addi    r1, r1, 0x50
    blr
}

asm void GXComputeDeltaRatio(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    lfs     f1, -0x79e4(r2)
    stw     r0, 0x14(r1)
    lfs     f0, 0(r3)
    fcmpu   cr0, f1, f0
    bne     _800722b8
    lfs     f1, 0x14(r3)
    lis     r4, lbl_8019E250@ha
    lfs     f0, -0x79e0(r2)
    addi    r4, r4, lbl_8019E250@l
    lfs     f2, 0x18(r3)
    fsubs   f0, f1, f0
    fdivs   f0, f2, f0
    fabs    f0, f0
    frsp    f0, f0
    stfs    f0, 4(r4)
    b       _800722e0
_800722b8:
    lfs     f2, -0x79e0(r2)
    lis     r4, lbl_8019E250@ha
    lfs     f1, 0x18(r3)
    addi    r4, r4, lbl_8019E250@l
    lfs     f0, 0x14(r3)
    fadds   f1, f2, f1
    fdivs   f0, f1, f0
    fabs    f0, f0
    frsp    f0, f0
    stfs    f0, 4(r4)
_800722e0:
    lfs     f2, 0x18(r3)
    lis     r5, lbl_8019E250@ha
    lfs     f1, 0x14(r3)
    addi    r5, r5, lbl_8019E250@l
    lis     r4, -0x7fe6
    fdivs   f0, f2, f1
    stfs    f0, 8(r5)
    lfs     f0, 0(r3)
    stfsu   f0, -0xff8(r4)
    lfs     f0, 4(r3)
    stfs    f0, 4(r4)
    lfs     f0, 8(r3)
    stfs    f0, 8(r4)
    lfs     f0, 0xc(r3)
    stfs    f0, 0xc(r4)
    lfs     f0, 0x10(r3)
    mr      r3, r4
    stfs    f0, 0x10(r4)
    stfs    f1, 0x14(r4)
    stfs    f2, 0x18(r4)
    bl      GXSetProjectionv
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void fn_80072344(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    lis     r3, lbl_8019F024@ha
    lis     r4, lbl_8019F008@ha
    stw     r0, 0x14(r1)
    addi    r3, r3, lbl_8019F024@l
    li      r5, 0x1c
    addi    r4, r4, lbl_8019F008@l
    bl      memcpy
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void fn_80072378(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    lis     r3, lbl_8019F008@ha
    lis     r4, lbl_8019F024@ha
    stw     r0, 0x14(r1)
    addi    r3, r3, lbl_8019F008@l
    li      r5, 0x1c
    addi    r4, r4, lbl_8019F024@l
    bl      memcpy
    lis     r3, lbl_8019F008@ha
    addi    r3, r3, lbl_8019F008@l
    bl      GXSetProjectionv
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void fn_800723B8(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    bl      GXBeginDisplayList
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void fn_800723D8(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    bl      GXEndDisplayList
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void fn_800723F8(void)
{
    nofralloc
    li      r0, 0
    stw     r0, -0x7698(r13)
    blr
}

asm s32 fn_80072404(register s32 a, register s32 b)
{
    nofralloc
    lis     r6, lbl_8015ACBC@ha
    lis     r5, lbl_8015AC68@ha
    li      r0, 0x11
    li      r7, 0
    addi    r6, r6, lbl_8015ACBC@l
    addi    r5, r5, lbl_8015AC68@l
    mtctr   r0
_80072420:
    clrlwi. r0, r3, 0x1f
    beq     _80072444
    cmpwi   r4, 0
    beq     _8007243c
    lwz     r0, 0(r6)
    add     r7, r7, r0
    b       _80072444
_8007243c:
    lwz     r0, 0(r5)
    add     r7, r7, r0
_80072444:
    srwi    r3, r3, 1
    addi    r6, r6, 4
    addi    r5, r5, 4
    bdnz    _80072420
    mr      r3, r7
    blr
}

asm void GXLoadMtxArray(register u32 a)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    stw     r31, 0xc(r1)
    stw     r30, 8(r1)
    mr      r30, r3
    lwz     r0, -0x7698(r13)
    cmplw   r30, r0
    beq     _800724b0
    bl      GXClearVtxDesc
    stw     r30, -0x7698(r13)
    li      r31, 0
_8007248c:
    clrlwi. r0, r30, 0x1f
    beq     _800724a0
    mr      r3, r31
    li      r4, 1
    bl      GXSetVtxDesc
_800724a0:
    addi    r31, r31, 1
    srwi    r30, r30, 1
    cmplwi  r31, 0x1a
    blt     _8007248c
_800724b0:
    lwz     r0, 0x14(r1)
    lwz     r31, 0xc(r1)
    lwz     r30, 8(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void fn_800724C8(void)
{
    nofralloc
    blr
}

#pragma pop
