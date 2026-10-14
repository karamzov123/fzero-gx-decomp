/* Non-matching: best partial attempt (91.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern s32 fn_1_155F7C(void);
extern s32 fn_1_155F8C(void);

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 pad_A[0x16];
    s32 unk_20;
    u8 pad_24[0x28];
    s32 unk_4C;
} ObjLocal;

#pragma opt_dead_assignments off
#pragma opt_strength_reduction off
u32 fn_1_145B58(s32 arg0, ObjLocal *arg1) {
    s32 f4;
    s32 f5;
    s32 f6;
    s32 f7;
    s32 res;
    s32 f4_2;
    u8 lab_v;
    s32 x;
    u32 a;
    u32 b;
    if (arg0 == 10 || arg0 == 6) {
        return arg1->unk_20 == 0;
    }
    f4 = 1;
    f5 = 1;
    f7 = 1;
    f6 = 1;
    (void) f6;  /* fzgx: keeps the web at its definition */
    if (!((u32)((~((u32)arg0 - 4) | 1) - ((1 - ((u32)arg0 - 4)) >> 1)) >> 31)) {
        f4_2 = 0;
        (void) f4_2;  /* fzgx: keeps the web at its definition */
    }
    if (f4_2 == 0 && arg0 != 9) {
        f7 = 0;
    }
    if (f7 == 0 && arg0 != 10) {
        f6 = 0;
    }
    if (f6 == 0 && arg0 != 6) {
        f5 = 0;
        (void) f5;  /* fzgx: keeps the web at its definition */
    }
    if (f5) {
        res = 0;
        if (fn_1_155F7C() != 0) {
            if (arg1->unk_20 == fn_1_155F8C()) {
                res = 1;
            }
        }
        return res;
    }
    lab_v = lbl_1_bss_3C30.unk_8;
    x = lab_v ^ arg1->unk_4C;
    a = x >> 1;
    b = x & lab_v;
    return (a - b) >> 31;
}
#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset
