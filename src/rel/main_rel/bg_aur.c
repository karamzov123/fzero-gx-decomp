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

/* fzgx:begin fn_1_15176C */
extern void OSPanic(const char *, int, const char *, ...);

typedef struct {
    u8 pad_0[0x4];
    f32 unk_4;
} AurParam;

typedef struct {
    u8 pad_0[0x10];
    f32 unk_10;
    u8 pad_14[0x20];
    AurParam **unk_34;
    u8 pad_38[0x4];
    u32 unk_3C;
} AurObj;

typedef struct {
    AurObj *obj;
    u8 pad_4[0x4];
    u32 flags;
    u8 pad_C[0xA0];
} AurEntryA;

typedef struct {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x18];
    f32 unk_28[3];
    AurObj *obj;
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
} AurEntryB;

typedef struct {
    s32 unk_0;
    u8 pad_4[0x80];
    s32 countA;
    AurEntryA entriesA[32];
    u8 pad_1608[0x21C];
    AurEntryB entriesB[64];
    s32 countB;
} AurMgr;

s32 fn_1_15176C(s32 type, AurObj *obj) {
    AurMgr *mgr;
    AurEntryB *e;

    if (obj == NULL) {
        return 1;
    }
    mgr = (AurMgr *)lbl_1_data_2A7E0.unk_3C;
    switch (type) {
    case 0:
        mgr->entriesA[mgr->countA].flags |= 0x40000000;
        mgr->entriesA[mgr->countA].flags |= 0x10000000;
        mgr->entriesA[mgr->countA].obj = obj;
        mgr->countA++;
        if (mgr->countA >= 32) {
            OSPanic("bg_aur.c", 0x542, "SPOT LIGHT OVER!");
        }
        break;
    case 1:
        mgr->entriesA[mgr->countA].flags |= 0x40000000;
        mgr->entriesA[mgr->countA].flags |= 0x20000000;
        mgr->entriesA[mgr->countA].obj = obj;
        mgr->countA++;
        if (mgr->countA >= 32) {
            OSPanic("bg_aur.c", 0x549, "SPOT LIGHT OVER!");
        }
        break;
    case 2:
        mgr->entriesA[mgr->countA].flags |= 0x40000000;
        mgr->entriesA[mgr->countA].flags |= 0x10000000;
        mgr->entriesA[mgr->countA].flags |= 0x08000000;
        mgr->entriesA[mgr->countA].obj = obj;
        mgr->countA++;
        if (mgr->countA >= 32) {
            OSPanic("bg_aur.c", 0x551, "SPOT LIGHT OVER!");
        }
        break;
    case 3:
        mgr->entriesA[mgr->countA].flags |= 0x40000000;
        mgr->entriesA[mgr->countA].flags |= 0x20000000;
        mgr->entriesA[mgr->countA].flags |= 0x08000000;
        mgr->entriesA[mgr->countA].obj = obj;
        mgr->countA++;
        if (mgr->countA >= 32) {
            OSPanic("bg_aur.c", 0x559, "SPOT LIGHT OVER!");
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        e = &mgr->entriesB[mgr->countB];
        obj->unk_3C = 0;
        e->obj = obj;
        if (type == 4 || type == 5) {
            e->unk_38 = 1;
        } else if (type == 6) {
            e->unk_39 = 1;
        } else if (type == 7) {
            e->unk_3A = 1;
        } else if (type == 8) {
            e->unk_3B = 1;
        }
        if (mgr->unk_0 == 0) {
            s32 i;
            e->unk_C = obj->unk_10;
            /* frame counts -> seconds */
            for (i = 0; i < 3; i++) {
                if (obj->unk_34 != NULL && obj->unk_34[i] != NULL) {
                    e->unk_28[i] = obj->unk_34[i]->unk_4 / 60.0f;
                }
            }
        }
        mgr->countB++;
        if (mgr->countB >= 64) {
            OSPanic("bg_aur.c", 0x57F, "ELEV STOP OVER! in bg_aur.c");
        }
        break;
    }
    return 1;
}
/* fzgx:end fn_1_15176C */

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

/* fzgx:begin fn_1_152A28 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s8 value);
extern int fn_1_8D72C(s16 value);

#define CELL_HIDDEN 0x80000000
#define CELL_LOCKED 0x40000000

typedef struct Cell {
    s16 id;
    u8 pad[2];
    u32 flags;
} Cell;

static inline s32 get_cell(s16 grp, s16 ent, Cell *table, s16 cols, u32 mode) {
    if (mode != 0) {
        if (table[grp * cols + ent].flags & (CELL_HIDDEN | CELL_LOCKED))
            return -1;
    } else {
        if (table[grp * cols + ent].flags & CELL_LOCKED)
            return -1;
    }
    if (table[grp * cols + ent].id == -1)
        return -1;
    return table[grp * cols + ent].id;
}

static inline void fn_1_152A28_find(s16 id, Cell *table, s16 rows, s16 cols, u32 mask, s16 *grp, s16 *ent) {
    s16 i;
    s16 j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if ((table[i * cols + j].flags & mask) == 0 && id == table[i * cols + j].id) {
                *grp = i;
                *ent = j;
                return;
            }
        }
    }
}

s32 fn_1_152A28(s16 id, s16 y, s16 x, Cell *table, s16 nrows, s16 ncols) {
    s16 cols = ncols;
    u32 mode;
    s32 res;
    s16 rows = nrows;
    s16 ent;
    s16 grp;
    s16 total = (s16)(rows * cols);
    mode = lbl_1_bss_8B3A0.unk_94 & 0x20000;

    if (mode != 0) {
        if (id != -1) {
            fn_1_152A28_find(id, table, rows, cols, (CELL_HIDDEN | CELL_LOCKED), &grp, &ent);
        }
    } else {
        if (id != -1) {
            fn_1_152A28_find(id, table, rows, cols, CELL_LOCKED, &grp, &ent);
        }
    }
    if (x != 0) {
        do {
            ent = (s16)((ent + x + total) % cols);
            res = get_cell(grp, ent, table, cols, mode);
        } while ((s16)res < 0);
    }
    if (y != 0) {
        do {
            grp = (s16)((grp + y + total) % rows);
            res = get_cell(grp, ent, table, cols, mode);
        } while ((s16)res < 0);
    }
    return res;
}
/* fzgx:end fn_1_152A28 */

/* fzgx:begin fn_1_152CB4 */
#define CELL_HIDDEN 0x80000000
#define CELL_LOCKED 0x40000000

typedef struct fn_1_152CB4_Cell {
    s16 id;
    u8 pad[2];
    u32 flags;
} fn_1_152CB4_Cell;

static inline s32 fn_1_152CB4_get(s16 grp, s16 ent, fn_1_152CB4_Cell *table, s16 cols) {
    if (lbl_1_bss_8B3A0.unk_94 & 0x20000) {
        if (table[grp * cols + ent].flags & (CELL_HIDDEN | CELL_LOCKED))
            return -1;
    } else {
        if (table[grp * cols + ent].flags & CELL_LOCKED)
            return -1;
    }
    if (table[grp * cols + ent].id == -1)
        return -1;
    return table[grp * cols + ent].id;
}

static inline void fn_1_152CB4_find(s16 id, fn_1_152CB4_Cell *table, s16 rows, s16 cols, u32 mask, s16 *grp, s16 *ent) {
    s16 i;
    s16 j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if ((table[i * cols + j].flags & mask) == 0 && id == table[i * cols + j].id) {
                *grp = i;
                *ent = j;
                return;
            }
        }
    }
}

s32 fn_1_152CB4(s32 id, s16 y, s16 x, fn_1_152CB4_Cell *table, s16 nrows, s16 ncols) {
    s16 cols = ncols;
    s16 ent;
    s16 grp;
    s16 prev;
    s32 res;
    s16 rows = nrows;
    s16 total = (s16)(rows * cols);
    s16 saved;

    if (lbl_1_bss_8B3A0.unk_94 & 0x20000) {
        if ((s16)id != -1) {
            fn_1_152CB4_find((s16)id, table, rows, cols, (CELL_HIDDEN | CELL_LOCKED), &grp, &ent);
        }
    } else {
        if ((s16)id != -1) {
            fn_1_152CB4_find((s16)id, table, rows, cols, CELL_LOCKED, &grp, &ent);
        }
    }
    saved = ent;
    if (x != 0) {
        do {
            prev = ent;
            ent = (s16)((ent + x + total) % cols);
            if (x > 0 && prev > ent)
                break;
            if (x < 0 && prev < ent)
                break;
            res = fn_1_152CB4_get(grp, ent, table, cols);
            if ((s16)res >= 0) {
                id = res;
                saved = ent;
            }
        } while ((s16)res < 0);
        ent = saved;
    }
    if (y != 0) {
        do {
            prev = grp;
            grp = (s16)((grp + y + total) % rows);
            if (y > 0 && prev > grp)
                break;
            if (y < 0 && prev < grp)
                break;
            res = fn_1_152CB4_get(grp, ent, table, cols);
            if ((s16)res >= 0) {
                id = res;
            }
        } while ((s16)res < 0);
    }
    return id;
}
/* fzgx:end fn_1_152CB4 */

/* fzgx:begin fn_1_152FAC noprologue */
#include "types.h"

#define CELL_HIDDEN 0x80000000  /* fzgx-allow: A1 flag bit, not an address */
#define CELL_LOCKED 0x40000000

typedef struct fn_1_152FAC_Cell {
    s16 id;
    u8 pad[2];
    u32 flags;
} fn_1_152FAC_Cell;

typedef struct fn_1_152FAC_Pos {
    s16 grp;
    s16 ent;
} fn_1_152FAC_Pos;

struct fn_1_152FAC_lbl_1_bss_8B3A0 {
    u8 pad_0[0x94];
    u32 unk_94;
    u8 pad_98[0x18];
    fn_1_152FAC_Pos cur[4];
    fn_1_152FAC_Pos repeat[4];
    fn_1_152FAC_Pos anchor[4];
};

extern struct fn_1_152FAC_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;

static inline s32 fn_1_152FAC_get(s16 grp, s16 ent, fn_1_152FAC_Cell *table, s16 cols) {
    if (lbl_1_bss_8B3A0.unk_94 & 0x20000) {
        if (table[grp * cols + ent].flags & (CELL_HIDDEN | CELL_LOCKED))
            return -1;
    } else {
        if (table[grp * cols + ent].flags & CELL_LOCKED)
            return -1;
    }
    if (table[grp * cols + ent].id == -1)
        return -1;
    return table[grp * cols + ent].id;
}

static inline void fn_1_152FAC_find(s16 id, fn_1_152FAC_Cell *table, s16 rows, s16 cols, u32 mask, s16 *grp, s16 *ent) {
    s16 i;
    s16 j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if ((table[i * cols + j].flags & mask) == 0 && id == table[i * cols + j].id) {
                *grp = i;
                *ent = j;
                return;
            }
        }
    }
}

static inline s16 fn_1_152FAC_scan_grp(s16 grp, s16 ent, s16 step, fn_1_152FAC_Cell *table, s16 rows, s16 cols, s16 *found) {
    s16 cnt = 0;
    do {
        cnt++;
        grp += step;
        if (grp < 0 || rows - 1 < grp) {
            return 100;
        }
    } while ((s16)fn_1_152FAC_get(grp, ent, table, cols) < 0);
    *found = grp;
    return cnt;
}

static inline s16 fn_1_152FAC_scan_ent(s16 grp, s16 ent, s16 step, fn_1_152FAC_Cell *table, s16 cols, s16 *found) {
    s16 cnt = 0;
    do {
        cnt++;
        ent += step;
        if (ent < 0 || cols - 1 < ent) {
            return 100;
        }
    } while ((s16)fn_1_152FAC_get(grp, ent, table, cols) < 0);
    *found = ent;
    return cnt;
}

s32 fn_1_152FAC(s16 idx, s32 id, s16 y, s16 x, fn_1_152FAC_Cell *table, s16 rows, s16 cols) {
    s16 total = (s16)(rows * cols);
    s16 grp;
    s16 ent;
    s16 lo;
    s16 hi;
    s16 lo_cnt;
    s16 hi_cnt;

    if (lbl_1_bss_8B3A0.unk_94 & 0x20000) {
        if ((s16)id != -1) {
            fn_1_152FAC_find((s16)id, table, rows, cols, (CELL_HIDDEN | CELL_LOCKED), &grp, &ent);
        }
    } else {
        if ((s16)id != -1) {
            fn_1_152FAC_find((s16)id, table, rows, cols, CELL_LOCKED, &grp, &ent);
        }
    }
    if (x != 0) {
        do {
            ent = (s16)((ent + x + total) % cols);
            id = fn_1_152FAC_get(lbl_1_bss_8B3A0.anchor[idx].grp, ent, table, cols);
            if ((s16)id < 0) {
                lo_cnt = fn_1_152FAC_scan_grp(lbl_1_bss_8B3A0.anchor[idx].grp, ent, -1, table, rows, cols, &lo);
                hi_cnt = fn_1_152FAC_scan_grp(lbl_1_bss_8B3A0.anchor[idx].grp, ent, 1, table, rows, cols, &hi);
                if (lo_cnt != 100 || hi_cnt != 100) {
                    if (lo_cnt < hi_cnt) {
                        id = fn_1_152FAC_get(lo, ent, table, cols);
                    } else {
                        id = fn_1_152FAC_get(hi, ent, table, cols);
                    }
                }
            } else {
                lbl_1_bss_8B3A0.repeat[idx].grp = 0;
            }
        } while ((s16)id < 0);
        lbl_1_bss_8B3A0.anchor[idx].ent = ent;
        lbl_1_bss_8B3A0.repeat[idx].ent = 0;
    }
    if (y != 0) {
        do {
            grp = (s16)((grp + y + total) % rows);
            id = fn_1_152FAC_get(grp, lbl_1_bss_8B3A0.anchor[idx].ent, table, cols);
            if ((s16)id < 0) {
                lo_cnt = fn_1_152FAC_scan_ent(grp, lbl_1_bss_8B3A0.anchor[idx].ent, -1, table, cols, &lo);
                hi_cnt = fn_1_152FAC_scan_ent(grp, lbl_1_bss_8B3A0.anchor[idx].ent, 1, table, cols, &hi);
                if (lo_cnt != 100 || hi_cnt != 100) {
                    if (lo_cnt < hi_cnt) {
                        id = fn_1_152FAC_get(grp, lo, table, cols);
                    } else {
                        id = fn_1_152FAC_get(grp, hi, table, cols);
                    }
                }
            } else {
                lbl_1_bss_8B3A0.repeat[idx].ent = 0;
            }
        } while ((s16)id < 0);
        lbl_1_bss_8B3A0.anchor[idx].grp = grp;
        lbl_1_bss_8B3A0.repeat[idx].grp = 0;
    }
    if (lbl_1_bss_8B3A0.unk_94 & 0x8000) {
        if (y != 0) {
            if (lbl_1_bss_8B3A0.cur[idx].ent == ent) {
                lbl_1_bss_8B3A0.repeat[idx].ent++;
            } else {
                lbl_1_bss_8B3A0.repeat[idx].ent = 0;
            }
            if (lbl_1_bss_8B3A0.repeat[idx].ent > 2) {
                lbl_1_bss_8B3A0.repeat[idx].ent = 0;
                lbl_1_bss_8B3A0.anchor[idx].ent = lbl_1_bss_8B3A0.cur[idx].ent;
            }
        }
        if (x != 0) {
            if (lbl_1_bss_8B3A0.cur[idx].grp == grp) {
                lbl_1_bss_8B3A0.repeat[idx].grp++;
            } else {
                lbl_1_bss_8B3A0.repeat[idx].grp = 0;
            }
            if (lbl_1_bss_8B3A0.repeat[idx].grp > 2) {
                lbl_1_bss_8B3A0.repeat[idx].grp = 0;
                lbl_1_bss_8B3A0.anchor[idx].grp = lbl_1_bss_8B3A0.cur[idx].grp;
            }
        }
    }
    if (lbl_1_bss_8B3A0.unk_94 & 0x20000) {
        if ((s16)id != -1) {
            fn_1_152FAC_find((s16)id, table, rows, cols, (CELL_HIDDEN | CELL_LOCKED), &grp, &ent);
        }
    } else {
        if ((s16)id != -1) {
            fn_1_152FAC_find((s16)id, table, rows, cols, CELL_LOCKED, &grp, &ent);
        }
    }
    lbl_1_bss_8B3A0.cur[idx].ent = ent;
    lbl_1_bss_8B3A0.cur[idx].grp = grp;
    return id;
}
/* fzgx:end fn_1_152FAC */
