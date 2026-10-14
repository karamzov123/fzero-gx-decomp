/* Non-matching: best partial attempt (86.77% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/load.h"
extern void fn_8000659C(void);

#pragma opt_propagation off
void fn_1_4706C(void) {
    s32 i;
    u32 *base = (u32 *)(void *)&lbl_1_bss_384C0;
    u32 *p_2;
    u32 *p;
    fn_8000659C();
    if ((s32)base[0] != (s32)base[1]) {
        p = base + 6;
        for (i = 0; i < 0x400; i++, p += 4) {
            if (p[0] == 0x80000000) { p[0] = 0; base[0x5818 / 4] = p[2]; }
        }
        base[1] = base[0];
    }
    p_2 = base + 6;
    for (i = 0; i < 0x400; i++, p_2 += 4) {
        p_2[0] = 0;
    }
    base[0x5820 / 4] = 0;
}
#pragma opt_propagation reset
