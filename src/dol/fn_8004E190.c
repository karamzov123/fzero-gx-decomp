#include "types.h"


/* --- dol/fn_8004E190.c --- */
/* --- dol/fn_8004E190.c --- */
struct Fn8004E190 {
    u8 pad_0[0x10];
    u32 field_10;
};

u32 fn_8004E190(struct Fn8004E190 *arg) {
    return arg->field_10;
}

/* --- dol/fn_8004E198.c --- */
struct fn_8004E198_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

void fn_8004E198(struct fn_8004E198_Arg0 *arg0) {
    if ((s32)arg0->unk_C != 3) { return; }
    arg0->unk_C = 0;
}

/* --- dol/fn_8004E1B0.c --- */
/* --- dol/fn_8004E1B0.c --- */
extern u32 memset(u32, u32, u32);

struct fn_8004E1B0_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

void fn_8004E1B0(struct fn_8004E1B0_Arg0 *arg0) {
    arg0->unk_C = 0;
    memset(((u32)arg0 + 40), 0, 8);
}

/* --- dol/fn_8004E1E4.c --- */
struct fn_8004E1E4_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
};

void fn_8004E1E4(struct fn_8004E1E4_Arg0 *arg0) {
    if ((s32)arg0->unk_C != 0) { return; }
    arg0->unk_10 = 0;
    arg0->unk_C = 1;
}

/* --- dol/fn_8004E204.c --- */
struct fn_8004E204_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

s32 fn_8004E204(struct fn_8004E204_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 v0;
    v0 = (u32)arg0;
    if ((s32)arg0->unk_C == 0) {
    *(u32 *)((u8 *)v0 + 20) = 2;
    *(u32 *)((u8 *)v0 + 24) = arg1;
    *(u32 *)((u8 *)v0 + 28) = arg2;
    *(u32 *)((u8 *)v0 + 32) = arg3;
    *(u32 *)((u8 *)v0 + 36) = arg4;
    v0 = 1;
    return v0;
    }
    v0 = 0;
    return v0;
}

/* --- dol/fn_8004E238.c --- */
typedef struct {
    u8 _pad[0x0c];
    s32 field_0c;
    u8 _pad_10[0x04];
    s32 field_14;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    s32 field_24;
} Fn8004E238Data;

s32 fn_8004E238(Fn8004E238Data* data, u32 arg_1, u32 arg_2, u32 arg_3) {
    if (data->field_0c == 0) {
        data->field_14 = 1;
        data->field_18 = arg_1;
        data->field_1c = arg_2;
        data->field_20 = arg_3;
        data->field_24 = 0;
        return 1;
    }
    return 0;
}

/* --- dol/fn_8004E270.c --- */
struct fn_8004E270_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

u32 fn_8004E270(struct fn_8004E270_Arg0 *arg0) {
    return arg0->unk_C;
}

/* --- dol/fn_8004E278.c --- */
struct fn_8004E278_Arg0 {
    u32 unk_0;
};

void fn_8004E278(struct fn_8004E278_Arg0 *arg0) {
    if ((u32)arg0 != 0) {
    arg0->unk_0 = 0;
    memset((u32)arg0, 0, 60);
    }
}

/* --- dol/fn_8004E2B0.c --- */
/* --- dol/fn_8004E2B0.c --- */
typedef struct {
    u8 _pad[0x34];
    s16 field_34;
    s16 field_36;
    s16 field_38;
} Fn8004E2B0Data;

void fn_8004E2B0(Fn8004E2B0Data* data, s16* value_1, s16* value_2, s16* value_3) {
    *value_1 = data->field_34;
    *value_2 = data->field_36;
    *value_3 = data->field_38;
}

/* --- dol/fn_8004E2CC.c --- */
struct fn_8004E2CC_Arg0 {
    u8 pad_0[0x34];
    u16 unk_34;
    u16 unk_36;
    u16 unk_38;
};

void fn_8004E2CC(struct fn_8004E2CC_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    arg0->unk_34 = arg1;
    arg0->unk_36 = arg2;
    arg0->unk_38 = arg3;
}

/* --- dol/fn_8004E2DC.c --- */
struct fn_8004E2DC_Arg0 {
    u8 pad_0[0x28];
    s16 unk_28;
    s16 unk_2A;
    s16 unk_2C;
    s16 unk_2E;
};
struct fn_8004E2DC_Arg1 {
    u16 unk_0;
    u16 unk_2;
};
struct fn_8004E2DC_Arg2 {
    u16 unk_0;
    u16 unk_2;
};

void fn_8004E2DC(struct fn_8004E2DC_Arg0 *arg0, struct fn_8004E2DC_Arg1 *arg1, struct fn_8004E2DC_Arg2 *arg2) {
    arg1->unk_0 = arg0->unk_28;
    arg2->unk_0 = arg0->unk_2A;
    arg1->unk_2 = arg0->unk_2C;
    arg2->unk_2 = arg0->unk_2E;
}

/* --- dol/fn_8004E300.c --- */
struct Fn8004E300 {
    u8 pad_0[0x28];
    s16 field_28;
    s16 field_2A;
    s16 field_2C;
    s16 field_2E;
};

void fn_8004E300(struct Fn8004E300* dst, s16* value_1, s16* value_2) {
    dst->field_28 = value_1[0];
    dst->field_2A = value_2[0];
    dst->field_2C = value_1[1];
    dst->field_2E = value_2[1];
}

/* --- dol/fn_8004E324.c --- */
extern u32 fn_80046D94(u32, u32, u32, u32);

void fn_8004E324(u32 arg0, u32 arg1, u32 arg2) {
    fn_80046D94(arg2, arg1, (arg0 + 48), (arg0 + 50));
}
