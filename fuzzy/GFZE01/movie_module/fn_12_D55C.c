/* Non-matching: best partial attempt (61.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */

#include "types.h"

typedef struct MPVMCContext MPVMCContext;

typedef void (*MPVMCFunction)(MPVMCContext *context);

struct MPVMCContext {
    MPVMCFunction functions08[4];
    u8 field_10[8];
    u8 *destination;
    u32 field_1c;
    s32 reference_stride;
    const u8 *reference0;
    const u8 *reference1;
    u8 field_2c[8];
    MPVMCFunction functions16[4];
};

void fn_12_D55C(MPVMCContext *context);

#pragma opt_propagation off
void fn_12_D55C(MPVMCContext *context) {
    u32 *d;
    s32 i;
    u32 m2;
    s32 stride;
    u32 m1;
    const u8 *s;
    u32 x0;
    u32 a1, w1;
    u32 a0, w0;
    u32 x1;
    s = context->reference0;
    d = (u32 *)context->destination;
    stride = context->reference_stride;
    m1 = 0xFEFEFEFE;
    m2 = 0x01010101;
    switch ((u32)s & 3) {
    case 0:
        for (i = 0; i < 8; i++) {
            __dcbt((void *)s, stride);
            w0 = ((const u32 *)s)[0];
            w1 = ((const u32 *)s)[1];
            a1 = s[8];
            a0 = (w1 >> 24) | (w0 << 8);
            a1 = (w1 << 8) | a1;
            x0 = w0 ^ a0;
            s += stride;
            w0 &= a0;
            x1 = w1 ^ a1;
            a0 = x0 & m1;
            x0 &= m2;
            w1 &= a1;
            a1 = x1 & m1;
            x1 &= m2;
            a0 >>= 1;
            w0 += x0;
            a1 >>= 1;
            w0 += a0;
            w1 += x1;
            d[0] = w0;
            w1 += a1;
            d[1] = w1;
            d += 2;
        }
        break;
    case 1:
        s -= 1;
        for (i = 0; i < 8; i++) {
            __dcbt((void *)s, stride);
            w1 = ((const u32 *)s)[1];
            a0 = ((const u32 *)s)[0];
            a1 = *(const u16 *)(s + 8);
            w0 = w1 >> 24;
            w0 = __rlwimi(w0, a0, 8, 0, 23);
            a0 = (a0 << 16) | (w1 >> 16);
            a1 = __rlwimi(a1, w1, 16, 0, 15);
            x0 = w0 ^ a0;
            w1 <<= 8;
            w1 = __rlwimi(w1, a1, 24, 24, 31);
            w0 &= a0;
            a0 = x0 & m1;
            x0 &= m2;
            x1 = w1 ^ a1;
            w1 &= a1;
            a1 = x1 & m1;
            a0 >>= 1;
            w0 += x0;
            x1 &= m2;
            w0 += a0;
            a1 >>= 1;
            w1 += x1;
            d[0] = w0;
            w1 += a1;
            s += stride;
            d[1] = w1;
            d += 2;
        }
        break;
    case 2:
        s -= 2;
        for (i = 0; i < 8; i++) {
            __dcbt((void *)s, stride);
            w0 = ((const u32 *)s)[0];
            w1 = ((const u32 *)s)[1];
            x1 = ((const u32 *)s)[2];
            a0 = __rlwimi(w0 << 24, w1, 24, 8, 31);
            w0 = __rlwimi(w0 << 16, w1, 16, 16, 31);
            x0 = w0 ^ a0;
            w0 &= a0;
            a1 = __rlwimi(w1 << 24, x1, 24, 8, 31);
            a0 = x0 & m1;
            w1 = __rlwimi(w1 << 16, x1, 16, 16, 31);
            x0 &= m2;
            s += stride;
            x1 = w1 ^ a1;
            w1 &= a1;
            a1 = x1 & m1;
            a0 >>= 1;
            w0 += x0;
            x1 &= m2;
            w0 += a0;
            a1 >>= 1;
            w1 += x1;
            d[0] = w0;
            w1 += a1;
            d[1] = w1;
            d += 2;
        }
        break;
    case 3:
        s -= 3;
        for (i = 0; i < 8; i++) {
            __dcbt((void *)s, stride);
            a0 = ((const u32 *)s)[1];
            w0 = __lwbrx((void *)s, 0);
            w0 = __rlwimi(w0, a0, 24, 8, 31);
            a1 = ((const u32 *)s)[2];
            x0 = w0 ^ a0;
            w1 = __rlwimi(a0 << 24, a1, 24, 8, 31);
            w0 &= a0;
            a0 = x0 & m1;
            x0 &= m2;
            x1 = w1 ^ a1;
            w1 &= a1;
            a1 = x1 & m1;
            a0 >>= 1;
            w0 += x0;
            x1 &= m2;
            w0 += a0;
            a1 >>= 1;
            w1 += x1;
            d[0] = w0;
            w1 += a1;
            s += stride;
            d[1] = w1;
            d += 2;
        }
        break;
    }
}
