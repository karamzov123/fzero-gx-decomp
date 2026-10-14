/* Non-matching: best partial attempt (76.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

void fn_12_3E688(u8 *arg0, u8 *arg1, u8 *arg2) {
    u8 *p0;
    s32 val;
    s32 i;
    s32 count;
    s32 idx;
    s32 acc;
    s32 idx2;
    s32 val2;
    s32 range_val;
    s32 range_idx;

    p0 = arg0;
    val = 0;
    i = 0;
    while (i < 16) {
        p0[0] = val++;
        i += 2;
        p0[1] = val;
        val += 2;
        p0 += 2;
    }

    for (; i < 176; i += 2) {
        arg0[i] = val;
        arg0[i + 1] = val;
        val++;
    }

    for (; i < 192; i++) {
        arg0[i] = val++;
    }

    for (; i < 256; i++) {
        arg0[i] = (val >= 255) ? 255 : val;
        val += 2;
    }

    idx = 128;
    val = idx;
    for (count = 2; count != 0; count--) {
        arg1[idx] = val;
        arg2[idx] = val;
        arg1[idx - 1] = val;
        arg2[idx - 1] = val;
        arg1[idx - 2] = val;
        arg2[idx - 2] = val;
        val--;
        idx -= 3;

        arg1[idx] = val;
        arg2[idx] = val;
        arg1[idx - 1] = val;
        arg2[idx - 1] = val;
        arg1[idx - 2] = val;
        arg2[idx - 2] = val;
        val--;
        idx -= 3;

        arg1[idx] = val;
        arg2[idx] = val;
        arg1[idx - 1] = val;
        arg2[idx - 1] = val;
        arg1[idx - 2] = val;
        arg2[idx - 2] = val;
        val--;
        idx -= 3;

        arg1[idx] = val;
        arg2[idx] = val;
        arg1[idx - 1] = val;
        arg2[idx - 1] = val;
        arg1[idx - 2] = val;
        arg2[idx - 2] = val;
        val--;
        idx -= 3;
    }

    acc = val * idx;
    for (i = idx; i >= 0; i--) {
        s32 v = acc / idx;
        acc -= val;
        arg1[i] = v;
        arg2[i] = v;
    }

    idx2 = 128;
    val2 = idx2;
    for (count = 2; count != 0; count--) {
        arg1[idx2] = val2;
        arg2[idx2] = val2;
        arg1[idx2 + 1] = val2;
        arg2[idx2 + 1] = val2;
        arg1[idx2 + 2] = val2;
        arg2[idx2 + 2] = val2;
        val2++;
        idx2 += 3;

        arg1[idx2] = val2;
        arg2[idx2] = val2;
        arg1[idx2 + 1] = val2;
        arg2[idx2 + 1] = val2;
        arg1[idx2 + 2] = val2;
        arg2[idx2 + 2] = val2;
        val2++;
        idx2 += 3;

        arg1[idx2] = val2;
        arg2[idx2] = val2;
        arg1[idx2 + 1] = val2;
        arg2[idx2 + 1] = val2;
        arg1[idx2 + 2] = val2;
        arg2[idx2 + 2] = val2;
        val2++;
        idx2 += 3;

        arg1[idx2] = val2;
        arg2[idx2] = val2;
        arg1[idx2 + 1] = val2;
        arg2[idx2 + 1] = val2;
        arg1[idx2 + 2] = val2;
        arg2[idx2 + 2] = val2;
        val2++;
        idx2 += 3;
    }

    range_val = 255 - val2;
    range_idx = 255 - idx2;
    for (i = idx2; i < 256; i++) {
        s32 v = val2 + (range_val * (i - idx2)) / range_idx;
        arg1[i] = v;
        arg2[i] = v;
    }
}
