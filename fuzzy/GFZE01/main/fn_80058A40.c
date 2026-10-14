/* Non-matching: best partial attempt (96.93% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

typedef u32 (*fn_80058A40_Fn0)(u32);
typedef u32 (*fn_80058A40_Fn1)(u32);
typedef u32 (*fn_80058A40_Fn2)(u32);
struct fn_80058A40_Hook {
    u32 fn;
    u32 arg;
};
extern u8 lbl_80092384[288];
extern void SVM_CallErr(const char *, ...);

u32 fn_80058A40(u32 arg0, u32 arg1, u32 arg2) {
    Obj_8018FEB0 *p_lbl_8018FEB0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    s32 v4;
    u32 v5;
    u32 t0;
    p_lbl_8018FEB0 = &lbl_8018FEB0;
    v0 = p_lbl_8018FEB0->unk_2C;
    v1 = arg0;
    if (v0 != 0) {
        t0 = ((fn_80058A40_Fn0)v0)(arg0);
        v1 = t0;
    } else {
        v2 = ((struct fn_80058A40_Hook *)((u8 *)p_lbl_8018FEB0 + 0xC0))->fn;
        if (v2 != 0) {
            ((fn_80058A40_Fn1)v2)(((struct fn_80058A40_Hook *)((u8 *)p_lbl_8018FEB0 + 0xC0))->arg);
            if ((s32)*(volatile u32 *)&p_lbl_8018FEB0->unk_4 == 0) {
                p_lbl_8018FEB0->unk_8 = 1;
            }
            p_lbl_8018FEB0->unk_4 = *(volatile u32 *)&p_lbl_8018FEB0->unk_4 + 1;
        }
        v3 = *(u32 *)v1;
        *(u32 *)v1 = 1;
        v1 = ((u32)((1 - v3) | (v3 - 1)) >> 31);
        if (((struct fn_80058A40_Hook *)((u8 *)p_lbl_8018FEB0 + 0xB8))->fn != 0) {
            p_lbl_8018FEB0->unk_4 = *(volatile u32 *)&p_lbl_8018FEB0->unk_4 - 1;
            v4 = (1 - v3);
            v5 = arg2;
            if ((s32)*(volatile u32 *)&p_lbl_8018FEB0->unk_4 == 0) {
                if ((s32)*(volatile u32 *)&p_lbl_8018FEB0->unk_8 != 1) {
                    v4 = *(volatile u32 *)&p_lbl_8018FEB0->unk_8;
                    v5 = 1;
                    SVM_CallErr((const char *)lbl_80092384, v4, v5);
                }
                p_lbl_8018FEB0->unk_8 = 0;
            }
            ((fn_80058A40_Fn2)((struct fn_80058A40_Hook *)((u8 *)p_lbl_8018FEB0 + 0xB8))->fn)(((struct fn_80058A40_Hook *)((u8 *)p_lbl_8018FEB0 + 0xB8))->arg);
        }
    }
    return v1;
}
