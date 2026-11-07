#include "types.h"
#include "psvec_quant.h"

void fn_12_12324(u8 *src, u32 *table, void *unused) {
    u32 *q;
    s32 count;
    u32 stride;
    u8 *p;
    s32 i;

    q = table + 1;
    count = 6;
    do {
        p = (u8 *)q[0];
        stride = q[1];
        q += 2;
        if (((u32)p & 0x1F) == 0) {
            for (i = 2; i != 0; i--) {
                __dcbz(p, 0);
                psq3_row(src, p);
                p += stride;
                __dcbz(p, 0);
                psq3_row(src + 0x10, p);
                p += stride;
                __dcbz(p, 0);
                psq3_row(src + 0x20, p);
                p += stride;
                __dcbz(p, 0);
                psq3_row(src + 0x30, p);
                p += stride;
                src += 0x40;
            }
        } else {
            for (i = 2; i != 0; i--) {
                psq3_row(src, p);
                p += stride;
                psq3_row(src + 0x10, p);
                p += stride;
                psq3_row(src + 0x20, p);
                p += stride;
                psq3_row(src + 0x30, p);
                p += stride;
                src += 0x40;
            }
        }
    } while (--count > 0);
}
