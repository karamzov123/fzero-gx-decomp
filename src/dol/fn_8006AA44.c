#include "types.h"
#pragma optimize_for_size on

typedef struct PadOut {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    s8 unk_6;
} PadOut;

typedef struct PadIn {
    u8 pad_0[2];
    u8 unk_2;
    u8 pad_3;
    u8 unk_4;
    u8 unk_5;
} PadIn;

typedef struct PadCalib {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    s8 unk_6;
    u8 pad_7[7];
    u8 unk_E;
    u8 unk_F;
    s8 unk_10;
    u8 pad_11[7];
    u8 unk_18;
    u8 unk_19;
    u8 pad_1A[6];
    u8 unk_20;
    u8 pad_21[7];
    s32 unk_28;
} PadCalib;

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

void fn_8006AA44(PadOut *out, PadIn *in, PadCalib *calib) {
    if ((in->unk_2 ^ calib->unk_20) & 8) {
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
