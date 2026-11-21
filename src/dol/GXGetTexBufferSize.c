#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include "types.h"
#include <types.h>
#include "sdk_addresses.h"

// The write-gather pipe is a memory-mapped hardware register.
#define GX_FIFO_U8 (*(volatile u8 *)0xCC008000u) // fzgx-allow: A2 hardware register
#define GX_FIFO_U32 (*(volatile u32 *)0xCC008000u) // fzgx-allow: A2 hardware register

void fn_80035960(s32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, s32 arg6);

typedef enum _GXCITexFmt { GX_TF_C4 = 8, GX_TF_C8, GX_TF_C14X2 } GXCITexFmt;

static inline void __GXGetTexTileShift(GXTexFmt format, u32 *widthTiles, u32 *heightTiles) {
    switch (format) {
    case GX_TF_I4:
    case GX_TF_C4:
    case GX_TF_CMPR:
    case GX_CTF_R4:
    case GX_CTF_Z4:
        *widthTiles = 3;
        *heightTiles = 3;
        break;
    case GX_TF_I8:
    case GX_TF_IA4:
    case GX_TF_C8:
    case GX_TF_Z8:
    case GX_CTF_RA4:
    case GX_CTF_R8:
    case GX_CTF_G8:
    case GX_CTF_B8:
    case GX_CTF_RG8:
    case GX_CTF_Z8M:
    case GX_CTF_Z8L:
        *widthTiles = 3;
        *heightTiles = 2;
        break;
    case GX_TF_IA8:
    case GX_TF_RGB565:
    case GX_TF_RGB5A3:
    case GX_TF_RGBA8:
    case GX_TF_C14X2:
    case GX_TF_Z16:
    case GX_TF_Z24X8:
    case GX_CTF_RA8:
    case GX_CTF_GB8:
    case 44:
    case GX_CTF_Z16L:
        *widthTiles = 2;
        *heightTiles = 2;
        break;
    default:
        *heightTiles = 0;
        *widthTiles = 0;
        break;
    }
}

u32 GXGetTexBufferSize(u16 width, u16 height, u32 format, GXBool mipmap, u8 max_lod) {
    u32 widthTiles, heightTiles, tileSize, bufferSize, numX, numY, i;
    __GXGetTexTileShift(format, &widthTiles, &heightTiles);
    if (format == GX_TF_RGBA8 || format == GX_TF_Z24X8) {
        tileSize = 0x40;
    } else {
        tileSize = 0x20;
    }
    if (mipmap == ((GXBool)1)) {
        bufferSize = 0;
        for (i = 0; i < max_lod; i++) {
            numX = (((width) + (1 << (widthTiles)) - 1) >> (widthTiles));
            numY = (((height) + (1 << (heightTiles)) - 1) >> (heightTiles));
            bufferSize += numX * numY * tileSize;
            if (width == 1 && height == 1) {
                break;
            }
            width = (width > 1) ? (width >> 1) : 1;
            height = (height > 1) ? (height >> 1) : 1;
        }
    } else {
        numX = (((width) + (1 << (widthTiles)) - 1) >> (widthTiles));
        numY = (((height) + (1 << (heightTiles)) - 1) >> (heightTiles));
        bufferSize = numX * numY * tileSize;
    }
    return bufferSize;
}

void __GetImageTileCount(GXTexFmt format, u16 width, u16 height, u32 *a, u32 *b, u32 *c) {
    u32 widthTiles, heightTiles;
    __GXGetTexTileShift(format, &widthTiles, &heightTiles);
    if (width <= 0) {
        width = 1;
    }
    if (height <= 0) {
        height = 1;
    }
    *a = (((width) + (1 << (widthTiles)) - 1) >> (widthTiles));
    *b = (((height) + (1 << (heightTiles)) - 1) >> (heightTiles));
    *c = (format == GX_TF_RGBA8 || format == GX_TF_Z24X8) ? 2 : 1;
}

typedef enum _GXTexWrapMode {
    GX_CLAMP,
    GX_REPEAT,
    GX_MIRROR,
    GX_MAX_TEXWRAPMODE,
} GXTexWrapMode;

typedef struct __GXTexObjInt_struct {
    u32 mode0;
    u32 mode1;
    u32 image0;
    u32 image3;
    void *userData;
    GXTexFmt fmt;
    u32 tlutName;
    u16 loadCnt;
    u8 loadFmt;
    u8 flags;
} __GXTexObjInt;

void (*DVDLowClearCallback())(u32);

void GXInitTexObj(GXTexObj *obj, void *image_ptr, u16 width, u16 height, GXTexFmt format,
                 GXTexWrapMode wrap_s, GXTexWrapMode wrap_t, u8 mipmap) {
    u32 imageBase;
    u32 maxLOD;
    u16 rowT;
    u16 colT;
    u32 rowC;
    u32 colC;
    __GXTexObjInt *t = (__GXTexObjInt *)obj;
    memset(t, 0, 0x20);
    do {
        (t->mode0) = ((u32)(t->mode0) & ~(((1 << (2)) - 1) << (0))) | ((u32)(wrap_s) << (0));
    } while (0);
    do {
        (t->mode0) = ((u32)(t->mode0) & ~(((1 << (2)) - 1) << (2))) | ((u32)(wrap_t) << (2));
    } while (0);
    do {
        (t->mode0) = ((u32)(t->mode0) & ~(((1 << (1)) - 1) << (4))) | ((u32)(1) << (4));
    } while (0);
    if (mipmap != 0) {
        u8 lmax;
        t->flags |= 1;
        if ((u32)format - 8 <= 2)
            t->mode0 = (t->mode0 & 0xFFFFFF1F) | 0xA0;
        else
            t->mode0 = (t->mode0 & 0xFFFFFF1F) | 0xC0;
        if (width > height) {
            maxLOD = 31 - __cntlzw(width);
        } else {
            maxLOD = 31 - __cntlzw(height);
        }
        lmax = 16.0f * maxLOD;
        do {
            (t->mode1) = ((u32)(t->mode1) & ~(((1 << (8)) - 1) << (8))) | ((u32)(lmax) << (8));
        } while (0);
    } else {
        t->mode0 = (t->mode0 & 0xFFFFFF1F) | 0x80;
    }
    t->fmt = format;
    do {
        (t->image0) = ((u32)(t->image0) & ~(((1 << (10)) - 1) << (0))) | ((u32)(width - 1) << (0));
    } while (0);
    do {
        (t->image0) =
            ((u32)(t->image0) & ~(((1 << (10)) - 1) << (10))) | ((u32)(height - 1) << (10));
    } while (0);
    do {
        (t->image0) =
            ((u32)(t->image0) & ~(((1 << (4)) - 1) << (20))) | ((u32)(format & 0xF) << (20));
    } while (0);
    imageBase = (u32)((u32)image_ptr >> 5) & 0x01FFFFFF;
    do {
        (t->image3) = ((u32)(t->image3) & ~(((1 << (21)) - 1) << (0))) | ((u32)(imageBase) << (0));
    } while (0);
    switch (format & 0xF) {
    case 0:
    case 8:
        t->loadFmt = 1;
        rowT = 3;
        colT = 3;
        break;
    case 1:
    case 2:
    case 9:
        t->loadFmt = 2;
        rowT = 3;
        colT = 2;
        break;
    case 3:
    case 4:
    case 5:
    case 10:
        t->loadFmt = 2;
        rowT = 2;
        colT = 2;
        break;
    case 6:
        t->loadFmt = 3;
        rowT = 2;
        colT = 2;
        break;
    case 14:
        t->loadFmt = 0;
        rowT = 3;
        colT = 3;
        break;
    default:
        t->loadFmt = 2;
        rowT = 2;
        colT = 2;
        break;
    }
    rowC = (width + (1 << rowT) - 1) >> rowT;
    colC = (height + (1 << colT) - 1) >> colT;
    t->loadCnt = (rowC * colC) & 0x7FFF;
    t->flags |= 2;
}

extern u8 lbl_801A6570[6];

void GXInitTexObjLOD(GXTexObj *obj, GXTexFilter minFilter, GXTexFilter maxFilter, f32 minLOD,
                 f32 maxLOD, f32 lodBias, GXBool doBiasClamp, GXBool doEdgeLOD,
                 GXAnisotropy maxAniso) {
    GXTexObj *internal = (GXTexObj *)obj;
    u8 reg1, reg2;
    if (lodBias < -4.0f) {
        lodBias = -4.0f;
    } else if (lodBias >= 4.0f) {
        lodBias = 3.99f;
    }
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((22 - 15 + 1))) - 1) << (31 - (15) - ((22 - 15 + 1)) + 1))) |
        ((int)((u8)(lodBias * 32.0f)) << (31 - (15) - ((22 - 15 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((27 - 27 + 1))) - 1) << (31 - (27) - ((27 - 27 + 1)) + 1))) |
        ((int)(maxFilter == 1 ? 1 : 0) << (31 - (27) - ((27 - 27 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((26 - 24 + 1))) - 1) << (31 - (24) - ((26 - 24 + 1)) + 1))) |
        ((int)(lbl_801A6570[minFilter]) << (31 - (24) - ((26 - 24 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((23 - 23 + 1))) - 1) << (31 - (23) - ((23 - 23 + 1)) + 1))) |
        ((int)(doEdgeLOD ? 0 : 1) << (31 - (23) - ((23 - 23 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((14 - 14 + 1))) - 1) << (31 - (14) - ((14 - 14 + 1)) + 1))) |
        ((int)(0) << (31 - (14) - ((14 - 14 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((13 - 13 + 1))) - 1) << (31 - (13) - ((13 - 13 + 1)) + 1))) |
        ((int)(0) << (31 - (13) - ((13 - 13 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((12 - 11 + 1))) - 1) << (31 - (11) - ((12 - 11 + 1)) + 1))) |
        ((int)(maxAniso) << (31 - (11) - ((12 - 11 + 1)) + 1));
    (internal->texture_filter) =
        (internal->texture_filter &
         ~(((1 << ((10 - 10 + 1))) - 1) << (31 - (10) - ((10 - 10 + 1)) + 1))) |
        ((int)(doBiasClamp) << (31 - (10) - ((10 - 10 + 1)) + 1));
    if (minLOD < 0.0f) {
        minLOD = 0.0f;
    } else if (minLOD > 10.0f) {
        minLOD = 10.0f;
    }
    reg1 = minLOD * 16.0f;
    if (maxLOD < 0.0f) {
        maxLOD = 0.0f;
    } else if (maxLOD > 10.0f) {
        maxLOD = 10.0f;
    }
    reg2 = maxLOD * 16.0f;
    (internal->texture_lod) = (internal->texture_lod & ~(((1 << ((31 - 24 + 1))) - 1)
                                                         << (31 - (24) - ((31 - 24 + 1)) + 1))) |
                              ((int)(reg1) << (31 - (24) - ((31 - 24 + 1)) + 1));
    (internal->texture_lod) = (internal->texture_lod & ~(((1 << ((23 - 16 + 1))) - 1)
                                                         << (31 - (16) - ((23 - 16 + 1)) + 1))) |
                              ((int)(reg2) << (31 - (16) - ((23 - 16 + 1)) + 1));
}

void fn_80036058(struct fn_80036058_Arg0 *arg0, u32 arg1) {
    arg0->unk_C = ((arg0->unk_C & ~0x1FFFFF) | ((arg1 >> 5) & 0x1FFFFFF));
}

void fn_80036070(const Fn80036070Data *data, u32 *out_scaled, u16 *out_width, u16 *out_height,
                 u32 *out_value, u32 *out_flags_low, u32 *out_flags_high, u8 *out_enabled) {
    *out_scaled = (data->scaled_value & 0x001FFFFFu) << 5;
    *out_width = (u16)((data->dimensions & 0x3FFu) + 1);
    *out_height = (u16)(((data->dimensions >> 10) & 0x3FFu) + 1);
    *out_value = data->value_14;
    *out_flags_low = data->flags & 3u;
    *out_flags_high = (data->flags >> 2) & 3u;
    *out_enabled = (u8)(!((data->enabled & 1u) - 1u));
}

u32 fn_800360D8(struct fn_800360D8_Arg0 *arg0) {
    return ((arg0->unk_C & 0x1FFFFF) << 5);
}

u32 GXGetTexObjWidth(struct GXGetTexObjWidth_Arg0 *arg0) {
    return ((arg0->unk_8 & 0x3FF) + 1);
}

u32 GXGetTexObjHeight(struct GXGetTexObjHeight_Arg0 *arg0) {
    return (((arg0->unk_8 >> 10) & 0x3FF) + 1);
}

u32 fn_80036104(struct fn_80036104_Arg0 *arg0) {
    return arg0->unk_14;
}

extern u8 lbl_801A6578[8];
extern const f64 lbl_801A70C0;
extern const f32 lbl_801A70E0;
extern const f64 lbl_801A70E8;
extern const f32 lbl_801A70E4;

void fn_8003610C(const Fn8003610CData *data, u32 *out_table, u32 *out_bit,
                 f32 *out_low, f32 *out_high, f32 *out_signed,
                 u8 *out_flag, u8 *out_inverse, u32 *out_bits) {
    int sign;
    *out_table = lbl_801A6578[(data->flags >> 5) & 7u];
    *out_bit = (data->flags >> 4) & 1u;
    *out_low = (f32)(data->packed & 0xffu) * lbl_801A70E0;
    *out_high = (f32)((data->packed >> 8) & 0xffu) * lbl_801A70E0;
    sign = (data->flags >> 9) & 0xff;
    *out_signed = (f32)(s8)(s16)sign * lbl_801A70E4;
    *out_flag = (u8)((data->flags >> 21) & 1u);
    *out_inverse = (u8)!((data->flags >> 8) & 1u);
    *out_bits = (data->flags >> 19) & 3u;
}

void fn_800361F0(GXTexObj *obj, GXTexRegion *region, GXTexMapID map);

extern u8 lbl_801A6538[8];

extern u8 lbl_801A6540[8];

extern u8 lbl_801A6548[8];

extern u8 lbl_801A6550[8];

extern u8 lbl_801A6558[8];

extern u8 lbl_801A6560[8];

extern u8 lbl_801A6568[8];

void fn_800361F0(GXTexObj *obj, GXTexRegion *region, GXTexMapID map) {
    GXTexObj *internalObj = (GXTexObj *)obj;
    GXTexRegion *internalRegion = (GXTexRegion *)region;
    (internalObj->texture_filter) =
        (internalObj->texture_filter &
         ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
        ((int)(lbl_801A6538[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
    (internalObj->texture_lod) = (internalObj->texture_lod &
                                  ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
                                 ((int)(lbl_801A6540[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
    (internalObj->texture_size) =
        (internalObj->texture_size &
         ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
        ((int)(lbl_801A6548[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
    (internalRegion->unk0) =
        (internalRegion->unk0 & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
        ((int)(lbl_801A6550[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
    (internalRegion->unk4) =
        (internalRegion->unk4 & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
        ((int)(lbl_801A6558[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
    (internalObj->texture_address) =
        (internalObj->texture_address &
         ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
        ((int)(lbl_801A6560[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (internalObj->texture_filter);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (internalObj->texture_lod);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (internalObj->texture_size);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (internalRegion->unk0);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (internalRegion->unk4);
    ;
    GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXWGFifo.s32 = (internalObj->texture_address);
    ;
    if ((internalObj->texture_flags & 2) == 0) {
        GXTlutObj *tlut = (GXTlutObj *)gx->tlutRegionCallback(internalObj->tlut_name);
        (tlut->address) =
            (tlut->address & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((int)(lbl_801A6568[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
        GXWGFifo.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXWGFifo.s32 = (tlut->address);
        ;
    }
    gx->tImage0[map] = internalObj->texture_size;
    gx->tMode0[map] = internalObj->texture_filter;
    gx->dirtyState |= GX_DIRTY_SU_TEX;
    gx->bpSentNot = ((GXBool)0);
}
