#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/mdlload.h"

extern void fn_80071484(void);
extern void fn_80071678(void);
extern void *OSGetArenaHi(void);
extern void fn_1_D3BE8(void);
extern u8 lbl_1_bss_7AD58[8];
extern void fn_1_9A508(void);
extern void fn_1_D3F24(void *base);
extern void fn_1_D3F88(void *base);
extern f32 lbl_1_rodata_6168[112];
extern u32 fn_1_5910(void);
extern void fn_1_9AD88(Obj_1_data_2A7E0 *obj);
extern u32 fn_1_9D260(void);
extern s32 fn_1_D3E90(void);
extern void fn_1_1067A8(void *obj, f32 value, f32 limit);
extern void fn_1_D4174(void *base, void *arg);
extern s16 camera_get_mode(void);
extern s32 fn_1_6EC0(u8 value);
extern u32 fn_1_864E8(s32 value);
extern s32 fn_1_7000(void);
extern void fn_1_681C(u8 value, void *out);
extern s32 fn_1_1FB80(void *value, s32 mode);
extern void fn_1_103090(void *ptr);
extern void fn_1_1030A4(void *ptr);
extern void fn_1_103264(void *item, void *arg);
extern s16 fn_1_3F0C8(void);
extern void fn_1_D6748(void *obj, u32 *arg1, s16 arg2);
extern u32 lbl_801A63C0;
extern void fn_1_D550C(void *);

extern int fn_1_45730(void *owner, void *buffer);
extern int fn_1_458A0(void *buffer, void *work, int size, int mode);
extern u32 lbl_801A6410;
extern void *fn_1_45D0(u32 allocator, u32 size, const unsigned char *name, int mode);
extern int fn_1_45850(void *buffer);
extern void fn_1_12F78(void *owner, void *data);
extern void DCFlushRange(void *address, u32 length);
extern void *fn_80071100(void *data, void *size, void *user);
extern void fn_1_D3BE8(void);
extern void fn_80071484(void);
extern void fn_80071678(void);
extern void *OSGetArenaHi(void);
extern u8 lbl_1_bss_7AD58[8];
extern void fn_1_9A508(void);
extern void fn_1_D3F24(void *base);
extern void fn_1_D3F88(void *base);
extern f32 lbl_1_rodata_6168[112];
extern u32 fn_1_5910(void);
extern void fn_1_9AD88(Obj_1_data_2A7E0 *obj);
extern u32 fn_1_9D260(void);
extern s32 fn_1_D3E90(void);
extern void fn_1_1067A8(void *obj, f32 value, f32 limit);
extern void fn_1_D4174(void *base, void *arg);
extern s16 camera_get_mode(void);
extern s32 fn_1_6EC0(u8 value);
extern u32 fn_1_864E8(s32 value);
extern s32 fn_1_7000(void);
extern void fn_1_681C(u8 value, void *out);
extern s32 fn_1_1FB80(void *value, s32 mode);
extern void fn_1_103090(void *ptr);
extern void fn_1_1030A4(void *ptr);
extern void fn_1_103264(void *item, void *arg);
extern s16 fn_1_3F0C8(void);
extern void fn_1_D6748(void *obj, u32 *arg1, s16 arg2);
extern u32 lbl_801A63C0;
extern void fn_1_D550C(void *);

extern void fn_1_D3BE8(void);

extern void fn_1_D3BE8(void);

extern void fn_1_D3BE8(void);

extern void fn_1_D3BE8(void);

extern void fn_1_D3BE8(void);
extern int fn_1_D3B6C(void);

/* fzgx:begin fn_1_D35D4 noprologue */
#include "types.h"

extern int fn_1_45730(void *arg0, void *arg1);
extern u8 lbl_1_bss_3BC0[32];
extern int fn_1_458A0(void *arg0, void *arg1, u32 arg2, u32 arg3);
extern char lbl_1_data_3DBD8[10];
extern void *lbl_801A6410[1];
extern void *fn_1_45D0(void *arg0, u32 arg1, void *arg2, u32 arg3);
extern int fn_1_45850(void *arg);
extern void fn_1_12860(void *arg0, void *arg1);
extern void fn_1_46B4(void *arg0, void *arg1, void *arg2, u32 arg3);
extern void *fn_80071100(void *arg0, void *arg1, void *arg2);
extern int fn_1_D3B6C(void);
extern void DCFlushRange(void *address, u32 length);

int fn_1_D35D4(void *unused, void *arg) {
    u8 local[0x58];
    u32 size1;
    u32 size0;
    struct { void * value; } buffer1;
    u8 *data;
    void *buffer0;
    void *object;

    if (fn_1_45730(unused, local) == 0) {
        return 0;
    }
    if (fn_1_458A0(local, lbl_1_bss_3BC0, 32, 0) < 0) {
        return 0;
    }

    size0 = (__lwbrx((u32 *)lbl_1_bss_3BC0, 0) + 39) & ~31;
    size1 = (__lwbrx((u32 *)lbl_1_bss_3BC0, 4) + 31) & ~31;

    buffer0 = fn_1_45D0(lbl_801A6410[0], ((size1 + 31) & ~31) + 32,
                         lbl_1_data_3DBD8, 0x7a);
    data = (u8 *)buffer0 + 32;
    if (data == 0) {
        return 0;
    }
    buffer1.value = fn_1_45D0(lbl_801A6410[0], size0,
                         lbl_1_data_3DBD8, 0x80);
    if (buffer1.value == 0) {
        return 0;
    }
    if (fn_1_458A0(local, buffer1.value, size0, 0) < 0) {
        return 0;
    }
    if (fn_1_45850(local) == 0) {
        return 0;
    }
    fn_1_12860(buffer1.value, (u8 *)buffer0 + 32);
    fn_1_46B4(lbl_801A6410[0], buffer1.value, lbl_1_data_3DBD8, 0x8e);
    DCFlushRange((u8 *)buffer0 + 32, size1);
    object = fn_80071100((u8 *)buffer0 + 32, buffer0, arg);
    *(u32 *)((u8 *)object + 0x10) &= ~1;
    return fn_1_D3B6C();
}
/* fzgx:end fn_1_D35D4 */

/* fzgx:begin fn_1_D3768 */
typedef struct {
    u8 _pad[0x10];
    u32 flags;
} Fn80071100Result;

// Loads, prepares, and submits the owner's model payload.
int fn_1_D3768(void *owner, void *user) {
    u8 buffer[0x58];
    u32 data_size;
    Fn80071100Result *result;
    u32 aligned_size;
    void *data;

    if (fn_1_45730(owner, buffer) == 0) {
        return 0;
    }
    if (fn_1_458A0(buffer, lbl_1_bss_3BC0, 32, 0) < 0) {
        return 0;
    }

    (void)__lwbrx(lbl_1_bss_3BC0, 0);
    data_size = __lwbrx(lbl_1_bss_3BC0, 4);
    aligned_size = (data_size + 0x1f) & ~0x1f;
    data = fn_1_45D0(lbl_801A6410,
                     ((aligned_size + 0x1f) & ~0x1f) + 0x20,
                     lbl_1_data_3DBD8, 0x7a);
    result = (Fn80071100Result *)((u8 *)data + 0x20);
    if (result == 0) {
        return 0;
    }
    if (fn_1_45850(buffer) == 0) {
        return 0;
    }

    fn_1_12F78(owner, result);
    DCFlushRange(result, aligned_size);
    result = (Fn80071100Result *)fn_80071100(result, data, user);
    result->flags &= ~1;
    return fn_1_D3B6C();
}
/* fzgx:end fn_1_D3768 */

/* fzgx:begin fn_1_D3884 */
void fn_1_D3884(void) {
    fn_80071484();
}
/* fzgx:end fn_1_D3884 */

/* fzgx:begin fn_1_D38A4 */
void fn_1_D38A4(void) {
    fn_80071678();
}
/* fzgx:end fn_1_D38A4 */

/* fzgx:begin fn_1_D38C4 noprologue */
#include "types.h"

extern int fn_1_45730(void *arg, void *path);
extern u8 lbl_1_bss_3BC0[32];
extern int fn_1_458A0(void *path, void *data, int size, int offset);
extern char lbl_1_data_3DBD8[10];
extern void *lbl_801A6410;
extern void *fn_1_45D0(void *base, int offset, void *source, int size);
extern int fn_1_45850(void *path);
extern void fn_1_12860(void *data, int size);
extern void fn_1_46B4(void *base, int offset, void *source, int size);
extern void DCFlushRange(void *address, u32 size);
extern void *fn_80071678(void *address, u32 size);

typedef struct {
    u8 pad[0xc];
    u32 field_c;
} Fn1D38C4Result;

#pragma opt_propagation off
#pragma opt_common_subs off
void *fn_1_D38C4(void *arg) {
    u8 path[96];
    u32 size2;
    u32 size;
    void *data2;
    void *aligned;
    void *data;
    Fn1D38C4Result *result;

    if (fn_1_45730(arg, path) == 0) {
        return 0;
    }
    if (fn_1_458A0(path, lbl_1_bss_3BC0, 0x20, 0) < 0) {
        return 0;
    }

    size = (__lwbrx((void *)lbl_1_bss_3BC0, 0) + 0x27) & ~0x1f;
    size2 = (__lwbrx((void *)lbl_1_bss_3BC0, 4) + 0x1f) & ~0x1f;

    data = fn_1_45D0(lbl_801A6410, ((size2 + 0x1f) & ~0x1f) + 0x20,
                     lbl_1_data_3DBD8, 0x1d6);
    aligned = (void *)(((u32)data + 0x3f) & ~0x1f);
    if (aligned == 0) {
        return 0;
    }
    data2 = fn_1_45D0(lbl_801A6410, size, lbl_1_data_3DBD8, 0x1dc);
    if (data2 == 0) {
        return 0;
    }
    if (fn_1_458A0(path, data2, size, 0) < 0) {
        return 0;
    }
    if (fn_1_45850(path) == 0) {
        return 0;
    }

    fn_1_12860(data2, (int)aligned);
    fn_1_46B4(lbl_801A6410, (int)data2, lbl_1_data_3DBD8, 0x1ea);
    DCFlushRange(aligned, size2);

    result = (Fn1D38C4Result *)fn_80071678(aligned, (u32)data);
    result->field_c = 0;
    return result;
}
#pragma opt_common_subs reset

#pragma opt_propagation reset
/* fzgx:end fn_1_D38C4 */

/* fzgx:begin fn_1_D3A4C noprologue */
#include "types.h"

extern int fn_1_45730(void *arg, void *buffer);
extern u8 lbl_1_bss_3BC0[32];
extern int fn_1_458A0(void *buffer, void *work, int size, int flags);
extern char lbl_1_data_3DBD8[10];
extern void *lbl_801A6410;
extern void *fn_1_45D0(void *arg0, u32 size, void *data, int count);
extern int fn_1_45850(void *buffer);
extern void fn_1_12F78(void *arg, void *buffer);
extern void DCFlushRange(void *buffer, u32 size);
extern void *fn_80071678(void *buffer, u32 size);

int fn_1_D3A4C(void *arg) {
    u8 buffer[96];
    u32 result;
    u32 size;
    u32 ptr;
    u32 value0;
    u32 value1;

    if (fn_1_45730(arg, buffer) == 0) {
        return 0;
    }
    if (fn_1_458A0(buffer, lbl_1_bss_3BC0, 32, 0) < 0) {
        return 0;
    }

    value0 = __lwbrx((void *)lbl_1_bss_3BC0, 0);
    value1 = __lwbrx((void *)lbl_1_bss_3BC0, 4);
    size = (value1 + 31) & ~31;
    ptr = (u32)fn_1_45D0(lbl_801A6410,
                         (((size + 31) & ~31) + 32),
                         lbl_1_data_3DBD8, 470);
    result = (ptr + 63) & ~31;
    if (result == 0) {
        return 0;
    }
    if (fn_1_45850(buffer) == 0) {
        return 0;
    }

    fn_1_12F78(arg, (void *)result);
    DCFlushRange((void *)result, size);
    ptr = (u32)fn_80071678((void *)result, ptr);
    *(u32 *)((u8 *)ptr + 12) = 0;
    return (int)ptr;
}
/* fzgx:end fn_1_D3A4C */

/* fzgx:begin fn_1_D3B6C noprologue */
#include "types.h"

extern void *OSGetArenaHi(void);

extern void fn_1_D3BE8();

typedef struct {
    u32 unk_00;
    void *resource;
} ModelReleaseEntry;

typedef struct {
    s32 entry_count;
    u8 unk_04[4];
    ModelReleaseEntry *entry_table;
} ModelReleaseList;

// Release the list's resources only when it resides above the arena high-water mark.
void *fn_1_D3B6C(ModelReleaseList *list) {
    s32 index;

    if (list != 0 && list > (ModelReleaseList *)OSGetArenaHi()) {
        for (index = 0; index < list->entry_count; index++) {
            fn_1_D3BE8(list->entry_table[index].resource);
        }
    }

    return list;
}
/* fzgx:end fn_1_D3B6C */

/* fzgx:begin fn_1_D3BE8 */
// Increment the model-loader byte counter.
void fn_1_D3BE8(void) {
    lbl_1_bss_7AD58[0]++;
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
extern s32 fn_1_58C4(void);
extern void fn_1_5948(s32 index);
extern void fn_1_105AB8(void *base, s32 index);
extern void fn_1_D47D8(void *state, s32 index);
extern void fn_1_627C(s32 index);
extern void fn_1_D5958(void *state);
extern void fn_1_D4360(void *state);
extern void fn_1_D4964(void *state);

// Initializes the model-loader state for every available entry.
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
    fn_1_D4964(state);
}
/* fzgx:end fn_1_D3C58 */

/* fzgx:begin fn_1_D3CF4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/mdlload.h"

extern f32 lbl_1_rodata_6168;

extern void fn_1_9AD54(void);
extern void *fn_1_9D260(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_D42A8(u32, int);
extern s32 fn_1_D3E90(void);
extern void fn_1_106084(u32, int, f32, f32, f32);
extern void fn_1_D4FFC(u32, int);
extern void fn_1_D47F0(u32, int);
extern void fn_1_627C(s32 index);
extern void fn_1_D59A8(u32);
extern void fn_1_D4370(u32);
extern void fn_1_D41D8(void);
extern void fn_1_D3FDC(u32, void *);

void fn_1_D3CF4(void) {
    int count;
    f32 *v2;
    int i;
    u32 obj;
    void *t1;

    obj = (u32)lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    t1 = fn_1_9D260();
    count = fn_1_58C4();
    v2 = (f32 *)obj;
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_D42A8(obj, i);
        if (fn_1_D3E90() == 0) {
            fn_1_106084(obj + 0x20, i, *(f32 *)(obj + 0xC040), *v2, lbl_1_rodata_6168);
        }
        fn_1_D4FFC(obj, i);
        fn_1_D47F0(obj, i);
        fn_1_627C(i);
        v2++;
    }
    fn_1_D59A8(obj);
    fn_1_D4370(obj);
    fn_1_D41D8();
    fn_1_D3FDC(obj, t1);
}
/* fzgx:end fn_1_D3CF4 */

/* fzgx:begin fn_1_D3DDC */
void fn_1_D3DDC(void) {
    fn_1_D3F88(lbl_1_data_2A7E0.unk_3C);
}
/* fzgx:end fn_1_D3DDC */

/* fzgx:begin fn_1_D3E08 */
// Refreshes the model state and applies the indexed limit when loading is inactive.
void fn_1_D3E08(void) {
    u32 model_index;
    Obj_1_data_2A7E0_At3C *model;
    void *update_value;

    model_index = fn_1_5910();
    model = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD88(&lbl_1_data_2A7E0);
    update_value = (void *)fn_1_9D260();

    if (fn_1_D3E90() == 0) {
        fn_1_1067A8(&model->unk_20, ((f32 *)model)[model_index],
                    lbl_1_rodata_6168[0]);
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
    if (value != -1 && fn_1_6EC0((u8)fn_1_5910()) != 0 &&
        (fn_1_864E8((s16)value) & 0x20) != 0) {
        return 1;
    }

    if (fn_1_7000() != 0) {
        return 1;
    }

    fn_1_681C((u8)fn_1_5910(), data);
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

/* fzgx:begin fn_1_D3FDC noprologue */
#include "dolphin/types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.6499999761581421f;
    s = 0.75f;
    s = 1.0f;
    s = 0.0f;
    s = 182.04444885253906f;
    d = 0.5;
    d = 2.0;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"
#define fabs(x) __fabs(x)

extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(u32);
extern void fn_1_1030D4(void *, void *);

typedef struct ColorEntry {
    u8 pad0[8];
    u32 flags;
    u8 padC[0x20];
    f32 red;
    f32 green;
    f32 blue;
    u8 pad38[0x74];
} ColorEntry;

void fn_1_D3FDC(void *arg0, void *arg1)
{
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
            entry->red = fabs(lbl_8006D188((s32)(182.04444885253906f * (f32)lbl_801A66A0)));
            entry->green = fabs(lbl_8006D188((s32)(0.5 * (182.04444885253906f * (f32)lbl_801A66A0))));
            entry->blue = fabs(lbl_8006D188((s32)(2.0 * (182.04444885253906f * (f32)lbl_801A66A0))));
        }
        fn_1_1030D4(entry, arg1);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D3FDC */

/* fzgx:begin fn_1_D4174 */
// Process each model-load entry in the caller-provided table.
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

            random_value = (s32)(lbl_801A63C0 * 0x676A4B6B + 0x33CB);
            lbl_801A63C0 = (u32)random_value;
            random_value = ((u32)random_value >> 16) & 0x7FFF;
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

/* fzgx:begin fn_1_D42A8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/mdlload.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/mdlload.h"

#ifndef GAME_MAIN_REL_MDLLOAD_TYPES_H
#define GAME_MAIN_REL_MDLLOAD_TYPES_H

#endif  // GAME_MAIN_REL_MDLLOAD_TYPES_H

/* end game/main_rel/mdlload_types.h */

extern void fn_1_681C(u8, u32 *);
extern void fn_1_6898(u8, u32 *);
extern f32 lbl_1_rodata_6168[112];

typedef struct D42Vec { f32 x, y, z; } D42Vec;
/* Volatile preserves the repeated source-vector reads in the clamped-distance calculation. */
static inline f32 d42dist(volatile D42Vec *a, D42Vec *b) {
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
static inline f32 fn_1_D42A8_array_read(f32 *array, s32 index) { return array[index]; }
#pragma opt_common_subs off
void fn_1_D42A8(u32 arg0, int arg1) {
    D42Vec a;
    D42Vec b;
    fn_1_681C((u8)arg1, (u32 *)&a);
    fn_1_6898((u8)arg1, (u32 *)&b);
    ((f32 *)arg0)[arg1] = d42dist(&a, &b) < fn_1_D42A8_array_read(lbl_1_rodata_6168, 0) ? d42dist(&a, &b) : fn_1_D42A8_array_read(lbl_1_rodata_6168, 0);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_D42A8 */

/* fzgx:begin fn_1_D4360 */
void fn_1_D4360(void *base) {
    *(s32 *)((char *)base + 0xc074) = 200;
}
/* fzgx:end fn_1_D4360 */

/* fzgx:begin fn_1_D4370 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.6499999761581421f;
    s = 0.75f;
    s = 1.0f;
    s = 0.0f;
    s = 182.04444885253906f;
    d = 0.5;
    d = 2.0;
    d = 4503599627370496.0;
    s = 0.5f;
    s = 0.02500000037252903f;
    s = 0.9900000095367432f;
    s = 1.649999976158142f;
}
#pragma section code_type ".text"
struct fn_1_D4370_lbl_1_rodata_6168 {
    u8 pad_0[0xC];
    f32 unk_C;
    f32 unk_10;
    u8 pad_14[0x14];
    f64 unk_28;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
};
extern struct fn_1_D4370_lbl_1_rodata_6168 lbl_1_rodata_6168;

struct fn_1_D4370_lbl_801A63C0 {
    u32 unk_0;
};
extern struct fn_1_D4370_lbl_801A63C0 lbl_801A63C0;

extern u32 fn_1_539CC(void *, void *, f32);
extern void fn_1_9A7A8(u32 *);

struct FzgxCopy_4 { u32 words[1]; };

struct D4370State {
    f32 unk_0;
    s32 unk_4;
    s32 unk_8;
    f32 arrC[5];
    s32 arr20[5];
    s32 unk_34;
    s32 unk_38;
};

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
    struct { f32 value; } var_f1;
    f32 var_f2;
    struct D4370State *temp_r30;
    struct fn_1_D4370_lbl_1_rodata_6168 *temp_r31;
    struct D4370State *var_r4;
    s32 var_r5;
    u32 temp_r4_2;
    u32 temp_r6;
    u32 temp_r7;
    u32 temp_r9;
    u32 temp_r9_2;
    s32 idx;

    temp_r30 = (struct D4370State *)((u8 *)(arg0) + 0xC040);
    temp_r31 = &lbl_1_rodata_6168;
    if ((s32) (*(s32 *)((u8 *)(arg0) + 49268)) != 0) {
        temp_r30->unk_34 = temp_r30->unk_34 - 1;
        if (temp_r30->unk_34 <= 0) {
            var_r4 = temp_r30;
            var_r5 = 0;
            temp_r9 = (lbl_801A63C0.unk_0 * 0x676A4B6B) + 0x33CB;
            lbl_801A63C0.unk_0 = temp_r9;
            temp_r30->unk_8 = (s32) ((s32)((temp_r9 >> 0x10U) & 0x7FFF) % 3) + 1;
            temp_r30->unk_4 = 0;
            while (var_r5 < temp_r30->unk_8) {
                temp_r9_2 = (lbl_801A63C0.unk_0 * 0x676A4B6B) + 0x33CB;
                lbl_801A63C0.unk_0 = temp_r9_2;
                temp_r7 = (u32) ((temp_r9_2 >> 0x10U) & 0x7FFF) >> 0x1FU;
                if (((((temp_r9_2 >> 0x10U) & 1) ^ temp_r7) - temp_r7) != 0) {
                    var_f0 = (1.0f);
                } else {
                    var_f0 = (0.5f);
                }
                var_r4->arrC[0] = var_f0;
                var_r5 += 1;
                temp_r6 = (lbl_801A63C0.unk_0 * 0x676A4B6B) + 0x33CB;
                lbl_801A63C0.unk_0 = temp_r6;
                var_r4->arr20[0] = (s32) ((s32)((temp_r6 >> 0x10U) & 0x7FFF) % 60) + 0xA;
                var_r4 = (struct D4370State *)((u8 *)(var_r4) + 4);
                            }
            temp_r30->unk_38 = temp_r30->arr20[temp_r30->unk_4];
            (*(f32 *)((u8 *)(arg0) + 49216)) = temp_r30->arrC[temp_r30->unk_4];
        }
    } else {
        temp_r30->unk_38 = temp_r30->unk_38 - 1;
        var_f1.value = (*(f32 *)((u8 *)(arg0) + 49216)) - (0.0250000004f);
        var_f1.value = (var_f1.value > (0.0f)) ? var_f1.value : (0.0f);
        (*(f32 *)((u8 *)(arg0) + 49216)) = var_f1.value;
        idx = temp_r30->unk_4;
        if (idx == (temp_r30->unk_8 - 1)) {
            if ((*(f32 *)((u8 *)(arg0) + 49216)) <= (0.0f)) {
                temp_r4_2 = (lbl_801A63C0.unk_0 * 0x676A4B6B) + 0x33CB;
                lbl_801A63C0.unk_0 = temp_r4_2;
                temp_r30->unk_34 = (s32) ((s32)((temp_r4_2 >> 0x10U) & 0x7FFF) % 180) + 0x78;
                temp_r30->unk_38 = 0;
                (*(f32 *)((u8 *)(arg0) + 49216)) = (f32) (0.0f);
            }
        } else if (temp_r30->unk_38 <= 0) {
            temp_r30->unk_4 = idx + 1;
            temp_r30->unk_38 = temp_r30->arr20[temp_r30->unk_4];
            var_f1.value = (*(f32 *)((u8 *)(arg0) + 49216)) + temp_r30->arrC[temp_r30->unk_4];
            var_f1.value = (var_f1.value < (1.0f)) ? var_f1.value : (1.0f);
            (*(f32 *)((u8 *)(arg0) + 49216)) = var_f1.value;
        }
    }
    temp_f4 = *(f32 *)((u8 *)(arg0) + 49216);
    (*(u8 *)((u8 *)(&loc_18) + 0)) = 0xFF;
    (*(u8 *)((u8 *)(&loc_18) + 1)) = 0xFF;
    (*(u8 *)((u8 *)(&loc_18) + 2)) = 0xFF;
    (*(u8 *)((u8 *)(&loc_18) + 3)) = 0x80;
    (*(u8 *)((u8 *)(&loc_14) + 0)) = 0xEB;
    (*(u8 *)((u8 *)(&loc_14) + 1)) = 0xB4;
    (*(u8 *)((u8 *)(&loc_14) + 2)) = 0xD2;
    (*(u8 *)((u8 *)(&loc_14) + 3)) = 0x80;
    if (temp_f4 > (0.99000001f)) {
        loc_1C.words[0] = loc_18.words[0];
        (*(u8 *)((u8 *)(&loc_1C) + 0)) = (u8) ((f32) (*(u8 *)((u8 *)(&loc_1C) + 0)) * temp_f4);
        (*(u8 *)((u8 *)(&loc_1C) + 1)) = (u8) ((f32) (*(u8 *)((u8 *)(&loc_1C) + 1)) * temp_f4);
        (*(u8 *)((u8 *)(&loc_1C) + 2)) = (u8) ((f32) (*(u8 *)((u8 *)(&loc_1C) + 2)) * temp_f4);
        (*(u8 *)((u8 *)(&loc_1C) + 3)) = (u8) ((f32) (*(u8 *)((u8 *)(&loc_1C) + 3)) * temp_f4);
    } else {
        spC = loc_14.words[0];
        sp10 = loc_18.words[0];
        loc_1C.words[0] = fn_1_539CC((void *)(&sp10), (void *)(&spC), (f32)((0.5f) * (*(f32 *)((u8 *)(arg0) + 49216))));
        temp_f4_2 = (*(f32 *)((u8 *)(arg0) + 49216)) / (1.64999998f);
        (*(u8 *)((u8 *)(&loc_1C) + 0)) = (u8) ((f32) (*(u8 *)((u8 *)(&loc_1C) + 0)) * temp_f4_2);
        (*(u8 *)((u8 *)(&loc_1C) + 1)) = (u8) ((f32) (*(u8 *)((u8 *)(&loc_1C) + 1)) * temp_f4_2);
        (*(u8 *)((u8 *)(&loc_1C) + 2)) = (u8) ((f32) (*(u8 *)((u8 *)(&loc_1C) + 2)) * temp_f4_2);
        (*(u8 *)((u8 *)(&loc_1C) + 3)) = (u8) ((f32) (*(u8 *)((u8 *)(&loc_1C) + 3)) * temp_f4_2);
    }
    sp8 = loc_1C.words[0];
    fn_1_9A7A8((u32 *)(&sp8));
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

void fn_1_D47D8(struct Base *base, s32 index) {
    base->entries[index].flag[0] = -1;
}
/* fzgx:end fn_1_D47D8 */

/* fzgx:begin fn_1_D47F0 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.6499999761581421f;
    s = 0.75f;
    s = 1.0f;
    s = 0.0f;
    s = 182.04444885253906f;
    d = 0.5;
    d = 2.0;
    d = 4503599627370496.0;
    s = 0.5f;
    s = 0.02500000037252903f;
    s = 0.9900000095367432f;
    s = 1.649999976158142f;
    s = 3000.0f;
    s = 100.0f;
}
#pragma section code_type ".text"

extern u32 lbl_1_bss_6D620[78];
extern f32 lbl_1_rodata_6168[112];
extern u32 fn_1_681C(u32 index, void *out);
extern u32 fn_1_1FB80(void *data, u32 mode);

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

#pragma opt_common_subs off
void fn_1_D47F0(void *base, u32 index) {
    f32 *constants;
    D47F0Entry *entry;
    D47F0Entry *cached;
    u8 temp[0x18];
    u32 result;
    f32 base_value;
    f32 delta;
    f32 scaled_delta;
    f32 scaled_base;

    constants = lbl_1_rodata_6168;
    entry = (D47F0Entry *)((u8 *)lbl_1_bss_6D620 + index * 0x18);
    cached = (D47F0Entry *)((u8 *)base + index * 0x18 + 0xe780);
    fn_1_681C(index & 0xff, temp);
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

/* fzgx:begin fn_1_D4964 noprologue */
#include "types.h"
#include "rel/main_rel/mdlload.h"

typedef struct { u32 dummy[8]; } Sig_GXInitTexObj_GXTexObj;
typedef Sig_GXInitTexObj_GXTexObj Sig_GXInitTexObjLOD_GXTexObj;
extern const f32 lbl_1_rodata_6168;
extern u32 lbl_801A63C0;
extern u32 fn_1_D523C(void *);
extern void fn_80008BEC(void *, int, u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(Sig_GXInitTexObj_GXTexObj *, void *, u16, u16, int, int, int, u8);
extern void GXInitTexObjLOD(Sig_GXInitTexObjLOD_GXTexObj *, int, int, f32, f32, f32, u8, u8, int);
extern void GXInvalidateTexAll(void);
struct Table16 { s32 a[16]; };
struct Pool { u8 pad[16]; f32 zero; u8 gap[0x34]; struct Table16 a,b,c,d; };
#define R(off) (*(const s32 *)((u8 *)&lbl_1_rodata_6168 + (off)))
static inline int random15(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}
void fn_1_D4964(u32 arg0) {
    struct Pool *pool=(struct Pool *)&lbl_1_rodata_6168;
    u8 *v0 = (u8 *)(arg0 + 0xC140);
    s32 loc_C8[16];
    s32 loc_88[16];
    s32 loc_48[16];
    s32 loc_8[16];
    int v10, v18, v15, v19, v21, v16, v25, v33, slope;
    u8 *v9;
    int v40, v47, v35, y, x, v53;
    *(struct Table16 *)loc_C8=pool->a;
    *(struct Table16 *)loc_88=pool->b;
    *(struct Table16 *)loc_48=pool->c;
    *(struct Table16 *)loc_8=pool->d;
    fn_80008BEC((void *)(v0 + 32), 0, 512);
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
    DCFlushRange((void *)(v0+32),512);
    fn_80008BEC((void *)(v0+544),0,9216);
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
    DCFlushRange((void *)(v0+544),9216);
    GXInitTexObj((Sig_GXInitTexObj_GXTexObj *)v0,(void *)(v0+32),32,32,0,1,1,0);
    GXInitTexObjLOD((Sig_GXInitTexObjLOD_GXTexObj *)v0,1,1,pool->zero,pool->zero,pool->zero,0,0,0);
    {
    int v58, v56;
    for(v56=0;v56<4;v56++) {
        for(v58=0;v58<8;v58++) {
            GXInitTexObj((Sig_GXInitTexObj_GXTexObj *)(v0+v56*2304+v58*288+800),(void *)(v0+v56*2304+v58*288+544),16,16,2,1,1,0);
            GXInitTexObjLOD((Sig_GXInitTexObjLOD_GXTexObj *)(v0+v56*2304+v58*288+800),0,0,pool->zero,pool->zero,pool->zero,0,0,0);
        }
    }
    }
    GXInvalidateTexAll();
    lbl_1_data_2A7E0.unk_2C=(u32)fn_1_D523C;
}
/* fzgx:end fn_1_D4964 */

/* fzgx:begin fn_1_D4FFC noprologue */
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3_D4FFC;

struct MdlLoadState_D4FFC {
    u8 pad_0[0x2620];
    f32 rand0;
    f32 rand1;
    s16 thresh[4];
    s16 sel[4];
};

extern f32 lbl_1_rodata_6168[112];
extern s16 camera_get_mode(void);
extern s32 fn_1_6EC0(u8 value);
extern u32 fn_1_864E8(int index);
extern void fn_1_862A8(int mode, Vec3_D4FFC *out);
extern f32 lbl_8006D6FC(Vec3_D4FFC *a, Vec3_D4FFC *b);
extern u32 lbl_801A66A0;
extern u32 lbl_801A63C0;

extern void DCFlushRange(void *address, u32 length);

/* Primes the TU literal pool so this function's constants land at retail's offsets. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.6499999761581421f;
    s = 0.75f;
    s = 1.0f;
    s = 0.0f;
    s = 182.04444885253906f;
    d = 0.5;
    d = 2.0;
    d = 4503599627370496.0;
    s = 0.5f;
    s = 0.02500000037252903f;
    s = 0.9900000095367432f;
    s = 1.649999976158142f;
    s = 3000.0f;
    s = 100.0f;
}

__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    s32 table[64] = {
        0, 0, 14, 14, 0, 0, 14, 14, 12, 12, 9, 9, 12, 12, 9, 9,
        0, 0, -180, -180, 0, 0, -180, -180, -30, -30, 0, 0, -30, -30, 0, 0,
        0, 0, 20, -20, 0, 0, 20, -20, 10, -10, -10, 10, 10, -10, -10, 10,
        0, 0, 20, 20, 0, 0, -20, -20, 10, 10, -10, -10, -10, -10, 10, 10,
    };
    DCFlushRange(table, sizeof(table));
}
#pragma section code_type ".text"

static inline s32 rand15_D4FFC(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

void fn_1_D4FFC(u8 *base, u32 index) {
    struct MdlLoadState_D4FFC *s = (struct MdlLoadState_D4FFC *)(base + 0xC140);
    Vec3_D4FFC pos;
    Vec3_D4FFC ref = {0.0f, 1.0f, 0.0f};
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
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d; /* pool primer: volatile forces the stores that place the literals */
    s = 30.0f; s = 0.6499999761581421f; s = 0.75f; s = 1.0f; s = 0.0f; s = 182.04444885253906f;
    d = 0.5; d = 2.0; d = 4503599627370496.0;
    s = 0.5f; s = 0.02500000037252903f; s = 0.9900000095367432f; s = 1.649999976158142f; s = 3000.0f; s = 100.0f;
}
static const u32 fzgx_pool_table2[67] = {0x00000000, 0x00000000, 0x0000000E, 0x0000000E, 0x00000000, 0x00000000, 0x0000000E, 0x0000000E, 0x0000000C, 0x0000000C, 0x00000009, 0x00000009, 0x0000000C, 0x0000000C, 0x00000009, 0x00000009, 0x00000000, 0x00000000, 0xFFFFFF4C, 0xFFFFFF4C, 0x00000000, 0x00000000, 0xFFFFFF4C, 0xFFFFFF4C, 0xFFFFFFE2, 0xFFFFFFE2, 0x00000000, 0x00000000, 0xFFFFFFE2, 0xFFFFFFE2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000014, 0xFFFFFFEC, 0x00000000, 0x00000000, 0x00000014, 0xFFFFFFEC, 0x0000000A, 0xFFFFFFF6, 0xFFFFFFF6, 0x0000000A, 0x0000000A, 0xFFFFFFF6, 0xFFFFFFF6, 0x0000000A, 0x00000000, 0x00000000, 0x00000014, 0x00000014, 0x00000000, 0x00000000, 0xFFFFFFEC, 0xFFFFFFEC, 0x0000000A, 0x0000000A, 0xFFFFFFF6, 0xFFFFFFF6, 0xFFFFFFF6, 0xFFFFFFF6, 0x0000000A, 0x0000000A, 0x00000000, 0x3F800000, 0x00000000};
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp = fzgx_pool_table2; (void)cp; } /* keep the table in the pool section */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) { volatile f32 s = 0.8999999761581421f; s = 32767.0f; (void)s; } /* pool primer */
static const u32 fzgx_pool_table4[1] = {0};
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp = fzgx_pool_table4; (void)cp; } /* keep the table in the pool section */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) { volatile f32 s; volatile f64 d; d = 4503601774854144.0; s = 23.0f; s = 24.0f; (void)s; (void)d; } /* pool primer */
static const u32 fzgx_pool_table6[6] = {0,0,0,0,0,0xBF800000};
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp = fzgx_pool_table6; (void)cp; } /* keep the table in the pool section */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d; /* pool primer: volatile forces the stores that place the literals */
    s = 1.5f; s = 10.0f; s = 136.0f; s = 90.0f; s = 0.6000000238418579f; s = 0.4000000059604645f; s = 96.0f;
    s = 0.07999999821186066f; s = 0.10000000149011612f; s = 4.0f; s = 20.0f; s = 70.0f;
    (void)d;
}
#pragma section code_type ".text"
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
extern f32 lbl_1_rodata_6168[112];
extern void fn_1_681C(u8 value, void *out);
extern void fn_1_6898(u32, u32 *);
extern void fn_1_6914(u32, u32 *);
extern s32 fn_1_58C4(void);
extern s32 fn_1_66B8(void *, f32);
extern void fn_1_D550C(void *);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D668(u32 *);
static inline f32 distance_squared_operand(f32 right, f32 left) { return left * right; }
#pragma opt_dead_assignments off
static inline f32 distance_squared(f32 *a, f32 *b) {
    f32 dx = (*((a) + (0)));
    f32 dy = a[1];
    f32 dz = a[2];
    dx -= b[0]; dy -= (*((1) + (b))); dz -= b[2];
    dx = distance_squared_operand((dx), (dx));
    dx += dy * dy; dx += dz * dz;
    return dx;
}
#pragma opt_dead_assignments reset

static inline f32 fn_1_D59A8_operand(f32 left, f32 right) { return left * right; }
static inline f32 fn_1_D59A8_operand_(f32 right, f32 left) { return left * right; }
#pragma opt_common_subs on
static inline f32 fn_1_D59A8_operand__(f32 left, f32 right) { return left * right; }
static inline f32 fn_1_D59A8_operand___(f32 left, f32 right) { left += right; return left; }
void fn_1_D59A8(struct fn_1_D59A8_obj *obj) {
    f32 v44[3]; f32 v38[3]; f32 v2c[3]; f32 v20[3]; f32 v14[3]; f32 v8[3];
    f32 step1;
    s32 i;
    struct { s32 value; } j;
    u32 count;
    fn_1_681C(0, (u32 *)v44);
    fn_1_6898(0, (u32 *)v38);
    step1 = (0.0799999982f);
    for (i = 0; i < 3; i++) {
        obj->elems[i].unk_2C = obj->elems[i].unk_2C - 1;
        obj->elems[i].pos[0] = obj->elems[i].pos[0] + step1;
        obj->elems[i].pos[2] = fn_1_D59A8_operand___((obj->elems[i].pos[2]), (((0.100000001f))));
        obj->elems[i].unk_28 = obj->elems[i].unk_28 + obj->elems[i].unk_2A;
        count = fn_1_58C4();
        fn_1_681C(0, (u32 *)v8);
        best:;
        {
            f32 best;
            best = lbl_8006D0B4(distance_squared(&obj->elems[i].pos[0], v8));
            for (j.value = 1; (u32)j.value < count; j.value++) {
                fn_1_681C((u8)j.value, (u32 *)v8);
                best < lbl_8006D0B4(distance_squared(&obj->elems[i].pos[0], v8))
                    ? (best = best) : (best = lbl_8006D0B4(distance_squared(&obj->elems[i].pos[0], v8)));
            }
            if (fn_1_66B8(&obj->elems[i].pos[0], (4.0f)) == 0) {
                fn_1_D550C(&obj->elems[i].pos[0]);
            }
            if (obj->elems[i].unk_2C < -180 && best > (30.0f)) {
                fn_1_D550C(&obj->elems[i].pos[0]);
            }
        }
    }
    obj->elems[i].unk_2C = obj->elems[i].unk_2C - 1;
    fn_1_681C(0, (u32 *)v2c);
    fn_1_6914(0, (u32 *)v20);
    v14[0] = v20[0] - v2c[0];
    v14[1] = (*((v20) + (1))) - (*((1) + (v2c)));
    v14[2] = v20[2] - v2c[2];
    lbl_8006D668((u32 *)v14);
    obj->elems[3].pos[0] = (f32)(v2c[0] + (f32)(fn_1_D59A8_operand_(((20.0f)), (v14[0]))));
    obj->elems[3].pos[1] = (f32)(v2c[1] + (f32)(fn_1_D59A8_operand((v14[1]), ((20.0f)))));
    obj->elems[3].pos[2] = (f32)(v2c[2] + (f32)(fn_1_D59A8_operand__((v14[2]), ((20.0f)))));
    obj->elems[3].unk_24 = (70.0f);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_D59A8 */

/* fzgx:begin fn_1_D5C68 */
// fn_1_D5C68: returns a constant.
int fn_1_D5C68(void) {
    return 0;
}
/* fzgx:end fn_1_D5C68 */
