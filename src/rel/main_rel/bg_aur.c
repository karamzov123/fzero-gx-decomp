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

/* fzgx:begin fn_1_151BDC noprologue */
#include "types.h"

typedef struct GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

/* A cell of a selection grid. */
typedef struct {
    s16 id;
    u8 pad[2];
    u32 flags;
} GridCell;

#define CELL_HIDDEN 0x80000000
#define CELL_LOCKED 0x40000000

typedef struct {
    s16 grp;
    s16 ent;
} GridPos;

/* The menu input state (0x14C bytes). */
typedef struct {
    u8 pad_0[0x94];
    u32 flags; /* 0x94 */
    u8 pad_98[0x18];
    GridPos cur[4]; /* 0xB0 */
    GridPos repeat[4]; /* 0xC0 */
    GridPos anchor[4]; /* 0xD0 */
    u8 pad_E0[0x6C];
} MenuState;

typedef struct {
    u32 flags;
    u8 pad_4[0x81A4];
    u32 colors[1][2]; /* 0x81A8 */
} MenuColorData;

typedef struct {
    u8 pad_0[4];
    GXColor color4; /* 0x4 */
    GXColor color8; /* 0x8 */
    u8 pad_C[9];
    u8 id; /* 0x15 */
} MenuMaterial;

typedef struct {
    u8 pad_0[4];
    MenuMaterial *mat; /* 0x4 */
} MenuModel;

extern MenuState lbl_1_bss_8B3A0;
extern void fn_80074A7C(void (*func)(MenuModel *));
extern void fn_80008BA8(void *dst, const void *src, u32 n);
extern u32 fn_1_8D5F0(s16 id);
extern s32 fn_1_8D690(s16 id);
extern s32 fn_1_8D72C(s16 id);
extern s32 fn_1_F7BE4(s16 id);
extern s32 fn_1_F7EDC(s16 id);

void fn_1_151C9C(MenuModel *model);

MenuColorData *lbl_1_bss_8ED88;
s16 lbl_1_bss_8ED8C;
s16 lbl_1_bss_8ED8E;

void fn_1_151BDC(MenuColorData *data) {
    lbl_1_bss_8ED88 = data;
}
/* fzgx:end fn_1_151BDC */

/* fzgx:begin fn_1_151BE8 noprologue */
u32 fn_1_151BE8(s16 row, s16 col) {
    u32 colors[75][4] = {
        { 0xFA323201, 0x008C2801, 0x328CFA01, 0xFADC6401 },
        { 0xFADC6401, 0xFA323201, 0x008C2801, 0x328CFA01 },
        { 0xFA323201, 0x008C2801, 0x328CFA01, 0xFADC6401 },
        { 0xFA323201, 0x008C2801, 0x328CFA01, 0xFADC6401 },
        { 0xFA323201, 0x008C2801, 0x328CFA01, 0xFADC6401 },
        { 0xFA323201, 0x008C2801, 0x328CFA01, 0xFADC6401 },
        { 0x008C2801, 0x328CFA01, 0xFADC6401, 0xFA323201 },
        { 0xFA323201, 0x008C2801, 0x328CFA01, 0xFADC6401 },
        { 0xFADC6401, 0xFA323201, 0x008C2801, 0x328CFA01 },
        { 0x008C2801, 0x328CFA01, 0xFADC6401, 0xFA323201 },
        { 0xFA323201, 0x008C2801, 0x328CFA01, 0xFADC6401 },
        { 0xFADC6401, 0xFA323201, 0x008C2801, 0x328CFA01 },
        { 0x008C2801, 0x328CFA01, 0xFADC6401, 0xFA323201 },
        { 0x008C2801, 0x328CFA01, 0xFADC6401, 0xFA323201 },
        { 0x008C2801, 0x328CFA01, 0xFADC6401, 0xFA323201 },
        { 0xFA323201, 0x008C2801, 0x328CFA01, 0xFADC6401 },
        { 0xFA323201, 0x008C2801, 0x328CFA01, 0xFADC6401 },
        { 0xFADC6401, 0xFA323201, 0x008C2801, 0x328CFA01 },
        { 0x008C2801, 0x328CFA01, 0xFADC6401, 0xFA323201 },
        { 0x008C2801, 0x328CFA01, 0xFADC6401, 0xFA323201 },
        { 0x008C2801, 0x328CFA01, 0xFADC6401, 0xFA323201 },
        { 0xFA323201, 0x008C2801, 0x328CFA01, 0xFADC6401 },
        { 0xFADC6401, 0xFA323201, 0x008C2801, 0x328CFA01 },
        { 0x008C2801, 0x328CFA01, 0xFADC6401, 0xFA323201 },
        { 0x008C2801, 0x328CFA01, 0xFADC6401, 0xFA323201 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0xFABA6401, 0xFA78C801, 0x005A2801, 0x8C64DC01 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFABA6401, 0xFA78C801, 0x005A2801, 0x8C64DC01 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0xFABA6401, 0xFA78C801, 0x005A2801, 0x8C64DC01 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFABA6401, 0xFA78C801, 0x005A2801, 0x8C64DC01 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFABA6401, 0xFA78C801, 0x005A2801, 0x8C64DC01 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0xFABA6401, 0xFA78C801, 0x005A2801, 0x8C64DC01 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0xFABA6401, 0xFA78C801, 0x005A2801, 0x8C64DC01 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFABA6401, 0xFA78C801, 0x005A2801, 0x8C64DC01 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
        { 0xFABA6401, 0xFA78C801, 0x005A2801, 0x8C64DC01 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0xFA78C801, 0x005A2801, 0x8C64DC01, 0xFABA6401 },
        { 0xFABA6401, 0xFA78C801, 0x005A2801, 0x8C64DC01 },
        { 0x005A2801, 0x8C64DC01, 0xFABA6401, 0xFA78C801 },
    };

    return colors[row][col];
}
/* fzgx:end fn_1_151BE8 */

/* fzgx:begin fn_1_151C3C noprologue */
void fn_1_151C3C(s16 index, s16 row) {
    lbl_1_bss_8ED8C = index;
    lbl_1_bss_8ED8E = row;
    fn_80074A7C(fn_1_151C9C);
}
/* fzgx:end fn_1_151C3C */

/* fzgx:begin fn_1_151C78 noprologue */
void fn_1_151C78(void) {
    fn_80074A7C(NULL);
}
/* fzgx:end fn_1_151C78 */

/* fzgx:begin fn_1_151C9C noprologue */
static inline void color_scale(GXColor *c, f32 k) {
    c->r = c->r * k;
    c->g = c->g * k;
    c->b = c->b * k;
}

void fn_1_151C9C(MenuModel *model) {
    MenuColorData *data;
    s16 idx;
    s16 i;
    u32 color;
    MenuMaterial *mat;
    GXColor c;

    data = lbl_1_bss_8ED88;
    idx = lbl_1_bss_8ED8C;
    for (i = 0; i < 1; i++) {
        if (data == NULL || (data->flags & 0x80000000) == 0 || (data->flags & 0x40000000) == 0) {
            color = fn_1_151BE8(lbl_1_bss_8ED8E, i);
        } else {
            color = data->colors[idx][i];
        }
        mat = model->mat;
        if (mat->id == (u8)color) {
            c.r = color >> 24;
            c.g = color >> 16;
            c.b = color >> 8;
            c.a = 0xFF;
            fn_80008BA8(&mat->color8, &c, 4);
            color_scale(&c, 1.0f);
            fn_80008BA8(&model->mat->color4, &c, 4);
        }
    }
}
/* fzgx:end fn_1_151C9C */

/* fzgx:begin fn_1_151E20 noprologue */
u32 fn_1_151E20(u32 value, s16 index) {
    u32 result = (u32)-1;

    switch (index) {
    case 0:
        result = value >> 24;
        break;
    case 1:
        result = (value >> 16) & 0xFF;
        break;
    case 2:
        result = (value >> 8) & 0xFF;
        break;
    case 3:
        result = value & 0xFF;
        break;
    }
    return result;
}
/* fzgx:end fn_1_151E20 */

/* fzgx:begin fn_1_151E74 noprologue */
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
    }
}
/* fzgx:end fn_1_151E74 */

/* fzgx:begin fn_1_151EF8 noprologue */
void fn_1_151EF8(s16 *ids, s16 id_count, GridCell *table, s16 rows, s16 cols) {
    s16 i;
    s16 j;
    s16 row;
    s16 col;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            table[i * cols + j].flags |= CELL_LOCKED;
            table[i * cols + j].id = -1;
        }
    }
    for (i = 0; i < id_count; i++) {
        if (ids[i] == -1) {
            continue;
        }
        row = i / cols;
        col = i % cols;
        table[row * cols + col].id = ids[i];
        table[row * cols + col].flags = 0;
        if (table[row * cols + col].id >= 0x29) {
            table[row * cols + col].flags |= 0x20000000;
            table[row * cols + col].flags |= CELL_LOCKED;
            continue;
        }
        if (!fn_1_8D690(table[row * cols + col].id)) {
            table[row * cols + col].flags |= CELL_HIDDEN;
        }
        if (!fn_1_8D72C(table[row * cols + col].id)) {
            table[row * cols + col].flags |= CELL_LOCKED;
        }
        if ((lbl_1_bss_8B3A0.flags & 0x40000000) != 0 && !fn_1_8D690(table[row * cols + col].id)) {
            table[row * cols + col].flags |= CELL_LOCKED;
        }
        if ((lbl_1_bss_8B3A0.flags & 0x02000000) != 0 && table[row * cols + col].id != 6 &&
            (table[row * cols + col].flags & CELL_HIDDEN) == 0) {
            table[row * cols + col].flags |= CELL_HIDDEN;
        }
    }
}
/* fzgx:end fn_1_151EF8 */

/* fzgx:begin fn_1_152208 noprologue */
void fn_1_152208(s16 *ids, s16 id_count, GridCell *table, s16 rows, s16 cols) {
    s16 i;
    s16 k;
    s16 n;
    s16 row;
    s16 col;
    s32 found;

    found = 0;
    for (i = 0; i < 41; i++) {
        if ((fn_1_8D5F0(i) & 0x10000000) && fn_1_F7BE4(i) != 0) {
            found = 1;
            break;
        }
    }
    for (i = 0; i < rows; i++) {
        for (k = 0; k < cols; k++) {
            table[i * cols + k].flags |= CELL_LOCKED;
            table[i * cols + k].id = -1;
        }
    }
    for (n = 0; n < id_count; n++) {
        if (ids[n] == -1) {
            continue;
        }
        row = n / cols;
        col = n % cols;
        table[row * cols + col].id = ids[n];
        table[row * cols + col].flags = 0;
        if (found == 1) {
            table[row * cols + col].flags |= CELL_HIDDEN;
        } else if ((fn_1_8D5F0(table[row * cols + col].id) & 0x10000000) != 0) {
            table[row * cols + col].flags |= CELL_LOCKED;
        } else {
            table[row * cols + col].flags |= CELL_HIDDEN;
        }
        if (fn_1_F7BE4(table[row * cols + col].id) != 0) {
            table[row * cols + col].flags &= 0x3FFFFFFF;
        }
    }
}
/* fzgx:end fn_1_152208 */

/* fzgx:begin fn_1_152510 noprologue */
void fn_1_152510(s16 *ids, s16 id_count, GridCell *table, s16 rows, s16 cols) {
    s16 i;
    s16 k;
    s16 n;
    s16 row;
    s16 col;
    s32 found;

    found = 0;
    for (i = 0; i < 41; i++) {
        if ((fn_1_8D5F0(i) & 0x10000000) && fn_1_F7EDC(i) != 0) {
            found = 1;
            break;
        }
    }
    for (i = 0; i < rows; i++) {
        for (k = 0; k < cols; k++) {
            table[i * cols + k].flags |= CELL_LOCKED;
            table[i * cols + k].id = -1;
        }
    }
    for (n = 0; n < id_count; n++) {
        if (ids[n] == -1) {
            continue;
        }
        row = n / cols;
        col = n % cols;
        table[row * cols + col].id = ids[n];
        table[row * cols + col].flags = 0;
        if (found == 1) {
            table[row * cols + col].flags |= CELL_HIDDEN;
        } else if ((fn_1_8D5F0(table[row * cols + col].id) & 0x10000000) != 0) {
            table[row * cols + col].flags |= CELL_LOCKED;
        } else {
            table[row * cols + col].flags |= CELL_HIDDEN;
        }
        if (fn_1_F7EDC(table[row * cols + col].id) != 0) {
            table[row * cols + col].flags &= 0x3FFFFFFF;
        }
        if (fn_1_F7BE4(table[row * cols + col].id) != 0) {
            table[row * cols + col].flags &= 0x3FFFFFFF;
            table[row * cols + col].flags |= 0x08000000;
        }
    }
}
/* fzgx:end fn_1_152510 */

/* fzgx:begin fn_1_152840 noprologue */
int fn_1_152840(s16 id, GridCell *table, s16 rows, s16 cols) {
    s16 count;
    s16 i;
    s16 j;

    if (id == -1) {
        return 0;
    }
    count = cols;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < count; j++) {
            if ((table[i * count + j].flags & (CELL_HIDDEN | CELL_LOCKED)) == 0 && id == table[i * count + j].id) {
                return 1;
            }
        }
    }
    return 0;
}
/* fzgx:end fn_1_152840 */

/* fzgx:begin fn_1_1528D0 noprologue */
s32 fn_1_1528D0(s16 grp, s16 ent, GridCell *table, s16 rows, s16 cols) {
    if (lbl_1_bss_8B3A0.flags & 0x20000) {
        if (table[grp * cols + ent].flags & (CELL_HIDDEN | CELL_LOCKED)) {
            return -1;
        }
    } else {
        if (table[grp * cols + ent].flags & CELL_LOCKED) {
            return -1;
        }
    }
    if (table[grp * cols + ent].id == -1) {
        return -1;
    }
    return table[grp * cols + ent].id;
}
/* fzgx:end fn_1_1528D0 */

/* fzgx:begin fn_1_152970 noprologue */
s32 fn_1_152970(s16 *grp, s16 *ent, s16 id, u32 mask, GridCell *table, s16 rows, s16 cols) {
    s16 count;
    s16 i;
    s16 j;

    if (id == -1) {
        return 0;
    }
    count = cols;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < count; j++) {
            if ((table[i * count + j].flags & mask) == 0 && id == table[i * count + j].id) {
                *grp = i;
                *ent = j;
                return 1;
            }
        }
    }
    return 0;
}
/* fzgx:end fn_1_152970 */

/* fzgx:begin fn_1_152A28 noprologue */
s32 fn_1_152A28(s16 id, s16 y, s16 x, GridCell *table, s16 rows, s16 cols) {
    s16 ent;
    s16 grp;
    s32 res;
    s16 total = (rows * cols);

    if (lbl_1_bss_8B3A0.flags & 0x20000) {
        fn_1_152970(&grp, &ent, id, CELL_HIDDEN | CELL_LOCKED, table, rows, cols);
    } else {
        fn_1_152970(&grp, &ent, id, CELL_LOCKED, table, rows, cols);
    }
    if (x != 0) {
        do {
            ent = ((ent + x + total) % cols);
            res = fn_1_1528D0(grp, ent, table, rows, cols);
        } while ((s16)res < 0);
    }
    if (y != 0) {
        do {
            grp = ((grp + y + total) % rows);
            res = fn_1_1528D0(grp, ent, table, rows, cols);
        } while ((s16)res < 0);
    }
    return res;
}
/* fzgx:end fn_1_152A28 */

/* fzgx:begin fn_1_152CB4 noprologue */
s32 fn_1_152CB4(s32 id, s16 y, s16 x, GridCell *table, s16 rows, s16 cols) {
    s16 ent;
    s16 grp;
    s16 prev;
    s32 res;
    s16 total = (rows * cols);
    s16 saved;

    if (lbl_1_bss_8B3A0.flags & 0x20000) {
        fn_1_152970(&grp, &ent, id, CELL_HIDDEN | CELL_LOCKED, table, rows, cols);
    } else {
        fn_1_152970(&grp, &ent, id, CELL_LOCKED, table, rows, cols);
    }
    saved = ent;
    if (x != 0) {
        do {
            prev = ent;
            ent = ((ent + x + total) % cols);
            if (x > 0 && prev > ent) {
                break;
            }
            if (x < 0 && prev < ent) {
                break;
            }
            res = fn_1_1528D0(grp, ent, table, rows, cols);
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
            grp = ((grp + y + total) % rows);
            if (y > 0 && prev > grp) {
                break;
            }
            if (y < 0 && prev < grp) {
                break;
            }
            res = fn_1_1528D0(grp, ent, table, rows, cols);
            if ((s16)res >= 0) {
                id = res;
            }
        } while ((s16)res < 0);
    }
    return id;
}
/* fzgx:end fn_1_152CB4 */

/* fzgx:begin fn_1_152FAC noprologue */
static inline s16 grid_scan_grp(s16 grp, s16 ent, s16 step, GridCell *table, s16 rows, s16 cols, s16 *found) {
    s16 cnt = 0;

    do {
        cnt++;
        grp += step;
        if (grp < 0 || rows - 1 < grp) {
            return 100;
        }
    } while ((s16)fn_1_1528D0(grp, ent, table, rows, cols) < 0);
    *found = grp;
    return cnt;
}

static inline s16 grid_scan_ent(s16 grp, s16 ent, s16 step, GridCell *table, s16 rows, s16 cols, s16 *found) {
    s16 cnt = 0;

    do {
        cnt++;
        ent += step;
        if (ent < 0 || cols - 1 < ent) {
            return 100;
        }
    } while ((s16)fn_1_1528D0(grp, ent, table, rows, cols) < 0);
    *found = ent;
    return cnt;
}

s32 fn_1_152FAC(s16 idx, s32 id, s16 y, s16 x, GridCell *table, s16 rows, s16 cols) {
    s16 total = (rows * cols);
    s16 grp;
    s16 ent;
    s16 lo;
    s16 hi;
    s16 lo_cnt;
    s16 hi_cnt;

    if (lbl_1_bss_8B3A0.flags & 0x20000) {
        fn_1_152970(&grp, &ent, id, CELL_HIDDEN | CELL_LOCKED, table, rows, cols);
    } else {
        fn_1_152970(&grp, &ent, id, CELL_LOCKED, table, rows, cols);
    }
    if (x != 0) {
        do {
            ent = ((ent + x + total) % cols);
            id = fn_1_1528D0(lbl_1_bss_8B3A0.anchor[idx].grp, ent, table, rows, cols);
            if ((s16)id < 0) {
                lo_cnt = grid_scan_grp(lbl_1_bss_8B3A0.anchor[idx].grp, ent, -1, table, rows, cols, &lo);
                hi_cnt = grid_scan_grp(lbl_1_bss_8B3A0.anchor[idx].grp, ent, 1, table, rows, cols, &hi);
                if (lo_cnt != 100 || hi_cnt != 100) {
                    if (lo_cnt < hi_cnt) {
                        id = fn_1_1528D0(lo, ent, table, rows, cols);
                    } else {
                        id = fn_1_1528D0(hi, ent, table, rows, cols);
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
            grp = ((grp + y + total) % rows);
            id = fn_1_1528D0(grp, lbl_1_bss_8B3A0.anchor[idx].ent, table, rows, cols);
            if ((s16)id < 0) {
                lo_cnt = grid_scan_ent(grp, lbl_1_bss_8B3A0.anchor[idx].ent, -1, table, rows, cols, &lo);
                hi_cnt = grid_scan_ent(grp, lbl_1_bss_8B3A0.anchor[idx].ent, 1, table, rows, cols, &hi);
                if (lo_cnt != 100 || hi_cnt != 100) {
                    if (lo_cnt < hi_cnt) {
                        id = fn_1_1528D0(grp, lo, table, rows, cols);
                    } else {
                        id = fn_1_1528D0(grp, hi, table, rows, cols);
                    }
                }
            } else {
                lbl_1_bss_8B3A0.repeat[idx].ent = 0;
            }
        } while ((s16)id < 0);
        lbl_1_bss_8B3A0.anchor[idx].grp = grp;
        lbl_1_bss_8B3A0.repeat[idx].grp = 0;
    }
    if (lbl_1_bss_8B3A0.flags & 0x8000) {
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
    if (lbl_1_bss_8B3A0.flags & 0x20000) {
        fn_1_152970(&grp, &ent, id, CELL_HIDDEN | CELL_LOCKED, table, rows, cols);
    } else {
        fn_1_152970(&grp, &ent, id, CELL_LOCKED, table, rows, cols);
    }
    lbl_1_bss_8B3A0.cur[idx].ent = ent;
    lbl_1_bss_8B3A0.cur[idx].grp = grp;
    return id;
}
/* fzgx:end fn_1_152FAC */
