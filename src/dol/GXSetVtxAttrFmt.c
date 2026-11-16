
#include "types.h"

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

typedef enum _GXAttr {
    GX_VA_PNMTXIDX,
    GX_VA_TEX0MTXIDX,
    GX_VA_TEX1MTXIDX,
    GX_VA_TEX2MTXIDX,
    GX_VA_TEX3MTXIDX,
    GX_VA_TEX4MTXIDX,
    GX_VA_TEX5MTXIDX,
    GX_VA_TEX6MTXIDX,
    GX_VA_TEX7MTXIDX,
    GX_VA_POS,
    GX_VA_NRM,
    GX_VA_CLR0,
    GX_VA_CLR1,
    GX_VA_TEX0,
    GX_VA_TEX1,
    GX_VA_TEX2,
    GX_VA_TEX3,
    GX_VA_TEX4,
    GX_VA_TEX5,
    GX_VA_TEX6,
    GX_VA_TEX7,
    GX_POS_MTX_ARRAY,
    GX_NRM_MTX_ARRAY,
    GX_TEX_MTX_ARRAY,
    GX_LIGHT_ARRAY,
    GX_VA_NBT,
    GX_VA_MAX_ATTR,
    GX_VA_NULL = 255,
} GXAttr;

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

typedef enum _GXCompType {
    GX_U8 = 0,
    GX_S8 = 1,
    GX_U16 = 2,
    GX_S16 = 3,
    GX_F32 = 4,
    GX_RGB565 = 0,
    GX_RGB8 = 1,
    GX_RGBX8 = 2,
    GX_RGBA4 = 3,
    GX_RGBA6 = 4,
    GX_RGBA8 = 5,
    GX_COMP_NULL = 0,
} GXCompType;

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

typedef enum _GXDirtyFlag {
    GX_DIRTY_SU_TEX = (1 << 0),
    GX_DIRTY_BP_MASK = (1 << 1),
    GX_DIRTY_GEN_MODE = (1 << 2),
    GX_DIRTY_VCD = (1 << 3),
    GX_DIRTY_VAT = (1 << 4),
    GX_DIRTY_AMB_COLOR0 = (1 << 8),
    GX_DIRTY_AMB_COLOR1 = (1 << 9),
    GX_DIRTY_MAT_COLOR0 = (1 << 10),
    GX_DIRTY_MAT_COLOR1 = (1 << 11),
    GX_DIRTY_MTX_IDX = (1 << 26),
    GX_DIRTY_PROJECTION = (1 << 27),
    GX_DIRTY_VIEWPORT = (1 << 28),
    GX_DIRTY_VLIM = GX_DIRTY_VCD | GX_DIRTY_VAT,
    GX_AMB_MAT_MASK =
        GX_DIRTY_AMB_COLOR0 | GX_DIRTY_AMB_COLOR1 | GX_DIRTY_MAT_COLOR0 | GX_DIRTY_MAT_COLOR1,
    GX_LIGHT_CHAN_MASK = 0x100F000,
    GX_TEX_GEN_MASK = 0x2FF0000,
} GXDirtyFlag;

typedef enum _GXCPVATGrp0 {
    GX_CP_VAT_GRP0_POS_CNT_ST = 31,
    GX_CP_VAT_GRP0_POS_CNT_END = 31,
    GX_CP_VAT_GRP0_POS_TYPE_ST = 28,
    GX_CP_VAT_GRP0_POS_TYPE_END = 30,
    GX_CP_VAT_GRP0_POS_SHIFT_ST = 23,
    GX_CP_VAT_GRP0_POS_SHIFT_END = 27,
    GX_CP_VAT_GRP0_NRM_CNT_ST = 22,
    GX_CP_VAT_GRP0_NRM_CNT_END = 22,
    GX_CP_VAT_GRP0_NRM_TYPE_ST = 19,
    GX_CP_VAT_GRP0_NRM_TYPE_END = 21,
    GX_CP_VAT_GRP0_CLRDIFF_CNT_ST = 18,
    GX_CP_VAT_GRP0_CLRDIFF_CNT_END = 18,
    GX_CP_VAT_GRP0_CLRDIFF_TYPE_ST = 15,
    GX_CP_VAT_GRP0_CLRDIFF_TYPE_END = 17,
    GX_CP_VAT_GRP0_CLRSPEC_CNT_ST = 14,
    GX_CP_VAT_GRP0_CLRSPEC_CNT_END = 14,
    GX_CP_VAT_GRP0_CLRSPEC_TYPE_ST = 11,
    GX_CP_VAT_GRP0_CLRSPEC_TYPE_END = 13,
    GX_CP_VAT_GRP0_TXC0_CNT_ST = 10,
    GX_CP_VAT_GRP0_TXC0_CNT_END = 10,
    GX_CP_VAT_GRP0_TXC0_TYPE_ST = 7,
    GX_CP_VAT_GRP0_TXC0_TYPE_END = 9,
    GX_CP_VAT_GRP0_TXC0_SHIFT_ST = 2,
    GX_CP_VAT_GRP0_TXC0_SHIFT_END = 6,
    GX_CP_VAT_GRP0_BYTEDEQ_ST = 1,
    GX_CP_VAT_GRP0_BYTEDEQ_END = 1,
    GX_CP_VAT_GRP0_NRMIDX3_ST = 0,
    GX_CP_VAT_GRP0_NRMIDX3_END = 0,
} GXCPVATGrp0;

typedef enum _GXCPVATGrp1 {
    GX_CP_VAT_GRP1_TXC1_CNT_ST = 31,
    GX_CP_VAT_GRP1_TXC1_CNT_END = 31,
    GX_CP_VAT_GRP1_TXC1_TYPE_ST = 28,
    GX_CP_VAT_GRP1_TXC1_TYPE_END = 30,
    GX_CP_VAT_GRP1_TXC1_SHIFT_ST = 23,
    GX_CP_VAT_GRP1_TXC1_SHIFT_END = 27,
    GX_CP_VAT_GRP1_TXC2_CNT_ST = 22,
    GX_CP_VAT_GRP1_TXC2_CNT_END = 22,
    GX_CP_VAT_GRP1_TXC2_TYPE_ST = 19,
    GX_CP_VAT_GRP1_TXC2_TYPE_END = 21,
    GX_CP_VAT_GRP1_TXC2_SHIFT_ST = 14,
    GX_CP_VAT_GRP1_TXC2_SHIFT_END = 18,
    GX_CP_VAT_GRP1_TXC3_CNT_ST = 13,
    GX_CP_VAT_GRP1_TXC3_CNT_END = 13,
    GX_CP_VAT_GRP1_TXC3_TYPE_ST = 10,
    GX_CP_VAT_GRP1_TXC3_TYPE_END = 12,
    GX_CP_VAT_GRP1_TXC3_SHIFT_ST = 5,
    GX_CP_VAT_GRP1_TXC3_SHIFT_END = 9,
    GX_CP_VAT_GRP1_TXC4_CNT_ST = 4,
    GX_CP_VAT_GRP1_TXC4_CNT_END = 4,
    GX_CP_VAT_GRP1_TXC4_TYPE_ST = 1,
    GX_CP_VAT_GRP1_TXC4_TYPE_END = 3,
} GXCPVATGrp1;

typedef enum _GXCPVATGrp2 {
    GX_CP_VAT_GRP2_TXC4_SHIFT_ST = 27,
    GX_CP_VAT_GRP2_TXC4_SHIFT_END = 31,
    GX_CP_VAT_GRP2_TXC5_CNT_ST = 26,
    GX_CP_VAT_GRP2_TXC5_CNT_END = 26,
    GX_CP_VAT_GRP2_TXC5_TYPE_ST = 23,
    GX_CP_VAT_GRP2_TXC5_TYPE_END = 25,
    GX_CP_VAT_GRP2_TXC5_SHIFT_ST = 18,
    GX_CP_VAT_GRP2_TXC5_SHIFT_END = 22,
    GX_CP_VAT_GRP2_TXC6_CNT_ST = 17,
    GX_CP_VAT_GRP2_TXC6_CNT_END = 17,
    GX_CP_VAT_GRP2_TXC6_TYPE_ST = 14,
    GX_CP_VAT_GRP2_TXC6_TYPE_END = 16,
    GX_CP_VAT_GRP2_TXC6_SHIFT_ST = 9,
    GX_CP_VAT_GRP2_TXC6_SHIFT_END = 13,
    GX_CP_VAT_GRP2_TXC7_CNT_ST = 8,
    GX_CP_VAT_GRP2_TXC7_CNT_END = 8,
    GX_CP_VAT_GRP2_TXC7_TYPE_ST = 5,
    GX_CP_VAT_GRP2_TXC7_TYPE_END = 7,
    GX_CP_VAT_GRP2_TXC7_SHIFT_ST = 0,
    GX_CP_VAT_GRP2_TXC7_SHIFT_END = 4,
} GXCPVATGrp2;

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

typedef struct _GXVtxAttrFmtList {
    GXAttr attr;
    GXCompCnt cnt;
    GXCompType type;
    u8 frac;
} GXVtxAttrFmtList;

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
    unsigned char padding_before_dirtyVAT[1];
    u8 dirtyVAT;
    u32 dirtyState;
} GXData;

extern GXData *const gx;

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
