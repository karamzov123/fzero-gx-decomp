#include "types.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <types.h>
#include "sdk_addresses.h"

void GXSetCoPlanar(u32 arg0) {
    GXData *data;
    u32 value;

    data = gx;
    value = (arg0 & 0xFF) << 19;
    data->genMode = (data->genMode & 0xFFF7FFFF) | value;
    *(volatile u8 *)((u8 *)0xCC010000 + -32768) = 0x61; /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile u32 *)((u8 *)0xCC010000 + -32768) = 0xFE080000; /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile u8 *)((u8 *)0xCC010000 + -32768) = 0x61; /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile u32 *)((u8 *)0xCC010000 + -32768) = data->genMode; /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

void __GXSetGenMode(void) {
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = gx->genMode;
    gx->bpSentNot = 0;
}
