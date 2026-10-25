#include "types.h"

extern u32 gx;

u32 GXSetTlutRegionCallback(u32 value) {
    u32 *p;
    u32 old;

    p = (u32 *)gx;
    p = (u32 *)((u8 *)p + 0x414);
    old = *p;
    *p = value;
    return old;
}
