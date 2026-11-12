#ifndef PSVEC_MADD_H
#define PSVEC_MADD_H

#include "types.h"

/* acc += v * s, in place: the paired-single multiply-add of psvec_scale_add with the accumulator as its own
 * destination. One pointer parameter fewer than psvec_scale_add(acc, v, s, acc) means one argument copy fewer
 * in the inlined code; the emitted kernel is the same (fn_1_105CC8). */
static inline void psvec_madd(register void *acc, const register void *v, register f32 s) {
    register f32 axy, vxy, az, vz;
    asm {
        psq_l axy, 0(acc), 0, 0
        psq_l vxy, 0(v), 0, 0
        lfs az, 8(acc)
        lfs vz, 8(v)
        ps_madds0 axy, vxy, s, axy
        fmadds az, vz, s, az
        psq_st axy, 0(acc), 0, 0
        stfs az, 8(acc)
    }
}

#endif
