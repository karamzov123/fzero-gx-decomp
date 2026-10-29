#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bitmap.h"

extern void fn_1_48214(int index, int enabled);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);
extern s32 lbl_801A6410;
extern void OSPanic(const unsigned char *, ...);
extern int fn_1_45D0(int, int, const unsigned char *, int);
extern int fn_80008F88(int, int);
extern void fn_8006FDEC(void);
extern void fn_80009064(u32 value);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, s32 arg3);
extern void *fn_1_48730(u32 value);
extern void fn_1_47AD4(Obj_1_data_FCD4 *obj, u8 value, int arg2, int arg3);
extern f32 lbl_1_rodata_10C0[5];
extern f32 lbl_1_bss_3E05C;

extern void *fn_1_48730(u32 value);

/* fzgx:begin fn_1_47E54 */
typedef struct {
    s32 unk_0;
    s32 unk_4[9];
} Fn147E54Entry;

extern void OSPanic(const unsigned char *, ...);
extern void fn_1_465D0(s32, s32);
extern u32 lbl_801A66B4;

void fn_1_47E54(s32 index) {
    s32 valid;

    if (index > 0xbb) {
        valid = 0;
    } else {
        valid = index >= 0;
    }
    if (valid == 0) {
        OSPanic(lbl_1_data_1A368, 0x18c, lbl_1_data_1A374);
    }
    fn_1_465D0(*(s32 *)((u8 *)&lbl_1_data_FCD4.unk_4 + index * 0x28 + lbl_801A66B4 * 4), 1);
}
/* fzgx:end fn_1_47E54 */

/* fzgx:begin fn_1_47EE4 noprologue */
#include "rel/main_rel/bitmap.h"

typedef struct {
    s32 unk_0;
    u8 pad_4[0x24];
} Fn147EE4Entry;

extern void OSPanic(const unsigned char *, ...);
extern void fn_1_47AD4(Fn147EE4Entry *object, s32 arg1, s32 arg2, s32 arg3);

void fn_1_47EE4(s32 index) {
    Fn147EE4Entry *object;
    s32 valid;

    object = (Fn147EE4Entry *)((u8 *)&lbl_1_data_FCD4 + index * 0x28);
    if (index > 0xbb) {
        valid = 0;
    } else {
        valid = index >= 0;
    }
    if (valid == 0) {
        OSPanic(lbl_1_data_1A368, 0x1a8, lbl_1_data_1A374);
    }
    if (object->unk_0 == 0) {
        fn_1_47AD4(object, 0, 1, 1);
    }
}
/* fzgx:end fn_1_47EE4 */

/* fzgx:begin fn_1_47F74 noprologue */
#include "rel/main_rel/bitmap.h"

typedef struct {
    s32 unk_0;
    u8 pad_4[0x24];
} Fn147F74Entry;

extern void OSPanic(const unsigned char *, ...);
extern void fn_1_47AD4(Fn147F74Entry *object, s32 arg1, s32 arg2, s32 arg3);

void fn_1_47F74(s32 index) {
    Fn147F74Entry *object;
    s32 valid;

    object = (Fn147F74Entry *)((u8 *)&lbl_1_data_FCD4 + index * 0x28);
    if (index > 0xbb) {
        valid = 0;
    } else {
        valid = index >= 0;
    }
    if (valid == 0) {
        OSPanic(lbl_1_data_1A368, 0x1b5, lbl_1_data_1A374);
    }
    if (object->unk_0 == 0) {
        fn_1_47AD4(object, 0, 0, 1);
    }
}
/* fzgx:end fn_1_47F74 */

/* fzgx:begin fn_1_48004 noprologue */
#include "rel/main_rel/bitmap.h"

typedef struct {
    s32 unk_0;
    u8 pad_4[0x24];
} BitmapEntry;

extern void OSPanic(const u8 *, ...);
extern void fn_1_47AD4(BitmapEntry *, s32, s32, s32);
extern void fn_1_48418(s32);

void fn_1_48004(s32 index, s32 image) {
    BitmapEntry *entry;
    s32 valid;

    entry = (BitmapEntry *)((u8 *)&lbl_1_data_FCD4 + index * 0x28);
    if (index > 0xbb) {
        valid = 0;
    } else {
        valid = index >= 0;
    }
    if (valid == 0) {
        OSPanic(lbl_1_data_1A368, 0x1c5, lbl_1_data_1A374);
    }
    if (entry->unk_0 == 0) {
        if (image == 0) {
            if (index > 0xbb) {
                valid = 0;
            } else {
                valid = index >= 0;
            }
            if (valid == 0) {
                OSPanic(lbl_1_data_1A368, 0x1b5, lbl_1_data_1A374);
            }
            if (entry->unk_0 == 0) {
                fn_1_47AD4(entry, 0, 0, 1);
            }
        } else {
            fn_1_48418(image);
            fn_1_47AD4(entry, image, 0, 1);
        }
    }
}
/* fzgx:end fn_1_48004 */

/* fzgx:begin fn_1_4811C */
// Enables the bitmap entry identified by the caller.
void fn_1_4811C(int arg) {
    fn_1_48214(arg, 1);
}
/* fzgx:end fn_1_4811C */

/* fzgx:begin fn_1_48140 */
// Disables the bitmap entry supplied by the caller.
void fn_1_48140(int index) {
    fn_1_48214(index, 0);
}
/* fzgx:end fn_1_48140 */

/* fzgx:begin fn_1_48164 */
// Enables matching bitmap entries in the shared bitmap table.
void fn_1_48164(int value) {
    s16 index;
    Obj_1_data_FCD4 *entry;

    index = 1;
    entry = (Obj_1_data_FCD4 *)((u8 *)&lbl_1_data_FCD4 + 0x28);
    for (; index < 0xbc; index++, entry = (Obj_1_data_FCD4 *)((u8 *)entry + 0x28)) {
        if ((s32)entry->unk_0 != 0 && entry->unk_24 == value) {
            fn_1_48214(index, 1);
        }
    }
}
/* fzgx:end fn_1_48164 */

/* fzgx:begin fn_1_481E8 */
// Initializes the bitmap entry and refreshes the related bitmap state.
void fn_1_481E8(int arg0) {
    fn_1_48214(arg0, 0);
    fn_1_4DDC0();
    fn_1_4F724();
}
/* fzgx:end fn_1_481E8 */

/* fzgx:begin fn_1_48214 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bitmap.h"

extern s32 lbl_801A6410;
extern void fn_8006FDEC(void);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, s32 arg3);
extern void fn_1_484CC(s32);

typedef struct {
    s32 unk_0;
    u32 unk_4;
    u8 pad_8[0x18];
    Obj_1_data_FCD4_At20 *unk_20;
    u8 unk_24;
    u8 pad_25[0x3];
} TexRecord;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    s32 unk_8;
} BitmapEntry;

// Iterates texture records in a range, tearing down bitmap references and
// releasing dependent texture state.
void fn_1_48214(s32 index, s32 enabled) {
    int found;
    s32 n;
    s16 i;
    s16 end;
    TexRecord *record;

    fn_8006FDEC();

    if (index == 0xbc) {
        i = 1;
        end = 0xbc;
    } else {
        s32 low;
        if (index >= 1) {
            low = index;
        } else {
            low = 1;
        }
        i = (s16)low;
        end = (s16)(index + 1);
    }

    record = (TexRecord *)((u8 *)&lbl_1_data_FCD4 + i * 0x28);

    while (i < end) {
        if (record->unk_0 != 0) {
            if (record->unk_24 == 0) {
                fn_1_46B4(lbl_801A6410, record->unk_20->unk_C,
                          (char *)lbl_1_data_1A368, 0x21e);
                fn_1_46B4(lbl_801A6410, (u32)record->unk_20,
                          (char *)lbl_1_data_1A368, 0x21f);
                record->unk_0 = 0;
            } else {
                BitmapEntry *bitmap =
                    (BitmapEntry *)((u8 *)&lbl_1_data_6CA0 +
                                    record->unk_24 * 12);

                fn_1_46B4(bitmap->unk_0, record->unk_20->unk_C,
                          (char *)lbl_1_data_1A368, 0x223);
                fn_1_46B4(bitmap->unk_0, (u32)record->unk_20,
                          (char *)lbl_1_data_1A368, 0x224);
                record->unk_0 = 0;
                if (enabled == 0) {
                    found = 0;
                    for (n = 0; n < 0xbc; n++) {
                        TexRecord *scan;
                        u8 sc;
                        u8 rc;

                        scan = (TexRecord *)((u8 *)&lbl_1_data_FCD4 + n * 0x28);
                        if (scan->unk_0 != 0) {
                            sc = scan->unk_24;
                            rc = record->unk_24;
                            if (sc == rc) {
                                found = 1;
                            }
                        }
                    }
                    if (found == 0) {
                        fn_1_484CC(record->unk_24);
                    }
                }
            }
        }
        i++;
        record = (TexRecord *)((u8 *)record + 0x28);
    }
}
/* fzgx:end fn_1_48214 */

/* fzgx:begin fn_1_48418 */
typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
} BitmapSlot;

void fn_1_48418(int index) {
    BitmapSlot *obj = (BitmapSlot *)&lbl_1_data_6CA0 + index;
    int valid;
    if (index > 2) {
        valid = 0;
    } else {
        valid = index >= 0;
    }
    if (valid == 0) {
        OSPanic(lbl_1_data_1A368, 0x248, lbl_1_data_1A390);
    }
    if (obj->unk_0 == -1) {
        obj->unk_4 = fn_1_45D0(lbl_801A6410, obj->unk_8, lbl_1_data_1A368, 0x250);
        obj->unk_0 = fn_80008F88(obj->unk_4, obj->unk_4 + obj->unk_8);
    }
}
/* fzgx:end fn_1_48418 */

/* fzgx:begin fn_1_484CC */
// Releases a bitmap and invalidates dependent texture records.
void fn_1_484CC(s32 index) {
    u8 *texture_record;
    s16 texture_index;
    u32 *bitmap_entry;

    bitmap_entry = (u32 *)((u8 *)&lbl_1_data_6CA0 + index * 12);
    if (*(s32 *)bitmap_entry == -1) {
        return;
    }

    fn_8006FDEC();
    texture_index = 1;
    texture_record = (u8 *)&lbl_1_data_FCD4 + 0x28;
    while (texture_index < 188) {
        if (*(s32 *)texture_record != 0 && texture_record[0x24] == index) {
            fn_1_48214(texture_index, 1);
        }
        texture_index++;
        texture_record += 0x28;
    }

    fn_80009064(bitmap_entry[0]);
    fn_1_46B4(lbl_801A6410, bitmap_entry[1],
              (char *)lbl_1_data_1A368, 0x265);
    bitmap_entry[0] = (u32)-1;
}
/* fzgx:end fn_1_484CC */

/* fzgx:begin fn_1_485A8 */
u32 fn_1_485A8(s32 index) {
    return ((Obj_1_data_FCD4 *)((u8 *)&lbl_1_data_FCD4 + index * 0x28))->unk_0 != 0;
}
/* fzgx:end fn_1_485A8 */

/* fzgx:begin fn_1_485C8 noprologue */
#include "types.h"

extern struct fn_1_485C8_lbl_1_data_FCD4 lbl_1_data_FCD4;
extern u32 lbl_1_bss_3E020;

struct fn_1_485C8_lbl_1_data_FCD4_0_E40 {
    u8 pad_0[0x20];
    u32 unk_20;
    u8 pad_24[0x4];
};
struct fn_1_485C8_lbl_1_data_FCD4 {
    struct fn_1_485C8_lbl_1_data_FCD4_0_E40 unk_0[1];
};

void fn_1_485C8(u32 arg0) {
    lbl_1_bss_3E020 = lbl_1_data_FCD4.unk_0[arg0].unk_20;
}
/* fzgx:end fn_1_485C8 */

/* fzgx:begin fn_1_48690 */
// Return the current bitmap width, or the default width when no bitmap is active.
u16 fn_1_48690(u32 unused) {
    void *bitmap = fn_1_48730(unused);

    if (bitmap != 0) {
        return *(u16 *)((u8 *)bitmap + 8);
    }

    return 8;
}
/* fzgx:end fn_1_48690 */

/* fzgx:begin fn_1_486C4 */
// Return the current bitmap height, or the default height when no bitmap is active.
u16 fn_1_486C4(u32 value) {
    void *bitmap = (void *)fn_1_48730(value);

    if (bitmap != 0) {
        return *(u16 *)((u8 *)bitmap + 0xA);
    }
    return 8;
}
/* fzgx:end fn_1_486C4 */

/* fzgx:begin fn_1_486F8 */
// Return the bitmap entry flags for the slot identified by value.
u32 fn_1_486F8(u32 value) {
    void *bitmap = fn_1_48730(value);

    if (bitmap != 0) {
        return *(u32 *)bitmap & 0x1F;
    }
    return 0;
}
/* fzgx:end fn_1_486F8 */

/* fzgx:begin fn_1_48730 */
// Look up the bitmap data for the table and slot encoded in value.
void *fn_1_48730(u32 value) {
    u32 table_index = (value >> 8) & 0xffff;
    u32 slot_index = value & 0xff;
    Obj_1_data_FCD4 *entry =
        (Obj_1_data_FCD4 *)((u8 *)&lbl_1_data_FCD4 + table_index * 0x28);

    if (entry != 0 && (s32)entry->unk_0 == 1 && entry->unk_20 != 0) {
        return (u8 *)entry->unk_20->unk_4 + ((u8)slot_index << 4);
    }
    return 0;
}
/* fzgx:end fn_1_48730 */

/* fzgx:begin fn_1_4877C */
// fn_1_4877C: empty in retail (single blr).
void fn_1_4877C(void) {
}
/* fzgx:end fn_1_4877C */

/* fzgx:begin fn_1_48780 */
void fn_1_48780(void) {
    Obj_1_data_FCD4 *obj;
    int i;

    obj = (Obj_1_data_FCD4 *)((u8 *)&lbl_1_data_FCD4 + 0x28);
    for (i = 1; i < 0xBC; i++) {
        if ((int)obj->unk_0 != 0) {
            fn_1_47AD4(obj, obj->unk_24, 0, 0);
        }
        obj = (Obj_1_data_FCD4 *)((u8 *)obj + 0x28);
    }
}
/* fzgx:end fn_1_48780 */

/* fzgx:begin fn_1_487EC pool */
#ifndef GAME_MAIN_REL_BITMAP_TYPES_H
#define GAME_MAIN_REL_BITMAP_TYPES_H

#endif  // GAME_MAIN_REL_BITMAP_TYPES_H

extern f32 lbl_1_bss_3E05C;

extern s32 fn_1_48A0C(u32, u32, void *, u32);

typedef struct {
    s32 unk_0;
    u8 pad_4[0x28];
    u16 *unk_2C;
    s16 *unk_30;
    f32 unk_34;
} BitmapGroup;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3E058;
f32 lbl_1_bss_3E05C;
u32 lbl_1_bss_3E060[0x56B];
s32 lbl_1_bss_3F60C[0x56B];
s32 lbl_1_bss_40BB8;
s32 lbl_1_bss_40BBC[0x2C];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3E058;
    s = *(u8 *)&lbl_1_bss_3E05C;
    s = *(u8 *)&lbl_1_bss_3E060;
    s = *(u8 *)&lbl_1_bss_3F60C;
    s = *(u8 *)&lbl_1_bss_40BB8;
    s = *(u8 *)&lbl_1_bss_40BBC;
}
#pragma section code_type ".text"

static inline void reset_bitmap_groups(s32 zero, BitmapGroup **group, u16 **p) {
    s32 j;
    s32 *count;
    s32 k;

    lbl_1_bss_40BB8 = zero;
    count = lbl_1_bss_40BBC;
    for (j = zero; j < 0x2C; count++, j++, (*group)++) {
        *count = zero;
        if ((*group)->unk_0 == -1) {
            *p = (*group)->unk_2C;
            k = 0;
            while (**p != 0) {
                *(s16 *)((u8 *)(*group)->unk_30 + k) = -1;
                (*p)++;
                k += 2;
                (*count)++;
            }
        }
    }
}

void fn_1_487EC(void) {
    s32 *count;
    s32 j;
    BitmapGroup *group;
    s32 i;
    BitmapGroup *target;
    s32 n;
    u16 key;
    u16 *q;
    u16 *p;
    s32 k;

    for (i = 0; i < 0x56B; i++) {
        lbl_1_bss_3E060[i] = 0;
        lbl_1_bss_3F60C[i] = -1;
    }

    /* count the entries of every terminator-marked group and reset their slots */
    group = (BitmapGroup *)&lbl_1_data_1AEA8;
    reset_bitmap_groups(0, &group, &p);

    target = (BitmapGroup *)&lbl_1_data_1AEA8 + 42;
    for (i = 0; i < 0x56B; i++) {
        key = ((u16 *)&lbl_1_data_1A3B8)[i];
        n = 0;
        q = target->unk_2C;
        while (*q != 0) {
            if (*q == key && fn_1_48A0C(n, 0x2A, target, 1) != 0) {
                lbl_1_bss_40BB8++;
                break;
            }
            n++;
            q++;
        }
    }
}
/* fzgx:end fn_1_487EC */

/* fzgx:begin fn_1_48A0C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bitmap.h"

extern s32 lbl_801A6410;
extern u32 lbl_1_bss_3E060[1387];
extern u32 lbl_1_bss_3F60C[1388];
extern u8 lbl_1_bss_40C6C[44384];
extern void OSPanic(const char *, int, const char *, ...);
extern int fn_1_45D0(int, int, const char *, int);
extern u32 OSAllocFromArenaLo(u32, u32);
extern u32 fn_1_4BA24(u8, int, void *);
extern void GXInitTexObj(void *, void *, u16, u16, int, int, int, u8);

// Allocate (or share) the glyph texture for character `ch` of font slot `idx`.
// Returns 1 when a new texture was created, 0 otherwise.
extern u8 lbl_1_bss_4BB9C__fzgx_offset_0[];
extern u8 lbl_1_bss_4BBA0__fzgx_offset_0[];
extern u8 lbl_1_data_1A3B8__fzgx_offset_0[];
extern u8 lbl_1_data_1AE90__fzgx_offset_0[];
extern u8 lbl_1_data_1AE94__fzgx_offset_0[];
extern u8 lbl_1_data_1AE9C__fzgx_offset_0[];
extern u8 lbl_1_data_1B848__fzgx_offset_0[];
extern u8 lbl_1_data_1B860__fzgx_offset_0[];
extern u8 lbl_1_data_1B878__fzgx_offset_0[];
extern u8 lbl_1_data_1B888__fzgx_offset_0[];
extern u8 lbl_1_data_1B898__fzgx_offset_0[];
extern u8 lbl_1_data_1B8A8__fzgx_offset_0[];
extern u8 lbl_1_data_1B8B8__fzgx_offset_0[];
extern u8 lbl_1_data_1B8CC__fzgx_offset_0[];
extern u8 lbl_1_data_1B8E0__fzgx_offset_0[];
extern u8 lbl_1_data_1B8F4__fzgx_offset_0[];
extern u8 lbl_1_data_1B908__fzgx_offset_0[];
extern u8 lbl_1_data_1B920__fzgx_offset_0[];
extern u8 lbl_1_data_1B934__fzgx_offset_0[];
extern u8 lbl_1_data_1B948__fzgx_offset_0[];
extern u8 lbl_1_data_1B95C__fzgx_offset_0[];
extern u8 lbl_1_data_1B974__fzgx_offset_0[];
extern u8 lbl_1_data_1B988__fzgx_offset_0[];
extern u8 lbl_1_data_1B99C__fzgx_offset_0[];
extern u8 lbl_1_data_1B9B0__fzgx_offset_0[];
extern u8 lbl_1_data_1B9C0__fzgx_offset_0[];
extern u8 lbl_1_data_1B9D8__fzgx_offset_0[];
extern u8 lbl_1_data_1B9EC__fzgx_offset_0[];
extern u8 lbl_1_data_1BA00__fzgx_offset_0[];
extern u8 lbl_1_data_1BA14__fzgx_offset_0[];
extern u8 lbl_1_data_1BA28__fzgx_offset_0[];
extern u8 lbl_1_data_1BA3C__fzgx_offset_0[];
extern u8 lbl_1_data_1BA4C__fzgx_offset_0[];
extern u8 lbl_1_data_1BA60__fzgx_offset_0[];
extern u8 lbl_1_data_1BA74__fzgx_offset_0[];
extern u8 lbl_1_data_1BA8C__fzgx_offset_0[];
extern u8 lbl_1_data_1BAA4__fzgx_offset_0[];
extern u8 lbl_1_data_1BABC__fzgx_offset_0[];
extern u8 lbl_1_data_1BAD0__fzgx_offset_0[];
extern u8 lbl_1_data_1BAE8__fzgx_offset_0[];
extern u8 lbl_1_data_1BAFC__fzgx_offset_0[];
extern u8 lbl_1_data_1BB10__fzgx_offset_0[];
extern u8 lbl_1_data_1BB28__fzgx_offset_0[];
extern u8 lbl_1_data_1BB3C__fzgx_offset_0[];
extern u8 lbl_1_data_1BB50__fzgx_offset_0[];
extern u8 lbl_1_data_1BB68__fzgx_offset_0[];
extern u8 lbl_1_data_1BB7C__fzgx_offset_0[];
extern u8 lbl_1_data_1BB90__fzgx_offset_0[];
extern u8 lbl_1_data_1BBA0__fzgx_offset_0[];
extern u8 lbl_1_data_1BBB0__fzgx_offset_0[];
extern u8 lbl_1_data_1BC74__fzgx_offset_0[];
extern u8 lbl_1_data_1BC80__fzgx_offset_0[];
extern u8 lbl_1_data_1BC88__fzgx_offset_0[];
extern u8 lbl_1_data_1BC90__fzgx_offset_0[];
extern u8 lbl_1_data_1BC98__fzgx_offset_0[];
extern u8 lbl_1_data_1BCA4__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_1A3B8[700] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x81408141, 0x81428143, 0x81448145, 0x81468147, 0x81488149, 0x814A814B, 0x814C814D, 0x814F8151,  /* fzgx-allow: A1 retail data bytes */
    0x8158815B, 0x815E815F, 0x81608162, 0x81638165, 0x81668167, 0x81688169, 0x816A816D, 0x816E816F,  /* fzgx-allow: A1 retail data bytes */
    0x81708171, 0x81728175, 0x81768177, 0x8178817B, 0x817C817E, 0x81818183, 0x8184818F, 0x81908193,  /* fzgx-allow: A1 retail data bytes */
    0x81948195, 0x81968197, 0x819A81A0, 0x81A381E7, 0x81E881F4, 0x824F8250, 0x82518252, 0x82538254,
    0x82558256, 0x82578258, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B,
    0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282,
    0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292,
    0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x829F82A0, 0x82A182A2, 0x82A382A4, 0x82A582A6,
    0x82A782A8, 0x82A982AA, 0x82AB82AC, 0x82AD82AE, 0x82AF82B0, 0x82B182B2, 0x82B382B4, 0x82B582B6,
    0x82B782B8, 0x82B982BA, 0x82BB82BC, 0x82BD82BE, 0x82BF82C0, 0x82C182C2, 0x82C382C4, 0x82C582C6,
    0x82C782C8, 0x82C982CA, 0x82CB82CC, 0x82CD82CE, 0x82CF82D0, 0x82D182D2, 0x82D382D4, 0x82D582D6,
    0x82D782D8, 0x82D982DA, 0x82DB82DC, 0x82DD82DE, 0x82DF82E0, 0x82E182E2, 0x82E382E4, 0x82E582E6,
    0x82E782E8, 0x82E982EA, 0x82EB82EC, 0x82ED82EE, 0x82EF82F0, 0x82F18340, 0x83418342, 0x83438344,
    0x83458346, 0x83478348, 0x8349834A, 0x834B834C, 0x834D834E, 0x834F8350, 0x83518352, 0x83538354,
    0x83558356, 0x83578358, 0x8359835A, 0x835B835C, 0x835D835E, 0x835F8360, 0x83618362, 0x83638364,
    0x83658366, 0x83678368, 0x8369836A, 0x836B836C, 0x836D836E, 0x836F8370, 0x83718372, 0x83738374,
    0x83758376, 0x83778378, 0x8379837A, 0x837B837C, 0x837D837E, 0x83808381, 0x83828383, 0x83848385,
    0x83868387, 0x83888389, 0x838A838B, 0x838C838D, 0x838E838F, 0x83908391, 0x83928393, 0x83948395,
    0x8396839F, 0x83A083A1, 0x83A483A6, 0x83AD83AF, 0x83B083B2, 0x83B483B5, 0x83BF83D0, 0x88A488AB,
    0x88AC88B3, 0x88B588B6, 0x88C088C3, 0x88C888CA, 0x88CB88CC, 0x88CD88CF, 0x88D388D5, 0x88D988DA,
    0x88DB88E1, 0x88E388E6, 0x88E788EA, 0x88F388F5, 0x88F688F8, 0x88F98940, 0x89418945, 0x8946894A,
    0x895C895E, 0x89638965, 0x89668968, 0x89698970, 0x897A897E, 0x89808983, 0x89848985, 0x89878989,
    0x898A898E, 0x898F8993, 0x899C899E, 0x899F89A1, 0x89A389A4, 0x89AD89AE, 0x89AF89B1, 0x89B489B7,
    0x89B889B9, 0x89BA89BB, 0x89BC89BD, 0x89BF89C1, 0x89C289C5, 0x89C689C8, 0x89C989CA, 0x89CC89CD,
    0x89D289D4, 0x89D789D8, 0x89DC89DD, 0x89DF89E4, 0x89E589E6, 0x89EE89EF, 0x89F089F1, 0x89F389F5,
    0x89F689F7, 0x89F989FC, 0x8A428A43, 0x8A448A45, 0x8A4A8A4D, 0x8A4F8A51, 0x8A588A65, 0x8A678A69,
    0x8A6C8A6D, 0x8A6F8A70, 0x8A778A79, 0x8A7A8A7C, 0x8A848A87, 0x8A888AA3, 0x8AA88AA9, 0x8AAA8AAC,
    0x8AAE8AAF, 0x8AB18AB4, 0x8AB58AB7, 0x8ABB8ABD, 0x8AC28AC7, 0x8AC88ACD, 0x8ACF8AD3, 0x8AD48AD6,
    0x8AD78AD9, 0x8ADB8ADC, 0x8AE28AE6, 0x8AE78AE8, 0x8AE98AEB, 0x8AEC8AED, 0x8AEE8AEF, 0x8AF08AF1,
    0x8AF38AF6, 0x8AFA8AFC, 0x8B408B41, 0x8B438B49, 0x8B4B8B4C, 0x8B4D8B4E, 0x8B518B53, 0x8B568B5A,
    0x8B5E8B60, 0x8B638B6C, 0x8B718B74, 0x8B788B79, 0x8B7B8B7D, 0x8B7E8B81, 0x8B858B86, 0x8B898B8B,
    0x8B8C8B8E, 0x8B908B91, 0x8B938B96, 0x8B978B9F, 0x8BA38BA4, 0x8BA58BA6, 0x8BAD8BAF, 0x8BB08BB3,
    0x8BB58BB6, 0x8BB98BBB, 0x8BBD8BBE, 0x8BBF8BC1, 0x8BC38BC6, 0x8BC78BC8, 0x8BC98BCF, 0x8BD88BD9,
    0x8BDE8BDF, 0x8BE08BE2, 0x8BE38BE5, 0x8BE68BEA, 0x8BEC8BEF, 0x8BF08BF2, 0x8BF38BF4, 0x8BF68BFC,
    0x8C4A8C4D, 0x8C4E8C50, 0x8C518C52, 0x8C578C59, 0x8C5A8C5E, 0x8C5F8C60, 0x8C628C68, 0x8C698C6E,
    0x8C6F8C70, 0x8C768C78, 0x8C798C7C, 0x8C7D8C82, 0x8C838C86, 0x8C878C88, 0x8C8B8C8C, 0x8C8D8C8F,
    0x8C928C95, 0x8C968C99, 0x8C9A8CA0, 0x8CA48CA8, 0x8CA98CAB, 0x8CAD8CAF, 0x8CB08CB1, 0x8CB38CB4,
    0x8CB58CB6, 0x8CB88CB9, 0x8CBB8CBE, 0x8CC08CC2, 0x8CC38CC4, 0x8CC58CC7, 0x8CC88CCB, 0x8CCC8CD6,
    0x8CD98CDD, 0x8CE28CE3, 0x8CE58CEB, 0x8CF08CF3, 0x8CF58CF6, 0x8CF78CF8, 0x8CFB8CFC, 0x8D448D48,
    0x8D498D4B, 0x8D4C8D4E, 0x8D528D55, 0x8D588D5A, 0x8D5C8D62, 0x8D6C8D72, 0x8D738D75, 0x8D778D7E,
    0x8D808D82, 0x8D868D87, 0x8D8B8D8F, 0x8D908D91, 0x8D938D95, 0x8D968D9C, 0x8D9E8DA0, 0x8DA18DA2,
    0x8DA58DA6, 0x8DAA8DB0, 0x8DB68DB7, 0x8DB88DC3, 0x8DC48DC5, 0x8DC88DCB, 0x8DCE8DCF, 0x8DD08DD3,
    0x8DD58DD7, 0x8DDA8DDB, 0x8DDD8DDE, 0x8DDF8DE0, 0x8DEC8DED, 0x8E408E42, 0x8E458E4F, 0x8E518E52,
    0x8E598E5A, 0x8E5D8E5E, 0x8E638E64, 0x8E678E68, 0x8E698E6A, 0x8E6C8E6D, 0x8E6E8E70, 0x8E718E74,
    0x8E758E76, 0x8E778E78, 0x8E7B8E7E, 0x8E808E84, 0x8E8A8E8B, 0x8E8E8E91, 0x8E958E96, 0x8E978E99,
    0x8E9A8E9D, 0x8E9E8E9F, 0x8EA18EA6, 0x8EA98EAB, 0x8EAE8EAF, 0x8EB88EBA, 0x8EBF8EC0, 0x8ECA8ECB,
    0x8ECC8ECD, 0x8ED08ED2, 0x8ED38ED4, 0x8ED78EDF, 0x8EE18EE3, 0x8EE58EE6, 0x8EE78EE8, 0x8EEA8EEB,
    0x8EED8EEF, 0x8EF18EF3, 0x8EF58EF6, 0x8EFB8EFC, 0x8F438F45, 0x8F478F49, 0x8F4B8F50, 0x8F518F57,
    0x8F5A8F5B, 0x8F5C8F5D, 0x8F5F8F61, 0x8F628F63, 0x8F648F68, 0x8F6A8F6B, 0x8F6E8F6F, 0x8F708F74,
    0x8F758F80, 0x8F848F87, 0x8F888F89, 0x8F8A8F8F, 0x8F918F94, 0x8F958F97, 0x8F988F9C, 0x8F9D8F9E,
    0x8F9F8FA4, 0x8FA78FAA, 0x8FAB8FAC, 0x8FAD8FB2, 0x8FB38FB8, 0x8FBB8FC1, 0x8FC48FC6, 0x8FC88FCC,
    0x8FCD8FCE, 0x8FD08FD5, 0x8FD88FDA, 0x8FDC8FE1, 0x8FE38FE4, 0x8FE68FE8, 0x8FEA8FED, 0x8FEE8FF3,
    0x8FFC9041, 0x90449045, 0x90469047, 0x9048904A, 0x904B904D, 0x90539054, 0x90559056, 0x905B905E,
    0x905F9065, 0x90679069, 0x906C906E, 0x9073907D, 0x90849085, 0x90879088, 0x908B908C, 0x9094909D,
    0x90A290A3, 0x90A690A7, 0x90A890AA, 0x90AB90AC, 0x90AD90AE, 0x90AF90B3, 0x90B690B7, 0x90B890BA,
    0x90BB90C0, 0x90C290C3, 0x90C890C9, 0x90CC90CD, 0x90CE90CF, 0x90D190D4, 0x90D590D8, 0x90DA90DC,
    0x90DD90E0, 0x90E190E2, 0x90E690E7, 0x90E890E9, 0x90EA90ED, 0x90F290F3, 0x90F490F5, 0x90F990FC,
    0x91449149, 0x914F9150, 0x91529153, 0x915E915F, 0x91619163, 0x91669167, 0x9168916E, 0x91729177,
    0x917A917B, 0x917D9180, 0x91819188, 0x918A918D, 0x91909193, 0x91959196, 0x91979198, 0x919C919D,
    0x91A091A2, 0x91A491A5, 0x91A691A7, 0x91A991AA, 0x91AB91AC, 0x91AE91AF, 0x91B091B1, 0x91B691B8,
    0x91B991BC, 0x91BD91C5, 0x91CA91CC, 0x91CE91D2, 0x91D491D6, 0x91D891DC, 0x91DD91DE, 0x91DF91E0,
    0x91E391E4, 0x91E591E6, 0x91E891EC, 0x91F091F5, 0x92409242, 0x92449245, 0x924E9250, 0x92539254,
    0x92559261, 0x92629263, 0x92659266, 0x9269926A, 0x926B926D, 0x926E9270, 0x92759276, 0x927A9281,
    0x92859286, 0x92879288, 0x9289928D, 0x92989299, 0x92A192A3, 0x92A692A7, 0x92AD92AE, 0x92B292B4,
    0x92B792B8, 0x92BC92C0, 0x92C792C9, 0x92CA92CD, 0x92D792E1, 0x92E892E9, 0x92EA92ED, 0x92EF92F6,
    0x93409347, 0x9349934B, 0x93539354, 0x93569357, 0x93589359, 0x935C935D, 0x935F9360, 0x9364936E,
    0x936F9371, 0x93729373, 0x93779378, 0x937A937C, 0x93809381, 0x938B9390, 0x93969399, 0x939A939D,
    0x939E93A5, 0x93A693AA, 0x93AC93AD, 0x93AE93AF, 0x93B093B7, 0x93B993BA, 0x93BE93BF, 0x93C193C6,
    0x93C793CB, 0x93CD93DD, 0x93DF93E0, 0x93E493EE, 0x93EF93F1, 0x93F793FA, 0x93FC9440, 0x94439445,
    0x9446944D, 0x944E944F, 0x94529459, 0x945C945D, 0x94659468, 0x946A9470, 0x94729473, 0x94749477,
    0x9479947A, 0x947B947C, 0x94839484, 0x948E9492, 0x9497949A, 0x94A094AD, 0x94AF94B1, 0x94B294B4,
    0x94BA94BB, 0x94BC94BD, 0x94C494C5, 0x94C694CC, 0x94D494DA, 0x94DB94DE, 0x94DF94E2, 0x94E394E4,
    0x94E594E6, 0x94E994ED, 0x94EF94F0, 0x94F194F2, 0x94F594F6, 0x94FC9543, 0x954B9550, 0x95579559,
    0x955C955D, 0x95619562, 0x9569956E, 0x95719573, 0x95749576, 0x95779578, 0x957A957B, 0x957C9581,
    0x95829583, 0x95849589, 0x958B9590, 0x95919594, 0x95959597, 0x959C959D, 0x959E95A0, 0x95A195A5,
    0x95A895AA, 0x95B195B6, 0x95B795BA, 0x95BD95BF, 0x95C095C2, 0x95C795CA, 0x95CF95D0, 0x95D495D9,
    0x95DB95DF, 0x95E095E2, 0x95E595E6, 0x95EF95F1, 0x95F395F6, 0x95F895F9, 0x95FA95FB, 0x9640964A,
    0x964B964D, 0x964F9652, 0x96539656, 0x96579659, 0x965C965D, 0x965F9660, 0x96669668, 0x966C966E,
    0x9676967A, 0x967B9681, 0x96829683, 0x96849687, 0x96889695, 0x9696969C, 0x969D969E, 0x969F96A1,
    0x96A296A3, 0x96A796AD, 0x96AF96B0, 0x96B196B2, 0x96B396B6, 0x96BC96BD, 0x96BE96C5, 0x96CA96CD,
    0x96D296D7, 0x96D896D9, 0x96DA96DF, 0x96E296E5, 0x96E996EC, 0x96F096F1, 0x96F396F4, 0x96FC9741,
    0x97449745, 0x9746974C, 0x97529754, 0x97569759, 0x975C975D, 0x975E975F, 0x97619763, 0x9765976C,
    0x97709774, 0x97769778, 0x977A977B, 0x977D977E, 0x97819783, 0x9788978A, 0x978B978D, 0x978E9791,
    0x97979798, 0x979D97A0, 0x97A397A5, 0x97A697A7, 0x97AC97AF, 0x97B397B7, 0x97B997BC, 0x97BF97C3,
    0x97C797CA, 0x97CC97CD, 0x97CE97D6, 0x97DC97DE, 0x97DF97E1, 0x97E297E7, 0x97ED97EE, 0x97F097F1,
    0x97F397F6, 0x97FB9841, 0x98439849, 0x984A9851, 0x98549856, 0x9859985E, 0x985F9861, 0x98629863,
    0x98659866, 0x98729C66, 0x9C729D7C, 0xE0A3E0F8, 0xE3A9E690, 0xE8A60000, 0x0, 0x4E554C4C,
    0x0, 0x6173635F, 0x32347832, 0x34000000
};
static u32 fzgx_pool_data_lbl_1_data_1AEA8[616] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x201, 0x1C180000, 0x30, 0x3A, 0xB010000, 0x3DBA2E8C, 0x3F800000, 0x3B54C77B,
    0x3D2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x205, 0x1C180000,
    0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3BEA0EA1, 0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0xF, 0x8100000, 0x20, 0x7A,
    0x10060000, 0x3D800000, 0x3E000000, 0x3C000000, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0xE, 0xC0C0000, 0x0, 0x7F, 0x10080000, 0x3D800000,
    0x3E000000, 0x3BAAAAAB, 0x3C2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x7, 0xC0E0000, 0x41, 0x5A, 0x8040000, 0x3E000000, 0x3E800000, 0x3C2AAAAB,
    0x3C924925, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x8, 0x12120000,
    0x20, 0x73, 0xC070000, 0x3DAAAAAB, 0x3E100000, 0x3B97B426, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x8, 0x12120000, 0x20, 0x73,
    0xC070000, 0x3DAAAAAB, 0x3E100000, 0x3B97B426, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x3, 0xC100000, 0x20, 0x7A, 0xC080000, 0x3DAAAAAB,
    0x3E000000, 0x3BE38E39, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x4, 0x18180000, 0x20, 0x7A, 0xC080000, 0x3DAAAAAB, 0x3E000000, 0x3B638E39,
    0x3BAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x890E, 0x80A0000,
    0x41, 0x5A, 0x8040000, 0x3E000000, 0x3E800000, 0x3C800000, 0x3CCCCCCD, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x944E, 0x18200000, 0x30, 0x3D,
    0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3C088889, 0x3C2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9452, 0x18180000, 0x31, 0x36, 0x3020000, 0x3EAAAAAB,
    0x3F000000, 0x3C638E39, 0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9427, 0x2C380000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B94F209,
    0x3C124925, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9428, 0x10140000,
    0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3C4CCCCD, 0x3CCCCCCD, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9433, 0x14140000, 0x30, 0x3D,
    0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3C23D70A, 0x3C888889, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x942C, 0x18200000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD,
    0x3F000000, 0x3C088889, 0x3C800000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x942E, 0x3C340000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B5A740E,
    0x3C1D89D9, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x943D, 0x48400000,
    0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B360B61, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9703, 0x10140000, 0x30, 0x3B,
    0xC010000, 0x3DAAAAAB, 0x3F800000, 0x3BAAAAAB, 0x3D4CCCCD, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9731, 0x18200000, 0x30, 0x3D, 0x5030000, 0x3E4CCCCD,
    0x3EAAAAAB, 0x3C088889, 0x3C2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9733, 0x18180000, 0x31, 0x36, 0x3020000, 0x3EAAAAAB, 0x3F000000, 0x3C638E39,
    0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x971A, 0x12140000,
    0x2C, 0x5A, 0xC040000, 0x3DAAAAAB, 0x3E800000, 0x3B97B426, 0x3C4CCCCD, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x971B, 0xC0C0000, 0x2C, 0x5A,
    0xC040000, 0x3DAAAAAB, 0x3E800000, 0x3BE38E39, 0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x972D, 0x20240000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD,
    0x3F000000, 0x3BCCCCCD, 0x3C638E39, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x972E, 0x282C0000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3BA3D70A,
    0x3C3A2E8C, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9811, 0x20180000,
    0x30, 0x3C, 0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3BCCCCCD, 0x3C638E39, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9902, 0x80C0000, 0x30, 0x39,
    0xA010000, 0x3DCCCCCD, 0x3F800000, 0x3C4CCCCD, 0x3DAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9905, 0xA100000, 0x30, 0x39, 0xA010000, 0x3DB6DB6E,
    0x3F800000, 0x3C124925, 0x3D800000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9906, 0xC1A0000, 0x2C, 0x5A, 0xC040000, 0x3DAAAAAB, 0x3E800000, 0x3BE38E39,
    0x3C1D89D9, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x990A, 0x18200000,
    0x41, 0x5A, 0xA030000, 0x3DCCCCCD, 0x3EAAAAAB, 0x3B888889, 0x3C2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x990B, 0xC100000, 0x41, 0x5A,
    0xA040000, 0x3DCCCCCD, 0x3E800000, 0x3C088889, 0x3C800000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x990D, 0x80C0000, 0x30, 0x39, 0xA010000, 0x3DCCCCCD,
    0x3F800000, 0x3C4CCCCD, 0x3DAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9725, 0x14140000, 0x30, 0x3D, 0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3C23D70A,
    0x3C888889, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9A1E, 0x10100000,
    0x41, 0x5A, 0x8040000, 0x3E000000, 0x3E800000, 0x3C000000, 0x3C800000, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9A26, 0x10100000, 0x30, 0x39,
    0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3C4CCCCD, 0x3D000000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9A07, 0xC1A0000, 0x2C, 0x5A, 0xC040000, 0x3DAAAAAB,
    0x3E800000, 0x3BE38E39, 0x3C1D89D9, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9E29, 0x18100000, 0x30, 0x3C, 0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3C088889,
    0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9E22, 0x28340000,
    0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3BA3D70A, 0x3C1D89D9, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9E27, 0x38440000, 0x30, 0x39,
    0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B6A0EA1, 0x3BF0F0F1, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9F0A, 0x20180000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD,
    0x3F000000, 0x3BCCCCCD, 0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0xBB02, 0x30240000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B888889,
    0x3C638E39, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0xBB04, 0x20180000,
    0x30, 0x3C, 0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3BCCCCCD, 0x3C638E39, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0xFFFFFFFF, 0x18180000, 0x0, 0x0,
    0x1010000, 0x3F800000, 0x3F800000, 0x3D2AAAAB, 0x3D2AAAAB, (u32)lbl_1_data_1AE9C__fzgx_offset_0, 0x1200000, (u32)lbl_1_data_1A3B8__fzgx_offset_0,
    (u32)lbl_1_bss_4BBA0__fzgx_offset_0, 0x3F800000, 0x9603, 0x18200000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD,
    0x3F000000, 0x3C088889, 0x3C800000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000
};
static u32 fzgx_pool_data_lbl_1_data_1B848[288] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x464F4E54, 0x5F414456, 0x41435F43, 0x52454449, 0x545F4E55, 0x4D000000, 0x464F4E54, 0x5F414456,
    0x41435F53, 0x54415254, 0x5F4E554D, 0x0, 0x464F4E54, 0x5F415343, 0x5F387831, 0x36000000,
    0x464F4E54, 0x5F415343, 0x5F313278, 0x31320000, 0x464F4E54, 0x5F415343, 0x5F313478, 0x31360000,
    0x464F4E54, 0x5F415343, 0x5F313878, 0x31380000, 0x464F4E54, 0x5F415343, 0x5F313878, 0x31385F54,
    0x494D4500, 0x464F4E54, 0x5F415343, 0x5F53454C, 0x5F313278, 0x31360000, 0x464F4E54, 0x5F415343,
    0x5F53454C, 0x5F323478, 0x32340000, 0x464F4E54, 0x5F474152, 0x5F415343, 0x5F387831, 0x30000000,
    0x464F4E54, 0x5F524143, 0x5F415343, 0x5F54494D, 0x455F4E55, 0x4D000000, 0x464F4E54, 0x5F524143,
    0x5F464143, 0x455F4E55, 0x4D000000, 0x464F4E54, 0x5F524143, 0x5F52414E, 0x4B5F4E55, 0x4D000000,
    0x464F4E54, 0x5F524143, 0x5F52414E, 0x4B5F4E55, 0x4D5F5300, 0x464F4E54, 0x5F524143, 0x5F56535F,
    0x52414E4B, 0x5F4E554D, 0x0, 0x464F4E54, 0x5F524143, 0x5F535045, 0x45445F4E, 0x554D0000,
    0x464F4E54, 0x5F524143, 0x5F54494D, 0x455F4143, 0x0, 0x464F4E54, 0x5F524143, 0x5F54494D,
    0x455F4143, 0x5F530000, 0x464F4E54, 0x5F524553, 0x5F415343, 0x0, 0x464F4E54, 0x5F524553,
    0x5F415343, 0x5F54494D, 0x455F4E55, 0x4D000000, 0x464F4E54, 0x5F524553, 0x5F464143, 0x455F4E55,
    0x4D000000, 0x464F4E54, 0x5F524553, 0x5F4E414D, 0x455F4153, 0x43000000, 0x464F4E54, 0x5F524553,
    0x5F4E414D, 0x455F4153, 0x435F5300, 0x464F4E54, 0x5F524553, 0x5F54494D, 0x455F4E55, 0x4D000000,
    0x464F4E54, 0x5F524553, 0x5F54494D, 0x455F4E55, 0x4D5F5300, 0x464F4E54, 0x5F524553, 0x41435F4E,
    0x554D0000, 0x464F4E54, 0x5F524553, 0x47435F41, 0x53435F53, 0x53000000, 0x464F4E54, 0x5F524553,
    0x47435F41, 0x53435F59, 0x0, 0x464F4E54, 0x5F524553, 0x47435F43, 0x5553544F, 0x4D5F464F,
    0x4E540000, 0x464F4E54, 0x5F524553, 0x47435F50, 0x4C415445, 0x5F415343, 0x0, 0x464F4E54,
    0x5F524553, 0x47435F50, 0x4C415445, 0x5F415343, 0x5F530000, 0x464F4E54, 0x5F524553, 0x47435F56,
    0x5F415343, 0x0, 0x464F4E54, 0x5F524553, 0x5F56535F, 0x52414E4B, 0x5F4E554D, 0x0,
    0x464F4E54, 0x5F53454C, 0x5F4E414D, 0x455F4153, 0x43000000, 0x464F4E54, 0x5F53454C, 0x5F574549,
    0x4748545F, 0x4E554D00, 0x464F4E54, 0x5F53454C, 0x5F435553, 0x544F4D5F, 0x464F4E54, 0x0,
    0x464F4E54, 0x5F53454C, 0x41435F44, 0x4154415F, 0x4E554D00, 0x464F4E54, 0x5F53454C, 0x41435F54,
    0x494D455F, 0x4E554D00, 0x464F4E54, 0x5F53454C, 0x41435F54, 0x494D455F, 0x4E554D5F, 0x53000000,
    0x464F4E54, 0x5F53454C, 0x41465F43, 0x4F494E5F, 0x4E554D00, 0x464F4E54, 0x5F564945, 0x575F4C41,
    0x505F4E55, 0x4D000000, 0x464F4E54, 0x5F564945, 0x575F4E55, 0x4D000000, 0x464F4E54, 0x5F415343,
    0x5F323478, 0x32340000, 0x464F4E54, 0x5F524550, 0x5F535045, 0x45445F4E, 0x554D0000, (u32)lbl_1_data_1B848__fzgx_offset_0,
    (u32)lbl_1_data_1B860__fzgx_offset_0, (u32)lbl_1_data_1B878__fzgx_offset_0, (u32)lbl_1_data_1B888__fzgx_offset_0, (u32)lbl_1_data_1B898__fzgx_offset_0, (u32)lbl_1_data_1B8A8__fzgx_offset_0, (u32)lbl_1_data_1B8B8__fzgx_offset_0, (u32)lbl_1_data_1B8CC__fzgx_offset_0, (u32)lbl_1_data_1B8E0__fzgx_offset_0,
    (u32)lbl_1_data_1B8F4__fzgx_offset_0, (u32)lbl_1_data_1B908__fzgx_offset_0, (u32)lbl_1_data_1B920__fzgx_offset_0, (u32)lbl_1_data_1B934__fzgx_offset_0, (u32)lbl_1_data_1B948__fzgx_offset_0, (u32)lbl_1_data_1B95C__fzgx_offset_0, (u32)lbl_1_data_1B974__fzgx_offset_0, (u32)lbl_1_data_1B988__fzgx_offset_0,
    (u32)lbl_1_data_1B99C__fzgx_offset_0, (u32)lbl_1_data_1B9B0__fzgx_offset_0, (u32)lbl_1_data_1B9C0__fzgx_offset_0, (u32)lbl_1_data_1B9D8__fzgx_offset_0, (u32)lbl_1_data_1B9EC__fzgx_offset_0, (u32)lbl_1_data_1BA00__fzgx_offset_0, (u32)lbl_1_data_1BA14__fzgx_offset_0, (u32)lbl_1_data_1BA28__fzgx_offset_0,
    (u32)lbl_1_data_1BA3C__fzgx_offset_0, (u32)lbl_1_data_1BA4C__fzgx_offset_0, (u32)lbl_1_data_1BA60__fzgx_offset_0, (u32)lbl_1_data_1BA74__fzgx_offset_0, (u32)lbl_1_data_1BA8C__fzgx_offset_0, (u32)lbl_1_data_1BAA4__fzgx_offset_0, (u32)lbl_1_data_1BABC__fzgx_offset_0, (u32)lbl_1_data_1BAD0__fzgx_offset_0,
    (u32)lbl_1_data_1BAE8__fzgx_offset_0, (u32)lbl_1_data_1BAFC__fzgx_offset_0, (u32)lbl_1_data_1BB10__fzgx_offset_0, (u32)lbl_1_data_1BB28__fzgx_offset_0, (u32)lbl_1_data_1BB3C__fzgx_offset_0, (u32)lbl_1_data_1BB50__fzgx_offset_0, (u32)lbl_1_data_1BB68__fzgx_offset_0, (u32)lbl_1_data_1BB7C__fzgx_offset_0,
    (u32)lbl_1_data_1BB90__fzgx_offset_0, (u32)lbl_1_data_1BBA0__fzgx_offset_0, (u32)lbl_1_data_1BBB0__fzgx_offset_0, 0x4F524947, 0x494E414C, 0x0, 0x52454755, 0x4C415200,
    0x424F4C44, 0x0, 0x4954414C, 0x49430000, 0x424F4C44, 0x20495441, 0x4C494300, 0x54454741,
    0x4B490000, (u32)lbl_1_data_1BC74__fzgx_offset_0, (u32)lbl_1_data_1BC80__fzgx_offset_0, (u32)lbl_1_data_1BC88__fzgx_offset_0, (u32)lbl_1_data_1BC90__fzgx_offset_0, (u32)lbl_1_data_1BC98__fzgx_offset_0, (u32)lbl_1_data_1BCA4__fzgx_offset_0, 0x1
};
static u32 fzgx_pool_data_lbl_1_data_1BCC8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x666F6E74, 0x2E630000
};
static u32 fzgx_pool_data_lbl_1_data_1A3B8_1918[45] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x63616E6E, 0x6F74204F, 0x53416C6C, 0x6F632061, 0x7420666F, 0x6E745F74, 0x6573745F, 0x696E6974,
    0xA000000, 0x30313233, 0x34353637, 0x38394142, 0x43444546, 0x4748494A, 0x4B4C4D4E, 0x4F505152,
    0x53545556, 0x5758595A, 0x61626364, 0x65666768, 0x696A6B6C, 0x6D6E6F70, 0x71727374, 0x75767778,
    0x797A2122, 0x23242526, 0x2728292A, 0x2B2C2D2E, 0x2F3A3B3C, 0x3D3E3F40, 0x5B5C5D5E, 0x5F607B7C,
    0x7D7E0000, 0x54455853, 0x70725075, 0x745F5375, 0x62203A20, 0x4E6F2072, 0x65676973, 0x74726174,
    0x696F6E20, 0x6F662043, 0x414C4C5F, 0x4241434B, 0x2E0A0000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_1A3B8(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1A3B8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1AEA8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1B848;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1BCC8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1A3B8_1918;
}
#pragma section code_type ".text"

int fn_1_48A0C(int ch, int idx, Obj_1_data_1AEA8 *font, int noLoad) {
    // Retail addresses the font table and its strings off one base register
    // (the TU's data section); the one-member wrapper keeps the address CSE'd.
    s16 *slots;
    u8 *table;
    int tex;
    int i;
    u16 code;
    int fmt;

    
    slots = (s16 *)font->unk_30;
    if (slots[ch] != -1) {
        return 0;
    }
    table = ((u8 *)fzgx_pool_data_lbl_1_data_1AEA8);
    for (i = 1; i < 44; i++) {
        Obj_1_data_1AEA8 *other = (Obj_1_data_1AEA8 *)(table + i * 0x38);
        if (i != idx && (s32)other->unk_0 == -1 && ((s16 *)other->unk_30)[ch] != -1) {
            slots[ch] = ((s16 *)other->unk_30)[ch];
            return 0;
        }
    }

    tex = -1;
    for (i = 0; i < 0x56B; i++) {
        if (lbl_1_bss_3E060[i] == 0) {
            tex = i;
            break;
        }
    }
    if (tex == -1) {
        return 0;
    }

    if (noLoad) {
        lbl_1_bss_3E060[tex] = OSAllocFromArenaLo(*(u16 *)((u8 *)font + 0x28), 0x20);
    } else {
        lbl_1_bss_3E060[tex] = fn_1_45D0(lbl_801A6410, *(u16 *)((u8 *)font + 0x28),
                                         (const char *)(((u8 *)fzgx_pool_data_lbl_1_data_1BCC8)), 0x14E);
    }
    if (lbl_1_bss_3E060[tex] == 0) {
        OSPanic((const char *)(((u8 *)fzgx_pool_data_lbl_1_data_1BCC8)), 0x150, (const char *)(((u8 *)fzgx_pool_data_lbl_1_data_1A3B8_1918)));
    }
    fn_1_4BA24((u8)idx, ch, (void *)lbl_1_bss_3E060[tex]);

    fmt = 0;
    code = ((u16 *)font->unk_2C)[ch];
    if ((code >= 0x839F && code <= 0x83BE) || code == 0x8452) {
        fmt = 0xE;
    }
    GXInitTexObj(&lbl_1_bss_40C6C[tex * 0x20], (void *)lbl_1_bss_3E060[tex], font->unk_4, font->unk_5,
                 fmt, 0, 0, 0);
    ((s16 *)font->unk_30)[ch] = tex;
    if (noLoad) {
        lbl_1_bss_3F60C[tex] = -1;
    } else {
        lbl_1_bss_3F60C[tex] = lbl_801A6410;
    }
    return 1;
}
/* fzgx:end fn_1_48A0C */

/* fzgx:begin fn_1_4AEE8 */
u32 fn_1_4AEE8(u32 value) {
    u32 previous = lbl_1_data_1BCC4;

    lbl_1_bss_3E05C = lbl_1_rodata_10C0[0];
    lbl_1_data_1BCC4 = value;

    return previous;
}
/* fzgx:end fn_1_4AEE8 */
