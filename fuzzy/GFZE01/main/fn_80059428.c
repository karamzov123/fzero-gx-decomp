/* Non-matching: best partial attempt (96.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef void (*fn_80059428_Fn0)(u32);
typedef void (*fn_80059428_Fn1)(u32, void *);

struct fn_80059428_pair {
    u32 f_0;
    u32 f_4;
};

struct fn_80059428_lbl_8018FEB0 {
    union {
        struct { u32 unk_0; };
        struct { u8 pad_view_unk_4[0x4]; s32 unk_4; };
        struct { u8 pad_view_unk_8[0x8]; s32 unk_8; };
        struct { u8 pad_view_unk_C[0xC]; u8 unk_C[0x24]; };
        struct { u8 pad_view_unk_30[0x30]; u8 unk_30[0x80]; };
        struct { u32 unk_B4; };
        struct { u8 pad_view_unk_B0[0xB0]; u32 unk_B0; };
        struct { u8 pad_view_unk_B8[0xB8]; u32 unk_B8; };
        struct { u8 pad_view_unk_BC[0xBC]; u32 unk_BC; };
        struct { u8 pad_view_unk_C0[0xC0]; u32 unk_C0; };
        struct { u8 pad_view_unk_C4[0xC4]; u32 unk_C4; };
        struct { u8 pad_view_unk_C8[0xC8]; u8 unk_C8[0x40]; };
        struct { u8 pad_view_unk_108[0x108]; struct fn_80059428_pair unk_108[6][6]; };
    };
};

extern struct fn_80059428_lbl_8018FEB0 lbl_8018FEB0[];
extern u8 lbl_800924C4[52];
extern u8 lbl_80092384[288];
extern u32 SVM_CallErr(u32, ...);
extern void strncpy(void *, void *, int);

#pragma opt_propagation off
static inline struct fn_80059428_pair (* fn_80059428_read_pointer(struct fn_80059428_lbl_8018FEB0 * owner))[6] { return owner->unk_108; }
#pragma opt_lifetimes off
#pragma opt_strength_reduction off
#pragma opt_dead_assignments off
s32 fn_80059428(s32 arg0, u32 arg1, u32 arg2) {
    s32 id;
    struct fn_80059428_lbl_8018FEB0 *p_lbl_8018FEB0;
    struct fn_80059428_pair *q;
    s32 i;

    p_lbl_8018FEB0 = (struct fn_80059428_lbl_8018FEB0 *)&lbl_8018FEB0;
    id = arg0;
    if (p_lbl_8018FEB0->unk_C0 != 0) {
        ((fn_80059428_Fn0)p_lbl_8018FEB0->unk_C0)(
            *(volatile u32 *)((u8 *)&p_lbl_8018FEB0->unk_C0 + 4));
        if ((*(s32 volatile *)&(p_lbl_8018FEB0->unk_4)) /* Retail reloads this field. */ == 0) {
            p_lbl_8018FEB0->unk_8 = 1;
        }
        p_lbl_8018FEB0->unk_4 = (*(s32 volatile *)&(p_lbl_8018FEB0->unk_4)) /* Retail reloads this field. */ + 1;
    }
    q = fn_80059428_read_pointer(p_lbl_8018FEB0)[id];
    for (i = 0; i < 6; i++) {
        if (q->f_0 == 0) {
            q->f_0 = arg1;
            q->f_4 = arg2;
            break;
        }
        q++;
    }
    if (i == 6) {
        strncpy(p_lbl_8018FEB0->unk_30, lbl_800924C4, 127);
        if (p_lbl_8018FEB0->unk_B0 != 0) {
            ((fn_80059428_Fn1)p_lbl_8018FEB0->unk_B0)(
                *(volatile u32 *)((u8 *)&p_lbl_8018FEB0->unk_B0 + 4), p_lbl_8018FEB0->unk_30);
        }
    }
    if (p_lbl_8018FEB0->unk_B8 != 0) {
        p_lbl_8018FEB0->unk_4 = (*(s32 volatile *)&(p_lbl_8018FEB0->unk_4)) /* Retail reloads this field. */ - 1;
        if ((*(s32 volatile *)&(p_lbl_8018FEB0->unk_4)) /* Retail reloads this field. */ == 0) {
            if ((*(s32 volatile *)&(p_lbl_8018FEB0->unk_8)) /* Retail reloads this field. */ != 1) {
                SVM_CallErr((u32)lbl_80092384, (*(s32 volatile *)&(p_lbl_8018FEB0->unk_8)) /* Retail reloads this field. */, 1);
            }
            p_lbl_8018FEB0->unk_8 = 0;
        }
        ((fn_80059428_Fn0)p_lbl_8018FEB0->unk_B8)(
            *(volatile u32 *)((u8 *)&p_lbl_8018FEB0->unk_B8 + 4));
    }
    if (i == 6) {
        return -1;
    }
    return i;
}
#pragma opt_dead_assignments reset

#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset

#pragma opt_propagation reset

