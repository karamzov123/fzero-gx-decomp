#include "types.h"
#include "sofdec/mpvmc_ppc.h"

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
