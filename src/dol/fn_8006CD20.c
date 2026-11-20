#include "types.h"


/* --- dol/fn_8006CD20.c --- */
extern f32 lbl_801A6CA0;
extern f32 lbl_801A6CA4;

void fn_8006CD20(f32 arg0, f32 arg1) {
    lbl_801A6CA4 = arg0;
    lbl_801A6CA0 = arg1;
}

/* --- dol/fn_8006CD2C.c --- */
void fn_8006CD2C(f32 *a, f32 *b) {
    *a = lbl_801A6CA4;
    *b = lbl_801A6CA0;
}

/* --- dol/fn_8006CD40.c --- */
f32 fn_8006CD40(f32 arg0) {
    f32 v0;
    v0 = lbl_801A6CA0;
    lbl_801A6CA0 = arg0;
    return v0;
}
