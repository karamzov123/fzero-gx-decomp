/* Non-matching: best partial attempt (38.84% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Dec {
    u8 pad_0[0x400];
    u8 *ptr;
    u8 pad_404[0x15];
    u8 flags;
} Dec;

extern u8 lbl_8008FF50[144];
extern const f64 lbl_801A7178;

s32 fn_80039E48(Dec *d) {
    f32 arr[64];
    f32 *dst;
    const f64 *c;
    u32 v;
    u16 id;
    u16 n;
    u16 i;
    u16 j;

    id = (d->ptr[0] << 8) | d->ptr[1];
    d->ptr += 2;
    n = id - 2;
    c = (const f64 *)&lbl_8008FF50[0x50];
    do {
        v = *d->ptr++;
        i = 0;
        do {
            arr[lbl_8008FF50[i + 0]] = (f32)(u32)*d->ptr++;
            arr[lbl_8008FF50[i + 1]] = (f32)(u32)*d->ptr++;
            arr[lbl_8008FF50[i + 2]] = (f32)(u32)*d->ptr++;
            arr[lbl_8008FF50[i + 3]] = (f32)(u32)*d->ptr++;
            arr[lbl_8008FF50[i + 4]] = (f32)(u32)*d->ptr++;
            arr[lbl_8008FF50[i + 5]] = (f32)(u32)*d->ptr++;
            arr[lbl_8008FF50[i + 6]] = (f32)(u32)*d->ptr++;
            arr[lbl_8008FF50[i + 7]] = (f32)(u32)*d->ptr++;
            i += 8;
        } while (i < 64);
        d->flags |= 1 << v;
        dst = (f32 *)((u8 *)d + (v << 8));
        i = 0;
        j = 0;
        do {
            dst[i + 0] = c[0] * (arr[i + 0] * c[j]);
            dst[i + 1] = c[1] * (arr[i + 1] * c[j]);
            dst[i + 2] = c[2] * (arr[i + 2] * c[j]);
            dst[i + 3] = c[3] * (arr[i + 3] * c[j]);
            dst[i + 4] = c[4] * (arr[i + 4] * c[j]);
            dst[i + 5] = c[5] * (arr[i + 5] * c[j]);
            dst[i + 6] = c[6] * (arr[i + 6] * c[j]);
            dst[i + 7] = c[7] * (arr[i + 7] * c[j]);
            i += 8;
            j++;
        } while (j < 8);
    } while (n -= 0x41);
    return 0;
}
