/* Non-matching: best partial attempt (100.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/font.h"

void fn_1_4DE04(void) {
    Obj_1_bss_4C688 *p = &lbl_1_bss_4C688;
    s32 i;

    for (i = 0; i < 64; i++, p = (Obj_1_bss_4C688 *)((u8 *)p + 0x80)) {
        p->unk_0 = 0;
    }
}
