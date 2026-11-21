#include <types.h>
#include <dolphin/gx/GXPriv.h>
void GXSetTexCopySrc(u16 left, u16 top, u16 width, u16 height) {
    gx->cpTexSrc = 0;
    (gx->cpTexSrc) = (gx->cpTexSrc & ~(((1 << (10)) - 1) << (31 - (22) - (10) + 1))) |
                     ((int)(left) << (31 - (22) - (10) + 1));
    (gx->cpTexSrc) = (gx->cpTexSrc & ~(((1 << (10)) - 1) << (31 - (12) - (10) + 1))) |
                     ((int)(top) << (31 - (12) - (10) + 1));
    (gx->cpTexSrc) = (gx->cpTexSrc & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                     ((int)(0x49) << (31 - (0) - (8) + 1));
    gx->cpTexSize = 0;
    (gx->cpTexSize) = (gx->cpTexSize & ~(((1 << (10)) - 1) << (31 - (22) - (10) + 1))) |
                      ((int)(width - 1) << (31 - (22) - (10) + 1));
    (gx->cpTexSize) = (gx->cpTexSize & ~(((1 << (10)) - 1) << (31 - (12) - (10) + 1))) |
                      ((int)(height - 1) << (31 - (12) - (10) + 1));
    (gx->cpTexSize) = (gx->cpTexSize & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                      ((int)(0x4A) << (31 - (0) - (8) + 1));
}
