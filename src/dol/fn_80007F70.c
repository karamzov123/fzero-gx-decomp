#include "types.h"
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
    blend = lbl_801A6F10 * (lbl_801A6F14 + lbl_8006D188((s16)(arg3 * (f32)((arg2 & 63) << 10))));
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
    result.c.r = arg0[0] - (u8)(r * ((f32)(u32)arg0[0] - (f32)(u32)arg1[0]));
    result.c.g = arg0[1] - (u8)(g * ((f32)(u32)arg0[1] - (f32)(u32)arg1[1]));
    result.c.b = arg0[2] - (u8)(b * ((f32)(u32)arg0[2] - (f32)(u32)arg1[2]));
    result.c.a = arg0[3] - (u8)(a * ((f32)(u32)arg0[3] - (f32)(u32)arg1[3]));
    return result.word;
}
