#include "types.h"


/* --- dol/fn_80074D68.c --- */
extern f32 lbl_801A6D68;
extern f32 lbl_801A6D6C;
extern f32 lbl_801A6D70;

void fn_80074D68(f32 arg0, f32 arg1, f32 arg2) {
    lbl_801A6D70 = arg0;
    lbl_801A6D6C = arg1;
    lbl_801A6D68 = arg2;
}

/* --- dol/fn_80074D78.c --- */
extern u32 lbl_801A6D58;

void fn_80074D78(u32 arg0) {
    lbl_801A6D58 = ((u32)__cntlzw(arg0) >> 5);
}
