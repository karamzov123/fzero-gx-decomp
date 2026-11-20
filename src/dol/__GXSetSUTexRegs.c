#include <types.h>
#include "sdk_addresses.h"
#pragma dont_inline on

/* --- dol/__GXSetSUTexRegs.c --- */
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

void fn_800365B4(u32 texImgIndex, u32 setUpRegIndex);

void __GXSetSUTexRegs(void) {
    u32 i;
    u32 b;
    u32 a;
    u32 c;
    u32 d;
    u32 stackFiller;
    if (gx->tcsManEnab != 0xff) {
        a = ((gx->genMode) >> (31 - (18) - ((21 - 18 + 1)) + 1) & ((1 << ((21 - 18 + 1))) - 1)) + 1;
        b = ((gx->genMode) >> (31 - (13) - ((15 - 13 + 1)) + 1) & ((1 << ((15 - 13 + 1))) - 1));
        for (i = 0; i < b; i++) {
            switch (i) {
            case 0:
                c = ((gx->iref) >> (31 - (29) - ((31 - 29 + 1)) + 1) &
                     ((1 << ((31 - 29 + 1))) - 1));
                d = ((gx->iref) >> (31 - (26) - ((28 - 26 + 1)) + 1) &
                     ((1 << ((28 - 26 + 1))) - 1));
                break;
            case 1:
                c = ((gx->iref) >> (31 - (23) - ((25 - 23 + 1)) + 1) &
                     ((1 << ((25 - 23 + 1))) - 1));
                d = ((gx->iref) >> (31 - (20) - ((22 - 20 + 1)) + 1) &
                     ((1 << ((22 - 20 + 1))) - 1));
                break;
            case 2:
                c = ((gx->iref) >> (31 - (17) - ((19 - 17 + 1)) + 1) &
                     ((1 << ((19 - 17 + 1))) - 1));
                d = ((gx->iref) >> (31 - (14) - ((16 - 14 + 1)) + 1) &
                     ((1 << ((16 - 14 + 1))) - 1));
                break;
            case 3:
                c = ((gx->iref) >> (31 - (11) - ((13 - 11 + 1)) + 1) &
                     ((1 << ((13 - 11 + 1))) - 1));
                d = ((gx->iref) >> (31 - (8) - ((10 - 8 + 1)) + 1) & ((1 << ((10 - 8 + 1))) - 1));
                break;
            }
            if (!(gx->tcsManEnab & (1 << d))) {
                fn_800365B4(c, d);
            }
        }
        for (i = 0; i < a; i++) {
            u32 *g = &gx->tref[i / 2];
            c = gx->texmapId[i] & ~0x100;
            if (i & 1) {
                d = ((*g) >> (31 - (14) - ((16 - 14 + 1)) + 1) & ((1 << ((16 - 14 + 1))) - 1));
            } else {
                d = ((*g) >> (31 - (26) - ((28 - 26 + 1)) + 1) & ((1 << ((28 - 26 + 1))) - 1));
            }
            if (c != 0xff && !(gx->tcsManEnab & (1 << d)) && gx->tevTcEnab & (1 << i)) {
                fn_800365B4(c, d);
            }
        }
    }
}

/* --- dol/__GXSetTmemConfig.c --- */
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

void __GXSetTmemConfig(u32 config) {
    switch (config) {
    case 1:
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8c0d8000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x900dc000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8d0d8800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x910dc800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8e0d9000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x920dd000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8f0d9800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x930dd800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xac0da000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb00de000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xad0da800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb10de800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xae0db000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb20df000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xaf0db800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb30df800);
        ;
        break;
    case 0:
    default:
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8c0d8000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x900dc000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8d0d8400);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x910dc400);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8e0d8800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x920dc800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8f0d8c00);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x930dcc00);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xac0d9000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb00dd000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xad0d9400);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb10dd400);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xae0d9800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb20dd800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xaf0d9c00);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb30ddc00);
        ;
        break;
    }
}
