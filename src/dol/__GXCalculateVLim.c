#include <types.h>

typedef u8 GXBool;

typedef enum _GXTexMapID {
    GX_TEXMAP0,
    GX_TEXMAP1,
    GX_TEXMAP2,
    GX_TEXMAP3,
    GX_TEXMAP4,
    GX_TEXMAP5,
    GX_TEXMAP6,
    GX_TEXMAP7,
    GX_MAX_TEXMAP,
    GX_TEXMAP_NULL = 255,
    GX_TEXMAP_DISABLE,
} GXTexMapID;

typedef enum _GXVtxFmt {
    GX_VTXFMT0,
    GX_VTXFMT1,
    GX_VTXFMT2,
    GX_VTXFMT3,
    GX_VTXFMT4,
    GX_VTXFMT5,
    GX_VTXFMT6,
    GX_VTXFMT7,
    GX_MAX_VTXFMT,
} GXVtxFmt;

typedef enum _GXCompCnt {
    GX_POS_XY = 0,
    GX_POS_XYZ = 1,
    GX_NRM_XYZ = 0,
    GX_NRM_NBT = 1,
    GX_NRM_NBT3 = 2,
    GX_CLR_RGB = 0,
    GX_CLR_RGBA = 1,
    GX_TEX_S = 0,
    GX_TEX_ST = 1,
    GX_COMPCNT_NULL = 0,
} GXCompCnt;

typedef enum _GXAttrType {
    GX_NONE,
    GX_DIRECT,
    GX_INDEX8,
    GX_INDEX16,
} GXAttrType;

typedef enum _GXTlut {
    GX_TLUT0,
    GX_TLUT1,
    GX_TLUT2,
    GX_TLUT3,
    GX_TLUT4,
    GX_TLUT5,
    GX_TLUT6,
    GX_TLUT7,
    GX_TLUT8,
    GX_TLUT9,
    GX_TLUT10,
    GX_TLUT11,
    GX_TLUT12,
    GX_TLUT13,
    GX_TLUT14,
    GX_TLUT15,
    GX_MAX_TLUT,
    GX_BIGTLUT0 = 0x10,
    GX_BIGTLUT1,
    GX_BIGTLUT2,
    GX_BIGTLUT3,
    GX_MAX_BIGTLUT = 4,
    GX_MAX_TLUT_ALL = GX_MAX_TLUT + GX_MAX_BIGTLUT,
} GXTlut;

typedef enum _GXCPVCDLo {
    GX_CP_VCD_LO_POSMTXIDX_ST = 31,
    GX_CP_VCD_LO_POSMTXIDX_END = 31,
    GX_CP_VCD_LO_TEX0MTXIDX_ST = 30,
    GX_CP_VCD_LO_TEX0MTXIDX_END = 30,
    GX_CP_VCD_LO_TEX1MTXIDX_ST = 29,
    GX_CP_VCD_LO_TEX1MTXIDX_END = 29,
    GX_CP_VCD_LO_TEX2MTXIDX_ST = 28,
    GX_CP_VCD_LO_TEX2MTXIDX_END = 28,
    GX_CP_VCD_LO_TEX3MTXIDX_ST = 27,
    GX_CP_VCD_LO_TEX3MTXIDX_END = 27,
    GX_CP_VCD_LO_TEX4MTXIDX_ST = 26,
    GX_CP_VCD_LO_TEX4MTXIDX_END = 26,
    GX_CP_VCD_LO_TEX5MTXIDX_ST = 25,
    GX_CP_VCD_LO_TEX5MTXIDX_END = 25,
    GX_CP_VCD_LO_TEX6MTXIDX_ST = 24,
    GX_CP_VCD_LO_TEX6MTXIDX_END = 24,
    GX_CP_VCD_LO_TEX7MTXIDX_ST = 23,
    GX_CP_VCD_LO_TEX7MTXIDX_END = 23,
    GX_CP_VCD_LO_POS_ST = 21,
    GX_CP_VCD_LO_POS_END = 22,
    GX_CP_VCD_LO_NRM_ST = 19,
    GX_CP_VCD_LO_NRM_END = 20,
    GX_CP_VCD_LO_CLRDIF_ST = 17,
    GX_CP_VCD_LO_CLRDIF_END = 18,
    GX_CP_VCD_LO_CLRSPEC_ST = 15,
    GX_CP_VCD_LO_CLRSPEC_END = 16,
} GXCPVCDLo;

typedef enum _GXCPVCDHi {
    GX_CP_VCD_HI_TEX0COORD_ST = 30,
    GX_CP_VCD_HI_TEX0COORD_END = 31,
    GX_CP_VCD_HI_TEX1COORD_ST = 28,
    GX_CP_VCD_HI_TEX1COORD_END = 29,
    GX_CP_VCD_HI_TEX2COORD_ST = 26,
    GX_CP_VCD_HI_TEX2COORD_END = 27,
    GX_CP_VCD_HI_TEX3COORD_ST = 24,
    GX_CP_VCD_HI_TEX3COORD_END = 25,
    GX_CP_VCD_HI_TEX4COORD_ST = 22,
    GX_CP_VCD_HI_TEX4COORD_END = 23,
    GX_CP_VCD_HI_TEX5COORD_ST = 20,
    GX_CP_VCD_HI_TEX5COORD_END = 21,
    GX_CP_VCD_HI_TEX6COORD_ST = 18,
    GX_CP_VCD_HI_TEX6COORD_END = 19,
    GX_CP_VCD_HI_TEX7COORD_ST = 16,
    GX_CP_VCD_HI_TEX7COORD_END = 17,
} GXCPVCDHi;

typedef enum _GXPerf0 {
    GX_PERF0_VERTICES = 0,
    GX_PERF0_CLIP_VTX = 1,
    GX_PERF0_CLIP_CLKS = 2,
    GX_PERF0_XF_WAIT_IN = 3,
    GX_PERF0_XF_WAIT_OUT = 4,
    GX_PERF0_XF_XFRM_CLKS = 5,
    GX_PERF0_XF_LIT_CLKS = 6,
    GX_PERF0_XF_BOT_CLKS = 7,
    GX_PERF0_XF_REGLD_CLKS = 8,
    GX_PERF0_XF_REGRD_CLKS = 9,
    GX_PERF0_CLIP_RATIO = 10,
    GX_PERF0_TRIANGLES = 11,
    GX_PERF0_TRIANGLES_CULLED = 12,
    GX_PERF0_TRIANGLES_PASSED = 13,
    GX_PERF0_TRIANGLES_SCISSORED = 14,
    GX_PERF0_TRIANGLES_0TEX = 15,
    GX_PERF0_TRIANGLES_1TEX = 16,
    GX_PERF0_TRIANGLES_2TEX = 17,
    GX_PERF0_TRIANGLES_3TEX = 18,
    GX_PERF0_TRIANGLES_4TEX = 19,
    GX_PERF0_TRIANGLES_5TEX = 20,
    GX_PERF0_TRIANGLES_6TEX = 21,
    GX_PERF0_TRIANGLES_7TEX = 22,
    GX_PERF0_TRIANGLES_8TEX = 23,
    GX_PERF0_TRIANGLES_0CLR = 24,
    GX_PERF0_TRIANGLES_1CLR = 25,
    GX_PERF0_TRIANGLES_2CLR = 26,
    GX_PERF0_QUAD_0CVG = 27,
    GX_PERF0_QUAD_NON0CVG = 28,
    GX_PERF0_QUAD_1CVG = 29,
    GX_PERF0_QUAD_2CVG = 30,
    GX_PERF0_QUAD_3CVG = 31,
    GX_PERF0_QUAD_4CVG = 32,
    GX_PERF0_AVG_QUAD_CNT = 33,
    GX_PERF0_CLOCKS = 34,
    GX_PERF0_NONE = 35,
} GXPerf0;

typedef enum _GXPerf1 {
    GX_PERF1_TEXELS = 0,
    GX_PERF1_TX_IDLE = 1,
    GX_PERF1_TX_REGS = 2,
    GX_PERF1_TX_MEMSTALL = 3,
    GX_PERF1_TC_CHECK1_2 = 4,
    GX_PERF1_TC_CHECK3_4 = 5,
    GX_PERF1_TC_CHECK5_6 = 6,
    GX_PERF1_TC_CHECK7_8 = 7,
    GX_PERF1_TC_MISS = 8,
    GX_PERF1_VC_ELEMQ_FULL = 9,
    GX_PERF1_VC_MISSQ_FULL = 10,
    GX_PERF1_VC_MEMREQ_FULL = 11,
    GX_PERF1_VC_STATUS7 = 12,
    GX_PERF1_VC_MISSREP_FULL = 13,
    GX_PERF1_VC_STREAMBUF_LOW = 14,
    GX_PERF1_VC_ALL_STALLS = 15,
    GX_PERF1_VERTICES = 16,
    GX_PERF1_FIFO_REQ = 17,
    GX_PERF1_CALL_REQ = 18,
    GX_PERF1_VC_MISS_REQ = 19,
    GX_PERF1_CP_ALL_REQ = 20,
    GX_PERF1_CLOCKS = 21,
    GX_PERF1_NONE = 22,
} GXPerf1;

typedef struct _GXTexObj {
    u32 texture_filter;
    u32 texture_lod;
    u32 texture_size;
    u32 texture_address;
    u32 user_data;
    u32 texture_format;
    u32 tlut_name;
    u16 texture_time_count;
    u8 texture_tile_type;
    u8 texture_flags;
} GXTexObj;

typedef struct _GXTlutObj {
    u32 format;
    u32 address;
    u32 numEntries;
} GXTlutObj;

typedef struct _GXTexRegion {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8 unkC;
    u8 unkD;
} GXTexRegion;

typedef struct _GXTlutRegion {
    u32 unk0;
    GXTlutObj tlutObj;
} GXTlutRegion;

typedef GXTexRegion *(*GXTexRegionCallback)(const GXTexObj *t_obj, GXTexMapID id);

typedef GXTlutRegion *(*GXTlutRegionCallback)(u32 idx);

typedef struct _GXData {
    u16 vNumNot;
    u16 bpSentNot;
    u16 vNum;
    u16 vLim;
    u32 cpEnable;
    u32 cpStatus;
    u32 cpClr;
    u32 vcdLo;
    u32 vcdHi;
    u32 vatA[8];
    u32 vatB[8];
    u32 vatC[8];
    u32 lpSize;
    u32 matIdxA;
    u32 matIdxB;
    u32 indexBase[4];
    u32 indexStride[4];
    u32 ambColor[2];
    u32 matColor[2];
    u32 suTs0[8];
    u32 suTs1[8];
    u32 suScis0;
    u32 suScis1;
    u32 tref[8];
    u32 iref;
    u32 bpMask;
    u32 IndTexScale0;
    u32 IndTexScale1;
    u32 tevc[16];
    u32 teva[16];
    u32 tevKsel[8];
    u32 cmode0;
    u32 cmode1;
    u32 zmode;
    u32 peCtrl;
    u32 cpDispSrc;
    u32 cpDispSize;
    u32 cpDispStride;
    u32 cpDisp;
    u32 cpTexSrc;
    u32 cpTexSize;
    u32 cpTexStride;
    u32 cpTex;
    GXBool cpTexZ;
    u32 genMode;
    GXTexRegion TexRegions0[GX_MAX_TEXMAP];
    GXTexRegion TexRegions1[4];
    u32 nextTexRgn;
    u32 nextTexRgnCI;
    GXTlutRegion TlutRegions[GX_MAX_TLUT_ALL];
    GXTexRegionCallback texRegionCallback;
    GXTlutRegionCallback tlutRegionCallback;
    GXAttrType nrmType;
    GXBool hasNrms;
    GXBool hasBiNrms;
    u32 projType;
    f32 projMtx[6];
    f32 vpLeft;
    f32 vpTop;
    f32 vpWd;
    f32 vpHt;
    f32 vpNearz;
    f32 vpFarz;
    f32 zOffset;
    f32 zScale;
    u32 tImage0[8];
    u32 tMode0[8];
    u32 texmapId[16];
    u32 tcsManEnab;
    u32 tevTcEnab;
    GXPerf0 perf0;
    GXPerf1 perf1;
    u32 perfSel;
    GXBool inDispList;
    GXBool dlSaveContext;
    u8 dirtyVAT;
    u32 dirtyState;
} GXData;

extern u8 lbl_801A6528[4];
extern u8 lbl_801A652C[4];
extern u8 lbl_801A6530[8];
extern GXData *const gx;

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
