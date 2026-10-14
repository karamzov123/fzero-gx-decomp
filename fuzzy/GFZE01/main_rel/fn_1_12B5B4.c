/* Non-matching: best partial attempt (96.57% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/archive.h"
extern u8 *fn_1_36AD0(void);

void fn_1_12B5B4(s16 arg0, s16 arg1) {
    u8 *base;
    u32 *src;
    s16 i;
    base = fn_1_36AD0() + arg0 * 0x81C0;
    src = &lbl_1_bss_8B2E0.unk_0 + arg0 * 12 + (s16)(arg1 % 4) * 3;
    i = 0;
    while (i < 3) {
        *(u32 *)(base + 0x81A8 + i * 8) = *src;
        i++;
        src++;
    }
}
