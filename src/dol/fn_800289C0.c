#include "types.h"


/* --- dol/fn_800289C0.c --- */
struct fn_800289C0_Arg0 {
    u8 pad_0[0x8];
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
};

void fn_800289C0(struct fn_800289C0_Arg0 *arg0) {
    if (arg0->unk_10 == arg0->unk_C) {
        return;
    }
    arg0->unk_10 += arg0->unk_8;
    if (arg0->unk_8 > 0) {
        if (arg0->unk_10 > arg0->unk_C) {
            arg0->unk_10 = arg0->unk_C;
        }
    } else if (arg0->unk_8 < 0) {
        if (arg0->unk_10 < arg0->unk_C) {
            arg0->unk_10 = arg0->unk_C;
        }
    }
}

/* --- dol/fn_80028A1C.c --- */
struct fn_80028A1C_Arg0 {
    u8 pad_0[0x8];
    s32 unk_8;
    s32 unk_c;
    s32 unk_10;
};

void fn_80028A1C(struct fn_80028A1C_Arg0 *arg0) {
    if (arg0->unk_10 == arg0->unk_c) {
        return;
    }
    arg0->unk_10 = arg0->unk_10 + arg0->unk_8;
    if (arg0->unk_8 > 0) {
        if (arg0->unk_10 > arg0->unk_c) {
            arg0->unk_10 = arg0->unk_c;
        }
    } else if (arg0->unk_8 < 0) {
        if (arg0->unk_10 < arg0->unk_c) {
            arg0->unk_10 = arg0->unk_c;
        }
    }
}
