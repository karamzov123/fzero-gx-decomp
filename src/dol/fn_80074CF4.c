#include "types.h"


/* --- dol/fn_80074CF4.c --- */
extern f32 lbl_8019F130[7];

void fn_80074CF4(f32 arg0, f32 arg1, f32 arg2) {
    lbl_8019F130[0] = arg0;
    lbl_8019F130[1] = arg1;
    lbl_8019F130[2] = arg2;
}

/* --- dol/fn_80074D08.c --- */
extern u32 lbl_801A6D74;

u32 fn_80074D08(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D74;
    lbl_801A6D74 = arg0;
    return v0;
}

/* --- dol/fn_80074D18.c --- */
extern u32 lbl_801A6D64;

void fn_80074D18(u32 arg0) {
    lbl_801A6D64 = ((u32)__cntlzw(arg0) >> 5);
}
