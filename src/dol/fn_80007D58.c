#include "types.h"


/* --- dol/fn_80007D58.c --- */
typedef union {
    f32 f;
    u32 u;
} FloatBits;

u32 fn_80007D58(f32 *arg0) {
    u32 flags[11];
    FloatBits value3;
    FloatBits value7;
    FloatBits value11;
    FloatBits value0;
    FloatBits value1;
    FloatBits value2;
    FloatBits value4;
    FloatBits value5;
    FloatBits value6;
    FloatBits value8;
    FloatBits value9;
    FloatBits value10;

    flags[0] = 1;
    flags[1] = flags[0];
    flags[2] = flags[0];
    flags[3] = flags[0];
    flags[4] = flags[0];
    flags[5] = flags[0];
    flags[6] = flags[0];
    flags[7] = flags[0];
    flags[8] = flags[0];
    flags[9] = flags[0];
    flags[10] = flags[0];
    value0.f = arg0[0];
    if ((value0.u & 0x7F800000) != 0x7F800000) {
        value1.f = arg0[1];
        if ((value1.u & 0x7F800000) != 0x7F800000) {
            flags[10] = 0;
        }
    }
    if ((s32)flags[10] == 0) {
        value2.f = arg0[2];
        if ((value2.u & 0x7F800000) != 0x7F800000) flags[9] = 0;
    }
    if ((s32)flags[9] == 0) {
        value4.f = arg0[4];
        if ((value4.u & 0x7F800000) != 0x7F800000) flags[8] = 0;
    }
    if ((s32)flags[8] == 0) {
        value5.f = arg0[5];
        if ((value5.u & 0x7F800000) != 0x7F800000) flags[7] = 0;
    }
    if ((s32)flags[7] == 0) {
        value6.f = arg0[6];
        if ((value6.u & 0x7F800000) != 0x7F800000) flags[6] = 0;
    }
    if ((s32)flags[6] == 0) {
        value8.f = arg0[8];
        if ((value8.u & 0x7F800000) != 0x7F800000) flags[5] = 0;
    }
    if ((s32)flags[5] == 0) {
        value9.f = arg0[9];
        if ((value9.u & 0x7F800000) != 0x7F800000) flags[4] = 0;
    }
    if ((s32)flags[4] == 0) {
        value10.f = arg0[10];
        if ((value10.u & 0x7F800000) != 0x7F800000) flags[3] = 0;
    }
    if ((s32)flags[3] == 0) {
        value3.f = arg0[3];
        if ((value3.u & 0x7F800000) != 0x7F800000) flags[2] = 0;
    }
    if ((s32)flags[2] == 0) {
        value7.f = arg0[7];
        if ((value7.u & 0x7F800000) != 0x7F800000) flags[1] = 0;
    }
    if ((s32)flags[1] == 0) {
        value11.f = arg0[11];
        if ((value11.u & 0x7F800000) != 0x7F800000) flags[0] = 0;
    }
    return flags[0];
}

/* --- dol/fn_80007F70.c --- */
extern f32 lbl_8006D188(s32);
extern const f32 lbl_801A6F14;
extern const f32 lbl_801A6F10;
extern const f64 lbl_801A6F18;
typedef union { struct { u8 r,g,b,a; } c; u32 word; } Color;
u32 fn_80007F70(u8 *arg0, u8 *arg1, s32 arg2, f32 arg3) {
    Color result;
    f32 blend;
    f32 r, g, b, a;
    u8 temp;
    blend = lbl_801A6F10 * (lbl_801A6F14 + lbl_8006D188((s16)(arg3 * ((arg2 & 63) << 10))));
    if (arg0[0] < arg1[0]) {
        temp = arg1[0]; arg1[0] = arg0[0]; arg0[0] = temp;
        r = lbl_801A6F18 - blend;
    } else r = blend;
    if (arg0[1] < arg1[1]) {
        temp = arg1[1]; arg1[1] = arg0[1]; arg0[1] = temp;
        g = lbl_801A6F18 - blend;
    } else g = blend;
    if (arg0[2] < arg1[2]) {
        temp = arg1[2]; arg1[2] = arg0[2]; arg0[2] = temp;
        b = lbl_801A6F18 - blend;
    } else b = blend;
    if (arg0[3] < arg1[3]) {
        temp = arg1[3]; arg1[3] = arg0[3]; arg0[3] = temp;
        a = lbl_801A6F18 - blend;
    } else a = blend;
    result.c.r = arg0[0] - (u8)(r * ((f32)arg0[0] - arg1[0]));
    result.c.g = arg0[1] - (u8)(g * ((f32)arg0[1] - arg1[1]));
    result.c.b = arg0[2] - (u8)(b * ((f32)arg0[2] - arg1[2]));
    result.c.a = arg0[3] - (u8)(a * ((f32)arg0[3] - arg1[3]));
    return result.word;
}
