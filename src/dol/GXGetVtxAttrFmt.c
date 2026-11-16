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

extern GXData *const gx;

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

typedef struct GXVtxAttrFmt {
    u32 attr;
    GXCompCnt cnt;
    GXCompType type;
    u8 frac;
} GXVtxAttrFmt;

void GXGetVtxAttrFmtv(GXVtxFmt vat, GXVtxAttrFmt *fmt) {
    int attr;

    for (attr = 9; attr <= 20; attr++) {
        fmt->attr = (u32)attr;
        GXGetVtxAttrFmt(vat, attr, &fmt->cnt, &fmt->type, &fmt->frac);
        fmt++;
    }
    fmt->attr = 0xff;
}

#include "sdk_addresses.h"

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
    u64 u64;
    s8 s8;
    s16 s16;
    s32 s32;
    s64 s64;
    f32 f32;
    f64 f64;
} PPCWGPipe;

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

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
        GXFIFO.u8 = (u8)(8);
        GXFIFO.u8 = (u8)(cpAttr | GX_BP_REG_SETMODE0_TEX4);
        GXFIFO.u32 = (u32)(phyAddr);
        regAddr = cpAttr - 12;
        if (regAddr >= 0 && regAddr < 4) {
            gx->indexBase[regAddr] = phyAddr;
        }
    } while (0);
    do {
        long regAddr;
        GXFIFO.u8 = (u8)(8);
        GXFIFO.u8 = (u8)(cpAttr | GX_BP_REG_SETIMAGE2_TEX4);
        GXFIFO.u32 = (u32)(stride);
        regAddr = cpAttr - 12;
        if (regAddr >= 0 && regAddr < 4) {
            gx->indexStride[regAddr] = stride;
        }
    } while (0);
}

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
} GXWGFifoReg;

#define GXWGFifoAddress ((u32)(0xCC00 << 16) + 0x8000)
// Hardware FIFO register is intentionally volatile.
#define GXWGFifo (*(volatile GXWGFifoReg *)GXWGFifoAddress)

void GXInvalidateVtxCache(void) {
    GXWGFifo.u8 = 0x48;
}

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

void __GXSetMatrixIndex(GXAttr index);

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

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
        GXFIFO.u8 = (u8)(0x10);
        GXFIFO.u32 = (u32)(0x1000 + (dst_coord + 0x40));
        GXFIFO.u32 = (u32)(reg);
        ;
    } while (0);
    reg = 0;
    (reg) = ((u32)(reg) & ~(((1 << (6)) - 1) << (0))) | ((u32)(pt_texmtx - 64) << (0));
    ;
    (reg) = ((u32)(reg) & ~(((1 << (1)) - 1) << (8))) | ((u32)(normalize) << (8));
    ;
    do {
        GXFIFO.u8 = (u8)(0x10);
        GXFIFO.u32 = (u32)(0x1000 + (dst_coord + 0x50));
        GXFIFO.u32 = (u32)(reg);
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

