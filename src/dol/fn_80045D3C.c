#include "types.h"

extern u32 fn_8004E278(u32);
extern u32 memset(u32, u32, u32);

u32 fn_80045D3C(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if (arg0 != 0) {
    v0 = *(u32 *)(arg0 + 8);
    *(u32 *)((u8 *)arg0 + 8) = 0;
    t0 = fn_8004E278(v0);
    v0 = t0;
    v0 = arg0;
    t1 = memset(v0, 0, 216);
    v0 = t1;
    *(u16 *)((u8 *)arg0 + 0) = 0;
    }
    return v0;
}
