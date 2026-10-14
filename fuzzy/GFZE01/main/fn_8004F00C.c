/* Non-matching: best partial attempt (36.27% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern s16 lbl_800911E0[32];

static s16 fn_8004F00C_clamp(s32 v) {
    if (v > 0x7FFF) {
        return 0x7FFF;
    }
    if (v < -0x8000) {
        return -0x8000;
    }
    return (s16)v;
}

s16 fn_8004F00C(s16 *in, s16 count, s16 *outA, s16 *stateA, s16 *outB, s16 *stateB,
                s16 coef1, s16 coef2, s16 *pred, s16 step, s16 bias) {
    s16 sA0 = stateA[0];
    s16 sA1 = stateA[1];
    s16 sB0 = stateB[0];
    s16 sB1 = stateB[1];
    s16 half = (s16)(((s32)count + ((u32)count >> 31)) >> 1);
    s16 i;
    s16 lastA = 0;
    s16 lastB = 0;

    for (i = 0; i < half; i++) {
        s16 *oA = outA;
        s16 *oB = outB;
        s16 hdr;
        s16 hdr2;
        s16 idxA;
        s16 idxB;
        s16 j;
        s8 *bp;

        hdr = in[0];
        if (((u32)hdr << 16) & 0x10000) {
            return (s16)(i << 1);
        }
        {
            s16 p = pred[0];

            pred[0] = (s16)(bias + p * step);
            idxA = (s16)(((u16)(hdr ^ p) << 13 >> 19) + 1);
            pred[0] = (s16)((u16)pred[0] >> 1);
        }
        hdr2 = ((s16 *)((s8 *)in + 0x12))[0];
        if (((u32)hdr2 << 16) & 0x10000) {
            return (s16)(i << 1);
        }
        {
            s16 p = pred[0];

            pred[0] = (s16)(bias + p * step);
            idxB = (s16)(((u16)(hdr2 ^ p) << 13 >> 19) + 1);
            pred[0] = (s16)((u16)pred[0] >> 1);
        }
        bp = (s8 *)in + 2;
        for (j = 0; j < 16; j++) {
            s8 x0 = bp[0];
            s8 x1 = bp[0x12];
            s16 v0;
            s16 v1;
            s16 v2;
            s16 v3;

            bp++;
            v0 = fn_8004F00C_clamp(((coef1 * sA0 + coef2 * sA1) >> 12) + (x0 >> 4) * idxA);
            v1 = fn_8004F00C_clamp(((coef1 * sB0 + coef2 * sB1) >> 12) + (x1 >> 4) * idxB);
            {
                s16 t0 = lbl_800911E0[(u8)x0 << 28 >> 30];
                s16 t1 = lbl_800911E0[(u8)x1 << 28 >> 30];

                v2 = fn_8004F00C_clamp(((coef1 * v0 + coef2 * sA0) >> 12) + t0 * idxA);
                v3 = fn_8004F00C_clamp(((coef1 * v1 + coef2 * sB0) >> 12) + t1 * idxB);
            }
            oA[0] = v0;
            oB[0] = v1;
            oA[1] = v2;
            oB[1] = v3;
            oA += 2;
            oB += 2;
            sA1 = sA0;
            sA0 = v0;
            sB1 = sB0;
            sB0 = v1;
            lastA = v0;
            lastB = v1;
        }
        in = (s16 *)(bp + 0x12);
        outA = oA;
        outB = oB;
    }
    stateA[0] = lastA;
    stateA[1] = lastB;
    stateB[0] = lastA;
    stateB[1] = lastB;
    return count;
}
