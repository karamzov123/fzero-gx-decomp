/* Non-matching: best partial attempt (83.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80052DD0_Arg0 {
    f32 unk_0;
    u8 pad_4[0x17C];
    f32 unk_180;
    u8 pad_184[0x7C];
    f32 unk_200;
    u8 pad_204[0x17C];
    f32 unk_380;
    u8 pad_384[0x7C];
    f32 unk_400;
    u8 pad_404[0x17C];
    f32 unk_580;
    u8 pad_584[0x7C];
    f32 unk_600;
    u8 pad_604[0x17C];
    f32 unk_780;
    u8 pad_784[0x7C];
    f32 unk_800;
    u8 pad_804[0x7C];
    f32 unk_880;
    u8 pad_884[0x7C];
    f32 unk_980;
    u8 pad_984[0x7C];
    f32 unk_A00;
    u8 pad_A04[0x7C];
    f32 unk_A80;
    u8 pad_A84[0x7C];
    f32 unk_B00;
    u8 pad_B04[0x7C];
    f32 unk_B80;
    u8 pad_B84[0x7C];
    f32 unk_C00;
};

struct fn_80052DD0_Arg1 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_3C;
    f32 unk_38;
};

struct fn_80052DD0_Arg2 {
    u16 unk_0;
};

struct fn_80052DD0_Pool {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[4];
    f32 unk_10;
};

extern struct fn_80052DD0_Pool lbl_80091338;

#pragma opt_dead_assignments off
static inline f32 fn_80052DD0_read_pointer(struct fn_80052DD0_Arg1 * owner) { return owner->unk_0; }
#pragma opt_lifetimes on
static inline f32 fn_80052DD0_read_pointer_(struct fn_80052DD0_Arg1 * owner) { return owner->unk_18; }
static inline f32 fn_80052DD0_read_pointer__(struct fn_80052DD0_Arg0 * owner) { return owner->unk_0; }
#pragma opt_strength_reduction off
static inline f32 fn_80052DD0_read_pointer___(struct fn_80052DD0_Arg1 * owner) { return owner->unk_30; }
static inline f32 fn_80052DD0_read_pointer____(struct fn_80052DD0_Arg1 * owner) { return owner->unk_2C; }
static inline f32 fn_80052DD0_read_pointer_____(struct fn_80052DD0_Arg0 * owner) { return owner->unk_A80; }
static inline f32 fn_80052DD0_read_pointer______(struct fn_80052DD0_Arg0 * owner) { return owner->unk_B80; }
void fn_80052DD0(struct fn_80052DD0_Arg0 *arg0, struct fn_80052DD0_Arg1 *arg1,
                 struct fn_80052DD0_Arg2 *arg2) {
    f32 fzgx_live;
    s32 count;
    struct { f32 value; } sum;
    f64 d;

    for (count = 0x20; count != 0; count--) {
        sum.value = lbl_80091338.unk_0 + fn_80052DD0_read_pointer(arg1) * fn_80052DD0_read_pointer__(arg0)
              + arg1->unk_4 * arg0->unk_180 + arg1->unk_8 * arg0->unk_200
              + arg1->unk_C * arg0->unk_380 + arg1->unk_10 * arg0->unk_400
              + arg1->unk_14 * arg0->unk_580 + fn_80052DD0_read_pointer_(arg1) * arg0->unk_600
              + arg1->unk_1C * arg0->unk_780 + arg1->unk_20 * arg0->unk_800
              + arg1->unk_24 * arg0->unk_880 + arg1->unk_28 * arg0->unk_980
              + fn_80052DD0_read_pointer____(arg1) * arg0->unk_A00 + fn_80052DD0_read_pointer___(arg1) * fn_80052DD0_read_pointer_____(arg0)
              + arg1->unk_34 * arg0->unk_B00 + arg1->unk_38 * fn_80052DD0_read_pointer______(arg0)
              + arg1->unk_3C * arg0->unk_C00;
        if (sum.value > lbl_80091338.unk_4) {
            sum.value = lbl_80091338.unk_4;
        } else if (sum.value < lbl_80091338.unk_8) {
            sum.value = lbl_80091338.unk_8;
        }
        d = (f32)(s32)sum.value;
        fzgx_live = lbl_80091338.unk_10;
        d = d - fzgx_live;
        arg2->unk_0 = (s16)(s32)d;
        arg0 = (struct fn_80052DD0_Arg0 *)((u8 *)arg0 + 4);
        arg1 = (struct fn_80052DD0_Arg1 *)((u8 *)arg1 + 0x40);
        arg2 = (struct fn_80052DD0_Arg2 *)((u8 *)arg2 + 2);
    }
}
#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

