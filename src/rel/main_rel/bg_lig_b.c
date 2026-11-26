#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_lig.h"

extern u32 lbl_801A66A0;

/* fzgx:begin fn_1_D6748 */
typedef struct {
    f32 x, y, z;
} Vec3_D6748;

/* the 0xE8-byte record fn_1_58E3C copies into a free effect slot */
typedef struct {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[0xA];
    s16 unk_18;
    u16 unk_1A;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2C[4];
    f32 unk_30;
    u8 pad_34[8];
    Vec3_D6748 unk_3C;
    Vec3_D6748 unk_48;
    u8 pad_54[0x1C];
    Vec3_D6748 unk_70;
    u8 pad_7C[0xC];
    Vec3_D6748 unk_88;
    Vec3_D6748 unk_94;
    u8 pad_A0[0xC];
    s16 unk_AC;
    u8 pad_AE[4];
    u16 unk_B2;
    u8 pad_B4[0x34];
} Desc_D6748;

extern s32 fn_1_66B8(void *arg0, f32 arg1);
extern s32 fn_1_58C4(void);
extern void fn_1_681C(u8 index, void *out);
extern u32 fn_1_584AC(void);
extern s16 fn_1_58E3C(void *source);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D668(void *);
extern void *memset(void *dst, int value, u32 size);
extern u32 lbl_801A63C0;

/* one step of the executable's random generator, lbl_801A63C0 */
static inline s32 rand15_D6748(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

static inline f32 dist2_D6748(Vec3_D6748 *a, Vec3_D6748 *b) {
    f32 dx = a->x;
    f32 dy = a->y;
    f32 dz = a->z;

    dx -= b->x;
    dy -= b->y;
    dz -= b->z;
    dx *= dx;
    dx += dy * dy;
    dx += dz * dz;
    return dx;
}

/* distance from p to the nearest viewport camera (fn_1_58C4 viewports, fn_1_681C positions) */
static inline f32 nearest_camera_D6748(Vec3_D6748 *p) {
    Vec3_D6748 cam;
    u32 n;
    u32 i;
    f32 best;

    n = fn_1_58C4();
    fn_1_681C(0, &cam);
    best = lbl_8006D0B4(dist2_D6748(p, &cam));
    for (i = 1; i < n; i++) {
        fn_1_681C(i, &cam);
        best = best < lbl_8006D0B4(dist2_D6748(p, &cam)) ? best : lbl_8006D0B4(dist2_D6748(p, &cam));
    }
    return best;
}

void fn_1_D6748(Vec3_D6748 *a, Vec3_D6748 *b, s16 kind) {
    Desc_D6748 desc;
    f32 s;

    if (fn_1_66B8(a, 4.0f) == 0 && fn_1_66B8(b, 4.0f) == 0) {
        return;
    }
    if (nearest_camera_D6748(a) < 2000.0f || nearest_camera_D6748(b) < 2000.0f) {
        return;
    }
    memset(&desc, 0, 0xE8);
    desc.unk_18 = 0;
    desc.unk_C = 0x13;
    desc.unk_1A = 0xFFFF;
    desc.unk_88 = *a;
    desc.unk_94 = *b;
    desc.unk_3C = *b;
    {
        Vec3_D6748 zero = {0.0f, 0.0f, 0.0f};
        desc.unk_48 = zero;
    }
    /* the casts keep each product unfused: retail has fmul/fadd here, no fmadd */
    desc.unk_28 = 1.0 + (f64)(0.2 * (rand15_D6748() / 32767.0f - 0.5));
    desc.unk_30 = 1.0 + (f64)(0.2 * (rand15_D6748() / 32767.0f - 0.5));
    desc.unk_B2 = kind;
    s = 0.8f + (f32)(0.2f * ((u16)fn_1_584AC() / 32767.0f));
    desc.unk_1C = 255.0f * (0.5f * (1.0f + s)) / 255.0f;
    desc.unk_20 = 224.0f * s / 255.0f;
    desc.unk_24 = 176.0f * s / 255.0f;
    desc.unk_70.x = 0.8f * ((u16)fn_1_584AC() / 32767.0f - 0.5f);
    desc.unk_70.y = 0.8f * ((u16)fn_1_584AC() / 32767.0f - 0.5f);
    desc.unk_70.z = 0.8f * ((u16)fn_1_584AC() / 32767.0f - 0.5f);
    lbl_8006D668(&desc.unk_70);
    desc.unk_AC = 20;
    fn_1_58E3C(&desc);
}
/* fzgx:end fn_1_D6748 */

/* fzgx:begin fn_1_D6C10 */
#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table7[6] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
}
static const unsigned long fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0029999017715454f;
}
static const unsigned long fzgx_pool_table11[1] = {0xD2F1A9FC};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5625f;
}
static const unsigned long fzgx_pool_table13[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.140625f;
}
static const unsigned long fzgx_pool_table15[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 2.5f;
    s = 85.0f;
    s = 21.0f;
    s = 1.284999966621399f;
    s = 89128.9609375f;
    s = 0.07999999821186066f;
}
static const unsigned long fzgx_pool_table17[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 182.04444885253906;
    s = 1.9375f;
}
static const unsigned long fzgx_pool_table19[4] = {0x00000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
static inline Vec3 D6C10InitialVelocity(void) {
    Vec3 initialVelocity = { 0.0f, 0.0f, 0.0f };
    return initialVelocity;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    Vec3 initialVelocity = D6C10InitialVelocity();
    const void *volatile cp = &initialVelocity; /* fzgx-allow: S2 pool primer sink */
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const unsigned long fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.09;
    d = 30.0;
    s = 10.0f;
    s = 1.5f;
    s = 0.019999999552965164f;
}
static const unsigned long fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const unsigned long *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    s = 221.0f;
}
static const unsigned long fzgx_pool_table28[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const unsigned long *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile double d;  /* fzgx-allow: S2 pool primer sink */
    d = 0.05;
}
#pragma section code_type ".text"
#pragma pool_data on

extern f32 lbl_8006D0B4(f32);
extern s16 fn_1_58E3C(void *);
extern s32 fn_1_58C4(void);
extern u32 fn_1_584AC(void);
extern s32 fn_1_66B8(void *, f32);

extern void * memset(void *, int, u32);
extern void fn_1_681C(u8 index, void *out);

typedef struct {
    u8 pad_0[0xC];
    u16 unk_C;
    u8 pad_E[2];
    s32 unk_10;
    u8 pad_14[4];
    u16 unk_18;
    u16 unk_1A;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[4];
    u32 unk_34;
    u8 pad_38[4];
    Vec3 unk_3C;
    Vec3 unk_48;
    u8 pad_54[0x34];
    f32 unk_88;
    f32 unk_8C;
    u8 pad_90[0x1C];
    s16 unk_AC;
    u8 pad_AE[4];
    u16 unk_B2;
    u8 pad_B4[0x34];
} ParticleD6C10;

static inline f32 D6C10Distance(Vec3 *a, f32 *b) {
    f32 dx = a->x;
    f32 dy = a->y;
    f32 dz = a->z;
    dx -= b[0];
    dy -= b[1];
    dz -= b[2];
    dx *= dx;
    dx += dy * dy;
    dx += dz * dz;
    return lbl_8006D0B4(dx);
}

static inline f32 D6C10NearestImpl(f32 best, Vec3 *a, f32 *b) {
    if (best < D6C10Distance(a, b)) return best;
    return D6C10Distance(a, b);
}
#define D6C10Nearest(best, a, b) D6C10NearestImpl(best, a, b)

void fn_1_D6C10(Vec3 *arg0, f32 arg1) {
    u32 v0;
    f32 v1;
    u32 v2;
    u32 v3;
    struct { f32 value; } v4;
    u32 v5;
    f64 v8;
    f32 v32;
    f32 v36;
    u32 v38;
    f32 coefficient;
    ParticleD6C10 loc_14;
    f32 loc_8[3];
    /* frame */
    u32 t0;
    s32 t1;
    u32 t8;
    u32 t9;
    u32 t10;
    u32 t11;
    u32 t12;
    u32 t13;
    u32 t14;
    u32 t15;
    u32 t16;
    u32 t17;
    s16 t18;
    f32 fzgx_pool_f32_0 = 0.0199999996f;
    f32 fzgx_pool_f32_1 = 10.0f;
    /* Spawn one particle near the closest viewer. */
    v0 = lbl_801A66A0;
    v1 = arg1;
    v8 = arg1;
    if (v0 % 20 == 0) {
    v1 = (((20.0f) * arg1));
    t0 = fn_1_66B8(arg0, v1);
    v3 = t0;
    if ((s32)v3 != 0) {
    t1 = fn_1_58C4();
    v3 = t1;
    v2 = v3;
    v3 = 0;
    fn_1_681C(v3, loc_8);
    v4.value = D6C10Distance(arg0, loc_8);
    v5 = 1;
    while (v5 < v2) {
    v3 = (v5 & 0xFF);
    fn_1_681C(v3, loc_8);
    v4.value = D6C10Nearest(v4.value, arg0, loc_8);
    v5++;
    }
    if (v4.value > (800.0f)) return;
    {
    f64 v1;
    memset(&loc_14, 0, sizeof(loc_14));
    {
    struct { f64 value; } product;
    v1 = (0.089999999999999997);
    loc_14.unk_18 = 0;
    v1 = v1 * v8;
    product.value = v1;
    loc_14.unk_C = 13;
    v2 = 1;
    loc_14.unk_1A = (0x10000 - 1);
    coefficient = product.value;
    }
    v5 = 0x43300000;
    loc_14.unk_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 360);
    while ((u8)v2 != 0) {
    loc_14.unk_3C = *arg0;
    t8 = fn_1_584AC();
    v3 = t8;
    v1 = (f32)((v3 & 0xFFFF));
    v1 = ((f32)v1 / (32767.0f));
    v1 = (f64)((v1) - ((0.5)));
    v1 = (f64)((f64)(fzgx_pool_f32_1) * (f64)(v1));
    loc_14.unk_3C.x = ((loc_14.unk_3C.x) + v1);
    t9 = fn_1_584AC();
    v3 = t9;
    v1 = (f32)((v3 & 0xFFFF));
    v1 = ((f32)v1 / (32767.0f));
    v1 = (f64)((v1) - ((0.5)));
    v1 = (f64)((f64)(fzgx_pool_f32_1) * (f64)(v1));
    loc_14.unk_3C.y = ((loc_14.unk_3C.y) + v1);
    t10 = fn_1_584AC();
    v3 = t10;
    v1 = (f32)(v3 & 0xFFFF);
    {
    loc_14.unk_48 = D6C10InitialVelocity();
    }
    v1 = ((f32)v1 / (32767.0f));
    v1 = (f64)((v1) - ((0.5)));
    v1 = (f64)((f64)(fzgx_pool_f32_1) * (f64)(v1));
    loc_14.unk_3C.z = ((loc_14.unk_3C.z) + v1);
    t11 = fn_1_584AC();
    v3 = t11;
    v32 = (v3 & 0xFFFF) / (32767.0f);
    v32 = (0.5f) * v32;
    v32 = (1.5f) + v32;
    v32 = (60.0f) * v32;
    loc_14.unk_10 = v32;
    t12 = fn_1_584AC();
    v3 = t12;
    v1 = (f32)((v3 & 0xFFFF));
    v1 = ((f32)v1 / (32767.0f));
    v1 = (f64)((v1) - ((0.5)));
    v1 = (f64)((f64)(fzgx_pool_f32_0) * (f64)(v1));
    loc_14.unk_48.x = ((loc_14.unk_48.x) + v1);
    t13 = fn_1_584AC();
    v3 = t13;
    v1 = (f32)((v3 & 0xFFFF));
    v1 = ((f32)v1 / (32767.0f));
    v1 = (f64)((v1) - ((0.5)));
    v1 = (f64)((f64)(fzgx_pool_f32_0) * (f64)(v1));
    loc_14.unk_48.z = ((loc_14.unk_48.z) + v1);
    t14 = fn_1_584AC();
    {
    v1 = (t14 & 0xFFFF) / 32767.0f;
    loc_14.unk_B2 = 14;
    loc_14.unk_3C.x -= loc_14.unk_48.x;
    loc_14.unk_48.y += (0.10000000000000001) + (coefficient * (f32)v1);
    loc_14.unk_28 = v8;
    loc_14.unk_2C = ((30.0) * v8);
    }
    loc_14.unk_3C.y -= loc_14.unk_48.y;
    loc_14.unk_3C.z -= loc_14.unk_48.z;
    t15 = fn_1_584AC();
    v3 = t15;
    v36 = (v3 & 0xFFFF) / (32767.0f);
    v36 = (0.200000003f) * v36;
    v36 = (0.800000012f) + v36;
    loc_14.unk_1C = ((221.0f) * ((0.5f) * ((1.0f) + v36))) / (255.0f);
    loc_14.unk_20 = ((221.0f) * v36) / (255.0f);
    loc_14.unk_24 = ((255.0f) * v36) / (255.0f);
    t16 = fn_1_584AC();
    v3 = t16;
    loc_14.unk_8C = (0.200000003f);
    v1 = (((0.02)) * (((v3 & 0xFFFF) / (32767.0f))));
    loc_14.unk_88 = (((0.050000000000000003)) + v1);
    t17 = fn_1_584AC();
    v3 = t17;
    v38 = (v3 & 0xFFFF);
    v1 = (((v38 / (32767.0f))) - ((0.5)));
    loc_14.unk_AC = (((182.04444885253906)) * v1);
    t18 = fn_1_58E3C(&loc_14);
    v3 = t18;
    v2--;
    }
    }
    }
    }
}
/* fzgx:end fn_1_D6C10 */
