#include "types.h"
#include "rel/main_rel/globals.h"
#include "game/vec3.h"

/* A loaded model resource as the loader functions return it. */
typedef struct {
    u32 unk_00;
    void *resource;
} MdlEntry;

typedef struct {
    s32 count; /* 0x00 */
    u8 unk_04[4];
    MdlEntry *entries; /* 0x08 */
    u32 unk_0C;
    u32 flags; /* 0x10 */
} MdlModel;

typedef struct { u32 dummy[8]; } MdlTexObj;

typedef struct {
    Vec3 pos;
    Vec3 vel;
    Vec3 scale;
    f32 value;
    s16 phase;
    s16 step;
    s16 count;
} MdlSpark;

extern u32 lbl_801A63C0;
extern u32 lbl_801A66A0;
extern void *lbl_801A6410;
extern void *lbl_801A6D00;
extern u8 lbl_1_bss_3BC0[32];
extern u8 lbl_1_bss_6D620[0x78];

extern void *OSGetArenaHi(void);
extern void DCFlushRange(void *address, u32 length);
extern void fn_80008BEC(void *dst, int value, u32 size);
extern void *fn_80071100(void *data, void *base, void *user);
extern void *fn_80071484(void *name);
extern void *fn_80071678(void *data, void *base);
extern f32 lbl_8006D188(s32 angle);
extern f32 lbl_8006D0B4(f32 value);
/* SMB1 mathutil_vec_normalize_len (DOL mathutil asm) */
extern f32 lbl_8006D668(void *v);
extern f32 lbl_8006D6FC(Vec3 *a, Vec3 *b);
/* SMB1 mathutil_mtxA_tf_vec (DOL mathutil asm) */
extern void lbl_8006E1C0(Vec3 *src, Vec3 *dst);
extern void GXInitTexObj(MdlTexObj *obj, void *image, u16 width, u16 height, int format, int wrapS, int wrapT, u8 mipmap);
extern void GXInitTexObjLOD(MdlTexObj *obj, int minFilt, int magFilt, f32 minLod, f32 maxLod, f32 lodBias, u8 biasClamp,
                            u8 edgeLod, int maxAniso);
extern void GXInvalidateTexAll(void);
extern void GXLoadTexMtxImm(f32 (*mtx)[4], s32 id, s32 type);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_800734A8(s32, s32, s32, s32);
extern void fn_80073778(void *, s32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_800739E0(s32, s32, s32);
extern void fn_80073E8C(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void fn_800745A4(s32, s32, s32, s32, s32, s32);

extern void *fn_1_45D0(void *heap, u32 size, const char *file, s32 line);
extern void fn_1_46B4(void *heap, void *ptr, const char *file, s32 line);
extern int fn_1_45730(void *name, void *file);
extern int fn_1_458A0(void *file, void *buffer, u32 size, u32 offset);
extern int fn_1_45850(void *file);
extern void fn_1_12860(void *src, void *dst);
extern void fn_1_12F78(void *file, void *dst);
extern s32 fn_1_58C4(void);
extern u32 fn_1_5910(void);
extern void fn_1_5948(s32 index);
extern void fn_1_627C(s32 index);
extern s32 fn_1_66B8(void *pos, f32 radius);
extern void fn_1_681C(u8 index, void *out);
extern void fn_1_6898(u8 index, void *out);
extern void fn_1_6914(u8 index, void *out);
extern void fn_1_6990(u8 index, void *out);
extern s32 fn_1_6EC0(u8 index);
extern s32 fn_1_7000(void);
extern s32 fn_1_1FB80(void *data, s32 mode);
extern s16 fn_1_3F0C8(void);
extern u32 fn_1_539CC(void *a, void *b, f32 t);
extern void fn_1_862A8(s32 mode, Vec3 *out);
extern void fn_1_8636C(s32 mode, void *out);
extern u32 fn_1_864E8(s32 mode);
extern f32 fn_1_8652C(s32 mode);
extern void fn_1_9A508(void);
extern void fn_1_9A7A8(u32 *color);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(Obj_1_data_2A7E0 *obj);
extern void *fn_1_9D260(void);
extern void fn_1_A714C(f32 *, f32 *, f32 *, f32 *);
extern f32 fn_1_A71AC(void);
extern void fn_1_103090(void *ptr);
extern void fn_1_1030A4(void *ptr);
extern void fn_1_1030D4(void *ptr, void *arg);
extern void fn_1_103264(void *ptr, void *arg);
extern void fn_1_105AB8(void *base, s32 index);
extern void fn_1_106084(u32, int, f32, f32, f32);
extern void fn_1_1067A8(void *obj, f32 value, f32 limit);
extern s16 camera_get_mode(void);
extern void fn_1_D6748(void *obj, u32 *arg1, s16 arg2);

void *fn_1_D3B6C(MdlModel *model);
void fn_1_D3BE8(void *resource);
void fn_1_D3F24(void *base);
void fn_1_D3F88(void *base);
s32 fn_1_D3E90(void);
void fn_1_D4174(void *base, void *arg);
void fn_1_D47D8(void *state, s32 index);
void fn_1_D4360(void *state);
void fn_1_D4964(u32 arg0);
void fn_1_D5958(void *state);
void fn_1_D42A8(u32, int);
void fn_1_D4FFC(u8 *base, u32 index);
void fn_1_D47F0(void *base, u32 index);
struct fn_1_D59A8_obj;
void fn_1_D59A8(struct fn_1_D59A8_obj *obj);
void fn_1_D4370(void *arg0);
void fn_1_D41D8(void);
void fn_1_D3FDC(void *arg0, void *arg1);
void fn_1_D523C(void *state);
void fn_1_D550C(void *arg);

extern u8 lbl_1_bss_7AD58;
s32 lbl_1_bss_7AD60;
s32 lbl_1_bss_7AD64;
s32 lbl_1_bss_7AD68;
s32 lbl_1_bss_7AD6C;
s32 lbl_1_bss_7AD70;

/* fzgx:begin fn_1_D35D4 */
void *fn_1_D35D4(void *name, void *user) {
    u8 local[0x58];
    u32 size1;
    u32 size0;
    void *buffer1;
    u8 *data;
    void *buffer0;
    MdlModel *object;

    if (fn_1_45730(name, local) == 0) {
        return 0;
    }
    if (fn_1_458A0(local, lbl_1_bss_3BC0, 32, 0) < 0) {
        return 0;
    }

    size0 = (__lwbrx(lbl_1_bss_3BC0, 0) + 39) & ~31;
    size1 = (__lwbrx(lbl_1_bss_3BC0, 4) + 31) & ~31;

    buffer0 = fn_1_45D0(lbl_801A6410, ((size1 + 31) & ~31) + 32, "mdlload.c", 0x7a);
    data = (u8 *)buffer0 + 32;
    if (data == 0) {
        return 0;
    }
    buffer1 = fn_1_45D0(lbl_801A6410, size0, "mdlload.c", 0x80);
    if (buffer1 == 0) {
        return 0;
    }
    if (fn_1_458A0(local, buffer1, size0, 0) < 0) {
        return 0;
    }
    if (fn_1_45850(local) == 0) {
        return 0;
    }
    fn_1_12860(buffer1, data);
    fn_1_46B4(lbl_801A6410, buffer1, "mdlload.c", 0x8e);
    DCFlushRange(data, size1);
    object = fn_80071100(data, buffer0, user);
    object->flags &= ~1;
    return fn_1_D3B6C(object);
}
/* fzgx:end fn_1_D35D4 */

/* fzgx:begin fn_1_D3768 */
// Loads, prepares, and submits the owner's model payload.
void *fn_1_D3768(void *name, void *user) {
    u8 buffer[0x58];
    u32 data_size;
    MdlModel *result;
    u32 aligned_size;
    void *data;

    if (fn_1_45730(name, buffer) == 0) {
        return 0;
    }
    if (fn_1_458A0(buffer, lbl_1_bss_3BC0, 32, 0) < 0) {
        return 0;
    }

    (void)__lwbrx(lbl_1_bss_3BC0, 0);
    data_size = __lwbrx(lbl_1_bss_3BC0, 4);
    aligned_size = (data_size + 0x1f) & ~0x1f;
    data = fn_1_45D0(lbl_801A6410, ((aligned_size + 0x1f) & ~0x1f) + 0x20, "mdlload.c", 0x7a);
    result = (MdlModel *)((u8 *)data + 0x20);
    if (result == 0) {
        return 0;
    }
    if (fn_1_45850(buffer) == 0) {
        return 0;
    }

    fn_1_12F78(name, result);
    DCFlushRange(result, aligned_size);
    result = fn_80071100(result, data, user);
    result->flags &= ~1;
    return fn_1_D3B6C(result);
}
/* fzgx:end fn_1_D3768 */

/* fzgx:begin fn_1_D3884 */
void *fn_1_D3884(void *name) {
    return fn_80071484(name);
}
/* fzgx:end fn_1_D3884 */

/* fzgx:begin fn_1_D38A4 */
void *fn_1_D38A4(void *data, void *base) {
    return fn_80071678(data, base);
}
/* fzgx:end fn_1_D38A4 */

/* fzgx:begin fn_1_D38C4 */
void *fn_1_D38C4(void *name) {
    u8 path[96];
    u32 size2;
    u32 size;
    void *data2;
    void *aligned;
    void *data;
    MdlModel *result;

    if (fn_1_45730(name, path) == 0) {
        return 0;
    }
    if (fn_1_458A0(path, lbl_1_bss_3BC0, 0x20, 0) < 0) {
        return 0;
    }

    size = (__lwbrx(lbl_1_bss_3BC0, 0) + 0x27) & ~0x1f;
    size2 = (__lwbrx(lbl_1_bss_3BC0, 4) + 0x1f) & ~0x1f;

    data = fn_1_45D0(lbl_801A6410, ((size2 + 0x1f) & ~0x1f) + 0x20, "mdlload.c", 0x1d6);
    aligned = (void *)(((u32)data + 0x3f) & ~0x1f);
    if (aligned == 0) {
        return 0;
    }
    data2 = fn_1_45D0(lbl_801A6410, size, "mdlload.c", 0x1dc);
    if (data2 == 0) {
        return 0;
    }
    if (fn_1_458A0(path, data2, size, 0) < 0) {
        return 0;
    }
    if (fn_1_45850(path) == 0) {
        return 0;
    }

    fn_1_12860(data2, aligned);
    fn_1_46B4(lbl_801A6410, data2, "mdlload.c", 0x1ea);
    DCFlushRange(aligned, size2);

    result = fn_80071678(aligned, data);
    result->unk_0C = 0;
    return result;
}
/* fzgx:end fn_1_D38C4 */

/* fzgx:begin fn_1_D3A4C */
void *fn_1_D3A4C(void *name) {
    u8 buffer[96];
    u32 result;
    u32 size;
    u32 ptr;
    u32 value0;
    u32 value1;

    if (fn_1_45730(name, buffer) == 0) {
        return 0;
    }
    if (fn_1_458A0(buffer, lbl_1_bss_3BC0, 32, 0) < 0) {
        return 0;
    }

    value0 = __lwbrx(lbl_1_bss_3BC0, 0);
    value1 = __lwbrx(lbl_1_bss_3BC0, 4);
    size = (value1 + 31) & ~31;
    ptr = (u32)fn_1_45D0(lbl_801A6410, (((size + 31) & ~31) + 32), "mdlload.c", 470);
    result = (ptr + 63) & ~31;
    if (result == 0) {
        return 0;
    }
    if (fn_1_45850(buffer) == 0) {
        return 0;
    }

    fn_1_12F78(name, (void *)result);
    DCFlushRange((void *)result, size);
    ptr = (u32)fn_80071678((void *)result, (void *)ptr);
    ((MdlModel *)ptr)->unk_0C = 0;
    return (void *)ptr;
}
/* fzgx:end fn_1_D3A4C */

/* fzgx:begin fn_1_D3B6C */
/* Release the model's resources only when it resides above the arena high-water mark. */
// Release the list's resources only when it resides above the arena high-water mark.
void *fn_1_D3B6C(MdlModel *model) {
    s32 index;

    if (model != 0 && model > (MdlModel *)OSGetArenaHi()) {
        for (index = 0; index < model->count; index++) {
            fn_1_D3BE8(model->entries[index].resource);
        }
    }

    return model;
}
/* fzgx:end fn_1_D3B6C */

/* fzgx:begin fn_1_D3BE8 */
// Increment the model-loader byte counter.
void fn_1_D3BE8(void *resource) {
    lbl_1_bss_7AD58++;
}
/* fzgx:end fn_1_D3BE8 */

/* fzgx:begin fn_1_D3C00 */
// fn_1_D3C00: empty in retail (single blr).
void fn_1_D3C00(void) {
}
/* fzgx:end fn_1_D3C00 */

/* fzgx:begin fn_1_D3C04 */
void fn_1_D3C04(void) {
    void *state = lbl_1_data_2A7E0.unk_3C;

    *(u32 *)((u8 *)state + 0xE7E0) = 0;
    fn_1_9A508();
    fn_1_D3F24(state);
    *(u32 *)((u8 *)state + 0xFD64) = (u32)-1;
}
/* fzgx:end fn_1_D3C04 */

/* fzgx:begin fn_1_D3C58 */
/* Initializes the model-loader state for every available entry. */
void fn_1_D3C58(void) {
    Obj_1_data_2A7E0_At3C *state;
    s32 count;
    s32 index;

    state = lbl_1_data_2A7E0.unk_3C;
    count = fn_1_58C4();
    for (index = 0; index < count; index++) {
        fn_1_5948(index);
        fn_1_105AB8(&state->unk_20, index);
        fn_1_D47D8(state, index);
        fn_1_627C(index);
    }
    fn_1_D5958(state);
    fn_1_D4360(state);
    fn_1_D4964((u32)state);
}
/* fzgx:end fn_1_D3C58 */

/* fzgx:begin fn_1_D3CF4 */
void fn_1_D3CF4(void) {
    int count;
    int i;
    u32 obj;
    void *t1;

    obj = (u32)lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    t1 = fn_1_9D260();
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_D42A8(obj, i);
        if (fn_1_D3E90() == 0) {
            fn_1_106084(obj + 0x20, i, *(f32 *)(obj + 0xC040), ((f32 *)obj)[i], 30.0f);
        }
        fn_1_D4FFC((u8 *)obj, i);
        fn_1_D47F0((void *)obj, i);
        fn_1_627C(i);
    }
    fn_1_D59A8((void *)obj);
    fn_1_D4370((void *)obj);
    fn_1_D41D8();
    fn_1_D3FDC((void *)obj, t1);
}
/* fzgx:end fn_1_D3CF4 */

/* fzgx:begin fn_1_D3DDC */
void fn_1_D3DDC(void) {
    fn_1_D3F88(lbl_1_data_2A7E0.unk_3C);
}
/* fzgx:end fn_1_D3DDC */

/* fzgx:begin fn_1_D3E08 */
/* Refreshes the model state and applies the indexed limit when loading is inactive. */
void fn_1_D3E08(void) {
    u32 model_index;
    Obj_1_data_2A7E0_At3C *model;
    void *update_value;

    model_index = fn_1_5910();
    model = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD88(&lbl_1_data_2A7E0);
    update_value = fn_1_9D260();

    if (fn_1_D3E90() == 0) {
        fn_1_1067A8(&model->unk_20, ((f32 *)model)[model_index], 30.0f);
    }

    fn_1_D4174(model, update_value);
}
/* fzgx:end fn_1_D3E08 */

/* fzgx:begin fn_1_D3E8C */
// fn_1_D3E8C: empty in retail (single blr).
void fn_1_D3E8C(void) {
}
/* fzgx:end fn_1_D3E8C */

/* fzgx:begin fn_1_D3E90 */
s32 fn_1_D3E90(void) {
    s16 value;
    u8 data[8];

    value = camera_get_mode();
    if (value != -1 && fn_1_6EC0(fn_1_5910()) != 0 &&
        (fn_1_864E8(value) & 0x20) != 0) {
        return 1;
    }

    if (fn_1_7000() != 0) {
        return 1;
    }

    fn_1_681C(fn_1_5910(), data);
    return fn_1_1FB80(data, 1);
}
/* fzgx:end fn_1_D3E90 */

/* fzgx:begin fn_1_D3F24 */
void fn_1_D3F24(void *base) {
    s32 value;
    s32 count;
    char *ptr;

    value = 1;
    ptr = (char *)base + 0x10000;
    count = *(s32 *)(ptr - 0x1820);
    ptr -= 0x181c;

    while (count > 0) {
        *(s32 *)(ptr + 0x68) = value;
        fn_1_103090(ptr);
        count--;
        ptr += 0xac;
    }
}
/* fzgx:end fn_1_D3F24 */

/* fzgx:begin fn_1_D3F88 */
// Iterate through items in a structure, calling fn_1_1030A4 on each.
void fn_1_D3F88(void *base) {
    s32 count;
    char *ptr;

    ptr = (char *)base + 0x10000;
    count = *(s32 *)(ptr - 0x1820);
    ptr -= 0x181c;

    while (count > 0) {
        fn_1_1030A4(ptr);
        count--;
        ptr += 0xac;
    }
}
/* fzgx:end fn_1_D3F88 */

/* fzgx:begin fn_1_D3FDC */
typedef struct ColorEntry {
    u8 pad0[8];
    u32 flags;
    u8 padC[0x20];
    f32 red;
    f32 green;
    f32 blue;
    u8 pad38[0x74];
} ColorEntry;

void fn_1_D3FDC(void *arg0, void *arg1) {
    s32 count;
    ColorEntry *entry = (ColorEntry *)((u8 *)arg0 + 0xE7E4);
    count = *(s32 *)((u8 *)arg0 + 0xE7E0);
    while (count > 0) {
        if ((entry->flags >> 28) & 1) {
            entry->red = 0.65f;
            entry->green = 0.75f;
            entry->blue = 1.0f;
        } else if ((entry->flags >> 29) & 1) {
            entry->red = 1.0f;
            entry->green = 0.0f;
            entry->blue = 0.0f;
        } else {
            entry->red = __fabs(lbl_8006D188((182.04444885253906f * lbl_801A66A0)));
            entry->green = __fabs(lbl_8006D188((0.5 * (182.04444885253906f * lbl_801A66A0))));
            entry->blue = __fabs(lbl_8006D188((2.0 * (182.04444885253906f * lbl_801A66A0))));
        }
        fn_1_1030D4(entry, arg1);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D3FDC */

/* fzgx:begin fn_1_D4174 */
/* Process each model-load entry in the caller-provided table. */
void fn_1_D4174(void *base, void *arg) {
    s32 remaining;
    char *entry;

    entry = (char *)base + 0x10000;
    remaining = *(s32 *)(entry - 0x1820);
    entry -= 0x181c;

    while (remaining > 0) {
        fn_1_103264(entry, arg);
        remaining--;
        entry += 0xac;
    }
}
/* fzgx:end fn_1_D4174 */

/* fzgx:begin fn_1_D41D8 */
typedef struct {
    u8 pad_0[0xC];
    s16 unk_C;
    s16 unk_E;
    u8 pad_10[0x4];
    u32 unk_14;
    u8 pad_18[0x8];
    u32 unk_20;
} MdlloadItem;

void fn_1_D41D8(void) {
    Obj_1_bss_3BE0_Target **root;
    s32 i;
    MdlloadItem *item;

    if (fn_1_3F0C8() == 0x28) {
        return;
    }

    root = &lbl_1_bss_3BE0;
    i = 0;
    item = (MdlloadItem *)(*root)->unk_A8;
    while (i < (s32)(*root)->unk_A4) {
        if (item->unk_20 & 1) {
            s32 random_value;
            s32 divisor;
            s32 remainder;

            random_value = (lbl_801A63C0 * 0x676A4B6B + 0x33CB);
            lbl_801A63C0 = random_value;
            random_value = (random_value >> 16) & 0x7FFF;
            divisor = (u16)item->unk_C;
            remainder = random_value % divisor;
            if ((remainder >> 7) == 0) {
                fn_1_D6748(item, &item->unk_14, item->unk_E);
            }
        }
        i++;
        item++;
    }
}
/* fzgx:end fn_1_D41D8 */

/* fzgx:begin fn_1_D42A8 */
typedef struct D42Vec { f32 x, y, z; } D42Vec;

static inline f32 d42dist(D42Vec *a, D42Vec *b) {
    f32 value;
    f32 dx;
    f32 dy;
    f32 dz;
    dx = a->x;
    dx -= b->x;
    dy = a->y;
    dy -= b->y;
    dz = a->z;
    dz -= b->z;
    value = dx*dx;
    value = value + dy*dy;
    value = value + dz*dz;
    return value;
}

/* WARNING: compiler-diff device, not original code */
#pragma opt_common_subs off
void fn_1_D42A8(u32 arg0, int arg1) {
    D42Vec a;
    D42Vec b;
    fn_1_681C(arg1, &a);
    fn_1_6898(arg1, &b);
    ((f32 *)arg0)[arg1] = d42dist(&a, &b) < 30.0f ? d42dist(&a, &b) : 30.0f;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_D42A8 */

/* fzgx:begin fn_1_D4360 */
void fn_1_D4360(void *base) {
    *(s32 *)((char *)base + 0xc074) = 200;
}
/* fzgx:end fn_1_D4360 */

/* fzgx:begin fn_1_D4370 */
struct D4370State {
    f32 unk_0;
    s32 unk_4;
    s32 unk_8;
    f32 arrC[5];
    s32 arr20[5];
    s32 unk_34;
    s32 unk_38;
};

struct FzgxCopy_4 { u32 words[1]; };

void fn_1_D4370(void *arg0) {
    struct FzgxCopy_4 loc_1C;
    struct FzgxCopy_4 loc_18;
    struct FzgxCopy_4 loc_14;
    u32 sp10;
    u32 spC;
    u32 sp8;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 var_f0;
    struct D4370State *temp_r30;
    struct D4370State *var_r4;
    s32 var_r5;
    u32 temp_r4_2;
    u32 temp_r6;
    u32 temp_r7;
    u32 temp_r9;
    u32 temp_r9_2;
    s32 idx;

    temp_r30 = (struct D4370State *)((u8 *)(arg0) + 0xC040);
    if ((*(s32 *)((u8 *)(arg0) + 49268)) != 0) {
        temp_r30->unk_34 = temp_r30->unk_34 - 1;
        if (temp_r30->unk_34 <= 0) {
            var_r4 = temp_r30;
            var_r5 = 0;
            temp_r9 = (lbl_801A63C0 * 0x676A4B6B) + 0x33CB;
            lbl_801A63C0 = temp_r9;
            temp_r30->unk_8 = ((s32)((temp_r9 >> 0x10U) & 0x7FFF) % 3) + 1;
            temp_r30->unk_4 = 0;
            while (var_r5 < temp_r30->unk_8) {
                temp_r9_2 = (lbl_801A63C0 * 0x676A4B6B) + 0x33CB;
                lbl_801A63C0 = temp_r9_2;
                temp_r7 = ((temp_r9_2 >> 0x10U) & 0x7FFF) >> 0x1FU;
                if (((((temp_r9_2 >> 0x10U) & 1) ^ temp_r7) - temp_r7) != 0) {
                    var_f0 = (1.0f);
                } else {
                    var_f0 = (0.5f);
                }
                var_r4->arrC[0] = var_f0;
                var_r5 += 1;
                temp_r6 = (lbl_801A63C0 * 0x676A4B6B) + 0x33CB;
                lbl_801A63C0 = temp_r6;
                var_r4->arr20[0] = ((s32)((temp_r6 >> 0x10U) & 0x7FFF) % 60) + 0xA;
                var_r4 = (struct D4370State *)((u8 *)(var_r4) + 4);
            }
            temp_r30->unk_38 = temp_r30->arr20[temp_r30->unk_4];
            (*(f32 *)((u8 *)(arg0) + 49216)) = temp_r30->arrC[temp_r30->unk_4];
        }
    } else {
        temp_r30->unk_38 = temp_r30->unk_38 - 1;
        var_f0 = (*(f32 *)((u8 *)(arg0) + 49216)) - (0.0250000004f);
        var_f0 = (var_f0 > (0.0f)) ? var_f0 : (0.0f);
        (*(f32 *)((u8 *)(arg0) + 49216)) = var_f0;
        idx = temp_r30->unk_4;
        if (idx == (temp_r30->unk_8 - 1)) {
            if ((*(f32 *)((u8 *)(arg0) + 49216)) <= (0.0f)) {
                temp_r4_2 = (lbl_801A63C0 * 0x676A4B6B) + 0x33CB;
                lbl_801A63C0 = temp_r4_2;
                temp_r30->unk_34 = ((s32)((temp_r4_2 >> 0x10U) & 0x7FFF) % 180) + 0x78;
                temp_r30->unk_38 = 0;
                (*(f32 *)((u8 *)(arg0) + 49216)) = (0.0f);
            }
        } else if (temp_r30->unk_38 <= 0) {
            temp_r30->unk_4 = idx + 1;
            temp_r30->unk_38 = temp_r30->arr20[temp_r30->unk_4];
            var_f0 = (*(f32 *)((u8 *)(arg0) + 49216)) + temp_r30->arrC[temp_r30->unk_4];
            var_f0 = (var_f0 < (1.0f)) ? var_f0 : (1.0f);
            (*(f32 *)((u8 *)(arg0) + 49216)) = var_f0;
        }
    }
    temp_f4 = *(f32 *)((u8 *)(arg0) + 49216);
    (*(u8 *)(&loc_18)) = 0xFF;
    (*((u8 *)(&loc_18) + 1)) = 0xFF;
    (*((u8 *)(&loc_18) + 2)) = 0xFF;
    (*((u8 *)(&loc_18) + 3)) = 0x80;
    (*(u8 *)(&loc_14)) = 0xEB;
    (*((u8 *)(&loc_14) + 1)) = 0xB4;
    (*((u8 *)(&loc_14) + 2)) = 0xD2;
    (*((u8 *)(&loc_14) + 3)) = 0x80;
    if (temp_f4 > (0.99000001f)) {
        loc_1C.words[0] = loc_18.words[0];
        (*(u8 *)(&loc_1C)) = ((*(u8 *)(&loc_1C)) * temp_f4);
        (*((u8 *)(&loc_1C) + 1)) = ((*((u8 *)(&loc_1C) + 1)) * temp_f4);
        (*((u8 *)(&loc_1C) + 2)) = ((*((u8 *)(&loc_1C) + 2)) * temp_f4);
        (*((u8 *)(&loc_1C) + 3)) = ((*((u8 *)(&loc_1C) + 3)) * temp_f4);
    } else {
        spC = loc_14.words[0];
        sp10 = loc_18.words[0];
        loc_1C.words[0] = fn_1_539CC(&sp10, &spC, ((0.5f) * (*(f32 *)((u8 *)(arg0) + 49216))));
        temp_f4_2 = (*(f32 *)((u8 *)(arg0) + 49216)) / (1.64999998f);
        (*(u8 *)(&loc_1C)) = ((*(u8 *)(&loc_1C)) * temp_f4_2);
        (*((u8 *)(&loc_1C) + 1)) = ((*((u8 *)(&loc_1C) + 1)) * temp_f4_2);
        (*((u8 *)(&loc_1C) + 2)) = ((*((u8 *)(&loc_1C) + 2)) * temp_f4_2);
        (*((u8 *)(&loc_1C) + 3)) = ((*((u8 *)(&loc_1C) + 3)) * temp_f4_2);
    }
    sp8 = loc_1C.words[0];
    fn_1_9A7A8(&sp8);
}
/* fzgx:end fn_1_D4370 */

/* fzgx:begin fn_1_D47D8 */
struct Entry {
    s8 flag[0x18];
};

struct Base {
    char pad[0xe780];
    struct Entry entries[1];
};

void fn_1_D47D8(void *state, s32 index) {
    struct Base *base = state;

    base->entries[index].flag[0] = -1;
}
/* fzgx:end fn_1_D47D8 */

/* fzgx:begin fn_1_D47F0 */
typedef struct {
    s8 state;
    u8 pad[3];
    f32 value;
    f32 field_8;
    u8 field_c;
    u8 field_d;
    u8 field_e;
    u8 pad_f;
    u8 pad_10[8];
} D47F0Entry;

/* WARNING: compiler-diff device, not original code */
#pragma opt_common_subs off
void fn_1_D47F0(void *base, u32 index) {
    D47F0Entry *entry;
    D47F0Entry *cached;
    u8 temp[0x18];
    u32 result;
    f32 base_value;
    f32 delta;
    f32 scaled_delta;
    f32 scaled_base;

    entry = (D47F0Entry *)(lbl_1_bss_6D620 + index * 0x18);
    cached = (D47F0Entry *)((u8 *)base + index * 0x18 + 0xe780);
    fn_1_681C(index, temp);
    result = fn_1_1FB80(temp, 1);
    base_value = *(f32 *)((u8 *)base + 0xc040);

    if (base_value > (0.0f) && !(result & 1)) {
        if (cached->state == -1) {
            *cached = *entry;
        }
        entry->state = 4;
        entry->value = (0.0f);
        base_value = *(f32 *)((u8 *)base + 0xc040);
        delta = (1.0f) - base_value;
        scaled_base = (100.0f) * base_value;
        scaled_delta = (3000.0f) * delta;
        entry->field_8 = scaled_delta + scaled_base;
        entry->field_c = 0x17;
        entry->field_d = 0x1a;
        entry->field_e = 0x1d;
    } else if (cached->state != -1) {
        *entry = *cached;
        cached->state = -1;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_D47F0 */

/* fzgx:begin fn_1_D4964 */
static inline int random15(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

void fn_1_D4964(u32 arg0) {
    u8 *v0 = (u8 *)(arg0 + 0xC140);
    s32 loc_C8[16] = {0, 0, 14, 14, 0, 0, 14, 14, 12, 12, 9, 9, 12, 12, 9, 9};
    s32 loc_88[16] = {0, 0, -180, -180, 0, 0, -180, -180, -30, -30, 0, 0, -30, -30, 0, 0};
    s32 loc_48[16] = {0, 0, 20, -20, 0, 0, 20, -20, 10, -10, -10, 10, 10, -10, -10, 10};
    s32 loc_8[16] = {0, 0, 20, 20, 0, 0, -20, -20, 10, 10, -10, -10, -10, -10, 10, 10};
    int v10, v18, v15, v19, v21, v16, v25, v33, slope;
    int v40, v47, v35, y, x, v53;
    fn_80008BEC((v0 + 32), 0, 512);
    for (v10=0; v10<16; v10++) {
        for(v15=0;v15<8;v15++) {
            for(v18=0;v18<8;v18++) {
                v19=v15*8+v18;
                v21=v19/2;
                v16=((v19&1)^((u32)v19>>31))-((u32)v19>>31);
                if(v21+v10*32<512) {
                    v25=loc_88[v10];
                    slope=loc_48[v10];
                    if(slope>0) v25+=v18*slope;
                    else v25+=(v18-7)*slope;
                    slope=loc_8[v10];
                    if(slope>0) v25+=v15*slope;
                    else v25+=(v15-7)*slope;
                    if(random15()%100<v25) {
                        v33=random15()%loc_C8[v10];
                        if(v16) ((u8 *)(v0+32))[v10*32+v21]|=v33;
                        else ((u8 *)(v0+32))[v10*32+v21]|=v33<<4;
                    }
                }
            }
        }
    }
    DCFlushRange((v0+32),512);
    fn_80008BEC((v0+544),0,9216);
    for(v35=0;v35<4;v35++) {
        *(s16 *)(v0+9768+v35*2)=v35*3+1;
        for(v40=0;v40<8;v40++) {
            for(v47=0;v47<*(s16 *)(v0+9768+v35*2);v47++) {
                v53=random15()%16;
                y=random15()%16;
                *(u8 *)(v0+544+v35*2304+v40*288+v53+y*16)=16;
                *(u8 *)(v0+544+v35*2304+((v40+1)%8)*288+v53+y*16)=1;
                *(u8 *)(v0+544+v35*2304+((v40+2)%8)*288+v53+y*16)=17;
            }
        }
    }
    DCFlushRange((v0+544),9216);
    GXInitTexObj((MdlTexObj *)v0,(v0+32),32,32,0,1,1,0);
    GXInitTexObjLOD((MdlTexObj *)v0,1,1,0.0f,0.0f,0.0f,0,0,0);
    {
    int v58, v56;
    for(v56=0;v56<4;v56++) {
        for(v58=0;v58<8;v58++) {
            GXInitTexObj((MdlTexObj *)(v0+v56*2304+v58*288+800),(v0+v56*2304+v58*288+544),16,16,2,1,1,0);
            GXInitTexObjLOD((MdlTexObj *)(v0+v56*2304+v58*288+800),0,0,0.0f,0.0f,0.0f,0,0,0);
        }
    }
    }
    GXInvalidateTexAll();
    lbl_1_data_2A7E0.unk_2C=(u32)fn_1_D523C;
}
/* fzgx:end fn_1_D4964 */

/* fzgx:begin fn_1_D4FFC */
struct MdlLoadState_D4FFC {
    u8 pad_0[0x2620];
    f32 rand0;
    f32 rand1;
    s16 thresh[4];
    s16 sel[4];
};

static inline s32 rand15_D4FFC(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

void fn_1_D4FFC(u8 *base, u32 index) {
    struct MdlLoadState_D4FFC *s = (struct MdlLoadState_D4FFC *)(base + 0xC140);
    Vec3 pos;
    Vec3 ref = {0.0f, 1.0f, 0.0f};
    s16 mode;
    f32 dist;
    s32 i;

    mode = camera_get_mode();
    if (mode != -1 && fn_1_6EC0(index) && (fn_1_864E8(mode) & 0x20)) {
        s->sel[index] = -1;
        return;
    }
    if (mode != -1) {
        fn_1_862A8(camera_get_mode(), &pos);
        dist = lbl_8006D6FC(&pos, &ref);
        s->sel[index] = -1;
        for (i = 0; i < 4; i++) {
            if (dist > 0.9f * s->thresh[i] / s->thresh[3]) {
                s->sel[index] = i;
            }
        }
        if ((lbl_801A66A0 & 7) == 0) {
            s->rand0 = rand15_D4FFC() / 32767.0f;
            s->rand1 = rand15_D4FFC() / 32767.0f;
        }
    } else {
        s->sel[index] = -1;
    }
}
/* fzgx:end fn_1_D4FFC */

/* fzgx:begin fn_1_D523C */
typedef struct {
    u8 pad_0[0x15];
    u8 unk_15;
} D523C_Mode;

typedef struct {
    u8 pad_0[0x4];
    D523C_Mode *unk_4;
    u8 pad_8[0x4];
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
} D523C_State;

/* the block at +0xC140 of lbl_1_data_2A7E0.unk_3C; field names as fn_1_D4FFC's view of it */
typedef struct {
    u8 pad_0[0x2620];
    f32 rand0;
    f32 rand1;
    s16 thresh[4];
    s16 sel[4];
    s16 unk_2638;
    s16 unk_263A;
} D523C_Tex;

/* Callback stored by fn_1_D4964 in lbl_1_data_2A7E0.unk_2C. Does nothing when the sel entry for fn_1_5910's port is
 * -1, when state->unk_4->unk_15 is 2, or (unless it is 1) when the five state words equal the ones saved last time;
 * otherwise saves them, issues the GX setup calls with a 2x4 texture matrix (GXLoadTexMtxImm) and advances the words. */
void fn_1_D523C(void *arg) {
    D523C_State *state = arg;
    f32 mtx[3][4];
    f32 *obj;
    D523C_Tex *tex;
    s32 n10_1 = state->unk_10 + 1;
    s32 n10_2 = state->unk_10 + 2;
    s32 n18 = state->unk_18;
    s32 n18_1 = n18 + 1;
    s32 n18_2 = n18 + 2;
    s32 n14_3 = state->unk_14 + 3;
    s32 n14_6 = state->unk_14 + 6;
    s32 nC = state->unk_C;
    s32 nC_1 = nC + 1;
    s32 n1C = state->unk_1C;
    s32 n1C_1 = n1C + 1;
    u32 port;
    u8 mode;
    f32 scale;

    port = fn_1_5910();
    obj = (f32 *)lbl_1_data_2A7E0.unk_3C;
    tex = (D523C_Tex *)((u8 *)obj + 0xC140);
    if (tex->sel[port] == -1) {
        return;
    }
    mode = state->unk_4->unk_15;
    if (mode == 2 ||
        (mode != 1 && lbl_1_bss_7AD60 == state->unk_10 && lbl_1_bss_7AD64 == state->unk_18 &&
         lbl_1_bss_7AD68 == state->unk_14 && lbl_1_bss_7AD6C == state->unk_C &&
         lbl_1_bss_7AD70 == state->unk_1C)) {
        return;
    }
    lbl_1_bss_7AD60 = state->unk_10;
    lbl_1_bss_7AD64 = state->unk_18;
    lbl_1_bss_7AD68 = state->unk_14;
    lbl_1_bss_7AD6C = state->unk_C;
    lbl_1_bss_7AD70 = state->unk_1C;
    fn_80072EDC(nC, 1);
    fn_800734A8(nC, n10_1, n18_1, 4);
    fn_800745A4(n10_1, 1, 4, n14_3, 0, 0x7D);
    fn_80073778(tex, n18_1);
    fn_80072AB0(nC, 0, 0);
    mtx[0][0] = tex->unk_2638;
    mtx[0][1] = 0.0f;
    mtx[0][2] = 0.0f;
    mtx[0][3] = tex->rand0;
    mtx[1][0] = 0.0f;
    scale = obj[port] < 23.0f ? obj[port] : 23.0f;
    scale = 1.0f - scale / 24.0f;
    mtx[1][1] = tex->unk_263A * scale;
    mtx[1][2] = 0.0f;
    mtx[1][3] = tex->rand1;
    GXLoadTexMtxImm(mtx, n14_3, 1);
    fn_800738E0(n1C, n10_1, n18);
    fn_80073778((u8 *)tex + tex->sel[port] * 0x900 + ((lbl_801A66A0 >> 1) & 7) * 0x120 + 0x320, n18);
    fn_80073E8C(nC, n1C, 0x10, 0x10, 0x10, 0x10, 2, 1, 0, 0);
    fn_800739E0(state->unk_1C, 4, 4);
    state->unk_1C = n1C_1;
    state->unk_C = nC_1;
    state->unk_10 = n10_2;
    state->unk_18 = n18_2;
    state->unk_14 = n14_6;
}
/* fzgx:end fn_1_D523C */

/* fzgx:begin fn_1_D550C */
/* pos += dir * len */
static inline void spark_offset(Vec3 *pos, Vec3 *dir, f32 len) {
    pos->x += (f32)(dir->x * len);
    pos->y += (f32)(dir->y * len);
    pos->z += (f32)(dir->z * len);
}

/* out = a x b */
static inline void spark_cross(f32 *a, f32 *b, f32 *out) {
    f32 a0 = a[0];
    f32 a1 = a[1];
    f32 a2 = a[2];
    f32 x;
    f32 y;
    f32 z;

    x = a1 * b[2];
    x -= a2 * b[1];
    y = a2 * b[0];
    y -= a0 * b[2];
    z = a0 * b[1];
    z -= a1 * b[0];
    out[0] = x;
    out[1] = y;
    out[2] = z;
}

/* *out = range * a random value in [-0.5, 0.5] */
static inline void spark_rand_range(f32 *out, f32 range, s32 r) {
    *out = range * (r / 32767.0f - 0.5f);
}

/* one step of the executable's random generator, lbl_801A63C0 */
static inline s32 spark_rand15(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

void fn_1_D550C(void *arg) {
    MdlSpark *e = arg;
    Vec3 eye;
    Vec3 at;
    Vec3 v48;
    Vec3 zero = {0.0f, 0.0f, 0.0f}; /* unused: retail keeps only its .rodata initializer */
    static const Vec3 forward = {0.0f, 0.0f, -1.0f};
    Vec3 dir;
    Vec3 up;
    Vec3 side;
    Vec3 pos;
    f32 size;
    f32 s;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 mode;
    f32 base;
    f32 dist;
    f32 t;
    s32 r;

    fn_1_681C(0, &eye);
    fn_1_6898(0, &at);
    fn_1_6914(0, &v48);
    fn_1_6990(0, &up);
    mode = camera_get_mode();
    if (mode < 0) {
        return;
    }
    dir = forward;
    fn_1_8636C(mode, lbl_801A6D00);
    lbl_8006E1C0(&dir, &dir);
    lbl_8006D668(&dir);
    fn_1_A714C(&a, &b, &c, &d);
    pos = eye;
    t = (f32)(1.5f * (spark_rand15() / 32767.0f)) - 0.5f;
    base = fn_1_8652C(mode) / 10.0f;
    r = spark_rand15();
    dist = base + (c + (f32)(t * (100.0f - c)));
    spark_offset(&pos, &dir, dist);
    spark_rand_range(&s, (dist / 10.0f) * fn_1_A71AC(), r);
    r = spark_rand15();
    spark_offset(&pos, &up, s);
    spark_cross((f32 *)&dir, (f32 *)&up, (f32 *)&side);
    spark_rand_range(&s, b * (dist * fn_1_A71AC()), r);
    spark_offset(&pos, &side, s);
    e->pos = pos;
    size = 136.0f * (1.0f - t);
    e->scale.x = size;
    e->scale.y = size;
    e->scale.z = size;
    e->value = (90.0f + base) * (0.6f + (f32)(0.4f * (spark_rand15() / 32767.0f)));
    e->phase = spark_rand15();
    e->step = 96.0f * (spark_rand15() / 32767.0f - 0.5f);
    e->count = 20;
}
/* fzgx:end fn_1_D550C */

/* fzgx:begin fn_1_D5958 */
// fn_1_D5958: iterate through 4 structures, calling fn_1_D550C on each.
void fn_1_D5958(void *arg) {
    void *ptr = arg;
    int i = 0;
    for (; i < 4; i++) {
        fn_1_D550C((char *)ptr + 0xc07c);
        ptr = (char *)ptr + 0x30;
    }
}
/* fzgx:end fn_1_D5958 */

/* fzgx:begin fn_1_D59A8 */
struct fn_1_D59A8_elem {
    f32 pos[3];
    u8 pad_C[0x18];
    f32 unk_24;
    s16 unk_28;
    s16 unk_2A;
    s16 unk_2C;
};
struct fn_1_D59A8_obj {
    u8 pad_0[0xC07C];
    struct fn_1_D59A8_elem elems[3];
};
static inline f32 distance_squared(f32 *a, f32 *b) {
    f32 dx = a[0];
    f32 dy = a[1];
    f32 dz = a[2];
    dx -= b[0]; dy -= b[1]; dz -= b[2];
    dx = ((f32)((dx) * dx));
    dx += dy * dy; dx += dz * dz;
    return dx;
}

/* Distance from pos to the nearest player. */
static inline f32 nearest_player_dist(f32 *pos) {
    f32 v[3];
    u32 count;
    u32 j;
    f32 best;

    count = fn_1_58C4();
    fn_1_681C(0, v);
    best = lbl_8006D0B4(distance_squared(pos, v));
    for (j = 1; j < count; j++) {
        fn_1_681C(j, v);
        best = best < lbl_8006D0B4(distance_squared(pos, v)) ? best : lbl_8006D0B4(distance_squared(pos, v));
    }
    return best;
}

/* out = base + dir * len */
static inline void add_scaled(f32 *out, f32 *base, f32 *dir, f32 len) {
    out[0] = base[0] + (f32)(dir[0] * len);
    out[1] = base[1] + (f32)(dir[1] * len);
    out[2] = base[2] + (f32)(dir[2] * len);
}

void fn_1_D59A8(struct fn_1_D59A8_obj *obj) {
    f32 v44[3]; f32 v38[3]; f32 v2c[3]; f32 v20[3]; f32 v14[3];
    f32 step1;
    s32 i;
    f32 best;
    fn_1_681C(0, v44);
    fn_1_6898(0, v38);
    step1 = 0.08f;
    for (i = 0; i < 3; i++) {
        obj->elems[i].unk_2C = obj->elems[i].unk_2C - 1;
        obj->elems[i].pos[0] = obj->elems[i].pos[0] + step1;
        obj->elems[i].pos[2] += 0.1f;
        obj->elems[i].unk_28 = obj->elems[i].unk_28 + obj->elems[i].unk_2A;
        best = nearest_player_dist(obj->elems[i].pos);
        if (fn_1_66B8(obj->elems[i].pos, 4.0f) == 0) {
            fn_1_D550C(obj->elems[i].pos);
        }
        if (obj->elems[i].unk_2C < -180 && best > 30.0f) {
            fn_1_D550C(obj->elems[i].pos);
        }
    }
    obj->elems[i].unk_2C = obj->elems[i].unk_2C - 1;
    fn_1_681C(0, v2c);
    fn_1_6914(0, v20);
    v14[0] = v20[0] - v2c[0];
    v14[1] = v20[1] - v2c[1];
    v14[2] = v20[2] - v2c[2];
    lbl_8006D668(v14);
    add_scaled(obj->elems[3].pos, v2c, v14, 20.0f);
    obj->elems[3].unk_24 = 70.0f;
}
/* fzgx:end fn_1_D59A8 */

/* fzgx:begin fn_1_D5C68 */
/* sqrt(0.5); nothing in retail references it */
const f32 lbl_1_rodata_6320 = 0.70710677f;

// fn_1_D5C68: returns a constant.
int fn_1_D5C68(void) {
    return 0;
}
/* fzgx:end fn_1_D5C68 */
