/* Non-matching: best partial attempt (91.40% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/screen_effect.h"

struct fn_1_76DC0_lbl_801A63C0 { u32 unk_0; };
typedef union { struct { u8 r, g, b, a; }; u8 rgba[4]; } EffectColor;
struct fn_1_76DC0_layout {
    u8 pad_0[0x13C];
    EffectColor unk_13C[5];
    EffectColor unk_150;
    f32 unk_154;
    f32 unk_158;
};
extern const f32 lbl_1_rodata_31AC;
extern const f32 lbl_1_rodata_31EC;
extern struct fn_1_76DC0_lbl_801A63C0 lbl_801A63C0;

#pragma opt_propagation off
u32 fn_1_76DC0(u32 arg0) {
    EffectColor * fzgx_live_;
    EffectColor * fzgx_live;
    s32 v0;
    u32 v3;
    struct { unsigned int v2; unsigned int v4; } fzgx_copy_state;
    struct fn_1_76DC0_layout *p = (struct fn_1_76DC0_layout *)&lbl_1_data_1D960;
    s32 v0_2;
    v0 = arg0;
    if ((s32)arg0 == 17) {
        fzgx_copy_state.v2 = lbl_801A63C0.unk_0 * 0x676A4B6B + 13259;
        v3 = (fzgx_copy_state.v2 >> 16) & 0x7FFF;
        lbl_801A63C0.unk_0 = fzgx_copy_state.v2;
        v0_2 = 23;
        fzgx_live_ = p->unk_13C;
        fzgx_live = fzgx_live_;
        p->unk_150 = (*((fzgx_live) + (v3 % 5)));
    } else {
        if ((s32)v0_2 >= 18 && (s32)v0_2 < 23) {
            fzgx_copy_state.v2 = v0_2 - 18;
            fzgx_copy_state.v4 = fzgx_copy_state.v2;
            v0_2 = 23;
            fzgx_live_ = p->unk_13C;
            p->unk_150 = (*((fzgx_live_) + (fzgx_copy_state.v4 % 5)));
        }
    }
    if (v0_2 == 23) {
        p->unk_154 = lbl_1_rodata_31AC;
        p->unk_158 = lbl_1_rodata_31AC;
    }
    if (v0_2 != 24) { return (u32)fzgx_live_; }
    p->unk_150.r = 48;
    p->unk_154 = lbl_1_rodata_31EC;
    p->unk_158 = lbl_1_rodata_31EC;
    p->unk_150.g = 48;
    p->unk_150.b = 40;
    p->unk_150.a = 32;
    return (u32)fzgx_live_;
}
#pragma opt_propagation reset

