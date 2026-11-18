#include "types.h"

union FpscrUnion {
    f64 f;
    struct {
        u32 fpscr_pad;
        u32 fpscr;
    } u;
};

/* Original Dolphin SDK base/PPCArch.c mixed C + inline asm (mtfsf). */
void PPCMtfpscr(register u32 newFPSCR) {
    union FpscrUnion m;

    asm {
        li r4, 0
        stw r4, m.u.fpscr_pad
        stw newFPSCR, m.u.fpscr
        lfd f31, m.f
        mtfsf 255, f31
    }
}
