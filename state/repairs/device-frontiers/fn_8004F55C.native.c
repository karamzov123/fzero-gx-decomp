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

/* Unaccepted natural-C frontier: three positional words differ in the prologue.
 * See ../sel-natural-accesses.md. Do not install this as a matching unit. */
int fn_8004F55C(const signed char *input, int num_blocks, short *output, short delay[2],
                short coefficient0, short coefficient1, short *random_state,
                short random_multiplier, short random_increment) {
    int block;
    int i;
    int older;
    int previous;

    previous = delay[0];
    older = delay[1];
    for (block = 0; block < num_blocks; block++) {
        short code = *(const short *)input;
        short gain;

        if (code & 0x8000) return block;
        gain = ((code ^ *random_state) & 0x1fff) + 1;
        *random_state = random_increment + *random_state * random_multiplier;
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
    delay[0] = previous;
    delay[1] = older;
    return num_blocks;
}
