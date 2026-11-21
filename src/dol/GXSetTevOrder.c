#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>

extern int lbl_8012B3B8[];
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXSetTevOrder(GXTevStageID stage, GXTexCoordID coord, GXTexMapID map, GXChannelID color) {

    u32 *reg;
    u32 tempMap;
    u32 tempCoord;
    reg = &gx->tref[stage / 2];
    gx->texmapId[stage] = map;
    tempMap = map & ~0x100;
    tempMap = (tempMap >= GX_MAX_TEXMAP) ? GX_TEXMAP0 : tempMap;
    if (coord >= GX_MAXCOORD) {
        tempCoord = GX_TEXCOORD0;
        gx->tevTcEnab = gx->tevTcEnab & ~(1 << stage);
    } else {
        tempCoord = coord;
        gx->tevTcEnab = gx->tevTcEnab | (1 << stage);
    }
    if (stage & 1) {
        (*reg) = (*reg & ~(((1 << ((19 - 17 + 1))) - 1) << (31 - (17) - ((19 - 17 + 1)) + 1))) |
                 ((int)(tempMap) << (31 - (17) - ((19 - 17 + 1)) + 1));
        (*reg) = (*reg & ~(((1 << ((16 - 14 + 1))) - 1) << (31 - (14) - ((16 - 14 + 1)) + 1))) |
                 ((int)(tempCoord) << (31 - (14) - ((16 - 14 + 1)) + 1));
        (*reg) = (*reg & ~(((1 << ((12 - 10 + 1))) - 1) << (31 - (10) - ((12 - 10 + 1)) + 1))) |
                 ((int)((color == GX_COLOR_NULL ? 7 : lbl_8012B3B8[color]))
                  << (31 - (10) - ((12 - 10 + 1)) + 1));
        (*reg) = (*reg & ~(((1 << ((13 - 13 + 1))) - 1) << (31 - (13) - ((13 - 13 + 1)) + 1))) |
                 ((int)(((map != GX_TEXMAP_NULL) && !(map & 0x100)))
                  << (31 - (13) - ((13 - 13 + 1)) + 1));
    } else {
        (*reg) = (*reg & ~(((1 << ((31 - 29 + 1))) - 1) << (31 - (29) - ((31 - 29 + 1)) + 1))) |
                 ((int)(tempMap) << (31 - (29) - ((31 - 29 + 1)) + 1));
        (*reg) = (*reg & ~(((1 << ((28 - 26 + 1))) - 1) << (31 - (26) - ((28 - 26 + 1)) + 1))) |
                 ((int)(tempCoord) << (31 - (26) - ((28 - 26 + 1)) + 1));
        (*reg) = (*reg & ~(((1 << ((24 - 22 + 1))) - 1) << (31 - (22) - ((24 - 22 + 1)) + 1))) |
                 ((int)((color == GX_COLOR_NULL ? 7 : lbl_8012B3B8[color]))
                  << (31 - (22) - ((24 - 22 + 1)) + 1));
        (*reg) = (*reg & ~(((1 << ((25 - 25 + 1))) - 1) << (31 - (25) - ((25 - 25 + 1)) + 1))) |
                 ((int)(((map != GX_TEXMAP_NULL) && !(map & 0x100)))
                  << (31 - (25) - ((25 - 25 + 1)) + 1));
    }
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (*reg);
    ;
    gx->bpSentNot = ((GXBool)0);
    gx->dirtyState |= 1;
}
