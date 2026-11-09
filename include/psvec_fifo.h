#ifndef PSVEC_FIFO_H
#define PSVEC_FIFO_H

#include "types.h"

/* GX FIFO upload kernels: the SDK's WriteMTXPS* and light-object copies. Kept out of psvec.h on
 * purpose: adding an inline function to an included header shifts MWCC's anonymous @N literal
 * numbering in every includer and breaks matched units' pool maps (see psvec_fill.h). Add a new
 * kernel to a new header once any unit that includes this one carries a `pool` map.
 *
 * Every pair is loaded before the first store, and each pair is written to offset 0 of the
 * write-gather port. Locals declared in load order give retail's descending f5..f0. Pass
 * `&GXWGFifo` as dest: the absolute object reuses the `lis` the header write materialized.
 *
 * Validated byte-exact 2026-11-07: GXLoadTexMtxImm (4x3, 4x2), fn_800356B8 (light object);
 * 2026-11-08: GXLoadPosMtxImm (4x3), GXLoadNrmMtxImm (3x3 from 3x4). */

/* Copies twelve f32 from mtx to the FIFO. */
static inline void WriteMTXPS4x3(const register void *mtx, register volatile void *dest) {
    register f32 a, b, c, d, e, f;
    asm {
        psq_l a, 0(mtx), 0, 0
        psq_l b, 8(mtx), 0, 0
        psq_l c, 16(mtx), 0, 0
        psq_l d, 24(mtx), 0, 0
        psq_l e, 32(mtx), 0, 0
        psq_l f, 40(mtx), 0, 0
        psq_st a, 0(dest), 0, 0
        psq_st b, 0(dest), 0, 0
        psq_st c, 0(dest), 0, 0
        psq_st d, 0(dest), 0, 0
        psq_st e, 0(dest), 0, 0
        psq_st f, 0(dest), 0, 0
    }
}

/* Copies eight f32 from mtx to the FIFO. */
static inline void WriteMTXPS4x2(const register void *mtx, register volatile void *dest) {
    register f32 a, b, c, d;
    asm {
        psq_l a, 0(mtx), 0, 0
        psq_l b, 8(mtx), 0, 0
        psq_l c, 16(mtx), 0, 0
        psq_l d, 24(mtx), 0, 0
        psq_st a, 0(dest), 0, 0
        psq_st b, 0(dest), 0, 0
        psq_st c, 0(dest), 0, 0
        psq_st d, 0(dest), 0, 0
    }
}

/* Copies the 3x3 normal part of a 3x4 matrix (columns 0..2 of each row) to the FIFO:
 * a pair and a single per row (GXLoadNrmMtxImm). */
static inline void WriteMTXPS3x3from3x4(const register void *mtx, register volatile void *dest) {
    register f32 a, b, c, d, e, f;
    asm {
        psq_l a, 0(mtx), 0, 0
        lfs b, 8(mtx)
        psq_l c, 16(mtx), 0, 0
        lfs d, 24(mtx)
        psq_l e, 32(mtx), 0, 0
        lfs f, 40(mtx)
        psq_st a, 0(dest), 0, 0
        stfs b, 0(dest)
        psq_st c, 0(dest), 0, 0
        stfs d, 0(dest)
        psq_st e, 0(dest), 0, 0
        stfs f, 0(dest)
    }
}

/* Three zero words, the color word at +0xC, then twelve f32 from +0x10 to the FIFO. */
static inline void WriteLightObjPS(const register void *src, register volatile void *dest) {
    register u32 zero, color;
    register f32 a, b, c, d, e, f;
    asm {
        lwz color, 12(src)
        xor zero, zero, zero
        psq_l a, 16(src), 0, 0
        psq_l b, 24(src), 0, 0
        psq_l c, 32(src), 0, 0
        psq_l d, 40(src), 0, 0
        psq_l e, 48(src), 0, 0
        psq_l f, 56(src), 0, 0
        stw zero, 0(dest)
        stw zero, 0(dest)
        stw zero, 0(dest)
        stw color, 0(dest)
        psq_st a, 0(dest), 0, 0
        psq_st b, 0(dest), 0, 0
        psq_st c, 0(dest), 0, 0
        psq_st d, 0(dest), 0, 0
        psq_st e, 0(dest), 0, 0
        psq_st f, 0(dest), 0, 0
    }
}

#endif  // PSVEC_FIFO_H
