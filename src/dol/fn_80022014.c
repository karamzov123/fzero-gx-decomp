#include "types.h"


/* --- dol/fn_80022014.c --- */
extern u32 lbl_801A6B20;

void fn_80022014(u32 arg0) {
    lbl_801A6B20 = arg0;
}

/* --- dol/fn_8002201C.c --- */
extern u32 lbl_80164D20[];

u32 fn_8002201C(void) {
    return (u32)&lbl_80164D20;
}
