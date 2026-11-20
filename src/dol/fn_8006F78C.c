#include "types.h"


/* --- dol/fn_8006F78C.c --- */
extern f32 lbl_801A6618;
extern f32 lbl_801A661C;
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
