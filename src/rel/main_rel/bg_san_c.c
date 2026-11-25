#include "types.h"
#include "game/vec3.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_san.h"

extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_9A508(void);
extern void fn_1_DAF94();
extern s32 fn_1_5910();
extern void *fn_1_9D260();
extern s16 fn_1_7B054();
extern s16 fn_1_3F0C8(void);
extern void fn_1_1067A8(void *arg0, f32 arg1, f32 arg2);
extern void *fn_1_548AC(s32);
extern void fn_1_5489C(void *, void *);
extern void lbl_8006DCA4();
extern void fn_1_DB53C(void *, f32);
extern u32 fn_1_105AB8(u32, u32);

/* fzgx:begin fn_1_DAD68 */
// fn_1_DAD68: empty in retail (single blr).
void fn_1_DAD68(void) {
}
/* fzgx:end fn_1_DAD68 */

/* fzgx:begin fn_1_DAD6C */
#include "rel/main_rel/bg_san.h"

void fn_1_DAD6C(void) {
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    fn_1_9A508();
    fn_1_DAF94(obj);
}
/* fzgx:end fn_1_DAD6C */

/* fzgx:begin fn_1_DADA8 */
#include "types.h"

extern u32 fn_1_58C4();
extern s32 fn_1_5948();
extern void fn_1_627C();

struct fn_1_DADA8_lbl_1_data_2A7E0 {
    u8 pad_0[0x3C];
    u32 unk_3C;
};

void fn_1_DADA8(void) {
    u32 v0;
    s32 v1;
    u32 t0;
    v0 = (*(struct fn_1_DADA8_lbl_1_data_2A7E0 *)&lbl_1_data_2A7E0).unk_3C;
    t0 = fn_1_58C4();
    v1 = 0;
    while (v1 < (s32)t0) {
    fn_1_5948(v1);
    fn_1_105AB8(((v0 + 0x10000) + 17056), v1);
    fn_1_627C(v1);
    v1++;
    }
}
/* fzgx:end fn_1_DADA8 */

/* fzgx:begin fn_1_DAE24 */
extern u32 fn_1_58C4();
extern s32 fn_1_5948();

extern void fn_1_106084(void *target, s32 index, f32 x, f32 y, f32 z);
extern void fn_1_627C();
extern void fn_1_DB138();

void fn_1_DAE24(void) {
    s32 count;
    f32 *value;
    s32 index;
    u32 object;

    object = (u32)lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    count = fn_1_58C4();
    value = (f32 *)object;
    for (index = 0; index < count; index++) {
        if (fn_1_7B054(fn_1_5948(index)) == 42) {
            if (fn_1_3F0C8() != 39) {
                fn_1_106084((void *)(object + 0x142a0), index,
                    0.0f, *value, 30.0f);
            }
        }
        fn_1_627C(index);
        value++;
    }
    fn_1_DB138(object);
}
/* fzgx:end fn_1_DAE24 */

/* fzgx:begin fn_1_DAEF8 */
// fn_1_DAEF8: empty in retail (single blr).
void fn_1_DAEF8(void) {
}
/* fzgx:end fn_1_DAEF8 */

/* fzgx:begin fn_1_DAEFC */
extern void fn_1_DB198();

// Initializes the current background object and updates it for the active state.
void fn_1_DAEFC(void) {
    s32 slot;
    Obj_1_data_2A7E0_At3C *background;

    slot = fn_1_5910();
    background = lbl_1_data_2A7E0.unk_3C;
    fn_1_DB198(background, fn_1_9D260(&lbl_1_data_2A7E0));
    fn_1_9AD88();
    if (fn_1_7B054() == 42) {
        if (fn_1_3F0C8() != 39) {
            fn_1_1067A8(
                (u8 *)background + 0x142a0,
                ((f32 *)background)[slot],
                30.0f
            );
        }
    }
}
/* fzgx:end fn_1_DAEFC */

/* fzgx:begin fn_1_DAF90 */
// fn_1_DAF90: empty in retail (single blr).
void fn_1_DAF90(void) {
}
/* fzgx:end fn_1_DAF90 */

/* fzgx:begin fn_1_DAF94 */
extern u32 fn_1_58C4();

typedef struct V3 { f32 x, y, z; } V3;
typedef struct Elem { V3 pos; f32 w; } Elem;
typedef struct Src { u8 pad[0xc]; V3 pos; } Src;
typedef struct Entry {
    Src *src;
    V3 cur;
    s32 zero;
    f32 one;
    s16 a;
    f32 b;
    Elem first[128];
    Elem second[128];
} Entry;
typedef struct Obj {
    u8 pad[0x10];
    s32 count;
    Entry entries[1];
} Obj;

void fn_1_DAF94(Obj *obj) {
    Entry *e = obj->entries;
    if (fn_1_58C4() < 2) {
        f32 one;
        f32 zero;
        Src *s;
        s32 n;
        zero = 0.0f;
        one = 1.0f;
        n = obj->count;
        for (; n > 0; n--) {
            s32 i;
            Elem *p;
            s = e->src;
            obj->entries[0].a = 0;
            obj->entries[0].b = zero;
            for (i = 128, p = obj->entries[0].first; i != 0; i--, p++) {
                p->pos = s->pos;
                p->w = zero;
            }
            for (i = 128, p = obj->entries[0].second; i != 0; i--, p++) {
                p->pos = s->pos;
                p->w = zero;
            }
            e->cur = s->pos;
            e->zero = 0;
            e->one = one;
            e++;
        }
    }
}
/* fzgx:end fn_1_DAF94 */

/* fzgx:begin fn_1_DB138 */
typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
} BgSanContext;

extern u32 fn_1_58C4();
extern void fn_1_DB268();

// Process each background-san entry when the object is in an eligible state.
void fn_1_DB138(BgSanContext *context) {
    u8 *entry;
    s32 count;

    if (fn_1_58C4(context) < 2) {
        count = context->unk_10;
        entry = (u8 *)context + 0x14;
        while (count > 0) {
            fn_1_DB268(entry);
            count -= 1;
            entry += 0x1020;
        }
    }
}
/* fzgx:end fn_1_DB138 */

/* fzgx:begin fn_1_DB198 */
typedef struct BgSanObject {
    u8 unk_00[0x10];
    s32 unk_10;
    void *unk_14;
    u8 unk_18[0x80c];
    f32 unk_824;
    f32 unk_828;
    f32 unk_82c;
} BgSanObject;

typedef struct BgSanPosition {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
} BgSanPosition;

typedef struct BgSanAllocation {
    u8 unk_00[0x4];
    void (*unk_04)(void);
    void *unk_08;
} BgSanAllocation;

extern u32 fn_1_58C4();
extern void *fn_1_5448C(BgSanPosition *position);
extern void fn_1_DB53C(void *, f32);

// Builds a scaled position event when the object is active.
void fn_1_DB198(BgSanObject *object, void *arg1) {
    BgSanPosition position;
    void *result;
    BgSanAllocation *allocation;

    if (fn_1_58C4((Obj_1_data_2A7E0 *)object) < 2 && object->unk_10 != 0) {
        position.unk_00 = (((f32 *)object->unk_14)[3] + object->unk_824) * 0.5f;
        position.unk_04 = (((f32 *)object->unk_14)[4] + object->unk_828) * 0.5f;
        position.unk_08 = (((f32 *)object->unk_14)[5] + object->unk_82c) * 0.5f;
        lbl_8006DCA4(object->unk_14);
        result = fn_1_5448C(&position);
        allocation = (BgSanAllocation *)fn_1_548AC(12);
        if (allocation != 0) {
            allocation->unk_04 = (void (*)(void))fn_1_DB53C;
            allocation->unk_08 = arg1;
            fn_1_5489C(result, allocation);
        }
    }
}
/* fzgx:end fn_1_DB198 */

/* fzgx:begin fn_1_DB268 */
typedef struct {
    f32 x, y, z;
} Fn1DB268_Vec;

typedef struct {
    Fn1DB268_Vec pos;
    f32 height;
} Fn1DB268_Point;

typedef struct {
    s16 head;
    f32 height;
    Fn1DB268_Point upper[128];
    Fn1DB268_Point lower[128];
} Fn1DB268_Trail;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x8];
    Fn1DB268_Vec pos;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    f32 scale;
} Fn1DB268_Source;

typedef struct {
    Fn1DB268_Source *source;
    Fn1DB268_Vec pos;
    s32 age;
    u8 pad_14[4];
    Fn1DB268_Trail trail;
} Fn1DB268_Effect;

extern u32 fn_1_58C4();
extern u32 lbl_801A66A0;
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D7DC(void *);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006E1B0(void *, void *);

void fn_1_DB268(Fn1DB268_Effect *effect) {
    Fn1DB268_Trail *slot; /* the trail shifted to the head entry: slot->upper[0] is upper[head] */
    Fn1DB268_Source *source;
    Fn1DB268_Trail *trail;
    Fn1DB268_Vec vecs[2];
    f32 dist;
    f32 drop;
    f32 dz;
    f32 dy;
    f32 dx;
    f32 rise;
    s32 i;
    Fn1DB268_Point *upper;
    Fn1DB268_Point *lower;

    if (fn_1_58C4() >= 2) {
        return;
    }
    source = effect->source;
    trail = &effect->trail;
    if (lbl_801A66A0 & 1) {
        return;
    }
    if (effect->age < 0xF8) {
        effect->age++;
    }
    dx = source->pos.x - effect->pos.x;
    dy = source->pos.y - effect->pos.y;
    dz = source->pos.z - effect->pos.z;
    vecs[1].x = dx;
    vecs[1].y = dy;
    vecs[1].z = dz;
    dist = dx * dx;
    dist += dy * dy;
    dist += dz * dz;
    dist = lbl_8006D0B4(dist);
    trail->head = (trail->head + 1) % 128;
    slot = (Fn1DB268_Trail *)((u8 *)trail + trail->head * sizeof(Fn1DB268_Point));
    lbl_8006D7DC(&source->pos);
    mathutil_mtxA_rotate_z(source->rot_z);
    mathutil_mtxA_rotate_y(source->rot_y);
    mathutil_mtxA_rotate_x(source->rot_x);
    rise = 25.0f;
    rise *= source->scale;
    {
        Fn1DB268_Vec offset = {0.0f, 0.0f, 0.0f};
        offset.y = rise;
        vecs[0] = offset;
        lbl_8006E1B0(&vecs[0], &vecs[0]);
        slot->upper[0].pos = vecs[0];
    }
    {
        Fn1DB268_Vec offset = {0.0f, 0.0f, 0.0f};
        offset.y = -rise;
        vecs[0] = offset;
        lbl_8006E1B0(&vecs[0], &vecs[0]);
        slot->lower[0].pos = vecs[0];
    }
    drop = 0.1f * dist;
    trail->height -= drop;
    slot->upper[0].height = trail->height;
    slot->lower[0].height = trail->height;
    upper = trail->upper;
    lower = trail->lower;
    for (i = 0; i < 128; i++, upper++, lower++) {
        if (i != trail->head) {
            upper->height += 0.02f * dist;
            lower->height += 0.02f * dist;
        }
    }
    effect->pos = source->pos;
}
/* fzgx:end fn_1_DB268 */

/* fzgx:begin fn_1_DB53C */
typedef struct DB53CVec {
    f32 x;
    f32 y;
    f32 z;
} DB53CVec;
DB53CVec lbl_1_bss_7ADB8[4];

typedef struct DB53CObj {
    u8 pad_0[0x4];
    u32 mask;
    u8 pad_8[0x4];
    DB53CVec pos;
} DB53CObj;

typedef struct DB53CItem {
    DB53CObj *obj;
    u8 pad_4[0x10];
    f32 alpha;
    u8 pad_18[0x808];
    DB53CVec pos;
    u8 pad_82C[0x7F4];
} DB53CItem;

typedef struct DB53CGroup {
    u8 pad_0[0x10];
    s32 count;
    DB53CItem items[1];
} DB53CGroup;

typedef struct DB53CEntry {
    u8 pad_0[0x8];
    u8 *data;
} DB53CEntry;

typedef struct DB53CTable {
    u8 pad_0[0xC];
    DB53CEntry *entries;
} DB53CTable;

typedef struct DB53CGlobal3BE0 {
    DB53CTable *table;
} DB53CGlobal3BE0;

typedef struct DB53CTexHolder {
    u8 pad_0[0x24];
    void *tex;
} DB53CTexHolder;

typedef struct DB53CScene {
    u8 pad_0[0x1C0];
    DB53CTexHolder *holder;
} DB53CScene;

typedef struct DB53CRoot {
    u8 pad_0[0x8];
    DB53CScene *scene;
} DB53CRoot;

typedef struct DB53CData2A7E0 {
    u8 pad_0[0x3C];
    DB53CGroup *group;
} DB53CData2A7E0;

s32 lbl_1_data_3DC70 = -1;
extern u32 lbl_801A6D00;

extern u32 fn_1_58C4();

extern s32 fn_1_6F84(void);
extern f32 fn_1_DC084();
extern s32 fn_1_54E34(DB53CVec *, f32);
extern s16 camera_get_mode(void);
extern s32 camera_get_flags(void);
extern u32 camera_forward_status(void);
extern void fn_1_862D4(s32, DB53CVec *);
extern u32 fn_1_864E8(s32);
extern u32 fn_1_1FC98(DB53CVec *, s32);
extern u8 *fn_1_8627C(s32);
extern void fn_1_DB9B0();

extern void u_gxutil_upload_some_mtx(u32, u32);
extern void fn_80072864(s32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80073778(void *, s32);
extern u32 fn_80036104(void *);
extern u16 GXGetTexObjHeight(void *);
extern u16 GXGetTexObjWidth(void *);
extern void *fn_800360D8(void *);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void fn_8007245C(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80073898(u32);

/* Pool primer: reproduces the TU's shared literal pool layout (0.0f). */
void fn_1_DB53C(void *arg0, f32 arg1) {
    DB53CVec mid;
    DB53CVec b;
    DB53CVec a;
    DB53CVec pos;
    DB53CItem *item;
    s32 count;
    void *ctx;
    s32 mode;
    u32 flags;
    void *tex;
    DB53CGroup *group;
    f32 dist;

    if (fn_1_58C4() >= 2) {
        return;
    }

    ctx = *(void **)((u8 *)arg0 + 8);
    group = (DB53CGroup *)lbl_1_data_2A7E0.unk_3C;
    item = group->items;
    tex = ((DB53CRoot *)lbl_1_bss_38458)->scene->holder->tex;

    lbl_8006DCA4();
    u_gxutil_upload_some_mtx(lbl_801A6D00, 0);
    fn_80072864(0);
    fn_800728A8(1, 4, 1, 0);
    fn_80073778(tex, 0);
    GXInitTexObj(tex, fn_800360D8(tex), GXGetTexObjWidth(tex), GXGetTexObjHeight(tex),
                 fn_80036104(tex), 0, 1, 0);
    fn_8007245C(0x2A00);
    fn_800747D0(4, 0, 1, 1, 0, 2, 2);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 4);
    fn_80072EDC(0, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074788(1);
    fn_80073898(0);

    for (count = group->count; count > 0; count--, item++) {
        b = item->obj->pos;
        a = item->pos;
        mid.x = 0.5f * (a.x + b.x);
        mid.y = 0.5f * (a.y + b.y);
        mid.z = 0.5f * (a.z + b.z);

        dist = fn_1_DC084(&mid);
        if (dist > 2000.0f) {
            if (dist > 2500.0f) {
                item->alpha = 0.0f;
                continue;
            }
            item->alpha = 1.0f - (dist - 2000.0f) / 500.0f;
        } else {
            item->alpha = 1.0f;
        }

        lbl_8006DCA4();
        if (fn_1_54E34(&mid, 650.0f) == 0 && fn_1_3F0C8() != 39) {
            continue;
        }

        flags = 0;
        mode = camera_get_mode();
        if (camera_get_flags() != 0 && lbl_1_data_3DC70 >= 0) {
            mode = lbl_1_data_3DC70;
        }
        lbl_1_data_3DC70 = mode;

        if (mode >= 0) {
            u8 *cam;

            fn_1_862D4(mode, &pos);
            if (fn_1_864E8(mode) & 0x800) {
                pos = lbl_1_bss_7ADB8[fn_1_5910()];
            } else if (fn_1_6F84() != 0) {
                if (camera_forward_status() & 0x80000000) {
                    lbl_1_bss_7ADB8[fn_1_5910()] = pos;
                } else {
                    pos = lbl_1_bss_7ADB8[fn_1_5910()];
                }
            } else {
                lbl_1_bss_7ADB8[fn_1_5910()] = pos;
            }
            flags = fn_1_1FC98(&pos, -1);
            cam = fn_1_8627C(mode);
            if (cam != NULL) {
                s32 idx = *(s32 *)(cam + 0xB8);
                if (idx >= 0) {
                    u8 *data = ((DB53CGlobal3BE0 *)&lbl_1_bss_3BE0)->table->entries[idx].data;
                    if (data != NULL) {
                        flags |= *(u32 *)(data + 0x38);
                    }
                }
            }
        }

        if (flags & item->obj->mask) {
            fn_1_DB9B0(item, ctx);
        } else if (fn_1_3F0C8() == 39) {
            fn_1_DB9B0(item, ctx);
        }
    }
}
/* fzgx:end fn_1_DB53C */

/* fzgx:begin fn_1_DB9B0 */
#include "psvec.h"
#include "rel/main_rel/bg_lig.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "dolphin/gx.h"

#ifndef GAME_MAIN_REL_BG_SAN_TYPES_H
#define GAME_MAIN_REL_BG_SAN_TYPES_H

#ifndef GAME_MAIN_REL_SHARED_TYPES_H
#define GAME_MAIN_REL_SHARED_TYPES_H

#endif  // GAME_MAIN_REL_SHARED_TYPES_H

#endif  // GAME_MAIN_REL_BG_SAN_TYPES_H

/* end game/main_rel/bg_san_types.h */
/* takes the handler (reads handler->unk_08); non-prototype so Handler.unk_04 accepts it */

extern u32 fn_1_58C4();




extern void fn_1_DB9B0();

extern f32 lbl_8006D188(s32);
extern f32 lbl_8006D534(Vec3 *, Vec3 *);
extern f64 __fabs(f64);
extern u32 lbl_8006D46C(f32);
extern void lbl_8006D5F0(Vec3 *, Vec3 *, f32);
extern void fn_1_681C(u8, void *);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);

s32 fn_1_5948();

typedef struct Sig_fn_1_DB9B0_DB53CVec {
    f32 x; f32 y; f32 z;
} Sig_fn_1_DB9B0_DB53CVec;
typedef struct Sig_fn_1_DB9B0_DB53CObj {
    u8 pad_0[0x4];
    u32 mask;
    u8 pad_8[0x4];
    Sig_fn_1_DB9B0_DB53CVec pos;
} Sig_fn_1_DB9B0_DB53CObj;

typedef struct DB9B0Point { Vec3 pos; f32 t; } DB9B0Point;
typedef struct DB9B0Trail { s16 head; u8 pad_2[6]; DB9B0Point a[128]; DB9B0Point b[128]; } DB9B0Trail;
typedef union DB9B0Pipe { f32 f; u8 b; } DB9B0Pipe;
// Graphics FIFO accesses are volatile hardware writes.
#define wgPipe (*(volatile DB9B0Pipe *)&GXWGFifo)
#define DB9B0_PIPE_F wgPipe.f

/* Prime the module's shared literal pool in retail order. */
static inline void DB9B0_cross(Vec3 *a, Vec3 *b, Vec3 *out) {
    f32 x = a->y * b->z;
    f32 y = a->z * b->x;
    f32 z = a->x * b->y;
    z -= ((a->y) * b->x);
    x -= a->z * b->y;
    y -= a->x * b->z;
    out->y = y;
    out->x = x;
    out->z = z;
}

static inline void DB9B0_position_yzx(f32 y, f32 z, f32 x) {
    wgPipe.f = x; wgPipe.f = y; wgPipe.f = z;
}
static inline void DB9B0_position(f64 x, f32 y, f32 z) {
    wgPipe.f = x; wgPipe.f = y; wgPipe.f = z;
}
static inline void DB9B0_color(u8 r, u8 g, u8 b, u8 a) {
    wgPipe.b = r; wgPipe.b = g; wgPipe.b = b; wgPipe.b = a;
}
static inline void DB9B0_tex(f32 s, f32 t) {
    wgPipe.f = s; wgPipe.f = t;
}

#pragma opt_lifetimes off
void fn_1_DB9B0(void *arg0) {
    s32 v3_r2;
    Sig_fn_1_DB9B0_DB53CObj *v1;
    u8 *v0;
    s32 v3;
    DB9B0Point *v52;
    f32 v20, v33, v49, v62;
    s32 v34, v63, v43;
    if (fn_1_58C4() < 2) {
        v0 = (u8 *)arg0 + 24;
        v1 = *(Sig_fn_1_DB9B0_DB53CObj **)arg0;
        if (*(s32 *)((u8 *)arg0 + 16) >= 128) {
            fn_8003462C(152, 0, 30);
            {
            Vec3 loc_8C, loc_80;
            s32 v19 = (*(s16 *)v0 + 1) % 128;
            Vec3 loc_74 = { 0.5f, 0.0f, 0.0f };
            Vec3 loc_68, loc_5C, loc_50;
            DB9B0Point *v25;
            s32 next;
            for (v3 = 0; v3 < 15; v3++) {
                v20 = v3 / 14.0f;
                fn_1_681C(fn_1_5910(), &loc_50);
                next = v19;
                v19 = (v19 + 8) % 128;
                v25 = (DB9B0Point *)(v0 + (next << 4) + 8);
                psvec_sub(&v25->pos, &loc_50, &loc_8C);
                psvec_sub(&v25->pos, &((DB9B0Trail *)v0)->a[v19].pos, &loc_80);
                DB9B0_cross(&loc_8C, &loc_80, &loc_68);
                if (0.0 != loc_68.x ||
                    0.0 != loc_68.y ||
                    0.0 != loc_68.z) {
                    lbl_8006D5F0(&loc_68, &loc_74, 0.5f);
                }
                psvec_scale(&loc_74, ((2.5 * *(f32 *)((u8 *)v1 + 32)) * (1.0 + v20)), &loc_5C);
                v33 = __fabs(lbl_8006D188(lbl_8006D46C(lbl_8006D534(&loc_8C, &loc_80))));
                v34 = (v33 * (255.0f * lbl_8006D188((32768.0f * v20))));
                if (*(s32 *)((u8 *)arg0 + 16) < 248) {
                    v34 = ((u8)v34 * ((*(s32 *)((u8 *)arg0 + 16) - 128) / 120.0f));
                }
                v34 = ((u8)v34 * *(f32 *)((u8 *)arg0 + 20));
                {
                f32 positionX = ((volatile DB9B0Point *)v25)->pos.x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
                f32 offsetX = loc_5C.x;
                DB9B0_position_yzx(v25->pos.y + loc_5C.y, v25->pos.z + loc_5C.z, positionX + offsetX);
                DB9B0_color(255, 255, 255, v34);
                DB9B0_tex(0.0f, v25->t);
                DB9B0_position_yzx(v25->pos.y - loc_5C.y, v25->pos.z - loc_5C.z, v25->pos.x - offsetX);
                DB9B0_color(255, 255, 255, v34);
                DB9B0_tex(1.0f, v25->t);
                }
            }
            }
            fn_8003462C(152, 0, 30);
            {
            Vec3 loc_44, loc_38;
            s32 v13 = (*(s16 *)v0 + 1) % 128;
            Vec3 loc_2C = { 0.5f, 0.0f, 0.0f };
            Vec3 loc_20, loc_14, loc_8;
            for (v3_r2 = 0; v3_r2 < 15; v3_r2++) {
                v49 = v3_r2 / 14.0f;
                fn_1_681C(fn_1_5910(), &loc_8);
                v43 = v13;
                v13 = (v13 + 8) % 128;
                v52 = (DB9B0Point *)((u32)v0 + (v43 << 4) + 2056);
                psvec_sub(&v52->pos, &loc_8, &loc_44);
                psvec_sub(&v52->pos, (v0 + (v13 << 4) + 2056), &loc_38);
                DB9B0_cross(&loc_44, &loc_38, &loc_20);
                if (0.0 != loc_20.x ||
                    0.0 != loc_20.y ||
                    0.0 != loc_20.z) {
                    lbl_8006D5F0(&loc_20, &loc_2C, 0.5f);
                }
                psvec_scale(&loc_2C, ((2.5 * *(f32 *)((u8 *)v1 + 32)) * (1.0 + v49)), &loc_14);
                v62 = __fabs(lbl_8006D188(lbl_8006D46C(lbl_8006D534(&loc_44, &loc_38))));
                v63 = (v62 * (255.0f * lbl_8006D188((32768.0f * v49))));
                if (*(s32 *)((u8 *)arg0 + 16) < 248) {
                    v63 = ((u8)v63 * ((*(s32 *)((u8 *)arg0 + 16) - 128) / 120.0f));
                }
                {
                    f32 baseX = ((volatile DB9B0Point *)v52)->pos.x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
                    f32 offsetX = loc_14.x;
                    f32 positionX = baseX + offsetX;
                    DB9B0_position(positionX, v52->pos.y + loc_14.y, v52->pos.z + loc_14.z);
                    DB9B0_color(255, 255, 255, v63);
                    DB9B0_tex(0.0f, v52->t);
                    DB9B0_position(v52->pos.x - offsetX, v52->pos.y - loc_14.y, v52->pos.z - loc_14.z);
                    DB9B0_color(255, 255, 255, v63);
                    DB9B0_tex(1.0f, v52->t);
                }
            }
            }
        }
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_DB9B0 */

/* fzgx:begin fn_1_DC084 */
extern u32 fn_1_58C4();
extern void fn_1_681C(u8, void *);
extern f32 lbl_8006D0B4(f32 value);

static inline f32 distance_squared(Vec3 *a, Vec3 *b) {
    f32 dx = a->x;
    f32 dy = a->y;
    f32 dz = a->z;

    dx -= b->x;
    dy -= b->y;
    dz -= b->z;

    dx = dx * dx;
    dx += dy * dy;
    dx += dz * dz;
    return dx;
}

f32 fn_1_DC084(Vec3 *pos) {
    Vec3 point;
    u32 i;
    f32 best;
    u32 count;

    count = fn_1_58C4();
    fn_1_681C(0, &point);
    best = lbl_8006D0B4(distance_squared(pos, &point));
    for (i = 1; i < count; i++) {
        fn_1_681C(i, &point);
        best = best < lbl_8006D0B4(distance_squared(pos, &point))
                   ? best
                   : lbl_8006D0B4(distance_squared(pos, &point));
    }
    return best;
}
/* fzgx:end fn_1_DC084 */

/* fzgx:begin fn_1_DC1B8 */
// fn_1_DC1B8: returns a constant.
int fn_1_DC1B8(void) {
    return 0;
}
/* fzgx:end fn_1_DC1B8 */

/* fzgx:begin fn_1_DC1C0 */
typedef struct {
    u8 pad_0[0x14];
    u32 unk_14;
    u8 pad_18[0x1008];
} BgSanEntry;

int fn_1_DC1C0(int arg0, int arg1) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;
    switch (arg0) {
    case 0:
        if ((s32)obj->unk_10 < 20) {
            BgSanEntry *entry = (BgSanEntry *)obj;
            entry += obj->unk_10;
            entry->unk_14 = arg1;
            obj->unk_10 = obj->unk_10 + 1;
        }
        break;
    default:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_DC1C0 */
