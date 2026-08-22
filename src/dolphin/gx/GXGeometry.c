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

#pragma pop
