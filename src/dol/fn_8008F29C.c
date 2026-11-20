#include "types.h"

extern u32 fn_8008E770(u32, u32, u32, u32);
extern u32 fn_8008E9B4(u32);
extern u32 fn_8008EBF8(u32);
extern u32 fn_8008EC78(void);

#pragma opt_common_subs off
s32 fn_8008F29C(u8 *arg0, u32 arg1) {
    u8 *v0;
    s32 v1;
    s32 v8;
    u32 v3;
    struct { u32 value; } v5;
    u32 v6;
    u32 v2;
    struct { u32 a[1]; } loc_28;
    u32 loc_24;
    u32 loc_18[3];
    u32 loc_10[2];
    v0 = arg0;
    loc_28.a[0] = arg1;
    v1 = 0;
    while (!v1) {
        v1 = fn_8008EBF8(5);
    }
    if (v1 == 0) return 1;
    loc_18[0] = 0x80000000;
    fn_8008E9B4(fn_8008E770((u32)loc_18, 2, 1, 0));
    fn_8008E9B4(fn_8008E770((u32)&loc_28, 4, 1, 0));
    {
        u32 v9 = loc_28.a[0];
        if ((v9 & 3) != 0) v2 = 1;
        else v2 = 0;
        v3 = (v9 >> 2) + v2;
    }
    v5.value = 0;
    while (v5.value < v3) {
        u8 *v7;
        if (v5.value < v3 - 1) v6 = 4;
        else if ((loc_28.a[0] & 3) + (loc_28.a[0] & 1) == 2) v6 = 2;
        else v6 = 4;
        v7 = v0;
        v0 += 4;
        fn_8008E9B4(fn_8008E770((u32)v7, v6, 1, 0));
        v5.value++;
    }
    fn_8008EC78();
    v8 = 0;
    while (((0) == v8)) {
        v8 = fn_8008EBF8(5);
    }
    if (((0) == v8)) return 1;
    loc_10[0] = 0x10000;
    fn_8008E9B4(fn_8008E770((u32)loc_10, 2, 1, 0));
    fn_8008E9B4(fn_8008E770((u32)&loc_24, 2, 0, 0));
    do {
        fn_8008E9B4(fn_8008E770((u32)&loc_24, 2, 0, 0));
    } while (((loc_24 >> 16) & 1) == 0);
    fn_8008EC78();
    return 0;
}
#pragma opt_common_subs reset

