
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

void fn_12_1FADC(MPVMCContext *context);

void fn_12_1FADC(MPVMCContext *context) {
    const u8 *s = context->reference0;
    __dcbt((void *)s, 0);
    switch ((u32)s & 7) {
    case 0: {
        s32 stride = context->reference_stride;
        double *d = (double *)context->destination;
        u32 pitch = (u32)stride & ~7;
        const u8 *p;
        double a0, a1, b0, b1;
        a0 = ((const double *)s)[0];
        a1 = ((const double *)s)[1];
        p = s + pitch;
        b0 = ((const double *)p)[0];
        b1 = ((const double *)p)[1];
        p += pitch;
        d[0] = a0;
        d[8] = a1;
        a0 = ((const double *)p)[0];
        a1 = ((const double *)p)[1];
        p += pitch;
        d[1] = b0;
        d[9] = b1;
        b0 = ((const double *)p)[0];
        b1 = ((const double *)p)[1];
        p += pitch;
        d[2] = a0;
        d[10] = a1;
        a0 = ((const double *)p)[0];
        a1 = ((const double *)p)[1];
        p += pitch;
        d[3] = b0;
        d[11] = b1;
        b0 = ((const double *)p)[0];
        b1 = ((const double *)p)[1];
        p += pitch;
        d[4] = a0;
        d[12] = a1;
        a0 = ((const double *)p)[0];
        a1 = ((const double *)p)[1];
        p += pitch;
        d[5] = b0;
        d[13] = b1;
        b0 = ((const double *)p)[0];
        b1 = ((const double *)p)[1];
        p += pitch;
        d[6] = a0;
        d[14] = a1;
        a0 = ((const double *)p)[0];
        a1 = ((const double *)p)[1];
        p += pitch;
        d[7] = b0;
        d[15] = b1;
        b0 = ((const double *)p)[0];
        b1 = ((const double *)p)[1];
        p += pitch;
        d[16] = a0;
        d[24] = a1;
        a0 = ((const double *)p)[0];
        a1 = ((const double *)p)[1];
        p += pitch;
        d[17] = b0;
        d[25] = b1;
        b0 = ((const double *)p)[0];
        b1 = ((const double *)p)[1];
        p += pitch;
        d[18] = a0;
        d[26] = a1;
        a0 = ((const double *)p)[0];
        a1 = ((const double *)p)[1];
        p += pitch;
        d[19] = b0;
        d[27] = b1;
        b0 = ((const double *)p)[0];
        b1 = ((const double *)p)[1];
        p += pitch;
        d[20] = a0;
        d[28] = a1;
        a0 = ((const double *)p)[0];
        a1 = ((const double *)p)[1];
        p += pitch;
        d[21] = b0;
        d[29] = b1;
        b0 = ((const double *)p)[0];
        b1 = ((const double *)p)[1];
        d[22] = a0;
        d[30] = a1;
        d[23] = b0;
        d[31] = b1;
        break;
    }
    case 4: {
        s32 stride = context->reference_stride;
        s32 i;
        u32 *d = (u32 *)context->destination;
        u32 pitch = (u32)stride & ~3;
        const u8 *p = s;
        u32 w0, w1, w2, w3;
        for (i = 0; i < 8; i++) {
            w0 = ((const u32 *)p)[0];
            w1 = ((const u32 *)p)[1];
            w2 = ((const u32 *)p)[2];
            w3 = ((const u32 *)p)[3];
            p += pitch;
            d[0] = w0;
            d[1] = w1;
            d[16] = w2;
            d[17] = w3;
            d += 2;
        }
        d += 16;
        for (i = 0; i < 8; i++) {
            w0 = ((const u32 *)p)[0];
            w1 = ((const u32 *)p)[1];
            w2 = ((const u32 *)p)[2];
            w3 = ((const u32 *)p)[3];
            p += pitch;
            d[0] = w0;
            d[1] = w1;
            d[16] = w2;
            d[17] = w3;
            d += 2;
        }
        break;
    }
    case 2:
    case 6: {
        s32 stride = context->reference_stride;
        s32 i;
        u32 *d = (u32 *)context->destination;
        const u8 *p = s;
        u32 h0, w0, w1, w2, h1;
        for (i = 0; i < 16; i++) {
            h0 = *(const u16 *)p;
            w0 = *(const u32 *)(p + 2);
            w1 = *(const u32 *)(p + 6);
            w2 = *(const u32 *)(p + 10);
            h1 = *(const u16 *)(p + 14);
            p += (u32)stride & ~1;
            h0 = (h0 << 16) | (w0 >> 16);
            w0 = (w0 << 16) | (w1 >> 16);
            w1 = (w1 << 16) | (w2 >> 16);
            w2 = (w2 << 16) | h1;
            d[0] = h0;
            d[1] = w0;
            d[16] = w1;
            d[17] = w2;
            d += 2;
            if (i == 7) {
                d += 16;
            }
        }
        break;
    }
    case 1:
    case 5: {
        s32 stride;
        s32 i;
        u32 *d;
        const u8 *p = s;
        u32 w0, w1, w2, w3, b;
        d = (u32 *)context->destination;
        stride = context->reference_stride;
        for (i = 0; i < 16; i++) {
            __dcbt((void *)p, stride);
            w0 = *(const u32 *)(p - 1);
            w1 = *(const u32 *)(p + 3);
            w2 = *(const u32 *)(p + 7);
            w3 = *(const u32 *)(p + 11);
            b = p[15];
            p += stride;
            w0 = (w0 << 8) | (w1 >> 24);
            w1 = (w1 << 8) | (w2 >> 24);
            w2 = (w2 << 8) | (w3 >> 24);
            w3 = (w3 << 8) | b;
            d[0] = w0;
            d[1] = w1;
            d[16] = w2;
            d[17] = w3;
            d += 2;
            if (i == 7) {
                d += 16;
            }
        }
        break;
    }
    case 3:
    case 7: {
        s32 stride;
        s32 i;
        u32 *d;
        const u8 *p = s;
        u32 w0, w1, w2, w3, w4;
        d = (u32 *)context->destination;
        stride = context->reference_stride;
        for (i = 0; i < 16; i++) {
            __dcbt((void *)p, stride);
            w0 = *(const u32 *)(p - 3);
            w1 = *(const u32 *)(p + 1);
            w2 = *(const u32 *)(p + 5);
            w3 = *(const u32 *)(p + 9);
            w4 = *(const u32 *)(p + 13);
            p += stride;
            w0 = (w0 << 24) | (w1 >> 8);
            w1 = (w1 << 24) | (w2 >> 8);
            w2 = (w2 << 24) | (w3 >> 8);
            w3 = (w3 << 24) | (w4 >> 8);
            d[0] = w0;
            d[1] = w1;
            d[16] = w2;
            d[17] = w3;
            d += 2;
            if (i == 7) {
                d += 16;
            }
        }
        break;
    }
    }
}
