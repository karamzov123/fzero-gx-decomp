/* Non-matching: best partial attempt (37.73% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct MovieModule MovieModule;

struct MovieModule {
    u8 unk_000[0x4];
    u32 unk_4;
    u32 unk_8;
};

void fn_12_11CE0(MovieModule *arg0, void *arg1, u32 arg2) {
    u32 *dst = (u32 *)arg0->unk_4;
    u32 *ent = (u32 *)arg1 + 1;
    f64 *src = (f64 *)arg0->unk_8;
    s32 i;

    for (i = 0; i < 6; i++) {
        u32 out = ent[0];
        u32 stride = ent[1];
        u32 t = stride >> 3;
        u8 *o = (u8 *)out;
        s32 j;

        ent += 2;

        if ((s32)arg2 >= 0) {
            dst = (u32 *)((u8 *)dst + 0x80);
            if ((out & 0xf8000000) == 0) {
                u32 step = t << 3;
                u8 *q = o;

                *(f64 *)q = src[0];
                q += step;
                *(f64 *)q = src[1];
                q += step;
                *(f64 *)q = src[2];
                q += step;
                *(f64 *)q = src[3];
                q += step;
                *(f64 *)q = src[4];
                q += step;
                *(f64 *)q = src[5];
                q += step;
                *(f64 *)q = src[6];
                *(f64 *)(q + step) = src[7];
            } else {
                u32 step = t << 3;
                u8 *q = o;

                *(f64 *)q = src[0];
                q += step;
                *(f64 *)q = src[1];
                q += step;
                *(f64 *)q = src[2];
                q += step;
                *(f64 *)q = src[3];
                q += step;
                *(f64 *)q = src[4];
                q += step;
                *(f64 *)q = src[5];
                q += step;
                *(f64 *)q = src[6];
                q += step;
                *(f64 *)q = src[7];
            }
            src += 8;
        } else {
            for (j = 0; j < 4; j++) {
                psvec_add((void *)dst, (void *)src, (void *)o);
                o += stride;
                psvec_add((void *)((u8 *)dst + 0x10), (void *)((u8 *)src + 0x8),
                          (void *)o);
                o += stride;
                dst += 8;
                src += 2;
            }
        }
        arg2 <<= 1;
    }
}
