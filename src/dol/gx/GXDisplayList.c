#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <dolphin/os/OSInterrupt.h>

typedef struct FifoBackup {
    struct __GXFifoObj fifo;
    GXData gx;
    u32 pad_51C;
} FifoBackup;

FifoBackup lbl_801783A0;
extern volatile u32 *__piReg; /* hardware register */
extern struct __GXFifoObj *lbl_801A6C28;

extern struct __GXFifoObj *fn_80032360(void);
extern void fn_8003458C(void);
extern void *memcpy(void *dest, const void *src, u32 n);
extern void fn_80031FF4(struct __GXFifoObj *);
extern void __GXSaveCPUFifoAux(struct __GXFifoObj *);
extern void GXSetCPUFifo(struct __GXFifoObj *);
extern void __GXSendFlushPrim(void);

static inline void InitFifoBase(struct __GXFifoObj *fifo, void *base, u32 size) {
    fifo->base = base;
    fifo->top = (u8 *)base + size - 4;
    fifo->size = size;
    fifo->count = 0;
    fifo->rdPtr = base;
    fifo->wrPtr = base;
}

void fn_8003887C(void *start, u32 size) {
    struct __GXFifoObj *token;
    token = fn_80032360();
    if (gx->dirtyState != 0) {
        fn_8003458C();
    }
    if (gx->dlSaveContext != 0) {
        memcpy(&lbl_801783A0.gx, gx, 0x4f8);
    }
    InitFifoBase(&lbl_801783A0.fifo, start, size);
    gx->inDispList = 1;
    fn_80031FF4(token);
    lbl_801A6C28 = token;
    GXSetCPUFifo(&lbl_801783A0.fifo);
}

u32 fn_80038944(void) {
    u32 flag;
    s32 enabled;
    u32 saved;

    if (gx->dirtyState != 0) {
        fn_8003458C();
    }
    flag = (__piReg[5] >> 26) & 1;
    __GXSaveCPUFifoAux(&lbl_801783A0.fifo);
    GXSetCPUFifo(lbl_801A6C28);
    if (gx->dlSaveContext != 0) {
        enabled = OSDisableInterrupts();
        saved = gx->cpEnable;
        memcpy(gx, &lbl_801783A0.gx, 0x4f8);
        gx->cpEnable = saved;
        OSRestoreInterrupts(enabled);
    }
    gx->inDispList = 0;
    if (flag == 0) {
        return lbl_801783A0.fifo.count;
    }
    return 0;
}

void GXCallDisplayList(void *list, u32 nbytes) {
    if (gx->dirtyState != 0) {
        fn_8003458C();
    }
    if (*(u32 *)gx == 0) {
        __GXSendFlushPrim();
    }
    GXWGFifo.u8 = 0x40;
    GXWGFifo.u32 = (u32)list;
    GXWGFifo.u32 = nbytes;
}
