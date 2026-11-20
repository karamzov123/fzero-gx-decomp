#include "types.h"


/* --- dol/fn_80070DE0.c --- */
extern u32 lbl_801A6D0C;

u32 fn_80070DE0(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D0C;
    lbl_801A6D0C = arg0;
    return v0;
}

/* --- dol/fn_80070DF0.c --- */
extern u32 lbl_801A6D08;

u32 fn_80070DF0(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D08;
    lbl_801A6D08 = arg0;
    return v0;
}

/* --- dol/fn_80070E00.c --- */
extern void fn_80071C64(void);
extern void fn_80071C8C(void);

void fn_80070E00(void) {
    lbl_801A6D0C = (u32)fn_80071C64;
    lbl_801A6D08 = (u32)fn_80071C8C;
}
