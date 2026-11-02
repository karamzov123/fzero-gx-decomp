#ifndef SFXMC_H
#define SFXMC_H

#include "types.h"

/* Sofdec motion-compensation row kernel recovered from retail movie_module code.
 *
 * One 8-pixel row: four s16 coefficient pairs (GQR3) plus four u8 prediction
 * pairs (GQR4), stored back as u8 pixels (GQR4). Only inline assembly can
 * produce the displacement psq_l/psq_st forms with a non-zero GQR, so the row
 * is a helper the compiler inlines and schedules with the surrounding code
 * (same approach as psvec.h). The second row of a pair reads its coefficients
 * and prediction at larger displacements, hence the two variants. */

static inline void sfxmc_add_row0(const register void *coef, const register void *pred, register void *dst) {
    asm {
        psq_l f0, 0x0(coef), 0, 3
        psq_l f4, 0x0(pred), 0, 4
        psq_l f1, 0x4(coef), 0, 3
        psq_l f5, 0x2(pred), 0, 4
        psq_l f2, 0x8(coef), 0, 3
        psq_l f6, 0x4(pred), 0, 4
        psq_l f3, 0xc(coef), 0, 3
        psq_l f7, 0x6(pred), 0, 4
        ps_add f0, f0, f4
        ps_add f1, f1, f5
        ps_add f2, f2, f6
        ps_add f3, f3, f7
        psq_st f0, 0x0(dst), 0, 4
        psq_st f1, 0x2(dst), 0, 4
        psq_st f2, 0x4(dst), 0, 4
        psq_st f3, 0x6(dst), 0, 4
    }
}

static inline void sfxmc_add_row1(const register void *coef, const register void *pred, register void *dst) {
    asm {
        psq_l f0, 0x10(coef), 0, 3
        psq_l f4, 0x8(pred), 0, 4
        psq_l f1, 0x14(coef), 0, 3
        psq_l f5, 0xa(pred), 0, 4
        psq_l f2, 0x18(coef), 0, 3
        psq_l f6, 0xc(pred), 0, 4
        psq_l f3, 0x1c(coef), 0, 3
        psq_l f7, 0xe(pred), 0, 4
        ps_add f0, f0, f4
        ps_add f1, f1, f5
        ps_add f2, f2, f6
        ps_add f3, f3, f7
        psq_st f0, 0x0(dst), 0, 4
        psq_st f1, 0x2(dst), 0, 4
        psq_st f2, 0x4(dst), 0, 4
        psq_st f3, 0x6(dst), 0, 4
    }
}

#endif
