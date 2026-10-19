#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern int fn_8003BE1C(void *arg0, void *arg1);
extern int fn_8003C1A4(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_8003CE74(void *arg0, void *arg1, int arg2);
extern void fn_8003CBB0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void fn_8003C6D0(void *arg0, void *arg1, void *arg2, void *arg3);
extern u16 lbl_1_bss_8ED8C;
extern u16 lbl_1_bss_8ED8E;
extern void fn_1_151C9C(void);
extern void fn_80074A7C(void (*callback)(void));
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24(void *);
extern void fn_1_153C60(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *value);
extern void fn_1_9AD88(void);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);

extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

/* fzgx:begin fn_1_151AF0 */
int fn_1_151AF0(void *arg0, int mode, void *arg2, void *arg3, void *arg4, void *arg5) {
    u8 local_8[4];
    u8 local_c[8];
    u8 local_14[12];

    if (fn_8003BE1C(arg0, local_c) == 0) {
        return 0;
    }
    if (fn_8003C1A4(local_14, local_8, arg5, arg0, local_c) == 0) {
        return 0;
    }
    switch (mode) {
    case 0:
        fn_8003CE74(local_14, arg2, 0xff);
        break;
    case 1:
        fn_8003CBB0(local_14, arg2, arg3, arg4);
        break;
    case 2:
        fn_8003C6D0(local_14, arg2, arg3, arg4);
        break;
    }
    return 1;
}
/* fzgx:end fn_1_151AF0 */

/* fzgx:begin fn_1_151BDC */
void fn_1_151BDC(u32 value) {
    lbl_1_bss_8ED88 = value;
}
/* fzgx:end fn_1_151BDC */

/* fzgx:begin fn_1_151BE8 */
struct fn_1_151BE8_Copy1200 { u32 a[75][4]; };

u32 fn_1_151BE8(s16 arg0, s16 arg1) {
    struct fn_1_151BE8_Copy1200 loc_8;
    loc_8 = *(struct fn_1_151BE8_Copy1200 *)&lbl_1_rodata_D048;
    {
        s16 row = arg0;
        s16 col = arg1;
        return loc_8.a[row][col];
    }
}
/* fzgx:end fn_1_151BE8 */

/* fzgx:begin fn_1_151C3C */
void fn_1_151C3C(u16 value1, u16 value2) {
    lbl_1_bss_8ED8C = value1;
    lbl_1_bss_8ED8E = value2;
    fn_80074A7C(fn_1_151C9C);
}
/* fzgx:end fn_1_151C3C */

/* fzgx:begin fn_1_151C78 */
void fn_1_151C78(void) {
    fn_80074A7C(0);
}
/* fzgx:end fn_1_151C78 */

/* fzgx:begin fn_1_151C9C noprologue */
#include "types.h"

struct fn_1_151C9C_lbl_1_bss_8ED88 {
    u32 unk_0;
    s16 unk_4;
    s16 unk_6;
};
struct fn_1_151C9C_lbl_1_rodata_D500 {
    f64 unk_0;
};
struct fn_1_151C9C_lbl_1_rodata_D4F8 {
    f32 unk_0;
};
extern struct fn_1_151C9C_lbl_1_bss_8ED88 lbl_1_bss_8ED88;
extern struct fn_1_151C9C_lbl_1_rodata_D4F8 lbl_1_rodata_D4F8;
extern struct fn_1_151C9C_lbl_1_rodata_D500 lbl_1_rodata_D500;
extern u32 fn_1_151BE8(s16, s16);
extern void fn_80008BA8(void *, void *, u32);

struct FzgxCopy_4 { u32 words[1]; };
#pragma opt_propagation off
void fn_1_151C9C(void *arg0, s32 arg_sp0) {
    struct FzgxCopy_4 loc_8;
    void *temp_r7;
    u32 var_r3;
    s32 temp_r3;
    void *var_r30;
    u32 temp_r29;
    s16 var_r28;

    var_r28 = 0;
    temp_r29 = lbl_1_bss_8ED88.unk_0;
    var_r30 = (void *)(temp_r29 + (lbl_1_bss_8ED88.unk_4 * 8));
    while (var_r28 < 1) {
        if ((temp_r29 == 0) || (temp_r3 = *(s32 *)((u8 *)(temp_r29) + 0), (((temp_r3 & 0x80000000) == 0) != 0)) || !(temp_r3 & 0x40000000)) {
            var_r3 = fn_1_151BE8((s16)(lbl_1_bss_8ED88.unk_6), var_r28);
        } else {
            var_r3 = *(u32 *)((u8 *)(var_r30) + 33192);
        }
        temp_r7 = (void *)(*(void **)((u8 *)(arg0) + 4));
        if ((u8) (*(u8 *)((u8 *)(temp_r7) + 21)) == (u8) var_r3) {
            (*(s8 *)((u8 *)(&loc_8) + 0)) = (s8) (var_r3 >> 0x18U);
            (*(u8 *)((u8 *)(&loc_8) + 1)) = (u8) (var_r3 >> 0x10U);
            (*(u8 *)((u8 *)(&loc_8) + 2)) = (u8) (var_r3 >> 8U);
            (*(u8 *)((u8 *)(&loc_8) + 3)) = 0xFF;
            fn_80008BA8((void *)((u8 *)(temp_r7) + 8), (void *)(&loc_8), (u32)(4U));
            (*(s8 *)((u8 *)(&loc_8) + 0)) = (s8) ((f32) (*(u8 *)((u8 *)(&loc_8) + 0)) * lbl_1_rodata_D4F8.unk_0);
            (*(s8 *)((u8 *)(&loc_8) + 1)) = (s8) ((f32) (*(u8 *)((u8 *)(&loc_8) + 1)) * lbl_1_rodata_D4F8.unk_0);
            (*(s8 *)((u8 *)(&loc_8) + 2)) = (s8) ((f32) (*(u8 *)((u8 *)(&loc_8) + 2)) * lbl_1_rodata_D4F8.unk_0);
            fn_80008BA8((void *)((u8 *)((*(void **)((u8 *)(arg0) + 4))) + 4), (void *)(&loc_8), (u32)(4U));
        }
        var_r30 = (void *)((u8 *)(var_r30) + 4);
        var_r28 += 1;
            }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_151C9C */

/* fzgx:begin fn_1_151E20 */
u32 fn_1_151E20(u32 value, s16 index) {
    u32 result = (u32)-1;

    switch (index) {
    case 0:
        result = value >> 24;
        break;
    case 1:
        result = (value >> 16) & 0xff;
        break;
    case 2:
        result = (value >> 8) & 0xff;
        break;
    case 3:
        result = value & 0xff;
        break;
    }

    return result;
}
/* fzgx:end fn_1_151E20 */

/* fzgx:begin fn_1_151E74 */
void fn_1_151E74(u32 *value, s16 index, int byte) {
    switch (index) {
    case 0:
        *value = (*value & 0x00FFFFFF) | ((u32)byte << 24);
        break;
    case 1:
        *value = (*value & 0xFF00FFFF) | ((u32)byte << 16);
        break;
    case 2:
        *value = (*value & 0xFFFF00FF) | ((u32)byte << 8);
        break;
    case 3:
        *value = (*value & 0xFFFFFF00) | byte;
        break;
    default:
        break;
    }
}
/* fzgx:end fn_1_151E74 */

/* fzgx:begin fn_1_151EF8 */
typedef struct {
    s16 unk_0;
    u8 pad_2[0x2];
    u32 unk_4;
} Entry_151EF8;

void fn_1_151EF8(s16 *values, s16 value_count, Entry_151EF8 *entries,
                 s16 group_count, s16 group_size) {
    s16 i;
    s16 j;
    s16 group_index;
    s16 local_index;
    Entry_151EF8 *entry;

    for (i = 0; i < group_count; i++) {
        for (j = 0; j < group_size; j++) {
            entries[i * group_size + j].unk_4 |= (1u << 30);
            entries[i * group_size + j].unk_0 = -1;
        }
    }

    for (i = 0; i < value_count; i++) {

        if (values[i] == -1) {
            continue;
        }

        group_index = i / group_size;
        local_index = i % group_size;

        entries[group_index * group_size + local_index].unk_0 = values[i];
        entries[group_index * group_size + local_index].unk_4 = 0;

        if (entries[group_index * group_size + local_index].unk_0 >= 0x29) {
            entries[group_index * group_size + local_index].unk_4 |= (1u << 29);
            entries[group_index * group_size + local_index].unk_4 |= (1u << 30);
            continue;
        }

        if (!fn_1_8D690(entries[group_index * group_size + local_index].unk_0)) {
            entries[group_index * group_size + local_index].unk_4 |= (1u << 31);
        }
        if (!fn_1_8D72C(entries[group_index * group_size + local_index].unk_0)) {
            entries[group_index * group_size + local_index].unk_4 |= (1u << 30);
        }
        if ((lbl_1_bss_8B3A0.unk_94 & 0x40000000) != 0 &&
            !fn_1_8D690(entries[group_index * group_size + local_index].unk_0)) {
            entries[group_index * group_size + local_index].unk_4 |= (1u << 30);
        }
        if ((lbl_1_bss_8B3A0.unk_94 & 0x02000000) != 0 &&
            entries[group_index * group_size + local_index].unk_0 != 6 &&
            (entries[group_index * group_size + local_index].unk_4 & 0x80000000) == 0) {
            entries[group_index * group_size + local_index].unk_4 |= (1u << 31);
        }
    }
}
/* fzgx:end fn_1_151EF8 */

/* fzgx:begin fn_1_152208 */
extern s32 fn_1_8D5F0(s16);
extern s32 fn_1_F7BE4(s16);

typedef struct {
    s16 id;
    u32 flags;
} Entry;

void fn_1_152208(s16 *ids, s16 id_count, Entry *table, s16 rows, s16 cols) {
    s16 i;
    s16 k;
    s16 n;
    s16 row;
    s16 col;
    s32 found;

    found = 0;
    for (i = 0; i < 41; i++) {
        if ((fn_1_8D5F0(i) & 0x10000000) && (fn_1_F7BE4(i) != 0)) {
            found = 1;
            break;
        }
    }

    for (i = 0; i < rows; i++) {
        for (k = 0; k < cols; k++) {
            table[(i * cols) + k].flags |= 0x40000000;
            table[(i * cols) + k].id = -1;
        }
    }

    for (n = 0; n < id_count; n++) {
        if (ids[n] == -1) {
            continue;
        }
        row = n / cols;
        col = n % cols;
        table[(row * cols) + col].id = ids[n];
        table[(row * cols) + col].flags = 0;
        if (found == 1) {
            table[(row * cols) + col].flags |= 0x80000000;
        } else if ((fn_1_8D5F0(table[(row * cols) + col].id) & 0x10000000) != 0) {
            table[(row * cols) + col].flags |= 0x40000000;
        } else {
            table[(row * cols) + col].flags |= 0x80000000;
        }
        if (fn_1_F7BE4(table[(row * cols) + col].id) != 0) {
            table[(row * cols) + col].flags &= 0x3FFFFFFF;
        }
    }
}
/* fzgx:end fn_1_152208 */

/* fzgx:begin fn_1_152510 */
extern u32 fn_1_8D5F0(s16 value);
extern s32 fn_1_F7EDC(s16 value);
extern s32 fn_1_F7BE4(s16 value);

typedef struct {
    s16 id;
    u8 pad[2];
    u32 flags;
} Cell;

void fn_1_152510(s16 *ids, s16 id_count, Cell *table, s16 rows, s16 cols) {
    s16 i;
    s16 k;
    s16 n;
    s16 row;
    s16 col;
    s32 found;

    found = 0;
    for (i = 0; i < 41; i++) {
        if ((fn_1_8D5F0(i) & 0x10000000) && (fn_1_F7EDC(i) != 0)) {
            found = 1;
            break;
        }
    }

    for (i = 0; i < rows; i++) {
        for (k = 0; k < cols; k++) {
            table[(i * cols) + k].flags |= 0x40000000;
            table[(i * cols) + k].id = -1;
        }
    }

    for (n = 0; n < id_count; n++) {
        if (ids[n] == -1) {
            continue;
        }
        row = n / cols;
        col = n % cols;
        table[(row * cols) + col].id = ids[n];
        table[(row * cols) + col].flags = 0;
        if (found == 1) {
            table[(row * cols) + col].flags |= 0x80000000;
        } else if ((fn_1_8D5F0(table[(row * cols) + col].id) & 0x10000000) != 0) {
            table[(row * cols) + col].flags |= 0x40000000;
        } else {
            table[(row * cols) + col].flags |= 0x80000000;
        }
        if (fn_1_F7EDC(table[(row * cols) + col].id) != 0) {
            table[(row * cols) + col].flags &= 0x3FFFFFFF;
        }
        if (fn_1_F7BE4(table[(row * cols) + col].id) != 0) {
            table[(row * cols) + col].flags &= 0x3FFFFFFF;
            table[(row * cols) + col].flags |= 0x08000000;
        }
    }
}
/* fzgx:end fn_1_152510 */

/* fzgx:begin fn_1_152840 */
typedef struct Entry {
    s16 id;
    u8 pad[2];
    u32 flags;
} Entry;

int fn_1_152840(s16 id, Entry *entries, s16 outer_count, s16 inner_count) {
    s16 count;
    s16 i;
    s16 j;

    if (id == -1) {
        return 0;
    }

    count = inner_count;
    for (i = 0; i < outer_count; i++) {
        for (j = 0; j < count; j++) {
            if ((entries[(i * count) + j].flags & (3u << 30)) == 0 &&
                id == entries[(i * count) + j].id) {
                return 1;
            }
        }
    }

    return 0;
}
/* fzgx:end fn_1_152840 */

/* fzgx:begin fn_1_1528D0 */
typedef struct Cell {
    s16 id;
    u8 pad[2];
    u32 flags;
} Cell;

s32 fn_1_1528D0(s16 x, s16 y, Cell *table, s16 unused, s16 multiplier) {
    s32 value;

    if (lbl_1_bss_8B3A0.unk_94 & 0x00020000) {
        if (table[(x * multiplier) + y].flags & ~0x3FFFFFFF)
            return -1;
    } else {
        if (table[(x * multiplier) + y].flags & 0x40000000)
            return -1;
    }

    value = table[(x * multiplier) + y].id;
    if (value != -1)
        return value;
    return -1;
}
/* fzgx:end fn_1_1528D0 */

/* fzgx:begin fn_1_152970 */
typedef struct {
    s16 key;
    u16 pad;
    u32 mask;
} Fn152970Entry;

s32 fn_1_152970(s16 *out_group, s16 *out_entry, s16 key, u32 mask,
                 Fn152970Entry *entries, s16 group_count, s16 entry_count) {
    s16 count;
    s16 group;
    s16 entry;

    if (key == -1) {
        return 0;
    }

    count = entry_count;
    for (group = 0; group < group_count; group++) {
        for (entry = 0; entry < count; entry++) {
            if ((entries[(group * count) + entry].mask & mask) == 0 &&
                key == entries[(group * count) + entry].key) {
                *out_group = group;
                *out_entry = entry;
                return 1;
            }
        }
    }
    return 0;
}
/* fzgx:end fn_1_152970 */

/* fzgx:begin fn_1_153988 */
// fn_1_153988: empty in retail (single blr).
void fn_1_153988(void) {
}
/* fzgx:end fn_1_153988 */

/* fzgx:begin fn_1_15398C */
// Prepares the shared background object and advances the background system.
void fn_1_15398C(void) {
    Obj_1_data_2A7E0_At3C *background = lbl_1_data_2A7E0.unk_3C;

    fn_1_153AF8(&background->unk_0);
    fn_1_153D48(background);
    fn_1_9A508();
}
/* fzgx:end fn_1_15398C */

/* fzgx:begin fn_1_1539D0 */
// Calls initialization, then loops calling two functions for each item
void fn_1_1539D0(void) {
    int count = fn_1_58C4();
    int i;
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_627C(i);
    }
}
/* fzgx:end fn_1_1539D0 */

/* fzgx:begin fn_1_153A28 */
void fn_1_153A28(void) {
    Obj_1_data_2A7E0_At3C *obj;
    int count;
    int i;

    obj = lbl_1_data_2A7E0.unk_3C;
    fn_1_9D260();
    fn_1_9AD54();
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_153D74(obj);
        fn_1_627C(i);
    }
    fn_1_153B24(obj);
}
/* fzgx:end fn_1_153A28 */

/* fzgx:begin fn_1_153AAC */
// fn_1_153AAC: empty in retail (single blr).
void fn_1_153AAC(void) {
}
/* fzgx:end fn_1_153AAC */

/* fzgx:begin fn_1_153AB0 */
// Initializes the background Aurora object.
void fn_1_153AB0(void) {
    Obj_1_data_2A7E0_At3C *object = lbl_1_data_2A7E0.unk_3C;

    fn_1_153C60(object);
    fn_1_1540B0(object);
    fn_1_9AD88();
}
/* fzgx:end fn_1_153AB0 */

/* fzgx:begin fn_1_153AF4 */
// fn_1_153AF4: empty in retail (single blr).
void fn_1_153AF4(void) {
}
/* fzgx:end fn_1_153AF4 */

/* fzgx:begin fn_1_153AF8 */
// Clears the first entry and any following entries selected by its count.
void fn_1_153AF8(u32 *entries) {
    u32 *current = entries;
    int index = 0;

    entries[0] = 0;
    while (index < (int)entries[0]) {
        *++current = 0;
        index++;
    }
}
/* fzgx:end fn_1_153AF8 */

/* fzgx:begin fn_1_153B24 noprologue */
#include "types.h"

typedef struct {
    s32 count;
    u8 pad_004[0x100];
    s32 counter[64];
    f32 timer[64];
    f32 progress[64];
    f32 cooldown[64];
} Fn153B24Data;

void fn_1_153B24(Fn153B24Data *data, u32 lab_unused0, u32 lab_unused1, u32 lab_unused2) {
    f32 base;
    f32 prod;
    s32 i;

    for (i = 0; i < data->count; i++) {
        data->timer[i] -= 0.15f;
        if (data->timer[i] <= -0.95f) {
            data->counter[i]++;
            data->timer[i] = 0.031f;
        }

        base = 0.005f;
        prod = -0.032f * (f32)data->counter[i];
        data->progress[i] = base + prod;

        if (data->progress[i] <= -0.923f) {
            data->timer[i] = -0.95f;
            data->progress[i] = -0.923f;
            data->counter[i] = (s32)((data->progress[i] - 0.005f) / -0.032f);
        }

        if (data->progress[i] == -0.923f) {
            data->cooldown[i] -= -0.032f;
            if (data->cooldown[i] > 1.0f) {
                data->cooldown[i] = 0.0f;
                data->timer[i] = 0.031f;
                data->progress[i] = 0.005f;
                data->counter[i] = (s32)((data->progress[i] - 0.005f) / -0.032f);
            }
        }
    }
}
/* fzgx:end fn_1_153B24 */

/* fzgx:begin fn_1_153C60 noprologue */
#include "types.h"

extern u32 lbl_1_data_2A7E0[];
extern void lbl_8006DFE8(void *);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void lbl_8006D784(void *);
extern void fn_1_560F0(s32, void *);
extern void fn_1_55210(void *);

void fn_1_153C60(u8 *base) {
    u8 *entry;
    u8 *slot;
    s32 i;
    u8 *obj;
    u8 work0[0x30];
    u8 work1[0x30];

    entry = base;
    slot = base;
    i = 0;

    while (i < *(s32 *)base) {
        obj = *(u8 **)(entry + 4);
        {
            u32 value = *(u32 *)(obj + 4);

            if ((value + 0x10000) == 0xffff || (value & lbl_1_data_2A7E0[20]) != 0) {
                lbl_8006DFE8(slot + 0x504);
                lbl_8006E13C(obj + 0x20);
                lbl_8006E0A4((u8 *)*(void **)(base + 0x1104) + 8);
                fn_80072558();
                lbl_8006D784(work0);
                *(f32 *)(work0 + 0xC) = *(f32 *)(entry + 0x204);
                *(f32 *)(work0 + 0x1C) = *(f32 *)(entry + 0x304);
                fn_1_560F0(0, work0);
                lbl_8006D784(work1);
                *(f32 *)(work1 + 0x1C) = *(f32 *)(entry + 0x404);
                fn_1_560F0(1, work1);
                fn_1_55210(*(void **)(base + 0x1104));
            }
        }

        entry += 4;
        slot += 0x30;
        i++;
    }
}
/* fzgx:end fn_1_153C60 */

/* fzgx:begin fn_1_153D48 */
// Clears the Aurora background data region.
void fn_1_153D48(void *background) {
    fn_80008BEC((u8 *)background + 0x1108, 0, 0x5fc);
}
/* fzgx:end fn_1_153D48 */

/* fzgx:begin fn_1_153D74 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 flag;
    u8 pad_0xc[0x80];
    V3 pos;
    u8 pad_0x98[0x24];
    V3 ang;
    u8 pad_0xc8[0x24];
    V3 view;
    u8 pad_0xf8[0xe4];
    V3 screen;
    u8 pad_0x1e8[0x24];
    V3 target;
} Aurora;

typedef struct {
    u32 unk_0[7];
    f32 zero;
    u32 unk_1[2];
    V3 def[5];
    f32 k1;
    f32 k2;
    f32 k3;
    f32 k4;
} AuroraDef;

typedef struct {
    f32 m[12];
} AuroraCam;

extern int fn_1_58C4(void);
extern void fn_1_5948(int);
extern s16 camera_get_mode(void);
extern void lbl_8006D784(void *mat);
extern u32 lbl_8006DAEC(void);
extern u32 lbl_8006DB74(void *mat);
extern void lbl_8006DD7C(void);
extern void lbl_8006DB30(void);
extern f32 lbl_8006D0B4(f32 x);
extern void fn_1_862D4(s16 mode, void *out);
extern void fn_1_8636C(s16 mode, AuroraCam *cam);
extern void fn_1_869B0(s16 mode, void *out);
extern void fn_8006F1F0(V3 *a, V3 *b, V3 *out);

extern AuroraDef lbl_1_rodata_D508;
extern AuroraCam *lbl_801A6D00;

static inline f32 fn_1_153D74_read_pointer(V3 * owner) { return owner->y; }
static inline f32 fn_1_153D74_operand(f32 right, f32 left) { left *= right; return left; }
#pragma opt_lifetimes off
#pragma opt_strength_reduction off
void fn_1_153D74(void *arg0) {
    f32 fzgx_live;
    u8 *base = (u8 *)arg0 + 0x1108;
    int count;
    const AuroraDef *cfg = &lbl_1_rodata_D508;
    Aurora *p;
    u8 *q;
    int i;
    s32 mode;
    V3 v;
    V3 d;
    f32 k3;
    f32 k2;
    f32 k1;
    f32 k4;
    f32 len;
    f32 s;
    f32 z;
    f32 dx;
    f32 dy;
    f32 dz;

    if (*(u32 *)(base + 8) == 0) {
        return;
    }
    count = fn_1_58C4();
    k1 = cfg->k1;
    k2 = cfg->k2;
    k3 = cfg->k3;
    k4 = cfg->k4;
    p = (Aurora *)base;
    q = base;
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        mode = camera_get_mode();
        if (mode == -1) {
            v = cfg->def[0];
            p->ang = cfg->def[1];
            p->view = cfg->def[2];
            p->target = cfg->def[3];
            p->screen = cfg->def[4];
            lbl_8006D784(q + 0x11c);
            lbl_8006D784(q + 0x23c);
        } else {
            lbl_8006DAEC();
            fn_1_862D4(mode, &v);
            fn_1_8636C(mode, lbl_801A6D00);
            z = cfg->zero;
            *(f32 *)(0xE0000000 + 0x0c) = z;
            *(f32 *)(0xE0000000 + 0x1c) = z;
            *(f32 *)(0xE0000000 + 0x2c) = z;
            p->ang.x = -lbl_801A6D00->m[2];
            p->ang.y = -lbl_801A6D00->m[6];
            p->ang.z = -lbl_801A6D00->m[10];
            p->view.x = lbl_801A6D00->m[1];
            p->view.y = lbl_801A6D00->m[5];
            p->view.z = lbl_801A6D00->m[9];
            lbl_8006DB74(q + 0x11c);
            fn_1_869B0(mode, &p->target);
            fn_8006F1F0(&v, &p->view, &p->pos);
            z = cfg->zero;
            *(f32 *)(0xE0000000 + 0x0c) = z;
            *(f32 *)(0xE0000000 + 0x1c) = z;
            *(f32 *)(0xE0000000 + 0x2c) = z;
            lbl_8006DD7C();
            lbl_8006DB74(q + 0x23c);
            lbl_8006DB30();
        }
        p->screen.x = v.x + (f32)(p->target.x * k1) + (f32)(p->view.x * k2);
        p->screen.y = v.y + (f32)(p->target.y * k1) + (f32)(p->view.y * k2);
        p->screen.z = v.z + (f32)(p->target.z * k1) + (f32)(p->view.z * k2);
        dx = (p->screen.x - p->pos.x) * k3;
        d.x = dx;
        dy = (p->screen.y - p->pos.y) * k3;
        d.y = dy;
        fzgx_live = p->screen.z;
        dz = (fzgx_live - p->pos.z) * k3;
        d.z = dz;
        len = fn_1_153D74_operand((dx), (dx)) + (dy * dy);
        len = len + dz * dz;
        len = lbl_8006D0B4(len);
        if (len > k4) {
            s = k4 / len;
            d.x = d.x * s;
            d.y = d.y * s;
            d.z = d.z * s;
        }
        psvec_add(&p->pos.x, &d.x, &p->pos.x);
        p = (Aurora *)((u8 *)p + 0xc);
        q = q + 0x30;
    }
}
#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset
/* fzgx:end fn_1_153D74 */

/* fzgx:begin fn_1_1540B0 noprologue */
#include "types.h"

extern s32 fn_1_5910(void);
extern void fn_1_154164(u32 value, u32 *arg1, u32 *arg2, u32 arg3);
extern u32 lbl_1_rodata_D57C[7];

void fn_1_1540B0(u32 value) {
    u32 *table;
    s32 i;
    u32 *base;
    u32 *entry;
    u32 args[3];

    base = (u32 *)((u8 *)value + 0x1108);
    {
        s32 slot;
        slot = fn_1_5910();
        fn_1_154164(value, (u32 *)((u8 *)base + slot * 0xc + 0x8c),
                    (u32 *)((u8 *)base + slot * 0x30 + 0x23c), 0);
    }

    entry = lbl_1_rodata_D57C;
    table = base;
    i = 0;
    while (i < (s32)base[1]) {
        args[0] = entry[0];
        args[1] = entry[1];
        args[2] = entry[2];
        fn_1_154164(value, args, (u32 *)((u8 *)table + 0x2fc), 1);
        table = (u32 *)((u8 *)table + 0x30);
        i++;
    }
}
/* fzgx:end fn_1_1540B0 */

/* fzgx:begin fn_1_1543E8 */
u32 fn_1_1543E8(s32 value, u32 *source) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;

    switch (value) {
    case 0:
        obj->unk_1104 = *source;
        break;
    default:
        break;
    }

    return 1;
}
/* fzgx:end fn_1_1543E8 */
