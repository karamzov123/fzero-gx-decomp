#include "types.h"


/* --- dol/fn_8004784C.c --- */
extern struct fn_8004784C_lbl_8017B5A0 lbl_8017B5A0;

struct fn_8004784C_lbl_8017B5A0 {
    u32 unk_0;
};

u32 fn_8004784C(void) {
    u32 v0;
    v0 = lbl_8017B5A0.unk_0;
    lbl_8017B5A0.unk_0 = (v0 + 1);
    return v0;
}
