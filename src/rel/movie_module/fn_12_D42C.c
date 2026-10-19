
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

void fn_12_D42C(MPVMCContext *context);

void fn_12_D42C(MPVMCContext *context) {
    s32 row;
    s32 stride;
    const u8 *reference0;
    const u8 *reference1;
    u32 *destination;
    s32 top0, bottom0, top1, bottom1, top2, bottom2;
    u32 sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7;
    stride = context->reference_stride;
    reference0 = context->reference0;
    reference1 = context->reference1;
    destination = (u32 *)context->destination;
    for (row = 0; row < 8; row++) {
        top0 = reference0[0];
        bottom0 = reference1[0];
        __dcbt((void *)reference1, stride);
        top1 = reference0[1];
        bottom1 = reference1[1];
        sum0 = (u32)top0 + (u32)top1 + (u32)bottom0 + (u32)bottom1 + 2;
        top2 = reference0[2];
        bottom2 = reference1[2];
        sum1 = (u32)top1 + (u32)top2 + (u32)bottom1 + (u32)bottom2 + 2;
        top0 = reference0[3];
        bottom0 = reference1[3];
        sum2 = (u32)top2 + (u32)top0 + (u32)bottom2 + (u32)bottom0 + 2;
        top1 = reference0[4];
        bottom1 = reference1[4];
        sum3 = (u32)top0 + (u32)top1 + (u32)bottom0 + (u32)bottom1 + 2;
        top2 = reference0[5];
        bottom2 = reference1[5];
        sum4 = (u32)top1 + (u32)top2 + (u32)bottom1 + (u32)bottom2 + 2;
        top0 = reference0[6];
        bottom0 = reference1[6];
        sum5 = (u32)top2 + (u32)top0 + (u32)bottom2 + (u32)bottom0 + 2;
        top1 = reference0[7];
        bottom1 = reference1[7];
        sum6 = (u32)top0 + (u32)top1 + (u32)bottom0 + (u32)bottom1 + 2;
        top2 = reference0[8];
        bottom2 = reference1[8];
        sum7 = (u32)top1 + (u32)top2 + (u32)bottom1 + (u32)bottom2 + 2;
        destination[0] = (((sum0 << 22) & 0xFF000000) | ((sum1 << 14) & 0x00FF0000) |
                          ((sum2 << 6) & 0x0000FF00) | ((sum3 >> 2) & 0x000000FF));
        destination[1] = (((sum4 << 22) & 0xFF000000) | ((sum5 << 14) & 0x00FF0000) |
                          ((sum6 << 6) & 0x0000FF00) | ((sum7 >> 2) & 0x000000FF));
        reference0 += stride;
        reference1 += stride;
        destination += 2;
    }
}
