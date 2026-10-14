/* Non-matching: best partial attempt (94.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

typedef void (*fn_80058EF4_Fn0)(u32);
typedef void (*fn_80058EF4_Fn1)(u32);
extern u8 lbl_80092384[288];
extern void SVM_CallErr(const char *, ...);

void fn_80058EF4(u32 arg0, u32 arg1) {
    Obj_8018FEB0 *p_lbl_8018FEB0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    p_lbl_8018FEB0 = &lbl_8018FEB0;
    v0 = *(u32 *)((u8 *)p_lbl_8018FEB0 + 0xC0);
    if (v0 != 0) {
        ((fn_80058EF4_Fn0)v0)(*(u32 *)((u32)((u8 *)p_lbl_8018FEB0 + 0xC0) + 4));
        if ((s32)p_lbl_8018FEB0->unk_4 == 0) {
            p_lbl_8018FEB0->unk_8 = 1;
        }
        p_lbl_8018FEB0->unk_4++;
    }
    v1 = *(u32 *)((u8 *)p_lbl_8018FEB0 + 0xB8);
    *(u32 *)((u8 *)p_lbl_8018FEB0 + 0xB0) = arg0;
    *(u32 *)((u32)((u8 *)p_lbl_8018FEB0 + 0xB0) + 4) = arg1;
    if (v1 != 0) {
        p_lbl_8018FEB0->unk_4--;
        if ((s32)*(volatile u32 *)&p_lbl_8018FEB0->unk_4 == 0) {
            if ((s32)p_lbl_8018FEB0->unk_8 != 1) {
                v3 = *(volatile u32 *)&p_lbl_8018FEB0->unk_8;
                v4 = 1;
                SVM_CallErr((const char *)lbl_80092384, v3, v4);
            }
            p_lbl_8018FEB0->unk_8 = 0;
        }
        ((fn_80058EF4_Fn1)*(u32 *)((u8 *)p_lbl_8018FEB0 + 0xB8))(*(u32 *)((u32)((u8 *)p_lbl_8018FEB0 + 0xB8) + 4));
    }
}
