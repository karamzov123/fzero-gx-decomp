#include <types.h>
#include <dolphin/types.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/gx/GXPriv.h>

extern vu16 *__cpReg;
extern vu32 *__piReg;

extern GXFifoObj *lbl_801A6BF0; /* current CPU FIFO */
extern GXFifoObj *lbl_801A6BF4; /* current GP FIFO */
extern OSThread *lbl_801A6BF8;  /* thread suspended on FIFO overflow */
extern GXBool lbl_801A6BFC;     /* CPU and GP share one FIFO */
extern u32 lbl_801A6C00;
extern GXBreakPtCallback lbl_801A6C04;
extern u32 lbl_801A6C08;

s32 OSResumeThread(OSThread *thread);
s32 OSSuspendThread(OSThread *thread);
void fn_80009FF4(void);
void GXFlush(void);
void __GXFifoReadEnable(void);
void __GXFifoReadDisable(void);
void __GXFifoLink(u8 en);
void __GXWriteFifoIntEnable(u8 hiWatermarkEn, u8 loWatermarkEn);
void __GXWriteFifoIntReset(u8 hiWatermarkClr, u8 loWatermarkClr);
void GXInitFifoPtrs(GXFifoObj *fifo, void *readPtr, void *writePtr);
void fn_80031D60(GXFifoObj *fifo, u32 hiWatermark, u32 loWatermark);
void __GXSaveCPUFifoAux(GXFifoObj *fifo);

static inline void GXOverflowHandler(void) {
    lbl_801A6C08 += 1;
    __GXWriteFifoIntEnable(0, 1);
    __GXWriteFifoIntReset(1, 0);
    lbl_801A6C00 = 1;
    OSSuspendThread(lbl_801A6BF8);
}

static inline void GXUnderflowHandler(void) {
    OSResumeThread(lbl_801A6BF8);
    lbl_801A6C00 = 0;
    __GXWriteFifoIntReset(1, 1);
    __GXWriteFifoIntEnable(1, 0);
}

static inline void GXBreakPointHandler(OSContext *context) {
    OSContext bpContext;

    gx->cpEnable = (gx->cpEnable & ~(1 << 5)) | (0 << 5);
    __cpReg[1] = gx->cpEnable;
    if (lbl_801A6C04) {
        OSClearContext(&bpContext);
        OSSetCurrentContext(&bpContext);
        lbl_801A6C04();
        OSClearContext(&bpContext);
        OSSetCurrentContext(context);
    }
}

void GXCPInterruptHandler(s16 interrupt, OSContext *context) {
    gx->cpStatus = __cpReg[0];
    if ((gx->cpEnable >> 3 & 1) && (gx->cpStatus >> 1 & 1)) {
        GXUnderflowHandler();
    }
    if ((gx->cpEnable >> 2 & 1) && (gx->cpStatus >> 0 & 1)) {
        GXOverflowHandler();
    }
    if ((gx->cpEnable >> 5 & 1) && (gx->cpStatus >> 4 & 1)) {
        GXBreakPointHandler(context);
    }
}

void GXInitFifoBase(GXFifoObj *fifo, void *base, u32 size) {
    fifo->base = base;
    fifo->end = (void *)((u32)base + size - 4);
    fifo->size = size;
    fifo->rw_dst = 0;
    fn_80031D60(fifo, size - 0x4000, (size >> 1) & ~0x1F);
    GXInitFifoPtrs(fifo, base, base);
}

void GXInitFifoPtrs(GXFifoObj *fifo, void *readPtr, void *writePtr) {
    BOOL enabled = OSDisableInterrupts();

    fifo->read_ptr = readPtr;
    fifo->write_ptr = writePtr;
    fifo->rw_dst = (u8 *)writePtr - (u8 *)readPtr;
    if (fifo->rw_dst < 0) {
        fifo->rw_dst += fifo->size;
    }
    OSRestoreInterrupts(enabled);
}

void fn_80031D60(GXFifoObj *fifo, u32 hiWatermark, u32 loWatermark) {
    fifo->high_wtrmark = hiWatermark;
    fifo->low_wtrmark = loWatermark;
}

void GXSetCPUFifo(GXFifoObj *fifo) {
    BOOL enabled = OSDisableInterrupts();

    lbl_801A6BF0 = fifo;
    if (fifo == lbl_801A6BF4) {
        __piReg[3] = (u32)fifo->base & 0x3FFFFFFF;
        __piReg[4] = (u32)fifo->end & 0x3FFFFFFF;
        __piReg[5] = (s32)fifo->write_ptr & 0x3FFFFFE0 & 0xFBFFFFFF;
        lbl_801A6BFC = 1;
        __GXWriteFifoIntReset(1, 1);
        __GXWriteFifoIntEnable(1, 0);
        __GXFifoLink(1);
    } else {
        if (lbl_801A6BFC) {
            __GXFifoLink(0);
            lbl_801A6BFC = 0;
        }
        __GXWriteFifoIntEnable(0, 0);
        __piReg[3] = (u32)fifo->base & 0x3FFFFFFF;
        __piReg[4] = (u32)fifo->end & 0x3FFFFFFF;
        __piReg[5] = (s32)fifo->write_ptr & 0x3FFFFFE0 & 0xFBFFFFFF;
    }
    fn_80009FF4();
    OSRestoreInterrupts(enabled);
}

void GXSetGPFifo(GXFifoObj *fifo) {
    int interrupts = OSDisableInterrupts();
    u32 reg;

    __GXFifoReadDisable();
    __GXWriteFifoIntEnable(0, 0);
    lbl_801A6BF4 = fifo;
    __cpReg[16] = (u16)fifo->base;
    __cpReg[18] = (u16)fifo->end;
    __cpReg[24] = (u16)fifo->rw_dst;
    __cpReg[26] = (u16)fifo->write_ptr;
    __cpReg[28] = (u16)fifo->read_ptr;
    __cpReg[20] = (u16)fifo->high_wtrmark;
    __cpReg[22] = (u16)fifo->low_wtrmark;
    __cpReg[17] = ((u32)fifo->base & 0x3FFFFFFF) >> 16;
    __cpReg[19] = ((u32)fifo->end & 0x3FFFFFFF) >> 16;
    __cpReg[25] = fifo->rw_dst >> 16;
    __cpReg[27] = ((u32)fifo->write_ptr & 0x3FFFFFFF) >> 16;
    __cpReg[29] = ((u32)fifo->read_ptr & 0x3FFFFFFF) >> 16;
    __cpReg[21] = fifo->high_wtrmark >> 16;
    __cpReg[23] = fifo->low_wtrmark >> 16;
    fn_80009FF4();
    if (lbl_801A6BF0 == lbl_801A6BF4) {
        lbl_801A6BFC = 1;
        __GXWriteFifoIntEnable(1, 0);
        __GXFifoLink(1);
    } else {
        lbl_801A6BFC = 0;
        __GXWriteFifoIntEnable(0, 0);
        __GXFifoLink(0);
    }
    reg = gx->cpEnable;
    __GXWriteFifoIntReset(1, 1);
    __GXFifoReadEnable();
    OSRestoreInterrupts(interrupts);
}

void fn_80031FF4(GXFifoObj *fifo) {
    __GXSaveCPUFifoAux(fifo);
}

void __GXSaveCPUFifoAux(GXFifoObj *fifo) {
    int interrupts = OSDisableInterrupts();

    GXFlush();
    fifo->base = (void *)(__piReg[3] + 0x80000000);
    fifo->end = (void *)(__piReg[4] + 0x80000000);
    fifo->write_ptr = (void *)((__piReg[5] & ~0x4000000) + 0x80000000);
    if (lbl_801A6BFC != 0) {
        do {
            u32 temp = __cpReg[29] << 16;
            temp |= __cpReg[28];
            fifo->read_ptr = (void *)(temp + 0x80000000);
        } while (0);
        do {
            u32 temp = __cpReg[25] << 16;
            temp |= __cpReg[24];
            fifo->rw_dst = temp;
        } while (0);
    } else {
        fifo->rw_dst = (u32)fifo->write_ptr - (u32)fifo->read_ptr;
        if (fifo->rw_dst < 0) {
            fifo->rw_dst += fifo->size;
        }
    }
    OSRestoreInterrupts(interrupts);
}

void GXGetGPStatus(GXBool *overhi, GXBool *underlow, GXBool *readIdle, GXBool *cmdIdle,
                   GXBool *brkpt) {
    gx->cpStatus = __cpReg[0];
    *overhi = gx->cpStatus & 1;
    *underlow = (gx->cpStatus >> 1) & 1;
    *readIdle = (gx->cpStatus >> 2) & 1;
    *cmdIdle = (gx->cpStatus >> 3) & 1;
    *brkpt = (gx->cpStatus >> 4) & 1;
}

void GXGetFifoPtrs(GXFifoObj *fifo, void **readPtr, void **writePtr) {
    if (fifo == lbl_801A6BF0) {
        fifo->write_ptr = (void *)(0x80000000 + (__piReg[5] & 0xFBFFFFFF));
    }
    if (fifo == lbl_801A6BF4) {
        do {
            u32 temp = __cpReg[29] << 16;
            temp |= __cpReg[28];
            fifo->read_ptr = (void *)(0x80000000 + temp);
        } while (0);
        do {
            u32 temp = __cpReg[25] << 16;
            temp |= __cpReg[24];
            fifo->rw_dst = temp;
        } while (0);
    } else {
        fifo->rw_dst = (u8 *)fifo->write_ptr - (u8 *)fifo->read_ptr;
        if (fifo->rw_dst < 0) {
            fifo->rw_dst += fifo->size;
        }
    }
    *readPtr = fifo->read_ptr;
    *writePtr = fifo->write_ptr;
}
