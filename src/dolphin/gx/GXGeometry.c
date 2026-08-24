typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
} __GXFifoInt;

#define GXWGFifo ((volatile __GXFifoInt *)0xCC008000)

#define GX_WRITE_RAS_REG(reg)       \
    do {                            \
        GXWGFifo->u8 = 0x61;        \
        GXWGFifo->u32 = (u32)(reg); \
    } while (0)

#define SET_REG_FIELD(reg, size, pos, val) \
    ((reg) = (((u32)(reg)) & ~((((1 << (size)) - 1)) << (pos))) | ((u32)(val) << (pos)))

typedef volatile struct GXData {
    u16 inVertexList;
    u16 bpSent;
    u16 vNum;
    u16 vLim;
    u8 pad[0x7C - 0x8];
    u32 lpSize;
    u8 pad2[0xB8 - 0x80];
    u32 suTs0[8];
    u8 pad3[0x204 - 0xD8];
    u32 genMode;
    u8 pad4[0x4F4 - 0x208];
    u32 dirtyState;
} GXData;

extern GXData *const gx;

extern void fn_8003666C(void);
extern void fn_80036F24(void);
extern void __GXSetVCD(void);
extern void __GXSetVAT(void);
extern void __GXCalculateVatSizes(void);
extern void __cvt_fp2unsigned(void);
extern void fn_80088624(void);
extern void* memset(void* dst, int c, unsigned long n);
extern void __GXGetTexTileSize(register void* p1, register void* p2, register int id, register void* p4);
extern void __cvt_fp2unsigned(void);
extern void GXGetVtxDescv(register void* p);
extern void __GXWriteXFCmdHeader(register void* p);
extern void GXClearVtxDesc(register void* p);
extern void GXSetVtxDesc(register void* p, register int a, register int b);
extern void GXBuildPackedRegister(register void* p, register int a, register int b);
extern void fn_80088600(void);
extern void GXSetVtxDescv(register void* p, register int a, register int b);
extern void __GXSetVATGroup(register void* p, register int a, register int b);
extern void GXGetVtxDesc(register void* p, register int a);
extern unsigned char jumptable_8012B120[28];
extern unsigned char jumptable_8012B140[244];
extern unsigned char jumptable_8012B234[244];
extern unsigned char jumptable_8012B328[60];
void fn_800372E0(register void* p);
void __GXSetLightAttnEnable_A(register void* p, register int a);
void __GXSetLightAttnEnable_B(register void* p, register int a);
void __GXSetLightColorAttnSel(register void* p);
void GXSetLightColorAttnRegs(register void* p, register int a, register int b);
void GXWriteLightReg(register void* p);
void fn_8003756C(register void* p, register int a);
void GXSetChanCtrl(register void* p1, register int a, register int b);
void __GXWriteMatColorRegs(void);
void GXWriteTextureState(register void* p, register int a, register int b);
void __GXWriteChanColorRegs(register void* p, register int a, register int b);
void GXWriteLightColor(register void* p);
void __GXSetChanAmbSrcBit(register void* p);
void __GXSetChanMatSrcBit(register void* p);
void __GXWriteChanCtrlBitfields(register void* p);
void __GXXFSetPerfEnableMulti(register void* p);
void fn_80037C2C(register void* p, register int a, register int b);
void __GXSetZModeBits(register void* p);
void GXWriteLightAttn(register void* p);
void fn_80037D7C(register void* p);
void fn_80037DB4(register void* p, register int a);
void GXSetupLitVertexData(register void* p);
void fn_800384FC(register void* p);
void fn_80038878(void);

void __GXSetGenMode(void);
void __GXSendFlushPrim(void);

#pragma push
#pragma force_active on

void __GXSetDirtyState(void)
{
    if (gx->dirtyState & 1)
        fn_8003666C();
    if (gx->dirtyState & 2)
        fn_80036F24();
    if (gx->dirtyState & 4)
        __GXSetGenMode();
    if (gx->dirtyState & 8)
        __GXSetVCD();
    if (gx->dirtyState & 0x10)
        __GXSetVAT();
    if (gx->dirtyState & 0x18)
        __GXCalculateVatSizes();
    gx->dirtyState = 0;
}

asm void GXBegin(register s32 prim, register s32 vtxFmt, register u16 nverts)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r5, 0
    stw	r30, 0x20(r1)
    addi	r30, r4, 0
    stw	r29, 0x1c(r1)
    addi	r29, r3, 0
    lwz	r6, -0x7de8(r2)
    lwz	r0, 0x4f4(r6)
    cmplwi	r0, 0
    beq     _800346dc
    clrlwi.	r0, r0, 0x1f
    beq     _8003466c
    bl      fn_8003666C
_8003466c:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x4f4(r3)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    beq     _80034680
    bl      fn_80036F24
_80034680:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x4f4(r3)
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    beq     _80034694
    bl      __GXSetGenMode
_80034694:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x4f4(r3)
    rlwinm.	r0, r0, 0, 0x1c, 0x1c
    beq     _800346a8
    bl      __GXSetVCD
_800346a8:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x4f4(r3)
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    beq     _800346bc
    bl      __GXSetVAT
_800346bc:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x4f4(r3)
    rlwinm.	r0, r0, 0, 0x1b, 0x1c
    beq     _800346d0
    bl      __GXCalculateVatSizes
_800346d0:
    lwz	r3, -0x7de8(r2)
    li	r0, 0
    stw	r0, 0x4f4(r3)
_800346dc:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0(r3)
    cmplwi	r0, 0
    bne     _800346f0
    bl      __GXSendFlushPrim
_800346f0:
    or	r0, r30, r29
    lis	r3, -0x33ff
    stb	r0, -0x8000(r3)
    sth	r31, -0x8000(r3)
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void __GXSendFlushPrim(void)
{
    nofralloc
    lwz	r3, -0x7de8(r2)
    li	r0, 0x98
    lis	r5, -0x33ff
    lhz	r6, 4(r3)
    li	r4, 0
    lhz	r3, 6(r3)
    mullw	r7, r6, r3
    stb	r0, -0x8000(r5)
    sth	r6, -0x8000(r5)
    addi	r3, r7, 3
    cmplwi	r7, 0
    srwi	r3, r3, 2
    ble     _80034794
    rlwinm.	r0, r3, 0x1d, 3, 0x1f
    mtctr	r0
    beq     _80034788
_8003475c:
    stw	r4, -0x8000(r5)
    stw	r4, -0x8000(r5)
    stw	r4, -0x8000(r5)
    stw	r4, -0x8000(r5)
    stw	r4, -0x8000(r5)
    stw	r4, -0x8000(r5)
    stw	r4, -0x8000(r5)
    stw	r4, -0x8000(r5)
    bdnz    _8003475c
    andi.	r3, r3, 7
    beq     _80034794
_80034788:
    mtctr	r3
_8003478c:
    stw	r4, -0x8000(r5)
    bdnz    _8003478c
_80034794:
    lwz	r3, -0x7de8(r2)
    li	r0, 1
    sth	r0, 2(r3)
    blr	
}

asm void GXSetLineWidth(register s32 width, register s32 offset)
{
    nofralloc
    lwz	r7, -0x7de8(r2)
    slwi	r6, r4, 0x10
    li	r5, 0x61
    lwz	r0, 0x7c(r7)
    lis	r4, -0x33ff
    rlwinm	r0, r0, 0, 0, 0x17
    rlwimi	r0, r3, 0, 0x18, 0x1f
    stw	r0, 0x7c(r7)
    li	r0, 0
    lwz	r3, 0x7c(r7)
    rlwinm	r3, r3, 0, 0x10, 0xc
    or	r3, r3, r6
    stw	r3, 0x7c(r7)
    stb	r5, -0x8000(r4)
    lwz	r3, 0x7c(r7)
    stw	r3, -0x8000(r4)
    sth	r0, 2(r7)
    blr	
}

asm void GXSetPointSize(register s32 size, register s32 offset)
{
    nofralloc
    lwz	r7, -0x7de8(r2)
    slwi	r6, r4, 0x13
    li	r5, 0x61
    lwz	r0, 0x7c(r7)
    lis	r4, -0x33ff
    rlwinm	r0, r0, 0, 0x18, 0xf
    rlwimi	r0, r3, 8, 0x10, 0x17
    stw	r0, 0x7c(r7)
    li	r0, 0
    lwz	r3, 0x7c(r7)
    rlwinm	r3, r3, 0, 0xd, 9
    or	r3, r3, r6
    stw	r3, 0x7c(r7)
    stb	r5, -0x8000(r4)
    lwz	r3, 0x7c(r7)
    stw	r3, -0x8000(r4)
    sth	r0, 2(r7)
    blr	
}

asm void __GXSetTexCoordGen_Cache(register s32 tc, register s32 a, register s32 b)
{
    nofralloc
    lwz	r6, -0x7de8(r2)
    slwi	r8, r3, 2
    add	r7, r6, r8
    lwz	r0, 0xb8(r7)
    add	r9, r6, r8
    rlwinm	r3, r0, 0, 0xe, 0xc
    rlwinm	r0, r4, 0x12, 6, 0xd
    or	r0, r3, r0
    stw	r0, 0xb8(r7)
    rlwinm	r0, r5, 0x13, 5, 0xc
    li	r5, 0x61
    lwz	r3, 0xb8(r9)
    lis	r4, -0x33ff
    rlwinm	r3, r3, 0, 0xd, 0xb
    or	r0, r3, r0
    stw	r0, 0xb8(r9)
    add	r3, r6, r8
    li	r0, 0
    stb	r5, -0x8000(r4)
    lwz	r3, 0xb8(r3)
    stw	r3, -0x8000(r4)
    sth	r0, 2(r6)
    blr	
}

asm void GXSetCullMode(register s32 mode)
{
    nofralloc
    cmpwi	r3, 2
    beq     _800348b0
    bge     _800348b4
    cmpwi	r3, 1
    bge     _800348a8
    b       _800348b4
_800348a8:
    li	r3, 2
    b       _800348b4
_800348b0:
    li	r3, 1
_800348b4:
    lwz	r4, -0x7de8(r2)
    slwi	r0, r3, 0xe
    lwz	r3, 0x204(r4)
    rlwinm	r3, r3, 0, 0x12, 0xf
    or	r0, r3, r0
    stw	r0, 0x204(r4)
    lwz	r0, 0x4f4(r4)
    ori	r0, r0, 4
    stw	r0, 0x4f4(r4)
    blr	
}

asm void __GXSetZMode_Cache(register s32 arg)
{
    nofralloc
    lwz	r6, -0x7de8(r2)
    rlwinm	r0, r3, 0x13, 5, 0xc
    li	r4, 0x61
    lwz	r5, 0x204(r6)
    lis	r3, -0x33ff
    rlwinm	r5, r5, 0, 0xd, 0xb
    or	r0, r5, r0
    stw	r0, 0x204(r6)
    lis	r0, -0x1f8
    stb	r4, -0x8000(r3)
    stw	r0, -0x8000(r3)
    stb	r4, -0x8000(r3)
    lwz	r0, 0x204(r6)
    stw	r0, -0x8000(r3)
    blr	
}

asm void __GXSetGenMode(void)
{
    nofralloc
    li	r0, 0x61
    lwz	r4, -0x7de8(r2)
    lis	r5, -0x33ff
    stb	r0, -0x8000(r5)
    li	r0, 0
    lwz	r3, 0x204(r4)
    stw	r3, -0x8000(r5)
    sth	r0, 2(r4)
    blr	
}


asm void fn_8003493C(register void* src, register void* dst, register int a, register int b)
{
    nofralloc
    cmplw	r3, r4
    clrlwi	r7, r5, 0x10
    clrlwi	r0, r6, 0x10
    rlwinm	r5, r5, 1, 0x10, 0x1e
    rlwinm	r6, r6, 1, 0x10, 0x1e
    beq     _800349cc
    lwz	r9, 0(r3)
    lwz	r8, 4(r3)
    stw	r9, 0(r4)
    stw	r8, 4(r4)
    lwz	r9, 8(r3)
    lwz	r8, 0xc(r3)
    stw	r9, 8(r4)
    stw	r8, 0xc(r4)
    lwz	r9, 0x10(r3)
    lwz	r8, 0x14(r3)
    stw	r9, 0x10(r4)
    stw	r8, 0x14(r4)
    lwz	r9, 0x18(r3)
    lwz	r8, 0x1c(r3)
    stw	r9, 0x18(r4)
    stw	r8, 0x1c(r4)
    lwz	r9, 0x20(r3)
    lwz	r8, 0x24(r3)
    stw	r9, 0x20(r4)
    stw	r8, 0x24(r4)
    lwz	r9, 0x28(r3)
    lwz	r8, 0x2c(r3)
    stw	r9, 0x28(r4)
    stw	r8, 0x2c(r4)
    lwz	r9, 0x30(r3)
    lwz	r8, 0x34(r3)
    stw	r9, 0x30(r4)
    stw	r8, 0x34(r4)
    lwz	r8, 0x38(r3)
    stw	r8, 0x38(r4)
_800349cc:
    lhz	r8, 4(r3)
    subf	r8, r5, r8
    sth	r8, 4(r4)
    lhz	r10, 6(r3)
    lhz	r8, 8(r3)
    mullw	r9, r6, r10
    divwu	r8, r9, r8
    subf	r8, r8, r10
    sth	r8, 6(r4)
    lwz	r8, 0x14(r3)
    cmpwi	r8, 0
    bne     _80034a1c
    lwz	r8, 0(r3)
    rlwinm	r8, r8, 0, 0x1e, 0x1e
    cmpwi	r8, 2
    beq     _80034a1c
    lhz	r8, 8(r3)
    subf	r8, r0, r8
    sth	r8, 8(r4)
    b       _80034a28
_80034a1c:
    lhz	r8, 8(r3)
    subf	r8, r6, r8
    sth	r8, 8(r4)
_80034a28:
    lhz	r8, 0xe(r3)
    subf	r5, r5, r8
    sth	r5, 0xe(r4)
    lhz	r5, 0x10(r3)
    subf	r5, r6, r5
    sth	r5, 0x10(r4)
    lhz	r5, 0xa(r3)
    add	r5, r5, r7
    sth	r5, 0xa(r4)
    lhz	r3, 0xc(r3)
    add	r0, r3, r0
    sth	r0, 0xc(r4)
    blr	
}

asm void __GXSetScissor_LT(register int xl, register int yt, register int xr, register int yb)
{
    nofralloc
    lwz	r9, -0x7de8(r2)
    li	r10, 0
    clrlwi	r7, r5, 0x10
    stw	r10, 0x1e0(r9)
    clrlwi	r5, r6, 0x10
    addi	r0, r5, -1
    lwz	r8, 0x1e0(r9)
    clrlwi	r3, r3, 0x10
    rlwinm	r4, r4, 0xa, 6, 0x15
    rlwinm	r5, r8, 0, 0, 0x15
    or	r3, r5, r3
    stw	r3, 0x1e0(r9)
    addi	r3, r7, -1
    slwi	r0, r0, 0xa
    lwz	r5, 0x1e0(r9)
    rlwinm	r5, r5, 0, 0x16, 0xb
    or	r4, r5, r4
    stw	r4, 0x1e0(r9)
    lwz	r4, 0x1e0(r9)
    clrlwi	r4, r4, 8
    oris	r4, r4, 0x4900
    stw	r4, 0x1e0(r9)
    stw	r10, 0x1e4(r9)
    lwz	r4, 0x1e4(r9)
    rlwinm	r4, r4, 0, 0, 0x15
    or	r3, r4, r3
    stw	r3, 0x1e4(r9)
    lwz	r3, 0x1e4(r9)
    rlwinm	r3, r3, 0, 0x16, 0xb
    or	r0, r3, r0
    stw	r0, 0x1e4(r9)
    lwz	r0, 0x1e4(r9)
    clrlwi	r0, r0, 8
    oris	r0, r0, 0x4a00
    stw	r0, 0x1e4(r9)
    blr	
}

asm void __GXSetScissor_RB(register int xl, register int yt, register int xr, register int yb)
{
    nofralloc
    lwz	r9, -0x7de8(r2)
    li	r10, 0
    clrlwi	r7, r5, 0x10
    stw	r10, 0x1f0(r9)
    clrlwi	r5, r6, 0x10
    addi	r0, r5, -1
    lwz	r8, 0x1f0(r9)
    clrlwi	r3, r3, 0x10
    rlwinm	r4, r4, 0xa, 6, 0x15
    rlwinm	r5, r8, 0, 0, 0x15
    or	r3, r5, r3
    stw	r3, 0x1f0(r9)
    addi	r3, r7, -1
    slwi	r0, r0, 0xa
    lwz	r5, 0x1f0(r9)
    rlwinm	r5, r5, 0, 0x16, 0xb
    or	r4, r5, r4
    stw	r4, 0x1f0(r9)
    lwz	r4, 0x1f0(r9)
    clrlwi	r4, r4, 8
    oris	r4, r4, 0x4900
    stw	r4, 0x1f0(r9)
    stw	r10, 0x1f4(r9)
    lwz	r4, 0x1f4(r9)
    rlwinm	r4, r4, 0, 0, 0x15
    or	r3, r4, r3
    stw	r3, 0x1f4(r9)
    lwz	r3, 0x1f4(r9)
    rlwinm	r3, r3, 0, 0x16, 0xb
    or	r0, r3, r0
    stw	r0, 0x1f4(r9)
    lwz	r0, 0x1f4(r9)
    clrlwi	r0, r0, 8
    oris	r0, r0, 0x4a00
    stw	r0, 0x1f4(r9)
    blr	
}

asm void __GXSetScissorBoxOffset(register int arg)
{
    nofralloc
    lwz	r4, -0x7de8(r2)
    li	r0, 0
    stw	r0, 0x1e8(r4)
    addi	r5, r4, 0x1e8
    rlwinm	r0, r3, 1, 0x10, 0x1e
    lwz	r4, 0x1e8(r4)
    srawi	r0, r0, 5
    rlwinm	r3, r4, 0, 0, 0x15
    or	r0, r3, r0
    stw	r0, 0(r5)
    lwz	r0, 0(r5)
    clrlwi	r0, r0, 8
    oris	r0, r0, 0x4d00
    stw	r0, 0(r5)
    blr	
}

asm void __GXInitTexObjHW(register void* p1, register void* p2, register int id, register void* p4)
{
    nofralloc
    mflr	r0
    cmpwi	r5, 0x13
    stw	r0, 4(r1)
    li	r0, 0
    addi	r8, r3, 0
    stwu	r1, -0x30(r1)
    stw	r31, 0x2c(r1)
    clrlwi	r31, r5, 0x1c
    stw	r30, 0x28(r1)
    addi	r30, r6, 0
    lwz	r7, -0x7de8(r2)
    stb	r0, 0x200(r7)
    addi	r7, r4, 0
    bne     _80034bf4
    li	r31, 0xb
_80034bf4:
    cmpwi	r5, 0x26
    beq     _80034c14
    bge     _80034c30
    cmpwi	r5, 4
    bge     _80034c30
    cmpwi	r5, 0
    bge     _80034c14
    b       _80034c30
_80034c14:
    lwz	r3, -0x7de8(r2)
    lwzu	r0, 0x1fc(r3)
    rlwinm	r0, r0, 0, 0x11, 0xe
    oris	r0, r0, 1
    ori	r0, r0, 0x8000
    stw	r0, 0(r3)
    b       _80034c44
_80034c30:
    lwz	r3, -0x7de8(r2)
    lwzu	r0, 0x1fc(r3)
    rlwinm	r0, r0, 0, 0x11, 0xe
    oris	r0, r0, 1
    stw	r0, 0(r3)
_80034c44:
    rlwinm	r4, r5, 0, 0x1b, 0x1b
    lwz	r3, -0x7de8(r2)
    addi	r0, r4, -0x10
    cntlzw	r0, r0
    rlwinm	r0, r0, 0x1b, 0x18, 0x1f
    stb	r0, 0x200(r3)
    addi	r4, r8, 0
    addi	r6, r1, 0x20
    lwzu	r0, 0x1fc(r3)
    addi	r8, r1, 0x18
    rlwinm	r0, r0, 0, 0x1d, 0x1b
    rlwimi	r0, r31, 0, 0x1c, 0x1c
    stw	r0, 0(r3)
    addi	r3, r5, 0
    addi	r5, r7, 0
    clrlwi	r31, r31, 0x1d
    addi	r7, r1, 0x1c
    bl      __GXGetTexTileSize
    lwz	r3, -0x7de8(r2)
    li	r0, 0
    stw	r0, 0x1f8(r3)
    addi	r7, r3, 0x1f8
    addi	r8, r3, 0x1fc
    lwz	r5, 0x20(r1)
    rlwinm	r3, r30, 9, 0xf, 0x16
    lwz	r4, 0x18(r1)
    slwi	r0, r31, 4
    lwz	r6, 0(r7)
    mullw	r4, r5, r4
    rlwinm	r5, r6, 0, 0, 0x15
    or	r4, r5, r4
    stw	r4, 0(r7)
    lwz	r4, 0(r7)
    clrlwi	r4, r4, 8
    oris	r4, r4, 0x4d00
    stw	r4, 0(r7)
    lwz	r4, 0(r8)
    rlwinm	r4, r4, 0, 0x17, 0x15
    or	r3, r4, r3
    stw	r3, 0(r8)
    lwz	r3, 0(r8)
    rlwinm	r3, r3, 0, 0x1c, 0x18
    or	r0, r3, r0
    stw	r0, 0(r8)
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr	
}

asm void __GXSetZMode(register int arg)
{
    nofralloc
    lwz	r4, -0x7de8(r2)
    slwi	r0, r3, 0xc
    lwz	r3, 0x1ec(r4)
    rlwinm	r3, r3, 0, 0x14, 0x11
    or	r0, r3, r0
    stw	r0, 0x1ec(r4)
    lwzu	r0, 0x1fc(r4)
    rlwinm	r0, r0, 0, 0x14, 0x11
    stw	r0, 0(r4)
    blr	
}

asm void __GXSetBlendMode(register int a, register int b, register int c)
{
    nofralloc
    lwz	r6, -0x7de8(r2)
    clrlwi	r4, r3, 0x1f
    addi	r0, r4, -1
    lwz	r4, 0x1ec(r6)
    cntlzw	r0, r0
    rlwinm	r3, r3, 0, 0x1e, 0x1e
    rlwinm	r5, r4, 0, 0, 0x1e
    rlwinm	r4, r0, 0x1b, 0x18, 0x1f
    or	r0, r5, r4
    stw	r0, 0x1ec(r6)
    addi	r0, r3, -2
    cntlzw	r0, r0
    lwz	r3, 0x1ec(r6)
    rlwinm	r5, r0, 0x1c, 0x17, 0x1e
    rlwinm	r3, r3, 0, 0x1f, 0x1d
    or	r0, r3, r5
    stw	r0, 0x1ec(r6)
    lwz	r0, 0x1fc(r6)
    rlwinm	r0, r0, 0, 0, 0x1e
    or	r0, r0, r4
    stw	r0, 0x1fc(r6)
    lwz	r0, 0x1fc(r6)
    rlwinm	r0, r0, 0, 0x1f, 0x1d
    or	r0, r0, r5
    stw	r0, 0x1fc(r6)
    blr	
}

asm void fn_80034D9C(register void* p1, register void* p2, register int id, register void* p4)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    lfs	f0, -0x7dc0(r2)
    fdivs	f1, f0, f1
    bl      __cvt_fp2unsigned
    clrlwi	r6, r3, 0x17
    lwz	r4, -0x7de8(r2)
    li	r0, 0x61
    lis	r3, -0x33ff
    stb	r0, -0x8000(r3)
    oris	r0, r6, 0x4e00
    li	r5, 0
    stw	r0, -0x8000(r3)
    subfic	r3, r6, 0x100
    addic	r0, r3, -1
    sth	r5, 2(r4)
    subfe	r0, r0, r3
    rlwinm	r0, r0, 0xa, 0xe, 0x15
    lwz	r3, 0x1ec(r4)
    cmplwi	r6, 0x80
    addi	r5, r6, 0
    rlwinm	r3, r3, 0, 0x16, 0x14
    or	r0, r3, r0
    stw	r0, 0x1ec(r4)
    lwz	r0, 0x1e4(r4)
    rlwinm	r4, r0, 0x16, 0x16, 0x1f
    rlwinm	r0, r0, 0x1e, 0xe, 0x17
    divwu	r3, r0, r6
    addi	r4, r4, 1
    addi	r3, r3, 1
    ble     _80034e48
    cmplwi	r6, 0x100
    bge     _80034e48
    b       _80034e2c
_80034e28:
    srwi	r5, r5, 1
_80034e2c:
    clrlwi.	r0, r5, 0x1f
    beq     _80034e28
    divwu	r0, r4, r5
    mullw	r0, r0, r5
    subf.	r0, r0, r4
    bne     _80034e48
    addi	r3, r3, 1
_80034e48:
    cmplwi	r3, 0x400
    ble     _80034e54
    li	r3, 0x400
_80034e54:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void __GXSetBlendModePair(register int a, register int b, register int c)
{
    nofralloc
    clrlwi	r0, r4, 8
    lbz	r4, 3(r3)
    lbz	r5, 0(r3)
    li	r6, 0x61
    slwi	r7, r4, 8
    lwz	r4, -0x7de8(r2)
    rlwimi	r7, r5, 0, 0x18, 0x1f
    lis	r5, -0x33ff
    clrlwi	r7, r7, 8
    stb	r6, -0x8000(r5)
    oris	r7, r7, 0x4f00
    stw	r7, -0x8000(r5)
    oris	r7, r0, 0x5100
    li	r0, 0
    lbz	r8, 2(r3)
    lbz	r3, 1(r3)
    slwi	r3, r3, 8
    stb	r6, -0x8000(r5)
    rlwimi	r3, r8, 0, 0x18, 0x1f
    clrlwi	r3, r3, 8
    oris	r3, r3, 0x5000
    stw	r3, -0x8000(r5)
    stb	r6, -0x8000(r5)
    stw	r7, -0x8000(r5)
    sth	r0, 2(r4)
    blr	
}

asm void GXSetCopyClear(register void* p1, register void* p2, register int id, register void* p4)
{
    nofralloc
    stwu	r1, -0x50(r1)
    clrlwi.	r0, r3, 0x18
    stmw	r23, 0x2c(r1)
    beq     _80035000
    lbz	r0, 1(r4)
    lbz	r3, 7(r4)
    slwi	r30, r0, 4
    lbz	r8, 0(r4)
    lbz	r0, 0x13(r4)
    slwi	r25, r3, 4
    lbz	r10, 6(r4)
    rlwimi	r30, r8, 0, 0x1c, 0x1f
    lbz	r11, 2(r4)
    lbz	r7, 0xd(r4)
    rlwimi	r25, r10, 0, 0x1c, 0x1f
    slwi	r27, r11, 8
    lbz	r9, 8(r4)
    lbz	r3, 0xe(r4)
    slwi	r26, r9, 8
    lbz	r28, 3(r4)
    rlwimi	r27, r30, 0, 0x18, 0x1f
    lbz	r9, 0x10(r4)
    slwi	r23, r7, 4
    lbz	r12, 0xc(r4)
    lbz	r7, 0x15(r4)
    slwi	r24, r3, 8
    rlwimi	r23, r12, 0, 0x1c, 0x1f
    lbz	r29, 0x12(r4)
    slwi	r0, r0, 4
    rlwimi	r0, r29, 0, 0x1c, 0x1f
    lbz	r8, 0x14(r4)
    slwi	r28, r28, 0xc
    lbz	r31, 9(r4)
    rlwimi	r28, r27, 0, 0x14, 0x1f
    lbz	r29, 4(r4)
    rlwimi	r24, r23, 0, 0x18, 0x1f
    lbz	r10, 0xf(r4)
    slwi	r23, r8, 8
    lbz	r12, 0xa(r4)
    rlwimi	r26, r25, 0, 0x18, 0x1f
    lbz	r3, 0x16(r4)
    slwi	r25, r10, 0xc
    lbz	r30, 5(r4)
    rlwimi	r23, r0, 0, 0x18, 0x1f
    lbz	r0, 0x17(r4)
    slwi	r27, r31, 0xc
    lbz	r11, 0xb(r4)
    lbz	r8, 0x11(r4)
    slwi	r4, r29, 0x10
    slwi	r7, r7, 0xc
    slwi	r10, r12, 0x10
    rlwimi	r27, r26, 0, 0x14, 0x1f
    slwi	r12, r3, 0x10
    rlwimi	r7, r23, 0, 0x14, 0x1f
    rlwimi	r4, r28, 0, 0x10, 0x1f
    slwi	r3, r30, 0x14
    rlwimi	r25, r24, 0, 0x14, 0x1f
    slwi	r9, r9, 0x10
    rlwimi	r10, r27, 0, 0x10, 0x1f
    rlwimi	r3, r4, 0, 0xc, 0x1f
    rlwimi	r12, r7, 0, 0x10, 0x1f
    clrlwi	r7, r3, 8
    slwi	r3, r11, 0x14
    rlwimi	r3, r10, 0, 0xc, 0x1f
    clrlwi	r4, r3, 8
    slwi	r3, r8, 0x14
    rlwimi	r9, r25, 0, 0x10, 0x1f
    rlwimi	r3, r9, 0, 0xc, 0x1f
    slwi	r0, r0, 0x14
    rlwimi	r0, r12, 0, 0xc, 0x1f
    clrlwi	r3, r3, 8
    clrlwi	r0, r0, 8
    oris	r8, r7, 0x100
    oris	r7, r4, 0x200
    oris	r9, r3, 0x300
    oris	r10, r0, 0x400
    b       _80035020
_80035000:
    lis	r8, 0x166
    lis	r7, 0x266
    lis	r4, 0x366
    lis	r3, 0x466
    addi	r8, r8, 0x6666
    addi	r7, r7, 0x6666
    addi	r9, r4, 0x6666
    addi	r10, r3, 0x6666
_80035020:
    li	r4, 0x61
    lis	r3, -0x33ff
    stb	r4, -0x8000(r3)
    clrlwi.	r0, r5, 0x18
    stw	r8, -0x8000(r3)
    stb	r4, -0x8000(r3)
    stw	r7, -0x8000(r3)
    stb	r4, -0x8000(r3)
    stw	r9, -0x8000(r3)
    stb	r4, -0x8000(r3)
    stw	r10, -0x8000(r3)
    beq     _800350b4
    lbz	r0, 0(r6)
    lbz	r3, 1(r6)
    oris	r5, r0, 0x5300
    lbz	r0, 4(r6)
    lbz	r4, 2(r6)
    rlwinm	r7, r5, 0, 0x1a, 0x13
    slwi	r5, r3, 6
    lbz	r3, 5(r6)
    or	r7, r7, r5
    oris	r8, r0, 0x5400
    lbz	r5, 3(r6)
    lbz	r0, 6(r6)
    rlwinm	r6, r7, 0, 0x14, 0xd
    slwi	r4, r4, 0xc
    or	r6, r6, r4
    rlwinm	r4, r8, 0, 0x1a, 0x13
    slwi	r3, r3, 6
    or	r3, r4, r3
    rlwinm	r6, r6, 0, 0xe, 7
    slwi	r4, r5, 0x12
    rlwinm	r3, r3, 0, 0x14, 0xd
    slwi	r0, r0, 0xc
    or	r6, r6, r4
    or	r7, r3, r0
    b       _800350c4
_800350b4:
    lis	r4, 0x5359
    lis	r3, 0x5400
    addi	r6, r4, 0x5000
    addi	r7, r3, 0x15
_800350c4:
    li	r5, 0x61
    lwz	r3, -0x7de8(r2)
    lis	r4, -0x33ff
    stb	r5, -0x8000(r4)
    li	r0, 0
    stw	r6, -0x8000(r4)
    stb	r5, -0x8000(r4)
    stw	r7, -0x8000(r4)
    sth	r0, 2(r3)
    lmw	r23, 0x2c(r1)
    addi	r1, r1, 0x50
    blr	
}

asm void __GXSetGenMode2(register int idx)
{
    nofralloc
    lwz	r4, -0x7de8(r2)
    slwi	r0, r3, 7
    lwzu	r3, 0x1ec(r4)
    rlwinm	r3, r3, 0, 0x19, 0x16
    or	r0, r3, r0
    stw	r0, 0(r4)
    blr	
}


asm void __GXSetDispCopy(register int a, register int b)
{
    nofralloc
    clrlwi.	r0, r4, 0x18
    beq     _80035150
    lwz	r7, -0x7de8(r2)
    li	r0, 0x61
    lis	r5, -0x33ff
    lwz	r6, 0x1d8(r7)
    rlwinm	r6, r6, 0, 0, 0x1e
    stb	r0, -0x8000(r5)
    ori	r6, r6, 1
    rlwinm	r6, r6, 0, 0x1f, 0x1b
    ori	r6, r6, 0xe
    stw	r6, -0x8000(r5)
    lwz	r6, 0x1d0(r7)
    stb	r0, -0x8000(r5)
    rlwinm	r0, r6, 0, 0, 0x1d
    stw	r0, -0x8000(r5)
_80035150:
    clrlwi.	r0, r4, 0x18
    li	r0, 0
    bne     _80035170
    lwz	r5, -0x7de8(r2)
    lwz	r5, 0x1dc(r5)
    clrlwi	r5, r5, 0x1d
    cmplwi	r5, 3
    bne     _8003519c
_80035170:
    lwz	r5, -0x7de8(r2)
    lwz	r7, 0x1dc(r5)
    rlwinm	r5, r7, 0x1a, 0x1f, 0x1f
    cmplwi	r5, 1
    bne     _8003519c
    li	r0, 0x61
    lis	r6, -0x33ff
    stb	r0, -0x8000(r6)
    rlwinm	r5, r7, 0, 0x1a, 0x18
    li	r0, 1
    stw	r5, -0x8000(r6)
_8003519c:
    li	r9, 0x61
    lwz	r7, -0x7de8(r2)
    lis	r8, -0x33ff
    stb	r9, -0x8000(r8)
    rlwinm	r3, r3, 0x1b, 8, 0x1f
    oris	r10, r3, 0x4b00
    lwz	r6, 0x1e0(r7)
    clrlwi.	r5, r4, 0x18
    rlwinm	r3, r4, 0xb, 0xd, 0x14
    stw	r6, -0x8000(r8)
    stb	r9, -0x8000(r8)
    lwz	r4, 0x1e4(r7)
    stw	r4, -0x8000(r8)
    stb	r9, -0x8000(r8)
    lwz	r4, 0x1e8(r7)
    stw	r4, -0x8000(r8)
    stb	r9, -0x8000(r8)
    stw	r10, -0x8000(r8)
    lwz	r4, 0x1ec(r7)
    rlwinm	r4, r4, 0, 0x15, 0x13
    or	r3, r4, r3
    stw	r3, 0x1ec(r7)
    lwz	r3, 0x1ec(r7)
    rlwinm	r3, r3, 0, 0x12, 0x10
    ori	r3, r3, 0x4000
    stw	r3, 0x1ec(r7)
    lwz	r3, 0x1ec(r7)
    clrlwi	r3, r3, 8
    oris	r3, r3, 0x5200
    stw	r3, 0x1ec(r7)
    stb	r9, -0x8000(r8)
    lwz	r3, 0x1ec(r7)
    stw	r3, -0x8000(r8)
    beq     _8003523c
    stb	r9, -0x8000(r8)
    lwz	r3, 0x1d8(r7)
    stw	r3, -0x8000(r8)
    stb	r9, -0x8000(r8)
    lwz	r3, 0x1d0(r7)
    stw	r3, -0x8000(r8)
_8003523c:
    clrlwi.	r0, r0, 0x18
    beq     _8003525c
    li	r0, 0x61
    lwz	r3, -0x7de8(r2)
    lis	r4, -0x33ff
    stb	r0, -0x8000(r4)
    lwz	r0, 0x1dc(r3)
    stw	r0, -0x8000(r4)
_8003525c:
    lwz	r3, -0x7de8(r2)
    li	r0, 0
    sth	r0, 2(r3)
    blr	
}

asm void __GXSetTexCopy(register void* p, register int id, register int v)
{
    nofralloc
    clrlwi.	r0, r4, 0x18
    beq     _800352ac
    lwz	r7, -0x7de8(r2)
    li	r0, 0x61
    lis	r5, -0x33ff
    lwz	r6, 0x1d8(r7)
    rlwinm	r6, r6, 0, 0, 0x1e
    stb	r0, -0x8000(r5)
    ori	r6, r6, 1
    rlwinm	r6, r6, 0, 0x1f, 0x1b
    ori	r6, r6, 0xe
    stw	r6, -0x8000(r5)
    lwz	r6, 0x1d0(r7)
    stb	r0, -0x8000(r5)
    rlwinm	r0, r6, 0, 0, 0x1d
    stw	r0, -0x8000(r5)
_800352ac:
    lwz	r6, -0x7de8(r2)
    li	r0, 0
    lbz	r5, 0x200(r6)
    lwz	r7, 0x1dc(r6)
    cmplwi	r5, 0
    beq     _800352dc
    clrlwi	r5, r7, 0x1d
    cmplwi	r5, 3
    beq     _800352dc
    rlwinm	r0, r7, 0, 0, 0x1c
    ori	r7, r0, 3
    li	r0, 1
_800352dc:
    clrlwi.	r5, r4, 0x18
    bne     _800352f0
    clrlwi	r5, r7, 0x1d
    cmplwi	r5, 3
    bne     _80035304
_800352f0:
    rlwinm	r5, r7, 0x1a, 0x1f, 0x1f
    cmplwi	r5, 1
    bne     _80035304
    li	r0, 1
    rlwinm	r7, r7, 0, 0x1a, 0x18
_80035304:
    clrlwi.	r5, r0, 0x18
    beq     _8003531c
    li	r6, 0x61
    lis	r5, -0x33ff
    stb	r6, -0x8000(r5)
    stw	r7, -0x8000(r5)
_8003531c:
    li	r9, 0x61
    lwz	r7, -0x7de8(r2)
    lis	r8, -0x33ff
    stb	r9, -0x8000(r8)
    rlwinm	r3, r3, 0x1b, 8, 0x1f
    oris	r10, r3, 0x4b00
    lwz	r6, 0x1f0(r7)
    clrlwi.	r5, r4, 0x18
    rlwinm	r3, r4, 0xb, 0xd, 0x14
    stw	r6, -0x8000(r8)
    stb	r9, -0x8000(r8)
    lwz	r4, 0x1f4(r7)
    stw	r4, -0x8000(r8)
    stb	r9, -0x8000(r8)
    lwz	r4, 0x1f8(r7)
    stw	r4, -0x8000(r8)
    stb	r9, -0x8000(r8)
    stw	r10, -0x8000(r8)
    lwz	r4, 0x1fc(r7)
    rlwinm	r4, r4, 0, 0x15, 0x13
    or	r3, r4, r3
    stw	r3, 0x1fc(r7)
    lwz	r3, 0x1fc(r7)
    rlwinm	r3, r3, 0, 0x12, 0x10
    stw	r3, 0x1fc(r7)
    lwz	r3, 0x1fc(r7)
    clrlwi	r3, r3, 8
    oris	r3, r3, 0x5200
    stw	r3, 0x1fc(r7)
    stb	r9, -0x8000(r8)
    lwz	r3, 0x1fc(r7)
    stw	r3, -0x8000(r8)
    beq     _800353b8
    stb	r9, -0x8000(r8)
    lwz	r3, 0x1d8(r7)
    stw	r3, -0x8000(r8)
    stb	r9, -0x8000(r8)
    lwz	r3, 0x1d0(r7)
    stw	r3, -0x8000(r8)
_800353b8:
    clrlwi.	r0, r0, 0x18
    beq     _800353d8
    li	r0, 0x61
    lwz	r3, -0x7de8(r2)
    lis	r4, -0x33ff
    stb	r0, -0x8000(r4)
    lwz	r0, 0x1dc(r3)
    stw	r0, -0x8000(r4)
_800353d8:
    lwz	r3, -0x7de8(r2)
    li	r0, 0
    sth	r0, 2(r3)
    blr	
}

asm void __GXFlushTextureCache(register int a)
{
    nofralloc
    li	r6, 0x61
    lwz	r3, -0x7de8(r2)
    lis	r5, -0x33ff
    lis	r4, 0x5500
    stb	r6, -0x8000(r5)
    addi	r0, r4, 0x3ff
    stw	r0, -0x8000(r5)
    lis	r4, 0x5600
    addi	r4, r4, 0x3ff
    stb	r6, -0x8000(r5)
    li	r0, 0
    stw	r4, -0x8000(r5)
    sth	r0, 2(r3)
    blr	
}

asm void GXInitLightSpot(register void* p1, register void* p2, register int id, register void* p4)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r4, 0
    stw	r30, 0x18(r1)
    addi	r30, r3, 0
    lfs	f0, -0x7db8(r2)
    fcmpo	cr0, f1, f0
    cror	2, 0, 2
    beq     _80035458
    lfs	f0, -0x7db4(r2)
    fcmpo	cr0, f1, f0
    ble     _8003545c
_80035458:
    li	r31, 0
_8003545c:
    lfs	f2, -0x7db0(r2)
    lfs	f0, -0x7dac(r2)
    fmuls	f1, f2, f1
    fdivs	f1, f1, f0
    bl      fn_80088624
    cmplwi	r31, 6
    bgt     _80035580
    lis     r3, -0x7fed
    addi	r3, r3, -0x4ee0
    slwi	r0, r31, 2
    lwzx	r0, r3, r0
    mtctr	r0
    bctr	
    lfs	f0, -0x7da8(r2)
    lfs	f4, -0x7da4(r2)
    fmuls	f3, f0, f1
    lfs	f6, -0x7db8(r2)
    b       _8003558c
    lfs	f2, -0x7da0(r2)
    fneg	f0, f1
    lfs	f6, -0x7db8(r2)
    fsubs	f1, f2, f1
    fdivs	f1, f2, f1
    fmr	f4, f1
    fmuls	f3, f0, f1
    b       _8003558c
    lfs	f2, -0x7da0(r2)
    fneg	f0, f1
    lfs	f3, -0x7db8(r2)
    fsubs	f1, f2, f1
    fdivs	f1, f2, f1
    fmr	f6, f1
    fmuls	f4, f0, f1
    b       _8003558c
    lfs	f4, -0x7da0(r2)
    lfs	f2, -0x7d9c(r2)
    fsubs	f3, f4, f1
    fsubs	f0, f1, f2
    fmuls	f3, f3, f3
    fmuls	f0, f1, f0
    fdivs	f1, f4, f3
    fmuls	f3, f1, f0
    fmuls	f4, f2, f1
    fneg	f6, f1
    b       _8003558c
    lfs	f5, -0x7da0(r2)
    lfs	f3, -0x7d98(r2)
    fsubs	f4, f5, f1
    lfs	f2, -0x7d94(r2)
    fadds	f0, f5, f1
    fmuls	f4, f4, f4
    fmuls	f0, f2, f0
    fdivs	f4, f5, f4
    fmuls	f2, f3, f4
    fmuls	f4, f0, f4
    fmr	f6, f2
    fmuls	f3, f2, f1
    b       _8003558c
    lfs	f5, -0x7da0(r2)
    lfs	f0, -0x7d9c(r2)
    fsubs	f4, f5, f1
    lfs	f2, -0x7d94(r2)
    fmuls	f3, f0, f1
    lfs	f0, -0x7d90(r2)
    fmuls	f2, f2, f1
    fmuls	f4, f4, f4
    fmuls	f1, f3, f1
    fdivs	f3, f5, f4
    fmuls	f1, f3, f1
    fmuls	f4, f2, f3
    fmuls	f6, f0, f3
    fsubs	f3, f5, f1
    b       _8003558c
_80035580:
    lfs	f4, -0x7db8(r2)
    lfs	f3, -0x7da0(r2)
    fmr	f6, f4
_8003558c:
    stfs	f3, 0x10(r30)
    stfs	f4, 0x14(r30)
    stfs	f6, 0x18(r30)
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}


asm void GXInitLightDistAttn(register void* p1, register void* p2, register int a, register int b)
{
    nofralloc
    lfs	f0, -0x7db8(r2)
    fcmpo	cr0, f1, f0
    bge     _800355c0
    li	r4, 0
_800355c0:
    lfs	f0, -0x7db8(r2)
    fcmpo	cr0, f2, f0
    cror	2, 0, 2
    beq     _800355e0
    lfs	f0, -0x7da0(r2)
    fcmpo	cr0, f2, f0
    cror	2, 1, 2
    bne     _800355e4
_800355e0:
    li	r4, 0
_800355e4:
    cmpwi	r4, 2
    beq     _80035624
    bge     _80035600
    cmpwi	r4, 0
    beq     _80035664
    bge     _8003560c
    b       _80035664
_80035600:
    cmpwi	r4, 4
    bge     _80035664
    b       _80035648
_8003560c:
    lfs	f5, -0x7da0(r2)
    fmuls	f0, f2, f1
    lfs	f4, -0x7db8(r2)
    fsubs	f1, f5, f2
    fdivs	f3, f1, f0
    b       _80035670
_80035624:
    lfs	f5, -0x7da0(r2)
    fmuls	f4, f2, f1
    lfs	f3, -0x7d8c(r2)
    fsubs	f2, f5, f2
    fmuls	f0, f1, f4
    fmuls	f1, f3, f2
    fdivs	f3, f1, f4
    fdivs	f4, f1, f0
    b       _80035670
_80035648:
    fmuls	f0, f2, f1
    lfs	f5, -0x7da0(r2)
    lfs	f3, -0x7db8(r2)
    fsubs	f2, f5, f2
    fmuls	f0, f1, f0
    fdivs	f4, f2, f0
    b       _80035670
_80035664:
    lfs	f3, -0x7db8(r2)
    lfs	f5, -0x7da0(r2)
    fmr	f4, f3
_80035670:
    stfs	f5, 0x1c(r3)
    stfs	f3, 0x20(r3)
    stfs	f4, 0x24(r3)
    blr	
}

asm void GXInitLightAttnCoefs(void)
{
    nofralloc
    stfs	f1, 0x28(r3)
    stfs	f2, 0x2c(r3)
    stfs	f3, 0x30(r3)
    blr	
}

asm void GXInitSpecularDir(register void* p)
{
    nofralloc
    fneg	f4, f1
    fneg	f1, f2
    fneg	f0, f3
    stfs	f4, 0x34(r3)
    stfs	f1, 0x38(r3)
    stfs	f0, 0x3c(r3)
    blr	
}

asm void fn_800356AC(void)
{
    nofralloc
    lwz	r0, 0(r4)
    stw	r0, 0xc(r3)
    blr	
}

asm void __GXSetChanColor(register void* p)
{
    nofralloc
    cntlzw	r0, r4
    subfic	r0, r0, 0x1f
    rlwinm	r5, r0, 4, 0x19, 0x1b
    lis	r4, -0x33ff
    li	r0, 0x10
    addi	r5, r5, 0x600
    stb	r0, -0x8000(r4)
    oris	r0, r5, 0xf
    stwu	r0, -0x8000(r4)
    lwz	r0, 0xc(r3)
    xor	r6, r6, r6
    psq_l	f5, 0x10(r3), 0, 0
    psq_l	f4, 0x18(r3), 0, 0
    psq_l	f3, 0x20(r3), 0, 0
    psq_l	f2, 0x28(r3), 0, 0
    psq_l	f1, 0x30(r3), 0, 0
    psq_l	f0, 0x38(r3), 0, 0
    stw	r6, 0(r4)
    stw	r6, 0(r4)
    stw	r6, 0(r4)
    stw	r0, 0(r4)
    psq_st	f5, 0x0(r4), 0, 0
    psq_st	f4, 0x0(r4), 0, 0
    psq_st	f3, 0x0(r4), 0, 0
    psq_st	f2, 0x0(r4), 0, 0
    psq_st	f1, 0x0(r4), 0, 0
    psq_st	f0, 0x0(r4), 0, 0
    lwz	r3, -0x7de8(r2)
    li	r0, 1
    sth	r0, 2(r3)
    blr	
}

asm void GXSetChanAmbColor(register void* p1, register int a, register int b)
{
    nofralloc
    cmpwi	r3, 3
    beq     _800357c0
    bge     _80035758
    cmpwi	r3, 1
    beq     _80035788
    bge     _800357a8
    cmpwi	r3, 0
    bge     _80035768
    blr	
_80035758:
    cmpwi	r3, 5
    beq     _800357e4
    bgelr	
    b       _800357d8
_80035768:
    lwz	r3, -0x7de8(r2)
    li	r5, 0
    lwz	r0, 0(r4)
    lwz	r3, 0xa8(r3)
    rlwinm	r0, r0, 0, 0, 0x17
    mr	r7, r0
    rlwimi	r7, r3, 0, 0x18, 0x1f
    b       _800357f4
_80035788:
    lwz	r3, -0x7de8(r2)
    li	r5, 1
    lwz	r0, 0(r4)
    lwz	r3, 0xac(r3)
    rlwinm	r0, r0, 0, 0, 0x17
    mr	r7, r0
    rlwimi	r7, r3, 0, 0x18, 0x1f
    b       _800357f4
_800357a8:
    lwz	r3, -0x7de8(r2)
    li	r5, 0
    lbz	r7, 3(r4)
    lwz	r3, 0xa8(r3)
    rlwimi	r7, r3, 0, 0, 0x17
    b       _800357f4
_800357c0:
    lwz	r3, -0x7de8(r2)
    li	r5, 1
    lbz	r7, 3(r4)
    lwz	r3, 0xac(r3)
    rlwimi	r7, r3, 0, 0, 0x17
    b       _800357f4
_800357d8:
    lwz	r7, 0(r4)
    li	r5, 0
    b       _800357f4
_800357e4:
    lwz	r7, 0(r4)
    li	r5, 1
    b       _800357f4
    blr	
_800357f4:
    li	r0, 0x10
    lwz	r4, -0x7de8(r2)
    lis	r6, -0x33ff
    stb	r0, -0x8000(r6)
    addi	r3, r5, 0x100a
    slwi	r0, r5, 2
    stw	r3, -0x8000(r6)
    li	r5, 1
    add	r3, r4, r0
    stw	r7, -0x8000(r6)
    sth	r5, 2(r4)
    stw	r7, 0xa8(r3)
    blr	
}

asm void GXSetChanMatColor(register void* p1, register int a, register int b)
{
    nofralloc
    cmpwi	r3, 3
    beq     _800358b4
    bge     _8003584c
    cmpwi	r3, 1
    beq     _8003587c
    bge     _8003589c
    cmpwi	r3, 0
    bge     _8003585c
    blr	
_8003584c:
    cmpwi	r3, 5
    beq     _800358d8
    bgelr	
    b       _800358cc
_8003585c:
    lwz	r3, -0x7de8(r2)
    li	r5, 0
    lwz	r0, 0(r4)
    lwz	r3, 0xb0(r3)
    rlwinm	r0, r0, 0, 0, 0x17
    mr	r7, r0
    rlwimi	r7, r3, 0, 0x18, 0x1f
    b       _800358e8
_8003587c:
    lwz	r3, -0x7de8(r2)
    li	r5, 1
    lwz	r0, 0(r4)
    lwz	r3, 0xb4(r3)
    rlwinm	r0, r0, 0, 0, 0x17
    mr	r7, r0
    rlwimi	r7, r3, 0, 0x18, 0x1f
    b       _800358e8
_8003589c:
    lwz	r3, -0x7de8(r2)
    li	r5, 0
    lbz	r7, 3(r4)
    lwz	r3, 0xb0(r3)
    rlwimi	r7, r3, 0, 0, 0x17
    b       _800358e8
_800358b4:
    lwz	r3, -0x7de8(r2)
    li	r5, 1
    lbz	r7, 3(r4)
    lwz	r3, 0xb4(r3)
    rlwimi	r7, r3, 0, 0, 0x17
    b       _800358e8
_800358cc:
    lwz	r7, 0(r4)
    li	r5, 0
    b       _800358e8
_800358d8:
    lwz	r7, 0(r4)
    li	r5, 1
    b       _800358e8
    blr	
_800358e8:
    li	r0, 0x10
    lwz	r4, -0x7de8(r2)
    lis	r6, -0x33ff
    stb	r0, -0x8000(r6)
    addi	r3, r5, 0x100c
    slwi	r0, r5, 2
    stw	r3, -0x8000(r6)
    li	r5, 1
    add	r3, r4, r0
    stw	r7, -0x8000(r6)
    sth	r5, 2(r4)
    stw	r7, 0xb0(r3)
    blr	
}

asm void __GXSetChanAmbColor(register void* p)
{
    nofralloc
    lwz	r6, -0x7de8(r2)
    rlwinm	r0, r3, 4, 0x14, 0x1b
    clrlwi	r8, r3, 0x18
    lwz	r5, 0x204(r6)
    li	r4, 0x10
    lis	r3, -0x33ff
    rlwinm	r5, r5, 0, 0x1c, 0x18
    or	r0, r5, r0
    stw	r0, 0x204(r6)
    li	r0, 0x1009
    stb	r4, -0x8000(r3)
    stw	r0, -0x8000(r3)
    stw	r8, -0x8000(r3)
    lwz	r0, 0x4f4(r6)
    ori	r0, r0, 4
    stw	r0, 0x4f4(r6)
    blr	
}

asm void __GXSetChanCtrl(register void* p1, register int a, register int b)
{
    nofralloc
    rlwinm	r0, r4, 1, 0x17, 0x1e
    or	r0, r0, r6
    rlwinm	r4, r0, 0, 0x1a, 0x18
    slwi	r0, r5, 6
    cmpwi	r9, 0
    clrlwi	r10, r3, 0x1e
    or	r6, r4, r0
    bne     _80035984
    li	r8, 0
_80035984:
    subfic	r4, r9, 2
    addic	r0, r4, -1
    subfe	r5, r0, r4
    neg	r4, r9
    addic	r0, r4, -1
    subfe	r0, r0, r4
    rlwinm	r6, r6, 0, 0x19, 0x16
    slwi	r4, r8, 7
    or	r4, r6, r4
    rlwinm	r6, r4, 0, 0x17, 0x15
    slwi	r4, r5, 9
    or	r4, r6, r4
    rlwinm	r4, r4, 0, 0x16, 0x14
    slwi	r0, r0, 0xa
    or	r6, r4, r0
    rlwinm	r6, r6, 0, 0x1e, 0x19
    rlwimi	r6, r7, 2, 0x1a, 0x1d
    rlwinm	r6, r6, 0, 0x15, 0x10
    li	r5, 0x10
    lis	r4, -0x33ff
    stb	r5, -0x8000(r4)
    addi	r0, r10, 0x100e
    rlwimi	r6, r7, 7, 0x11, 0x14
    stw	r0, -0x8000(r4)
    cmpwi	r3, 4
    stw	r6, -0x8000(r4)
    bne     _80035a04
    stb	r5, -0x8000(r4)
    li	r0, 0x1010
    stw	r0, -0x8000(r4)
    stw	r6, -0x8000(r4)
    b       _80035a1c
_80035a04:
    cmpwi	r3, 5
    bne     _80035a1c
    stb	r5, -0x8000(r4)
    li	r0, 0x1011
    stw	r0, -0x8000(r4)
    stw	r6, -0x8000(r4)
_80035a1c:
    lwz	r3, -0x7de8(r2)
    li	r0, 1
    sth	r0, 2(r3)
    blr	
}

asm void __GXGetTexBufferSize(register void* p1, register void* p2, register int id, register void* p4)
{
    nofralloc
    stwu	r1, -0x28(r1)
    cmplwi	r5, 0x3c
    stw	r31, 0x24(r1)
    bgt     _80035a78
    lis     r8, -0x7fed
    addi	r8, r8, -0x4ec0
    slwi	r0, r5, 2
    lwzx	r0, r8, r0
    mtctr	r0
    bctr	
    li	r0, 3
    li	r8, 3
    b       _80035a80
    li	r0, 3
    li	r8, 2
    b       _80035a80
    li	r0, 2
    li	r8, 2
    b       _80035a80
_80035a78:
    li	r8, 0
    li	r0, 0
_80035a80:
    cmplwi	r5, 6
    beq     _80035a90
    cmplwi	r5, 0x16
    bne     _80035a98
_80035a90:
    li	r5, 0x40
    b       _80035a9c
_80035a98:
    li	r5, 0x20
_80035a9c:
    clrlwi	r6, r6, 0x18
    cmplwi	r6, 1
    bne     _80035b44
    clrlwi	r9, r7, 0x18
    li	r6, 1
    mtctr	r9
    slw	r7, r6, r8
    slw	r6, r6, r0
    cmplwi	r9, 0
    addi	r10, r6, -1
    addi	r7, r7, -1
    li	r31, 0
    ble     _80035b78
_80035ad0:
    clrlwi	r11, r3, 0x10
    add	r6, r11, r10
    clrlwi	r12, r4, 0x10
    sraw	r9, r6, r0
    add	r6, r12, r7
    sraw	r6, r6, r8
    mullw	r6, r9, r6
    mullw	r6, r5, r6
    cmplwi	r11, 1
    add	r31, r31, r6
    bne     _80035b04
    cmplwi	r12, 1
    beq     _80035b78
_80035b04:
    clrlwi	r3, r3, 0x10
    cmplwi	r3, 1
    ble     _80035b18
    srawi	r6, r11, 1
    b       _80035b1c
_80035b18:
    li	r6, 1
_80035b1c:
    clrlwi	r3, r4, 0x10
    cmplwi	r3, 1
    clrlwi	r3, r6, 0x10
    ble     _80035b34
    srawi	r4, r12, 1
    b       _80035b38
_80035b34:
    li	r4, 1
_80035b38:
    clrlwi	r4, r4, 0x10
    bdnz    _80035ad0
    b       _80035b78
_80035b44:
    li	r6, 1
    slw	r7, r6, r0
    slw	r6, r6, r8
    clrlwi	r9, r3, 0x10
    addi	r3, r7, -1
    add	r7, r9, r3
    clrlwi	r4, r4, 0x10
    addi	r3, r6, -1
    sraw	r6, r7, r0
    add	r0, r4, r3
    sraw	r0, r0, r8
    mullw	r0, r6, r0
    mullw	r31, r5, r0
_80035b78:
    mr	r3, r31
    lwz	r31, 0x24(r1)
    addi	r1, r1, 0x28
    blr	
}

asm void __GXGetTexTileSize(register void* p1, register void* p2, register int id, register void* p4)
{
    nofralloc
    cmplwi	r3, 0x3c
    bgt     _80035bcc
    lis     r9, -0x7fed
    addi	r9, r9, -0x4dcc
    slwi	r0, r3, 2
    lwzx	r0, r9, r0
    mtctr	r0
    bctr	
    li	r11, 3
    li	r12, 3
    b       _80035bd4
    li	r11, 3
    li	r12, 2
    b       _80035bd4
    li	r11, 2
    li	r12, 2
    b       _80035bd4
_80035bcc:
    li	r12, 0
    li	r11, 0
_80035bd4:
    clrlwi.	r0, r4, 0x10
    bne     _80035be0
    li	r4, 1
_80035be0:
    clrlwi.	r0, r5, 0x10
    bne     _80035bec
    li	r5, 1
_80035bec:
    li	r10, 1
    slw	r9, r10, r11
    clrlwi	r4, r4, 0x10
    addi	r0, r9, -1
    add	r0, r4, r0
    sraw	r0, r0, r11
    slw	r4, r10, r12
    stw	r0, 0(r6)
    clrlwi	r5, r5, 0x10
    addi	r0, r4, -1
    add	r0, r5, r0
    sraw	r0, r0, r12
    cmpwi	r3, 6
    stw	r0, 0(r7)
    beq     _80035c34
    cmpwi	r3, 0x16
    beq     _80035c34
    li	r10, 0
_80035c34:
    cmpwi	r10, 0
    beq     _80035c44
    li	r0, 2
    b       _80035c48
_80035c44:
    li	r0, 1
_80035c48:
    stw	r0, 0(r8)
    blr	
}

asm void GXInitTexObj(register void* p1, register int a, register int b)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x60(r1)
    stmw	r24, 0x40(r1)
    addi	r27, r4, 0
    addi	r28, r5, 0
    addi	r31, r3, 0
    addi	r29, r6, 0
    addi	r30, r7, 0
    addi	r24, r8, 0
    addi	r25, r9, 0
    addi	r26, r10, 0
    li	r4, 0
    li	r5, 0x20
    bl      memset
    lwz	r4, 0(r31)
    clrlwi.	r0, r26, 0x18
    slwi	r3, r25, 2
    rlwinm	r4, r4, 0, 0, 0x1d
    or	r4, r4, r24
    stw	r4, 0(r31)
    lwz	r0, 0(r31)
    rlwinm	r0, r0, 0, 0x1e, 0x1b
    or	r0, r0, r3
    stw	r0, 0(r31)
    lwz	r0, 0(r31)
    rlwinm	r0, r0, 0, 0x1c, 0x1a
    ori	r0, r0, 0x10
    stw	r0, 0(r31)
    beq     _80035d68
    lbz	r3, 0x1f(r31)
    addi	r0, r30, -8
    cmplwi	r0, 2
    ori	r0, r3, 1
    stb	r0, 0x1f(r31)
    bgt     _80035cf4
    lwz	r0, 0(r31)
    rlwinm	r0, r0, 0, 0x1b, 0x17
    ori	r0, r0, 0xa0
    stw	r0, 0(r31)
    b       _80035d04
_80035cf4:
    lwz	r0, 0(r31)
    rlwinm	r0, r0, 0, 0x1b, 0x17
    ori	r0, r0, 0xc0
    stw	r0, 0(r31)
_80035d04:
    clrlwi	r3, r28, 0x10
    clrlwi	r0, r29, 0x10
    cmplw	r3, r0
    ble     _80035d20
    cntlzw	r0, r3
    subfic	r0, r0, 0x1f
    b       _80035d28
_80035d20:
    cntlzw	r0, r0
    subfic	r0, r0, 0x1f
_80035d28:
    stw	r0, 0x3c(r1)
    lis	r0, 0x4330
    lwz	r3, 4(r31)
    stw	r0, 0x38(r1)
    lfd	f1, -0x7d80(r2)
    rlwinm	r3, r3, 0, 0x18, 0xf
    lfd	f0, 0x38(r1)
    lfs	f2, -0x7d88(r2)
    fsubs	f0, f0, f1
    fmuls	f0, f2, f0
    fctiwz	f0, f0
    stfd	f0, 0x30(r1)
    lwz	r0, 0x34(r1)
    rlwimi	r3, r0, 8, 0x10, 0x17
    stw	r3, 4(r31)
    b       _80035d78
_80035d68:
    lwz	r0, 0(r31)
    rlwinm	r0, r0, 0, 0x1b, 0x17
    ori	r0, r0, 0x80
    stw	r0, 0(r31)
_80035d78:
    stw	r30, 0x14(r31)
    clrlwi	r3, r29, 0x10
    clrlwi	r7, r30, 0x1c
    lwz	r5, 8(r31)
    clrlwi	r4, r28, 0x10
    addi	r0, r3, -1
    rlwinm	r6, r5, 0, 0, 0x15
    addi	r5, r4, -1
    or	r5, r6, r5
    stw	r5, 8(r31)
    slwi	r5, r0, 0xa
    rlwinm	r0, r27, 0x1b, 7, 0x1f
    lwz	r6, 8(r31)
    cmplwi	r7, 0xe
    rlwinm	r6, r6, 0, 0x16, 0xb
    or	r5, r6, r5
    stw	r5, 8(r31)
    lwz	r5, 8(r31)
    rlwinm	r5, r5, 0, 0xc, 7
    rlwimi	r5, r30, 0x14, 8, 0xb
    stw	r5, 8(r31)
    lwz	r5, 0xc(r31)
    rlwinm	r5, r5, 0, 0, 0xa
    or	r0, r5, r0
    stw	r0, 0xc(r31)
    bgt     _80035e5c
    lis     r5, -0x7fed
    addi	r5, r5, -0x4cd8
    slwi	r0, r7, 2
    lwzx	r0, r5, r0
    mtctr	r0
    bctr	
    li	r0, 1
    stb	r0, 0x1e(r31)
    li	r0, 3
    li	r7, 3
    b       _80035e6c
    li	r0, 2
    stb	r0, 0x1e(r31)
    li	r0, 3
    li	r7, 2
    b       _80035e6c
    li	r0, 2
    stb	r0, 0x1e(r31)
    li	r0, 2
    li	r7, 2
    b       _80035e6c
    li	r0, 3
    stb	r0, 0x1e(r31)
    li	r0, 2
    li	r7, 2
    b       _80035e6c
    li	r0, 0
    stb	r0, 0x1e(r31)
    li	r0, 3
    li	r7, 3
    b       _80035e6c
_80035e5c:
    li	r0, 2
    stb	r0, 0x1e(r31)
    li	r0, 2
    li	r7, 2
_80035e6c:
    clrlwi	r8, r0, 0x10
    li	r6, 1
    slw	r5, r6, r8
    clrlwi	r7, r7, 0x10
    addi	r0, r5, -1
    slw	r5, r6, r7
    add	r4, r4, r0
    addi	r0, r5, -1
    sraw	r4, r4, r8
    add	r0, r3, r0
    sraw	r0, r0, r7
    mullw	r0, r4, r0
    clrlwi	r0, r0, 0x11
    sth	r0, 0x1c(r31)
    lbz	r0, 0x1f(r31)
    ori	r0, r0, 2
    stb	r0, 0x1f(r31)
    lwz	r0, 0x64(r1)
    lmw	r24, 0x40(r1)
    addi	r1, r1, 0x60
    mtlr	r0
    blr	
}

asm void fn_80035EC4(register void* p1, register void* p2, register int id, register void* p4)
{
    nofralloc
    stwu	r1, -0x38(r1)
    lfs	f0, -0x7d78(r2)
    fcmpo	cr0, f3, f0
    bge     _80035edc
    fmr	f3, f0
    b       _80035ef0
_80035edc:
    lfs	f0, -0x7d74(r2)
    fcmpo	cr0, f3, f0
    cror	2, 1, 2
    bne     _80035ef0
    lfs	f3, -0x7d70(r2)
_80035ef0:
    lfs	f0, -0x7d6c(r2)
    cmpwi	r5, 1
    lwz	r0, 0(r3)
    fmuls	f0, f0, f3
    rlwinm	r5, r0, 0, 0x17, 0xe
    fctiwz	f0, f0
    stfd	f0, 0x30(r1)
    lwz	r0, 0x34(r1)
    rlwimi	r5, r0, 9, 0xf, 0x16
    stw	r5, 0(r3)
    bne     _80035f24
    li	r5, 1
    b       _80035f28
_80035f24:
    li	r5, 0
_80035f28:
    lwz	r9, 0(r3)
    clrlwi.	r0, r7, 0x18
    slwi	r5, r5, 4
    rlwinm	r7, r9, 0, 0x1c, 0x1a
    or	r5, r7, r5
    stw	r5, 0(r3)
    addi	r5, r13, -0x7e50
    lbzx	r0, r5, r4
    lwz	r7, 0(r3)
    slwi	r0, r0, 5
    rlwinm	r4, r7, 0, 0x1b, 0x17
    or	r0, r4, r0
    stw	r0, 0(r3)
    beq     _80035f68
    li	r0, 0
    b       _80035f6c
_80035f68:
    li	r0, 1
_80035f6c:
    lwz	r4, 0(r3)
    slwi	r0, r0, 8
    rlwinm	r4, r4, 0, 0x18, 0x16
    or	r0, r4, r0
    stw	r0, 0(r3)
    slwi	r4, r8, 0x13
    rlwinm	r0, r6, 0x15, 3, 0xa
    lwz	r5, 0(r3)
    rlwinm	r5, r5, 0, 0xf, 0xd
    stw	r5, 0(r3)
    lwz	r5, 0(r3)
    rlwinm	r5, r5, 0, 0xe, 0xc
    stw	r5, 0(r3)
    lwz	r5, 0(r3)
    rlwinm	r5, r5, 0, 0xd, 0xa
    or	r4, r5, r4
    stw	r4, 0(r3)
    lwz	r4, 0(r3)
    rlwinm	r4, r4, 0, 0xb, 9
    or	r0, r4, r0
    stw	r0, 0(r3)
    lfs	f0, -0x7d68(r2)
    fcmpo	cr0, f1, f0
    bge     _80035fd4
    fmr	f1, f0
    b       _80035fe4
_80035fd4:
    lfs	f0, -0x7d64(r2)
    fcmpo	cr0, f1, f0
    ble     _80035fe4
    fmr	f1, f0
_80035fe4:
    lfs	f3, -0x7d88(r2)
    lfs	f0, -0x7d68(r2)
    fmuls	f1, f3, f1
    fcmpo	cr0, f2, f0
    fctiwz	f1, f1
    stfd	f1, 0x30(r1)
    lwz	r4, 0x34(r1)
    bge     _8003600c
    fmr	f2, f0
    b       _8003601c
_8003600c:
    lfs	f0, -0x7d64(r2)
    fcmpo	cr0, f2, f0
    ble     _8003601c
    fmr	f2, f0
_8003601c:
    lwz	r0, 4(r3)
    rlwinm	r0, r0, 0, 0, 0x17
    rlwimi	r0, r4, 0, 0x18, 0x1f
    stw	r0, 4(r3)
    lfs	f0, -0x7d88(r2)
    lwz	r0, 4(r3)
    fmuls	f0, f0, f2
    rlwinm	r4, r0, 0, 0x18, 0xf
    fctiwz	f0, f0
    stfd	f0, 0x30(r1)
    lwz	r0, 0x34(r1)
    rlwimi	r4, r0, 8, 0x10, 0x17
    stw	r4, 4(r3)
    addi	r1, r1, 0x38
    blr	
}

asm void fn_80036058(register void* p)
{
    nofralloc
    lwz	r5, 0xc(r3)
    rlwinm	r0, r4, 0x1b, 7, 0x1f
    rlwinm	r4, r5, 0, 0, 0xa
    or	r0, r4, r0
    stw	r0, 0xc(r3)
    blr	
}


#pragma pop
