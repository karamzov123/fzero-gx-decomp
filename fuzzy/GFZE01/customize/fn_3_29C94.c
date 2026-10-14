/* Non-matching: best partial attempt (44.85% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/toolkit.h"
#include "font.h"

extern f32 lbl_3_rodata_768[];
extern u8 lbl_1_rodata_26F8[];
extern u32 fn_3_20B3C(void *);
extern void fn_1_133DBC(void *);
extern f32 fn_1_A6FE8(void);
typedef s32 (*Callback)(u32);
extern void fn_1_8D1EC(void *, Callback, void *);
extern void fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_138120(void *);
extern void fn_3_2B750(s16, s16);
extern void fn_3_1D338(s16);
extern s32 fn_3_0(s32);
extern void fn_3_1C278(s32, s32, s32, s32, s32, f32);
extern void fn_1_49410(void);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4AE0C(const char *, ...);
extern int fn_1_4F734(FontDrawPacket *);
extern u16 fn_1_A5DB0(void);
extern f32 lbl_8006D188(s32);

void fn_3_29C94(void) {
    Obj_3_bss_241E0 *car = (Obj_3_bss_241E0 *)&lbl_3_bss_241E0;
    Obj_3_bss_F0 *state = &lbl_3_bss_F0;
    s16 *selected;
    u32 *flags;
    s32 i;
    s32 id;
    s32 index;
    f32 angle;
    f32 x;
    f32 y;
    f32 z;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 shadow[4];
    FontDrawPacket packet;

    fn_1_133DBC(0);
    car->unk_0 = lbl_3_rodata_768[0x1d0 / 4];
    car->unk_4 = lbl_3_rodata_768[0x620 / 4];
    car->unk_8 = car->unk_20;
    car->unk_C = car->unk_24;
    car->unk_38 = 0;
    car->unk_58 = 0;
    car->unk_48 = fn_1_A6FE8();
    fn_1_8D1EC(car, (Callback)fn_3_20B3C, (void *)((u8 *)state + 8));
    fn_1_134AD4();
    fn_1_13ABA8(0x28000000);
    fn_3_2B750(0x2b, state->unk_A);
    fn_1_138120(0);
    selected = (s16 *)((u8 *)state + 8);
    index = *selected;
    flags = (u32 *)((u8 *)&lbl_3_bss_140 + index * 0x81c0);
    if (!(*flags & 1)) {
        if (state->unk_C != 1 && (!(state->unk_24 & 1) || !(state->unk_24 & 8))) {
            fn_3_1D338(0);
        }
    } else {
        if (state->unk_C == 1 || ((state->unk_24 & 1) && (state->unk_24 & 8))) {
            if (!(flags[0] & 2)) fn_3_1D338(2);
            else fn_3_1D338(1);
        } else if (state->unk_C == 2) {
            shadow[1] = *(u32 *)((u8 *)lbl_3_rodata_768 + 0x608);
            fn_1_49410();
            fn_1_495C8(1);
            fn_1_496FC(lbl_3_rodata_768[0x58 / 4], lbl_3_rodata_768[0x1a0 / 4]);
            shadow[0] = *(u32 *)((u8 *)lbl_3_rodata_768 + 0x60c);
            fn_1_49514((u32 *)&shadow[0]);
            fn_3_2B750(0, state->unk_A);
            fn_1_4AE0C("");
            shadow[2] = *(u32 *)((u8 *)lbl_3_rodata_768 + 0x610);
            fn_1_49514((u32 *)&shadow[2]);
            for (i = 0; i <= 1; i++) {
                shadow[3] = *(u32 *)((u8 *)lbl_3_rodata_768 + 0x614);
                fn_1_49514((u32 *)&shadow[3]);
                if (state->unk_C == i) {
                    shadow[0] = *(u32 *)((u8 *)lbl_3_rodata_768 + 0x618);
                    fn_1_49514((u32 *)&shadow[0]);
                }
                fn_3_2B750(*(s16 *)((u8 *)selected + i * 2), state->unk_A);
                fn_1_4AE0C("");
                shadow[0] = *(u32 *)((u8 *)lbl_3_rodata_768 + 0x61c);
                fn_1_49514((u32 *)&shadow[0]);
            }
        }
    }
    {
        u32 *dst = (u32 *)&packet;
        u32 *src = (u32 *)((u8 *)lbl_1_rodata_26F8 - 4);
        for (i = 0; i < 22; i++) dst[i] = src[i + 1];
    }
    *(f32 *)((u8 *)&packet + 4) = 95.0f;
    *(f32 *)((u8 *)&packet + 8) = 16.0f;
    *(f32 *)((u8 *)&packet + 12) = 10.0f;
    fn_1_4F734(&packet);
    id = fn_1_A5DB0();
    {
        f64 conversion1;
        f64 conversion2;
        s32 diff = state->unk_2C - state->unk_2A;
        angle = (f32)fabs((f64)diff - lbl_3_rodata_768[0x98 / 4]);
        x = (f32)(id - lbl_3_rodata_768[0x1f8 / 4]) / lbl_3_rodata_768[0x170 / 4];
        x *= lbl_3_rodata_768[0x198 / 4] * lbl_3_rodata_768[0x228 / 4];
        a = (s32)x + 0x4000;
        y = (f32)fabs((f32)lbl_8006D188((s16)a));
        b = (s32)(lbl_3_rodata_768[0x19c / 4] * angle);
        z = (f32)fabs((f32)lbl_8006D188(b));
        (void)conversion1;
        (void)conversion2;
    }
    {
        s32 sc = (s32)(100.0f * z);
        s32 pos = (s16)sc;
        s32 height = (s32)(lbl_3_rodata_768[0x5c / 4] - (f32)pos * 0.5f);
        s32 offset = (s32)((lbl_3_rodata_768[0x58 / 4] - (f32)(s16)pos) * ((f32)(state->unk_2C - state->unk_2A) / 480.0f));
        lbl_3_bss_A248C.unk_4 = 0x280;
        lbl_3_bss_A248C.unk_6 = (s16)pos;
        lbl_3_bss_A248C.unk_0 = (s16)height;
        lbl_3_bss_A248C.unk_2 = (s16)offset;
    }
    if ((state->unk_24 & 1) && (state->unk_24 & 2)) {
        s16 direction = state->unk_2C > state->unk_2A ? 1 : -1;
        index = (s16)(*selected + direction + 4);
        index = (s16)((index + 4) % 4);
        fn_3_0(index);
        flags = (u32 *)((u8 *)&lbl_3_bss_140 + index * 0x81c0);
        if (!(*flags & 1)) fn_3_1C278(-1,-1,-1,-1,0,z);
        else if (!(*flags & 2)) fn_3_1C278(*(u8 *)((u8 *)flags + 0x81a0),-1,-1,-1,0,z);
        else fn_3_1C278(*(u8 *)((u8 *)flags + 0x81a0),*(u8 *)((u8 *)flags + 0x81a4),*(u8 *)((u8 *)flags + 0x81ac),*(u8 *)((u8 *)flags + 0x81b4),0,z);
        fn_3_0(*selected);
        flags = (u32 *)((u8 *)&lbl_3_bss_140 + *selected * 0x81c0);
        if (!(*flags & 1)) fn_3_1C278(-1,-1,-1,-1,0,1.0f-z);
        else if (!(*flags & 2)) fn_3_1C278(*(u8 *)((u8 *)flags + 0x81a0),-1,-1,-1,0,1.0f-z);
        else fn_3_1C278(*(u8 *)((u8 *)flags + 0x81a0),*(u8 *)((u8 *)flags + 0x81a4),*(u8 *)((u8 *)flags + 0x81ac),*(u8 *)((u8 *)flags + 0x81b4),0,1.0f-z);
    } else {
        fn_3_0(*selected);
        flags = (u32 *)((u8 *)&lbl_3_bss_140 + *selected * 0x81c0);
        if (!(*flags & 1)) fn_3_1C278(-1,-1,-1,-1,0,1.0f);
        else if (!(*flags & 2)) fn_3_1C278(*(u8 *)((u8 *)flags + 0x81a0),-1,-1,-1,0,1.0f);
        else fn_3_1C278(*(u8 *)((u8 *)flags + 0x81a0),*(u8 *)((u8 *)flags + 0x81a4),*(u8 *)((u8 *)flags + 0x81ac),*(u8 *)((u8 *)flags + 0x81b4),0,1.0f);
    }
}
