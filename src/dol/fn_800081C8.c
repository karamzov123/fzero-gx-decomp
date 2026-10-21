#include "types.h"
extern u32 lbl_801A66A0;
extern u32 fn_80007F70(u8 *, u8 *, s32, f32);
typedef struct { u8 r, g, b, a; } Color;
u32 fn_800081C8(Color arg0, Color arg1, f32 arg2) {
    Color color0;
    Color color1;
    color1 = arg1;
    color0 = arg0;
    return fn_80007F70((u8 *)&color0, (u8 *)&color1, lbl_801A66A0, arg2);
}
