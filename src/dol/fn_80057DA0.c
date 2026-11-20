#include "types.h"


/* --- dol/fn_80057DA0.c --- */
struct fn_80057DA0_Arg0 {
    u8 pad_0[0x24];
    u32 unk_24;
};

u32 fn_80057DA0(struct fn_80057DA0_Arg0 *arg0) {
    return arg0->unk_24;
}

/* --- dol/fn_80057DA8.c --- */
struct fn_80057DA8_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};

u32 fn_80057DA8(struct fn_80057DA8_Arg0 *arg0) {
    return arg0->unk_20;
}

/* --- dol/fn_80057DB0.c --- */
struct fn_80057DB0_Arg0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};

u32 fn_80057DB0(struct fn_80057DB0_Arg0 *arg0) {
    return arg0->unk_1C;
}
