#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma peephole off

void *memset(void *dest, int value, size_t n);

vu32 __PIRegs[12] : FZGX_ADDR___PIRegs;

asm void ExternalInterruptHandler_8000DD10(register __OSException exception,
                                           register OSContext *context);

extern __OSInterruptHandler *InterruptHandlerTable;

void ExternalInterruptHandler_8000DD10(register __OSException exception,
                                       register OSContext *context);

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
    __OSSetExceptionHandler(4, ExternalInterruptHandler_8000DD10);
}
