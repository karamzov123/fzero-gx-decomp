#include "types.h"


/* --- dol/fn_80009468.c --- */
extern u32 lbl_8015BE40[40];
extern u32 lbl_801A6730;

void fn_80009468(void) {
    s32 i;

    for (i = 0; i < 40; i += 5) {
        lbl_8015BE40[i] = -1;
        lbl_8015BE40[i + 1] = 0;
        lbl_8015BE40[i + 2] = 0;
        lbl_8015BE40[i + 3] = 0;
        lbl_8015BE40[i + 4] = 0;
    }
    lbl_801A6730 = -1;
}

/* --- dol/fn_8000951C.c --- */
extern u32 lbl_8015BEE0[8];
extern u32 lbl_801A6410;
extern u32 lbl_801A6744;
extern u32 lbl_801A6740;
extern u32 lbl_801A673C;
extern u32 lbl_801A6738;

void fn_8000951C(u32 arg0) {
    if ((s32)lbl_801A6730 != -1) {
        lbl_8015BEE0[0] = lbl_801A6410;
        lbl_8015BEE0[1] = lbl_801A6744;
        lbl_8015BEE0[2] = lbl_801A6740;
        lbl_8015BEE0[3] = lbl_801A673C;
        lbl_8015BEE0[4] = lbl_801A6738;
        lbl_801A6410 = lbl_8015BE40[lbl_801A6730 * 5];
        lbl_801A6744 = lbl_8015BE40[lbl_801A6730 * 5 + 1];
        lbl_801A6740 = lbl_8015BE40[lbl_801A6730 * 5 + 2];
        lbl_801A673C = lbl_8015BE40[lbl_801A6730 * 5 + 3];
        lbl_801A6738 = lbl_8015BE40[lbl_801A6730 * 5 + 4];
    }
}

/* --- dol/fn_800095A4.c --- */
void fn_800095A4(void) {
    if ((s32)lbl_801A6730 != -1) {
        lbl_8015BE40[lbl_801A6730 * 5] = lbl_801A6410;
        lbl_8015BE40[lbl_801A6730 * 5 + 1] = lbl_801A6744;
        lbl_8015BE40[lbl_801A6730 * 5 + 2] = lbl_801A6740;
        lbl_8015BE40[lbl_801A6730 * 5 + 3] = lbl_801A673C;
        lbl_8015BE40[lbl_801A6730 * 5 + 4] = lbl_801A6738;
        lbl_801A6410 = lbl_8015BEE0[0];
        lbl_801A6744 = lbl_8015BEE0[1];
        lbl_801A6740 = lbl_8015BEE0[2];
        lbl_801A673C = lbl_8015BEE0[3];
        lbl_801A6738 = lbl_8015BEE0[4];
    }
}
