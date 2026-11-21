#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>
#pragma dont_inline on

/* --- dol/__GXSetSUTexRegs.c --- */
void fn_800365B4(u32 texImgIndex, u32 setUpRegIndex);

void __GXSetSUTexRegs(void) {
    u32 i;
    u32 b;
    u32 a;
    u32 c;
    u32 d;
    u32 stackFiller;
    if (gx->tcsManEnab != 0xff) {
        a = ((gx->genMode) >> (31 - (18) - ((21 - 18 + 1)) + 1) & ((1 << ((21 - 18 + 1))) - 1)) + 1;
        b = ((gx->genMode) >> (31 - (13) - ((15 - 13 + 1)) + 1) & ((1 << ((15 - 13 + 1))) - 1));
        for (i = 0; i < b; i++) {
            switch (i) {
            case 0:
                c = ((gx->iref) >> (31 - (29) - ((31 - 29 + 1)) + 1) &
                     ((1 << ((31 - 29 + 1))) - 1));
                d = ((gx->iref) >> (31 - (26) - ((28 - 26 + 1)) + 1) &
                     ((1 << ((28 - 26 + 1))) - 1));
                break;
            case 1:
                c = ((gx->iref) >> (31 - (23) - ((25 - 23 + 1)) + 1) &
                     ((1 << ((25 - 23 + 1))) - 1));
                d = ((gx->iref) >> (31 - (20) - ((22 - 20 + 1)) + 1) &
                     ((1 << ((22 - 20 + 1))) - 1));
                break;
            case 2:
                c = ((gx->iref) >> (31 - (17) - ((19 - 17 + 1)) + 1) &
                     ((1 << ((19 - 17 + 1))) - 1));
                d = ((gx->iref) >> (31 - (14) - ((16 - 14 + 1)) + 1) &
                     ((1 << ((16 - 14 + 1))) - 1));
                break;
            case 3:
                c = ((gx->iref) >> (31 - (11) - ((13 - 11 + 1)) + 1) &
                     ((1 << ((13 - 11 + 1))) - 1));
                d = ((gx->iref) >> (31 - (8) - ((10 - 8 + 1)) + 1) & ((1 << ((10 - 8 + 1))) - 1));
                break;
            }
            if (!(gx->tcsManEnab & (1 << d))) {
                fn_800365B4(c, d);
            }
        }
        for (i = 0; i < a; i++) {
            u32 *g = &gx->tref[i / 2];
            c = gx->texmapId[i] & ~0x100;
            if (i & 1) {
                d = ((*g) >> (31 - (14) - ((16 - 14 + 1)) + 1) & ((1 << ((16 - 14 + 1))) - 1));
            } else {
                d = ((*g) >> (31 - (26) - ((28 - 26 + 1)) + 1) & ((1 << ((28 - 26 + 1))) - 1));
            }
            if (c != 0xff && !(gx->tcsManEnab & (1 << d)) && gx->tevTcEnab & (1 << i)) {
                fn_800365B4(c, d);
            }
        }
    }
}

/* --- dol/__GXSetTmemConfig.c --- */

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void __GXSetTmemConfig(u32 config) {
    switch (config) {
    case 1:
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8c0d8000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x900dc000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8d0d8800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x910dc800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8e0d9000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x920dd000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8f0d9800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x930dd800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xac0da000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb00de000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xad0da800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb10de800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xae0db000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb20df000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xaf0db800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb30df800);
        ;
        break;
    case 0:
    default:
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8c0d8000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x900dc000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8d0d8400);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x910dc400);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8e0d8800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x920dc800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x8f0d8c00);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0x930dcc00);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xac0d9000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb00dd000);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xad0d9400);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb10dd400);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xae0d9800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb20dd800);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xaf0d9c00);
        ;
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (0xb30ddc00);
        ;
        break;
    }
}
