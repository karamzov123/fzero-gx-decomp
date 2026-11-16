#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_tow.h"
#include "rel/main_rel/bg_aur.h"
#include "psvec.h"

typedef struct {
    s32 count;
    u8 pad_004[0x100];
    s32 counter[64];
    f32 timer[64];
    f32 progress[64];
    f32 cooldown[64];
} Fn153B24Data;

typedef struct {
    f32 m[12];
} AuroraCam;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3;

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

typedef struct BgAurVec {
    f32 x, y, z;
} BgAurVec;
extern void fn_1_153AF8(u32 *entries);
extern void fn_1_153D48(void *background);
extern void fn_1_9A508(void);
extern int fn_1_58C4(void);
extern void fn_1_5948(u32 arg0);
extern void fn_1_627C();
extern u32 fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern void fn_1_153D74(void *);
extern void fn_1_153B24();
extern void fn_1_153C60(u8 *base);
extern void fn_1_1540B0(Obj_1_data_2A7E0_At3C *);
extern void fn_1_9AD88(void);
extern void lbl_8006DFE8(void *);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void lbl_8006D784(void *);
extern void fn_1_560F0(s32 index, void *arg);
extern void fn_1_55210(void *value);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern s16 camera_get_mode(void);
extern u32 lbl_8006DAEC(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DB30(void);
extern f32 lbl_8006D0B4(f32 x);
extern void fn_1_862D4(s16 mode, void *out);
extern void fn_1_8636C(int index, void *arg);
extern void fn_1_869B0(int index, u32 *out);
extern void fn_8006F1F0(V3 *a, V3 *b, V3 *out);
extern AuroraDef lbl_1_rodata_D508;
extern AuroraCam *lbl_801A6D00;
extern s32 fn_1_5910(void);
extern void fn_1_154164(u8 *value, const BgAurVec *offset, void *rotation, s32 all);
extern u32 lbl_1_rodata_D57C[7];
extern u32 fn_1_9BBE4(void *, u32, u32, void *);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0C8(void *);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern u32 lbl_801A63C0;
extern void OSPanic(const char *file, int line, const char *msg, ...);

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
        fn_1_5948( (int)(i));
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

    fn_1_153C60( (u8 *)(Obj_1_data_2A7E0_At3C *)(object));
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

/* fzgx:begin fn_1_153B24 */

void fn_1_153B24(data, lab_unused0, lab_unused1, lab_unused2)
Fn153B24Data *data;
u32 lab_unused0;
u32 lab_unused1;
u32 lab_unused2;
{
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

/* fzgx:begin fn_1_153C60 */

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

            if ((value + 0x10000) == 0xffff || (value & (((u32 *)&lbl_1_data_2A7E0))[20]) != 0) {
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

/* fzgx:begin fn_1_153D74 */

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





static inline f32 fn_1_153D74_operand(f32 right, f32 left) { left *= right; return left; }
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
        fn_1_5948( (int)(i));
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
            fn_1_8636C( (s16)(mode), (void *)(AuroraCam *)(lbl_801A6D00));
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
            fn_1_869B0( (s16)(mode), (u32 *)(void *)(&p->target));
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
/* fzgx:end fn_1_153D74 */

/* fzgx:begin fn_1_1540B0 */
void fn_1_1540B0(Obj_1_data_2A7E0_At3C *bg) {
    u8 *table;
    s32 i;
    u8 *base;
    s32 slot;
    BgAurVec args;

    base = (u8 *)bg + 0x1108;
    slot = fn_1_5910();
    fn_1_154164((u8 *)bg, (BgAurVec *)(base + slot * 0xc + 0x8c), base + slot * 0x30 + 0x23c, 0);
    table = base;
    for (i = 0; i < ((s32 *)base)[1]; i++) {
        args = *(BgAurVec *)lbl_1_rodata_D57C;
        fn_1_154164((u8 *)bg, &args, table + 0x2fc, 1);
        table += 0x30;
    }
}
/* fzgx:end fn_1_1540B0 */

/* fzgx:begin fn_1_154164 */
/* begin game/main_rel/bg_aur_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BG_AUR_TYPES_H
#define GAME_MAIN_REL_BG_AUR_TYPES_H

// Types (and the externs that name them) of bg_aur.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).

struct fn_1_151C9C_lbl_1_rodata_D4F8 {
    f32 unk_0;
};

struct fn_1_151C9C_lbl_1_rodata_D500 {
    f64 unk_0;
};


#endif  // GAME_MAIN_REL_BG_AUR_TYPES_H

/* end game/main_rel/bg_aur_types.h */

typedef struct V { f32 x,y,z; } V;


typedef struct BgAurPart {
    u32 flags;
    u32 unk_4;
    u32 unk_8;
    f32 pos[3];
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    s16 unk_1e;
    f32 scale[3];
    u8 pad_2c[0x40 - 0x2c];
} BgAurPart;

typedef struct BgAurParts {
    s32 count;
    u32 unk_4;
    BgAurPart *parts[17];
    s32 hidden[17];
} BgAurParts;

void fn_1_154164(u8 *value, const BgAurVec *offset, void *rotation, s32 all) {
    f32 *pos;
    BgAurPart *part;
    s32 i;
    BgAurParts *list;
    f32 mtx[12];
    BgAurPart parts[17];

    list = (BgAurParts *)(value + 0x1108);
    if (list->parts[0] == NULL) {
        return;
    }

    parts[0] = *list->parts[0];
    parts[0].flags &= 0x7FFFFFFF;
    psvec_add(parts[0].pos, offset, parts[0].pos);
    lbl_8006D7DC(parts[0].pos);
    lbl_8006DFC4(rotation);
    lbl_8006E13C(parts[0].scale);
    lbl_8006DB74(mtx);
    fn_1_9BBE4(&parts[0], 0, 0, mtx);

    for (i = 0; i < list->count; i++) {
        if (all == 0 && list->hidden[i] != 0) {
            continue;
        }
        part = &parts[i + 1];
        pos = part->pos;
        parts[i + 1] = *list->parts[i + 1];
        parts[i + 1].flags &= 0x7FFFFFFF;
        psvec_add(pos, offset, pos);
        lbl_8006D7DC(parts[0].pos);
        lbl_8006DFC4(rotation);
        lbl_8006E0C8(parts[0].pos);
        lbl_8006E0A4(pos);
        mathutil_mtxA_rotate_z(parts[i + 1].rot_z);
        mathutil_mtxA_rotate_y(parts[i + 1].rot_y);
        mathutil_mtxA_rotate_x(parts[i + 1].rot_x);
        lbl_8006E13C(part->scale);
        lbl_8006DB74(mtx);
        fn_1_9BBE4(part, 0, 0, mtx);
    }
}
/* fzgx:end fn_1_154164 */

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

/* fzgx:begin fn_1_154410 */

/* Retail addresses bg_tow.c's literal pool (lbl_1_rodata_D508) through one base register;
   the primer reproduces that pool's first-use order so this unit's literals land on the
   retail offsets. The .fzgxpool section is dropped at integration. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.15f;
    s = -0.95f;
    s = 0.031f;
    s = 0.005f;
    s = -0.032f;
    s = -0.923f;
    s = 1.0f;
    s = 0.0f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[15] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
    s = 200.0f;
    s = 50.0f;
    s = 0.1f;
    s = 5.0f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.981f;
    s = 32767.0f;
    s = -0.928f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    u32 flags;
    u8 pad_4[0x8];
    u8 pos[0xC];
    s16 rotX;
    s16 rotY;
    s16 rotZ;
} BgTowEntity;

typedef struct {
    s32 count;
    s32 count2;
    BgTowEntity *single;
    BgTowEntity *entries[16];
    s32 flags[16];
    u8 pad_8C[0x2FC - 0x8C];
    u8 mtx[16][0x30];
} BgTowSub;

typedef struct {
    s32 count;
    BgTowEntity *entries[64];
    s32 steps[64];
    f32 valA[64];
    f32 valB[64];
    f32 valC[64];
    u8 mtx[64][0x30];
    u32 unk_1104;
    BgTowSub sub;
} BgTowState;

static inline f32 bg_tow_randf(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (f32)(s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f;
}

s32 fn_1_154410(s32 kind, BgTowEntity *ent) {
    BgTowState *obj = (BgTowState *)lbl_1_data_2A7E0.unk_3C;
    BgTowSub *sub;

    switch (kind) {
    case 0:
        ent->flags |= 0x80000000;
        obj->entries[obj->count] = ent;
        obj->valA[obj->count] = -0.95f + (f32)(0.981f * bg_tow_randf());
        obj->valB[obj->count] = 0.005f + (f32)(-0.928f * bg_tow_randf());
        obj->steps[obj->count] = (s32)((obj->valB[obj->count] - 0.005f) / -0.032f);
        obj->valC[obj->count] = 0.0f;
        lbl_8006D7DC(ent->pos);
        mathutil_mtxA_rotate_z(ent->rotZ);
        mathutil_mtxA_rotate_y(ent->rotY);
        mathutil_mtxA_rotate_x(ent->rotX);
        lbl_8006DB74(obj->mtx[obj->count]);
        obj->count++;
        if (obj->count >= 64) {
            OSPanic("bg_tow.c", 482, "WINDOW NUM OVER!");
        }
        break;
    case 1:
        ent->flags |= 0x80000000;
        obj->sub.single = ent;
        break;
    case 2:
    case 3:
    case 5:
        sub = &obj->sub;
        ent->flags |= 0x80000000;
        sub->entries[sub->count] = ent;
        if (kind == 5) {
            sub->flags[sub->count] = 1;
        } else {
            sub->flags[sub->count] = 0;
        }
        sub->count++;
        if (sub->count >= 16) {
            OSPanic("bg_tow.c", 510, "BG_TOW_SEARCH OTHER NUM OVER\n");
        }
        break;
    case 4:
        sub = &obj->sub;
        lbl_8006D7DC(ent->pos);
        mathutil_mtxA_rotate_z(ent->rotZ);
        mathutil_mtxA_rotate_y(ent->rotY);
        mathutil_mtxA_rotate_x(ent->rotX);
        lbl_8006DB74(sub->mtx[sub->count2]);
        sub->count2++;
        if (sub->count2 >= 16) {
            OSPanic("bg_tow.c", 527, "BG_TOW_SCAMPOINT01 NUM OVER!");
        }
        break;
    default:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_154410 */
