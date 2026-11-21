#ifndef DOLPHIN_GX_GXPRIV_H
#define DOLPHIN_GX_GXPRIV_H
/* Private GX types shared by the GX library translation units (SDK layout). */
#include <types.h>

typedef u8 GXBool;

typedef enum _GXTexFilter {
    GX_NEAR,
    GX_LINEAR,
    GX_NEAR_MIP_NEAR,
    GX_LIN_MIP_NEAR,
    GX_NEAR_MIP_LIN,
    GX_LIN_MIP_LIN,
} GXTexFilter;

typedef enum _GXAnisotropy {
    GX_ANISO_1,
    GX_ANISO_2,
    GX_ANISO_4,
    GX_MAX_ANISOTROPY,
} GXAnisotropy;

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

struct fn_80036058_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

typedef struct Fn80036070Data {
    u32 flags;
    u8 pad_04[4];
    u32 dimensions;
    u32 scaled_value;
    u8 pad_10[4];
    u32 value_14;
    u8 pad_18[7];
    u8 enabled;
} Fn80036070Data;

struct fn_800360D8_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct GXGetTexObjWidth_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

struct GXGetTexObjHeight_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

struct fn_80036104_Arg0 {
    u8 pad_0[0x14];
    u32 unk_14;
};

typedef struct Fn8003610CData {
    u32 flags;
    u32 packed;
} Fn8003610CData;

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

typedef enum _GXFifoCmd {
    GX_FIFO_CMD_NOOP = 0x00,
    GX_FIFO_CMD_LOAD_BP_REG = 0x61,
    GX_FIFO_CMD_LOAD_CP_REG = 0x08,
    GX_FIFO_CMD_LOAD_XF_REG = 0x10,
    GX_FIFO_CMD_LOAD_INDX_A = 0x20,
    GX_FIFO_CMD_LOAD_INDX_B = 0x28,
    GX_FIFO_CMD_LOAD_INDX_C = 0x30,
    GX_FIFO_CMD_LOAD_INDX_D = 0x38,
    GX_FIFO_CMD_CALL_DL = 0x40,
    GX_FIFO_CMD_INVAL_VTX = 0x48,
} GXFifoCmd;

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
    u8 fgRange;
    f32 fgSideX;
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
    u8 abtWaitPECopy;
    u8 dirtyVAT;
    u32 dirtyState;
} GXData;

#ifndef DOLPHIN_GX_H
typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    u64 u64;
    s8 s8;
    s16 s16;
    s32 s32;
    s64 s64;
    f32 f32;
    f64 f64;
} PPCWGPipe;
#endif

typedef enum {
    VI_TVMODE_NTSC_INT = ((((0)) << 2) + ((0))),
    VI_TVMODE_NTSC_DS = ((((0)) << 2) + ((1))),
    VI_TVMODE_NTSC_PROG = ((((0)) << 2) + ((2))),
    VI_TVMODE_NTSC_3D = ((((0)) << 2) + ((3))),
    VI_TVMODE_PAL_INT = ((((1)) << 2) + ((0))),
    VI_TVMODE_PAL_DS = ((((1)) << 2) + ((1))),
    VI_TVMODE_MPAL_INT = ((((2)) << 2) + ((0))),
    VI_TVMODE_MPAL_DS = ((((2)) << 2) + ((1))),
    VI_TVMODE_DEBUG_INT = ((((3)) << 2) + ((0))),
    VI_TVMODE_DEBUG_PAL_INT = ((((4)) << 2) + ((0))),
    VI_TVMODE_DEBUG_PAL_DS = ((((4)) << 2) + ((1))),
    VI_TVMODE_EURGB60_INT = ((((5)) << 2) + ((0))),
    VI_TVMODE_EURGB60_DS = ((((5)) << 2) + ((1))),
    VI_TVMODE_GCA_INT = ((((6)) << 2) + ((0))),
    VI_TVMODE_GCA_DS = ((((6)) << 2) + ((1))),
    VI_TVMODE_GCA_PROG = ((((6)) << 2) + ((2))),
} VITVMode;

typedef enum {
    VI_XFBMODE_SF = 0,
    VI_XFBMODE_DF = 1,
} VIXFBMode;

typedef struct _GXRenderModeObj {
    VITVMode viTVmode;
    u16 fbWidth;
    u16 efbHeight;
    u16 xfbHeight;
    u16 viXOrigin;
    u16 viYOrigin;
    u16 viWidth;
    u16 viHeight;
    VIXFBMode xFBmode;
    u8 field_rendering;
    u8 aa;
    u8 sample_pattern[12][2];
    u8 vfilter[7];
} GXRenderModeObj;

typedef void (*GXBreakPtCallback)(void);

struct GXInitFifoBase_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x10];
    u32 unk_1C;
};

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

typedef struct GXVtxAttrFmt {
    u32 attr;
    GXCompCnt cnt;
    GXCompType type;
    u8 frac;
} GXVtxAttrFmt;

typedef enum _GXBPRegs {
    GX_BP_REG_GENMODE = 0x0,
    GX_BP_REG_DISPCOPYFILTER0 = 0x1,
    GX_BP_REG_DISPCOPYFILTER1 = 0x2,
    GX_BP_REG_DISPCOPYFILTER2 = 0x3,
    GX_BP_REG_DISPCOPYFILTER3 = 0x4,
    GX_BP_REG_INDMTX0A = 0x6,
    GX_BP_REG_INDMTX0B = 0x7,
    GX_BP_REG_INDMTX0C = 0x8,
    GX_BP_REG_INDMTX1A = 0x9,
    GX_BP_REG_INDMTX1B = 0xA,
    GX_BP_REG_INDMTX1C = 0xB,
    GX_BP_REG_INDMTX2A = 0xC,
    GX_BP_REG_INDMTX2B = 0xD,
    GX_BP_REG_INDMTX2C = 0xE,
    GX_BP_REG_INDIMASK = 0xF,
    GX_BP_REG_INDTEVSTAGE0 = 0x10,
    GX_BP_REG_INDTEVSTAGE1 = 0x11,
    GX_BP_REG_INDTEVSTAGE2 = 0x12,
    GX_BP_REG_INDTEVSTAGE3 = 0x13,
    GX_BP_REG_INDTEVSTAGE4 = 0x14,
    GX_BP_REG_INDTEVSTAGE5 = 0x15,
    GX_BP_REG_INDTEVSTAGE6 = 0x16,
    GX_BP_REG_INDTEVSTAGE7 = 0x17,
    GX_BP_REG_INDTEVSTAGE8 = 0x18,
    GX_BP_REG_INDTEVSTAGE9 = 0x19,
    GX_BP_REG_INDTEVSTAGE10 = 0x1A,
    GX_BP_REG_INDTEVSTAGE11 = 0x1B,
    GX_BP_REG_INDTEVSTAGE12 = 0x1C,
    GX_BP_REG_INDTEVSTAGE13 = 0x1D,
    GX_BP_REG_INDTEVSTAGE14 = 0x1E,
    GX_BP_REG_INDTEVSTAGE15 = 0x1F,
    GX_BP_REG_SCISSORTL = 0x20,
    GX_BP_REG_SCISSORBR = 0x21,
    GX_BP_REG_LINEPTWIDTH = 0x22,
    GX_BP_REG_PERF0TRI = 0x23,
    GX_BP_REG_PERF0QUAD = 0x24,
    GX_BP_REG_RAS1_SS0 = 0x25,
    GX_BP_REG_RAS1_SS1 = 0x26,
    GX_BP_REG_RAS1_IREF = 0x27,
    GX_BP_REG_RAS1_TREF0 = 0x28,
    GX_BP_REG_RAS1_TREF1 = 0x29,
    GX_BP_REG_RAS1_TREF2 = 0x2A,
    GX_BP_REG_RAS1_TREF3 = 0x2B,
    GX_BP_REG_RAS1_TREF4 = 0x2C,
    GX_BP_REG_RAS1_TREF5 = 0x2D,
    GX_BP_REG_RAS1_TREF6 = 0x2E,
    GX_BP_REG_RAS1_TREF7 = 0x2F,
    GX_BP_REG_SU_SSIZE0 = 0x30,
    GX_BP_REG_SU_TSIZE0 = 0x31,
    GX_BP_REG_SU_SSIZE1 = 0x32,
    GX_BP_REG_SU_TSIZE1 = 0x33,
    GX_BP_REG_SU_SSIZE2 = 0x34,
    GX_BP_REG_SU_TSIZE2 = 0x35,
    GX_BP_REG_SU_SSIZE3 = 0x36,
    GX_BP_REG_SU_TSIZE3 = 0x37,
    GX_BP_REG_SU_SSIZE4 = 0x38,
    GX_BP_REG_SU_TSIZE4 = 0x39,
    GX_BP_REG_SU_SSIZE5 = 0x3A,
    GX_BP_REG_SU_TSIZE5 = 0x3B,
    GX_BP_REG_SU_SSIZE6 = 0x3C,
    GX_BP_REG_SU_TSIZE6 = 0x3D,
    GX_BP_REG_SU_SSIZE7 = 0x3E,
    GX_BP_REG_SU_TSIZE7 = 0x3F,
    GX_BP_REG_ZMODE = 0x40,
    GX_BP_REG_BLENDMODE = 0x41,
    GX_BP_REG_DSTALPHA = 0x42,
    GX_BP_REG_ZCONTROL = 0x43,
    GX_BP_REG_FIELDMASK = 0x44,
    GX_BP_REG_DRAWDONE = 0x45,
    GX_BP_REG_PETOKEN = 0x47,
    GX_BP_REG_PETOKENINT = 0x48,
    GX_BP_REG_TEXCOPYSRCXY = 0x49,
    GX_BP_REG_TEXCOPYSRCWH = 0x4A,
    GX_BP_REG_TEXCOPYDST = 0x4B,
    GX_BP_REG_DISPCOPYSTRIDE = 0x4D,
    GX_BP_REG_DISPCOPYSCALEY = 0x4E,
    GX_BP_REG_COPYCLEARAR = 0x4F,
    GX_BP_REG_COPYCLEARGB = 0x50,
    GX_BP_REG_COPYCLEARZ = 0x51,
    GX_BP_REG_COPYFILTER0 = 0x53,
    GX_BP_REG_COPYFILTER1 = 0x54,
    GX_BP_REG_BOUNDINGBOX0 = 0x55,
    GX_BP_REG_BOUNDINGBOX1 = 0x56,
    GX_BP_REG_SCISSOROFFSET = 0x59,
    GX_BP_REG_TMEMPRELOADADDR = 0x60,
    GX_BP_REG_TMEMPRELOADEVEN = 0x61,
    GX_BP_REG_TMEMPRELOADODD = 0x62,
    GX_BP_REG_TMEMPRELOADMODE = 0x63,
    GX_BP_REG_TMEMTLUTSRC = 0x64,
    GX_BP_REG_TMEMTLUTDST = 0x65,
    GX_BP_REG_TMEMTEXINVALIDATE = 0x66,
    GX_BP_REG_PERF1 = 0x67,
    GX_BP_REG_FIELDMODE = 0x68,
    GX_BP_REG_SETMODE0_TEX0 = 0x80,
    GX_BP_REG_SETMODE0_TEX1 = 0x81,
    GX_BP_REG_SETMODE0_TEX2 = 0x82,
    GX_BP_REG_SETMODE0_TEX3 = 0x83,
    GX_BP_REG_SETMODE1_TEX0 = 0x84,
    GX_BP_REG_SETMODE1_TEX1 = 0x85,
    GX_BP_REG_SETMODE1_TEX2 = 0x86,
    GX_BP_REG_SETMODE1_TEX3 = 0x87,
    GX_BP_REG_SETIMAGE0_TEX0 = 0x88,
    GX_BP_REG_SETIMAGE0_TEX1 = 0x89,
    GX_BP_REG_SETIMAGE0_TEX2 = 0x8A,
    GX_BP_REG_SETIMAGE0_TEX3 = 0x8B,
    GX_BP_REG_SETIMAGE1_TEX0 = 0x8C,
    GX_BP_REG_SETIMAGE1_TEX1 = 0x8D,
    GX_BP_REG_SETIMAGE1_TEX2 = 0x8E,
    GX_BP_REG_SETIMAGE1_TEX3 = 0x8F,
    GX_BP_REG_SETIMAGE2_TEX0 = 0x90,
    GX_BP_REG_SETIMAGE2_TEX1 = 0x91,
    GX_BP_REG_SETIMAGE2_TEX2 = 0x92,
    GX_BP_REG_SETIMAGE2_TEX3 = 0x93,
    GX_BP_REG_SETIMAGE3_TEX0 = 0x94,
    GX_BP_REG_SETIMAGE3_TEX1 = 0x95,
    GX_BP_REG_SETIMAGE3_TEX2 = 0x96,
    GX_BP_REG_SETIMAGE3_TEX3 = 0x97,
    GX_BP_REG_SETTLUT_TEX0 = 0x98,
    GX_BP_REG_SETTLUT_TEX1 = 0x99,
    GX_BP_REG_SETTLUT_TEX2 = 0x9A,
    GX_BP_REG_SETTLUT_TEX3 = 0x9B,
    GX_BP_REG_SETMODE0_TEX4 = 0xA0,
    GX_BP_REG_SETMODE0_TEX5 = 0xA1,
    GX_BP_REG_SETMODE0_TEX6 = 0xA2,
    GX_BP_REG_SETMODE0_TEX7 = 0xA3,
    GX_BP_REG_SETMODE1_TEX4 = 0xA4,
    GX_BP_REG_SETMODE1_TEX5 = 0xA5,
    GX_BP_REG_SETMODE1_TEX6 = 0xA6,
    GX_BP_REG_SETMODE1_TEX7 = 0xA7,
    GX_BP_REG_SETIMAGE0_TEX4 = 0xA8,
    GX_BP_REG_SETIMAGE0_TEX5 = 0xA9,
    GX_BP_REG_SETIMAGE0_TEX6 = 0xAA,
    GX_BP_REG_SETIMAGE0_TEX7 = 0xAB,
    GX_BP_REG_SETIMAGE1_TEX4 = 0xAC,
    GX_BP_REG_SETIMAGE1_TEX5 = 0xAD,
    GX_BP_REG_SETIMAGE1_TEX6 = 0xAE,
    GX_BP_REG_SETIMAGE1_TEX7 = 0xAF,
    GX_BP_REG_SETIMAGE2_TEX4 = 0xB0,
    GX_BP_REG_SETIMAGE2_TEX5 = 0xB1,
    GX_BP_REG_SETIMAGE2_TEX6 = 0xB2,
    GX_BP_REG_SETIMAGE2_TEX7 = 0xB3,
    GX_BP_REG_SETIMAGE3_TEX4 = 0xB4,
    GX_BP_REG_SETIMAGE3_TEX5 = 0xB5,
    GX_BP_REG_SETIMAGE3_TEX6 = 0xB6,
    GX_BP_REG_SETIMAGE3_TEX7 = 0xB7,
    GX_BP_REG_SETTLUT_TEX4 = 0xB8,
    GX_BP_REG_SETTLUT_TEX5 = 0xB9,
    GX_BP_REG_SETTLUT_TEX6 = 0xBA,
    GX_BP_REG_SETTLUT_TEX7 = 0xBB,
    GX_BP_REG_TEVCOLORCOMBINER0 = 0xC0,
    GX_BP_REG_TEVALPHACOMBINER0 = 0xC1,
    GX_BP_REG_TEVCOLORCOMBINER1 = 0xC2,
    GX_BP_REG_TEVALPHACOMBINER1 = 0xC3,
    GX_BP_REG_TEVCOLORCOMBINER2 = 0xC4,
    GX_BP_REG_TEVALPHACOMBINER2 = 0xC5,
    GX_BP_REG_TEVCOLORCOMBINER3 = 0xC6,
    GX_BP_REG_TEVALPHACOMBINER3 = 0xC7,
    GX_BP_REG_TEVCOLORCOMBINER4 = 0xC8,
    GX_BP_REG_TEVALPHACOMBINER4 = 0xC9,
    GX_BP_REG_TEVCOLORCOMBINER5 = 0xCA,
    GX_BP_REG_TEVALPHACOMBINER5 = 0xCB,
    GX_BP_REG_TEVCOLORCOMBINER6 = 0xCC,
    GX_BP_REG_TEVALPHACOMBINER6 = 0xCD,
    GX_BP_REG_TEVCOLORCOMBINER7 = 0xCE,
    GX_BP_REG_TEVALPHACOMBINER7 = 0xCF,
    GX_BP_REG_TEVCOLORCOMBINER8 = 0xD0,
    GX_BP_REG_TEVALPHACOMBINER8 = 0xD1,
    GX_BP_REG_TEVCOLORCOMBINER9 = 0xD2,
    GX_BP_REG_TEVALPHACOMBINER9 = 0xD3,
    GX_BP_REG_TEVCOLORCOMBINER10 = 0xD4,
    GX_BP_REG_TEVALPHACOMBINER10 = 0xD5,
    GX_BP_REG_TEVCOLORCOMBINER11 = 0xD6,
    GX_BP_REG_TEVALPHACOMBINER11 = 0xD7,
    GX_BP_REG_TEVCOLORCOMBINER12 = 0xD8,
    GX_BP_REG_TEVALPHACOMBINER12 = 0xD9,
    GX_BP_REG_TEVCOLORCOMBINER13 = 0xDA,
    GX_BP_REG_TEVALPHACOMBINER13 = 0xDB,
    GX_BP_REG_TEVCOLORCOMBINER14 = 0xDC,
    GX_BP_REG_TEVALPHACOMBINER14 = 0xDD,
    GX_BP_REG_TEVCOLORCOMBINER15 = 0xDE,
    GX_BP_REG_TEVALPHACOMBINER15 = 0xDF,
    GX_BP_REG_TEVREG0LO = 0xE0,
    GX_BP_REG_TEVREG0HI = 0xE1,
    GX_BP_REG_TEVREG1LO = 0xE2,
    GX_BP_REG_TEVREG1HI = 0xE3,
    GX_BP_REG_TEVREG2LO = 0xE4,
    GX_BP_REG_TEVREG2HI = 0xE5,
    GX_BP_REG_TEVREG3LO = 0xE6,
    GX_BP_REG_TEVREG3HI = 0xE7,
    GX_BP_REG_FOGRANGE = 0xE8,
    GX_BP_REG_FOGRANGEK0 = 0xE9,
    GX_BP_REG_FOGRANGEK1 = 0xEA,
    GX_BP_REG_FOGRANGEK2 = 0xEB,
    GX_BP_REG_FOGRANGEK3 = 0xEC,
    GX_BP_REG_FOGRANGEK4 = 0xED,
    GX_BP_REG_FOGPARAM0 = 0xEE,
    GX_BP_REG_FOGPARAM1 = 0xEF,
    GX_BP_REG_FOGPARAM2 = 0xF0,
    GX_BP_REG_FOGPARAM3 = 0xF1,
    GX_BP_REG_FOGCOLOR = 0xF2,
    GX_BP_REG_ALPHACOMPARE = 0xF3,
    GX_BP_REG_ZTEXTURE0 = 0xF4,
    GX_BP_REG_ZTEXTURE1 = 0xF5,
    GX_BP_REG_TEVKSEL0 = 0xF6,
    GX_BP_REG_TEVKSEL1 = 0xF7,
    GX_BP_REG_TEVKSEL2 = 0xF8,
    GX_BP_REG_TEVKSEL3 = 0xF9,
    GX_BP_REG_TEVKSEL4 = 0xFA,
    GX_BP_REG_TEVKSEL5 = 0xFB,
    GX_BP_REG_TEVKSEL6 = 0xFC,
    GX_BP_REG_TEVKSEL7 = 0xFD,
    GX_BP_REG_SSMASK = 0xFE,
} GXBPRegs;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
} GXWGFifoReg;

typedef enum _GXTexCoordID {
    GX_TEXCOORD0,
    GX_TEXCOORD1,
    GX_TEXCOORD2,
    GX_TEXCOORD3,
    GX_TEXCOORD4,
    GX_TEXCOORD5,
    GX_TEXCOORD6,
    GX_TEXCOORD7,
    GX_MAXCOORD,
    GX_TEXCOORD_NULL = 255,
} GXTexCoordID;

typedef enum _GXTexGenType {
    GX_TG_MTX3x4,
    GX_TG_MTX2x4,
    GX_TG_BUMP0,
    GX_TG_BUMP1,
    GX_TG_BUMP2,
    GX_TG_BUMP3,
    GX_TG_BUMP4,
    GX_TG_BUMP5,
    GX_TG_BUMP6,
    GX_TG_BUMP7,
    GX_TG_SRTG,
} GXTexGenType;

typedef enum _GXTexGenSrc {
    GX_TG_POS,
    GX_TG_NRM,
    GX_TG_BINRM,
    GX_TG_TANGENT,
    GX_TG_TEX0,
    GX_TG_TEX1,
    GX_TG_TEX2,
    GX_TG_TEX3,
    GX_TG_TEX4,
    GX_TG_TEX5,
    GX_TG_TEX6,
    GX_TG_TEX7,
    GX_TG_TEXCOORD0,
    GX_TG_TEXCOORD1,
    GX_TG_TEXCOORD2,
    GX_TG_TEXCOORD3,
    GX_TG_TEXCOORD4,
    GX_TG_TEXCOORD5,
    GX_TG_TEXCOORD6,
    GX_TG_COLOR0,
    GX_TG_COLOR1,
} GXTexGenSrc;

typedef enum _GXCompare {
    GX_NEVER,
    GX_LESS,
    GX_EQUAL,
    GX_LEQUAL,
    GX_GREATER,
    GX_NEQUAL,
    GX_GEQUAL,
    GX_ALWAYS,
} GXCompare;

typedef enum _GXAlphaOp {
    GX_AOP_AND,
    GX_AOP_OR,
    GX_AOP_XOR,
    GX_AOP_XNOR,
    GX_MAX_ALPHAOP
} GXAlphaOp;

typedef enum _GXClipMode {
    GX_CLIP_ENABLE,
    GX_CLIP_DISABLE,
} GXClipMode;

typedef enum _GXXFRegs {
    GX_XF_REG_ERROR = 0x1000,
    GX_XF_REG_DIAGNOSTICS = 0x1001,
    GX_XF_REG_STATE0 = 0x1002,
    GX_XF_REG_STATE1 = 0x1003,
    GX_XF_REG_CLOCK = 0x1004,
    GX_XF_REG_CLIPDISABLE = 0x1005,
    GX_XF_REG_PERF0 = 0x1006,
    GX_XF_REG_PERF1 = 0x1007,
    GX_XF_REG_INVERTEXSPEC = 0x1008,
    GX_XF_REG_NUMCOLORS = 0x1009,
    GX_XF_REG_AMBIENT0 = 0x100A,
    GX_XF_REG_AMBIENT1 = 0x100B,
    GX_XF_REG_MATERIAL0 = 0x100C,
    GX_XF_REG_MATERIAL1 = 0x100D,
    GX_XF_REG_COLOR0CNTRL = 0x100E,
    GX_XF_REG_COLOR1CNTRL = 0x100F,
    GX_XF_REG_ALPHA0CNTRL = 0x1010,
    GX_XF_REG_ALPHA1CNTRL = 0x1011,
    GX_XF_REG_DUALTEXTRAN = 0x1012,
    GX_XF_REG_MATRIXINDEX0 = 0x1018,
    GX_XF_REG_MATRIXINDEX1 = 0x1019,
    GX_XF_REG_SCALEX = 0x101A,
    GX_XF_REG_SCALEY = 0x101B,
    GX_XF_REG_SCALEZ = 0x101C,
    GX_XF_REG_OFFSETX = 0x101D,
    GX_XF_REG_OFFSETY = 0x101E,
    GX_XF_REG_OFFSETZ = 0x101F,
    GX_XF_REG_PROJECTIONA = 0x1020,
    GX_XF_REG_PROJECTIONB = 0x1021,
    GX_XF_REG_PROJECTIONC = 0x1022,
    GX_XF_REG_PROJECTIOND = 0x1023,
    GX_XF_REG_PROJECTIONE = 0x1024,
    GX_XF_REG_PROJECTIONF = 0x1025,
    GX_XF_REG_PROJECTORTHO = 0x1026,
    GX_XF_REG_NUMTEX = 0x103F,
    GX_XF_REG_TEX0 = 0x1040,
    GX_XF_REG_TEX1 = 0x1041,
    GX_XF_REG_TEX2 = 0x1042,
    GX_XF_REG_TEX3 = 0x1043,
    GX_XF_REG_TEX4 = 0x1044,
    GX_XF_REG_TEX5 = 0x1045,
    GX_XF_REG_TEX6 = 0x1046,
    GX_XF_REG_TEX7 = 0x1047,
    GX_XF_REG_DUALTEX0 = 0x1050,
    GX_XF_REG_DUALTEX1 = 0x1051,
    GX_XF_REG_DUALTEX2 = 0x1052,
    GX_XF_REG_DUALTEX3 = 0x1053,
    GX_XF_REG_DUALTEX4 = 0x1054,
    GX_XF_REG_DUALTEX5 = 0x1055,
    GX_XF_REG_DUALTEX6 = 0x1056,
    GX_XF_REG_DUALTEX7 = 0x1057,
} GXXFRegs;

typedef struct _GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

typedef enum _GXCopyMode {
    GX_COPY_PROGRESSIVE,
    GX_COPY_INTLC_EVEN,
    GX_COPY_INTLC_ODD,
} GXCopyMode;

typedef enum _GXBPFieldMask {
    GX_BP_FIELDMASK_ODD_ST = 31,
    GX_BP_FIELDMASK_ODD_END = 31,
    GX_BP_FIELDMASK_EVEN_ST = 30,
    GX_BP_FIELDMASK_EVEN_END = 30,
} GXBPFieldMask;

typedef struct _GXFogAdjTable {
    u16 fogVals[10];
} GXFogAdjTable;

typedef enum _GXBPFogRange {
    GX_BP_FOGRANGE_CENTER_ST = 22,
    GX_BP_FOGRANGE_CENTER_END = 31,
    GX_BP_FOGRANGE_ENABLED_ST = 21,
    GX_BP_FOGRANGE_ENABLED_END = 21,
} GXBPFogRange;

typedef enum _GXBPFogRangeK {
    GX_BP_FOGRANGEK_HI_ST = 20,
    GX_BP_FOGRANGEK_HI_END = 31,
    GX_BP_FOGRANGEK_LO_ST = 8,
    GX_BP_FOGRANGEK_LO_END = 19,
} GXBPFogRangeK;

typedef struct _GXFifoObj {
    void *base;
    void *end;
    u32 size;
    u32 high_wtrmark;
    u32 low_wtrmark;
    void *read_ptr;
    void *write_ptr;
    s32 rw_dst;
    u8 fifo_wrap;
    u8 cpu_fifo_ready;
    u8 gp_fifo_ready;
    u8 field_0x23[93];
} GXFifoObj;

typedef volatile u16 vu16;

typedef enum _GXIndTexStageID {
    GX_INDTEXSTAGE0,
    GX_INDTEXSTAGE1,
    GX_INDTEXSTAGE2,
    GX_INDTEXSTAGE3,
    GX_MAX_INDTEXSTAGE,
} GXIndTexStageID;

typedef enum _GXIndTexScale {
    GX_ITS_1,
    GX_ITS_2,
    GX_ITS_4,
    GX_ITS_8,
    GX_ITS_16,
    GX_ITS_32,
    GX_ITS_64,
    GX_ITS_128,
    GX_ITS_256,
    GX_MAX_ITSCALE,
} GXIndTexScale;

typedef enum _GXTexOffset {
    GX_TO_ZERO,
    GX_TO_SIXTEENTH,
    GX_TO_EIGHTH,
    GX_TO_FOURTH,
    GX_TO_HALF,
    GX_TO_ONE,
    GX_MAX_TEXOFFSET,
} GXTexOffset;

typedef enum _GXProjectionType { GX_PERSPECTIVE, GX_ORTHOGRAPHIC } GXProjectionType;

typedef f32 Mtx44[4][4];

typedef enum _GXBPScissorTL {
    GX_BP_SCISSORTL_TOP_ST = 0,
    GX_BP_SCISSORTL_TOP_END = 10,
    GX_BP_SCISSORTL_LEFT_ST = 12,
    GX_BP_SCISSORTL_LEFT_END = 22,
} GXBPScissorTL;

typedef enum _GXBPScissorBR {
    GX_BP_SCISSORBR_BOT_ST = 0,
    GX_BP_SCISSORBR_BOT_END = 10,
    GX_BP_SCISSORBR_RIGHT_ST = 12,
    GX_BP_SCISSORBR_RIGHT_END = 22,
} GXBPScissorBR;

typedef enum _GXTevStageID {
    GX_TEVSTAGE0,
    GX_TEVSTAGE1,
    GX_TEVSTAGE2,
    GX_TEVSTAGE3,
    GX_TEVSTAGE4,
    GX_TEVSTAGE5,
    GX_TEVSTAGE6,
    GX_TEVSTAGE7,
    GX_TEVSTAGE8,
    GX_TEVSTAGE9,
    GX_TEVSTAGE10,
    GX_TEVSTAGE11,
    GX_TEVSTAGE12,
    GX_TEVSTAGE13,
    GX_TEVSTAGE14,
    GX_TEVSTAGE15,
    GX_MAX_TEVSTAGE,
} GXTevStageID;

typedef enum _GXIndTexMtxID {
    GX_ITM_OFF,
    GX_ITM_0,
    GX_ITM_1,
    GX_ITM_2,
    GX_ITM_3,
    GX_ITM_S0 = 5,
    GX_ITM_S1,
    GX_ITM_S2,
    GX_ITM_S3,
    GX_ITM_T0 = 9,
    GX_ITM_T1,
    GX_ITM_T2,
} GXIndTexMtxID;

typedef enum _GXIndTexFormat {
    GX_ITF_8,
    GX_ITF_5,
    GX_ITF_4,
    GX_ITF_3,
} GXIndTexFormat;

typedef enum _GXIndTexBiasSel {
    GX_ITB_NONE,
    GX_ITB_S,
    GX_ITB_T,
    GX_ITB_ST,
    GX_ITB_U,
    GX_ITB_SU,
    GX_ITB_TU,
    GX_ITB_STU,
} GXIndTexBiasSel;

typedef enum _GXIndTexAlphaSel {
    GX_ITBA_OFF,
    GX_ITBA_S,
    GX_ITBA_T,
    GX_ITBA_U,
} GXIndTexAlphaSel;

typedef enum _GXIndTexWrap {
    GX_ITW_OFF,
    GX_ITW_256,
    GX_ITW_128,
    GX_ITW_64,
    GX_ITW_32,
    GX_ITW_16,
    GX_ITW_0,
} GXIndTexWrap;

typedef enum _GXTevKAlphaSel {
    GX_TEV_KASEL_1,
    GX_TEV_KASEL_7_8,
    GX_TEV_KASEL_3_4,
    GX_TEV_KASEL_5_8,
    GX_TEV_KASEL_1_2,
    GX_TEV_KASEL_3_8,
    GX_TEV_KASEL_1_4,
    GX_TEV_KASEL_1_8,
    GX_TEV_KASEL_K0_R = 0x10,
    GX_TEV_KASEL_K1_R,
    GX_TEV_KASEL_K2_R,
    GX_TEV_KASEL_K3_R,
    GX_TEV_KASEL_K0_G,
    GX_TEV_KASEL_K1_G,
    GX_TEV_KASEL_K2_G,
    GX_TEV_KASEL_K3_G,
    GX_TEV_KASEL_K0_B,
    GX_TEV_KASEL_K1_B,
    GX_TEV_KASEL_K2_B,
    GX_TEV_KASEL_K3_B,
    GX_TEV_KASEL_K0_A,
    GX_TEV_KASEL_K1_A,
    GX_TEV_KASEL_K2_A,
    GX_TEV_KASEL_K3_A,
} GXTevKAlphaSel;

typedef enum _GXTevKColorSel {
    GX_TEV_KCSEL_1,
    GX_TEV_KCSEL_7_8,
    GX_TEV_KCSEL_3_4,
    GX_TEV_KCSEL_5_8,
    GX_TEV_KCSEL_1_2,
    GX_TEV_KCSEL_3_8,
    GX_TEV_KCSEL_1_4,
    GX_TEV_KCSEL_1_8,
    GX_TEV_KCSEL_K0 = 0xC,
    GX_TEV_KCSEL_K1,
    GX_TEV_KCSEL_K2,
    GX_TEV_KCSEL_K3,
    GX_TEV_KCSEL_K0_R,
    GX_TEV_KCSEL_K1_R,
    GX_TEV_KCSEL_K2_R,
    GX_TEV_KCSEL_K3_R,
    GX_TEV_KCSEL_K0_G,
    GX_TEV_KCSEL_K1_G,
    GX_TEV_KCSEL_K2_G,
    GX_TEV_KCSEL_K3_G,
    GX_TEV_KCSEL_K0_B,
    GX_TEV_KCSEL_K1_B,
    GX_TEV_KCSEL_K2_B,
    GX_TEV_KCSEL_K3_B,
    GX_TEV_KCSEL_K0_A,
    GX_TEV_KCSEL_K1_A,
    GX_TEV_KCSEL_K2_A,
    GX_TEV_KCSEL_K3_A,
} GXTevKColorSel;

typedef enum _GXTevMode {
    GX_MODULATE,
    GX_DECAL,
    GX_BLEND,
    GX_REPLACE,
    GX_PASSCLR,
} GXTevMode;

struct GXTevData {
    u32 TEVCOpTableST0[5];
    u32 TEVCOpTableST1[5];
    u32 TEVAOpTableST0[5];
    u32 TEVAOpTableST1[5];
};

typedef enum _GXChannelID {
    GX_COLOR0,
    GX_COLOR1,
    GX_ALPHA0,
    GX_ALPHA1,
    GX_COLOR0A0,
    GX_COLOR1A1,
    GX_COLOR_ZERO,
    GX_ALPHA_BUMP,
    GX_ALPHA_BUMPN,
    GX_COLOR_NULL = 255,
} GXChannelID;

typedef enum _GXTevSwapSel {
    GX_TEV_SWAP0,
    GX_TEV_SWAP1,
    GX_TEV_SWAP2,
    GX_TEV_SWAP3,
    GX_MAX_TEVSWAP,
} GXTevSwapSel;

typedef enum _GXTevColorChan {
    GX_CH_RED,
    GX_CH_GREEN,
    GX_CH_BLUE,
    GX_CH_ALPHA,
} GXTevColorChan;

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

typedef struct _GXVtxAttrFmtList {
    GXAttr attr;
    GXCompCnt cnt;
    GXCompType type;
    u8 frac;
} GXVtxAttrFmtList;

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

typedef struct _GXVtxDescList {
    GXAttr attr;
    GXAttrType type;
} GXVtxDescList;

typedef enum _GXTexFmt {
    GX_TF_I4 = 0x0,
    GX_TF_I8 = 0x1,
    GX_TF_IA4 = 0x2,
    GX_TF_IA8 = 0x3,
    GX_TF_RGB565 = 0x4,
    GX_TF_RGB5A3 = 0x5,
    GX_TF_RGBA8 = 0x6,
    GX_TF_CI14 = 0x9,
    GX_TF_CMPR = 0xE,
    GX_TF_Z8 = 0x11,
    GX_TF_Z16 = 0x13,
    GX_TF_Z24X8 = 0x16,
    GX_CTF_R4 = 0x20,
    GX_CTF_RA4 = 0x22,
    GX_CTF_RA8 = 0x23,
    GX_CTF_YUVA8 = 0x26,
    GX_CTF_A8 = 0x26,
    GX_CTF_R8 = 0x27,
    GX_CTF_G8 = 0x28,
    GX_CTF_B8 = 0x29,
    GX_CTF_RG8 = 0x2A,
    GX_CTF_GB8 = 0x2B,
    GX_CTF_Z4 = 0x30,
    GX_CTF_Z8M = 0x39,
    GX_CTF_Z8L = 0x3A,
    GX_CTF_Z16L = 0x3C,
} GXTexFmt;

typedef enum _GXZTexOp {
    GX_ZT_DISABLE,
    GX_ZT_ADD,
    GX_ZT_REPLACE,
    GX_MAX_ZTEXOP,
} GXZTexOp;

typedef struct {
    u8 pad[128];
} GXFifoObj_u1;

struct __GXFifoObj {
    u8 *base;
    u8 *top;
    u32 size;
    u32 hiWatermark;
    u32 loWatermark;
    void *rdPtr;
    void *wrPtr;
    s32 count;
    u8 bind_cpu;
    u8 bind_gp;
};

typedef enum _GXCPRegs {
    GX_CP_REG_MTXIDXA = 0x30,
    GX_CP_REG_MTXIDXB = 0x40,
    GX_CP_REG_VCD_LO = 0x50,
    GX_CP_REG_VCD_HI = 0x60,
    GX_CP_REG_VAT_GRP0 = 0x70,
    GX_CP_REG_VAT_GRP1 = 0x80,
    GX_CP_REG_VAT_GRP2 = 0x90,
    GX_CP_REG_ARRAYBASE = 0xA0,
    GX_CP_REG_ARRAYSTRIDE = 0xB0,
} GXCPRegs;

typedef enum _GXFogType {
    GX_FOG_NONE = 0,
} GXFogType;

typedef struct FogState {
    u8 pad_0[0x20];
    GXColor color;
    u8 pad_24[0x4];
    u32 colorReg;
} FogState;

extern GXData *const gx;

#endif
