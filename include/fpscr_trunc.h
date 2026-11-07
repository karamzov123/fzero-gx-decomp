#ifndef FPSCR_TRUNC_H
#define FPSCR_TRUNC_H

#include "types.h"

/* Truncate to integer through a stack word pair (recovered 2026-11-07, fn_1_144F40).
 *
 * Retail's fractional-part code `x - (f32)trunc(x)` (main_rel sel_static_disp fn_1_144F40,
 * and the same shape in fn_1_139440) converts with fctiwz but homes the result in a
 * 4-byte-aligned 8-byte slot among the declared locals (fn_1_144F40: stfd f0, 0xc(r1);
 * lwz r5, 0x10(r1), below the 0x58-byte packet local), not in MWCC's 8-aligned conversion
 * temp area above the locals. Those are the only two 4-aligned fctiwz homes in the
 * whole game. A plain (s32) cast, block locals, struct/array carriers, out-parameters and
 * __fctiwz (a call, not an intrinsic) all keep the temp in the temp area, so the sequence
 * can come only from inline assembly inlined into the caller, like fpscr_floor: the
 * compiler then allocates the registers and schedules it with the surrounding code.
 *
 * As in fpscr_floor, the stack word pair is an s32 array, not a double: retail homes it
 * at 4-byte alignment. Each inline site gets its own home. */
static inline s32 fpscr_trunc(register f32 x) {
    register f64 t;
    s32 w[2];
    asm {
        fctiwz t, x
        stfd t, w
    }
    return w[1];
}

#endif
