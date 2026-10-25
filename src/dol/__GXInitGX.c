#pragma peephole off
#include "types.h"

typedef u8 GXBool;

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
    GX_MAX_ALPHAOP,
} GXAlphaOp;

typedef enum _GXZFmt16 {
    GX_ZC_LINEAR,
    GX_ZC_NEAR,
    GX_ZC_MID,
    GX_ZC_FAR,
} GXZFmt16;

typedef enum _GXGamma {
    GX_GM_1_0,
    GX_GM_1_7,
    GX_GM_2_2,
} GXGamma;

typedef enum _GXPixelFmt {
    GX_PF_RGB8_Z24,
    GX_PF_RGBA6_Z24,
    GX_PF_RGB565_Z16,
    GX_PF_Z24,
    GX_PF_Y8,
    GX_PF_U8,
    GX_PF_V8,
    GX_PF_YUV420,
} GXPixelFmt;

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
    GX_VA_NULL = 0xFF,
} GXAttr;

typedef enum _GXAttrType {
    GX_NONE,
    GX_DIRECT,
    GX_INDEX8,
    GX_INDEX16,
} GXAttrType;

typedef enum _GXTexFmt {
    GX_TF_I4 = 0x0,
    GX_TF_I8 = 0x1,
    GX_TF_IA4 = 0x2,
    GX_TF_IA8 = 0x3,
    GX_TF_RGB565 = 0x4,
    GX_TF_RGB5A3 = 0x5,
    GX_TF_RGBA8 = 0x6,
    GX_TF_CMPR = 0xE,
    GX_CTF_R4 = 0x0 | 0x20,
    GX_CTF_RA4 = 0x2 | 0x20,
    GX_CTF_RA8 = 0x3 | 0x20,
    GX_CTF_YUVA8 = 0x6 | 0x20,
    GX_CTF_A8 = 0x7 | 0x20,
    GX_CTF_R8 = 0x8 | 0x20,
    GX_CTF_G8 = 0x9 | 0x20,
    GX_CTF_B8 = 0xA | 0x20,
    GX_CTF_RG8 = 0xB | 0x20,
    GX_CTF_GB8 = 0xC | 0x20,
    GX_TF_Z8 = 0x1 | 0x10,
    GX_TF_Z16 = 0x3 | 0x10,
    GX_TF_Z24X8 = 0x6 | 0x10,
    GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    GX_TF_A8 = GX_CTF_A8,
} GXTexFmt;

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
    GX_TEXMAP_NULL = 0xFF,
    GX_TEX_DISABLE = 0x100,
} GXTexMapID;

typedef enum _GXTexCoordID {
    GX_TEXCOORD0,
    GX_TEXCOORD1,
    GX_TEXCOORD2,
    GX_TEXCOORD3,
    GX_TEXCOORD4,
    GX_TEXCOORD5,
    GX_TEXCOORD6,
    GX_TEXCOORD7,
    GX_MAX_TEXCOORD,
    GX_TEXCOORD_NULL = 0xFF,
} GXTexCoordID;

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

typedef enum _GXTevMode {
    GX_MODULATE,
    GX_DECAL,
    GX_BLEND,
    GX_REPLACE,
    GX_PASSCLR,
} GXTevMode;

typedef enum _GXTexMtxType {
    GX_MTX3x4,
    GX_MTX2x4,
} GXTexMtxType;

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

typedef enum _GXPosNrmMtx {
    GX_PNMTX0 = 0,
    GX_PNMTX1 = 3,
    GX_PNMTX2 = 6,
    GX_PNMTX3 = 9,
    GX_PNMTX4 = 12,
    GX_PNMTX5 = 15,
    GX_PNMTX6 = 18,
    GX_PNMTX7 = 21,
    GX_PNMTX8 = 24,
    GX_PNMTX9 = 27,
} GXPosNrmMtx;

typedef enum _GXTexMtx {
    GX_TEXMTX0 = 30,
    GX_TEXMTX1 = 33,
    GX_TEXMTX2 = 36,
    GX_TEXMTX3 = 39,
    GX_TEXMTX4 = 42,
    GX_TEXMTX5 = 45,
    GX_TEXMTX6 = 48,
    GX_TEXMTX7 = 51,
    GX_TEXMTX8 = 54,
    GX_TEXMTX9 = 57,
    GX_IDENTITY = 60,
} GXTexMtx;

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
    GX_COLOR_NULL = 0xFF,
} GXChannelID;

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

typedef enum _GXBlendMode {
    GX_BM_NONE,
    GX_BM_BLEND,
    GX_BM_LOGIC,
    GX_BM_SUBTRACT,
    GX_MAX_BLENDMODE,
} GXBlendMode;

typedef enum _GXBlendFactor {
    GX_BL_ZERO,
    GX_BL_ONE,
    GX_BL_SRCCLR,
    GX_BL_INVSRCCLR,
    GX_BL_SRCALPHA,
    GX_BL_INVSRCALPHA,
    GX_BL_DSTALPHA,
    GX_BL_INVDSTALPHA,
    GX_BL_DSTCLR = GX_BL_SRCCLR,
    GX_BL_INVDSTCLR = GX_BL_INVSRCCLR,
} GXBlendFactor;

typedef enum _GXLogicOp {
    GX_LO_CLEAR,
    GX_LO_AND,
    GX_LO_REVAND,
    GX_LO_COPY,
    GX_LO_INVAND,
    GX_LO_NOOP,
    GX_LO_XOR,
    GX_LO_OR,
    GX_LO_NOR,
    GX_LO_EQUIV,
    GX_LO_INV,
    GX_LO_REVOR,
    GX_LO_INVCOPY,
    GX_LO_INVOR,
    GX_LO_NAND,
    GX_LO_SET,
} GXLogicOp;

typedef enum _GXPTTexMtx {
    GX_PTTEXMTX0 = 64,
    GX_PTTEXMTX1 = 67,
    GX_PTTEXMTX2 = 70,
    GX_PTTEXMTX3 = 73,
    GX_PTTEXMTX4 = 76,
    GX_PTTEXMTX5 = 79,
    GX_PTTEXMTX6 = 82,
    GX_PTTEXMTX7 = 85,
    GX_PTTEXMTX8 = 88,
    GX_PTTEXMTX9 = 91,
    GX_PTTEXMTX10 = 94,
    GX_PTTEXMTX11 = 97,
    GX_PTTEXMTX12 = 100,
    GX_PTTEXMTX13 = 103,
    GX_PTTEXMTX14 = 106,
    GX_PTTEXMTX15 = 109,
    GX_PTTEXMTX16 = 112,
    GX_PTTEXMTX17 = 115,
    GX_PTTEXMTX18 = 118,
    GX_PTTEXMTX19 = 121,
    GX_PTIDENTITY = 125,
} GXPTTexMtx;

typedef enum _GXDiffuseFn {
    GX_DF_NONE,
    GX_DF_SIGN,
    GX_DF_CLAMP,
} GXDiffuseFn;

typedef enum _GXColorSrc {
    GX_SRC_REG,
    GX_SRC_VTX,
} GXColorSrc;

typedef enum _GXAttnFn {
    GX_AF_SPEC,
    GX_AF_SPOT,
    GX_AF_NONE,
} GXAttnFn;

typedef enum _GXLightID {
    GX_LIGHT0 = 0x001,
    GX_LIGHT1 = 0x002,
    GX_LIGHT2 = 0x004,
    GX_LIGHT3 = 0x008,
    GX_LIGHT4 = 0x010,
    GX_LIGHT5 = 0x020,
    GX_LIGHT6 = 0x040,
    GX_LIGHT7 = 0x080,
    GX_MAX_LIGHT = 0x100,
    GX_LIGHT_NULL = 0,
} GXLightID;

typedef enum _GXTexOffset {
    GX_TO_ZERO,
    GX_TO_SIXTEENTH,
    GX_TO_EIGHTH,
    GX_TO_FOURTH,
    GX_TO_HALF,
    GX_TO_ONE,
    GX_MAX_TEXOFFSET,
} GXTexOffset;

typedef enum _GXCullMode { GX_CULL_NONE, GX_CULL_FRONT, GX_CULL_BACK, GX_CULL_ALL } GXCullMode;

typedef enum _GXTevSwapSel {
    GX_TEV_SWAP0 = 0,
    GX_TEV_SWAP1,
    GX_TEV_SWAP2,
    GX_TEV_SWAP3,
    GX_MAX_TEVSWAP
} GXTevSwapSel;

typedef enum _GXTevColorChan { GX_CH_RED = 0, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA } GXTevColorChan;

typedef enum _GXFogType {
    GX_FOG_NONE = 0,
    GX_FOG_LIN = 2,
    GX_FOG_EXP = 4,
    GX_FOG_EXP2 = 5,
    GX_FOG_REVEXP = 6,
    GX_FOG_REVEXP2 = 7
} GXFogType;

typedef enum _GXTevKColorSel {
    GX_TEV_KCSEL_1 = 0x00,
    GX_TEV_KCSEL_7_8 = 0x01,
    GX_TEV_KCSEL_3_4 = 0x02,
    GX_TEV_KCSEL_5_8 = 0x03,
    GX_TEV_KCSEL_1_2 = 0x04,
    GX_TEV_KCSEL_3_8 = 0x05,
    GX_TEV_KCSEL_1_4 = 0x06,
    GX_TEV_KCSEL_1_8 = 0x07,
    GX_TEV_KCSEL_K0 = 0x0C,
    GX_TEV_KCSEL_K1 = 0x0D,
    GX_TEV_KCSEL_K2 = 0x0E,
    GX_TEV_KCSEL_K3 = 0x0F,
    GX_TEV_KCSEL_K0_R = 0x10,
    GX_TEV_KCSEL_K1_R = 0x11,
    GX_TEV_KCSEL_K2_R = 0x12,
    GX_TEV_KCSEL_K3_R = 0x13,
    GX_TEV_KCSEL_K0_G = 0x14,
    GX_TEV_KCSEL_K1_G = 0x15,
    GX_TEV_KCSEL_K2_G = 0x16,
    GX_TEV_KCSEL_K3_G = 0x17,
    GX_TEV_KCSEL_K0_B = 0x18,
    GX_TEV_KCSEL_K1_B = 0x19,
    GX_TEV_KCSEL_K2_B = 0x1A,
    GX_TEV_KCSEL_K3_B = 0x1B,
    GX_TEV_KCSEL_K0_A = 0x1C,
    GX_TEV_KCSEL_K1_A = 0x1D,
    GX_TEV_KCSEL_K2_A = 0x1E,
    GX_TEV_KCSEL_K3_A = 0x1F
} GXTevKColorSel;

typedef enum _GXTevKAlphaSel {
    GX_TEV_KASEL_1 = 0x00,
    GX_TEV_KASEL_7_8 = 0x01,
    GX_TEV_KASEL_3_4 = 0x02,
    GX_TEV_KASEL_5_8 = 0x03,
    GX_TEV_KASEL_1_2 = 0x04,
    GX_TEV_KASEL_3_8 = 0x05,
    GX_TEV_KASEL_1_4 = 0x06,
    GX_TEV_KASEL_1_8 = 0x07,
    GX_TEV_KASEL_K0_R = 0x10,
    GX_TEV_KASEL_K1_R = 0x11,
    GX_TEV_KASEL_K2_R = 0x12,
    GX_TEV_KASEL_K3_R = 0x13,
    GX_TEV_KASEL_K0_G = 0x14,
    GX_TEV_KASEL_K1_G = 0x15,
    GX_TEV_KASEL_K2_G = 0x16,
    GX_TEV_KASEL_K3_G = 0x17,
    GX_TEV_KASEL_K0_B = 0x18,
    GX_TEV_KASEL_K1_B = 0x19,
    GX_TEV_KASEL_K2_B = 0x1A,
    GX_TEV_KASEL_K3_B = 0x1B,
    GX_TEV_KASEL_K0_A = 0x1C,
    GX_TEV_KASEL_K1_A = 0x1D,
    GX_TEV_KASEL_K2_A = 0x1E,
    GX_TEV_KASEL_K3_A = 0x1F
} GXTevKAlphaSel;

typedef enum _GXZTexOp {
    GX_ZT_DISABLE,
    GX_ZT_ADD,
    GX_ZT_REPLACE,
    GX_MAX_ZTEXOP,
} GXZTexOp;

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

typedef enum _GXPerf0 {
    GX_PERF0_VERTICES,
    GX_PERF0_CLIP_VTX,
    GX_PERF0_CLIP_CLKS,
    GX_PERF0_XF_WAIT_IN,
    GX_PERF0_XF_WAIT_OUT,
    GX_PERF0_XF_XFRM_CLKS,
    GX_PERF0_XF_LIT_CLKS,
    GX_PERF0_XF_BOT_CLKS,
    GX_PERF0_XF_REGLD_CLKS,
    GX_PERF0_XF_REGRD_CLKS,
    GX_PERF0_CLIP_RATIO,
    GX_PERF0_TRIANGLES,
    GX_PERF0_TRIANGLES_CULLED,
    GX_PERF0_TRIANGLES_PASSED,
    GX_PERF0_TRIANGLES_SCISSORED,
    GX_PERF0_TRIANGLES_0TEX,
    GX_PERF0_TRIANGLES_1TEX,
    GX_PERF0_TRIANGLES_2TEX,
    GX_PERF0_TRIANGLES_3TEX,
    GX_PERF0_TRIANGLES_4TEX,
    GX_PERF0_TRIANGLES_5TEX,
    GX_PERF0_TRIANGLES_6TEX,
    GX_PERF0_TRIANGLES_7TEX,
    GX_PERF0_TRIANGLES_8TEX,
    GX_PERF0_TRIANGLES_0CLR,
    GX_PERF0_TRIANGLES_1CLR,
    GX_PERF0_TRIANGLES_2CLR,
    GX_PERF0_QUAD_0CVG,
    GX_PERF0_QUAD_NON0CVG,
    GX_PERF0_QUAD_1CVG,
    GX_PERF0_QUAD_2CVG,
    GX_PERF0_QUAD_3CVG,
    GX_PERF0_QUAD_4CVG,
    GX_PERF0_AVG_QUAD_CNT,
    GX_PERF0_CLOCKS,
    GX_PERF0_NONE,
} GXPerf0;

typedef enum _GXPerf1 {
    GX_PERF1_TEXELS,
    GX_PERF1_TX_IDLE,
    GX_PERF1_TX_REGS,
    GX_PERF1_TX_MEMSTALL,
    GX_PERF1_TC_CHECK1_2,
    GX_PERF1_TC_CHECK3_4,
    GX_PERF1_TC_CHECK5_6,
    GX_PERF1_TC_CHECK7_8,
    GX_PERF1_TC_MISS,
    GX_PERF1_VC_ELEMQ_FULL,
    GX_PERF1_VC_MISSQ_FULL,
    GX_PERF1_VC_MEMREQ_FULL,
    GX_PERF1_VC_STATUS7,
    GX_PERF1_VC_MISSREP_FULL,
    GX_PERF1_VC_STREAMBUF_LOW,
    GX_PERF1_VC_ALL_STALLS,
    GX_PERF1_VERTICES,
    GX_PERF1_FIFO_REQ,
    GX_PERF1_CALL_REQ,
    GX_PERF1_VC_MISS_REQ,
    GX_PERF1_CP_ALL_REQ,
    GX_PERF1_CLOCKS,
    GX_PERF1_NONE,
} GXPerf1;

typedef enum _GXClipMode {
    GX_CLIP_ENABLE = 0,
    GX_CLIP_DISABLE = 1,
} GXClipMode;

typedef enum _GXFBClamp {
    GX_CLAMP_NONE = 0,
    GX_CLAMP_TOP = 1,
    GX_CLAMP_BOTTOM = 2,
} GXFBClamp;

typedef enum _GXCopyMode {
    GX_COPY_PROGRESSIVE = 0,
    GX_COPY_INTLC_EVEN = 2,
    GX_COPY_INTLC_ODD = 3,
} GXCopyMode;

typedef enum _GXAlphaReadMode {
    GX_READ_00,
    GX_READ_FF,
    GX_READ_NONE,
} GXAlphaReadMode;

typedef struct OSContext {
    u32 gpr[32];
    u32 cr;
    u32 lr;
    u32 ctr;
    u32 xer;
    f64 fpr[32];
    u32 fpscr_pad;
    u32 fpscr;
    u32 srr0;
    u32 srr1;
    u16 mode;
    u16 state;
    u32 gqr[8];
    f64 psf[32];
} OSContext;

typedef s32 OSPriority;

struct OSThread;

struct OSMutex;

struct OSMutexQueue;

typedef struct OSThreadQueue {
    struct OSThread *head;
    struct OSThread *tail;
} OSThreadQueue;

typedef struct OSThreadLink {
    struct OSThread *next;
    struct OSThread *prev;
} OSThreadLink;

typedef struct OSMutexQueue {
    struct OSMutex *head;
    struct OSMutex *tail;
} OSMutexQueue;

typedef struct OSMutexLink {
    struct OSMutex *next;
    struct OSMutex *prev;
} OSMutexLink;

typedef struct OSThread {
    struct OSContext context;
    u16 state;
    u16 attr;
    s32 suspend;
    OSPriority priority;
    OSPriority base;
    void *val;
    struct OSThreadQueue *queue;
    struct OSThreadLink link;
    struct OSThreadQueue queueJoin;
    struct OSMutex *mutex;
    struct OSMutexQueue queueMutex;
    struct OSThreadLink linkActive;
    u8 *stackBase;
    u32 *stackEnd;
} OSThread;

typedef enum {
    VI_TVMODE_NTSC_INT = (((0) << 2) + (0)),
    VI_TVMODE_NTSC_DS = (((0) << 2) + (1)),
    VI_TVMODE_NTSC_PROG = (((0) << 2) + (2)),
    VI_TVMODE_3 = 3,
    VI_TVMODE_PAL_INT = (((1) << 2) + (0)),
    VI_TVMODE_PAL_DS = (((1) << 2) + (1)),
    VI_TVMODE_EURGB60_INT = (((5) << 2) + (0)),
    VI_TVMODE_EURGB60_DS = (((5) << 2) + (1)),
    VI_TVMODE_MPAL_INT = (((2) << 2) + (0)),
    VI_TVMODE_MPAL_DS = (((2) << 2) + (1)),
    VI_TVMODE_DEBUG_INT = (((3) << 2) + (0)),
    VI_TVMODE_DEBUG_PAL_INT = (((4) << 2) + (0)),
    VI_TVMODE_DEBUG_PAL_DS = (((4) << 2) + (1)),
} VITVMode;

typedef enum { VI_XFBMODE_SF = 0, VI_XFBMODE_DF } VIXFBMode;

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

typedef struct _GXColor {
    u8 r, g, b, a;
} GXColor;

typedef struct _GXTexObj {
    u32 dummy[8];
} GXTexObj;

typedef struct _GXTexRegion {
    u32 dummy[4];
} GXTexRegion;

typedef struct _GXTlutRegion {
    u32 dummy[4];
} GXTlutRegion;

typedef struct _GXFogAdjTable {
    u16 r[10];
} GXFogAdjTable;

typedef GXTexRegion *(*GXTexRegionCallback)(GXTexObj *t_obj, GXTexMapID id);

typedef GXTlutRegion *(*GXTlutRegionCallback)(u32 idx);

typedef struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;
    OSMutexLink link;
} OSMutex;

struct OSContext;

struct __GXData_struct {
    u16 vNum;
    u16 bpSent;
    u16 unk04;
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
    u8 cpTexZ;
    u32 genMode;
    GXTexRegion TexRegions[8];
    GXTexRegion TexRegionsCI[4];
    u32 nextTexRgn;
    u32 nextTexRgnCI;
    GXTlutRegion TlutRegions[20];
    GXTexRegion *(*texRegionCallback)(GXTexObj *, GXTexMapID);
    GXTlutRegion *(*tlutRegionCallback)(u32);
    GXAttrType nrmType;
    u8 hasNrms;
    u8 hasBiNrms;
    u32 projType;
    float projMtx[6];
    float vpLeft;
    float vpTop;
    float vpWd;
    float vpHt;
    float vpNearz;
    float vpFarz;
    u8 fgRange;
    float fgSideX;
    u32 tImage0[8];
    u32 tMode0[8];
    u32 texmapId[16];
    u32 tcsManEnab;
    u32 pad0;
    GXPerf0 perf0;
    GXPerf1 perf1;
    u32 perfSel;
    u8 inDispList;
    u8 dlSaveContext;
    u8 dirtyVAT;
    u32 dirtyState;
};

void __GXInitGX();

void GXSetIndTexCoordScale(GXIndTexStageID ind_state, GXIndTexScale scale_s, GXIndTexScale scale_t);

void GXSetNumIndStages(u8 nIndStages);

void fn_80036EDC(GXTevStageID tev_stage);

void GXPokeAlphaMode(GXCompare func, u8 threshold);

void GXPokeAlphaRead(GXAlphaReadMode mode);

void GXPokeAlphaUpdate(GXBool update_enable);

void GXPokeBlendMode(GXBlendMode type, GXBlendFactor src_factor, GXBlendFactor dst_factor,
                     GXLogicOp op);

void GXPokeColorUpdate(GXBool update_enable);

void GXPokeDstAlpha(GXBool enable, u8 alpha);

void GXPokeDither(GXBool dither);

void GXPokeZMode(GXBool compare_enable, GXCompare func, GXBool update_enable);

void GXSetScissor(u32 left, u32 top, u32 wd, u32 ht);

void fn_80034890(GXCullMode mode);

void GXSetCoPlanar(GXBool enable);

extern int OSCreateThread(OSThread *thread, void *(*func)(void *), void *param, void *stack,
                          u32 stackSize, s32 priority, u16 attr);

extern GXRenderModeObj lbl_8012AFB8;
extern u8 lbl_8012AC44[];
extern f32 lbl_8012AD14[];
extern void GXSetProjectionv(f32 *);

extern GXRenderModeObj lbl_8012B06C;

extern GXRenderModeObj lbl_8012B0A8;

extern GXRenderModeObj lbl_8012B0E4;

void GXSetDispCopySrc(u16 left, u16 top, u16 wd, u16 ht);

void fn_80034B7C(u16 wd, u16 ht);

void GXSetDispCopyFrame2Field(GXCopyMode mode);

void fn_80034D34(GXFBClamp clamp);

u32 GXSetDispCopyYScale(f32 vscale);

void GXSetCopyClear(GXColor clear_clr, u32 clear_z);

void fn_80034ECC(GXBool aa, const u8 sample_pattern[12][2], GXBool vf, const u8 vfilter[7]);

void GXSetDispCopyGamma(GXGamma gamma);

void GXClearBoundingBox(void);

void GXClearVtxDesc(void);

void GXSetArray(GXAttr attr, const void *base_ptr, u8 stride);

void GXInvalidateVtxCache(void);

void GXSetTexCoordGen2(GXTexCoordID dst_coord, GXTexGenType func, GXTexGenSrc src_param, u32 mtx,
                       GXBool normalize, u32 pt_texmtx);

void GXSetNumTexGens(u8 nTexGens);

static inline void GXSetTexCoordGen(GXTexCoordID dst_coord, GXTexGenType func,
                                    GXTexGenSrc src_param, u32 mtx) {
    GXSetTexCoordGen2(dst_coord, func, src_param, mtx, ((GXBool)0), GX_PTIDENTITY);
}

void GXSetLineWidth(u8 width, GXTexOffset texOffsets);

void GXSetPointSize(u8 pointSize, GXTexOffset texOffsets);

void fn_80034834(GXTexCoordID coord, u8 line_enable, u8 point_enable);

void fn_80035734(GXChannelID chan, GXColor amb_color);

void fn_80035828(GXChannelID chan, GXColor mat_color);

void fn_8003591C(u8 nChans);

void fn_80035960(GXChannelID chan, GXBool enable, GXColorSrc amb_src, GXColorSrc mat_src,
                 u32 light_mask, GXDiffuseFn diff_fn, GXAttnFn attn_fn);

void GXSetGPMetric(GXPerf0 perf0, GXPerf1 perf1);

void GXClearGPMetric(void);

void fn_800377F8(GXFogType type, f32 startz, f32 endz, f32 nearz, f32 farz, GXColor color);

void GXSetFogRangeAdj(GXBool enable, u16 center, GXFogAdjTable *table);

void fn_80037B14(GXBlendMode type, GXBlendFactor src_factor, GXBlendFactor dst_factor,
                 GXLogicOp op);

void fn_80037B68(GXBool update_enable);

void fn_80037B94(GXBool update_enable);

void fn_80037BC0(GXBool compare_enable, GXCompare func, GXBool update_enable);

void GXSetZCompLoc(GXBool before_tex);

void fn_80037C2C(GXPixelFmt pix_fmt, GXZFmt16 z_fmt);

void fn_80037D14(GXBool dither);

void fn_80037D40(GXBool enable, u8 alpha);

void GXSetFieldMask(GXBool odd_mask, GXBool even_mask);

void GXSetFieldMode(GXBool field_mode, GXBool half_aspect_ratio);

void GXSetTevOp(GXTevStageID id, GXTevMode mode);

void GXSetTevKColorSel(GXTevStageID stage, GXTevKColorSel sel);

void GXSetTevKAlphaSel(GXTevStageID stage, GXTevKAlphaSel sel);

void GXSetTevSwapMode(GXTevStageID stage, GXTevSwapSel ras_sel, GXTevSwapSel tex_sel);

void GXSetTevSwapModeTable(GXTevSwapSel table, GXTevColorChan red, GXTevColorChan green,
                           GXTevColorChan blue, GXTevColorChan alpha);

void GXSetAlphaCompare(GXCompare comp0, u8 ref0, GXAlphaOp op, GXCompare comp1, u8 ref1);

void GXSetZTexture(GXZTexOp op, GXTexFmt fmt, u32 bias);

void GXSetTevOrder(GXTevStageID stage, GXTexCoordID coord, GXTexMapID map, GXChannelID color);

void GXSetNumTevStages(u8 nStages);

void GXInvalidateTexAll(void);

GXTexRegionCallback GXSetTexRegionCallback(GXTexRegionCallback f);

GXTlutRegionCallback GXSetTlutRegionCallback(GXTlutRegionCallback f);

void GXLoadPosMtxImm(f32 mtx[3][4], u32 id);

void GXLoadNrmMtxImm(f32 mtx[3][4], u32 id);

void GXSetCurrentMtx(u32 id);

void GXLoadTexMtxImm(f32 mtx[][4], u32 id, GXTexMtxType type);

void fn_80038EEC(f32 left, f32 top, f32 wd, f32 ht, f32 nearz, f32 farz);

void GXSetScissorBoxOffset(s32 x_off, s32 y_off);

void GXSetClipMode(GXClipMode mode);

void (*DVDLowClearCallback())(u32);

u32 VIGetTvFormat(void);

extern struct __GXData_struct *gx;

GXTexRegion *__GXDefaultTexRegionCallback(GXTexObj *t_obj, GXTexMapID unused);

GXTlutRegion *fn_80030848(u32 idx);

void __GXInitGX() {
    GXRenderModeObj *rmode;
    f32 identity_mtx[3][4];
    GXColor clear = {64, 64, 64, 255};
    GXColor black = {0, 0, 0, 0};
    GXColor white = {255, 255, 255, 255};
    u32 i;
    switch (VIGetTvFormat()) {
    case 0:
        rmode = &lbl_8012AFB8;
        break;
    case 1:
        rmode = &lbl_8012B0A8;
        break;
    case 5:
        rmode = &lbl_8012B0E4;
        break;
    case 2:
        rmode = &lbl_8012B06C;
        break;
    default:
        rmode = &lbl_8012AFB8;
        break;
    }
    GXSetCopyClear(clear, 0xFFFFFF);
    GXSetTexCoordGen(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3CU);
    GXSetTexCoordGen(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_TEX1, 0x3CU);
    GXSetTexCoordGen(GX_TEXCOORD2, GX_TG_MTX2x4, GX_TG_TEX2, 0x3CU);
    GXSetTexCoordGen(GX_TEXCOORD3, GX_TG_MTX2x4, GX_TG_TEX3, 0x3CU);
    GXSetTexCoordGen(GX_TEXCOORD4, GX_TG_MTX2x4, GX_TG_TEX4, 0x3CU);
    GXSetTexCoordGen(GX_TEXCOORD5, GX_TG_MTX2x4, GX_TG_TEX5, 0x3CU);
    GXSetTexCoordGen(GX_TEXCOORD6, GX_TG_MTX2x4, GX_TG_TEX6, 0x3CU);
    GXSetTexCoordGen(GX_TEXCOORD7, GX_TG_MTX2x4, GX_TG_TEX7, 0x3CU);
    GXSetNumTexGens(1);
    GXClearVtxDesc();
    GXInvalidateVtxCache();
    for (i = GX_VA_POS; i <= GX_LIGHT_ARRAY; ++i)
        GXSetArray(i, gx, 0);
    for (i = 0; i < 8; ++i)
        GXSetVtxAttrFmtv(i, lbl_8012AC44);
    GXSetLineWidth(6, 0);
    GXSetPointSize(6, 0);
    fn_80034834(0, 0, 0);
    fn_80034834(1, 0, 0);
    fn_80034834(2, 0, 0);
    fn_80034834(3, 0, 0);
    fn_80034834(4, 0, 0);
    fn_80034834(5, 0, 0);
    fn_80034834(6, 0, 0);
    fn_80034834(7, 0, 0);
    identity_mtx[0][0] = 1.0f;
    identity_mtx[0][1] = 0.0f;
    identity_mtx[0][2] = 0.0f;
    identity_mtx[0][3] = 0.0f;
    identity_mtx[1][0] = 0.0f;
    identity_mtx[1][1] = 1.0f;
    identity_mtx[1][2] = 0.0f;
    identity_mtx[1][3] = 0.0f;
    identity_mtx[2][0] = 0.0f;
    identity_mtx[2][1] = 0.0f;
    identity_mtx[2][2] = 1.0f;
    identity_mtx[2][3] = 0.0f;
    GXLoadPosMtxImm(identity_mtx, GX_PNMTX0);
    GXLoadNrmMtxImm(identity_mtx, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXLoadTexMtxImm(identity_mtx, GX_IDENTITY, GX_MTX3x4);
    GXLoadTexMtxImm(identity_mtx, GX_PTIDENTITY, GX_MTX3x4);
    fn_80038EEC(0.0f, 0.0f, rmode->fbWidth, rmode->xfbHeight, 0.0f, 1.0f);
    GXSetProjectionv(lbl_8012AD14);
    GXSetCoPlanar(((GXBool)0));
    fn_80034890(GX_CULL_BACK);
    GXSetClipMode(GX_CLIP_ENABLE);
    GXSetScissor(0, 0, rmode->fbWidth, rmode->efbHeight);
    GXSetScissorBoxOffset(0, 0);
    fn_8003591C(0);
    fn_80035960(GX_COLOR0A0, ((GXBool)0), GX_SRC_REG, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE,
                GX_AF_NONE);
    fn_80035734(GX_COLOR0A0, black);
    fn_80035828(GX_COLOR0A0, white);
    fn_80035960(GX_COLOR1A1, ((GXBool)0), GX_SRC_REG, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE,
                GX_AF_NONE);
    fn_80035734(GX_COLOR1A1, black);
    fn_80035828(GX_COLOR1A1, white);
    GXInvalidateTexAll();
    {
        struct __GXData_struct *p = gx;
        p->nextTexRgn = 0;
        p->nextTexRgnCI = 0;
    }
    GXSetTexRegionCallback(__GXDefaultTexRegionCallback);
    GXSetTlutRegionCallback(fn_80030848);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD2, GX_TEXMAP2, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE3, GX_TEXCOORD3, GX_TEXMAP3, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE4, GX_TEXCOORD4, GX_TEXMAP4, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE5, GX_TEXCOORD5, GX_TEXMAP5, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE6, GX_TEXCOORD6, GX_TEXMAP6, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE7, GX_TEXCOORD7, GX_TEXMAP7, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE8, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE9, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE10, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE11, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE12, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE13, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE14, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE15, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetNumTevStages(1);
    GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
    GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_AND, GX_ALWAYS, 0);
    GXSetZTexture(GX_ZT_DISABLE, GX_TF_Z8, 0);
    for (i = GX_TEVSTAGE0; i < GX_MAX_TEVSTAGE; i++) {
        GXSetTevKColorSel((GXTevStageID)i, GX_TEV_KCSEL_1_4);
        GXSetTevKAlphaSel((GXTevStageID)i, GX_TEV_KASEL_1);
        GXSetTevSwapMode((GXTevStageID)i, GX_TEV_SWAP0, GX_TEV_SWAP0);
    }
    GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA);
    GXSetTevSwapModeTable(GX_TEV_SWAP1, GX_CH_RED, GX_CH_RED, GX_CH_RED, GX_CH_ALPHA);
    GXSetTevSwapModeTable(GX_TEV_SWAP2, GX_CH_GREEN, GX_CH_GREEN, GX_CH_GREEN, GX_CH_ALPHA);
    GXSetTevSwapModeTable(GX_TEV_SWAP3, GX_CH_BLUE, GX_CH_BLUE, GX_CH_BLUE, GX_CH_ALPHA);
    for (i = GX_TEVSTAGE0; i < GX_MAX_TEVSTAGE; i++)
        fn_80036EDC((GXTevStageID)i);
    GXSetNumIndStages(0);
    GXSetIndTexCoordScale(GX_INDTEXSTAGE0, GX_ITS_1, GX_ITS_1);
    GXSetIndTexCoordScale(GX_INDTEXSTAGE1, GX_ITS_1, GX_ITS_1);
    GXSetIndTexCoordScale(GX_INDTEXSTAGE2, GX_ITS_1, GX_ITS_1);
    GXSetIndTexCoordScale(GX_INDTEXSTAGE3, GX_ITS_1, GX_ITS_1);
    fn_800377F8(GX_FOG_NONE, 0.0f, 1.0f, 0.1f, 1.0f, black);
    GXSetFogRangeAdj(((GXBool)0), 0, 0);
    fn_80037B14(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    fn_80037B68(((GXBool)1));
    fn_80037B94(((GXBool)1));
    fn_80037BC0(((GXBool)1), GX_LEQUAL, ((GXBool)1));
    GXSetZCompLoc(((GXBool)1));
    fn_80037D14(((GXBool)1));
    fn_80037D40(((GXBool)0), 0);
    fn_80037C2C(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
    GXSetFieldMask(((GXBool)1), ((GXBool)1));
    GXSetFieldMode(rmode->field_rendering,
                ((rmode->viHeight == 2 * rmode->xfbHeight) ? ((GXBool)1) : ((GXBool)0)));
    GXSetDispCopySrc(0, 0, rmode->fbWidth, rmode->efbHeight);
    fn_80034B7C(rmode->fbWidth, rmode->efbHeight);
    GXSetDispCopyYScale((f32)(rmode->xfbHeight) / (f32)(rmode->efbHeight));
    fn_80034D34((GXFBClamp)(GX_CLAMP_TOP | GX_CLAMP_BOTTOM));
    fn_80034ECC(rmode->aa, rmode->sample_pattern, ((GXBool)1), rmode->vfilter);
    GXSetDispCopyGamma(GX_GM_1_0);
    GXSetDispCopyFrame2Field(GX_COPY_PROGRESSIVE);
    GXClearBoundingBox();
    GXPokeColorUpdate(((GXBool)1));
    GXPokeAlphaUpdate(((GXBool)1));
    GXPokeDither(((GXBool)0));
    GXPokeBlendMode(GX_BM_NONE, GX_BL_ZERO, GX_BL_ONE, GX_LO_SET);
    GXPokeAlphaMode(GX_ALWAYS, 0);
    GXPokeAlphaRead(GX_READ_FF);
    GXPokeDstAlpha(((GXBool)0), 0);
    GXPokeZMode(((GXBool)1), GX_ALWAYS, ((GXBool)1));
    GXSetGPMetric(0x23, 0x16);
    GXClearGPMetric();
}
