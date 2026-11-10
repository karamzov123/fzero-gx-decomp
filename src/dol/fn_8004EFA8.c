#include "types.h"

extern int lbl_8017B028;

int fn_8004F00C();
int fn_8004F26C();

/* WARNING: compiler-diff device, not original code: keeps the dead address compares at the end of
 * fn_8004EFA8 alive until register allocation (see there). The body is exact with the pragma on; whether it has other dead assignments that the pragma also keeps was not checked. */
#pragma opt_dead_assignments off
int fn_8004EFA8(const signed char *input, int num_samples, short *output_l, short delay_l[2],
                short *output_r, short delay_r[2], int coefficient0, int coefficient1,
                short *random_state, short random_multiplier, short random_increment) {
    int result;
    int escaped;
    short increment;
    short multiplier;
    short *state;

    /* WARNING: compiler-diff device, not original code: the three stack-passed parameters are copied
     * into locals (declared in this order) because the address compares below make the parameters
     * themselves address-taken; the copies keep the three loads in the entry block with retail's
     * registers. The honest form passes random_state, random_multiplier and random_increment directly. */
    state = random_state;
    multiplier = random_multiplier;
    increment = random_increment;
    if (lbl_8017B028 == 0) {
        result = fn_8004F00C(input, num_samples, output_l, delay_l, output_r, delay_r,
                             coefficient0, coefficient1, state, multiplier, increment);
    } else {
        result = fn_8004F26C(input, num_samples, output_l, delay_l, output_r, delay_r,
                             coefficient0, coefficient1, state, multiplier, increment);
    }
    /* WARNING: compiler-diff device, not original code: dead compares of the three stack-parameter
     * addresses, kept by `#pragma opt_dead_assignments off` and deleted after register allocation, so
     * nothing of them reaches the object code. A compare of a parameter's address makes MWCC count that
     * stack slot as escaped (worst-case alias), so the final scheduler orders the parameter loads after
     * the prologue's `stw r31`, as retail does. CRI built ADX with a compiler build we do not have,
     * whose loads carry that dependence without help. */
    escaped = (int)&random_state == result;
    escaped = (int)&random_multiplier == result;
    escaped = (int)&random_increment == result;
    return result;
}
#pragma opt_dead_assignments reset
