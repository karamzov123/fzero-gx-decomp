/* Non-matching: best partial attempt (98.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieTables {
    f64 values[64];
    f64 rows[64];
    u32 result;
} MovieTables;

extern f64 lbl_12_bss_798[129];
extern u32 fn_12_4E14(void);
extern f64 fn_80087E80(f64);
extern const f64 lbl_12_rodata_598;
extern const f64 lbl_12_rodata_5A0;
extern const f64 lbl_12_rodata_5A8;
extern const f64 lbl_12_rodata_5B0;

#pragma opt_loop_invariants off
#pragma opt_propagation off
void fn_12_4D14(void) {
    u32 *fzgx_value;
    f64 * fzgx_live;
    MovieTables *tbl = (MovieTables *)lbl_12_bss_798;
    f64 *p;
    f64 *q;
    f64 *table;
    f64 *table2;
    int i;
    int j;
    f64 scale;
    f64 factor;
    f64 value;

    fzgx_value = &(tbl->result);
    *fzgx_value = fn_12_4E14();
    fzgx_live = tbl->values;
    table = fzgx_live;
    table2 = tbl->rows;
    for (i = 0; i < 8; i++) {
        if (i == 0) {
            scale = lbl_12_rodata_5A8;
        } else {
            scale = lbl_12_rodata_598;
        }
        p = table;
        factor = lbl_12_rodata_5B0 * (f64)i;
        q = table2;
        for (j = 0; j < 8; j++) {
            value = fn_80087E80(factor * (lbl_12_rodata_598 + (f64)j));
            value = scale * value;
            *p = value;
            *q = value;
            p = p + 1;
            q += 8;
        }
        table += 8;
        table2++;
    }
}
#pragma opt_propagation reset

#pragma opt_loop_invariants reset

