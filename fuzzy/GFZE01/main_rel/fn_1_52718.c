/* Non-matching: best partial attempt (84.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct Sig_fn_800371F8_GXColor {
    u8 r, g, b, a;
} Sig_fn_800371F8_GXColor;

struct fn_1_52718_Arg0 {
    u8 pad_0[0x2c];
    f32 unk_2c;
    u8 pad_30[8];
    u8 unk_38;
    u8 unk_39;
    u8 unk_3a;
    u8 pad_3b;
    Sig_fn_800371F8_GXColor unk_3c;
};

extern const f32 lbl_1_rodata_27A0;
extern void fn_800371F8(s32, Sig_fn_800371F8_GXColor);
extern void fn_800728A8(s32, s32, s32, s32);

void fn_1_52718(struct fn_1_52718_Arg0 *arg0) {
    u8 v0;
    u8 v1;
    Sig_fn_800371F8_GXColor loc_C;
    Sig_fn_800371F8_GXColor loc_8;
    v0 = arg0->unk_38;
    v1 = arg0->unk_39;
    loc_C.r = v0;
    loc_C.g = v1;
    loc_C.b = arg0->unk_3a;
    loc_C.a = (s32)(f32)(lbl_1_rodata_27A0 * arg0->unk_2c);
    fn_800371F8(1, loc_C);
    loc_8 = arg0->unk_3c;
    fn_800371F8(2, loc_8);
    fn_800728A8(1, 1, 1, 0);
}
