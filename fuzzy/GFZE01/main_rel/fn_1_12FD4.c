/* Non-matching: best partial attempt (76.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/live_camera.h"

extern u32 *fn_1_1304C(Obj_1_bss_3B30 *, u32);

u32 fn_1_12FD4(u32 arg0, u32 arg1, u32 arg2) {
    *(u8 *)&lbl_1_bss_3B30.unk_0 = 0;
    lbl_1_bss_3B30.unk_80 = arg1;
    lbl_1_bss_3B30.unk_84 = 0;
    return *fn_1_1304C(&lbl_1_bss_3B30, arg0);
}
