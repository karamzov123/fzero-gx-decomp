#include "types.h"


/* --- dol/fn_80021910.c --- */
// fn_80021910: empty in retail (single blr).
void fn_80021910(void) {
}

/* --- dol/fn_80021914.c --- */
extern u32 lbl_801A6B08;

void fn_80021914(u32 arg0) {
    if (lbl_801A6B08 == arg0) { return; }
    lbl_801A6B08 = arg0;
}

/* --- dol/fn_80021928.c --- */
u32 fn_80021928(void) {
    return lbl_801A6B08;
}
