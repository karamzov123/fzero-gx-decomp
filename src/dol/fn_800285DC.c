#include "types.h"

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
