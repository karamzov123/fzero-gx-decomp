#include <types.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>
#include "types.h"
#include <dolphin/gx/GXPriv.h>

/* --- dol/GXSetGPFifo.c --- */

void __GXFifoReadEnable(void);

void __GXFifoReadDisable(void);

void __GXFifoLink(u8 en);

void __GXWriteFifoIntEnable(u8 hiWatermarkEn, u8 loWatermarkEn);

void __GXWriteFifoIntReset(u8 hiWatermarkClr, u8 loWatermarkClr);
extern u16 *__cpReg;

void fn_80009FF4(void);

extern GXFifoObj *lbl_801A6BF0;

extern GXFifoObj *lbl_801A6BF4;

extern GXBool lbl_801A6BFC;

void GXSetGPFifo(GXFifoObj *fifo) {
    int interrupts = OSDisableInterrupts();
    u32 reg;
    __GXFifoReadDisable();
    __GXWriteFifoIntEnable(0, 0);
    lbl_801A6BF4 = fifo;
    (*(vu16 *)((vu16 *)(__cpReg) + (16)) = (u16)fifo->base);
    (*(vu16 *)((vu16 *)(__cpReg) + (18)) = (u16)fifo->end);
    (*(vu16 *)((vu16 *)(__cpReg) + (24)) = (u16)fifo->rw_dst);
    (*(vu16 *)((vu16 *)(__cpReg) + (26)) = (u16)fifo->write_ptr);
    (*(vu16 *)((vu16 *)(__cpReg) + (28)) = (u16)fifo->read_ptr);
    (*(vu16 *)((vu16 *)(__cpReg) + (20)) = (u16)fifo->high_wtrmark);
    (*(vu16 *)((vu16 *)(__cpReg) + (22)) = (u16)fifo->low_wtrmark);
    (*(vu16 *)((vu16 *)(__cpReg) + (17)) = ((u32)fifo->base & 0x3FFFFFFF) >> 16);
    (*(vu16 *)((vu16 *)(__cpReg) + (19)) = ((u32)fifo->end & 0x3FFFFFFF) >> 16);
    (*(vu16 *)((vu16 *)(__cpReg) + (25)) = (fifo->rw_dst) >> 16);
    (*(vu16 *)((vu16 *)(__cpReg) + (27)) = ((u32)fifo->write_ptr & 0x3FFFFFFF) >> 16);
    (*(vu16 *)((vu16 *)(__cpReg) + (29)) = ((u32)fifo->read_ptr & 0x3FFFFFFF) >> 16);
    (*(vu16 *)((vu16 *)(__cpReg) + (21)) = (fifo->high_wtrmark) >> 16);
    (*(vu16 *)((vu16 *)(__cpReg) + (23)) = (fifo->low_wtrmark) >> 16);
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

/* --- dol/fn_80031FF4.c --- */
extern u32 __GXSaveCPUFifoAux(void);

u32 fn_80031FF4(void) {
    return __GXSaveCPUFifoAux();
}
