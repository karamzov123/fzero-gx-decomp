#include <types.h>
#include <dolphin/os.h>
#include <dolphin/os/OSInterrupt.h>

typedef struct _GXRenderModeObj GXRenderModeObj;

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
    u8 antialiasing;
    u8 sample_pattern[12][2];
    u8 vfilter[7];
} GXRenderModeObj;

typedef struct {
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
} VITiming;

typedef struct {
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
    VITiming *timing;
} SomeVIStruct;

void OSReport(const char *fmt, ...);

extern u32 lbl_801A693C;

extern s16 lbl_801A6940;

extern s16 lbl_801A6942;

extern volatile u32 lbl_801A6944; // fzgx-allow: S2 SDK asynchronous state

extern volatile u64 lbl_801A6948; // fzgx-allow: S2 SDK asynchronous state

extern u32 lbl_801A6970;
extern u32 lbl_801A6974;

void (*__VIDisableRawPositionInterrupt())(s16, s16);

VITiming *getTiming(VITVMode mode);

static unsigned char fzgx_pool_vi_prefix[500] = {
60, 60, 32, 68, 111, 108, 112, 104, 105, 110, 32, 83, 68, 75, 32, 45, 32, 86, 73, 9,
114, 101, 108, 101, 97, 115, 101, 32, 98, 117, 105, 108, 100, 58, 32, 83, 101, 112, 32, 32,
53, 32, 50, 48, 48, 50, 32, 48, 53, 58, 51, 51, 58, 49, 51, 32, 40, 48, 120, 50,
51, 48, 49, 41, 32, 62, 62, 0, 6, 0, 0, 240, 0, 24, 0, 25, 0, 3, 0, 2,
12, 13, 12, 13, 2, 8, 2, 7, 2, 8, 2, 7, 2, 13, 1, 173, 64, 71, 105, 162,
1, 117, 122, 0, 1, 156, 6, 0, 0, 240, 0, 24, 0, 24, 0, 4, 0, 4, 12, 12,
12, 12, 2, 8, 2, 8, 2, 8, 2, 8, 2, 14, 1, 173, 64, 71, 105, 162, 1, 117,
122, 0, 1, 156, 5, 0, 1, 31, 0, 35, 0, 36, 0, 1, 0, 0, 13, 12, 11, 10,
2, 107, 2, 106, 2, 105, 2, 108, 2, 113, 1, 176, 64, 75, 106, 172, 1, 124, 133, 0,
1, 164, 5, 0, 1, 31, 0, 33, 0, 33, 0, 2, 0, 2, 13, 11, 13, 11, 2, 107,
2, 109, 2, 107, 2, 109, 2, 112, 1, 176, 64, 75, 106, 172, 1, 124, 133, 0, 1, 164,
6, 0, 0, 240, 0, 24, 0, 25, 0, 3, 0, 2, 16, 15, 14, 13, 2, 6, 2, 5,
2, 4, 2, 7, 2, 13, 1, 173, 64, 78, 112, 162, 1, 117, 122, 0, 1, 156, 6, 0,
0, 240, 0, 24, 0, 24, 0, 4, 0, 4, 16, 14, 16, 14, 2, 6, 2, 8, 2, 6,
2, 8, 2, 14, 1, 173, 64, 78, 112, 162, 1, 117, 122, 0, 1, 156, 12, 0, 1, 224,
0, 48, 0, 48, 0, 6, 0, 6, 24, 24, 24, 24, 4, 14, 4, 14, 4, 14, 4, 14,
4, 26, 1, 173, 64, 71, 105, 162, 1, 117, 122, 0, 1, 156, 12, 0, 1, 224, 0, 44,
0, 44, 0, 10, 0, 10, 24, 24, 24, 24, 4, 14, 4, 14, 4, 14, 4, 14, 4, 26,
1, 173, 64, 71, 105, 168, 1, 123, 122, 0, 1, 156, 6, 0, 0, 241, 0, 24, 0, 25,
0, 1, 0, 0, 12, 13, 12, 13, 2, 8, 2, 7, 2, 8, 2, 7, 2, 13, 1, 173,
64, 71, 105, 159, 1, 114, 122, 0, 1, 156, 12, 0, 1, 224, 0, 48, 0, 48, 0, 6,
0, 6, 24, 24, 24, 24, 4, 14, 4, 14, 4, 14, 4, 14, 4, 26, 1, 173, 64, 71,
105, 180, 1, 135, 122, 0, 1, 156, 1, 240, 1, 220, 1, 174, 1, 116, 1, 41, 0, 219,
0, 142, 0, 70, 0, 12, 0, 226, 0, 203, 0, 192, 0, 196, 0, 207, 0, 222, 0, 236,
0, 252, 0, 8, 0, 15, 0, 19, 0, 19, 0, 15, 0, 12, 0, 8, 0, 1, 0, 0
};
static void *fzgx_pool_vi_timing_switch[27] = {
    (u8 *)getTiming + 40,
    (u8 *)getTiming + 48,
    (u8 *)getTiming + 104,
    (u8 *)getTiming + 112,
    (u8 *)getTiming + 56,
    (u8 *)getTiming + 64,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 88,
    (u8 *)getTiming + 96,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 120,
    (u8 *)getTiming + 128,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 72,
    (u8 *)getTiming + 80,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 136,
    (u8 *)getTiming + 152,
    (u8 *)getTiming + 144
};

static volatile u16 lbl_8015CF68[59]; // fzgx-allow: S2 SDK asynchronous state

static unsigned char lbl_8015CF68__fzgx_offset_78[118];

static SomeVIStruct lbl_8015D058__fzgx_offset_0;

#pragma section code_type ".fzgxpool"
static void sdk_layout____bss_0(void) {
    volatile unsigned char sink; // fzgx-allow: S2 SDK asynchronous state
    sink = *(unsigned char *)&lbl_8015CF68;
    sink = *(unsigned char *)&lbl_8015CF68__fzgx_offset_78;
    sink = *(unsigned char *)&lbl_8015D058__fzgx_offset_0;
}
#pragma section code_type ".text"

static inline void AdjustPosition(u16 acv) {
    s32 coeff;
    s32 frac;
    lbl_8015D058__fzgx_offset_0.AdjustedDispPosX =
        (((s16)lbl_8015D058__fzgx_offset_0.DispPosX + lbl_801A6940) > (0x2D0 - lbl_8015D058__fzgx_offset_0.DispSizeX)
             ? (0x2D0 - lbl_8015D058__fzgx_offset_0.DispSizeX)
         : ((s16)lbl_8015D058__fzgx_offset_0.DispPosX + lbl_801A6940) < (0) ? (0)
                                                       : ((s16)lbl_8015D058__fzgx_offset_0.DispPosX + lbl_801A6940));
    coeff = (lbl_8015D058__fzgx_offset_0.FBMode == VI_XFBMODE_SF) ? 2 : 1;
    frac = lbl_8015D058__fzgx_offset_0.DispPosY & 1;
    lbl_8015D058__fzgx_offset_0.AdjustedDispPosY =
        (((s16)lbl_8015D058__fzgx_offset_0.DispPosY + lbl_801A6942) > (frac) ? ((s16)lbl_8015D058__fzgx_offset_0.DispPosY + lbl_801A6942)
                                                        : (frac));
    lbl_8015D058__fzgx_offset_0.AdjustedDispSizeY = lbl_8015D058__fzgx_offset_0.DispSizeY +
                               (((s16)lbl_8015D058__fzgx_offset_0.DispPosY + lbl_801A6942 - frac) < (0)
                                    ? ((s16)lbl_8015D058__fzgx_offset_0.DispPosY + lbl_801A6942 - frac)
                                    : (0)) -
                               (((s16)lbl_8015D058__fzgx_offset_0.DispPosY + (s16)lbl_8015D058__fzgx_offset_0.DispSizeY + lbl_801A6942 -
                                 (((s16)acv * 2) - frac)) > (0)
                                    ? ((s16)lbl_8015D058__fzgx_offset_0.DispPosY + (s16)lbl_8015D058__fzgx_offset_0.DispSizeY + lbl_801A6942 -
                                       (((s16)acv * 2) - frac))
                                    : (0));
    lbl_8015D058__fzgx_offset_0.AdjustedPanPosY = lbl_8015D058__fzgx_offset_0.PanPosY - ((((s16)lbl_8015D058__fzgx_offset_0.DispPosY + lbl_801A6942 - frac) < (0)
                                                    ? ((s16)lbl_8015D058__fzgx_offset_0.DispPosY + lbl_801A6942 - frac)
                                                    : (0)) /
                                               coeff);
    lbl_8015D058__fzgx_offset_0.AdjustedPanSizeY = lbl_8015D058__fzgx_offset_0.PanSizeY +
                              ((((s16)lbl_8015D058__fzgx_offset_0.DispPosY + lbl_801A6942 - frac) < (0)
                                    ? ((s16)lbl_8015D058__fzgx_offset_0.DispPosY + lbl_801A6942 - frac)
                                    : (0)) /
                               coeff) -
                              ((((s16)lbl_8015D058__fzgx_offset_0.DispPosY + (s16)lbl_8015D058__fzgx_offset_0.DispSizeY + lbl_801A6942 -
                                 (((s16)acv * 2) - frac)) > (0)
                                    ? ((s16)lbl_8015D058__fzgx_offset_0.DispPosY + (s16)lbl_8015D058__fzgx_offset_0.DispSizeY + lbl_801A6942 -
                                       (((s16)acv * 2) - frac))
                                    : (0)) /
                               coeff);
}

static inline void setInterruptRegs(VITiming *tm) {
    u16 hct, vct;
    u16 borrow;
    vct = tm->nhlines / 2;
    borrow = tm->nhlines % 2;
    if (borrow != 0) {
        hct = tm->hlw;
    } else {
        hct = 0;
    }
    vct++;
    hct++;
    lbl_8015CF68[25] = (u16)(u32)hct;
    (lbl_801A6948 |= 1LL << (63 - (25)));
    lbl_8015CF68[24] = vct | 0x1000;
    (lbl_801A6948 |= 1LL << (63 - (24)));
    vct;
}

static inline void setPicConfig(u16 fbSizeX, VIXFBMode xfbMode, u16 panPosX, u16 panSizeX,
                                u8 *wordPerLine, u8 *std, u8 *wpl, u8 *xof) {
    *wordPerLine = (fbSizeX + 15) / 16;
    *std = (xfbMode == VI_XFBMODE_SF) ? *wordPerLine : (u8)(*wordPerLine * 2);
    *xof = panPosX % 16;
    *wpl = (*xof + panSizeX + 15) / 16;
    lbl_8015CF68[0x24] = *std | (*wpl << 8);
    lbl_801A6948 |= 0x8000000;
}

static inline void setBBIntervalRegs(VITiming *tm) {
    u16 val;
    val = tm->bs1 | (tm->be1 << 5);
    lbl_8015CF68[11] = val;
    lbl_801A6948 |= 0x10000000000000;
    val = tm->bs3 | (tm->be3 << 5);
    lbl_8015CF68[10] = val;
    lbl_801A6948 |= 0x20000000000000;
    val = tm->bs2 | (tm->be2 << 5);
    lbl_8015CF68[13] = val;
    lbl_801A6948 |= 0x4000000000000;
    val = tm->bs4 | (tm->be4 << 5);
    lbl_8015CF68[12] = val;
    lbl_801A6948 |= (1LL << (63 - 12));
}

static inline void setScalingRegs(u16 panSizeX, u16 dispSizeX, BOOL threeD) {
    u32 scale;
    panSizeX = threeD ? (panSizeX << 1) : panSizeX;
    if (panSizeX < dispSizeX) {
        scale = (u32)(dispSizeX + (panSizeX << 8) - 1) / dispSizeX;
        lbl_8015CF68[37] = scale | 0x1000;
        lbl_801A6948 |= 0x04000000;
        lbl_8015CF68[56] = (u32)panSizeX;
        lbl_801A6948 |= 0x80;
    } else {
        lbl_8015CF68[37] = 0x100;
        lbl_801A6948 |= 0x04000000;
    }
}

void setFbbRegs(SomeVIStruct *lbl_8015D058__fzgx_offset_0, u32 *tfbb, u32 *bfbb, u32 *rtfbb, u32 *rbfbb);

static inline void setHorizontalRegs(VITiming *tm, u16 dispPosX, u16 dispSizeX) {
    u32 hbe;
    u32 hbs;
    u32 hbeLo;
    u32 hbeHi;
    lbl_8015CF68[3] = (u16)(u32)tm->hlw;
    (lbl_801A6948 |= 1LL << (63 - (3)));
    lbl_8015CF68[2] = tm->hce | (tm->hcs << 8);
    (lbl_801A6948 |= 1LL << (63 - (2)));
    hbe = tm->hbe640 - 40 + dispPosX;
    hbs = tm->hbs640 + 40 + dispPosX - (720 - dispSizeX);
    hbeLo = hbe & 0x1FF;
    hbeHi = hbe >> 9;
    lbl_8015CF68[5] = tm->hsy | (hbeLo << 7);
    (lbl_801A6948 |= 1LL << (63 - (5)));
    lbl_8015CF68[4] = hbeHi | (hbs * 2);
    (lbl_801A6948 |= 1LL << (63 - (4)));
}

void setVerticalRegs(u16 dispPosY, u16 dispSizeY, u8 equ, u16 acv, u16 prbOdd, u16 prbEven,
                     u16 psbOdd, u16 psbEven, BOOL black);

static inline void PrintDebugPalCaution(void) {
    if (lbl_801A6974 == 0) {
        lbl_801A6974 = 1;
        OSReport("***************************************\n");
        OSReport(" ! ! ! C A U T I O N ! ! !             \n");
        OSReport("This TV format \"DEBUG_PAL\" is only for \n");
        OSReport("temporary solution until PAL DAC board \n");
        OSReport("is available. Please do NOT use this   \n");
        OSReport("mode in real games!!!                  \n");
        OSReport("***************************************\n");
    }
}

#pragma opt_strength_reduction off
void VIConfigure(GXRenderModeObj *rm) {
    VITiming *tm;
    u32 regDspCfg;
    BOOL enabled;
    u32 newNonInter;
    u32 tvInBootrom;
    u32 tvInGame;
    enabled = OSDisableInterrupts();
    newNonInter = rm->viTVmode;
    newNonInter = newNonInter & 3;
    if (lbl_8015D058__fzgx_offset_0.nonInter != newNonInter) {
        lbl_801A6944 = 1;
        lbl_8015D058__fzgx_offset_0.nonInter = newNonInter;
    }
    (void)0;
    tvInGame = (u32)rm->viTVmode >> 2;
    tvInBootrom = *(u32 *)((void *)((u32)(0xCC) + (0x8000 << 16)));
    if (tvInGame == (4)) {
        PrintDebugPalCaution();
    }
    switch (tvInBootrom) {
    case (2):
    case (0):
    case (6):
        if (tvInGame == (0) || tvInGame == (2) || tvInGame == (6)) {
            break;
        }
        goto panic; // fzgx-allow: S1 SDK error cleanup path
    case (1):
    case (5):
        if (tvInGame == (1) || tvInGame == (5)) {
            break;
        }
    default:
    panic:
        OSPanic("vi.c", 1884,
                "VIConfigure(): Tried to change mode from (%d) to (%d), which is forbidden\n",
                tvInBootrom, tvInGame);
    }
    if ((tvInGame == (0)) || (tvInGame == (2))) {
        lbl_8015D058__fzgx_offset_0.tv = tvInBootrom;
    } else {
        lbl_8015D058__fzgx_offset_0.tv = tvInGame;
    }
    lbl_8015D058__fzgx_offset_0.DispPosX = rm->viXOrigin;
    lbl_8015D058__fzgx_offset_0.DispPosY = (lbl_8015D058__fzgx_offset_0.nonInter == 1) ? (u16)(rm->viYOrigin * 2) : rm->viYOrigin;
    lbl_8015D058__fzgx_offset_0.DispSizeX = rm->viWidth;
    lbl_8015D058__fzgx_offset_0.FBSizeX = rm->fbWidth;
    lbl_8015D058__fzgx_offset_0.FBSizeY = rm->xfbHeight;
    lbl_8015D058__fzgx_offset_0.FBMode = rm->xFBmode;
    lbl_8015D058__fzgx_offset_0.PanSizeX = lbl_8015D058__fzgx_offset_0.FBSizeX;
    lbl_8015D058__fzgx_offset_0.PanSizeY = lbl_8015D058__fzgx_offset_0.FBSizeY;
    lbl_8015D058__fzgx_offset_0.PanPosX = 0;
    lbl_8015D058__fzgx_offset_0.PanPosY = 0;
    lbl_8015D058__fzgx_offset_0.DispSizeY = (lbl_8015D058__fzgx_offset_0.nonInter == 2)             ? lbl_8015D058__fzgx_offset_0.PanSizeY
                       : (lbl_8015D058__fzgx_offset_0.nonInter == 3)           ? lbl_8015D058__fzgx_offset_0.PanSizeY
                       : (lbl_8015D058__fzgx_offset_0.FBMode == VI_XFBMODE_SF) ? (u16)(lbl_8015D058__fzgx_offset_0.PanSizeY * 2)
                                                          : lbl_8015D058__fzgx_offset_0.PanSizeY;
    lbl_8015D058__fzgx_offset_0.threeD = (lbl_8015D058__fzgx_offset_0.nonInter == 3) ? 1 : 0;
    tm = getTiming((lbl_8015D058__fzgx_offset_0.tv << 2) + lbl_8015D058__fzgx_offset_0.nonInter);
    lbl_8015D058__fzgx_offset_0.timing = tm;
    AdjustPosition(tm->acv);
    (void)0;
    (void)0;
    if (lbl_801A693C == 0) {
        lbl_8015D058__fzgx_offset_0.tv = 3;
    }
    setInterruptRegs(tm);
    regDspCfg = (*((1) + (lbl_8015CF68)));
    if ((lbl_8015D058__fzgx_offset_0.nonInter == (2)) || (lbl_8015D058__fzgx_offset_0.nonInter == (3))) {
        regDspCfg = (((u32)(regDspCfg)) & ~0x00000004) | (((u32)(1)) << 2);
    } else {
        regDspCfg = (((u32)(regDspCfg)) & ~0x00000004) | (((u32)(lbl_8015D058__fzgx_offset_0.nonInter & 1)) << 2);
    }
    regDspCfg = (((u32)(regDspCfg)) & ~0x00000008) | (((u32)(lbl_8015D058__fzgx_offset_0.threeD)) << 3);
    if ((lbl_8015D058__fzgx_offset_0.tv == (4)) || (lbl_8015D058__fzgx_offset_0.tv == (5)) || (lbl_8015D058__fzgx_offset_0.tv == (6))) {
        regDspCfg = (((u32)(regDspCfg)) & ~0x00000300) | (((u32)(0)) << 8);
    } else {
        regDspCfg = (((u32)(regDspCfg)) & ~0x00000300) | (((u32)(lbl_8015D058__fzgx_offset_0.tv)) << 8);
    }
    lbl_8015CF68[1] = regDspCfg;
    (lbl_801A6948 |= 1LL << (63 - (1)));
    regDspCfg = (*((54) + (lbl_8015CF68)));
    if (rm->viTVmode == VI_TVMODE_NTSC_PROG || rm->viTVmode == VI_TVMODE_NTSC_3D ||
        rm->viTVmode == VI_TVMODE_GCA_PROG) {
        regDspCfg = (u32)(regDspCfg & ~0x1) | 1;
    } else {
        regDspCfg = (u32)(regDspCfg & ~0x1);
    }
    lbl_8015CF68[54] = (u16)regDspCfg;
    (lbl_801A6948 |= 1LL << (63 - (54)));
    setScalingRegs(lbl_8015D058__fzgx_offset_0.PanSizeX, lbl_8015D058__fzgx_offset_0.DispSizeX, lbl_8015D058__fzgx_offset_0.threeD);
    setHorizontalRegs(tm, lbl_8015D058__fzgx_offset_0.AdjustedDispPosX, lbl_8015D058__fzgx_offset_0.DispSizeX);
    setBBIntervalRegs(tm);
    setPicConfig(lbl_8015D058__fzgx_offset_0.FBSizeX, lbl_8015D058__fzgx_offset_0.FBMode, lbl_8015D058__fzgx_offset_0.PanPosX, lbl_8015D058__fzgx_offset_0.PanSizeX,
                 &lbl_8015D058__fzgx_offset_0.wordPerLine, &lbl_8015D058__fzgx_offset_0.std, &lbl_8015D058__fzgx_offset_0.wpl, &lbl_8015D058__fzgx_offset_0.xof);
    if (lbl_801A6970 != 0) {
        setFbbRegs(&lbl_8015D058__fzgx_offset_0, &lbl_8015D058__fzgx_offset_0.tfbb, &lbl_8015D058__fzgx_offset_0.bfbb, &lbl_8015D058__fzgx_offset_0.rtfbb, &lbl_8015D058__fzgx_offset_0.rbfbb);
    }
    setVerticalRegs(lbl_8015D058__fzgx_offset_0.AdjustedDispPosY, lbl_8015D058__fzgx_offset_0.AdjustedDispSizeY, tm->equ, tm->acv, tm->prbOdd,
                    tm->prbEven, tm->psbOdd, tm->psbEven, lbl_8015D058__fzgx_offset_0.black);
    OSRestoreInterrupts(enabled);
}
#pragma opt_strength_reduction reset

