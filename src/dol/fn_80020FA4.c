#include "types.h"

extern u8 lbl_8015D200[];
extern void (*lbl_801A6AC0)(void *, u32);
extern void (*lbl_801A6AC4)(void *, u32);
extern u32 lbl_801A6AC8;
extern u32 lbl_801A6ACC;
extern u8 *lbl_801A6AD0;
extern u8 *lbl_801A6AD4;
extern u8 *lbl_801A6AD4__fzgx_offset_4;
extern u32 lbl_801A6ADC;
extern u32 lbl_801A6AE0;
extern u32 lbl_801A6AE4;
extern u32 lbl_801A6AE8;
extern u32 lbl_801A6AEC;
extern u32 lbl_801A6AF0;
extern u32 lbl_801A6B08;
extern void DCInvalidateRange(void *, u32);
extern void DCFlushRangeNoSync(void *, u32);

#pragma opt_propagation off
static inline u8 * fn_80020FA4_address_685(u8 * base, s32 offset) {
    u8 * result;
    result = (u8 *)offset;
    result = base + (s32)result;
    return result;
}
void fn_80020FA4(void) {
    u8 *base = (u8 *)&lbl_8015D200;
    u8 *v0;
    u8 *v1;
    u8 *a[4];
    u8 *b[3];
    u8 *c[3];

    v0 = fn_80020FA4_address_685(base, lbl_801A6AE0 * 1920);
    v1 = base + lbl_801A6AE4 * 1920;
    lbl_801A6AD0 = v0;
    lbl_801A6AD4 = v1;
    lbl_801A6AD4__fzgx_offset_4 = v0 + 5760;
    lbl_801A6ADC = (u32)(v1 + 5760);

    if (lbl_801A6AC0 != 0) {
        if (lbl_801A6B08 == 2) {
            u8 *p = base + lbl_801A6AF0 * 1920;
            a[0] = p;
            a[1] = p + 0x280;
            a[2] = ((0x500) + (p));
            a[3] = p + 0x1b80;
            DCInvalidateRange(((0)[a]), 0x780);
            DCInvalidateRange(a[3], 0x280);
            lbl_801A6AC0(a, lbl_801A6AC8);
            DCFlushRangeNoSync(a[0], 0x780);
            DCFlushRangeNoSync(a[3], 0x280);
        } else {
            u8 *p = base + lbl_801A6AF0 * 1920;
            b[0] = p;
            b[1] = p + 0x280;
            b[2] = p + 0x500;
            DCInvalidateRange(b[0], 0x780);
            lbl_801A6AC0(b, lbl_801A6AC8);
            DCFlushRangeNoSync(b[0], 0x780);
        }
    }
    if (lbl_801A6AC4 != 0 && lbl_801A6B08 != 2) {
        u8 *p = base + lbl_801A6AF0 * 1920;
        p += 5760;
        c[0] = p;
        c[1] = p + 0x280;
        c[2] = p + 0x500;
        DCInvalidateRange(c[0], 0x780);
        lbl_801A6AC4(c, lbl_801A6ACC);
        DCFlushRangeNoSync(((0)[c]), 0x780);
    }
    lbl_801A6AE0 += 1;
    lbl_801A6AE0 %= 3;
    lbl_801A6AE4 += 1;
    lbl_801A6AE4 %= 3;
    lbl_801A6AE8 += 1;
    lbl_801A6AE8 &= 1;
    lbl_801A6AEC += 1;
    lbl_801A6AEC &= 1;
    lbl_801A6AF0 += 1;
    lbl_801A6AF0 %= 3;
}
#pragma opt_propagation reset
