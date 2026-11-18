#include "types.h"

union FpscrUnion {
    f64 f;
    struct {
        u32 fpscr_pad;
        u32 fpscr;
    } u;
};

/* Original Dolphin SDK base/PPCArch.c mixed C + inline asm (mffs). */
u32 PPCMffpscr(void) {
    union FpscrUnion m;

    asm {
        mffs f31
        stfd f31, m.f
    }
    return m.u.fpscr;
}
