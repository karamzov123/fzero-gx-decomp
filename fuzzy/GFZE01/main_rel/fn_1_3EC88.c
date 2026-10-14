/* Non-matching: best partial attempt (92.14% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/game.h"
extern u8 lbl_1_bss_5480[0x20700];
extern void fn_80008BA8(void *, const void *, u32);

static inline u8 fn_1_3EC88_array_read(s32 index, u8 *array) { return array[index]; }
#pragma opt_propagation off
void *fn_1_3EC88(u32 arg0, u8 *arg1) {
    u8 *p_lbl_1_bss_3C00;
    u8 *p_arg1;
    u8 *v3;
    u8 *v1;
    u32 *v4;
    u8 *v5;
    u8 *p_lbl_1_bss_5480;
    u32 *v2;
    s32 v6;
    s32 v7;
    s32 v15;
    u8 v16;
    u8 *p_tail;
    p_lbl_1_bss_3C00 = &lbl_1_bss_3C00;
    (void) p_lbl_1_bss_3C00;  /* fzgx: keeps the web at its definition */
    p_arg1 = arg1;
    p_lbl_1_bss_5480 = lbl_1_bss_5480;
    v1 = p_lbl_1_bss_3C00 + 0x163c;
    v2 = (u32 *)(p_lbl_1_bss_3C00 + 0x17f8);
{
#define fzgx_loop_v4_781 v4
    u32 v0 = (u32)p_lbl_1_bss_3C00 + 0x20000;
    v3 = (u8 *)(v0 + 0x265c);
    fzgx_loop_v4_781 = (u32 *)(v0 + 0x267c);
    v5 = (u8 *)(v0 + 0x2298);
    v6 = arg0 & 0xff;
    v15 = 0;
    v7 = 0;
    while ((s16)v15 < (s32)v6 && (s16)v7 < 4) {
        v16 = fn_1_3EC88_array_read(1, p_arg1);
        if (v16 != 255) {
            *v3 = v16;
            if (fn_1_3EC88_array_read(2, p_arg1) == 255) {
                *v1 = 1;
            } else {
                *v1 = fn_1_3EC88_array_read(2, p_arg1);
            }
            *v5 = v7;
            *fzgx_loop_v4_781 = 0;
            fn_80008BA8(p_lbl_1_bss_5480 + 4, p_arg1, 12);
            *v2 = (u32)(p_lbl_1_bss_5480 + 4);
            p_lbl_1_bss_5480 += 0x81c0;
            v2 = v2 + 1;
            v15++;
            v3 = v3 + 1;
            v1++;
            fzgx_loop_v4_781++;
            v5++;
        }
        p_arg1 += 12;
        v7++;
    }
    v4 = fzgx_loop_v4_781;
}
    p_tail = p_lbl_1_bss_3C00 + 0x30;
    *p_lbl_1_bss_3C00 = v15;
    p_tail[8] = v15;
    return p_tail;
}
#pragma opt_propagation reset
