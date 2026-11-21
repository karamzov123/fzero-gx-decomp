#include "types.h"
#pragma opt_propagation off

/* --- dol/fn_8005A588.c --- */
extern u32 lbl_80190178[];
extern u32 lbl_8019017C[];

void fn_8005A588(u32 arg0, u32 arg1) {
    lbl_80190178[0] = arg0;
    lbl_8019017C[0] = arg1;
}

/* --- dol/fn_8005A59C.c --- */
void fn_8005A59C(void) {
    int i;
    for (i = 0; i < 40; i++) {
    }
}

/* --- dol/fn_8005A5A8.c --- */
/* --- dol/fn_8005A5A8.c --- */
// The retail code performs this read even though its value is discarded.
extern volatile u32 lbl_80092528[36];
extern u8 lbl_801324F0[104];

u8 *fn_8005A5A8(void) {
    lbl_80092528[0];
    return lbl_801324F0;
}
