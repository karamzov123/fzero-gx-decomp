/* Non-matching: best partial attempt (97.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/phys.h"

extern int fn_1_4C10(void);
extern u32 fn_1_3F8C0(void);
extern u32 fn_80008E84(u32);

void fn_1_E9BA8(void) {
    s32 *state = (s32 *)lbl_1_data_3E358;
    s32 next;
    if ((s32)lbl_1_bss_7B188 == 0) return;
    if (fn_1_4C10() != 0) return;
    if (*(s16 *)&lbl_1_bss_960 == 9) {
        lbl_1_bss_7C85C.unk_0 = fn_80008E84(fn_1_3F8C0());
    }
    next = state[0x1d8 / 4];
    if (next >= 0) {
        state[0x1d8 / 4] = -1;
        state[0x1d4 / 4] = next;
    }
    if (state[0x1d4 / 4] >= 0) {
        ((void (**)(void))((u8 *)state + 0x98))[state[0x1d4 / 4]]();
    }
    if (*(s16 *)&lbl_1_bss_960 == 9) {
        fn_80008E84(lbl_1_bss_7C85C.unk_0);
    }
}
