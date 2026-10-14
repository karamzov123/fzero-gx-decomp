/* Non-matching: best partial attempt (47.94% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_3C8CC_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s32 unk_C;
    s32 unk_10;
};

struct fn_12_3C8CC_Arg1 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

void fn_12_3C8CC(struct fn_12_3C8CC_Arg0 *arg0, struct fn_12_3C8CC_Arg1 *arg1) {
    s32 v0 = arg0->unk_C;
    u8 *v1 = (u8 *)(arg0->unk_0 - 4);
    u8 *v2 = (u8 *)(arg0->unk_0 - 4 + (arg0->unk_C & 0x3FFFFFFC) * 4);
    u8 *v3 = (u8 *)(arg0->unk_4 - 4);
    u8 *v4 = (u8 *)(arg0->unk_8 - 4);
    u8 *v5 = (u8 *)(arg1->unk_0 - 4);
    u8 *v6;
    u8 *v7;
    u8 *v19;
    u32 v8 = arg1->unk_8;
    u32 v9 = arg1->unk_C;
    u32 v10 = arg1->unk_10;
    u32 v11;
    u32 v12;
    u32 v13;
    u32 v14;
    u32 v15;
    u32 v16;
    s32 v17;
    s32 v18;

    if (v0 <= arg1->unk_C) {
        v5 += (arg1->unk_C - arg1->unk_4) & 0x7FFFFFFC;
    } else {
        v0 = arg1->unk_C;
    }

    if (v8 > arg1->unk_18) {
        v8 = arg1->unk_18;
    } else {
        v5 += (arg1->unk_C * (arg1->unk_18 - arg1->unk_8 * arg1->unk_10) & 0x3FFFFFFC) * 4;
    }

    v17 = v0 / 4;
    v18 = arg0->unk_C / 4;
    v6 = v5 + ((v9 * v10 & 1) << 1);
    v11 = ((arg0->unk_10 - v0 / 2) / 4) * 4;
    v7 = v5 + v10 * ((v9 >> 1) * v8) * 4;
    v12 = (v18 * 2 - v17) * 4;
    v13 = ((v10 * (v9 * 2) - v0) & 1) << 1;
    v14 = (v0 * 2) & 0x7FFFFFFC;
    v15 = v11;
    v11 = v12;

    while (v7 > v5) {
        v19 = v5 + v14;

        while (v19 > v5) {
            u32 a0, a1, a2, a3, b0, b1, c0, c1, d0, d1, d2, d3;

            a0 = *(u32 *)(v1 + 4);
            b0 = *(u32 *)(v3 + 4);
            c0 = *(u32 *)(v4 + 4);
            d0 = *(u32 *)(v2 + 4);
            *(u32 *)(v5 + 4) = ((b0 & 0xFF0000) >> 8) | ((c0 & 0xFF0000) << 8) | (a0 & 0xFF) | ((a0 & 0xFF000000) >> 8);
            *(u32 *)(v6 + 4) = ((b0 & 0xFF0000) >> 8) | ((c0 & 0xFF0000) << 8) | (d0 & 0xFF) | ((d0 & 0xFF000000) >> 8);

            a1 = *(u32 *)(v1 + 8);
            d1 = *(u32 *)(v2 + 8);
            *(u32 *)(v5 + 8) = (b0 & 0xFF00) | ((c0 & 0xFF00) << 16) | ((a1 & 0xFF0000) >> 16) | ((a1 & 0xFF00) << 8);
            *(u32 *)(v6 + 8) = (b0 & 0xFF00) | ((c0 & 0xFF00) << 16) | ((d1 & 0xFF0000) >> 16) | ((d1 & 0xFF00) << 8);
            *(u32 *)(v5 + 12) = ((b0 & 0xFF) << 8) | ((c0 & 0xFF) << 24) | (a1 & 0xFF) | ((a1 & 0xFF000000) >> 8);
            *(u32 *)(v6 + 12) = ((b0 & 0xFF) << 8) | ((c0 & 0xFF) << 24) | (d1 & 0xFF) | ((d1 & 0xFF000000) >> 8);
            *(u32 *)(v5 + 16) = ((b0 & 0xFF00) << 16) | (c0 & 0xFF000000) | ((a1 & 0xFF0000) >> 16) | ((a1 & 0xFF00) << 8);
            *(u32 *)(v6 + 16) = ((b0 & 0xFF00) << 16) | (c0 & 0xFF000000) | (d1 & 0xFF0000) >> 16 | ((d1 & 0xFF00) << 8);

            b1 = *(u32 *)(v3 + 8);
            c1 = *(u32 *)(v4 + 8);
            a2 = *(u32 *)(v1 + 12);
            d2 = *(u32 *)(v2 + 12);
            *(u32 *)(v5 + 20) = ((b1 & 0xFF0000) >> 8) | ((c1 & 0xFF0000) << 8) | (a2 & 0xFF) | ((a2 & 0xFF000000) >> 8);
            *(u32 *)(v6 + 20) = ((b1 & 0xFF0000) >> 8) | ((c1 & 0xFF0000) << 8) | (d2 & 0xFF) | ((d2 & 0xFF000000) >> 8);
            *(u32 *)(v5 + 24) = (b1 & 0xFF00) | ((c1 & 0xFF00) << 16) | ((a2 & 0xFF0000) >> 16) | ((a2 & 0xFF00) << 8);
            *(u32 *)(v6 + 24) = (b1 & 0xFF00) | ((c1 & 0xFF00) << 16) | ((d2 & 0xFF0000) >> 16) | ((d2 & 0xFF00) << 8);

            a3 = *(u32 *)(v1 + 16);
            d3 = *(u32 *)(v2 + 16);
            *(u32 *)(v5 + 28) = ((b1 & 0xFF00) << 16) | (c1 & 0xFF000000) | ((a3 & 0xFF0000) >> 16) | ((a3 & 0xFF00) << 8);
            *(u32 *)(v6 + 28) = ((b1 & 0xFF00) << 16) | (c1 & 0xFF000000) | ((d3 & 0xFF0000) >> 16) | ((d3 & 0xFF00) << 8);
            *(u32 *)(v5 + 32) = ((b1 & 0xFF) << 8) | ((c1 & 0xFF) << 24) | (a3 & 0xFF) | ((a3 & 0xFF000000) >> 8);
            *(u32 *)(v6 + 32) = ((b1 & 0xFF) << 8) | ((c1 & 0xFF) << 24) | (d3 & 0xFF) | ((d3 & 0xFF000000) >> 8);

            v1 += 16;
            v2 += 16;
            v3 += 8;
            v4 += 8;
            v5 += 32;
            v6 += 32;
        }

        v5 += v13;
        v6 += v13;
        v1 += v11;
        v2 += v11;
        v3 += v15;
        v4 += v15;
    }
}
