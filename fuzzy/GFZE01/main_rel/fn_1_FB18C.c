/* Non-matching: best partial attempt (65.89% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/spline.h"
#include "psvec.h"

extern const f32 lbl_1_rodata_7480[];
extern s16 fn_1_E5430(s16);
extern Obj_1_data_2A7E0 *fn_1_E54A8(s16, s16);
extern s32 fn_1_E5770(void *, u32, u64);
extern s16 fn_1_E5568(s32);
extern void fn_1_E5930(void *, u32, u32, u32);
extern void fn_1_E594C(void *, u32, u32, u32);
extern void fn_1_E57F4(void *, f32);
extern void fn_1_E57FC(void *, void *);
extern void fn_1_E5988(void *, void *);
extern void fn_1_E5A94(void *, void *);
extern void fn_1_DE180(void *, void *, f32);
extern void fn_80008BEC(void *, s32, u32);
extern u32 lbl_801A66A0;
extern u32 lbl_801A63C0;

typedef struct { f32 x,y,z; } V3;
typedef struct { u8 pad[0x154]; s32 timer; } Obj;
typedef struct { u32 unk0; s16 unk4, unk6, unk8, unkA; u16 unkC; u8 pad[10]; f32 x,y,z,w; } Bss;

void fn_1_FB18C(void) {
    s16 count, i;
    Obj_1_data_2A7E0 *obj;
    Obj *o;
    u32 seed;
    s16 j;
    f32 f;
    f64 d;
    V3 a, b, c;
    u32 scratch[26];

    count = fn_1_E5430(4);
    scratch[0] = *(u32 *)(lbl_1_rodata_7480 + 0x3c);
    scratch[1] = *(u32 *)(lbl_1_rodata_7480 + 0x3d);
    scratch[2] = *(u32 *)(lbl_1_rodata_7480 + 0x3e);
    for (i = 0; i < count; i++) {
        obj = fn_1_E54A8(4, i);
        o = (Obj *)obj;
        if (fn_1_E5770(obj, 0, 0x20)) {
            f = 0.0f + 0.99f * *(f32 *)((u8 *)obj + 0x84) * *(f32 *)((u8 *)obj + 0xf4);
            if (*(f32 *)((u8 *)obj + 0x58) < f) {
                *(f32 *)((u8 *)obj + 0x58) = f;
                fn_1_DE180(obj, scratch, 0.05f * *(f32 *)((u8 *)obj + 0x18));
                fn_1_E5930(obj, 0, 0x40000000, 0);
            }
        }
    }
    count = fn_1_E5430(4);
    d = 4503599627370496.0;
    for (i = 0; i < count; i++) {
        obj = fn_1_E54A8(4, i);
        o = (Obj *)obj;
        if (!fn_1_E5770(obj, 0, 3))
            o->timer++;
        f = ((s16)*(s16 *)((u8 *)obj + 8) % 2) == 0 ? 240.0f : 120.0f;
        if ((f32)o->timer > f) {
            o->timer = 0;
            fn_1_E5930(obj, 0, 3, 0);
        } else {
            f = f - (f32)o->timer;
            if (f < 30.0f) {
                f = f / 30.0f;
                if (f < 0.0f) f = 0.0f;
                else if (f > 1.0f) f = 1.0f;
                fn_1_E57F4(obj, f);
            }
        }
    }
    if (lbl_1_bss_84428.unk_0 != 1) return;
    if (lbl_1_bss_84428.unk_4 != -1) {
        s16 n = lbl_1_bss_84428.unk_4;
        n--;
        lbl_1_bss_84428.unk_4 = n;
        if (n > 0) n--;
        else n = 0;
        lbl_1_bss_84428.unk_4 = n;
    }
    if (lbl_1_bss_84428.unk_4 == 0) lbl_1_bss_84428.unk_0 = 0;
    count = fn_1_E5430(4);
    if (lbl_801A66A0 % lbl_1_bss_84428.unk_6 != 0) return;
    for (i = 0, j = 0; i < count; i++) {
        obj = fn_1_E54A8(4, i);
        if (!fn_1_E5770(obj, 0, 3)) continue;
        if (j >= lbl_1_bss_84428.unk_8) continue;
        if (fn_1_E5568(4) >= lbl_1_bss_84428.unk_A) continue;
        fn_1_E594C(obj, 0, 3, 0);
        fn_1_E594C(obj, 0, 0x8000, 0);
        fn_1_E57F4(obj, 1.0f);
        ((Obj *)obj)->timer = 0;
        seed = lbl_801A63C0;
        seed = seed * 0x676A4B6B + 0x33cb;
        lbl_801A63C0 = seed;
        a.x = -0.5f * lbl_1_bss_84428.unk_1C + (f32)((seed >> 16) & 0x7fff) / 32767.0f * lbl_1_bss_84428.unk_1C;
        a.y = -0.5f * lbl_1_bss_84428.unk_20 + (f32)(((seed * 0x676A4B6B + 0x33cb) >> 16) & 0x7fff) / 32767.0f * lbl_1_bss_84428.unk_20;
        a.z = -0.5f * lbl_1_bss_84428.unk_24 + (f32)(((seed * 0x676A4B6B + 0x33cb) * 0x676A4B6B + 0x33cb >> 16) & 0x7fff) / 32767.0f * lbl_1_bss_84428.unk_24;
        psvec_add(&lbl_1_bss_84428.unk_18, &a, &b);
        fn_1_E5988(obj, &b);
        seed = lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33cb;
        c.x = ((f32)((seed >> 16) & 0x7fff) - 4503599627370496.0f) * 0.052359879f;
        c.y = ((f32)((seed * 0x676A4B6B + 0x33cb >> 16) & 0x7fff) - 4503599627370496.0f) * 0.052359879f;
        c.z = ((f32)((seed * 0x676A4B6B + 0x33cb * 0x676A4B6B + 0x33cb >> 16) & 0x7fff) - 4503599627370496.0f) * 0.052359879f;
        fn_1_E5A94(obj, &c);
        fn_80008BEC(&b, 0, 12);
        fn_1_E57FC(obj, &b);
        j++;
    }
}
