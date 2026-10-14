/* Non-matching: best partial attempt (64.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_801A66A0;
extern u32 fn_80007F70(u32 *, u32 *, u32);

u32 fn_800081C8(u32 *arg0, u32 *arg1) {
    u32 left;
    u32 right;

    right = *arg1;
    left = *arg0;
    return fn_80007F70(&left, &right, lbl_801A66A0);
}
