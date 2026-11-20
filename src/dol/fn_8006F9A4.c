#include "types.h"


/* --- dol/fn_8006F9A4.c --- */
extern u32 fn_8006E5FC(void *);
extern u32 fn_8006EB4C(void *, void *, void *, f32);
extern void mathutil_mtxA_from_quat(void *);
extern u32 lbl_8006DC34(u32);
extern void lbl_8006DBAC(void *);

void fn_8006F9A4(f32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    struct { u32 a[4]; } loc_28;
    struct { u32 a[4]; } loc_18;
    struct { u32 a[4]; } loc_8;

    lbl_8006DBAC((void *)arg1);
    fn_8006E5FC((void *)&loc_28);
    lbl_8006DBAC((void *)arg2);
    fn_8006E5FC((void *)&loc_18);
    fn_8006EB4C((void *)&loc_8, (void *)&loc_28, (void *)&loc_18, arg0);
    mathutil_mtxA_from_quat((void *)&loc_8);
    lbl_8006DC34(arg3);
}

/* --- dol/fn_8006FA24.c --- */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

extern u32 lbl_8006D5A4(void *, void *, void *, f32);
extern void lbl_8006D668(void *);

static inline void cross(Vec *a, Vec *b, Vec *out) {
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

void fn_8006FA24(f32 arg0, Vec *arg1, Vec *arg2, Vec *arg3) {
    lbl_8006D5A4(&arg1[0], &arg2[0], &arg3[0], arg0);
    lbl_8006D5A4(&arg1[1], &arg2[1], &arg3[1], arg0);
    cross(&arg3[0], &arg3[1], &arg3[2]);
    cross(&arg3[2], &arg3[0], &arg3[1]);
    lbl_8006D668(&arg3[0]);
    lbl_8006D668(&arg3[1]);
    lbl_8006D668(&arg3[2]);
}
