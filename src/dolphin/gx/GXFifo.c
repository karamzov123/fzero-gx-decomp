typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef int BOOL;

typedef struct __GXFifoObj {
    u8 *base;
    u8 *top;
    u32 size;
    u32 hiWatermark;
    u32 loWatermark;
    void *rdPtr;
    void *wrPtr;
    s32 count;
} __GXFifoObj;

typedef struct GXData {
    u8 pad[8];
    u32 cpEnable;
    u32 cpStatus;
    u32 cpClr;
} GXData;

typedef void GXFifoObj;
typedef void *GXBreakPtCallback;

#define OSPhysicalToCached(p) ((void *)((u32)(p) + 0x80000000))
#define GET_REG_FIELD(reg, size, pos) (((reg) >> (pos)) & ((1 << (size)) - 1))
#define NULL ((void *)0)
#define FALSE 0
#define TRUE 1

extern BOOL OSDisableInterrupts(void);
extern void OSRestoreInterrupts(BOOL level);
extern void PPCSync(void);
extern u32 *__piReg;
extern u16 *__cpReg;
extern GXData *const gx;
extern struct __GXFifoObj *CPUFifo;
extern struct __GXFifoObj *GPFifo;
extern void *__GXCurrentThread;
extern BOOL GXOverflowSuspendInProgress;
extern u8 CPGPLinked;
extern GXBreakPtCallback BreakPointCB;
extern void fn_80033E20(void);
extern void *fn_800102AC(void);
extern void fn_80031B50(int interrupt, void *context);
typedef void (*__OSInterruptHandler)(int interrupt, void *context);
extern __OSInterruptHandler __OSSetInterruptHandler(short interrupt, __OSInterruptHandler handler);
extern u32 __OSUnmaskInterrupts(u32 mask);
extern void GXInitFifoLimits(GXFifoObj *fifo, u32 hiWatermark, u32 loWatermark);
extern void GXInitFifoPtrs(GXFifoObj *fifo, void *readPtr, void *writePtr);
extern void __GXSaveCPUFifoAux(__GXFifoObj *realFifo);

#pragma push
#pragma force_active on

void GXInitFifoBase(GXFifoObj *fifo, void *base, u32 size)
{
    __GXFifoObj *realFifo = (__GXFifoObj *)fifo;
    u8 *top = (u8 *)base + size - 4;

    realFifo->base = base;
    realFifo->top = top;
    realFifo->size = size;
    realFifo->count = 0;
    GXInitFifoLimits(fifo, size - 0x4000, (size >> 1) & ~0x1F);
    GXInitFifoPtrs(fifo, base, base);
}

#pragma dont_inline on
void GXInitFifoPtrs(GXFifoObj *fifo, void *readPtr, void *writePtr)
{
    __GXFifoObj *realFifo = (__GXFifoObj *)fifo;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    realFifo->rdPtr = readPtr;
    realFifo->wrPtr = writePtr;
    realFifo->count = (u8 *)writePtr - (u8 *)readPtr;
    if (realFifo->count < 0) {
        realFifo->count += realFifo->size;
    }
    OSRestoreInterrupts(enabled);
}

void GXInitFifoLimits(GXFifoObj *fifo, u32 hiWatermark, u32 loWatermark)
{
    __GXFifoObj *realFifo = (__GXFifoObj *)fifo;

    realFifo->hiWatermark = hiWatermark;
    realFifo->loWatermark = loWatermark;
}

void GXSetCPUFifo(GXFifoObj *fifo)
{
    __GXFifoObj *realFifo = (__GXFifoObj *)fifo;
    BOOL enabled;
    u32 reg;

    enabled = OSDisableInterrupts();
    CPUFifo = realFifo;
    if (CPUFifo == GPFifo) {
        __piReg[3] = (u32)realFifo->base & 0x3FFFFFFF;
        __piReg[4] = (u32)realFifo->top & 0x3FFFFFFF;
        reg = (u32)realFifo->wrPtr & 0x3FFFFFE0;
        reg &= 0xFBFFFFFF;
        __piReg[5] = reg;
        CPGPLinked = TRUE;
        __GXWriteFifoIntReset(1, 1);
        __GXWriteFifoIntEnable(1, 0);
        __GXFifoLink(1);
    } else {
        if (CPGPLinked) {
            __GXFifoLink(0);
            CPGPLinked = FALSE;
        }
        __GXWriteFifoIntEnable(0, 0);
        __piReg[3] = (u32)realFifo->base & 0x3FFFFFFF;
        __piReg[4] = (u32)realFifo->top & 0x3FFFFFFF;
        reg = (u32)realFifo->wrPtr & 0x3FFFFFE0;
        reg &= 0xFBFFFFFF;
        __piReg[5] = reg;
    }

    PPCSync();

    OSRestoreInterrupts(enabled);
}

void GXSetGPFifo(GXFifoObj *fifo)
{
    __GXFifoObj *realFifo = (__GXFifoObj *)fifo;
    BOOL enabled;

    enabled = OSDisableInterrupts();

    __GXFifoReadDisable();
    __GXWriteFifoIntEnable(0, 0);
    GPFifo = realFifo;

    __cpReg[16] = (u32)realFifo->base & 0xFFFF;
    __cpReg[18] = (u32)realFifo->top & 0xFFFF;
    __cpReg[24] = realFifo->count & 0xFFFF;
    __cpReg[26] = (u32)realFifo->wrPtr & 0xFFFF;
    __cpReg[28] = (u32)realFifo->rdPtr & 0xFFFF;
    __cpReg[20] = (u32)realFifo->hiWatermark & 0xFFFF;
    __cpReg[22] = (u32)realFifo->loWatermark & 0xFFFF;
    __cpReg[17] = ((u32)realFifo->base & 0x3FFFFFFF) >> 16;
    __cpReg[19] = ((u32)realFifo->top & 0x3FFFFFFF) >> 16;
    __cpReg[25] = realFifo->count >> 16;
    __cpReg[27] = ((u32)realFifo->wrPtr & 0x3FFFFFFF) >> 16;
    __cpReg[29] = ((u32)realFifo->rdPtr & 0x3FFFFFFF) >> 16;
    __cpReg[21] = (u32)realFifo->hiWatermark >> 16;
    __cpReg[23] = (u32)realFifo->loWatermark >> 16;

    PPCSync();

    if (CPUFifo == GPFifo) {
        CPGPLinked = TRUE;
        __GXWriteFifoIntEnable(1, 0);
        __GXFifoLink(1);
    } else {
        CPGPLinked = FALSE;
        __GXWriteFifoIntEnable(0, 0);
        __GXFifoLink(0);
    }
    __GXWriteFifoIntReset(1, 1);
    __GXFifoReadEnable();
    OSRestoreInterrupts(enabled);
}

void GXSaveCPUFifo(GXFifoObj *fifo)
{
    __GXSaveCPUFifoAux((__GXFifoObj *)fifo);
}

#pragma dont_inline on
void __GXSaveCPUFifoAux(__GXFifoObj *realFifo)
{
    BOOL enabled = OSDisableInterrupts();

    fn_80033E20();
    realFifo->base = OSPhysicalToCached(__piReg[3]);
    realFifo->top = OSPhysicalToCached(__piReg[4]);
    realFifo->wrPtr = OSPhysicalToCached(__piReg[5] & 0xFBFFFFFF);
    if (CPGPLinked) {
        u32 temp = (__cpReg[29] << 16) | __cpReg[28];
        realFifo->rdPtr = OSPhysicalToCached(temp);
        temp = (__cpReg[25] << 16) | __cpReg[24];
        realFifo->count = temp;
    } else {
        realFifo->count = (u8 *)realFifo->wrPtr - (u8 *)realFifo->rdPtr;
        if (realFifo->count < 0) {
            realFifo->count += realFifo->size;
        }
    }
    OSRestoreInterrupts(enabled);
}

void GXGetGPStatus(u8 *overhi, u8 *underlow, u8 *readIdle, u8 *cmdIdle, u8 *brkpt)
{
    gx->cpStatus = __cpReg[0];
    *overhi = GET_REG_FIELD(gx->cpStatus, 1, 0);
    *underlow = GET_REG_FIELD(gx->cpStatus, 1, 1);
    *readIdle = GET_REG_FIELD(gx->cpStatus, 1, 2);
    *cmdIdle = GET_REG_FIELD(gx->cpStatus, 1, 3);
    *brkpt = GET_REG_FIELD(gx->cpStatus, 1, 4);
}

void GXGetFifoPtrs(GXFifoObj *fifo, void **readPtr, void **writePtr)
{
    __GXFifoObj *realFifo = (__GXFifoObj *)fifo;

    if (realFifo == CPUFifo) {
        realFifo->wrPtr = OSPhysicalToCached(__piReg[5] & 0xFBFFFFFF);
    }
    if (realFifo == GPFifo) {
        u32 temp = (__cpReg[29] << 16) | __cpReg[28];
        realFifo->rdPtr = OSPhysicalToCached(temp);
        temp = (__cpReg[25] << 16) | __cpReg[24];
        realFifo->count = temp;
    } else {
        realFifo->count = (u8 *)realFifo->wrPtr - (u8 *)realFifo->rdPtr;
        if (realFifo->count < 0) {
            realFifo->count += realFifo->size;
        }
    }
    *readPtr = realFifo->rdPtr;
    *writePtr = realFifo->wrPtr;
}

GXBreakPtCallback GXSetBreakPtCallback(GXBreakPtCallback cb)
{
    GXBreakPtCallback oldcb = BreakPointCB;
    BOOL enabled;

    enabled = OSDisableInterrupts();

    BreakPointCB = cb;
    OSRestoreInterrupts(enabled);
    return oldcb;
}

void __GXFifoInit(void)
{
    __OSSetInterruptHandler(0x11, fn_80031B50);
    __OSUnmaskInterrupts(0x4000);
    __GXCurrentThread = fn_800102AC();
    GXOverflowSuspendInProgress = FALSE;
    CPUFifo = NULL;
    GPFifo = NULL;
}

#pragma pop
