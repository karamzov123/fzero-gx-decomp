#include <types.h>
#include "sdk_addresses.h"
#include "types.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include "dolphin/hw_regs.h"

void __GXSetGenMode(void);

void GXAdjustForOverscan(GXRenderModeObj *rmin, GXRenderModeObj *rmout, u16 hor, u16 ver) {
    unsigned short hor2 = hor * 2;
    unsigned short ver2 = ver * 2;
    unsigned long verf;
    if (rmin != rmout) {
        *rmout = *rmin;
    }
    rmout->fbWidth = rmin->fbWidth - hor2;
    verf = (ver2 * rmin->efbHeight) / (u32)rmin->xfbHeight;
    rmout->efbHeight = rmin->efbHeight - verf;
    if (rmin->xFBmode == VI_XFBMODE_SF && (rmin->viTVmode & 2) != 2) {
        rmout->xfbHeight = rmin->xfbHeight - ver;
    } else {
        rmout->xfbHeight = rmin->xfbHeight - ver2;
    }
    rmout->viWidth = rmin->viWidth - hor2;
    rmout->viHeight = rmin->viHeight - ver2;
    rmout->viXOrigin = rmin->viXOrigin + hor;
    rmout->viYOrigin = rmin->viYOrigin + ver;
}

void GXSetDispCopySrc(u16 left, u16 top, u16 width, u16 height) {
    gx->cpDispSrc = 0;
    (gx->cpDispSrc) = (gx->cpDispSrc & ~(((1 << (10)) - 1) << (31 - (22) - (10) + 1))) |
                      ((int)(left) << (31 - (22) - (10) + 1));
    (gx->cpDispSrc) = (gx->cpDispSrc & ~(((1 << (10)) - 1) << (31 - (12) - (10) + 1))) |
                      ((int)(top) << (31 - (12) - (10) + 1));
    (gx->cpDispSrc) = (gx->cpDispSrc & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                      ((int)(73) << (31 - (0) - (8) + 1));
    gx->cpDispSize = 0;
    (gx->cpDispSize) = (gx->cpDispSize & ~(((1 << (10)) - 1) << (31 - (22) - (10) + 1))) |
                       ((int)(width - 1) << (31 - (22) - (10) + 1));
    (gx->cpDispSize) = (gx->cpDispSize & ~(((1 << (10)) - 1) << (31 - (12) - (10) + 1))) |
                       ((int)(height - 1) << (31 - (12) - (10) + 1));
    (gx->cpDispSize) = (gx->cpDispSize & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                       ((int)(74) << (31 - (0) - (8) + 1));
}

void GXSetTexCopySrc(u16 left, u16 top, u16 width, u16 height) {
    gx->cpTexSrc = 0;
    (gx->cpTexSrc) = (gx->cpTexSrc & ~(((1 << (10)) - 1) << (31 - (22) - (10) + 1))) |
                     ((int)(left) << (31 - (22) - (10) + 1));
    (gx->cpTexSrc) = (gx->cpTexSrc & ~(((1 << (10)) - 1) << (31 - (12) - (10) + 1))) |
                     ((int)(top) << (31 - (12) - (10) + 1));
    (gx->cpTexSrc) = (gx->cpTexSrc & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                     ((int)(0x49) << (31 - (0) - (8) + 1));
    gx->cpTexSize = 0;
    (gx->cpTexSize) = (gx->cpTexSize & ~(((1 << (10)) - 1) << (31 - (22) - (10) + 1))) |
                      ((int)(width - 1) << (31 - (22) - (10) + 1));
    (gx->cpTexSize) = (gx->cpTexSize & ~(((1 << (10)) - 1) << (31 - (12) - (10) + 1))) |
                      ((int)(height - 1) << (31 - (12) - (10) + 1));
    (gx->cpTexSize) = (gx->cpTexSize & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                      ((int)(0x4A) << (31 - (0) - (8) + 1));
}

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((val) << (shift)))

#define OLD_SET(reg, size, shift, val) ((reg) = ((u32)(reg) & ~(((1 << (size)) - 1) << (shift))) | ((u32)(val) << (shift)))
void fn_80034B7C(u16 value) {
    GXData *state = gx;
    u32 *reg;
    state->cpDispStride = 0;
    reg = &state->cpDispStride;
    OLD_SET(*reg, 10, 0, (u16)(value << 1) >> 5);
    OLD_SET(*reg, 8, 24, 0x4d);
}

extern void __GetImageTileCount(s32 fmt, u16 width, u16 height, u32 *row_tiles, u32 *col_tiles, u32 *cmp_tiles);

void fn_80034BB8(u16 width, u16 height, s32 fmt, u8 mipmap) {
    u32 row_tiles;
    u32 col_tiles;
    u32 cmp_tiles;
    u32 pe_tex_fmt;
    u32 pe_tex_fmt_h;

    gx->cpTexZ = 0;
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
        SET_REG_FIELD(gx->cpTex, 2, 15, 3);
        break;
    default:
        SET_REG_FIELD(gx->cpTex, 2, 15, 2);
        break;
    }
    gx->cpTexZ = 0x10 == (fmt & 0x10);
    pe_tex_fmt_h = (pe_tex_fmt & 8) >> 3;
    SET_REG_FIELD(gx->cpTex, 1, 3, pe_tex_fmt_h);
    pe_tex_fmt = pe_tex_fmt & 7;
    __GetImageTileCount(fmt, width, height, &row_tiles, &col_tiles, &cmp_tiles);
    gx->cpTexStride = 0;
    SET_REG_FIELD(gx->cpTexStride, 10, 0, row_tiles * cmp_tiles);
    SET_REG_FIELD(gx->cpTexStride, 8, 24, 0x4d);
    SET_REG_FIELD(gx->cpTex, 1, 9, mipmap);
    SET_REG_FIELD(gx->cpTex, 3, 4, pe_tex_fmt);
}

void GXSetDispCopyFrame2Field(GXCopyMode arg0) {
    (gx->cpDisp) = (gx->cpDisp & ~(((1 << (2)) - 1) << (31 - (18) - (2) + 1))) |
                   ((int)(arg0) << (31 - (18) - (2) + 1));
    (gx->cpTex) = (gx->cpTex & ~(((1 << (2)) - 1) << (31 - (18) - (2) + 1))) |
                  ((int)(0) << (31 - (18) - (2) + 1));
}
