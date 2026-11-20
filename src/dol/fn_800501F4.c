#include "types.h"

struct fn_800501F4_Arg0 {
    u8 pad_0[0x8];
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
};

extern u32 lbl_80186FA8[4];
extern void fn_800502A0(struct fn_800501F4_Arg0 *arg0, u32 arg1);
extern u32 lbl_801309C0[];

#pragma opt_propagation off
s32 fn_800501F4(struct fn_800501F4_Arg0 *arg0, s32 arg1) {
    u32 counter;
    s32 result;
    s32 shift;
    u32 *tbl;

    {
        u32 *counter_p;

        counter_p = lbl_80186FA8;
        counter = *counter_p;
        *counter_p = counter + 1;
    }
    if (arg0->unk_C < arg1) {
        fn_800502A0(arg0, counter);
    }
    if (arg1 > arg0->unk_C) {
        arg0->unk_10 += arg0->unk_C;
        arg0->unk_C = 0;
        return 0;
    }
    tbl = lbl_801309C0;
    shift = arg0->unk_C - arg1;
    result = (arg0->unk_8 >> shift) & tbl[arg1];
    arg0->unk_C = shift;
    arg0->unk_10 += arg1;
    return result;
}
#pragma opt_propagation reset

