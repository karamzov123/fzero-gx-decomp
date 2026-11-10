#ifndef SOFDEC_MPVMC_PPC_H2_H
#define SOFDEC_MPVMC_PPC_H2_H

#include "types.h"

/* CRI Sofdec MPEG motion compensation, 8x8 chroma block with horizontal half-pel interpolation: the
 * PowerPC kernels of MPVMC08_OneRefH2 (movie_module fn_12_D55C), one per source alignment modulo 4.
 * Each expansion does two rows: it builds the row and its right neighbour as word pairs (A,B) and (C,D),
 * averages them bytewise with rounding as (p & q) + ((p ^ q) & m2) + (((p ^ q) & m1) >> 1), stores two
 * words, steps the source by the stride, and finally advances the destination by 16 bytes.
 *
 * The kernel bodies are inline assembly on the caller's register variables, like the copy kernels of the
 * same source file in sofdec/mpvmc_ppc.h (whose lwzux/lfdux cannot come from C). The compiler allocates
 * the registers and schedules; the caller declares the variables in the order that gives retail's
 * registers. They are macros, expanded inside the caller's loops, because an inline function's parameter
 * copies change MWCC's register numbering. A macro is one logical line, hence the ';' separators. */

/* Source word aligned: the neighbour is the same two words shifted left one byte, completed by a trailing byte. */
#define MPVMC08_H2_ROWS_AL0(s, stride, d, m1, m2, A, B, C, D, x, y) \
    asm { \
        dcbt s, stride; \
        lwz A, 0(s); \
        lwz C, 4(s); \
        lbz D, 8(s); \
        slwi B, A, 8; \
        rlwimi B, C, 8, 24, 31; \
        rlwimi D, C, 8, 0, 23; \
        xor x, A, B; \
        add s, s, stride; \
        and A, A, B; \
        xor y, C, D; \
        and B, x, m1; \
        and x, x, m2; \
        and C, C, D; \
        and D, y, m1; \
        and y, y, m2; \
        srwi B, B, 1; \
        add A, A, x; \
        srwi D, D, 1; \
        add A, A, B; \
        add C, C, y; \
        stw A, 0(d); \
        add C, C, D; \
        stw C, 4(d); \
        dcbt s, stride; \
        lwz A, 0(s); \
        lwz C, 4(s); \
        lbz D, 8(s); \
        slwi B, A, 8; \
        rlwimi B, C, 8, 24, 31; \
        rlwimi D, C, 8, 0, 23; \
        xor x, A, B; \
        add s, s, stride; \
        and A, A, B; \
        xor y, C, D; \
        and B, x, m1; \
        and x, x, m2; \
        and C, C, D; \
        and D, y, m1; \
        and y, y, m2; \
        srwi B, B, 1; \
        add A, A, x; \
        srwi D, D, 1; \
        add A, A, B; \
        add C, C, y; \
        stw A, 8(d); \
        add C, C, D; \
        stw C, 12(d); \
        addi d, d, 16; \
    }

/* Source at 1 mod 4 (read from s - 1): both operands come from two words and a trailing halfword. */
#define MPVMC08_H2_ROWS_AL1(s, stride, d, m1, m2, A, B, C, D, x, y) \
    asm { \
        dcbt s, stride; \
        lwz C, 4(s); \
        lwz B, 0(s); \
        lhz D, 8(s); \
        srwi A, C, 24; \
        rlwimi A, B, 8, 0, 23; \
        rlwimi B, C, 0, 0, 15; \
        rotlwi B, B, 16; \
        rlwimi D, C, 16, 0, 15; \
        xor x, A, B; \
        slwi C, C, 8; \
        rlwimi C, D, 24, 24, 31; \
        and A, A, B; \
        and B, x, m1; \
        and x, x, m2; \
        xor y, C, D; \
        and C, C, D; \
        and D, y, m1; \
        srwi B, B, 1; \
        add A, A, x; \
        and y, y, m2; \
        add A, A, B; \
        srwi D, D, 1; \
        add C, C, y; \
        stw A, 0(d); \
        add C, C, D; \
        add s, s, stride; \
        stw C, 4(d); \
        dcbt s, stride; \
        lwz C, 4(s); \
        lhz D, 8(s); \
        lwz B, 0(s); \
        srwi A, C, 24; \
        rlwimi D, C, 16, 0, 15; \
        add s, s, stride; \
        rlwimi A, B, 8, 0, 23; \
        rlwimi B, C, 0, 0, 15; \
        rotlwi B, B, 16; \
        slwi C, C, 8; \
        xor x, A, B; \
        rlwimi C, D, 24, 24, 31; \
        and A, A, B; \
        and B, x, m1; \
        and x, x, m2; \
        xor y, C, D; \
        and C, C, D; \
        and D, y, m1; \
        srwi B, B, 1; \
        add A, A, x; \
        and y, y, m2; \
        add A, A, B; \
        srwi D, D, 1; \
        add C, C, y; \
        stw A, 8(d); \
        add C, C, D; \
        stw C, 12(d); \
        addi d, d, 16; \
    }

/* Source at 2 mod 4 (read from s - 2): both operands come from three words, shifted 16 and 24 bits. */
#define MPVMC08_H2_ROWS_AL2(s, stride, d, m1, m2, A, B, C, D, x, y) \
    asm { \
        dcbt s, stride; \
        lwz A, 0(s); \
        lwz C, 4(s); \
        slwi B, A, 24; \
        slwi A, A, 16; \
        lwz y, 8(s); \
        slwi D, C, 24; \
        rlwimi B, C, 24, 8, 31; \
        rlwimi A, C, 16, 16, 31; \
        xor x, A, B; \
        slwi C, C, 16; \
        and A, A, B; \
        rlwimi D, y, 24, 8, 31; \
        and B, x, m1; \
        rlwimi C, y, 16, 16, 31; \
        and x, x, m2; \
        add s, s, stride; \
        xor y, C, D; \
        and C, C, D; \
        and D, y, m1; \
        srwi B, B, 1; \
        add A, A, x; \
        and y, y, m2; \
        add A, A, B; \
        srwi D, D, 1; \
        add C, C, y; \
        stw A, 0(d); \
        add C, C, D; \
        stw C, 4(d); \
        dcbt s, stride; \
        lwz A, 0(s); \
        lwz C, 4(s); \
        slwi B, A, 24; \
        slwi A, A, 16; \
        lwz y, 8(s); \
        slwi D, C, 24; \
        rlwimi B, C, 24, 8, 31; \
        rlwimi A, C, 16, 16, 31; \
        xor x, A, B; \
        slwi C, C, 16; \
        and A, A, B; \
        rlwimi D, y, 24, 8, 31; \
        and B, x, m1; \
        rlwimi C, y, 16, 16, 31; \
        and x, x, m2; \
        add s, s, stride; \
        xor y, C, D; \
        and C, C, D; \
        and D, y, m1; \
        srwi B, B, 1; \
        add A, A, x; \
        and y, y, m2; \
        add A, A, B; \
        srwi D, D, 1; \
        add C, C, y; \
        stw A, 8(d); \
        add C, C, D; \
        stw C, 12(d); \
        addi d, d, 16; \
    }

/* Source at 3 mod 4 (read from s - 3): the first word is loaded byte-reversed (lwbrx) and completed from the next two. */
#define MPVMC08_H2_ROWS_AL3(s, stride, d, m1, m2, A, B, C, D, x, y) \
    asm { \
        dcbt s, stride; \
        lwz B, 4(s); \
        lwbrx A, 0, s; \
        rlwimi A, B, 24, 8, 31; \
        lwz D, 8(s); \
        xor x, A, B; \
        slwi C, B, 24; \
        rlwimi C, D, 24, 8, 31; \
        and A, A, B; \
        and B, x, m1; \
        and x, x, m2; \
        xor y, C, D; \
        and C, C, D; \
        and D, y, m1; \
        srwi B, B, 1; \
        add A, A, x; \
        and y, y, m2; \
        add A, A, B; \
        srwi D, D, 1; \
        add C, C, y; \
        stw A, 0(d); \
        add C, C, D; \
        add s, s, stride; \
        stw C, 4(d); \
        dcbt s, stride; \
        lwz B, 4(s); \
        lwbrx A, 0, s; \
        rlwimi A, B, 24, 8, 31; \
        lwz D, 8(s); \
        xor x, A, B; \
        slwi C, B, 24; \
        rlwimi C, D, 24, 8, 31; \
        and A, A, B; \
        and B, x, m1; \
        and x, x, m2; \
        xor y, C, D; \
        and C, C, D; \
        and D, y, m1; \
        srwi B, B, 1; \
        add A, A, x; \
        and y, y, m2; \
        add A, A, B; \
        srwi D, D, 1; \
        add C, C, y; \
        stw A, 8(d); \
        add C, C, D; \
        add s, s, stride; \
        stw C, 12(d); \
        addi d, d, 16; \
    }

#endif
