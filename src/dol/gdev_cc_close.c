#include "types.h"


/* --- dol/gdev_cc_close.c --- */
// gdev_cc_close: returns a constant.
int gdev_cc_close(void) {
    return 0;
}

/* --- dol/gdev_cc_open.c --- */
extern u32 lbl_801A6E10;

s32 gdev_cc_open(u32 arg0) {
    u32 v0;
    v0 = arg0;
    if ((s32)lbl_801A6E10 != 0) {
    v0 = -10005;
    return v0;
    }
    v0 = 0;
    lbl_801A6E10 = 1;
    return v0;
}

/* --- dol/gdev_cc_shutdown.c --- */
// gdev_cc_shutdown: returns a constant.
int gdev_cc_shutdown(void) {
    return 0;
}

/* --- dol/gdev_cc_initialize.c --- */
extern u32 MWTRACE(u32, ...);
extern u32 fn_8008E324(u32, u32, u32);
extern u32 fn_8008F838(u32, u32);
extern u32 lbl_80095E64[];
extern u32 lbl_80095E78[];
extern u32 lbl_801A5E78[];
extern u32 lbl_801A6378[];

s32 gdev_cc_initialize(u32 arg0, u32 arg1) {
    MWTRACE(1, (u32)&lbl_80095E64);
    fn_8008F838(arg0, arg1);
    MWTRACE(1, (u32)&lbl_80095E78);
    fn_8008E324((u32)&lbl_801A6378, (u32)&lbl_801A5E78, 1280);
    return 0;
}
