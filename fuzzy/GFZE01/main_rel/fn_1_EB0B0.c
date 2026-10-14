/* Non-matching: best partial attempt (68.50% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/phys.h"

extern u8 lbl_1_bss_7C8CE;

#pragma opt_propagation off
int fn_1_EB0B0(void) {
    s32 flag = lbl_1_bss_7C8CE;
    s32 state = lbl_1_bss_7B188;
    return -(state != 0) & flag;
}
