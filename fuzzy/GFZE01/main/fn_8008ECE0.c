/* Non-matching: best partial attempt (81.25% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

struct PiRegs { vu32 status; };
extern struct PiRegs __PIRegs;
typedef void (*InterruptCallback)(u32);
extern InterruptCallback * volatile lbl_801A6678;

void fn_8008ECE0(s16 interrupt, void *context) {
    u32 value;
    InterruptCallback callback;
    InterruptCallback *state;
    value = __PIRegs.status;
    value &= 0x1000;
    state = lbl_801A6678;
    value |= 0x1000;
    *(vu32 *)&__PIRegs = value;
    callback = *state;
    if (callback != 0) {
        callback(2);
    }
}
