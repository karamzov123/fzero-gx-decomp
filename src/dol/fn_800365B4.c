#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct GXData {
    u16 unk_000;
    u16 bp_sent_not;
    u8 pad_004[0xb4];
    u32 su_ts0[8];
    u32 su_ts1[8];
    u8 pad_0f8[0x364];
    u32 t_image0[8];
    u32 t_mode0[8];
} GXData;

typedef union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} PPCWGPipe;

extern GXData *const gx;
volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */

#define SET_REG_FIELD(reg, size, shift, val) \
    (reg = ((reg) & ~(((1 << size) - 1) << shift)) | (val << shift))
#define GET_REG_FIELD(reg, size, shift) (((reg) >> (shift)) & ((1 << (size)) - 1))
#define GX_WRITE_RAS_REG(reg) \
    do { \
        GXWGFifo.u8 = 0x61; \
        GXWGFifo.u32 = (reg); \
    } while (0)

void fn_800365B4(u32 tex_map, u32 tex_coord) {
    u32 width;
    u32 height;
    u8 s_bias;
    u8 t_bias;
    width = GET_REG_FIELD(gx->t_image0[tex_map], 10, 0);
    height = (gx->t_image0[tex_map] & 0xffc00) >> 10;
    SET_REG_FIELD(gx->su_ts0[tex_coord], 16, 0, width);
    SET_REG_FIELD(gx->su_ts1[tex_coord], 16, 0, height);
    s_bias = GET_REG_FIELD(gx->t_mode0[tex_map], 2, 0) == 1;
    t_bias = GET_REG_FIELD(gx->t_mode0[tex_map], 2, 2) == 1;
    SET_REG_FIELD(gx->su_ts0[tex_coord], 1, 16, s_bias);
    SET_REG_FIELD(gx->su_ts1[tex_coord], 1, 16, t_bias);
    GX_WRITE_RAS_REG(gx->su_ts0[tex_coord]);
    GX_WRITE_RAS_REG(gx->su_ts1[tex_coord]);
    gx->bp_sent_not = 0;
}
