#ifndef DOL_MPEG_AUDIO_H
#define DOL_MPEG_AUDIO_H

#include "types.h"

/* MPEG-1 audio Layer II decoder tables (ISO 11172-3), recovered from fn_80050670, which
 * returns a table's sblimit and stores the table's base (12288-byte stride), and
 * fn_80050698, the dequantizer that reads the entries and the scalefactor multipliers.
 * Names stay the dtk labels until the librarian names the module. */

/* One allocation-table entry: the ISO reference decoder's sb_alloc {steps, bits, group,
 * quant} followed by the precomputed dequantization constants. Entry 0 of each subband has
 * steps 0 and holds the width of the subband's allocation field in bits. */
typedef struct {
    u32 steps;  /* 0x00: quantization levels (3, 5, 7, 9, 15, ..., 2^n - 1) */
    u32 bits;   /* 0x04: code width in bits */
    u32 group;  /* 0x08: 1 = three samples packed in one code, 3 = not grouped */
    u32 quant;  /* 0x0C: quantization class index */
    f32 scale;  /* 0x10: 2 / steps */
    f32 offset; /* 0x14: -(steps - 1) / steps */
} MpaAllocEntry;

extern u32 lbl_8012D9B8[1];                   /* sblimit of each allocation table (30) */
extern MpaAllocEntry lbl_8012D9BC[1][32][16]; /* allocation tables [table][subband][index] */

extern f32 lbl_80130A48[64]; /* scalefactor multipliers 2^(1 - i/3); the last entry is 1e-20 */
extern u32 lbl_80130B98[10]; /* (1 << n) - 1 for n = 0..8, then 0 */

#endif
