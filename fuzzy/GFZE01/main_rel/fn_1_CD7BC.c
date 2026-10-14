/* Non-matching: best partial attempt (98.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
struct fn_1_CD7BC_Copy88 { u32 a[22]; };
struct fn_1_CD7BC_lbl_1_rodata_5C00 {
    f64 unk_0;
};
extern f32 lbl_1_rodata_5C3C;
extern f32 lbl_1_rodata_5C40;
extern f32 lbl_1_rodata_5C48;
extern f32 lbl_1_rodata_5C7C;
extern f32 lbl_1_rodata_5CFC;
extern f32 lbl_1_rodata_5D90;
extern f32 lbl_1_rodata_5E0C;
extern f32 lbl_1_rodata_5F10;
extern f32 lbl_1_rodata_5F18;
extern f32 lbl_1_rodata_5F1C;
extern struct fn_1_CD7BC_lbl_1_rodata_5C00 lbl_1_rodata_5C00;
extern u32 lbl_1_rodata_26F8;
extern u32 fn_1_864E8(int);
extern u16 fn_1_8664C(int);
extern u32 fn_1_58C4(void);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern f32 lbl_8006D0B4(f32);
extern int fn_1_4F734(FontDrawPacket *);

struct FzgxCopy_88 { u32 words[22]; };
static inline u32 fn_1_CD7BC_array_read(u32 *array, s32 index) { return array[index]; }
void fn_1_CD7BC(s32 arg0) {
    u32 * fzgx_live;
    u16 temp_r3;
    s32 base;
    s32 var_r29;
    s32 var_r28;
    s32 temp_r0;
    s32 sp64;
    s32 sp60;
    struct FzgxCopy_88 loc_8;
    s32 sp4;
    f32 temp_f31;
    f32 temp_f29;
    f32 temp_f28;
    f32 temp_f27;
    f32 var_f1;
    f32 var_f1_2;

    if (!(fn_1_864E8((s32)(arg0)) & 0x10010080)) {
        temp_r3 = fn_1_8664C((s32)(arg0));
        if (((s32) temp_r3 > 0x14) && ((s32) temp_r3 < 0xAA)) {
            loc_8 = *(const struct FzgxCopy_88 *)((((s32)(((u8 *)(&lbl_1_rodata_26F8) + -4))) + 4));
            fzgx_live = loc_8.words;
            fzgx_live[0] = 0x940C;
            (*(f32 *)((u8 *)(&loc_8) + 12)) = *(f32 *)((u8 *)(&lbl_1_rodata_5F18) + 0);
            temp_f31 = *(f32 *)((u8 *)(&lbl_1_rodata_5C40) + 0);
            if (fn_1_58C4() == 1) {
                var_f1 = *(f32 *)((u8 *)(&lbl_1_rodata_5CFC) + 0);
            } else {
                var_f1 = *(f32 *)((u8 *)(&lbl_1_rodata_5E0C) + 0);
            }
            (*(f32 *)((u8 *)(&loc_8) + 16)) *= var_f1;
            if (fn_1_58C4() == 1) {
                var_f1_2 = *(f32 *)((u8 *)(&lbl_1_rodata_5CFC) + 0);
            } else {
                var_f1_2 = *(f32 *)((u8 *)(&lbl_1_rodata_5E0C) + 0);
            }
            (*(f32 *)((u8 *)(&loc_8) + 20)) *= var_f1_2;
            var_r28 = 0;
            var_r29 = 0;
            base = temp_r3 - 0x14;
            (*(f32 *)((u8 *)(&loc_8) + 44)) = *(f32 *)((u8 *)(&lbl_1_rodata_5D90) + 0);
            temp_f29 = *(f32 *)((u8 *)(&lbl_1_rodata_5CFC) + 0);
            temp_f31 = *(f32 *)((u8 *)(&lbl_1_rodata_5C40) + 0);
            temp_f27 = *(f32 *)((u8 *)(&lbl_1_rodata_5C7C) + 0);
            temp_f28 = *(f32 *)((u8 *)(&lbl_1_rodata_5F1C) + 0);
            do {
                s32 temp_r27;
                (*(f32 *)((u8 *)(&loc_8) + 20)) = temp_f29;
                temp_r27 = base - var_r28;
                if (var_r28 < 6) {
                    if ((temp_r27 > 0) && (temp_r27 < 0xA)) {
                        loc_8.words[0xC] = 9;
                        (*(f32 *)((u8 *)(&loc_8) + 4)) = (*(f32 *)((u8 *)(&lbl_1_rodata_5C3C) + 0)) - (f32) ((fn_1_48690((u32)(fn_1_CD7BC_array_read(loc_8.words, 0))) >> 1U) & 0x7FFF);
                    } else {
                        loc_8.words[0xC] = 0xB;
                        (*(f32 *)((u8 *)(&loc_8) + 4)) = (*(f32 *)((u8 *)(&lbl_1_rodata_5C3C) + 0)) + (f32) ((fn_1_48690((u32)(fn_1_CD7BC_array_read(loc_8.words, 0))) >> 1U) & 0x7FFF);
                    }
                } else if ((temp_r27 > 0) && (temp_r27 < 0xA)) {
                    loc_8.words[0xC] = 0xB;
                    (*(f32 *)((u8 *)(&loc_8) + 4)) = (*(f32 *)((u8 *)(&lbl_1_rodata_5C3C) + 0)) + (f32) ((fn_1_48690((u32)(fn_1_CD7BC_array_read(loc_8.words, 0))) >> 1U) & 0x7FFF);
                } else {
                    loc_8.words[0xC] = 9;
                    (*(f32 *)((u8 *)(&loc_8) + 4)) = (*(f32 *)((u8 *)(&lbl_1_rodata_5C3C) + 0)) - (f32) ((fn_1_48690((u32)(fn_1_CD7BC_array_read(loc_8.words, 0))) >> 1U) & 0x7FFF);
                }
                (*(f32 *)((u8 *)(&loc_8) + 8)) = (f32) var_r29 + (temp_f31 - (f32) ((fn_1_486C4((u32)(fn_1_CD7BC_array_read(loc_8.words, 0))) >> 1U) & 0x7FFF));
                if ((temp_r27 > 0) && (temp_r27 < 0xA)) {
                    (*(f32 *)((u8 *)(&loc_8) + 16)) *= lbl_8006D0B4((f32)((*(f32 *)((u8 *)(&lbl_1_rodata_5C48) + 0)) / (f32) (temp_r27 + 1)));
                    (*(f32 *)((u8 *)(&loc_8) + 44)) = (f32) temp_r27 / (*(f32 *)((u8 *)(&lbl_1_rodata_5C48) + 0));
                } else if ((temp_r27 > 0x82) && (temp_r27 < 0x96)) {
                    (*(f32 *)((u8 *)(&loc_8) + 16)) *= lbl_8006D0B4((f32)((*(f32 *)((u8 *)(&lbl_1_rodata_5F10) + 0)) / (f32) (0x97 - temp_r27)));
                    (*(f32 *)((u8 *)(&loc_8) + 44)) = (f32) (0x96 - temp_r27) / (*(f32 *)((u8 *)(&lbl_1_rodata_5F10) + 0));
                } else if ((temp_r27 >= 0xA) && (temp_r27 <= 0x82)) {
                    (*(f32 *)((u8 *)(&loc_8) + 16)) = *(f32 *)((u8 *)(&lbl_1_rodata_5CFC) + 0);
                    (*(f32 *)((u8 *)(&loc_8) + 44)) = *(f32 *)((u8 *)(&lbl_1_rodata_5CFC) + 0);
                } else if ((temp_r27 <= 0) || (temp_r27 >= 0x96)) {
                    (*(f32 *)((u8 *)(&loc_8) + 44)) = *(f32 *)((u8 *)(&lbl_1_rodata_5D90) + 0);
                }
                temp_r0 = var_r28 + 1;
                sp64 = temp_r0 ^ 0x80000000;
                sp60 = 0x43300000;
                (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
                (*(f32 *)((u8 *)(&loc_8) + 28)) = (f32) var_r28 / temp_f27;
                (*(f32 *)((u8 *)(&loc_8) + 36)) = (f32) temp_r0 / temp_f27;
                fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
                var_r28 += 1;
                var_r29 += 4;
            } while (var_r28 < 0xD);
        }
    }
}
