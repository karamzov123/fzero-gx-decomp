
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
