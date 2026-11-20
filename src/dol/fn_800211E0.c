#include "types.h"


/* --- dol/fn_800211E0.c --- */
extern u32 lbl_801A6AC0;
extern u32 lbl_801A6AC8;

void fn_800211E0(u32 arg0, u32 arg1) {
    lbl_801A6AC0 = arg0;
    lbl_801A6AC8 = arg1;
}

/* --- dol/fn_800211EC.c --- */
extern u32 lbl_801A6AC4;
extern u32 lbl_801A6ACC;

void fn_800211EC(u32 arg0, u32 arg1) {
    lbl_801A6AC4 = arg0;
    lbl_801A6ACC = arg1;
}

/* --- dol/fn_800211F8.c --- */
extern u32 lbl_801A6B00;

u32 fn_800211F8(void) {
    return lbl_801A6B00;
}
