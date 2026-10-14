/* Non-matching: best partial attempt (61.85% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ranking.h"

struct fn_1_1586AC_Copy12 { u32 a[3]; };
struct fn_1_1586AC_Entry {
    u32 unk_0;
    u32 unk_4;
    struct fn_1_1586AC_Copy12 unk_8;
    struct fn_1_1586AC_Copy12 unk_14;
    u8 pad_20[0x1C];
};
extern u32 lbl_1_rodata_D978[3];
extern u32 lbl_1_rodata_D984[39];
extern void fn_1_9A508(void);

void fn_1_1586AC(void) {
    Obj_1_data_2A7E0_At3C *v0;
    s32 v1;
    struct fn_1_1586AC_Entry *v2;
    s32 v4;
    s32 v7;
    s32 v5;
    v0 = lbl_1_data_2A7E0.unk_3C;
    v0->unk_0 = 0;
    v2 = (struct fn_1_1586AC_Entry *)((u8 *)v0 + 0xFA0C);
    for (v1 = 0; v1 < 400; v1++) {
        v2[v1].unk_0 = 0;
        v2[v1].unk_8 = *(struct fn_1_1586AC_Copy12 *)lbl_1_rodata_D978;
        v2[v1].unk_14 = *(struct fn_1_1586AC_Copy12 *)lbl_1_rodata_D984;
    }
    for (v4 = 0; v4 < 20; v4++) {
        for (v7 = 0; v7 < 20; v7++) {
            for (v5 = 0; v5 < 20; v5++) {
                *(u32 *)((u8 *)v0 + v4 * 3200 + v7 * 160 + v5 * 4 + 12) = 0;
            }
        }
    }
    fn_1_9A508();
}
