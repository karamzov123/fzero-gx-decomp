/* Non-matching: best partial attempt (97.06% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef void (*fn_800596D4_CbFn)(s32);

typedef struct {
    u32 fn;
    s32 arg;
} fn_800596D4_Cb;

typedef struct {
    u32 unk_0;
    volatile s32 unk_4;
    volatile s32 unk_8;
    u8 pad_C[0xAC];
    fn_800596D4_Cb cb;
} fn_800596D4_Obj;

extern fn_800596D4_Obj lbl_8018FEB0;
extern char lbl_80092384[288];
extern void SVM_CallErr(const char *message, ...);

void fn_800596D4(void) {
    fn_800596D4_Obj *p = (fn_800596D4_Obj *)&lbl_8018FEB0;

    if (p->cb.fn != 0) {
        p->unk_4 = p->unk_4 - 1;
        if (p->unk_4 == 0) {
            if (p->unk_8 != 5) {
                SVM_CallErr(lbl_80092384, p->unk_8, 5);
            }
            p->unk_8 = 0;
        }
        {
            fn_800596D4_Cb *c = (fn_800596D4_Cb *)&p->cb;
            ((fn_800596D4_CbFn)c->fn)(c->arg);
        }
    }
}
