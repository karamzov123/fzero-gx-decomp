#include "types.h"

struct fn_8006C788_Arg0 {
    u8 pad_0[0x24];
    u32 unk_24;
};

struct fn_8006C788_Arg1 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 unk_3;
    s16 unk_4;
    s16 unk_6;
};

s32 fn_8006C788(struct fn_8006C788_Arg0 *arg0, struct fn_8006C788_Arg1 *arg1) {
    s32 current;
    s32 scale;
    s32 limit;
    s32 value;

    current = *(s32 *)((u8 *)arg0->unk_24 + 0x64);
    if (current < 0) {
        scale = -arg1->unk_4;
        limit = arg1->unk_2;
    } else {
        scale = -arg1->unk_6;
        limit = arg1->unk_3;
    }
    current *= scale;
    scale = -limit;
    value = current * 20 / 0xFF000;
    if (scale > value) {
        value = scale;
    }
    if (limit < value) {
        value = limit;
    }
    return value;
}
