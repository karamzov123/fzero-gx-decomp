#include "types.h"


/* --- dol/fn_800475C0.c --- */
/* --- dol/fn_800475C0.c --- */
struct fn_800475C0_lbl_8017B030 {
    u32 unk_0;
    u32 unk_4;
};

extern struct fn_800475C0_lbl_8017B030 lbl_8017B030[];
extern u32 memset(u32, u32, u32);

void fn_800475C0(void) {
    struct fn_800475C0_lbl_8017B030 *p_lbl_8017B030;
    p_lbl_8017B030 = (struct fn_800475C0_lbl_8017B030 *)&lbl_8017B030;
    memset((u32)((u8 *)(u32)p_lbl_8017B030 + 40), 0, 256);
    p_lbl_8017B030->unk_0 = 0;
    p_lbl_8017B030->unk_4 = 0;
}
