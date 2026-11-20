#include "types.h"


/* --- dol/fn_8006FEFC.c --- */
extern u32 fn_8001BE6C(void);
extern u32 lbl_801A6CCC;
extern u32 lbl_801A6CD0;
extern u32 *lbl_801A6D30;
extern void VISetNextFrameBuffer(u32 value);
extern void VIFlush(void);
extern void VIWaitForRetrace(void);
extern u32 lbl_801A6CE0;

void fn_8006FEFC(void) {
    while (fn_8001BE6C() - lbl_801A6CCC < lbl_801A6CD0 - 1) {
    }

    VISetNextFrameBuffer(*lbl_801A6D30);
    VIFlush();
    VIWaitForRetrace();

    if ((lbl_801A6CE0 & 0x20) == 0) {
        lbl_801A6D30[0] = lbl_801A6D30[1 + lbl_801A6D30[4]];
        lbl_801A6D30[4] ^= 1;
    }

    lbl_801A6D30[3]++;
}

/* --- dol/fn_8006FF8C.c --- */
/* --- dol/fn_8006FF8C.c --- */

void fn_8006FF8C(s32 value) {
    if (value != 0 || ((value = lbl_801A6CE0) & 0x10) != 0) {
        lbl_801A6CE0 |= 0x20;
    } else {
        lbl_801A6CE0 = value & ~0x20;
    }
}

/* --- dol/fn_8006FFBC.c --- */
extern u32 lbl_801A6CD4;

u32 fn_8006FFBC(void) {
    return lbl_801A6CD4;
}

/* --- dol/fn_8006FFC4.c --- */

void fn_8006FFC4(u32 arg0) {
    lbl_801A6CD0 = arg0;
}

/* --- dol/fn_8006FFCC.c --- */
extern u32 lbl_801A6CB0;

u32 fn_8006FFCC(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6CB0;
    lbl_801A6CB0 = arg0;
    return v0;
}
