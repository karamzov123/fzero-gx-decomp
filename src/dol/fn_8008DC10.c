#include "types.h"

extern u8 fn_8008D7B0(void *arg0, void *arg1, u32 *arg2);
extern s32 fn_8008A754(void);
extern u32 fn_8008CB20(u32 arg0, u32 arg1, u32 *arg2, void *arg3);

s32 fn_8008DC10(void *arg0, void *arg1, u32 *arg2) {
    u32 v0;
    u32 v1;

    if (!fn_8008D7B0(arg0, arg1, arg2)) {
        return 1;
    }
    if (fn_8008A754() == 0) {
        return 1;
    }
    v0 = *arg2;
    v1 = fn_8008CB20(0xd0, 1, &v0, arg1);
    *arg2 = v0;
    switch ((v1 & 0xff)) {
    case 0:
        return 0;
    case 2:
        return 2;
    default:
        return 1;
    }
}
