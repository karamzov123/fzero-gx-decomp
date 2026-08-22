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
extern void fn_80032B8C(void);
extern void fn_80033650(void);
extern void fn_80032BE0(void);
extern void fn_80035B88(void);
extern void fn_80079764(void);

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
        fn_80032B8C();
    if (gx->dirtyState & 0x10)
        fn_80033650();
    if (gx->dirtyState & 0x18)
        fn_80032BE0();
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
    bl      fn_80032B8C
_800346a8:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x4f4(r3)
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    beq     _800346bc
    bl      fn_80033650
_800346bc:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x4f4(r3)
    rlwinm.	r0, r0, 0, 0x1b, 0x1c
    beq     _800346d0
    bl      fn_80032BE0
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

asm void fn_80034834(register s32 tc, register s32 a, register s32 b)
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

asm void fn_800348DC(register s32 arg)
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

asm void fn_80034A5C(register int xl, register int yt, register int xr, register int yb)
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

asm void fn_80034AEC(register int xl, register int yt, register int xr, register int yb)
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

asm void fn_80034B7C(register int arg)
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

asm void fn_80034BB8(register void* p1, register void* p2, register int id, register void* p4)
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
    bl      fn_80035B88
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

asm void fn_80034D0C(register int arg)
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

asm void fn_80034D34(register int a, register int b, register int c)
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
    bl      fn_80079764
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

asm void fn_80034E64(register int a, register int b, register int c)
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

asm void fn_80034ECC(register void* p1, register void* p2, register int id, register void* p4)
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

asm void fn_800350F4(register int idx)
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

#pragma pop
