#include "types.h"

struct Fn8004E8A0 {
    u8 pad_0[0x18];
    s32 count_18;
    u8 pad_1[0xC90 - 0x1C];
    s32 field_C90;
    s32 field_C94;
};

extern struct Fn8004E8A0 lbl_8017E980;
extern void VIWaitForRetrace(void);
extern void fn_80058DB4(void);

void fn_8004E8A0(void) {
    struct Fn8004E8A0* state = &lbl_8017E980;

    while (state->field_C94 == 1) {
        VIWaitForRetrace();
        state->count_18 += 1;
        fn_80058DB4();
    }
    state->field_C90 = 1;
}
