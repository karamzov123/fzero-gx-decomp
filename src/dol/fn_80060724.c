#include "types.h"
#pragma use_lmw_stmw on

extern f32 fn_80088578(f32 x);

typedef struct {
    u8 unk_0;
    u8 unk_1;
    s16 unk_2;
} Fn80060724Range;

typedef struct {
    u8 pad_0[8];
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
} Fn80060724Table;

typedef struct {
    u8 pad_0;
    u8 unk_1;
    u8 pad_2[2];
    u8 unk_4;
    u8 pad_5[7];
    Fn80060724Table unk_C;
} Fn80060724Info;

typedef struct {
    u8 pad_0[6];
    u8 unk_6;
    u8 unk_7;
    u8 pad_8[0x54 - 0x8];
} Fn80060724Channel;

extern Fn80060724Channel lbl_80192D68[16];

/* 0..127 level -> attenuation in 0.1 dB units, as in fn_8005C5C8; zero means silence */
#define LEVEL(dst, v)                                                    \
    if ((v) != 0) {                                                      \
        dst = (s32)(10.0 * (20.0 * fn_80088578((f32)(v) / 127.0f)));     \
    } else {                                                             \
        dst = -904;                                                      \
    }

void fn_80060724(Fn80060724Info *info, u8 index, u8 value, s32 *out0, s32 *out1, s32 *out2) {
    Fn80060724Table *table = &info->unk_C;
    Fn80060724Range *range;
    Fn80060724Range *range2;
    u8 low = info->unk_4;
    u8 i;
    s32 level;

    *out0 = info->unk_1;
    range = (Fn80060724Range *)((u8 *)table + table->unk_9);
    for (i = 0; i < table->unk_8; range++, i++) {
        if (value <= range->unk_0) {
            break;
        }
        low = range->unk_0 + 1;
    }
    level = (range->unk_2 * (value - low)) >> 8;
    level += ((lbl_80192D68[index].unk_6 - 64) << 1) + range->unk_1;
    if (level > 127) {
        level = 127;
    } else if (level < 0) {
        level = 0;
    }
    LEVEL(*out1, level);
    range2 = (Fn80060724Range *)((u8 *)table + table->unk_B);
    for (i = 0; i < table->unk_A; range2++, i++) {
        if (value <= range2->unk_0) {
            break;
        }
        low = range2->unk_0 + 1;
    }
    level = (range2->unk_2 * (value - low)) >> 8;
    level += ((lbl_80192D68[index].unk_7 - 64) << 1) + range2->unk_1;
    if (level > 127) {
        level = 127;
    } else if (level < 0) {
        level = 0;
    }
    LEVEL(*out2, level);
}

