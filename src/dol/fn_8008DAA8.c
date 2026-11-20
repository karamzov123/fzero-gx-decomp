#include "types.h"


/* --- dol/fn_8008DAA8.c --- */
extern s32 fn_8008A754(u32);
extern u32 fn_8008CB20(u32, u32, u32 *, u32);

s32 fn_8008DAA8(u32 arg0, u32 arg1, u32 *arg2) {
    u32 v0;
    u32 v1;

    if (fn_8008A754(arg0) == 0) {
        return 1;
    }
    v0 = *arg2;
    v1 = fn_8008CB20(0xd0, arg0, &v0, arg1);
    *arg2 = v0;
    switch ((s32)(v1 & 0xff)) {
    case 0:
        return 0;
    case 2:
        return 2;
    default:
        return 1;
    }
}

/* --- dol/fn_8008DB5C.c --- */
s32 fn_8008DB5C(u32 arg0, u32 arg1, u32 *arg2) {
    u32 v0;
    u32 v1;

    if (fn_8008A754(arg0) == 0) {
        return 1;
    }
    v0 = *arg2;
    v1 = fn_8008CB20(0xd1, arg0, &v0, arg1);
    *arg2 = v0;
    switch ((s32)(v1 & 0xff)) {
    case 0:
        return 0;
    case 2:
        return 2;
    default:
        return 1;
    }
}
