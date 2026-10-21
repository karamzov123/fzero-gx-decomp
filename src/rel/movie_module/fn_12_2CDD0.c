#include "types.h"

struct fn_12_2CDD0_Arg3 { u32 unk_0; };
struct fn_12_2CDD0_Copy12 { u32 a[3]; };

static inline s32 find_entry(u32 v1, u32 v2, u32 v3, u32 arg2, s32 v8, s32 v9, s32 v7, u32 v5) {
    struct { s32 value; } result;
#define v12 result.value
    struct { u32 value; } entry;
    s32 v11 = v8;
    u32 v4, v14;
    s32 v15;
    for (v12 = 0; v12 < v7; v12++) {
        entry.value = v1 + v11 * 12;
        v4 = *(u32 *)((u8 *)entry.value + 4);
        v14 = v4 + *(u32 *)((u8 *)entry.value + 8);
        if (v14 <= v5) {
            if (v4 <= arg2 && arg2 < v14) return v12;
        } else {
            if ((v4 <= arg2 && arg2 < v5) ||
                (v2 <= arg2 && arg2 < v14 - v3)) return v12;
        }
        v15 = v11 + 1;
        v11 = v15 - v9;
        if (v15 < v9) v11 = v15;
    }
    return -1;
}
#undef v12

s32 fn_12_2CDD0(void *arg0, s32 arg1, u32 arg2, struct fn_12_2CDD0_Arg3 *arg3) {
    u32 v4;
    s32 v11;
    struct { u32 value; } base;
#define v0 base.value
    s32 v12;
    u32 v13;
    u32 v5;
    u32 v1;
    s32 v8;
    s32 v9;
    u32 v2;
    u32 v3;
    s32 v7;
    u32 v14;
    s32 v15;
    s32 v16;
    s32 v17;
    u32 v18;
    arg3->unk_0 = -1;
    v0 = (u32)((u8 *)arg0 + arg1 * 116);
    v1 = *(u32 *)((u8 *)v0 + 4472);
    v2 = *(u32 *)((u8 *)v0 + 4440);
    v3 = *(u32 *)((u8 *)v0 + 4444);
    if (v1 == 0) return 0;
    v5 = v2 + v3;
    if (arg2 >= v5) arg2 -= v3;
    v7 = *(s32 *)((u8 *)v0 + 4480);
    if (v7 != 0) {
        v8 = *(s32 *)((u8 *)v0 + 4488);
        v9 = *(s32 *)((u8 *)v0 + 4476);
        v12 = find_entry(v1, v2, v3, arg2, v8, v9, v7, v5);
        if (v12 != -1) {
            v16 = v8 + v12;
            v17 = v16 - v9;
            if (v16 < v9) v17 = v16;
            *(s32 *)((u8 *)v0 + 4480) -= v12;
            *(s32 *)((u8 *)v0 + 4488) = v17;
            v18 = *(u32 *)((u8 *)v0 + 4472) + v17 * 12;
            *(struct fn_12_2CDD0_Copy12 *)arg3 = *(struct fn_12_2CDD0_Copy12 *)v18;
        }
    }
    return 0;
}
