#include "types.h"

extern u32 fn_80046718(void);
extern u32 fn_80046738(void);
extern u32 memset(u32, u32, u32);

u32 fn_80047C08(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0, t1, t2, t3, t4;
    v0 = arg0;
    if (arg0 != 0) {
    t0 = fn_80046738();
    v0 = t0;
    v0 = *(u32 *)(arg0 + 128);
    v1 = arg1;
    v2 = arg2;
    if (v0 != 0) {
    if (v0 != 0) {
    v1 = 0;
    *(u8 *)((u8 *)v0 + 0) = 0;
    v2 = 144;
    t1 = memset(v0, v1, v2);
    v0 = t1;
    }
    }
    v0 = *(u32 *)(arg0 + 132);
    if (v0 != 0) {
    if (v0 != 0) {
    v1 = 0;
    *(u8 *)((u8 *)v0 + 0) = 0;
    v2 = 144;
    t2 = memset(v0, v1, v2);
    v0 = t2;
    }
    }
    v0 = arg0;
    v1 = 0;
    v2 = 4;
    t3 = memset(v0, v1, v2);
    v0 = t3;
    t4 = fn_80046718();
    v0 = t4;
    }
    return v0;
}
