#include "types.h"
#pragma opt_loop_invariants off

/* --- rel/movie_module/DCT_FsriInitSparseTbl.c --- */
void *memset(void *destination, int value, unsigned long size);

void fn_12_4D14(void);

void fn_12_4CEC(const double input[8][8], double output[8][8]);

extern float lbl_12_bss_DB0[64][64];

extern double lbl_12_bss_BB0[64];

static inline int dctFsriScanIndex(int index) {
    int row = index / 8;
    int offset = index % 8;
    int result;
    if ((row % 2) == 0) {
        offset *= 2;
    } else {
        row--;
        offset = offset * 2 + 1;
    }
    result = offset + row * 8;
    if ((result < 0) || (result >= 256)) {
        while (1) {
        }
    }
    return result;
}

static inline void dctFsriStoreSparseCoefficient(int coefficient, int index, const double *value) {
    lbl_12_bss_DB0[dctFsriScanIndex(coefficient)][index] = (float)*value;
}

void DCT_FsriInitSparseTbl(void) {
    union DctCoefficientMatrix {
        double matrix[8][8];
        double coefficients[64];
    } source, destination;
    int coefficient;
    memset(lbl_12_bss_DB0, 0, sizeof(lbl_12_bss_DB0));
    fn_12_4D14();
    for (coefficient = 0; coefficient < 64; coefficient++) {
        int index;
        for (index = 0; index < 64; index++) {
            if (index == coefficient) {
                source.coefficients[index] = 1.0 / lbl_12_bss_BB0[index];
            } else {
                source.coefficients[index] = 0.0;
            }
        }
        fn_12_4CEC(source.matrix, destination.matrix);
        for (index = 0; index < 64; index++) {
            dctFsriStoreSparseCoefficient(coefficient, index, &destination.coefficients[index]);
        }
    }
}

/* --- rel/movie_module/fn_12_5548.c --- */
/* --- rel/movie_module/fn_12_5548.c --- */
extern void *memset(void *dst, int value, u32 size);

void fn_12_5548(void *dst) {
    memset(dst, 0, 0x54);
}

/* --- rel/movie_module/DCT_FsriInitScaleTbl.c --- */

void DCT_FsriInitScaleTbl(float scale_table[64]) {
    int index;
    for (index = 0; index < 64; index++) {
        scale_table[dctFsriScanIndex(index)] = (float)lbl_12_bss_BB0[index];
    }
}

/* --- rel/movie_module/DCT_FsriInit.c --- */
const char *fn_12_4E14(void);

extern const double lbl_12_rodata_610[8];

extern const char *lbl_12_bss_BA8;

void DCT_FsriInitSparseTbl(void);

void DCT_FsriInit(void) {
    int row;
    int column;
    lbl_12_bss_BA8 = fn_12_4E14();
    for (row = 0; row < 8; row++) {
        for (column = 0; column < 8; column++) {
            lbl_12_bss_BB0[row * 8 + column] = lbl_12_rodata_610[row] * lbl_12_rodata_610[column];
        }
    }
    DCT_FsriInitSparseTbl();
}

#define READ_BITS(n, dst) \
    if ((s32)v5 >= 32 - (n)) { \
        v5 -= 32 - (n); \
        if (v5 != 0) { \
            v10 |= v7 >> ((n) - v5); \
            (dst) = v10 >> (32 - (n)); \
            v10 = v7 << v5; \
        } else { \
            (dst) = v10 >> (32 - (n)); \
            v10 = v7; \
        } \
        v7 = *(u32 *)v8; \
        v8 += 4; \
    } else { \
        (dst) = v10 >> (32 - (n)); \
        v10 <<= (n); \
        v5 += (n); \
    }
#define SKIP_BITS(n) \
    v5 += (n); \
    if ((s32)v5 >= 32) { \
        v5 -= 32; \
        v10 = v7 << v5; \
        v7 = *(u32 *)v8; \
        v8 += 4; \
    } else { \
        v10 <<= (n); \
    }
#define PEEK_BITS(n, dst) \
    (dst) = v10 >> (32 - (n)); \
    if ((s32)v5 > 32 - (n)) { \
        (dst) |= v7 >> (64 - (n) - v5); \
    }

