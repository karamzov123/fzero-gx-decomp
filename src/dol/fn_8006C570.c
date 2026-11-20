#include "types.h"


/* --- dol/fn_8006C570.c --- */
struct fn_8006C570_Arg0 {
    u8 pad_0[4];
    u32 unk_4;
    u8 pad_8[0x24];
    u32 unk_2C;
};
struct fn_8006C570_Arg1 {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8;
    u8 unk_9;
};

static inline s32 interpolate(s32 start, s32 end, s32 current, s32 duration) {
    s32 round;
    s32 difference;
    difference = end - start;
    round = duration / 2;
    if (current < 0) round = -round;
    difference = current * difference;
    difference += round;
    return start + difference / duration;
}
s32 fn_8006C570(struct fn_8006C570_Arg0 *arg0, struct fn_8006C570_Arg1 *arg1, s32 arg2) {
    u32 current;
    s32 negative;
    s32 magnitude;
    s32 result;
    s32 duration;
    s32 start;
    s32 round;
    s32 delta;
    u32 end;

    current = arg0->unk_2C;
    magnitude = __abs(arg2);
    negative = (u32)arg2 >> 31;
    result = magnitude;
    duration = arg1->unk_0;
    if (current < (u32)duration) {
        start = arg1->unk_8;
        result = interpolate(start, magnitude, current, duration);
    } else {
        end = arg0->unk_4;
        if (end != 0xFFFFFFFF) {
            duration = arg1->unk_4;
            if (current > end - duration) {
                if (current < end) {
                    result = current - (end - duration);
                    start = arg1->unk_9;
                    result = interpolate(magnitude, start, result, duration);
                } else {
                    result = arg1->unk_9;
                }
            }
        }
    }
    if (negative) result = -result;
    return result;
}

/* --- dol/fn_8006C634.c --- */
struct fn_8006C634_Arg2 {
    u32 unk_0;
};
struct fn_8006C634_lbl_8019E014 {
    s16 unk_0[1];
};

extern struct fn_8006C634_lbl_8019E014 lbl_8019E014[];

void fn_8006C634(u32 arg0, u32 arg1, struct fn_8006C634_Arg2 *arg2) {
    u32 v0;
    s32 v1;
    s32 unk_1;
    s32 v4;

    v0 = arg1 & 0xFF;
    if (v0 < 64) {
        v1 = lbl_8019E014[0].unk_0[v0];
    } else if (v0 < 128) {
        v1 = lbl_8019E014[0].unk_0[127 - v0];
    } else if (v0 < 192) {
        v1 = -lbl_8019E014[0].unk_0[v0 - 128];
    } else {
        v1 = -lbl_8019E014[0].unk_0[255 - v0];
    }
    unk_1 = arg0 * v1;
    v4 = 0x1FE00;
    if (unk_1 < 0) {
        v4 = -0x1FE00;
    }
    {
        s32 scaled = unk_1 * 127;
        scaled += v4;
        arg2->unk_0 = -(scaled / 0x3FC00);
    }
}
