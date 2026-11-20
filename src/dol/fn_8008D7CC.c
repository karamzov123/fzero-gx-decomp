#include "types.h"


/* --- dol/fn_8008D7CC.c --- */
extern s32 fn_8008A754(u32 arg0);
extern u8 fn_8008CB38(u32 arg0, u32 arg1, u32 arg2, u8 arg3);

s32 fn_8008D7CC(u32 arg0, u32 arg1, s32 arg2) {
    s32 mode;
    u8 value;

    mode = 0;
    if (fn_8008A754(arg0) == 0) {
        return 1;
    }

    if (arg2 == 0) {
        mode = 0;
    } else if (arg2 == 1) {
        mode = 1;
    } else if (arg2 == 2) {
        mode = 2;
    }

    value = fn_8008CB38(0xD4, arg0, arg1, (u8)mode);
    switch (value) {
    case 0:
        return 0;
    case 2:
        return 2;
    case 1:
    default:
        return 1;
    }
}

/* --- dol/fn_8008D8A8.c --- */
extern u32 fn_8008CB30(u32, u32);

s32 fn_8008D8A8(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 t0, t1;
    t0 = fn_8008A754(arg0);
    v0 = t0;
    if ((s32)t0 == 0) {
    v0 = 1;
    } else {
    v0 = 211;
    t1 = fn_8008CB30(v0, arg0);
    v0 = t1;
    v1 = (v0 & 0xFF);
    switch ((s32)v1) {
    case 0:
    v0 = 0;
    break;
    case 2:
    v0 = 2;
    break;
    default:
    v0 = 1;
    }
    }
    return v0;
}
