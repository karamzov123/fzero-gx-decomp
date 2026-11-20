#include "types.h"


/* --- dol/fn_8004E190.c --- */
struct Fn8004E190 {
    u8 pad_0[0x10];
    u32 field_10;
};

u32 fn_8004E190(struct Fn8004E190 *arg) {
    return arg->field_10;
}

/* --- dol/fn_8004E198.c --- */
struct fn_8004E198_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

void fn_8004E198(struct fn_8004E198_Arg0 *arg0) {
    if ((s32)arg0->unk_C != 3) { return; }
    arg0->unk_C = 0;
}
