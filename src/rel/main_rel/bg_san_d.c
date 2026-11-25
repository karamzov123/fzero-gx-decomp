#include "types.h"
#include "game/vec3.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_san.h"

extern void fn_1_DC6FC(void *context);
extern void fn_1_DC5E8(Obj_1_data_2A7E0_At3C *, s32);
extern void fn_1_9AD54(void);
extern void fn_1_103F58(void *arg);
extern void fn_1_9AD88(void);
extern void fn_1_9A508(void);
extern s32 fn_1_5910();
extern void *fn_1_9D260();
extern void fn_1_103D28(void *arg0, u32 arg1, f32 arg2);
extern void fn_1_72648(void);
extern void fn_1_103090(void *);
extern void fn_1_1030A4(void *);
extern void *fn_1_54448(s32);
extern void *fn_1_548AC(s32);
extern void fn_1_DC764();
extern void fn_1_5489C(void *, void *);
extern void fn_1_103264(void *, void *);

/* fzgx:begin fn_1_DC204 */
// fn_1_DC204: empty in retail (single blr).
void fn_1_DC204(void) {
}
/* fzgx:end fn_1_DC204 */

/* fzgx:begin fn_1_DC208 */
#include "rel/main_rel/bg_san.h"

extern void fn_1_DC3A4();

void fn_1_DC208(void) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;

    obj->unk_0 = 0;
    fn_1_9A508();
    fn_1_103D28((u8 *)obj + 0x1588, 0x14, 0.5f);
    fn_1_DC3A4(obj);
}
/* fzgx:end fn_1_DC208 */

/* fzgx:begin fn_1_DC264 */
// fn_1_DC264: empty in retail (single blr).
void fn_1_DC264(void) {
}
/* fzgx:end fn_1_DC264 */

/* fzgx:begin fn_1_DC268 */
void fn_1_9AD54(void);

void fn_1_DCB10(void);
void fn_1_DC454();
s32 fn_1_58C4(void);
s32 fn_1_5948();
void fn_1_DC648();
void fn_1_627C(s32);

// Initializes scene data and updates each active scene entry.
void fn_1_DC268(void) {
    Obj_1_data_2A7E0_At3C *scene_data;
    s32 entry_index;
    s32 entry_count;

    scene_data = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    entry_count = (s32)fn_1_9D260();
    fn_1_DCB10();
    fn_1_DC454(scene_data, entry_count);

    entry_count = fn_1_58C4();
    for (entry_index = 0; entry_index < entry_count; entry_index++) {
        fn_1_5948(entry_index);
        fn_1_DC648(scene_data);
        fn_1_627C(entry_index);
    }
}
/* fzgx:end fn_1_DC268 */

/* fzgx:begin fn_1_DC2F8 */
#include "rel/main_rel/bg_san.h"

extern void fn_1_DC404();

void fn_1_DC2F8(void) {
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    fn_1_72648();
    fn_1_DC404(obj);
    fn_1_103F10((u8 *)obj + 0x1588);
}
/* fzgx:end fn_1_DC2F8 */

/* fzgx:begin fn_1_DC33C */
// Builds the active background scene and publishes it to the renderer.
void fn_1_DC33C(void) {
    Obj_1_data_2A7E0_At3C *background;
    s32 scene_data;

    background = lbl_1_data_2A7E0.unk_3C;
    scene_data = (s32)fn_1_9D260(&lbl_1_data_2A7E0);
    fn_1_103F58(&background->unk_1588);
    fn_1_DC6FC(background);
    fn_1_DC5E8(background, scene_data);
    fn_1_9AD88();
}
/* fzgx:end fn_1_DC33C */

/* fzgx:begin fn_1_DC3A0 */
// fn_1_DC3A0: empty in retail (single blr).
void fn_1_DC3A0(void) {
}
/* fzgx:end fn_1_DC3A0 */

/* fzgx:begin fn_1_DC3A4 */
typedef struct fn_1_DC3A4_Entry {
    u8 unk00[0x68];
    s32 initialized;
    u8 unk6c[0x40];
} fn_1_DC3A4_Entry;

typedef struct fn_1_DC3A4_Container {
    s32 count;
    fn_1_DC3A4_Entry entries[1];
} fn_1_DC3A4_Container;

// Marks each entry as initialized and processes all entries in the container.
void fn_1_DC3A4(fn_1_DC3A4_Container *container) {
    s32 count;
    fn_1_DC3A4_Entry *entry;

    count = container->count;
    entry = container->entries;
    while (count > 0) {
        entry->initialized = 1;
        fn_1_103090(entry);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_DC3A4 */

/* fzgx:begin fn_1_DC404 */
// Calls the cleanup routine for each entry in the container.
typedef struct fn_1_DC404_Entry {
    u8 data[0xac];
} fn_1_DC404_Entry;

typedef struct fn_1_DC404_Container {
    s32 count;
    fn_1_DC404_Entry entries[1];
} fn_1_DC404_Container;

void fn_1_DC404(fn_1_DC404_Container *container) {
    s32 count;
    fn_1_DC404_Entry *entry;

    count = container->count;
    entry = container->entries;
    while (count > 0) {
        fn_1_1030A4(entry);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_DC404 */

/* fzgx:begin fn_1_DC454 */
extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(s32);
extern void fn_1_1030D4(void *entry, void *arg);

typedef struct SanEntry {
    u8 unk00[0x08];
    u32 unk08;
    u8 unk0c[0x20];
    f32 value2c;
    f32 value30;
    f32 value34;
    u8 unk38[0x74];
} SanEntry;

typedef struct SanContainer {
    s32 count;
    SanEntry entries[1];
} SanContainer;

void fn_1_DC454(SanContainer *container, void *arg) {
    void *saved_arg;
    s32 count;
    SanEntry *entry;

    saved_arg = arg;
    entry = container->entries;
    count = container->count;
    while (count > 0) {
        if (((1) & ((entry->unk08 >> 28)))) {
            entry->value2c = 0.6499999761581421f;
            entry->value30 = 0.75f;
            entry->value34 = 1.0f;
        } else if ((entry->unk08 >> 29) & 1) {
            entry->value2c = 1.0f;
            entry->value30 = 0.0f;
            entry->value34 = 0.0f;
        } else {
            entry->value2c = __fabs(lbl_8006D188(
                (182.04444885253906f * lbl_801A66A0)));
            entry->value30 = __fabs(lbl_8006D188(
                ((((lbl_801A66A0) * (182.04444885253906f)) * (0.5)))));
            entry->value34 = __fabs(lbl_8006D188(
                (2.0 * (182.04444885253906f * lbl_801A66A0))));
        }
        fn_1_1030D4(entry, saved_arg);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_DC454 */

/* fzgx:begin fn_1_DC5E8 */
typedef struct fn_1_DC5E8_Entry {
    u8 unk_00[0xac];
} fn_1_DC5E8_Entry;

typedef struct fn_1_DC5E8_Container {
    s32 unk_00;
    fn_1_DC5E8_Entry unk_04[1];
} fn_1_DC5E8_Container;

// Apply the supplied argument to each active entry in the container.
void fn_1_DC5E8(Obj_1_data_2A7E0_At3C *container, s32 arg) {
    s32 count;
    fn_1_DC5E8_Entry *entry;
    fn_1_DC5E8_Container *data;

    data = (fn_1_DC5E8_Container *)container;
    entry = data->unk_04;
    count = data->unk_00;
    while (count > 0) {
        fn_1_103264(entry, (void *)arg);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_DC5E8 */

/* fzgx:begin fn_1_DC648 */
extern void fn_1_681C(u8, void *);
extern s32 fn_1_1FB80(u8 *, s32);

void fn_1_DC648(void *object) {
    u32 index;
    u32 direction;
    u32 offset;
    u8 local;
    s32 value;

    index = fn_1_5910();
    fn_1_681C(index, &local);
    direction = fn_1_1FB80(&local, 1);
    offset = (index << 1) + 0x2264;
    if ((direction & 1) != 0) {
        value = *(s16 *)((u8 *)object + offset);
        value += 1;
        *(s16 *)((u8 *)object + offset) = (value < 0) ? 0 : ((value > 30) ? 30 : value);
    } else {
        value = *(s16 *)((u8 *)object + offset);
        value -= 1;
        *(s16 *)((u8 *)object + offset) = (value < 0) ? 0 : ((value > 30) ? 30 : value);
    }
}
/* fzgx:end fn_1_DC648 */

/* fzgx:begin fn_1_DC6FC */
typedef struct Handler {
    u8 unk_00[4];
    void (*unk_04)(void);
    void *unk_08;
} Handler;

// Registers the callback and its context with a newly allocated handler.
void fn_1_DC6FC(void *context) {
    void *value;
    Handler *handler;

    value = fn_1_54448(0);
    handler = fn_1_548AC(12);
    if (handler != 0) {
        handler->unk_04 = fn_1_DC764;
        handler->unk_08 = context;
        fn_1_5489C(value, handler);
    }
}
/* fzgx:end fn_1_DC6FC */

/* fzgx:begin fn_1_DC764 */
#include "dolphin/hw_regs.h"

/* .rodata 0x66D0: the literals fn_1_DC208 and fn_1_DC454 pool before this function's own */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} SanVec;

typedef struct {
    u8 pad_0[0x2260];
    void *unk_2260;
    s16 unk_2264[4];
} SanObj;

typedef struct {
    u8 pad_0[0x108];
    f32 unk_108;
} SanProgress;


extern s16 camera_get_mode(void);
extern void fn_1_869B0(s32, SanVec *);
extern void fn_1_862A8(s32, SanVec *);
extern SanProgress *fn_1_8627C(s32);
extern void fn_1_681C(u8, void *);
extern void fn_1_6914(u8, SanVec *);
extern f32 lbl_8006D6FC(SanVec *, SanVec *);
extern f32 lbl_8006D188(s32);
extern u32 lbl_801A66A0;
extern void GXGetProjectionv(f32 *);
extern void C_MTXOrtho(f32 (*)[4], f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(f32 (*)[4], s32);
extern void lbl_8006D7F4(f32, f32, f32);
extern void fn_80072558(void);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_80074A60(s32, s32);
extern void lbl_8006D860(f32, f32, f32);
extern void fn_80072B7C(s32);
extern void fn_1_56000(u8, u8, u8);
extern void lbl_8006DB74(f32 (*)[4]);
extern void fn_1_560F0(s32, f32 (*)[4]);
extern void fn_1_556B8(void *);
extern void fn_80074A6C(void);
extern void fn_80072270(f32 *);

static inline void san_cross(const SanVec *a, const SanVec *b, SanVec *out) {
    f32 ax, ay, az, bx, bz, by;
    f32 x, y, z;

    ay = a->y;
    bz = b->z;
    az = a->z;
    bx = b->x;
    by = b->y;
    ax = a->x;
    x = ay * bz;
    y = az * bx;
    z = ax * by;
    x = x - az * by;
    y = y - ax * bz;
    z = z - ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

/* the viewport's own pad port (fn_1_5910) and its camera mode */
static inline s32 view_mode(s32 *port) {
    *port = fn_1_5910();
    return camera_get_mode();
}

#define LC_MTX ((f32 *)LC_BASE)

/* moves the locked-cache matrix A's translation by t times its first column */
static inline void lc_translate(f32 t) {
    f32 tx;
    f32 ty;
    f32 tz;

    tx = LC_MTX[0];
    tx = tx * t + LC_MTX[3];
    ty = LC_MTX[4];
    ty = ty * t + LC_MTX[7];
    tz = LC_MTX[8];
    tz = tz * t + LC_MTX[11];
    LC_MTX[3] = tx;
    LC_MTX[7] = ty;
    LC_MTX[11] = tz;
}

/* retail translates mtxA in place (each fmadds result in its column-0 load register), as in fn_1_44A74 */
#pragma opt_lifetimes off
void fn_1_DC764(Handler *handler) {
    SanObj *obj = handler->unk_08;
    void *model = obj->unk_2260;
    s32 port;
    s32 mode;
    SanVec from;
    SanVec to;
    SanVec dir;
    SanVec fwd;
    SanVec up;
    SanVec side;
    f32 proj[7];
    f32 ortho[4][4];
    f32 mtx[3][4];
    f32 lateral;
    f32 d;
    f32 d2;
    f32 size;
    f32 scale;
    f32 base;
    f32 wave;
    f32 x;
    f32 t;
    s8 sign;

    mode = view_mode(&port);
    if (mode == -1) {
        return;
    }
    if (obj->unk_2264[port] <= 0) {
        return;
    }
    fn_1_869B0(mode, &fwd);
    fn_1_862A8(mode, &up);
    san_cross(&fwd, &up, &side);
    lateral = fn_1_8627C(mode)->unk_108;
    fn_1_681C(port, &from);
    fn_1_6914(port, &to);
    dir.x = to.x - from.x;
    dir.y = to.y - from.y;
    dir.z = to.z - from.z;
    d = lbl_8006D6FC(&fwd, &dir);
    sign = (d > 0.0f) ? 1 : -1;
    d2 = lbl_8006D6FC(&side, &dir);
    wave = 0.85f + (f32)(0.15f * lbl_8006D188(65536.0f * (lbl_801A66A0 % 60) / 60.0f));
    base = 0.0f;
    size = base + (f64)(wave / 2.0f * __fabs(d));
    scale = size * obj->unk_2264[port] / 30.0f;
    GXGetProjectionv(proj);
    C_MTXOrtho(ortho, 5.0f, -5.0f, -5.0f, 5.0f, 0.1f, 90000.0f);
    fn_800737E4(ortho, 1);
    lbl_8006D7F4(0.0f, 0.0f, -0.1f);
    fn_80072558();
    fn_1_5621C(scale, scale, scale, 1.0f);
    fn_80074A60(1, 1);
    x = -(sign * (d2 + lateral / 60.0f));
    lbl_8006D860(1.0 / (1.0 + (f64)(3.0 * __fabs(x))), 1.0f, 1.0f);
    t = (x > 0.0f) ? 0.0f : -(3.0f * x);
    lc_translate(t);
    fn_80072B7C(0);
    fn_1_56000(1, 3, 0);
    lbl_8006DB74(mtx);
    fn_1_560F0(0, mtx);
    fn_1_556B8(model);
    fn_80072B7C(1);
    fn_1_56000(1, 3, 1);
    fn_1_5621C(1.0f, 1.0f, 1.0f, 1.0f);
    fn_80074A6C();
    fn_80072270(proj);
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_DC764 */

/* fzgx:begin fn_1_DCB10 */
#include "rel/main_rel/bg_lig.h"
#include "rel/main_rel/bg_san.h"

typedef struct fn_1_DCB10_Entry {
    Vec3 position;
    u8 pad_0c[0x14];
    u32 flags;
} fn_1_DCB10_Entry;

typedef struct fn_1_DCB10_Container {
    u8 pad_00[0xa4];
    s32 count;
    fn_1_DCB10_Entry *entries;
} fn_1_DCB10_Container;

void fn_1_DCB10(void) {
    fn_1_DCB10_Container **global;
    s32 i;
    fn_1_DCB10_Entry *entry;

    global = (fn_1_DCB10_Container **)&lbl_1_bss_3BE0;
    i = 0;
    entry = (*global)->entries;
    while (i < (*global)->count) {
        if (entry->flags & 2) {
            fn_1_D6C10(&entry->position, 6.0f);
        }
        i++;
        entry++;
    }
}
/* fzgx:end fn_1_DCB10 */

/* fzgx:begin fn_1_DCB9C */
#include "rel/main_rel/bg_san.h"

s32 fn_1_DCB9C(s32 value, u32 *data) {
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    switch (value) {
    case 0:
        obj->unk_1584 = *data;
        break;
    case 1:
        obj->unk_225C = *data;
        break;
    case 2:
        obj->unk_2260 = *data;
        break;
    }
    return 1;
}
/* fzgx:end fn_1_DCB9C */
