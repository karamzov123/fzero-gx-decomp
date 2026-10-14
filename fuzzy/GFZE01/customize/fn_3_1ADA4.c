/* Non-matching: best partial attempt (89.74% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/toolkit.h"

extern void fn_3_15240(void *, s32, s16, u16, s32, s16);

#pragma opt_lifetimes off
#pragma opt_common_subs on
#pragma opt_dead_assignments off
void fn_3_1ADA4(void *data, s32 first_a, s32 second_a, s32 first_b, u32 second_b, u32 lab_unused0, u32 lab_unused1) {
    s32 half;
    u32 width;
    s32 count;
    s16 limit;
    s16 current;
    s16 end;

{
    s32 fzgx_loop_count_572;
    s16 fzgx_loop_limit_572;
    current = (s16)second_a;
    end = (s16)second_b;
    half = (end - current) / 2;
    fzgx_loop_count_572 = 0;
    width = (s16)first_b - (s16)first_a;
    fzgx_loop_limit_572 = half;
    while ((s16)fzgx_loop_count_572 < fzgx_loop_limit_572) {
        fn_3_15240(data, first_a, (s16)current, (u16)width, first_a, (s16)(end - fzgx_loop_count_572 - 1));
        current++;
        fzgx_loop_count_572++;
    }
    count = fzgx_loop_count_572;
    limit = fzgx_loop_limit_572;
}
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

#pragma opt_lifetimes reset

