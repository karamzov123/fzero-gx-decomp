#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/shadowmap.h"

extern void fn_800746A8(u32, u32);
extern void fn_8007245C(u32);
extern void fn_800728A8(u32, u32, u32, u32);
extern void fn_800720B0(u32);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80072EDC(u32, u32);
extern void fn_80073C6C(u32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80073898(u32);
extern void fn_80074788(u32);

extern void *lbl_801A6410;
extern void fn_1_46B4(void *, void *, unsigned char *, int);
extern f32 lbl_1_rodata_28B4[16];
extern void *GXGetTexBufferSize(int, int, int, int, int);
extern void *fn_1_45D0(void *, int, char *, int);
extern void GXInitTexObj(void *, void *, int, int, int, int, int, int);
extern void GXInitTexObjLOD(void *, int, int, f32, f32, f32, int, int, int);
extern void fn_80073778(void *, u32);
extern void fn_800724C8(void);
extern void fn_800745A4(u32, s32, s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern u32 fn_800371F8(u32, void *);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80072864(u32);
extern void GXSetAlphaCompare(u32, u32, u32, u32, u32);
extern void fn_80074918(u8, s32, u8);
extern void lbl_8006D758(void);
extern void GXLoadPosMtxImm(void *arg0, int arg1);
extern void fn_8003462C(u32 size, u32 heap, u32 alignment);
extern void *lbl_801A6D00;
extern f32 lbl_1_rodata_28F4[23];
extern void fn_1_57DC0(void);
extern void *fn_1_548AC(u32 size);
extern void *fn_1_5448C(void *arg);
extern void fn_1_57E84(void);
extern void fn_1_5489C(void *arg0, void *arg1);
extern void lbl_8006DB74(void *arg);
extern void fn_80008BA8(void *dst, void *src, u32 size);

/* fzgx:begin fn_1_5672C */
#include "types.h"

typedef struct fn_1_5672C_ShadowMapEntry {
    int field_00;
    int field_04;
    f32 field_08;
    char unk_0c[0x30];
    void *field_3c;
    void *field_40;
    int field_44;
    int field_48;
} fn_1_5672C_ShadowMapEntry;

void fn_1_5672C(fn_1_5672C_ShadowMapEntry *entries, int count) {
    void *buffer;
    int i;
    fn_1_5672C_ShadowMapEntry *entry;
    f32 zero = lbl_1_rodata_28B4[0];

    entry = entries;
    i = 0;
    while (i < count) {
        buffer = GXGetTexBufferSize(0x40, 0x40, 0, 0, 0);
        entry->field_00 = 0;
        entry->field_04 = 0;
        entry->field_08 = zero;
        entry->field_3c = fn_1_45D0(lbl_801A6410, 0x20, (*(char (*)[12])&lbl_1_data_1C660), 0x67);
        entry->field_40 = fn_1_45D0(lbl_801A6410, (int)buffer, (*(char (*)[12])&lbl_1_data_1C660), 0x68);
        entry->field_44 = 0;
        entry->field_48 = 0;
        GXInitTexObj(entry->field_3c, entry->field_40, 0x40, 0x40, 0, 0, 0, 0);
        GXInitTexObjLOD(entry->field_3c, 1, 1, lbl_1_rodata_28B4[0],
                        lbl_1_rodata_28B4[0], lbl_1_rodata_28B4[0], 0, 0, 0);
        i++;
        entry++;
    }
}
/* fzgx:end fn_1_5672C */

/* fzgx:begin fn_1_56858 */
typedef struct fn_1_56858_ShadowMapEntry {
    char pad_00[0x3c];
    void *unk_3c;
    void *unk_40;
    char pad_44[0x08];
} fn_1_56858_ShadowMapEntry;

// Register each entry's resources, then clear it for reuse.
void fn_1_56858(fn_1_56858_ShadowMapEntry *entries, u32 count) {
    u32 index;
    fn_1_56858_ShadowMapEntry *current_entry;

    for (index = 0, current_entry = entries; index < count;
         index++, current_entry++) {
        fn_1_46B4(lbl_801A6410, current_entry->unk_3c, lbl_1_data_1C660, 0x87);
        fn_1_46B4(lbl_801A6410, current_entry->unk_40, lbl_1_data_1C660, 0x88);
        memset(current_entry, 0, 0x4c);
    }
}
/* fzgx:end fn_1_56858 */

/* fzgx:begin fn_1_568EC */
typedef struct ShadowMap {
    u8 pad44[0x44];
    u32 field44;
    u32 field48;
} ShadowMap;

void fn_1_568EC(ShadowMap *map, u32 value0, u32 value1) {
    map->field48 = value0;
    map->field44 = value1;
}
/* fzgx:end fn_1_568EC */

/* fzgx:begin fn_1_568F8 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

struct fn_1_568F8_lbl_1_rodata_28B0 {
    u32 unk_0;
    f32 unk_4;
    Vec3f v1;
    Vec3f v2;
    Vec3f v3;
    Vec3f v4;
    u32 unk_38;
    u32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
};
extern struct fn_1_568F8_lbl_1_rodata_28B0 lbl_1_rodata_28B0;

typedef struct Unk48 {
    u8 pad[0x14C];
    u8 unk_14C[0x70];
    Vec3f pos;
} Unk48;

typedef struct Unk44 {
    u8 pad[0x38C];
    u8 field_38C;
    u8 pad38D[0x3B8 - 0x38D];
    s16 field_3B8;
} Unk44;

typedef struct LocC {
    u32 unk_0;
    u32 unk_4;
} LocC;

typedef struct ShadowMap {
    u32 unk_0;
    u32 unk_4;
    u8 pad8[0x38];
    void *unk_40;
    Unk44 *unk_44;
    Unk48 *unk_48;
} ShadowMap;

extern f64 __fabs(f64);
extern void fn_80038F10(void *);
extern void GXGetScissor(u32 *, u32 *, u32 *, u32 *);
extern void GXGetProjectionv(void *);
extern void fn_8006F1F0(void *, void *, void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006D89C(f32, f32);
extern void lbl_8006E0D8(f32, f32, f32);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_80074188(u32, u32, u32, u32);
extern void fn_80074300(u32, u32, u32, u32);
extern void fn_80074438(u32, u32, u32, u32);
extern void fn_800744F8(void *, u32);
extern void fn_8003526C(void *, s32);
extern void fn_80007C2C(void);
extern void lbl_8006DC6C(void *);
extern void lbl_8006DFD8(void *);
extern void lbl_8006DBAC(void *);
extern void fn_80072558(void);
extern void fn_80074788(u32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_800725DC(void *);
extern void fn_80072614(void *);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_80073C6C(u32);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80072EDC(u32, u32);
extern void fn_800728A8(u32, u32, u32, u32);
extern void fn_80074918(u32, u32, u32);
extern int fn_1_56724(void);
extern void fn_80077BAC(void *);
extern void fn_1_870BC(void *, s32, void *, s32, s32, f32);
extern void GXInvalidateTexAll(void);
extern void fn_80072270(void *);

void fn_1_568F8(ShadowMap *map) {
    struct fn_1_568F8_lbl_1_rodata_28B0 *p_rodata;
    Unk48 *unk_48;
    Unk44 *unk_44;
    s32 flag;
    f32 scale;
    s32 i;
    Vec3f *vec;
    f32 ax, ay, az;
    f32 loc_C8[16];
    f32 loc_98[12];
    f32 loc_80[6];
    f32 loc_64[7];
    Vec3f loc_58;
    Vec3f loc_4C;
    Vec3f loc_40;
    Vec3f loc_34;
    Vec3f loc_28;
    u32 loc_24;
    u32 loc_20;
    u32 loc_1C;
    u32 loc_18;
    u32 loc_14;
    volatile u32 loc_10; /* volatile: preserves stack spill slot across calls to match retail */
    u32 loc_C;
    u32 loc_8;

    p_rodata = (struct fn_1_568F8_lbl_1_rodata_28B0 *)&lbl_1_rodata_28B0;
    unk_48 = map->unk_48;
    flag = (map->unk_0 >> 1) & 1;

    if (flag != 0 || (flag == 0 && (map->unk_4 & 1) == 0)) {
        goto do_work; /* goto: matches retail branch layout and early return */
    }
    return;

do_work:
    map->unk_4 &= ~3;
    if (flag) {
        map->unk_4 |= 2;
    } else {
        map->unk_4 |= 1;
    }

    fn_80038F10(loc_80);
    GXGetScissor(&loc_24, &loc_20, &loc_1C, &loc_18);
    GXGetProjectionv(loc_64);

    if (flag) {
        ax = __fabs(unk_48->pos.x);
        ay = __fabs(unk_48->pos.y);
        az = __fabs(unk_48->pos.z);
        if (ax <= ay && ax <= az) {
            loc_4C = p_rodata->v1;
            vec = &loc_4C;
        } else if (ay <= az && ay <= ax) {
            loc_40 = p_rodata->v2;
            vec = &loc_40;
        } else {
            loc_34 = p_rodata->v3;
            vec = &loc_34;
        }
        scale = p_rodata->unk_40;
        vec->x = -vec->x;
        vec->y = -vec->y;
        vec->z = -vec->z;
        psvec_scale(&unk_48->pos, scale, &loc_58);
        loc_28 = p_rodata->v4;
        fn_8006F1F0(&loc_58, vec, &loc_28);
        lbl_8006DB74(loc_98);
    } else {
        lbl_8006D89C(p_rodata->unk_44, p_rodata->unk_4);
        lbl_8006E0D8(p_rodata->unk_4, p_rodata->unk_48, p_rodata->unk_4);
        lbl_8006DB74(loc_98);
    }

    {
        f32 v3 = p_rodata->unk_4C;
        f32 v13 = p_rodata->unk_40;
        C_MTXOrtho(loc_C8, v3, v13, v13, v3, p_rodata->unk_4, p_rodata->unk_50);
    }
    fn_800737E4(loc_C8, 1);
    fn_80038EEC(p_rodata->unk_4, p_rodata->unk_4, p_rodata->unk_54, p_rodata->unk_54, p_rodata->unk_4, p_rodata->unk_44);
    fn_80074188(0, 0, 128, 128);
    fn_80074300(0, 0, 128, 128);
    fn_80074438(64, 64, 0, 1);
    loc_14 = p_rodata->unk_38;
    fn_800744F8(&loc_14, 0x00FFFFFF);
    fn_8003526C(map->unk_40, 1);
    fn_80007C2C();

    if (flag) {
        lbl_8006DC6C((u8 *)unk_48 + 0x14C);
        lbl_8006DFD8(loc_98);
    } else {
        lbl_8006DBAC(loc_98);
    }

    fn_80072558();
    loc_10 = p_rodata->unk_3C;
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073898(0);
    loc_8 = loc_10;
    fn_800725DC(&loc_8);
    loc_C = p_rodata->unk_0;
    fn_80072614(&loc_C);
    fn_800747D0(4, 0, 0, 0, 1, 2, 1);
    fn_80073C6C(0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072EDC(0, 4);
    fn_800728A8(1, 1, 0, 0);
    fn_80074918(1, 3, 1);
    fn_80077BAC((void *)fn_1_56724);

    unk_44 = map->unk_44;
    for (i = 0; i < 6; i++) {
        if (i != 5 && (unk_44->field_38C & (1 << i))) {
            fn_1_870BC(unk_44, (s8)i, unk_44, 0, unk_44->field_3B8 & 0xFF, p_rodata->unk_44);
            break;
        }
    }

    fn_80077BAC(0);
    fn_8003526C(map->unk_40, 1);
    GXInvalidateTexAll();
    fn_80038EEC(loc_80[0], loc_80[1], loc_80[2], loc_80[3], loc_80[4], loc_80[5]);
    fn_80074188(loc_24, loc_20, loc_1C, loc_18);
    fn_80072270(loc_64);
}
/* fzgx:end fn_1_568F8 */

/* fzgx:begin fn_1_56D4C */
typedef signed long s32;

typedef unsigned char u8;

typedef unsigned long u32;

typedef float f32;
typedef double f64;

typedef struct fn_1_568F8_Color {
u8 r;
u8 g;
u8 b;
u8 a;
} fn_1_568F8_Color;
typedef struct fn_1_568F8_Vec3 {
f32 x;
f32 y;
f32 z;
} fn_1_568F8_Vec3;
typedef struct fn_1_568F8_Pool {
fn_1_568F8_Color tev_color; /* 0x00 */
f32 zero; /* 0x04 */
fn_1_568F8_Vec3 axis_x; /* 0x08 */
fn_1_568F8_Vec3 axis_y; /* 0x14 */
fn_1_568F8_Vec3 axis_z; /* 0x20 */
fn_1_568F8_Vec3 up; /* 0x2c */
fn_1_568F8_Color clear_color; /* 0x38 */
fn_1_568F8_Color chan_color; /* 0x3c */
f32 neg_three; /* 0x40 */
f32 one; /* 0x44 */
f32 twenty; /* 0x48 */
f32 three; /* 0x4c */
f32 hundred; /* 0x50 */
f32 size; /* 0x54 */
} fn_1_568F8_Pool;


typedef struct fn_1_56D4C_Vec3 {
f32 x;
f32 y;
f32 z;
} fn_1_56D4C_Vec3;
typedef struct fn_1_56D4C_Pool {
u8 pad_0[0x4];
f32 zero; /* 0x04 */
u8 pad_8[0x3c];
f32 one; /* 0x44 */
f32 twenty; /* 0x48 */
u8 pad_4c[0xc];
fn_1_56D4C_Vec3 axis_x; /* 0x58 */
fn_1_56D4C_Vec3 axis_y; /* 0x64 */
fn_1_56D4C_Vec3 axis_z; /* 0x70 */
fn_1_56D4C_Vec3 trans; /* 0x7c */
f32 six; /* 0x88 */
f32 fade; /* 0x8c */
} fn_1_56D4C_Pool;
typedef struct fn_1_56D4C_Target {
u32 flags;
u8 pad_4[0x148];
f32 mtx[3][4]; /* 0x14c */
u8 pad_17c[0x40];
fn_1_56D4C_Vec3 dir; /* 0x1bc */
f32 dist; /* 0x1c8 */
u8 pad_1cc[0x8];
fn_1_56D4C_Vec3 pos; /* 0x1d4 */
} fn_1_56D4C_Target;
typedef struct fn_1_56D4C_Entry {
u32 flags;
u32 unk_4;
f32 alpha; /* 0x08 */
f32 mtx[3][4]; /* 0x0c */
u8 pad_3c[0xc];
fn_1_56D4C_Target *target; /* 0x48 */
} fn_1_56D4C_Entry;

static const u32 fzgx_pool_rodata_lbl_1_rodata_28B0[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_28B4[16] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x3F800000, 0x0, 0x0, 0x0, 0x3F800000, 0x0, 0x0,
    0x0, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0xFF00FF, 0xC0400000  /* fzgx-allow: A1 retail data bytes */
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_28F4[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F800000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_28B0_48[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x41A00000, 0x40400000, 0x42C80000, 0x43000000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_28B0_58[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F800000, 0x0, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_28B0_64[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x3F800000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_28B0_70[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x3F800000
};
static inline fn_1_56D4C_Vec3 fn_1_56D4C_translation(void) {
    fn_1_56D4C_Vec3 v = { 0.0f, 0.0f, 0.0f };
    return v;
}
static const u32 fzgx_pool_rodata_lbl_1_rodata_28B0_88[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40C00000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_28B0_8C[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3D4CCCCD, 0x40186666, 0x66666666, 0x43300000, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_rodata_28B0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_28B4;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_28F4;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0_48;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0_58;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0_64;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0_70;
    { fn_1_56D4C_Vec3 v = fn_1_56D4C_translation(); s = *(u8 *)&v; }
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0_88;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0_8C;
}
#pragma section code_type ".text"

extern f64 __fabs(f64);
extern s32 fn_1_66B8(s32, f32);
extern void lbl_8006DBAC(void *);
extern f32 lbl_8006D668(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DF44(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DB30(void);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006DFC4(void *);
extern void *lbl_801A6D00;
static inline void fn_1_56D4C_cross_values(f32 bz, f32 by, f32 bx, f32 ay, f32 az, f32 ax, fn_1_56D4C_Vec3 *out) {
f32 x;
f32 y;
f32 z;
z = ax * by;
y = az * bx;
x = ay * bz;
z -= ay * bx;
y -= ax * bz;
x -= az * by;
out->z = z;
out->y = y;
out->x = x;
}
#define fn_1_56D4C_cross(a, b, out) fn_1_56D4C_cross_values((b)->z, (b)->y, (b)->x, (a)->y, (a)->z, (a)->x, out)
static inline void fn_1_56D4C_cross_simple(fn_1_56D4C_Vec3 *a, fn_1_56D4C_Vec3 *b, fn_1_56D4C_Vec3 *out) {
f32 ax;
f32 ay;
f32 az;
f32 bx;
f32 by;
f32 bz;
f32 x;
f32 y;
f32 z;
ay = a->y;
az = a->z;
ax = a->x;
bx = b->x;
bz = b->z;
by = b->y;
x = ay * bz;
y = az * bx;
z = ax * by;
x -= az * by;
y -= ax * bz;
z -= ay * bx;
out->x = x;
out->y = y;
out->z = z;
}
static inline void fn_1_56D4C_cross_second(fn_1_56D4C_Vec3 *a, fn_1_56D4C_Vec3 *b, fn_1_56D4C_Vec3 *out) {
f32 ax;
f32 ay;
f32 az;
f32 bx;
f32 by;
f32 bz;
f32 x;
f32 y;
f32 z;
ay = a->y;
bz = b->z;
az = a->z;
bx = b->x;
by = b->y;
ax = a->x;
x = ay * bz;
y = az * bx;
z = ax * by;
x -= az * by;
y -= ax * bz;
z -= ay * bx;
out->x = x;
out->y = y;
out->z = z;
}
static inline void fn_1_56D4C_negate(fn_1_56D4C_Vec3 *src, fn_1_56D4C_Vec3 *dst) {
dst->x = -src->x;
dst->y = -src->y;
dst->z = -src->z;
}
/* locked-cache current matrix (translation column) */
void fn_1_56D4C(fn_1_56D4C_Entry *entry) {

f32 z;
f32 y;
f32 x;
fn_1_56D4C_Target *target;
    void * lab_t0;
f32 (*m)[4];
f32 dist;
f32 ax;
f32 ay;
f32 az;
f32 alpha;
fn_1_56D4C_Vec3 *axis;
fn_1_56D4C_Vec3 c;
f32 a[3];
f32 b[3];
f32 e[3];
fn_1_56D4C_Vec3 f;
f32 d[3];
fn_1_56D4C_Vec3 axis_x;
fn_1_56D4C_Vec3 axis_y;
fn_1_56D4C_Vec3 axis_z;
target = entry->target;
entry->flags &= ~3;
if (target->flags & 0x8000) {
dist = (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0_48)));
} else {
dist = target->dist;
}
lbl_8006DBAC(target->mtx);
if (dist <= (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28B4))) || !fn_1_66B8(0, (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0_88))))) {
entry->flags &= ~4;
return;
}
entry->flags |= 1;
ax = __fabs(target->dir.x);
ay = __fabs(target->dir.y);
az = __fabs(target->dir.z);
if (ax <= ay && ax <= az) {
axis_x = (*(fn_1_56D4C_Vec3 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0_58)));
axis = &axis_x;
} else if (ay <= az && ay <= ax) {
axis_y = (*(fn_1_56D4C_Vec3 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0_64)));
axis = &axis_y;
} else {
axis_z = (*(fn_1_56D4C_Vec3 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0_70)));
axis = &axis_z;
}
if ((entry->flags >> 1) & 1) {
*(fn_1_56D4C_Vec3 *)a = *axis;
*(fn_1_56D4C_Vec3 *)b = target->dir;
fn_1_56D4C_cross ((fn_1_56D4C_Vec3 *)a, (fn_1_56D4C_Vec3 *)b, &c);
fn_1_56D4C_cross ((fn_1_56D4C_Vec3 *)b, &c, (fn_1_56D4C_Vec3 *)a);
fn_1_56D4C_cross (&c, (fn_1_56D4C_Vec3 *)a, (fn_1_56D4C_Vec3 *)b);
lab_t0 = &c;
lbl_8006D668(lab_t0);
lab_t0 = (fn_1_56D4C_Vec3 *)a;
lbl_8006D668(lab_t0);
lab_t0 = (fn_1_56D4C_Vec3 *)b;
lbl_8006D668(lab_t0);
entry->mtx[0][0] = c.x;
entry->mtx[0][1] = a[0];
entry->mtx[0][2] = b[0];
entry->mtx[0][3] = target->pos.x;
entry->mtx[1][0] = c.y;
entry->mtx[1][1] = a[1];
entry->mtx[1][2] = b[1];
entry->mtx[1][3] = target->pos.y;
entry->mtx[2][0] = c.z;
entry->mtx[2][1] = a[2];
entry->mtx[2][2] = b[2];
entry->mtx[2][3] = target->pos.z;
} else {
fn_1_56D4C_negate(&target->dir, (fn_1_56D4C_Vec3 *)d);
fn_1_56D4C_cross_simple (axis, (fn_1_56D4C_Vec3 *)d, (fn_1_56D4C_Vec3 *)e);
lab_t0 = (fn_1_56D4C_Vec3 *)e;
lbl_8006D668(lab_t0);
fn_1_56D4C_cross_second ((fn_1_56D4C_Vec3 *)d, (fn_1_56D4C_Vec3 *)e, &f);
lab_t0 = &f;
lbl_8006D668(lab_t0);
{
fn_1_56D4C_Vec3 trans = fn_1_56D4C_translation();
m = lbl_801A6D00;
m[0][0] = e[0];
m[0][1] = f.x;
m[0][2] = d[0];
m[0][3] = trans.x;
m[1][0] = e[1];
m[1][1] = f.y;
m[1][2] = d[1];
m[1][3] = trans.y;
m[2][0] = e[2];
m[2][1] = f.z;
m[2][2] = d[2];
m[2][3] = trans.z;
}
lbl_8006DAEC();
lbl_8006DF44();
lbl_8006DB74((u8 *)lbl_801A6D00 + 0x60);
lbl_8006DB30();
lbl_8006E15C((*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28F4))), (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28F4))), (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28B4))));
lbl_8006DFC4((u8 *)lbl_801A6D00 + 0x60);
lbl_8006DFC4(target->mtx);
x = *(volatile f32 *)&target->pos.x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
y = target->pos.y;
z = target->pos.z;
((f32 (*)[4])0xE0000000) [0][3] = x;
((f32 (*)[4])0xE0000000) [1][3] = y;
((f32 (*)[4])0xE0000000) [2][3] = z;
lbl_8006DB74(entry->mtx);
}
alpha = (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28B0_8C))) * dist;
entry->flags |= 4;
if (alpha < (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28B4)))) {
alpha = (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28B4)));
} else if (alpha > (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28F4)))) {
alpha = (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28F4)));
}
entry->alpha = alpha;
if (target->flags & 0x8000) {
entry->alpha = (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_28F4)));
}
}
/* fzgx:end fn_1_56D4C */

/* fzgx:begin fn_1_571E8 */
#include "types.h"

typedef union fn_1_571E8_GXFifo {
    volatile f32 f32; /* write-gather FIFO: writes have side effects */
    volatile u8 u8;   /* write-gather FIFO: writes have side effects */
} fn_1_571E8_GXFifo;

enum { GX_FIFO_ADDR = 0xCC008000 }; /* fzgx-allow: A1 GX write-gather FIFO hardware address */
#define GXWGFifo (*(fn_1_571E8_GXFifo *)GX_FIFO_ADDR)

typedef struct fn_1_571E8_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_571E8_Vec3;

typedef struct fn_1_571E8_Arg0 {
    u8 pad_0[8];
    fn_1_571E8_Vec3 p0;
    fn_1_571E8_Vec3 p1;
    fn_1_571E8_Vec3 p2;
    fn_1_571E8_Vec3 p3;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
} fn_1_571E8_Arg0;

void fn_1_571E8(fn_1_571E8_Arg0 *arg0) {
    f32 x;
    f32 y;
    f32 z;
    f32 x2;
    f32 y2;
    f32 z2;
    f32 x3;
    f32 y3;
    f32 z3;
    f32 x4;
    f32 y4;
    f32 z4;
    u32 loc_8;

    fn_80073778((void *)arg0->unk_38, 0);
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3C, 0, 0x7D);
    fn_800734A8(0, 0, 0, 0xFF);
    fn_80072AB0(0, 0, 0);
    loc_8 = arg0->unk_3C;
    fn_800371F8(1, &loc_8);
    fn_80072C24(0, 0xF, 0xF, 0xF, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 4);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800720B0(0);
    fn_80072864(2);
    GXSetAlphaCompare(4, 0x4F, 0, 3, 0xFF);
    fn_800728A8(1, 7, 6, 0);
    fn_80074918(1, arg0->unk_40, 0);
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8003462C(0x80, 0, 4);

    z = arg0->p0.z;
    y = arg0->p0.y;
    x = arg0->p0.x;
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
    GXWGFifo.f32 = lbl_1_rodata_28B4[0];
    GXWGFifo.f32 = lbl_1_rodata_28B4[0];

    z2 = arg0->p1.z;
    y2 = arg0->p1.y;
    x2 = arg0->p1.x;
    GXWGFifo.f32 = x2;
    GXWGFifo.f32 = y2;
    GXWGFifo.f32 = z2;
    GXWGFifo.f32 = lbl_1_rodata_28F4[0];
    GXWGFifo.f32 = lbl_1_rodata_28B4[0];

    z3 = arg0->p2.z;
    y3 = arg0->p2.y;
    x3 = arg0->p2.x;
    GXWGFifo.f32 = x3;
    GXWGFifo.f32 = y3;
    GXWGFifo.f32 = z3;
    GXWGFifo.f32 = lbl_1_rodata_28F4[0];
    GXWGFifo.f32 = lbl_1_rodata_28F4[0];

    z4 = arg0->p3.z;
    y4 = arg0->p3.y;
    x4 = arg0->p3.x;
    GXWGFifo.f32 = x4;
    GXWGFifo.f32 = y4;
    GXWGFifo.f32 = z4;
    GXWGFifo.f32 = lbl_1_rodata_28B4[0];
    GXWGFifo.f32 = lbl_1_rodata_28F4[0];

    fn_80074918(1, 3, 1);
    GXSetAlphaCompare(7, 0, 0, 7, 0);
}
/* fzgx:end fn_1_571E8 */

/* fzgx:begin fn_1_5745C noprologue */
#include "types.h"
#include "psvec.h"

extern const f32 lbl_1_rodata_28B0;
#define SHADOW_ZERO (*(const f32 *)((const u8 *)&lbl_1_rodata_28B0 + 4))
#define SHADOW_SIZE (*(const f32 *)((const u8 *)&lbl_1_rodata_28B0 + 0x4c))
#define SHADOW_DEPTH (*(const f64 *)((const u8 *)&lbl_1_rodata_28B0 + 0x90))
#define SHADOW_BIAS (*(const f64 *)((const u8 *)&lbl_1_rodata_28B0 + 0x98))

typedef struct ShadowQuadVec3 {
    f32 x;
    f32 y;
    f32 z;
} ShadowQuadVec3;

typedef struct ShadowQuad {
    void *next;
    void (*draw)(struct ShadowQuad *);
    ShadowQuadVec3 p0;
    ShadowQuadVec3 p1;
    ShadowQuadVec3 p2;
    ShadowQuadVec3 p3;
    u32 unk_38;
    u8 color[4];
    u32 mode;
} ShadowQuad;

typedef struct ShadowSrc {
    u32 flags;
    u32 mask;
    f32 alpha;
    u8 mtx[0x0C];
    f32 x;
    u8 pad_1C[0x0C];
    f32 y;
    u8 pad_2C[0x0C];
    f32 z;
    u32 unk_3C;
} ShadowSrc;

typedef struct ShadowCam {
    u8 pad_0[0xD4];
    ShadowQuadVec3 pos;
} ShadowCam;

typedef struct ShadowCtx {
    u8 pad_0[0x2C];
    f32 scale;
    u8 pad_30[0x30];
    u8 mtx[0x30];
} ShadowCtx;

extern ShadowCam *lbl_801A66CC;
extern ShadowCtx *lbl_801A6D00;

extern void *fn_1_548AC(u32);
extern s32 fn_1_54E34(void *, f32);
extern void *fn_1_54384(f32);
extern void fn_1_571E8(ShadowQuad *);
extern void fn_1_5489C(void **, void **);
extern void lbl_8006DCA4(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006E1D8(void *, f32, f32, f32);

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[1] = {0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; /* fzgx-allow: S2 pool primer sink */
    s = 0.0f;
}
static const unsigned long fzgx_pool_table3[14] = {0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00FF00FF}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; /* fzgx-allow: S2 pool primer sink */
    s = -3.0f;
    s = 1.0f;
    s = 20.0f;
    s = 3.0f;
    s = 100.0f;
    s = 128.0f;
}
static const unsigned long fzgx_pool_table5[12] = {0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d; /* fzgx-allow: S2 pool primer sinks */
    s = 6.0f;
    s = 0.05000000074505806f;
    d = 6.1;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

/* The locked cache holds the transform; the active camera is shared render state. */
static inline void ShadowCam_set_lc(void) {
    ShadowCam *cam;
    psvec_set(&cam->pos,
              (cam = *(ShadowCam *volatile *)&lbl_801A66CC, *(f32 *)(0xE0000000 + 0x2C)),  /* fzgx-allow: S2 volatile keeps the verified access order */
              *(f32 *)(0xE0000000 + 0x1C),
              *(f32 *)(0xE0000000 + 0x0C));
}
#define ShadowCam_set(cam) ShadowCam_set_lc()

#pragma opt_common_subs off
void fn_1_5745C(ShadowSrc *src, u32 *color) {
    struct { ShadowCam **value; } cameraSlot;
    u32 flags;
    void *list;
    ShadowQuad *quad;
    f32 size;
    f32 n;

    if (!((src->flags >> 2) & 1)) {
        return;
    }
    flags = src->flags & src->mask;
    if (!(flags & 1) && !(flags & 2)) {
        return;
    }
    quad = (ShadowQuad *)fn_1_548AC(sizeof(ShadowQuad));
    if (quad == NULL) {
        return;
    }
    lbl_8006DCA4();
    lbl_801A66CC->pos.x = src->x;
    lbl_801A66CC->pos.y = src->y;
    lbl_801A66CC->pos.z = src->z;
    if (fn_1_54E34(&lbl_801A66CC->pos, 3.0f) == 0) {
        return;
    }
    lbl_8006DFC4(src->mtx);
    list = fn_1_54384(lbl_801A6D00->scale);
    quad->draw = fn_1_571E8;
    /* The active camera is shared render state. */
    ShadowCam_set(*(ShadowCam *volatile *)&lbl_801A66CC);
    lbl_801A66CC->pos.z = -lbl_801A66CC->pos.z;
    if (lbl_801A66CC->pos.z > 6.1) {
        lbl_8006DB74(lbl_801A6D00->mtx);
        lbl_8006D848((lbl_801A66CC->pos.z - 3.0f) / lbl_801A66CC->pos.z);
        lbl_8006DFC4(lbl_801A6D00->mtx);
        quad->mode = 3;
    } else {
        quad->mode = 7;
    }
    size = 3.0f;
    if ((src->flags >> 1) & 1) {
        n = -size;
        lbl_8006E1D8(&quad->p0, n, n, 0.0f);
        lbl_8006E1D8(&quad->p1, size, n, 0.0f);
        lbl_8006E1D8(&quad->p2, size, size, 0.0f);
        lbl_8006E1D8(&quad->p3, n, size, 0.0f);
    } else {
        n = -size;
        lbl_8006E1D8(&quad->p0, n, 0.0f, n);
        lbl_8006E1D8(&quad->p1, size, 0.0f, n);
        lbl_8006E1D8(&quad->p2, size, 0.0f, size);
        lbl_8006E1D8(&quad->p3, n, 0.0f, size);
    }
    quad->unk_38 = src->unk_3C;
    *(u32 *)quad->color = *color;
    quad->color[3] = quad->color[3] * src->alpha;
    fn_1_5489C(list, (void **)quad);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_5745C */

/* fzgx:begin fn_1_57714 */
// Updates the shadow-map enable flag.
void fn_1_57714(u8 value) {
    lbl_1_data_1C670.unk_0 = value;
}
/* fzgx:end fn_1_57714 */

/* fzgx:begin fn_1_57720 */
void fn_1_57720(u32 value_1, u32 value_2, u32 value_3, u32 value_4) {
    lbl_1_data_1C670.unk_4 = value_1;
    lbl_1_data_1C670.unk_8 = value_2;
    lbl_1_data_1C670.unk_C = value_3;
    lbl_1_data_1C670.unk_10 = value_4;
}
/* fzgx:end fn_1_57720 */

/* fzgx:begin fn_1_5773C */
typedef union fn_1_5773C_GXFifo {
    volatile f32 f32; /* write-gather FIFO: writes have side effects */
    volatile u8 u8;   /* write-gather FIFO: writes have side effects */
} fn_1_5773C_GXFifo;

enum { GX_FIFO_ADDR = 0xCC008000 }; /* fzgx-allow: A1 GX write-gather FIFO hardware address */
#define GXWGFifo (*(fn_1_5773C_GXFifo *)GX_FIFO_ADDR)

typedef struct fn_1_5773C_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_5773C_Vec3;

void fn_1_5773C(fn_1_5773C_Vec3 *arg0, fn_1_5773C_Vec3 *arg1, u8 *arg2) {
    u32 color;
    f32 y;
    f32 z;
    f32 x;
    f32 y2;
    f32 z2;
    f32 x2;

    fn_1_57DC0();
    color = *(u32 *)arg2;
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8003462C(0xA8, 0, 2);
    z = arg0->z;
    y = arg0->y;
    x = arg0->x;
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
    GXWGFifo.u8 = ((u8 *)&color)[0];
    GXWGFifo.u8 = ((u8 *)&color)[1];
    GXWGFifo.u8 = ((u8 *)&color)[2];
    GXWGFifo.u8 = ((u8 *)&color)[3];
    z2 = arg1->z;
    y2 = arg1->y;
    x2 = arg1->x;
    GXWGFifo.f32 = x2;
    GXWGFifo.f32 = y2;
    GXWGFifo.f32 = z2;
    GXWGFifo.u8 = ((u8 *)&color)[0];
    GXWGFifo.u8 = ((u8 *)&color)[1];
    GXWGFifo.u8 = ((u8 *)&color)[2];
    GXWGFifo.u8 = ((u8 *)&color)[3];
}
/* fzgx:end fn_1_5773C */

/* fzgx:begin fn_1_57810 noprologue */
#include "sdk_addresses.h"
#include "types.h"

/* GX write-gather FIFO */
typedef union { u8 u8; f32 f32; } FifoT;
#define FIFO (*(volatile FifoT *)FZGX_ADDR_GXFIFO)  /* fzgx-allow: S2 volatile view keeps the verified load order */
typedef struct { u8 r, g, b, a; } Col;
typedef struct { f32 x, y, z; } Vtx3;
extern void *lbl_801A6D00;
extern void GXLoadPosMtxImm(void *, int);
extern void fn_1_57DC0(void);
extern void fn_8003462C(u8, u8, u16);

static inline void Pos3(f32 x, f32 y, f32 z) {
    FIFO.f32 = x;
    FIFO.f32 = y;
    FIFO.f32 = z;
}
static inline void Col4(u8 r, u8 g, u8 b, u8 a) {
    FIFO.u8 = r;
    FIFO.u8 = g;
    FIFO.u8 = b;
    FIFO.u8 = a;
}

/* retail keeps the trip count in two webs (an uncoalesced copy): lifetimes off */
#pragma opt_lifetimes off
void fn_1_57810(u16 n, Vtx3 *verts, Col *color) {
    u8 a;
    u8 b;
    u8 g;
    u8 r;
    int count;
    int i;
    Vtx3 *p;
    u32 cw;
    u8 *cb;
    if (n < 2) return;
    fn_1_57DC0();
    cw = *(u32 *)color;
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8003462C(0xB0, 0, n);
    cb = (u8 *)&cw;
    r = cb[0];
    g = cb[1];
    b = cb[2];
    a = cb[3];
    count = n;
    p = verts;
    for (i = count; i > 0; i--) {
        Pos3(p->x, p->y, p->z);
        Col4(r, g, b, a);
        p++;
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_57810 */

/* fzgx:begin fn_1_579A0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/shadowmap.h"

extern void *lbl_801A6D00;
extern void fn_1_57DC0(void);
extern void GXLoadPosMtxImm(void *, u32);
extern void fn_8003462C(u32, u32, u32);

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} ColorVertex;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe;

volatile WGPipe GXWGFifo : 0xCC008000; /* fzgx-allow: A1 write-gather FIFO port */

static inline void GXPosition3f32(const f32 x, const f32 y, const f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}

static inline void GXColor4u8(const u8 r, const u8 g, const u8 b, const u8 a) {
    GXWGFifo.u8 = r;
    GXWGFifo.u8 = g;
    GXWGFifo.u8 = b;
    GXWGFifo.u8 = a;
}

void fn_1_579A0(ColorVertex *first, ColorVertex *second) {
    fn_1_57DC0();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8003462C(0xa8, 0, 2);

    GXPosition3f32(first->x, first->y, first->z);
    GXColor4u8(first->r, first->g, first->b, first->a);
    GXPosition3f32(second->x, second->y, second->z);
    GXColor4u8(second->r, second->g, second->b, first->a);
}
/* fzgx:end fn_1_579A0 */

/* fzgx:begin fn_1_57A70 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"

/* begin dolphin/gx.h (deltawave784/fzgx, CC0) */
#ifndef DOLPHIN_GX_H
#define DOLPHIN_GX_H


/* The GX write-gather pipe: one memory-mapped port at GX_FIFO_BASE (dolphin/hw_regs.h), written through
   the member whose width the command needs. Declared as an MWCC absolute object: every store is
   emitted in order, addressed by literal (`lis rX, 0xCC01; stb rY, -0x8000(rX)`) with no
   relocation, and the named object cannot alias the `gx` context, which keeps retail's schedule.
   Proven by GXSetViewportJitter (fn_80038DE8) and GXSetFog (fn_800377F8). */
typedef union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    s8 s8;
    s16 s16;
    s32 s32;
    f32 f32;
    f64 f64;
} PPCWGPipe;
typedef PPCWGPipe WGPipe;

volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE; /* volatile: hardware port */

#define GX_WRITE_U8(v) (GXWGFifo.u8 = (u8)(v))
#define GX_WRITE_U16(v) (GXWGFifo.u16 = (u16)(v))
#define GX_WRITE_U32(v) (GXWGFifo.u32 = (u32)(v))
#define GX_WRITE_F32(v) (GXWGFifo.f32 = (f32)(v))

/* BP (raster) register write: command byte 0x61 followed by the register word. */
#define GX_WRITE_RAS_REG(value)  \
    do {                         \
        GXWGFifo.u8 = 0x61;      \
        GXWGFifo.u32 = (value);  \
    } while (0)

/* XF register write: command byte 0x10, then (count - 1) << 16 | address, then the data words. */
#define GX_WRITE_XF_REG_HDR(addr, count) \
    do {                                  \
        GXWGFifo.u8 = 0x10;               \
        GXWGFifo.u32 = (((count) - 1) << 16) | (addr); \
    } while (0)

#endif

/* end dolphin/gx.h */

extern u32 lbl_801A6D00;
extern void GXLoadPosMtxImm(u32, u32);
extern void fn_1_57DC0(u32);
extern void fn_8003462C(u32, u32, u32);

typedef struct { f32 x, y, z; s8 a, b, c, d; } V16;

static inline void pos3(f32 x, f32 y, f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}
static inline void col4(u8 a, u8 b, u8 c, u8 d) {
    GXWGFifo.u8 = a;
    GXWGFifo.u8 = b;
    GXWGFifo.u8 = c;
    GXWGFifo.u8 = d;
}

static inline f32 fn_1_57A70_read_pointer(V16 * owner) { return owner->x; }
#pragma opt_loop_invariants off
void fn_1_57A70(u32 n, V16 *v) {
    s32 i;
    u16 count;
    V16 *p;
    if ((u16)n >= 2) {
        fn_1_57DC0(n);
        GXLoadPosMtxImm(lbl_801A6D00, 0);
        fn_8003462C(0xB0, 0, n);
        p = v;
        count = n;
        for (i = 0; i < count; i++) {
            pos3(fn_1_57A70_read_pointer(p), p->y, p->z);
            col4(p->a, p->b, p->c, p->d);
            p++;
        }
    }
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_57A70 */

/* fzgx:begin fn_1_57BBC */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
} Fn1_57BBC_ArgBlock;

typedef struct {
    u32 unk_0;
    void (*unk_4)(void);
    u8 pad_8[0x30];
    u32 unk_38;
    u16 unk_3C;
    u8 pad_3E[0x2];
    void *unk_40;
    Obj_1_data_1C670 unk_44;
} Fn1_57BBC_Object;

typedef struct {
    Fn1_57BBC_ArgBlock unk_0;
    Fn1_57BBC_ArgBlock unk_10;
} Fn1_57BBC_Data;

void fn_1_57BBC(Fn1_57BBC_ArgBlock *arg0, Fn1_57BBC_ArgBlock *arg1) {
    Fn1_57BBC_Object *object;
    Fn1_57BBC_Data *data;
    void *value;

    object = fn_1_548AC(0x60);
    if (object == 0) {
        return;
    }

    data = fn_1_548AC(0x20);
    if (data == 0) {
        return;
    }

    value = fn_1_5448C(arg0);
    object->unk_4 = fn_1_57E84;
    object->unk_38 = 0xA8;
    object->unk_3C = 2;
    object->unk_44 = lbl_1_data_1C670;
    data->unk_0 = *arg0;
    data->unk_10 = *arg1;
    object->unk_40 = data;
    lbl_8006DB74(object->pad_8);
    fn_1_5489C(value, object);
}
/* fzgx:end fn_1_57BBC */

/* fzgx:begin fn_1_57CD0 */
typedef struct {
    u8 pad_0[0x4];
    void (*unk_4)(void);
    u8 pad_8[0x30];
    u32 unk_38;
    u16 unk_3C;
    u8 pad_3E[0x2];
    void *unk_40;
    Obj_1_data_1C670 unk_44;
} Fn1_57CD0_Object;

void fn_1_57CD0(u32 value, void *arg) {
    u32 size;
    Fn1_57CD0_Object *object;
    void *created;
    void *buffer;

    if ((u16)value < 2) {
        return;
    }

    object = fn_1_548AC(0x60);
    if (object == 0) {
        return;
    }

    size = (value & 0xffff) << 4;
    buffer = fn_1_548AC(size);
    if (buffer == 0) {
        return;
    }

    created = fn_1_5448C(arg);
    object->unk_4 = fn_1_57E84;
    object->unk_38 = 0xa8;
    object->unk_3C = (u16)value;
    object->unk_44 = lbl_1_data_1C670;
    fn_80008BA8(buffer, arg, size);
    object->unk_40 = buffer;
    lbl_8006DB74(object->pad_8);
    fn_1_5489C(created, object);
}
/* fzgx:end fn_1_57CD0 */

/* fzgx:begin fn_1_57DC0 */
void fn_1_57DC0(void) {
    fn_800746A8(lbl_1_data_1C670.unk_0, lbl_1_data_1C670.unk_14);
    fn_8007245C(0xa00);
    fn_800728A8(lbl_1_data_1C670.unk_4, lbl_1_data_1C670.unk_8,
                lbl_1_data_1C670.unk_C, lbl_1_data_1C670.unk_10);
    fn_800720B0(0);
    fn_800747D0(4, 0, 1, 1, 0, 2, 1);
    fn_800734A8(0, 0xff, 0xff, 4);
    fn_80072EDC(0, 4);
    fn_80073C6C(0);
    fn_80073678(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_80074788(1);
}
/* fzgx:end fn_1_57DC0 */

/* fzgx:begin fn_1_57E84 noprologue */
#include "types.h"
#include "rel/main_rel/shadowmap.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} ColorVertex;

typedef struct {
    u8 pad_0[0x8];
    u8 unk_8[0x30];
    u32 unk_38;
    u16 unk_3C;
    u8 pad_3E[0x2];
    ColorVertex *unk_40;
    Obj_1_data_1C670 unk_44;
} Fn1_57E84_Object;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe;

volatile WGPipe GXWGFifo : 0xCC008000; /* fzgx-allow: A1 write-gather FIFO port */

extern void fn_800746A8(u32, u32);
extern void fn_8007245C(u32);
extern void fn_800728A8(u32, u32, u32, u32);
extern void fn_800720B0(u32);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80072EDC(u32, u32);
extern void fn_80073C6C(u32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80073898(u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);
extern void GXLoadPosMtxImm(void *, int);
extern void fn_8003462C(u32, u32, u32);

static inline void GXPosition3f32(const f32 x, const f32 y, const f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}

static inline void GXColor4u8(const u8 r, const u8 g, const u8 b, const u8 a) {
    GXWGFifo.u8 = r;
    GXWGFifo.u8 = g;
    GXWGFifo.u8 = b;
    GXWGFifo.u8 = a;
}

/* fn_1_57DC0's body: retail inlines that same-TU function here */
static inline void state_apply(void) {
    fn_800746A8(lbl_1_data_1C670.unk_0, lbl_1_data_1C670.unk_14);
    fn_8007245C(0xa00);
    fn_800728A8(lbl_1_data_1C670.unk_4, lbl_1_data_1C670.unk_8,
                lbl_1_data_1C670.unk_C, lbl_1_data_1C670.unk_10);
    fn_800720B0(0);
    fn_800747D0(4, 0, 1, 1, 0, 2, 1);
    fn_800734A8(0, 0xff, 0xff, 4);
    fn_80072EDC(0, 4);
    fn_80073C6C(0);
    fn_80073678(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_80074788(1);
}

void fn_1_57E84(Fn1_57E84_Object *object) {
    Obj_1_data_1C670 saved;
    ColorVertex *v;
    s32 i;
    s32 count;

    saved = lbl_1_data_1C670;
    lbl_1_data_1C670 = object->unk_44;
    state_apply();
    fn_80074918(1, 3, 1);
    GXLoadPosMtxImm(object->unk_8, 0);
    fn_8003462C(object->unk_38, 0, object->unk_3C);
    count = object->unk_3C;
    v = object->unk_40;
    for (i = 0; i < count; i++) {
        GXPosition3f32(v->x, v->y, v->z);
        GXColor4u8(v->r, v->g, v->b, v->a);
        v++;
    }
    lbl_1_data_1C670 = saved;
}
/* fzgx:end fn_1_57E84 */
