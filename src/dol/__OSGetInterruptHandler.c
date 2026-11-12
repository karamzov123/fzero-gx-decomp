#include "types.h"

extern u32 InterruptHandlerTable;

u32 __OSGetInterruptHandler(u32 arg0) {
    return *(u32 *)((u8 *)InterruptHandlerTable + ((s16)arg0 << 2));
}
