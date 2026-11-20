#include "types.h"


/* --- dol/fn_80058434.c --- */
struct fn_80058434_Arg0 {
    u8 pad_0[0x38];
    u32 unk_38;
    u32 unk_3C;
};

void fn_80058434(struct fn_80058434_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_38 = arg1;
    arg0->unk_3C = arg2;
}

/* --- dol/fn_80058440.c --- */
struct fn_80058440_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

u32 fn_80058440(struct fn_80058440_Arg0 *arg0) {
    return arg0->unk_8;
}
