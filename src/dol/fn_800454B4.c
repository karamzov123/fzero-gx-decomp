#include "types.h"


/* --- dol/fn_800454B4.c --- */
struct fn_800454B4_Arg0 {
    u8 pad_0[0xD2];
    s16 unk_D2[1];
};

s16 fn_800454B4(struct fn_800454B4_Arg0 *arg0, u32 arg1) {
    return arg0->unk_D2[arg1];
}

/* --- dol/fn_800454C4.c --- */
struct fn_800454C4_Arg0 {
    u8 pad_0[0xD0];
    s16 unk_D0;
};

s32 fn_800454C4(struct fn_800454C4_Arg0 *arg0) {
    return arg0->unk_D0;
}

/* --- dol/fn_800454CC.c --- */
struct fn_800454CC_Arg0 {
    u8 pad_0[0xBC];
    u32 unk_BC;
};

u32 fn_800454CC(struct fn_800454CC_Arg0 *arg0) {
    return arg0->unk_BC;
}

/* --- dol/fn_800454D4.c --- */
struct fn_800454D4_Arg0 {
    u8 pad_0[0x34];
    u32 unk_34;
};

u32 fn_800454D4(struct fn_800454D4_Arg0 *arg0) {
    return arg0->unk_34;
}

/* --- dol/fn_800454DC.c --- */
typedef struct Fn800454DCContext {
    u8 pad[0x30];
    u32 value;
} Fn800454DCContext;

u32 fn_800454DC(Fn800454DCContext *context) {
    return context->value;
}

/* --- dol/fn_800454E4.c --- */
u32 fn_800454E4(u32 arg0) {
    u32 v0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = 0;
    return v0;
    }
    v0 = *(u32 *)((u8 *)v0 + 44);
    return v0;
}

/* --- dol/fn_800454FC.c --- */
struct fn_800454FC_Arg0 {
    u8 pad_0[0x28];
    u32 unk_28;
};

u32 fn_800454FC(struct fn_800454FC_Arg0 *arg0) {
    return arg0->unk_28;
}

/* --- dol/fn_80045504.c --- */
struct fn_80045504_Arg0 {
    u8 pad_0[0x24];
    s16 unk_24;
};

s32 fn_80045504(struct fn_80045504_Arg0 *arg0) {
    return arg0->unk_24;
}

/* --- dol/fn_8004550C.c --- */
struct fn_8004550C_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

u32 fn_8004550C(struct fn_8004550C_Arg0 *arg0) {
    return arg0->unk_18;
}

/* --- dol/fn_80045514.c --- */
struct fn_80045514_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};

u32 fn_80045514(struct fn_80045514_Arg0 *arg0) {
    return arg0->unk_10;
}
