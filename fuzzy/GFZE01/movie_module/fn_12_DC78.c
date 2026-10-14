/* Non-matching: best partial attempt (8.72% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_DC78_Arg0 {
    u8 pad_0[0x18];
    void *dst;
    u8 pad_1C[4];
    s32 stride;
    u8 *src;
};

void fn_12_DC78(struct fn_12_DC78_Arg0 *arg0) {
    u8 *src = arg0->src;
    __dcbt(src, 0);

    switch ((u32)src & 7) {
    case 0: {
        f64 f0, f1, f2, f3, f4, f5, f6, f7;
        f64 *d = (f64 *)arg0->dst;
        u8 *s = src;
        s32 stride = arg0->stride;

        f0 = *(f64 *)src;
        s += stride; f1 = *(f64 *)s;
        s += stride; f2 = *(f64 *)s;
        s += stride; f3 = *(f64 *)s;
        s += stride; f4 = *(f64 *)s;
        s += stride; f5 = *(f64 *)s;
        s += stride; f6 = *(f64 *)s;
        s += stride; f7 = *(f64 *)s;

        d[0] = f0;
        d[1] = f1;
        d[2] = f2;
        d[3] = f3;
        d[4] = f4;
        d[5] = f5;
        d[6] = f6;
        d[7] = f7;
        return;
    }
    case 4: {
        u32 *d = (u32 *)arg0->dst;
        u8 *s = src;
        s32 stride = arg0->stride;

        d[0] = *(u32 *)src;
        d[1] = *(u32 *)(src + 4);

        s += stride;
        d[2] = *(u32 *)s;
        d[3] = *(u32 *)(s + 4);

        s += stride;
        d[4] = *(u32 *)s;
        d[5] = *(u32 *)(s + 4);

        s += stride;
        d[6] = *(u32 *)s;
        d[7] = *(u32 *)(s + 4);

        s += stride;
        d[8] = *(u32 *)s;
        d[9] = *(u32 *)(s + 4);

        s += stride;
        d[10] = *(u32 *)s;
        d[11] = *(u32 *)(s + 4);

        s += stride;
        d[12] = *(u32 *)s;
        d[13] = *(u32 *)(s + 4);

        s += stride;
        d[14] = *(u32 *)s;
        d[15] = *(u32 *)(s + 4);
        return;
    }
    case 2:
    case 6: {
        u32 *d = (u32 *)arg0->dst;
        u8 *s = src;
        s32 stride = arg0->stride & ~1;
        int i;

        for (i = 0; i < 2; i++) {
            u32 r4, r7, r8;

            r4 = *(u16 *)s;
            r7 = *(u32 *)(s + 2);
            r8 = *(u16 *)(s + 6);
            d[0] = (r4 << 16) | (r7 >> 16);
            d[1] = (r7 << 16) | r8;
            s += stride;

            r4 = *(u16 *)s;
            r7 = *(u32 *)(s + 2);
            r8 = *(u16 *)(s + 6);
            d[2] = (r4 << 16) | (r7 >> 16);
            d[3] = (r7 << 16) | r8;
            s += stride;

            r4 = *(u16 *)s;
            r7 = *(u32 *)(s + 2);
            r8 = *(u16 *)(s + 6);
            d[4] = (r4 << 16) | (r7 >> 16);
            d[5] = (r7 << 16) | r8;
            s += stride;

            r4 = *(u16 *)s;
            r7 = *(u32 *)(s + 2);
            r8 = *(u16 *)(s + 6);
            d[6] = (r4 << 16) | (r7 >> 16);
            d[7] = (r7 << 16) | r8;
            s += stride;

            d += 8;
        }
        return;
    }
    case 1:
    case 5: {
        u32 *d = (u32 *)arg0->dst;
        u8 *s = src - 1;
        s32 stride = arg0->stride;
        s32 stride2 = stride * 2;
        u32 w0, w1, b;

        __dcbt(s, stride);

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); b = s[8];
        __dcbt(s, stride2);
        d[0] = (w0 << 8) | (w1 >> 24);
        d[1] = (w1 << 8) | b;
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); b = s[8];
        __dcbt(s, stride2);
        d[2] = (w0 << 8) | (w1 >> 24);
        d[3] = (w1 << 8) | b;
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); b = s[8];
        __dcbt(s, stride2);
        d[4] = (w0 << 8) | (w1 >> 24);
        d[5] = (w1 << 8) | b;
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); b = s[8];
        __dcbt(s, stride2);
        d[6] = (w0 << 8) | (w1 >> 24);
        d[7] = (w1 << 8) | b;
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); b = s[8];
        __dcbt(s, stride2);
        d[8] = (w0 << 8) | (w1 >> 24);
        d[9] = (w1 << 8) | b;
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); b = s[8];
        __dcbt(s, stride2);
        d[10] = (w0 << 8) | (w1 >> 24);
        d[11] = (w1 << 8) | b;
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); b = s[8];
        d[12] = (w0 << 8) | (w1 >> 24);
        d[13] = (w1 << 8) | b;
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); b = s[8];
        d[14] = (w0 << 8) | (w1 >> 24);
        d[15] = (w1 << 8) | b;
        return;
    }
    case 3:
    case 7: {
        u32 *d = (u32 *)arg0->dst;
        u8 *s = src - 3;
        s32 stride = arg0->stride;
        s32 stride2 = stride * 2;
        u32 w0, w1, w2;

        __dcbt(s, stride);

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); w2 = *(u32 *)(s + 8);
        __dcbt(s, stride2);
        d[0] = (w0 << 24) | (w1 >> 8);
        d[1] = (w1 << 24) | (w2 >> 8);
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); w2 = *(u32 *)(s + 8);
        __dcbt(s, stride2);
        d[2] = (w0 << 24) | (w1 >> 8);
        d[3] = (w1 << 24) | (w2 >> 8);
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); w2 = *(u32 *)(s + 8);
        __dcbt(s, stride2);
        d[4] = (w0 << 24) | (w1 >> 8);
        d[5] = (w1 << 24) | (w2 >> 8);
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); w2 = *(u32 *)(s + 8);
        __dcbt(s, stride);
        d[6] = (w0 << 24) | (w1 >> 8);
        d[7] = (w1 << 24) | (w2 >> 8);
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); w2 = *(u32 *)(s + 8);
        __dcbt(s, stride2);
        d[8] = (w0 << 24) | (w1 >> 8);
        d[9] = (w1 << 24) | (w2 >> 8);
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); w2 = *(u32 *)(s + 8);
        __dcbt(s, stride2);
        d[10] = (w0 << 24) | (w1 >> 8);
        d[11] = (w1 << 24) | (w2 >> 8);
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); w2 = *(u32 *)(s + 8);
        d[12] = (w0 << 24) | (w1 >> 8);
        d[13] = (w1 << 24) | (w2 >> 8);
        s += stride;

        w0 = *(u32 *)s; w1 = *(u32 *)(s + 4); w2 = *(u32 *)(s + 8);
        d[14] = (w0 << 24) | (w1 >> 8);
        d[15] = (w1 << 24) | (w2 >> 8);
        return;
    }
    }
}
