/* Non-matching: best partial attempt (98.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 fn_1_8D5F0(s16 value);
extern s32 fn_1_F7EDC(s16 value);
extern s32 fn_1_F7BE4(s16 value);

typedef struct {
    s16 id;
    u8 pad[2];
    u32 flags;
} Cell;

void fn_1_152510(s16 *ids, s16 id_count, Cell *table, s16 rows, s16 cols) {
    s16 i;
    s16 j;
    s16 k;
    s16 n;
    s16 row;
    s16 col;
    s32 found;

    found = 0;
    for (i = 0; i < 41; i++) {
        if ((fn_1_8D5F0(i) & 0x10000000) && (fn_1_F7EDC(i) != 0)) {
            found = 1;
            break;
        }
    }

    for (j = 0; j < rows; j++) {
        for (k = 0; k < cols; k++) {
            table[(j * cols) + k].flags |= 0x40000000;
            table[(j * cols) + k].id = -1;
        }
    }

    for (n = 0; n < id_count; n++) {
        if (ids[n] == -1) {
            continue;
        }
        row = n / cols;
        col = n % cols;
        table[(row * cols) + col].id = ids[n];
        table[(row * cols) + col].flags = 0;
        if (found == 1) {
            table[(row * cols) + col].flags |= 0x80000000;
        } else if ((fn_1_8D5F0(table[(row * cols) + col].id) & 0x10000000) != 0) {
            table[(row * cols) + col].flags |= 0x40000000;
        } else {
            table[(row * cols) + col].flags |= 0x80000000;
        }
        if (fn_1_F7EDC(table[(row * cols) + col].id) != 0) {
            table[(row * cols) + col].flags &= 0x3FFFFFFF;
        }
        if (fn_1_F7BE4(table[(row * cols) + col].id) != 0) {
            table[(row * cols) + col].flags &= 0x3FFFFFFF;
            table[(row * cols) + col].flags |= 0x08000000;
        }
    }
}
