typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void* memset(void*, int, unsigned long);
extern void __cvt_fp2unsigned(void);
extern void __GXFlushTextureState(void);
extern void GXGetVtxDescv(register void* p);
extern void __GXWriteXFCmdHeader(register void* p);
extern void GXClearVtxDesc(register void* p);
extern void GXSetVtxDesc(register void* p, register int a, register int b);
extern void GXBuildPackedRegister(register void* p, register int a, register int b);
extern void tan(void);
extern void fn_80088600(void);
extern void GXSetVtxDescv(register void* p, register int a, register int b);
extern void __GXSetVATGroup(register void* p, register int a, register int b);
extern void GXGetVtxDesc(register void* p, register int a);
extern void __GXSetDirtyState(void);
extern void GXBegin(register s32 prim, register s32 vtxFmt, register u16 nverts);
extern unsigned char lbl_8012B3B8[40];
extern unsigned char lbl_8012B3E0[32];
extern unsigned char lbl_80178118[648];

#pragma push
#pragma force_active on

extern unsigned char gx[4];
asm void __GXSetChanMatColor(register void* p)
{
    nofralloc
    lbz	r0, 3(r4)
    slwi	r5, r3, 1
    lbz	r6, 0(r4)
    addi	r7, r5, 0xe0
    slwi	r0, r0, 0xc
    rlwimi	r0, r6, 0, 0x18, 0x1f
    lbz	r6, 1(r4)
    lbz	r9, 2(r4)
    rlwinm	r0, r0, 0, 0xc, 7
    oris	r8, r0, 0x80
    lwz	r3, gx
    slwi	r7, r7, 0x18
    li	r0, 0x61
    lis	r4, -0x33ff
    slwi	r6, r6, 0xc
    stb	r0, -0x8000(r4)
    rlwimi	r7, r8, 0, 8, 0x1f
    stw	r7, -0x8000(r4)
    rlwimi	r6, r9, 0, 0x18, 0x1f
    addi	r5, r5, 0xe1
    stb	r0, -0x8000(r4)
    rlwinm	r0, r6, 0, 0xc, 7
    oris	r6, r0, 0x80
    slwi	r0, r5, 0x18
    rlwimi	r0, r6, 0, 8, 0x1f
    stw	r0, -0x8000(r4)
    li	r0, 0
    sth	r0, 2(r3)
    blr	
}

asm void __GXSetLightAttnEnable_A(register void* p, register int a)
{
    nofralloc
    srawi	r5, r3, 1
    lwz	r6, gx
    clrlwi.	r0, r3, 0x1f
    slwi	r3, r5, 2
    addi	r7, r3, 0x1b0
    add	r7, r6, r7
    beq     _80037388
    lwz	r3, 0(r7)
    slwi	r0, r4, 0xe
    rlwinm	r3, r3, 0, 0x12, 0xc
    or	r0, r3, r0
    stw	r0, 0(r7)
    b       _8003739c
_80037388:
    lwz	r3, 0(r7)
    slwi	r0, r4, 4
    rlwinm	r3, r3, 0, 0x1c, 0x16
    or	r0, r3, r0
    stw	r0, 0(r7)
_8003739c:
    li	r0, 0x61
    lwz	r3, gx
    lis	r5, -0x33ff
    stb	r0, -0x8000(r5)
    li	r0, 0
    lwz	r4, 0(r7)
    stw	r4, -0x8000(r5)
    sth	r0, 2(r3)
    blr	
}

asm void __GXSetLightAttnEnable_B(register void* p, register int a)
{
    nofralloc
    srawi	r5, r3, 1
    lwz	r6, gx
    clrlwi.	r0, r3, 0x1f
    slwi	r3, r5, 2
    addi	r7, r3, 0x1b0
    add	r7, r6, r7
    beq     _800373f4
    lwz	r3, 0(r7)
    slwi	r0, r4, 0x13
    rlwinm	r3, r3, 0, 0xd, 7
    or	r0, r3, r0
    stw	r0, 0(r7)
    b       _80037408
_800373f4:
    lwz	r3, 0(r7)
    slwi	r0, r4, 9
    rlwinm	r3, r3, 0, 0x17, 0x11
    or	r0, r3, r0
    stw	r0, 0(r7)
_80037408:
    li	r0, 0x61
    lwz	r3, gx
    lis	r5, -0x33ff
    stb	r0, -0x8000(r5)
    li	r0, 0
    lwz	r4, 0(r7)
    stw	r4, -0x8000(r5)
    sth	r0, 2(r3)
    blr	
}

asm void __GXSetLightColorAttnSel(register void* p)
{
    nofralloc
    slwi	r3, r3, 2
    lwz	r7, gx
    addi	r8, r3, 0x170
    add	r8, r7, r8
    lwz	r0, 0(r8)
    slwi	r5, r5, 2
    li	r3, 0x61
    rlwinm	r0, r0, 0, 0, 0x1d
    or	r0, r0, r4
    stw	r0, 0(r8)
    lis	r4, -0x33ff
    li	r0, 0
    lwz	r6, 0(r8)
    rlwinm	r6, r6, 0, 0x1e, 0x1b
    or	r5, r6, r5
    stw	r5, 0(r8)
    stb	r3, -0x8000(r4)
    lwz	r3, 0(r8)
    stw	r3, -0x8000(r4)
    sth	r0, 2(r7)
    blr	
}

asm void GXSetLightColorAttnRegs(register void* p, register int a, register int b)
{
    nofralloc
    slwi	r10, r3, 1
    lwz	r9, gx
    slwi	r3, r3, 3
    addi	r11, r3, 0x1b0
    add	r11, r9, r11
    lwz	r8, 0(r11)
    addi	r0, r10, 1
    slwi	r3, r0, 2
    rlwinm	r0, r8, 0, 0, 0x1d
    or	r0, r0, r4
    stw	r0, 0(r11)
    addi	r10, r3, 0x1b0
    slwi	r0, r5, 2
    lwz	r3, 0(r11)
    li	r8, 0x61
    lis	r5, -0x33ff
    rlwinm	r3, r3, 0, 0x1e, 0x1b
    or	r0, r3, r0
    stw	r0, 0(r11)
    add	r10, r9, r10
    slwi	r3, r7, 2
    stb	r8, -0x8000(r5)
    li	r0, 0
    lwz	r4, 0(r11)
    stw	r4, -0x8000(r5)
    lwz	r4, 0(r10)
    rlwinm	r4, r4, 0, 0, 0x1d
    or	r4, r4, r6
    stw	r4, 0(r10)
    lwz	r4, 0(r10)
    rlwinm	r4, r4, 0, 0x1e, 0x1b
    or	r3, r4, r3
    stw	r3, 0(r10)
    stb	r8, -0x8000(r5)
    lwz	r3, 0(r10)
    stw	r3, -0x8000(r5)
    sth	r0, 2(r9)
    blr	
}

asm void GXWriteLightReg(register void* p)
{
    nofralloc
    clrlwi	r0, r4, 0x18
    lwz	r4, gx
    oris	r0, r0, 0xf300
    rlwinm	r0, r0, 0, 0x18, 0xf
    rlwimi	r0, r7, 8, 0x10, 0x17
    rlwinm	r7, r0, 0, 0x10, 0xc
    slwi	r0, r3, 0x10
    or	r0, r7, r0
    rlwinm	r3, r0, 0, 0xd, 9
    slwi	r0, r6, 0x13
    or	r6, r3, r0
    li	r0, 0x61
    lis	r3, -0x33ff
    stb	r0, -0x8000(r3)
    rlwinm	r6, r6, 0, 0xa, 7
    slwi	r0, r5, 0x16
    or	r0, r6, r0
    stw	r0, -0x8000(r3)
    li	r0, 0
    sth	r0, 2(r4)
    blr	
}

asm void fn_8003756C(register void* p, register int a)
{
    nofralloc
    cmpwi	r4, 0x13
    clrlwi	r0, r5, 8
    oris	r7, r0, 0xf400
    beq     _800375a0
    bge     _8003758c
    cmpwi	r4, 0x11
    beq     _80037598
    b       _800375b0
_8003758c:
    cmpwi	r4, 0x16
    beq     _800375a8
    b       _800375b0
_80037598:
    li	r6, 0
    b       _800375b4
_800375a0:
    li	r6, 1
    b       _800375b4
_800375a8:
    li	r6, 2
    b       _800375b4
_800375b0:
    li	r6, 2
_800375b4:
    li	r0, 0x61
    lwz	r4, gx
    lis	r5, -0x33ff
    stb	r0, -0x8000(r5)
    rlwinm	r6, r6, 0, 0x1e, 0x1b
    slwi	r3, r3, 2
    stw	r7, -0x8000(r5)
    or	r3, r6, r3
    clrlwi	r3, r3, 8
    stb	r0, -0x8000(r5)
    oris	r3, r3, 0xf500
    li	r0, 0
    stw	r3, -0x8000(r5)
    sth	r0, 2(r4)
    blr	
}

asm void GXSetChanCtrl(register void* p1, register int a, register int b)
{
    nofralloc
    srawi	r7, r3, 1
    lwz	r9, gx
    rlwinm	r10, r5, 0, 0x18, 0x16
    addze	r7, r7
    slwi	r0, r3, 2
    add	r8, r9, r0
    slwi	r7, r7, 2
    stw	r5, 0x49c(r8)
    addi	r7, r7, 0x100
    cmplwi	r10, 8
    addi	r0, r10, 0
    add	r7, r9, r7
    blt     _8003762c
    li	r9, 0
    b       _80037630
_8003762c:
    mr	r9, r0
_80037630:
    cmpwi	r4, 8
    blt     _8003765c
    lwz	r4, gx
    li	r0, 1
    slw	r0, r0, r3
    lwz	r8, 0x4e0(r4)
    addi	r10, r4, 0x4e0
    li	r4, 0
    andc	r0, r8, r0
    stw	r0, 0(r10)
    b       _80037678
_8003765c:
    lwz	r8, gx
    li	r0, 1
    slw	r0, r0, r3
    addi	r10, r8, 0x4e0
    lwz	r8, 0x4e0(r8)
    or	r0, r8, r0
    stw	r0, 0(r10)
_80037678:
    clrlwi.	r0, r3, 0x1f
    beq     _80037710
    lwz	r8, 0(r7)
    slwi	r3, r9, 0xc
    slwi	r0, r4, 0xf
    rlwinm	r4, r8, 0, 0x14, 0x10
    or	r3, r4, r3
    stw	r3, 0(r7)
    cmpwi	r6, 0xff
    lwz	r3, 0(r7)
    rlwinm	r3, r3, 0, 0x11, 0xd
    or	r0, r3, r0
    stw	r0, 0(r7)
    bne     _800376b8
    li	r0, 7
    b       _800376cc
_800376b8:
    lis     r3, lbl_8012B3B8@ha
    slwi	r4, r6, 2
    addi	r0, r3, lbl_8012B3B8@l
    add	r3, r0, r4
    lwz	r0, 0(r3)
_800376cc:
    lwz	r3, 0(r7)
    slwi	r0, r0, 0x13
    cmpwi	r5, 0xff
    rlwinm	r3, r3, 0, 0xd, 9
    or	r0, r3, r0
    stw	r0, 0(r7)
    li	r4, 0
    beq     _800376f8
    rlwinm.	r0, r5, 0, 0x17, 0x17
    bne     _800376f8
    li	r4, 1
_800376f8:
    lwz	r3, 0(r7)
    slwi	r0, r4, 0x12
    rlwinm	r3, r3, 0, 0xe, 0xc
    or	r0, r3, r0
    stw	r0, 0(r7)
    b       _80037798
_80037710:
    lwz	r3, 0(r7)
    slwi	r0, r4, 3
    cmpwi	r6, 0xff
    rlwinm	r3, r3, 0, 0, 0x1c
    or	r3, r3, r9
    stw	r3, 0(r7)
    lwz	r3, 0(r7)
    rlwinm	r3, r3, 0, 0x1d, 0x19
    or	r0, r3, r0
    stw	r0, 0(r7)
    bne     _80037744
    li	r0, 7
    b       _80037758
_80037744:
    lis     r3, lbl_8012B3B8@ha
    slwi	r4, r6, 2
    addi	r0, r3, lbl_8012B3B8@l
    add	r3, r0, r4
    lwz	r0, 0(r3)
_80037758:
    lwz	r3, 0(r7)
    slwi	r0, r0, 7
    cmpwi	r5, 0xff
    rlwinm	r3, r3, 0, 0x19, 0x15
    or	r0, r3, r0
    stw	r0, 0(r7)
    li	r4, 0
    beq     _80037784
    rlwinm.	r0, r5, 0, 0x17, 0x17
    bne     _80037784
    li	r4, 1
_80037784:
    lwz	r3, 0(r7)
    slwi	r0, r4, 6
    rlwinm	r3, r3, 0, 0x1a, 0x18
    or	r0, r3, r0
    stw	r0, 0(r7)
_80037798:
    li	r0, 0x61
    lwz	r3, gx
    lis	r5, -0x33ff
    stb	r0, -0x8000(r5)
    li	r0, 0
    lwz	r4, 0(r7)
    stw	r4, -0x8000(r5)
    sth	r0, 2(r3)
    lwz	r0, 0x4f4(r3)
    ori	r0, r0, 1
    stw	r0, 0x4f4(r3)
    blr	
}

asm void __GXWriteMatColorRegs(void)
{
    nofralloc
    lwz	r4, gx
    clrlwi	r3, r3, 0x18
    addi	r0, r3, -1
    lwz	r3, 0x204(r4)
    slwi	r0, r0, 0xa
    rlwinm	r3, r3, 0, 0x16, 0x11
    or	r0, r3, r0
    stw	r0, 0x204(r4)
    lwz	r0, 0x4f4(r4)
    ori	r0, r0, 4
    stw	r0, 0x4f4(r4)
    blr	
}

asm void GXWriteTextureState(register void* p, register int a, register int b)
{
    nofralloc
    mflr	r0
    li	r10, 0
    stw	r0, 4(r1)
    li	r11, 0
    stwu	r1, -0x48(r1)
    stw	r31, 0x44(r1)
    rlwinm.	r31, r3, 0x1d, 0x1f, 0x1f
    stw	r30, 0x40(r1)
    clrlwi	r30, r3, 0x1d
    stw	r29, 0x3c(r1)
    addi	r29, r4, 0
    stw	r28, 0x38(r1)
    beq     _80037874
    fcmpu	cr0, f4, f3
    beq     _8003783c
    fcmpu	cr0, f2, f1
    bne     _8003784c
_8003783c:
    lfs	f0, -0x7d48(r2)
    stfs	f0, 0x2c(r1)
    stfs	f0, 0x28(r1)
    b       _80037948
_8003784c:
    fsubs	f5, f2, f1
    lfs	f6, -0x7d44(r2)
    fsubs	f2, f4, f3
    fsubs	f0, f1, f3
    fdivs	f3, f6, f5
    fmuls	f1, f3, f2
    fmuls	f0, f3, f0
    stfs	f1, 0x2c(r1)
    stfs	f0, 0x28(r1)
    b       _80037948
_80037874:
    fcmpu	cr0, f4, f3
    beq     _80037884
    fcmpu	cr0, f2, f1
    bne     _80037894
_80037884:
    lfs	f3, -0x7d48(r2)
    lfs	f4, -0x7d40(r2)
    fmr	f5, f3
    b       _800378b0
_80037894:
    fsubs	f0, f4, f3
    fsubs	f5, f2, f1
    fmuls	f2, f4, f3
    fdivs	f4, f4, f0
    fmuls	f0, f0, f5
    fdivs	f5, f1, f5
    fdivs	f3, f2, f0
_800378b0:
    lfs	f1, -0x7d40(r2)
    li	r3, 0
    lfd	f0, -0x7d38(r2)
    b       _800378c8
_800378c0:
    fmuls	f4, f4, f1
    addi	r3, r3, 1
_800378c8:
    fcmpo	cr0, f4, f0
    bgt     _800378c0
    lfd	f0, -0x7d28(r2)
    lfs	f2, -0x7d30(r2)
    lfs	f1, -0x7d48(r2)
    b       _800378e8
_800378e0:
    fmuls	f4, f4, f2
    addi	r3, r3, -1
_800378e8:
    fcmpo	cr0, f4, f1
    ble     _800378f8
    fcmpo	cr0, f4, f0
    blt     _800378e0
_800378f8:
    addi	r28, r3, 1
    lfs	f0, -0x7d20(r2)
    li	r0, 1
    lfd	f2, -0x7d18(r2)
    slw	r0, r0, r28
    fmuls	f1, f0, f4
    xoris	r3, r0, 0x8000
    stfs	f5, 0x28(r1)
    lis	r0, 0x4330
    stw	r3, 0x34(r1)
    stw	r0, 0x30(r1)
    lfd	f0, 0x30(r1)
    fsubs	f0, f0, f2
    fdivs	f0, f3, f0
    stfs	f0, 0x2c(r1)
    bl      __cvt_fp2unsigned
    clrlwi	r3, r3, 8
    clrlwi	r0, r28, 8
    oris	r10, r3, 0xef00
    oris	r11, r0, 0xf000
_80037948:
    lwz	r7, 0x2c(r1)
    li	r0, 0x61
    lbz	r6, 1(r29)
    lis	r4, -0x33ff
    rlwinm	r8, r7, 0x14, 0xd, 0x14
    rlwimi	r8, r7, 0x14, 0x15, 0x1f
    lbz	r9, 2(r29)
    lbz	r5, 0(r29)
    rlwinm	r7, r7, 0x14, 0xc, 0xc
    rlwimi	r7, r8, 0, 0xd, 0x1f
    lwz	r12, 0x28(r1)
    clrlwi	r7, r7, 8
    stb	r0, -0x8000(r4)
    oris	r7, r7, 0xee00
    slwi	r6, r6, 8
    lwz	r3, gx
    stw	r7, -0x8000(r4)
    rlwinm	r7, r12, 0x14, 0xd, 0x14
    stb	r0, -0x8000(r4)
    rlwimi	r7, r12, 0x14, 0x15, 0x1f
    rlwinm	r8, r12, 0x14, 0xc, 0xc
    stw	r10, -0x8000(r4)
    rlwimi	r8, r7, 0, 0xd, 0x1f
    slwi	r7, r31, 0x14
    stb	r0, -0x8000(r4)
    rlwimi	r7, r8, 0, 0xc, 0x1f
    rlwinm	r8, r7, 0, 0xb, 7
    stw	r11, -0x8000(r4)
    slwi	r7, r30, 0x15
    or	r7, r8, r7
    clrlwi	r7, r7, 8
    stb	r0, -0x8000(r4)
    oris	r7, r7, 0xf100
    stw	r7, -0x8000(r4)
    rlwimi	r6, r9, 0, 0x18, 0x1f
    stb	r0, -0x8000(r4)
    slwi	r0, r5, 0x10
    rlwimi	r0, r6, 0, 0x10, 0x1f
    clrlwi	r0, r0, 8
    oris	r0, r0, 0xf200
    stw	r0, -0x8000(r4)
    li	r0, 0
    sth	r0, 2(r3)
    lwz	r0, 0x4c(r1)
    lwz	r31, 0x44(r1)
    lwz	r30, 0x40(r1)
    lwz	r29, 0x3c(r1)
    lwz	r28, 0x38(r1)
    addi	r1, r1, 0x48
    mtlr	r0
    blr	
}

asm void __GXWriteChanColorRegs(register void* p, register int a, register int b)
{
    nofralloc
    clrlwi.	r0, r3, 0x18
    beq     _80037ad8
    lhz	r8, 2(r5)
    li	r0, 0x61
    lhz	r10, 0(r5)
    lis	r6, -0x33ff
    slwi	r8, r8, 0xc
    rlwimi	r8, r10, 0, 0x14, 0x1f
    stb	r0, -0x8000(r6)
    li	r7, 0xe9
    clrlwi	r9, r8, 8
    rlwimi	r9, r7, 0x18, 0, 7
    stw	r9, -0x8000(r6)
    li	r7, 0xea
    slwi	r9, r7, 0x18
    lhzu	r10, 4(r5)
    li	r7, 0xeb
    lhz	r8, 2(r5)
    slwi	r8, r8, 0xc
    stb	r0, -0x8000(r6)
    rlwimi	r8, r10, 0, 0x14, 0x1f
    rlwimi	r9, r8, 0, 8, 0x1f
    stw	r9, -0x8000(r6)
    slwi	r9, r7, 0x18
    li	r7, 0xec
    lhz	r8, 6(r5)
    lhz	r10, 4(r5)
    slwi	r8, r8, 0xc
    rlwimi	r8, r10, 0, 0x14, 0x1f
    stb	r0, -0x8000(r6)
    rlwimi	r9, r8, 0, 8, 0x1f
    stw	r9, -0x8000(r6)
    slwi	r9, r7, 0x18
    li	r7, 0xed
    lhz	r8, 0xa(r5)
    lhz	r10, 8(r5)
    slwi	r8, r8, 0xc
    rlwimi	r8, r10, 0, 0x14, 0x1f
    stb	r0, -0x8000(r6)
    rlwimi	r9, r8, 0, 8, 0x1f
    stw	r9, -0x8000(r6)
    lhz	r8, 0xe(r5)
    lhz	r10, 0xc(r5)
    slwi	r8, r8, 0xc
    rlwimi	r8, r10, 0, 0x14, 0x1f
    stb	r0, -0x8000(r6)
    clrlwi	r9, r8, 8
    rlwimi	r9, r7, 0x18, 0, 7
    stw	r9, -0x8000(r6)
_80037ad8:
    clrlwi	r5, r4, 0x10
    lwz	r4, gx
    addi	r0, r5, 0x156
    rlwinm	r5, r0, 0, 0x16, 0x14
    rlwinm	r0, r3, 0xa, 0xe, 0x15
    or	r0, r5, r0
    clrlwi	r5, r0, 8
    li	r0, 0x61
    lis	r3, -0x33ff
    stb	r0, -0x8000(r3)
    oris	r5, r5, 0xe800
    li	r0, 0
    stw	r5, -0x8000(r3)
    sth	r0, 2(r4)
    blr	
}

asm void GXWriteLightColor(register void* p)
{
    nofralloc
    lwz	r8, gx
    subfic	r0, r3, 3
    cntlzw	r7, r0
    subfic	r0, r3, 2
    lwz	r9, 0x1d0(r8)
    rlwimi	r9, r7, 6, 0x14, 0x14
    addi	r7, r9, 0
    rlwimi	r7, r3, 0, 0x1f, 0x1f
    cntlzw	r0, r0
    rlwimi	r7, r0, 0x1c, 0x1e, 0x1e
    rlwimi	r7, r6, 0xc, 0x10, 0x13
    rlwimi	r7, r4, 8, 0x15, 0x17
    li	r0, 0x61
    lis	r3, -0x33ff
    stb	r0, -0x8000(r3)
    rlwimi	r7, r5, 5, 0x18, 0x1a
    li	r0, 0
    stw	r7, -0x8000(r3)
    stw	r7, 0x1d0(r8)
    sth	r0, 2(r8)
    blr	
}

asm void __GXSetChanAmbSrcBit(register void* p)
{
    nofralloc
    lwz	r5, gx
    li	r0, 0x61
    lis	r4, -0x33ff
    lwz	r6, 0x1d0(r5)
    rlwimi	r6, r3, 3, 0x1c, 0x1c
    stb	r0, -0x8000(r4)
    li	r0, 0
    stw	r6, -0x8000(r4)
    stw	r6, 0x1d0(r5)
    sth	r0, 2(r5)
    blr	
}

asm void __GXSetChanMatSrcBit(register void* p)
{
    nofralloc
    lwz	r5, gx
    li	r0, 0x61
    lis	r4, -0x33ff
    lwz	r6, 0x1d0(r5)
    rlwimi	r6, r3, 4, 0x1b, 0x1b
    stb	r0, -0x8000(r4)
    li	r0, 0
    stw	r6, -0x8000(r4)
    stw	r6, 0x1d0(r5)
    sth	r0, 2(r5)
    blr	
}

asm void __GXWriteChanCtrlBitfields(register void* p)
{
    nofralloc
    lwz	r6, gx
    li	r0, 0x61
    lwz	r7, 0x1d8(r6)
    rlwimi	r7, r3, 0, 0x1f, 0x1f
    lis	r3, -0x33ff
    stb	r0, -0x8000(r3)
    rlwimi	r7, r4, 1, 0x1c, 0x1e
    rlwimi	r7, r5, 4, 0x1b, 0x1b
    stw	r7, -0x8000(r3)
    li	r0, 0
    stw	r7, 0x1d8(r6)
    sth	r0, 2(r6)
    blr	
}

asm void __GXXFSetPerfEnableMulti(register void* p)
{
    nofralloc
    lwz	r6, gx
    rlwinm	r0, r3, 6, 0x12, 0x19
    li	r3, 0x61
    lwz	r5, 0x1dc(r6)
    lis	r4, -0x33ff
    rlwinm	r5, r5, 0, 0x1a, 0x18
    or	r0, r5, r0
    stw	r0, 0x1dc(r6)
    li	r0, 0
    stb	r3, -0x8000(r4)
    lwz	r3, 0x1dc(r6)
    stw	r3, -0x8000(r4)
    sth	r0, 2(r6)
    blr	
}

asm void __GXSetGenModeInline(register void* p, register int a, register int b)
{
    nofralloc
    lwz	r7, gx
    lis     r5, lbl_8012B3E0@ha
    slwi	r6, r3, 2
    addi	r0, r5, lbl_8012B3E0@l
    lwz	r8, 0x1dc(r7)
    add	r10, r0, r6
    lwz	r5, 0(r10)
    rlwinm	r6, r8, 0, 0, 0x1c
    slwi	r0, r4, 3
    or	r4, r6, r5
    stw	r4, 0x1dc(r7)
    lwz	r4, 0x1dc(r7)
    rlwinm	r4, r4, 0, 0x1d, 0x19
    or	r0, r4, r0
    stw	r0, 0x1dc(r7)
    lwz	r5, 0x1dc(r7)
    cmplw	r8, r5
    beq     _80037cbc
    li	r0, 0x61
    lis	r4, -0x33ff
    stb	r0, -0x8000(r4)
    cmpwi	r3, 2
    stw	r5, -0x8000(r4)
    bne     _80037c94
    li	r0, 1
    b       _80037c98
_80037c94:
    li	r0, 0
_80037c98:
    lwz	r5, gx
    rlwinm	r0, r0, 9, 0xf, 0x16
    lwz	r4, 0x204(r5)
    rlwinm	r4, r4, 0, 0x17, 0x15
    or	r0, r4, r0
    stw	r0, 0x204(r5)
    lwz	r0, 0x4f4(r5)
    ori	r0, r0, 4
    stw	r0, 0x4f4(r5)
_80037cbc:
    lwz	r0, 0(r10)
    cmplwi	r0, 4
    bne     _80037d04
    lwz	r5, gx
    addi	r3, r3, -4
    li	r0, 0x61
    lwz	r4, 0x1d4(r5)
    rlwinm	r4, r4, 0, 0x17, 0x14
    rlwimi	r4, r3, 9, 0x15, 0x16
    stw	r4, 0x1d4(r5)
    lis	r3, -0x33ff
    lwz	r4, 0x1d4(r5)
    clrlwi	r4, r4, 8
    oris	r4, r4, 0x4200
    stw	r4, 0x1d4(r5)
    stb	r0, -0x8000(r3)
    lwz	r0, 0x1d4(r5)
    stw	r0, -0x8000(r3)
_80037d04:
    lwz	r3, gx
    li	r0, 0
    sth	r0, 2(r3)
    blr	
}

asm void __GXSetZModeBits(register void* p)
{
    nofralloc
    lwz	r5, gx
    li	r0, 0x61
    lis	r4, -0x33ff
    lwz	r6, 0x1d0(r5)
    rlwimi	r6, r3, 2, 0x1d, 0x1d
    stb	r0, -0x8000(r4)
    li	r0, 0
    stw	r6, -0x8000(r4)
    stw	r6, 0x1d0(r5)
    sth	r0, 2(r5)
    blr	
}

asm void GXWriteLightAttn(register void* p)
{
    nofralloc
    lwz	r6, gx
    clrlwi	r5, r4, 0x18
    li	r0, 0x61
    lwz	r7, 0x1d4(r6)
    lis	r4, -0x33ff
    rlwimi	r7, r5, 0, 0x18, 0x1f
    stb	r0, -0x8000(r4)
    clrlwi	r0, r3, 0x18
    addi	r3, r7, 0
    rlwimi	r3, r0, 8, 0x17, 0x17
    stw	r3, -0x8000(r4)
    li	r0, 0
    stw	r3, 0x1d4(r6)
    sth	r0, 2(r6)
    blr	
}

asm void GXSetFieldMask(register void* p)
{
    nofralloc
    clrlwi	r0, r4, 0x18
    lwz	r4, gx
    rlwinm	r5, r0, 0, 0x1f, 0x1d
    rlwinm	r0, r3, 1, 0x17, 0x1e
    or	r0, r5, r0
    clrlwi	r5, r0, 8
    li	r0, 0x61
    lis	r3, -0x33ff
    stb	r0, -0x8000(r3)
    oris	r5, r5, 0x4400
    li	r0, 0
    stw	r5, -0x8000(r3)
    sth	r0, 2(r4)
    blr	
}

asm void GXSetFieldMode(register void* p, register int a)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    rlwinm	r0, r4, 0x16, 2, 9
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    lis	r31, -0x33ff
    stw	r30, 0x18(r1)
    li	r30, 0x61
    stw	r29, 0x14(r1)
    mr	r29, r3
    lwz	r5, gx
    lwz	r4, 0x7c(r5)
    rlwinm	r4, r4, 0, 0xa, 8
    or	r0, r4, r0
    stw	r0, 0x7c(r5)
    stb	r30, -0x8000(r31)
    lwz	r0, 0x7c(r5)
    stw	r0, -0x8000(r31)
    bl      __GXFlushTextureState
    clrlwi	r0, r29, 0x18
    stb	r30, -0x8000(r31)
    oris	r0, r0, 0x6800
    stw	r0, -0x8000(r31)
    bl      __GXFlushTextureState
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void GXSetupLitVertexData(register void* p)
{
    nofralloc
    mflr	r0
    lis	r4, -0x7fe8
    stw	r0, 4(r1)
    stwu	r1, -0x3c8(r1)
    stfd	f31, 0x3c0(r1)
    stfd	f30, 0x3b8(r1)
    stfd	f29, 0x3b0(r1)
    stfd	f28, 0x3a8(r1)
    stfd	f27, 0x3a0(r1)
    stfd	f26, 0x398(r1)
    stmw	r24, 0x378(r1)
    addi	r31, r4, -0x7ee8
    addi	r24, r3, 0
    addi	r3, r31, 0
    lfs	f0, -0x7d0c(r2)
    fneg	f31, f0
    bl      GXGetVtxDescv
    li	r3, 3
    addi	r4, r31, 0xd8
    bl      __GXWriteXFCmdHeader
    bl      GXClearVtxDesc
    li	r3, 9
    li	r4, 1
    bl      GXSetVtxDesc
    li	r3, 0xa
    li	r4, 1
    bl      GXSetVtxDesc
    li	r3, 3
    li	r4, 9
    li	r5, 1
    li	r6, 4
    li	r7, 0
    bl      GXBuildPackedRegister
    li	r3, 3
    li	r4, 0xa
    li	r5, 0
    li	r6, 4
    li	r7, 0
    bl      GXBuildPackedRegister
    addi	r29, r1, 0x1d4
    lfs	f27, -0x7d08(r2)
    addi	r28, r1, 0x44
    lfs	f28, -0x7d04(r2)
    lfd	f29, -0x7cf8(r2)
    mr	r26, r29
    lfd	f30, -0x7cf0(r2)
    addi	r25, r28, 0
    clrlwi	r30, r24, 0x18
    li	r24, 0
    lis	r27, 0x4330
    b       _80037f50
_80037efc:
    xoris	r0, r24, 0x8000
    stw	r30, 0x36c(r1)
    stw	r0, 0x374(r1)
    stw	r27, 0x370(r1)
    lfd	f0, 0x370(r1)
    stw	r27, 0x368(r1)
    fsubs	f1, f0, f29
    lfd	f0, 0x368(r1)
    fmuls	f1, f28, f1
    fsubs	f0, f0, f30
    fmuls	f1, f27, f1
    fdivs	f26, f1, f0
    fmr	f1, f26
    bl      tan
    stfs	f1, 0(r26)
    fmr	f1, f26
    bl      fn_80088600
    stfs	f1, 0(r25)
    addi	r26, r26, 4
    addi	r25, r25, 4
    addi	r24, r24, 1
_80037f50:
    cmpw	r24, r30
    ble     _80037efc
    addi	r27, r30, 1
    rlwinm	r5, r27, 1, 0x10, 0x1e
    li	r3, 0x98
    li	r4, 3
    bl      GXBegin
    cmpwi	r30, 0
    lfs	f1, -0x7d10(r2)
    lfs	f0, -0x7d0c(r2)
    addi	r4, r29, 0
    addi	r5, r28, 0
    lis	r3, -0x33ff
    blt     _800380d0
    rlwinm.	r0, r27, 0x1e, 2, 0x1f
    mtctr	r0
    beq     _80038088
_80037f94:
    lfs	f3, 0(r4)
    stfs	f3, -0x8000(r3)
    lfs	f2, 0(r5)
    stfs	f2, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f0, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f3, 4(r4)
    stfs	f3, -0x8000(r3)
    lfsu	f2, 4(r5)
    stfs	f2, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f0, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f3, 8(r4)
    stfs	f3, -0x8000(r3)
    lfsu	f2, 4(r5)
    stfs	f2, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f0, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f3, 0xc(r4)
    addi	r4, r4, 0x10
    stfs	f3, -0x8000(r3)
    lfsu	f2, 4(r5)
    stfs	f2, -0x8000(r3)
    addi	r5, r5, 4
    stfs	f31, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f0, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    bdnz    _80037f94
    andi.	r27, r27, 3
    beq     _800380d0
_80038088:
    mtctr	r27
_8003808c:
    lfs	f3, 0(r4)
    addi	r4, r4, 4
    stfs	f3, -0x8000(r3)
    lfs	f2, 0(r5)
    addi	r5, r5, 4
    stfs	f2, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f0, -0x8000(r3)
    stfs	f3, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    bdnz    _8003808c
_800380d0:
    addi	r25, r30, 2
    clrlwi	r5, r25, 0x10
    li	r3, 0xa0
    li	r4, 3
    bl      GXBegin
    lfs	f2, -0x7d10(r2)
    lis	r3, -0x33ff
    lfs	f1, -0x7d0c(r2)
    cmpwi	r30, 0
    stfs	f2, -0x8000(r3)
    li	r6, 0
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    blt     _800382c4
    addi	r0, r30, 1
    cmpwi	r0, 8
    addi	r4, r30, -8
    ble     _800384a0
    addi	r0, r4, 8
    srwi	r0, r0, 3
    cmpwi	r4, 0
    mtctr	r0
    addi	r4, r29, 0
    addi	r5, r28, 0
    blt     _800384a0
_80038140:
    lfs	f0, 0(r4)
    addi	r6, r6, 8
    stfs	f0, -0x8000(r3)
    lfs	f0, 0(r5)
    fneg	f0, f0
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 4(r4)
    stfs	f0, -0x8000(r3)
    lfs	f0, 4(r5)
    fneg	f0, f0
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 8(r4)
    stfs	f0, -0x8000(r3)
    lfs	f0, 8(r5)
    fneg	f0, f0
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 0xc(r4)
    stfs	f0, -0x8000(r3)
    lfs	f0, 0xc(r5)
    fneg	f0, f0
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 0x10(r4)
    stfs	f0, -0x8000(r3)
    lfs	f0, 0x10(r5)
    fneg	f0, f0
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 0x14(r4)
    stfs	f0, -0x8000(r3)
    lfs	f0, 0x14(r5)
    fneg	f0, f0
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 0x18(r4)
    stfs	f0, -0x8000(r3)
    lfs	f0, 0x18(r5)
    fneg	f0, f0
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 0x1c(r4)
    addi	r4, r4, 0x20
    stfs	f0, -0x8000(r3)
    lfs	f0, 0x1c(r5)
    addi	r5, r5, 0x20
    fneg	f0, f0
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    bdnz    _80038140
    b       _800384a0
_80038274:
    addi	r0, r30, 1
    lfs	f1, -0x7d0c(r2)
    subf	r0, r6, r0
    lfs	f0, -0x7d10(r2)
    cmpw	r6, r30
    mtctr	r0
    lis	r3, -0x33ff
    bgt     _800382c4
_80038294:
    lfs	f2, 0(r4)
    addi	r4, r4, 4
    stfs	f2, -0x8000(r3)
    lfs	f2, 0(r5)
    addi	r5, r5, 4
    fneg	f2, f2
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f0, -0x8000(r3)
    stfs	f0, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    bdnz    _80038294
_800382c4:
    clrlwi	r5, r25, 0x10
    li	r3, 0xa0
    li	r4, 3
    bl      GXBegin
    lfs	f2, -0x7d10(r2)
    lis	r3, -0x33ff
    lfs	f1, -0x7d00(r2)
    cmpwi	r30, 0
    stfs	f2, -0x8000(r3)
    li	r6, 0
    stfs	f2, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    blt     _80038488
    addi	r0, r30, 1
    cmpwi	r0, 8
    addi	r4, r30, -8
    ble     _800384b8
    addi	r0, r4, 8
    srwi	r0, r0, 3
    cmpwi	r4, 0
    mtctr	r0
    blt     _800384b8
_80038328:
    lfs	f0, 0(r29)
    addi	r6, r6, 8
    stfs	f0, -0x8000(r3)
    lfs	f0, 0(r28)
    stfs	f0, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 4(r29)
    stfs	f0, -0x8000(r3)
    lfs	f0, 4(r28)
    stfs	f0, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 8(r29)
    stfs	f0, -0x8000(r3)
    lfs	f0, 8(r28)
    stfs	f0, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 0xc(r29)
    stfs	f0, -0x8000(r3)
    lfs	f0, 0xc(r28)
    stfs	f0, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 0x10(r29)
    stfs	f0, -0x8000(r3)
    lfs	f0, 0x10(r28)
    stfs	f0, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 0x14(r29)
    stfs	f0, -0x8000(r3)
    lfs	f0, 0x14(r28)
    stfs	f0, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 0x18(r29)
    stfs	f0, -0x8000(r3)
    lfs	f0, 0x18(r28)
    stfs	f0, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    lfs	f0, 0x1c(r29)
    addi	r29, r29, 0x20
    stfs	f0, -0x8000(r3)
    lfs	f0, 0x1c(r28)
    addi	r28, r28, 0x20
    stfs	f0, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f2, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    bdnz    _80038328
    b       _800384b8
_8003843c:
    addi	r0, r30, 1
    lfs	f1, -0x7d10(r2)
    subf	r0, r6, r0
    lfs	f0, -0x7d00(r2)
    cmpw	r6, r30
    mtctr	r0
    lis	r3, -0x33ff
    bgt     _80038488
_8003845c:
    lfs	f2, 0(r4)
    addi	r4, r4, 4
    stfs	f2, -0x8000(r3)
    lfs	f2, 0(r5)
    addi	r5, r5, 4
    stfs	f2, -0x8000(r3)
    stfs	f31, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f1, -0x8000(r3)
    stfs	f0, -0x8000(r3)
    bdnz    _8003845c
_80038488:
    mr	r3, r31
    bl      GXSetVtxDescv
    li	r3, 3
    addi	r4, r31, 0xd8
    bl      __GXSetVATGroup
    b       _800384d0
_800384a0:
    slwi	r0, r6, 2
    addi	r4, r1, 0x1d4
    addi	r5, r1, 0x44
    add	r4, r4, r0
    add	r5, r5, r0
    b       _80038274
_800384b8:
    slwi	r0, r6, 2
    addi	r4, r1, 0x1d4
    addi	r5, r1, 0x44
    add	r4, r4, r0
    add	r5, r5, r0
    b       _8003843c
_800384d0:
    lmw	r24, 0x378(r1)
    lwz	r0, 0x3cc(r1)
    lfd	f31, 0x3c0(r1)
    lfd	f30, 0x3b8(r1)
    lfd	f29, 0x3b0(r1)
    lfd	f28, 0x3a8(r1)
    lfd	f27, 0x3a0(r1)
    lfd	f26, 0x398(r1)
    addi	r1, r1, 0x3c8
    mtlr	r0
    blr	
}

asm void fn_800384FC(register void* p)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    clrlwi	r0, r4, 0x18
    stwu	r1, -0xd0(r1)
    stfd	f31, 0xc8(r1)
    stfd	f30, 0xc0(r1)
    stfd	f29, 0xb8(r1)
    stfd	f28, 0xb0(r1)
    stfd	f27, 0xa8(r1)
    stfd	f26, 0xa0(r1)
    stfd	f25, 0x98(r1)
    stfd	f24, 0x90(r1)
    stfd	f23, 0x88(r1)
    stfd	f22, 0x80(r1)
    stfd	f21, 0x78(r1)
    stfd	f20, 0x70(r1)
    stfd	f19, 0x68(r1)
    stmw	r21, 0x3c(r1)
    mr	r22, r3
    clrlwi	r3, r3, 0x18
    stw	r3, 0x34(r1)
    lis	r3, 0x4330
    mr	r21, r4
    stw	r0, 0x2c(r1)
    lis     r4, lbl_80178118@ha
    addi	r26, r4, lbl_80178118@l
    stw	r3, 0x30(r1)
    addi	r4, r1, 0x10
    stw	r3, 0x28(r1)
    li	r3, 0xd
    lfd	f2, 0x30(r1)
    lfd	f0, 0x28(r1)
    lfd	f3, -0x7cf0(r2)
    lfs	f4, -0x7d08(r2)
    fsubs	f2, f2, f3
    lfs	f1, -0x7ce8(r2)
    fsubs	f0, f0, f3
    fdivs	f25, f4, f2
    fdivs	f24, f1, f0
    bl      GXGetVtxDesc
    mr	r3, r26
    bl      GXGetVtxDescv
    li	r3, 3
    addi	r4, r26, 0xd8
    bl      __GXWriteXFCmdHeader
    bl      GXClearVtxDesc
    li	r3, 9
    li	r4, 1
    bl      GXSetVtxDesc
    li	r3, 0xa
    li	r4, 1
    bl      GXSetVtxDesc
    li	r3, 3
    li	r4, 9
    li	r5, 1
    li	r6, 4
    li	r7, 0
    bl      GXBuildPackedRegister
    li	r3, 3
    li	r4, 0xa
    li	r5, 0
    li	r6, 4
    li	r7, 0
    bl      GXBuildPackedRegister
    lwz	r0, 0x10(r1)
    cmpwi	r0, 0
    beq     _8003862c
    li	r3, 0xd
    li	r4, 1
    bl      GXSetVtxDesc
    li	r3, 3
    li	r4, 0xd
    li	r5, 1
    li	r6, 4
    li	r7, 0
    bl      GXBuildPackedRegister
_8003862c:
    clrlwi	r23, r21, 0x18
    lfd	f26, -0x7cf8(r2)
    addi	r0, r23, 1
    lfs	f28, -0x7d0c(r2)
    lfd	f30, -0x7cf0(r2)
    slwi	r25, r0, 1
    clrlwi	r24, r22, 0x18
    li	r22, 0
    lis	r29, 0x4330
    lis	r30, -0x33ff
    b       _80038814
_80038658:
    xoris	r27, r22, 0x8000
    stw	r27, 0x2c(r1)
    stw	r29, 0x28(r1)
    lfd	f0, 0x28(r1)
    fsubs	f0, f0, f26
    fmuls	f20, f0, f25
    fmr	f1, f20
    fadds	f27, f20, f25
    bl      fn_80088600
    fmuls	f23, f28, f1
    fmr	f1, f27
    bl      fn_80088600
    fmuls	f22, f28, f1
    fmr	f1, f20
    bl      tan
    fmuls	f21, f28, f1
    fmr	f1, f27
    bl      tan
    fmuls	f20, f28, f1
    clrlwi	r5, r25, 0x10
    li	r3, 0x98
    li	r4, 3
    bl      GXBegin
    fdivs	f29, f20, f28
    addi	r0, r22, 1
    xoris	r31, r0, 0x8000
    li	r21, 0
    fdivs	f31, f21, f28
    b       _80038808
_800386cc:
    xoris	r28, r21, 0x8000
    stw	r28, 0x2c(r1)
    stw	r29, 0x28(r1)
    lfd	f0, 0x28(r1)
    fsubs	f0, f0, f26
    fmuls	f19, f0, f24
    fmr	f1, f19
    bl      tan
    fmr	f27, f1
    fmr	f1, f19
    bl      fn_80088600
    fmuls	f0, f27, f22
    lwz	r0, 0x10(r1)
    fmuls	f3, f1, f22
    cmpwi	r0, 0
    fdivs	f2, f0, f28
    stfs	f0, -0x8000(r30)
    stfs	f3, -0x8000(r30)
    stfs	f20, -0x8000(r30)
    fdivs	f0, f3, f28
    stfs	f2, -0x8000(r30)
    stfs	f0, -0x8000(r30)
    stfs	f29, -0x8000(r30)
    beq     _8003877c
    stw	r28, 0x2c(r1)
    stw	r23, 0x34(r1)
    stw	r29, 0x28(r1)
    stw	r29, 0x30(r1)
    lfd	f2, 0x28(r1)
    stw	r31, 0x24(r1)
    lfd	f0, 0x30(r1)
    fsubs	f2, f2, f26
    stw	r24, 0x1c(r1)
    fsubs	f0, f0, f30
    stw	r29, 0x20(r1)
    stw	r29, 0x18(r1)
    fdivs	f3, f2, f0
    lfd	f2, 0x20(r1)
    lfd	f0, 0x18(r1)
    fsubs	f2, f2, f26
    stfs	f3, -0x8000(r30)
    fsubs	f0, f0, f30
    fdivs	f0, f2, f0
    stfs	f0, -0x8000(r30)
_8003877c:
    fmuls	f0, f27, f23
    lwz	r0, 0x10(r1)
    fmuls	f2, f1, f23
    cmpwi	r0, 0
    fdivs	f1, f0, f28
    stfs	f0, -0x8000(r30)
    stfs	f2, -0x8000(r30)
    stfs	f21, -0x8000(r30)
    fdivs	f0, f2, f28
    stfs	f1, -0x8000(r30)
    stfs	f0, -0x8000(r30)
    stfs	f31, -0x8000(r30)
    beq     _80038804
    xoris	r0, r21, 0x8000
    stw	r23, 0x24(r1)
    stw	r0, 0x1c(r1)
    stw	r29, 0x18(r1)
    stw	r29, 0x20(r1)
    lfd	f1, 0x18(r1)
    stw	r27, 0x2c(r1)
    lfd	f0, 0x20(r1)
    fsubs	f1, f1, f26
    stw	r24, 0x34(r1)
    fsubs	f0, f0, f30
    stw	r29, 0x28(r1)
    stw	r29, 0x30(r1)
    fdivs	f2, f1, f0
    lfd	f1, 0x28(r1)
    lfd	f0, 0x30(r1)
    fsubs	f1, f1, f26
    stfs	f2, -0x8000(r30)
    fsubs	f0, f0, f30
    fdivs	f0, f1, f0
    stfs	f0, -0x8000(r30)
_80038804:
    addi	r21, r21, 1
_80038808:
    cmpw	r21, r23
    ble     _800386cc
    addi	r22, r22, 1
_80038814:
    cmpw	r22, r24
    blt     _80038658
    mr	r3, r26
    bl      GXSetVtxDescv
    li	r3, 3
    addi	r4, r26, 0xd8
    bl      __GXSetVATGroup
    lmw	r21, 0x3c(r1)
    lwz	r0, 0xd4(r1)
    lfd	f31, 0xc8(r1)
    lfd	f30, 0xc0(r1)
    lfd	f29, 0xb8(r1)
    lfd	f28, 0xb0(r1)
    lfd	f27, 0xa8(r1)
    lfd	f26, 0xa0(r1)
    lfd	f25, 0x98(r1)
    lfd	f24, 0x90(r1)
    lfd	f23, 0x88(r1)
    lfd	f22, 0x80(r1)
    lfd	f21, 0x78(r1)
    lfd	f20, 0x70(r1)
    lfd	f19, 0x68(r1)
    addi	r1, r1, 0xd0
    mtlr	r0
    blr	
}

asm void fn_80038878(void)
{
    nofralloc
    blr	
}

#pragma pop
