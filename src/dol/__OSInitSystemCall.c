#include "sdk_addresses.h"
#include <dolphin/os.h>
#include "types.h"
#pragma peephole off

/* --- dol/__OSInitSystemCall.c --- */
void *memcpy(void *dest, const void *src, size_t n);

void __OSSystemCallVectorStart();

void __OSSystemCallVectorEnd();

void __OSInitSystemCall() {
    void *addr = ((void *)FZGX_ADDR___OSSystemCallVectorAddress);
    memcpy(addr, __OSSystemCallVectorStart,
           (size_t)__OSSystemCallVectorEnd - (size_t)__OSSystemCallVectorStart);
    DCFlushRangeNoSync(addr, 0x100);
    __sync();
    ICInvalidateRange(addr, 0x100);
}

/* --- dol/fn_80010140.c --- */
// fn_80010140: empty in retail (single blr).
void fn_80010140(void) {
}
