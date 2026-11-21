#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include "types.h"
#include "psvec_fifo.h"
#include "dolphin/hw_regs.h"
#include <types.h>

typedef enum _GXSpotFn {
    GX_SP_OFF,
    GX_SP_FLAT,
    GX_SP_COS,
    GX_SP_COS2,
    GX_SP_SHARP,
    GX_SP_RING1,
    GX_SP_RING2,
} GXSpotFn;

typedef struct _GXLightObj {
    u32 dummy[16];
} GXLightObj;

struct __GXLightObjInt_struct {
    u32 reserved[3];
    u32 Color;
    f32 a[3];
    f32 k[3];
    f32 lpos[3];
    f32 ldir[3];
};

extern f32 fn_80088624(f32);

void fn_80035420(GXLightObj *lt_obj, f32 cutoff, GXSpotFn spot_func) {
    f32 a0, a1, a2;
    f32 d, cr;
    struct __GXLightObjInt_struct *obj;

    if (cutoff <= 0.0f || cutoff > 90.0f)
        spot_func = GX_SP_OFF;

    cr = fn_80088624((3.14159265358979323846f * cutoff) / 180.0f);

    obj = (struct __GXLightObjInt_struct *)lt_obj;

    switch (spot_func) {
    case GX_SP_FLAT:
        a0 = -1000.0f * cr;
        a1 = 1000.0f;
        a2 = 0.0f;
        break;
    case GX_SP_COS:
        a1 = 1.0f / (1.0f - cr);
        a0 = -cr * a1;
        a2 = 0.0f;
        break;
    case GX_SP_COS2:
        a2 = 1.0f / (1.0f - cr);
        a1 = -cr * a2;
        a0 = 0.0f;
        break;
    case GX_SP_SHARP:
        d = 1.0f / ((1.0f - cr) * (1.0f - cr));
        a0 = (cr * (cr - 2.0f)) * d;
        a1 = 2.0f * d;
        a2 = -d;
        break;
    case GX_SP_RING1:
        d = 1.0f / ((1.0f - cr) * (1.0f - cr));
        a2 = -4.0f * d;
        a0 = a2 * cr;
        a1 = (4.0f * (1.0f + cr)) * d;
        break;
    case GX_SP_RING2:
        d = 1.0f / ((1.0f - cr) * (1.0f - cr));
        a0 = (2.0f * cr * cr) * d;
        a0 = 1.0f - a0;
        a1 = (4.0f * cr) * d;
        a2 = -2.0f * d;
        break;
    case GX_SP_OFF:
    default:
        a0 = 1.0f;
        a1 = 0.0f;
        a2 = a1;
        break;
    }

    obj->a[0] = a0;
    obj->a[1] = a1;
    obj->a[2] = a2;
}

typedef enum _GXDistAttnFn {
    GX_DA_OFF,
    GX_DA_GENTLE,
    GX_DA_MEDIUM,
    GX_DA_STEEP,
} GXDistAttnFn;

void (*DVDLowClearCallback())(u32);

void GXInitLightDistAttn(GXLightObj *lt_obj, f32 ref_dist, f32 ref_br, GXDistAttnFn dist_func) {
    f32 k0, k1, k2;
    struct __GXLightObjInt_struct *obj;
    obj = (struct __GXLightObjInt_struct *)lt_obj;
    if (ref_dist < 0.0f)
        dist_func = GX_DA_OFF;
    if (ref_br <= 0.0f || ref_br >= 1.0f)
        dist_func = GX_DA_OFF;
    switch (dist_func) {
    case GX_DA_GENTLE:
        k0 = 1.0f;
        k1 = (1.0f - ref_br) / (ref_br * ref_dist);
        k2 = 0.0f;
        break;
    case GX_DA_MEDIUM:
        k0 = 1.0f;
        k1 = (0.5f * (1.0f - ref_br)) / (ref_br * ref_dist);
        k2 = (0.5f * (1.0f - ref_br)) / (ref_br * ref_dist * ref_dist);
        break;
    case GX_DA_STEEP:
        k0 = 1.0f;
        k1 = 0.0f;
        k2 = (1.0f - ref_br) / (ref_br * ref_dist * ref_dist);
        break;
    case GX_DA_OFF:
    default:
        k0 = 1.0f;
        k1 = 0.0f;
        k2 = 0.0f;
        break;
    }
    obj->k[0] = k0;
    obj->k[1] = k1;
    obj->k[2] = k2;
}

struct fn_80035680_Arg1 {
    u8 pad_0[0x28];
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
};

void fn_80035680(f32 arg0, struct fn_80035680_Arg1 *arg1, f32 arg2, f32 arg3) {
    arg1->unk_28 = arg0;
    arg1->unk_2C = arg2;
    arg1->unk_30 = arg3;
}

struct fn_80035690_Arg3 {
    u8 pad_0[0x34];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
};

f32 fn_80035690(f32 arg0, f32 arg1, f32 arg2, struct fn_80035690_Arg3 *arg3) {
    arg3->unk_34 = (-arg0);
    arg3->unk_38 = (-arg1);
    arg3->unk_3C = (-arg2);
    return (-arg1);
}

struct fn_800356AC_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};
struct fn_800356AC_Arg1 {
    u32 unk_0;
};

void fn_800356AC(struct fn_800356AC_Arg0 *arg0, struct fn_800356AC_Arg1 *arg1) {
    arg0->unk_C = arg1->unk_0;
}

void fn_800356B8(void *light_obj, u32 light_id) {
    u32 index;
    u32 addr;

    index = 31 - __cntlzw(light_id);
    addr = (index & 7) * 16 + 0x600;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = addr | 0xF0000;
    WriteLightObjPS(light_obj, &GXWGFifo);
    gx->bpSentNot = 1;
}

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((val) << (shift)))

void fn_80035734(s32 chan, GXColor color) {
    u32 reg;
    u32 rgb;
    u32 index;

    switch (chan) {
    case 0:
        reg = gx->ambColor[0];
        rgb = *(u32 *)&color >> 8;
        SET_REG_FIELD(reg, 24, 8, rgb);
        index = 0;
        break;
    case 1:
        reg = gx->ambColor[1];
        rgb = *(u32 *)&color >> 8;
        SET_REG_FIELD(reg, 24, 8, rgb);
        index = 1;
        break;
    case 2:
        reg = gx->ambColor[0];
        SET_REG_FIELD(reg, 8, 0, color.a);
        index = 0;
        break;
    case 3:
        reg = gx->ambColor[1];
        SET_REG_FIELD(reg, 8, 0, color.a);
        index = 1;
        break;
    case 4:
        reg = *(u32 *)&color;
        index = 0;
        break;
    case 5:
        reg = *(u32 *)&color;
        index = 1;
        break;
    default:
        return;
    }
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = index + 0x100a;
    GXWGFifo.u32 = reg;
    gx->bpSentNot = 1;
    gx->ambColor[index] = reg;
}

void fn_80035828(s32 chan, GXColor color) {
    u32 reg;
    u32 rgb;
    u32 index;

    switch (chan) {
    case 0:
        reg = gx->matColor[0];
        rgb = *(u32 *)&color >> 8;
        SET_REG_FIELD(reg, 24, 8, rgb);
        index = 0;
        break;
    case 1:
        reg = gx->matColor[1];
        rgb = *(u32 *)&color >> 8;
        SET_REG_FIELD(reg, 24, 8, rgb);
        index = 1;
        break;
    case 2:
        reg = gx->matColor[0];
        SET_REG_FIELD(reg, 8, 0, color.a);
        index = 0;
        break;
    case 3:
        reg = gx->matColor[1];
        SET_REG_FIELD(reg, 8, 0, color.a);
        index = 1;
        break;
    case 4:
        reg = *(u32 *)&color;
        index = 0;
        break;
    case 5:
        reg = *(u32 *)&color;
        index = 1;
        break;
    default:
        return;
    }
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = index + 0x100c;
    GXWGFifo.u32 = reg;
    gx->bpSentNot = 1;
    gx->matColor[index] = reg;
}

// The write-gather pipe is a memory-mapped hardware register.
#define GX_FIFO_U8 (*(volatile u8 *)0xCC008000u) // fzgx-allow: A2 hardware register
#define GX_FIFO_U32 (*(volatile u32 *)0xCC008000u) // fzgx-allow: A2 hardware register

void fn_8003591C(u8 value) {
    GXData * context = gx;
    context->genMode = (context->genMode & 0xffffff8fu) | ((u32)value << 4);
    GX_FIFO_U8 = 0x10;
    GX_FIFO_U32 = 0x1009;
    GX_FIFO_U32 = value;
    context->dirtyState |= 4;
}

// The write-gather pipe is a memory-mapped hardware register.
#define GX_FIFO_U8 (*(volatile u8 *)0xCC008000u) // fzgx-allow: A2 hardware register
#define GX_FIFO_U32 (*(volatile u32 *)0xCC008000u) // fzgx-allow: A2 hardware register

void fn_80035960(s32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, s32 arg6) {
    u32 idx = arg0 & 3;
    u32 b1;
    u32 b2;
    u32 v;

    v = ((arg1 & 0xFF) << 1) | arg3;
    v = (v & 0xFFFFFFBF) | (arg2 << 6);
    if (arg6 == 0) {
        arg5 = 0;
    }
    b1 = (arg6 != 2);
    b2 = (arg6 != 0);
    v = (v & 0xFFFFFE7F) | (arg5 << 7);
    v = (v & 0xFFFFFDFF) | (b1 << 9);
    v = (v & 0xFFFFFBFF) | (b2 << 10);
    v = (v & 0xFFFFFFC3) | ((arg4 << 2) & 0x3C);
    v = (v & 0xFFFF87FF) | ((arg4 << 7) & 0x7800);
    GX_FIFO_U8 = 0x10;
    GX_FIFO_U32 = idx + 0x100E;
    GX_FIFO_U32 = v;
    if (arg0 == 4) {
        GX_FIFO_U8 = 0x10;
        GX_FIFO_U32 = 0x1010;
        GX_FIFO_U32 = v;
    } else if (arg0 == 5) {
        GX_FIFO_U8 = 0x10;
        GX_FIFO_U32 = 0x1011;
        GX_FIFO_U32 = v;
    }
    gx->bpSentNot = 1;
}
