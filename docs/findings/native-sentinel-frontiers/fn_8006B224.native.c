#include "types.h"

struct Fn8006B3F0Data;
extern s32 fn_8006B3F0(struct Fn8006B3F0Data *);
extern void fn_800139E8(u32, u32, s32);
extern s32 lbl_801A6C88;
extern u8 lbl_80199670[18720];

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
#pragma opt_propagation off
void fn_8006B224(void) {
    s32 entry_offset;
    u8 *base;
    s32 index;
    if (lbl_801A6C88 != 0) {
        base = lbl_80199670;
        index = 0;
        entry_offset = 0;
        do {
            fn_8006B3F0((struct Fn8006B3F0Data *)(base + entry_offset));
            fn_800139E8(index, 0x400, 0);
            index++;
            entry_offset += 0x1248;
        } while (index < 4);
        lbl_801A6C88 = 0;
    }
}
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
#pragma opt_strength_reduction reset
