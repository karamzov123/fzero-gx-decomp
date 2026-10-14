/* Non-matching: best partial attempt (16.58% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_12_bss_1B778[2];
extern u64 __mftb(void);

u64 fn_12_335B8(void) {
    if (*(u64 *)lbl_12_bss_1B778 == 1) {
        return 0;
    }
    return __mftb();
}
