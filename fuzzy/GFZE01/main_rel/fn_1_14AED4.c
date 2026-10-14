/* Non-matching: best partial attempt (89.78% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

struct fn_1_14AED4_state {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[10];
    u32 unk_10;
    u8 pad_14[8];
    f32 unk_1C;
    u8 pad_20[4];
    s32 unk_24;
    u8 pad_28[4];
    s32 unk_2C;
    u8 unk_30;
};
extern u32 fn_1_8623C(void);
extern u32 fn_1_14A9D0(u32, u32, u32, u32, u32, u32);
extern u32 fn_1_3F2A0(void);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern void fn_1_A2D84(u32 value);

#pragma opt_propagation on
#pragma opt_dead_assignments off
#pragma opt_lifetimes off
u32 fn_1_14AED4(void) {
    struct fn_1_14AED4_state *p_lbl_1_bss_8E518;
    u32 v0;
    u32 v2;
    f32 *v3;
    s32 *v4;
    u8 v5;
    u8 v7;
    s32 v8;
    f32 *v10;
    s32 *v11;
    u8 v12;
    u8 v14;
    u8 v15;
    u8 v16;
    s32 result;
    s32 tmp_cse1;
    p_lbl_1_bss_8E518 = (struct fn_1_14AED4_state *)&lbl_1_bss_8E518;
    if (p_lbl_1_bss_8E518->unk_5 == 4)
        v0 = lbl_1_bss_3C30.unk_8;
    else
        v0 = lbl_1_bss_3C30.unk_9;
    fn_1_14A9D0(v0, 1, 30, 180, 1, 0);
    if (((lbl_1_bss_9F8.unk_8 >> 8) & 1) && !((lbl_1_bss_D58.unk_8 >> 12) & 1)) {
        if ((lbl_801A66A4 - p_lbl_1_bss_8E518->unk_10) >= 195) {
            p_lbl_1_bss_8E518->unk_5 = 2;
            p_lbl_1_bss_8E518->unk_4 = 0;
            if (*(s16 *)&lbl_1_bss_960 == 1)
                p_lbl_1_bss_8E518->unk_30 = 4;
            else {
                v2 = lbl_1_bss_3C30.unk_9;
                (void) v2;  /* fzgx: keeps the web at its definition */
                p_lbl_1_bss_8E518->unk_30 = v2 < 6 ? v2 : 6;
            }
            if (p_lbl_1_bss_8E518->unk_2C != 0) {
                v3 = (f32 *)((u32)p_lbl_1_bss_8E518 + 28);
                v4 = (s32 *)((u32)p_lbl_1_bss_8E518 + 28);
                fn_1_3F2A0();
                v2 = fn_1_8623C();
                v5 = p_lbl_1_bss_8E518->unk_30;
                tmp_cse1 = v2 * 160;
                v7 = *(u8 *)(((tmp_cse1) + ((u8 *)&lbl_1_bss_3C30)) + 220);
                p_lbl_1_bss_8E518->unk_24 = v7;
                result = v7 - ((v5 >> 1) - 1);
                p_lbl_1_bss_8E518->unk_24 = result;
                if (result < 0) {
                    *v4 = 0;
                } else {
                    v8 = lbl_1_bss_3C30.unk_9 - v5;
                    if (result >= v8)
                        *v4 = v8;
                }
                *v3 = (f32)*v4;
            } else {
                v10 = &p_lbl_1_bss_8E518->unk_1C;
                v11 = &p_lbl_1_bss_8E518->unk_24;
                fn_1_3F2A0();
                v2 = fn_1_8623C();
                v12 = p_lbl_1_bss_8E518->unk_30;
                v14 = *(u8 *)(((tmp_cse1) + ((u8 *)&lbl_1_bss_3C30)) + 220);
                p_lbl_1_bss_8E518->unk_24 = v14;
                v0 = v14 - ((v12 >> 1) - 1);
                result = v0;
                p_lbl_1_bss_8E518->unk_24 = result;
                if (result < 0) {
                    *v11 = 0;
                } else {
                    v15 = p_lbl_1_bss_8E518->unk_5;
                    if (*v11 >= (s32)(u8)(v15 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v12)
                        *v11 = (s32)(u8)(v15 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v12;
                }
                if (p_lbl_1_bss_8E518->unk_5 == 4)
                    v16 = lbl_1_bss_3C30.unk_8;
                else
                    v16 = lbl_1_bss_3C30.unk_9;
                *v10 = (f32)(u32)v16 - (f32)(u32)p_lbl_1_bss_8E518->unk_30;
            }
            fn_1_A2D84(0xA9010400);
        } else {
            fn_1_14CA4C();
        }
    } else if ((lbl_1_bss_9F8.unk_8 >> 9) & 1) {
        p_lbl_1_bss_8E518->unk_5 = 0;
        fn_1_A2D84(0xA9010400);
    }

    return (u32)v11;
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

