#include "types.h"
typedef struct Sig_GXSetCopyClear__GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Sig_GXSetCopyClear_GXColor;
struct fn_800744F8_Arg0 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
};
struct fn_800744F8_lbl_801A6D38_T {
    u8 pad_0[0xB20];
    Sig_GXSetCopyClear_GXColor unk_B20;
    u32 unk_B24;
};
extern struct fn_800744F8_lbl_801A6D38_T *lbl_801A6D38;
extern void GXSetCopyClear(Sig_GXSetCopyClear_GXColor, u32);
void fn_800744F8(struct fn_800744F8_Arg0 arg0, u32 arg1) {
    u32 first = arg0.unk_0;
    if (lbl_801A6D38->unk_B20.r != first ||
        lbl_801A6D38->unk_B20.g != arg0.unk_1 ||
        lbl_801A6D38->unk_B20.b != arg0.unk_2 ||
        lbl_801A6D38->unk_B20.a != arg0.unk_3 ||
        lbl_801A6D38->unk_B24 != arg1) {
        GXSetCopyClear(*(Sig_GXSetCopyClear_GXColor *)&arg0, arg1);
        lbl_801A6D38->unk_B20 = *(Sig_GXSetCopyClear_GXColor *)&arg0;
        lbl_801A6D38->unk_B24 = arg1;
    }
}
