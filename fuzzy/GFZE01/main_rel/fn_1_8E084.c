/* Non-matching: best partial attempt (98.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad_38c[0x38c];
    u8 flags;
    u8 pad_38d[0x2d];
    s16 state;
} Car;

extern u8 lbl_1_bss_6E82C[300];

#pragma opt_dead_assignments off
#pragma opt_lifetimes off
void fn_1_8E084(Car *car, s32 *value, s32 index) {
    s8 old_state = (s8)car->state;
    s32 n = old_state + 1;
    s8 state = (s8)n;

    while (1) {
        if (state != 5)
            break;

        if ((s8)n < 0 || state > 5) {
            state = ((s8)n < 0) ? 0 : (((s8)n > 5) ? 5 : (s8)n);
            goto store;
        }

        while (state < 5) {
            switch (car->flags & (1 << state)) {
            case 0:
                state++;
                break;
            default:
                goto store;
        }
        }
        state = -1;
        goto store;
    }

store:
    car->state = state;
    if (car->state == -1) {
        car->state = 5;
        *value = *value - *(u16 *)(lbl_1_bss_6E82C + index * 10 + old_state * 2);
    } else {
        *value = *value - *(u16 *)(lbl_1_bss_6E82C + index * 10 + ((2) * (old_state)))
                       + *(u16 *)(lbl_1_bss_6E82C + index * 10 + car->state * 2);
    }
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset
