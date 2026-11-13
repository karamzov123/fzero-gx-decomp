/* WARNING: compiler-diff device, not original code: retained for the remaining identity-helper and
 * stack-parameter allocation devices below. The prediction no longer uses a copy-only local. */
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

/* WARNING: compiler-diff device, not original code: a value returned through this helper's local is its own
 * register object numbered above MWCC's CSE temporaries, so it is coloured before them. Used for the
 * increment copy of fn_8004F00C (see there). */
static inline short compiler_diff_keep(short x) {
    short kept = x;
    return kept;
}

/* Two-tap history prediction, converted from the coefficients' twelve fractional bits. */
static inline int PredictSample(short c0, short c1, int high, int previous) {
    int value = c0 * high;
    value += c1 * previous;
    return value >> 12;
}

/* WARNING: compiler-diff device, not original code: keeps the dead address compares at the end of
 * fn_8004F00C alive until register allocation (see there). */
#pragma opt_dead_assignments off
int fn_8004F00C(const signed char *input, int num_samples, short *output_left,
                short delay_left[2], short *output_right, short delay_right[2],
                short coefficient0, short coefficient1, short *random_state,
                short random_multiplier, short random_increment) {
    short multiplier;
    short *state;
    short increment;
    int older_left;
    int older_right;
    int previous_right;
    int previous_left;
    int block;
    int packed_left;
    int packed_right;
    short gain_left;
    short gain_right;
    int i;
    int escaped;

    /* WARNING: compiler-diff device, not original code: the three stack-passed parameters are copied into
     * locals because the address compares below make the parameters themselves address-taken; the copies
     * keep the three loads in the entry block. increment goes through compiler_diff_keep so that increment
     * is coloured r0 and multiplier r11 as in retail. The honest form uses random_state, random_multiplier
     * and random_increment directly. */
    state = random_state;
    multiplier = random_multiplier;
    increment = compiler_diff_keep(random_increment);
    previous_left = delay_left[0];
    older_left = delay_left[1];
    previous_right = delay_right[0];
    older_right = delay_right[1];
    for (block = 0; block < num_samples / 2; block++) {
        short code;

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
            int decoded_right;
            int low_left;
            int low_right;

            packed_left = input[0];
            packed_right = input[18];
            input++;
            older_left = (packed_left >> 4) * gain_left +
                ((coefficient0 * previous_left + coefficient1 * older_left) >> 12);
            CLAMP_SAMPLE(older_left);
            decoded_right = (packed_right >> 4) * gain_right;
            decoded_right += (coefficient0 * previous_right + coefficient1 * older_right) >> 12;
            CLAMP_SAMPLE(decoded_right);
            output_left[0] = older_left;
            low_left = lbl_800911E0[packed_left & 15];
            output_right[0] = decoded_right;
            low_right = lbl_800911E0[packed_right & 15];
            previous_left = low_left * gain_left +
                PredictSample(coefficient0, coefficient1, older_left, previous_left);
            CLAMP_SAMPLE(previous_left);
            previous_right = low_right * gain_right +
                PredictSample(coefficient0, coefficient1, decoded_right, previous_right);
            CLAMP_SAMPLE(previous_right);
            output_left[1] = previous_left;
            older_right = decoded_right;
            output_left += 2;
            output_right[1] = previous_right;
            output_right += 2;
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
