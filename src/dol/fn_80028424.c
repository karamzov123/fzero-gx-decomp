#include "types.h"

typedef struct Fn80028424Node_u0 Fn80028424Node_u0;

struct Fn80028424Node_u0 {
    Fn80028424Node_u0 *next;
    Fn80028424Node_u0 *prev;
    void *data;
};

extern u32 OSDisableInterrupts(void);
extern Fn80028424Node_u0 *lbl_801A6B90;
extern void OSRestoreInterrupts(u32 level);
extern void fn_80026D70(void *data);

void fn_80028424(Fn80028424Node_u0 *node) {
    u32 level;

    level = OSDisableInterrupts();
    if (node == lbl_801A6B90) {
        lbl_801A6B90 = node->next;
        if (lbl_801A6B90 != 0) {
            lbl_801A6B90->prev = 0;
        }
    } else {
        Fn80028424Node_u0 *next;
        Fn80028424Node_u0 *prev;

        next = node->next;
        prev = node->prev;
        prev->next = next;
        if (next != 0) {
            next->prev = prev;
        }
    }
    OSRestoreInterrupts(level);
    fn_80026D70(node->data);
}

extern f32 lbl_801A7020[2];

struct fn_800284A0_Arg0 {
    u32 unk_0;
    u32 unk_4;
    f32 unk_8;
    u32 unk_c;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1c;
};

void fn_800284A0(struct fn_800284A0_Arg0 *arg0, u32 arg1, u32 arg2, f32 arg3) {
    f32 value;

    arg0->unk_0 = arg1;
    arg0->unk_4 = arg2;
    arg0->unk_8 = arg3;
    arg0->unk_c = 0;
    value = lbl_801A7020[0];
    arg0->unk_1c = value;
    arg0->unk_18 = value;
    arg0->unk_14 = value;
    arg0->unk_10 = value;
}

struct fn_800284CC_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 unk_8;
    u8 unk_9;
};

void fn_800284CC(struct fn_800284CC_Arg0 *arg0) {
    arg0->unk_4 = 2;
    arg0->unk_8 = 64;
    arg0->unk_9 = 127;
}

typedef struct {
    u8 pad0[4];
    u32 field4;
    u32 field8;
} Fn800284E8Data;

void fn_800284E8(Fn800284E8Data *data) {
    data->field4 = 5;
    data->field8 = 0;
}

extern u8 lbl_801299D0[256];

struct fn_800284FC_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 *unk_8;
    u32 unk_c;
    f32 unk_10;
    u32 unk_14;
    f32 unk_18;
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    u32 unk_28;
};

void fn_800284FC(struct fn_800284FC_Arg0 *arg0) {
    f32 zero;
    arg0->unk_4 = 7;
    arg0->unk_28 = 0;
    arg0->unk_8 = lbl_801299D0;
    arg0->unk_c = 64;
    zero = lbl_801A7020[0];
    arg0->unk_10 = zero;
    arg0->unk_14 = 0;
    arg0->unk_24 = zero;
    arg0->unk_20 = zero;
    arg0->unk_1c = zero;
    arg0->unk_18 = zero;
}

struct fn_80028540_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
};

void fn_80028540(struct fn_80028540_Arg0 *arg0) {
    arg0->unk_4 = 8;
    arg0->unk_8 = 0;
}

struct fn_80028554_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
};

void fn_80028554(struct fn_80028554_Arg0 *arg0) {
    arg0->unk_4 = 9;
    arg0->unk_8 = 0;
}

struct fn_80028568_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
};

void fn_80028568(struct fn_80028568_Arg0 *arg0) {
    arg0->unk_4 = 10;
    arg0->unk_8 = 0;
}

struct fn_8002857C_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
};

void fn_8002857C(struct fn_8002857C_Arg0 *arg0) {
    arg0->unk_4 = 11;
    arg0->unk_10 = 0;
    arg0->unk_C = 0;
    arg0->unk_8 = 0;
}

struct fn_80028598_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    f32 unk_10;
    u32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    u32 unk_28;
};

void fn_80028598(struct fn_80028598_Arg0 *arg0) {
    f32 value;
    arg0->unk_4 = 14;
    arg0->unk_28 = 0;
    arg0->unk_8 = (u32)lbl_801299D0;
    arg0->unk_C = 64;
    value = lbl_801A7020[0];
    arg0->unk_10 = value;
    arg0->unk_14 = 0;
    arg0->unk_24 = value;
    arg0->unk_20 = value;
    arg0->unk_1C = value;
    arg0->unk_18 = value;
}

extern const f32 lbl_801A7028;

struct fn_800285DC_state {
    u8 pad_0[0x18];
    u32 unk_18;
};

extern void fn_80028B3C(void *);
extern void fn_800289C0(void *);
extern void fn_80028A78(void *);
extern void fn_80028A1C(void *);
extern f32 fn_800288C4(s32);
extern void fn_800230A4(struct fn_800285DC_state *, s32);
extern void fn_80023228(struct fn_800285DC_state *, s16, s16);
extern void fn_800234D0(struct fn_800285DC_state *, f32);
extern u32 fn_80026D90(struct fn_800285DC_state *, u32);
extern u32 fn_80026E2C(struct fn_800285DC_state *, u32);
extern u32 fn_80026EAC(struct fn_800285DC_state *, u32);
extern void fn_80026EE0(struct fn_800285DC_state *, s32);
extern void fn_80026F4C(struct fn_800285DC_state *, s32);

struct fn_800285DC_node {
    struct fn_800285DC_node *next;
    u32 type;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 padB[5];
    s32 i10;
    u8 pad14[8];
    u8 b1C;
    u8 b1D;
    u8 b1E;
    u8 pad1F;
    u16 h20;
    u16 h22;
    f32 f24;
    s32 i28;
};

struct fn_800285DC_Arg0 {
    u8 pad_0[0x8];
    struct fn_800285DC_state *unk_8;
    f32 unk_C;
    struct fn_800285DC_node *unk_10;
};

void fn_800285DC(struct fn_800285DC_Arg0 *arg0) {
    struct fn_800285DC_node *node;
    s32 acc_d;
    s32 acc_c;
    s32 acc_b;
    s32 acc_a;
    u8 byte_a;
    u8 byte_b;
    u8 byte_c;
    u16 half_b;
    u16 half_a;
    f32 f;
    struct fn_800285DC_state *state;

    acc_a = 0;
    acc_b = 0;
    acc_c = 0;
    acc_d = 0;
    byte_a = 0x40;
    byte_b = 0x7F;
    byte_c = 1;
    half_a = 0;
    half_b = 0;
    f = arg0->unk_C / lbl_801A7028;
    node = arg0->unk_10;

    while (node != 0) {
        switch (node->type) {
        case 1:
            fn_80028B3C(node);
            f += node->f24;
            byte_a = node->b1C;
            byte_b = node->b1D;
            acc_c += node->i28;
            half_b = node->h20;
            half_a = node->h22;
            byte_c = node->b1E;
            break;
        case 2:
            byte_a = node->b8;
            byte_b = node->b9;
            break;
        case 3:
            half_b = *(u16 *)&node->b8;
            half_a = *(u16 *)&node->bA;
            break;
        case 4:
            byte_c = node->b8;
            break;
        case 5:
            acc_d += *(u32 *)&node->b8;
            break;
        case 6:
            fn_800289C0(node);
            acc_d += node->i10;
            break;
        case 7:
            fn_80028A78(&node->b8);
            acc_d += (s32)(node->i28 * node->f24);
            break;
        case 8:
            acc_c += *(u32 *)&node->b8;
            break;
        case 9:
            acc_b += *(u32 *)&node->b8;
            break;
        case 10:
            acc_a += *(u32 *)&node->b8;
            break;
        case 11:
            fn_80028A1C(node);
            acc_c += node->i10;
            break;
        case 12:
            fn_80028A1C(node);
            acc_b += node->i10;
            break;
        case 13:
            fn_80028A1C(node);
            acc_a += node->i10;
            break;
        case 14:
            fn_80028A78(&node->b8);
            acc_c += (s32)(node->i28 * node->f24);
            break;
        case 15:
            fn_80028A78(&node->b8);
            acc_b += (s32)(node->i28 * node->f24);
            break;
        case 16:
            fn_80028A78(&node->b8);
            acc_a += (s32)(node->i28 * node->f24);
            break;
        }
        node = node->next;
    }

    f = f * fn_800288C4(acc_d >> 16);
    state = arg0->unk_8;
    fn_800230A4(state, byte_c);
    fn_800234D0(state, f);
    fn_80023228(state, half_b, half_a);
    fn_80026D90(state, acc_c >> 16);
    fn_80026E2C(state, acc_b);
    fn_80026EAC(state, acc_a);
    fn_80026EE0(state, byte_a);
    fn_80026F4C(state, byte_b);
}

struct fn_800288B4_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};
struct fn_800288B4_Arg1 {
    u32 unk_0;
};

void fn_800288B4(struct fn_800288B4_Arg0 *arg0, struct fn_800288B4_Arg1 *arg1) {
    arg1->unk_0 = arg0->unk_10;
    arg0->unk_10 = (u32)arg1;
}
