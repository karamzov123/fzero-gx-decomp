
#include "types.h"

// Hardware or OS state can change asynchronously.
typedef volatile u16 vu16;

// Hardware or OS state can change asynchronously.
typedef volatile u32 vu32;

// Hardware or OS state can change asynchronously.
typedef volatile u64 vu64;

typedef enum { VI_XFBMODE_SF = 0, VI_XFBMODE_DF } VIXFBMode;

typedef struct VITimingInfo {
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
    u16 numHalfLines;
    u16 hlw;
    u8 hsy;
    u8 hcs;
    u8 hce;
    u8 hbe640;
    u16 hbs640;
    u8 hbeCCIR656;
    u16 hbsCCIR656;
} VITimingInfo;

typedef struct VIPositionInfo {
    u16 dispPosX;
    u16 dispPosY;
    u16 dispSizeX;
    u16 dispSizeY;
    u16 adjDispPosX;
    u16 adjDispPosY;
    u16 adjDispSizeY;
    u16 adjPanPosY;
    u16 adjPanSizeY;
    u16 fbSizeX;
    u16 fbSizeY;
    u16 panPosX;
    u16 panPosY;
    u16 panSizeX;
    u16 panSizeY;
    VIXFBMode xfbMode;
    u32 nonInter;
    u32 tv;
    u8 wordPerLine;
    u8 std;
    u8 wpl;
    u32 bufAddr;
    u32 tfbb;
    u32 bfbb;
    u8 xof;
    BOOL isBlack;
    BOOL is3D;
    u32 rbufAddr;
    u32 rtfbb;
    u32 rbfbb;
    VITimingInfo *timing;
} VIPositionInfo;

void VIFlush(void);

BOOL OSDisableInterrupts(void);

BOOL OSRestoreInterrupts(BOOL level);

extern u32 lbl_801A6928;

extern vu32 lbl_801A6944;

extern vu64 lbl_801A6948;

extern vu32 lbl_801A6950;

extern vu64 lbl_801A6958;

extern u32 lbl_801A6968;

extern VITimingInfo timing[10];

struct viBss {
    u16 regs[59];
    unsigned char padding_118[2];
    u16 shdwRegs[59];
    unsigned char padding_238[2];
    VIPositionInfo HorVer;
};
extern struct viBss lbl_8015CF68;

static inline int cntlzd(u64 bit) {
    s32 hi;
    u32 lo;
    hi = (u32)(bit >> 32);
    lo = (u32)(bit & 0xFFFFFFFF);
    hi = __cntlzw(hi);
    if (hi < 32) {
        return hi;
    }
    return (32 + __cntlzw(lo));
}

#pragma opt_lifetimes off
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
void VIFlush(void) {
    struct viBss *bss = &lbl_8015CF68;
    s32 regIndex;
    u32 val;
    BOOL enabled;
    enabled = OSDisableInterrupts();
    lbl_801A6950 |= lbl_801A6944;
    lbl_801A6944 = 0;
    lbl_801A6958 |= lbl_801A6948;
    while (lbl_801A6948) {
        regIndex = cntlzd(lbl_801A6948);
        (bss->shdwRegs)[regIndex] = ((u16 *)bss)[regIndex];
        lbl_801A6948 &= ~(1ull << (63 - (regIndex)));
    }
    lbl_801A6928 = 1;
    lbl_801A6968 = (bss->HorVer).bufAddr;
    OSRestoreInterrupts(enabled);
}
#pragma opt_loop_invariants reset

#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset

