#include <types.h>
#include <dolphin/gx/GXPriv.h>

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
