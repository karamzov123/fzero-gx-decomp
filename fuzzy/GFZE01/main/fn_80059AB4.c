/* Non-matching: best partial attempt (97.06% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

typedef u32 (*fn_80059AB4_Fn0)(u32);
struct fn_80059AB4_Callback {
    fn_80059AB4_Fn0 function;
    u32 argument;
};
extern u8 lbl_80092384[288];
extern void SVM_CallErr(const char *, ...);

void fn_80059AB4(void) {
    volatile Obj_8018FEB0 *p_lbl_8018FEB0 = &lbl_8018FEB0;
    struct fn_80059AB4_Callback *callback = (struct fn_80059AB4_Callback *)((u8 *)&lbl_8018FEB0 + 0xB8);
    u32 v0;
    if (callback->function != 0) {
        v0 = p_lbl_8018FEB0->unk_4;
        p_lbl_8018FEB0->unk_4 = v0 - 1;
        if ((s32)p_lbl_8018FEB0->unk_4 == 0) {
            if ((s32)p_lbl_8018FEB0->unk_8 != 1) {
                SVM_CallErr((const char *)lbl_80092384, p_lbl_8018FEB0->unk_8, 1);
            }
            p_lbl_8018FEB0->unk_8 = 0;
        }
        callback->function(callback->argument);
    }
}
