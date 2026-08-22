typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef long long s64;
typedef int BOOL;
typedef u64 OSTime;

#define NULL ((void *)0)
#define FALSE 0
#define TRUE 1
#define OSPhysicalToUncached(p) ((void *)((u32)(p) + 0xC0000000))
#define SET_REG_FIELD(line, reg, size, pos, val) \
    ((reg) = (((u32)(reg)) & ~((((1 << (size)) - 1)) << (pos))) | ((u32)(val) << (pos)))
#define GET_REG_FIELD(reg, size, pos) (((reg) >> (pos)) & ((1 << (size)) - 1))
#define GXWGFifo ((volatile __GXFifoInt *)0xCC008000)
#define GX_WRITE_RAS_REG(reg)       \
    do {                            \
        GXWGFifo->u8 = 0x61;        \
        GXWGFifo->u32 = (u32)(reg); \
    } while (0)

typedef volatile struct GXData {
    u16 unk;
    u16 bpSent;
    u16 vNum;
    u8 pad[0x4F1 - 0x6];
    u8 field4F1;
    u8 field4F2;
    u32 dirtyState;
} GXData;

typedef struct OSContext {
    u64 dummy[0x59];
} OSContext;

typedef unsigned char GXBool;
typedef enum { GX_COMPARE_NEVER = 0, GX_COMPARE_LESS, GX_COMPARE_EQUAL, GX_COMPARE_GREATER, GX_COMPARE_LEQUAL, GX_COMPARE_GEQUAL, GX_COMPARE_ALWAYS = 7 } GXCompare;
typedef enum { GX_READ_00 = 0, GX_READ_FF, GX_READ_ZB, GX_READ_NA } GXAlphaReadMode;
typedef enum { GX_BM_NONE = 0, GX_BM_BLEND, GX_BM_LOGIC, GX_BM_SUBTRACT } GXBlendMode;
typedef enum { GX_BL_ZERO = 0, GX_BL_ONE, GX_BL_SRCCLR, GX_BL_INVSRCCLR, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_BL_DSTALPHA, GX_BL_INVDSTALPHA, GX_BL_DSTCLR, GX_BL_INVDSTCLR } GXBlendFactor;
typedef enum { GX_LO_CLEAR = 0, GX_LO_SET, GX_LO_COPY, GX_LO_ANDINV, GX_LO_INVAND, GX_LO_AND, GX_LO_EQUIV, GX_LO_OR, GX_LO_XOR, GX_LO_NOR, GX_LO_NOTXOR, GX_LO_INVOR, GX_LO_INVINVOR, GX_LO_INV } GXLogicOp;
typedef void (*GXDrawSyncCallback)(u16 token);
typedef void (*GXDrawDoneCallback)(void);

typedef enum {
    GX_MT_NULL = 0,
    GX_MT_XF_FLUSH,
    GX_MT_DL_SAVE_CONTEXT,
    GX_MT_ABORT_CLEAN_FIFO
} GXMiscToken;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
} __GXFifoInt;

extern GXData *const gx;
extern u16 *__peReg;
extern u16 *__memReg;
extern void PPCSync(void);
extern u32 PPCMfwpar(void);
extern void PPCMtwpar(u32 addr);
extern BOOL OSDisableInterrupts(void);
extern void OSRestoreInterrupts(BOOL level);
extern u64 OSGetTime(void);
extern void OSClearContext(OSContext *context);
extern void OSSetCurrentContext(OSContext *context);
typedef struct OSThreadQueue {
    void *head;
    void *tail;
    void *pad;
} OSThreadQueue;
extern void OSInitThreadQueue(OSThreadQueue *queue);
extern void OSSleepThread(OSThreadQueue *queue);
extern void OSWakeupThread(OSThreadQueue *queue);
extern void *GXGetGPFifo(void);
extern void fn_8003458C(void);

#pragma push
#pragma force_active on

extern GXDrawSyncCallback TokenCB;
extern GXDrawDoneCallback DrawDoneCB;
extern u8 DrawDone;
extern u64 FinishQueue;

static inline void __GXAbortWait(u32 clocks)
{
    OSTime time0;
    OSTime time1;

    time0 = OSGetTime();
    do {
        time1 = OSGetTime();
    } while (time1 - time0 <= clocks / 4U);
}

void GXSetMisc(GXMiscToken token, u32 val)
{
    switch (token) {
    case GX_MT_NULL:
        break;
    case GX_MT_XF_FLUSH:
        gx->vNum = val;
        gx->unk = !gx->vNum;
        gx->bpSent = 1;
        if (gx->vNum != 0) {
            gx->dirtyState |= 8;
        }
        break;
    case GX_MT_DL_SAVE_CONTEXT:
        gx->field4F1 = (val != 0);
        break;
    case GX_MT_ABORT_CLEAN_FIFO:
        gx->field4F2 = (val != 0);
        break;
    default:
        break;
    }
}

void GXFlush(void)
{
    u32 i;

    if (gx->dirtyState != 0) {
        fn_8003458C();
    }
    for (i = 8; i > 0; i--) {
        GXWGFifo->u32 = 0;
    }
    PPCSync();
}

void GXResetWriteGatherPipe(void)
{
    while (PPCMfwpar() & 1) {
    }
    PPCMtwpar(0x0C008000);
}





void GXPokeAlphaMode(GXCompare func, u8 threshold)
{
    u32 reg;

    reg = (func << 8) | threshold;
    __peReg[3] = reg;
}

void GXPokeAlphaRead(GXAlphaReadMode mode)
{
    u32 reg = mode;

    SET_REG_FIELD(0x26E, reg, 1, 2, 1);
    __peReg[4] = reg;
}

void GXPokeAlphaUpdate(GXBool update_enable)
{
    u32 reg;

    reg = __peReg[1];
    SET_REG_FIELD(0x27A, reg, 1, 4, update_enable);
    __peReg[1] = reg;
}

void GXPokeBlendMode(GXBlendMode type, GXBlendFactor src_factor, GXBlendFactor dst_factor, GXLogicOp op)
{
    u32 reg;

    reg = __peReg[1];
    SET_REG_FIELD(0x28C, reg, 1, 0, (type == GX_BM_BLEND) || (type == GX_BM_SUBTRACT));
    SET_REG_FIELD(0x28D, reg, 1, 11, (type == GX_BM_SUBTRACT));
    SET_REG_FIELD(0x28F, reg, 1, 1, (type == GX_BM_LOGIC));
    SET_REG_FIELD(0x290, reg, 4, 12, op);
    SET_REG_FIELD(0x291, reg, 3, 8, src_factor);
    SET_REG_FIELD(0x292, reg, 3, 5, dst_factor);
    SET_REG_FIELD(0x293, reg, 8, 24, 0x41);
    __peReg[1] = reg;
}

void GXPokeColorUpdate(GXBool update_enable)
{
    u32 reg;

    reg = __peReg[1];
    SET_REG_FIELD(0x2A0, reg, 1, 3, update_enable);
    __peReg[1] = reg;
}

void GXPokeDstAlpha(GXBool enable, u8 alpha)
{
    __peReg[2] = alpha | ((u32)enable << 8);
}

void GXPokeDither(GXBool dither)
{
    u32 reg;

    reg = __peReg[1];
    SET_REG_FIELD(0x2B8, reg, 1, 2, dither);
    __peReg[1] = reg;
}

void GXPokeZMode(GXBool compare_enable, GXCompare func, GXBool update_enable)
{
    u32 reg;

    reg = compare_enable;
    SET_REG_FIELD(0x2C4, reg, 3, 1, func);
    SET_REG_FIELD(0x2C5, reg, 1, 4, update_enable);
    __peReg[0] = reg;
}

void GXPeekARGB(u16 x, u16 y, u32 *color)
{
    u32 addr = (u32)OSPhysicalToUncached(0x08000000);

    SET_REG_FIELD(0x2DC, addr, 10, 2, x);
    SET_REG_FIELD(0x2DD, addr, 10, 12, y);
    SET_REG_FIELD(0x2DE, addr, 2, 22, 0);
    *color = *(u32 *)addr;
}

void GXPeekZ(u16 x, u16 y, u32 *z)
{
    u32 addr = (u32)OSPhysicalToUncached(0x08000000);

    SET_REG_FIELD(0x2F0, addr, 10, 2, x);
    SET_REG_FIELD(0x2F1, addr, 10, 12, y);
    SET_REG_FIELD(0x2F2, addr, 2, 22, 1);
    *z = *(u32 *)addr;
}

GXDrawSyncCallback GXSetDrawSyncCallback(GXDrawSyncCallback cb)
{
    GXDrawSyncCallback oldcb;
    BOOL enabled;

    oldcb = TokenCB;
    enabled = OSDisableInterrupts();
    TokenCB = cb;
    OSRestoreInterrupts(enabled);
    return oldcb;
}

static void GXTokenInterruptHandler(s32 interrupt, OSContext *context)
{
    OSContext exceptionContext;
    u32 reg;
    u16 token;

    token = __peReg[7];
    if (TokenCB != NULL) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        TokenCB(token);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
    reg = __peReg[5];
    SET_REG_FIELD(0, reg, 1, 2, 1);
    __peReg[5] = reg;
}

GXDrawDoneCallback GXSetDrawDoneCallback(GXDrawDoneCallback cb)
{
    GXDrawDoneCallback oldcb;
    BOOL enabled;

    oldcb = DrawDoneCB;
    enabled = OSDisableInterrupts();
    DrawDoneCB = cb;
    OSRestoreInterrupts(enabled);
    return oldcb;
}

static void GXFinishInterruptHandler(s32 interrupt, OSContext *context)
{
    OSContext exceptionContext;
    u32 reg;

    reg = __peReg[5];
    SET_REG_FIELD(0, reg, 1, 3, 1);
    __peReg[5] = reg;
    DrawDone = TRUE;
    if (DrawDoneCB != NULL) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        DrawDoneCB();
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
    OSWakeupThread((OSThreadQueue *)&FinishQueue);
}

void __GXPEInit(void)
{
    u32 reg;

    __OSSetInterruptHandler(0x12, GXTokenInterruptHandler);
    __OSSetInterruptHandler(0x13, GXFinishInterruptHandler);
    OSInitThreadQueue((OSThreadQueue *)&FinishQueue);
    __OSUnmaskInterrupts(0x2000);
    __OSUnmaskInterrupts(0x1000);
    reg = __peReg[5];
    SET_REG_FIELD(0, reg, 1, 2, 1);
    SET_REG_FIELD(0, reg, 1, 3, 1);
    SET_REG_FIELD(0, reg, 1, 0, 1);
    SET_REG_FIELD(0, reg, 1, 1, 1);
    __peReg[5] = reg;
}
asm void GXAbortFrame(void)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x28(r1)
    stmw    r27, 0x14(r1)
    lwz     r3, 0x8218(r2) /* gx */
    lbz     r0, 0x4f2(r3)
    cmplwi  r0, 0
    beq     GXAF_done
    bl      GXGetGPFifo
    cmplwi  r3, 0
    beq     GXAF_done
    lwz     r3, 0x8814(r13) /* __memReg */
    addi    r6, r3, 0x4e
    lhz     r4, 0x4e(r3)
    addi    r5, r3, 0x50
GXAF_poll1:
    mr      r0, r4
    lhz     r4, 0(r6)
    lhz     r3, 0(r5)
    cmplw   r4, r0
    bne     GXAF_poll1
    slwi    r0, r4, 16
    or      r27, r0, r3
GXAF_outer:
    bl      OSGetTime
    li      r0, 0
    addi    r31, r4, 0
    addi    r30, r3, 0
    xoris   r28, r0, 0x8000
    li      r29, 8
GXAF_wait1:
    bl      OSGetTime
    subfc   r4, r31, r4
    subfe   r0, r30, r3
    xoris   r3, r0, 0x8000
    subfc   r0, r4, r29
    subfe   r3, r3, r28
    subfe   r3, r28, r28
    neg.    r3, r3
    beq     GXAF_wait1
    lwz     r3, 0x8814(r13) /* __memReg */
    addi    r6, r3, 0x4e
    lhz     r4, 0x4e(r3)
    addi    r5, r3, 0x50
GXAF_poll2:
    mr      r0, r4
    lhz     r4, 0(r6)
    lhz     r3, 0(r5)
    cmplw   r4, r0
    bne     GXAF_poll2
    slwi    r0, r4, 16
    or      r0, r0, r3
    cmplw   r0, r27
    mr      r27, r0
    bne     GXAF_outer
GXAF_done:
    lis     r3, 0xcc00
    li      r0, 0x1
    addi    r27, r3, 0x3000
    stwu    r0, 0x18(r27)
    bl      OSGetTime
    li      r0, 0
    addi    r31, r4, 0
    addi    r30, r3, 0
    xoris   r28, r0, 0x8000
    li      r29, 0x32
GXAF_wait2:
    bl      OSGetTime
    subfc   r4, r31, r4
    subfe   r0, r30, r3
    xoris   r3, r0, 0x8000
    subfc   r0, r4, r29
    subfe   r3, r3, r28
    subfe   r3, r28, r28
    neg.    r3, r3
    beq     GXAF_wait2
    li      r30, 0
    stw     r30, 0(r27)
    bl      OSGetTime
    addi    r28, r4, 0
    addi    r29, r3, 0
    xoris   r31, r30, 0x8000
    li      r30, 5
GXAF_wait3:
    bl      OSGetTime
    subfc   r4, r28, r4
    subfe   r0, r29, r3
    xoris   r3, r0, 0x8000
    subfc   r0, r4, r30
    subfe   r3, r3, r31
    subfe   r3, r31, r31
    neg.    r3, r3
    beq     GXAF_wait3
    lmw     r27, 0x14(r1)
    lwz     r0, 0x2c(r1)
    addi    r1, r1, 0x28
    mtlr    r0
    blr
}

asm void GXSetDrawSync(u16 token)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    stw     r30, 0x10(r1)
    mr      r30, r3
    bl      OSDisableInterrupts
    li      r6, 0x61
    lwz     r4, 0x8218(r2) /* gx */
    lis     r5, 0xcc01
    clrlwi  r0, r30, 16
    stb     r6, -0x8000(r5)
    oris    r0, r0, 0x4800
    stw     r0, -0x8000(r5)
    clrrwi  r0, r0, 16
    rlwimi  r0, r30, 0, 16, 31
    clrlwi  r0, r0, 8
    stb     r6, -0x8000(r5)
    oris    r0, r0, 0x4700
    stw     r0, -0x8000(r5)
    mr      r30, r3
    lwz     r0, 0x4f4(r4)
    cmplwi  r0, 0
    beq     GXDS_skip
    bl      fn_8003458C
GXDS_skip:
    li      r31, 0
    lis     r3, 0xcc01
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    bl      PPCSync
    mr      r3, r30
    bl      OSRestoreInterrupts
    lwz     r3, 0x8218(r2) /* gx */
    sth     r31, 0x2(r3)
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

asm void GXSetDrawDone(void)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    stw     r30, 0x10(r1)
    bl      OSDisableInterrupts
    li      r0, 0x61
    lwz     r4, 0x8218(r2) /* gx */
    lis     r6, 0xcc01
    lis     r5, 0x4500
    stb     r0, -0x8000(r6)
    addi    r0, r5, 0x2
    stw     r0, -0x8000(r6)
    mr      r30, r3
    lwz     r0, 0x4f4(r4)
    cmplwi  r0, 0
    beq     GXDD_skip
    bl      fn_8003458C
GXDD_skip:
    li      r31, 0
    lis     r3, 0xcc01
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    stw     r31, -0x8000(r3)
    bl      PPCSync
    stb     r31, 0x8858(r13) /* DrawDone */
    mr      r3, r30
    bl      OSRestoreInterrupts
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

asm void GXDrawDone(void)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    bl      OSDisableInterrupts
    li      r0, 0x61
    lis     r5, 0xcc01
    lis     r4, 0x4500
    stb     r0, -0x8000(r5)
    addi    r0, r4, 0x2
    stw     r0, -0x8000(r5)
    mr      r31, r3
    bl      GXFlush
    li      r0, 0
    stb     r0, 0x8858(r13) /* DrawDone */
    mr      r3, r31
    bl      OSRestoreInterrupts
    bl      OSDisableInterrupts
    mr      r31, r3
    b       GXDD_check
GXDD_sleep:
    addi    r3, r13, 0x885c /* FinishQueue */
    bl      OSSleepThread
GXDD_check:
    lbz     r0, 0x8858(r13) /* DrawDone */
    cmplwi  r0, 0
    beq     GXDD_sleep
    mr      r3, r31
    bl      OSRestoreInterrupts
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}

#pragma pop
