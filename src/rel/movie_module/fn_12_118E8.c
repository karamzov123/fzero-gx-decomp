#include "types.h"
#include "sfxmc.h"

typedef struct McBiSrc {
    u8 pad_0[4];
    s16 *coef;
    u8 *pred0;
    u8 *pred1;
} McBiSrc;

typedef struct McBlock {
    u8 *dst;
    u32 stride;
} McBlock;

typedef struct McDst {
    u8 pad_0[4];
    McBlock blocks[6];
} McDst;

extern const f32 lbl_12_rodata_9E8[2];

#pragma opt_strength_reduction off
void fn_12_118E8(McBiSrc *src, McDst *out, s32 cbp) {
    u8 *pred1;
    u8 *d;
    u32 stride;
    u8 *pred0;
    s16 *coef;
    McBlock *blk;
    s32 i;
    s32 j;

    coef = src->coef;
    pred0 = src->pred0;
    sfxmc_load_bias(lbl_12_rodata_9E8);
    blk = out->blocks;
    pred1 = src->pred1;
    for (i = 0; i < 6; i++) {
        d = blk->dst;
        stride = blk->stride;
        blk++;
        if (cbp >= 0) {
            if (((u32)d & 0x1F) == 0) {
                coef += 64;
                for (j = 4; j != 0; j--) {
                    __dcbz(d, 0);
                    sfxmc_avg_row0(pred0, pred1, d);
                    d += stride;
                    __dcbz(d, 0);
                    sfxmc_avg_row1(pred0, pred1, d);
                    d += stride;
                    pred0 += 0x10;
                    pred1 += 0x10;
                }
            } else {
                coef += 64;
                for (j = 4; j != 0; j--) {
                    sfxmc_avg_row0(pred0, pred1, d);
                    d += stride;
                    sfxmc_avg_row1(pred0, pred1, d);
                    d += stride;
                    pred0 += 0x10;
                    pred1 += 0x10;
                }
            }
        } else if (((u32)d & 0x1F) == 0) {
            for (j = 4; j != 0; j--) {
                __dcbz(d, 0);
                sfxmc_avg_add_row0(coef, pred0, pred1, d);
                d += stride;
                __dcbz(d, 0);
                sfxmc_avg_add_row1(coef, pred0, pred1, d);
                d += stride;
                pred0 += 0x10;
                pred1 += 0x10;
                coef += 0x10;
            }
        } else {
            for (j = 4; j != 0; j--) {
                sfxmc_avg_add_row0(coef, pred0, pred1, d);
                d += stride;
                sfxmc_avg_add_row1(coef, pred0, pred1, d);
                d += stride;
                pred0 += 0x10;
                pred1 += 0x10;
                coef += 0x10;
            }
        }
        cbp <<= 1;
    }
}
#pragma opt_strength_reduction reset
