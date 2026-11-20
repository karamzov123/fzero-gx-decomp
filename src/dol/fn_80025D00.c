#include "types.h"


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
