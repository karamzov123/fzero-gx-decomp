#include "types.h"


/* --- dol/fn_8006F774.c --- */
extern f32 lbl_801A6618;
extern f32 lbl_801A661C;
extern f32 lbl_801A73FC;

f32 fn_8006F774(f32 arg0, f32 arg1) {
    lbl_801A6618 = (arg0 * lbl_801A73FC);
    lbl_801A661C = (arg1 * lbl_801A73FC);
    return (arg0 * lbl_801A73FC);
}

/* --- dol/fn_8006F78C.c --- */
/* --- dol/fn_8006F78C.c --- */
extern const f32 lbl_801A7408;
extern const f64 lbl_801A7400;
extern void lbl_8006E1B0(void *, void *);

typedef struct {
    f32 value0;
    f32 value1;
    f32 value2;
} Fn8006F78CData;

void fn_8006F78C(void *arg0, Fn8006F78CData *arg1, f32 arg2) {
    f32 value0;
    f32 value1;
    f32 value2;
    f32 factor;

    lbl_8006E1B0(arg0, arg1);
    value2 = arg1->value2;
    if (__fabsf(value2) > lbl_801A7400) {
        factor = lbl_801A661C / (value2 * arg2);
        value0 = -arg1->value0 * factor;
        arg1->value0 = lbl_801A6618 + value0;
        value1 = arg1->value1 * factor;
        arg1->value1 = lbl_801A661C + value1;
    } else {
        arg1->value0 = lbl_801A7408;
        arg1->value1 = lbl_801A7408;
    }
}

/* --- dol/fn_8006F828.c --- */
extern const f32 lbl_801A73F0;
extern const f32 lbl_801A740C;

typedef struct {
    f32 value0;
    f32 value1;
    f32 value2;
} Fn8006F828Data;

void fn_8006F828(void *arg0, Fn8006F828Data *arg1, f32 arg2) {
    f32 value0;
    f32 value1;
    f32 value2;
    f32 factor;
    f32 cur0;
    f32 cur1;

    lbl_8006E1B0(arg0, arg1);
    value2 = arg1->value2;
    if (__fabsf(value2) > lbl_801A7400) {
        factor = lbl_801A661C / (value2 * arg2);
        value0 = -arg1->value0 * factor;
        arg1->value0 = lbl_801A6618 + value0;
        value1 = arg1->value1 * factor;
        arg1->value1 = lbl_801A661C + value1;
        cur0 = arg1->value0;
        if (cur0 < lbl_801A740C * lbl_801A6618 && cur0 > lbl_801A73F0) {
            cur1 = arg1->value1;
            if (cur1 < lbl_801A740C * lbl_801A661C && cur1 > lbl_801A73F0) {
                return;
            }
        }
    }
    arg1->value0 = lbl_801A7408;
    arg1->value1 = lbl_801A7408;
}

/* --- dol/fn_8006F900.c --- */
extern const f32 lbl_801A73F8;

typedef struct {
    f32 value0;
    f32 value4;
    f32 value8;
} Fn8006F900Data;

void fn_8006F900(void *arg0, Fn8006F900Data *arg1, f32 arg2) {
    f32 value8;
    f32 factor;

    lbl_8006E1B0(arg0, arg1);
    value8 = arg1->value8;
    if (__fabsf(value8) > lbl_801A7400) {
        factor = lbl_801A73F8 / (value8 * arg2);
        arg1->value0 = factor * (arg1->value0 * (lbl_801A740C * lbl_801A661C / (lbl_801A740C * lbl_801A6618)));
        arg1->value4 = arg1->value4 * factor;
    } else {
        arg1->value0 = lbl_801A7408;
        arg1->value4 = lbl_801A7408;
    }
}

/* --- dol/fn_8006F9A4.c --- */
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
    fn_8006E5FC(&loc_28);
    lbl_8006DBAC((void *)arg2);
    fn_8006E5FC(&loc_18);
    fn_8006EB4C(&loc_8, &loc_28, &loc_18, arg0);
    mathutil_mtxA_from_quat(&loc_8);
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
