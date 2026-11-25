#include <dolphin/os.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSReset.h>
#include <dolphin/types.h>
#include <dolphin/base/PPCArch.h>
#include <dolphin/os/OSError.h>
#include "sdk_addresses.h"
#include "types.h"

u32 OSGetPhysicalMemSize(void) {
    return *(u32 *)FZGX_ADDR___OSPhysicalMemSize;
}

u32 OSGetConsoleSimulatedMemSize(void) {
    return *(u32 *)FZGX_ADDR___OSSimulatedMemSize;
}

vu16 __MEMRegs[64] : FZGX_ADDR___MEMRegs;

BOOL OnReset(BOOL final) {
    if (final != 0) {
        __MEMRegs[8] = 0xFF;
        __OSMaskInterrupts(0xf0000000);
    }
    return 1;
}

extern OSErrorHandler __OSErrorTable[(16 + 1)];


void MEMIntrruptHandler(__OSInterrupt interrupt, OSContext *context) {
    u32 addr;
    u32 cause;
    cause = __MEMRegs[0xf];
    addr = (((u32)__MEMRegs[0x12] & 0x3ff) << 16) | __MEMRegs[0x11];
    __MEMRegs[0x10] = 0;
    if (__OSErrorTable[15]) {
        __OSErrorTable[15](15, context, cause, addr);
        return;
    }
    __OSUnhandledException(15, context, cause, addr);
}

/* Dolphin SDK os/OSMemory.c: Config24MB, Config48MB and RealMode are CodeWarrior asm
 * functions in the original. They program the instruction and data BATs (mtspr IBAT/DBAT)
 * and leave real mode with rfi through SRR0/SRR1, with no compiler frame. */
static asm void Config24MB(void) {
    nofralloc
    li r7, 0x0
    lis r4, 0x0
    addi r4, r4, 0x2
    lis r3, 0x8000
    addi r3, r3, 0x1ff
    lis r6, 0x100
    addi r6, r6, 0x2
    lis r5, 0x8100
    addi r5, r5, 0xff
    isync
    mtspr DBAT0U, r7
    mtspr DBAT0L, r4
    mtspr DBAT0U, r3
    isync
    mtspr IBAT0U, r7
    mtspr IBAT0L, r4
    mtspr IBAT0U, r3
    isync
    mtspr DBAT2U, r7
    mtspr DBAT2L, r6
    mtspr DBAT2U, r5
    isync
    mtspr IBAT2U, r7
    mtspr IBAT2L, r6
    mtspr IBAT2U, r5
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtsrr1 r3
    mflr r3
    mtsrr0 r3
    rfi
}

static asm void Config48MB(void) {
    nofralloc
    li r7, 0x0
    lis r4, 0x0
    addi r4, r4, 0x2
    lis r3, 0x8000
    addi r3, r3, 0x3ff
    lis r6, 0x200
    addi r6, r6, 0x2
    lis r5, 0x8200
    addi r5, r5, 0x1ff
    isync
    mtspr DBAT0U, r7
    mtspr DBAT0L, r4
    mtspr DBAT0U, r3
    isync
    mtspr IBAT0U, r7
    mtspr IBAT0L, r4
    mtspr IBAT0U, r3
    isync
    mtspr DBAT2U, r7
    mtspr DBAT2L, r6
    mtspr DBAT2U, r5
    isync
    mtspr IBAT2U, r7
    mtspr IBAT2L, r6
    mtspr IBAT2U, r5
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtsrr1 r3
    mflr r3
    mtsrr0 r3
    rfi
}

static asm void RealMode(register u32 addr) {
    nofralloc
    clrlwi addr, addr, 2
    mtsrr0 addr
    mfmsr addr
    rlwinm addr, addr, 0, 28, 25
    mtsrr1 addr
    rfi
}

#pragma peephole off

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);

void OSRegisterResetFunction(OSResetFunctionInfo *func);

extern OSResetFunctionInfo ResetFunctionInfo;

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
        RealMode((u32)&Config24MB);
    } else if (simulatedSize <= 0x3000000) {
        RealMode((u32)&Config48MB);
    }
    __OSUnmaskInterrupts((0x80000000u >> (4)));
    OSRestoreInterrupts(enabled);
}
