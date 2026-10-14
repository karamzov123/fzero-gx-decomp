/* Non-matching: best partial attempt (34.53% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct { u32 a, b, c, d; } Word4;

void fn_12_12324(void *arg0, void *arg1, void *arg2) {
    u8 *src = (u8 *)arg0;
    u32 *e = (u32 *)arg1 + 1;
    s32 i;
    u32 stride;
    u8 *dst;

    for (i = 6; i > 0; i--) {
        dst = *(u8 **)(e + 0);
        stride = e[1];
        e += 2;

        if (((u32)dst & 0x1F) == 0) {
            s32 j = 2;

            do {
                *(Word4 *)dst = *(Word4 *)(src + 0x00);
                dst += stride;
                *(Word4 *)dst = *(Word4 *)(src + 0x10);
                dst += stride;
                *(Word4 *)dst = *(Word4 *)(src + 0x20);
                dst += stride;
                *(Word4 *)dst = *(Word4 *)(src + 0x30);
                dst += stride;
                src += 0x40;
            } while (--j);
        } else {
            s32 j = 2;

            do {
                *(Word4 *)dst = *(Word4 *)(src + 0x00);
                dst += stride;
                *(Word4 *)dst = *(Word4 *)(src + 0x10);
                dst += stride;
                *(Word4 *)dst = *(Word4 *)(src + 0x20);
                dst += stride;
                *(Word4 *)dst = *(Word4 *)(src + 0x30);
                dst += stride;
                src += 0x40;
            } while (--j);
        }
    }
}
