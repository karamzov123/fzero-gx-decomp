#include "types.h"


/* --- dol/fn_80074A60.c --- */
extern u32 lbl_801A6D5C;
extern u32 lbl_801A6D60;

void fn_80074A60(u32 arg0, u32 arg1) {
    lbl_801A6D60 = arg0;
    lbl_801A6D5C = arg1;
}

/* --- dol/fn_80074A6C.c --- */
void fn_80074A6C(void) {
    lbl_801A6D60 = 0xFFFFFFFF;
    lbl_801A6D5C = 0xFFFFFFFF;
}

/* --- dol/fn_80074A7C.c --- */
extern u32 lbl_801A6D40;

u32 fn_80074A7C(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D40;
    lbl_801A6D40 = arg0;
    return v0;
}
