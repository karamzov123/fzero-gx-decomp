/* Non-matching: best partial attempt (64.90% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/editor.h"

struct fn_3_177AC_Arg0 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
};
extern u32 lbl_3_rodata_608[38];

void fn_3_177AC(struct fn_3_177AC_Arg0 *arg0) {
    struct fn_3_177AC_Arg0 color;
    u8 v2;
    u8 v3;
    u8 v4;
    *(u32 *)&lbl_3_bss_A2410.unk_4 = *(u32 *)arg0;
    if (__rlwnm(lbl_3_bss_A2410.unk_8, 3, 31, 31)) {
        color = *(struct fn_3_177AC_Arg0 *)lbl_3_rodata_608;
        color.unk_0 = lbl_3_bss_A2410.unk_10;
        color.unk_1 = lbl_3_bss_A2410.unk_12;
        color.unk_2 = lbl_3_bss_A2410.unk_14;
        v4 = arg0->unk_0;
        v3 = arg0->unk_1;
        v2 = arg0->unk_2;
        lbl_3_bss_A2410.unk_10 = v4;
        *(u32 *)&lbl_3_bss_A2410.unk_0 = *(u32 *)&color;
        lbl_3_bss_A2410.unk_12 = v3;
        lbl_3_bss_A2410.unk_14 = v2;
    }
}
