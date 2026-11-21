#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <dolphin/os/OSReset.h>
#include <dolphin/os/OSTime.h>

#pragma peephole off



typedef enum _GXCITexFmt {
    GX_TF_C4 = 0x8,
    GX_TF_C8 = 0x9,
    GX_TF_C14X2 = 0xA,
} GXCITexFmt;








GXTexFmt fn_80036104(const GXTexObj *to);


GXTexRegion *__GXDefaultTexRegionCallback(const GXTexObj *t_obj, GXTexMapID unused) {
    GXTexFmt fmt = fn_80036104(t_obj);
    if (fmt != GX_TF_C4 && fmt != GX_TF_C8 && fmt != GX_TF_C14X2) {
        return &gx->TexRegions0[gx->nextTexRgn++ & 7];
    } else {
        return &gx->TexRegions1[gx->nextTexRgnCI++ & 3];
    }
}

GXTlutRegion *fn_80030848(u32 index) {
    if (index >= 0x14) {
        return 0;
    }
    return &gx->TlutRegions[index];
}

extern volatile u16 *__cpReg; /* hardware register */
extern u32 GXResetFuncInfo[];
extern u32 GXSetCPUFifo(u32);
extern u32 PPCMfhid2(void);
extern u32 __GXFifoInit(void);
void __GXInitGX(void);
extern u32 __GXVersion;
extern u32 __memReg;
extern u32 __peReg;
extern u32 __piReg;
extern u8 gxData[];
extern void GXInitFifoBase(struct __GXFifoObj *, u32, u32);
extern void GXInitTexCacheRegion(GXTexRegion *, u8, u32, s32, u32, s32);
extern void GXInitTlutRegion(GXTlutRegion *, u32, u32);
extern void GXSetGPFifo(struct __GXFifoObj *);
extern void GXSetMisc(u32, u32);
extern void OSRegisterResetFunction(OSResetFunctionInfo *);
extern void OSRegisterVersion(const char *);
extern void PPCMthid2(u32);
extern void PPCMtwpar(u32);
extern void __GXFlushTextureState(void);
extern void __GXPEInit(void);
extern void __GXSetTmemConfig(u32);
extern vu32 __MEMRegs[];
extern vu32 __PIRegs[];
extern vu32 __CPRegs[];
#define GX_FIFO_U8 (*(volatile u8 *)0xCC008000) /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
#define GX_FIFO_U32 (*(volatile u32 *)0xCC008000) /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
extern OSTime OSGetTime(void);


extern u32 fn_80009FF4(void);
extern u32 fn_800321D8(u32);
extern u32 fn_80033EB0(void);
extern u32 fn_80034378(u32);
extern u32 fn_80034444(u32);

#pragma peephole off
#pragma opt_propagation off
s32 fn_8003086C(s32 arg0) {
    static u32 peCount;
    static OSTime time;
    static u32 calledOnce;
    u32 prev;
    u32 hi;
    u32 lo;
    volatile u16 *p50;  /* fzgx-allow: S2 memory-mapped register */
    volatile u16 *p46;  /* fzgx-allow: S2 memory-mapped register */
    OSTime now;
    u32 v;
    s64 diff;

    if (arg0 == 0) {
        if (calledOnce == 0) {
            p46 = (volatile u16 *)(__memReg + 0x4e);  /* fzgx-allow: S2 memory-mapped register */
            p50 = (volatile u16 *)(__memReg + 0x50);  /* fzgx-allow: S2 memory-mapped register */
            hi = *p46;
            do {
                prev = hi;
                hi = *p46;
                lo = *p50;
            } while (hi != prev);
            peCount = (hi << 16) | lo;
            now = OSGetTime();
            time = now;
            calledOnce = 1;
            return 0;
        }
        now = OSGetTime();
        p46 = (volatile u16 *)(__memReg + 0x4e);  /* fzgx-allow: S2 memory-mapped register */
        p50 = (volatile u16 *)(__memReg + 0x50);  /* fzgx-allow: S2 memory-mapped register */
        hi = *p46;
        do {
            prev = hi;
            hi = *p46;
            lo = *p50;
        } while (hi != prev);
        v = (hi << 16) | lo;
        if ((now - time) < 10) {
            return 0;
        }
        if (v != peCount) {
            time = now;
            peCount = v;
            return 0;
        }
    } else {
        fn_800321D8(0);
        fn_80034378(0);
        fn_80034444(0);
        GX_FIFO_U32 = 0;
        GX_FIFO_U32 = 0;
        GX_FIFO_U32 = 0;
        GX_FIFO_U32 = 0;
        GX_FIFO_U32 = 0;
        GX_FIFO_U32 = 0;
        GX_FIFO_U32 = 0;
        GX_FIFO_U32 = 0;
        fn_80009FF4();
        *(volatile u16 *)((u32)__cpReg + 2) = 0; /* hardware register */  /* fzgx-allow: S2 memory-mapped register */
        *(volatile u16 *)((u32)__cpReg + 4) = 3; /* hardware register */  /* fzgx-allow: S2 memory-mapped register */
        gx->abtWaitPECopy = 1;
        fn_80033EB0();
    }
    return 1;
}


#pragma opt_propagation reset


#pragma peephole reset
#pragma peephole off
void * GXInit(u32 arg0, u32 arg1, u32 arg2) {
    static u32 resetFuncRegistered;
    u8 *p_gxData_80177BA0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v4;
    s32 v11;
    u32 v5;
    u32 v6;
    u32 v12;
    u32 v30;
    s32 v34;
    s32 v66;
    u32 v63;
    u32 v65;
    s32 v88;
    s32 v94;
    s32 v101;
    s32 v106;
    u32 v109;
    u32 v110;
    u32 v111;
    u32 t8;
    p_gxData_80177BA0 = (u8 *)&gxData;
    OSRegisterVersion((const char *)__GXVersion);
    gx->inDispList = 0;
    gx->dlSaveContext = 1;
    gx->abtWaitPECopy = 1;
    gx->tcsManEnab = 0;
    gx->tevTcEnab = 0;
    GXSetMisc(1, 0);
    v0 = 0xCC000000; /* fzgx-allow: A1,A2 OSPhysicalToUncached(0x0C000000), as in the SDK */
    __piReg = 0xCC003000; /* fzgx-allow: A1,A2 OSPhysicalToUncached(0x0C003000) */
    __cpReg = (volatile u16 *)0xCC000000; /* fzgx-allow: A1,A2 OSPhysicalToUncached(0x0C000000) */
    __peReg = 0xCC001000; /* fzgx-allow: A1,A2 OSPhysicalToUncached(0x0C001000) */
    __memReg = 0xCC004000; /* fzgx-allow: A1,A2 OSPhysicalToUncached(0x0C004000) */
    __GXFifoInit();
    GXInitFifoBase((struct __GXFifoObj *)(p_gxData_80177BA0 + 1272), arg0, arg1);
    GXSetCPUFifo((u32)p_gxData_80177BA0 + 1272);
    GXSetGPFifo((struct __GXFifoObj *)((u32)&gxData + 1272));
    if (resetFuncRegistered == 0) {
        OSRegisterResetFunction((OSResetFunctionInfo *)&GXResetFuncInfo);
        resetFuncRegistered = 1;
    }
    __GXPEInit();
    t8 = PPCMfhid2();
    PPCMtwpar((0xC010000 + -32768));
    PPCMthid2((t8 | 0x40000000));
    gx->genMode = 0;
    v4 = ((u32)gx + 516);
    v5 = ((u32)gx + 292);
    v6 = ((u32)gx + 124);
    *(u32 *)v4 = (*(u32 *)v4 & 0xFFFFFF);
    gx->bpMask = 255;
    *(u32 *)v5 = ((*(u32 *)v5 & 0xFFFFFF) | 0xF000000);
    gx->lpSize = 0;
    *(u32 *)v6 = ((*(u32 *)v6 & 0xFFFFFF) | 0x22000000);
    for (v11 = 0; (u32)v11 < 16; v11++) {
        gx->tevc[v11] = 0;
        gx->teva[v11] = 0;
        gx->tref[(u32)v11 >> 1] = 0;
        gx->texmapId[v11] = 255;
        gx->tevc[v11] = (gx->tevc[v11] & 0xFFFFFF) | ((0xC0 + v11 * 2) << 24);
        gx->teva[v11] = (gx->teva[v11] & 0xFFFFFF) | ((0xC1 + v11 * 2) << 24);
        gx->tevKsel[(u32)v11 >> 1] = (gx->tevKsel[(u32)v11 >> 1] & 0xFFFFFF) | ((((u32)v11 >> 1) + 0xF6) << 24);
        gx->tref[(u32)v11 >> 1] = (gx->tref[(u32)v11 >> 1] & 0xFFFFFF) | ((((u32)v11 >> 1) + 0x28) << 24);
    }
    gx->iref = 0;
    v30 = ((u32)gx + 288);
    *(u32 *)v30 = ((*(u32 *)v30 & 0xFFFFFF) | 0x27000000);
    for (v34 = 0; (u32)v34 < 8; v34++) {
        gx->suTs0[v34] = 0;
        gx->suTs1[v34] = 0;
        gx->suTs0[v34] = (gx->suTs0[v34] & 0xFFFFFF) | ((0x30 + v34 * 2) << 24);
        gx->suTs1[v34] = (gx->suTs1[v34] & 0xFFFFFF) | ((0x31 + v34 * 2) << 24);
    }
    gx->suScis0 = (gx->suScis0 & 0xFFFFFF) | 0x20000000;
    gx->suScis1 = (gx->suScis1 & 0xFFFFFF) | 0x21000000;
    gx->cmode0 = (gx->cmode0 & 0xFFFFFF) | 0x41000000;
    gx->cmode1 = (gx->cmode1 & 0xFFFFFF) | 0x42000000;
    gx->zmode = (gx->zmode & 0xFFFFFF) | 0x40000000;
    gx->peCtrl = (gx->peCtrl & 0xFFFFFF) | 0x43000000;
    v63 = (u32)gx + 508;
    *(u32 *)v63 = *(u32 *)v63 & 0xFFFFFE7F;
    gx->dirtyState = 0;
    gx->dirtyVAT = 0;
    v65 = *(u32 *)0x800000F8 / 500; /* fzgx-allow: A1,A2 __OSBusClock lowmem global */
    __GXFlushTextureState();
    GX_FIFO_U8 = 97;
    GX_FIFO_U32 = (v65 >> 11) | 0x69000400;
    __GXFlushTextureState();
    GX_FIFO_U8 = 97;
    GX_FIFO_U32 = (v65 / 4224) | 0x46000200;
    for (v11 = 0; (u32)v11 < 8; v11++) {
        gx->vatA[v11] = (gx->vatA[v11] & 0xBFFFFFFF) | 0x40000000;
        gx->vatB[v11] = (gx->vatB[v11] & 0x7FFFFFFF) | 0x80000000;
        GX_FIFO_U8 = 8;
        GX_FIFO_U8 = v11 | 0x80;
        GX_FIFO_U32 = gx->vatB[v11];
    }
    GX_FIFO_U8 = 16;
    GX_FIFO_U32 = 4096;
    GX_FIFO_U32 = 63;
    GX_FIFO_U8 = 16;
    GX_FIFO_U32 = 4114;
    GX_FIFO_U32 = 1;
    GX_FIFO_U8 = 97;
    GX_FIFO_U32 = 0x5800000F;
    for (v88 = 0; (u32)v88 < 8; v88++) {
        GXInitTexCacheRegion(&gx->TexRegions0[v88], 0, v88 << 15, 0, (v88 << 15) + 0x80000, 0);
    }
    for (v94 = 0; (u32)v94 < 4; v94++) {
        GXInitTexCacheRegion(&gx->TexRegions1[v94], 0, (v94 * 2 + 8) << 15, 0, (v94 * 2 + 9) << 15, 0);
    }
    for (v101 = 0; (u32)v101 < 16; v101++) {
        GXInitTlutRegion(&gx->TlutRegions[v101], (v101 << 13) + 0xC0000, 16);
    }
    for (v106 = 0; (u32)v106 < 4; v106++) {
        GXInitTlutRegion(&gx->TlutRegions[v106 + 16], (v106 << 15) + 0xE0000, 64);
    }
    __cpReg[3] = 0;
    v110 = (u32)gx + 1260;
    *(u32 *)v110 = *(u32 *)v110 & 0xFFFFFF0F;
    GX_FIFO_U8 = 8;
    GX_FIFO_U8 = 32;
    GX_FIFO_U32 = gx->perfSel;
    GX_FIFO_U8 = 16;
    GX_FIFO_U32 = 4102;
    GX_FIFO_U32 = 0;
    GX_FIFO_U8 = 97;
    GX_FIFO_U32 = 0x23000000;
    GX_FIFO_U8 = 97;
    GX_FIFO_U32 = 0x24000000;
    GX_FIFO_U8 = 97;
    GX_FIFO_U32 = 0x67000000;
    __GXSetTmemConfig(0);
    __GXInitGX();
    return ((u8 *)(u32)p_gxData_80177BA0 + 1272);
}
#pragma peephole reset
#pragma peephole off




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








typedef enum _GXTexMtxType {
    GX_MTX3x4,
    GX_MTX2x4,
} GXTexMtxType;


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


typedef enum _GXCullMode { GX_CULL_NONE, GX_CULL_FRONT, GX_CULL_BACK, GX_CULL_ALL } GXCullMode;












typedef enum _GXFBClamp {
    GX_CLAMP_NONE = 0,
    GX_CLAMP_TOP = 1,
    GX_CLAMP_BOTTOM = 2,
} GXFBClamp;


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











typedef struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;
    OSMutexLink link;
} OSMutex;

struct OSContext;


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
        GXData *p = gx;
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
