#include "types.h"


/* --- dol/fn_8004C05C.c --- */
extern u32 fn_80041660(u32);
extern u32 fn_800474E4(u32);
extern u32 lbl_80090C88[];

s32 fn_8004C05C(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80090C88;
    t0 = fn_800474E4(v0);
    v0 = t0;
    v0 = -1;
    } else {
    if ((s8)*(u8 *)(v0 + 1) >= 2) {
    v0 = *(u32 *)(v0 + 4);
    t1 = fn_80041660(v0);
    v0 = t1;
    } else {
    v0 = 0;
    }
    }
    return v0;
}

/* --- dol/fn_8004C0B4.c --- */
extern u32 fn_80041684(u32);
extern u32 lbl_80090CB4[];

s32 fn_8004C0B4(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80090CB4;
    t0 = fn_800474E4(v0);
    v0 = t0;
    v0 = -1;
    } else {
    if ((s8)*(u8 *)(v0 + 1) >= 2) {
    v0 = *(u32 *)(v0 + 4);
    t1 = fn_80041684(v0);
    v0 = t1;
    } else {
    v0 = 0;
    }
    }
    return v0;
}

/* --- dol/fn_8004C10C.c --- */
extern u32 fn_800415F4(u32);
extern u32 lbl_80090F60[];

s32 fn_8004C10C(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80090F60;
    t0 = fn_800474E4(v0);
    v0 = t0;
    v0 = -1;
    } else {
    if ((s8)*(u8 *)(v0 + 1) >= 2) {
    v0 = *(u32 *)(v0 + 4);
    t1 = fn_800415F4(v0);
    v0 = t1;
    } else {
    v0 = 0;
    }
    }
    return v0;
}
