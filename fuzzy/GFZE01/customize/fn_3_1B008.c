/* Non-matching: best partial attempt (98.65% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/toolkit.h"

extern u32 fn_3_149AC(void *, s32, s32);
extern void fn_3_14794(void *,s16, s32, u32 *);

#pragma opt_common_subs off
#pragma opt_loop_invariants off
void fn_3_1B008(void *obj, s32 x1, u32 y1, s32 x2, s32 y2, u32 lab_unused0) {
    s32 row;
    s16 right = (s16)x2;
    s16 lab_t1;
    s32 delta;
    u32 * table;
    s32 bottom;
    u32 value;
    u32 src;
    s32 i;
    s16 cols;
    s16 rows;
    s16 j;
    s32 last = right - 1;
    void * lab_t0;
    table = &lbl_3_bss_A2454;
    bottom = (s16)y2;

    {
    s32 fzgx_loop_row_464;
for (fzgx_loop_row_464 = y1; (s16)fzgx_loop_row_464 < bottom; fzgx_loop_row_464++) {
        delta = last - (s16)fzgx_loop_row_464;
{
    s32 col;
        for (col = x1; (s16)col < right; col++) {
            value = fn_3_149AC(obj, col, fzgx_loop_row_464);
            lab_t1 = delta;
            lab_t0 = (void *)*table;
            fn_3_14794(lab_t0, lab_t1, col, &value);
}
        }
    }
    row = fzgx_loop_row_464;
}

    src = lbl_3_bss_A2454;
    rows = (s16)(y2 - y1);
    cols = (s16)(right - x1);

    if (obj) {
        for (i = 0; (s16)i < rows; i++) {
            for (j = 0; (s16)j < cols; j++) {
                u32 v = fn_3_149AC((void *)src, j, i);
                lab_t0 = obj;
                fn_3_14794(lab_t0, j, i, &v);
            }
        }
    }
}
#pragma opt_loop_invariants reset

#pragma opt_common_subs reset
