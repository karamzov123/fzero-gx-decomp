/* Non-matching: best partial attempt (78.65% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"

extern u32 lbl_1_data_2A0C0[4];
extern s32 fn_1_9D93C(s32, u32 *);
typedef u32 (*Sig_fn_1_9CF78_FilterCallback)(u32, void *);
extern void fn_1_9CF78(void *, Sig_fn_1_9CF78_FilterCallback);

void fn_1_9D994(s32 arg0) {
    void *p;
    u8 *base = (u8 *)lbl_1_data_2A0C0;
    #pragma opt_propagation off
    __typeof__(lbl_1_data_2A7E0) *state = (__typeof__(lbl_1_data_2A7E0) *)(base + 0x720);
    state->unk_80 = 0;
    state->unk_7C = 0;
    p = (u8 *)lbl_1_data_2A0C0 + 0x2BB8;
    if (arg0 == 0x2b) {
        p = (u8 *)lbl_1_data_2A0C0 + 0x2BE4;
    }
    fn_1_9CF78(p, (Sig_fn_1_9CF78_FilterCallback)fn_1_9D93C);
}
