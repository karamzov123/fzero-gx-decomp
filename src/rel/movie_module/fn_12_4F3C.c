#include "types.h"
#include "sofdec/mpvidct_ppc.h"

typedef struct MPVBlockCtx {
    s8 coded[0x2C];
    f32 *coefficients;
    u32 **outputs;
    u8 pad_34[0x14];
    f32 *work;
} MPVBlockCtx;

extern f32 lbl_12_data_0[12];

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
