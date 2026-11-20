#include "types.h"


/* --- dol/fn_800211E0.c --- */
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

/* --- dol/fn_80021200.c --- */
extern u32 lbl_801A6AF8;
extern u8 lbl_8015FF00[1536];
extern u32 lbl_801A6AFC;

u8 *fn_80021200(void) {
    u32 index = lbl_801A6AF8;
    u8 *base = lbl_8015FF00;
    u8 *old = base;

    lbl_801A6AF8 = index + 1;
    old += index * 0x300;
    lbl_801A6AF8 &= 1;
    lbl_801A6AFC = (u32)(base + lbl_801A6AF8 * 0x300);
    return old;
}
