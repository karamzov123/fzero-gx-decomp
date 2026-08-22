typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
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

typedef void GXFifoObj;

extern BOOL OSDisableInterrupts(void);
extern void OSRestoreInterrupts(BOOL level);
extern void GXInitFifoLimits(GXFifoObj *fifo, u32 hiWatermark, u32 loWatermark);
extern void GXInitFifoPtrs(GXFifoObj *fifo, void *readPtr, void *writePtr);

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
