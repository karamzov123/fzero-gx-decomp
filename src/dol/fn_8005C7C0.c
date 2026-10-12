#include "types.h"

extern u8 lbl_800929D8[32];
extern u8 lbl_801A6C80[];
extern void fn_8005D258(u32, u32, u32, s32 *, s32 *);
extern f32 fn_80088578(f32);
extern const f64 lbl_801A7248;  /* 4503599627370496.0 */
extern const f32 lbl_801A7250;  /* 255.0f */
extern const f64 lbl_801A7238;  /* 20.0 */
extern const f64 lbl_801A7218;  /* 4503601774854144.0 */
extern const f32 lbl_801A7254;  /* 10.0f */

void fn_8005C7C0(s32 index) {
    u8 *base = lbl_801A6C80;
    u8 *entry = base + index * 0x118;
    u32 w0 = *(u32 *)(entry + 0x1420);
    u32 w1 = *(u32 *)(entry + 0x1424);
    u32 w2 = *(u32 *)(entry + 0x1428);
    s16 out_a;
    s16 out_b;
    u8 sel;
    u8 k;
    s32 n;
    f32 base_v;
    f32 t;
    f32 acc1;
    f32 acc2;
    f32 r1v;
    f32 r2v;
    s16 v1;
    s16 v2;
    f64 d;
    f32 scale;

    fn_8005D258((w0 >> 16) & 0xFF, w1, w2, (s32 *)&out_a, (s32 *)&out_b);

    sel = entry[0x140a];
    if ((*(u8 *)((u8 *)w1 + 6) & 0x01) != 0) {
        sel = base[sel * 0x20 + 0x590];
    }
    sel &= 0xFF;

    if (entry[0x1411] == 0xFF && entry[0x1412] == 0xFF) {
        *(u8 *)(entry + 0x1498) = sel;
        return;
    }

    n = (s16)lbl_800929D8[0x60 + sel] / 4 - 1;
    k = lbl_800929D8[0x20 + (u8)(n - 1)];

    d = *(const f64 *)((const u8 *)&lbl_801A7248 + n * 8);
    scale = *(const f32 *)((const u8 *)&lbl_801A7250 + n * 4);
    t = (f32)((f64)(s16)n - d) / scale;

    base_v = (f32)((f64)(s16)k - lbl_801A7248) / lbl_801A7250;

    /* first call: f31 = base_v stays live; f30 = base_v + 20*result */
    acc1 = (f32)(20.0 * (f64)fn_80088578(t));
    r1v = base_v + acc1;

    /* second call: same table lookup, f31 reused */
    acc2 = (f32)(20.0 * (f64)fn_80088578((f32)((f64)(s16)k - lbl_801A7248) / lbl_801A7250));
    r2v = base_v + acc2;

    v1 = (s16)(10.0f * r1v + (f64)(s16)out_a);
    v2 = (s16)(10.0f * r2v + (f64)(s16)out_b);

    if (v1 < -0x3C0) {
        v1 = -0x3C0;
    }
    if (v2 < -0x3C0) {
        v2 = -0x3C0;
    }

    if (base[index * 0x118 + 0x1411] == index) {
        v2 = v1;
    }

    *(u32 *)(entry + 0x148C) = (u32)(v2 - (*(s32 *)(entry + 0x151C) >> 16)) << 16;
    *(u32 *)(entry + 0x141C) = (u32)v2;
}
