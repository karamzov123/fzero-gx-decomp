#include "types.h"


/* --- dol/fn_80023568.c --- */
extern u32 OSDisableInterrupts(u32, u32);
extern u32 OSRestoreInterrupts(void);

void fn_80023568(u32 arg0, u32 arg1);

/* --- dol/fn_800235D4.c --- */
extern u32 lbl_801A6B70;
extern u32 lbl_801A6B74;
extern u32 lbl_801A6B78;
extern u32 lbl_801A6B7C;

u32 fn_800235D4(void) {
    u32 result;

    if (lbl_801A6B7C != 0) {
        result = lbl_801A6B70 + lbl_801A6B78++ * 56;
        lbl_801A6B78 %= lbl_801A6B74;
        return result;
    }
    return 0;
}

/* --- dol/fn_8002361C.c --- */
void fn_8002361C(u32 value0, u32 value1) {
    lbl_801A6B70 = value0;
    lbl_801A6B74 = value1;
    lbl_801A6B78 = 0;
    lbl_801A6B7C = 1;
}
