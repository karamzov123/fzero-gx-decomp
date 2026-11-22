#include "types.h"

typedef struct AXARTNode AXARTNode;
struct AXARTNode {
    AXARTNode *next;
    AXARTNode *prev;
    void *data;
};

extern AXARTNode *lbl_801A6B90;

/* --- dol/fn_80026FE0.c --- */
typedef struct SoundChan {
    u8 pad_00[0x1C];
    u32 unk_1C;
    u8 pad_20[0x124];
    u16 unk_144;
    u8 pad_146[4];
    u16 unk_14A[18];
    u8 pad_16E[0x2E];
    u16 unk_19C;
    s16 unk_19E;
} SoundChan;

typedef struct SoundEntry {
    SoundChan *chan;
    u32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u8 pad_14[8];
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    u16 unk_38;
    u16 unk_3A;
    u16 unk_3C;
    u16 unk_3E;
    u16 unk_40;
    u16 unk_42;
    u16 unk_44;
    u16 unk_46;
    u16 unk_48;
    u16 unk_4A;
    u16 unk_4C;
    u16 unk_4E;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
    u16 unk_56;
    u16 unk_58;
    u16 unk_5A;
    u16 unk_5C;
    u16 unk_5E;
} SoundEntry;

extern SoundEntry lbl_80176160[64];
extern u8 lbl_80128990[3008];
extern s32 lbl_801A6B80;
extern s32 lbl_801A6B84;
extern s32 lbl_801A6B88;

void AISetStreamVolLeft(u8 vol);
void AISetStreamVolRight(u8 vol);

static inline s32 get_curve(u8 *base, s32 idx) {
    s32 r;
    if (idx <= -904) {
        r = 0;
    } else if (idx >= 60) {
        r = 0xFF64;
    } else {
        r = *(u16 *)(base + (idx << 1) + 0x710);
    }
    return r;
}

void fn_80026FE0(void);

/* --- dol/fn_8002805C.c --- */
extern f32 lbl_801A7000;
extern f32 lbl_801A7004;
extern u32 fn_80028B2C(f32);
extern u32 fn_80028B34(f32);
void fn_8002805C(void) {
    lbl_801A6B90 = 0;
    fn_80028B34(lbl_801A7000);
    fn_80028B2C(lbl_801A7004);
}



extern u32 OSDisableInterrupts(void);
extern void fn_80026D70(void *data);
extern void OSRestoreInterrupts(u32 level);

void fn_80028090(void) {
    u32 level;
    AXARTNode *node;

    level = OSDisableInterrupts();
    node = lbl_801A6B90;
    while (node != 0) {
        fn_80026D70(node->data);
        node = node->next;
    }
    lbl_801A6B90 = 0;
    OSRestoreInterrupts(level);
}

extern u32 fn_800285DC(u32);
void fn_800280F0(void) {
    u32 v0;
    v0 = (u32)lbl_801A6B90;
    while (v0 != 0) {
    fn_800285DC(v0);
    v0 = *(u32 *)(v0);
    }
}

typedef struct Fn80028130Data_u1 Fn80028130Data_u1;

struct Fn80028130Data_u1 {
    u8 pad0[8];
    u32 value0;
    f32 value1;
    u32 value2;
};

extern f64 lbl_801A7008;

void fn_80028130(Fn80028130Data_u1 *data, u32 value0, u32 value1) {
    data->value2 = 0;
    data->value0 = value0;
    data->value1 = value1;
}

typedef struct Fn80028164Arg0 Fn80028164Arg0;
typedef struct Fn80028164Node Fn80028164Node;

struct Fn80028164Arg0 {
    u8 pad0[8];
    void *data;
    f32 value;
    Fn80028164Node *nodes;
};

struct Fn80028164Node {
    Fn80028164Node *next;
    u32 type;
    union {
        u32 word;
        u16 half[2];
        u8 byte[4];
    } value8;
    u8 padc[4];
    u32 value10;
    u8 pad14[8];
    u8 value1c;
    u8 value1d;
    u8 value1e;
    u8 pad1f[1];
    u16 value20;
    u16 value22;
    f32 value24;
    u32 value28;
};

extern f32 lbl_801A7010;
extern f64 lbl_801A7018;
extern u8 jumptable_80129550;
extern u32 fn_800231C4(void *);
extern void fn_80028B3C(Fn80028164Node *);
extern f32 fn_800288C4(s32);
extern void fn_800230A4(void *, u32);
extern void fn_800234D0(void *, f32);
extern void fn_80023228(void *, u16, u16);
extern void fn_80025EF4(void *, u32, s32, s32, s32, u32, u32, u32);
#pragma opt_propagation off
void fn_80028164(Fn80028164Arg0 *arg0) {
    f32 value;
    f32 total;
    Fn80028164Node *node;
    s32 green;
    s32 blue;
    s32 alpha;
    s32 color;
    u8 red;
    u8 default_alpha;
    u8 default_blue;
    u16 height;
    u16 width;
    u32 level;
    s32 random_value;
    void *data;

    fn_800231C4(arg0->data);
    value = arg0->value;
    total = value / lbl_801A7010;
    node = arg0->nodes;
    color = 0;
    alpha = 0;
    blue = 0;
    green = 0;
    red = 64;
    default_alpha = 127;
    default_blue = 1;
    width = 0;
    height = 0;
    while (node != 0) {
        switch (node->type) {
        case 0:
            break;
        case 1:
            fn_80028B3C(node);
            total += node->value24;
            red = node->value1c;
            default_alpha = node->value1d;
            blue += node->value28;
            height = node->value20;
            width = node->value22;
            default_blue = node->value1e;
            break;
        case 2:
            red = node->value8.byte[0];
            default_alpha = node->value8.byte[1];
            break;
        case 3:
            height = node->value8.half[0];
            width = *(u16 *)((u8 *)node + 0xa);
            break;
        case 4:
            default_blue = node->value8.byte[0];
            break;
        case 5:
            green += node->value8.word;
            break;
        case 6:
            green += node->value10;
            break;
        case 7:
            random_value = ((s32)node->value28 * node->value24);
            green += random_value;
            break;
        case 8:
            blue += node->value8.word;
            break;
        case 9:
            alpha += node->value8.word;
            break;
        case 10:
            color += node->value8.word;
            break;
        case 11:
            blue += node->value10;
            break;
        case 12:
            alpha += node->value10;
            break;
        case 13:
            color += node->value10;
            break;
        case 14:
            random_value = ((s32)node->value28 * node->value24);
            blue += random_value;
            break;
        case 15:
            random_value = ((s32)node->value28 * node->value24);
            alpha += random_value;
            break;
        case 16:
            random_value = ((s32)node->value28 * node->value24);
            color += random_value;
            break;
        }
        node = node->next;
    }
    total *= fn_800288C4(green >> 16);
    data = arg0->data;
    fn_800230A4(data, default_blue);
    fn_800234D0(data, total);
    fn_80023228(data, height, width);
    fn_80025EF4(arg0->data, 0, blue >> 16, alpha, color, red, default_alpha, 0);
    level = OSDisableInterrupts();
    if (lbl_801A6B90 != 0) {
        lbl_801A6B90->prev = (AXARTNode *)arg0;
        *((u32 *)arg0 + 0) = (u32)lbl_801A6B90;
    } else {
        *((u32 *)arg0 + 0) = 0;
    }
    *((u32 *)arg0 + 1) = 0;
    lbl_801A6B90 = (AXARTNode *)arg0;
    OSRestoreInterrupts(level);
}
#pragma opt_propagation reset

