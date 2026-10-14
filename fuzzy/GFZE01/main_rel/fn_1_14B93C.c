/* Non-matching: best partial attempt (87.05% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

struct fn_1_14B93C_state {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[10];
    u32 unk_10;
    u8 pad_14[4];
    f32 unk_18;
    u8 pad_1C[4];
    s32 unk_20;
    u8 pad_24[4];
    s32 unk_28;
    u8 pad_2C[4];
    u8 unk_30;
};
extern u32 fn_1_3F2A0(void);
extern u32 fn_1_14A9D0(u32,u32,u32,u32,u32,u32);
extern void fn_1_A2D84(u32);
extern void fn_1_14CA4C(void);
extern int fn_1_8623C(void);
extern u32 lbl_801A66A4;

#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
u32 fn_1_14B93C(void) {
    struct fn_1_14B93C_state *p = (struct fn_1_14B93C_state *)&lbl_1_bss_8E518;
    u32 v0;
    f32 *v3;
    s32 *v4;
    u8 v5;
    s32 v6;
    s32 v7;
    s32 *v12;
    s32 v9;
    f32 *v11;
    u8 v8;
    u8 v13;
    s32 v14;
    u8 v15;
    u16 v16;
    u8 v17;
    u8 fzgx_frame_pad[16];  /* fzgx: retail frame home */
    fn_1_3F2A0();
    if ((s32)lbl_1_bss_25BA0.unk_0 == 0) {
        if (p->unk_5 == 4) v0 = lbl_1_bss_3C30.unk_8;
        else v0 = lbl_1_bss_3C30.unk_9;
        fn_1_14A9D0(v0,1,30,180,0,1);
        if (((lbl_1_bss_9F8.unk_8 >> 8) & 1) && !((lbl_1_bss_D58.unk_8 >> 12) & 1)) {
            if (lbl_801A66A4 - p->unk_10 >= 195) {
                p->unk_5 = 8;
                fn_1_A2D84(0xA9010400);
            } else fn_1_14CA4C();
        } else if ((lbl_1_bss_9F8.unk_8 >> 9) & 1) {
            p->unk_5 = 3;
            p->unk_4 = 0;
            if (*(s16 *)&lbl_1_bss_960 == 1) p->unk_30 = 4;
            else {
                v0 = lbl_1_bss_3C30.unk_9 < 6 ? lbl_1_bss_3C30.unk_9 : 6;
                p->unk_30 = v0;
            }
            if (p->unk_28 != 0) {
                v3 = (f32 *)((u8 *)(u32)p + 24);
                v4 = (s32 *)((u8 *)(u32)p + 32);
                v6 = fn_1_8623C() * 160;
                v5 = p->unk_30;
                v7 = ((u32)v5 >> 1) - 1;
                v8 = *((u8 *)&lbl_1_bss_3C30 + v6 + lbl_1_bss_3C30.unk_A7 + 226);
                v9 = v8 - v7;
                p->unk_20 = v8;
                p->unk_20 = v9;
                if (v9 < 0) *v4 = 0;
                else {
                    s32 limit = lbl_1_bss_3C30.unk_9 - v5;
                    if (v9 >= limit) *v4 = limit;
                }
                *v3 = (f32)*v4;
            } else {
                v11 = (f32 *)((u8 *)(u32)p + 24);
                v12 = (s32 *)((u8 *)(u32)p + 32);
                v14 = fn_1_8623C() * 160;
                v13 = p->unk_30;
                v15 = ((u32)v13 >> 1) - 1;
                v0 = *((u8 *)&lbl_1_bss_3C30 + v14 + lbl_1_bss_3C30.unk_A7 + 226);
                p->unk_20 = v0;
                p->unk_20 = v0 - v15;
                if ((s32)(v0 - v15) < 0) *v12 = 0;
                else {
                    v16 = p->unk_5;
                    if (*v12 >= (s32)((u8)(v16 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v13))
                        *v12 = (u8)(v16 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v13;
                }
                if (p->unk_5 == 4) v17 = lbl_1_bss_3C30.unk_8;
                else v17 = lbl_1_bss_3C30.unk_9;
                *v11 = (f32)(u32)v17 - (f32)(u32)p->unk_30;
            }
            fn_1_A2D84(0xA9010400);
        }
    }
    return (u32)v12;
}
#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset

