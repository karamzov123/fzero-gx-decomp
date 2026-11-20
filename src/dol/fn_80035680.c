#include "types.h"


/* --- dol/fn_80035680.c --- */
struct fn_80035680_Arg1 {
    u8 pad_0[0x28];
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
};

void fn_80035680(f32 arg0, struct fn_80035680_Arg1 *arg1, f32 arg2, f32 arg3) {
    arg1->unk_28 = arg0;
    arg1->unk_2C = arg2;
    arg1->unk_30 = arg3;
}

/* --- dol/fn_80035690.c --- */
struct fn_80035690_Arg3 {
    u8 pad_0[0x34];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
};

f32 fn_80035690(f32 arg0, f32 arg1, f32 arg2, struct fn_80035690_Arg3 *arg3) {
    arg3->unk_34 = (-arg0);
    arg3->unk_38 = (-arg1);
    arg3->unk_3C = (-arg2);
    return (-arg1);
}

/* --- dol/fn_800356AC.c --- */
struct fn_800356AC_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};
struct fn_800356AC_Arg1 {
    u32 unk_0;
};

void fn_800356AC(struct fn_800356AC_Arg0 *arg0, struct fn_800356AC_Arg1 *arg1) {
    arg0->unk_C = arg1->unk_0;
}
