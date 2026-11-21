#include <types.h>
#include <dolphin/gx/GXPriv.h>
void GXGetVtxDesc(GXAttr attr, GXAttrType *type) {
    u32 cpType;
    switch (attr) {
    case GX_VA_PNMTXIDX:
        cpType = ((int)((gx->vcdLo) >> (0)) & ((1 << (1)) - 1));
        break;
    case GX_VA_TEX0MTXIDX:
        cpType = ((int)((gx->vcdLo) >> (1)) & ((1 << (1)) - 1));
        break;
    case GX_VA_TEX1MTXIDX:
        cpType = ((int)((gx->vcdLo) >> (2)) & ((1 << (1)) - 1));
        break;
    case GX_VA_TEX2MTXIDX:
        cpType = ((int)((gx->vcdLo) >> (3)) & ((1 << (1)) - 1));
        break;
    case GX_VA_TEX3MTXIDX:
        cpType = ((int)((gx->vcdLo) >> (4)) & ((1 << (1)) - 1));
        break;
    case GX_VA_TEX4MTXIDX:
        cpType = ((int)((gx->vcdLo) >> (5)) & ((1 << (1)) - 1));
        break;
    case GX_VA_TEX5MTXIDX:
        cpType = ((int)((gx->vcdLo) >> (6)) & ((1 << (1)) - 1));
        break;
    case GX_VA_TEX6MTXIDX:
        cpType = ((int)((gx->vcdLo) >> (7)) & ((1 << (1)) - 1));
        break;
    case GX_VA_TEX7MTXIDX:
        cpType = ((int)((gx->vcdLo) >> (8)) & ((1 << (1)) - 1));
        break;
    case GX_VA_POS:
        cpType = ((int)((gx->vcdLo) >> (9)) & ((1 << (2)) - 1));
        break;
    case GX_VA_NRM:
        cpType = gx->hasNrms ? ((int)((gx->vcdLo) >> (11)) & ((1 << (2)) - 1)) : 0;
        break;
    case GX_VA_NBT:
        cpType = gx->hasBiNrms ? ((int)((gx->vcdLo) >> (11)) & ((1 << (2)) - 1)) : 0;
        break;
    case GX_VA_CLR0:
        cpType = ((int)((gx->vcdLo) >> (13)) & ((1 << (2)) - 1));
        break;
    case GX_VA_CLR1:
        cpType = ((int)((gx->vcdLo) >> (15)) & ((1 << (2)) - 1));
        break;
    case GX_VA_TEX0:
        cpType = ((int)((gx->vcdHi) >> (0)) & ((1 << (2)) - 1));
        break;
    case GX_VA_TEX1:
        cpType = ((int)((gx->vcdHi) >> (2)) & ((1 << (2)) - 1));
        break;
    case GX_VA_TEX2:
        cpType = ((int)((gx->vcdHi) >> (4)) & ((1 << (2)) - 1));
        break;
    case GX_VA_TEX3:
        cpType = ((int)((gx->vcdHi) >> (6)) & ((1 << (2)) - 1));
        break;
    case GX_VA_TEX4:
        cpType = ((int)((gx->vcdHi) >> (8)) & ((1 << (2)) - 1));
        break;
    case GX_VA_TEX5:
        cpType = ((int)((gx->vcdHi) >> (10)) & ((1 << (2)) - 1));
        break;
    case GX_VA_TEX6:
        cpType = ((int)((gx->vcdHi) >> (12)) & ((1 << (2)) - 1));
        break;
    case GX_VA_TEX7:
        cpType = ((int)((gx->vcdHi) >> (14)) & ((1 << (2)) - 1));
        break;
    default:
        cpType = 0;
        break;
    }
    *type = cpType;
}
