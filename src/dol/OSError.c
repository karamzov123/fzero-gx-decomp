#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

typedef struct __va_list_struct {
    char gpr;
    char fpr;
    char reserved[2];
    char *input_arg_area;
    char *reg_save_area;
} __va_list[1];

typedef __va_list va_list;

u32 PPCMfmsr(void);

void PPCMtmsr(u32 val);

u32 PPCMffpscr(void);

void PPCMtfpscr(u32 val);

void PPCHalt(void);

u32 fn_8000BFC0();

int vprintf(const char *, va_list);

s32 OSDisableScheduler();

s32 OSEnableScheduler();

vu16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

OSThreadQueue __OSActiveThreadQueue : FZGX_ADDR___OSActiveThreadQueue;

volatile OSContext *__OSFPUContext : FZGX_ADDR___OSFPUContext; // fzgx-allow: S2 SDK asynchronous state

extern volatile __OSInterrupt __OSLastInterrupt; // fzgx-allow: S2 SDK asynchronous state

extern volatile u32 __OSLastInterruptSrr0; // fzgx-allow: S2 SDK asynchronous state

extern volatile OSTime __OSLastInterruptTime; // fzgx-allow: S2 SDK asynchronous state

OSErrorHandler __OSErrorTable[(16 + 1)];

u32 __OSFpscrEnableBits = (1 << (31 - 24)) | (1 << (31 - 25)) | (1 << (31 - 26)) |
                          (1 << (31 - 27)) | (1 << (31 - 28));

void OSReport(const char *msg, ...) {
    va_list marker;
    ((void)msg, __builtin_va_info(&marker));
    vprintf(msg, marker);
    (void)0;
}

void OSPanic(const char *file, int line, const char *msg, ...) {
    va_list marker;
    u32 i;
    u32 *p;
    OSDisableInterrupts();
    ((void)msg, __builtin_va_info(&marker));
    vprintf(msg, marker);
    (void)0;
    OSReport(" in \"%s\" on line %d.\n", file, line);
    OSReport("\nAddress:      Back Chain    LR Save\n");
    for (i = 0, p = (u32 *)fn_8000BFC0(); p && (u32)p != 0xffffffff && i++ < 16; p = (u32 *)*p) {
        OSReport("0x%08x:   0x%08x    0x%08x\n", p, p[0], p[1]);
    }
    PPCHalt();
}

OSErrorHandler OSSetErrorHandler(OSError error, OSErrorHandler handler) {
    OSErrorHandler oldHandler;
    BOOL enabled;
    enabled = OSDisableInterrupts();
    oldHandler = __OSErrorTable[error];
    __OSErrorTable[error] = handler;
    if (error == 16) {
        u32 msr;
        u32 fpscr;
        OSThread *thread;
        msr = PPCMfmsr();
        PPCMtmsr(msr | (1 << (31 - 18)));
        fpscr = PPCMffpscr();
        if (handler) {
            for (thread = __OSActiveThreadQueue.head; thread; thread = thread->linkActive.next) {
                thread->context.srr1 |= (1 << (31 - 20)) | (1 << (31 - 23));
                if ((thread->context.state & 0x01u) == 0) {
                    int i;
                    thread->context.state |= 0x01u;
                    for (i = 0; i < 32; ++i) {
                        *(u64 *)&thread->context.fpr[i] = (u64)0xffffffffffffffffLL;
                        *(u64 *)&thread->context.psf[i] = (u64)0xffffffffffffffffLL;
                    }
                    thread->context.fpscr = (1 << (31 - 29));
                }
                thread->context.fpscr |=
                    __OSFpscrEnableBits & ((1 << (31 - 24)) | (1 << (31 - 25)) | (1 << (31 - 26)) |
                                           (1 << (31 - 27)) | (1 << (31 - 28)));
                thread->context.fpscr &=
                    ~((1 << (31 - 12)) | (1 << (31 - 11)) | (1 << (31 - 10)) | (1 << (31 - 9)) |
                      (1 << (31 - 8)) | (1 << (31 - 7)) | (1 << (31 - 21)) | (1 << (31 - 22)) |
                      (1 << (31 - 23)) | (1 << (31 - 6)) | (1 << (31 - 5)) | (1 << (31 - 4)) |
                      (1 << (31 - 3)) | (1 << (31 - 0)) | (1 << (31 - 14)));
            }
            fpscr |= __OSFpscrEnableBits & ((1 << (31 - 24)) | (1 << (31 - 25)) | (1 << (31 - 26)) |
                                            (1 << (31 - 27)) | (1 << (31 - 28)));
            msr |= (1 << (31 - 20)) | (1 << (31 - 23));
        } else {
            for (thread = __OSActiveThreadQueue.head; thread; thread = thread->linkActive.next) {
                thread->context.srr1 &= ~((1 << (31 - 20)) | (1 << (31 - 23)));
                thread->context.fpscr &= ~((1 << (31 - 24)) | (1 << (31 - 25)) | (1 << (31 - 26)) |
                                           (1 << (31 - 27)) | (1 << (31 - 28)));
                thread->context.fpscr &=
                    ~((1 << (31 - 12)) | (1 << (31 - 11)) | (1 << (31 - 10)) | (1 << (31 - 9)) |
                      (1 << (31 - 8)) | (1 << (31 - 7)) | (1 << (31 - 21)) | (1 << (31 - 22)) |
                      (1 << (31 - 23)) | (1 << (31 - 6)) | (1 << (31 - 5)) | (1 << (31 - 4)) |
                      (1 << (31 - 3)) | (1 << (31 - 0)) | (1 << (31 - 14)));
            }
            fpscr &= ~((1 << (31 - 24)) | (1 << (31 - 25)) | (1 << (31 - 26)) | (1 << (31 - 27)) |
                       (1 << (31 - 28)));
            msr &= ~((1 << (31 - 20)) | (1 << (31 - 23)));
        }
        fpscr &= ~((1 << (31 - 12)) | (1 << (31 - 11)) | (1 << (31 - 10)) | (1 << (31 - 9)) |
                   (1 << (31 - 8)) | (1 << (31 - 7)) | (1 << (31 - 21)) | (1 << (31 - 22)) |
                   (1 << (31 - 23)) | (1 << (31 - 6)) | (1 << (31 - 5)) | (1 << (31 - 4)) |
                   (1 << (31 - 3)) | (1 << (31 - 0)) | (1 << (31 - 14)));
        PPCMtfpscr(fpscr);
        PPCMtmsr(msr);
    }
    OSRestoreInterrupts(enabled);
    return oldHandler;
}

void __OSUnhandledException(__OSException exception, OSContext *context, u32 dsisr, u32 dar) {
    OSTime now;

    now = OSGetTime();
    if (!((((1 << (31 - 30))) & (context->srr1)))) {
        OSReport("Non-recoverable Exception %d", exception);
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
        OSReport("Unhandled Exception %d", exception);
    }
    OSReport("\n");
    OSDumpContext(context);
    OSReport("\nDSISR = 0x%08x                   DAR  = 0x%08x\n", dsisr, dar);
    OSReport("TB = 0x%016llx\n", now);
    switch (exception) {
    case 2:
        OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access invalid address 0x%x "
                 "(read from DAR)\n",
                 context->srr0, dar);
        break;
    case 3:
        OSReport("\nAttempted to fetch instruction from invalid address 0x%x (read from SRR0)\n",
                 context->srr0);
        break;
    case 5:
        OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access unaligned address "
                 "0x%x (read from DAR)\n",
                 context->srr0, dar);
        break;
    case 6:
        OSReport("\nProgram exception : Possible illegal instruction/operation at or around 0x%x "
                 "(read from SRR0)\n",
                 context->srr0, dar);
        break;
    case 15:
        OSReport("\n");
        OSReport("AI DMA Address =   0x%04x%04x\n", __DSPRegs[0x00000018], __DSPRegs[0x00000018 + 1]);
        OSReport("ARAM DMA Address = 0x%04x%04x\n", __DSPRegs[0x00000010], __DSPRegs[0x00000010 + 1]);
        OSReport("DI DMA Address =   0x%08x\n", __DIRegs[0x00000005]);
        break;
    }
    OSReport("\nLast interrupt (%d): SRR0 = 0x%08x  TB = 0x%016llx\n", __OSLastInterrupt,
             __OSLastInterruptSrr0, __OSLastInterruptTime);
    PPCHalt();
}
