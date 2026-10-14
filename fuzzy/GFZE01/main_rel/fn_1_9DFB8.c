/* Non-matching: best partial attempt (53.95% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_9DFB8_Arg1 {
    s32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
};

f32 fn_1_9DFB8(s32 arg0, struct fn_1_9DFB8_Arg1 *arg1, s32 *arg2, s32 arg3, f32 arg4) {
    struct fn_1_9DFB8_Arg1 *p;
    s32 n;
    s32 i;
    struct fn_1_9DFB8_Arg1 *lo;
    f32 f;
    f32 d;
    f32 t;
    f32 t2;
    f32 a;
    f32 c;
    f32 w;
    f32 r;

    n = arg0 - 2;
    p = arg1;
    if (n >= 0 && arg4 > p->unk_4) {
        if (arg4 < ((struct fn_1_9DFB8_Arg1 *)((u8 *)p + arg0 * 0x14 - 0x14))->unk_4) {
            i = *arg2;
            if (i <= 0) {
                i = 0;
            } else if (i >= n) {
                i = n;
            }
            p = &p[i];
            if (p->unk_4 <= arg4) {
                do {
                    p++;
                    i++;
                } while (i < arg0 - 1 && p->unk_4 <= arg4);
                lo = p - 1;
                *arg2 = i - 1;
            } else {
                do {
                    p--;
                    i--;
                } while (i >= 0 && p->unk_4 > arg4);
                lo = p;
                p++;
                *arg2 = i;
            }
            if (lo->unk_0 == 0) {
                return lo->unk_8;
            } else if (lo->unk_0 == 1) {
                d = p->unk_4 - lo->unk_4;
                t = (arg4 - lo->unk_4) / d;
                c = *(f32 *)(0xE0000000 + 0x19C);
                return lo->unk_8 * (c - t) + p->unk_8 * t;
            }
            d = p->unk_4 - lo->unk_4;
            t = (arg4 - lo->unk_4) / d;
            t2 = t * t;
            a = t * t2 - t2;
            c = *(f32 *)(0xE0000000 + 0x19C);
            w = (c + c) * a - t2;
            r = lo->unk_8 * (w + c) - w * p->unk_8;
            return (lo->unk_10 * (a - t2 + t) + a * p->unk_C) * d + r;
        } else {
            p = (struct fn_1_9DFB8_Arg1 *)((u8 *)p + arg0 * 0x14 - 0x14);
            f = p->unk_C;
        }
    } else {
        n = 0;
        f = p->unk_10;
    }
    *arg2 = n;
    if (arg3 > 0) {
        return f;
    }
    return p->unk_8;
}
