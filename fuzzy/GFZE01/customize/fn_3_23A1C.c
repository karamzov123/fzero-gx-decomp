/* Non-matching: best partial attempt (52.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/toolkit.h"

struct Pool23A1C {
    u8 pad0[0x98];
    f64 conv;
    u8 padA0[0xE8];
    f32 one;
    f32 half;
    u8 pad190[0x20];
    f32 forty;
    u8 pad1B0[0x14];
    f32 eighty;
    u8 pad1C8[0x28];
    f32 zero;
    u8 pad1F4[4];
    f64 two52;
    u8 pad200[0x1B0];
    f32 five;
    u8 pad3B4[0x10];
    f32 tenth;
    f32 scale;
    f32 fifteen;
    f32 twoFifths;
};
extern struct Pool23A1C lbl_3_rodata_768;
extern u8 lbl_1_rodata_26F8[];
extern u32 lbl_801A66A8;
extern u32 lbl_1_data_21078[];
extern u32 lbl_1_data_212A8[];
extern u32 lbl_3_data_4B70;
extern u8 lbl_3_data_4B84[0x14];
extern Obj_3_bss_6D8C0 lbl_3_bss_6D8C0;
extern void fn_1_50164(void *, f32, f32, f32, f32);
extern void fn_1_5233C(void *, void *);
extern f32 lbl_8006D188(u32);
extern void fn_1_49410(void);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_49738(void *);
extern void fn_1_495A0(f32);
extern void fn_1_49590(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_49748(f32);
extern s16 fn_1_12C930(s16);
extern char *fn_1_14EA74(void *, char *, s16);
extern void fn_1_49514(u32 *);
extern void fn_3_23A1C(s16, s16, s16, s16, s32);

void fn_3_23A1C(s16 index, s16 base, s16 offset, s16 step, s32 mode) {
    s16 i;
    s32 total;
    s16 *item;
    u8 *entry;
    f32 y;
    f32 t;
    f32 f;
    f32 rgba;
    f32 seconds;
    f32 minutes;
    f32 hours;
    u32 color;
    u32 c;
    u32 d;
    u32 tick;
    f32 v;
    f32 w;
    f32 x;
    u32 params[4];
    u32 pos[3];
    u32 pos2[3];
    u32 dummy;
    s32 count;
    s32 now;
    s32 remainder;
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
    u8 *palette = (u8 *)&lbl_3_bss_20;
    Obj_3_bss_F0 *state = &lbl_3_bss_F0;
    struct Pool23A1C *pool = &lbl_3_rodata_768;
    void *fn = (void *)fn_1_5233C;
    i = 0;
    total = 0;
    item = (s16 *)&lbl_3_bss_20;
    while (i < 4) {
        struct { u32 words[24]; } local;
        *(u32 *)&local.words[0] = *(u32 *)((u8 *)pool + 0x3B4);
        *(u32 *)&local.words[1] = *(u32 *)((u8 *)pool + 0x3B8);
        {
            u32 j;
            u32 *src = (u32 *)(lbl_1_rodata_26F8 - 4);
            u32 *dst = (u32 *)&local.words[2];
            for (j = 0; j < 22; j += 2) {
                dst[j] = src[j + 1];
                dst[j + 1] = src[j + 2];
            }
        }
        total = index + (s32)i * step;
        pos[0] = 0;
        pos[1] = 0;
        pos[2] = 0;
        {
            f64 conv = 4503601774854144.0;
            f64 a = (f64)(s32)total + conv;
            f64 b = (f64)(s32)base + conv;
            f64 cc = (f64)(s32)offset + conv;
            pos[0] = 0x18A4;
            ((f32 *)pos)[0] = (f32)(a - conv);
            ((f32 *)pos)[1] = (f32)(b - conv);
            ((f32 *)pos)[2] = (f32)(cc - conv);
        }
        params[0] = 10;
        if (mode == 1 && i == 3) ((f32 *)params)[1] = 0.2f;
        fn_1_50164(pos, 127.0f, 40.0f, 8.0f, 8.0f);
        if (lbl_3_bss_20.unk_18 == i) {
            *(u32 *)&local.words[0] = *(u32 *)(lbl_1_rodata_26F8 - 4);
            {
                u32 j;
                u32 *src = (u32 *)(lbl_1_rodata_26F8 - 4);
                u32 *dst = (u32 *)&local.words[2];
                for (j = 0; j < 22; j += 2) {
                    dst[j] = src[j + 1];
                    dst[j + 1] = src[j + 2];
                }
            }
            params[0] = 10;
            ((f32 *)params)[1] = 0.5f;
            if (mode == 1 && i == 3) ((f32 *)params)[1] = 0.2f;
            {
                u32 tm = lbl_801A66A8;
                u32 mins = tm / 60;
                u32 secs = tm - mins * 60;
                f32 tmf = (f32)(tm - mins * 60);
                minutes = (f32)mins;
                seconds = (f32)secs;
                hours = (f32)(tm % 60);
                (void)tmf;
            }
            now = lbl_801A66A8;
            count = now / 60;
            remainder = now - count * 60;
            v = lbl_8006D188((u32)(0.0f + 65536.0f * ((f32)remainder / 60.0f)));
            red = (u8)(0.5f + 40.0f * v);
            v = lbl_8006D188((u32)(0.0f + 65536.0f * ((f32)(now % 60) / 60.0f)));
            green = (u8)(0.5f + 40.0f * v);
            v = lbl_8006D188((u32)(0.0f + 65536.0f * ((f32)(now % 60) / 60.0f)));
            blue = (u8)(0.5f + 80.0f * v);
            ((u8 *)&local)[0x38] = red;
            ((u8 *)&local)[0x39] = green;
            ((u8 *)&local)[0x3A] = blue;
            fn_1_50164(&local.words[2], 127.0f, 40.0f, 40.0f, 40.0f);
        }
        fn_1_49410();
        fn_1_495C8(1);
        if (state->unk_A == 0 || state->unk_A >= 5) {
            fn_1_4955C(0.5416667f, 0.5416667f);
        } else {
            fn_1_4955C(0.45833334f, 0.5416667f);
        }
        fn_1_4966C(-2.0f, 0.0f);
        dummy = *(u32 *)((u8 *)pool + 0x3BC);
        fn_1_49514(&dummy);
        fn_1_496FC(((f32 *)pos)[0], ((f32 *)pos)[1] - 15.0f);
        fn_1_4954C(((f32 *)pos)[2] - 1.0f);
        fn_1_49738(fn);
        if (mode == 1 && i == 3) fn_1_495A0(0.2f);
        if (state->unk_A != 5 && state->unk_A >= 0) fn_1_49590(0.5f);
        fn_3_2B750(item[0], state->unk_A);
        fn_1_4AE0C((const char *)lbl_3_data_4B70, 0);
        fn_1_49410();
        fn_1_495C8(1);
        fn_1_495B0(0x80000000);
        fn_1_4965C(2);
        fn_1_4955C(0.41666666f, 0.5f);
        dummy = *(u32 *)((u8 *)pool + 0x3C0);
        fn_1_49514(&dummy);
        fn_1_496FC(((f32 *)pos)[0], ((f32 *)pos)[1] + 5.0f - 1.0f);
        fn_1_4954C(((f32 *)pos)[2] - 1.0f);
        fn_1_49738(fn);
        fn_1_49748(1.0f);
        if (mode == 1 && i == 3) fn_1_495A0(0.2f);
        if (state->unk_A != 5 && state->unk_A >= 0) fn_1_49590(0.5f);
        if (i == 3) {
            if (state->unk_A == 5) {
                c = fn_1_12C930(((s16 *)((u8 *)&lbl_3_bss_20))[0x67]);
                fn_1_4AE0C((const char *)lbl_3_data_4B70, lbl_1_data_21078[c]);
            } else {
                c = fn_1_12C930(((s16 *)((u8 *)&lbl_3_bss_20))[0x67]);
                fn_1_4AE0C((const char *)lbl_3_data_4B70, lbl_1_data_212A8[c]);
            }
        } else {
            entry = palette;
            fn_1_14EA74((void *)(s32)((s16 *)((u8 *)&lbl_3_bss_6D8C0))[entry[0] * 8], (char *)&local.words[2], state->unk_A);
            fn_1_4AE0C((const char *)lbl_3_data_4B84, 0);
        }
        total += step;
        item++;
        palette += 8;
        i++;
    }
}
