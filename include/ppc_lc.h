#ifndef PPC_LC_H
#define PPC_LC_H

#include "types.h"

/* Locked-cache line zeroing (dcbz_l base, offset) as an inline-assembly helper; MWCC has
 * no intrinsic for it. Kept out of include/ppc_ops.h so that header's includers keep their
 * literal numbering. Validated 2026-11-09 on movie_module fn_12_CF2C: thirty-two iterations
 * of eight `dcbi rB, rO; dcbz_l rB, rO; addi rO, rO, 0x20` (with ppc_dcbi from ppc_ops.h). */
static inline void ppc_dcbz_l(register void *base, register s32 offset) {
    asm { dcbz_l base, offset }
}

#endif  // PPC_LC_H
