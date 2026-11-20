#include "types.h"


/* --- dol/fn_8005A668.c --- */
struct fn_8005A668_Arg0 {
    u8 pad_0[0xA0];
    u16 unk_A0;
};

void fn_8005A668(struct fn_8005A668_Arg0 *arg0, u32 arg1) {
    if (arg0 == 0) { return; }
    arg0->unk_A0 = arg1;
}

/* --- dol/fn_8005A678.c --- */
// fn_8005A678: returns a constant.
int fn_8005A678(void) {
    return 0;
}

/* --- dol/fn_8005A680.c --- */
// fn_8005A680: returns a constant.
int fn_8005A680(void) {
    return 0;
}

/* --- dol/fn_8005A688.c --- */
struct fn_8005A688_Arg0 {
    u8 pad_0[0x80];
    u32 unk_80;
};

void fn_8005A688(struct fn_8005A688_Arg0 *arg0, u32 arg1) {
    if (arg0 == 0) { return; }
    arg0->unk_80 = arg1;
}
