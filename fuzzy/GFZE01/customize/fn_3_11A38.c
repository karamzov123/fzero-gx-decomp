/* Non-matching: best partial attempt (32.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_paste_editor.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3F;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x8];
} Bf0Entry;

struct Pool_288 {
    u8 pad_00[0x30];
    f32 unk_30;
    f32 unk_34;
    u8 pad_38[0x10];
    f64 unk_48;
    u8 pad_50[0x1C];
    f32 unk_6C;
    u8 pad_70[0x38];
    f32 unk_A8;
    u8 pad_AC[0x10];
    f32 unk_BC;
    u8 pad_C0[0xDC];
    f32 unk_19C;
    u8 pad_1A0[0x24];
    f32 unk_1C4;
    u8 pad_1C8[0x10];
    f64 unk_1D8;
    f32 unk_1E0;
    f32 unk_1E4;
    f32 unk_1E8;
    f32 unk_1EC;
    f32 unk_1F0;
    f32 unk_1F4;
    f64 unk_1F8;
    f32 unk_200;
    f32 unk_204;
    f64 unk_208;
};

extern Bf0Entry lbl_1_bss_BF0[];
extern struct Pool_288 lbl_3_rodata_288;
extern u32 lbl_3_bss_7EDCC[3];

extern void lbl_8006D758(void);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void fn_80072558(void);
extern void lbl_8006E1B0(void *, void *);
extern void fn_3_12E4C(void *, u8, Vec3F *, Vec3F *);
extern void fn_8006E250(void *);
extern void fn_80008BA8(void *, void *, u32);

void fn_3_11A38(void) {
    struct Pool_288 *pool = &lbl_3_rodata_288;
    Vec3F *p9 = (Vec3F *)&lbl_3_bss_9F690.unk_10;
    f32 f6 = 0.0f;
    f32 f5 = 0.0f;
    f32 t = 0.0f;
    f32 w;
    f32 diff;
    f32 z;
    f32 val;
    s32 c;
    Vec3F v;
    Vec3F res;
    Vec3F out1;
    Vec3F out2;

    f6 = (fabsf(lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_4) >= pool->unk_1D8)
             ? ((lbl_3_bss_7EDD8.unk_4E > 0x28) ? (pool->unk_1E0 * lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_4)
                                                  : (pool->unk_1E4 * lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_4))
             : f6;
    if (fabsf(lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_4) >= pool->unk_1D8) {
        lbl_3_bss_7EDD8.unk_4E += 1;
    } else {
        lbl_3_bss_7EDD8.unk_4E = 0;
    }
    if (fabsf(lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_0) >= pool->unk_1D8) {
        f5 = (lbl_3_bss_7EDD8.unk_4C > 0x28) ? (pool->unk_1E8 * lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_0)
                                              : (pool->unk_1E0 * lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_0);
        lbl_3_bss_7EDD8.unk_4C += 1;
    } else {
        lbl_3_bss_7EDD8.unk_4C = 0;
    }
    val = (f32)((s32)(-lbl_3_bss_7EDD8.unk_26) - 4503601774854144.0) + f6;
    val = (val < pool->unk_1EC) ? pool->unk_1EC : ((val > pool->unk_1F0) ? pool->unk_1F0 : val);
    lbl_3_bss_7EDD8.unk_26 = (s16)(s32)val;
    val = (f32)((s32)(-lbl_3_bss_7EDD8.unk_28) - 4503601774854144.0) + f5;
    lbl_3_bss_7EDD8.unk_28 = (s16)(s32)val;
    diff = lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_10 - lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_14;
    if (t == diff) {
        lbl_3_bss_7EDD8.unk_51 = 0;
    } else {
        c = lbl_3_bss_7EDD8.unk_51 + 1;
        if (c < 0) {
            c = 0;
        } else if (c > 0xFF) {
            c = 0xFF;
        }
        lbl_3_bss_7EDD8.unk_51 = c;
    }
    t += pool->unk_BC;
    if (lbl_3_bss_7EDD8.unk_C & 0x80) {
        z = lbl_3_bss_9F640.unk_C + diff * t;
        lbl_3_bss_9F640.unk_C = (z < pool->unk_1F4) ? pool->unk_1F4 : ((z > pool->unk_6C) ? pool->unk_6C : z);
    } else if (lbl_3_bss_7EDD8.unk_C & 0x100) {
        z = lbl_3_bss_9F640.unk_C + diff * t;
        lbl_3_bss_9F640.unk_C = (z < pool->unk_1F4) ? pool->unk_1F4 : ((z > pool->unk_30) ? pool->unk_30 : z);
    }
    v.x = pool->unk_34;
    v.y = pool->unk_34;
    v.z = pool->unk_34;
    if (fabsf(lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_8) < pool->unk_208
        && fabsf(lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_C) < pool->unk_208) {
        lbl_3_bss_7EDD8.unk_48 = 0;
    } else {
        lbl_3_bss_7EDD8.unk_48 += 1;
    }
    w = pool->unk_34;
    if (lbl_3_bss_7EDD8.unk_48 != 0) {
        w = (lbl_3_bss_7EDD8.unk_48 > 0x28) ? pool->unk_1C4
                                            : ((lbl_3_bss_7EDD8.unk_48 > 0x14) ? pool->unk_200 : pool->unk_19C);
    }
    if (fabsf(lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_8) >= pool->unk_208) {
        v.x = lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_8;
    }
    if (fabsf(lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_C) >= pool->unk_208) {
        v.y = lbl_1_bss_BF0[lbl_3_bss_7EDD8.unk_14].unk_C;
    }
    psvec_scale_add(p9, &v, w, &res);
    lbl_8006D758();
    mathutil_mtxA_rotate_y(lbl_3_bss_7EDD8.unk_28);
    mathutil_mtxA_rotate_x(lbl_3_bss_7EDD8.unk_26);
    fn_80072558();
    lbl_8006E1B0(&res, &res);
    fn_3_12E4C(*(void **)&lbl_3_bss_7EDCC[0], (u8)lbl_3_bss_7EDD8.unk_1C, &out1, &out2);
    res.z = (res.z < out1.z) ? out1.z : ((res.z > out2.z) ? out2.z : res.z);
    res.y = (res.y < out1.y) ? out1.y : ((res.y > out2.y) ? out2.y : res.y);
    res.x = (res.x < out1.x) ? out1.x : ((res.x > out2.x) ? out2.x : res.x);
    fn_8006E250(&res);
    res.z = pool->unk_34;
    fn_80008BA8(&lbl_3_bss_9F640.unk_10, &res, 0xC);
    fn_80008BA8(p9, &res, 0xC);
    lbl_3_bss_9F640.unk_4 = res.x;
    lbl_3_bss_9F640.unk_8 = res.y;
    lbl_3_bss_9F690.unk_4 = res.x;
    lbl_3_bss_9F690.unk_8 = res.y;
    lbl_3_bss_9F690.unk_C = pool->unk_A8;
}
