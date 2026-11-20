#include "types.h"

extern u32 fn_80026D90(u32, u32);
extern u32 fn_8005A628(void);
extern u32 fn_8005A648(void);

u32 fn_8005A74C(u32 arg0, u32 arg1) {
    u32 v5;
    u32 v3;
    s32 v4;
    u32 v2;
    u32 v1;
    u32 v0;
    u32 t0, t1, t2;
    v0 = arg0;
    v1 = arg1;
    if (arg0 != 0) {
    v2 = (v1 & ((s32)v1 >> 31));
    v3 = -999;
    if ((s32)v2 > -999) {
    v3 = v2;
    }
    if ((s32)v3 != (s32)*(u32 *)(arg0 + 132)) {
    *(u32 *)((u8 *)arg0 + 132) = v3;
    v4 = 0;
    v5 = arg0;
    while (v4 < (s8)*(u8 *)(arg0 + 2)) {
    t0 = fn_8005A648();
    v0 = t0;
    v0 = *(u32 *)(v5 + 8);
    if (v0 != 0) {
    v1 = v3;
    t1 = fn_80026D90(v0, v1);
    v0 = t1;
    }
    t2 = fn_8005A628();
    v0 = t2;
    v5 += 4;
    v4++;
    }
    }
    }
    return v0;
}
