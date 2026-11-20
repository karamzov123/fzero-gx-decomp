#include "types.h"


/* --- dol/fn_80054608.c --- */
struct fn_80054608_lbl_801873D8 {
    u32 unk_0;
};
struct fn_80054608_lbl_80091388 {
    u32 unk_0;
};

extern struct fn_80054608_lbl_80091388 lbl_80091388[];
extern struct fn_80054608_lbl_801873D8 lbl_801873D8[];
extern u32 fn_80051958(u32);
extern u32 lbl_801873EC[];
extern u32 memset(u32, u32, u32);

u32 fn_80054608(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 t0, t1;
    v0 = lbl_80091388[0].unk_0;
    v1 = arg1;
    if ((s32)lbl_801873D8[0].unk_0 == 0) {
    t0 = fn_80051958(v0);
    v0 = t0;
    v1 = 0;
    v0 = (u32)&lbl_801873EC;
    t1 = memset((u32)v0, v1, 64);
    v0 = t1;
    }
    v1 = (u32)&lbl_801873D8;
    v0 = *(u32 *)((u8 *)v1 + 0);
    *(u32 *)((u8 *)v1 + 0) = (v0 + 1);
    return v0;
}

/* --- dol/fn_8005466C.c --- */
extern u32 lbl_80187430[];
extern u32 lbl_80187434[80];

void fn_8005466C(u32 arg0, u32 arg1) {
    if (arg0 == 0) {
        lbl_80187430[0] = 0;
        lbl_80187434[0] = 0;
    } else {
        lbl_80187430[0] = arg0;
        lbl_80187434[0] = arg1;
    }
}

/* --- dol/fn_800546A0.c --- */
typedef u32 (*fn_800546A0_Fn0)(u32, u32, u32);
typedef u32 (*fn_800546A0_Fn1)(u32);

struct fn_800546A0_Object {
    u32 vtable;
    u32 value;
};

extern char lbl_80091C48[28];
extern char lbl_80091C64[26];

s32 fn_800546A0(struct fn_800546A0_Object *arg0) {
    s32 result = 3;

    if (arg0 == 0) {
        if (lbl_80187430[0] != 0) {
            ((fn_800546A0_Fn0)lbl_80187430[0])(lbl_80187434[0], (u32)&lbl_80091C48, 0);
        }
        return 3;
    } else if (*(u32 *)((u8 *)arg0->vtable + 44) != 0) {
        result = ((fn_800546A0_Fn1)*(u32 *)((u8 *)arg0->vtable + 44))(arg0->value);
    } else if (lbl_80187430[0] != 0) {
        ((fn_800546A0_Fn0)lbl_80187430[0])(lbl_80187434[0], (u32)&lbl_80091C64, 0);
    }

    return result;
}
