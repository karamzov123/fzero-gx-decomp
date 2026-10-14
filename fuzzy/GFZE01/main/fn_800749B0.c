/* Non-matching: best partial attempt (70.64% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_8019F040[240];
extern u32 lbl_801A6D78;
extern void lbl_8006DD14(void *src, void *dst);
typedef struct State {
    u8 pad[0x20];
    u8 first[0x30];
    u8 entries[3][0x30];
    u32 flags[4];
} State;

void fn_800749B0(u32 index, void *src) {
    State *base = (State *)lbl_8019F040;
    if (index == 0) {
        if (src != 0) {
            lbl_8006DD14(src, base->first);
            lbl_801A6D78 = 1;
        } else {
            lbl_801A6D78 = 0;
        }
    } else {
        if (src != 0) {
            lbl_8006DD14(src, base->entries[index - 1]);
            base->flags[index - 1] = 1;
        } else {
            base->flags[index - 1] = 0;
        }
    }
}
