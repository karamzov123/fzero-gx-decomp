/* Imported from deltawave784/fzgx@13b0aeca (CC0): include/dolphin/os/OSFastCast.h. */
#ifndef DOLPHIN_OS_OSFASTCAST_H
#define DOLPHIN_OS_OSFASTCAST_H

#include "dolphin/types.h"

/* Dolphin SDK fast float/integer casts through the paired-single quantizers (OSFastCast.h).
 * OSInitFastCast loads GQR2..GQR5 with the u8/u16/s8/s16 formats; a cast is one quantized
 * psq_st (or psq_l) of a single lane through a stack temporary, then an integer load.
 * Retail fn_1_60D54 (main_rel effect.c): `psq_st f31, 0x10(r1), 1, qr2; lbz r0, 0x10(r1)` per
 * colour byte, one 4-byte stack slot per site.
 * The temporary is the SDK's `f32 tmp` for every width (fn_1_65748: three __OSf32tou8 sites get
 * slots 0x10/0xc/0x8; a u8 temporary packs them into 1-byte slots and shifts every later offset).
 * The pointer form is the SDK's: MWCC folds `0(ptr)` with ptr = &tmp into an r1 displacement
 * (probe, GC/1.3.2 -O4,p: `psq_st f0, 0x8(r1), 1, qr2; lbz r0, 0x8(r1)`); `tmp` alone as the
 * operand is rejected (illegal object reference). Units cannot carry inline assembly: include this header.
 * Hand-owned (librarian). */

#define OS_GQR_F32 0x0000
#define OS_GQR_U8 0x0004
#define OS_GQR_U16 0x0005
#define OS_GQR_S8 0x0006
#define OS_GQR_S16 0x0007

#define OS_FASTCAST_U8 2
#define OS_FASTCAST_U16 3
#define OS_FASTCAST_S8 4
#define OS_FASTCAST_S16 5

static inline u8 __OSf32tou8(register f32 inF) {
    f32 tmp;
    register f32 *ptr = &tmp;
    asm {
        psq_st inF, 0(ptr), 1, OS_FASTCAST_U8
    }
    return *(u8 *)ptr;
}

static inline u16 __OSf32tou16(register f32 inF) {
    f32 tmp;
    register f32 *ptr = &tmp;
    asm {
        psq_st inF, 0(ptr), 1, OS_FASTCAST_U16
    }
    return *(u16 *)ptr;
}

static inline s8 __OSf32tos8(register f32 inF) {
    f32 tmp;
    register f32 *ptr = &tmp;
    asm {
        psq_st inF, 0(ptr), 1, OS_FASTCAST_S8
    }
    return *(s8 *)ptr;
}

static inline s16 __OSf32tos16(register f32 inF) {
    f32 tmp;
    register f32 *ptr = &tmp;
    asm {
        psq_st inF, 0(ptr), 1, OS_FASTCAST_S16
    }
    return *(s16 *)ptr;
}

static inline f32 __OSu8tof32(register u8 *in) {
    register f32 r;
    asm {
        psq_l r, 0(in), 1, OS_FASTCAST_U8
    }
    return r;
}

static inline f32 __OSu16tof32(register u16 *in) {
    register f32 r;
    asm {
        psq_l r, 0(in), 1, OS_FASTCAST_U16
    }
    return r;
}

static inline f32 __OSs8tof32(register s8 *in) {
    register f32 r;
    asm {
        psq_l r, 0(in), 1, OS_FASTCAST_S8
    }
    return r;
}

static inline f32 __OSs16tof32(register s16 *in) {
    register f32 r;
    asm {
        psq_l r, 0(in), 1, OS_FASTCAST_S16
    }
    return r;
}

#endif  // DOLPHIN_OS_OSFASTCAST_H
