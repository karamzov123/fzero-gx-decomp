#include <types.h>
#include <dolphin/gx/GXPriv.h>
static inline void SETVCDATTR(GXAttr attr, GXAttrType type) {
    switch (attr) {
    case GX_VA_PNMTXIDX:
        (gx->vcdLo) =
            (gx->vcdLo &
             ~(((1 << ((GX_CP_VCD_LO_POSMTXIDX_END - GX_CP_VCD_LO_POSMTXIDX_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_LO_POSMTXIDX_ST) -
                   ((GX_CP_VCD_LO_POSMTXIDX_END - GX_CP_VCD_LO_POSMTXIDX_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_LO_POSMTXIDX_ST) -
                             ((GX_CP_VCD_LO_POSMTXIDX_END - GX_CP_VCD_LO_POSMTXIDX_ST + 1)) + 1));
        break;
    case GX_VA_TEX0MTXIDX:
        (gx->vcdLo) =
            (gx->vcdLo &
             ~(((1 << ((GX_CP_VCD_LO_TEX0MTXIDX_END - GX_CP_VCD_LO_TEX0MTXIDX_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_LO_TEX0MTXIDX_ST) -
                   ((GX_CP_VCD_LO_TEX0MTXIDX_END - GX_CP_VCD_LO_TEX0MTXIDX_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_LO_TEX0MTXIDX_ST) -
                             ((GX_CP_VCD_LO_TEX0MTXIDX_END - GX_CP_VCD_LO_TEX0MTXIDX_ST + 1)) + 1));
        break;
    case GX_VA_TEX1MTXIDX:
        (gx->vcdLo) =
            (gx->vcdLo &
             ~(((1 << ((GX_CP_VCD_LO_TEX1MTXIDX_END - GX_CP_VCD_LO_TEX1MTXIDX_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_LO_TEX1MTXIDX_ST) -
                   ((GX_CP_VCD_LO_TEX1MTXIDX_END - GX_CP_VCD_LO_TEX1MTXIDX_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_LO_TEX1MTXIDX_ST) -
                             ((GX_CP_VCD_LO_TEX1MTXIDX_END - GX_CP_VCD_LO_TEX1MTXIDX_ST + 1)) + 1));
        break;
    case GX_VA_TEX2MTXIDX:
        (gx->vcdLo) =
            (gx->vcdLo &
             ~(((1 << ((GX_CP_VCD_LO_TEX2MTXIDX_END - GX_CP_VCD_LO_TEX2MTXIDX_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_LO_TEX2MTXIDX_ST) -
                   ((GX_CP_VCD_LO_TEX2MTXIDX_END - GX_CP_VCD_LO_TEX2MTXIDX_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_LO_TEX2MTXIDX_ST) -
                             ((GX_CP_VCD_LO_TEX2MTXIDX_END - GX_CP_VCD_LO_TEX2MTXIDX_ST + 1)) + 1));
        break;
    case GX_VA_TEX3MTXIDX:
        (gx->vcdLo) =
            (gx->vcdLo &
             ~(((1 << ((GX_CP_VCD_LO_TEX3MTXIDX_END - GX_CP_VCD_LO_TEX3MTXIDX_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_LO_TEX3MTXIDX_ST) -
                   ((GX_CP_VCD_LO_TEX3MTXIDX_END - GX_CP_VCD_LO_TEX3MTXIDX_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_LO_TEX3MTXIDX_ST) -
                             ((GX_CP_VCD_LO_TEX3MTXIDX_END - GX_CP_VCD_LO_TEX3MTXIDX_ST + 1)) + 1));
        break;
    case GX_VA_TEX4MTXIDX:
        (gx->vcdLo) =
            (gx->vcdLo &
             ~(((1 << ((GX_CP_VCD_LO_TEX4MTXIDX_END - GX_CP_VCD_LO_TEX4MTXIDX_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_LO_TEX4MTXIDX_ST) -
                   ((GX_CP_VCD_LO_TEX4MTXIDX_END - GX_CP_VCD_LO_TEX4MTXIDX_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_LO_TEX4MTXIDX_ST) -
                             ((GX_CP_VCD_LO_TEX4MTXIDX_END - GX_CP_VCD_LO_TEX4MTXIDX_ST + 1)) + 1));
        break;
    case GX_VA_TEX5MTXIDX:
        (gx->vcdLo) =
            (gx->vcdLo &
             ~(((1 << ((GX_CP_VCD_LO_TEX5MTXIDX_END - GX_CP_VCD_LO_TEX5MTXIDX_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_LO_TEX5MTXIDX_ST) -
                   ((GX_CP_VCD_LO_TEX5MTXIDX_END - GX_CP_VCD_LO_TEX5MTXIDX_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_LO_TEX5MTXIDX_ST) -
                             ((GX_CP_VCD_LO_TEX5MTXIDX_END - GX_CP_VCD_LO_TEX5MTXIDX_ST + 1)) + 1));
        break;
    case GX_VA_TEX6MTXIDX:
        (gx->vcdLo) =
            (gx->vcdLo &
             ~(((1 << ((GX_CP_VCD_LO_TEX6MTXIDX_END - GX_CP_VCD_LO_TEX6MTXIDX_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_LO_TEX6MTXIDX_ST) -
                   ((GX_CP_VCD_LO_TEX6MTXIDX_END - GX_CP_VCD_LO_TEX6MTXIDX_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_LO_TEX6MTXIDX_ST) -
                             ((GX_CP_VCD_LO_TEX6MTXIDX_END - GX_CP_VCD_LO_TEX6MTXIDX_ST + 1)) + 1));
        break;
    case GX_VA_TEX7MTXIDX:
        (gx->vcdLo) =
            (gx->vcdLo &
             ~(((1 << ((GX_CP_VCD_LO_TEX7MTXIDX_END - GX_CP_VCD_LO_TEX7MTXIDX_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_LO_TEX7MTXIDX_ST) -
                   ((GX_CP_VCD_LO_TEX7MTXIDX_END - GX_CP_VCD_LO_TEX7MTXIDX_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_LO_TEX7MTXIDX_ST) -
                             ((GX_CP_VCD_LO_TEX7MTXIDX_END - GX_CP_VCD_LO_TEX7MTXIDX_ST + 1)) + 1));
        break;
    case GX_VA_POS:
        (gx->vcdLo) = (gx->vcdLo & ~(((1 << ((GX_CP_VCD_LO_POS_END - GX_CP_VCD_LO_POS_ST + 1))) - 1)
                                     << (31 - (GX_CP_VCD_LO_POS_ST) -
                                         ((GX_CP_VCD_LO_POS_END - GX_CP_VCD_LO_POS_ST + 1)) + 1))) |
                      ((int)(type) << (31 - (GX_CP_VCD_LO_POS_ST) -
                                       ((GX_CP_VCD_LO_POS_END - GX_CP_VCD_LO_POS_ST + 1)) + 1));
        break;
    case GX_VA_NRM:
        if (type != GX_NONE) {
            gx->hasNrms = 1;
            gx->hasBiNrms = 0;
            gx->nrmType = type;
        } else {
            gx->hasNrms = 0;
        }
        break;
    case GX_VA_NBT:
        if (type != GX_NONE) {
            gx->hasBiNrms = 1;
            gx->hasNrms = 0;
            gx->nrmType = type;
        } else {
            gx->hasBiNrms = 0;
        }
        break;
    case GX_VA_CLR0:
        (gx->vcdLo) =
            (gx->vcdLo & ~(((1 << ((GX_CP_VCD_LO_CLRDIF_END - GX_CP_VCD_LO_CLRDIF_ST + 1))) - 1)
                           << (31 - (GX_CP_VCD_LO_CLRDIF_ST) -
                               ((GX_CP_VCD_LO_CLRDIF_END - GX_CP_VCD_LO_CLRDIF_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_LO_CLRDIF_ST) -
                             ((GX_CP_VCD_LO_CLRDIF_END - GX_CP_VCD_LO_CLRDIF_ST + 1)) + 1));
        break;
    case GX_VA_CLR1:
        (gx->vcdLo) =
            (gx->vcdLo & ~(((1 << ((GX_CP_VCD_LO_CLRSPEC_END - GX_CP_VCD_LO_CLRSPEC_ST + 1))) - 1)
                           << (31 - (GX_CP_VCD_LO_CLRSPEC_ST) -
                               ((GX_CP_VCD_LO_CLRSPEC_END - GX_CP_VCD_LO_CLRSPEC_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_LO_CLRSPEC_ST) -
                             ((GX_CP_VCD_LO_CLRSPEC_END - GX_CP_VCD_LO_CLRSPEC_ST + 1)) + 1));
        break;
    case GX_VA_TEX0:
        (gx->vcdHi) =
            (gx->vcdHi &
             ~(((1 << ((GX_CP_VCD_HI_TEX0COORD_END - GX_CP_VCD_HI_TEX0COORD_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_HI_TEX0COORD_ST) -
                   ((GX_CP_VCD_HI_TEX0COORD_END - GX_CP_VCD_HI_TEX0COORD_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_HI_TEX0COORD_ST) -
                             ((GX_CP_VCD_HI_TEX0COORD_END - GX_CP_VCD_HI_TEX0COORD_ST + 1)) + 1));
        break;
    case GX_VA_TEX1:
        (gx->vcdHi) =
            (gx->vcdHi &
             ~(((1 << ((GX_CP_VCD_HI_TEX1COORD_END - GX_CP_VCD_HI_TEX1COORD_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_HI_TEX1COORD_ST) -
                   ((GX_CP_VCD_HI_TEX1COORD_END - GX_CP_VCD_HI_TEX1COORD_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_HI_TEX1COORD_ST) -
                             ((GX_CP_VCD_HI_TEX1COORD_END - GX_CP_VCD_HI_TEX1COORD_ST + 1)) + 1));
        break;
    case GX_VA_TEX2:
        (gx->vcdHi) =
            (gx->vcdHi &
             ~(((1 << ((GX_CP_VCD_HI_TEX2COORD_END - GX_CP_VCD_HI_TEX2COORD_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_HI_TEX2COORD_ST) -
                   ((GX_CP_VCD_HI_TEX2COORD_END - GX_CP_VCD_HI_TEX2COORD_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_HI_TEX2COORD_ST) -
                             ((GX_CP_VCD_HI_TEX2COORD_END - GX_CP_VCD_HI_TEX2COORD_ST + 1)) + 1));
        break;
    case GX_VA_TEX3:
        (gx->vcdHi) =
            (gx->vcdHi &
             ~(((1 << ((GX_CP_VCD_HI_TEX3COORD_END - GX_CP_VCD_HI_TEX3COORD_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_HI_TEX3COORD_ST) -
                   ((GX_CP_VCD_HI_TEX3COORD_END - GX_CP_VCD_HI_TEX3COORD_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_HI_TEX3COORD_ST) -
                             ((GX_CP_VCD_HI_TEX3COORD_END - GX_CP_VCD_HI_TEX3COORD_ST + 1)) + 1));
        break;
    case GX_VA_TEX4:
        (gx->vcdHi) =
            (gx->vcdHi &
             ~(((1 << ((GX_CP_VCD_HI_TEX4COORD_END - GX_CP_VCD_HI_TEX4COORD_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_HI_TEX4COORD_ST) -
                   ((GX_CP_VCD_HI_TEX4COORD_END - GX_CP_VCD_HI_TEX4COORD_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_HI_TEX4COORD_ST) -
                             ((GX_CP_VCD_HI_TEX4COORD_END - GX_CP_VCD_HI_TEX4COORD_ST + 1)) + 1));
        break;
    case GX_VA_TEX5:
        (gx->vcdHi) =
            (gx->vcdHi &
             ~(((1 << ((GX_CP_VCD_HI_TEX5COORD_END - GX_CP_VCD_HI_TEX5COORD_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_HI_TEX5COORD_ST) -
                   ((GX_CP_VCD_HI_TEX5COORD_END - GX_CP_VCD_HI_TEX5COORD_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_HI_TEX5COORD_ST) -
                             ((GX_CP_VCD_HI_TEX5COORD_END - GX_CP_VCD_HI_TEX5COORD_ST + 1)) + 1));
        break;
    case GX_VA_TEX6:
        (gx->vcdHi) =
            (gx->vcdHi &
             ~(((1 << ((GX_CP_VCD_HI_TEX6COORD_END - GX_CP_VCD_HI_TEX6COORD_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_HI_TEX6COORD_ST) -
                   ((GX_CP_VCD_HI_TEX6COORD_END - GX_CP_VCD_HI_TEX6COORD_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_HI_TEX6COORD_ST) -
                             ((GX_CP_VCD_HI_TEX6COORD_END - GX_CP_VCD_HI_TEX6COORD_ST + 1)) + 1));
        break;
    case GX_VA_TEX7:
        (gx->vcdHi) =
            (gx->vcdHi &
             ~(((1 << ((GX_CP_VCD_HI_TEX7COORD_END - GX_CP_VCD_HI_TEX7COORD_ST + 1))) - 1)
               << (31 - (GX_CP_VCD_HI_TEX7COORD_ST) -
                   ((GX_CP_VCD_HI_TEX7COORD_END - GX_CP_VCD_HI_TEX7COORD_ST + 1)) + 1))) |
            ((int)(type) << (31 - (GX_CP_VCD_HI_TEX7COORD_ST) -
                             ((GX_CP_VCD_HI_TEX7COORD_END - GX_CP_VCD_HI_TEX7COORD_ST + 1)) + 1));
        break;
    }
}

void GXSetVtxDescv(GXVtxDescList *list) {
    for (; list->attr != GX_VA_NULL; list++) {
        SETVCDATTR(list->attr, list->type);
    }
    if (gx->hasNrms || gx->hasBiNrms) {
        (gx->vcdLo) = (gx->vcdLo & ~(((1 << (2)) - 1) << (31 - (19) - (2) + 1))) |
                      ((int)(gx->nrmType) << (31 - (19) - (2) + 1));
    } else {
        (gx->vcdLo) = (gx->vcdLo & ~(((1 << (2)) - 1) << (31 - (19) - (2) + 1))) |
                      ((int)(0) << (31 - (19) - (2) + 1));
    }
    gx->dirtyState |= GX_DIRTY_VCD;
}
