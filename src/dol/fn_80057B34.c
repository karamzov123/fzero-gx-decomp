#include "types.h"


/* --- dol/fn_80057B34.c --- */
struct fn_80057B34_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0x4];
    u32 unk_18;
};

void fn_80057B34(struct fn_80057B34_Arg0 *arg0) {
    arg0->unk_C = arg0->unk_18;
    arg0->unk_10 = 0;
}

/* --- dol/fn_80057B48.c --- */
struct fn_80057B48_Arg0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
    u32 unk_20;
};

void fn_80057B48(struct fn_80057B48_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_1C = arg1;
    arg0->unk_20 = arg2;
}

/* --- dol/fn_80057B54.c --- */
struct fn_80057B54_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

u32 fn_80057B54(struct fn_80057B54_Arg0 *arg0) {
    return arg0->unk_8;
}
