#include "types.h"

typedef u32 (*fn_8005A0C0_Fn0)(u32, u32, u32);

extern u32 fn_80059AB4(void);
extern u32 fn_80059B44(void);
extern u32 lbl_800926F8[];
extern u32 lbl_80190178[];
extern u32 lbl_8019017C[];

#pragma opt_common_subs off
u32 fn_8005A0C0(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0, t1, t2;
    v0 = arg0;
    if (arg0 == 0) {
        v1 = arg1;
        v2 = arg2;
        if (lbl_80190178[0] != 0) {
            v2 = (u32)&lbl_8019017C;
            v1 = (u32)&lbl_800926F8;
            v0 = *(u32 *)(v2);
            v2 = 0;
            t0 = ((fn_8005A0C0_Fn0)lbl_80190178[0])(v0, v1, v2);
            v0 = t0;
        }
        v0 = 0;
    } else {
        t1 = fn_80059B44();
        v0 = t1;
        if ((s32)arg2 == 0) {
            *(u32 *)((u8 *)arg0 + 16) = arg1;
        } else {
            if ((s32)arg2 == 2) {
                *(u32 *)((u8 *)arg0 + 16) = (*(u32 *)((u8 *)arg0 + 12) + arg1);
            } else {
                if ((s32)arg2 == 1) {
                    *(u32 *)((u8 *)arg0 + 16) = (*(u32 *)((u8 *)arg0 + 16) + arg1);
                }
            }
        }
        v3 = *(u32 *)(arg0 + 12);
        v0 = *(u32 *)(arg0 + 16);
        if ((s32)v0 < (s32)v3) {
            v3 = v0;
        }
        *(u32 *)((u8 *)arg0 + 16) = v3;
        *(u32 *)((u8 *)arg0 + 16) = (s32)*(u32 *)((u8 *)arg0 + 16) > 0 ? *(u32 *)((u8 *)arg0 + 16) : 0;
        t2 = fn_80059AB4();
        v0 = t2;
        v0 = *(u32 *)(arg0 + 16);
    }
    return v0;
}
#pragma opt_common_subs reset

