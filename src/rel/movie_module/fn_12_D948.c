
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

void fn_12_D948(MPVMCContext *context);

static inline u32 mpvmc_avg_masked(u32 w, u32 a, u32 m1, u32 m2) {
    u32 x = w ^ a;
    return (w & a) + ((x & m1) >> 1) + (x & m2);
}

void fn_12_D948(MPVMCContext *context) {
    s32 row;
    u32 *destination;
    const u8 *reference0;
    const u8 *reference1;
    s32 stride;
    u32 w0, a0, w1, a1, w2, a2;
    u32 m1 = 0xFEFEFEFE;
    u32 m2 = 0x01010101;
    reference0 = context->reference0;
    reference1 = context->reference1;
    destination = (u32 *)context->destination;
    stride = context->reference_stride;
    switch ((u32)reference0 & 3) {
    case 0:
        for (row = 0; row < 8; row++) {
            w0 = ((const u32 *)reference0)[0];
            a0 = ((const u32 *)reference1)[0];
            w1 = ((const u32 *)reference0)[1];
            a1 = ((const u32 *)reference1)[1];
            destination[0] = mpvmc_avg_masked(w0, a0, m1, m2);
            destination[1] = mpvmc_avg_masked(w1, a1, m1, m2);
            reference0 += stride;
            reference1 += stride;
            destination += 2;
        }
        break;
    case 1:
        reference0 -= 1;
        reference1 -= 1;
        for (row = 0; row < 8; row++) {
            w1 = ((const u32 *)reference0)[1];
            a1 = ((const u32 *)reference1)[1];
            w0 = ((const u32 *)reference0)[0];
            w2 = reference0[8];
            reference0 += stride;
            a0 = ((const u32 *)reference1)[0];
            a2 = reference1[8];
            reference1 += stride;
            w0 = (w0 << 8) | (w1 >> 24);
            a0 = (a0 << 8) | (a1 >> 24);
            w2 = (w1 << 8) | w2;
            a2 = (a1 << 8) | a2;
            destination[0] = mpvmc_avg_masked(w0, a0, m1, m2);
            destination[1] = mpvmc_avg_masked(w2, a2, m1, m2);
            destination += 2;
        }
        break;
    case 2:
        reference0 -= 2;
        reference1 -= 2;
        for (row = 0; row < 8; row++) {
            w1 = ((const u32 *)reference0)[1];
            a1 = ((const u32 *)reference1)[1];
            w0 = ((const u32 *)reference0)[0];
            w2 = *(const u16 *)(reference0 + 8);
            reference0 += stride;
            a0 = ((const u32 *)reference1)[0];
            a2 = *(const u16 *)(reference1 + 8);
            reference1 += stride;
            w0 = (w0 << 16) | (w1 >> 16);
            a0 = (a0 << 16) | (a1 >> 16);
            w2 = (w1 << 16) | w2;
            a2 = (a1 << 16) | a2;
            destination[0] = mpvmc_avg_masked(w0, a0, m1, m2);
            destination[1] = mpvmc_avg_masked(w2, a2, m1, m2);
            destination += 2;
        }
        break;
    case 3:
        reference0 -= 3;
        reference1 -= 3;
        for (row = 0; row < 8; row++) {
            w1 = ((const u32 *)reference0)[1];
            a1 = ((const u32 *)reference1)[1];
            w0 = ((const u32 *)reference0)[0];
            w2 = ((const u32 *)reference0)[2];
            reference0 += stride;
            a0 = ((const u32 *)reference1)[0];
            a2 = ((const u32 *)reference1)[2];
            reference1 += stride;
            w0 = (w0 << 24) | (w1 >> 8);
            a0 = (a0 << 24) | (a1 >> 8);
            w2 = (w1 << 24) | (w2 >> 8);
            a2 = (a1 << 24) | (a2 >> 8);
            destination[0] = mpvmc_avg_masked(w0, a0, m1, m2);
            destination[1] = mpvmc_avg_masked(w2, a2, m1, m2);
            destination += 2;
        }
        break;
    }
}
