/* Non-matching: best partial attempt (88.72% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

#pragma use_lmw_stmw on

extern const s32 lbl_800911E0[16];

#define CLAMP16(x)                                   \
    if ((x) > 0x7fff || (x) < -0x8000) {             \
        if ((x) < -0x8000) {                         \
            (x) = -0x8000;                           \
        } else if ((x) > 0x7fff) {                   \
            (x) = 0x7fff;                            \
        }                                            \
    }

static inline const s32 fn_8004F00C_array_read(const s32 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
static inline u8 *fn_8004F00C_array_read_(u8 *array) { return array; }
#pragma opt_lifetimes off
s32 fn_8004F00C(u8 *src, s32 n, s16 *out_l, s16 *hist_l, s16 *out_r, s16 *hist_r, s16 c1, s16 c2,
                s16 *seed, s16 mul, s16 add)
{
    s32 l1;
    s32 r1;
    s32 r0;
    s32 l0;
    s32 hdr_2;
    s32 b;
    s32 blocks;
    s32 hdr;
    s16 scale_r;
    s32 k;
    s16 scale_l;
    s32 tmp_cse1;
    s32 nl, nr;

    blocks = n / 2;
    l0 = hist_l[0];
    l1 = hist_l[1];
    r0 = hist_r[0];
    r1 = hist_r[1];
    for (b = 0; b < blocks; b++) {
        hdr = *(s16 *)src;
        if (hdr & 0x8000) {
            tmp_cse1 = b * 2;
            return tmp_cse1;
        }
        k = *seed;
        *seed = k * mul + add;
        *seed &= 0x7fff;
        scale_l = ((hdr ^ k) & 0x1fff) + 1;
        hdr_2 = *(s16 *)(src + 0x12);
        if (hdr_2 & 0x8000) {
            return tmp_cse1;
        }
        k = *seed;
        *seed = k * mul + add;
        *seed &= 0x7fff;
        scale_r = ((((((hdr_2)) ^ ((k))))) & 0x1fff) + 1;
        src += 2;
        for (k = 0; k < 16; k++) {
            s8 bl = (s8)fn_8004F00C_array_read_(src)[0];
            s32 br = (s8)fn_8004F00C_array_read_(src)[0x12];
            src++;
            l1 = (bl >> 4) * scale_l + ((c1 * l0 + c2 * l1) >> 12);
            CLAMP16(l1);
            nr = ((scale_r) * ((br >> 4))) + ((c1 * r0 + c2 * r1) >> 12);
            CLAMP16(nr);
            out_l[0] = l1;
            out_r[0] = nr;
            l0 = fn_8004F00C_array_read(lbl_800911E0, bl & 0xf) * scale_l + ((c1 * l1 + c2 * l0) >> 12);
            CLAMP16(l0);
            r0 = fn_8004F00C_array_read(lbl_800911E0, br & 0xf) * scale_r + ((c1 * nr + c2 * r0) >> 12);
            CLAMP16(r0);
            out_l[1] = l0;
            r1 = nr;
            out_l += 2;
            out_r[1] = r0;
            out_r += 2;
        }
        src += 0x12;
    }
    hist_l[0] = l0;
    hist_l[1] = l1;
    hist_r[0] = r0;
    hist_r[1] = r1;
    return n;
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

