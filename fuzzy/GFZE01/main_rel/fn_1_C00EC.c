/* Non-matching: best partial attempt (96.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/memcard.h"

extern u32 lbl_801A66B4;
extern const f64 lbl_1_rodata_4CB0;
extern u32 lbl_1_rodata_50D8;
extern f32 lbl_1_rodata_50DC[35];

extern void fn_1_496FC(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4CF3C(void *, ...);

#pragma opt_propagation off
#pragma opt_loop_invariants off
void fn_1_C00EC(u8 type, u8 slot, s32 value1, s32 value2, f32 amount) {
    u8 * base;
    u32 nan_value;
    u32 lab_t1;
    base = (u8 *)&lbl_1_data_35AC8;

    if (type <= 2 && slot <= 3) {
        fn_1_496FC((f32)value1, (f32)value2);

        nan_value = lbl_1_rodata_50D8;
        fn_1_49514(&nan_value);
{
    f32 saved_amount = amount;
        fn_1_4955C(saved_amount, saved_amount);
}

        if (type == 1) {
            u8 *tbl2 = base + 0x7578;
            u8 *tbl1 = base + 0x74d4;
            u32 index = lbl_801A66B4;
            f32 *val = lbl_1_rodata_50DC;

            lab_t1 = *(u32 *)(tbl1 + index * 12 + type * 4);
            fn_1_4CF3C(base + 0x75d8, lab_t1, *(u32 *)(tbl2 + index * 16 + slot * 4), ((0)[val]));
        } else {
            u8 *tbl1 = base + 0x74d4;
            u32 index = lbl_801A66B4;

            fn_1_4CF3C((void *)*(u32 *)(tbl1 + index * 12 + type * 4),
                       ((0)[lbl_1_rodata_50DC]));
        }
    }
}
#pragma opt_loop_invariants reset

#pragma opt_propagation reset

