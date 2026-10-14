/* Non-matching: best partial attempt (84.88% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/spline.h"
struct SplineLookupRow { s16 a, group, type, d, value; };
struct SplineLookupTable { struct SplineLookupRow rows[44]; };
extern u8 lbl_1_rodata_6E38[440];
extern void fn_80008BA8(void *, void *, u32);
extern u32 fn_1_F9DC4(u32);
extern u32 fn_1_F210C(s32);
#pragma opt_loop_invariants off
#pragma opt_propagation off
s32 fn_1_F965C(s16 index) {
    struct SplineLookupTable table1;
    struct SplineLookupTable table2;
    struct SplineLookupTable table3;
    struct SplineLookupRow row1;
    struct SplineLookupRow row2;
    struct SplineLookupRow row3;
    s32 result = 0;
    s16 ordinal;
    s16 matches;
    s16 j;
    s16 group;
    struct SplineLookupRow *cursor;
    table1 = *(struct SplineLookupTable *)lbl_1_rodata_6E38;
    fn_80008BA8(&row1, &table1.rows[(s16)index], sizeof(row1));
    table2 = *(struct SplineLookupTable *)lbl_1_rodata_6E38;
    fn_80008BA8(&row2, &table2.rows[(s16)index], sizeof(row2));
    index = (s16)index;
    ordinal = 0;
    for (;;) {
        j = 0;
        group = row2.group;
        matches = j;
        cursor = table3.rows;
        while (j < 44) {
            table3 = *(struct SplineLookupTable *)lbl_1_rodata_6E38;
            fn_80008BA8(&row3, cursor, sizeof(row3));
            if (row3.group == group) {
                if (matches == ordinal) goto found;
                matches++;
            }
            cursor++;
            j++;
        }
        j = -1;
found:
        if (index == j) break;
        ordinal++;
    }
    switch (row1.group) {
    case 0: result = (u8)(fn_1_F9DC4((u8)ordinal) != 0); break;
    case 1: {
        u32 flags = *(u32 *)((u8 *)&lbl_1_bss_7F0C0 + 0x4900);
        u32 shift = ((u8)ordinal + 17) & 31;
        result = (u8)(((flags << shift) | (flags >> (32 - shift))) & 1) != 0;
        break;
    }
    case 2: result = (u8)!fn_1_F210C(row1.value); break;
    case 3: {
        u32 flags = *(u32 *)((u8 *)&lbl_1_bss_7F0C0 + 0x4910);
        u32 shift = (32 - ((s16)ordinal * 2 + 1)) & 31;
        result = (u8)(((flags << shift) | (flags >> (32 - shift))) & 1) != 0;
        break;
    }
    }
    return result;
}
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
