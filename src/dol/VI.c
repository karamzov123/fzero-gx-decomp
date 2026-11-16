/* Dolphin SDK VI library: vi.c (build of Sep  5 2002). */
#include <dolphin/os.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSRtc.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/types.h>
#include "dolphin/hw_regs.h"

typedef volatile u64 vu64; // fzgx-allow: S2 SDK asynchronous state

#define VI_TVMODE(format, interlace) (((format) << 2) + (interlace))

#define VI_INTERLACE 0
#define VI_NON_INTERLACE 1
#define VI_PROGRESSIVE 2
#define VI_3D 3

#define VI_NTSC 0
#define VI_PAL 1
#define VI_MPAL 2
#define VI_DEBUG 3
#define VI_DEBUG_PAL 4
#define VI_EURGB60 5
#define VI_GCA 6

typedef enum {
    VI_TVMODE_NTSC_INT = VI_TVMODE(VI_NTSC, VI_INTERLACE),
    VI_TVMODE_NTSC_DS = VI_TVMODE(VI_NTSC, VI_NON_INTERLACE),
    VI_TVMODE_NTSC_PROG = VI_TVMODE(VI_NTSC, VI_PROGRESSIVE),
    VI_TVMODE_NTSC_3D = VI_TVMODE(VI_NTSC, VI_3D),
    VI_TVMODE_PAL_INT = VI_TVMODE(VI_PAL, VI_INTERLACE),
    VI_TVMODE_PAL_DS = VI_TVMODE(VI_PAL, VI_NON_INTERLACE),
    VI_TVMODE_MPAL_INT = VI_TVMODE(VI_MPAL, VI_INTERLACE),
    VI_TVMODE_MPAL_DS = VI_TVMODE(VI_MPAL, VI_NON_INTERLACE),
    VI_TVMODE_DEBUG_INT = VI_TVMODE(VI_DEBUG, VI_INTERLACE),
    VI_TVMODE_DEBUG_PAL_INT = VI_TVMODE(VI_DEBUG_PAL, VI_INTERLACE),
    VI_TVMODE_DEBUG_PAL_DS = VI_TVMODE(VI_DEBUG_PAL, VI_NON_INTERLACE),
    VI_TVMODE_EURGB60_INT = VI_TVMODE(VI_EURGB60, VI_INTERLACE),
    VI_TVMODE_EURGB60_DS = VI_TVMODE(VI_EURGB60, VI_NON_INTERLACE),
    VI_TVMODE_GCA_INT = VI_TVMODE(VI_GCA, VI_INTERLACE),
    VI_TVMODE_GCA_DS = VI_TVMODE(VI_GCA, VI_NON_INTERLACE),
    VI_TVMODE_GCA_PROG = VI_TVMODE(VI_GCA, VI_PROGRESSIVE)
} VITVMode;

typedef enum { VI_XFBMODE_SF = 0, VI_XFBMODE_DF } VIXFBMode;

typedef void (*VIRetraceCallback)(u32 retraceCount);

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

typedef struct timing_s {
    u8 equ;
    u16 acv;
    u16 prbOdd;
    u16 prbEven;
    u16 psbOdd;
    u16 psbEven;
    u8 bs1;
    u8 bs2;
    u8 bs3;
    u8 bs4;
    u16 be1;
    u16 be2;
    u16 be3;
    u16 be4;
    u16 nhlines;
    u16 hlw;
    u8 hsy;
    u8 hcs;
    u8 hce;
    u8 hbe640;
    u16 hbs640;
    u8 hbeCCIR656;
    u16 hbsCCIR656;
} timing_s;

typedef struct HorVer_s {
    u16 DispPosX;
    u16 DispPosY;
    u16 DispSizeX;
    u16 DispSizeY;
    u16 AdjustedDispPosX;
    u16 AdjustedDispPosY;
    u16 AdjustedDispSizeY;
    u16 AdjustedPanPosY;
    u16 AdjustedPanSizeY;
    u16 FBSizeX;
    u16 FBSizeY;
    u16 PanPosX;
    u16 PanPosY;
    u16 PanSizeX;
    u16 PanSizeY;
    VIXFBMode FBMode;
    u32 nonInter;
    u32 tv;
    u8 wordPerLine;
    u8 std;
    u8 wpl;
    u32 bufAddr;
    u32 tfbb;
    u32 bfbb;
    u8 xof;
    BOOL black;
    BOOL threeD;
    u32 rbufAddr;
    u32 rtfbb;
    u32 rbfbb;
    timing_s *timing;
} HorVer_s;

/* Register indices of __VIRegs. */
#define VI_VERT_TIMING 0
#define VI_DISP_CONFIG 1
#define VI_HORIZ_TIMING_0U 2
#define VI_HORIZ_TIMING_0L 3
#define VI_HORIZ_TIMING_1U 4
#define VI_HORIZ_TIMING_1L 5
#define VI_VERT_TIMING_ODD_U 6
#define VI_VERT_TIMING_ODD 7
#define VI_VERT_TIMING_EVEN_U 8
#define VI_VERT_TIMING_EVEN 9
#define VI_BBI_ODD_U 10
#define VI_BBI_ODD 11
#define VI_BBI_EVEN_U 12
#define VI_BBI_EVEN 13
#define VI_TOP_FIELD_BASE_LEFT_U 14
#define VI_TOP_FIELD_BASE_LEFT 15
#define VI_TOP_FIELD_BASE_RIGHT_U 16
#define VI_TOP_FIELD_BASE_RIGHT 17
#define VI_BOTTOM_FIELD_BASE_LEFT_U 18
#define VI_BOTTOM_FIELD_BASE_LEFT 19
#define VI_BOTTOM_FIELD_BASE_RIGHT_U 20
#define VI_BOTTOM_FIELD_BASE_RIGHT 21
#define VI_VERT_COUNT 22
#define VI_HORIZ_COUNT 23
#define VI_DISP_INT_0U 24
#define VI_DISP_INT_0 25
#define VI_DISP_INT_1U 26
#define VI_DISP_INT_1 27
#define VI_DISP_INT_2U 28
#define VI_DISP_INT_3U 30
#define VI_HSW 36
#define VI_HSR 37
#define VI_FCT_0U 38
#define VI_FCT_0 39
#define VI_FCT_1U 40
#define VI_FCT_1 41
#define VI_FCT_2U 42
#define VI_FCT_2 43
#define VI_FCT_3U 44
#define VI_FCT_3 45
#define VI_FCT_4U 46
#define VI_FCT_4 47
#define VI_FCT_5U 48
#define VI_FCT_5 49
#define VI_FCT_6U 50
#define VI_FCT_6 51
#define VI_CLK_SEL 54
#define VI_WIDTH 56

#define VI_DISP_CONFIG_SET_NIN(reg, x) ((((u32)(reg)) & ~0x00000004) | (((u32)(x)) << 2))
#define VI_DISP_CONFIG_SET_DLR(reg, x) ((((u32)(reg)) & ~0x00000008) | (((u32)(x)) << 3))
#define VI_DISP_CONFIG_SET_FMT(reg, x) ((((u32)(reg)) & ~0x00000300) | (((u32)(x)) << 8))
#define VI_CLK_SEL_SET_VICLKSEL(reg, x) ((((u32)(reg)) & ~0x00000001) | (((u32)(x)) << 0))

#define VI_BITMASK(index) (1ull << (63 - (index)))
#define MARK_CHANGED(index) (changed |= VI_BITMASK(index))

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define CLAMP(x, l, h) (((x) > (h)) ? (h) : (((x) < (l)) ? (l) : (x)))

#define IS_LOWER_16MB(x) ((x) < 16 * 1024 * 1024)

vu16 __VIRegs[59] : FZGX_ADDR___VIRegs;

extern int __cntlzw(unsigned int);

void OSSleepThread(OSThreadQueue *queue);
void OSWakeupThread(OSThreadQueue *queue);
void OSInitThreadQueue(OSThreadQueue *queue);
void OSReport(const char *msg, ...);
void OSRegisterVersion(const char *id);
OSSram *__OSLockSram(void);
BOOL __OSUnlockSram(BOOL commit);
__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);
void SIRefreshSamplingRate(void);

const char *__VIVersion = "<< Dolphin SDK - VI\trelease build: Sep  5 2002 05:33:13 (0x2301) >>";

static BOOL IsInitialized;
static vu32 retraceCount; // fzgx-allow: S2 SDK asynchronous state
static vu32 flushFlag; // fzgx-allow: S2 SDK asynchronous state
static OSThreadQueue retraceQueue;
static VIRetraceCallback PreCB;
static VIRetraceCallback PostCB;
static u32 encoderType;
static s16 displayOffsetH;
static s16 displayOffsetV;
static vu32 changeMode; // fzgx-allow: S2 SDK asynchronous state
static vu64 changed; // fzgx-allow: S2 SDK asynchronous state
static vu32 shdwChangeMode; // fzgx-allow: S2 SDK asynchronous state
static vu64 shdwChanged; // fzgx-allow: S2 SDK asynchronous state
static timing_s *CurrTiming;
static u32 CurrTvMode;
static u32 NextBufAddr;
static u32 CurrBufAddr;
static u32 FBSet;

static u16 regs[59];
static u16 shdwRegs[59];
static HorVer_s HorVer;

static timing_s timing[10] = {
    {6, 240, 24, 25, 3, 2, 12, 13, 12, 13, 520, 519, 520, 519, 525, 429, 64, 71, 105, 162, 373, 122, 412},
    {6, 240, 24, 24, 4, 4, 12, 12, 12, 12, 520, 520, 520, 520, 526, 429, 64, 71, 105, 162, 373, 122, 412},
    {5, 287, 35, 36, 1, 0, 13, 12, 11, 10, 619, 618, 617, 620, 625, 432, 64, 75, 106, 172, 380, 133, 420},
    {5, 287, 33, 33, 2, 2, 13, 11, 13, 11, 619, 621, 619, 621, 624, 432, 64, 75, 106, 172, 380, 133, 420},
    {6, 240, 24, 25, 3, 2, 16, 15, 14, 13, 518, 517, 516, 519, 525, 429, 64, 78, 112, 162, 373, 122, 412},
    {6, 240, 24, 24, 4, 4, 16, 14, 16, 14, 518, 520, 518, 520, 526, 429, 64, 78, 112, 162, 373, 122, 412},
    {12, 480, 48, 48, 6, 6, 24, 24, 24, 24, 1038, 1038, 1038, 1038, 1050, 429, 64, 71, 105, 162, 373, 122, 412},
    {12, 480, 44, 44, 10, 10, 24, 24, 24, 24, 1038, 1038, 1038, 1038, 1050, 429, 64, 71, 105, 168, 379, 122, 412},
    {6, 241, 24, 25, 1, 0, 12, 13, 12, 13, 520, 519, 520, 519, 525, 429, 64, 71, 105, 159, 370, 122, 412},
    {12, 480, 48, 48, 6, 6, 24, 24, 24, 24, 1038, 1038, 1038, 1038, 1050, 429, 64, 71, 105, 180, 391, 122, 412},
};

static u16 taps[25] = {
    0x01F0, 0x01DC, 0x01AE, 0x0174, 0x0129, 0x00DB, 0x008E, 0x0046, 0x000C,
    0x00E2, 0x00CB, 0x00C0, 0x00C4, 0x00CF, 0x00DE, 0x00EC, 0x00FC, 0x0008,
    0x000F, 0x0013, 0x0013, 0x000F, 0x000C, 0x0008, 0x0001,
};

static u32 getCurrentFieldEvenOdd(void);

static u32 cntlzd(u64 bit) {
    u32 hi;
    u32 lo;
    s32 value;

    hi = (u32)(bit >> 32);
    lo = (u32)(bit & 0xFFFFFFFF);
    value = __cntlzw(hi);
    if (value < 32) {
        return value;
    }
    return 32 + __cntlzw(lo);
}

static BOOL VISetRegs(void) {
    s32 regIndex;

    if (!(shdwChangeMode == 1 && getCurrentFieldEvenOdd() == 0)) {
        while (shdwChanged) {
            regIndex = cntlzd(shdwChanged);
            __VIRegs[regIndex] = shdwRegs[regIndex];
            shdwChanged &= ~VI_BITMASK(regIndex);
        }
        shdwChangeMode = 0;
        CurrTiming = HorVer.timing;
        CurrTvMode = HorVer.tv;
        CurrBufAddr = NextBufAddr;
        return TRUE;
    }
    return FALSE;
}

static void __VIRetraceHandler(__OSInterrupt interrupt, OSContext *context) {
    OSContext exceptionContext;
    u16 reg;
    u32 inter = 0;
    /* Not used by the release build. MWCC 1.2.5n still gives the declared local a
       stack slot: the retail frame is 0x2F8 bytes, 8 more than without it. */
    u32 val;

    reg = __VIRegs[VI_DISP_INT_0U];
    if (reg & 0x8000) {
        __VIRegs[VI_DISP_INT_0U] = reg & ~0x8000;
        inter |= 1;
    }
    reg = __VIRegs[VI_DISP_INT_1U];
    if (reg & 0x8000) {
        __VIRegs[VI_DISP_INT_1U] = reg & ~0x8000;
        inter |= 2;
    }
    reg = __VIRegs[VI_DISP_INT_2U];
    if (reg & 0x8000) {
        __VIRegs[VI_DISP_INT_2U] = reg & ~0x8000;
        inter |= 4;
    }
    reg = __VIRegs[VI_DISP_INT_3U];
    if (reg & 0x8000) {
        __VIRegs[VI_DISP_INT_3U] = reg & ~0x8000;
        inter |= 8;
    }

    if ((inter & 4) || (inter & 8)) {
        OSSetCurrentContext(context);
        return;
    }

    retraceCount++;

    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    if (PreCB) {
        (*PreCB)(retraceCount);
    }

    if (flushFlag) {
        if (VISetRegs()) {
            flushFlag = 0;
            SIRefreshSamplingRate();
        }
    }

    if (PostCB) {
        OSClearContext(&exceptionContext);
        (*PostCB)(retraceCount);
    }

    OSWakeupThread(&retraceQueue);

    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}

/* VISetPreRetraceCallback */
VIRetraceCallback fn_8001A78C(VIRetraceCallback callback) {
    BOOL enabled;
    VIRetraceCallback oldcb;

    oldcb = PreCB;
    enabled = OSDisableInterrupts();
    PreCB = callback;
    OSRestoreInterrupts(enabled);
    return oldcb;
}

/* VISetPostRetraceCallback */
VIRetraceCallback fn_8001A7D0(VIRetraceCallback callback) {
    BOOL enabled;
    VIRetraceCallback oldcb;

    oldcb = PostCB;
    enabled = OSDisableInterrupts();
    PostCB = callback;
    OSRestoreInterrupts(enabled);
    return oldcb;
}

static timing_s *getTiming(VITVMode mode) {
    switch (mode) {
    case VI_TVMODE_NTSC_INT:
        return &timing[0];
    case VI_TVMODE_NTSC_DS:
        return &timing[1];
    case VI_TVMODE_PAL_INT:
        return &timing[2];
    case VI_TVMODE_PAL_DS:
        return &timing[3];
    case VI_TVMODE_EURGB60_INT:
        return &timing[0];
    case VI_TVMODE_EURGB60_DS:
        return &timing[1];
    case VI_TVMODE_MPAL_INT:
        return &timing[4];
    case VI_TVMODE_MPAL_DS:
        return &timing[5];
    case VI_TVMODE_NTSC_PROG:
        return &timing[6];
    case VI_TVMODE_NTSC_3D:
        return &timing[7];
    case VI_TVMODE_DEBUG_PAL_INT:
        return &timing[2];
    case VI_TVMODE_DEBUG_PAL_DS:
        return &timing[3];
    case VI_TVMODE_GCA_INT:
        return &timing[8];
    case VI_TVMODE_GCA_PROG:
        return &timing[9];
    }
    return NULL;
}

void __VIInit(VITVMode mode) {
    timing_s *tm;
    u32 nonInter;
    vu32 a; // fzgx-allow: S2 SDK delay loop counter
    u32 tv, tvForReg;
    u16 hct, vct;

    nonInter = mode & 2;
    tv = (u32)mode >> 2;
    __OSTVMode = tv;
    tm = getTiming(mode);

    __VIRegs[VI_DISP_CONFIG] = 2;
    for (a = 0; a < 1000; a++) {
    }
    __VIRegs[VI_DISP_CONFIG] = 0;

    __VIRegs[VI_HORIZ_TIMING_0L] = tm->hlw << 0;
    __VIRegs[VI_HORIZ_TIMING_0U] = (tm->hce << 0) | (tm->hcs << 8);
    __VIRegs[VI_HORIZ_TIMING_1L] = (tm->hsy << 0) | ((tm->hbe640 & ((1 << 9) - 1)) << 7);
    __VIRegs[VI_HORIZ_TIMING_1U] = ((tm->hbe640 >> 9) << 0) | (tm->hbs640 << 1);
    __VIRegs[VI_VERT_TIMING] = (tm->equ << 0) | (0 << 4);
    __VIRegs[VI_VERT_TIMING_ODD] = (tm->prbOdd + tm->acv * 2 - 2) << 0;
    __VIRegs[VI_VERT_TIMING_ODD_U] = tm->psbOdd + 2 << 0;
    __VIRegs[VI_VERT_TIMING_EVEN] = (tm->prbEven + tm->acv * 2 - 2) << 0;
    __VIRegs[VI_VERT_TIMING_EVEN_U] = tm->psbEven + 2 << 0;
    __VIRegs[VI_BBI_ODD] = (tm->bs1 << 0) | (tm->be1 << 5);
    __VIRegs[VI_BBI_ODD_U] = (tm->bs3 << 0) | (tm->be3 << 5);
    __VIRegs[VI_BBI_EVEN] = (tm->bs2 << 0) | (tm->be2 << 5);
    __VIRegs[VI_BBI_EVEN_U] = (tm->bs4 << 0) | (tm->be4 << 5);
    __VIRegs[VI_HSW] = (40 << 0) | (40 << 8);
    __VIRegs[VI_DISP_INT_1] = 1;
    __VIRegs[VI_DISP_INT_1U] = (1 << 0) | (1 << 12) | (0 << 15);

    hct = (tm->hlw + 1);
    vct = (tm->nhlines / 2 + 1) | (1 << 12) | (0 << 15);
    __VIRegs[VI_DISP_INT_0] = hct << 0;
    __VIRegs[VI_DISP_INT_0U] = vct;

    if (mode != VI_TVMODE_NTSC_PROG && mode != VI_TVMODE_NTSC_3D && mode != VI_TVMODE_GCA_PROG) {
        __VIRegs[VI_DISP_CONFIG] =
            (1 << 0) | (0 << 1) | (nonInter << 2) | (0 << 3) | (0 << 4) | (0 << 6) | (tv << 8);
        __VIRegs[VI_CLK_SEL] = 0;
    } else {
        __VIRegs[VI_DISP_CONFIG] = (1 << 0) | (0 << 1) | (1 << 2) | (0 << 3) | (0 << 4) | (0 << 6) | (tv << 8);
        __VIRegs[VI_CLK_SEL] = 1;
    }
}

static void AdjustPosition(u16 acv) {
    s32 coeff;
    s32 frac;

    HorVer.AdjustedDispPosX = CLAMP((s16)HorVer.DispPosX + displayOffsetH, 0, 720 - HorVer.DispSizeX);

    coeff = (HorVer.FBMode == VI_XFBMODE_SF) ? 2 : 1;
    frac = HorVer.DispPosY & 1;

    HorVer.AdjustedDispPosY = MAX((s16)HorVer.DispPosY + displayOffsetV, frac);

    HorVer.AdjustedDispSizeY =
        HorVer.DispSizeY + MIN((s16)HorVer.DispPosY + displayOffsetV - frac, 0) -
        MAX((s16)HorVer.DispPosY + (s16)HorVer.DispSizeY + displayOffsetV - (((s16)acv * 2) - frac), 0);

    HorVer.AdjustedPanPosY = HorVer.PanPosY - (MIN((s16)HorVer.DispPosY + displayOffsetV - frac, 0) / coeff);

    HorVer.AdjustedPanSizeY =
        HorVer.PanSizeY + (MIN((s16)HorVer.DispPosY + displayOffsetV - frac, 0) / coeff) -
        (MAX((s16)HorVer.DispPosY + (s16)HorVer.DispSizeY + displayOffsetV - (((s16)acv * 2) - frac), 0) / coeff);
}

static void ImportAdjustingValues(void) {
    OSSram *sram;

    sram = __OSLockSram();
    displayOffsetH = sram->displayOffsetH;
    displayOffsetV = 0;
    __OSUnlockSram(FALSE);
}

static u32 getEncoderType(void) {
    return 1;
}

void VIInit(void) {
    u16 dspCfg;
    u32 value;
    u32 tv;
    u32 tvInBootrom;

    if (IsInitialized) {
        return;
    }

    OSRegisterVersion(__VIVersion);
    IsInitialized = TRUE;

    encoderType = getEncoderType();

    if (!(__VIRegs[VI_DISP_CONFIG] & 1)) {
        __VIInit(VI_TVMODE_NTSC_INT);
    }

    retraceCount = 0;
    changed = 0;
    shdwChanged = 0;
    changeMode = 0;
    shdwChangeMode = 0;
    flushFlag = 0;

    __VIRegs[VI_FCT_0] = taps[0] | ((taps[1] & 0x3F) << 10);
    __VIRegs[VI_FCT_0U] = (taps[1] >> 6) | (taps[2] << 4);
    __VIRegs[VI_FCT_1] = taps[3] | ((taps[4] & 0x3F) << 10);
    __VIRegs[VI_FCT_1U] = (taps[4] >> 6) | (taps[5] << 4);
    __VIRegs[VI_FCT_2] = taps[6] | ((taps[7] & 0x3F) << 10);
    __VIRegs[VI_FCT_2U] = (taps[7] >> 6) | (taps[8] << 4);
    __VIRegs[VI_FCT_3] = taps[9] | (taps[10] << 8);
    __VIRegs[VI_FCT_3U] = taps[11] | (taps[12] << 8);
    __VIRegs[VI_FCT_4] = taps[13] | (taps[14] << 8);
    __VIRegs[VI_FCT_4U] = taps[15] | (taps[16] << 8);
    __VIRegs[VI_FCT_5] = taps[17] | (taps[18] << 8);
    __VIRegs[VI_FCT_5U] = taps[19] | (taps[20] << 8);
    __VIRegs[VI_FCT_6] = taps[21] | (taps[22] << 8);
    __VIRegs[VI_FCT_6U] = taps[23] | (taps[24] << 8);

    __VIRegs[VI_WIDTH] = 640;

    ImportAdjustingValues();

    tvInBootrom = __OSTVMode;
    dspCfg = __VIRegs[VI_DISP_CONFIG];
    HorVer.nonInter = (dspCfg >> 2U) & 1;
    HorVer.tv = ((u32)dspCfg & 0x300) >> 8;
    if (tvInBootrom == VI_PAL && HorVer.tv == VI_NTSC) {
        HorVer.tv = VI_EURGB60;
    }
    tv = (HorVer.tv == VI_DEBUG) ? VI_NTSC : HorVer.tv;
    HorVer.timing = getTiming((VITVMode)VI_TVMODE(tv, HorVer.nonInter));
    regs[VI_DISP_CONFIG] = dspCfg;

    CurrTiming = HorVer.timing;
    CurrTvMode = HorVer.tv;

    HorVer.DispSizeX = 640;
    HorVer.DispSizeY = CurrTiming->acv * 2;
    HorVer.DispPosX = (720 - HorVer.DispSizeX) / 2;
    HorVer.DispPosY = 0;

    AdjustPosition(CurrTiming->acv);

    HorVer.FBSizeX = 640;
    HorVer.FBSizeY = CurrTiming->acv * 2;
    HorVer.PanPosX = 0;
    HorVer.PanPosY = 0;
    HorVer.PanSizeX = 640;
    HorVer.PanSizeY = CurrTiming->acv * 2;
    HorVer.FBMode = VI_XFBMODE_SF;
    HorVer.wordPerLine = 40;
    HorVer.std = 40;
    HorVer.wpl = 40;
    HorVer.xof = 0;
    HorVer.black = TRUE;
    HorVer.threeD = FALSE;

    OSInitThreadQueue(&retraceQueue);

    value = __VIRegs[VI_DISP_INT_0U];
    value = (u16)(value & ~0x8000);
    __VIRegs[VI_DISP_INT_0U] = (u16)value;
    value = __VIRegs[VI_DISP_INT_1U];
    value = (u16)(value & ~0x8000);
    __VIRegs[VI_DISP_INT_1U] = (u16)value;

    PreCB = NULL;
    PostCB = NULL;

    __OSSetInterruptHandler(0x18, __VIRetraceHandler);
    __OSUnmaskInterrupts(0x80);
}

void VIWaitForRetrace(void) {
    BOOL enabled;
    u32 count;

    enabled = OSDisableInterrupts();
    count = retraceCount;
    do {
        OSSleepThread(&retraceQueue);
    } while (count == retraceCount);
    OSRestoreInterrupts(enabled);
}

static void setInterruptRegs(timing_s *tm) {
    u16 hct, vct, borrow;

    vct = tm->nhlines / 2;
    borrow = tm->nhlines % 2;
    if (borrow != 0) {
        hct = tm->hlw;
    } else {
        hct = 0;
    }
    vct++;
    hct++;
    regs[VI_DISP_INT_0] = hct;
    MARK_CHANGED(VI_DISP_INT_0);
    regs[VI_DISP_INT_0U] = vct | 0x1000;
    MARK_CHANGED(VI_DISP_INT_0U);
}

static void setPicConfig(u16 fbSizeX, VIXFBMode xfbMode, u16 panPosX, u16 panSizeX, u8 *wordPerLine, u8 *std,
                         u8 *wpl, u8 *xof) {
    *wordPerLine = (fbSizeX + 15) / 16;
    *std = (xfbMode == VI_XFBMODE_SF) ? *wordPerLine : (u8)(*wordPerLine * 2);
    *xof = panPosX % 16;
    *wpl = (*xof + panSizeX + 15) / 16;
    regs[VI_HSW] = *std | (*wpl << 8);
    MARK_CHANGED(VI_HSW);
}

static void setBBIntervalRegs(timing_s *tm) {
    u16 val;

    val = tm->bs1 | (tm->be1 << 5);
    regs[VI_BBI_ODD] = val;
    MARK_CHANGED(VI_BBI_ODD);
    val = tm->bs3 | (tm->be3 << 5);
    regs[VI_BBI_ODD_U] = val;
    MARK_CHANGED(VI_BBI_ODD_U);
    val = tm->bs2 | (tm->be2 << 5);
    regs[VI_BBI_EVEN] = val;
    MARK_CHANGED(VI_BBI_EVEN);
    val = tm->bs4 | (tm->be4 << 5);
    regs[VI_BBI_EVEN_U] = val;
    MARK_CHANGED(VI_BBI_EVEN_U);
}

static void setScalingRegs(u16 panSizeX, u16 dispSizeX, BOOL threeD) {
    u32 scale;

    panSizeX = threeD ? (panSizeX << 1) : panSizeX;
    if (panSizeX < dispSizeX) {
        scale = (u32)(dispSizeX + (panSizeX << 8) - 1) / dispSizeX;
        regs[VI_HSR] = scale | 0x1000;
        MARK_CHANGED(VI_HSR);
        regs[VI_WIDTH] = panSizeX;
        MARK_CHANGED(VI_WIDTH);
    } else {
        regs[VI_HSR] = 0x100;
        MARK_CHANGED(VI_HSR);
    }
}

static void calcFbbs(u32 bufAddr, u16 panPosX, u16 panPosY, u8 wordPerLine, VIXFBMode xfbMode, u16 dispPosY,
                     u32 *tfbb, u32 *bfbb) {
    u32 bytesPerLine, xoffInWords;

    xoffInWords = (u32)panPosX / 16;
    bytesPerLine = (u32)wordPerLine * 32;
    *tfbb = bufAddr + xoffInWords * 32 + bytesPerLine * panPosY;
    *bfbb = (xfbMode == VI_XFBMODE_SF) ? *tfbb : (*tfbb + bytesPerLine);
    if (dispPosY % 2 == 1) {
        u32 tmp = *tfbb;
        *tfbb = *bfbb;
        *bfbb = tmp;
    }
    *tfbb = *tfbb & 0x3FFFFFFF;
    *bfbb = *bfbb & 0x3FFFFFFF;
}

static void setFbbRegs(HorVer_s *hv, u32 *tfbb, u32 *bfbb, u32 *rtfbb, u32 *rbfbb) {
    u32 shifted;

    calcFbbs(hv->bufAddr, hv->PanPosX, hv->AdjustedPanPosY, hv->wordPerLine, hv->FBMode, hv->AdjustedDispPosY,
             tfbb, bfbb);
    if (hv->threeD) {
        calcFbbs(hv->rbufAddr, hv->PanPosX, hv->AdjustedPanPosY, hv->wordPerLine, hv->FBMode,
                 hv->AdjustedDispPosY, rtfbb, rbfbb);
    }
    if (IS_LOWER_16MB(*tfbb) && IS_LOWER_16MB(*bfbb) && IS_LOWER_16MB(*rtfbb) && IS_LOWER_16MB(*rbfbb)) {
        shifted = 0;
    } else {
        shifted = 1;
    }
    if (shifted) {
        *tfbb >>= 5;
        *bfbb >>= 5;
        *rtfbb >>= 5;
        *rbfbb >>= 5;
    }

    regs[VI_TOP_FIELD_BASE_LEFT] = *tfbb & 0xFFFF;
    MARK_CHANGED(VI_TOP_FIELD_BASE_LEFT);
    regs[VI_TOP_FIELD_BASE_LEFT_U] = (*tfbb >> 16) | hv->xof << 8 | shifted << 12;
    MARK_CHANGED(VI_TOP_FIELD_BASE_LEFT_U);
    regs[VI_BOTTOM_FIELD_BASE_LEFT] = *bfbb & 0xFFFF;
    MARK_CHANGED(VI_BOTTOM_FIELD_BASE_LEFT);
    regs[VI_BOTTOM_FIELD_BASE_LEFT_U] = *bfbb >> 16;
    MARK_CHANGED(VI_BOTTOM_FIELD_BASE_LEFT_U);
    if (hv->threeD) {
        regs[VI_TOP_FIELD_BASE_RIGHT] = *rtfbb & 0xFFFF;
        MARK_CHANGED(VI_TOP_FIELD_BASE_RIGHT);
        regs[VI_TOP_FIELD_BASE_RIGHT_U] = *rtfbb >> 16;
        MARK_CHANGED(VI_TOP_FIELD_BASE_RIGHT_U);
        regs[VI_BOTTOM_FIELD_BASE_RIGHT] = *rbfbb & 0xFFFF;
        MARK_CHANGED(VI_BOTTOM_FIELD_BASE_RIGHT);
        regs[VI_BOTTOM_FIELD_BASE_RIGHT_U] = *rbfbb >> 16;
        MARK_CHANGED(VI_BOTTOM_FIELD_BASE_RIGHT_U);
    }
}

static void setHorizontalRegs(timing_s *tm, u16 dispPosX, u16 dispSizeX) {
    u32 hbe, hbs, hbeLo, hbeHi;

    regs[VI_HORIZ_TIMING_0L] = tm->hlw;
    MARK_CHANGED(VI_HORIZ_TIMING_0L);
    regs[VI_HORIZ_TIMING_0U] = tm->hce | (tm->hcs << 8);
    MARK_CHANGED(VI_HORIZ_TIMING_0U);
    hbe = tm->hbe640 - 40 + dispPosX;
    hbs = tm->hbs640 + 40 + dispPosX - (720 - dispSizeX);
    hbeLo = hbe & 0x1FF;
    hbeHi = hbe >> 9;
    regs[VI_HORIZ_TIMING_1L] = tm->hsy | (hbeLo << 7);
    MARK_CHANGED(VI_HORIZ_TIMING_1L);
    regs[VI_HORIZ_TIMING_1U] = hbeHi | (hbs << 1);
    MARK_CHANGED(VI_HORIZ_TIMING_1U);
}

static void setVerticalRegs(u16 dispPosY, u16 dispSizeY, u8 equ, u16 acv, u16 prbOdd, u16 prbEven, u16 psbOdd,
                            u16 psbEven, BOOL black) {
    u16 actualPrbOdd, actualPrbEven, actualPsbOdd, actualPsbEven, actualAcv, c, d;

    if (regs[VI_CLK_SEL] & 1) {
        c = 1;
        d = 2;
    } else {
        c = 2;
        d = 1;
    }

    if (dispPosY % 2 == 0) {
        actualPrbOdd = prbOdd + d * dispPosY;
        actualPsbOdd = psbOdd + d * ((c * acv - dispSizeY) - dispPosY);
        actualPrbEven = prbEven + d * dispPosY;
        actualPsbEven = psbEven + d * ((c * acv - dispSizeY) - dispPosY);
    } else {
        actualPrbOdd = prbEven + d * dispPosY;
        actualPsbOdd = psbEven + d * ((c * acv - dispSizeY) - dispPosY);
        actualPrbEven = prbOdd + d * dispPosY;
        actualPsbEven = psbOdd + d * ((c * acv - dispSizeY) - dispPosY);
    }

    actualAcv = dispSizeY / c;

    if (black) {
        actualPrbOdd += 2 * actualAcv - 2;
        actualPsbOdd += 2;
        actualPrbEven += 2 * actualAcv - 2;
        actualPsbEven += 2;
        actualAcv = 0;
    }

    regs[VI_VERT_TIMING] = equ | actualAcv << 4;
    MARK_CHANGED(VI_VERT_TIMING);
    regs[VI_VERT_TIMING_ODD] = (u16)actualPrbOdd << 0;
    MARK_CHANGED(VI_VERT_TIMING_ODD);
    regs[VI_VERT_TIMING_ODD_U] = (u16)actualPsbOdd << 0;
    MARK_CHANGED(VI_VERT_TIMING_ODD_U);
    regs[VI_VERT_TIMING_EVEN] = (u16)actualPrbEven << 0;
    MARK_CHANGED(VI_VERT_TIMING_EVEN);
    regs[VI_VERT_TIMING_EVEN_U] = (u16)actualPsbEven << 0;
    MARK_CHANGED(VI_VERT_TIMING_EVEN_U);
}

static void PrintDebugPalCaution(void) {
    static u32 message = 0;

    if (message == 0) {
        message = 1;
        OSReport("***************************************\n");
        OSReport(" ! ! ! C A U T I O N ! ! !             \n");
        OSReport("This TV format \"DEBUG_PAL\" is only for \n");
        OSReport("temporary solution until PAL DAC board \n");
        OSReport("is available. Please do NOT use this   \n");
        OSReport("mode in real games!!!                  \n");
        OSReport("***************************************\n");
    }
}

void VIConfigure(const GXRenderModeObj *rm) {
    timing_s *tm;
    u32 regDspCfg;
    BOOL enabled;
    u32 newNonInter;
    u32 tvInBootrom;
    u32 tvInGame;

    enabled = OSDisableInterrupts();

    newNonInter = (u32)rm->viTVmode & 3;
    if (HorVer.nonInter != newNonInter) {
        changeMode = 1;
        HorVer.nonInter = newNonInter;
    }

    tvInGame = (u32)rm->viTVmode >> 2;
    tvInBootrom = __OSTVMode;

    if (tvInGame == VI_DEBUG_PAL) {
        PrintDebugPalCaution();
    }

    switch (tvInBootrom) {
    case VI_MPAL:
    case VI_NTSC:
    case VI_GCA:
        if (tvInGame == VI_NTSC || tvInGame == VI_MPAL || tvInGame == VI_GCA) {
            break;
        }
        goto panic; // fzgx-allow: S1 SDK error path
    case VI_PAL:
    case VI_EURGB60:
        if (tvInGame == VI_PAL || tvInGame == VI_EURGB60) {
            break;
        }
    default:
    panic:
        OSPanic("vi.c", 1884, "VIConfigure(): Tried to change mode from (%d) to (%d), which is forbidden\n",
                tvInBootrom, tvInGame);
    }

    if (tvInGame == VI_NTSC || tvInGame == VI_MPAL) {
        HorVer.tv = tvInBootrom;
    } else {
        HorVer.tv = tvInGame;
    }

    HorVer.DispPosX = rm->viXOrigin;
    HorVer.DispPosY = (HorVer.nonInter == VI_NON_INTERLACE) ? (u16)(rm->viYOrigin * 2) : rm->viYOrigin;
    HorVer.DispSizeX = rm->viWidth;
    HorVer.FBSizeX = rm->fbWidth;
    HorVer.FBSizeY = rm->xfbHeight;
    HorVer.FBMode = rm->xFBmode;
    HorVer.PanSizeX = HorVer.FBSizeX;
    HorVer.PanSizeY = HorVer.FBSizeY;
    HorVer.PanPosX = 0;
    HorVer.PanPosY = 0;

    HorVer.DispSizeY = (HorVer.nonInter == VI_PROGRESSIVE)  ? HorVer.PanSizeY
                       : (HorVer.nonInter == VI_3D)         ? HorVer.PanSizeY
                       : (HorVer.FBMode == VI_XFBMODE_SF)   ? (u16)(HorVer.PanSizeY * 2)
                                                            : HorVer.PanSizeY;

    HorVer.threeD = (HorVer.nonInter == VI_3D) ? TRUE : FALSE;

    tm = getTiming((VITVMode)VI_TVMODE(HorVer.tv, HorVer.nonInter));
    HorVer.timing = tm;

    AdjustPosition(tm->acv);

    if (encoderType == 0) {
        HorVer.tv = VI_DEBUG;
    }

    setInterruptRegs(tm);

    regDspCfg = regs[VI_DISP_CONFIG];
    if (HorVer.nonInter == VI_PROGRESSIVE || HorVer.nonInter == VI_3D) {
        regDspCfg = VI_DISP_CONFIG_SET_NIN(regDspCfg, 1);
    } else {
        regDspCfg = VI_DISP_CONFIG_SET_NIN(regDspCfg, HorVer.nonInter & 1);
    }
    regDspCfg = VI_DISP_CONFIG_SET_DLR(regDspCfg, HorVer.threeD);
    if (HorVer.tv == VI_DEBUG_PAL || HorVer.tv == VI_EURGB60 || HorVer.tv == VI_GCA) {
        regDspCfg = VI_DISP_CONFIG_SET_FMT(regDspCfg, 0);
    } else {
        regDspCfg = VI_DISP_CONFIG_SET_FMT(regDspCfg, HorVer.tv);
    }
    regs[VI_DISP_CONFIG] = regDspCfg;
    MARK_CHANGED(VI_DISP_CONFIG);

    regDspCfg = regs[VI_CLK_SEL];
    if (rm->viTVmode == VI_TVMODE_NTSC_PROG || rm->viTVmode == VI_TVMODE_NTSC_3D ||
        rm->viTVmode == VI_TVMODE_GCA_PROG) {
        regDspCfg = VI_CLK_SEL_SET_VICLKSEL(regDspCfg, 1);
    } else {
        regDspCfg = VI_CLK_SEL_SET_VICLKSEL(regDspCfg, 0);
    }
    regs[VI_CLK_SEL] = (u16)regDspCfg;
    MARK_CHANGED(VI_CLK_SEL);

    setScalingRegs(HorVer.PanSizeX, HorVer.DispSizeX, HorVer.threeD);
    setHorizontalRegs(tm, HorVer.AdjustedDispPosX, HorVer.DispSizeX);
    setBBIntervalRegs(tm);
    setPicConfig(HorVer.FBSizeX, HorVer.FBMode, HorVer.PanPosX, HorVer.PanSizeX, &HorVer.wordPerLine, &HorVer.std,
                 &HorVer.wpl, &HorVer.xof);

    if (FBSet) {
        setFbbRegs(&HorVer, &HorVer.tfbb, &HorVer.bfbb, &HorVer.rtfbb, &HorVer.rbfbb);
    }

    setVerticalRegs(HorVer.AdjustedDispPosY, HorVer.AdjustedDispSizeY, tm->equ, tm->acv, tm->prbOdd, tm->prbEven,
                    tm->psbOdd, tm->psbEven, HorVer.black);

    OSRestoreInterrupts(enabled);
}

void VIFlush(void) {
    BOOL enabled;
    s32 regIndex;
    /* Not used by the release build. The retail frame (0x20) has its stack slot. */
    u32 val;

    enabled = OSDisableInterrupts();
    shdwChangeMode |= changeMode;
    changeMode = 0;
    shdwChanged |= changed;
    while (changed) {
        regIndex = cntlzd(changed);
        shdwRegs[regIndex] = regs[regIndex];
        changed &= ~VI_BITMASK(regIndex);
    }
    flushFlag = 1;
    NextBufAddr = HorVer.bufAddr;
    OSRestoreInterrupts(enabled);
}

void VISetNextFrameBuffer(void *fb) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    HorVer.bufAddr = (u32)fb;
    FBSet = 1;
    setFbbRegs(&HorVer, &HorVer.tfbb, &HorVer.bfbb, &HorVer.rtfbb, &HorVer.rbfbb);
    OSRestoreInterrupts(enabled);
}

void VISetBlack(BOOL black) {
    BOOL enabled;
    timing_s *tm;

    enabled = OSDisableInterrupts();
    HorVer.black = black;
    tm = HorVer.timing;
    setVerticalRegs(HorVer.AdjustedDispPosY, HorVer.DispSizeY, tm->equ, tm->acv, tm->prbOdd, tm->prbEven,
                    tm->psbOdd, tm->psbEven, HorVer.black);
    OSRestoreInterrupts(enabled);
}

/* VIGetRetraceCount */
u32 fn_8001BE6C(void) {
    return retraceCount;
}

static u32 getCurrentHalfLine(void) {
    u32 hcount, vcount0, vcount;

    vcount = __VIRegs[VI_VERT_COUNT] & 0x7FF;
    do {
        vcount0 = vcount;
        hcount = __VIRegs[VI_HORIZ_COUNT] & 0x7FF;
        vcount = __VIRegs[VI_VERT_COUNT] & 0x7FF;
    } while (vcount0 != vcount);

    return ((vcount - 1) << 1) + ((hcount - 1) / CurrTiming->hlw);
}

static u32 getCurrentFieldEvenOdd(void) {
    return (getCurrentHalfLine() < CurrTiming->nhlines) ? 1 : 0;
}

u32 VIGetNextField(void) {
    s32 nextField;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    nextField = getCurrentFieldEvenOdd() ^ 1;
    OSRestoreInterrupts(enabled);
    return nextField ^ (HorVer.AdjustedDispPosY & 1);
}

u32 VIGetCurrentLine(void) {
    u32 halfLine;
    timing_s *tm;
    BOOL enabled;

    tm = CurrTiming;
    enabled = OSDisableInterrupts();
    halfLine = getCurrentHalfLine();
    OSRestoreInterrupts(enabled);

    if (halfLine >= tm->nhlines) {
        halfLine -= tm->nhlines;
    }

    return halfLine >> 1;
}

u32 VIGetTvFormat(void) {
    u32 format;
    BOOL enabled;

    enabled = OSDisableInterrupts();

    switch (CurrTvMode) {
    case VI_NTSC:
    case VI_DEBUG:
    case VI_GCA:
        format = VI_NTSC;
        break;
    case VI_PAL:
    case VI_DEBUG_PAL:
        format = VI_PAL;
        break;
    case VI_EURGB60:
    case VI_MPAL:
        format = CurrTvMode;
        break;
    }

    OSRestoreInterrupts(enabled);
    return format;
}

u32 VIGetDTVStatus(void) {
    u32 dtvStatus;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    dtvStatus = __VIRegs[VI_DTV_STAT] & 3;
    OSRestoreInterrupts(enabled);
    return dtvStatus & 1;
}
