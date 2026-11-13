/* WARNING: compiler-diff device, not original code: keeps the dead arm in fn_8004F26C's inner loop and the
 * copies of its stack-passed parameters alive until register allocation (see there). */
#pragma opt_propagation off
#include "types.h"
#include "adx_compiler_diff.h"

extern const int lbl_800911E0[16];

#define CLAMP_SAMPLE(x)                 \
    if ((x) > 32767 || (x) < -32768) {  \
        if ((x) < -32768) {             \
            (x) = -32768;               \
        } else if ((x) > 32767) {       \
            (x) = 32767;                \
        }                               \
    }


/* WARNING: compiler-diff device, not original code: coefficient1 is `register` only so that it can be the
 * operand of a dead register write (see the entry block). The honest declaration is `short coefficient1`. */
int fn_8004F26C(const signed char *input, int num_samples, short *output_left,
                short delay_left[2], short *output_right, short delay_right[2],
                short coefficient0, register short coefficient1, short *random_state,
                short random_multiplier, short random_increment) {
    int multiplier;
    short *state;
    register short increment;
    int c0;
    int c1;
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
    register int num_blocks;
    register int dead_sum;
    register void *escaped_address;

    num_blocks = num_samples / 2;
    /* WARNING: compiler-diff device, not original code: the three stack-passed parameters are copied into
     * locals because the dead writes below make the parameters themselves address-taken; the copies keep
     * the three loads in the entry block. The honest form uses random_state, random_multiplier and
     * random_increment directly. */
    state = random_state;
    c1 = coefficient1;
    c0 = coefficient0;
    multiplier = random_multiplier;
    increment = random_increment;
    /* WARNING: compiler-diff device, not original code: dead writes of the three stack-parameter addresses
     * (ADX_COMPILER_DIFF_DEAD_WRITE, adx_compiler_diff.h); nothing of them reaches the object code. They make
     * MWCC treat the parameter slots as escaped, so the final scheduler orders the three parameter loads
     * after the prologue's stmw, as retail does. */
    escaped_address = &random_state;
    ADX_COMPILER_DIFF_DEAD_WRITE(escaped_address);
    escaped_address = &random_multiplier;
    ADX_COMPILER_DIFF_DEAD_WRITE(escaped_address);
    escaped_address = &random_increment;
    ADX_COMPILER_DIFF_DEAD_WRITE(escaped_address);
    /* WARNING: compiler-diff device, not original code: dead_sum and the four dead writes are dead readers
     * of entry-block values; nothing of them reaches the object code. They make the first scheduling issue
     * the state, multiplier and increment loads before the `srawi` of num_samples / 2 and the four delay
     * loads after it, which is retail's colouring: the `add` temporary of the division is r12 (it no longer
     * overlaps older_left), the 0x66666667 high half is r20 and the table's is r21. The coefficient1 write
     * keeps that parameter's entry copy until register allocation. Without them the function is 10 rows
     * off, all in the entry block. */
    dead_sum = (int)state + multiplier;
    ADX_COMPILER_DIFF_DEAD_WRITE(dead_sum);
    ADX_COMPILER_DIFF_DEAD_WRITE(num_blocks);
    ADX_COMPILER_DIFF_DEAD_WRITE(increment);
    ADX_COMPILER_DIFF_DEAD_WRITE(coefficient1);
    previous_left = delay_left[0];
    older_left = delay_left[1];
    previous_right = delay_right[0];
    older_right = delay_right[1];
    for (block = 0; block < num_blocks; block++) {
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
            int mixed;
            int product;
            int sum;
            int shifted;
            int zero;

            packed_left = input[0];
            packed_right = input[18];
            input++;
            older_left = (packed_left >> 4) * gain_left +
                ((c0 * previous_left + c1 * older_left) >> 12);
            CLAMP_SAMPLE(older_left);
            decoded_right = (packed_right >> 4) * gain_right +
                ((c0 * previous_right + c1 * older_right) >> 12);
            CLAMP_SAMPLE(decoded_right);
            older_right = decoded_right;
            mixed = (older_left + decoded_right) * 7 / 10;
            CLAMP_SAMPLE(mixed);
            output_right[0] = mixed;
            output_left[0] = mixed;
            low_left = lbl_800911E0[packed_left & 15];
            low_right = lbl_800911E0[packed_right & 15];
            /* WARNING: compiler-diff device, not original code: the left prediction is split into the locals
             * product/sum/shifted, and the clamp carries a dead arm (`zero` is always 0) that redefines
             * older_right and older_left. With `#pragma opt_propagation off` the arm survives to register
             * allocation and is folded afterwards, so it emits nothing; it only lengthens shifted's and sum's
             * live ranges, which gives retail's colour order in the inner loop. Technique (not code) taken
             * from the RE4 decomp's ADX_DecodeSte4AsMono (adonis-singh/re4, src/lib/adx_dcd5.c). The honest
             * form is `previous_left = low_left * gain_left + ((coefficient0 * older_left + coefficient1 *
             * previous_left) >> 12); CLAMP_SAMPLE(previous_left);`. */
            product = low_left * gain_left;
            sum = c0 * older_left + c1 * previous_left;
            shifted = sum >> 12;
            previous_left = product + shifted;
            if (previous_left > 32767 || previous_left < -32768) {
                if (previous_left < -32768) {
                    previous_left = -32768;
                } else if (previous_left > 32767) {
                    previous_left = 32767;
                }
                zero = 0;
                if (zero != 0) {
                    older_right = shifted + 1;
                    older_left = sum;
                }
            }

            previous_right = low_right * gain_right +
                ((c0 * older_right + c1 * previous_right) >> 12);
            CLAMP_SAMPLE(previous_right);
            mixed = (previous_left + previous_right) * 7 / 10;
            CLAMP_SAMPLE(mixed);
            output_right[1] = mixed;
            output_left[1] = mixed;
            output_left += 2;
            output_right += 2;
        }
        input += 18;
    }
    delay_left[0] = previous_left;
    delay_left[1] = older_left;
    delay_right[0] = previous_right;
    delay_right[1] = older_right;
    return num_samples;
}
