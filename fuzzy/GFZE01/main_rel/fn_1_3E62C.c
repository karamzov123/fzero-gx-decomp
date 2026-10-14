/* Non-matching: best partial attempt (95.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/game.h"

void fn_1_3E62C(void)
{
    Obj_1_bss_25BA0 *a = &lbl_1_bss_25BA0;

    if ((s32)a->unk_0 == 0) {
        Obj_1_bss_6EAB4 *b = &lbl_1_bss_6EAB4;
        u32 flags = b->unk_0;
        a->unk_0 = 1;
        lbl_1_bss_53F4 = 13;
        b->unk_0 = flags | 0x2C;
    }
}
