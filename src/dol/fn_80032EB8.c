#include "types.h"
#include <types.h>
#include <dolphin/gx/GXPriv.h>

/* --- dol/fn_80032EB8.c --- */
extern void GXGetVtxDesc(int attr, u32 *type);

void fn_80032EB8(u32 fmt) {
    int attr;

    for (attr = 0; attr <= 20; attr++) {
        *(u32 *)(fmt + attr * 8) = attr;
        GXGetVtxDesc(attr, (u32 *)(fmt + attr * 8 + 4));
    }
    *(u32 *)(fmt + attr * 8) = 25;
    GXGetVtxDesc(25, (u32 *)(fmt + attr * 8 + 4));
    *(u32 *)(fmt + ++attr * 8) = 255;
}

/* --- dol/GXClearVtxDesc.c --- */
void GXClearVtxDesc(void) {
    gx->vcdLo = 0;
    (gx->vcdLo) = (gx->vcdLo & ~(((1 << (2)) - 1) << (31 - (0x15) - (2) + 1))) |
                  ((int)(GX_DIRECT) << (31 - (0x15) - (2) + 1));
    gx->vcdHi = 0;
    gx->hasNrms = 0;
    gx->hasBiNrms = 0;
    gx->dirtyState |= GX_DIRTY_VCD;
}
