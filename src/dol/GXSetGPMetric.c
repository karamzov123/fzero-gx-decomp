#include "sdk_addresses.h"

#include "types.h"

// Hardware or OS state can change asynchronously.
typedef volatile u16 vu16;

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
    u8 lab_pad[4];
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
    s32 perfSel;
    GXBool inDispList;
    GXBool dlSaveContext;
    u8 dirtyVAT;
    u32 dirtyState;
} GXData;

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

void GXSetGPMetric(GXPerf0 perf0, GXPerf1 perf1);

extern GXData *const gx;

extern u16 *__cpReg;

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe GXFIFO : FZGX_ADDR_GXFIFO;

#pragma opt_propagation off
void GXSetGPMetric(GXPerf0 perf0, GXPerf1 perf1) {
    switch (gx->perf0) {
    case GX_PERF0_VERTICES:
    case GX_PERF0_CLIP_VTX:
    case GX_PERF0_CLIP_CLKS:
    case GX_PERF0_XF_WAIT_IN:
    case GX_PERF0_XF_WAIT_OUT:
    case GX_PERF0_XF_XFRM_CLKS:
    case GX_PERF0_XF_LIT_CLKS:
    case GX_PERF0_XF_BOT_CLKS:
    case GX_PERF0_XF_REGLD_CLKS:
    case GX_PERF0_XF_REGRD_CLKS:
    case GX_PERF0_CLIP_RATIO:
    case GX_PERF0_CLOCKS:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0;
        break;
    case GX_PERF0_TRIANGLES:
    case GX_PERF0_TRIANGLES_CULLED:
    case GX_PERF0_TRIANGLES_PASSED:
    case GX_PERF0_TRIANGLES_SCISSORED:
    case GX_PERF0_TRIANGLES_0TEX:
    case GX_PERF0_TRIANGLES_1TEX:
    case GX_PERF0_TRIANGLES_2TEX:
    case GX_PERF0_TRIANGLES_3TEX:
    case GX_PERF0_TRIANGLES_4TEX:
    case GX_PERF0_TRIANGLES_5TEX:
    case GX_PERF0_TRIANGLES_6TEX:
    case GX_PERF0_TRIANGLES_7TEX:
    case GX_PERF0_TRIANGLES_8TEX:
    case GX_PERF0_TRIANGLES_0CLR:
    case GX_PERF0_TRIANGLES_1CLR:
    case GX_PERF0_TRIANGLES_2CLR:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x23000000);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_0CVG:
    case GX_PERF0_QUAD_NON0CVG:
    case GX_PERF0_QUAD_1CVG:
    case GX_PERF0_QUAD_2CVG:
    case GX_PERF0_QUAD_3CVG:
    case GX_PERF0_QUAD_4CVG:
    case GX_PERF0_AVG_QUAD_CNT:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x24000000);
            ;
        } while (0);
        break;
    case GX_PERF0_NONE:
        break;
    }
    switch (gx->perf1) {
    case GX_PERF1_TEXELS:
    case GX_PERF1_TX_IDLE:
    case GX_PERF1_TX_REGS:
    case GX_PERF1_TX_MEMSTALL:
    case GX_PERF1_TC_CHECK1_2:
    case GX_PERF1_TC_CHECK3_4:
    case GX_PERF1_TC_CHECK5_6:
    case GX_PERF1_TC_CHECK7_8:
    case GX_PERF1_TC_MISS:
    case GX_PERF1_CLOCKS:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x67000000);
            ;
        } while (0);
        break;
    case GX_PERF1_VC_ELEMQ_FULL:
    case GX_PERF1_VC_MISSQ_FULL:
    case GX_PERF1_VC_MEMREQ_FULL:
    case GX_PERF1_VC_STATUS7:
    case GX_PERF1_VC_MISSREP_FULL:
    case GX_PERF1_VC_STREAMBUF_LOW:
    case GX_PERF1_VC_ALL_STALLS:
    case GX_PERF1_VERTICES:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(0) << (4));
        ;
        GXFIFO.u8 = 8;
        GXFIFO.u8 = 32;
        GXFIFO.u32 = gx->perfSel;
        break;
    case GX_PERF1_FIFO_REQ:
    case GX_PERF1_CALL_REQ:
    case GX_PERF1_VC_MISS_REQ:
    case GX_PERF1_CP_ALL_REQ:
        (*(vu16 *)((vu16 *)(__cpReg) + (3)) = 0);
        break;
    case GX_PERF1_NONE:
        break;
    }
    gx->perf0 = perf0;
    switch (gx->perf0) {
    case GX_PERF0_VERTICES:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0x273;
        break;
    case GX_PERF0_CLIP_VTX:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0x14A;
        break;
    case GX_PERF0_CLIP_CLKS:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0x16B;
        break;
    case GX_PERF0_XF_WAIT_IN:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0x84;
        break;
    case GX_PERF0_XF_WAIT_OUT:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0xC6;
        break;
    case GX_PERF0_XF_XFRM_CLKS:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0x210;
        break;
    case GX_PERF0_XF_LIT_CLKS:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0x252;
        break;
    case GX_PERF0_XF_BOT_CLKS:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0x231;
        break;
    case GX_PERF0_XF_REGLD_CLKS:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0x1AD;
        break;
    case GX_PERF0_XF_REGRD_CLKS:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0x1CE;
        break;
    case GX_PERF0_CLOCKS:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0x21;
        break;
    case GX_PERF0_CLIP_RATIO:
        GXFIFO.u8 = 0x10;
        GXFIFO.u32 = 0x1006;
        GXFIFO.u32 = 0x153;
        break;
    case GX_PERF0_TRIANGLES:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300AE7F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_CULLED:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x23008E7F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_PASSED:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x23009E7F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_SCISSORED:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x23001E7F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_0TEX:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300AC3F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_1TEX:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300AC7F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_2TEX:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300ACBF);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_3TEX:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300ACFF);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_4TEX:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300AD3F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_5TEX:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300AD7F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_6TEX:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300ADBF);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_7TEX:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300ADFF);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_8TEX:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300AE3F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_0CLR:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300A27F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_1CLR:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300A67F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_2CLR:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2300AA7F);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_0CVG:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2402C0C6);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_NON0CVG:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2402C16B);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_1CVG:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2402C0E7);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_2CVG:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2402C108);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_3CVG:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2402C129);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_4CVG:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2402C14A);
            ;
        } while (0);
        break;
    case GX_PERF0_AVG_QUAD_CNT:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x2402C1AD);
            ;
        } while (0);
        break;
    case GX_PERF0_NONE:
        break;
    }
    gx->perf1 = perf1;
    switch (gx->perf1) {
    case GX_PERF1_TEXELS:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x67000042);
            ;
        } while (0);
        break;
    case GX_PERF1_TX_IDLE:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x67000084);
            ;
        } while (0);
        break;
    case GX_PERF1_TX_REGS:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x67000063);
            ;
        } while (0);
        break;
    case GX_PERF1_TX_MEMSTALL:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x67000129);
            ;
        } while (0);
        break;
    case GX_PERF1_TC_MISS:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x67000252);
            ;
        } while (0);
        break;
    case GX_PERF1_CLOCKS:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x67000021);
            ;
        } while (0);
        break;
    case GX_PERF1_TC_CHECK1_2:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x6700014B);
            ;
        } while (0);
        break;
    case GX_PERF1_TC_CHECK3_4:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x6700018D);
            ;
        } while (0);
        break;
    case GX_PERF1_TC_CHECK5_6:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x670001CF);
            ;
        } while (0);
        break;
    case GX_PERF1_TC_CHECK7_8:
        do {
            GXFIFO.u8 = (u8)(0x61);
            GXFIFO.u32 = (u32)(0x67000211);
            ;
        } while (0);
        break;
    case GX_PERF1_VC_ELEMQ_FULL:
        gx->perfSel = (gx->perfSel & 0xFFFFFF0F) | 0x20;
        ;
        GXFIFO.u8 = 8;
        GXFIFO.u8 = 32;
        GXFIFO.u32 = gx->perfSel;
        break;
    case GX_PERF1_VC_MISSQ_FULL:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(3) << (4));
        ;
        GXFIFO.u8 = 8;
        GXFIFO.u8 = 32;
        GXFIFO.u32 = gx->perfSel;
        break;
    case GX_PERF1_VC_MEMREQ_FULL:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(4) << (4));
        ;
        GXFIFO.u8 = 8;
        GXFIFO.u8 = 32;
        GXFIFO.u32 = gx->perfSel;
        break;
    case GX_PERF1_VC_STATUS7:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(5) << (4));
        ;
        GXFIFO.u8 = 8;
        GXFIFO.u8 = 32;
        GXFIFO.u32 = gx->perfSel;
        break;
    case GX_PERF1_VC_MISSREP_FULL:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(6) << (4));
        ;
        GXFIFO.u8 = 8;
        GXFIFO.u8 = 32;
        GXFIFO.u32 = gx->perfSel;
        break;
    case GX_PERF1_VC_STREAMBUF_LOW:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(7) << (4));
        ;
        GXFIFO.u8 = 8;
        GXFIFO.u8 = 32;
        GXFIFO.u32 = gx->perfSel;
        break;
    case GX_PERF1_VC_ALL_STALLS:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(9) << (4));
        ;
        GXFIFO.u8 = 8;
        GXFIFO.u8 = 32;
        GXFIFO.u32 = gx->perfSel;
        break;
    case GX_PERF1_VERTICES:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(8) << (4));
        ;
        GXFIFO.u8 = 8;
        GXFIFO.u8 = 32;
        GXFIFO.u32 = gx->perfSel;
        break;
    case GX_PERF1_FIFO_REQ:
        (*(vu16 *)((vu16 *)(__cpReg) + (3)) = 2);
        break;
    case GX_PERF1_CALL_REQ:
        (*(vu16 *)((vu16 *)(__cpReg) + (3)) = 3);
        break;
    case GX_PERF1_VC_MISS_REQ:
        (*(vu16 *)((vu16 *)(__cpReg) + (3)) = 4);
        break;
    case GX_PERF1_CP_ALL_REQ:
        (*(vu16 *)((vu16 *)(__cpReg) + (3)) = 5);
        break;
    case GX_PERF1_NONE:
        break;
    }
    gx->bpSentNot = ((GXBool)0);
}
#pragma opt_propagation reset

