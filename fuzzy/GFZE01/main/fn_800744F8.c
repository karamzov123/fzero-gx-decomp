/* Non-matching: best partial attempt (95.09% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Sig_GXSetCopyClear__GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Sig_GXSetCopyClear_GXColor;

extern void GXSetCopyClear(Sig_GXSetCopyClear_GXColor, u32);

struct fn_800744F8_lbl_801A6D38_T {
    u8 pad_0[0xB20];
    Sig_GXSetCopyClear_GXColor unk_B20;
    u32 unk_B24;
};

extern struct fn_800744F8_lbl_801A6D38_T *lbl_801A6D38;

void fn_800744F8(Sig_GXSetCopyClear_GXColor *arg0, u32 arg1) {
    if (lbl_801A6D38->unk_B20.r != arg0->r ||
        lbl_801A6D38->unk_B20.g != arg0->g ||
        lbl_801A6D38->unk_B20.b != arg0->b ||
        lbl_801A6D38->unk_B20.a != arg0->a ||
        lbl_801A6D38->unk_B24 != arg1) {
        GXSetCopyClear(*arg0, arg1);
        lbl_801A6D38->unk_B20 = *arg0;
        lbl_801A6D38->unk_B24 = arg1;
    }
}
