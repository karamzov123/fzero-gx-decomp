#include "types.h"


/* --- dol/fn_80006334.c --- */
struct fn_80006334_Arg0 {
    u8 unk_0;
};

u32 fn_80006334(struct fn_80006334_Arg0 *arg0) {
    return ((arg0->unk_0 >> 7) & 0x1);
}

/* --- dol/fn_80006340.c --- */
extern u8 lbl_801A66DB;

void fn_80006340(u32 arg0) {
    if ((s32)arg0 == -1) { return; }
    lbl_801A66DB = 0;
}
