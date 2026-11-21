#include <types.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>
#include "types.h"
#include <dolphin/gx/GXPriv.h>

/* --- dol/__GXSaveCPUFifoAux.c --- */
/* --- dol/__GXSaveCPUFifoAux.c --- */

extern u32 *__piReg;

extern u16 *__cpReg;

void GXFlush(void);

extern GXBool lbl_801A6BFC;

void __GXSaveCPUFifoAux(GXFifoObj *fifo) {
    int interrupts = OSDisableInterrupts();
    GXFlush();
    fifo->base = ((void *)((u32)((*(vu32 *)((vu32 *)(__piReg) + (3)))) + (0x8000 << 16)));
    fifo->end = ((void *)((u32)((*(vu32 *)((vu32 *)(__piReg) + (4)))) + (0x8000 << 16)));
    fifo->write_ptr =
        ((void *)((u32)((*(vu32 *)((vu32 *)(__piReg) + (5))) & ~0x4000000) + (0x8000 << 16)));
    if (lbl_801A6BFC != 0) {
        do {
            u32 temp = (*(vu16 *)((vu16 *)(__cpReg) + (29))) << 16;
            temp |= (*(vu16 *)((vu16 *)(__cpReg) + (28)));
            fifo->read_ptr = ((void *)((u32)(temp) + (0x8000 << 16)));
        } while (0);
        do {
            u32 temp = (*(vu16 *)((vu16 *)(__cpReg) + (25))) << 16;
            temp |= (*(vu16 *)((vu16 *)(__cpReg) + (24)));
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

/* --- dol/GXGetGPStatus.c --- */
void GXGetGPStatus(GXBool *overhi, GXBool *underlow, GXBool *readIdle, GXBool *cmdIdle,
                 GXBool *brkpt) {
    gx->cpStatus = (*(vu16 *)((vu16 *)(__cpReg) + (0)));
    *overhi = gx->cpStatus & 1;
    *underlow = (gx->cpStatus >> 1) & 1;
    *readIdle = (gx->cpStatus >> 2) & 1;
    *cmdIdle = (gx->cpStatus >> 3) & 1;
    *brkpt = (gx->cpStatus >> 4) & 1;
}

/* --- dol/GXGetFifoPtrs.c --- */

void (*DVDLowClearCallback())(u32);

extern struct __GXFifoObj *lbl_801A6BF0;

extern struct __GXFifoObj *lbl_801A6BF4;

void GXGetFifoPtrs(GXFifoObj_u1 *fifo, void **readPtr, void **writePtr) {
    struct __GXFifoObj *realFifo = (struct __GXFifoObj *)fifo;
    if (realFifo == lbl_801A6BF0) {
        realFifo->wrPtr = ((void *)((u32)((0x8000 << 16) + (u32)(__piReg[5] & 0xFBFFFFFF))));
    }
    if (realFifo == lbl_801A6BF4) {
        do {
            u32 temp = __cpReg[29] << 16;
            temp |= __cpReg[28];
            realFifo->rdPtr = ((void *)((u32)((0x8000 << 16) + (u32)(temp))));
        } while (0);
        do {
            u32 temp = __cpReg[25] << 16;
            temp |= __cpReg[24];
            realFifo->count = temp;
        } while (0);
    } else {
        realFifo->count = (u8 *)realFifo->wrPtr - (u8 *)realFifo->rdPtr;
        if (realFifo->count < 0) {
            realFifo->count += realFifo->size;
        }
    }
    *readPtr = realFifo->rdPtr;
    *writePtr = realFifo->wrPtr;
}
