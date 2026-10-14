/* Non-matching: best partial attempt (25.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/effect_car.h"

struct fn_1_71024_lbl_1_rodata_2D70 {
    f32 unk_0;
    u8 pad_4[0x14];
    f32 unk_18;
    f32 unk_1C;
    f32 unk_24;
    u8 pad_28[0x18];
    f64 unk_40;
    f32 unk_48;
    u8 pad_4C[0x28];
    f32 unk_74;
    u8 pad_78[0x10];
    f64 unk_88;
    f32 unk_90;
    f32 unk_94;
    u8 pad_98[0x2C];
    f64 unk_D0;
    u8 pad_D8[0x4C];
    f32 unk_124;
    u8 pad_128[0x5C];
    f32 unk_184;
};
extern struct fn_1_71024_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern u32 fn_1_584AC(void);
extern int fn_1_58C4(void);
extern void fn_1_681C(u8, void *);
extern u32 fn_1_59078(void *);
extern f32 lbl_8006D0B4(f32);
extern u8 *memset(u8 *, int, u32);

typedef struct Vec3 {
    f32 x, y, z;
} Vec3;

u32 fn_1_71024(void *arg0, Vec3 *arg1, u32 arg2, f32 arg3) {
    struct {
        u8 pad_0[4];
        s16 unk_18;
        s16 unk_1A;
        s16 unk_1C;
        u8 pad_1E[2];
        s16 unk_20;
        u8 pad_22[6];
        f32 unk_C4;
        u8 pad_2C[8];
        u32 unk_34;
        u8 pad_38[4];
        f32 unk_3C;
        f32 unk_40;
        f32 unk_44;
        Vec3 unk_48;
        u8 pad_54[4];
        s16 unk_58;
        u8 pad_5A[0x5A];
        f32 unk_C8;
        u8 pad_CC[0x7C];
    } loc;
    u32 *car = (u32 *)((u8 *)arg0 + 0x38);
    u32 count;
    u32 i;
    u32 random;
    Vec3 point;
    f32 best;
    f32 x;
    f32 y;
    f32 z;
    s32 index;

    memset((u8 *)&loc, 0, 0xE8);
    loc.unk_1C = -1;
    loc.unk_18 = *(s16 *)((u8 *)arg0 + 0x18);
    loc.unk_20 = 34;
    random = fn_1_584AC();
    if ((((random & 0xFFFF) >> 15) ^ (random & 1)) - ((random & 0xFFFF) >> 15)) {
        loc.unk_34 = *(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38458 + 8) + 0x50);
    } else {
        loc.unk_34 = *(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38458 + 8) + 0x58);
    }
    random = fn_1_584AC() & 0xFFFF;
    loc.unk_3C = *(f32 *)((u8 *)arg0 + 0x3C) +
        (f64)2.0 * ((f32)random / 32767.0f - (f64)0.5);
    random = fn_1_584AC() & 0xFFFF;
    loc.unk_40 = *(f32 *)((u8 *)arg0 + 0x40) +
        (f64)2.0 * ((f32)random / 32767.0f - (f64)0.5);
    random = fn_1_584AC() & 0xFFFF;
    loc.unk_44 = *(f32 *)((u8 *)arg0 + 0x44) +
        (f64)2.0 * ((f32)random / 32767.0f - (f64)0.5);

    loc.unk_48.x = *(f32 *)((u8 *)arg0 + 0x48);
    loc.unk_48.y = *(f32 *)((u8 *)arg0 + 0x4C);
    loc.unk_48.z = *(f32 *)((u8 *)arg0 + 0x50);
    loc.unk_48.x += 0.5f * arg1->x;
    loc.unk_48.y += 0.5f * arg1->y;
    loc.unk_48.z += 0.5f * arg1->z;
    loc.unk_3C = loc.unk_3C - loc.unk_48.x;
    loc.unk_40 = loc.unk_40 - loc.unk_48.y;
    loc.unk_44 = loc.unk_44 - loc.unk_48.z;

    random = fn_1_584AC() & 0xFFFF;
    loc.unk_C8 = 0.8f + 0.2f * ((f32)random / 32767.0f);
    loc.unk_C4 = arg3 * loc.unk_C8;
    loc.unk_3C = 0.0f;
    random = fn_1_584AC() & 0xFFFF;
    x = 0.8f + 0.2f * ((f32)random / 32767.0f);
    loc.unk_40 = 0.5f * (1.0f + x);
    loc.unk_44 = (136.0f * x) / 255.0f;
    random = fn_1_584AC();
    loc.unk_58 = (s16)random;
    random = fn_1_584AC() & 0xFFFF;
    index = (s16)((0.8f + 0.2f * ((f32)random / 32767.0f)) *
                  (f32)arg2);

    if (*(s8 *)((u8 *)car[0] + 0x475) != -1) {
        count = fn_1_58C4();
        fn_1_681C(0, &point);
        x = *(f32 *)((u8 *)arg0 + 0x3C) - point.x;
        y = *(f32 *)((u8 *)arg0 + 0x40) - point.y;
        z = *(f32 *)((u8 *)arg0 + 0x44) - point.z;
        best = lbl_8006D0B4((f32)(x*x) + y*y + z*z);
        for (i = 1; i < count; i++) {
            fn_1_681C((u8)i, &point);
            x = *(f32 *)((u8 *)arg0 + 0x3C) - point.x;
            y = *(f32 *)((u8 *)arg0 + 0x40) - point.y;
            z = *(f32 *)((u8 *)arg0 + 0x44) - point.z;
            if (best >= lbl_8006D0B4((f32)(x*x) + y*y + z*z)) {
                x = *(f32 *)((u8 *)arg0 + 0x3C) - point.x;
                y = *(f32 *)((u8 *)arg0 + 0x40) - point.y;
                z = *(f32 *)((u8 *)arg0 + 0x44) - point.z;
                best = lbl_8006D0B4((f32)(x*x) + y*y + z*z);
            }
        }
        x = best / 800.0f * 10.0f;
        if (x < 1.0f) {
            loc.unk_C8 = 1.0f;
        } else if (x > 10.0f) {
            loc.unk_C8 = 10.0f;
        } else {
            loc.unk_C8 = x;
        }
    } else {
        loc.unk_C8 = 1.0f;
    }
    return fn_1_59078(&loc);
}
