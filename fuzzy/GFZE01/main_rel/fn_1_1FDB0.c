/* Non-matching: best partial attempt (94.15% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

struct Vec {
    f32 x;
    f32 y;
    f32 z;
};

struct fn_1_1FDB0_obj {
    u8 pad_0[0xD4];
    struct Vec v;
};

extern const f32 lbl_1_rodata_6D0;
extern f32 lbl_1_rodata_6D4;
extern f32 lbl_8006D0B4(f32);
extern struct fn_1_1FDB0_obj *lbl_801A66CC;

static inline f32 len2(f32 x, f32 y, f32 z) {
    return (f32)(x * x) + y * y + z * z;
}

#pragma opt_dead_assignments off
void fn_1_1FDB0(struct Vec *a, struct Vec *b, struct Vec *c, struct Vec *out) {
    f32 tmp_call9;
    struct Vec d1;
    struct Vec d2;
    struct Vec d3;
    f32 t;
    f32 num;
    f32 den;
    f32 l1;
    f32 l2;

    psvec_sub(&c->x, &b->x, &d1.x);
    psvec_sub(&b->x, &a->x, &d2.x);

    num = (f32)(d1.x * d2.x) + d1.y * d2.y + d1.z * d2.z;
    den = (f32)(d1.x * d1.x) + d1.y * d1.y + d1.z * d1.z;
    t = -num / den;

    if (((*(u32 *)&t & 0x7F800000) - 0x7F800000) == 0) {
        *out = *b;
        tmp_call9 = lbl_8006D0B4(len2(d2.x, d2.y, d2.z));
        tmp_call9;
    } else if (lbl_1_rodata_6D0 <= t && t <= lbl_1_rodata_6D4) {
        psvec_scale(&d1.x, t, &lbl_801A66CC->v.x);
        psvec_add(&d2.x, &lbl_801A66CC->v.x, &d2.x);
        psvec_add(&b->x, &lbl_801A66CC->v.x, &out->x);
        lbl_8006D0B4(len2(d2.x, d2.y, d2.z));
    } else {
        psvec_sub(&c->x, &a->x, &d3.x);
        l1 = len2(d2.x, d2.y, d2.z);
        l2 = len2(d3.x, d3.y, d3.z);
        if (l1 < l2) {
            *out = *b;
            tmp_call9 = lbl_8006D0B4(l1);
            tmp_call9;
        } else {
            *out = *c;
            lbl_8006D0B4(l2);
        }
    }
}
#pragma opt_dead_assignments reset
