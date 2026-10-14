/* Non-matching: best partial attempt (50.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_3C4A8_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
};
struct fn_12_3C4A8_Arg1 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0x4];
    u32 unk_18;
};

#define CONVERT_PAIR(out_off, u_val, v_val, y0_0, y0_1, y1_0, y1_1) \
    uv = t2[u_val] | t3[v_val]; \
    dst0 = t0[y0_0] | uv; \
    dst1 = t0[y1_0] | uv; \
    *(u32 *)((u8 *)pdst0 + out_off) = dst0 | t1[y0_1]; \
    *(u32 *)((u8 *)pdst1 + out_off) = dst1 | t1[y1_1];

void fn_12_3C4A8(struct fn_12_3C4A8_Arg0 *arg0, struct fn_12_3C4A8_Arg1 *arg1, u32 arg2) {
    u32 *t0;
    u32 *t1;
    u32 *t2;
    u32 *t3;
    u32 py0;
    u32 py1;
    u32 pu;
    u32 pv;
    u32 pdst0;
    u32 pdst1;
    u32 row_end;
    u32 end_y;
    u32 y0, y1, u, v, uv, dst0, dst1;
    s32 step_y, step_uv, step_dst;
    u32 row_bytes;
    u32 r9, r16;

    t0 = (u32 *)arg2;
    t1 = (u32 *)((u8 *)t0 + 0x400);
    t2 = (u32 *)((u8 *)t1 + 0x400);
    t3 = (u32 *)((u8 *)t2 + 0x400);

    py0 = arg0->unk_0 - 4;
    py1 = py0 + (arg0->unk_C & ~3);
    pu = arg0->unk_4 - 4;
    pv = arg0->unk_8 - 4;
    pdst0 = arg1->unk_0 - 4;

    if (arg1->unk_C == 0) {
        arg1->unk_C = 640;
    }
    if (arg1->unk_18 == 0) {
        arg1->unk_18 = 480;
    }

    r9 = arg0->unk_C;
    if (r9 > arg1->unk_C) {
        r9 = arg1->unk_C;
    } else {
        pdst0 += ((arg1->unk_C - arg1->unk_4) & 0x7FFFFFFC);
    }

    r16 = arg1->unk_8;
    if (r16 > arg1->unk_18) {
        r16 = arg1->unk_18;
    } else {
        pdst0 += ((arg1->unk_C * (arg1->unk_18 - r16 * arg1->unk_10)) & ~3);
    }

    step_y = (((((s32)arg0->unk_C / 4) << 1) - ((s32)r9 / 4)) << 2);
    step_uv = (((s32)(arg0->unk_10 - ((s32)r9 / 2)) / 4) << 2);
    pdst1 = pdst0 + (((arg1->unk_C * arg1->unk_10) << 1) & ~3);
    end_y = pdst0 + ((arg1->unk_10 * ((arg1->unk_C >> 1) * r16)) << 2);
    row_bytes = (r9 << 1) & 0x7FFFFFFC;
    step_dst = ((((arg1->unk_10 * (arg1->unk_C << 1)) - r9) << 1) & ~3);

    while (end_y > pdst0) {
        row_end = pdst0 + row_bytes;
        while (row_end > pdst0) {
            __dcbt((void *)py0, 32);
            y0 = *(u32 *)((u8 *)py0 + 4);
            u = *(u32 *)((u8 *)pu + 4);
            v = *(u32 *)((u8 *)pv + 4);
            y1 = *(u32 *)((u8 *)py1 + 4);
            CONVERT_PAIR(4, u >> 24, v >> 24, y0 >> 24, (y0 >> 16) & 0xFF, y1 >> 24, (y1 >> 16) & 0xFF);
            CONVERT_PAIR(8, (u >> 16) & 0xFF, (v >> 16) & 0xFF, (y0 >> 8) & 0xFF, y0 & 0xFF, (y1 >> 8) & 0xFF, y1 & 0xFF);

            y0 = *(u32 *)((u8 *)py0 + 8);
            py1 += 8;
            y1 = *(u32 *)py1;
            CONVERT_PAIR(12, (u >> 8) & 0xFF, (v >> 8) & 0xFF, y0 >> 24, (y0 >> 16) & 0xFF, y1 >> 24, (y1 >> 16) & 0xFF);
            CONVERT_PAIR(16, u & 0xFF, v & 0xFF, (y0 >> 8) & 0xFF, y0 & 0xFF, (y1 >> 8) & 0xFF, y1 & 0xFF);

            __dcbt((void *)py1, 32);
            y0 = *(u32 *)((u8 *)py0 + 12);
            pu += 8;
            u = *(u32 *)pu;
            pv += 8;
            v = *(u32 *)pv;
            y1 = *(u32 *)((u8 *)py1 + 4);
            CONVERT_PAIR(20, u >> 24, v >> 24, y0 >> 24, (y0 >> 16) & 0xFF, y1 >> 24, (y1 >> 16) & 0xFF);
            CONVERT_PAIR(24, (u >> 16) & 0xFF, (v >> 16) & 0xFF, (y0 >> 8) & 0xFF, y0 & 0xFF, (y1 >> 8) & 0xFF, y1 & 0xFF);

            py0 += 16;
            y0 = *(u32 *)py0;
            py1 += 8;
            y1 = *(u32 *)py1;
            CONVERT_PAIR(28, (u >> 8) & 0xFF, (v >> 8) & 0xFF, y0 >> 24, (y0 >> 16) & 0xFF, y1 >> 24, (y1 >> 16) & 0xFF);

            uv = t2[u & 0xFF] | t3[v & 0xFF];
            dst0 = t0[(y0 >> 8) & 0xFF] | uv;
            dst1 = t0[(y1 >> 8) & 0xFF] | uv;
            pdst0 += 32;
            *(u32 *)pdst0 = dst0 | t1[y0 & 0xFF];
            pdst1 += 32;
            *(u32 *)pdst1 = dst1 | t1[y1 & 0xFF];
        }
        pdst0 += step_dst;
        pdst1 += step_dst;
        py0 += step_y;
        py1 += step_y;
        pu += step_uv;
        pv += step_uv;
    }
}
