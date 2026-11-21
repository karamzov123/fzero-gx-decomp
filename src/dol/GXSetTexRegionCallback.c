#include "types.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include "dolphin/hw_regs.h"
#include <types.h>
#include "sdk_addresses.h"
#pragma dont_inline on

u32 GXSetTexRegionCallback(u32 arg0) {
    u32 *p;
    u32 v0;

    p = (u32 *)gx + 0x410 / 4;
    v0 = *p++;
    p--;
    *p = arg0;
    return v0;
}

u32 GXSetTlutRegionCallback(u32 value) {
    u32 *p;
    u32 old;

    p = (u32 *)gx;
    p = (u32 *)((u8 *)p + 0x414);
    old = *p;
    *p = value;
    return old;
}

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((val) << (shift)))
#define GET_REG_FIELD(reg, size, shift) (((reg) >> (shift)) & ((1 << (size)) - 1))

void fn_800365B4(u32 tex_map, u32 tex_coord) {
    u32 width;
    u32 height;
    u8 s_bias;
    u8 t_bias;
    width = GET_REG_FIELD(gx->tImage0[tex_map], 10, 0);
    height = (gx->tImage0[tex_map] & 0xffc00) >> 10;
    SET_REG_FIELD(gx->suTs0[tex_coord], 16, 0, width);
    SET_REG_FIELD(gx->suTs1[tex_coord], 16, 0, height);
    s_bias = GET_REG_FIELD(gx->tMode0[tex_map], 2, 0) == 1;
    t_bias = GET_REG_FIELD(gx->tMode0[tex_map], 2, 2) == 1;
    SET_REG_FIELD(gx->suTs0[tex_coord], 1, 16, s_bias);
    SET_REG_FIELD(gx->suTs1[tex_coord], 1, 16, t_bias);
    GX_WRITE_RAS_REG(gx->suTs0[tex_coord]);
    GX_WRITE_RAS_REG(gx->suTs1[tex_coord]);
    gx->bpSentNot = 0;
}

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

void __GXSetTmemConfig(u32 config) {
    switch (config) {
    case 1:
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x8c0d8000);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x900dc000);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x8d0d8800);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x910dc800);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x8e0d9000);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x920dd000);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x8f0d9800);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x930dd800);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xac0da000);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xb00de000);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xad0da800);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xb10de800);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xae0db000);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xb20df000);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xaf0db800);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xb30df800);
        ;
        break;
    case 0:
    default:
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x8c0d8000);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x900dc000);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x8d0d8400);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x910dc400);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x8e0d8800);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x920dc800);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x8f0d8c00);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0x930dcc00);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xac0d9000);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xb00dd000);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xad0d9400);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xb10dd400);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xae0d9800);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xb20dd800);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xaf0d9c00);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (0xb30ddc00);
        ;
        break;
    }
}
