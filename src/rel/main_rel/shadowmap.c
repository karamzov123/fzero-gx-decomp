#include "types.h"
#include "psvec.h"
#include "dolphin/hw_regs.h"
#include "dolphin/gx.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} ShadowVec;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} ShadowColor;

/* The object that casts the shadow. */
typedef struct {
    u32 flags;
    u8 pad_4[0x148];
    f32 mtx[3][4]; /* 0x14C */
    u8 pad_17C[0x40];
    ShadowVec dir; /* 0x1BC */
    f32 dist; /* 0x1C8 */
    u8 pad_1CC[0x8];
    ShadowVec pos; /* 0x1D4 */
} ShadowTarget;

typedef struct {
    u8 pad_0[0x38C];
    u8 parts; /* 0x38C */
    u8 pad_38D[0x2B];
    s16 unk_3B8; /* 0x3B8 */
} ShadowModel;

/* A shadow map (0x4C bytes). */
typedef struct {
    u32 flags;
    u32 state;
    f32 alpha;
    f32 mtx[3][4]; /* 0x0C */
    void *texObj; /* 0x3C */
    void *texBuf; /* 0x40 */
    ShadowModel *model; /* 0x44 */
    ShadowTarget *target; /* 0x48 */
} ShadowMap;

/* A shadow quad of the draw list (0x44 bytes). */
typedef struct ShadowQuad {
    void *next;
    void (*draw)(struct ShadowQuad *);
    ShadowVec p0;
    ShadowVec p1;
    ShadowVec p2;
    ShadowVec p3;
    void *texObj; /* 0x38 */
    ShadowColor color; /* 0x3C */
    u32 mode; /* 0x40 */
} ShadowQuad;

typedef struct {
    u8 pad_0[0xD4];
    ShadowVec pos;
} ShadowCam;

typedef f32 ShadowMtx[3][4];

extern void *lbl_801A6410;
extern ShadowCam *lbl_801A66CC;
extern ShadowMtx *lbl_801A6D00;

extern f64 __fabs(f64);
extern void *GXGetTexBufferSize(int, int, int, int, int);
extern void GXInitTexObj(void *, void *, int, int, int, int, int, int);
extern void GXInitTexObjLOD(void *, int, int, f32, f32, f32, int, int, int);
extern void GXGetScissor(u32 *, u32 *, u32 *, u32 *);
extern void GXGetProjectionv(void *);
extern void GXInvalidateTexAll(void);
extern void GXSetAlphaCompare(u32, u32, u32, u32, u32);
extern void GXLoadPosMtxImm(void *, int);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_80007C2C(void);
extern void fn_8003462C(u32 size, u32 heap, u32 alignment);
extern void fn_8003526C(void *, s32);
extern u32 fn_800371F8(u32, void *);
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_80038F10(void *);
extern void lbl_8006D668(void *);
extern void lbl_8006D758(void);
extern void lbl_8006D848(f32);
extern void lbl_8006D89C(f32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006DF44(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006DFD8(void *);
extern void lbl_8006E0D8(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E1D8(void *, f32, f32, f32);
extern void fn_8006F1F0(void *, void *, void *);
extern void fn_800720B0(u32);
extern void fn_80072270(void *);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_800725DC(ShadowColor);
extern void fn_80072614(ShadowColor);
extern void fn_80072864(u32);
extern void fn_800728A8(u32, u32, u32, u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80072EDC(u32, u32);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80073678(u32);
extern void fn_80073778(void *, u32);
extern void fn_800737E4(void *, s32);
extern void fn_80073898(u32);
extern void fn_80073C6C(u32);
extern void fn_80074188(u32, u32, u32, u32);
extern void fn_80074300(u32, u32, u32, u32);
extern void fn_80074438(u32, u32, u32, u32);
extern void fn_800744F8(ShadowColor, u32);
extern void fn_800745A4(u32, s32, s32, s32, s32, s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_80074918(u32, u32, u32);
extern void fn_80077BAC(void *);
extern void *fn_1_45D0(void *, int, char *, int);
extern void fn_1_46B4(void *, void *, char *, int);
extern void fn_1_5489C(void *, void *);
extern void *fn_1_548AC(u32 size);
extern void *fn_1_54384(f32);
extern s32 fn_1_54E34(void *, f32);
extern int fn_1_56724(void);
extern s32 fn_1_66B8(s32, f32);
extern void fn_1_870BC(void *, s32, void *, s32, s32, f32);
extern void *memset(void *, int, u32);

void fn_1_571E8(ShadowQuad *quad);

static const ShadowColor lbl_1_rodata_28B0 = {0, 0, 0, 0};

/* fzgx:begin fn_1_5672C */
void fn_1_5672C(ShadowMap *maps, int count) {
    void *size;
    int i;
    ShadowMap *map;

    map = maps;
    i = 0;
    while (i < count) {
        size = GXGetTexBufferSize(0x40, 0x40, 0, 0, 0);
        map->flags = 0;
        map->state = 0;
        map->alpha = 0.0f;
        map->texObj = fn_1_45D0(lbl_801A6410, 0x20, "shadowmap.c", 0x67);
        map->texBuf = fn_1_45D0(lbl_801A6410, (int)size, "shadowmap.c", 0x68);
        map->model = NULL;
        map->target = NULL;
        GXInitTexObj(map->texObj, map->texBuf, 0x40, 0x40, 0, 0, 0, 0);
        GXInitTexObjLOD(map->texObj, 1, 1, 0.0f, 0.0f, 0.0f, 0, 0, 0);
        i++;
        map++;
    }
}
/* fzgx:end fn_1_5672C */

/* fzgx:begin fn_1_56858 */
// Register each entry's resources, then clear it for reuse.
void fn_1_56858(ShadowMap *maps, u32 count) {
    u32 i;
    ShadowMap *map;

    for (i = 0, map = maps; i < count; i++, map++) {
        fn_1_46B4(lbl_801A6410, map->texObj, "shadowmap.c", 0x87);
        fn_1_46B4(lbl_801A6410, map->texBuf, "shadowmap.c", 0x88);
        memset(map, 0, sizeof(ShadowMap));
    }
}
/* fzgx:end fn_1_56858 */

/* fzgx:begin fn_1_568EC */
void fn_1_568EC(ShadowMap *map, ShadowTarget *target, ShadowModel *model) {
    map->target = target;
    map->model = model;
}
/* fzgx:end fn_1_568EC */

/* fzgx:begin fn_1_568F8 */
static inline void shadow_set_chan(ShadowColor color) {
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073898(0);
    fn_800725DC(color);
}

void fn_1_568F8(ShadowMap *map) {
    ShadowTarget *target;
    ShadowModel *model;
    s32 flag;
    f32 scale;
    s32 i;
    ShadowVec *vec;
    f32 ax, ay, az;
    f32 ortho[16];
    f32 view[12];
    f32 viewport[6];
    f32 proj[7];
    ShadowVec eye;
    ShadowVec axisX;
    ShadowVec axisY;
    ShadowVec axisZ;
    ShadowVec at;
    u32 left;
    u32 top;
    u32 width;
    u32 height;

    target = map->target;
    flag = (map->flags >> 1) & 1;

    if (!(flag != 0 || (flag == 0 && (map->state & 1) == 0))) {
        return;
    }
    map->state &= ~3;
    if (flag) {
        map->state |= 2;
    } else {
        map->state |= 1;
    }

    fn_80038F10(viewport);
    GXGetScissor(&left, &top, &width, &height);
    GXGetProjectionv(proj);

    if (flag) {
        ax = __fabs(target->dir.x);
        ay = __fabs(target->dir.y);
        az = __fabs(target->dir.z);
        if (ax <= ay && ax <= az) {
            axisX = (ShadowVec){1.0f, 0.0f, 0.0f};
            vec = &axisX;
        } else if (ay <= az && ay <= ax) {
            axisY = (ShadowVec){0.0f, 1.0f, 0.0f};
            vec = &axisY;
        } else {
            axisZ = (ShadowVec){0.0f, 0.0f, 1.0f};
            vec = &axisZ;
        }
        scale = -3.0f;
        vec->x = -vec->x;
        vec->y = -vec->y;
        vec->z = -vec->z;
        psvec_scale(&target->dir, scale, &eye);
        at = (ShadowVec){0.0f, 0.0f, 0.0f};
        fn_8006F1F0(&eye, vec, &at);
        lbl_8006DB74(view);
    } else {
        lbl_8006D89C(1.0f, 0.0f);
        lbl_8006E0D8(0.0f, 20.0f, 0.0f);
        lbl_8006DB74(view);
    }

    C_MTXOrtho(ortho, 3.0f, -3.0f, -3.0f, 3.0f, 0.0f, 100.0f);
    fn_800737E4(ortho, 1);
    fn_80038EEC(0.0f, 0.0f, 128.0f, 128.0f, 0.0f, 1.0f);
    fn_80074188(0, 0, 128, 128);
    fn_80074300(0, 0, 128, 128);
    fn_80074438(64, 64, 0, 1);
    fn_800744F8((ShadowColor){0, 0, 0, 0}, 0x00FFFFFF);
    fn_8003526C(map->texBuf, 1);
    fn_80007C2C();

    if (flag) {
        lbl_8006DC6C(target->mtx);
        lbl_8006DFD8(view);
    } else {
        lbl_8006DBAC(view);
    }

    fn_80072558();
    shadow_set_chan((ShadowColor){0x00, 0xFF, 0x00, 0xFF});
    fn_80072614(lbl_1_rodata_28B0);
    fn_800747D0(4, 0, 0, 0, 1, 2, 1);
    fn_80073C6C(0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072EDC(0, 4);
    fn_800728A8(1, 1, 0, 0);
    fn_80074918(1, 3, 1);
    fn_80077BAC((void *)fn_1_56724);

    model = map->model;
    for (i = 0; i < 6; i++) {
        if (i != 5 && (model->parts & (1 << i))) {
            fn_1_870BC(model, (s8)i, model, 0, model->unk_3B8 & 0xFF, 1.0f);
            break;
        }
    }

    fn_80077BAC(0);
    fn_8003526C(map->texBuf, 1);
    GXInvalidateTexAll();
    fn_80038EEC(viewport[0], viewport[1], viewport[2], viewport[3], viewport[4], viewport[5]);
    fn_80074188(left, top, width, height);
    fn_80072270(proj);
}
/* fzgx:end fn_1_568F8 */

/* fzgx:begin fn_1_56D4C */
static inline void fn_1_56D4C_cross_values(f32 bz, f32 by, f32 bx, f32 ay, f32 az, f32 ax, ShadowVec *out) {
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
static inline void fn_1_56D4C_cross_simple(ShadowVec *a, ShadowVec *b, ShadowVec *out) {
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
static inline void fn_1_56D4C_cross_second(ShadowVec *a, ShadowVec *b, ShadowVec *out) {
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
static inline void fn_1_56D4C_negate(ShadowVec *src, ShadowVec *dst) {
    dst->x = -src->x;
    dst->y = -src->y;
    dst->z = -src->z;
}
/* locked-cache current matrix (translation column) */
void fn_1_56D4C(ShadowMap *entry) {
    f32 z;
    f32 y;
    f32 x;
    ShadowTarget *target;
    void *lab_t0;
    f32 (*m)[4];
    f32 dist;
    f32 ax;
    f32 ay;
    f32 az;
    f32 alpha;
    ShadowVec *axis;
    ShadowVec c;
    f32 a[3];
    f32 b[3];
    f32 e[3];
    ShadowVec f;
    f32 d[3];
    ShadowVec axis_x;
    ShadowVec axis_y;
    ShadowVec axis_z;
    target = entry->target;
    entry->flags &= ~3;
    if (target->flags & 0x8000) {
        dist = 20.0f;
    } else {
        dist = target->dist;
    }
    lbl_8006DBAC(target->mtx);
    if (dist <= 0.0f || !fn_1_66B8(0, 6.0f)) {
        entry->flags &= ~4;
        return;
    }
    entry->flags |= 1;
    ax = __fabs(target->dir.x);
    ay = __fabs(target->dir.y);
    az = __fabs(target->dir.z);
    if (ax <= ay && ax <= az) {
        axis_x = (ShadowVec){1.0f, 0.0f, 0.0f};
        axis = &axis_x;
    } else if (ay <= az && ay <= ax) {
        axis_y = (ShadowVec){0.0f, 1.0f, 0.0f};
        axis = &axis_y;
    } else {
        axis_z = (ShadowVec){0.0f, 0.0f, 1.0f};
        axis = &axis_z;
    }
    if ((entry->flags >> 1) & 1) {
        *(ShadowVec *)a = *axis;
        *(ShadowVec *)b = target->dir;
        fn_1_56D4C_cross((ShadowVec *)a, (ShadowVec *)b, &c);
        fn_1_56D4C_cross((ShadowVec *)b, &c, (ShadowVec *)a);
        fn_1_56D4C_cross(&c, (ShadowVec *)a, (ShadowVec *)b);
        lab_t0 = &c;
        lbl_8006D668(lab_t0);
        lab_t0 = (ShadowVec *)a;
        lbl_8006D668(lab_t0);
        lab_t0 = (ShadowVec *)b;
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
        fn_1_56D4C_negate(&target->dir, (ShadowVec *)d);
        fn_1_56D4C_cross_simple(axis, (ShadowVec *)d, (ShadowVec *)e);
        lab_t0 = (ShadowVec *)e;
        lbl_8006D668(lab_t0);
        fn_1_56D4C_cross_second((ShadowVec *)d, (ShadowVec *)e, &f);
        lab_t0 = &f;
        lbl_8006D668(lab_t0);
        {
            ShadowVec trans = {0.0f, 0.0f, 0.0f};
            m = *lbl_801A6D00;
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
        lbl_8006DB74(lbl_801A6D00[2]);
        lbl_8006DB30();
        lbl_8006E15C(1.0f, 1.0f, 0.0f);
        lbl_8006DFC4(lbl_801A6D00[2]);
        lbl_8006DFC4(target->mtx);
        /* WARNING: compiler-diff device, not original code. The volatile view keeps the retail load order. */
        x = *(volatile f32 *)&target->pos.x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
        y = target->pos.y;
        z = target->pos.z;
        ((f32 (*)[4])LC_BASE)[0][3] = x;
        ((f32 (*)[4])LC_BASE)[1][3] = y;
        ((f32 (*)[4])LC_BASE)[2][3] = z;
        lbl_8006DB74(entry->mtx);
    }
    alpha = 0.05f * dist;
    entry->flags |= 4;
    if (alpha < 0.0f) {
        alpha = 0.0f;
    } else if (alpha > 1.0f) {
        alpha = 1.0f;
    }
    entry->alpha = alpha;
    if (target->flags & 0x8000) {
        entry->alpha = 1.0f;
    }
}
/* fzgx:end fn_1_56D4C */

/* fzgx:begin fn_1_571E8 */
static inline void GXPosition3f32(f32 x, f32 y, f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}

static inline void GXTexCoord2f32(f32 s, f32 t) {
    GXWGFifo.f32 = s;
    GXWGFifo.f32 = t;
}

void fn_1_571E8(ShadowQuad *quad) {
    ShadowColor color;

    fn_80073778(quad->texObj, 0);
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
    color = quad->color;
    fn_800371F8(1, &color);
    fn_80072C24(0, 0xF, 0xF, 0xF, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 4);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800720B0(0);
    fn_80072864(2);
    GXSetAlphaCompare(4, 0x4F, 0, 3, 0xFF);
    fn_800728A8(1, 7, 6, 0);
    fn_80074918(1, quad->mode, 0);
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    fn_8003462C(0x80, 0, 4);

    GXPosition3f32(quad->p0.x, quad->p0.y, quad->p0.z);
    GXTexCoord2f32(0.0f, 0.0f);
    GXPosition3f32(quad->p1.x, quad->p1.y, quad->p1.z);
    GXTexCoord2f32(1.0f, 0.0f);
    GXPosition3f32(quad->p2.x, quad->p2.y, quad->p2.z);
    GXTexCoord2f32(1.0f, 1.0f);
    GXPosition3f32(quad->p3.x, quad->p3.y, quad->p3.z);
    GXTexCoord2f32(0.0f, 1.0f);

    fn_80074918(1, 3, 1);
    GXSetAlphaCompare(7, 0, 0, 7, 0);
}
/* fzgx:end fn_1_571E8 */

/* fzgx:begin fn_1_5745C */
/* The locked cache holds the transform; the active camera is shared render state. */
/* WARNING: compiler-diff device, not original code. The volatile camera read keeps the retail lwzu form. */
static inline void ShadowCam_set_lc(void) {
    ShadowCam *cam;
    psvec_set(&cam->pos,
              (cam = *(ShadowCam *volatile *)&lbl_801A66CC, *(f32 *)(LC_BASE + 0x2C)),  /* fzgx-allow: S2 volatile keeps the verified access order */
              *(f32 *)(LC_BASE + 0x1C),
              *(f32 *)(LC_BASE + 0x0C));
}

/* WARNING: compiler-diff device, not original code. */
#pragma opt_common_subs off
void fn_1_5745C(ShadowMap *src, ShadowColor *color) {
    u32 flags;
    void *list;
    ShadowQuad *quad;
    f32 size;
    f32 n;

    if (!((src->flags >> 2) & 1)) {
        return;
    }
    flags = src->flags & src->state;
    if (!(flags & 1) && !(flags & 2)) {
        return;
    }
    quad = (ShadowQuad *)fn_1_548AC(sizeof(ShadowQuad));
    if (quad == NULL) {
        return;
    }
    lbl_8006DCA4();
    lbl_801A66CC->pos.x = src->mtx[0][3];
    lbl_801A66CC->pos.y = src->mtx[1][3];
    lbl_801A66CC->pos.z = src->mtx[2][3];
    if (fn_1_54E34(&lbl_801A66CC->pos, 3.0f) == 0) {
        return;
    }
    lbl_8006DFC4(src->mtx);
    list = fn_1_54384(lbl_801A6D00[0][2][3]);
    quad->draw = fn_1_571E8;
    /* The active camera is shared render state. */
    ShadowCam_set_lc();
    lbl_801A66CC->pos.z = -lbl_801A66CC->pos.z;
    if (lbl_801A66CC->pos.z > 6.1) {
        lbl_8006DB74(lbl_801A6D00[2]);
        lbl_8006D848((lbl_801A66CC->pos.z - 3.0f) / lbl_801A66CC->pos.z);
        lbl_8006DFC4(lbl_801A6D00[2]);
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
    quad->texObj = src->texObj;
    quad->color = *color;
    quad->color.a = quad->color.a * src->alpha;
    fn_1_5489C(list, quad);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_5745C */

/* fzgx:begin fn_1_57714 noprologue */
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

// Updates the shadow-map enable flag.
void fn_1_57714(u8 value) {
    lbl_1_data_1C670.unk_0 = value;
}
/* fzgx:end fn_1_57714 */

/* fzgx:begin fn_1_57720 noprologue */
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

void fn_1_57720(u32 value_1, u32 value_2, u32 value_3, u32 value_4) {
    lbl_1_data_1C670.unk_4 = value_1;
    lbl_1_data_1C670.unk_8 = value_2;
    lbl_1_data_1C670.unk_C = value_3;
    lbl_1_data_1C670.unk_10 = value_4;
}
/* fzgx:end fn_1_57720 */

/* fzgx:begin fn_1_5773C noprologue */
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
            pos3((p->x), p->y, p->z);
            col4(p->a, p->b, p->c, p->d);
            p++;
        }
    }
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_57A70 */

/* fzgx:begin fn_1_57BBC noprologue */
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

/* fzgx:begin fn_1_57CD0 noprologue */
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

/* fzgx:begin fn_1_57DC0 noprologue */
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
