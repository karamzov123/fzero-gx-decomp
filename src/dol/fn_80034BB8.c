#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct GXData {
    u8 pad_000[0x1f8];
    u32 cp_tex_stride;
    u32 cp_tex;
    u8 cp_tex_z;
} GXData;

extern GXData *const gx;

#define SET_REG_FIELD(reg, size, shift, val) \
    (reg = ((reg) & ~(((1 << size) - 1) << shift)) | (val << shift))

extern void __GetImageTileCount(s32 fmt, u16 width, u16 height, u32 *row_tiles, u32 *col_tiles, u32 *cmp_tiles);

void fn_80034BB8(u16 width, u16 height, s32 fmt, u8 mipmap) {
    u32 row_tiles;
    u32 col_tiles;
    u32 cmp_tiles;
    u32 pe_tex_fmt;
    u32 pe_tex_fmt_h;

    gx->cp_tex_z = 0;
    pe_tex_fmt = fmt & 0xf;
    if (fmt == 0x13) {
        pe_tex_fmt = 0xb;
    }
    switch (fmt) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 0x26:
        SET_REG_FIELD(gx->cp_tex, 2, 15, 3);
        break;
    default:
        SET_REG_FIELD(gx->cp_tex, 2, 15, 2);
        break;
    }
    gx->cp_tex_z = 0x10 == (fmt & 0x10);
    pe_tex_fmt_h = (pe_tex_fmt & 8) >> 3;
    SET_REG_FIELD(gx->cp_tex, 1, 3, pe_tex_fmt_h);
    pe_tex_fmt = pe_tex_fmt & 7;
    __GetImageTileCount(fmt, width, height, &row_tiles, &col_tiles, &cmp_tiles);
    gx->cp_tex_stride = 0;
    SET_REG_FIELD(gx->cp_tex_stride, 10, 0, row_tiles * cmp_tiles);
    SET_REG_FIELD(gx->cp_tex_stride, 8, 24, 0x4d);
    SET_REG_FIELD(gx->cp_tex, 1, 9, mipmap);
    SET_REG_FIELD(gx->cp_tex, 3, 4, pe_tex_fmt);
}
