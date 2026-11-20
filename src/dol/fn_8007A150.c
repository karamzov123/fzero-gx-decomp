#include "types.h"


/* --- dol/fn_8007A150.c --- */
extern u32 __begin_critical_region(u32);
extern u32 __end_critical_region(u32);
extern u32 fn_8007A23C(u32, u32);
extern u32 lbl_801A3380[];
extern u32 memset(u32, u32, u32);
extern u8 lbl_801A6DD8;

u32 fn_8007A150(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0, t1, t2, t3;
    t0 = __begin_critical_region(1);
    v0 = t0;
    v1 = arg1;
    v2 = arg2;
    if (lbl_801A6DD8 == 0) {
    v1 = 0;
    v0 = (u32)&lbl_801A3380;
    v2 = 52;
    t1 = memset((u32)v0, v1, v2);
    v0 = t1;
    lbl_801A6DD8 = 1;
    }
    v1 = arg0;
    v0 = (u32)&lbl_801A3380;
    t2 = fn_8007A23C((u32)v0, v1);
    v0 = t2;
    v0 = 1;
    t3 = __end_critical_region(v0);
    v0 = t3;
    return v0;
}

/* --- dol/fn_8007A1C0.c --- */
extern u32 fn_8007A294(u32, u32);

u32 fn_8007A1C0(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0, t1, t2, t3;
    t0 = __begin_critical_region(1);
    v0 = t0;
    v1 = arg0;
    v2 = 0;
    if (lbl_801A6DD8 == 0) {
    v1 = 0;
    v0 = (u32)&lbl_801A3380;
    v2 = 52;
    t1 = memset((u32)v0, v1, v2);
    v0 = t1;
    lbl_801A6DD8 = 1;
    }
    v1 = arg0;
    v0 = (u32)&lbl_801A3380;
    t2 = fn_8007A294((u32)v0, v1);
    v0 = t2;
    v1 = 1;
    t3 = __end_critical_region(v1);
    return v0;
}
