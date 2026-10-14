/* Non-matching: best partial attempt (83.73% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Sig_fn_800371F8_GXColor {
    u8 r, g, b, a;
} Sig_fn_800371F8_GXColor;

struct fn_1_52270_Arg0 {
    u8 pad_0[0x2C];
    f32 unk_2C;
    u8 pad_30[0x8];
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 pad_3B[0x1];
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E;
};

extern const f32 lbl_1_rodata_27A0;
extern void fn_800371F8(s32, Sig_fn_800371F8_GXColor);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);

void fn_1_52270(struct fn_1_52270_Arg0 *arg0) {
    Sig_fn_800371F8_GXColor col[2];
    col[0].r = arg0->unk_38;
    col[0].g = arg0->unk_39;
    col[0].b = arg0->unk_3A;
    col[0].a = (s32)(lbl_1_rodata_27A0 * arg0->unk_2C);
    col[1].r = arg0->unk_3C;
    col[1].g = arg0->unk_3D;
    col[1].b = arg0->unk_3E;
    col[1].a = 0;
    fn_800371F8(1, col[0]);
    fn_800371F8(2, col[1]);
    fn_80072C24(0, 4, 2, 8, 15);
    fn_80072CC4(0, 7, 7, 7, 1);
}
