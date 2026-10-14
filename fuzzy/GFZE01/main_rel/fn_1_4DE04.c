/* Non-matching: best partial attempt (83.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/font.h"

void fn_1_4DE04(void) {
    Obj_1_bss_4C688 *ptr;
    Obj_1_bss_4C688 *end;
    ptr = &lbl_1_bss_4C688;
    end = &lbl_1_bss_4C688 + 1;
    while (ptr != end) {
        ptr->unk_0 = 0;
        ptr->unk_80 = 0;
        ptr->unk_100 = 0;
        ptr->unk_180 = 0;
        ptr->unk_200 = 0;
        ptr->unk_280 = 0;
        ptr->unk_300 = 0;
        ptr->unk_380 = 0;
        ptr = (Obj_1_bss_4C688 *)((u8 *)ptr + 0x400);
    }
}
