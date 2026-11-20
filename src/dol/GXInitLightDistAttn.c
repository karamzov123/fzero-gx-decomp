#include "types.h"
#include "dolphin/gx.h"
#include "psvec_fifo.h"


/* --- dol/GXInitLightDistAttn.c --- */
typedef enum _GXDistAttnFn {
    GX_DA_OFF,
    GX_DA_GENTLE,
    GX_DA_MEDIUM,
    GX_DA_STEEP,
} GXDistAttnFn;

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

/* --- dol/fn_80035680.c --- */
/* --- dol/fn_80035680.c --- */
/* --- dol/fn_80035680.c --- */
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

/* --- dol/fn_80035690.c --- */
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

/* --- dol/fn_800356AC.c --- */
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

/* --- dol/fn_800356B8.c --- */
struct fn_800356B8_gx_T {
    u8 pad_0[0x2];
    u16 unk_2;
};
extern struct fn_800356B8_gx_T *gx;

void fn_800356B8(void *light_obj, u32 light_id) {
    u32 index;
    u32 addr;

    index = 31 - __cntlzw(light_id);
    addr = (index & 7) * 16 + 0x600;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = addr | 0xF0000;
    WriteLightObjPS(light_obj, &GXWGFifo);
    gx->unk_2 = 1;
}
