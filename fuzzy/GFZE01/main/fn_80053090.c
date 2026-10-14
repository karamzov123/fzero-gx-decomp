/* Non-matching: best partial attempt (94.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
struct fn_80053090_Arg0 {
 f32 unk_0; u8 pad_4[0x17C]; f32 unk_180; u8 pad_184[0x7C];
 f32 unk_200; u8 pad_204[0x17C]; f32 unk_380; u8 pad_384[0x7C];
 f32 unk_400; u8 pad_404[0x17C]; f32 unk_580; u8 pad_584[0x7C];
 f32 unk_600; u8 pad_604[0x17C]; f32 unk_780; u8 pad_784[0x7C];
 f32 unk_800; u8 pad_804[0x17C]; f32 unk_980;
};
struct fn_80053090_Arg1 {
 f32 unk_0;
 f32 unk_4;
 f32 unk_8;
 f32 unk_C;
 f32 unk_10;
 f32 unk_18;
 f32 unk_14;
 f32 unk_1C;
 f32 unk_20;
 f32 unk_24;
 f32 unk_28;
 f32 unk_2C;
 f32 unk_30;
 f32 unk_34;
 f32 unk_38;
 f32 unk_3C;
};
struct fn_80053090_Arg2 { u16 unk_0; };
extern f32 lbl_80091338[6];
#pragma opt_loop_invariants off
static inline f32 fn_80053090_read_pointer(struct fn_80053090_Arg1 * owner) { return owner->unk_C; }
#pragma opt_dead_assignments on
static inline f32 fn_80053090_read_pointer_(struct fn_80053090_Arg1 * owner) { return owner->unk_18; }
static inline f32 fn_80053090_read_pointer__(struct fn_80053090_Arg1 * owner) { return owner->unk_30; }
static inline f32 fn_80053090_read_pointer___(struct fn_80053090_Arg1 * owner) { return owner->unk_3C; }
#pragma opt_lifetimes on
#pragma opt_propagation off
static inline f32 fn_80053090_read_pointer____(struct fn_80053090_Arg1 * owner) { return owner->unk_38; }
#pragma opt_propagation reset

#pragma opt_common_subs on
static inline f32 fn_80053090_read_pointer_____(struct fn_80053090_Arg1 * owner) { return owner->unk_8; }
static inline f32 fn_80053090_read_pointer_______read_pointer(struct fn_80053090_Arg0 * owner) { return owner->unk_200; }
static inline f32 fn_80053090_read_pointer______(struct fn_80053090_Arg0 * owner) { return fn_80053090_read_pointer_______read_pointer(owner); }
#pragma opt_strength_reduction off
void fn_80053090(struct fn_80053090_Arg0 *arg0, struct fn_80053090_Arg1 *arg1, struct fn_80053090_Arg2 *arg2) {
    f32 fzgx_live___;
    f32 fzgx_live__;
    f32 fzgx_live_;
    f32 fzgx_live;
 s32 count;
 f32 sum;
 f32 upper;
 count = 32;
 upper = (2.14748365e+09f);
 do {
 sum = 0.0f;
 sum += arg1->unk_0 * arg0->unk_0;
 sum += arg1->unk_4 * arg0->unk_180;
 fzgx_live___ = arg0->unk_200;
 sum += arg1->unk_8 * fzgx_live___;
 fzgx_live = arg1->unk_C;
 sum += fzgx_live * arg0->unk_380;
 sum += arg1->unk_10 * arg0->unk_400;
 sum += arg1->unk_18 * arg0->unk_580;
 fzgx_live__ = arg1->unk_14;
 fzgx_live_ = fzgx_live__;
 sum += fzgx_live_ * arg0->unk_600;
 sum += arg1->unk_1C * arg0->unk_780;
 sum += arg1->unk_20 * arg0->unk_800;
 sum += arg1->unk_24 * arg0->unk_980;
 sum += arg1->unk_28 * *(f32 *)((u8 *)arg0 - 0x600);
 sum += arg1->unk_2C * *(f32 *)((u8 *)arg0 - 0x480);
 sum += arg1->unk_30 * *(f32 *)((u8 *)arg0 - 0x400);
 sum += arg1->unk_34 * *(f32 *)((u8 *)arg0 - 0x280);
 sum += arg1->unk_38 * *(f32 *)((u8 *)arg0 - 0x200);
 sum += arg1->unk_3C * *(f32 *)((u8 *)arg0 - 0x80);
 arg0 = (struct fn_80053090_Arg0 *)((u8 *)arg0 + 4);
 arg1++;
 if (sum > upper) sum = upper;
 else if (sum < (-2.14748365e+09f)) sum = (-2.14748365e+09f);
 arg2->unk_0 = (s32)(f32)((s32)sum >> 16);
 arg2++;
 } while (--count);
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset

