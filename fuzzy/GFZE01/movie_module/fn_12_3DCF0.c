/* Non-matching: best partial attempt (56.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    void *f0;
    u8 pad_4[0x8];
    s32 fC;
} Fn12_3DCF0_A;

typedef struct {
    void *f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Fn12_3DCF0_B;

void fn_12_3DCF0(Fn12_3DCF0_A *a, Fn12_3DCF0_B *b, const u8 *table, u32 unused) {
    u8 *src = (u8 *)a->f0;
    u32 *dst = (u32 *)b->f0;
    s32 n = a->fC;
    s32 cols = b->f4 / 4;
    s32 rows = b->f8 / 4;
    s32 dstride = ((b->fC - b->f4) << 4) & (s32)0xFFFFFFC0u;
    s32 i;

    for (i = 0; i < rows; i++) {
        s32 j;

        for (j = 0; j < cols; j++) {
            u8 *p = src;
            u8 *q = p + n;
            u8 *r = q + n;
            u8 *s = r + n;
            u32 t0;
            u32 t1;
            u32 t2;
            u32 t3;

            t0 = table[p[0]];
            t1 = table[p[1]];
            t2 = table[p[2]];
            t3 = table[p[3]];
            dst[0] &= (t1 << 8) | (t0 << 24) | 0x00FF00FFu;
            dst[1] &= (t3 << 8) | (t2 << 24) | 0x00FF00FFu;

            t0 = table[q[0]];
            t1 = table[q[1]];
            t2 = table[q[2]];
            t3 = table[q[3]];
            dst[2] &= (t1 << 8) | (t0 << 24) | 0x00FF00FFu;
            dst[3] &= (t3 << 8) | (t2 << 24) | 0x00FF00FFu;

            t0 = table[r[0]];
            t1 = table[r[1]];
            t2 = table[r[2]];
            t3 = table[r[3]];
            dst[4] &= (t1 << 8) | (t0 << 24) | 0x00FF00FFu;
            dst[5] &= (t3 << 8) | (t2 << 24) | 0x00FF00FFu;

            t0 = table[s[0]];
            t1 = table[s[1]];
            t2 = table[s[2]];
            t3 = table[s[3]];
            dst[6] &= (t1 << 8) | (t0 << 24) | 0x00FF00FFu;
            dst[7] &= (t3 << 8) | (t2 << 24) | 0x00FF00FFu;

            src += 4;
            dst += 16;
        }

        src += n * 3;
        dst = (u32 *)((u8 *)dst + dstride);
    }
}
