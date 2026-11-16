#include "types.h"

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
} Mat34;

extern const f32 lbl_801A73F0;
extern Mat34 *lbl_801A6D00;
extern f32 lbl_8006D668(void *);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DF44(void);

static inline void fn_8006F1F0_cross(Vec3 *a, Vec3 *b, Vec3 *out) {
    f32 ax;
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = b->x;
    f32 bz = b->z;
    f32 by = b->y;
    f32 x;
    f32 y;
    f32 z;

    ax = a->x;
    x = ay * bz;
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

#pragma opt_propagation off
void fn_8006F1F0(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2) {
    Vec3 w;
    Vec3 u;
    Vec3 v;
    Mat34 *p;

    v.x = arg0->x - arg2->x;
    v.y = arg0->y - arg2->y;
    v.z = arg0->z - arg2->z;
    if (lbl_801A73F0 == lbl_8006D668(&v)) {
        lbl_8006D7DC(arg0);
        return;
    }
    fn_8006F1F0_cross(arg1, &v, &w);
    if (lbl_801A73F0 == lbl_8006D668(&w)) {
        lbl_8006D7DC(arg0);
        return;
    }
    fn_8006F1F0_cross(&v, &w, &u);
    if (lbl_801A73F0 == lbl_8006D668(&u)) {
        lbl_8006D7DC(arg0);
        return;
    }
    p = lbl_801A6D00;
    p->unk_0 = w.x;
    p->unk_4 = u.x;
    p->unk_8 = v.x;
    p->unk_C = arg0->x;
    p->unk_10 = w.y;
    p->unk_14 = u.y;
    p->unk_18 = v.y;
    p->unk_1C = arg0->y;
    p->unk_20 = w.z;
    p->unk_24 = u.z;
    p->unk_28 = v.z;
    p->unk_2C = arg0->z;
    lbl_8006DF44();
}


#pragma opt_propagation reset
