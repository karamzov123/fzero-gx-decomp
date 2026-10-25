#include "types.h"

extern u32 InterruptHandlerTable_801A67A8;

u32 __OSGetInterruptHandler(u32 arg0) {
    return *(u32 *)((u8 *)InterruptHandlerTable_801A67A8 + ((s16)arg0 << 2));
}
