/* Non-matching: best partial attempt (87.88% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_800538D0_pool {
    f32 zero;
    f32 max;
    f32 min;
    f64 big;
};

struct fn_800538D0_Blk {
    f32 a[96];
    f32 b[32];
};

struct fn_800538D0_Arg0 {
    struct fn_800538D0_Blk blk[8];
};

struct fn_800538D0_Arg1 {
    f32 v[16];
};

extern const struct fn_800538D0_pool lbl_80091338;

static inline f32 fn_800538D0_read_pointer(const struct fn_800538D0_pool * owner) { return owner->zero; }
#pragma opt_common_subs off
static inline struct fn_800538D0_Blk * fn_800538D0_read_pointer_(struct fn_800538D0_Arg0 * owner) { return owner->blk; }
void fn_800538D0(struct fn_800538D0_Arg0 *arg0, struct fn_800538D0_Arg1 *arg1, u16 *arg2) {
    s32 i;
    s32 count = 32;
    for (i = 0; i < count; i++) {
        f32 v = fn_800538D0_read_pointer(&lbl_80091338);
        f32 t;
        s32 n;
        v += arg1->v[0] * arg0->blk[0].a[i];
        v += arg1->v[1] * arg0->blk[0].b[i];
        v += arg1->v[2] * arg0->blk[1].a[i];
        v += arg1->v[3] * arg0->blk[1].b[i];
        v += arg1->v[4] * arg0->blk[2].a[i];
        v += arg1->v[5] * arg0->blk[2].b[i];
        v += arg1->v[6] * arg0->blk[3].a[i];
        v += arg1->v[7] * arg0->blk[3].b[i];
        v += arg1->v[8] * arg0->blk[4].a[i];
        v += arg1->v[9] * arg0->blk[4].b[i];
        v += arg1->v[10] * arg0->blk[5].a[i];
        v += arg1->v[11] * fn_800538D0_read_pointer_(arg0)[5].b[i];
        v += arg1->v[12] * (*((arg0->blk) + (6))).a[i];
        v += arg1->v[13] * arg0->blk[6].b[i];
        v += arg1->v[14] * arg0->blk[7].a[i];
        v += arg1->v[15] * arg0->blk[7].b[i];
        arg1++;
        if (v > lbl_80091338.max) {
            v = lbl_80091338.max;
        } else if (v < lbl_80091338.min) {
            v = lbl_80091338.min;
        }
        n = (s32)v;
        t = (f32)(n >> 16);
        arg2[i] = (u16)(s32)t;
    }
}
#pragma opt_common_subs reset

