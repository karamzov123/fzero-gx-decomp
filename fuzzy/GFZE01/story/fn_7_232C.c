/* Non-matching: best partial attempt (97.08% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_7_232C_bss {
    u8 pad_0[0x24];
    u32 unk_24;
    u8 pad_28[0x270];
    s32 unk_298;
    u32 unk_29C;
    u32 unk_2A0;
};

extern struct fn_7_232C_bss lbl_7_bss_0;

s32 fn_7_232C(u32 *arg0) {
    struct fn_7_232C_bss *p = &lbl_7_bss_0;
    u32 v = *arg0;
    s32 ret = 0;
    p->unk_2A0 = v;
    p->unk_24 = v & 2;
    if (p->unk_298 != 0) {
        ret = 2;
    }
    return ret;
}
