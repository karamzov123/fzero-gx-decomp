#include "types.h"


/* --- dol/__OSSetInterruptHandler.c --- */
extern u32 InterruptHandlerTable;

u32 __OSSetInterruptHandler(u32 arg0, u32 arg1) {
    s16 v0;
    u32 v1;
    u32 v2;
    v0 = (s16)arg0;
    v1 = (InterruptHandlerTable + (v0 << 2));
    v2 = *(u32 *)((u8 *)v1 + 0);
    *(u32 *)((u8 *)v1 + 0) = arg1;
    return v2;
}

/* --- dol/__OSGetInterruptHandler.c --- */
u32 __OSGetInterruptHandler(u32 arg0) {
    return *(u32 *)((u8 *)InterruptHandlerTable + ((s16)arg0 << 2));
}
