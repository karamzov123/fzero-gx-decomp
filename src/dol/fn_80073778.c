#include "types.h"
#include "dol/globals.h"


/* --- dol/fn_80073778.c --- */
typedef struct {
    u8 pad_00[0x20];
    u16 width;
    u16 height;
} TexEntry;

extern u16 GXGetTexObjWidth(void *obj);
extern u16 GXGetTexObjHeight(void *obj);
extern void GXLoadTexObj(void *obj, s32 index);

void fn_80073778(void *obj, s32 index) {
    TexEntry *entry;

    entry = (TexEntry *)(lbl_801A6D38 + index * 0x24 + 0x720);
    entry->width = GXGetTexObjWidth(obj);
    entry->height = GXGetTexObjHeight(obj);
    GXLoadTexObj(obj, index);
}

/* --- dol/fn_800737E4.c --- */
struct fn_800737E4_Arg0 {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    f32 unk_28;
    f32 unk_2C;
};

struct fn_800737E4_Local {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
};

extern f64 lbl_801A7468;
extern void fn_80072270(void *);

void fn_800737E4(struct fn_800737E4_Arg0 *arg0, s32 arg1) {
    struct fn_800737E4_Local local;

    local.unk_0 = (f32)arg1;
    switch (arg1) {
    case 0:
        local.unk_4 = arg0->unk_0;
        local.unk_8 = arg0->unk_8;
        local.unk_C = arg0->unk_14;
        local.unk_10 = arg0->unk_18;
        local.unk_14 = arg0->unk_28;
        local.unk_18 = arg0->unk_2C;
        break;
    default:
        local.unk_4 = arg0->unk_0;
        local.unk_8 = arg0->unk_C;
        local.unk_C = arg0->unk_14;
        local.unk_10 = arg0->unk_1C;
        local.unk_14 = arg0->unk_28;
        local.unk_18 = arg0->unk_2C;
        break;
    }
    fn_80072270(&local);
}
