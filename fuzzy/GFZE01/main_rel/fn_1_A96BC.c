/* Non-matching: best partial attempt (81.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"

void fn_1_A96BC(void) {
    Obj_1_bss_6F648 *state = &lbl_1_bss_6F648;
    *(u32 *)&state->pad_10[0x2000] = 0;
    state->unk_C = (u32)state->pad_10;
}
