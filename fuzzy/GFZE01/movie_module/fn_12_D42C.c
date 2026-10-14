/* Non-matching: best partial attempt (62.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_D42C_Arg0 {
    u8 pad_0[0x18];
    u32 *unk_18;
    u8 pad_1C[4];
    u32 unk_20;
    u8 *unk_24;
    u8 *unk_28;
};

#define BOX(d, i) (d = a[(i) + 1] + b[i], d += b[(i) + 1], d += 2, d += a[i])
#define P(s) (((s) >> 2) & 0xFF)

void fn_12_D42C(struct fn_12_D42C_Arg0 *arg0) {
    u32 stride = arg0->unk_20;
    u8 *a = arg0->unk_24;
    u8 *b = arg0->unk_28;
    u32 *out = arg0->unk_18;
    s32 i;
    for (i = 0; i < 8; i++) {
        u32 s0, s1, s2, s3, s4, s5, s6, s7;
        BOX(s0, 0);
        BOX(s1, 1);
        BOX(s2, 2);
        BOX(s3, 3);
        BOX(s4, 4);
        BOX(s5, 5);
        BOX(s6, 6);
        BOX(s7, 7);
        out[0] = (P(s1) << 8) | P(s0) | (P(s2) << 16) | (P(s3) << 24);
        out[1] = (P(s5) << 8) | P(s4) | (P(s6) << 16) | (P(s7) << 24);
        a += stride;
        b += stride;
        out += 2;
    }
}
