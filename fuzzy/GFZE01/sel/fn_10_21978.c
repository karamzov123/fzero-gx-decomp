/* Non-matching: best partial attempt (97.48% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct fn_10_21978_Copy88 { u32 a[22]; };
extern const f32 lbl_10_rodata_158[19];
extern u32 lbl_10_bss_55B34[2];
extern u32 lbl_1_rodata_26F8[];
extern u8 fn_10_8780(void);
extern u32 lbl_801A66C0;
extern f32 lbl_8006D0B4(f32);
extern int fn_1_4F734(FontDrawPacket *);

void fn_10_21978(void) {
    struct fn_10_21978_Copy88 loc_8;
    s32 v6;
    s32 v7;
    s32 v12;
    if (!fn_10_8780()) {
        lbl_10_bss_55B34[0] = 1;
        loc_8 = *(struct fn_10_21978_Copy88 *)lbl_1_rodata_26F8;
        loc_8.a[0] = 0x9e1a;
        loc_8.a[12] = 9;
        *(f32 *)((u8 *)&loc_8 + 8) = 240.0f;
        *(f32 *)((u8 *)&loc_8 + 12) = 0.08f;
        v6 = 0;
        v7 = 140;
        do {
            *(f32 *)((u8 *)&loc_8 + 16) = 1.0f;
            *(f32 *)((u8 *)&loc_8 + 4) = (f32)v7;
            v12 = (s32)(lbl_801A66C0 % 320) - v6;
            if (v12 > 0 && v12 < 20) {
                *(f32 *)((u8 *)&loc_8 + 20) = lbl_8006D0B4(20.0f / (f32)(v12 + 1));
                *(f32 *)((u8 *)&loc_8 + 44) = (f32)v12 / 20.0f;
            } else if (v12 > 220 && v12 < 240) {
                *(f32 *)((u8 *)&loc_8 + 20) = lbl_8006D0B4(20.0f / (f32)(241 - v12));
                *(f32 *)((u8 *)&loc_8 + 44) = (f32)(240 - v12) / 20.0f;
            } else if (v12 >= 20 && v12 <= 220) {
                *(f32 *)((u8 *)&loc_8 + 20) = 1.0f;
                *(f32 *)((u8 *)&loc_8 + 44) = 1.0f;
            } else if (v12 <= 0 || v12 >= 240) {
                *(f32 *)((u8 *)&loc_8 + 44) = 0.0f;
            }
            *(f32 *)((u8 *)&loc_8 + 16) *= 0.016666667f;
            *(f32 *)((u8 *)&loc_8 + 24) = (f32)v6 / 60.0f;
            *(f32 *)((u8 *)&loc_8 + 32) = (f32)(v6 + 1) / 60.0f;
            fn_1_4F734((FontDrawPacket *)&loc_8);
            v6++;
            v7 += 6;
        } while (v6 < 60);
    }
}
