#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} fn_8006FB20_Vec;

extern fn_8006FB20_Vec *lbl_801A6D00;
extern u32 lbl_8006D5A4(void *, void *, void *, f32);
extern u32 lbl_8006D668(void *);

static inline void fn_8006FB20_cross(fn_8006FB20_Vec *a, fn_8006FB20_Vec *b, fn_8006FB20_Vec *out) {
    f32 ax = a->x;
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = b->x;
    f32 bz = b->z;
    f32 by = b->y;
    f32 x;
    f32 y;
    f32 z;
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

void fn_8006FB20(f32 arg0, u32 arg1) {
    u32 tmp_lbl_8006D668;
    f32 lab_t3;
    fn_8006FB20_Vec *const p = lbl_801A6D00;

    lab_t3 = arg0;
    lbl_8006D5A4(&p[0], (void *)arg1, &p[0], lab_t3);
    lbl_8006D5A4(&p[1], (void *)(arg1 + 16), &p[1], arg0);
    fn_8006FB20_cross(&p[0], &p[1], &p[2]);
    fn_8006FB20_cross(&p[2], &p[0], &p[1]);
    tmp_lbl_8006D668 = lbl_8006D668(&p[0]);
    tmp_lbl_8006D668;
    tmp_lbl_8006D668 = lbl_8006D668(&p[1]);
    tmp_lbl_8006D668;
    tmp_lbl_8006D668 = lbl_8006D668(&p[2]);
    tmp_lbl_8006D668;
}


