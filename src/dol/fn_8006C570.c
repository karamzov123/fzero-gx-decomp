#include "types.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "sdk_addresses.h"
#pragma optimize_for_size on

/* --- dol/fn_8006C570.c --- */
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
    if (current < duration) {
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

/* --- dol/fn_8006C6E8.c --- */
struct fn_8006C6E8_Arg0 {
    u8 pad_0[0x24];
    u32 unk_24;
    u8 pad_28[0x10];
    u32 unk_38;
    u32 unk_3C;
};

struct fn_8006C6E8_Arg1 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 unk_3;
    s16 unk_4;
    s16 unk_6;
};

s32 fn_8006C6E8(struct fn_8006C6E8_Arg0 *arg0, struct fn_8006C6E8_Arg1 *arg1) {
    s32 count;
    s32 current;
    s32 value;
    s32 delta;

    count = arg0->unk_38;
    current = *(s32 *)(arg0->unk_24 + 0xc);
    if (current < count) {
        delta = current - count;
        value = delta * arg1->unk_4 / 0x20000;
        if (-(s32)arg1->unk_2 > value) {
            value = -(s32)arg1->unk_2;
        }
        if (arg1->unk_2 < value) {
            value = arg1->unk_2;
        }
        return -value;
    }

    count = arg0->unk_3C;
    if (current > count) {
        delta = current - count;
        value = delta * arg1->unk_6 / 0x20000;
        if (-((s32)arg1->unk_3) > value) {
            value = -((s32)arg1->unk_3);
        }
        if (arg1->unk_3 < value) {
            value = arg1->unk_3;
        }
        return -value;
    }
    return 0;
}

/* --- dol/fn_8006C788.c --- */
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

    current = *(s32 *)(arg0->unk_24 + 0x64);
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

/* --- dol/fn_8006C7E8.c --- */
u32 __OSBusClock : FZGX_ADDR___OSBusClock;
#define OS_BUS_CLOCK __OSBusClock

struct fn_8006C7E8_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10[10];
    u32 unk_38[10];
    u32 unk_60;
    u32 unk_64;
    u32 unk_68[16];
    u32 unk_A8[16];
    u32 unk_E8;
    u32 unk_EC;
};

extern u32 lbl_801A7390;
extern s32 OSGetTick(void);
extern f32 lbl_801327F8[];
extern s32 lbl_8019E114[];
extern volatile const f32 lbl_801A7394; // fzgx-allow: S2 retail reloads the scale on every iteration

static inline void fn_8006C7E8_copy(struct fn_8006C7E8_Arg0 *arg0, s32 *src) {
    s32 i;
    for (i = 0; i < 10; i++) {
        arg0->unk_10[i] = src[i];
        arg0->unk_38[i] = 0;
    }
}
void fn_8006C7E8(struct fn_8006C7E8_Arg0 *arg0, u32 arg1) {
    u32 local[2];
    s32 i;

    local[0] = lbl_801A7390;
    arg0->unk_4 = 0;
    arg0->unk_60 = 0;
    arg0->unk_E8 = 0;

    for (i = 0; i < 16; i++) {
        arg0->unk_68[i] = 0;
        arg0->unk_A8[i] = 0;
    }

    arg0->unk_0 = arg1;
    arg0->unk_EC = 0;
    arg0->unk_C = 0;
    arg0->unk_8 = 0;
    arg0->unk_64 = 0;

    arg0->unk_4 = OSGetTick() / ((OS_BUS_CLOCK / 4) / 1000);

    fn_8006C7E8_copy(arg0, (s32 *)local);

    arg0->unk_60 = 0;

    {
    s32 j;
    for (j = 0; j < 10; j++) {
        lbl_8019E114[j] = lbl_801327F8[j] * lbl_801A7394;
    }
    i = j;
    }

    fn_8006C7E8_copy(arg0, lbl_8019E114);

    arg0->unk_60 = 0;
}

/* --- dol/fn_8006C92C.c --- */
#define OS_BUS_CLOCK __OSBusClock
#define OS_TIMER_CLOCK (OS_BUS_CLOCK / 4)

struct fn_8006C92C_Obj {
    u8 pad_0[0x28];
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    s32 unk_34;
};

struct fn_8006C92C_Sub {
    u32 unk_0;
    u8 pad_4[0x43];
    s8 unk_47;
};

struct fn_8006C92C_Owner {
    u8 pad_0[0xF0];
    struct fn_8006C92C_Sub *unk_F0;
    struct fn_8006C92C_Obj *unk_F4[64];
    u8 pad_1F4[0x1000];
    s32 unk_11F4;
};

struct fn_8006C92C_Arg0 {
    struct fn_8006C92C_Owner *unk_0;
    u32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10[10];
    s32 unk_38[10];
    s32 unk_60;
    s32 unk_64;
    s32 unk_68[16];
    s32 unk_A8[16];
    s32 unk_E8;
    s32 unk_EC;
};

extern s32 fn_8006C190(struct fn_8006C92C_Obj *, u32);
extern u8 lbl_8019DF90[132];
extern void fn_800139E8(u32, u32, s32);

/* Pushes (d, dt) into the ring buffers; returns dt. */
static inline u32 fn_8006C92C_push(struct fn_8006C92C_Arg0 *arg0, s32 d, u32 dt) {
    arg0->unk_E8--;
    if (arg0->unk_E8 < 0) {
        arg0->unk_E8 = 15;
    }
    arg0->unk_68[arg0->unk_E8] = d;
    arg0->unk_A8[arg0->unk_E8] = dt;
    return dt;
}

/* Sums the samples of the last 16 ms and runs the 10-tap filter over the sum history. */
static inline void fn_8006C92C_filter(struct fn_8006C92C_Arg0 *arg0) {
    s32 i;
    s32 idx;
    s32 sumD;
    u32 sumT;
    s32 t;
    s32 excess;
    s32 dd;
    s32 round;
    s32 j;
    s32 acc;
    s32 k;

    idx = arg0->unk_E8;
    for (i = 0, sumT = 0, sumD = 0; i < 16 && sumT < 16; i++) {
        sumD += arg0->unk_68[idx];
        sumT += arg0->unk_A8[idx++];
        if (idx == 16) {
            idx = 0;
        }
    }
    if (sumT > 16) {
        /* remove the part of the oldest sample that lies beyond 16 ms */
        idx--;
        if (idx < 0) {
            idx = 15;
        }
        excess = sumT - 16;
        t = arg0->unk_A8[idx];
        dd = arg0->unk_68[idx];
        round = t / 2;
        if (excess < 0) {
            round = -round;
        }
        dd = excess * dd;
        dd += round;
        sumD -= dd / t;
    }

    arg0->unk_38[arg0->unk_60++] = sumD;
    if (arg0->unk_60 > 9) {
        arg0->unk_60 = 0;
    }
    acc = 0;
    for (j = 9; j >= 0; j--) {
        k = arg0->unk_60++;
        acc += arg0->unk_38[k] * arg0->unk_10[j];
        if (arg0->unk_60 > 9) {
            arg0->unk_60 = 0;
        }
    }
    arg0->unk_64 = acc;
}

static inline s32 fn_8006C92C_clamp127(s32 x) {
    x = x < -127 ? -127 : x;
    x = x > 127 ? 127 : x;
    return x;
}

/* x * scale / 255, rounded away from zero. */
static inline s32 fn_8006C92C_scale(s32 x, s32 scale) {
    s32 round;

    round = x < 0 ? -127 : 127;
    x *= scale;
    x += round;
    x /= 255;
    return x;
}

s32 fn_8006C92C(struct fn_8006C92C_Arg0 *arg0) {
    u32 dt;
    s32 a;
    s32 b;
    u32 now;
    s32 oldD;
    s32 level;
    s32 round;
    s32 v;
    s32 scale;
    u32 flags;
    struct fn_8006C92C_Obj *obj;
    s32 r;
    u32 n;

    a = 0;
    b = 0;
    now = OSGetTick() / (OS_TIMER_CLOCK / 1000);
    flags = now - arg0->unk_4;  /* elapsed ms; flags is reused as scratch below */
    arg0->unk_4 = now;
    oldD = arg0->unk_8;
    arg0->unk_8 = arg0->unk_0->unk_F0->unk_47;
    arg0->unk_C = arg0->unk_8 << 12;
    dt = fn_8006C92C_push(arg0, arg0->unk_8 - oldD, flags);
    fn_8006C92C_filter(arg0);

    for (n = 0; n < 64; n++) {
        obj = arg0->unk_0->unk_F4[n];
        if (obj != NULL && (obj->unk_28 & 1)) {
            s32 sel;
            fn_8006C190(obj, dt);
            flags = obj->unk_28;
            if ((flags & 1) && obj->unk_30 == 0) {
                level = fn_8006C92C_clamp127(obj->unk_34);
                sel = flags & 4;
            } else {
                level = 0;
                sel = 0;
            }
            if (sel) {
                a += level;
            } else {
                b += level;
            }
        }
    }

    scale = arg0->unk_0->unk_11F4;
    a = a > 128 ? 128 : a;
    v = a < -128 ? -128 : a;
    if (v < 0) {
        v = -lbl_8019DF90[-v];
    } else {
        v = lbl_8019DF90[v];
    }
    if (scale < 255) {
        v = fn_8006C92C_scale(v, scale);
        round = 127;
        if (b < 0) {
            round = -127;
        }
        level = b * scale;
        level += round;
        b = level / 255;
    }
    level = v + b;
    level = level > 128 ? 128 : level;
    r = -128;
    if (level >= -128) {
        r = level;
    }
    if (arg0->unk_EC != r) {
        arg0->unk_EC = r;
        if (r == 0) {
            fn_800139E8(arg0->unk_0->unk_F0->unk_0, 0x400, 0);
        } else {
            fn_800139E8(arg0->unk_0->unk_F0->unk_0, 0x600, r);
        }
    }
    return r;
}
