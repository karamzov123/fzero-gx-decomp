#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

u32 PPCMfmsr(void);

void PPCMtmsr(u32 val);

void PPCHalt(void);

s32 PPCMffpscr(void);

void PPCMtfpscr(u32 val);

vu16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

void OSReport(const char *msg, ...);

OSErrorHandler __OSErrorTable[(16 + 1)] __attribute__((aligned(8)));

extern volatile __OSInterrupt __OSLastInterrupt; // fzgx-allow: S2 SDK asynchronous state

extern volatile u32 __OSLastInterruptSrr0; // fzgx-allow: S2 SDK asynchronous state

extern volatile OSTime __OSLastInterruptTime; // fzgx-allow: S2 SDK asynchronous state

s32 OSDisableScheduler();

s32 OSEnableScheduler();

volatile OSContext *__OSFPUContext : FZGX_ADDR___OSFPUContext; // fzgx-allow: S2 SDK asynchronous state

void OSReport(const char *msg, ...);

// Shared .rodata blob holding this unit's report formats at fixed offsets.
extern char OSErrorData[];

void __OSUnhandledException(__OSException exception, OSContext *context, u32 dsisr, u32 dar) {
    const char *data = OSErrorData;
    OSTime now;

    now = OSGetTime();
    if (!((((1 << (31 - 30))) & (context->srr1)))) {
        OSReport(data + 0x5c, exception);
    } else {
        if (exception == 6 && (context->srr1 & (0x80000000 >> 11)) && __OSErrorTable[16] != 0) {
            u32 fpscr;
            u32 msr;
            exception = 16;
            msr = PPCMfmsr();
            PPCMtmsr(msr | (1 << (31 - 18)));
            if (__OSFPUContext) {
                OSSaveFPUContext((OSContext *)__OSFPUContext);
            }
            fpscr = PPCMffpscr();
            fpscr &= ~((((((1 << (31 - 11)))) | ((((1 << (31 - 10)))) | (((1 << (31 - 12))))))) | (1 << (31 - 9)) |
                       (1 << (31 - 8)) | (1 << (31 - 7)) | (1 << (31 - 21)) | (1 << (31 - 22)) |
                       (1 << (31 - 23)) | (1 << (31 - 6)) | (1 << (31 - 5)) | (1 << (31 - 4)) |
                       (1 << (31 - 3)) | (1 << (31 - 0)) | (1 << (31 - 14)));
            PPCMtfpscr(fpscr);
            PPCMtmsr(msr);
            if (__OSFPUContext == context) {
                OSDisableScheduler();
                __OSErrorTable[exception](exception, context, dsisr, dar);
                context->srr1 &= ~(1 << (31 - 18));
                __OSFPUContext = ((void *)0);
                context->fpscr &=
                    ~((1 << (31 - 12)) | (1 << (31 - 11)) | (1 << (31 - 10)) | (1 << (31 - 9)) |
                      (1 << (31 - 8)) | (1 << (31 - 7)) | (1 << (31 - 21)) | (1 << (31 - 22)) |
                      (1 << (31 - 23)) | (1 << (31 - 6)) | (1 << (31 - 5)) | (1 << (31 - 4)) |
                      (1 << (31 - 3)) | (1 << (31 - 0)) | (1 << (31 - 14)));
                OSEnableScheduler();
                __OSReschedule();
            } else {
                context->srr1 &= ~(1 << (31 - 18));
                __OSFPUContext = ((void *)0);
            }
            OSLoadContext(context);
        }
        if (__OSErrorTable[exception]) {
            OSDisableScheduler();
            __OSErrorTable[exception](exception, context, dsisr, dar);
            OSEnableScheduler();
            __OSReschedule();
            OSLoadContext(context);
        }
        if (exception == 8) {
            OSLoadContext(context);
        }
        OSReport(data + 0x7c, exception);
    }
    OSReport("\n");
    OSDumpContext(context);
    OSReport(data + 0x94, dsisr, dar);
    OSReport(data + 0xc8, now);
    switch (exception) {
    case 2:
        OSReport(data + 0xd8, context->srr0, dar);
        break;
    case 3:
        OSReport(data + 0x138, context->srr0);
        break;
    case 5:
        OSReport(data + 0x184, context->srr0, dar);
        break;
    case 6:
        OSReport(data + 0x1e8, context->srr0, dar);
        break;
    case 15:
        OSReport("\n");
        OSReport(data + 0x248, __DSPRegs[0x00000018], __DSPRegs[0x00000018 + 1]);
        OSReport(data + 0x268, __DSPRegs[0x00000010], __DSPRegs[0x00000010 + 1]);
        OSReport(data + 0x288, __DIRegs[0x00000005]);
        break;
    }
    OSReport(data + 0x2a4, __OSLastInterrupt, __OSLastInterruptSrr0, __OSLastInterruptTime);
    PPCHalt();
}
