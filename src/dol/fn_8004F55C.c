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
     * random_increment directly and declares gain in the block loop. */
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
