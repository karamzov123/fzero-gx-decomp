#include "types.h"


/* --- dol/fn_8004530C.c --- */
/* --- dol/fn_8004530C.c --- */
extern u32 fn_8004E198(u32);

struct fn_8004530C_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

u32 fn_8004530C(struct fn_8004530C_Arg0 *arg0) {
    u32 v0;
    u32 t0;
    v0 = (u32)arg0;
    if ((s32)arg0->unk_4 == 3) {
    v0 = *(u32 *)((u32)arg0 + 8);
    t0 = fn_8004E198(v0);
    v0 = t0;
    *(u32 *)((u8 *)(u32)arg0 + 140) = 0;
    *(u32 *)((u8 *)(u32)arg0 + 4) = 0;
    }
    return v0;
}

/* --- dol/fn_80045354.c --- */
extern u32 fn_8004E1B0(u32);

struct fn_80045354_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

void fn_80045354(struct fn_80045354_Arg0 *arg0) {
    fn_8004E1B0(arg0->unk_8);
    *(u32 *)((u8 *)(u32)arg0 + 4) = 0;
}

/* --- dol/fn_8004538C.c --- */
struct fn_8004538C_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_8004538C(struct fn_8004538C_Arg0 *arg0) {
    if ((s32)arg0->unk_4 != 0) { return; }
    arg0->unk_4 = 1;
}

/* --- dol/fn_800453A4.c --- */
struct fn_800453A4_Arg0 {
    u8 pad_0[0xD];
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u8 pad_10[0x38];
    u32 unk_48;
    u32 unk_4C;
    u8 pad_50[0x24];
    u32 unk_74;
    u8 pad_78[0x18];
    u32 unk_90;
    u32 unk_94;
    s16 unk_98;
};

u32 fn_800453A4(struct fn_800453A4_Arg0 *arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 unk_1;

    v0 = arg1;
    if (arg0->unk_98 == 0) {
        arg0->unk_48 = v0;
        v0 = arg0->unk_F;
        v0 = (s8)v0;
        v0 = ((s32)arg2 / (s32)v0);
        arg0->unk_4C = v0;
        arg0->unk_74 = 0;
        arg0->unk_90 = 0;
        arg0->unk_94 = 0;
        return (u32)arg0;
    }
    arg0->unk_48 = v0;
    unk_1 = (s8)arg0->unk_D / 8;
    arg0->unk_4C = ((s32)arg2 / (s32)(unk_1 * (s8)arg0->unk_E));
    arg0->unk_74 = 0;
    arg0->unk_90 = 0;
    arg0->unk_94 = 0;
}

/* --- dol/fn_80045414.c --- */
struct fn_80045414_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

u32 fn_80045414(struct fn_80045414_Arg0 *arg0) {
    return arg0->unk_4;
}

/* --- dol/fn_8004541C.c --- */
/* --- dol/fn_8004541C.c --- */
extern u32 fn_8004E2CC(u32, u32, u32, u32);
extern u32 fn_8004E300(u32, u32, u32);

struct fn_8004541C_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

void fn_8004541C(struct fn_8004541C_Arg0 *arg0) {
    fn_8004E300(arg0->unk_8, ((u32)arg0 + 168), ((u32)arg0 + 172));
    fn_8004E2CC(*(u32 *)((u8 *)arg0 + 8), *(s16 *)((u8 *)arg0 + 162), *(s16 *)((u8 *)arg0 + 164), *(s16 *)((u8 *)arg0 + 166));
}

/* --- dol/fn_80045468.c --- */
extern u32 fn_8004E2B0(u32, u32, u32, u32);
extern u32 fn_8004E2DC(u32, u32, u32);

struct fn_80045468_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

void fn_80045468(struct fn_80045468_Arg0 *arg0) {
    fn_8004E2DC(arg0->unk_8, ((u32)arg0 + 168), ((u32)arg0 + 172));
    fn_8004E2B0(*(u32 *)((u8 *)arg0 + 8), ((u32)arg0 + 162), ((u32)arg0 + 164), ((u32)arg0 + 166));
}

/* --- dol/fn_800454B4.c --- */
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
    v0 = *(u32 *)(v0 + 44);
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

/* --- dol/fn_8004551C.c --- */
struct fn_8004551C_Arg0 {
    u8 pad_0[0x98];
    s16 unk_98;
    s16 unk_9A;
};

u32 fn_8004551C(struct fn_8004551C_Arg0 *arg0) {
    if (arg0->unk_98 == 0) {
        return 0x10;
    }
    if (arg0->unk_98 == 2) {
        if (arg0->unk_9A == 2) {
            return 4;
        }
        if (arg0->unk_9A == 1) {
            return 8;
        }
        return 0x10;
    }
    if (arg0->unk_98 == 1) {
        return arg0->unk_9A == 2 ? 4 : 0x10;
    }
    return 0x10;
}
