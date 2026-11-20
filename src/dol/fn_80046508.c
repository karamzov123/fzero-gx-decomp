#include "types.h"


/* --- dol/fn_80046508.c --- */
struct fn_80046508_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};

void fn_80046508(struct fn_80046508_Arg0 *arg0, u32 arg1) {
    arg0->unk_20 = arg1;
}

/* --- dol/fn_80046510.c --- */
struct fn_80046510_Arg0 {
    u8 pad_0[0x1];
    u8 unk_1;
};

void fn_80046510(struct fn_80046510_Arg0 *arg0) {
    arg0->unk_1 = 0;
}
