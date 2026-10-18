
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
