#include <types.h>
#include "types.h"
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>

/* --- dol/GXInitTexObjLOD.c --- */

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

/* --- dol/fn_80036058.c --- */

void fn_80036058(struct fn_80036058_Arg0 *arg0, u32 arg1) {
    arg0->unk_C = ((arg0->unk_C & ~0x1FFFFF) | ((arg1 >> 5) & 0x1FFFFFF));
}

/* --- dol/fn_80036070.c --- */

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

/* --- dol/fn_800360D8.c --- */
/* --- dol/fn_800360D8.c --- */

u32 fn_800360D8(struct fn_800360D8_Arg0 *arg0) {
    return ((arg0->unk_C & 0x1FFFFF) << 5);
}

/* --- dol/GXGetTexObjWidth.c --- */

u32 GXGetTexObjWidth(struct GXGetTexObjWidth_Arg0 *arg0) {
    return ((arg0->unk_8 & 0x3FF) + 1);
}

/* --- dol/GXGetTexObjHeight.c --- */

u32 GXGetTexObjHeight(struct GXGetTexObjHeight_Arg0 *arg0) {
    return (((arg0->unk_8 >> 10) & 0x3FF) + 1);
}

/* --- dol/fn_80036104.c --- */

u32 fn_80036104(struct fn_80036104_Arg0 *arg0) {
    return arg0->unk_14;
}

/* --- dol/fn_8003610C.c --- */

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

/* --- dol/fn_800361F0.c --- */

void fn_800361F0(GXTexObj *obj, GXTexRegion *region, GXTexMapID map);
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe GXFIFO : FZGX_ADDR_GXFIFO;

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
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (internalObj->texture_filter);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (internalObj->texture_lod);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (internalObj->texture_size);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (internalRegion->unk0);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (internalRegion->unk4);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (internalObj->texture_address);
    ;
    if ((internalObj->texture_flags & 2) == 0) {
        GXTlutObj *tlut = (GXTlutObj *)gx->tlutRegionCallback(internalObj->tlut_name);
        (tlut->address) =
            (tlut->address & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((int)(lbl_801A6568[map]) << (31 - (0) - ((7 - 0 + 1)) + 1));
        GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
        GXFIFO.s32 = (tlut->address);
        ;
    }
    gx->tImage0[map] = internalObj->texture_size;
    gx->tMode0[map] = internalObj->texture_filter;
    gx->dirtyState |= GX_DIRTY_SU_TEX;
    gx->bpSentNot = ((GXBool)0);
}
