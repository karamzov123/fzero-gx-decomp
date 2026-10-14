/* Non-matching: best partial attempt (97.06% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

typedef void (*SVMCallback)(void *);
typedef struct SVMCallbackPair {
    SVMCallback function;
    void *object;
} SVMCallbackPair;

extern u8 lbl_80092384[288];
extern void SVM_CallErr(const char *, ...);

void fn_800597F4(void) {
    volatile Obj_8018FEB0 *state = &lbl_8018FEB0;
    SVMCallbackPair *callback = (SVMCallbackPair *)((u8 *)state + 0xB8);
    if (callback->function != 0) {
        state->unk_4--;
        if ((s32)state->unk_4 == 0) {
            if ((s32)state->unk_8 != 3) {
                SVM_CallErr((const char *)lbl_80092384, state->unk_8, 3);
            }
            state->unk_8 = 0;
        }
        callback->function(callback->object);
    }
}
