
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

void fn_12_1F1AC(MPVMCContext *context);

void fn_12_1F1AC(MPVMCContext *context) {
    s32 i;
    const u8 *s = context->reference0;
    s32 stride = context->reference_stride;
    u32 *d = (u32 *)context->destination;
    u32 a3, w0, a0, w1, a1, w2, a2, w3, v0, v1, v2, v3, v4;
    u32 m1 = 0xFEFEFEFE;
    u32 m2 = 0x01010101;
    switch ((u32)s & 3) {
    case 0:
        for (i = 0; i < 16; i++) {
            __dcbt((void *)s, stride);
            w0 = ((const u32 *)s)[0];
            w1 = ((const u32 *)s)[1];
            w2 = ((const u32 *)s)[2];
            w3 = ((const u32 *)s)[3];
            a0 = (w0 << 8) | (w1 >> 24);
            a1 = (w1 << 8) | (w2 >> 24);
            a2 = (w2 << 8) | (w3 >> 24);
            a3 = s[16];
            a3 = (w3 << 8) | a3;
            d[0] = ((w0 & a0) + (((w0 ^ a0) & m1) >> 1) + ((w0 ^ a0) & m2));
            d[1] = ((w1 & a1) + (((w1 ^ a1) & m1) >> 1) + ((w1 ^ a1) & m2));
            d[16] = ((w2 & a2) + (((w2 ^ a2) & m1) >> 1) + ((w2 ^ a2) & m2));
            d[17] = ((w3 & a3) + (((w3 ^ a3) & m1) >> 1) + ((w3 ^ a3) & m2));
            s += stride;
            d += 2;
            if (i == 7) {
                d += 16;
            }
        }
        break;
    case 1:
        s -= 1;
        for (i = 0; i < 16; i++) {
            __dcbt((void *)s, stride);
            v0 = ((const u32 *)s)[0];
            v1 = ((const u32 *)s)[1];
            v3 = ((const u32 *)s)[3];
            v2 = ((const u32 *)s)[2];
            v4 = ((const u32 *)s)[4];
            w2 = (v0 << 8) | (v1 >> 24);
            a2 = (v0 << 16) | (v1 >> 16);
            d[0] = ((w2 & a2) + (((w2 ^ a2) & m1) >> 1) + ((w2 ^ a2) & m2));
            w3 = (v1 << 8) | (v2 >> 24);
            a1 = (v1 << 16) | (v2 >> 16);
            d[1] = ((w3 & a1) + (((w3 ^ a1) & m1) >> 1) + ((w3 ^ a1) & m2));
            w0 = (v2 << 8) | (v3 >> 24);
            a0 = (v2 << 16) | (v3 >> 16);
            d[16] = ((w0 & a0) + (((w0 ^ a0) & m1) >> 1) + ((w0 ^ a0) & m2));
            w1 = (v3 << 8) | (v4 >> 24);
            a1 = (v3 << 16) | (v4 >> 16);
            d[17] = ((w1 & a1) + (((w1 ^ a1) & m1) >> 1) + ((w1 ^ a1) & m2));
            s += stride;
            d += 2;
            if (i == 7) {
                d += 16;
            }
        }
        break;
    case 2:
        s -= 2;
        for (i = 0; i < 16; i++) {
            __dcbt((void *)s, stride);
            v0 = ((const u32 *)s)[0];
            v1 = ((const u32 *)s)[1];
            v2 = ((const u32 *)s)[2];
            v3 = ((const u32 *)s)[3];
            v4 = ((const u32 *)s)[4];
            w2 = (v0 << 16) | (v1 >> 16);
            a2 = (v0 << 24) | (v1 >> 8);
            d[0] = ((w2 & a2) + (((w2 ^ a2) & m1) >> 1) + ((w2 ^ a2) & m2));
            w3 = (v1 << 16) | (v2 >> 16);
            a1 = (v1 << 24) | (v2 >> 8);
            d[1] = ((w3 & a1) + (((w3 ^ a1) & m1) >> 1) + ((w3 ^ a1) & m2));
            w0 = (v2 << 16) | (v3 >> 16);
            a0 = (v2 << 24) | (v3 >> 8);
            d[16] = ((w0 & a0) + (((w0 ^ a0) & m1) >> 1) + ((w0 ^ a0) & m2));
            w1 = (v3 << 16) | (v4 >> 16);
            a1 = (v3 << 24) | (v4 >> 8);
            d[17] = ((w1 & a1) + (((w1 ^ a1) & m1) >> 1) + ((w1 ^ a1) & m2));
            s += stride;
            d += 2;
            if (i == 7) {
                d += 16;
            }
        }
        break;
    case 3:
        s -= 3;
        for (i = 0; i < 16; i++) {
            __dcbt((void *)s, stride);
            w0 = ((const u32 *)s)[0];
            a0 = ((const u32 *)s)[1];
            a1 = ((const u32 *)s)[2];
            a2 = ((const u32 *)s)[3];
            a3 = ((const u32 *)s)[4];
            w0 = (w0 << 24) | (a0 >> 8);
            w1 = (a0 << 24) | (a1 >> 8);
            w2 = (a1 << 24) | (a2 >> 8);
            w3 = (a2 << 24) | (a3 >> 8);
            d[0] = ((w0 & a0) + (((w0 ^ a0) & m1) >> 1) + ((w0 ^ a0) & m2));
            d[1] = ((w1 & a1) + (((w1 ^ a1) & m1) >> 1) + ((w1 ^ a1) & m2));
            d[16] = ((w2 & a2) + (((w2 ^ a2) & m1) >> 1) + ((w2 ^ a2) & m2));
            d[17] = ((w3 & a3) + (((w3 ^ a3) & m1) >> 1) + ((w3 ^ a3) & m2));
            s += stride;
            d += 2;
            if (i == 7) {
                d += 16;
            }
        }
        break;
    }
}
