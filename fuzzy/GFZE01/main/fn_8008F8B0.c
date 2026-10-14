/* Non-matching: best partial attempt (87.44% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/types.h"

extern vu32 __PIRegs[];
extern u32 lbl_801A6E2C;

void fn_8008F8B0(s32 arg0, void *arg1) {
    __PIRegs[0] = 0x1000;
    if (lbl_801A6E2C != 0) {
        ((void (*)(s16, void *))lbl_801A6E2C)((s16)arg0, arg1);
    }
}
