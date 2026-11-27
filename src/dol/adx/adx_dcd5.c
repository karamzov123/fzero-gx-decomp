#include "types.h"
#include "adx_compiler_diff.h"

extern int lbl_8017B028;
extern const int lbl_800911E0[16];

#define CLAMP_SAMPLE(x)                 \
    if (x > 32767 || x < -32768) {  \
        if (x < -32768) {             \
            x = -32768;               \
        } else if (x > 32767) {       \
            x = 32767;                \
        }                               \
    }

/* Two-tap history prediction, converted from the coefficients' twelve fractional bits. */
static inline int PredictSample(int c0, int c1, int high, int previous) {
    int value = c0 * high;
    value += c1 * previous;
    return value >> 12;
}

int fn_8004F00C(const signed char *input, int num_samples, short *output_left,
                short delay_left[2], short *output_right, short delay_right[2],
                short coefficient0, short coefficient1, short *random_state,
                short random_multiplier, short random_increment);
int fn_8004F26C(const signed char *input, int num_samples, short *output_left,
                short delay_left[2], short *output_right, short delay_right[2],
                short coefficient0, register short coefficient1, short *random_state,
                short random_multiplier, short random_increment);

/* WARNING: compiler-diff device, not original code: keeps the dead address compares at the end of
 * fn_8004EFA8 alive until register allocation (see there). The body is exact with the pragma on; whether it has other dead assignments that the pragma also keeps was not checked. */
#pragma opt_dead_assignments off
int fn_8004EFA8(const signed char *input, int num_samples, short *output_l, short delay_l[2],
                short *output_r, short delay_r[2], short coefficient0, short coefficient1,
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

/* WARNING: compiler-diff device, not original code: keeps the dead address compares at the end of
 * fn_8004F00C alive until register allocation (see there). */
#pragma opt_dead_assignments off
int fn_8004F00C(const signed char *input, int num_samples, short *output_left,
                short delay_left[2], short *output_right, short delay_right[2],
                short coefficient0, short coefficient1, short *random_state,
                short random_multiplier, short random_increment) {
    int multiplier;
    short *state;
    short increment;
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
    int escaped;

    /* WARNING: compiler-diff device, not original code: the three stack-passed parameters are copied into
     * locals because the address compares below make the parameters themselves address-taken; the copies
     * keep the three loads in the entry block. The honest form uses random_state, random_multiplier and
     * random_increment directly. */
    state = random_state;
    c1 = coefficient1;
    c0 = coefficient0;
    multiplier = random_multiplier;
    increment = random_increment;
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
                ((c0 * previous_left + c1 * older_left) >> 12);
            CLAMP_SAMPLE(older_left);
            decoded_right = (packed_right >> 4) * gain_right;
            decoded_right += (c0 * previous_right + c1 * older_right) >> 12;
            CLAMP_SAMPLE(decoded_right);
            output_left[0] = older_left;
            low_left = lbl_800911E0[packed_left & 15];
            output_right[0] = decoded_right;
            low_right = lbl_800911E0[packed_right & 15];
            previous_left = low_left * gain_left +
                PredictSample(c0, c1, older_left, previous_left);
            CLAMP_SAMPLE(previous_left);
            previous_right = low_right * gain_right +
                PredictSample(c0, c1, decoded_right, previous_right);
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

/* WARNING: compiler-diff device, not original code: keeps the dead arm in fn_8004F26C's inner loop and the
 * copies of its stack-passed parameters alive until register allocation (see there). */
#pragma opt_propagation off
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
#pragma opt_propagation reset

/* WARNING: compiler-diff device, not original code: keeps the dead address compare at the end of
 * fn_8004F55C alive until register allocation (see there). The body is exact with the pragma on; whether it has other dead assignments that the pragma also keeps was not checked. */
#pragma opt_dead_assignments off
int fn_8004F55C(const signed char *input, int num_blocks, short *output, short delay[2],
                short coefficient0, short coefficient1, short *random_state,
                short random_multiplier, short random_increment) {
    int block;
    int i;
    int older;
    int previous;
    short gain;
    int increment;
    int escaped;

    /* WARNING: compiler-diff device, not original code: random_increment is copied into a local because
     * the address compare below makes the parameter itself address-taken; the copy keeps its load in the
     * entry block. gain is declared here, before the copy, rather than in the block loop, so that MWCC
     * numbers gain above the copy and colours them r31/r30 as retail does. The honest form uses
     * random_increment directly and declares gain in the block loop. Measured 2026-11-26: the honest form
     * (no copy, gain in the loop, no pragma, no compare) is 8 diff lines, all from the random_increment
     * load scheduled ahead of the table address (lha 42(r1) before addi/li); the same under GC/1.3.2r,
     * 2.0, 2.5 and 2.6, 32 under 1.3, 210 under 1.2.5n. A plain local copy, the operands swapped or the
     * delay loads swapped give 8-12. */
    increment = random_increment;
    previous = delay[0];
    older = delay[1];
    for (block = 0; block < num_blocks; block++) {
        short code = *(const short *)input;

        if (code & 0x8000) return block;
        gain = ((code ^ *random_state) & 0x1fff) + 1;
        *random_state = increment + *random_state * random_multiplier;
        *random_state &= 0x7fff;
        input += 2;
        for (i = 0; i < 16; i++) {
            int packed = *input;
            int decoded;

            input++;
            decoded = (packed >> 4) * gain +
                ((coefficient0 * previous + coefficient1 * older) >> 12);
            CLAMP_SAMPLE(decoded);
            output[0] = decoded;
            packed = lbl_800911E0[packed & 15];
            previous = packed * gain +
                ((coefficient0 * decoded + coefficient1 * previous) >> 12);
            CLAMP_SAMPLE(previous);
            output[1] = previous;
            older = decoded;
            output += 2;
        }
    }
    /* WARNING: compiler-diff device, not original code: a dead compare of the stack parameter's address,
     * kept by `#pragma opt_dead_assignments off` and deleted after register allocation, so nothing of it
     * reaches the object code. A compare of a parameter's address makes MWCC count that stack slot as
     * escaped (worst-case alias), so the final scheduler orders the random_increment load after the
     * prologue's stmw, as retail does. CRI built ADX with a compiler build we do not have, whose loads
     * carry that dependence without help. */
    escaped = (int)&random_increment == num_blocks;
    delay[0] = previous;
    delay[1] = older;
    return num_blocks;
}
#pragma opt_dead_assignments reset
