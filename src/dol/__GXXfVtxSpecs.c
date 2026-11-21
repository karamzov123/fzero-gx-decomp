#include "types.h"
#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>


/* --- dol/fn_80032360.c --- */
/* --- dol/fn_80032360.c --- */
/* --- dol/fn_80032360.c --- */
extern u32 lbl_801A6BF0;

u32 fn_80032360(void);

/* --- dol/fn_80032368.c --- */
extern u32 lbl_801A6BF4;

u32 fn_80032368(void);

/* --- dol/__GXXfVtxSpecs.c --- */
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

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
        GXFIFO.u8 = (u8)(0x10);
        GXFIFO.u32 = (u32)(0x1000 + (8));
        GXFIFO.u32 = (u32)(reg);
        ;
    } while (0);
    gx->bpSentNot = ((GXBool)1);
}

/* --- dol/GXSetVtxDesc.c --- */
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

/* --- dol/GXSetVtxDescv.c --- */
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

/* --- dol/__GXSetVCD.c --- */
// Hardware or OS state can change asynchronously.


void __GXSetVCD(void) {
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_CP_REG;
    GXFIFO.s8 = (GX_CP_REG_VCD_LO);
    GXFIFO.s32 = (gx->vcdLo);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_CP_REG;
    GXFIFO.s8 = (GX_CP_REG_VCD_HI);
    GXFIFO.s32 = (gx->vcdHi);
    ;
    __GXXfVtxSpecs();
}

/* --- dol/__GXCalculateVLim.c --- */
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

/* --- dol/GXGetVtxDesc.c --- */
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
