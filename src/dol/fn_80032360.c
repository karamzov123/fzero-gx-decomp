#include "types.h"
#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>

/* --- dol/fn_80032360.c --- */
/* --- dol/fn_80032360.c --- */
extern u32 lbl_801A6BF0;

u32 fn_80032360(void) {
    return lbl_801A6BF0;
}

/* --- dol/fn_80032368.c --- */
extern u32 lbl_801A6BF4;

u32 fn_80032368(void) {
    return lbl_801A6BF4;
}

/* --- dol/__GXXfVtxSpecs.c --- */
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void __GXXfVtxSpecs(void) {
    u32 nCols = 0;
    u32 nNrm;
    u32 nTex;
    u32 reg;
    nCols = ((int)((gx->vcdLo) >> (13)) & ((1 << (2)) - 1)) ? 1 : 0;
    nCols += ((int)((gx->vcdLo) >> (15)) & ((1 << (2)) - 1)) ? 1 : 0;
    nNrm = gx->hasBiNrms ? 2 : gx->hasNrms ? 1 : 0;
    nTex = 0;
    nTex += ((int)((gx->vcdHi) >> (0)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (2)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (4)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (6)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (8)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (10)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (12)) & ((1 << (2)) - 1)) ? 1 : 0;
    nTex += ((int)((gx->vcdHi) >> (14)) & ((1 << (2)) - 1)) ? 1 : 0;
    reg = (nCols) | (nNrm << 2) | (nTex << 4);
    do {
        GXFIFO.u8 = (u8)(0x10);
        GXFIFO.u32 = (u32)(0x1000 + (8));
        GXFIFO.u32 = (u32)(reg);
        ;
    } while (0);
    gx->bpSentNot = ((GXBool)1);
}
