#include "types.h"


/* --- dol/GXSetTexRegionCallback.c --- */
extern u32 gx;

u32 GXSetTexRegionCallback(u32 arg0) {
    u32 *p;
    u32 v0;

    p = (u32 *)gx + 0x410 / 4;
    v0 = *p++;
    p--;
    *p = arg0;
    return v0;
}

/* --- dol/GXSetTlutRegionCallback.c --- */
u32 GXSetTlutRegionCallback(u32 value) {
    u32 *p;
    u32 old;

    p = (u32 *)gx;
    p = (u32 *)((u8 *)p + 0x414);
    old = *p;
    *p = value;
    return old;
}
