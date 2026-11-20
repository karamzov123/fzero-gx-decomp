#include "types.h"


/* --- dol/fn_8004E1B0.c --- */
extern u32 memset(u32, u32, u32);

struct fn_8004E1B0_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

void fn_8004E1B0(struct fn_8004E1B0_Arg0 *arg0) {
    arg0->unk_C = 0;
    memset(((u32)arg0 + 40), 0, 8);
}

/* --- dol/fn_8004E1E4.c --- */
struct fn_8004E1E4_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
};

void fn_8004E1E4(struct fn_8004E1E4_Arg0 *arg0) {
    if ((s32)arg0->unk_C != 0) { return; }
    arg0->unk_10 = 0;
    arg0->unk_C = 1;
}
