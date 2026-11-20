#include "types.h"


/* --- dol/fn_80058ED4.c --- */
extern u32 lbl_8018FF68[];

void fn_80058ED4(u32 arg0, u32 arg1) {
    u32 *p;
    p = lbl_8018FF68;
    *p++ = arg0;
    *p = arg1;
}

/* --- dol/fn_80058EE4.c --- */
extern u32 lbl_8018FF70[];

void fn_80058EE4(u32 arg0, u32 arg1) {
    u32 *p;
    p = lbl_8018FF70;
    *p++ = arg0;
    *p = arg1;
}
