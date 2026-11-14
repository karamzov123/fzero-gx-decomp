#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma peephole off

// Hardware or OS state can change asynchronously.
extern volatile __OSInterrupt __OSLastInterrupt; // fzgx-allow: S2 SDK asynchronous state

// Hardware or OS state can change asynchronously.
extern volatile u32 __OSLastInterruptSrr0; // fzgx-allow: S2 SDK asynchronous state

// Hardware or OS state can change asynchronously.
extern volatile OSTime __OSLastInterruptTime; // fzgx-allow: S2 SDK asynchronous state

__OSInterruptHandler __OSGetInterruptHandler(__OSInterrupt interrupt);

s32 OSDisableScheduler();

s32 OSEnableScheduler();

vu32 __PIRegs[12] : FZGX_ADDR___PIRegs;

vu16 __MEMRegs[64] : FZGX_ADDR___MEMRegs;

vu16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

vu32 __AIRegs[8] : FZGX_ADDR___AIRegs;

extern __OSInterruptHandler *InterruptHandlerTable;

extern OSInterruptMask lbl_80123A60[];

static inline __OSInterruptHandler __OSGetInterruptHandler(__OSInterrupt interrupt) {
    return InterruptHandlerTable[interrupt];
}

void __OSDispatchInterrupt(__OSException exception, OSContext *context) {
    u32 intsr;
    u32 reg;
    OSInterruptMask cause;
    OSInterruptMask unmasked;
    OSInterruptMask *prio;
    __OSInterrupt interrupt;
    __OSInterruptHandler handler;
    intsr = __PIRegs[0];
    intsr &= ~0x00010000;
    if (intsr == 0 || (intsr & __PIRegs[1]) == 0) {
        OSLoadContext(context);
    }
    cause = 0;
    if (intsr & 0x00000080) {
        reg = __MEMRegs[15];
        if (reg & 0x1)
            cause |= (0x80000000u >> (0));
        if (reg & 0x2)
            cause |= (0x80000000u >> (1));
        if (reg & 0x4)
            cause |= (0x80000000u >> (2));
        if (reg & 0x8)
            cause |= (0x80000000u >> (3));
        if (reg & 0x10)
            cause |= (0x80000000u >> (4));
    }
    if (intsr & 0x00000040) {
        reg = __DSPRegs[5];
        if (reg & 0x8)
            cause |= (0x80000000u >> (5));
        if (reg & 0x20)
            cause |= (0x80000000u >> (6));
        if (reg & 0x80)
            cause |= (0x80000000u >> (7));
    }
    if (intsr & 0x00000020) {
        reg = __AIRegs[0];
        if (reg & 0x8)
            cause |= (0x80000000u >> (8));
    }
    if (intsr & 0x00000010) {
        reg = __EXIRegs[0];
        if (reg & 0x2)
            cause |= (0x80000000u >> (9));
        if (reg & 0x8)
            cause |= (0x80000000u >> (10));
        if (reg & 0x800)
            cause |= (0x80000000u >> (11));
        reg = __EXIRegs[5];
        if (reg & 0x2)
            cause |= (0x80000000u >> (12));
        if (reg & 0x8)
            cause |= (0x80000000u >> (13));
        if (reg & 0x800)
            cause |= (0x80000000u >> (14));
        reg = __EXIRegs[10];
        if (reg & 0x2)
            cause |= (0x80000000u >> (15));
        if (reg & 0x8)
            cause |= (0x80000000u >> (16));
    }
    if (intsr & 0x00002000)
        cause |= (0x80000000u >> (26));
    if (intsr & 0x00001000)
        cause |= (0x80000000u >> (25));
    if (intsr & 0x00000400)
        cause |= (0x80000000u >> (19));
    if (intsr & 0x00000200)
        cause |= (0x80000000u >> (18));
    if (intsr & 0x00000100)
        cause |= (0x80000000u >> (24));
    if (intsr & 0x00000008)
        cause |= (0x80000000u >> (20));
    if (intsr & 0x00000004)
        cause |= (0x80000000u >> (21));
    if (intsr & 0x00000002)
        cause |= (0x80000000u >> (22));
    if (intsr & 0x00000800)
        cause |= (0x80000000u >> (17));
    if (intsr & 0x00000001)
        cause |= (0x80000000u >> (23));
    unmasked = cause & ~(*(OSInterruptMask *)FZGX_ADDR___OSGlobalInterruptMask |
                         *(OSInterruptMask *)FZGX_ADDR___OSLocalInterruptMask);
    if (unmasked) {
        for (prio = lbl_80123A60;; ++prio) {
            if (unmasked & *prio) {
                interrupt = (__OSInterrupt)__cntlzw(unmasked & *prio);
                break;
            }
        }
        handler = __OSGetInterruptHandler(interrupt);
        if (handler) {
            if (4 < interrupt) {
                __OSLastInterrupt = interrupt;
                __OSLastInterruptTime = OSGetTime();
                __OSLastInterruptSrr0 = context->srr0;
            }
            OSDisableScheduler();
            handler(interrupt, context);
            OSEnableScheduler();
            __OSReschedule();
            OSLoadContext(context);
        }
    }
    OSLoadContext(context);
}
