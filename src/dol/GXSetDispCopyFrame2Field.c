#include <types.h>
#include <dolphin/gx/GXPriv.h>
void GXSetDispCopyFrame2Field(GXCopyMode arg0) {
    (gx->cpDisp) = (gx->cpDisp & ~(((1 << (2)) - 1) << (31 - (18) - (2) + 1))) |
                   ((int)(arg0) << (31 - (18) - (2) + 1));
    (gx->cpTex) = (gx->cpTex & ~(((1 << (2)) - 1) << (31 - (18) - (2) + 1))) |
                  ((int)(0) << (31 - (18) - (2) + 1));
}
