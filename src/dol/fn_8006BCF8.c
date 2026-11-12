#include "types.h"

extern s32 lbl_801A6C98;
extern s16 lbl_8019E014[64];
extern s16 lbl_8019E094[64];
extern const f32 lbl_801A738C; /* 1024.0f: this function's own entry in the TU literal pool */
extern f64 fn_800883E8(f64);

/* Word-aligned clear: eight words per pass, then the byte tail. */
static inline void ClearAligned(u32 *p, u32 n) {
    u8 *c;
    u32 i;

    p--;
    i = n >> 5;
    do {
        *++p = 0;
        *++p = 0;
        *++p = 0;
        *++p = 0;
        *++p = 0;
        *++p = 0;
        *++p = 0;
        *++p = 0;
    } while (--i);
    n &= 3;
    c = (u8 *)(p + 1) - 1;
    if (n) {
        do {
            *++c = 0;
        } while (--n);
    }
}

#pragma optimize_for_size on
void fn_8006BCF8(void *arg0) {
    s32 j;

    ClearAligned(arg0, 0x40);
    if (lbl_801A6C98 == 0) {
        for (j = 0; j < 64; j++) {
            /* WARNING: compiler-diff device, not original code: the original statements are
             *     lbl_8019E014[j] = 1024.0f * (f32)fn_800883E8(3.1415927f * (f32)j / 128.0f);
             *     lbl_8019E094[j] = (j * 0x400) / 63;
             * The retail compiler's scheduler treated a float-literal load as possibly aliasing later
             * stores, so the 1024.0f load uncovers the ramp-table store and is issued before `frsp`.
             * The shipped GC/2.0p1 never creates that memory edge for a literal. The two accesses
             * marked below (the 1024.0f read and the ramp-table store) carry a qualifier that neither
             * object really has; the scheduler serialises such accesses against each other, which
             * rebuilds exactly that one edge. They add no instruction and change no operand. */
            lbl_8019E014[j] = *(const volatile f32 *)&lbl_801A738C /* WARNING: device, see above */
                              * (f32)fn_800883E8(3.1415927f * (f32)j / 128.0f);
            *(volatile s16 *)&lbl_8019E094[j] = (j * 0x400) / 63; /* WARNING: device, see above */
        }
        lbl_801A6C98 = 1;
    }
}
