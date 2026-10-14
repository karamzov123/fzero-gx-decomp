/* Non-matching: best partial attempt (77.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/load.h"

typedef u32 (*fn_1_45A58_Fn0)(u32);
struct fn_1_45A58_lbl_1_bss_384C0 {
    u8 pad_0[0x15];
    u8 unk_15;
    u8 pad_16[0x5824 - 0x16];
    u32 unk_5824[16];
    u8 pad_5864[0x5AF4 - 0x5864];
    fn_1_45A58_Fn0 unk_5AF4[16];
};

void fn_1_45A58(u32 arg0) {
    struct fn_1_45A58_lbl_1_bss_384C0 *p_lbl_1_bss_384C0;
    void *v0;
    void *v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    p_lbl_1_bss_384C0 = (struct fn_1_45A58_lbl_1_bss_384C0 *)&lbl_1_bss_384C0;
    v2 = p_lbl_1_bss_384C0->unk_15;
    v3 = (u32)p_lbl_1_bss_384C0->unk_5AF4[v2];
    p_lbl_1_bss_384C0->unk_5824[v2] = 0;
    if (v3 != 0) {
        ((fn_1_45A58_Fn0)v3)(arg0);
    }
    v4 = p_lbl_1_bss_384C0->unk_15 + 1;
    v5 = v4 & 0xFF;
    p_lbl_1_bss_384C0->unk_15 = v4;
    p_lbl_1_bss_384C0->unk_15 = v5 & ~-(v5 > 15);
}
