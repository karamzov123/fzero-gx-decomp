#include <types.h>
#include "types.h"
#include "sdk_addresses.h"


/* --- dol/GXInitTexObjLOD.c --- */
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

extern u8 lbl_801A6570[6];

void GXInitTexObjLOD(GXTexObj *obj, GXTexFilter minFilter, GXTexFilter maxFilter, f32 minLOD,
                 f32 maxLOD, f32 lodBias, GXBool doBiasClamp, GXBool doEdgeLOD,
                 GXAnisotropy maxAniso) {
    GXTexObj *internal = (GXTexObj *)obj;
    u8 reg1, reg2;
    if (lodBias < -4.0f) {
        lodBias = -4.0f;
    } else if (lodBias >= 4.0f) {
        lodBias = 3.99f;
    }
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((22 - 15 + 1))) - 1) << (31 - (15) - ((22 - 15 + 1)) + 1))) |
        ((int)((u8)(lodBias * 32.0f)) << (31 - (15) - ((22 - 15 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((27 - 27 + 1))) - 1) << (31 - (27) - ((27 - 27 + 1)) + 1))) |
        ((int)(maxFilter == 1 ? 1 : 0) << (31 - (27) - ((27 - 27 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((26 - 24 + 1))) - 1) << (31 - (24) - ((26 - 24 + 1)) + 1))) |
        ((int)(lbl_801A6570[minFilter]) << (31 - (24) - ((26 - 24 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((23 - 23 + 1))) - 1) << (31 - (23) - ((23 - 23 + 1)) + 1))) |
        ((int)(doEdgeLOD ? 0 : 1) << (31 - (23) - ((23 - 23 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((14 - 14 + 1))) - 1) << (31 - (14) - ((14 - 14 + 1)) + 1))) |
        ((int)(0) << (31 - (14) - ((14 - 14 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((13 - 13 + 1))) - 1) << (31 - (13) - ((13 - 13 + 1)) + 1))) |
        ((int)(0) << (31 - (13) - ((13 - 13 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((12 - 11 + 1))) - 1) << (31 - (11) - ((12 - 11 + 1)) + 1))) |
        ((int)(maxAniso) << (31 - (11) - ((12 - 11 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((10 - 10 + 1))) - 1) << (31 - (10) - ((10 - 10 + 1)) + 1))) |
        ((int)(doBiasClamp) << (31 - (10) - ((10 - 10 + 1)) + 1));
    if (minLOD < 0.0f) {
        minLOD = 0.0f;
    } else if (minLOD > 10.0f) {
        minLOD = 10.0f;
    }
    reg1 = minLOD * 16.0f;
    if (maxLOD < 0.0f) {
        maxLOD = 0.0f;
    } else if (maxLOD > 10.0f) {
        maxLOD = 10.0f;
    }
    reg2 = maxLOD * 16.0f;
    (internal->texture_lod) = (internal->texture_lod & ~(((1 << ((31 - 24 + 1))) - 1)
                                                         << (31 - (24) - ((31 - 24 + 1)) + 1))) |
                              ((int)(reg1) << (31 - (24) - ((31 - 24 + 1)) + 1));
    (internal->texture_lod) = (internal->texture_lod & ~(((1 << ((23 - 16 + 1))) - 1)
                                                         << (31 - (16) - ((23 - 16 + 1)) + 1))) |
                              ((int)(reg2) << (31 - (16) - ((23 - 16 + 1)) + 1));
}

/* --- dol/fn_80036058.c --- */
struct fn_80036058_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

void fn_80036058(struct fn_80036058_Arg0 *arg0, u32 arg1) {
    arg0->unk_C = ((arg0->unk_C & ~0x1FFFFF) | ((arg1 >> 5) & 0x1FFFFFF));
}

/* --- dol/fn_80036070.c --- */
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

void fn_80036070(const Fn80036070Data *data, u32 *out_scaled, u16 *out_width, u16 *out_height,
                 u32 *out_value, u32 *out_flags_low, u32 *out_flags_high, u8 *out_enabled) {
    *out_scaled = (data->scaled_value & 0x001FFFFFu) << 5;
    *out_width = (u16)((data->dimensions & 0x3FFu) + 1);
    *out_height = (u16)(((data->dimensions >> 10) & 0x3FFu) + 1);
    *out_value = data->value_14;
    *out_flags_low = data->flags & 3u;
    *out_flags_high = (data->flags >> 2) & 3u;
    *out_enabled = (u8)(!((data->enabled & 1u) - 1u));
}

/* --- dol/fn_800360D8.c --- */
/* --- dol/fn_800360D8.c --- */
struct fn_800360D8_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

u32 fn_800360D8(struct fn_800360D8_Arg0 *arg0) {
    return ((arg0->unk_C & 0x1FFFFF) << 5);
}

/* --- dol/GXGetTexObjWidth.c --- */
struct GXGetTexObjWidth_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

u32 GXGetTexObjWidth(struct GXGetTexObjWidth_Arg0 *arg0) {
    return ((arg0->unk_8 & 0x3FF) + 1);
}

/* --- dol/GXGetTexObjHeight.c --- */
struct GXGetTexObjHeight_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

u32 GXGetTexObjHeight(struct GXGetTexObjHeight_Arg0 *arg0) {
    return (((arg0->unk_8 >> 10) & 0x3FF) + 1);
}

/* --- dol/fn_80036104.c --- */
struct fn_80036104_Arg0 {
    u8 pad_0[0x14];
    u32 unk_14;
};

u32 fn_80036104(struct fn_80036104_Arg0 *arg0) {
    return arg0->unk_14;
}

/* --- dol/fn_8003610C.c --- */
typedef struct Fn8003610CData {
    u32 flags;
    u32 packed;
} Fn8003610CData;

extern u8 lbl_801A6578[8];
extern const f64 lbl_801A70C0;
extern const f32 lbl_801A70E0;
extern const f64 lbl_801A70E8;
extern const f32 lbl_801A70E4;

void fn_8003610C(const Fn8003610CData *data, u32 *out_table, u32 *out_bit,
                 f32 *out_low, f32 *out_high, f32 *out_signed,
                 u8 *out_flag, u8 *out_inverse, u32 *out_bits) {
    int sign;
    *out_table = lbl_801A6578[(data->flags >> 5) & 7u];
    *out_bit = (data->flags >> 4) & 1u;
    *out_low = (f32)(data->packed & 0xffu) * lbl_801A70E0;
    *out_high = (f32)((data->packed >> 8) & 0xffu) * lbl_801A70E0;
    sign = (data->flags >> 9) & 0xff;
    *out_signed = (f32)(s8)(s16)sign * lbl_801A70E4;
    *out_flag = (u8)((data->flags >> 21) & 1u);
    *out_inverse = (u8)!((data->flags >> 8) & 1u);
    *out_bits = (data->flags >> 19) & 3u;
}

/* --- dol/fn_800361F0.c --- */
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

void fn_800361F0(GXTexObj *obj, GXTexRegion *region, GXTexMapID map);

extern GXData *const gx;

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe GXFIFO : FZGX_ADDR_GXFIFO;

extern u8 lbl_801A6538[8];

extern u8 lbl_801A6540[8];

extern u8 lbl_801A6548[8];

extern u8 lbl_801A6550[8];

extern u8 lbl_801A6558[8];

extern u8 lbl_801A6560[8];

extern u8 lbl_801A6568[8];

void fn_800361F0(GXTexObj *obj, GXTexRegion *region, GXTexMapID map) {
    GXTexObj *internalObj = (GXTexObj *)obj;
    GXTexRegion *internalRegion = (GXTexRegion *)region;
    (internalObj->texture_filter) =
        (internalObj->texture_filter &
         ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
        ((int)(lbl_801A6538[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
    (internalObj->texture_lod) = (internalObj->texture_lod &
                                  ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
                                 ((int)(lbl_801A6540[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
    (internalObj->texture_size) =
        (internalObj->texture_size &
         ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
        ((int)(lbl_801A6548[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
    (internalRegion->unk0) =
        (internalRegion->unk0 & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
        ((int)(lbl_801A6550[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
    (internalRegion->unk4) =
        (internalRegion->unk4 & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
        ((int)(lbl_801A6558[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
    (internalObj->texture_address) =
        (internalObj->texture_address &
         ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
        ((int)(lbl_801A6560[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (internalObj->texture_filter);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (internalObj->texture_lod);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (internalObj->texture_size);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (internalRegion->unk0);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (internalRegion->unk4);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (internalObj->texture_address);
    ;
    if ((internalObj->texture_flags & 2) == 0) {
        GXTlutObj *tlut = (GXTlutObj *)gx->tlutRegionCallback(internalObj->tlut_name);
        (tlut->address) =
            (tlut->address & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((int)(lbl_801A6568[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (tlut->address);
        ;
    }
    gx->tImage0[map] = internalObj->texture_size;
    gx->tMode0[map] = internalObj->texture_filter;
    gx->dirtyState |= GX_DIRTY_SU_TEX;
    gx->bpSentNot = ((GXBool)0);
}
