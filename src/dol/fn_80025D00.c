#include "types.h"


/* --- dol/fn_80025D00.c --- */
/* --- dol/fn_80025D00.c --- */
extern u32 fn_80008E34(u32, u32);
extern u32 lbl_801A6410;

u32 fn_80025D00(u32 arg0) {
    return fn_80008E34(lbl_801A6410, arg0);
}

/* --- dol/fn_80025D28.c --- */
extern void fn_80008E5C(u32, u32);

void fn_80025D28(u32 arg) {
    fn_80008E5C(lbl_801A6410, arg);
}

/* --- dol/fn_80025D50.c --- */
/* --- dol/fn_80025D50.c --- */
extern u32 lbl_801A64F8;
extern u32 lbl_801A64FC;

void fn_80025D50(u32 arg0, u32 arg1) {
    lbl_801A64F8 = arg0;
    lbl_801A64FC = arg1;
}
