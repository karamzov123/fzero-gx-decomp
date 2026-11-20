#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_80008C20_Vec;

extern u32 lbl_801A6D00[2];
extern f32 lbl_8006D668(void *);
extern void lbl_8006D7DC(void *);
extern const f32 lbl_801A6F30;

static inline void fn_80008C20_cross(fn_80008C20_Vec *a, fn_80008C20_Vec *b, fn_80008C20_Vec *out) {
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
void fn_80008C20(fn_80008C20_Vec *arg0, fn_80008C20_Vec *arg1, fn_80008C20_Vec *arg2) {
    fn_80008C20_Vec t;
    fn_80008C20_Vec t2;
    fn_80008C20_Vec v;
    f32 *p;

    v.x = -arg2->x;
    v.y = -arg2->y;
    v.z = -arg2->z;
    if (lbl_8006D668(&v) == 0.0f) {
        lbl_8006D7DC(arg0);
        return;
    }
    fn_80008C20_cross(arg1, &v, &t);
    if (lbl_8006D668(&t) == 0.0f) {
        lbl_8006D7DC(arg0);
        return;
    }
    fn_80008C20_cross(&v, &t, &t2);
    if (lbl_8006D668(&t2) == 0.0f) {
        lbl_8006D7DC(arg0);
        return;
    }
    p = (f32 *)((lbl_801A6D00)[0]);
    p[0] = t.x;
    p[1] = t2.x;
    p[2] = v.x;
    p[3] = arg0->x;
    p[4] = t.y;
    p[5] = t2.y;
    p[6] = v.y;
    p[7] = arg0->y;
    p[8] = t.z;
    p[9] = t2.z;
    p[10] = v.z;
    p[11] = arg0->z;
}

#pragma opt_propagation reset
