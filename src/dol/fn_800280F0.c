#include "types.h"

extern u32 fn_800285DC(u32);
extern u32 lbl_801A6B90;

void fn_800280F0(void) {
    u32 v0;
    v0 = lbl_801A6B90;
    while (v0 != 0) {
    fn_800285DC(v0);
    v0 = *(u32 *)(v0);
    }
}
