/* Non-matching: best partial attempt (97.30% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 *fn_1_36AD0(void);
extern u32 fn_1_151BE8(s16, s16);

struct fn_1_12B4EC_row {
    u8 pad_0[0x81A4];
    u8 unk_81A4;
    u32 unk_81A8;
};

#pragma opt_loop_invariants off
void fn_1_12B4EC(s16 arg0, s16 arg1) {
    s16 i;
    u8 *base = fn_1_36AD0();
    struct fn_1_12B4EC_row *row = (struct fn_1_12B4EC_row *)((u8 *)base + arg0 * 0x81C0);
    u8 idx;
    s16 j;
    idx = (u8)(arg1 % 4);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            ((struct fn_1_12B4EC_row *)((u8 *)row + j * 4))->unk_81A8 = fn_1_151BE8(row->unk_81A4, idx + j);
        }
        row = (struct fn_1_12B4EC_row *)((u8 *)row + 8);
    }
}
#pragma opt_loop_invariants reset

