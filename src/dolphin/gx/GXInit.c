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
extern void GXSetBreakPtCallback(GXBreakPtCallback cb);
extern void fn_80033EB0(void);
extern void fn_80034378(s32 arg);
extern void fn_80034444(s32 arg);
extern void fn_80010CB0(void *thread);
extern void fn_80010F38(void *thread);
extern void __GXWriteFifoIntEnable(u8 hiWatermarkEn, u8 loWatermarkEn);
extern void __GXWriteFifoIntReset(u8 hiWatermarkClr, u8 loWatermarkClr);
extern s32 fn_80036104(GXTexObj *obj);

/* called from later GX units */
extern void fn_80034E64(void *color, u32 zvalue);
extern void fn_80033A7C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void fn_80033D4C(s32 num);
extern void fn_80032F48(void);
extern void fn_80033A6C(void);
extern void fn_800339E0(s32 idx, void *arg, s32 val);
extern void fn_800332D8(s32 idx, const void *tbl);
extern void fn_800347A4(s32 width, s32 shift);
extern void fn_800347EC(s32 size, s32 shift);
extern void fn_80034834(s32 coord, s32 en1, s32 en2);
extern void fn_80038C5C(void *mtx, s32 id);
extern void fn_80038CAC(void *mtx, s32 id);
extern void fn_80038CFC(s32 id);
extern void fn_80038D34(void *mtx, s32 id, s32 type);
extern void fn_80038EEC(f32 x, f32 y, f32 wd, f32 ht, f32 nearz, f32 farz);
extern void fn_80038B3C(const void *data);
extern void fn_800348DC(s32 arg);
extern void fn_80034890(s32 arg);
extern void fn_80039060(s32 arg);
extern void fn_80038F48(s32 l, s32 t, s32 r, s32 b);
extern void fn_80039020(s32 ofs_x, s32 ofs_y);
extern void fn_8003591C(s32 num);
extern void fn_80035960(s32 chan, s32 en, s32 amb, s32 mat, s32 lights, s32 df, s32 af);
extern void fn_80035734(s32 chan, void *color);
extern void fn_80035828(s32 chan, void *color);
extern void fn_80036544(void);
extern void fn_8003658C(void *cb);
extern void fn_800365A0(void *cb);
extern void fn_800375F0(s32 stage, s32 coord, s32 map, s32 color);
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
extern void fn_80034A5C(s32 left, s32 top, s32 wd, s32 ht);
extern void fn_80034B7C(s32 wd, s32 ht);
extern void fn_80034D9C(f32 yscale);
extern void fn_80034D34(s32 gamma);
extern void fn_80034ECC(u8 aa, const u8 *sample, BOOL enable, const u8 *vfilt);
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

#pragma pop
