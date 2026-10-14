/* Non-matching: best partial attempt (90.72% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern const char lbl_80092384[];
extern void SVM_CallErr(const char *, ...);

typedef void (*Cb)(u32);

typedef struct {
    Cb fn;
    u32 arg;
} Hook;

typedef struct {
    u32 a;
    u32 b;
} Entry;

typedef struct {
    u32 unk_0;
    s32 unk_4;
    s32 unk_8;
    u8 pad_C[0xAC];
    Hook unk_B8;
    Hook unk_C0;
    Entry unk_C8[2];
} Obj;

extern Obj lbl_8018FEB0;

static inline Entry * fn_80059028_read_pointer(Obj * owner) { return owner->unk_C8; }
#pragma opt_propagation off
static inline Cb fn_80059028_read_pointer_(Obj * owner) { return owner->unk_B8.fn; }
#pragma opt_dead_assignments off
static inline Cb fn_80059028_read_pointer__(Hook * owner) { return owner->fn; }
void fn_80059028(u32 arg0, u32 arg1, u32 arg2) {
    Obj *p = (Obj *)&lbl_8018FEB0;
    Cb f;

    if (p->unk_C0.fn) {
        Hook *h = &p->unk_C0;
        fn_80059028_read_pointer__(h)(h->arg);
        if (p->unk_4 == 0) {
            p->unk_8 = 1;
        }
        p->unk_4 = p->unk_4 + 1;
    }

    f = fn_80059028_read_pointer_(p);
    fn_80059028_read_pointer(p)[arg0].a = arg1;
    fn_80059028_read_pointer(p)[arg0].b = arg2;
    if (f) {
        Hook *h = &p->unk_B8;
        p->unk_4 = p->unk_4 - 1;
        if (*(volatile s32 *)&p->unk_4 == 0) {
            if (*(volatile s32 *)&p->unk_8 != 1) {
                SVM_CallErr(lbl_80092384, p->unk_8, 1);
            }
            p->unk_8 = 0;
        }
        fn_80059028_read_pointer__(h)(h->arg);
    }
}
#pragma opt_dead_assignments reset

#pragma opt_propagation reset

