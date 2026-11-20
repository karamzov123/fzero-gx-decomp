#include "types.h"


/* --- dol/fn_800206FC.c --- */
extern u32 lbl_801A6A20;

u32 fn_800206FC(u32 arg0) {
    u32 v0;
    if ((arg0 & 0x1F) != 0) {
    v0 = (arg0 + (32 - (arg0 & 0x1F)));
    lbl_801A6A20 = v0;
    return arg0;
    }
    lbl_801A6A20 = arg0;
}

/* --- dol/fn_8002071C.c --- */
/* --- dol/fn_8002071C.c --- */

u32 fn_8002071C(void) {
    return lbl_801A6A20;
}

/* --- dol/fn_80020724.c --- */
extern u8 lbl_801A6AB0[8];
extern u8 lbl_801A6AA8[8];
extern u8 lbl_801A6AA0[8];
extern u8 lbl_801A6A98[8];
extern u8 lbl_801A6A90[8];
extern u8 lbl_801A6A88[8];
extern u8 lbl_801A6A80[8];
extern u8 lbl_801A6A78[8];
extern u8 lbl_801A6A70[8];
extern u8 lbl_801A6A68[8];
extern u8 lbl_801A6A60[8];
extern u8 lbl_801A6A58[8];
extern u8 lbl_801A6A50[8];
extern u8 lbl_801A6A48[8];
extern u8 lbl_801A6A40[8];
extern u8 lbl_801A6A38[8];
extern u8 lbl_801A6A30[8];
extern u8 lbl_801A6A28[8];

void fn_80020724(void) {
    lbl_801A6AB0[0] = 0;
    lbl_801A6AB0[0] = 0;
    lbl_801A6AA8[0] = 0;
    lbl_801A6AA0[0] = 0;
    lbl_801A6A98[0] = 0;
    lbl_801A6A90[0] = 0;
    lbl_801A6A88[0] = 0;
    lbl_801A6A80[0] = 0;
    lbl_801A6A78[0] = 0;
    lbl_801A6A70[0] = 0;
    lbl_801A6A68[0] = 0;
    lbl_801A6A60[0] = 0;
    lbl_801A6A58[0] = 0;
    lbl_801A6A50[0] = 0;
    lbl_801A6A48[0] = 0;
    lbl_801A6A40[0] = 0;
    lbl_801A6A38[0] = 0;
    lbl_801A6A30[0] = 0;
    lbl_801A6A28[0] = 0;
}
