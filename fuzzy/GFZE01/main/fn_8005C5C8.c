/* Non-matching: best partial attempt (85.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

extern const f64 lbl_801A7248;
extern const f32 lbl_801A7240;
extern const f64 lbl_801A7238;
extern const f64 lbl_801A7230;
extern f32 fn_80088578(f32 x);

typedef struct {
    u8 pad_0[0x140A];
    u8 sel;
    u8 pad_1[0x19];
    u8 *rec;
    u8 pad_2[0x7C];
    s32 a;
    u8 pad_3[8];
    s32 b;
} Rec;

#define BASE ((u8 *)lbl_801A6C80)
#define IDX ((sel & 0xFF) * 0x20)
#define CONV(x) ((s32)(lbl_801A7230 * (lbl_801A7238 * (f64)fn_80088578((f32)(x) / lbl_801A7240))))

#pragma opt_dead_assignments off
u32 fn_8005C5C8(s32 arg0) {
    s32 off = arg0 * 0x118;
    Rec *p = (Rec *)(BASE + off);
    u16 sel = p->sel;
    u8 *rec;
    u8 *q;
    Rec *e;
    s32 v0;
    s32 v1;
    u8 b;
    u8 a0;
    u8 a15;

    if (*(u32 *)((((0x5A4) + (IDX)) + (BASE))) != 0) {
        return (u32)e;
    }
    rec = p->rec;
    a0 = rec[0];
    a15 = ((0x15)[rec]);
    if (a15 != 0 || a0 == 0) {
        b = BASE[IDX + 0x593];
        if (b != 0) {
            v0 = CONV(b);
        } else {
            v0 = -904;
        }
        q = BASE + IDX;
        b = q[0x594];
        (void) b;  /* fzgx: keeps the web at its definition */
        if (b != 0) {
            v1 = CONV(b);
        } else {
            v1 = -904;
        }
    } else {
        b = rec[0x17];
        if (b != 0) {
            v0 = CONV(b);
        } else {
            v0 = -904;
        }
        b = rec[0x18];
        if (b != 0) {
            v1 = CONV(b);
        } else {
            v1 = -904;
        }
    }
    e = (Rec *)(BASE + off);
    e->a = v0;
    e->b = v1;
    return (u32)e;
}
#pragma opt_dead_assignments reset

