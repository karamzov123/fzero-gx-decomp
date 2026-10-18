/* Numerical behavior fixture only: native C, not bitwise Gekko FMA evidence. */
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>
static float cache[104];
#define DOLPHIN_HW_REGS_H
#define LC_BASE cache
#include "mathutil_mtxA_from_quat.native.c"

static void check(const float *q) {
    double x=q[0], y=q[1], z=q[2], w=q[3];
    double expected[12] = {
        1-2*(y*y+z*z), 2*(x*y-w*z), 2*(x*z+w*y), 0,
        2*(x*y+w*z), 1-2*(x*x+z*z), 2*(y*z-w*x), 0,
        2*(x*z-w*y), 2*(y*z+w*x), 1-2*(x*x+y*y), 0
    };
    unsigned i;
    for (i=0; i<104; ++i) cache[i]=17.0f;
    cache[103]=1.0f;
    mathutil_mtxA_from_quat(q);
    for (i=0; i<12; ++i) {
        assert(isfinite(cache[i]));
        assert(fabs((double)cache[i]-expected[i]) < 0.00001);
    }
    for (i=12; i<103; ++i) assert(cache[i]==17.0f);
    assert(cache[103]==1.0f);
}

static uint32_t random_word(uint32_t *state) {
    *state ^= *state << 13;
    *state ^= *state >> 17;
    *state ^= *state << 5;
    return *state;
}

int main(void) {
    static const float axes[4][4] = {
        {0,0,0,1}, {1,0,0,0}, {0,1,0,0}, {0,0,1,0}
    };
    uint32_t seed=0x71F02B19;
    unsigned n=0, i, j;
    for (i=0; i<4; ++i) { check(axes[i]); ++n; }
    for (i=0; i<1024; ++i) {
        float q[4];
        double norm=0;
        for (j=0; j<4; ++j) {
            q[j]=(float)((int)(random_word(&seed)&2047)-1024)/1024.0f;
            norm+=(double)q[j]*q[j];
        }
        assert(norm>0);
        norm=sqrt(norm);
        for (j=0; j<4; ++j) q[j]=(float)(q[j]/norm);
        check(q);
        ++n;
    }
    printf("PASS: %u normalized quaternion cases; all matrix elements, zero translations, and cache guards\n", n);
    return 0;
}
