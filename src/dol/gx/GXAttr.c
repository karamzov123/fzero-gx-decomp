#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include "types.h"
#include <types.h>
#include "sdk_addresses.h"
#include "dolphin/hw_regs.h"

extern u32 lbl_801A6BF0;

u32 fn_80032360(void);

extern u32 lbl_801A6BF4;

u32 fn_80032368(void);

void __GXXfVtxSpecs(void) {
    u32 nCols = 0;
    u32 nNrm;
    u32 nTex;
    u32 reg;
    nCols = ((int)((gx->vcdLo) >> (13)) & ((1 << (2)) - 1)) ? 1 : 0;
    nCols += ((int)((gx->vcdLo) >> (15)) & ((1 << (2)) - 1)) ? 1 : 0;
    nNrm = gx->hasBiNrms ? 2 : gx->hasNrms ? 1 : 0;
    nTex = 0;
    nTex += ((int)((gx->vcdHi) >> (0)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (2)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (4)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (6)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (8)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (10)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (12)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (14)) & ((1 << (2)) - 1)) ? 1 : 0;
    reg = (nCols) | (nNrm << 2) | (nTex << 4);
    do {
        GXWGFifo.u8 = (u8)(0x10);
        GXWGFifo.u32 = (u32)(0x1000 + (8));
        GXWGFifo.u32 = (u32)(reg);
        ;
    } while (0);
    gx->bpSentNot = ((GXBool)1);
}

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

void GXSetVtxDesc(GXAttr name, GXAttrType type) {
    SETVCDATTR(name, type);
    if (gx->hasNrms || gx->hasBiNrms) {
        (gx->vcdLo) = (gx->vcdLo & ~(((1 << (2)) - 1) << (31 - (19) - (2) + 1))) |
                      ((int)(gx->nrmType) << (31 - (19) - (2) + 1));
    } else {
        (gx->vcdLo) = (gx->vcdLo & ~(((1 << (2)) - 1) << (31 - (19) - (2) + 1))) |
                      ((int)(0) << (31 - (19) - (2) + 1));
    }
    gx->dirtyState |= GX_DIRTY_VCD;
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

// Hardware or OS state can change asynchronously.

void __GXSetVCD(void) {
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_CP_REG;
    GXWGFifo.s8 = (GX_CP_REG_VCD_LO);
    GXWGFifo.s32 = (gx->vcdLo);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_CP_REG;
    GXWGFifo.s8 = (GX_CP_REG_VCD_HI);
    GXWGFifo.s32 = (gx->vcdHi);
    ;
    __GXXfVtxSpecs();
}

extern u8 lbl_801A6528[4];
extern u8 lbl_801A652C[4];
extern u8 lbl_801A6530[8];
void __GXCalculateVLim(void) {

    u32 vlim;
    u32 vcdLoReg;
    u32 vcdHiReg;
    s32 compCnt;
    if (gx->vNum == 0) {
        return;
    }
    vcdLoReg = gx->vcdLo;
    vcdHiReg = gx->vcdHi;
    compCnt = gx->vatA[GX_VTXFMT0];
    compCnt = (compCnt & 0x200) >> 9;
    vlim = ((vcdLoReg) >> (31 - (GX_CP_VCD_LO_POSMTXIDX_ST) -
                           ((GX_CP_VCD_LO_POSMTXIDX_END - GX_CP_VCD_LO_POSMTXIDX_ST + 1)) + 1) &
            ((1 << ((GX_CP_VCD_LO_POSMTXIDX_END - GX_CP_VCD_LO_POSMTXIDX_ST + 1))) - 1));
    vlim += ((vcdLoReg) >> (31 - (GX_CP_VCD_LO_TEX0MTXIDX_ST) -
                            ((GX_CP_VCD_LO_TEX0MTXIDX_END - GX_CP_VCD_LO_TEX0MTXIDX_ST + 1)) + 1) &
             ((1 << ((GX_CP_VCD_LO_TEX0MTXIDX_END - GX_CP_VCD_LO_TEX0MTXIDX_ST + 1))) - 1));
    vlim += ((vcdLoReg) >> (31 - (GX_CP_VCD_LO_TEX1MTXIDX_ST) -
                            ((GX_CP_VCD_LO_TEX1MTXIDX_END - GX_CP_VCD_LO_TEX1MTXIDX_ST + 1)) + 1) &
             ((1 << ((GX_CP_VCD_LO_TEX1MTXIDX_END - GX_CP_VCD_LO_TEX1MTXIDX_ST + 1))) - 1));
    vlim += ((vcdLoReg) >> (31 - (GX_CP_VCD_LO_TEX2MTXIDX_ST) -
                            ((GX_CP_VCD_LO_TEX2MTXIDX_END - GX_CP_VCD_LO_TEX2MTXIDX_ST + 1)) + 1) &
             ((1 << ((GX_CP_VCD_LO_TEX2MTXIDX_END - GX_CP_VCD_LO_TEX2MTXIDX_ST + 1))) - 1));
    vlim += ((vcdLoReg) >> (31 - (GX_CP_VCD_LO_TEX3MTXIDX_ST) -
                            ((GX_CP_VCD_LO_TEX3MTXIDX_END - GX_CP_VCD_LO_TEX3MTXIDX_ST + 1)) + 1) &
             ((1 << ((GX_CP_VCD_LO_TEX3MTXIDX_END - GX_CP_VCD_LO_TEX3MTXIDX_ST + 1))) - 1));
    vlim += ((vcdLoReg) >> (31 - (GX_CP_VCD_LO_TEX4MTXIDX_ST) -
                            ((GX_CP_VCD_LO_TEX4MTXIDX_END - GX_CP_VCD_LO_TEX4MTXIDX_ST + 1)) + 1) &
             ((1 << ((GX_CP_VCD_LO_TEX4MTXIDX_END - GX_CP_VCD_LO_TEX4MTXIDX_ST + 1))) - 1));
    vlim += ((vcdLoReg) >> (31 - (GX_CP_VCD_LO_TEX5MTXIDX_ST) -
                            ((GX_CP_VCD_LO_TEX5MTXIDX_END - GX_CP_VCD_LO_TEX5MTXIDX_ST + 1)) + 1) &
             ((1 << ((GX_CP_VCD_LO_TEX5MTXIDX_END - GX_CP_VCD_LO_TEX5MTXIDX_ST + 1))) - 1));
    vlim += ((vcdLoReg) >> (31 - (GX_CP_VCD_LO_TEX6MTXIDX_ST) -
                            ((GX_CP_VCD_LO_TEX6MTXIDX_END - GX_CP_VCD_LO_TEX6MTXIDX_ST + 1)) + 1) &
             ((1 << ((GX_CP_VCD_LO_TEX6MTXIDX_END - GX_CP_VCD_LO_TEX6MTXIDX_ST + 1))) - 1));
    vlim += ((vcdLoReg) >> (31 - (GX_CP_VCD_LO_TEX7MTXIDX_ST) -
                            ((GX_CP_VCD_LO_TEX7MTXIDX_END - GX_CP_VCD_LO_TEX7MTXIDX_ST + 1)) + 1) &
             ((1 << ((GX_CP_VCD_LO_TEX7MTXIDX_END - GX_CP_VCD_LO_TEX7MTXIDX_ST + 1))) - 1));
    vlim += lbl_801A6530[((vcdLoReg) >> (31 - (GX_CP_VCD_LO_POS_ST) -
                                         ((GX_CP_VCD_LO_POS_END - GX_CP_VCD_LO_POS_ST + 1)) + 1) &
                          ((1 << ((GX_CP_VCD_LO_POS_END - GX_CP_VCD_LO_POS_ST + 1))) - 1))];
    vlim += lbl_801A6530[((vcdLoReg) >> (31 - (GX_CP_VCD_LO_NRM_ST) -
                                         ((GX_CP_VCD_LO_NRM_END - GX_CP_VCD_LO_NRM_ST + 1)) + 1) &
                          ((1 << ((GX_CP_VCD_LO_NRM_END - GX_CP_VCD_LO_NRM_ST + 1))) - 1))] *
            (compCnt == GX_NRM_NBT ? 3 : 1);
    vlim +=
        lbl_801A6528[((vcdLoReg) >> (31 - (GX_CP_VCD_LO_CLRDIF_ST) -
                                     ((GX_CP_VCD_LO_CLRDIF_END - GX_CP_VCD_LO_CLRDIF_ST + 1)) + 1) &
                      ((1 << ((GX_CP_VCD_LO_CLRDIF_END - GX_CP_VCD_LO_CLRDIF_ST + 1))) - 1))];
    vlim += lbl_801A6528[((vcdLoReg) >>
                              (31 - (GX_CP_VCD_LO_CLRSPEC_ST) -
                               ((GX_CP_VCD_LO_CLRSPEC_END - GX_CP_VCD_LO_CLRSPEC_ST + 1)) + 1) &
                          ((1 << ((GX_CP_VCD_LO_CLRSPEC_END - GX_CP_VCD_LO_CLRSPEC_ST + 1))) - 1))];
    vlim += lbl_801A652C[(
        (vcdHiReg) >> (31 - (GX_CP_VCD_HI_TEX0COORD_ST) -
                       ((GX_CP_VCD_HI_TEX0COORD_END - GX_CP_VCD_HI_TEX0COORD_ST + 1)) + 1) &
        ((1 << ((GX_CP_VCD_HI_TEX0COORD_END - GX_CP_VCD_HI_TEX0COORD_ST + 1))) - 1))];
    vlim += lbl_801A652C[(
        (vcdHiReg) >> (31 - (GX_CP_VCD_HI_TEX1COORD_ST) -
                       ((GX_CP_VCD_HI_TEX1COORD_END - GX_CP_VCD_HI_TEX1COORD_ST + 1)) + 1) &
        ((1 << ((GX_CP_VCD_HI_TEX1COORD_END - GX_CP_VCD_HI_TEX1COORD_ST + 1))) - 1))];
    vlim += lbl_801A652C[(
        (vcdHiReg) >> (31 - (GX_CP_VCD_HI_TEX2COORD_ST) -
                       ((GX_CP_VCD_HI_TEX2COORD_END - GX_CP_VCD_HI_TEX2COORD_ST + 1)) + 1) &
        ((1 << ((GX_CP_VCD_HI_TEX2COORD_END - GX_CP_VCD_HI_TEX2COORD_ST + 1))) - 1))];
    vlim += lbl_801A652C[(
        (vcdHiReg) >> (31 - (GX_CP_VCD_HI_TEX3COORD_ST) -
                       ((GX_CP_VCD_HI_TEX3COORD_END - GX_CP_VCD_HI_TEX3COORD_ST + 1)) + 1) &
        ((1 << ((GX_CP_VCD_HI_TEX3COORD_END - GX_CP_VCD_HI_TEX3COORD_ST + 1))) - 1))];
    vlim += lbl_801A652C[(
        (vcdHiReg) >> (31 - (GX_CP_VCD_HI_TEX4COORD_ST) -
                       ((GX_CP_VCD_HI_TEX4COORD_END - GX_CP_VCD_HI_TEX4COORD_ST + 1)) + 1) &
        ((1 << ((GX_CP_VCD_HI_TEX4COORD_END - GX_CP_VCD_HI_TEX4COORD_ST + 1))) - 1))];
    vlim += lbl_801A652C[(
        (vcdHiReg) >> (31 - (GX_CP_VCD_HI_TEX5COORD_ST) -
                       ((GX_CP_VCD_HI_TEX5COORD_END - GX_CP_VCD_HI_TEX5COORD_ST + 1)) + 1) &
        ((1 << ((GX_CP_VCD_HI_TEX5COORD_END - GX_CP_VCD_HI_TEX5COORD_ST + 1))) - 1))];
    vlim += lbl_801A652C[(
        (vcdHiReg) >> (31 - (GX_CP_VCD_HI_TEX6COORD_ST) -
                       ((GX_CP_VCD_HI_TEX6COORD_END - GX_CP_VCD_HI_TEX6COORD_ST + 1)) + 1) &
        ((1 << ((GX_CP_VCD_HI_TEX6COORD_END - GX_CP_VCD_HI_TEX6COORD_ST + 1))) - 1))];
    vlim += lbl_801A652C[(
        (vcdHiReg) >> (31 - (GX_CP_VCD_HI_TEX7COORD_ST) -
                       ((GX_CP_VCD_HI_TEX7COORD_END - GX_CP_VCD_HI_TEX7COORD_ST + 1)) + 1) &
        ((1 << ((GX_CP_VCD_HI_TEX7COORD_END - GX_CP_VCD_HI_TEX7COORD_ST + 1))) - 1))];
    gx->vLim = vlim;
}

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

void fn_80032EB8(GXVtxDescList *vcd) {
    GXAttr attr;

    for (attr = GX_VA_PNMTXIDX; attr <= GX_VA_TEX7; attr++) {
        vcd[attr].attr = attr;
        GXGetVtxDesc(attr, &vcd[attr].type);
    }
    vcd[attr].attr = GX_VA_NBT;
    GXGetVtxDesc(GX_VA_NBT, &vcd[attr].type);
    attr++;
    vcd[attr].attr = GX_VA_NULL;
}

void GXClearVtxDesc(void) {
    gx->vcdLo = 0;
    (gx->vcdLo) = (gx->vcdLo & ~(((1 << (2)) - 1) << (31 - (0x15) - (2) + 1))) |
                  ((int)(GX_DIRECT) << (31 - (0x15) - (2) + 1));
    gx->vcdHi = 0;
    gx->hasNrms = 0;
    gx->hasBiNrms = 0;
    gx->dirtyState |= GX_DIRTY_VCD;
}

static inline void SETVAT(u32 *vatA, u32 *vatB, u32 *vatC, GXAttr attr, GXCompCnt compCnt,
                          GXCompType compType, u8 shift) {
    switch (attr) {
    case GX_VA_POS:
        (*vatA) =
            (*vatA & ~(((1 << ((GX_CP_VAT_GRP0_POS_CNT_END - GX_CP_VAT_GRP0_POS_CNT_ST + 1))) - 1)
                       << (31 - (GX_CP_VAT_GRP0_POS_CNT_ST) -
                           ((GX_CP_VAT_GRP0_POS_CNT_END - GX_CP_VAT_GRP0_POS_CNT_ST + 1)) + 1))) |
            ((int)(compCnt) << (31 - (GX_CP_VAT_GRP0_POS_CNT_ST) -
                                ((GX_CP_VAT_GRP0_POS_CNT_END - GX_CP_VAT_GRP0_POS_CNT_ST + 1)) +
                                1));
        (*vatA) =
            (*vatA & ~(((1 << ((GX_CP_VAT_GRP0_POS_TYPE_END - GX_CP_VAT_GRP0_POS_TYPE_ST + 1))) - 1)
                       << (31 - (GX_CP_VAT_GRP0_POS_TYPE_ST) -
                           ((GX_CP_VAT_GRP0_POS_TYPE_END - GX_CP_VAT_GRP0_POS_TYPE_ST + 1)) + 1))) |
            ((int)(compType) << (31 - (GX_CP_VAT_GRP0_POS_TYPE_ST) -
                                 ((GX_CP_VAT_GRP0_POS_TYPE_END - GX_CP_VAT_GRP0_POS_TYPE_ST + 1)) +
                                 1));
        (*vatA) =
            (*vatA &
             ~(((1 << ((GX_CP_VAT_GRP0_POS_SHIFT_END - GX_CP_VAT_GRP0_POS_SHIFT_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP0_POS_SHIFT_ST) -
                   ((GX_CP_VAT_GRP0_POS_SHIFT_END - GX_CP_VAT_GRP0_POS_SHIFT_ST + 1)) + 1))) |
            ((int)(shift) << (31 - (GX_CP_VAT_GRP0_POS_SHIFT_ST) -
                              ((GX_CP_VAT_GRP0_POS_SHIFT_END - GX_CP_VAT_GRP0_POS_SHIFT_ST + 1)) +
                              1));
        break;
    case GX_VA_NRM:
    case GX_VA_NBT:
        (*vatA) =
            (*vatA & ~(((1 << ((GX_CP_VAT_GRP0_NRM_TYPE_END - GX_CP_VAT_GRP0_NRM_TYPE_ST + 1))) - 1)
                       << (31 - (GX_CP_VAT_GRP0_NRM_TYPE_ST) -
                           ((GX_CP_VAT_GRP0_NRM_TYPE_END - GX_CP_VAT_GRP0_NRM_TYPE_ST + 1)) + 1))) |
            ((int)(compType) << (31 - (GX_CP_VAT_GRP0_NRM_TYPE_ST) -
                                 ((GX_CP_VAT_GRP0_NRM_TYPE_END - GX_CP_VAT_GRP0_NRM_TYPE_ST + 1)) +
                                 1));
        if (compCnt == GX_NRM_NBT3) {
            (*vatA) = (*vatA &
                       ~(((1 << ((GX_CP_VAT_GRP0_NRM_CNT_END - GX_CP_VAT_GRP0_NRM_CNT_ST + 1))) - 1)
                         << (31 - (GX_CP_VAT_GRP0_NRM_CNT_ST) -
                             ((GX_CP_VAT_GRP0_NRM_CNT_END - GX_CP_VAT_GRP0_NRM_CNT_ST + 1)) + 1))) |
                      ((int)(GX_NRM_NBT)
                       << (31 - (GX_CP_VAT_GRP0_NRM_CNT_ST) -
                           ((GX_CP_VAT_GRP0_NRM_CNT_END - GX_CP_VAT_GRP0_NRM_CNT_ST + 1)) + 1));
            (*vatA) =
                (*vatA &
                 ~(((1 << ((GX_CP_VAT_GRP0_NRMIDX3_END - GX_CP_VAT_GRP0_NRMIDX3_ST + 1))) - 1)
                   << (31 - (GX_CP_VAT_GRP0_NRMIDX3_ST) -
                       ((GX_CP_VAT_GRP0_NRMIDX3_END - GX_CP_VAT_GRP0_NRMIDX3_ST + 1)) + 1))) |
                ((int)(1) << (31 - (GX_CP_VAT_GRP0_NRMIDX3_ST) -
                              ((GX_CP_VAT_GRP0_NRMIDX3_END - GX_CP_VAT_GRP0_NRMIDX3_ST + 1)) + 1));
        } else {
            (*vatA) = (*vatA &
                       ~(((1 << ((GX_CP_VAT_GRP0_NRM_CNT_END - GX_CP_VAT_GRP0_NRM_CNT_ST + 1))) - 1)
                         << (31 - (GX_CP_VAT_GRP0_NRM_CNT_ST) -
                             ((GX_CP_VAT_GRP0_NRM_CNT_END - GX_CP_VAT_GRP0_NRM_CNT_ST + 1)) + 1))) |
                      ((int)(compCnt)
                       << (31 - (GX_CP_VAT_GRP0_NRM_CNT_ST) -
                           ((GX_CP_VAT_GRP0_NRM_CNT_END - GX_CP_VAT_GRP0_NRM_CNT_ST + 1)) + 1));
            (*vatA) =
                (*vatA &
                 ~(((1 << ((GX_CP_VAT_GRP0_NRMIDX3_END - GX_CP_VAT_GRP0_NRMIDX3_ST + 1))) - 1)
                   << (31 - (GX_CP_VAT_GRP0_NRMIDX3_ST) -
                       ((GX_CP_VAT_GRP0_NRMIDX3_END - GX_CP_VAT_GRP0_NRMIDX3_ST + 1)) + 1))) |
                ((int)(0) << (31 - (GX_CP_VAT_GRP0_NRMIDX3_ST) -
                              ((GX_CP_VAT_GRP0_NRMIDX3_END - GX_CP_VAT_GRP0_NRMIDX3_ST + 1)) + 1));
        }
        break;
    case GX_VA_CLR0:
        (*vatA) =
            (*vatA &
             ~(((1 << ((GX_CP_VAT_GRP0_CLRDIFF_CNT_END - GX_CP_VAT_GRP0_CLRDIFF_CNT_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP0_CLRDIFF_CNT_ST) -
                   ((GX_CP_VAT_GRP0_CLRDIFF_CNT_END - GX_CP_VAT_GRP0_CLRDIFF_CNT_ST + 1)) + 1))) |
            ((int)(compCnt)
             << (31 - (GX_CP_VAT_GRP0_CLRDIFF_CNT_ST) -
                 ((GX_CP_VAT_GRP0_CLRDIFF_CNT_END - GX_CP_VAT_GRP0_CLRDIFF_CNT_ST + 1)) + 1));
        (*vatA) =
            (*vatA &
             ~(((1 << ((GX_CP_VAT_GRP0_CLRDIFF_TYPE_END - GX_CP_VAT_GRP0_CLRDIFF_TYPE_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP0_CLRDIFF_TYPE_ST) -
                   ((GX_CP_VAT_GRP0_CLRDIFF_TYPE_END - GX_CP_VAT_GRP0_CLRDIFF_TYPE_ST + 1)) + 1))) |
            ((int)(compType)
             << (31 - (GX_CP_VAT_GRP0_CLRDIFF_TYPE_ST) -
                 ((GX_CP_VAT_GRP0_CLRDIFF_TYPE_END - GX_CP_VAT_GRP0_CLRDIFF_TYPE_ST + 1)) + 1));
        break;
    case GX_VA_CLR1:
        (*vatA) =
            (*vatA &
             ~(((1 << ((GX_CP_VAT_GRP0_CLRSPEC_CNT_END - GX_CP_VAT_GRP0_CLRSPEC_CNT_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP0_CLRSPEC_CNT_ST) -
                   ((GX_CP_VAT_GRP0_CLRSPEC_CNT_END - GX_CP_VAT_GRP0_CLRSPEC_CNT_ST + 1)) + 1))) |
            ((int)(compCnt)
             << (31 - (GX_CP_VAT_GRP0_CLRSPEC_CNT_ST) -
                 ((GX_CP_VAT_GRP0_CLRSPEC_CNT_END - GX_CP_VAT_GRP0_CLRSPEC_CNT_ST + 1)) + 1));
        (*vatA) =
            (*vatA &
             ~(((1 << ((GX_CP_VAT_GRP0_CLRSPEC_TYPE_END - GX_CP_VAT_GRP0_CLRSPEC_TYPE_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP0_CLRSPEC_TYPE_ST) -
                   ((GX_CP_VAT_GRP0_CLRSPEC_TYPE_END - GX_CP_VAT_GRP0_CLRSPEC_TYPE_ST + 1)) + 1))) |
            ((int)(compType)
             << (31 - (GX_CP_VAT_GRP0_CLRSPEC_TYPE_ST) -
                 ((GX_CP_VAT_GRP0_CLRSPEC_TYPE_END - GX_CP_VAT_GRP0_CLRSPEC_TYPE_ST + 1)) + 1));
        break;
    case GX_VA_TEX0:
        (*vatA) =
            (*vatA & ~(((1 << ((GX_CP_VAT_GRP0_TXC0_CNT_END - GX_CP_VAT_GRP0_TXC0_CNT_ST + 1))) - 1)
                       << (31 - (GX_CP_VAT_GRP0_TXC0_CNT_ST) -
                           ((GX_CP_VAT_GRP0_TXC0_CNT_END - GX_CP_VAT_GRP0_TXC0_CNT_ST + 1)) + 1))) |
            ((int)(compCnt) << (31 - (GX_CP_VAT_GRP0_TXC0_CNT_ST) -
                                ((GX_CP_VAT_GRP0_TXC0_CNT_END - GX_CP_VAT_GRP0_TXC0_CNT_ST + 1)) +
                                1));
        (*vatA) = (*vatA &
                   ~(((1 << ((GX_CP_VAT_GRP0_TXC0_TYPE_END - GX_CP_VAT_GRP0_TXC0_TYPE_ST + 1))) - 1)
                     << (31 - (GX_CP_VAT_GRP0_TXC0_TYPE_ST) -
                         ((GX_CP_VAT_GRP0_TXC0_TYPE_END - GX_CP_VAT_GRP0_TXC0_TYPE_ST + 1)) + 1))) |
                  ((int)(compType)
                   << (31 - (GX_CP_VAT_GRP0_TXC0_TYPE_ST) -
                       ((GX_CP_VAT_GRP0_TXC0_TYPE_END - GX_CP_VAT_GRP0_TXC0_TYPE_ST + 1)) + 1));
        (*vatA) =
            (*vatA &
             ~(((1 << ((GX_CP_VAT_GRP0_TXC0_SHIFT_END - GX_CP_VAT_GRP0_TXC0_SHIFT_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP0_TXC0_SHIFT_ST) -
                   ((GX_CP_VAT_GRP0_TXC0_SHIFT_END - GX_CP_VAT_GRP0_TXC0_SHIFT_ST + 1)) + 1))) |
            ((int)(shift) << (31 - (GX_CP_VAT_GRP0_TXC0_SHIFT_ST) -
                              ((GX_CP_VAT_GRP0_TXC0_SHIFT_END - GX_CP_VAT_GRP0_TXC0_SHIFT_ST + 1)) +
                              1));
        break;
    case GX_VA_TEX1:
        (*vatB) =
            (*vatB & ~(((1 << ((GX_CP_VAT_GRP1_TXC1_CNT_END - GX_CP_VAT_GRP1_TXC1_CNT_ST + 1))) - 1)
                       << (31 - (GX_CP_VAT_GRP1_TXC1_CNT_ST) -
                           ((GX_CP_VAT_GRP1_TXC1_CNT_END - GX_CP_VAT_GRP1_TXC1_CNT_ST + 1)) + 1))) |
            ((int)(compCnt) << (31 - (GX_CP_VAT_GRP1_TXC1_CNT_ST) -
                                ((GX_CP_VAT_GRP1_TXC1_CNT_END - GX_CP_VAT_GRP1_TXC1_CNT_ST + 1)) +
                                1));
        (*vatB) = (*vatB &
                   ~(((1 << ((GX_CP_VAT_GRP1_TXC1_TYPE_END - GX_CP_VAT_GRP1_TXC1_TYPE_ST + 1))) - 1)
                     << (31 - (GX_CP_VAT_GRP1_TXC1_TYPE_ST) -
                         ((GX_CP_VAT_GRP1_TXC1_TYPE_END - GX_CP_VAT_GRP1_TXC1_TYPE_ST + 1)) + 1))) |
                  ((int)(compType)
                   << (31 - (GX_CP_VAT_GRP1_TXC1_TYPE_ST) -
                       ((GX_CP_VAT_GRP1_TXC1_TYPE_END - GX_CP_VAT_GRP1_TXC1_TYPE_ST + 1)) + 1));
        (*vatB) =
            (*vatB &
             ~(((1 << ((GX_CP_VAT_GRP1_TXC1_SHIFT_END - GX_CP_VAT_GRP1_TXC1_SHIFT_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP1_TXC1_SHIFT_ST) -
                   ((GX_CP_VAT_GRP1_TXC1_SHIFT_END - GX_CP_VAT_GRP1_TXC1_SHIFT_ST + 1)) + 1))) |
            ((int)(shift) << (31 - (GX_CP_VAT_GRP1_TXC1_SHIFT_ST) -
                              ((GX_CP_VAT_GRP1_TXC1_SHIFT_END - GX_CP_VAT_GRP1_TXC1_SHIFT_ST + 1)) +
                              1));
        break;
    case GX_VA_TEX2:
        (*vatB) =
            (*vatB & ~(((1 << ((GX_CP_VAT_GRP1_TXC2_CNT_END - GX_CP_VAT_GRP1_TXC2_CNT_ST + 1))) - 1)
                       << (31 - (GX_CP_VAT_GRP1_TXC2_CNT_ST) -
                           ((GX_CP_VAT_GRP1_TXC2_CNT_END - GX_CP_VAT_GRP1_TXC2_CNT_ST + 1)) + 1))) |
            ((int)(compCnt) << (31 - (GX_CP_VAT_GRP1_TXC2_CNT_ST) -
                                ((GX_CP_VAT_GRP1_TXC2_CNT_END - GX_CP_VAT_GRP1_TXC2_CNT_ST + 1)) +
                                1));
        (*vatB) = (*vatB &
                   ~(((1 << ((GX_CP_VAT_GRP1_TXC2_TYPE_END - GX_CP_VAT_GRP1_TXC2_TYPE_ST + 1))) - 1)
                     << (31 - (GX_CP_VAT_GRP1_TXC2_TYPE_ST) -
                         ((GX_CP_VAT_GRP1_TXC2_TYPE_END - GX_CP_VAT_GRP1_TXC2_TYPE_ST + 1)) + 1))) |
                  ((int)(compType)
                   << (31 - (GX_CP_VAT_GRP1_TXC2_TYPE_ST) -
                       ((GX_CP_VAT_GRP1_TXC2_TYPE_END - GX_CP_VAT_GRP1_TXC2_TYPE_ST + 1)) + 1));
        (*vatB) =
            (*vatB &
             ~(((1 << ((GX_CP_VAT_GRP1_TXC2_SHIFT_END - GX_CP_VAT_GRP1_TXC2_SHIFT_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP1_TXC2_SHIFT_ST) -
                   ((GX_CP_VAT_GRP1_TXC2_SHIFT_END - GX_CP_VAT_GRP1_TXC2_SHIFT_ST + 1)) + 1))) |
            ((int)(shift) << (31 - (GX_CP_VAT_GRP1_TXC2_SHIFT_ST) -
                              ((GX_CP_VAT_GRP1_TXC2_SHIFT_END - GX_CP_VAT_GRP1_TXC2_SHIFT_ST + 1)) +
                              1));
        break;
    case GX_VA_TEX3:
        (*vatB) =
            (*vatB & ~(((1 << ((GX_CP_VAT_GRP1_TXC3_CNT_END - GX_CP_VAT_GRP1_TXC3_CNT_ST + 1))) - 1)
                       << (31 - (GX_CP_VAT_GRP1_TXC3_CNT_ST) -
                           ((GX_CP_VAT_GRP1_TXC3_CNT_END - GX_CP_VAT_GRP1_TXC3_CNT_ST + 1)) + 1))) |
            ((int)(compCnt) << (31 - (GX_CP_VAT_GRP1_TXC3_CNT_ST) -
                                ((GX_CP_VAT_GRP1_TXC3_CNT_END - GX_CP_VAT_GRP1_TXC3_CNT_ST + 1)) +
                                1));
        (*vatB) = (*vatB &
                   ~(((1 << ((GX_CP_VAT_GRP1_TXC3_TYPE_END - GX_CP_VAT_GRP1_TXC3_TYPE_ST + 1))) - 1)
                     << (31 - (GX_CP_VAT_GRP1_TXC3_TYPE_ST) -
                         ((GX_CP_VAT_GRP1_TXC3_TYPE_END - GX_CP_VAT_GRP1_TXC3_TYPE_ST + 1)) + 1))) |
                  ((int)(compType)
                   << (31 - (GX_CP_VAT_GRP1_TXC3_TYPE_ST) -
                       ((GX_CP_VAT_GRP1_TXC3_TYPE_END - GX_CP_VAT_GRP1_TXC3_TYPE_ST + 1)) + 1));
        (*vatB) =
            (*vatB &
             ~(((1 << ((GX_CP_VAT_GRP1_TXC3_SHIFT_END - GX_CP_VAT_GRP1_TXC3_SHIFT_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP1_TXC3_SHIFT_ST) -
                   ((GX_CP_VAT_GRP1_TXC3_SHIFT_END - GX_CP_VAT_GRP1_TXC3_SHIFT_ST + 1)) + 1))) |
            ((int)(shift) << (31 - (GX_CP_VAT_GRP1_TXC3_SHIFT_ST) -
                              ((GX_CP_VAT_GRP1_TXC3_SHIFT_END - GX_CP_VAT_GRP1_TXC3_SHIFT_ST + 1)) +
                              1));
        break;
    case GX_VA_TEX4:
        (*vatB) =
            (*vatB & ~(((1 << ((GX_CP_VAT_GRP1_TXC4_CNT_END - GX_CP_VAT_GRP1_TXC4_CNT_ST + 1))) - 1)
                       << (31 - (GX_CP_VAT_GRP1_TXC4_CNT_ST) -
                           ((GX_CP_VAT_GRP1_TXC4_CNT_END - GX_CP_VAT_GRP1_TXC4_CNT_ST + 1)) + 1))) |
            ((int)(compCnt) << (31 - (GX_CP_VAT_GRP1_TXC4_CNT_ST) -
                                ((GX_CP_VAT_GRP1_TXC4_CNT_END - GX_CP_VAT_GRP1_TXC4_CNT_ST + 1)) +
                                1));
        (*vatB) = (*vatB &
                   ~(((1 << ((GX_CP_VAT_GRP1_TXC4_TYPE_END - GX_CP_VAT_GRP1_TXC4_TYPE_ST + 1))) - 1)
                     << (31 - (GX_CP_VAT_GRP1_TXC4_TYPE_ST) -
                         ((GX_CP_VAT_GRP1_TXC4_TYPE_END - GX_CP_VAT_GRP1_TXC4_TYPE_ST + 1)) + 1))) |
                  ((int)(compType)
                   << (31 - (GX_CP_VAT_GRP1_TXC4_TYPE_ST) -
                       ((GX_CP_VAT_GRP1_TXC4_TYPE_END - GX_CP_VAT_GRP1_TXC4_TYPE_ST + 1)) + 1));
        (*vatC) =
            (*vatC &
             ~(((1 << ((GX_CP_VAT_GRP2_TXC4_SHIFT_END - GX_CP_VAT_GRP2_TXC4_SHIFT_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP2_TXC4_SHIFT_ST) -
                   ((GX_CP_VAT_GRP2_TXC4_SHIFT_END - GX_CP_VAT_GRP2_TXC4_SHIFT_ST + 1)) + 1))) |
            ((int)(shift) << (31 - (GX_CP_VAT_GRP2_TXC4_SHIFT_ST) -
                              ((GX_CP_VAT_GRP2_TXC4_SHIFT_END - GX_CP_VAT_GRP2_TXC4_SHIFT_ST + 1)) +
                              1));
        break;
    case GX_VA_TEX5:
        (*vatC) =
            (*vatC & ~(((1 << ((GX_CP_VAT_GRP2_TXC5_CNT_END - GX_CP_VAT_GRP2_TXC5_CNT_ST + 1))) - 1)
                       << (31 - (GX_CP_VAT_GRP2_TXC5_CNT_ST) -
                           ((GX_CP_VAT_GRP2_TXC5_CNT_END - GX_CP_VAT_GRP2_TXC5_CNT_ST + 1)) + 1))) |
            ((int)(compCnt) << (31 - (GX_CP_VAT_GRP2_TXC5_CNT_ST) -
                                ((GX_CP_VAT_GRP2_TXC5_CNT_END - GX_CP_VAT_GRP2_TXC5_CNT_ST + 1)) +
                                1));
        (*vatC) = (*vatC &
                   ~(((1 << ((GX_CP_VAT_GRP2_TXC5_TYPE_END - GX_CP_VAT_GRP2_TXC5_TYPE_ST + 1))) - 1)
                     << (31 - (GX_CP_VAT_GRP2_TXC5_TYPE_ST) -
                         ((GX_CP_VAT_GRP2_TXC5_TYPE_END - GX_CP_VAT_GRP2_TXC5_TYPE_ST + 1)) + 1))) |
                  ((int)(compType)
                   << (31 - (GX_CP_VAT_GRP2_TXC5_TYPE_ST) -
                       ((GX_CP_VAT_GRP2_TXC5_TYPE_END - GX_CP_VAT_GRP2_TXC5_TYPE_ST + 1)) + 1));
        (*vatC) =
            (*vatC &
             ~(((1 << ((GX_CP_VAT_GRP2_TXC5_SHIFT_END - GX_CP_VAT_GRP2_TXC5_SHIFT_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP2_TXC5_SHIFT_ST) -
                   ((GX_CP_VAT_GRP2_TXC5_SHIFT_END - GX_CP_VAT_GRP2_TXC5_SHIFT_ST + 1)) + 1))) |
            ((int)(shift) << (31 - (GX_CP_VAT_GRP2_TXC5_SHIFT_ST) -
                              ((GX_CP_VAT_GRP2_TXC5_SHIFT_END - GX_CP_VAT_GRP2_TXC5_SHIFT_ST + 1)) +
                              1));
        break;
    case GX_VA_TEX6:
        (*vatC) =
            (*vatC & ~(((1 << ((GX_CP_VAT_GRP2_TXC6_CNT_END - GX_CP_VAT_GRP2_TXC6_CNT_ST + 1))) - 1)
                       << (31 - (GX_CP_VAT_GRP2_TXC6_CNT_ST) -
                           ((GX_CP_VAT_GRP2_TXC6_CNT_END - GX_CP_VAT_GRP2_TXC6_CNT_ST + 1)) + 1))) |
            ((int)(compCnt) << (31 - (GX_CP_VAT_GRP2_TXC6_CNT_ST) -
                                ((GX_CP_VAT_GRP2_TXC6_CNT_END - GX_CP_VAT_GRP2_TXC6_CNT_ST + 1)) +
                                1));
        (*vatC) = (*vatC &
                   ~(((1 << ((GX_CP_VAT_GRP2_TXC6_TYPE_END - GX_CP_VAT_GRP2_TXC6_TYPE_ST + 1))) - 1)
                     << (31 - (GX_CP_VAT_GRP2_TXC6_TYPE_ST) -
                         ((GX_CP_VAT_GRP2_TXC6_TYPE_END - GX_CP_VAT_GRP2_TXC6_TYPE_ST + 1)) + 1))) |
                  ((int)(compType)
                   << (31 - (GX_CP_VAT_GRP2_TXC6_TYPE_ST) -
                       ((GX_CP_VAT_GRP2_TXC6_TYPE_END - GX_CP_VAT_GRP2_TXC6_TYPE_ST + 1)) + 1));
        (*vatC) =
            (*vatC &
             ~(((1 << ((GX_CP_VAT_GRP2_TXC6_SHIFT_END - GX_CP_VAT_GRP2_TXC6_SHIFT_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP2_TXC6_SHIFT_ST) -
                   ((GX_CP_VAT_GRP2_TXC6_SHIFT_END - GX_CP_VAT_GRP2_TXC6_SHIFT_ST + 1)) + 1))) |
            ((int)(shift) << (31 - (GX_CP_VAT_GRP2_TXC6_SHIFT_ST) -
                              ((GX_CP_VAT_GRP2_TXC6_SHIFT_END - GX_CP_VAT_GRP2_TXC6_SHIFT_ST + 1)) +
                              1));
        break;
    case GX_VA_TEX7:
        (*vatC) =
            (*vatC & ~(((1 << ((GX_CP_VAT_GRP2_TXC7_CNT_END - GX_CP_VAT_GRP2_TXC7_CNT_ST + 1))) - 1)
                       << (31 - (GX_CP_VAT_GRP2_TXC7_CNT_ST) -
                           ((GX_CP_VAT_GRP2_TXC7_CNT_END - GX_CP_VAT_GRP2_TXC7_CNT_ST + 1)) + 1))) |
            ((int)(compCnt) << (31 - (GX_CP_VAT_GRP2_TXC7_CNT_ST) -
                                ((GX_CP_VAT_GRP2_TXC7_CNT_END - GX_CP_VAT_GRP2_TXC7_CNT_ST + 1)) +
                                1));
        (*vatC) = (*vatC &
                   ~(((1 << ((GX_CP_VAT_GRP2_TXC7_TYPE_END - GX_CP_VAT_GRP2_TXC7_TYPE_ST + 1))) - 1)
                     << (31 - (GX_CP_VAT_GRP2_TXC7_TYPE_ST) -
                         ((GX_CP_VAT_GRP2_TXC7_TYPE_END - GX_CP_VAT_GRP2_TXC7_TYPE_ST + 1)) + 1))) |
                  ((int)(compType)
                   << (31 - (GX_CP_VAT_GRP2_TXC7_TYPE_ST) -
                       ((GX_CP_VAT_GRP2_TXC7_TYPE_END - GX_CP_VAT_GRP2_TXC7_TYPE_ST + 1)) + 1));
        (*vatC) =
            (*vatC &
             ~(((1 << ((GX_CP_VAT_GRP2_TXC7_SHIFT_END - GX_CP_VAT_GRP2_TXC7_SHIFT_ST + 1))) - 1)
               << (31 - (GX_CP_VAT_GRP2_TXC7_SHIFT_ST) -
                   ((GX_CP_VAT_GRP2_TXC7_SHIFT_END - GX_CP_VAT_GRP2_TXC7_SHIFT_ST + 1)) + 1))) |
            ((int)(shift) << (31 - (GX_CP_VAT_GRP2_TXC7_SHIFT_ST) -
                              ((GX_CP_VAT_GRP2_TXC7_SHIFT_END - GX_CP_VAT_GRP2_TXC7_SHIFT_ST + 1)) +
                              1));
        break;
    }
}

void GXSetVtxAttrFmt(GXVtxFmt format, GXAttr attr, GXCompCnt count, GXCompType type, u8 frac) {
    u32 *vA = (u32 *)&gx->vatA[format];
    u32 *vB = (u32 *)&gx->vatB[format];
    u32 *vC = &gx->vatC[format];
    SETVAT(vA, vB, vC, attr, count, type, frac);
    gx->dirtyState |= GX_DIRTY_VAT;
    gx->dirtyVAT |= (u8)(1 << (u8)format);
}

void GXSetVtxAttrFmtv(GXVtxFmt format, GXVtxAttrFmtList *list) {
    u32 *vatA;
    u32 *vatB;
    u32 *vatC;
    vatA = (u32 *)&gx->vatA[format];
    vatB = (u32 *)&gx->vatB[format];
    vatC = &gx->vatC[format];
    for (; list->attr != GX_VA_NULL; list++) {
        SETVAT(vatA, vatB, vatC, list->attr, list->cnt, list->type, list->frac);
    }
    gx->dirtyState |= GX_DIRTY_VAT;
    gx->dirtyVAT |= (u8)(1 << (u8)format);
}

void fn_80033650(void) {
    u8 i;

    for (i = 0; i < 8; i++) {
        if (gx->dirtyVAT & (1 << (u8)i)) {
            GXWGFifo.u8 = 8;
            GXWGFifo.u8 = i | 0x70;
            GXWGFifo.u32 = gx->vatA[i];
            GXWGFifo.u8 = 8;
            GXWGFifo.u8 = i | 0x80;
            GXWGFifo.u32 = gx->vatB[i];
            GXWGFifo.u8 = 8;
            GXWGFifo.u8 = i | 0x90;
            GXWGFifo.u32 = gx->vatC[i];
        }
    }
    gx->dirtyVAT = 0;
}

static inline u8 GetFracForNrm(GXCompType type) {
    u8 frac;
    switch (type) {
    case GX_S8:
        frac = 6;
        break;
    case GX_S16:
        frac = 14;
        break;
    default:
    case GX_U16:
        frac = 0;
        break;
    }
    return frac;
}

void GXGetVtxAttrFmt(GXVtxFmt fmt, int attr, GXCompCnt *cnt, GXCompType *type, u8 *frac) {
    u32 *va;
    u32 *vb;
    u32 *vc;
    va = &gx->vatA[fmt];
    vb = &gx->vatB[fmt];
    vc = &gx->vatC[fmt];
    switch (attr) {
    case GX_VA_POS:
        *cnt = ((int)((*va) >> (0)) & ((1 << (1)) - 1));
        *type = ((int)((*va) >> (1)) & ((1 << (3)) - 1));
        *frac = ((int)((*va) >> (4)) & ((1 << (5)) - 1));
        return;
    case GX_VA_NRM:
    case GX_VA_NBT:
        *cnt = ((int)((*va) >> (9)) & ((1 << (1)) - 1));
        if (*cnt == GX_TEX_ST && (u8)(*va >> 0x1F) != 0) {
            *cnt = GX_NRM_NBT3;
        }
        *type = ((int)((*va) >> (10)) & ((1 << (3)) - 1));
        *frac = GetFracForNrm(*type);
        return;
    case GX_VA_CLR0:
        *cnt = ((int)((*va) >> (13)) & ((1 << (1)) - 1));
        *type = ((int)((*va) >> (14)) & ((1 << (3)) - 1));
        *frac = 0;
        return;
    case GX_VA_CLR1:
        *cnt = ((int)((*va) >> (17)) & ((1 << (1)) - 1));
        *type = ((int)((*va) >> (18)) & ((1 << (3)) - 1));
        *frac = 0;
        return;
    case GX_VA_TEX0:
        *cnt = ((int)((*va) >> (21)) & ((1 << (1)) - 1));
        *type = ((int)((*va) >> (22)) & ((1 << (3)) - 1));
        *frac = (u8)(*va >> 0x19U) & 0x1F;
        return;
    case GX_VA_TEX1:
        *cnt = ((int)((*vb) >> (0)) & ((1 << (1)) - 1));
        *type = ((int)((*vb) >> (1)) & ((1 << (3)) - 1));
        *frac = (u8)(*vb >> 4U) & 0x1F;
        return;
    case GX_VA_TEX2:
        *cnt = ((int)((*vb) >> (9)) & ((1 << (1)) - 1));
        *type = ((int)((*vb) >> (10)) & ((1 << (3)) - 1));
        *frac = (u8)(*vb >> 0xDU) & 0x1F;
        return;
    case GX_VA_TEX3:
        *cnt = ((int)((*vb) >> (18)) & ((1 << (1)) - 1));
        *type = ((int)((*vb) >> (19)) & ((1 << (3)) - 1));
        *frac = (u8)(*vb >> 0x16U) & 0x1F;
        return;
    case GX_VA_TEX4:
        *cnt = ((int)((*vb) >> (27)) & ((1 << (1)) - 1));
        *type = ((int)((*vb) >> (28)) & ((1 << (3)) - 1));
        *frac = ((int)((*vc) >> (0)) & ((1 << (5)) - 1));
        return;
    case GX_VA_TEX5:
        *cnt = ((int)((*vc) >> (5)) & ((1 << (1)) - 1));
        *type = ((int)((*vc) >> (6)) & ((1 << (3)) - 1));
        *frac = (u8)(*vc >> 9U) & 0x1F;
        return;
    case GX_VA_TEX6:
        *cnt = ((int)((*vc) >> (14)) & ((1 << (1)) - 1));
        *type = ((int)((*vc) >> (15)) & ((1 << (3)) - 1));
        *frac = (u8)(*vc >> 0x12) & 0x1F;
        return;
    case GX_VA_TEX7:
        *cnt = ((int)((*vc) >> (23)) & ((1 << (1)) - 1));
        *type = ((int)((*vc) >> (24)) & ((1 << (3)) - 1));
        *frac = (int)(*vc >> 0x1BU);
        return;
    default:
        *cnt = GX_TEX_ST;
        *type = GX_RGB565;
        *frac = 0;
        return;
    }
}

void GXGetVtxAttrFmtv(GXVtxFmt vat, GXVtxAttrFmt *fmt) {
    int attr;

    for (attr = 9; attr <= 20; attr++) {
        fmt->attr = (u32)attr;
        GXGetVtxAttrFmt(vat, attr, &fmt->cnt, &fmt->type, &fmt->frac);
        fmt++;
    }
    fmt->attr = 0xff;
}

void GXSetArray(GXAttr attr, void *base_ptr, u8 stride) {
    GXAttr cpAttr;
    u32 phyAddr;
    if (attr == GX_VA_NBT) {
        attr = GX_VA_NRM;
    }
    cpAttr = attr - GX_VA_POS;
    phyAddr = (u32)base_ptr & 0x3FFFFFFF;
    do {
        long regAddr;
        GXWGFifo.u8 = (u8)(8);
        GXWGFifo.u8 = (u8)(cpAttr | GX_BP_REG_SETMODE0_TEX4);
        GXWGFifo.u32 = (u32)(phyAddr);
        regAddr = cpAttr - 12;
        if (regAddr >= 0 && regAddr < 4) {
            gx->indexBase[regAddr] = phyAddr;
        }
    } while (0);
    do {
        long regAddr;
        GXWGFifo.u8 = (u8)(8);
        GXWGFifo.u8 = (u8)(cpAttr | GX_BP_REG_SETIMAGE2_TEX4);
        GXWGFifo.u32 = (u32)(stride);
        regAddr = cpAttr - 12;
        if (regAddr >= 0 && regAddr < 4) {
            gx->indexStride[regAddr] = stride;
        }
    } while (0);
}

// Hardware FIFO register is intentionally volatile.

void GXInvalidateVtxCache(void) {
    GXWGFifo.u8 = 0x48;
}

void __GXSetMatrixIndex(GXAttr index);

void GXSetTexCoordGen2(GXTexCoordID dst_coord, GXTexGenType func, GXTexGenSrc src_param, u32 mtx,
                 GXBool normalize, u32 pt_texmtx) {
    u32 reg = 0;
    u32 row;
    u32 bumprow;
    u32 form;
    GXAttr mtxIdAttr;
    form = 0;
    row = 5;
    switch (src_param) {
    case GX_TG_POS:
        row = 0;
        form = 1;
        break;
    case GX_TG_NRM:
        row = 1;
        form = 1;
        break;
    case GX_TG_BINRM:
        row = 3;
        form = 1;
        break;
    case GX_TG_TANGENT:
        row = 4;
        form = 1;
        break;
    case GX_TG_COLOR0:
        row = 2;
        break;
    case GX_TG_COLOR1:
        row = 2;
        break;
    case GX_TG_TEX0:
        row = 5;
        break;
    case GX_TG_TEX1:
        row = 6;
        break;
    case GX_TG_TEX2:
        row = 7;
        break;
    case GX_TG_TEX3:
        row = 8;
        break;
    case GX_TG_TEX4:
        row = 9;
        break;
    case GX_TG_TEX5:
        row = 10;
        break;
    case GX_TG_TEX6:
        row = 11;
        break;
    case GX_TG_TEX7:
        row = 12;
        break;
    case GX_TG_TEXCOORD0:
        bumprow;
        break;
    case GX_TG_TEXCOORD1:
        bumprow;
        break;
    case GX_TG_TEXCOORD2:
        bumprow;
        break;
    case GX_TG_TEXCOORD3:
        bumprow;
        break;
    case GX_TG_TEXCOORD4:
        bumprow;
        break;
    case GX_TG_TEXCOORD5:
        bumprow;
        break;
    case GX_TG_TEXCOORD6:
        bumprow;
        break;
    default:
        break;
    }
    switch (func) {
    case GX_TG_MTX2x4:
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (1))) | ((u32)(0) << (1));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (2))) | ((u32)(form) << (2));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (4))) | ((u32)(0) << (4));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (5)) - 1) << (7))) | ((u32)(row) << (7));
        ;
        break;
    case GX_TG_MTX3x4:
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (1))) | ((u32)(1) << (1));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (2))) | ((u32)(form) << (2));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (4))) | ((u32)(0) << (4));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (5)) - 1) << (7))) | ((u32)(row) << (7));
        ;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (1))) | ((u32)(0) << (1));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (2))) | ((u32)(form) << (2));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (4))) | ((u32)(1) << (4));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (5)) - 1) << (7))) | ((u32)(row) << (7));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (12))) | ((u32)(src_param - 12) << (12));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (15))) | ((u32)(func - 2) << (15));
        ;
        break;
    case GX_TG_SRTG:
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (1))) | ((u32)(0) << (1));
        ;
        (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (2))) | ((u32)(form) << (2));
        ;
        if (src_param == GX_TG_COLOR0) {
            (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (4))) | ((u32)(2) << (4));
            ;
        } else {
            (reg) = ((u32)(reg) & ~(((1 << (3)) - 1) << (4))) | ((u32)(3) << (4));
            ;
        }
        (reg) = ((u32)(reg) & ~(((1 << (5)) - 1) << (7))) | ((u32)(2) << (7));
        ;
        break;
    default:
        break;
    }
    do {
        GXWGFifo.u8 = (u8)(0x10);
        GXWGFifo.u32 = (u32)(0x1000 + (dst_coord + 0x40));
        GXWGFifo.u32 = (u32)(reg);
        ;
    } while (0);
    reg = 0;
    (reg) = ((u32)(reg) & ~(((1 << (6)) - 1) << (0))) | ((u32)(pt_texmtx - 64) << (0));
    ;
    (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (8))) | ((u32)(normalize) << (8));
    ;
    do {
        GXWGFifo.u8 = (u8)(0x10);
        GXWGFifo.u32 = (u32)(0x1000 + (dst_coord + 0x50));
        GXWGFifo.u32 = (u32)(reg);
        ;
    } while (0);
    switch (dst_coord) {
    case GX_TEXCOORD0:
        (gx->matIdxA) = ((u32)(gx->matIdxA) & ~(((1 << (6)) - 1) << (6))) | ((u32)(mtx) << (6));
        ;
        break;
    case GX_TEXCOORD1:
        (gx->matIdxA) = ((u32)(gx->matIdxA) & ~(((1 << (6)) - 1) << (12))) | ((u32)(mtx) << (12));
        ;
        break;
    case GX_TEXCOORD2:
        (gx->matIdxA) = ((u32)(gx->matIdxA) & ~(((1 << (6)) - 1) << (18))) | ((u32)(mtx) << (18));
        ;
        break;
    case GX_TEXCOORD3:
        (gx->matIdxA) = ((u32)(gx->matIdxA) & ~(((1 << (6)) - 1) << (24))) | ((u32)(mtx) << (24));
        ;
        break;
    case GX_TEXCOORD4:
        (gx->matIdxB) = ((u32)(gx->matIdxB) & ~(((1 << (6)) - 1) << (0))) | ((u32)(mtx) << (0));
        ;
        break;
    case GX_TEXCOORD5:
        (gx->matIdxB) = ((u32)(gx->matIdxB) & ~(((1 << (6)) - 1) << (6))) | ((u32)(mtx) << (6));
        ;
        break;
    case GX_TEXCOORD6:
        (gx->matIdxB) = ((u32)(gx->matIdxB) & ~(((1 << (6)) - 1) << (12))) | ((u32)(mtx) << (12));
        ;
        break;
    default:
        (gx->matIdxB) = ((u32)(gx->matIdxB) & ~(((1 << (6)) - 1) << (18))) | ((u32)(mtx) << (18));
        ;
        break;
    }
    mtxIdAttr = dst_coord + 1;
    __GXSetMatrixIndex(mtxIdAttr);
}

// Hardware FIFO register is intentionally volatile.

void GXSetNumTexGens(u32 value) {
    GXData *g;
    u32 masked_value;

    g = gx;
    masked_value = value & 0xFF;
    g->genMode = (g->genMode & ~0xFu) | masked_value;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = 0x103F;
    GXWGFifo.u32 = masked_value;
    g->dirtyState |= 4;
}
