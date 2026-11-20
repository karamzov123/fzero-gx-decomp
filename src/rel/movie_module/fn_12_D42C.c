#include "types.h"
#include "sofdec/mpvmc_ppc_h2.h"
#include "sofdec/mpvmc_ppc.h"


/* --- rel/movie_module/fn_12_D42C.c --- */
/* --- rel/movie_module/fn_12_D42C.c --- */
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

/* --- rel/movie_module/fn_12_D55C.c --- */
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

/* --- rel/movie_module/fn_12_D948.c --- */
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

/* --- rel/movie_module/fn_12_DC78.c --- */
/* MPVMC08_OneRef1p: copies an 8x8 chroma block from one reference with no interpolation. The kernel
 * is chosen by the source address modulo 8 (see sofdec/mpvmc_ppc.h). */
void fn_12_DC78(MPVMCContext *context) {
    register const u8 *s = context->reference0;
    __dcbt((void *)s, 0);
    switch ((u32)s & 7) {
    case 0: {
        MPVMC08_COPY_AL0(context, s);
        break;
    }
    case 4: {
        MPVMC08_COPY_AL4(context, s);
        break;
    }
    case 2:
    case 6: {
        MPVMC08_COPY_AL2(context, s);
        break;
    }
    case 1:
    case 5: {
        MPVMC08_COPY_AL1(context, s);
        break;
    }
    case 3:
    case 7: {
        MPVMC08_COPY_AL3(context, s);
        break;
    }
    }
}

/* --- rel/movie_module/fn_12_E0C8.c --- */
typedef struct {
    unsigned int field_0;
    unsigned int field_4;
    unsigned int field_8;
    unsigned int field_C;
} fn_12_E0C8_struct;

extern const fn_12_E0C8_struct lbl_12_rodata_928;

void fn_12_E0C8(fn_12_E0C8_struct *param) {
    *param = lbl_12_rodata_928;
}
