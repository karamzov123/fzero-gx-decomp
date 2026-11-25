#include "sdk_addresses.h"
#include <dolphin/os.h>
#include "types.h"
#pragma peephole off

/* Dolphin SDK os/OSSync.c. SystemCallVector is a CodeWarrior asm function in the original
 * (HID0 access and rfi, no compiler frame); __OSInitSystemCall copies it to the system call
 * exception vector between its two entry labels. */

void *memcpy(void *dest, const void *src, size_t n);

void __OSSystemCallVectorStart(void);
void __OSSystemCallVectorEnd(void);

asm void SystemCallVector(void) {
entry __OSSystemCallVectorStart
    nofralloc
    mfspr r9, HID0
    ori r10, r9, 0x8
    mtspr HID0, r10
    isync
    sync
    mtspr HID0, r9
    rfi
entry __OSSystemCallVectorEnd
    nop
}

void __OSInitSystemCall(void) {
    void *addr = (void *)FZGX_ADDR___OSSystemCallVectorAddress;
    memcpy(addr, __OSSystemCallVectorStart,
           (size_t)__OSSystemCallVectorEnd - (size_t)__OSSystemCallVectorStart);
    DCFlushRangeNoSync(addr, 0x100);
    __sync();
    ICInvalidateRange(addr, 0x100);
}

// fn_80010140: empty in retail (single blr).
void fn_80010140(void) {
}
