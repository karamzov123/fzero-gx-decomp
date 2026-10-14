/* Non-matching: best partial attempt (98.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern s8 lbl_1_rodata_82B4[132];

struct Table {
    s16 values[66];
};

u32 fn_1_12EF80(s16 value, s16 *row, s16 *column, u32 lab_unused0, u32 lab_unused1) {
    struct Table table = *(struct Table *)lbl_1_rodata_82B4;
    s16 i;
    s16 *p;
    struct { s16 value; } j;

    i = 0;
    (void) i;  /* fzgx: keeps the web at its definition */
    row[0] = -1;
    column[0] = -1;
    for (; i < 11; i++) {
        p = &table.values[i * 6];
        for (j.value = 0; j.value < 6; j.value++) {
            if ((((((s32)value)) == ((*p))))) {
                row[0] = i;
                column[0] = j.value;
                return (u32)p;
            }
            p++;
        }
    }
    return (u32)p;
}
