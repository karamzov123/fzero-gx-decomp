#ifndef PPC_OPS_H
#define PPC_OPS_H

#include "types.h"

/* Single-instruction PowerPC operations MWCC has no intrinsic for, as inline-asm helpers
 * inlined into the caller (the compiler allocates their registers, like include/psvec.h).
 * Kept in their own header: an inline function added to a widely included header shifts
 * MWCC's anonymous literal numbering in every includer (see include/psvec_fill.h).
 * Hand-owned (librarian).
 *
 * MWCC 1.3.2 treats `__dcbi` as an ordinary external call, and intrinsics.h /
 * ppc_intrinsics.h are not available to the project. */

/* dcbi base, offset. Validated 2026-11-04 (probe compile, GC/1.3.2 -O4,p): retail movie_module
 * fn_12_D038's thirteen-iteration loop of seven `dcbi r4, r3; addi r3, r3, 0x20` is reproduced
 * instruction for instruction by `off += 0x20` around seven calls per iteration. */
static inline void ppc_dcbi(register void *base, register s32 offset) {
    asm { dcbi base, offset }
}

/* The 64-bit time base read with the upper-word retry (mftbu, mftb, mftbu, cmpw, bne), the
 * SDK's OSGetTime inlined. Validated 2026-11-04: retail movie_module fn_12_335B8
 * (`if (lbl_12_bss_1B778 == 1) return 0; return ppc_get_time_base();`, returning s64) is
 * reproduced byte for byte, hi in r3 and lo in r4. */
static inline s64 ppc_get_time_base(void) {
    register u32 hi, lo, check;
    asm {
    retry:
        mftbu hi
        mftb lo
        mftbu check
        cmpw check, hi
        bne retry
    }
    return ((s64)hi << 32) | lo;
}

#endif  // PPC_OPS_H
