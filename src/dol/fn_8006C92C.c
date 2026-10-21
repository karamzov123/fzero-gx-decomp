#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "sdk_addresses.h"
u32 __OSBusClock : FZGX_ADDR___OSBusClock;
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

extern u32 OSGetTick(void);
extern s32 fn_8006C190(struct fn_8006C92C_Obj *, u32);
extern u8 lbl_8019DF90[132];
extern void fn_800139E8(u32, u32, s32);

#pragma optimize_for_size on

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
