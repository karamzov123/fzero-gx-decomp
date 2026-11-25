#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#include <dolphin/os/OSTime.h>
#pragma peephole off

/* Dolphin SDK os/OSInterrupt.c. The MSR[EE] accessors and the external interrupt entry are
 * CodeWarrior asm functions in the original (mfmsr/mtmsr, no compiler frame). The
 * __RAS_OSDisableInterrupts labels bound the restartable sequence that OSLoadContext checks
 * when it returns into an interrupted OSDisableInterrupts. */
void __RAS_OSDisableInterrupts_begin(void);
void __RAS_OSDisableInterrupts_end(void);

asm BOOL OSDisableInterrupts(void) {
    nofralloc
entry __RAS_OSDisableInterrupts_begin
    mfmsr r3
    rlwinm r4, r3, 0, 17, 15
    mtmsr r4
entry __RAS_OSDisableInterrupts_end
    rlwinm r3, r3, 17, 31, 31
    blr
}

asm BOOL OSEnableInterrupts(void) {
    nofralloc
    mfmsr r3
    ori r4, r3, 0x8000
    mtmsr r4
    rlwinm r3, r3, 17, 31, 31
    blr
}

asm BOOL OSRestoreInterrupts(register BOOL level) {
    nofralloc
    cmpwi level, 0
    mfmsr r4
    beq disable
    ori r5, r4, 0x8000
    b restore
disable:
    rlwinm r5, r4, 0, 17, 15
restore:
    mtmsr r5
    rlwinm r3, r4, 17, 31, 31
    blr
}

/* --- dol/__OSInterruptInit.c --- */
void *memset(void *dest, int value, size_t n);

vu32 __PIRegs[12] : FZGX_ADDR___PIRegs;

extern __OSInterruptHandler *InterruptHandlerTable;

static void ExternalInterruptHandler(register __OSException exception, register OSContext *context);

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler) {
    __OSInterruptHandler oldHandler;
    oldHandler = InterruptHandlerTable[interrupt];
    InterruptHandlerTable[interrupt] = handler;
    return oldHandler;
}

__OSInterruptHandler __OSGetInterruptHandler(__OSInterrupt interrupt) {
    return InterruptHandlerTable[interrupt];
}

void __OSInterruptInit(void) {
    InterruptHandlerTable = ((void *)((u32)(0x3040) + (0x8000 << 16)));
    memset(InterruptHandlerTable, 0, 32 * sizeof(__OSInterruptHandler));
    *(OSInterruptMask *)FZGX_ADDR___OSGlobalInterruptMask = 0;
    *(OSInterruptMask *)FZGX_ADDR___OSLocalInterruptMask = 0;
    __PIRegs[1] = 0xf0;
    __OSMaskInterrupts(((0x80000000u >> (0)) | (0x80000000u >> (1)) | (0x80000000u >> (2)) |
                        (0x80000000u >> (3)) | (0x80000000u >> (4))) |
                       ((0x80000000u >> (5)) | (0x80000000u >> (6)) | (0x80000000u >> (7))) |
                       ((0x80000000u >> (8))) |
                       ((0x80000000u >> (9)) | (0x80000000u >> (10)) | (0x80000000u >> (11)) |
                        (0x80000000u >> (12)) | (0x80000000u >> (13)) | (0x80000000u >> (14)) |
                        (0x80000000u >> (15)) | (0x80000000u >> (16))) |
                       ((0x80000000u >> (17)) | (0x80000000u >> (20)) | (0x80000000u >> (21)) |
                        (0x80000000u >> (22)) | (0x80000000u >> (23)) | (0x80000000u >> (24)) |
                        (0x80000000u >> (18)) | (0x80000000u >> (19)) | (0x80000000u >> (25)) |
                        (0x80000000u >> (26))));
    __OSSetExceptionHandler(4, ExternalInterruptHandler);
}

/* --- dol/SetInterruptMask.c --- */
vu16 __MEMRegs[64] : FZGX_ADDR___MEMRegs;

vu16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

vu32 __AIRegs[8] : FZGX_ADDR___AIRegs;

u32 SetInterruptMask(OSInterruptMask mask, OSInterruptMask current) {
    u32 reg;
    switch (__cntlzw(mask)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        reg = 0;
        if (!(current & (0x80000000u >> (0))))
            reg |= 0x1;
        if (!(current & (0x80000000u >> (1))))
            reg |= 0x2;
        if (!(current & (0x80000000u >> (2))))
            reg |= 0x4;
        if (!(current & (0x80000000u >> (3))))
            reg |= 0x8;
        if (!(current & (0x80000000u >> (4))))
            reg |= 0x10;
        __MEMRegs[0x0000000e] = (u16)reg;
        mask &= ~((0x80000000u >> (0)) | (0x80000000u >> (1)) | (0x80000000u >> (2)) |
                  (0x80000000u >> (3)) | (0x80000000u >> (4)));
        break;
    case 5:
    case 6:
    case 7:
        reg = __DSPRegs[0x00000005];
        reg &= ~0x1F8;
        if (!(current & (0x80000000u >> (5))))
            reg |= 0x10;
        if (!(current & (0x80000000u >> (6))))
            reg |= 0x40;
        if (!(current & (0x80000000u >> (7))))
            reg |= 0x100;
        __DSPRegs[0x00000005] = (u16)reg;
        mask &= ~((0x80000000u >> (5)) | (0x80000000u >> (6)) | (0x80000000u >> (7)));
        break;
    case 8:
        reg = __AIRegs[0];
        reg &= ~0x2C;
        if (!(current & (0x80000000u >> (8))))
            reg |= 0x4;
        __AIRegs[0] = reg;
        mask &= ~((0x80000000u >> (8)));
        break;
    case 9:
    case 10:
    case 11:
        reg = __EXIRegs[0];
        reg &= ~0x2C0F;
        if (!(current & (0x80000000u >> (9))))
            reg |= 0x1;
        if (!(current & (0x80000000u >> (10))))
            reg |= 0x4;
        if (!(current & (0x80000000u >> (11))))
            reg |= 0x400;
        __EXIRegs[0] = reg;
        mask &= ~((0x80000000u >> (9)) | (0x80000000u >> (10)) | (0x80000000u >> (11)));
        break;
    case 12:
    case 13:
    case 14:
        reg = __EXIRegs[5];
        reg &= ~0xC0F;
        if (!(current & (0x80000000u >> (12))))
            reg |= 0x1;
        if (!(current & (0x80000000u >> (13))))
            reg |= 0x4;
        if (!(current & (0x80000000u >> (14))))
            reg |= 0x400;
        __EXIRegs[5] = reg;
        mask &= ~((0x80000000u >> (12)) | (0x80000000u >> (13)) | (0x80000000u >> (14)));
        break;
    case 15:
    case 16:
        reg = __EXIRegs[10];
        reg &= ~0xF;
        if (!(current & (0x80000000u >> (15))))
            reg |= 0x1;
        if (!(current & (0x80000000u >> (16))))
            reg |= 0x4;
        __EXIRegs[10] = reg;
        mask &= ~((0x80000000u >> (15)) | (0x80000000u >> (16)));
        break;
    case 17:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 18:
    case 19:
    case 26:
        reg = 0xF0;
        if (!(current & (0x80000000u >> (17)))) {
            reg |= 0x800;
        }
        if (!(current & (0x80000000u >> (20)))) {
            reg |= 0x8;
        }
        if (!(current & (0x80000000u >> (21)))) {
            reg |= 0x4;
        }
        if (!(current & (0x80000000u >> (22)))) {
            reg |= 0x2;
        }
        if (!(current & (0x80000000u >> (23)))) {
            reg |= 0x1;
        }
        if (!(current & (0x80000000u >> (24)))) {
            reg |= 0x100;
        }
        if (!(current & (0x80000000u >> (25)))) {
            reg |= 0x1000;
        }
        if (!(current & (0x80000000u >> (18)))) {
            reg |= 0x200;
        }
        if (!(current & (0x80000000u >> (19)))) {
            reg |= 0x400;
        }
        if (!(current & (0x80000000u >> (26)))) {
            reg |= 0x2000;
        }
        __PIRegs[1] = reg;
        mask &= ~((0x80000000u >> (17)) | (0x80000000u >> (20)) | (0x80000000u >> (21)) |
                  (0x80000000u >> (22)) | (0x80000000u >> (23)) | (0x80000000u >> (24)) |
                  (0x80000000u >> (18)) | (0x80000000u >> (19)) | (0x80000000u >> (25)) |
                  (0x80000000u >> (26)));
        break;
    default:
        break;
    }
    return mask;
}

/* --- dol/__OSMaskInterrupts.c --- */
u32 SetInterruptMask(OSInterruptMask mask, OSInterruptMask current);

OSInterruptMask __OSMaskInterrupts(OSInterruptMask global) {
    BOOL enabled;
    OSInterruptMask prev;
    OSInterruptMask local;
    OSInterruptMask mask;
    enabled = OSDisableInterrupts();
    prev = *(OSInterruptMask *)FZGX_ADDR___OSGlobalInterruptMask;
    local = *(OSInterruptMask *)FZGX_ADDR___OSLocalInterruptMask;
    mask = ~(prev | local) & global;
    global |= prev;
    *(OSInterruptMask *)FZGX_ADDR___OSGlobalInterruptMask = global;
    while (mask) {
        mask = SetInterruptMask(mask, global | local);
    }
    OSRestoreInterrupts(enabled);
    return prev;
}

/* --- dol/__OSUnmaskInterrupts.c --- */
u32 SetInterruptMask(OSInterruptMask mask, OSInterruptMask current);

OSInterruptMask __OSUnmaskInterrupts(OSInterruptMask global) {
    BOOL enabled;
    OSInterruptMask prev;
    OSInterruptMask local;
    OSInterruptMask mask;
    enabled = OSDisableInterrupts();
    prev = *(OSInterruptMask *)FZGX_ADDR___OSGlobalInterruptMask;
    local = *(OSInterruptMask *)FZGX_ADDR___OSLocalInterruptMask;
    mask = (prev | local) & global;
    global = prev & ~global;
    *(OSInterruptMask *)FZGX_ADDR___OSGlobalInterruptMask = global;
    while (mask) {
        mask = SetInterruptMask(mask, global | local);
    }
    OSRestoreInterrupts(enabled);
    return prev;
}

/* --- dol/__OSDispatchInterrupt.c --- */
// Hardware or OS state can change asynchronously.
extern volatile __OSInterrupt __OSLastInterrupt; // fzgx-allow: S2 SDK asynchronous state

// Hardware or OS state can change asynchronously.
extern volatile u32 __OSLastInterruptSrr0; // fzgx-allow: S2 SDK asynchronous state

// Hardware or OS state can change asynchronously.
extern volatile OSTime __OSLastInterruptTime; // fzgx-allow: S2 SDK asynchronous state

__OSInterruptHandler GetInterruptHandlerInline(__OSInterrupt interrupt);

s32 OSDisableScheduler();

s32 OSEnableScheduler();







extern OSInterruptMask lbl_80123A60[];

static inline __OSInterruptHandler GetInterruptHandlerInline(__OSInterrupt interrupt) {
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
        handler = GetInterruptHandlerInline(interrupt);
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

static asm void ExternalInterruptHandler(register __OSException exception, register OSContext *context) {
    nofralloc
    stw r0, 0x0(context)
    stw r1, 0x4(context)
    stw r2, 0x8(context)
    stmw r6, 0x18(context)
    mfspr r0, GQR1
    stw r0, 0x1a8(context)
    mfspr r0, GQR2
    stw r0, 0x1ac(context)
    mfspr r0, GQR3
    stw r0, 0x1b0(context)
    mfspr r0, GQR4
    stw r0, 0x1b4(context)
    mfspr r0, GQR5
    stw r0, 0x1b8(context)
    mfspr r0, GQR6
    stw r0, 0x1bc(context)
    mfspr r0, GQR7
    stw r0, 0x1c0(context)
    stwu r1, -0x8(r1)
    b __OSDispatchInterrupt
}
