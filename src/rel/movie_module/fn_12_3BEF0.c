#include "types.h"

const char fzgx_pool_head[0x34] = "\nCRI CFT/GC Ver.1.29 Build:May  9 2003 15:17:25\n";

/* Literal-pool primer: fixes retail's first-use order of the TU's pooled constants.
 * Volatile stores preserve every literal in the pool rather than eliminating overwritten values. */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(volatile f32 *p, s32 n) { /* volatile: retain literal-pool primer stores. */
    p[0] = 0.5f;
    p[0] = 2.017f;
    p[0] = -0.392f;
    p[0] = 0.0f;
    p[0] = -0.813f;
    p[0] = 1.596f;
    p[0] = 1.164f;
    p[0] = 127.0f;
    p[0] = 278.696f;
    p[0] = 255.0f;
    p[0] = (f32)n;
}

/* YCbCr -> RGB conversion tables (Y, Cb, Cr) plus an alpha ramp in column 0. */
void fn_12_3BEF0(s32 mode, s32 lo, s32 hi, f32 *tbl) {
    s32 i;
    s32 j;
    f32 scale;
    f32 (*t)[4] = (f32 (*)[4])tbl;
    s32 k;
    s32 m;

    for (i = 0, k = 256, m = 512; i < 256; i++, k++, m++) {
        f32 y = 1.164f * (f32)(i - 16) + 0.5f;
        t[i][3] = y;
        t[i][2] = y;
        t[i][1] = y;
        t[k][3] = 2.017f * (f32)(i - 128) + 0.5f;
        t[k][2] = -0.392f * (f32)(i - 128) + 0.5f;
        t[k][1] = 0.0f;
        t[k][0] = 0.0f;
        t[m][3] = 0.0f;
        t[m][2] = -0.813f * (f32)(i - 128) + 0.5f;
        t[m][1] = 1.596f * (f32)(i - 128) + 0.5f;
        t[m][0] = 0.0f;
    }

    scale = 255.0f / (f32)(hi - lo);
    if (mode == 1) {
        for (i = 0, j = 255; i < 256; i++, j--) {
            if (i < lo) {
                tbl[i * 4] = 255.0f;
            } else if (i > hi) {
                tbl[i * 4] = 0.0f;
            } else {
                tbl[i * 4] = scale * (f32)(hi - j);
            }
        }
    } else {
        for (i = 0; i < 256; i++) {
            if (i < lo) {
                tbl[i * 4] = 0.0f;
            } else if (i > hi) {
                tbl[i * 4] = 255.0f;
            } else {
                tbl[i * 4] = scale * (f32)(i - lo);
            }
        }
    }
}
