/* begin dolphin/gx.h (deltawave784/fzgx@7d73e43f (CC0)) */
#ifndef DOLPHIN_GX_H
#define DOLPHIN_GX_H

#include "dolphin/types.h"
#include "dolphin/hw_regs.h"

/* The GX write-gather pipe: one memory-mapped port at GX_FIFO_BASE, written through
   the member whose width the command needs. Declared as an MWCC absolute object: every store is
   emitted in order, addressed by literal (`lis rX, 0xCC01; stb rY, -0x8000(rX)`) with no
   relocation, and the named object cannot alias the `gx` context, which keeps retail's schedule.
   Proven by GXSetViewportJitter (fn_80038DE8) and GXSetFog (fn_800377F8). */
typedef union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    s8 s8;
    s16 s16;
    s32 s32;
    f32 f32;
    f64 f64;
} PPCWGPipe;

volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE; /* volatile: hardware port */

#define GX_WRITE_U8(v) (GXWGFifo.u8 = (u8)(v))
#define GX_WRITE_U16(v) (GXWGFifo.u16 = (u16)(v))
#define GX_WRITE_U32(v) (GXWGFifo.u32 = (u32)(v))
#define GX_WRITE_F32(v) (GXWGFifo.f32 = (f32)(v))

/* BP (raster) register write: command byte 0x61 followed by the register word. */
#define GX_WRITE_RAS_REG(value)  \
    do {                         \
        GXWGFifo.u8 = 0x61;      \
        GXWGFifo.u32 = (value);  \
    } while (0)

/* XF register write: command byte 0x10, then (count - 1) << 16 | address, then the data words. */
#define GX_WRITE_XF_REG_HDR(addr, count) \
    do {                                  \
        GXWGFifo.u8 = 0x10;               \
        GXWGFifo.u32 = (((count) - 1) << 16) | (addr); \
    } while (0)

#endif

/* end dolphin/gx.h */
#include "types.h"

struct fn_80072168_lbl_8019E250 {
    u8 pad_0[0xC];
    u32 unk_C;
    u8 pad_10[0x14];
    u32 unk_24;
    u8 pad_28[0x4];
    u32 unk_2C;
};

struct fn_80072168_gx {
    u8 pad_0[2];
    u16 unk_2;
};

extern struct fn_80072168_lbl_8019E250 lbl_8019E250[];
extern struct fn_80072168_gx *gx;

#pragma opt_common_subs off
#pragma opt_propagation off
static inline void fn_80072168_write_bp_impl(u32 value) {
    u32 data = value;
    u32 command = 0x61;
    gx->unk_2 = 0;
    GXWGFifo.u8 = command;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    GXWGFifo.u32 = data;  /* fzgx-allow: S2 volatile view keeps the verified load order */
}
#define fn_80072168_write_bp(value, command) fn_80072168_write_bp_impl(value)

void fn_80072168(s32 arg0) {
    u32 mode;
    u32 v;
    struct fn_80072168_lbl_8019E250 *p;
    p = lbl_8019E250;
    if (!(p->unk_2C & 1)) {
        return;
    }
    if (arg0 != 0) {
        v = p->unk_24;
        mode = p->unk_C;
        if (((v >> 21) & 7) == mode) {
            return;
        }
        fn_80072168_write_bp(p->unk_24 = (v & 0xFF1FFFFF) | (mode << 21), 0x61);
    } else {
        v = p->unk_24;
        if (((v >> 21) & 7) == 0) {
            return;
        }
        fn_80072168_write_bp(p->unk_24 = v & 0xFF1FFFFF, 0x61);
    }
}
#pragma opt_common_subs reset
