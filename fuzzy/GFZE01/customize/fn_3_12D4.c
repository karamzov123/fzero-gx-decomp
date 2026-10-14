/* Non-matching: best partial attempt (88.89% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_3_12D4_lbl_3_rodata_0 {
    u8 pad_0[0x4];
    volatile f32 unk_4;
    f32 unk_8;
    u8 pad_C[0x3C];
    volatile u32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
};

extern struct fn_3_12D4_lbl_3_rodata_0 lbl_3_rodata_0;
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);

static inline void draw(f32 x, u32 color, f32 y, f32 z, f32 w, f32 t) {
    u32 loc_8[2];
    loc_8[0] = color;
    fn_1_53BD8(loc_8, x, y, z, w, t);
}

void fn_3_12D4(void) {
    f32 x = lbl_3_rodata_0.unk_4;
    draw(x, lbl_3_rodata_0.unk_48,
         lbl_3_rodata_0.unk_8, lbl_3_rodata_0.unk_4C,
         lbl_3_rodata_0.unk_50, lbl_3_rodata_0.unk_54);
}
