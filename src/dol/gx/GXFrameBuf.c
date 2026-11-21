#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <types.h>
#include "sdk_addresses.h"
#include "types.h"
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

void fn_80034D34(u32 flags) {
    u8 first = (flags & 1) == 1;
    u8 second = (flags & 2) == 2;

    SET_REG_FIELD(gx->cpDisp, 1, 0, first);
    SET_REG_FIELD(gx->cpDisp, 1, 1, second);
    SET_REG_FIELD(gx->cpTex, 1, 0, first);
    SET_REG_FIELD(gx->cpTex, 1, 1, second);
}

static inline u32 __GXGetNumXfbLines(u32 height, u32 scale) {
    u32 numLines;
    u32 actualHeight;
    u32 newScale;
    numLines = (height - 1) * 0x100;
    actualHeight = (numLines / scale) + 1;
    newScale = scale;
    if (newScale > 0x80 && newScale < 0x100) {
        while (newScale % 2 == 0) {
            newScale /= 2;
        }
        if (height % newScale == 0) {
            actualHeight++;
        }
    }
    if (actualHeight > 0x400) {
        actualHeight = 0x400;
    }
    return actualHeight;
}

u32 GXSetDispCopyYScale(f32 vertScale) {
    u32 scale;
    GXBool check;
    u32 height;
    u32 reg;
    scale = (u32)(256.0f / vertScale) & 0x1FF;
    check = (scale != 0x100);
    reg = 0;
    (reg) = (reg & ~(((1 << ((31 - 23 + 1))) - 1) << (31 - (23) - ((31 - 23 + 1)) + 1))) |
            ((int)(scale) << (31 - (23) - ((31 - 23 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((int)(0x4E) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (reg);
    ;
    gx->bpSentNot = ((GXBool)0);
    (gx->cpDisp) =
        (gx->cpDisp & ~(((1 << ((21 - 21 + 1))) - 1) << (31 - (21) - ((21 - 21 + 1)) + 1))) |
        ((int)(check) << (31 - (21) - ((21 - 21 + 1)) + 1));
    height = (gx->cpDispSize >> 10 & 0x3FF) + 1;
    return __GXGetNumXfbLines(height, scale);
}

void GXSetCopyClear(GXColor color, u32 clear_z) {
    u32 r6 = 0;
    (r6) = (r6 & ~(((1 << (8)) - 1) << (31 - (24) - (8) + 1))) |
           ((int)(color.r) << (31 - (24) - (8) + 1));
    (r6) = (r6 & ~(((1 << (8)) - 1) << (31 - (16) - (8) + 1))) |
           ((int)(color.a) << (31 - (16) - (8) + 1));
    (r6) =
        (r6 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) | ((int)(0x4f) << (31 - (0) - (8) + 1));
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = r6;
    r6 = 0;
    (r6) = (r6 & ~(((1 << (8)) - 1) << (31 - (24) - (8) + 1))) |
           ((int)(color.b) << (31 - (24) - (8) + 1));
    (r6) = (r6 & ~(((1 << (8)) - 1) << (31 - (16) - (8) + 1))) |
           ((int)(color.g) << (31 - (16) - (8) + 1));
    (r6) =
        (r6 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) | ((int)(0x50) << (31 - (0) - (8) + 1));
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = r6;
    r6 = 0;
    (r6) = (r6 & ~(((1 << (24)) - 1) << (31 - (8) - (24) + 1))) |
           ((int)(clear_z) << (31 - (8) - (24) + 1));
    (r6) =
        (r6 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) | ((int)(0x51) << (31 - (0) - (8) + 1));
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = r6;
    gx->bpSentNot = 0;
}

void fn_80034ECC(GXBool useAA, u8 samplePattern[12][2], GXBool doVertFilt, u8 vFilt[7]);

void fn_80034ECC(GXBool useAA, u8 samplePattern[12][2], GXBool doVertFilt, u8 vFilt[7]) {
    u32 vals[4];
    u32 unk1;
    u32 unk2;
    if (useAA) {
        vals[0] = 0;
        (vals[0]) =
            (vals[0] & ~(((1 << ((31 - 28 + 1))) - 1) << (31 - (28) - ((31 - 28 + 1)) + 1))) |
            ((samplePattern[0][0]) << (31 - (28) - ((31 - 28 + 1)) + 1));
        (vals[0]) =
            (vals[0] & ~(((1 << ((27 - 24 + 1))) - 1) << (31 - (24) - ((27 - 24 + 1)) + 1))) |
            ((samplePattern[0][1]) << (31 - (24) - ((27 - 24 + 1)) + 1));
        (vals[0]) =
            (vals[0] & ~(((1 << ((23 - 20 + 1))) - 1) << (31 - (20) - ((23 - 20 + 1)) + 1))) |
            ((samplePattern[1][0]) << (31 - (20) - ((23 - 20 + 1)) + 1));
        (vals[0]) =
            (vals[0] & ~(((1 << ((19 - 16 + 1))) - 1) << (31 - (16) - ((19 - 16 + 1)) + 1))) |
            ((samplePattern[1][1]) << (31 - (16) - ((19 - 16 + 1)) + 1));
        (vals[0]) =
            (vals[0] & ~(((1 << ((15 - 12 + 1))) - 1) << (31 - (12) - ((15 - 12 + 1)) + 1))) |
            ((samplePattern[2][0]) << (31 - (12) - ((15 - 12 + 1)) + 1));
        (vals[0]) = (vals[0] & ~(((1 << ((11 - 8 + 1))) - 1) << (31 - (8) - ((11 - 8 + 1)) + 1))) |
                    ((samplePattern[2][1]) << (31 - (8) - ((11 - 8 + 1)) + 1));
        (vals[0]) = (vals[0] & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
                    ((1) << (31 - (0) - ((7 - 0 + 1)) + 1));
        vals[1] = 0;
        (vals[1]) =
            (vals[1] & ~(((1 << ((31 - 28 + 1))) - 1) << (31 - (28) - ((31 - 28 + 1)) + 1))) |
            ((samplePattern[3][0]) << (31 - (28) - ((31 - 28 + 1)) + 1));
        (vals[1]) =
            (vals[1] & ~(((1 << ((27 - 24 + 1))) - 1) << (31 - (24) - ((27 - 24 + 1)) + 1))) |
            ((samplePattern[3][1]) << (31 - (24) - ((27 - 24 + 1)) + 1));
        (vals[1]) =
            (vals[1] & ~(((1 << ((23 - 20 + 1))) - 1) << (31 - (20) - ((23 - 20 + 1)) + 1))) |
            ((samplePattern[4][0]) << (31 - (20) - ((23 - 20 + 1)) + 1));
        (vals[1]) =
            (vals[1] & ~(((1 << ((19 - 16 + 1))) - 1) << (31 - (16) - ((19 - 16 + 1)) + 1))) |
            ((samplePattern[4][1]) << (31 - (16) - ((19 - 16 + 1)) + 1));
        (vals[1]) =
            (vals[1] & ~(((1 << ((15 - 12 + 1))) - 1) << (31 - (12) - ((15 - 12 + 1)) + 1))) |
            ((samplePattern[5][0]) << (31 - (12) - ((15 - 12 + 1)) + 1));
        (vals[1]) = (vals[1] & ~(((1 << ((11 - 8 + 1))) - 1) << (31 - (8) - ((11 - 8 + 1)) + 1))) |
                    ((samplePattern[5][1]) << (31 - (8) - ((11 - 8 + 1)) + 1));
        (vals[1]) = (vals[1] & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
                    ((2) << (31 - (0) - ((7 - 0 + 1)) + 1));
        vals[2] = 0;
        (vals[2]) =
            (vals[2] & ~(((1 << ((31 - 28 + 1))) - 1) << (31 - (28) - ((31 - 28 + 1)) + 1))) |
            ((samplePattern[6][0]) << (31 - (28) - ((31 - 28 + 1)) + 1));
        (vals[2]) =
            (vals[2] & ~(((1 << ((27 - 24 + 1))) - 1) << (31 - (24) - ((27 - 24 + 1)) + 1))) |
            ((samplePattern[6][1]) << (31 - (24) - ((27 - 24 + 1)) + 1));
        (vals[2]) =
            (vals[2] & ~(((1 << ((23 - 20 + 1))) - 1) << (31 - (20) - ((23 - 20 + 1)) + 1))) |
            ((samplePattern[7][0]) << (31 - (20) - ((23 - 20 + 1)) + 1));
        (vals[2]) =
            (vals[2] & ~(((1 << ((19 - 16 + 1))) - 1) << (31 - (16) - ((19 - 16 + 1)) + 1))) |
            ((samplePattern[7][1]) << (31 - (16) - ((19 - 16 + 1)) + 1));
        (vals[2]) =
            (vals[2] & ~(((1 << ((15 - 12 + 1))) - 1) << (31 - (12) - ((15 - 12 + 1)) + 1))) |
            ((samplePattern[8][0]) << (31 - (12) - ((15 - 12 + 1)) + 1));
        (vals[2]) = (vals[2] & ~(((1 << ((11 - 8 + 1))) - 1) << (31 - (8) - ((11 - 8 + 1)) + 1))) |
                    ((samplePattern[8][1]) << (31 - (8) - ((11 - 8 + 1)) + 1));
        (vals[2]) = (vals[2] & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
                    ((3) << (31 - (0) - ((7 - 0 + 1)) + 1));
        vals[3] = 0;
        (vals[3]) =
            (vals[3] & ~(((1 << ((31 - 28 + 1))) - 1) << (31 - (28) - ((31 - 28 + 1)) + 1))) |
            ((samplePattern[9][0]) << (31 - (28) - ((31 - 28 + 1)) + 1));
        (vals[3]) =
            (vals[3] & ~(((1 << ((27 - 24 + 1))) - 1) << (31 - (24) - ((27 - 24 + 1)) + 1))) |
            ((samplePattern[9][1]) << (31 - (24) - ((27 - 24 + 1)) + 1));
        (vals[3]) =
            (vals[3] & ~(((1 << ((23 - 20 + 1))) - 1) << (31 - (20) - ((23 - 20 + 1)) + 1))) |
            ((samplePattern[10][0]) << (31 - (20) - ((23 - 20 + 1)) + 1));
        (vals[3]) =
            (vals[3] & ~(((1 << ((19 - 16 + 1))) - 1) << (31 - (16) - ((19 - 16 + 1)) + 1))) |
            ((samplePattern[10][1]) << (31 - (16) - ((19 - 16 + 1)) + 1));
        (vals[3]) =
            (vals[3] & ~(((1 << ((15 - 12 + 1))) - 1) << (31 - (12) - ((15 - 12 + 1)) + 1))) |
            ((samplePattern[11][0]) << (31 - (12) - ((15 - 12 + 1)) + 1));
        (vals[3]) = (vals[3] & ~(((1 << ((11 - 8 + 1))) - 1) << (31 - (8) - ((11 - 8 + 1)) + 1))) |
                    ((samplePattern[11][1]) << (31 - (8) - ((11 - 8 + 1)) + 1));
        (vals[3]) = (vals[3] & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
                    ((4) << (31 - (0) - ((7 - 0 + 1)) + 1));
    } else {
        vals[0] = 0x01666666;
        vals[1] = 0x02666666;
        vals[2] = 0x03666666;
        vals[3] = 0x04666666;
    }
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (vals[0]);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (vals[1]);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (vals[2]);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (vals[3]);
    ;
    unk1 = 0;
    unk1 = (unk1 & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
             ((0x53) << (31 - (0) - ((7 - 0 + 1)) + 1));
    unk2 = 0;
    unk2 = (unk2 & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
             ((0x54) << (31 - (0) - ((7 - 0 + 1)) + 1));
    if (doVertFilt) {
        unk1 = (unk1 & ~(((1 << ((31 - 26 + 1))) - 1) << (31 - (26) - ((31 - 26 + 1)) + 1))) |
                 ((vFilt[0]) << (31 - (26) - ((31 - 26 + 1)) + 1));
        unk1 = (unk1 & ~(((1 << ((25 - 20 + 1))) - 1) << (31 - (20) - ((25 - 20 + 1)) + 1))) |
                 ((vFilt[1]) << (31 - (20) - ((25 - 20 + 1)) + 1));
        unk1 = (unk1 & ~(((1 << ((19 - 14 + 1))) - 1) << (31 - (14) - ((19 - 14 + 1)) + 1))) |
                 ((vFilt[2]) << (31 - (14) - ((19 - 14 + 1)) + 1));
        unk1 = (unk1 & ~(((1 << ((13 - 8 + 1))) - 1) << (31 - (8) - ((13 - 8 + 1)) + 1))) |
                 ((vFilt[3]) << (31 - (8) - ((13 - 8 + 1)) + 1));
        unk2 = (unk2 & ~(((1 << ((31 - 26 + 1))) - 1) << (31 - (26) - ((31 - 26 + 1)) + 1))) |
                 ((vFilt[4]) << (31 - (26) - ((31 - 26 + 1)) + 1));
        unk2 = (unk2 & ~(((1 << ((25 - 20 + 1))) - 1) << (31 - (20) - ((25 - 20 + 1)) + 1))) |
                 ((vFilt[5]) << (31 - (20) - ((25 - 20 + 1)) + 1));
        unk2 = (unk2 & ~(((1 << ((19 - 14 + 1))) - 1) << (31 - (14) - ((19 - 14 + 1)) + 1))) |
                 ((vFilt[6]) << (31 - (14) - ((19 - 14 + 1)) + 1));
    } else {
        unk1 = 0x53595000;
        unk2 = 0x54000015;
    }
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (unk1);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (unk2);
    ;
    gx->bpSentNot = ((GXBool)0);
}

void GXSetDispCopyGamma(u32 arg0) {
    u32 *reg = (u32 *)&gx->cpDisp;
    *reg = (*reg & 0xFFFFFE7F) | (arg0 << 7);
}

void fn_80035110(void *dest, GXBool doClear);

void fn_80035110(void *dest, GXBool doClear) {
    u32 newDest;
    GXBool check;
    if (doClear) {
        u32 reg;
        reg = gx->zmode;
        reg = (reg & ~(((1 << ((31 - 31 + 1))) - 1) << (31 - (31) - ((31 - 31 + 1)) + 1))) |
                ((1) << (31 - (31) - ((31 - 31 + 1)) + 1));
        reg = (reg & ~(((1 << ((30 - 28 + 1))) - 1) << (31 - (28) - ((30 - 28 + 1)) + 1))) |
                ((7) << (31 - (28) - ((30 - 28 + 1)) + 1));
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (reg);
        ;
        reg = gx->cmode0;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = reg & 0xFFFFFFFC;
        ;
    }
    check = ((GXBool)0);
    if (doClear || (gx->peCtrl & 0x7) == 3) {
        if ((gx->peCtrl >> 6 & 0x1) == 1) {
            check = ((GXBool)1);
            GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
            GXWGFifo.s32 = (gx->peCtrl & 0xFFFFFFBF);
            ;
        }
    }
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpDispSrc);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpDispSize);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpDispStride);
    ;
    newDest = (u32)dest & 0x3FFFFFFF;
    {
        u32 reg;
        reg = 0;
    reg = (reg & ~(((1 << ((31 - 11 + 1))) - 1) << (31 - (11) - ((31 - 11 + 1)) + 1))) |
            ((newDest >> 5) << (31 - (11) - ((31 - 11 + 1)) + 1));
    reg = (reg & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((0x4B) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (reg);
    ;
    }
    gx->cpDisp =
        (gx->cpDisp & ~(((1 << ((20 - 20 + 1))) - 1) << (31 - (20) - ((20 - 20 + 1)) + 1))) |
        (doClear << (31 - (20) - ((20 - 20 + 1)) + 1));
    gx->cpDisp =
        (gx->cpDisp & ~(((1 << ((17 - 17 + 1))) - 1) << (31 - (17) - ((17 - 17 + 1)) + 1))) |
        ((1) << (31 - (17) - ((17 - 17 + 1)) + 1));
    gx->cpDisp = (gx->cpDisp & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
                   ((0x52) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpDisp);
    ;
    if (doClear) {
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (gx->zmode);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (gx->cmode0);
        ;
    }
    if (check) {
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (gx->peCtrl);
        ;
    }
    gx->bpSentNot = ((GXBool)0);
}

void fn_8003526C(void *dest, GXBool doClear);

void fn_8003526C(void *dest, GXBool doClear) {
    u32 reg;
    u32 reg2;
    u32 newDest;
    GXBool check;
    if (doClear) {
        reg = gx->zmode;
        reg = (reg & ~(((1 << ((31 - 31 + 1))) - 1) << (31 - (31) - ((31 - 31 + 1)) + 1))) |
                ((1) << (31 - (31) - ((31 - 31 + 1)) + 1));
        reg = (reg & ~(((1 << ((30 - 28 + 1))) - 1) << (31 - (28) - ((30 - 28 + 1)) + 1))) |
                ((7) << (31 - (28) - ((30 - 28 + 1)) + 1));
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (reg);
        ;
        reg = gx->cmode0;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (reg & ~3u);
        ;
    }
    check = ((GXBool)0);
    reg2 = gx->peCtrl;
    if (gx->cpTexZ && (reg2 & 0x7) != 3) {
        check = ((GXBool)1);
        reg2 = (reg2 & ~(((1 << ((31 - 29 + 1))) - 1) << (31 - (29) - ((31 - 29 + 1)) + 1))) |
                 ((3) << (31 - (29) - ((31 - 29 + 1)) + 1));
    }
    if ((doClear || (reg2 & 0x7) == 3) && (reg2 >> 6 & 0x1) == 1) {
        check = ((GXBool)1);
        reg2 = (reg2 & ~(((1 << ((25 - 25 + 1))) - 1) << (31 - (25) - ((25 - 25 + 1)) + 1))) |
                 ((0) << (31 - (25) - ((25 - 25 + 1)) + 1));
    }
    if (check) {
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (reg2);
        ;
    }
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpTexSrc);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpTexSize);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpTexStride);
    ;
    newDest = (u32)dest & 0x3FFFFFFF;
    reg = 0;
    reg = (reg & ~(((1 << ((31 - 11 + 1))) - 1) << (31 - (11) - ((31 - 11 + 1)) + 1))) |
            ((newDest >> 5) << (31 - (11) - ((31 - 11 + 1)) + 1));
    reg = (reg & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((0x4B) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (reg);
    ;
    gx->cpTex =
        (gx->cpTex & ~(((1 << ((20 - 20 + 1))) - 1) << (31 - (20) - ((20 - 20 + 1)) + 1))) |
        (doClear << (31 - (20) - ((20 - 20 + 1)) + 1));
    gx->cpTex =
        (gx->cpTex & ~(((1 << ((17 - 17 + 1))) - 1) << (31 - (17) - ((17 - 17 + 1)) + 1))) |
        ((0) << (31 - (17) - ((17 - 17 + 1)) + 1));
    gx->cpTex = (gx->cpTex & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
                  ((0x52) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (gx->cpTex);
    ;
    if (doClear) {
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (gx->zmode);
        ;
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (gx->cmode0);
        ;
    }
    if (check) {
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (gx->peCtrl);
        ;
    }
    gx->bpSentNot = ((GXBool)0);
}

static inline void set_x2(u16 value) { gx->bpSentNot = value; }

void GXClearBoundingBox(void) {
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = 0x550003FF;
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = 0x560003FF;
    set_x2(((GXBool)0));
}
