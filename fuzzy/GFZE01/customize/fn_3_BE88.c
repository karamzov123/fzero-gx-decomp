/* Non-matching: best partial attempt (95.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef void (*fn_3_BE88_Fn0)(void);

struct fn_3_BE88_lbl_3_data_1958 {
    void (*table[47])(void);
    s32 unk_BC;
    s32 unk_C0;
};

extern int fn_1_4C10(void);
extern struct fn_3_BE88_lbl_3_data_1958 lbl_3_data_1958;

void fn_3_BE88(void) {
    struct fn_3_BE88_lbl_3_data_1958 *p_lbl_3_data_1958;
    int t0;
    s32 v0;
    p_lbl_3_data_1958 = (struct fn_3_BE88_lbl_3_data_1958 *)&lbl_3_data_1958;
    t0 = fn_1_4C10();
    if ((s32)t0 == 0) {
        v0 = p_lbl_3_data_1958->unk_C0;
        if ((s32)v0 >= 0) {
            p_lbl_3_data_1958->unk_BC = v0;
            p_lbl_3_data_1958->unk_C0 = -1;
        }
        p_lbl_3_data_1958->table[p_lbl_3_data_1958->unk_BC]();
    }
}
