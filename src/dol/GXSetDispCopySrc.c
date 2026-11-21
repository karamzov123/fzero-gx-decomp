#include <types.h>
#include <dolphin/gx/GXPriv.h>
void GXSetDispCopySrc(u16 left, u16 top, u16 width, u16 height) {
    gx->cpDispSrc = 0;
    (gx->cpDispSrc) = (gx->cpDispSrc & ~(((1 << (10)) - 1) << (31 - (22) - (10) + 1))) |
                      ((int)(left) << (31 - (22) - (10) + 1));
    (gx->cpDispSrc) = (gx->cpDispSrc & ~(((1 << (10)) - 1) << (31 - (12) - (10) + 1))) |
                      ((int)(top) << (31 - (12) - (10) + 1));
    (gx->cpDispSrc) = (gx->cpDispSrc & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                      ((int)(73) << (31 - (0) - (8) + 1));
    gx->cpDispSize = 0;
    (gx->cpDispSize) = (gx->cpDispSize & ~(((1 << (10)) - 1) << (31 - (22) - (10) + 1))) |
                       ((int)(width - 1) << (31 - (22) - (10) + 1));
    (gx->cpDispSize) = (gx->cpDispSize & ~(((1 << (10)) - 1) << (31 - (12) - (10) + 1))) |
                       ((int)(height - 1) << (31 - (12) - (10) + 1));
    (gx->cpDispSize) = (gx->cpDispSize & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                       ((int)(74) << (31 - (0) - (8) + 1));
}
