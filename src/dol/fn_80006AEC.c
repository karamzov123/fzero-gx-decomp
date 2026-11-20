#include "types.h"


/* --- dol/fn_80006AEC.c --- */
/* --- dol/fn_80006AEC.c --- */
extern u32 lbl_801A66DC;

void fn_80006AEC(u32 arg0) {
    lbl_801A66DC = arg0;
}

/* --- dol/fn_80006AF4.c --- */
extern u8 lbl_801A66D8;

u8 fn_80006AF4(void) {
    return lbl_801A66D8;
}

/* --- dol/fn_80006AFC.c --- */
extern u32 fn_80006B30(u32);
extern u32 fn_80083DB0(u32, u32);
extern u32 lbl_8015BD40[];
extern u32 lbl_801A63F8;

void fn_80006AFC(void) {
    fn_80083DB0((u32)&lbl_8015BD40, (u32)&lbl_801A63F8);
    fn_80006B30(0);
}
