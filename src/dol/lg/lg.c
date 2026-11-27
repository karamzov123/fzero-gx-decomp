#include "types.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "sdk_addresses.h"

u32 __OSBusClock : FZGX_ADDR___OSBusClock;
#define OS_BUS_CLOCK __OSBusClock
#define OS_TIMER_CLOCK (OS_BUS_CLOCK / 4)

typedef struct LGFlags {
    u8 flag7 : 1;
    u8 flag6 : 1;
    u8 rest : 6;
} LGFlags;

typedef struct PadStatus {
    u16 unk_0;
    u8 unk_2;
    s8 unk_3;
    u8 unk_4;
    u8 unk_5;
    s8 unk_6;
    u8 unk_7;
    u8 unk_8;
    s8 unk_9;
} PadStatus;

typedef struct LGCalib {
    u8 pad_0[3];
    s8 unk_3;
    u8 unk_4;
    u8 unk_5;
    s8 unk_6;
    u8 min_x;
    u8 min_y;
    u8 pad_9[4];
    s8 unk_D;
    u8 unk_E;
    u8 unk_F;
    s8 unk_10;
    u8 max_x;
    u8 max_y;
    u8 pad_13[4];
    s8 unk_17;
    u8 unk_18;
    u8 unk_19;
    u8 pad_1A;
    u8 dead_x;
    u8 dead_y;
    u8 pad_1D;
    PadStatus unk_1E;
    s32 unk_28;
} LGCalib;

typedef struct Fn8006AF94Out {
    u16 buttons;
    u8 data[6];
    s8 status;
} Fn8006AF94Out;

typedef struct Fn8006B048Entry {
    s32 index;
    LGFlags flags;
    u8 pad_5[3];
    s32 value;
    u16 field_c;
    u8 field_e;
    u8 field_f;
    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    s8 state;
    u8 pad_15[6];
    s8 field_1b;
    u8 field_1c;
    u8 field_1d;
    u8 field_1e;
    u8 field_1f;
    u8 field_20;
    u8 pad_21[4];
    u8 field_25;
    u8 field_26;
    u8 field_27;
    u8 field_28;
    u8 field_29;
    u8 field_2a;
    u8 pad_2b[4];
    u8 field_2f;
    u8 field_30;
    u8 field_31;
    u8 pad_32;
    u8 field_33;
    u8 field_34;
    u8 pad_35[15];
    PadStatus status;
    u8 pad_4E[2];
    u8 data_50[0x1248 - 0x50];
} Fn8006B048Entry;

typedef struct Fn8006BE0CLight {
    u8 type;
    u8 pad_1[3];
    u32 unk_4;
    u32 unk_8;
    union {
        struct {
            s16 level;
            u16 angle;
            u32 unk_10;
            u32 unk_14;
            u8 unk_18;
            u8 unk_19;
        } t0;
        struct {
            s16 level;
            s16 unk_E;
            u16 angle;
        } t1;
        struct {
            u8 level;
            u8 pad_D;
            u16 angle;
            u16 count;
            u16 angle2;
            s16 unk_14;
            u16 pad_16;
            u32 unk_18;
            u32 unk_1C;
            u8 unk_20;
            u8 unk_21;
        } t2;
        struct {
            s8 center;
            u8 width;
            u8 unk_E;
            u8 unk_F;
            s16 unk_10;
            s16 unk_12;
        } t7;
        u8 raw[0x1C];
    } u;
    u32 flags;
    u8 pad_2C[0xC];
    s32 lo;
    s32 hi;
} Fn8006BE0CLight;

typedef struct LGEffect {
    u8 unk_0;
    u8 pad_1[3];
    u32 unk_4;
    u32 unk_8;
    s16 unk_C;
    u16 unk_E;
    u16 unk_10;
    u16 unk_12;
    s16 unk_14;
    u8 pad_16[0xE];
    void *owner;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    s32 unk_34;
    u32 unk_38;
    u32 unk_3C;
} LGEffect;

struct LGEnvelope {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8;
    u8 unk_9;
};

struct LGCondParam {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 unk_3;
    s16 unk_4;
    s16 unk_6;
};

typedef struct LGSub {
    u32 unk_0;
    u8 pad_4[0x43];
    s8 unk_47;
} LGSub;

typedef struct LGFFData {
    struct LGFFData *unk_0;
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
    /* volatile: retail orders this pointer load before the generation load in fn_8006BC84. */
    /* WARNING: compiler-diff device, not original code: volatile pointer member orders the values load before the generation load in fn_8006BC84; plain u32 * 10 diff lines */
    u32 *volatile values;
    LGEffect *items[64];
    u8 pad_1F4[0x1000];
    s32 unk_11F4;
} LGFFData;

extern Fn8006B048Entry lbl_80199670[4];
extern s32 lbl_801A6C88;
extern u32 lbl_801A6C8C;
/* volatile: retail reloads the cursor after storing it. */
/* WARNING: compiler-diff device, not original code: volatile cursor (retail reloads it after the store); non-volatile 2254 dump lines (fn_8006BC84 loop shortens by one instruction and everything after shifts). Could be real shared state; no evidence either way */
extern volatile u32 lbl_801A6C90;
/* volatile: retail reads generation after the cursor stores. */
/* WARNING: compiler-diff device, not original code: volatile generation counter read after the cursor stores; non-volatile 26 diff lines */
extern volatile u32 lbl_801A6C94;
extern s32 lbl_801A6C98;
extern const f32 lbl_801A7370;
extern const f32 lbl_801A7374;
extern const f32 lbl_801A7378;
extern const f32 lbl_801A737C;
extern const f64 lbl_801A7380;
extern const f32 lbl_801A738C; /* 1024.0f: fn_8006BCF8's own entry in the TU literal pool */
extern u32 lbl_801A7390;
/* retail reloads the scale on every iteration */
/* WARNING: compiler-diff device, not original code: volatile scale so the loop reloads it each iteration; plain const f32 10 diff lines (load hoisted) */
extern volatile const f32 lbl_801A7394; // fzgx-allow: S2 retail reloads the scale on every iteration
extern u8 lbl_8019DF90[132];
extern s16 lbl_8019E014[64];
extern s16 lbl_8019E094[64];
extern f32 lbl_801327F8[];
extern s32 lbl_8019E114[];

extern void fn_800137C4(s32, void *);
extern s32 fn_80013428(s32, void *);
extern void fn_800139E8(u32, u32, s32);
extern u32 PADSetSamplingCallback(u32);
extern f64 fn_80088598(f64, f64);
extern f64 fn_800883E8(f64);
extern s32 OSGetTick(void);

s32 fn_8006B3F0(Fn8006B048Entry *data);
void fn_8006B92C(LGFFData *arg0);
void fn_8006B99C(void);
s32 fn_8006BA74(LGFFData *arg0, u32 *out, u8 *status);
s32 fn_8006BB30(LGFFData *data, u32 index, u32 arg);
s32 fn_8006BB74(LGFFData *data, u32 index);
s32 fn_8006BB9C(LGFFData *data, u32 index);
s32 fn_8006BBDC(LGFFData *data, u32 index);
s32 fn_8006BC1C(LGFFData *data, void *value);
s32 fn_8006BC50(LGFFData *data);
u32 fn_8006BC84(LGFFData *data);
void fn_8006BCF8(void *arg0);
s32 fn_8006BE0C(Fn8006BE0CLight *dst, const Fn8006BE0CLight *src);
s32 fn_8006C134(LGEffect *arg0);
s32 fn_8006C17C(LGEffect *arg0);
s32 fn_8006C190(LGEffect *arg0, u32 arg1);
s32 fn_8006C570(LGEffect *arg0, struct LGEnvelope *arg1, s32 arg2);
void fn_8006C634(u32 arg0, u32 arg1, s32 *arg2);
s32 fn_8006C6E8(LGEffect *arg0, struct LGCondParam *arg1);
s32 fn_8006C788(LGEffect *arg0, struct LGCondParam *arg1);
void fn_8006C7E8(LGFFData *arg0, void *arg1);
s32 fn_8006C92C(LGFFData *arg0);

void fn_8006AA20(u32 arg0, u32 arg1) {
    if ((s32)arg1 == 0) {
        return;
    }
    lbl_80199670[arg0].status.unk_9 = -1;
}

static inline u8 fn_8006AA44_scale(s32 value, u8 *min, u8 *max, u8 dead) {
    s32 lo;
    s32 hi;
    s32 range;
    s32 result;

    lo = *min;
    hi = *max;
    if (value < lo) {
        *min = value;
        lo = value;
    }
    if (value > hi) {
        *max = value;
        hi = value;
    }
    range = hi - lo - dead * 2;
    if (range == 0) {
        range = 1;
    }
    result = (value - (lo + dead)) * 0xFF / range;
    if (result < 0) {
        result = 0;
    }
    if (result > 0xFF) {
        result = 0xFF;
    }
    return result;
}

static inline s8 fn_8006AA44_half(s32 a, s32 b) {
    s32 result;

    result = (a - b) / 2;
    if (result < -0x80) {
        result = -0x80;
    } else if (result > 0x7F) {
        result = 0x7F;
    }
    return result;
}

void fn_8006AA44(PadStatus *out, PadStatus *in, LGCalib *calib) {
    if ((in->unk_2 ^ calib->unk_1E.unk_2) & 8) {
        calib->unk_28 = 0x40;
        calib->unk_4 = 0x50;
        calib->unk_5 = 0x50;
        calib->unk_6 = fn_8006AA44_half(calib->unk_4, calib->unk_5);
        calib->unk_E = 0xB0;
        calib->unk_F = 0xB0;
        calib->unk_10 = fn_8006AA44_half(calib->unk_E, calib->unk_F);
        calib->unk_18 = 10;
        calib->unk_19 = 10;
    }
    if (calib->unk_28 > 0) {
        calib->unk_28--;
        out->unk_5 = 0;
        out->unk_4 = 0;
        out->unk_6 = 0;
        return;
    }
    if (in->unk_2 & 8) {
        out->unk_4 = fn_8006AA44_scale(in->unk_4, &calib->unk_4, &calib->unk_E, calib->unk_18);
        out->unk_5 = fn_8006AA44_scale(in->unk_5, &calib->unk_5, &calib->unk_F, calib->unk_19);
        out->unk_6 = fn_8006AA44_half(out->unk_4, out->unk_5);
    } else {
        out->unk_5 = 0;
        out->unk_4 = 0;
        out->unk_6 = 0;
    }
}

typedef struct Fn8006AC44_Input {
    u16 buttons;
    u8 pad_2[4];
    u8 x;
    u8 y;
} Fn8006AC44_Input;

void fn_8006AC44(PadStatus *out, PadStatus *in_pad, LGCalib *calib) {
    Fn8006AC44_Input *in = (Fn8006AC44_Input *)in_pad;
    s32 value;

    if (in->x > calib->max_x - calib->dead_x * 2) {
        if ((in->buttons ^ calib->unk_1E.unk_0) & 0x40) {
            value = in->x - calib->dead_x;
            calib->max_x = value < 0 ? 0 : value;
            out->unk_7 = 0xFF;
        } else if (in->buttons & 0x40) {
            out->unk_7 = 0xFF;
        } else {
            out->unk_7 = fn_8006AA44_scale(in->x, &calib->min_x, &calib->max_x, calib->dead_x);
        }
    } else {
        out->unk_7 = fn_8006AA44_scale(in->x, &calib->min_x, &calib->max_x, calib->dead_x);
    }

    if (in->y > calib->max_y - calib->dead_y * 2) {
        if ((in->buttons ^ calib->unk_1E.unk_0) & 0x20) {
            value = in->y - calib->dead_y;
            calib->max_y = value < 0 ? 0 : value;
            out->unk_8 = 0xFF;
        } else if (in->buttons & 0x20) {
            out->unk_8 = 0xFF;
        } else {
            out->unk_8 = fn_8006AA44_scale(in->y, &calib->min_y, &calib->max_y, calib->dead_y);
        }
    } else {
        out->unk_8 = fn_8006AA44_scale(in->y, &calib->min_y, &calib->max_y, calib->dead_y);
    }
}

static inline s8 fn_8006AE90_scale(s8 value, s8 *min, s8 *max, s8 dead) {
    s32 lo;
    s32 hi;
    s32 range;
    s32 result;
    lo = *min;
    hi = *max;
    if (value < lo) { *min = value; lo = value; }
    if (value > hi) { hi = value; *max = value; }
    range = hi - lo - dead * 2;
    if (range == 0) range = 1;
    result = (value - (lo + dead)) * 255 / range - 127;
    if (result < -128) result = -128;
    if (result > 127) result = 127;
    return result;
}

void fn_8006AE90(PadStatus *arg0, PadStatus *arg1, LGCalib *arg2) {
    arg0->unk_3 = fn_8006AE90_scale(arg1->unk_3, &arg2->unk_3, &arg2->unk_D, arg2->unk_17);
    fn_8006AA44(arg0, arg1, arg2);
    fn_8006AC44(arg0, arg1, arg2);
    arg0->unk_0 = arg1->unk_0;
    arg0->unk_2 = arg1->unk_2;
    arg2->unk_1E = *arg1;
    arg0->unk_9 = 0;
}

void fn_8006AF94(void) {
    s32 off;
    u8 *base;
    s32 i;
    Fn8006B048Entry *entry;
    Fn8006AF94Out *out;

    i = 0;
    base = (u8 *)lbl_80199670;
    do {
        entry = (Fn8006B048Entry *)(base + i * 0x1248);
        if (entry->flags.flag7) {
            out = (Fn8006AF94Out *)((u8 *)entry + 0xc);
            fn_800137C4(i, out);
            switch (out->status) {
            case -1:
                entry->status.unk_9 = -1;
                entry->flags.flag6 = 1;
                break;
            case 0:
                fn_8006AE90(&entry->status, (PadStatus *)out, (LGCalib *)((u8 *)entry + 0x18));
                fn_8006C92C((LGFFData *)entry->data_50);
                break;
            }
        }
        i++;
        off += 0x1248;
    } while (i < 4);
}

void fn_8006B048(Fn8006B048Entry *arg, s32 index) {
    s32 value;
    Fn8006B048Entry *entry = arg;
    entry->index = index;
    entry->flags.flag7 = 0;
    entry->flags.flag6 = 0;
    entry->value = -1;
    entry->field_c = 0;
    entry->field_e = 0;
    entry->field_f = 0;
    entry->field_10 = 128;
    entry->field_11 = 128;
    entry->field_12 = 128;
    entry->field_13 = 128;
    entry->state = -1;
    entry->field_1b = -64;
    entry->field_1f = 80;
    entry->field_20 = 80;
    entry->field_25 = 64;
    entry->field_29 = 176;
    entry->field_2a = 176;
    entry->field_2f = 6;
    entry->field_33 = 12;
    entry->field_34 = 12;
    entry->field_1c = 80;
    entry->field_1d = 80;
    value = entry->field_1c - entry->field_1d;
    value /= 2;
    if (value < -128) value = -128;
    else if (value > 127) value = 127;
    entry->field_1e = value;
    entry->field_26 = 176;
    entry->field_27 = 176;
    value = entry->field_26 - entry->field_27;
    value /= 2;
    if (value < -128) value = -128;
    else if (value > 127) value = 127;
    entry->field_28 = value;
    entry->field_30 = 10;
    entry->field_31 = 10;
    fn_8006AE90(&entry->status, (PadStatus *)&entry->field_c, (LGCalib *)((u8 *)entry + 0x18));
}

void fn_8006B188(void) {
    s32 off;
    u8 *base;
    Fn8006B048Entry *entry;
    s32 i;

    if (lbl_801A6C88 == 0) {
        base = (u8 *)lbl_80199670;
        i = 0;
        off = 0;
        do {
            entry = (Fn8006B048Entry *)(base + i * 0x1248);
            fn_8006B92C((LGFFData *)entry->data_50);
            fn_8006B048(entry, i);
            fn_80013428(i, fn_8006AA20);
            fn_800137C4(i, (u8 *)entry + 0xc);
            i++;
            off += 0x1248;
        } while (i < 4);
        PADSetSamplingCallback((u32)fn_8006AF94);
        lbl_801A6C88 = 1;
    }
}

void fn_8006B224(void) {
    s32 i;
    u8 *base;
    s32 off;

    if (lbl_801A6C88 != 0) {
        base = (u8 *)lbl_80199670;
        for (i = 0; i < 4; i++) {
            fn_8006B3F0((Fn8006B048Entry *)(base + i * 0x1248));
            fn_800139E8(i, 0x400, 0);
        }
        lbl_801A6C88 = 0;
    }
}

s32 fn_8006B294(s32 index, u32 *out) {
    s32 offset;
    Fn8006B048Entry *entry;
    u8 *data;
    s8 state;

    if (index >= 4 || index < 0) {
        return -2;
    }
    if (out == 0) {
        return -2;
    }

    offset = index * 0x1248;
    entry = (Fn8006B048Entry *)((u8 *)lbl_80199670 + offset);
    if (entry->flags.flag6) {
        fn_8006B3F0(entry);
    }
    if (entry->flags.flag7) {
        *out = entry->value;
        return -3;
    }
    if (fn_80013428(index, fn_8006AA20) != -1) {
        fn_8006B048(entry, index);
        data = (u8 *)entry + 0xc;
        fn_800137C4(index, data);
        state = ((u8 *)lbl_80199670)[offset + 0x14];
        switch (state) {
        case -1:
            ((s8 *)lbl_80199670)[offset + 0x4d] = -1;
            return -4;
        case 0:
            fn_8006AE90(&entry->status, (PadStatus *)data, (LGCalib *)((u8 *)entry + 0x18));
            break;
        }
        ((u8 *)lbl_80199670)[offset + 0x4d] = 0;
        *out = (u32)entry;
        entry->index = index;
        entry->value = *out;
        fn_8006BC1C((LGFFData *)entry->data_50, entry);
        entry->flags.flag7 = 1;
        return 0;
    }
    return -4;
}

s32 fn_8006B3F0(Fn8006B048Entry *data) {
    if (data == 0 || (u32)data + 0x10000 == 0xffff) {
        return -2;
    }
    if (data->flags.flag7 == 0) {
        return -2;
    }
    data->flags.flag7 = 0;
    data->flags.flag6 = 0;
    fn_8006BC50((LGFFData *)data->data_50);
    data->value = -1;
    return 0;
}

/* fn_8006B3F0, defined earlier in this TU; MWCC inlines it here. */
static inline s32 Fn8006B470Close(Fn8006B048Entry *data) {
    if (data == 0 || (u32)data + 0x10000 == 0xffff) {
        return -2;
    }
    if (data->flags.flag7 == 0) {
        return -2;
    }
    data->flags.flag7 = 0;
    data->flags.flag6 = 0;
    fn_8006BC50((LGFFData *)data->data_50);
    data->value = -1;
    return 0;
}

s32 fn_8006B470(PadStatus *out) {
    s32 i;
    Fn8006B048Entry *entry;

    if (out == 0) {
        return -2;
    }
    for (i = 0; i < 4; i++) {
        entry = &lbl_80199670[i];
        if (entry->flags.flag6) {
            Fn8006B470Close(entry);
        }
        if (entry->flags.flag7) {
            out[i] = entry->status;
        } else {
            out[i].unk_9 = -1;
        }
    }
    return 0;
}

static inline s32 Fn8006B55CClose(void *handle) {
    Fn8006B048Entry *data = handle;

    if (data == 0 || (u32)data + 0x10000 == 0xffff) {
        return -2;
    }
    if (data->flags.flag7 == 0) {
        return -2;
    }
    data->flags.flag7 = 0;
    data->flags.flag6 = 0;
    fn_8006BC50((LGFFData *)data->data_50);
    data->value = -1;
    return 0;
}

s32 fn_8006B55C(Fn8006B048Entry *data, u32 *arg1, u8 *arg2) {
    if (data == 0 || (u32)data + 0x10000 == 0xffff) {
        return -2;
    }
    if (data->flags.flag7 == 0) {
        return -2;
    }
    if (arg1 == 0) {
        return -2;
    }
    if (arg2 == 0) {
        return -2;
    }
    if (data->flags.flag6 != 0) {
        Fn8006B55CClose(data);
        return -2;
    }
    return fn_8006BA74((LGFFData *)data->data_50, arg1, arg2);
}

s32 fn_8006B628(u32 value, u32 param) {
    u32 index;
    Fn8006B048Entry *entry;
    u32 enabled;

    index = value >> 16;
    if (index >= 4) {
        return -2;
    }
    entry = (Fn8006B048Entry *)((u8 *)lbl_80199670 + index * 0x1248);
    enabled = entry->flags.flag7;
    if (enabled == 0) {
        return -2;
    }
    if (param == 0) {
        return -2;
    }
    if (entry->flags.flag6) {
        if (entry != 0 && (u32)entry + 0x10000 != 0xffff && enabled != 0) {
            entry->flags.flag7 = 0;
            entry->flags.flag6 = 0;
            fn_8006BC50((LGFFData *)entry->data_50);
            entry->value = -1;
        }
        return -2;
    }
    return fn_8006BB30((LGFFData *)entry->data_50, value, param);
}

s32 fn_8006B6F8(u32 value) {
    u32 index;
    Fn8006B048Entry *entry;
    u32 enabled;

    index = value >> 16;
    if (index >= 4) {
        return -2;
    }
    entry = (Fn8006B048Entry *)((u8 *)lbl_80199670 + index * 0x1248);
    enabled = entry->flags.flag7;
    if (enabled == 0) {
        return -2;
    }
    if (entry->flags.flag6) {
        if (entry != 0 && (u32)entry + 0x10000 != 0xffff && enabled != 0) {
            entry->flags.flag7 = 0;
            entry->flags.flag6 = 0;
            fn_8006BC50((LGFFData *)entry->data_50);
            entry->value = -1;
        }
        return -2;
    }
    return fn_8006BB9C((LGFFData *)entry->data_50, value);
}

s32 fn_8006B7B4(u32 value) {
    u32 index;
    Fn8006B048Entry *entry;
    u32 enabled;

    index = value >> 16;
    if (index >= 4) {
        return -2;
    }
    entry = (Fn8006B048Entry *)((u8 *)lbl_80199670 + index * 0x1248);
    enabled = entry->flags.flag7;
    if (enabled == 0) {
        return -2;
    }
    if (entry->flags.flag6) {
        if (entry != 0 && (u32)entry + 0x10000 != 0xffff && enabled != 0) {
            entry->flags.flag7 = 0;
            entry->flags.flag6 = 0;
            fn_8006BC50((LGFFData *)entry->data_50);
            entry->value = -1;
        }
        return -2;
    }
    return fn_8006BBDC((LGFFData *)entry->data_50, value);
}

s32 fn_8006B870(u32 value) {
    u32 index;
    Fn8006B048Entry *entry;
    u32 enabled;

    index = value >> 16;
    if (index >= 4) {
        return -2;
    }
    entry = (Fn8006B048Entry *)((u8 *)lbl_80199670 + index * 0x1248);
    enabled = entry->flags.flag7;
    if (enabled == 0) {
        return -2;
    }
    if (entry->flags.flag6) {
        if (entry != 0 && entry != (Fn8006B048Entry *)-1 && enabled != 0) {
            entry->flags.flag7 = 0;
            entry->flags.flag6 = 0;
            fn_8006BC50((LGFFData *)entry->data_50);
            entry->value = -1;
        }
        return -2;
    }
    return fn_8006BB74((LGFFData *)entry->data_50, value);
}

void fn_8006B92C(LGFFData *arg0) {
    s32 i;

    fn_8006C7E8(arg0, arg0);
    arg0->unk_11F4 = 0xFF;
    for (i = 0; i < 64; i++) {
        arg0->items[i] = 0;
    }
    if ((s32)lbl_801A6C8C == 0) {
        fn_8006B99C();
        lbl_801A6C8C = 1;
    }
}

/* Power curve sample at x / 128; the conversions share one stack slot only when inlined. */
static inline f32 curve(s32 x) {
    return fn_80088598(x * lbl_801A7370, lbl_801A7374);
}

void fn_8006B99C(void) {
    s32 v0;
    f32 v1;
    for (v0 = 0; v0 < 129; v0++) {
        if (v0 < 0) {
            v1 = -(lbl_801A7378 + lbl_801A737C * curve(-v0));
        } else {
            v1 = lbl_801A7378 + lbl_801A737C * curve(v0);
        }
        lbl_8019DF90[v0] = v1;
    }
}

s32 fn_8006BA74(LGFFData *arg0, u32 *out, u8 *status) {
    u32 value;
    s32 result;
    s32 state;
    u32 index;
    LGEffect *record;

    result = 0;
    *out = fn_8006BC84(arg0);
    value = *out;
    if (value == 0xFFFFFFFF) {
        result = -5;
    } else {
        index = value & 0x3F;
        state = *status;
        record = (LGEffect *)((u8 *)arg0 + (index << 6) + 0x1F4);
        switch (state) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
            fn_8006BCF8(record);
            record->owner = arg0;
            fn_8006BE0C((Fn8006BE0CLight *)record, (const Fn8006BE0CLight *)status);
            break;
        default:
            *out = 0xFFFFFFFF;
            result = -2;
            break;
        }
        if (record != 0) {
            arg0->items[index] = record;
        }
    }
    return result;
}

s32 fn_8006BB30(LGFFData *data, u32 index, u32 arg) {
    s32 result;

    result = -2;
    if (data->items[index & 0x3f] != 0) {
        result = fn_8006BE0C((Fn8006BE0CLight *)data->items[index & 0x3f], (const Fn8006BE0CLight *)arg);
    }
    return result;
}

s32 fn_8006BB74(LGFFData *data, u32 index) {
    s32 result;

    result = -2;
    if (data->items[index & 0x3f] != 0) {
        data->items[index & 0x3f] = 0;
        result = 0;
    }
    return result;
}

s32 fn_8006BB9C(LGFFData *data, u32 index) {
    u32 result;

    result = -2;
    if (data->items[index & 0x3f] != 0) {
        result = fn_8006C134(data->items[index & 0x3f]);
    }
    return result;
}

s32 fn_8006BBDC(LGFFData *data, u32 index) {
    u32 result;

    result = -2;
    if (data->items[index & 0x3f] != 0) {
        result = fn_8006C17C(data->items[index & 0x3f]);
    }
    return result;
}

s32 fn_8006BC1C(LGFFData *data, void *value) {
    u32 i;
    data->unk_11F4 = 0xff;
    for (i = 0; i < 64; i++) {
        data->items[i] = 0;
    }
    data->values = value;
    return 0;
}

s32 fn_8006BC50(LGFFData *data) {
    u32 i;
    for (i = 0; i < 64; i++) {
        if (data->items[i] != 0) {
            data->items[i] = 0;
        }
    }
    return 0;
}

/* WARNING: compiler-diff device, not original code: opt_propagation off around fn_8006BC84; without it 10 diff lines */
#pragma opt_propagation off
u32 fn_8006BC84(LGFFData *data) {
    u32 count;
    u32 result;
    u32 i;

    count = lbl_801A6C90;
    result = -1;
    for (i = 0; i < 0x40; i++) {
        u32 index;
        u32 packed;
        u32 *values;

        index = (i + count) & 0x3f;
        if (data->items[index] != 0) {
            continue;
        }
        lbl_801A6C90 = index + 1;
        lbl_801A6C90 &= 0x3f;
        values = data->values;
        packed = (lbl_801A6C94 & 0xff) << 8;
        result = (((index & 0x3f)) | (((((((*values << 16) & 0xffff0000)) | ((packed & ~0xffff0000)))) & ~0x3f)));
        break;
    }
    return result;
}
#pragma opt_propagation reset

/* Word-aligned clear: eight words per pass, then the byte tail. */
static inline void ClearAligned(u32 *p, u32 n) {
    u8 *c;
    u32 i;

    p--;
    i = n >> 5;
    do {
        *++p = 0;
        *++p = 0;
        *++p = 0;
        *++p = 0;
        *++p = 0;
        *++p = 0;
        *++p = 0;
        *++p = 0;
    } while (--i);
    n &= 3;
    c = (u8 *)(p + 1) - 1;
    if (n) {
        do {
            *++c = 0;
        } while (--n);
    }
}

void fn_8006BCF8(void *arg0) {
    s32 j;

    ClearAligned(arg0, 0x40);
    if (lbl_801A6C98 == 0) {
        for (j = 0; j < 64; j++) {
            /* WARNING: compiler-diff device, not original code: the original statements are
             *     lbl_8019E014[j] = 1024.0f * (f32)fn_800883E8(3.1415927f * (f32)j / 128.0f);
             *     lbl_8019E094[j] = (j * 0x400) / 63;
             * The retail compiler's scheduler treated a float-literal load as possibly aliasing later
             * stores, so the 1024.0f load uncovers the ramp-table store and is issued before `frsp`.
             * The shipped GC/2.0p1 never creates that memory edge for a literal. The two accesses
             * marked below (the 1024.0f read and the ramp-table store) carry a qualifier that neither
             * object really has; the scheduler serialises such accesses against each other, which
             * rebuilds exactly that one edge. They add no instruction and change no operand. */
            lbl_8019E014[j] = *(const volatile f32 *)&lbl_801A738C /* WARNING: device, see above */
                              * (f32)fn_800883E8(3.1415927f * (f32)j / 128.0f);
            *(volatile s16 *)&lbl_8019E094[j] = (j * 0x400) / 63; /* WARNING: device, see above */
        }
        lbl_801A6C98 = 1;
    }
}

#define CLAMP_S(x) ((x) < -255 ? -255 : (x))
#define CLAMP_H(x) ((x) > 255 ? 255 : (x))
/* angle in degrees to a 0..255 fraction of a turn */
#define WRAP_ANGLE(a) ((((a) % 360) << 8) / 360)

s32 fn_8006BE0C(Fn8006BE0CLight *dst, const Fn8006BE0CLight *src) {
    s32 result;
    s32 type;
    s32 t;

    result = 0;
    type = src->type;
    dst->type = type;
    dst->unk_4 = src->unk_4;
    dst->unk_8 = src->unk_8;

    switch (type) {
    case 0:
        dst->flags |= 0x14;
        t = CLAMP_S(src->u.t0.level);
        dst->u.t0.level = CLAMP_H(t);
        dst->u.t0.angle = WRAP_ANGLE(src->u.t0.angle);
        dst->u.t0.unk_10 = src->u.t0.unk_10;
        dst->u.t0.unk_14 = src->u.t0.unk_14;
        dst->u.t0.unk_18 = CLAMP_H((s32)src->u.t0.unk_18);
        dst->u.t0.unk_19 = CLAMP_H((s32)src->u.t0.unk_19);
        break;
    case 1:
        dst->flags |= 0x24;
        t = CLAMP_S(src->u.t1.level);
        dst->u.t1.level = CLAMP_H(t);
        t = CLAMP_S(src->u.t1.unk_E);
        dst->u.t1.unk_E = CLAMP_H(t);
        dst->u.t1.angle = WRAP_ANGLE(src->u.t1.angle);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        dst->flags |= 0x44;
        dst->u.t2.level = CLAMP_H((s32)src->u.t2.level);
        dst->u.t2.angle = WRAP_ANGLE(src->u.t2.angle);
        dst->u.t2.count = src->u.t2.count < 2 ? 2 : src->u.t2.count;
        dst->u.t2.angle2 = WRAP_ANGLE(src->u.t2.angle2);
        t = CLAMP_S(src->u.t2.unk_14);
        dst->u.t2.unk_14 = CLAMP_H(t);
        dst->u.t2.unk_18 = src->u.t2.unk_18;
        dst->u.t2.unk_1C = src->u.t2.unk_1C;
        dst->u.t2.unk_20 = CLAMP_H((s32)src->u.t2.unk_20);
        dst->u.t2.unk_21 = CLAMP_H((s32)src->u.t2.unk_21);
        if (dst->u.t2.count < 4) {
            dst->u.t2.angle2 = 0x40;
        }
        break;
    case 7:
    case 8:
        dst->flags |= 0x80;
        dst->u.t7.center = src->u.t7.center;
        dst->u.t7.width = src->u.t7.width;
        t = CLAMP_S(src->u.t7.unk_12);
        dst->u.t7.unk_12 = CLAMP_H(t);
        t = CLAMP_S(src->u.t7.unk_10);
        dst->u.t7.unk_10 = CLAMP_H(t);
        dst->u.t7.unk_E = (u32)src->u.t7.unk_E >> 1;
        dst->u.t7.unk_F = (u32)src->u.t7.unk_F >> 1;
        dst->lo = (dst->u.t7.center - ((u32)dst->u.t7.width >> 1)) << 12;
        dst->hi = (dst->u.t7.center + ((u32)dst->u.t7.width >> 1)) << 12;
        break;
    default:
        result = -2;
        break;
    }
    return result;
}

s32 fn_8006C134(LGEffect *arg0) {
    arg0->unk_28 = (arg0->unk_28 | 1);
    arg0->unk_28 = (arg0->unk_28 & 0xFFFFFFFD);
    arg0->unk_2C = 0;
    arg0->unk_30 = arg0->unk_8;
    if ((arg0->unk_28 & 0x40) != 0) {
        arg0->unk_38 = (arg0->unk_12 << 16);
    }
    return 0;
}

s32 fn_8006C17C(LGEffect *arg0) {
    arg0->unk_28 = (arg0->unk_28 & ~0x1);
    return 0;
}

static inline s32 fn_8006C190_ramp(s32 current, s32 duration, s32 start, s32 end) {
    s32 round;
    s32 difference;
    difference = end - start;
    round = duration / 2;
    if (difference < 0) round = -round;
    difference = difference * current;
    difference += round;
    return start + difference / duration;
}

s32 fn_8006C190(LGEffect *arg0, u32 arg1) {
    s32 v4;
    u32 v10;
    s16 v9;
    s32 v8;
    s32 v17;
    /* WARNING: compiler-diff device, not original code: lab_t1 holds &arg0->unk_C across the switch; passing the address directly at both calls 1101 dump lines */
    struct LGCondParam *lab_t1;
    if (arg0->unk_28 & 1) {
        if (arg0->unk_30 != 0) {
            arg0->unk_30 -= arg1;
            if ((s32)arg0->unk_30 < 0) arg0->unk_30 = 0;
        } else {
            arg0->unk_2C += arg1;
            if (arg0->unk_4 != -1 && arg0->unk_4 < arg0->unk_2C) {
                if (arg0->unk_28 & 2) arg0->unk_28 &= ~1;
            }
        }
    }
    arg0->unk_28 |= 2;
    v4 = 0;
    if ((arg0->unk_28 & 1) && arg0->unk_30 == 0) v4 = 1;
    if (v4) {
        if (arg0->unk_28 & 0x10) {
            v4 = fn_8006C570(arg0, (struct LGEnvelope *)&arg0->unk_10, arg0->unk_C);
            fn_8006C634(v4, arg0->unk_E, &arg0->unk_34);
        } else if (arg0->unk_28 & 0x20) {
            v4 = fn_8006C190_ramp(arg0->unk_2C, arg0->unk_4, arg0->unk_C, *(s16 *)&arg0->unk_E);
            fn_8006C634(v4, arg0->unk_10, &arg0->unk_34);
        } else if (arg0->unk_28 & 0x40) {
            arg1 = (arg1 << 24) / arg0->unk_10;
            arg0->unk_38 += arg1;
            if (arg0->unk_38 >= 0x1000000) arg0->unk_38 -= arg0->unk_38 & ~0xFFFFFF;
            v9 = fn_8006C570(arg0, (struct LGEnvelope *)((u8 *)arg0 + 0x18), *(u8 *)&arg0->unk_C);
            switch (arg0->unk_0) {
            case 2:
                v10 = (arg0->unk_38 >> 16) & 0xFF;
                if (v10 < 64) v4 = lbl_8019E014[v10];
                else if (v10 < 128) v4 = lbl_8019E014[127 - v10];
                else if (v10 < 192) v4 = -lbl_8019E014[v10 - 128];
                else v4 = -lbl_8019E014[255 - v10];
                v8 = v4;
                break;
            case 3:
                v8 = -1024;
                if ((arg0->unk_38 >> 16) < 128) v8 = 1024;
                break;
            case 4:
                v10 = (arg0->unk_38 >> 16) & 0xFF;
                if (v10 < 64) v4 = lbl_8019E094[v10];
                else if (v10 < 128) v4 = lbl_8019E094[127 - v10];
                else if (v10 < 192) v4 = -lbl_8019E094[v10 - 128];
                else v4 = -lbl_8019E094[255 - v10];
                v8 = v4;
                break;
            case 5: v8 = lbl_8019E094[(arg0->unk_38 >> 18) & 63]; break;
            case 6: v8 = lbl_8019E094[(255 - ((arg0->unk_38 >> 16) & 255)) >> 2]; break;
            default: v8 = 0; break;
            }
            v4 = 512;
            if (v8 < 0) v4 = -512;
            v17 = v8 * v9;
            v17 += v4;
            v4 = v17 / 1024 + arg0->unk_14;
            fn_8006C634(v4, arg0->unk_E, &arg0->unk_34);
        } else if (arg0->unk_28 & 0x80) {
            lab_t1 = (struct LGCondParam *)&arg0->unk_C;
            switch (arg0->unk_0) {
            case 7:
                arg0->unk_34 = fn_8006C6E8(arg0, lab_t1);
                break;
            case 8:
                arg0->unk_34 = fn_8006C788(arg0, lab_t1);
                if ((s32)arg0->unk_34 == 0) arg0->unk_34 = arg0->unk_34 + 1;
                break;
            default: arg0->unk_34 = 0; break;
            }
        } else return 0;
    } else arg0->unk_34 = 0;
    return 1;
}

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

s32 fn_8006C570(LGEffect *arg0, struct LGEnvelope *arg1, s32 arg2) {
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

void fn_8006C634(u32 arg0, u32 arg1, s32 *arg2) {
    u32 v0;
    s32 v1;
    s32 unk_1;
    s32 v4;

    v0 = arg1 & 0xFF;
    if (v0 < 64) {
        v1 = lbl_8019E014[v0];
    } else if (v0 < 128) {
        v1 = lbl_8019E014[127 - v0];
    } else if (v0 < 192) {
        v1 = -lbl_8019E014[v0 - 128];
    } else {
        v1 = -lbl_8019E014[255 - v0];
    }
    unk_1 = arg0 * v1;
    v4 = 0x1FE00;
    if (unk_1 < 0) {
        v4 = -0x1FE00;
    }
    {
        s32 scaled = unk_1 * 127;
        scaled += v4;
        *arg2 = -(scaled / 0x3FC00);
    }
}

s32 fn_8006C6E8(LGEffect *arg0, struct LGCondParam *arg1) {
    s32 count;
    s32 current;
    s32 value;
    s32 delta;

    count = arg0->unk_38;
    current = *(s32 *)((u8 *)arg0->owner + 0xc);
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

s32 fn_8006C788(LGEffect *arg0, struct LGCondParam *arg1) {
    s32 current;
    s32 scale;
    s32 limit;
    s32 value;

    current = *(s32 *)((u8 *)arg0->owner + 0x64);
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

static inline void fn_8006C7E8_copy(LGFFData *arg0, s32 *src) {
    s32 i;
    for (i = 0; i < 10; i++) {
        arg0->unk_10[i] = src[i];
        arg0->unk_38[i] = 0;
    }
}

void fn_8006C7E8(LGFFData *arg0, void *arg1) {
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
    }

    fn_8006C7E8_copy(arg0, lbl_8019E114);

    arg0->unk_60 = 0;
}

/* Pushes (d, dt) into the ring buffers; returns dt. */
static inline u32 fn_8006C92C_push(LGFFData *arg0, s32 d, u32 dt) {
    arg0->unk_E8--;
    if (arg0->unk_E8 < 0) {
        arg0->unk_E8 = 15;
    }
    arg0->unk_68[arg0->unk_E8] = d;
    arg0->unk_A8[arg0->unk_E8] = dt;
    return dt;
}

/* Sums the samples of the last 16 ms and runs the 10-tap filter over the sum history. */
static inline void fn_8006C92C_filter(LGFFData *arg0) {
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

s32 fn_8006C92C(LGFFData *arg0) {
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
    LGEffect *obj;
    s32 r;
    u32 n;

    a = 0;
    b = 0;
    now = OSGetTick() / (OS_TIMER_CLOCK / 1000);
    flags = now - arg0->unk_4;  /* elapsed ms; flags is reused as scratch below */
    arg0->unk_4 = now;
    oldD = arg0->unk_8;
    arg0->unk_8 = ((LGSub *)arg0->unk_0->values)->unk_47;
    arg0->unk_C = arg0->unk_8 << 12;
    dt = fn_8006C92C_push(arg0, arg0->unk_8 - oldD, flags);
    fn_8006C92C_filter(arg0);

    for (n = 0; n < 64; n++) {
        obj = arg0->unk_0->items[n];
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
            fn_800139E8(((LGSub *)arg0->unk_0->values)->unk_0, 0x400, 0);
        } else {
            fn_800139E8(((LGSub *)arg0->unk_0->values)->unk_0, 0x600, r);
        }
    }
    return r;
}
