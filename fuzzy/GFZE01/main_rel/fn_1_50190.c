/* Non-matching: best partial attempt (98.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct Pkt88 { u32 words[22]; };

extern const f32 lbl_1_rodata_2750;
extern const f32 lbl_1_rodata_27A4;
extern const f64 lbl_1_rodata_2758;
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

#pragma opt_common_subs off
static inline u32 *fn_1_50190_array_read(u32 *array) { return array; }
#pragma opt_lifetimes off
void fn_1_50190(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    f32 temp_f31;
    u32 temp_r0;
    u32 temp_r4;
    f32 var_f30;
    f32 temp_f29;
    f32 temp_f30_2;
    f32 temp_f28_2;
    f32 var_f22_2;
    u32 temp_r0_2;
    f32 half;
    f32 var_f22;
    f32 temp_f30;
    f32 temp_f26_2;
    f32 temp_f28;
    f32 temp_f26;
    f32 temp_f25;
    f32 temp_f24;
    f32 temp_f23;
    s32 sp4;
    struct Pkt88 loc_8;

    temp_f23 = (f32) fn_1_48690((u32)(*(u32 *)((u8 *)(arg0) + 0)));
    temp_f24 = (f32) fn_1_486C4((u32)(*(u32 *)((u8 *)(arg0) + 0)));
    temp_f25 = (temp_f23 - farg2) - farg3;
    temp_f26 = (farg0 - farg2) - farg3;
    temp_f23 = (farg1 - farg4) - farg5;
    temp_f24 = (temp_f24 - farg4) - farg5;
    if (!(farg0 <= lbl_1_rodata_2750) && !(farg1 <= lbl_1_rodata_2750) && !(temp_f25 <= lbl_1_rodata_2750) && !(temp_f24 <= lbl_1_rodata_2750) && !(temp_f26 <= lbl_1_rodata_2750) && !(temp_f23 <= lbl_1_rodata_2750) && !(farg2 < lbl_1_rodata_2750) && !(farg3 < lbl_1_rodata_2750) && !(farg4 < lbl_1_rodata_2750) && !(farg5 < lbl_1_rodata_2750)) {
        temp_r4 = *(u32 *)((u8 *)(arg0) + 48);
        temp_r0 = temp_r4 & 3;
        switch (temp_r0) {                          /* switch 1; irregular */
        default:                                    /* switch 1 */
            var_f22 = *(f32 *)((u8 *)(arg0) + 4);
            break;
        case 2:                                     /* switch 1 */
            half = farg0 * (*(f32 *)((u8 *)(&lbl_1_rodata_27A4) + 0));
            var_f22_2 = (*(f32 *)((u8 *)(arg0) + 4)) - half;
            break;
        case 3:                                     /* switch 1 */
            var_f22_2 = (*(f32 *)((u8 *)(arg0) + 4)) - farg0;
            break;
        }
        temp_r0_2 = (temp_r4 >> 2U) & 3;
        switch (temp_r0_2) {                        /* switch 2; irregular */
        case 2:                                     /* switch 2 */
            half = farg1 * (*(f32 *)((u8 *)(&lbl_1_rodata_27A4) + 0));
            var_f30 = (*(f32 *)((u8 *)(arg0) + 8)) - half;
            break;
        case 3:                                     /* switch 2 */
            var_f30 = (*(f32 *)((u8 *)(arg0) + 8)) - farg1;
            break;
        default:                                    /* switch 2 */
            break;
            var_f30 = *(f32 *)((u8 *)(arg0) + 8);
        }
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)(0), (s16)(0), (s16)((s16) farg2), (s16)((s16) farg4));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22_2;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) farg2), (s16)(0), (s16)((s16) temp_f25), (s16)((s16) farg4));
        temp_f29 = temp_f26 / temp_f25;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        temp_f31 = var_f22_2 + farg2;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
{
    f32 temp_f27;
        temp_f27 = farg2 + temp_f25;
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) temp_f27), (s16)(0), (s16)((s16) farg3), (s16)((s16) farg4));
        temp_f26_2 = temp_f26 + temp_f31;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26_2;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)(0), (s16)((s16) farg4), (s16)((s16) farg2), (s16)((s16) temp_f24));
        temp_f28 = temp_f23 / temp_f24;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22_2;
        temp_f30 = var_f30 + farg4;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) farg2), (s16)((s16) farg4), (s16)((s16) temp_f25), (s16)((s16) temp_f24));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) temp_f27), (s16)((s16) farg4), (s16)((s16) farg3), (s16)((s16) temp_f24));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26_2;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        temp_f28_2 = farg4 + temp_f24;
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)(0), (s16)((s16) temp_f28_2), (s16)((s16) farg2), (s16)((s16) farg5));
        temp_f30_2 = temp_f23 + temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22_2;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) farg2), (s16)((s16) temp_f28_2), (s16)((s16) temp_f25), (s16)((s16) farg5));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) temp_f27), (s16)((s16) temp_f28_2), (s16)((s16) farg3), (s16)((s16) farg5));
}
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26_2;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
    }
}
#pragma opt_lifetimes reset

#pragma opt_common_subs reset

