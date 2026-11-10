#include "types.h"
#include "sofdec/mpvmc_ppc_h2.h"

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

/* MPVMC08_OneRefH2: 8x8 chroma block from one reference with horizontal half-pel interpolation.
 * The kernel is chosen by the source address modulo 4 (see sofdec/mpvmc_ppc_h2.h). The register
 * variables are declared in the order that gives retail's registers. */
void fn_12_D55C(MPVMCContext *context) {
    register u32 y;
    register s32 stride;
    register u32 A;
    register u32 B;
    register u32 *d;
    register const u8 *s;
    register u32 C;
    register u32 D;
    register u32 x;
    register u32 m1;
    register u32 m2;
    s32 i;

    s = context->reference0;
    m1 = 0xFEFEFEFE;
    m2 = 0x01010101;
    d = (u32 *)context->destination;
    stride = context->reference_stride;
    switch ((u32)s & 3) {
    case 0:
        for (i = 0; i < 4; i++) {
            MPVMC08_H2_ROWS_AL0(s, stride, d, m1, m2, A, B, C, D, x, y);
        }
        break;
    case 1:
        s -= 1;
        for (i = 0; i < 4; i++) {
            MPVMC08_H2_ROWS_AL1(s, stride, d, m1, m2, A, B, C, D, x, y);
        }
        break;
    case 2:
        s -= 2;
        for (i = 0; i < 4; i++) {
            MPVMC08_H2_ROWS_AL2(s, stride, d, m1, m2, A, B, C, D, x, y);
        }
        break;
    case 3:
        s -= 3;
        for (i = 0; i < 4; i++) {
            MPVMC08_H2_ROWS_AL3(s, stride, d, m1, m2, A, B, C, D, x, y);
        }
        break;
    }
}
