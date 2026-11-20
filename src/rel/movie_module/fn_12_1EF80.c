#include "types.h"


/* --- rel/movie_module/fn_12_1EF80.c --- */
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

void fn_12_1EF80(MPVMCContext *context);

void fn_12_1EF80(MPVMCContext *context) {
    s32 a0, b0, a1, b1, a2, b2;
    u32 p0, p1, p2, p3, p4, p5, p6, p7;
    s32 row;
    s32 stride;
    const u8 *reference0;
    const u8 *reference1;
    u32 *destination;
    stride = context->reference_stride;
    reference0 = context->reference0;
    reference1 = context->reference1;
    destination = (u32 *)context->destination;
    for (row = 0; row < 16; row++) {
        __dcbt((void *)reference1, stride);
        a0 = reference0[0];
        b0 = reference1[0];
        a1 = reference0[1];
        b1 = reference1[1];
        a2 = reference0[2];
        b2 = reference1[2];
        p0 = (u32)a0 + a1 + b0 + b1 + 2;
        p1 = (u32)a1 + a2 + b1 + b2 + 2;
        a0 = reference0[3];
        b0 = reference1[3];
        p2 = (u32)a2 + a0 + b2 + b0 + 2;
        a1 = reference0[4];
        b1 = reference1[4];
        p3 = (u32)a0 + a1 + b0 + b1 + 2;
        a2 = reference0[5];
        b2 = reference1[5];
        p4 = (u32)a1 + a2 + b1 + b2 + 2;
        a0 = reference0[6];
        b0 = reference1[6];
        p5 = (u32)a2 + a0 + b2 + b0 + 2;
        a1 = reference0[7];
        b1 = reference1[7];
        p6 = (u32)a0 + a1 + b0 + b1 + 2;
        a2 = reference0[8];
        b2 = reference1[8];
        p7 = (u32)a1 + a2 + b1 + b2 + 2;
        a0 = reference0[9];
        b0 = reference1[9];
        destination[0] = ((p0 << 22) & 0xFF000000) | ((p1 << 14) & 0x00FF0000) |
                         ((p2 << 6) & 0x0000FF00) | ((p3 >> 2) & 0x000000FF);
        destination[1] = ((p4 << 22) & 0xFF000000) | ((p5 << 14) & 0x00FF0000) |
                         ((p6 << 6) & 0x0000FF00) | ((p7 >> 2) & 0x000000FF);
        p0 = (u32)a2 + a0 + b2 + b0 + 2;
        a1 = reference0[10];
        b1 = reference1[10];
        p1 = (u32)a0 + a1 + b0 + b1 + 2;
        a2 = reference0[11];
        b2 = reference1[11];
        p2 = (u32)a1 + a2 + b1 + b2 + 2;
        a0 = reference0[12];
        b0 = reference1[12];
        p3 = (u32)a2 + a0 + b2 + b0 + 2;
        a1 = reference0[13];
        b1 = reference1[13];
        p4 = (u32)a0 + a1 + b0 + b1 + 2;
        a2 = reference0[14];
        b2 = reference1[14];
        p5 = (u32)a1 + a2 + b1 + b2 + 2;
        a0 = reference0[15];
        b0 = reference1[15];
        p6 = (u32)a2 + a0 + b2 + b0 + 2;
        a1 = reference0[16];
        b1 = reference1[16];
        p7 = (u32)a0 + a1 + b0 + b1 + 2;
        destination[16] = ((p0 << 22) & 0xFF000000) | ((p1 << 14) & 0x00FF0000) |
                          ((p2 << 6) & 0x0000FF00) | ((p3 >> 2) & 0x000000FF);
        destination[17] = ((p4 << 22) & 0xFF000000) | ((p5 << 14) & 0x00FF0000) |
                          ((p6 << 6) & 0x0000FF00) | ((p7 >> 2) & 0x000000FF);
        reference0 += stride;
        reference1 += stride;
        destination += 2;
        if (row == 7) {
            destination += 16;
        }
    }
}

/* --- rel/movie_module/fn_12_1F1AC.c --- */
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

/* --- rel/movie_module/fn_12_1F61C.c --- */
void fn_12_1F61C(MPVMCContext *context);

void fn_12_1F61C(MPVMCContext *context) {
    u32 *output;
    const u8 *reference0;
    const u8 *reference1;
    s32 stride;
    s32 row;
    u32 left0, right0, left1, right1, left2, right2, left3, right3;
    u32 tail0, tail1;
    u32 high_bits = 0xFEFEFEFE;
    u32 low_bits = 0x01010101;
    reference1 = context->reference1;
    reference0 = context->reference0;
    output = (u32 *)context->destination;
    stride = context->reference_stride;
    __dcbt((void *)reference1, 0);
    switch ((unsigned long)reference0 & 3) {
    case 0:
        for (row = 0; row < 16; row++) {
            __dcbt((void *)reference1, stride);
            left0 = ((const u32 *)reference0)[0];
            right0 = ((const u32 *)reference1)[0];
            left1 = ((const u32 *)reference0)[1];
            right1 = ((const u32 *)reference1)[1];
            left2 = ((const u32 *)reference0)[2];
            right2 = ((const u32 *)reference1)[2];
            left3 = ((const u32 *)reference0)[3];
            right3 = ((const u32 *)reference1)[3];
            output[0] = (((left0) & (right0)) + ((((left0) ^ (right0)) & (high_bits)) >> 1) +
                         (((left0) ^ (right0)) & (low_bits)));
            output[1] = (((left1) & (right1)) + ((((left1) ^ (right1)) & (high_bits)) >> 1) +
                         (((left1) ^ (right1)) & (low_bits)));
            output[16] = (((left2) & (right2)) + ((((left2) ^ (right2)) & (high_bits)) >> 1) +
                          (((left2) ^ (right2)) & (low_bits)));
            output[17] = (((left3) & (right3)) + ((((left3) ^ (right3)) & (high_bits)) >> 1) +
                          (((left3) ^ (right3)) & (low_bits)));
            reference0 += stride;
            reference1 += stride;
            output += 2;
            if (row == 7) {
                output += 16;
            }
        }
        break;
    case 1:
        reference0 -= 1;
        reference1 -= 1;
        for (row = 0; row < 16; row++) {
            __dcbt((void *)reference1, stride);
            left1 = ((const u32 *)reference0)[1];
            right1 = ((const u32 *)reference1)[1];
            left2 = ((const u32 *)reference0)[2];
            right2 = ((const u32 *)reference1)[2];
            left3 = ((const u32 *)reference0)[3];
            right3 = ((const u32 *)reference1)[3];
            tail0 = reference0[16];
            tail1 = reference1[16];
            left0 = ((const u32 *)reference0)[0];
            reference0 += stride;
            right0 = ((const u32 *)reference1)[0];
            reference1 += stride;
            left0 = (left0 << 8) | (left1 >> 24);
            right0 = (right0 << 8) | (right1 >> 24);
            left1 = (left1 << 8) | (left2 >> 24);
            right1 = (right1 << 8) | (right2 >> 24);
            left2 = (left2 << 8) | (left3 >> 24);
            right2 = (right2 << 8) | (right3 >> 24);
            tail0 = (left3 << 8) | tail0;
            tail1 = (right3 << 8) | tail1;
            output[0] = (((left0) & (right0)) + ((((left0) ^ (right0)) & (high_bits)) >> 1) +
                         (((left0) ^ (right0)) & (low_bits)));
            output[1] = (((left1) & (right1)) + ((((left1) ^ (right1)) & (high_bits)) >> 1) +
                         (((left1) ^ (right1)) & (low_bits)));
            output[16] = (((left2) & (right2)) + ((((left2) ^ (right2)) & (high_bits)) >> 1) +
                          (((left2) ^ (right2)) & (low_bits)));
            output[17] = (((tail0) & (tail1)) + ((((tail0) ^ (tail1)) & (high_bits)) >> 1) +
                          (((tail0) ^ (tail1)) & (low_bits)));
            output += 2;
            if (row == 7) {
                output += 16;
            }
        }
        break;
    case 2:
        reference0 -= 2;
        reference1 -= 2;
        for (row = 0; row < 16; row++) {
            __dcbt((void *)reference1, stride);
            left1 = ((const u32 *)reference0)[1];
            right1 = ((const u32 *)reference1)[1];
            left2 = ((const u32 *)reference0)[2];
            right2 = ((const u32 *)reference1)[2];
            left3 = ((const u32 *)reference0)[3];
            right3 = ((const u32 *)reference1)[3];
            tail0 = *(const u16 *)(reference0 + 16);
            tail1 = *(const u16 *)(reference1 + 16);
            left0 = ((const u32 *)reference0)[0];
            reference0 += stride;
            right0 = ((const u32 *)reference1)[0];
            reference1 += stride;
            left0 = (left0 << 16) | (left1 >> 16);
            right0 = (right0 << 16) | (right1 >> 16);
            left1 = (left1 << 16) | (left2 >> 16);
            right1 = (right1 << 16) | (right2 >> 16);
            left2 = (left2 << 16) | (left3 >> 16);
            right2 = (right2 << 16) | (right3 >> 16);
            tail0 = (left3 << 16) | tail0;
            tail1 = (right3 << 16) | tail1;
            output[0] = (((left0) & (right0)) + ((((left0) ^ (right0)) & (high_bits)) >> 1) +
                         (((left0) ^ (right0)) & (low_bits)));
            output[1] = (((left1) & (right1)) + ((((left1) ^ (right1)) & (high_bits)) >> 1) +
                         (((left1) ^ (right1)) & (low_bits)));
            output[16] = (((left2) & (right2)) + ((((left2) ^ (right2)) & (high_bits)) >> 1) +
                          (((left2) ^ (right2)) & (low_bits)));
            output[17] = (((tail0) & (tail1)) + ((((tail0) ^ (tail1)) & (high_bits)) >> 1) +
                          (((tail0) ^ (tail1)) & (low_bits)));
            output += 2;
            if (row == 7) {
                output += 16;
            }
        }
        break;
    case 3:
        reference0 -= 3;
        reference1 -= 3;
        for (row = 0; row < 16; row++) {
            __dcbt((void *)reference1, stride);
            left1 = ((const u32 *)reference0)[1];
            right1 = ((const u32 *)reference1)[1];
            left2 = ((const u32 *)reference0)[2];
            right2 = ((const u32 *)reference1)[2];
            left3 = ((const u32 *)reference0)[3];
            right3 = ((const u32 *)reference1)[3];
            tail0 = ((const u32 *)reference0)[4];
            tail1 = ((const u32 *)reference1)[4];
            left0 = ((const u32 *)reference0)[0];
            reference0 += stride;
            right0 = ((const u32 *)reference1)[0];
            reference1 += stride;
            left0 = (left0 << 24) | (left1 >> 8);
            right0 = (right0 << 24) | (right1 >> 8);
            left1 = (left1 << 24) | (left2 >> 8);
            right1 = (right1 << 24) | (right2 >> 8);
            left2 = (left2 << 24) | (left3 >> 8);
            right2 = (right2 << 24) | (right3 >> 8);
            tail0 = (left3 << 24) | (tail0 >> 8);
            tail1 = (right3 << 24) | (tail1 >> 8);
            output[0] = (((left0) & (right0)) + ((((left0) ^ (right0)) & (high_bits)) >> 1) +
                         (((left0) ^ (right0)) & (low_bits)));
            output[1] = (((left1) & (right1)) + ((((left1) ^ (right1)) & (high_bits)) >> 1) +
                         (((left1) ^ (right1)) & (low_bits)));
            output[16] = (((left2) & (right2)) + ((((left2) ^ (right2)) & (high_bits)) >> 1) +
                          (((left2) ^ (right2)) & (low_bits)));
            output[17] = (((tail0) & (tail1)) + ((((tail0) ^ (tail1)) & (high_bits)) >> 1) +
                          (((tail0) ^ (tail1)) & (low_bits)));
            output += 2;
            if (row == 7) {
                output += 16;
            }
        }
        break;
    }
}
