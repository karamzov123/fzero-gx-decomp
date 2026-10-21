#include "types.h"

typedef struct GXState {
    u8 pad0[0x4f0];
    u8 f4f0;
    u8 f4f1;
    u8 pad4f2[2];
    u32 f4f4;
} GXState;

typedef struct Fifo {
    u32 base;
    u32 end;
    u32 size;
    u32 pad[2];
    u32 rp;
    u32 wp;
    u32 cnt;
    u32 pad2;
    u32 saved[0x13e];
} Fifo;

Fifo lbl_801783A0[1];
extern GXState *gx;
extern u32 lbl_801A6C28;

extern u32 fn_80032360(void);
extern void fn_8003458C(void);
extern void *memcpy(void *, const void *, u32);
extern void fn_80031FF4(u32);
extern void GXSetCPUFifo(Fifo *);

static void InitFifoBase(Fifo *fifo, void *base, u32 size) {
    fifo->base = (u32)base;
    fifo->end = (u32)base + size - 4;
    fifo->size = size;
    fifo->cnt = 0;
    fifo->rp = (u32)base;
    fifo->wp = (u32)base;
}

void fn_8003887C(void *start, u32 size) {
    u32 token;
    token = fn_80032360();
    if (gx->f4f4 != 0) {
        fn_8003458C();
    }
    if (gx->f4f1 != 0) {
        memcpy(lbl_801783A0[0].saved, gx, 0x4f8);
    }
    InitFifoBase(lbl_801783A0, start, size);
    gx->f4f0 = 1;
    fn_80031FF4(token);
    lbl_801A6C28 = token;
    GXSetCPUFifo(lbl_801783A0);
}
