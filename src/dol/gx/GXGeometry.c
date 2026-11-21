#include <types.h>
#include "sdk_addresses.h"
#include "types.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>

void __GXSetSUTexRegs(void);
void fn_80036F24(void);
void __GXSetGenMode(void);
void __GXSetVCD(void);
void fn_80033650(void);
void __GXCalculateVLim(void);
void __GXSendFlushPrim(void);

void fn_8003458C(void) {
    if (gx->dirtyState & 1) {
        __GXSetSUTexRegs();
    }
    if (gx->dirtyState & 2) {
        fn_80036F24();
    }
    if (gx->dirtyState & 4) {
        __GXSetGenMode();
    }
    if (gx->dirtyState & 8) {
        __GXSetVCD();
    }
    if (gx->dirtyState & 0x10) {
        fn_80033650();
    }
    if (gx->dirtyState & 0x18) {
        __GXCalculateVLim();
    }
    gx->dirtyState = 0;
}

void fn_8003462C(u32 type, u32 vtxfmt, u16 nverts) {
    if (gx->dirtyState != 0) {
        fn_8003458C();
    }
    if (*(u32 *)&gx->vNumNot == 0) {
        __GXSendFlushPrim();
    }
    GXWGFifo.u8 = vtxfmt | type;
    GXWGFifo.u16 = nverts;
}

void __GXSendFlushPrim(void) {
    u32 i;
    u32 sz = gx->vNum * gx->vLim;
    GXWGFifo.u8 = 0x98;
    GXWGFifo.u16 = gx->vNum;
    for (i = 0; i < sz; i += 4) {
        GXWGFifo.s32 = 0;
    }
    gx->bpSentNot = 1;
}

void GXSetLineWidth(u8 width, GXTexOffset offsets) {
    GXData *data = gx;
    (data->lpSize) = (data->lpSize & ~(((1 << (8)) - 1) << (31 - (24) - (8) + 1))) |
                     ((int)(width) << (31 - (24) - (8) + 1));
    (data->lpSize) = (data->lpSize & ~(((1 << (3)) - 1) << (31 - (13) - (3) + 1))) |
                     ((int)(offsets) << (31 - (13) - (3) + 1));
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = data->lpSize;
    data->bpSentNot = 0;
}

void GXSetPointSize(u32 arg0, u32 arg1) {
    GXData *reg;
    u32 shifted;
    u32 command;
    // The FIFO pointer is volatile because it names memory-mapped hardware.
    volatile u8 *fifo;
    u16 zero;

    reg = gx;
    shifted = arg1 << 19;
    command = 0x61;
    // The GX write-gather FIFO is memory-mapped hardware.
    fifo = (volatile u8 *)((u8 *)0xCC010000 + -32768); /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    reg->lpSize = ((reg->lpSize & 0xFFFF00FF) & ~0xFF00) | ((arg0 << 8) & 0xFF00);
    zero = 0;
    reg->lpSize = (reg->lpSize & 0xFFC7FFFF) | shifted;
    *fifo = command;
    // The FIFO write is volatile because it accesses memory-mapped hardware.
    *(volatile u32 *)fifo = reg->lpSize;
    reg->bpSentNot = zero;
}

void fn_80034834(u32 arg0, u32 arg1, u32 arg2) {
    GXData *reg;
    u32 command;
    // The GX write-gather FIFO is memory-mapped hardware.
    volatile u8 *fifo;

    reg = gx;
    reg->suTs0[arg0] = (reg->suTs0[arg0] & 0xFFFBFFFF) | ((arg1 & 0xFF) << 18);
    reg->suTs0[arg0] = (reg->suTs0[arg0] & 0xFFF7FFFF) | ((arg2 & 0xFF) << 19);
    command = 0x61;
    fifo = (volatile u8 *)((u8 *)0xCC010000 + -32768); /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *fifo = command;
    // The FIFO data write is volatile because it accesses memory-mapped hardware.
    *(volatile u32 *)fifo = *(u32 *)((u8 *)reg->suTs0 + arg0 * 4);
    reg->bpSentNot = 0;
}

typedef struct {
    u8 pad0[0x204];
    u32 field204;
    u8 pad208[0x2ec];
    u32 field4f4;
} GxState;

void fn_80034890(s32 mode) {
    GxState *state;

    switch (mode) {
    case 1:
        mode = 2;
        break;
    case 2:
        mode = 1;
        break;
    }

    state = (GxState *)gx;
    state->field204 = (state->field204 & 0xffff3fff) | (mode << 14);
    state->field4f4 |= 4;
}

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
