#include "types.h"

typedef u32 (*fn_800549F0_Fn0)(u32, u32, u32);
typedef u32 (*fn_800549F0_Fn1)(u32);
typedef u32 (*fn_800549F0_Fn2)(u32, u32, u32);
struct fn_800549F0_lbl_80187434 {
    u32 unk_0;    u8 pad_4[0x13C];
};

extern struct fn_800549F0_lbl_80187434 lbl_80187434[];
extern u32 lbl_80091D54[];
extern u32 lbl_80091D70[];
extern u32 lbl_80187430[];

s32 fn_800549F0(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0, t1, t2;
    v0 = arg0;
    if (arg0 == 0) {
    v1 = arg1;
    v2 = arg2;
    if (lbl_80187430[0] != 0) {
    v2 = (u32)&lbl_80187434;
    v1 = (u32)&lbl_80091D54;
    v0 = *(u32 *)(v2);
    v2 = 0;
    t0 = ((fn_800549F0_Fn0)lbl_80187430[0])(v0, v1, v2);
    v0 = t0;
    }
    v0 = 0;
    } else {
    v1 = *(u32 *)(v0);
    v2 = *(u32 *)(v1 + 28);
    if (v2 != 0) {
    v0 = *(u32 *)(v0 + 4);
    t1 = ((fn_800549F0_Fn1)v2)(v0);
    v0 = t1;
    v3 = v0;
    } else {
    v3 = 0;
    if (lbl_80187430[0] != 0) {
    v0 = lbl_80187434[0].unk_0;
    t2 = ((fn_800549F0_Fn2)lbl_80187430[0])(v0, (u32)&lbl_80091D70, 0);
    v0 = t2;
    }
    }
    v0 = v3;
    }
    return v0;
}
