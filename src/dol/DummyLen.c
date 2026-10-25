#include "types.h"

extern u32 OSGetTick(void);
// The seed is shared with other random-number users and must be observed at each access.
extern volatile u32 lbl_801A6510;

s32 DummyLen(void) {
    u32 v0;
    u32 v1;
    u32 v4;
    u32 v3;
    s32 v2;
    u32 v5;
    u32 v6;
    u32 t0, t1;
    u64 pad;

    v4 = 1;
    v2 = 0;
    t0 = OSGetTick();
    lbl_801A6510 = t0;
    v0 = 0x41C64E6D;
    v1 = (lbl_801A6510 * v0) + 12345;
    lbl_801A6510 = v1;
    v3 = ((lbl_801A6510 >> 16) & 0x1F) + 1;
    while ((s32)v3 < 4 && (u32)v2 < 10) {
        t1 = OSGetTick();
        v3 = t1;
        v5 = v3 << v4;
        v4++;
        if (v4 > 16) {
            v4 = 1;
        }
        lbl_801A6510 = v5;
        v2++;
        v3 = lbl_801A6510 * v0;
        v6 = v3 + 12345;
        lbl_801A6510 = v6;
        v3 = (lbl_801A6510 >> 16) & 0x1F;
        v3++;
    }
    if ((s32)v3 < 4) {
        v3 = 4;
    }
    return v3;
}
