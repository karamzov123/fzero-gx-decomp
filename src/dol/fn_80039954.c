#include "types.h"
#pragma scheduling off

/* GXReadGPMetric: reads the four CP performance counters. */

struct fn_80039954_gx_T {
    u8 pad_0[0x4E4];
    u32 perf0;
    u32 perf1;
};

/* CP registers are hardware: reads must not be merged (volatile). */
extern u16 *__cpReg;
/* volatile: each hardware counter read must reach the CP registers. */
#define GX_GET_CP_REG(reg) (*(volatile u16 *)((u8 *)__cpReg + (reg) * 2))
extern struct fn_80039954_gx_T *gx;

static inline u32 __GXReadCPCounterU32(u32 regAddrL, u32 regAddrH) {
    u32 ctrH0;
    u32 ctrH1;
    u32 ctrL;

    ctrH0 = GX_GET_CP_REG(regAddrH);
    do {
        ctrH1 = ctrH0;
        ctrL = GX_GET_CP_REG(regAddrL);
        ctrH0 = GX_GET_CP_REG(regAddrH);
    } while (ctrH0 != ctrH1);
    return (ctrH0 << 16) | ctrL;
}

void fn_80039954(u32 *cnt0, u32 *cnt1) {
    u32 cpCtr0;
    u32 cpCtr1;
    u32 cpCtr2;
    u32 cpCtr3;

    cpCtr0 = __GXReadCPCounterU32(32, 33);
    cpCtr1 = __GXReadCPCounterU32(34, 35);
    cpCtr2 = __GXReadCPCounterU32(36, 37);
    cpCtr3 = __GXReadCPCounterU32(38, 39);

    switch (gx->perf0) {
    case 10:
        *cnt0 = cpCtr1 * 1000 / cpCtr0;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
        *cnt0 = cpCtr0;
        break;
    case 35:
        *cnt0 = 0;
        break;
    default:
        *cnt0 = 0;
        break;
    }

    switch (gx->perf1) {
    case 0:
        *cnt1 = cpCtr3 * 4;
        break;
    case 4:
        *cnt1 = cpCtr2 + cpCtr3 * 2;
        break;
    case 5:
        *cnt1 = cpCtr2 * 3 + cpCtr3 * 4;
        break;
    case 6:
        *cnt1 = cpCtr2 * 5 + cpCtr3 * 6;
        break;
    case 7:
        *cnt1 = cpCtr2 * 7 + cpCtr3 * 8;
        break;
    case 1:
    case 2:
    case 3:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 21:
        *cnt1 = cpCtr3;
        break;
    case 17:
    case 18:
    case 19:
    case 20:
        *cnt1 = cpCtr2;
        break;
    case 22:
        *cnt1 = 0;
        break;
    default:
        *cnt1 = 0;
        break;
    }
}
