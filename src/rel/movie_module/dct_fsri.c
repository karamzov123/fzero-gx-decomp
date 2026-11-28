#include "types.h"
#include "sofdec/mpvidct_ppc.h"

typedef struct MPVBlockCtx {
    s8 coded[0x2C];
    f32 *coefficients;
    u32 **outputs;
    u8 pad_34[0x14];
    f32 *work;
} MPVBlockCtx;
extern void fn_12_4F3C(MPVBlockCtx *ctx, s32 mask);
extern f32 lbl_12_data_0[12];
extern void *memset(void *dst, int value, u32 size);
extern void fn_12_4D14(void);
extern void fn_12_4CEC(void *arg0, void *arg1);
extern double lbl_12_bss_BB0[64];
extern void * fn_12_4E14(void);
extern const double lbl_12_rodata_610[8];
extern const char *lbl_12_bss_BA8;
extern void DCT_FsriInitSparseTbl(void);

/* fzgx:begin DCT_FsriInitScanTbl */
/* --- rel/movie_module/DCT_FsriInitScanTbl.c --- */
static inline int DCT_FsriInitScanTbl_dctFsriScanIndex(int index) {
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

void DCT_FsriInitScanTbl(const signed char source[64], signed char destination[64]) {
    int index;
    for (index = 0; index < 64; index++) {
        destination[index] = (signed char)DCT_FsriInitScanTbl_dctFsriScanIndex(source[index]);
    }
}
/* fzgx:end DCT_FsriInitScanTbl */

/* fzgx:begin fn_12_4F18 */
/* --- rel/movie_module/fn_12_4F18.c --- */
typedef struct MovieModule {
    u8 pad_28[0x28];
    void *field_28;
} MovieModule;


void fn_12_4F18(MovieModule *module) {
    fn_12_4F3C( (MPVBlockCtx *)(MovieModule *)(module), (s32)(void *)(module->field_28));
}
/* fzgx:end fn_12_4F18 */

/* fzgx:begin fn_12_4F3C */



#pragma explicit_zero_data on
__declspec(section ".data") f32 lbl_12_data_0[12] __attribute__((aligned(8))) = {
    1.41421354f, 1.41421354f, 2.61312604f, 2.61312604f, 1.08239222f, 1.08239222f, 0.765366852f, 0.765366852f, 0.5f, 0.5f, -0.5f, -0.5f
};
#pragma explicit_zero_data reset

/* --- rel/movie_module/fn_12_4F3C.c --- */


/* Inverse DCT of the six blocks of a macroblock. `mask` has one bit per block, top bit first; a block
 * whose `coded` flag is clear has only a DC coefficient and is filled with its rounded value. The
 * register variables are declared in the order that gives retail's registers. */
void fn_12_4F3C(MPVBlockCtx *ctx, s32 mask) {
    register s32 n;
    register s8 *flag;
    register f32 *tbl;
    register f32 *coef;
    register f32 *kp;
    register u32 **outp;
    register f32 *work;
    register f32 *p;
    register u32 *dst;
    register f32 *q;
    register f32 t0;
    register f32 k1;
    register f32 k2;
    register f32 k3;
    register f32 k4;
    register f32 k5;
    register f32 k6;
    register f32 t7;
    register f32 t8;
    register f32 t9;
    register f32 t10;
    register f32 t11;
    register f32 t12;
    register f32 t13;
    register f32 t31;
    s32 i;

    tbl = lbl_12_data_0;
    kp = tbl;
    work = ctx->work;
    MPVIDCT_LOAD_CONSTANTS(kp, k1, k2, k3, k4, k5, k6);
    coef = ctx->coefficients;
    outp = ctx->outputs;
    flag = ctx->coded;
    for (i = 0; i < 6; i++) {
        if (mask < 0) {
            if (*flag == 0) {
                f32 dc = *coef;
                s32 v;
                u32 w;
                u32 *out;
                out = *outp;
                if (dc < 0.0) {
                    v = (s16)(dc - 0.5f);
                } else {
                    v = (s16)(0.5f + dc);
                }
                w = ((u32)v << 16) | (v & 0xFFFF);
                out[31] = w;
                out[30] = w;
                out[29] = w;
                out[28] = w;
                out[27] = w;
                out[26] = w;
                out[25] = w;
                out[24] = w;
                out[23] = w;
                out[22] = w;
                out[21] = w;
                out[20] = w;
                out[19] = w;
                out[18] = w;
                out[17] = w;
                out[16] = w;
                out[15] = w;
                out[14] = w;
                out[13] = w;
                out[12] = w;
                out[11] = w;
                out[10] = w;
                out[9] = w;
                out[8] = w;
                out[7] = w;
                out[6] = w;
                out[5] = w;
                out[4] = w;
                out[3] = w;
                out[2] = w;
                out[1] = w;
                out[0] = w;
            } else {
                dst = *outp;
                p = coef - 2;
                q = work - 2;
                n = 4;
                MPVIDCT_PASS1(p, q, n, k1, k2, k3, k4, t0, t7, t8, t9, t10, t11, t12, t13, t31);
                q = (f32 *)dst;
                p = work;
                n = 4;
                MPVIDCT_PASS2(p, q, n, k1, k2, k3, k4, k5, k6, t0, t7, t8, t9, t10, t11, t12, t13, t31);
            }
        }
        mask <<= 1;
        coef += 0x40;
        outp++;
        flag++;
    }
}
/* fzgx:end fn_12_4F3C */

/* fzgx:begin fn_12_52C4 */
/* --- rel/movie_module/fn_12_52C4.c --- */
void fn_12_52C4(void *arg) {
    fn_12_4F3C(arg, -1);
}
/* fzgx:end fn_12_52C4 */

/* fzgx:begin DCT_FsriInitSparseTbl */
float lbl_12_bss_DB0[64][64] __attribute__((aligned(16)));

#pragma opt_loop_invariants off

/* --- rel/movie_module/DCT_FsriInitSparseTbl.c --- */




static inline int DCT_FsriInitSparseTbl_dctFsriScanIndex(int index) {
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
    lbl_12_bss_DB0[DCT_FsriInitSparseTbl_dctFsriScanIndex(coefficient)][index] = (float)*value;
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
/* fzgx:end DCT_FsriInitSparseTbl */

/* fzgx:begin fn_12_5548 */
/* --- rel/movie_module/fn_12_5548.c --- */
/* --- rel/movie_module/fn_12_5548.c --- */

void fn_12_5548(void *dst) {
    memset(dst, 0, 0x54);
}
/* fzgx:end fn_12_5548 */

/* fzgx:begin DCT_FsriInitScaleTbl */
/* --- rel/movie_module/DCT_FsriInitScaleTbl.c --- */

void DCT_FsriInitScaleTbl(float scale_table[64]) {
    int index;
    for (index = 0; index < 64; index++) {
        scale_table[DCT_FsriInitSparseTbl_dctFsriScanIndex(index)] = (float)lbl_12_bss_BB0[index];
    }
}
/* fzgx:end DCT_FsriInitScaleTbl */

/* fzgx:begin DCT_FsriInit */
/* --- rel/movie_module/DCT_FsriInit.c --- */




void DCT_FsriInit(void) {
    int row;
    int column;
    lbl_12_bss_BA8 = ((const char *)fn_12_4E14());
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
/* fzgx:end DCT_FsriInit */
