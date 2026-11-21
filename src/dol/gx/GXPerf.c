#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include "sdk_addresses.h"
#include "types.h"
#include "dolphin/hw_regs.h"
#include <types.h>
#include <dolphin/types.h>

void GXSetGPMetric(GXPerf0 perf0, GXPerf1 perf1);

// The CP registers are memory-mapped hardware and must not be cached.
extern volatile u16 *__cpReg;

void GXSetGPMetric(GXPerf0 perf0, GXPerf1 perf1) {
    switch (gx->perf0) {
    case GX_PERF0_VERTICES:
    case GX_PERF0_CLIP_VTX:
    case GX_PERF0_CLIP_CLKS:
    case GX_PERF0_XF_WAIT_IN:
    case GX_PERF0_XF_WAIT_OUT:
    case GX_PERF0_XF_XFRM_CLKS:
    case GX_PERF0_XF_LIT_CLKS:
    case GX_PERF0_XF_BOT_CLKS:
    case GX_PERF0_XF_REGLD_CLKS:
    case GX_PERF0_XF_REGRD_CLKS:
    case GX_PERF0_CLIP_RATIO:
    case GX_PERF0_CLOCKS:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0;
        break;
    case GX_PERF0_TRIANGLES:
    case GX_PERF0_TRIANGLES_CULLED:
    case GX_PERF0_TRIANGLES_PASSED:
    case GX_PERF0_TRIANGLES_SCISSORED:
    case GX_PERF0_TRIANGLES_0TEX:
    case GX_PERF0_TRIANGLES_1TEX:
    case GX_PERF0_TRIANGLES_2TEX:
    case GX_PERF0_TRIANGLES_3TEX:
    case GX_PERF0_TRIANGLES_4TEX:
    case GX_PERF0_TRIANGLES_5TEX:
    case GX_PERF0_TRIANGLES_6TEX:
    case GX_PERF0_TRIANGLES_7TEX:
    case GX_PERF0_TRIANGLES_8TEX:
    case GX_PERF0_TRIANGLES_0CLR:
    case GX_PERF0_TRIANGLES_1CLR:
    case GX_PERF0_TRIANGLES_2CLR:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x23000000);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_0CVG:
    case GX_PERF0_QUAD_NON0CVG:
    case GX_PERF0_QUAD_1CVG:
    case GX_PERF0_QUAD_2CVG:
    case GX_PERF0_QUAD_3CVG:
    case GX_PERF0_QUAD_4CVG:
    case GX_PERF0_AVG_QUAD_CNT:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x24000000);
            ;
        } while (0);
        break;
    case GX_PERF0_NONE:
        break;
    }
    switch (gx->perf1) {
    case GX_PERF1_TEXELS:
    case GX_PERF1_TX_IDLE:
    case GX_PERF1_TX_REGS:
    case GX_PERF1_TX_MEMSTALL:
    case GX_PERF1_TC_CHECK1_2:
    case GX_PERF1_TC_CHECK3_4:
    case GX_PERF1_TC_CHECK5_6:
    case GX_PERF1_TC_CHECK7_8:
    case GX_PERF1_TC_MISS:
    case GX_PERF1_CLOCKS:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x67000000);
            ;
        } while (0);
        break;
    case GX_PERF1_VC_ELEMQ_FULL:
    case GX_PERF1_VC_MISSQ_FULL:
    case GX_PERF1_VC_MEMREQ_FULL:
    case GX_PERF1_VC_STATUS7:
    case GX_PERF1_VC_MISSREP_FULL:
    case GX_PERF1_VC_STREAMBUF_LOW:
    case GX_PERF1_VC_ALL_STALLS:
    case GX_PERF1_VERTICES:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(0) << (4));
        ;
        GXWGFifo.u8 = 8;
        GXWGFifo.u8 = 32;
        GXWGFifo.u32 = gx->perfSel;
        break;
    case GX_PERF1_FIFO_REQ:
    case GX_PERF1_CALL_REQ:
    case GX_PERF1_VC_MISS_REQ:
    case GX_PERF1_CP_ALL_REQ:
        (*(vu16 *)((vu16 *)(__cpReg) + (3)) = 0);
        break;
    case GX_PERF1_NONE:
        break;
    }
    gx->perf0 = perf0;
    switch (gx->perf0) {
    case GX_PERF0_VERTICES:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0x273;
        break;
    case GX_PERF0_CLIP_VTX:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0x14A;
        break;
    case GX_PERF0_CLIP_CLKS:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0x16B;
        break;
    case GX_PERF0_XF_WAIT_IN:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0x84;
        break;
    case GX_PERF0_XF_WAIT_OUT:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0xC6;
        break;
    case GX_PERF0_XF_XFRM_CLKS:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0x210;
        break;
    case GX_PERF0_XF_LIT_CLKS:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0x252;
        break;
    case GX_PERF0_XF_BOT_CLKS:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0x231;
        break;
    case GX_PERF0_XF_REGLD_CLKS:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0x1AD;
        break;
    case GX_PERF0_XF_REGRD_CLKS:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0x1CE;
        break;
    case GX_PERF0_CLOCKS:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0x21;
        break;
    case GX_PERF0_CLIP_RATIO:
        GXWGFifo.u8 = 0x10;
        GXWGFifo.u32 = 0x1006;
        GXWGFifo.u32 = 0x153;
        break;
    case GX_PERF0_TRIANGLES:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300AE7F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_CULLED:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x23008E7F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_PASSED:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x23009E7F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_SCISSORED:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x23001E7F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_0TEX:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300AC3F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_1TEX:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300AC7F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_2TEX:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300ACBF);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_3TEX:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300ACFF);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_4TEX:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300AD3F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_5TEX:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300AD7F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_6TEX:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300ADBF);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_7TEX:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300ADFF);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_8TEX:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300AE3F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_0CLR:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300A27F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_1CLR:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300A67F);
            ;
        } while (0);
        break;
    case GX_PERF0_TRIANGLES_2CLR:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2300AA7F);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_0CVG:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2402C0C6);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_NON0CVG:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2402C16B);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_1CVG:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2402C0E7);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_2CVG:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2402C108);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_3CVG:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2402C129);
            ;
        } while (0);
        break;
    case GX_PERF0_QUAD_4CVG:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2402C14A);
            ;
        } while (0);
        break;
    case GX_PERF0_AVG_QUAD_CNT:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x2402C1AD);
            ;
        } while (0);
        break;
    case GX_PERF0_NONE:
        break;
    }
    gx->perf1 = perf1;
    switch (gx->perf1) {
    case GX_PERF1_TEXELS:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x67000042);
            ;
        } while (0);
        break;
    case GX_PERF1_TX_IDLE:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x67000084);
            ;
        } while (0);
        break;
    case GX_PERF1_TX_REGS:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x67000063);
            ;
        } while (0);
        break;
    case GX_PERF1_TX_MEMSTALL:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x67000129);
            ;
        } while (0);
        break;
    case GX_PERF1_TC_MISS:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x67000252);
            ;
        } while (0);
        break;
    case GX_PERF1_CLOCKS:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x67000021);
            ;
        } while (0);
        break;
    case GX_PERF1_TC_CHECK1_2:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x6700014B);
            ;
        } while (0);
        break;
    case GX_PERF1_TC_CHECK3_4:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x6700018D);
            ;
        } while (0);
        break;
    case GX_PERF1_TC_CHECK5_6:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x670001CF);
            ;
        } while (0);
        break;
    case GX_PERF1_TC_CHECK7_8:
        do {
            GXWGFifo.u8 = (u8)(0x61);
            GXWGFifo.u32 = (u32)(0x67000211);
            ;
        } while (0);
        break;
    case GX_PERF1_VC_ELEMQ_FULL:
        gx->perfSel = (gx->perfSel & 0xFFFFFF0F) | 0x20;
        ;
        GXWGFifo.u8 = 8;
        GXWGFifo.u8 = 32;
        GXWGFifo.u32 = gx->perfSel;
        break;
    case GX_PERF1_VC_MISSQ_FULL:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(3) << (4));
        ;
        GXWGFifo.u8 = 8;
        GXWGFifo.u8 = 32;
        GXWGFifo.u32 = gx->perfSel;
        break;
    case GX_PERF1_VC_MEMREQ_FULL:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(4) << (4));
        ;
        GXWGFifo.u8 = 8;
        GXWGFifo.u8 = 32;
        GXWGFifo.u32 = gx->perfSel;
        break;
    case GX_PERF1_VC_STATUS7:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(5) << (4));
        ;
        GXWGFifo.u8 = 8;
        GXWGFifo.u8 = 32;
        GXWGFifo.u32 = gx->perfSel;
        break;
    case GX_PERF1_VC_MISSREP_FULL:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(6) << (4));
        ;
        GXWGFifo.u8 = 8;
        GXWGFifo.u8 = 32;
        GXWGFifo.u32 = gx->perfSel;
        break;
    case GX_PERF1_VC_STREAMBUF_LOW:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(7) << (4));
        ;
        GXWGFifo.u8 = 8;
        GXWGFifo.u8 = 32;
        GXWGFifo.u32 = gx->perfSel;
        break;
    case GX_PERF1_VC_ALL_STALLS:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(9) << (4));
        ;
        GXWGFifo.u8 = 8;
        GXWGFifo.u8 = 32;
        GXWGFifo.u32 = gx->perfSel;
        break;
    case GX_PERF1_VERTICES:
        (gx->perfSel) = ((u32)(gx->perfSel) & ~(((1 << (4)) - 1) << (4))) | ((u32)(8) << (4));
        ;
        GXWGFifo.u8 = 8;
        GXWGFifo.u8 = 32;
        GXWGFifo.u32 = gx->perfSel;
        break;
    case GX_PERF1_FIFO_REQ:
        (*(vu16 *)((vu16 *)(__cpReg) + (3)) = 2);
        break;
    case GX_PERF1_CALL_REQ:
        (*(vu16 *)((vu16 *)(__cpReg) + (3)) = 3);
        break;
    case GX_PERF1_VC_MISS_REQ:
        (*(vu16 *)((vu16 *)(__cpReg) + (3)) = 4);
        break;
    case GX_PERF1_CP_ALL_REQ:
        (*(vu16 *)((vu16 *)(__cpReg) + (3)) = 5);
        break;
    case GX_PERF1_NONE:
        break;
    }
    gx->bpSentNot = ((GXBool)0);
}

#pragma scheduling off

/* GXReadGPMetric: reads the four CP performance counters. */

/* volatile: each hardware counter read must reach the CP registers. */
#define GX_GET_CP_REG(reg) (*(volatile u16 *)((u8 *)__cpReg + (reg) * 2))

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

#pragma scheduling reset
void GXClearGPMetric(void) {
    __cpReg[2] = 4;
}

u32 fn_80039B0C(void) {
    u32 loc_C;
    u32 loc_8;
    /* frame */
    fn_80039954(&loc_C, &loc_8);
    return loc_8;
}

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((val) << (shift)))

void fn_80039B38(void) {
    GX_WRITE_RAS_REG(0x2402c022);
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = 0x1006;
    GXWGFifo.u32 = 0x31000;
    gx->bpSentNot = 1;
}

#pragma scheduling off

void GXReadXfRasMetric(u32 *xf_wait_in, u32 *xf_wait_out, u32 *ras_busy, u32 *clocks) {
    *ras_busy = __GXReadCPCounterU32(32, 33);
    *clocks = __GXReadCPCounterU32(34, 35);
    *xf_wait_in = __GXReadCPCounterU32(36, 37);
    *xf_wait_out = __GXReadCPCounterU32(38, 39);
}
