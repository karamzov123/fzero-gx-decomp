/* Non-matching: best partial attempt (94.20% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_tow.h"

struct fn_1_154798_state {
    void (*callbacks[36])(void);
    s32 unk_90;
    s32 unk_94;
    s32 unk_98;
    s32 unk_9C;
};

void fn_1_154798(void) {
    struct fn_1_154798_state *state = (struct fn_1_154798_state *)&lbl_1_data_49A18;
    s32 next = state->unk_9C;
    if (next >= 0) {
        s32 previous = state->unk_98;
        state->unk_9C = -1;
        state->unk_94 = previous;
        state->unk_98 = next;
    }
    if (state->unk_98 >= 0) {
        state->callbacks[state->unk_98]();
    }
}
