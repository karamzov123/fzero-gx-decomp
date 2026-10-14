/* Non-matching: best partial attempt (94.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/archive.h"

extern void *lbl_801A6410;
extern void fn_1_46B4(void *, void *, u8 *, s32);
extern void OSPanic(u8 *, s32, u8 *, ...);

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_12A734(s32 arg0) {
    s32 offset = arg0 * 0x6c;
    Obj_1_bss_897AC *base = &lbl_1_bss_897AC;
    if ((s32)((Obj_1_bss_897AC *)((u8 *)base + offset))->unk_0 == 1) {
        Obj_1_bss_897AC *entry = (Obj_1_bss_897AC *)((u8 *)base + offset);
        void *handle = (void *)entry->unk_68;
        fn_1_46B4(lbl_801A6410, handle, lbl_1_data_40608, 0x145);
        ((Obj_1_bss_897AC *)((u8 *)base + offset))->unk_0 = 0;
    } else {
        OSPanic(lbl_1_data_40608, 0x149, lbl_1_data_40720);
    }
}
