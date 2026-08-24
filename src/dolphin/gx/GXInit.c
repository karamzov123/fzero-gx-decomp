typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int BOOL;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;

#define NULL ((void *)0)
#define FALSE 0
#define TRUE 1

#define OSPhysicalToUncached(p) ((u32)(p) | 0xCC000000)
#define GET_REG_FIELD(reg, size, pos) (((reg) >> (pos)) & ((1 << (size)) - 1))
#define SET_REG_FIELD(line, reg, size, pos, val) \
    ((reg) = (((u32)(reg)) & ~((((1 << (size)) - 1)) << (pos))) | ((u32)(val) << (pos)))

typedef struct GXTexObj GXTexObj;

typedef struct OSContext {
    u32 gpr[32];      /* 0x000 */
    u32 cr;           /* 0x080 */
    u32 lr;           /* 0x084 */
    u32 ctr;          /* 0x088 */
    u32 xer;          /* 0x08C */
    f64 fpr[32];      /* 0x090 */
    u32 fpscr_pad;    /* 0x190 */
    u32 fpscr;        /* 0x194 */
    u32 srr0;         /* 0x198 */
    u32 srr1;         /* 0x19C */
    u16 mode;         /* 0x1A0 */
    u16 state;        /* 0x1A2 */
    u32 gqr[8];       /* 0x1A4 */
    f64 psf[32];      /* 0x1C4 */
} OSContext;
typedef struct GXTlutRegion { u32 _[4]; } GXTlutRegion;
typedef struct GXTexRegion { u32 _[4]; } GXTexRegion;
typedef void GXFifoObj;

typedef struct GXRenderModeObj {
    u32 viTVMode;        /* 0x00 */
    u16 fbWidth;         /* 0x04 */
    u16 efbHeight;       /* 0x06 */
    u16 xfbHeight;       /* 0x08 */
    u16 viXOrigin;       /* 0x0A */
    u16 viYOrigin;       /* 0x0C */
    u16 viWidth;         /* 0x0E */
    u16 viHeight;        /* 0x10 */
    u32 xFBmode;         /* 0x14 */
    u8 field_rendering;  /* 0x18 */
    u8 aa;               /* 0x19 */
    u8 sample_pattern[24];
    u8 vfilter[7];       /* 0x32 */
} GXRenderModeObj;

typedef struct GXColor { u8 r, g, b, a; } GXColor;

typedef volatile union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 s32;
    f32 f32;
} PPCWGPipe;

#define GXWGFifo (*(volatile PPCWGPipe *)OSPhysicalToUncached(0x008000))
#define OS_BUS_CLOCK (*(volatile u32 *)0x800000F8)

#define GX_WRITE_RAS_REG(value)      \
    do {                             \
        GXWGFifo.u8 = 0x61;          \
        GXWGFifo.s32 = (u32)(value); \
    } while (0)

#define GX_WRITE_XF_REG(addr, value)         \
    do {                                     \
        GXWGFifo.u8 = 0x10;                  \
        GXWGFifo.s32 = 0x1000 + (addr);      \
        GXWGFifo.s32 = (u32)(value);         \
    } while (0)

typedef struct GXData {
    u8 pad00[8];                   /* 0x000 */
    u32 cpEnable;                  /* 0x008 */
    u32 cpStatus;                  /* 0x00C */
    u8 pad10[0x0C];                /* 0x010 */
    u32 vatA[8];                   /* 0x01C */
    u32 vatB[8];                   /* 0x03C */
    u8 pad05C[0x20];               /* 0x05C */
    u32 lpSize;                    /* 0x07C */
    u8 pad080[0x38];               /* 0x080 */
    u32 suTs0[8];                  /* 0x0B8 */
    u32 suTs1[8];                  /* 0x0D8 */
    u32 suScis0;                   /* 0x0F8 */
    u32 suScis1;                   /* 0x0FC */
    u32 tref[8];                   /* 0x100 */
    u32 iref;                      /* 0x120 */
    u32 bpMask;                    /* 0x124 */
    u8 pad128[0x08];               /* 0x128 */
    u32 tevc[16];                  /* 0x130 */
    u32 teva[16];                  /* 0x170 */
    u32 tevKsel[8];                /* 0x1B0 */
    u32 cmode0;                    /* 0x1D0 */
    u32 cmode1;                    /* 0x1D4 */
    u32 zmode;                     /* 0x1D8 */
    u32 peCtrl;                    /* 0x1DC */
    u8 pad1E0[0x1C];               /* 0x1E0 */
    u32 cpTex;                     /* 0x1FC */
    u8 pad200[0x04];               /* 0x200 */
    u32 genMode;                   /* 0x204 */
    GXTexRegion TexRegions[8];     /* 0x208 */
    GXTexRegion TexRegionsCI[4];   /* 0x288 */
    u32 nextTexRgn;                /* 0x2C8 */
    u32 nextTexRgnCI;              /* 0x2CC */
    GXTlutRegion TlutRegions[20];  /* 0x2D0 */
    u8 pad410[0x18C];              /* 0x410 */
    u32 texmapId[16];              /* 0x49C */
    u32 tcsManEnab;                /* 0x4DC */
    u32 unk4e0;                    /* 0x4E0 */
    u8 pad4E4[0x08];               /* 0x4E4 */
    u32 perfSel;                   /* 0x4EC */
    u8 inDispList;                 /* 0x4F0 */
    u8 dlSaveContext;              /* 0x4F1 */
    u8 unk4f2;                     /* 0x4F2 */
    u8 dirtyVAT;                   /* 0x4F3 */
    u32 dirtyState;                /* 0x4F4 */
} GXData;

extern GXData *const gx;
extern u8 gxData[];
extern u16 *__memReg;
extern u16 *__peReg;
extern u16 *__cpReg;
extern u32 *__piReg;
extern void *__GXCurrentThread;
extern BOOL GXOverflowSuspendInProgress;
typedef void (*GXBreakPtCallback)();
extern GXBreakPtCallback BreakPointCB;
extern u32 lbl_801A6C08;
extern u32 lbl_801A6BD8;
extern u32 lbl_801A6BE0;
extern u32 lbl_801A6BE4;
extern u32 lbl_801A6BE8;
extern char *__GXVersion;
extern const GXRenderModeObj lbl_8012AFB8;
extern const GXRenderModeObj lbl_8012B06C;
extern const GXRenderModeObj lbl_8012B0A8;
extern const GXRenderModeObj lbl_8012B0E4;
extern const u32 lbl_8012AC44[];
extern const u32 lbl_8012AD14[];
extern const f32 lbl_801A7068;
extern const f32 lbl_801A706C;
extern const f32 lbl_801A7070;
extern const f64 lbl_801A7078;
extern const GXColor lbl_801A705C;
extern const GXColor lbl_801A7060;
extern const GXColor lbl_801A7064;
extern u32 gxResetRegistered;
extern u8 GXResetFuncInfo[16];

extern void OSRegisterVersion(char *version);
extern void OSRegisterResetFunction(void *info);
extern void GXSetMisc(s32 token, u32 data);
extern void __GXFifoInit(void);
extern void GXInitFifoBase(GXFifoObj *fifo, void *base, u32 size);
extern void GXSetCPUFifo(GXFifoObj *fifo);
extern void GXSetGPFifo(GXFifoObj *fifo);
extern void __GXPEInit(void);
extern void PPCMtwpar(void *addr);
extern u32 PPCMfhid2(void);
extern void PPCMthid2(u32 value);
extern void PPCSync(void);
extern void __GXFlushTextureState(void);
extern void GXInitTexCacheRegion(GXTexRegion *region, u32 tmemEven, u32 mapEven,
                                 u32 tmemOdd, u32 mapOdd, u32 flags);
extern void GXInitTlutRegion(GXTlutRegion *region, u32 tmemAddr, u32 count);
extern void __GXSetTmemConfig(u32 sel);
extern s32 VIGetTvFormat(void);
extern s64 OSGetTime(void);
extern void OSClearContext(OSContext *context);
extern void OSSetCurrentContext(OSContext *context);
extern void fn_80033EB0(void);
extern void fn_80034378(s32 arg);
extern void fn_80034444(s32 arg);
extern void fn_80010CB0(void *thread);
extern void fn_80010F38(void *thread);
extern void __GXWriteFifoIntEnable(u8 hiWatermarkEn, u8 loWatermarkEn);
extern void __GXWriteFifoIntReset(u8 hiWatermarkClr, u8 loWatermarkClr);
extern s32 fn_80036104(GXTexObj *obj);

/* called from later GX units */
extern void __GXSetBlendModePair(void *color, u32 zvalue);
extern void GXSetTexCoordGen2(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void GXSetNumTexGens(s32 num);
extern void GXClearVtxDesc(void);
extern void fn_80033A6C(void);
extern void fn_800339E0(s32 idx, void *arg, s32 val);
extern void fn_800332D8(s32 idx, const void *tbl);
extern void GXSetLineWidth(s32 width, s32 shift);
extern void GXSetPointSize(s32 size, s32 shift);
extern void __GXSetTexCoordGen_Cache(s32 coord, s32 en1, s32 en2);
extern void fn_80038C5C(void *mtx, s32 id);
extern void fn_80038CAC(void *mtx, s32 id);
extern void fn_80038CFC(s32 id);
extern void GXWritePrimitiveFifo(void *mtx, s32 id, s32 type);
extern void fn_80038EEC(f32 x, f32 y, f32 wd, f32 ht, f32 nearz, f32 farz);
extern void fn_80038B3C(const void *data);
extern void __GXSetZMode_Cache(s32 arg);
extern void GXSetCullMode(s32 arg);
extern void fn_80039060(s32 arg);
extern void fn_80038F48(s32 l, s32 t, s32 r, s32 b);
extern void fn_80039020(s32 ofs_x, s32 ofs_y);
extern void __GXSetChanAmbColor(s32 num);
extern void fn_80035960(s32 chan, s32 en, s32 amb, s32 mat, s32 lights, s32 df, s32 af);
extern void GXSetChanAmbColor(s32 chan, void *color);
extern void GXSetChanMatColor(s32 chan, void *color);
extern void fn_80036544(void);
extern void GXSetChanCtrl(s32 stage, s32 coord, s32 map, s32 color);
extern void fn_800377C8(s32 stages);
extern void fn_80037014(s32 stage, s32 op);
extern void fn_80037518(s32 comp0, s32 ref0, s32 op, s32 comp1, s32 ref1);
extern void fn_8003756C(s32 type, s32 fmt, u32 bias);
extern void fn_80037354(s32 stage, s32 sel);
extern void fn_800373C0(s32 stage, s32 sel);
extern void fn_8003742C(s32 stage, s32 swap0, s32 swap1);
extern void fn_80037480(s32 table, s32 r, s32 g, s32 b);
extern void fn_80036EDC(s32 stage);
extern void fn_80036EB4(s32 stages);
extern void fn_80036C24(s32 stage, s32 scale0, s32 scale1);
extern void fn_800377F8(s32 type, f32 start, f32 end, f32 nearz, f32 farz, void *color);
extern void fn_80037A14(s32 enable, u16 center, u16 edge);
extern void fn_80037B14(s32 mode, s32 src, s32 dst, s32 op);
extern void fn_80037B68(BOOL update);
extern void fn_80037B94(BOOL update);
extern void fn_80037BC0(BOOL compare, s32 op, BOOL update);
extern void fn_80037BF4(BOOL before);
extern void fn_80037D14(BOOL dither);
extern void fn_80037D40(BOOL enable, u8 alpha);
extern void fn_80037C2C(s32 pixFmt, s32 zFmt);
extern void fn_80037D7C(BOOL odd, BOOL even);
extern void fn_80037DB4(BOOL fieldMode, BOOL halfAspect);
extern void __GXSetScissor_LT(s32 left, s32 top, s32 wd, s32 ht);
extern void __GXSetScissorBoxOffset(s32 wd, s32 ht);
extern void fn_80034D9C(f32 yscale);
extern void fn_80034D34(s32 gamma);
extern void GXSetCopyClear(u8 aa, const u8 *sample, BOOL enable, const u8 *vfilt);
extern void fn_800350F4(s32 flag);
extern void fn_80034D0C(s32 flag);
extern void fn_800353E8(void);
extern void fn_800342B8(s32 flag);
extern void fn_80034214(s32 flag);
extern void fn_800342E8(s32 flag);
extern void fn_80034230(s32 metric, s32 clear, s32 arg2, s32 arg3);
extern void fn_800341EC(s32 metric);
extern void fn_80034200(s32 metric);
extern void fn_800342D4(s32 arg);
extern void fn_80034304(s32 arg, s32 val0, s32 val1);
extern void fn_8003910C(s32 a, s32 b);
extern void fn_80039AFC(void);
extern void fn_800307CC(void);
extern void fn_80030848(void);
extern void fn_800307CC(void);
extern void fn_80030848(void);

#pragma push
#pragma force_active on

static void __GXInitGX(void);

asm static GXTexRegion *__GXDefaultTexRegionCallback(GXTexObj *obj, s32 unused)
{
    nofralloc
    mflr r0
    stw r0, 0x4(r1)
    stwu r1, -0x8(r1)
    bl fn_80036104
    cmpwi r3, 8
    beq Lci
    cmpwi r3, 9
    beq Lci
    cmpwi r3, 0xa
    beq Lci
    lwz r5, -0x7DE8(r2) /* gx@sda21 */
    lwz r3, 0x2c8(r5)
    clrlwi r0, r3, 29
    addi r4, r3, 1
    slwi r3, r0, 4
    stw r4, 0x2c8(r5)
    addi r3, r3, 0x208
    add r3, r5, r3
    b Ldone
Lci:
    lwz r5, -0x7DE8(r2) /* gx@sda21 */
    lwz r3, 0x2cc(r5)
    clrlwi r0, r3, 30
    addi r4, r3, 1
    slwi r3, r0, 4
    stw r4, 0x2cc(r5)
    addi r3, r3, 0x288
    add r3, r5, r3
Ldone:
    lwz r0, 0xc(r1)
    addi r1, r1, 0x8
    mtlr r0
    blr
}

asm static GXTlutRegion *__GXDefaultTlutRegionCallback(u32 idx)
{
    nofralloc
    cmplwi r3, 0x14
    blt Lcalc
    li r3, 0
    b Ldone
Lcalc:
    slwi r3, r3, 4
    lwz r0, -0x7DE8(r2) /* gx@sda21 */
    addi r3, r3, 0x2d0
    add r3, r0, r3
Ldone:
    blr
}

asm static BOOL GXResetFunc(BOOL final)
{
    nofralloc
    mflr r0
    stw r0, 0x4(r1)
    stwu r1, -0x20(r1)
    stw r31, 0x1c(r1)
    cmpwi r3, 0
    bne Lforce
    lwz r0, -0x77D8(r13) /* lbl_801A6BE8@sda21 */
    cmplwi r0, 0
    bne Lsecond
    lwz r3, -0x77EC(r13) /* __memReg@sda21 */
    addi r6, r3, 0x4e
    lhz r4, 0(r6)
    addi r5, r3, 0x50
Lp10:
    b Lp11
Lp11:
    b Lp12
Lp12:
    mr r0, r4
    lhz r4, 0(r6)
    lhz r3, 0(r5)
    cmplw r4, r0
    bne Lp12
    slwi r0, r4, 16
    or r0, r0, r3
    stw r0, -0x77E8(r13) /* lbl_801A6BD8@sda21 */
    bl OSGetTime
    stw r4, -0x77DC(r13) /* lbl_801A6BE4@sda21 */
    li r0, 1
    stw r3, -0x77E0(r13) /* lbl_801A6BE0@sda21 */
    li r3, 0
    stw r0, -0x77D8(r13) /* lbl_801A6BE8@sda21 */
    b Lexit
Lsecond:
    bl OSGetTime
    lwz r5, -0x77EC(r13) /* __memReg */
    addi r6, r5, 0x4e
    lhz r7, 0(r6)
    addi r5, r5, 0x50
Lp20:
    b Lp21
Lp21:
    b Lp22
Lp22:
    mr r0, r7
    lhz r7, 0(r6)
    lhz r10, 0(r5)
    cmplw r7, r0
    bne Lp22
    lwz r6, -0x77DC(r13) /* lbl_801A6BE4 */
    li r0, 0
    lwz r5, -0x77E0(r13) /* lbl_801A6BE0 */
    slwi r9, r7, 16
    subfc r8, r6, r4
    subfe r5, r5, r3
    li r7, 0xa
    xoris r6, r5, 0x8000
    xoris r5, r0, 0x8000
    subfc r0, r7, r8
    subfe r5, r5, r6
    subfe r5, r6, r6
    neg r5, r5
    cmpwi r5, 0
    or r5, r9, r10
    beq Lcheck
    li r3, 0
    b Lexit
Lcheck:
    lwz r0, -0x77E8(r13) /* lbl_801A6BD8 */
    cmplw r5, r0
    beq Ltrue
    stw r4, -0x77DC(r13) /* lbl_801A6BE4 */
    stw r3, -0x77E0(r13) /* lbl_801A6BE0 */
    li r3, 0
    stw r5, -0x77E8(r13) /* lbl_801A6BD8 */
    b Lexit
Lforce:
    li r3, 0
    bl GXSetBreakPtCallback
    li r3, 0
    bl fn_80034378
    li r3, 0
    bl fn_80034444
    li r31, 0
    lis r3, 0xcc01
    stw r31, -0x8000(r3)
    stw r31, -0x8000(r3)
    stw r31, -0x8000(r3)
    stw r31, -0x8000(r3)
    stw r31, -0x8000(r3)
    stw r31, -0x8000(r3)
    stw r31, -0x8000(r3)
    stw r31, -0x8000(r3)
    bl PPCSync
    lwz r3, -0x77F4(r13) /* __cpReg@sda21 */
    li r4, 3
    li r0, 1
    sth r31, 2(r3)
    lwz r3, -0x77F4(r13) /* __cpReg */
    sth r4, 4(r3)
    lwz r3, -0x7DE8(r2) /* gx@sda21 */
    stb r0, 0x4f2(r3)
    bl fn_80033EB0
Ltrue:
    li r3, 1
Lexit:
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    addi r1, r1, 0x20
    mtlr r0
    blr
}

#pragma pop

/* ==== carved from coarse/text_800309FC.c (pm4-gxtail) ====
 * GXInit + __GXInitGX (melee GXInit.c identity)
 * fn_80031B50 = __GXCPInterruptHandler (retail GXInit.c tail;
 *   melee GXFifo.c GXCPInterruptHandler; kept global: GXFifo.c refs it) */
#pragma push
#pragma force_active on

asm void *GXInit(void *base, u32 size)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x50(r1)
    stmw	r25, 0x34(r1)
    mr	r27, r3
    mr	r25, r4
    lis     r4, gxData@ha
    lwz	r3, -0x7ea0(r13)
    addi	r30, r4, gxData@l
    bl OSRegisterVersion
    lwz	r5, -0x7de8(r2)
    li	r0, 0
    li	r26, 1
    stb	r0, 0x4f0(r5)
    li	r3, 1
    li	r4, 0
    stb	r26, 0x4f1(r5)
    stb	r26, 0x4f2(r5)
    stw	r0, 0x4dc(r5)
    stw	r0, 0x4e0(r5)
    bl GXSetMisc
    lis	r4, -0x3400
    addi	r5, r4, 0x3000
    stw	r4, -0x77f4(r13)
    addi	r3, r4, 0x1000
    addi	r0, r4, 0x4000
    stw	r5, -0x77f8(r13)
    stw	r3, -0x77f0(r13)
    stw	r0, -0x77ec(r13)
    bl __GXFifoInit
    mr	r4, r27
    mr	r5, r25
    addi	r3, r30, 0x4f8
    bl GXInitFifoBase
    addi	r3, r30, 0x4f8
    bl GXSetCPUFifo
    addi	r3, r30, 0x4f8
    bl GXSetGPFifo
    lwz	r0, -0x77d4(r13)
    cmplwi	r0, 0
    bne L80030ab0
    lis     r3, GXResetFuncInfo@ha
    addi	r3, r3, GXResetFuncInfo@l
    bl OSRegisterResetFunction
    stw	r26, -0x77d4(r13)
L80030ab0:
    bl __GXPEInit
    bl PPCMtwpar
    lis	r4, 0xc01
    mr	r26, r3
    addi	r3, r4, -0x8000
    bl PPCMfhid2
    oris	r3, r26, 0x4000
    bl PPCMthid2
    lwz	r7, -0x7de8(r2)
    li	r4, 0
    li	r0, 0xff
    stw	r4, 0x204(r7)
    addi	r5, r7, 0x204
    addi	r8, r7, 0x124
    lwz	r3, 0(r5)
    addi	r10, r7, 0x7c
    li	r9, 0
    clrlwi	r3, r3, 8
    stw	r3, 0(r5)
    li	r5, 0xc0
    li	r6, 0xc1
    stw	r0, 0x124(r7)
    lwz	r0, 0(r8)
    clrlwi	r0, r0, 8
    oris	r0, r0, 0xf00
    stw	r0, 0(r8)
    stw	r4, 0x7c(r7)
    lwz	r0, 0(r10)
    clrlwi	r0, r0, 8
    oris	r0, r0, 0x2200
    stw	r0, 0(r10)
    b L80030b30
L80030b30:
    li	r0, 8
    mtctr	r0
    b L80030b3c
L80030b3c:
    b L80030b40
L80030b40:
    lwz	r3, -0x7de8(r2)
    srwi	r7, r9, 1
    addi	r29, r4, 0x130
    li	r0, 0
    addi	r26, r4, 0x170
    stwx	r0, r3, r29
    slwi	r11, r7, 2
    addi	r27, r11, 0x100
    stwx	r0, r3, r26
    addi	r10, r4, 0x49c
    stwx	r0, r3, r27
    li	r31, 0xff
    slwi	r28, r5, 0x18
    stwx	r31, r3, r10
    add	r25, r3, r29
    addi	r4, r4, 4
    lwz	r29, 0(r25)
    add	r26, r3, r26
    slwi	r12, r6, 0x18
    clrlwi	r29, r29, 8
    or	r28, r29, r28
    stw	r28, 0(r25)
    addi	r8, r11, 0x1b0
    addi	r11, r7, 0xf6
    lwz	r28, 0(r26)
    addi	r10, r7, 0x28
    addi	r29, r4, 0x130
    clrlwi	r7, r28, 8
    or	r7, r7, r12
    stw	r7, 0(r26)
    add	r8, r3, r8
    addi	r9, r9, 1
    lwz	r12, 0(r8)
    srwi	r7, r9, 1
    slwi	r11, r11, 0x18
    clrlwi	r12, r12, 8
    or	r11, r12, r11
    stw	r11, 0(r8)
    add	r25, r3, r27
    slwi	r11, r7, 2
    lwz	r8, 0(r25)
    slwi	r10, r10, 0x18
    addi	r26, r4, 0x170
    clrlwi	r8, r8, 8
    or	r8, r8, r10
    stw	r8, 0(r25)
    addi	r27, r11, 0x100
    addi	r10, r4, 0x49c
    stwx	r0, r3, r29
    addi	r5, r5, 2
    slwi	r28, r5, 0x18
    stwx	r0, r3, r26
    addi	r6, r6, 2
    slwi	r12, r6, 0x18
    stwx	r0, r3, r27
    addi	r8, r11, 0x1b0
    addi	r11, r7, 0xf6
    stwx	r31, r3, r10
    add	r25, r3, r29
    addi	r10, r7, 0x28
    lwz	r29, 0(r25)
    add	r26, r3, r26
    add	r8, r3, r8
    clrlwi	r29, r29, 8
    or	r28, r29, r28
    stw	r28, 0(r25)
    slwi	r11, r11, 0x18
    add	r25, r3, r27
    lwz	r28, 0(r26)
    slwi	r10, r10, 0x18
    addi	r4, r4, 4
    clrlwi	r7, r28, 8
    or	r7, r7, r12
    stw	r7, 0(r26)
    addi	r5, r5, 2
    addi	r6, r6, 2
    lwz	r12, 0(r8)
    addi	r9, r9, 1
    clrlwi	r12, r12, 8
    or	r11, r12, r11
    stw	r11, 0(r8)
    lwz	r8, 0(r25)
    clrlwi	r8, r8, 8
    or	r8, r8, r10
    stw	r8, 0(r25)
    bdnz L80030b40
    stw	r0, 0x120(r3)
    addi	r4, r3, 0x120
    mr	r9, r0
    lwz	r3, 0(r4)
    li	r10, 0x30
    li	r11, 0x31
    clrlwi	r3, r3, 8
    oris	r3, r3, 0x2700
    stw	r3, 0(r4)
    b L80030cc0
L80030cc0:
    li	r3, 2
    mtctr	r3
    b L80030ccc
L80030ccc:
    b L80030cd0
L80030cd0:
    lwz	r3, -0x7de8(r2)
    addi	r8, r9, 0xb8
    addi	r7, r9, 0xd8
    stwx	r0, r3, r8
    slwi	r6, r10, 0x18
    slwi	r4, r11, 0x18
    stwx	r0, r3, r7
    add	r12, r3, r8
    addi	r9, r9, 4
    lwz	r5, 0(r12)
    add	r25, r3, r7
    addi	r8, r9, 0xb8
    clrlwi	r5, r5, 8
    or	r5, r5, r6
    stw	r5, 0(r12)
    addi	r7, r9, 0xd8
    addi	r10, r10, 2
    lwz	r5, 0(r25)
    slwi	r6, r10, 0x18
    add	r12, r3, r8
    clrlwi	r5, r5, 8
    or	r4, r5, r4
    stw	r4, 0(r25)
    addi	r11, r11, 2
    slwi	r4, r11, 0x18
    stwx	r0, r3, r8
    addi	r9, r9, 4
    add	r25, r3, r7
    stwx	r0, r3, r7
    addi	r8, r9, 0xb8
    addi	r7, r9, 0xd8
    lwz	r5, 0(r12)
    addi	r10, r10, 2
    addi	r11, r11, 2
    clrlwi	r5, r5, 8
    or	r5, r5, r6
    stw	r5, 0(r12)
    slwi	r6, r10, 0x18
    add	r12, r3, r8
    lwz	r5, 0(r25)
    addi	r9, r9, 4
    addi	r10, r10, 2
    clrlwi	r5, r5, 8
    or	r4, r5, r4
    stw	r4, 0(r25)
    slwi	r4, r11, 0x18
    add	r25, r3, r7
    stwx	r0, r3, r8
    addi	r8, r9, 0xb8
    addi	r11, r11, 2
    stwx	r0, r3, r7
    addi	r7, r9, 0xd8
    addi	r9, r9, 4
    lwz	r5, 0(r12)
    clrlwi	r5, r5, 8
    or	r5, r5, r6
    stw	r5, 0(r12)
    slwi	r6, r10, 0x18
    add	r12, r3, r8
    lwz	r5, 0(r25)
    addi	r10, r10, 2
    clrlwi	r5, r5, 8
    or	r4, r5, r4
    stw	r4, 0(r25)
    slwi	r4, r11, 0x18
    add	r25, r3, r7
    stwx	r0, r3, r8
    addi	r11, r11, 2
    stwx	r0, r3, r7
    lwz	r5, 0(r12)
    clrlwi	r5, r5, 8
    or	r5, r5, r6
    stw	r5, 0(r12)
    lwz	r5, 0(r25)
    clrlwi	r5, r5, 8
    or	r4, r5, r4
    stw	r4, 0(r25)
    bdnz L80030cd0
    addi	r5, r3, 0xf8
    lwz	r0, 0(r5)
    lis	r4, 0x1062
    addi	r6, r3, 0xfc
    clrlwi	r0, r0, 8
    oris	r0, r0, 0x2000
    stw	r0, 0(r5)
    addi	r7, r3, 0x1d0
    addi	r8, r3, 0x1d4
    lwz	r0, 0(r6)
    addi	r9, r3, 0x1d8
    addi	r10, r3, 0x1dc
    clrlwi	r0, r0, 8
    oris	r0, r0, 0x2100
    stw	r0, 0(r6)
    addi	r6, r3, 0x1fc
    li	r29, 0
    lwz	r0, 0(r7)
    lis	r5, -0x8000
    addi	r4, r4, 0x4dd3
    clrlwi	r0, r0, 8
    oris	r0, r0, 0x4100
    stw	r0, 0(r7)
    lwz	r0, 0(r8)
    clrlwi	r0, r0, 8
    oris	r0, r0, 0x4200
    stw	r0, 0(r8)
    lwz	r0, 0(r9)
    clrlwi	r0, r0, 8
    oris	r0, r0, 0x4000
    stw	r0, 0(r9)
    lwz	r0, 0(r10)
    clrlwi	r0, r0, 8
    oris	r0, r0, 0x4300
    stw	r0, 0(r10)
    lwz	r0, 0(r6)
    rlwinm	r0, r0, 0, 0x19, 0x16
    stw	r0, 0(r6)
    stw	r29, 0x4f4(r3)
    stb	r29, 0x4f3(r3)
    lwz	r0, 0xf8(r5)
    mulhwu	r0, r4, r0
    srwi	r25, r0, 5
    bl __GXFlushTextureState
    srwi	r0, r25, 0xb
    oris	r0, r0, 0x6900
    li	r28, 0x61
    lis	r31, -0x33ff
    stb	r28, -0x8000(r31)
    ori	r0, r0, 0x400
    stw	r0, -0x8000(r31)
    bl __GXFlushTextureState
    lis	r3, 0x3e10
    stb	r28, -0x8000(r31)
    addi	r0, r3, -0x7c1f
    mulhwu	r0, r0, r25
    srwi	r0, r0, 0xa
    oris	r0, r0, 0x4600
    ori	r0, r0, 0x200
    stw	r0, -0x8000(r31)
    mr	r7, r29
    b L80030f00
L80030f00:
    li	r0, 2
    mtctr	r0
    li	r5, 8
    b L80030f10
L80030f10:
    b L80030f14
L80030f14:
    lwz	r6, -0x7de8(r2)
    addi	r8, r7, 0x1c
    addi	r9, r7, 0x3c
    add	r8, r6, r8
    lwz	r0, 0(r8)
    ori	r4, r29, 0x80
    addi	r3, r7, 0x3c
    rlwinm	r0, r0, 0, 2, 0
    oris	r0, r0, 0x4000
    stw	r0, 0(r8)
    add	r9, r6, r9
    addi	r7, r7, 4
    lwz	r0, 0(r9)
    addi	r8, r7, 0x1c
    add	r8, r6, r8
    clrlwi	r0, r0, 1
    oris	r0, r0, 0x8000
    stw	r0, 0(r9)
    addi	r9, r7, 0x3c
    add	r9, r6, r9
    stb	r5, -0x8000(r31)
    addi	r29, r29, 1
    stb	r4, -0x8000(r31)
    ori	r4, r29, 0x80
    addi	r29, r29, 1
    lwzx	r0, r6, r3
    addi	r3, r7, 0x3c
    addi	r7, r7, 4
    stw	r0, -0x8000(r31)
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0, 2, 0
    oris	r0, r0, 0x4000
    stw	r0, 0(r8)
    addi	r8, r7, 0x1c
    add	r8, r6, r8
    lwz	r0, 0(r9)
    clrlwi	r0, r0, 1
    oris	r0, r0, 0x8000
    stw	r0, 0(r9)
    addi	r9, r7, 0x3c
    add	r9, r6, r9
    stb	r5, -0x8000(r31)
    stb	r4, -0x8000(r31)
    ori	r4, r29, 0x80
    addi	r29, r29, 1
    lwzx	r0, r6, r3
    addi	r3, r7, 0x3c
    addi	r7, r7, 4
    stw	r0, -0x8000(r31)
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0, 2, 0
    oris	r0, r0, 0x4000
    stw	r0, 0(r8)
    addi	r8, r7, 0x1c
    add	r8, r6, r8
    lwz	r0, 0(r9)
    clrlwi	r0, r0, 1
    oris	r0, r0, 0x8000
    stw	r0, 0(r9)
    addi	r9, r7, 0x3c
    add	r9, r6, r9
    stb	r5, -0x8000(r31)
    stb	r4, -0x8000(r31)
    ori	r4, r29, 0x80
    addi	r29, r29, 1
    lwzx	r0, r6, r3
    addi	r3, r7, 0x3c
    addi	r7, r7, 4
    stw	r0, -0x8000(r31)
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0, 2, 0
    oris	r0, r0, 0x4000
    stw	r0, 0(r8)
    lwz	r0, 0(r9)
    clrlwi	r0, r0, 1
    oris	r0, r0, 0x8000
    stw	r0, 0(r9)
    stb	r5, -0x8000(r31)
    stb	r4, -0x8000(r31)
    lwzx	r0, r6, r3
    stw	r0, -0x8000(r31)
    bdnz L80030f14
    li	r4, 0x10
    lis	r6, -0x33ff
    stb	r4, -0x8000(r6)
    li	r0, 0x1000
    li	r28, 0
    stw	r0, -0x8000(r6)
    li	r0, 0x3f
    slwi	r25, r28, 0xf
    stw	r0, -0x8000(r6)
    li	r0, 0x1012
    li	r5, 1
    stb	r4, -0x8000(r6)
    li	r4, 0x61
    lis	r3, 0x5800
    stw	r0, -0x8000(r6)
    addi	r0, r3, 0xf
    addis	r26, r25, 8
    stw	r5, -0x8000(r6)
    slwi	r27, r28, 4
    stb	r4, -0x8000(r6)
    stw	r0, -0x8000(r6)
    b L800310b4
L800310b4:
    b L800310b8
L800310b8:
    b L800310bc
L800310bc:
    lwz	r0, -0x7de8(r2)
    addi	r3, r27, 0x208
    mr	r5, r25
    mr	r7, r26
    add	r3, r0, r3
    li	r4, 0
    li	r6, 0
    li	r8, 0
    bl GXInitTexCacheRegion
    addis	r26, r26, 1
    addis	r25, r25, 1
    addi	r26, r26, -0x8000
    addi	r25, r25, -0x8000
    addi	r27, r27, 0x10
    addi	r28, r28, 1
    cmplwi	r28, 8
    blt L800310bc
    li	r25, 0
    slwi	r3, r25, 1
    addi	r26, r3, 9
    addi	r27, r3, 8
    slwi	r28, r25, 4
    b L80031118
L80031118:
    b L8003111c
L8003111c:
    b L80031120
L80031120:
    lwz	r0, -0x7de8(r2)
    addi	r3, r28, 0x288
    slwi	r5, r27, 0xf
    add	r3, r0, r3
    slwi	r7, r26, 0xf
    li	r4, 0
    li	r6, 0
    li	r8, 0
    bl GXInitTexCacheRegion
    addi	r26, r26, 2
    addi	r27, r27, 2
    addi	r28, r28, 0x10
    addi	r25, r25, 1
    cmplwi	r25, 4
    blt L80031120
    li	r25, 0
    slwi	r3, r25, 0xd
    addis	r26, r3, 0xc
    slwi	r27, r25, 4
    b L80031170
L80031170:
    b L80031174
L80031174:
    b L80031178
L80031178:
    lwz	r0, -0x7de8(r2)
    addi	r3, r27, 0x2d0
    mr	r4, r26
    add	r3, r0, r3
    li	r5, 0x10
    bl GXInitTlutRegion
    addi	r26, r26, 0x2000
    addi	r27, r27, 0x10
    addi	r25, r25, 1
    cmplwi	r25, 0x10
    blt L80031178
    li	r25, 0
    slwi	r3, r25, 0xf
    addis	r26, r3, 0xe
    b L800311b4
L800311b4:
    b L800311b8
L800311b8:
    b L800311bc
L800311bc:
    addi	r0, r25, 0x10
    lwz	r5, -0x7de8(r2)
    slwi	r3, r0, 4
    addi	r3, r3, 0x2d0
    mr	r4, r26
    add	r3, r5, r3
    li	r5, 0x40
    bl GXInitTlutRegion
    addis	r26, r26, 1
    addi	r26, r26, -0x8000
    addi	r25, r25, 1
    cmplwi	r25, 4
    blt L800311bc
    lwz	r4, -0x77f4(r13)
    li	r12, 0
    li	r3, 8
    sth	r12, 6(r4)
    lis	r10, -0x33ff
    li	r9, 0x20
    lwz	r11, -0x7de8(r2)
    li	r8, 0x10
    li	r7, 0x1006
    addi	r4, r11, 0x4ec
    lwz	r0, 0(r4)
    li	r6, 0x61
    lis	r5, 0x2300
    rlwinm	r0, r0, 0, 0x1c, 0x17
    stw	r0, 0(r4)
    lis	r4, 0x2400
    lis	r0, 0x6700
    stb	r3, -0x8000(r10)
    li	r3, 0
    stb	r9, -0x8000(r10)
    lwz	r9, 0x4ec(r11)
    stw	r9, -0x8000(r10)
    stb	r8, -0x8000(r10)
    stw	r7, -0x8000(r10)
    stw	r12, -0x8000(r10)
    stb	r6, -0x8000(r10)
    stw	r5, -0x8000(r10)
    stb	r6, -0x8000(r10)
    stw	r4, -0x8000(r10)
    stb	r6, -0x8000(r10)
    stw	r0, -0x8000(r10)
    bl __GXSetTmemConfig
    bl __GXInitGX
    addi	r3, r30, 0x4f8
    lmw	r25, 0x34(r1)
    lwz	r0, 0x54(r1)
    addi	r1, r1, 0x50
    mtlr	r0
    blr
}

asm static void __GXInitGX(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x80(r1)
    stw	r31, 0x7c(r1)
    stw	r30, 0x78(r1)
    stw	r29, 0x74(r1)
    lwz	r4, -0x7de4(r2)
    lwz	r3, -0x7de0(r2)
    lwz	r0, -0x7ddc(r2)
    stw	r4, 0x28(r1)
    stw	r3, 0x24(r1)
    stw	r0, 0x20(r1)
    bl VIGetTvFormat
    cmpwi	r3, 2
    beq L80031318
    bge L800312dc
    cmpwi	r3, 0
    beq L800312e8
    bge L800312f8
    b L80031328
L800312dc:
    cmpwi	r3, 5
    beq L80031308
    b L80031328
L800312e8:
    lis     r3, lbl_8012AFB8@ha
    addi	r0, r3, lbl_8012AFB8@l
    mr	r31, r0
    b L80031334
L800312f8:
    lis     r3, lbl_8012B0A8@ha
    addi	r0, r3, lbl_8012B0A8@l
    mr	r31, r0
    b L80031334
L80031308:
    lis     r3, lbl_8012B0E4@ha
    addi	r0, r3, lbl_8012B0E4@l
    mr	r31, r0
    b L80031334
L80031318:
    lis     r3, lbl_8012B06C@ha
    addi	r0, r3, lbl_8012B06C@l
    mr	r31, r0
    b L80031334
L80031328:
    lis     r3, lbl_8012AFB8@ha
    addi	r0, r3, lbl_8012AFB8@l
    mr	r31, r0
L80031334:
    lwz	r0, 0x28(r1)
    lis	r4, 0x100
    addi	r3, r1, 0x1c
    stw	r0, 0x1c(r1)
    addi	r4, r4, -1
    bl __GXSetBlendModePair
    li	r3, 0
    li	r4, 1
    li	r5, 4
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl GXSetTexCoordGen2
    li	r3, 1
    li	r4, 1
    li	r5, 5
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl GXSetTexCoordGen2
    li	r3, 2
    li	r4, 1
    li	r5, 6
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl GXSetTexCoordGen2
    li	r3, 3
    li	r4, 1
    li	r5, 7
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl GXSetTexCoordGen2
    li	r3, 4
    li	r4, 1
    li	r5, 8
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl GXSetTexCoordGen2
    li	r3, 5
    li	r4, 1
    li	r5, 9
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl GXSetTexCoordGen2
    li	r3, 6
    li	r4, 1
    li	r5, 0xa
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl GXSetTexCoordGen2
    li	r3, 7
    li	r4, 1
    li	r5, 0xb
    li	r6, 0x3c
    li	r7, 0
    li	r8, 0x7d
    bl GXSetTexCoordGen2
    li	r3, 1
    bl GXSetNumTexGens
    bl GXClearVtxDesc
    bl fn_80033A6C
    li	r29, 9
    b L80031444
L80031444:
    b L80031448
L80031448:
    b L8003144c
L8003144c:
    lwz	r4, -0x7de8(r2)
    mr	r3, r29
    li	r5, 0
    bl fn_800339E0
    addi	r29, r29, 1
    cmplwi	r29, 0x18
    ble L8003144c
    li	r29, 0
    b L80031470
L80031470:
    lis     r3, lbl_8012AC44@ha
    addi	r30, r3, lbl_8012AC44@l
    b L8003147c
L8003147c:
    b L80031480
L80031480:
    mr	r3, r29
    mr	r4, r30
    bl fn_800332D8
    addi	r29, r29, 1
    cmplwi	r29, 8
    blt L80031480
    li	r3, 6
    li	r4, 0
    bl GXSetLineWidth
    li	r3, 6
    li	r4, 0
    bl GXSetPointSize
    li	r3, 0
    li	r4, 0
    li	r5, 0
    bl __GXSetTexCoordGen_Cache
    li	r3, 1
    li	r4, 0
    li	r5, 0
    bl __GXSetTexCoordGen_Cache
    li	r3, 2
    li	r4, 0
    li	r5, 0
    bl __GXSetTexCoordGen_Cache
    li	r3, 3
    li	r4, 0
    li	r5, 0
    bl __GXSetTexCoordGen_Cache
    li	r3, 4
    li	r4, 0
    li	r5, 0
    bl __GXSetTexCoordGen_Cache
    li	r3, 5
    li	r4, 0
    li	r5, 0
    bl __GXSetTexCoordGen_Cache
    li	r3, 6
    li	r4, 0
    li	r5, 0
    bl __GXSetTexCoordGen_Cache
    li	r3, 7
    li	r4, 0
    li	r5, 0
    bl __GXSetTexCoordGen_Cache
    lfs	f1, -0x7dd8(r2)
    addi	r3, r1, 0x2c
    lfs	f0, -0x7dd4(r2)
    li	r4, 0
    stfs	f1, 0x2c(r1)
    stfs	f0, 0x30(r1)
    stfs	f0, 0x34(r1)
    stfs	f0, 0x38(r1)
    stfs	f0, 0x3c(r1)
    stfs	f1, 0x40(r1)
    stfs	f0, 0x44(r1)
    stfs	f0, 0x48(r1)
    stfs	f0, 0x4c(r1)
    stfs	f0, 0x50(r1)
    stfs	f1, 0x54(r1)
    stfs	f0, 0x58(r1)
    bl fn_80038C5C
    addi	r3, r1, 0x2c
    li	r4, 0
    bl fn_80038CAC
    li	r3, 0
    bl fn_80038CFC
    addi	r3, r1, 0x2c
    li	r4, 0x3c
    li	r5, 0
    bl GXWritePrimitiveFifo
    addi	r3, r1, 0x2c
    li	r4, 0x7d
    li	r5, 0
    bl GXWritePrimitiveFifo
    lhz	r4, 4(r31)
    lis	r3, 0x4330
    lhz	r0, 8(r31)
    stw	r4, 0x6c(r1)
    lfs	f1, -0x7dd4(r2)
    stw	r0, 0x64(r1)
    lfd	f4, -0x7dc8(r2)
    fmr	f2, f1
    stw	r3, 0x68(r1)
    fmr	f5, f1
    lfs	f6, -0x7dd8(r2)
    stw	r3, 0x60(r1)
    lfd	f3, 0x68(r1)
    lfd	f0, 0x60(r1)
    fsubs	f3, f3, f4
    fsubs	f4, f0, f4
    bl fn_80038EEC
    lis     r3, lbl_8012AD14@ha
    addi	r3, r3, lbl_8012AD14@l
    bl fn_80038B3C
    li	r3, 0
    bl __GXSetZMode_Cache
    li	r3, 2
    bl GXSetCullMode
    li	r3, 0
    bl fn_80039060
    lhz	r5, 4(r31)
    li	r3, 0
    lhz	r6, 6(r31)
    li	r4, 0
    bl fn_80038F48
    li	r3, 0
    li	r4, 0
    bl fn_80039020
    li	r3, 0
    bl __GXSetChanAmbColor
    li	r3, 4
    li	r4, 0
    li	r5, 0
    li	r6, 1
    li	r7, 0
    li	r8, 0
    li	r9, 2
    bl fn_80035960
    lwz	r0, 0x24(r1)
    addi	r4, r1, 0x18
    li	r3, 4
    stw	r0, 0x18(r1)
    bl GXSetChanAmbColor
    lwz	r0, 0x20(r1)
    addi	r4, r1, 0x14
    li	r3, 4
    stw	r0, 0x14(r1)
    bl GXSetChanMatColor
    li	r3, 5
    li	r4, 0
    li	r5, 0
    li	r6, 1
    li	r7, 0
    li	r8, 0
    li	r9, 2
    bl fn_80035960
    lwz	r0, 0x24(r1)
    addi	r4, r1, 0x10
    li	r3, 5
    stw	r0, 0x10(r1)
    bl GXSetChanAmbColor
    lwz	r0, 0x20(r1)
    addi	r4, r1, 0xc
    li	r3, 5
    stw	r0, 0xc(r1)
    bl GXSetChanMatColor
    bl fn_80036544
    lwz	r4, -0x7de8(r2)
    li	r30, 0
    lis     r3, fn_800307CC@ha
    stw	r30, 0x2c8(r4)
    addi	r3, r3, fn_800307CC@l
    stw	r30, 0x2cc(r4)
    bl fn_8003658C
    lis     r3, fn_80030848@ha
    addi	r3, r3, fn_80030848@l
    bl fn_800365A0
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 4
    bl GXSetChanCtrl
    li	r3, 1
    li	r4, 1
    li	r5, 1
    li	r6, 4
    bl GXSetChanCtrl
    li	r3, 2
    li	r4, 2
    li	r5, 2
    li	r6, 4
    bl GXSetChanCtrl
    li	r3, 3
    li	r4, 3
    li	r5, 3
    li	r6, 4
    bl GXSetChanCtrl
    li	r3, 4
    li	r4, 4
    li	r5, 4
    li	r6, 4
    bl GXSetChanCtrl
    li	r3, 5
    li	r4, 5
    li	r5, 5
    li	r6, 4
    bl GXSetChanCtrl
    li	r3, 6
    li	r4, 6
    li	r5, 6
    li	r6, 4
    bl GXSetChanCtrl
    li	r3, 7
    li	r4, 7
    li	r5, 7
    li	r6, 4
    bl GXSetChanCtrl
    li	r3, 8
    li	r4, 0xff
    li	r5, 0xff
    li	r6, 0xff
    bl GXSetChanCtrl
    li	r3, 9
    li	r4, 0xff
    li	r5, 0xff
    li	r6, 0xff
    bl GXSetChanCtrl
    li	r3, 0xa
    li	r4, 0xff
    li	r5, 0xff
    li	r6, 0xff
    bl GXSetChanCtrl
    li	r3, 0xb
    li	r4, 0xff
    li	r5, 0xff
    li	r6, 0xff
    bl GXSetChanCtrl
    li	r3, 0xc
    li	r4, 0xff
    li	r5, 0xff
    li	r6, 0xff
    bl GXSetChanCtrl
    li	r3, 0xd
    li	r4, 0xff
    li	r5, 0xff
    li	r6, 0xff
    bl GXSetChanCtrl
    li	r3, 0xe
    li	r4, 0xff
    li	r5, 0xff
    li	r6, 0xff
    bl GXSetChanCtrl
    li	r3, 0xf
    li	r4, 0xff
    li	r5, 0xff
    li	r6, 0xff
    bl GXSetChanCtrl
    li	r3, 1
    bl fn_800377C8
    li	r3, 0
    li	r4, 3
    bl fn_80037014
    li	r3, 7
    li	r4, 0
    li	r5, 0
    li	r6, 7
    li	r7, 0
    bl fn_80037518
    li	r3, 0
    li	r4, 0x11
    li	r5, 0
    bl fn_8003756C
    b L80031874
L80031874:
    b L80031878
L80031878:
    b L8003187c
L8003187c:
    mr	r3, r30
    li	r4, 6
    bl fn_80037354
    mr	r3, r30
    li	r4, 0
    bl fn_800373C0
    mr	r3, r30
    li	r4, 0
    li	r5, 0
    bl fn_8003742C
    addi	r30, r30, 1
    cmplwi	r30, 0x10
    blt L8003187c
    li	r3, 0
    li	r4, 0
    li	r5, 1
    li	r6, 2
    li	r7, 3
    bl fn_80037480
    li	r3, 1
    li	r4, 0
    li	r5, 0
    li	r6, 0
    li	r7, 3
    bl fn_80037480
    li	r3, 2
    li	r4, 1
    li	r5, 1
    li	r6, 1
    li	r7, 3
    bl fn_80037480
    li	r3, 3
    li	r4, 2
    li	r5, 2
    li	r6, 2
    li	r7, 3
    bl fn_80037480
    li	r30, 0
    b L80031918
L80031918:
    b L8003191c
L8003191c:
    b L80031920
L80031920:
    mr	r3, r30
    bl fn_80036EDC
    addi	r30, r30, 1
    cmplwi	r30, 0x10
    blt L80031920
    li	r3, 0
    bl fn_80036EB4
    li	r3, 0
    li	r4, 0
    li	r5, 0
    bl fn_80036C24
    li	r3, 1
    li	r4, 0
    li	r5, 0
    bl fn_80036C24
    li	r3, 2
    li	r4, 0
    li	r5, 0
    bl fn_80036C24
    li	r3, 3
    li	r4, 0
    li	r5, 0
    bl fn_80036C24
    lfs	f2, -0x7dd8(r2)
    addi	r4, r1, 8
    lwz	r0, 0x24(r1)
    li	r3, 0
    fmr	f4, f2
    stw	r0, 8(r1)
    lfs	f1, -0x7dd4(r2)
    lfs	f3, -0x7dd0(r2)
    bl fn_800377F8
    li	r3, 0
    li	r4, 0
    li	r5, 0
    bl fn_80037A14
    li	r3, 0
    li	r4, 4
    li	r5, 5
    li	r6, 0
    bl fn_80037B14
    li	r3, 1
    bl fn_80037B68
    li	r3, 1
    bl fn_80037B94
    li	r3, 1
    li	r4, 3
    li	r5, 1
    bl fn_80037BC0
    li	r3, 1
    bl fn_80037BF4
    li	r3, 1
    bl fn_80037D14
    li	r3, 0
    li	r4, 0
    bl fn_80037D40
    li	r3, 0
    li	r4, 0
    bl fn_80037C2C
    li	r3, 1
    li	r4, 1
    bl fn_80037D7C
    lhz	r0, 8(r31)
    lhz	r3, 0x10(r31)
    slwi	r0, r0, 1
    cmpw	r3, r0
    bne L80031a34
    li	r4, 1
    b L80031a38
L80031a34:
    li	r4, 0
L80031a38:
    lbz	r3, 0x18(r31)
    bl fn_80037DB4
    lhz	r5, 4(r31)
    li	r3, 0
    lhz	r6, 6(r31)
    li	r4, 0
    bl __GXSetScissor_LT
    lhz	r3, 4(r31)
    lhz	r4, 6(r31)
    bl __GXSetScissorBoxOffset
    lhz	r4, 8(r31)
    lis	r3, 0x4330
    lhz	r0, 6(r31)
    stw	r4, 0x64(r1)
    lfd	f2, -0x7dc8(r2)
    stw	r0, 0x6c(r1)
    stw	r3, 0x60(r1)
    stw	r3, 0x68(r1)
    lfd	f1, 0x60(r1)
    lfd	f0, 0x68(r1)
    fsubs	f1, f1, f2
    fsubs	f0, f0, f2
    fdivs	f1, f1, f0
    bl fn_80034D9C
    li	r3, 3
    bl fn_80034D34
    lbz	r3, 0x19(r31)
    addi	r4, r31, 0x1a
    addi	r6, r31, 0x32
    li	r5, 1
    bl GXSetCopyClear
    li	r3, 0
    bl fn_800350F4
    li	r3, 0
    bl fn_80034D0C
    bl fn_800353E8
    li	r3, 1
    bl fn_800342B8
    li	r3, 1
    bl fn_80034214
    li	r3, 0
    bl fn_800342E8
    li	r3, 0
    li	r4, 0
    li	r5, 1
    li	r6, 0xf
    bl fn_80034230
    li	r3, 7
    li	r4, 0
    bl fn_800341EC
    li	r3, 1
    bl fn_80034200
    li	r3, 0
    li	r4, 0
    bl fn_800342D4
    li	r3, 1
    li	r4, 7
    li	r5, 1
    bl fn_80034304
    li	r3, 0x23
    li	r4, 0x16
    bl fn_8003910C
    bl fn_80039AFC
    lwz	r0, 0x84(r1)
    lwz	r31, 0x7c(r1)
    lwz	r30, 0x78(r1)
    lwz	r29, 0x74(r1)
    addi	r1, r1, 0x80
    mtlr	r0
    blr
}

asm void fn_80031B50(int interrupt, void *context)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x2e0(r1)
    stw	r31, 0x2dc(r1)
    mr	r31, r4
    lwz	r5, -0x77f4(r13)
    lwz	r3, -0x7de8(r2)
    lhz	r0, 0(r5)
    stw	r0, 0xc(r3)
    lwz	r0, 8(r3)
    rlwinm.	r0, r0, 0x1d, 0x1f, 0x1f
    beq L80031bb4
    lwz	r0, 0xc(r3)
    rlwinm.	r0, r0, 0x1f, 0x1f, 0x1f
    beq L80031bb4
    lwz	r3, -0x77c8(r13)
    bl fn_80010CB0
    li	r0, 0
    stw	r0, -0x77c0(r13)
    li	r3, 1
    li	r4, 1
    bl __GXWriteFifoIntReset
    li	r3, 1
    li	r4, 0
    bl __GXWriteFifoIntEnable
L80031bb4:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 8(r3)
    rlwinm.	r0, r0, 0x1e, 0x1f, 0x1f
    beq L80031c04
    lwz	r0, 0xc(r3)
    clrlwi.	r0, r0, 0x1f
    beq L80031c04
    lwz	r5, -0x77b8(r13)
    li	r3, 0
    li	r4, 1
    addi	r0, r5, 1
    stw	r0, -0x77b8(r13)
    bl __GXWriteFifoIntEnable
    li	r3, 1
    li	r4, 0
    bl __GXWriteFifoIntReset
    li	r0, 1
    lwz	r3, -0x77c8(r13)
    stw	r0, -0x77c0(r13)
    bl fn_80010F38
L80031c04:
    lwz	r3, -0x7de8(r2)
    lwz	r4, 8(r3)
    addi	r5, r3, 8
    rlwinm.	r0, r4, 0x1b, 0x1f, 0x1f
    beq L80031c70
    lwz	r0, 0xc(r3)
    rlwinm.	r0, r0, 0x1c, 0x1f, 0x1f
    beq L80031c70
    rlwinm	r0, r4, 0, 0x1b, 0x19
    stw	r0, 0(r5)
    lwz	r0, 8(r3)
    lwz	r3, -0x77f4(r13)
    sth	r0, 2(r3)
    lwz	r0, -0x77bc(r13)
    cmplwi	r0, 0
    beq L80031c70
    addi	r3, r1, 0x10
    bl OSClearContext
    addi	r3, r1, 0x10
    bl OSSetCurrentContext
    lwz	r12, -0x77bc(r13)
    mtlr	r12
    blrl
    addi	r3, r1, 0x10
    bl OSClearContext
    mr	r3, r31
    bl OSSetCurrentContext
L80031c70:
    lwz	r0, 0x2e4(r1)
    lwz	r31, 0x2dc(r1)
    addi	r1, r1, 0x2e0
    mtlr	r0
    blr
}

#pragma pop
