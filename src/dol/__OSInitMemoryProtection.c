#include <dolphin/os.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSReset.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma peephole off

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);

u32 OSGetConsoleSimulatedMemSize(void);

u32 OSGetPhysicalMemSize(void);

void OSRegisterResetFunction(OSResetFunctionInfo *func);

vu16 __MEMRegs[64] : FZGX_ADDR___MEMRegs;

extern OSResetFunctionInfo ResetFunctionInfo;

static inline u32 OSGetPhysicalMemSize() { return *(u32 *)FZGX_ADDR___OSPhysicalMemSize; }

static inline u32 OSGetConsoleSimulatedMemSize() { return *(u32 *)FZGX_ADDR___OSSimulatedMemSize; }

void MEMIntrruptHandler(__OSInterrupt interrupt, OSContext *context);

void Config24MB_8000E854();

void Config48MB_8000E8D4();

void RealMode_8000E954(register u32 addr);

void __OSInitMemoryProtection() {
    u32 padding[8];
    u32 simulatedSize;
    BOOL enabled;
    simulatedSize = OSGetConsoleSimulatedMemSize();
    enabled = OSDisableInterrupts();
    __MEMRegs[16] = 0;
    __MEMRegs[8] = 0xFF;
    __OSMaskInterrupts((0x80000000u >> (0)) | (0x80000000u >> (1)) | (0x80000000u >> (2)) |
                       (0x80000000u >> (3)));
    __OSSetInterruptHandler(0, MEMIntrruptHandler);
    __OSSetInterruptHandler(1, MEMIntrruptHandler);
    __OSSetInterruptHandler(2, MEMIntrruptHandler);
    __OSSetInterruptHandler(3, MEMIntrruptHandler);
    __OSSetInterruptHandler(4, MEMIntrruptHandler);
    OSRegisterResetFunction(&ResetFunctionInfo);
    if (OSGetConsoleSimulatedMemSize() < OSGetPhysicalMemSize() &&
        OSGetConsoleSimulatedMemSize() == 0x1800000) {
        DCInvalidateRange((void *)FZGX_ADDR___OSUnmappedMemory, 0x1800000);
        __MEMRegs[20] = 2;
    }
    if (simulatedSize <= 0x1800000) {
        RealMode_8000E954((u32)&Config24MB_8000E854);
    } else if (simulatedSize <= 0x3000000) {
        RealMode_8000E954((u32)&Config48MB_8000E8D4);
    }
    __OSUnmaskInterrupts((0x80000000u >> (4)));
    OSRestoreInterrupts(enabled);
}
