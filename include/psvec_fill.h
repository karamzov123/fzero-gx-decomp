#ifndef PSVEC_FILL_H
#define PSVEC_FILL_H

#include "types.h"

/* Paired-single fill kernel, kept out of psvec.h on purpose: adding any inline function to a
 * header shifts MWCC's anonymous literal numbering (@N) in every unit that includes it, and
 * the pool maps of matched units (units.json `pool`, e.g. live_camera fn_1_EBE4 @44) are keyed
 * by those numbers (measured 2026-10-27: adding this function to psvec.h failed 9 pool units).
 * Hand-owned (librarian).
 *
 * dst[0..11] = v: four 12-byte vectors (0x30 bytes) from one scalar FPR, six paired
 * displacement stores, no merge and no stfs (an lfs fills both lanes). v stays live and
 * usable afterwards: retail fn_1_4EDAC (main_rel font.c) does `lfs f31, 0x58(r30)`, the six
 * `psq_st f31, 0x0..0x28(r29), 0, qr0`, then passes f31 on as `ps_mr f1/f3/f5, f31`.
 * Validated 2026-10-27: fn_1_4EDAC's saved body (96.97%) with its four psvec_set calls replaced
 * by one psvec_fill4 scores 99.49%, the fill and ps_mr rows exact. */
static inline void psvec_fill4(register void *dst, register f32 v) {
    asm {
        psq_st v, 0(dst), 0, 0
        psq_st v, 8(dst), 0, 0
        psq_st v, 16(dst), 0, 0
        psq_st v, 24(dst), 0, 0
        psq_st v, 32(dst), 0, 0
        psq_st v, 40(dst), 0, 0
    }
}

#endif  // PSVEC_FILL_H
