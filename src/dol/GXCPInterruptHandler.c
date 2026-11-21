#include <types.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/types.h>
#include "types.h"
#include <dolphin/gx/GXPriv.h>

/* --- dol/GXCPInterruptHandler.c --- */

s32 OSResumeThread(OSThread *thread);

s32 OSSuspendThread(OSThread *thread);

void __GXWriteFifoIntEnable(u8 hiWatermarkEn, u8 loWatermarkEn);

void __GXWriteFifoIntReset(u8 hiWatermarkClr, u8 loWatermarkClr);
extern u16 *__cpReg;

extern OSThread *lbl_801A6BF8;

extern u32 lbl_801A6C00;

extern GXBreakPtCallback lbl_801A6C04;

extern u32 lbl_801A6C08;

static inline void GXOverflowHandler() {
    lbl_801A6C08 += 1;
    __GXWriteFifoIntEnable(0, 1);
    __GXWriteFifoIntReset(1, 0);
    lbl_801A6C00 = 1;
    OSSuspendThread(lbl_801A6BF8);
}

static inline void GXUnderflowHandler() {
    OSResumeThread(lbl_801A6BF8);
    lbl_801A6C00 = 0;
    __GXWriteFifoIntReset(1, 1);
    __GXWriteFifoIntEnable(1, 0);
}

static inline void GXBreakPointHandler(OSContext *context) {
    OSContext bpContext;
    (gx->cpEnable) = ((u32)(gx->cpEnable) & ~(((1 << (1)) - 1) << (5))) | ((u32)(0) << (5));
    ;
    (*(vu16 *)((vu16 *)(__cpReg) + (1)) = gx->cpEnable);
    if (lbl_801A6C04) {
        OSClearContext(&bpContext);
        OSSetCurrentContext(&bpContext);
        lbl_801A6C04();
        OSClearContext(&bpContext);
        OSSetCurrentContext(context);
    }
}

void GXCPInterruptHandler(s16 p1, OSContext *context) {
    gx->cpStatus = (*(vu16 *)((vu16 *)(__cpReg) + (0)));
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

/* --- dol/GXInitFifoBase.c --- */

extern void fn_80031D60(struct GXInitFifoBase_Arg0 *, u32, u32);
extern void GXInitFifoPtrs(struct GXInitFifoBase_Arg0 *, u32, u32);

void GXInitFifoBase(struct GXInitFifoBase_Arg0 *arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 lab_t1;

    v0 = arg2 - 4;
    v0 = arg1 + v0;
    arg0->unk_0 = arg1;
    arg0->unk_4 = v0;
    arg0->unk_8 = arg2;
    arg0->unk_1C = 0;
    lab_t1 = arg2 - 0x4000;
    fn_80031D60(arg0, lab_t1, __rlwinm(arg2, 31, 1, 26));
    GXInitFifoPtrs(arg0, arg1, arg1);
}
