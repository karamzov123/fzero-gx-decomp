#include "types.h"


/* --- dol/ddh_cc_close.c --- */
// ddh_cc_close: returns a constant.
int ddh_cc_close(void) {
    return 0;
}

/* --- dol/ddh_cc_open.c --- */
extern u32 lbl_801A6E08;

s32 ddh_cc_open(u32 arg0) {
    u32 v0;
    v0 = arg0;
    if ((s32)lbl_801A6E08 != 0) {
    v0 = -10005;
    return v0;
    }
    v0 = 0;
    lbl_801A6E08 = 1;
    return v0;
}

/* --- dol/ddh_cc_shutdown.c --- */
// ddh_cc_shutdown: returns a constant.
int ddh_cc_shutdown(void) {
    return 0;
}

/* --- dol/ddh_cc_initialize.c --- */
/* --- dol/ddh_cc_initialize.c --- */
extern u32 MWTRACE(u32, ...);
extern u32 fn_8008E324(u32, u32, u32);
extern u32 fn_8008EDF0(u32, u32);
extern u32 lbl_80095D84[];
extern u32 lbl_80095D98[];
extern u32 lbl_801A5658[];
extern u32 lbl_801A5E58[];

s32 ddh_cc_initialize(u32 arg0, u32 arg1) {
    MWTRACE(1, (u32)&lbl_80095D84);
    fn_8008EDF0(arg0, arg1);
    MWTRACE(1, (u32)&lbl_80095D98);
    fn_8008E324((u32)&lbl_801A5E58, (u32)&lbl_801A5658, 2048);
    return 0;
}

/* --- dol/fn_8008E114.c --- */
extern u32 memcpy(u32, u32, u32);
extern void fn_8008E73C(void *);
extern void fn_8008E718(void *);

struct fn_8008E114_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

s32 fn_8008E114(struct fn_8008E114_Arg0 *arg0, u32 arg1, u32 arg2) {
    u32 v2;

    if (arg2 > arg0->unk_10) {
        return -1;
    }
    fn_8008E73C(&arg0->unk_18);
    v2 = arg0->unk_c - (arg0->unk_0 - arg0->unk_8);
    if (arg2 < v2) {
        memcpy(arg1, arg0->unk_0, arg2);
        arg0->unk_0 += arg2;
    } else {
        memcpy(arg1, arg0->unk_0, v2);
        memcpy(arg1 + v2, arg0->unk_8, arg2 - v2);
        arg0->unk_0 = arg0->unk_8 + arg2 - v2;
    }
    if (arg0->unk_c == arg0->unk_0 - arg0->unk_8) {
        arg0->unk_0 = arg0->unk_8;
    }
    arg0->unk_14 += arg2;
    arg0->unk_10 -= arg2;
    fn_8008E718(&arg0->unk_18);
    return 0;
}
