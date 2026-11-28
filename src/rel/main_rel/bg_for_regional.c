/* Previously matched Japan/PAL units of bg_for.c, retained until that TU matches those releases as one unit. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"
#include "psvec.h"
#include "rel/main_rel/car_test.h"
#include "game/vec3.h"
#include "mathutil_vec_dot_prod.h"


typedef struct {
    f32 x;
    f32 y;
    f32 z;
} BgForVec;

/* A spot light of the course light list (0xAC bytes). */
typedef struct {
    s32 data; /* 0x00 */
    u32 unk_04;
    u32 flags; /* 0x08 */
    u8 unk_0C[0xA0];
} BgForSpotLight;

typedef struct {
    s32 count; /* 0x0000 */
    BgForSpotLight lights[32]; /* 0x0004 */
    u32 unk_1584;
    s32 unk_1588; /* 0x1588 */
} BgForLightList;

/* A camera (0xA0 bytes). */
typedef struct {
    BgForVec pos; /* 0x00 */
    BgForVec prevPos; /* 0x0C */
    BgForVec target; /* 0x18 */
    BgForVec up; /* 0x24 */
    f32 fovy; /* 0x30 */
    f32 aspect; /* 0x34 */
    f32 near; /* 0x38 */
    f32 far; /* 0x3C */
    f32 projMtx[3][4]; /* 0x40 */
    f32 viewMtx[3][4]; /* 0x70 */
} BgForCamera;



typedef Vec3 Vec;

struct fn_1_DCE60_lbl_1_rodata_6750 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
};

typedef struct fn_1_DD890_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_DD890_Vec3;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} E1408Vec;

typedef struct E1408Object {
    u8 pad0[0x18];
    f32 field18;
    f32 field1C;
    u8 pad20[0x24];
    E1408Vec field44;
    f32 field50;
    E1408Vec pos;
    E1408Vec vel;
    u8 pad6C[0x18];
    f32 field84;
    u8 pad88[0x6c];
    f32 fieldF4;
    u8 padF8[0x40];
    union {
        u64 flags;
        struct {
            u32 hi;
            u32 lo;
        } w;
    } f138;
    u32 mask140;
    void *other;
} E1408Object;

typedef struct {
    u8 pad_0[0x3ba];
    s16 state;
    u8 pad_3BC[0x84];
} CarTestCar;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn183D28Vec3;

typedef struct {
    u8 pad_0[0x14c];
    Fn183D28Vec3 pos;
    u8 pad_158[0x200 - 0x158];
    f32 unk_200;
} Fn183D28Body;

typedef struct {
    u8 pad_0[0x8];
    Fn183D28Vec3 dir;
    f32 radius;
} Fn183D28Target;

typedef struct {
    s16 limit;
    s16 pad_2;
    Fn183D28Target **target;
    u8 pad_8[4];
} Fn183D28Entry;

typedef struct {
    u8 pad_0[0x8];
    Fn183D28Target **target;
} Fn183D28Slot;

typedef struct {
    u8 pad_0[0x344];
    Fn183D28Slot *slots[1];
} Fn183D28Alt;

typedef struct {
    u8 pad_0[0x320];
    s16 index;
    u8 pad_322[0xa];
    Fn183D28Body *body;
    Fn183D28Entry entries[6];
    u8 pad_378[0x18];
    u32 flags;
    u8 pad_394[0xc];
    Fn183D28Alt *alt;
} Fn183D28Car;

typedef struct {
    u32 unk0;
    f32 value;
} Sig_fn_1_E5734_E5734Obj;

struct fn_1_DD890_lbl_801A66A0 {
    u32 unk_0;
};

typedef struct {
    f32 x, y, z, w;
} DE4B0Quat;

typedef Vec3 DE4B0Vec;

typedef struct {
    u8 pad_0[0x90];
    s32 *lap;
} DFBBCLapInfo;

typedef struct {
    u32 flags;
    s16 index;
    u8 pad_6[0x2];
    f32 mass;
    u8 pad_C[0x70];
    Vec pos;
    Vec prev_pos;
    Vec vel;
    u8 pad_A0[0xAC];
    u8 mtx[0x30];
    f32 speed;
    u8 pad_180[0x3C];
    Vec up;
    u8 pad_1C8[0x2D4];
    DFBBCLapInfo *lap_info;
} DFBBCCar;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} HitPoint;
extern struct fn_1_DCE60_lbl_1_rodata_6750 lbl_1_rodata_6750;
extern const f32 lbl_1_rodata_6780[];
extern void fn_80008BA8(void *dst, void *src, u32 size);
extern void fn_1_57714(u8 zMode);
extern void lbl_8006D758(void);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DCA4(void);
extern void fn_80072558(void);
extern void fn_1_57810(u32, void *, void *);
extern void lbl_8006D784(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DFE8(const void *);
extern void fn_1_DDF80(Vec *a, Vec *b, Vec *along, Vec *side, f32 along_scale, f32 side_scale);
extern void fn_1_56298(f32 r, f32 g, f32 b, f32 a);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006EE70(const Vec3 *input, s16 *output);
extern void mathutil_mtxA_rotate_z(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E15C(f32, f32, f32);
extern void fn_1_556B8(void *value);
extern f64 fabs(f64);
extern s32 fn_1_E1408(E1408Object *a, E1408Object *b);
extern void fn_1_E57F4(void *base, f32 value);
extern void fn_1_DCFA4(u32);
extern void fn_1_55FF0(f32 scale);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E14C(f32);
extern void lbl_8006D7DC(const void *);
extern s8 fn_1_84408(CarTestCar *);
extern void fn_1_8E084(CarTestCar *, u32 *, s32);
extern s8 fn_1_84124(Fn183D28Car *, s8, s8, u8 *);
extern s8 fn_1_84644(Fn183D28Body *);
extern f32 fn_1_E5734(Sig_fn_1_E5734_E5734Obj *);
extern u32 lbl_801A66A0;
extern void lbl_8006DB74(void *);
extern void fn_1_9BBE4(void *arg0, u32 arg1, u32 arg2, Fn183D28Vec3 *arg3);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_553C4(void *value, void *arg);
extern void fn_1_A8DD4(const char *format, ...);
extern void fn_1_E50F0(void *base, void *arg);
extern void fn_1_E5164(void *arg0, void *arg1);
extern void fn_1_E52F8(void *, void (*)(const char *, ...));
extern f32 lbl_8006D534(Vec *, Vec *);
extern void lbl_8006D5F0(Vec *, Vec *, f32);
extern f32 lbl_8006D668(Vec *);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void lbl_8006DAEC(void);
extern void lbl_8006DD14(void *, void *);
extern void fn_1_A7024(f32 fovy, f32 aspect, f32 near, f32 far);
extern void lbl_8006DCDC(void);
extern void lbl_8006DB30(void);
extern u32 lbl_801A63C0;
extern void fn_1_E5840(void *base, const void *value);
extern void lbl_8006E1C0(void *, void *);
extern void fn_8006E978(f32 *arg0, Vec3 *arg1, Vec3 *arg2);
extern void mathutil_mtxA_from_quat(DE4B0Quat *);
extern void fzgx_pool_sink(const void *, f32);
extern f32 fn_1_9E14C(u32, void *, f32);
extern f32 fn_1_9E194(u32, void *, f32);
extern void fn_1_A5594(u32 arg0, Fn183D28Vec3 *pos);
extern void *fn_1_86254(int index);
extern void lbl_8006E0B4(f32, f32, f32);
extern void fn_8006E2B0(Vec3 *, Vec3 *);
extern void fn_8006E250(Vec *, Vec *);
extern f32 lbl_8006D0E8(f32);
extern void lbl_8006DC34(void *);
extern void lbl_8006DFC4(void *);
extern s16 fn_1_DEDC4(Vec3 *a, Vec3 *b, void *mtx, Vec3 *point, Vec3 *normal, Vec3 *hit, Vec3 *out, f32 radius);
extern void lbl_8006D5A4(Vec3 *a, Vec3 *b, Vec3 *out, f32 t);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_A3BD8(s32 index, u32 value);
extern void fn_1_DF6AC(Vec *, Vec *, Vec *, Vec *, Vec *, f32, f32, f32, f32, f32, f32);
extern void fn_1_24F10(DFBBCCar *, f32);
extern u8 * fn_1_14F04(void);
extern s32 fn_1_20A5C(Vec3 *pos, f32 *out_t);
extern s32 fn_1_15578(Vec *, Vec *, f32 *, HitPoint *, s32, s32 *, u32, s32, s32, s32);
extern s16 fn_1_DF2A4(Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, f32, f32);
extern void fn_1_E57FC(void *object, void *source);
extern void fn_1_E5884(void *base, void *value);
extern void fn_1_E58CC(void *base, const void *value);
extern void fn_1_E5970(void *base, f32 value);
extern void fn_1_E5978(void *base, f32 value);
extern void fn_1_E5980(void *base, f32 value);
extern void fn_1_E5988(void *base, void *value);
extern void fn_1_E5A0C(void *base, void *value);
extern void fn_1_E5A50(void *base, void *value);
extern void fn_1_E5A94(void *base, void *value);
extern void fn_1_E5AD8(void *, f32);
extern void fn_8006F1F0(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2);
extern BgForCamera lbl_1_bss_7ADE8;

/* fzgx:begin fn_1_DDF80 */
/* bg_for.c's literal pool: -1.0f at 0x0, 0.0f at 0x20, 1.0f at 0x28 */
typedef struct {
    f32 neg_one;
    u8 pad_4[0x1C];
    f32 zero;
    u8 pad_24[0x4];
    f32 one;
} Pool;


/* opt_common_subs off as in fn_1_DE180, which repeats this code; opt_propagation off keeps the pool pointer
 * in one register from the start, as retail does */
/* WARNING: compiler-diff device, not original code: opt_common_subs off; removal changes 10 disassembly lines (bg_for/fn_1_DDF80.c) */
#pragma opt_common_subs off
/* WARNING: compiler-diff device, not original code: opt_propagation off; removal changes 28 disassembly lines (bg_for/fn_1_DDF80.c) */
#pragma opt_propagation off

static inline void cross(Vec *a, Vec *b, Vec *out) {
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
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline f32 dot(Vec *a, Vec *b) {
    f32 result;
    f32 ay;
    f32 az;
    f32 ax;
    f32 bx;
    f32 by;
    f32 bz;
    ax = a->x;
    bx = b->x;
    ay = a->y;
    by = b->y;
    az = a->z;
    bz = b->z;
    result = ax * bx;
    result += ay * by;
    result += az * bz;
    return result;
}

/* a helper of its own gives the -1.0 and the final scale retail's register order */
static inline void flip(const Pool *pool, Vec *v) {
    psvec_scale(v, pool->neg_one, v);
}

void fn_1_DDF80(Vec *a, Vec *b, Vec *along, Vec *side, f32 along_scale, f32 side_scale) {
    const Pool *pool = (const Pool *)lbl_1_rodata_6780;
    Vec pos;
    f32 c;
    f32 s;

    c = lbl_8006D534(a, b);
    s = lbl_8006D0B4(pool->one - (f32)(c * c));
    fn_80008BA8(along, b, sizeof(Vec));
    lbl_8006D5F0(along, along, along_scale * c);
    fn_80008BA8(&pos, a, sizeof(Vec));
    cross(&pos, b, side);
    cross(side, b, side);
    if (dot(side, side) > pool->zero) {
        lbl_8006D668(side);
    }
    if (!(dot(&pos, side) > pool->zero)) {
        flip(pool, side);
    }
    psvec_scale(side, side_scale * s, side);
}

#pragma opt_propagation reset
#pragma opt_common_subs reset
/* fzgx:end fn_1_DDF80 */

/* fzgx:begin fn_1_DE180 */
typedef struct fn_1_DE180_Obj {
    u8 pad_0[0x18];
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    u8 pad_24[0x20];
    Vec3 pos;
    f32 unk_50;
    u8 pad_54[0x18];
    Vec3 vel;
    u8 pad_78[0xC0];
    u64 flags;
} fn_1_DE180_Obj;

typedef Pool fn_1_DE180_Pool;


/* WARNING: compiler-diff device, not original code: opt_common_subs off; removal changes 270 disassembly lines (bg_for/fn_1_DDF80.c) */
#pragma opt_common_subs off

static inline void fn_1_DE180_cross(Vec3 *a, Vec3 *b, Vec3 *out) {
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = b->x;
    f32 by;
    f32 bz = b->z;
    f32 ax = a->x;
    f32 x;
    f32 z;
    f32 y;
    by = b->y;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    x = ay * bz;
    x -= az * by;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline f32 fn_1_DE180_dot(Vec3 *a, Vec3 *b) {
    f32 result;
    f32 ay;
    f32 az;
    f32 ax;
    f32 bx;
    f32 by;
    f32 bz;
    ax = a->x;
    bx = b->x;
    ay = a->y;
    by = b->y;
    az = a->z;
    bz = b->z;
    result = ax * bx;
    result += ay * by;
    result += az * bz;
    return result;
}

static inline void fn_1_DE180_perp(const fn_1_DE180_Pool *pool, Vec3 *a, Vec3 *b, Vec3 *out) {
    Vec3 *n = out;
    fn_1_DE180_cross(a, b, out);
    fn_1_DE180_cross(out, b, out);
    if (fn_1_DE180_dot(out, out) > pool->zero) {
        lbl_8006D668( (Vec *)(Vec3 *)(n));
    }
}

static inline BOOL fn_1_DE180_clamp(const fn_1_DE180_Pool *pool, Vec3 *v, f32 r) {
    Vec3 *p;
    if (r < pool->zero) {
        return FALSE;
    }
    p = v;
    if (fn_1_DE180_dot(v, v) <= r * r) {
        fn_80008BEC(p, 0, sizeof(Vec3));
        return TRUE;
    }
    return FALSE;
}

void fn_1_DE180(fn_1_DE180_Obj *obj, Vec3 *dir, f32 radius) {
    f32 damping;
    f32 side_scale;
    /* WARNING: compiler-diff device, not original code: f32 constant carrier; passing pool->neg_one directly changes 18 disassembly lines */
    f32 fzgx_live;
    f32 scale;
    const fn_1_DE180_Pool *pool;
    Vec3 push;
    Vec3 side;
    Vec3 pos;
    f32 s;
    f32 k;
    f32 dist;

    pool = (const fn_1_DE180_Pool *)lbl_1_rodata_6780;
    if ((obj->flags & 0x8000) != 0) {
        return;
    }
    dist = lbl_8006D534( (Vec *)(Vec3 *)(&obj->pos), (Vec *)(Vec3 *)(dir));
    if (dist > pool->zero) {
        return;
    }
    s = lbl_8006D0B4(pool->one - (f32)(dist * dist));
    k = obj->unk_50;
    scale = k * -obj->unk_18;
    fn_80008BA8(&push, dir, sizeof(Vec3));
    lbl_8006D5F0( (Vec *)(Vec3 *)(&push), (Vec *)(Vec3 *)(&push), scale * dist);
    fn_80008BA8(&pos, &obj->pos, sizeof(Vec3));

    fn_1_DE180_perp(pool, &pos, dir, &side);
    if (!(fn_1_DE180_dot(&pos, &side) > pool->zero)) {
        fzgx_live = pool->neg_one;
        psvec_scale(&side, fzgx_live, &side);
    }
    side_scale = k * s;
    psvec_scale(&side, side_scale, &side);
    if (fn_1_DE180_clamp(pool, &push, radius) == TRUE) {
        obj->flags |= 0x8000;
        if ((obj->flags & 0x8000000) == 0) {
            obj->flags |= 0x100000000ULL;
        }
    }
    psvec_add(&push, &side, &obj->pos);
    damping = pool->one - obj->unk_20;
    psvec_scale(&obj->vel, damping, &obj->vel);
}

#pragma opt_common_subs reset
/* fzgx:end fn_1_DE180 */
