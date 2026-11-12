#include <dolphin/si/SIPriv.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/si.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma dont_inline on

typedef struct XY {
    u16 line;
    u8 count;
} XY;

u32 VIGetTvFormat();

void OSReport(const char *msg, ...);

vu16 __VIRegs[59] : FZGX_ADDR___VIRegs;

extern u32 SamplingRate;

static XY fzgx_pool_XYNTSC[12] = {
    {263 - 17, 2}, {15, 18}, {30, 9}, {44, 6},  {52, 5},  {65, 4},
    {87, 3},       {87, 3},  {87, 3}, {131, 2}, {131, 2}, {131, 2},
};

static XY fzgx_pool_XYPAL[12] = {
    {313 - 17, 2}, {15, 21}, {29, 11}, {45, 7},  {52, 6},  {63, 5},
    {78, 4},       {104, 3}, {104, 3}, {104, 3}, {104, 3}, {156, 2},
};

void SISetSamplingRate(u32 msec) {
    XY *xy;
    BOOL enabled;
    if (msec > 11) {
        msec = 11;
    }
    enabled = OSDisableInterrupts();
    SamplingRate = msec;
    switch (VIGetTvFormat()) {
    case 0:
    case 2:
    case 5:
        xy = fzgx_pool_XYNTSC;
        break;
    case 1:
        xy = fzgx_pool_XYPAL;
        break;
    default:
        OSReport("SISetSamplingRate: unknown TV format. Use default.");
        msec = 0;
        xy = fzgx_pool_XYNTSC;
        break;
    }
    SISetXY((__VIRegs[54] & 1 ? 2u : 1u) * xy[msec].line, xy[msec].count);
    OSRestoreInterrupts(enabled);
}
