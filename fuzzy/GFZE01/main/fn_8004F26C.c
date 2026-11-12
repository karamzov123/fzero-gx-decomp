/* Non-matching: best partial attempt (99.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
/* WARNING: compiler-diff device, not original code: file-wide; without it the copy
 * `older_right = mix` and the register roles of the stack parameters change (26 -> 73 words). */
#pragma opt_propagation off
#include "types.h"

extern const int lbl_800911E0[16];

#define CLAMP_SAMPLE(x)                 \
    if ((x) > 32767 || (x) < -32768) {  \
        if ((x) < -32768) {             \
            (x) = -32768;               \
        } else if ((x) > 32767) {       \
            (x) = 32767;                \
        }                               \
    }

/* WARNING: compiler-diff device, not original code: keeps the dead address compares at the end of
 * fn_8004F26C alive until register allocation (see there). */
#pragma opt_dead_assignments off
int fn_8004F26C(const signed char *input, int num_samples, short *output_left,
                short delay_left[2], short *output_right, short delay_right[2],
                short coefficient0, short coefficient1, short *random_state,
                short random_multiplier, short random_increment) {
    int block;
    int blocks;
    int c1;
    short multiplier;
    short *state;
    int older_left;
    int older_right;
    int previous_right;
    int previous_left;
    short increment;
    int packed_left;
    int packed_right;
    short gain_left;
    short gain_right;
    short code;
    int escaped;
    int i;
    int mix;

    /* WARNING: compiler-diff device, not original code: the address compares below make the stack-passed
     * parameters address-taken, so they are copied into locals; the copies keep their loads in the entry
     * block. The honest form uses random_state, random_multiplier and random_increment directly. */
    blocks = num_samples / 2;
    c1 = coefficient1;
    state = random_state;
    multiplier = random_multiplier;
    increment = random_increment;
    previous_left = delay_left[0];
    older_left = delay_left[1];
    previous_right = delay_right[0];
    older_right = delay_right[1];
    for (block = 0; block < blocks; block++) {
        code = *(const short *)input;
        if (code & 0x8000) return block * 2;
        gain_left = ((code ^ *state) & 0x1fff) + 1;
        *state = increment + *state * multiplier;
        *state &= 0x7fff;
        code = *(const short *)(input + 18);
        if (code & 0x8000) return block * 2;
        gain_right = ((code ^ *state) & 0x1fff) + 1;
        *state = increment + *state * multiplier;
        *state &= 0x7fff;
        input += 2;
        for (i = 0; i < 16; i++) {
            packed_left = input[0];
            packed_right = input[18];
            input++;
            older_left = (packed_left >> 4) * gain_left +
                ((coefficient0 * previous_left + c1 * older_left) >> 12);
            CLAMP_SAMPLE(older_left);
            mix = (packed_right >> 4) * gain_right +
                ((coefficient0 * previous_right + c1 * older_right) >> 12);
            CLAMP_SAMPLE(mix);
            older_right = mix;
            mix = (older_left + mix) * 7 / 10;
            CLAMP_SAMPLE(mix);
            output_right[0] = mix;
            packed_left = lbl_800911E0[packed_left & 15];
            output_left[0] = mix;
            packed_right = lbl_800911E0[packed_right & 15];
            previous_left = packed_left * gain_left +
                ((coefficient0 * older_left + c1 * previous_left) >> 12);
            CLAMP_SAMPLE(previous_left);
            previous_right = packed_right * gain_right +
                ((coefficient0 * older_right + c1 * previous_right) >> 12);
            CLAMP_SAMPLE(previous_right);
            mix = (previous_left + previous_right) * 7 / 10;
            CLAMP_SAMPLE(mix);
            output_right[1] = mix;
            output_right += 2;
            output_left[1] = mix;
            output_left += 2;
        }
        input += 18;
    }
    /* WARNING: compiler-diff device, not original code: dead compares of the three stack-parameter
     * addresses, kept by `#pragma opt_dead_assignments off` and deleted after register allocation, so nothing
     * of them reaches the object code. They make MWCC treat the parameter slots as escaped, so the final
     * scheduler orders the three parameter loads after the prologue's stmw, as retail does. CRI built ADX
     * with a compiler build we do not have. */
    escaped = (int)&random_state == num_samples;
    escaped = (int)&random_multiplier == num_samples;
    escaped = (int)&random_increment == num_samples;
    delay_left[0] = previous_left;
    delay_left[1] = older_left;
    delay_right[0] = previous_right;
    delay_right[1] = older_right;
    return num_samples;
}
#pragma opt_dead_assignments reset
