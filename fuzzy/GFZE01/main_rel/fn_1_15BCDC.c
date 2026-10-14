/* Non-matching: best partial attempt (87.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u16 lbl_1_bss_8F980[16];
extern u16 lbl_1_bss_8F9A0[480];

#pragma opt_common_subs on
#pragma opt_dead_assignments on
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
static inline u16 fn_1_15BCDC_array_read(s32 index, u16 *array) { return array[index]; }
s32 fn_1_15BCDC(u32 *arg0) {
    s32 i;
    s32 j;
    s32 count;
    u16 *row;
    u16 cur;
    u16 sel;
    s32 end;
    u32 *p;

{
    u16 fzgx_loop_sel_373;
    u16 fzgx_loop_cur_373;
    fzgx_loop_sel_373 = 0;
    p = arg0;
    fzgx_loop_cur_373 = 0;
    count = 0;
    while (*p != 0xFFFFFFFF) {
        u32 v = *p;
        if (fzgx_loop_sel_373 == 0) {
            fzgx_loop_sel_373 = (u16)(v & 0xf);
        }
        if ((v >> 24) == 2) {
            fzgx_loop_cur_373 = (u16)((u16)fzgx_loop_cur_373 | (u16)(v >> 16));
        }
        p++;
        count++;
    }
    sel = fzgx_loop_sel_373;
    cur = fzgx_loop_cur_373;
}
    if (count == 0) {
        return 0;
    }
    row = &lbl_1_bss_8F9A0[(sel - 1) * 32];
    end = fn_1_15BCDC_array_read(sel, lbl_1_bss_8F980);
    end = end + 0x20;
    j = 0;
    for (i = 0; i < count; i++) {
        u32 v2 = arg0[(u16)(count - i - 1)];
        u16 val = fn_1_15BCDC_array_read((u16)((end - j) % 32), row);
        if ((v2 >> 24) == 2) {
            continue;
        }
        if (cur != 0 && val == cur) {
            j++;
            val = fn_1_15BCDC_array_read((u16)((end - j) % 32), row);
        }
        if (val != ((((u16)(v2 >> 16)) | (cur)))) {
            return 0;
        }
        j++;
    }
    return 1;
}
#pragma opt_lifetimes reset

#pragma opt_strength_reduction reset
#pragma opt_dead_assignments reset
#pragma opt_common_subs reset
