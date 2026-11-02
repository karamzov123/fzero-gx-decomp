/* Non-matching: best partial attempt (98.68% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "sfxmc.h"

typedef struct McSrc {
    u8 pad_0[4];
    s16 *coef;
    u8 *pred;
} McSrc;

typedef struct McBlock {
    u8 *dst;
    u32 stride;
} McBlock;

typedef struct McDst {
    u8 pad_0[4];
    McBlock blocks[6];
} McDst;

/* Six 8x8 blocks: a coded block adds its residual to the prediction, an
 * uncoded one copies the prediction; aligned destinations are zeroed by line
 * first so the stores do not fetch them. */
#pragma opt_strength_reduction off
u32 fn_12_11CE0(McSrc *src, McDst *out, s32 cbp) {
    s16 * fzgx_live;
    u8 *d;
    s16 *coef;
    McBlock *blk;
    u8 * q_2;
    u8 *pred;
    s32 i;
    s32 j;
    u32 stride;
    u8 *q;
    u32 n;
    f64 f8;
    f64 f9;
    f64 f10;
    f64 f11;

    fzgx_live = src->coef;
    coef = fzgx_live;
    blk = out->blocks;
    pred = src->pred;
    for (i = 0; i < 6; i++) {
        d = blk->dst;
        stride = blk->stride;
        blk++;
        if (cbp >= 0) {
            coef += 64;
            n = stride / 8;
            if (((u32)d & 0x1F) == 0) {
                __dcbz(d, 0);
                f8 = ((f64 *)pred)[0];
                f9 = ((f64 *)pred)[1];
                f10 = ((f64 *)pred)[2];
                f11 = ((f64 *)pred)[3];
                *(f64 *)d = f8;
                q = d + n * 8;
                __dcbz(q, 0);
                *(f64 *)q = f9;
                q += n * 8;
                __dcbz(q, 0);
                *(f64 *)q = f10;
                q += n * 8;
                __dcbz(q, 0);
                *(f64 *)q = f11;
                q += n * 8;
                __dcbz(q, 0);
                f8 = ((f64 *)pred)[4];
                f9 = ((f64 *)pred)[5];
                f10 = ((f64 *)pred)[6];
                f11 = ((f64 *)pred)[7];
                *(f64 *)q = f8;
                q += n * 8;
                __dcbz(q, 0);
                *(f64 *)q = f9;
                q += n * 8;
                __dcbz(q, 0);
                *(f64 *)q = f10;
                q += n * 8;
                __dcbz(q, 0);
                *(f64 *)q = f11;
            } else {
                f8 = ((f64 *)pred)[0];
                f9 = ((f64 *)pred)[1];
                f10 = ((f64 *)pred)[2];
                f11 = ((f64 *)pred)[3];
                *(f64 *)d = f8;
                q_2 = d + n * 8;
                *(f64 *)q_2 = f9;
                q_2 += n * 8;
                *(f64 *)q_2 = f10;
                q_2 += n * 8;
                *(f64 *)q_2 = f11;
                q_2 += n * 8;
                f8 = ((f64 *)pred)[4];
                f9 = ((f64 *)pred)[5];
                f10 = ((f64 *)pred)[6];
                f11 = ((f64 *)pred)[7];
                *(f64 *)q_2 = f8;
                q_2 += n * 8;
                *(f64 *)q_2 = f9;
                q_2 += n * 8;
                *(f64 *)q_2 = f10;
                *(f64 *)(q_2 + ((8) * (n))) = f11;
            }
            pred += 0x40;
        } else if (((u32)d & 0x1F) == 0) {
            for (j = 4; ((0) != (j)); j--) {
                __dcbz(d, 0);
                sfxmc_add_row0(coef, pred, d);
                d += stride;
                __dcbz(d, 0);
                sfxmc_add_row1(coef, pred, d);
                d += stride;
                pred += 0x10;
                coef += 0x10;
            }
        } else {
            for (j = 4; ((0) != (j)); j--) {
                sfxmc_add_row0(coef, pred, d);
                d += stride;
                sfxmc_add_row1(coef, pred, d);
                d += stride;
                pred += 0x10;
                coef += 0x10;
            }
        }
        cbp <<= 1;
    }
    return (u32)pred;
}
#pragma opt_strength_reduction reset

