#include "types.h"


/* --- dol/fn_80053EA0.c --- */
struct fn_80053EA0_Arg0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};

u32 fn_80053EA0(struct fn_80053EA0_Arg0 *arg0) {
    return arg0->unk_1C;
}

/* --- dol/fn_80053EA8.c --- */
struct fn_80053EA8_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};

u32 fn_80053EA8(struct fn_80053EA8_Arg0 *arg0) {
    return arg0->unk_20;
}
