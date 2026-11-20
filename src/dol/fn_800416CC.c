#include "types.h"


/* --- dol/fn_800416CC.c --- */
struct fn_800416CC_Arg0 {
    u8 pad_0[0x44];
    u32 unk_44;
};

void fn_800416CC(struct fn_800416CC_Arg0 *arg0, u32 arg1) {
    arg0->unk_44 = arg1;
}

/* --- dol/fn_800416D4.c --- */
struct fn_800416D4_Arg0 {
    u8 pad_0[0x40];
    u32 unk_40;
};

void fn_800416D4(struct fn_800416D4_Arg0 *arg0, u32 arg1) {
    arg0->unk_40 = arg1;
}

/* --- dol/fn_800416DC.c --- */
struct fn_800416DC_Arg0 {
    u8 pad_0[0x3C];
    u32 unk_3C;
};

void fn_800416DC(struct fn_800416DC_Arg0 *arg0, u32 arg1) {
    arg0->unk_3C = arg1;
}

/* --- dol/fn_800416E4.c --- */
struct fn_800416E4_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
    u32 unk_4C;
};

void fn_800416E4(struct fn_800416E4_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_48 = arg1;
    arg0->unk_4C = arg2;
}

/* --- dol/fn_800416F0.c --- */
struct fn_800416F0_Arg0 {
    u8 pad_0[0x34];
    u32 unk_34;
};

void fn_800416F0(struct fn_800416F0_Arg0 *arg0, u32 arg1) {
    arg0->unk_34 = arg1;
}

/* --- dol/fn_800416F8.c --- */
struct fn_800416F8_Arg0 {
    u8 pad_0[0x2C];
    u32 unk_2C;
};

u32 fn_800416F8(struct fn_800416F8_Arg0 *arg0) {
    return arg0->unk_2C;
}
