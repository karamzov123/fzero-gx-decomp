#include "types.h"


/* --- dol/fn_80007C60.c --- */
extern u32 fn_800744F8(void *, u32);
extern s32 lbl_801A6728;
extern u32 lbl_801A6F08;
extern u32 lbl_801A6408;

void fn_80007C60(s32 arg0) {
    u32 loc_8[2];

    if (arg0 || !lbl_801A6728) {
        loc_8[1] = lbl_801A6F08;
        ((u8 *)&lbl_801A6408)[0] = ((u8 *)&loc_8[1])[0];
        ((u8 *)&lbl_801A6408)[1] = ((u8 *)&loc_8[1])[1];
        ((u8 *)&lbl_801A6408)[2] = ((u8 *)&loc_8[1])[2];
        ((u8 *)&lbl_801A6408)[3] = ((u8 *)&loc_8[1])[3];
        loc_8[0] = lbl_801A6408;
        fn_800744F8(loc_8, (0x1000000 - 1));
    }
    lbl_801A6728 = 0;
}

/* --- dol/fn_80007CDC.c --- */
typedef union {
    f32 f;
    u32 u;
} FloatBits;

u32 fn_80007CDC(f32 *arg0) {
    u32 flags[2];
    FloatBits value0;
    FloatBits value1;
    FloatBits value2;

    flags[0] = 1;
    flags[1] = flags[0];
    value0.f = arg0[0];
    if ((value0.u & 0x7F800000) != 0x7F800000) {
        value1.f = arg0[1];
        if ((value1.u & 0x7F800000) != 0x7F800000) {
            flags[1] = 0;
        }
    }
    if ((s32)flags[1] == 0) {
        value2.f = arg0[2];
        if ((value2.u & 0x7F800000) != 0x7F800000) {
            flags[0] = 0;
        }
    }
    return flags[0];
}
