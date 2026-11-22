#include "types.h"

extern u32 lbl_8017B5A0[3];

void fn_80047834(void) {
    lbl_8017B5A0[0]--;
}

u32 fn_8004784C(void) {
    u32 v0;
    v0 = lbl_8017B5A0[0];
    lbl_8017B5A0[0] = v0 + 1;
    return v0;
}
