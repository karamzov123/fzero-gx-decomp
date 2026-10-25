#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect_car.h"

extern void fn_1_6F90C(void *arg0, void *arg1);
extern s16 fn_1_72318(void);
extern void fn_1_71D0C(void *arg0, void *arg1);

extern void *lbl_801A6410;
extern void fn_1_46B4(u32 value, void *field, u8 *data, s32 code);
extern u32 fn_1_4630(u32 value, u32 size, u8 *data, s32 code);
extern void fn_1_862D4(s16 value, void *result);
extern void fn_1_58E3C(void *entry);
extern u32 fn_1_58C4(void);
extern s8 lbl_1_bss_6C878[];
extern struct fn_1_6F404_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern void * fn_1_868C0(s8);
extern u32 fn_1_71024(void *, void *, u32, f32);
extern u32 fn_1_7099C(void *, void *, u32, f32, f32);
extern u32 fn_1_71768(void *, void *);
extern u32 fn_1_702A0(void *, void *, u32, u32);
extern u32 fn_80008C20(void *, void *, void *);
extern u32 lbl_8006E1C0(void *, void *);
extern u32 fn_1_584AC(void);
extern u32 fn_1_6FD58(void *, void *, f32, f32);
extern u32 fn_1_A33F0(u32, f32);
extern u32 fn_1_6D7BC(void *, void *, f32);
extern u32 fn_1_A5594(u32, void *);
extern u32 fn_1_714A8(void *, void *, u32, f32);

/* fzgx:begin fn_1_680F8 */
extern u8 *memset(u8 *dst, int value, u32 size);
extern void *lbl_801A6410;

typedef struct Fn1_680F8Arg {
    u8 pad_00[0x18];
    s16 unk_18;
    u16 unk_1a;
    u8 pad_1c[0x18];
    u32 unk_34;
    u8 *unk_38;
    u8 unk_3c[4];
} Fn1_680F8Arg;

typedef struct Fn1_680F8Entry {
    u8 pad_00[0x0c];
    u16 unk_0c;
    u8 pad_0e[0x0a];
    s16 unk_18;
    u8 pad_1a[0x1e];
    u8 *unk_38;
    u8 pad_3c[0xac];
} Fn1_680F8Entry;

void fn_1_680F8(Fn1_680F8Arg *arg) {
    u8 *p;
    Fn1_680F8Entry entry;
    u32 n;
    s32 i;

    arg->unk_1a = 0xffff;
{
    u8 *base;
    base = arg->unk_38;
    arg->unk_34 = fn_1_4630((u32)lbl_801A6410, 0x300, lbl_1_data_1D8A8, 0xc7);
    fn_1_862D4(arg->unk_18, arg->unk_3c);
    memset((u8 *)&entry, 0, 0xe8);
    entry.unk_18 = arg->unk_18;
    entry.unk_0c = 4;
    p = base;
}
    for (i = 0; i < 4; i++) {
        entry.unk_38 = p + 0x3b4;
        fn_1_58E3C(&entry);
        p += 0x30;
    }
    n = fn_1_58C4();
    for (i = 0; i < n; i++) {
        lbl_1_bss_6C878[i * 24] = -1;
    }
}
/* fzgx:end fn_1_680F8 */

/* fzgx:begin fn_1_68248 */
typedef struct Fn1_68248Arg {
    u8 pad0[0x34];
    void *unk_34;
} Fn1_68248Arg;

// Register the effect resource with the shared effect manager.
void fn_1_68248(Fn1_68248Arg *arg) {
    fn_1_46B4((u32)lbl_801A6410, arg->unk_34, lbl_1_data_1D8A8, 0xe2);
}
/* fzgx:end fn_1_68248 */

/* fzgx:begin fn_1_68B68 */
// Stub function that immediately returns.
void fn_1_68B68(void) {
}
/* fzgx:end fn_1_68B68 */

/* fzgx:begin fn_1_69BBC */
typedef struct EffectCar {
    u8 pad_00[0x1a];
    u16 field_1a;
} EffectCar;

void fn_1_69BBC(EffectCar *car) {
    car->field_1a = 0xffff;
}
/* fzgx:end fn_1_69BBC */

/* fzgx:begin fn_1_6A7A4 noprologue */
#include "types.h"

struct fn_1_6A7A4_lbl_801A66A0 {
    u32 unk_0;
};

extern s32 fn_1_58C4(void);
extern struct fn_1_6A7A4_lbl_801A66A0 lbl_801A66A0;
extern u8 lbl_1_rodata_2D70[];
extern void *fn_1_868C0(s8);
extern void lbl_8006DD14(u32, void *);
extern void *memset(void *, int, u32);
extern u32 fn_1_864E8(int);
extern u16 fn_1_584AC(void);
extern s32 fn_1_66B8(u32, f32);
extern f32 lbl_8006D668(void *);
extern void lbl_8006DC6C(void *);
extern void fn_8006E250(void *, void *);
extern s32 fn_1_6EC0(u8);
extern s16 camera_get_entry_field_0xa4(u32);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern s16 fn_1_58F50(const void *);

/* Volatile writes preserve the shared literal-pool order used by the effect-car functions. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_A7_0(f32 *f, f64 *d) {
    f[0] = 0.0f;
    f[1] = -1.0f;
    f[2] = 25.0f;
    f[3] = 15.0f;
    f[4] = 8.0f;
    f[5] = 150.0f;
    f[6] = 10.0f;
    f[7] = 0.5f;
    f[8] = 0.125f;
    f[9] = 32767.0f;
    f[10] = 30.0f;
    f[11] = 20.0f;
    f[12] = 1200.0f;
    f[13] = 0.15f;
    d[0] = 4503601774854144.0;
    d[1] = 4503599627370496.0;
    f[14] = 255.0f;
    f[15] = 102.0f;
    d[2] = 0.8;
    f[16] = 1.6f;
    f[17] = 3.0f;
    f[18] = 0.01f;
    f[19] = 0.6f;
    d[3] = 0.3;
    f[20] = 0.7f;
    f[21] = 0.2f;
    f[22] = 0.4f;
    f[23] = 0.1f;
    f[24] = 1.5f;
    d[4] = 2.0;
    f[25] = 0.8f;
    f[26] = 1.0f;
    f[27] = 85.0f;
    f[28] = 0.25f;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_A0[3] = { 0, 0, 0 };
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_A7_1(f32 *f, f64 *d) {
    f[0] = 100.0f;
    f[1] = 3.5f;
    f[2] = 23.0f;
    f[3] = 60.0f;
    f[4] = 4.0f;
    f[5] = 0.00000011920928955078125f;
    f[6] = 136.0f;
    f[7] = 0.03f;
    d[0] = 0.5;
    f[8] = 0.3f;
    f[9] = 128.0f;
    f[10] = 224.0f;
    f[11] = 500.0f;
}
#pragma section code_type ".text"

typedef struct VecA7 {
    f32 x, y, z;
} VecA7;
static inline f32 dot_A7(const VecA7 *a, const VecA7 *b) {
    return (f32)(a->x * b->x) + a->y * b->y + a->z * b->z;
}
static inline void reject_A7(VecA7 *v, const VecA7 *n) {
    f32 dot = -dot_A7(v, n);
    v->x += (f32)(dot * n->x);
    v->y += (f32)(dot * n->y);
    v->z += (f32)(dot * n->z);
}

typedef struct EffectA7 {
    u8 pad0[0xc];
    s16 kind;
    u8 padE[0xa];
    s16 id;
    u16 flags;
    VecA7 color;
    u8 pad28[0x14];
    VecA7 offset;
    VecA7 tangent;
    u8 pad54[0x1c];
    VecA7 direction;
    u8 pad7c[0xc];
    f32 field88;
    u8 pad8c[8];
    VecA7 position;
    VecA7 velocity;
    s16 lifetime;
    u8 padAe[0x3a];
} EffectA7;
#define F(o) ((o)==0 ? 0.0f : (o)==0x10 ? 8.0f : (o)==0x1c ? 0.5f : (o)==0x24 ? 32767.0f : (o)==0x48 ? 255.0f : (o)==0x70 ? 0.7f : (o)==0x74 ? 0.2f : (o)==0x78 ? 0.4f : (o)==0x80 ? 1.5f : (o)==0x90 ? 0.8f : (o)==0x94 ? 1.0f : (o)==0xd8 ? 0.3f : (o)==0xdc ? 128.0f : (o)==0xe0 ? 224.0f : 500.0f)
#define D(o) (2.0)
#define CARF(o) (*(f32 *)((u8 *)arg0 + (o)))

void fn_1_6A7A4(u32 arg0, void *arg1, f32 arg2) {
    u8 *p_lbl_1_rodata_2D70;
    u32 v0;
    s32 v1;
    u8 *v2;
    s32 v5;
    f32 v4;
    s32 v3;
    u32 v6;
    struct { u32 a[12]; } loc_8;
    EffectA7 effect;
    s32 t2;
    VecA7 *normal = (VecA7 *)arg1;
    f32 z, factor, clamp, speed;
    f32 dot;
    f32 tz, ty, tx;
    p_lbl_1_rodata_2D70 = (u8 *)&lbl_1_rodata_2D70;
    lbl_8006DD14((arg0 + 184), (void *)&loc_8);
    v0 = *(u32 *)((u8 *)arg0 + 56);
    fn_1_868C0((s8)*(s16 *)((u8 *)arg0 + 24));
    t2 = fn_1_58C4();
    v1 = t2;
    switch (t2) {
    case 1:
        if ((s8)*(u8 *)((u8 *)v0 + 1141) == -1) {
            if (lbl_801A66A0.unk_0 % 3 != 0) return;
        } else {
            if (lbl_801A66A0.unk_0 % 3 == 0) return;
        }
        break;
    case 2:
        if (lbl_801A66A0.unk_0 & 1) return;
        break;
    case 3:
    case 4:
        v3 = 0;
        for (v5 = 0; (v6 = v5) <= (u32)fn_1_58C4(); v5++) {
            if (fn_1_864E8(v6) & 0x20) v3++;
        }
        switch (v3) {
        case 4:
            if (lbl_801A66A0.unk_0 % 15 != 0) return;
            break;
        case 3:
            if (lbl_801A66A0.unk_0 % 10 != 0) return;
            break;
        case 2:
            if (lbl_801A66A0.unk_0 % 5 != 0) return;
            break;
        default:
            if (lbl_801A66A0.unk_0 % 5 != 0) return;
            break;
        }
        break;
    default:
        if ((s8)*(u8 *)((u8 *)v0 + 1141) == -1) {
            if (lbl_801A66A0.unk_0 % 3 != 0) return;
        } else {
            if (lbl_801A66A0.unk_0 % 3 == 0) return;
        }
        break;
    }
    v2 = (u8 *)v0 + 0x244;
    memset(&effect, 0, 0xe8);
    effect.id = *(s16 *)((u8 *)arg0 + 0x18);
    effect.kind = 5;
    effect.flags = 0xffff;
    effect.field88 = CARF(0x88);
    v4 = F(0x90) + (f32)(F(0x74) * ((f32)fn_1_584AC() / F(0x24)));
    z = F(0x1c) * (F(0x94) + v4);
    effect.color.x = (F(0xdc) * v4) / F(0x48);
    effect.color.y = (F(0xe0) * v4) / F(0x48);
    effect.color.z = (F(0x48) * z) / F(0x48);
    effect.direction.x = normal->x + (f32)(F(0x78) * ((f32)fn_1_584AC() / F(0x24) - F(0x1c)));
    effect.direction.y = normal->y + (f32)(F(0x78) * ((f32)fn_1_584AC() / F(0x24) - F(0x1c)));
    effect.direction.z = normal->z + (f32)(F(0x78) * ((f32)fn_1_584AC() / F(0x24) - F(0x1c)));
    lbl_8006D668(&effect.direction);
    effect.lifetime = 0x12;
    if (!fn_1_66B8(arg0 + 0x3c, F(0x10))) return;
    lbl_8006DC6C(&loc_8);
    tx = *(volatile f32 *)((u8 *)arg0 + 0x3c); /* volatile: keep the three translation loads before the locked-cache stores. */
    ty = CARF(0x40);
    tz = CARF(0x44);
    {
        /* CPU-local locked-cache matrix scratch area, not a linked data object. */
        enum { LOCKED_CACHE_MATRIX_BASE = 0xe0000000 };
        ((f32 *)LOCKED_CACHE_MATRIX_BASE)[3] = tx;
        ((f32 *)LOCKED_CACHE_MATRIX_BASE)[7] = ty;
        ((f32 *)LOCKED_CACHE_MATRIX_BASE)[11] = tz;
    }
    v3 = 4;
    do {
        if (!(*(u32 *)v2 & 2)) {
            effect.offset = *(VecA7 *)(v2 + 0x20);
            fn_8006E250(&effect.offset, &effect.offset);
            effect.offset.x *= D(0x88);
            if ((s8)*(u8 *)((u8 *)v0 + 0x475) != -1 &&
                fn_1_6EC0(*(u8 *)((u8 *)v0 + 0x475)) &&
                camera_get_entry_field_0xa4(*(u8 *)((u8 *)v0 + 0x475)) == 0) {
                effect.offset.x *= F(0x80);
                effect.offset.z -= F(0x94);
            }
            lbl_8006E1B0(&effect.offset, &effect.offset);
            factor = F(0x70) + (f32)(F(0x78) * ((f32)fn_1_584AC() / F(0x24)));
            effect.tangent.x = CARF(0x48) * factor;
            effect.tangent.y = CARF(0x4c) * factor;
            effect.tangent.z = CARF(0x50) * factor;
            dot = effect.tangent.x * normal->x;
            dot += effect.tangent.y * normal->y;
            dot += effect.tangent.z * normal->z;
            dot = -dot;
            effect.tangent.x += (f32)(dot * normal->x);
            effect.tangent.y += (f32)(dot * normal->y);
            effect.tangent.z += (f32)(dot * normal->z);
            if ((s32)fn_1_584AC() % 3 == 0) {
                factor = F(0x78) + (f32)(F(0xd8) * ((f32)fn_1_584AC() / F(0x24)));
                speed = *(f32 *)((u8 *)v0 + 0x17c) / F(0xe4) - F(0x74);
                clamp = speed < F(0) ? F(0) : speed > F(0x94) ? F(0x94) : speed;
                factor *= clamp;
                effect.tangent.x += (f32)(factor * normal->x);
                effect.tangent.y += (f32)(factor * normal->y);
                effect.tangent.z += (f32)(factor * normal->z);
            }
            effect.offset.x -= effect.tangent.x;
            effect.offset.y -= effect.tangent.y;
            effect.offset.z -= effect.tangent.z;
            effect.position.x = F(0x1c) * (effect.offset.x + CARF(0x3c));
            effect.position.y = F(0xd8) + (f32)(F(0x1c) * (effect.offset.y + CARF(0x40)));
            effect.position.z = F(0x1c) * (effect.offset.z + CARF(0x44));
            tx = F(0x80) * CARF(0x48);
            effect.velocity.x = tx;
            dot = tx * tx;
            ty = F(0x80) * CARF(0x4c);
            effect.velocity.y = ty;
            dot += ty * ty;
            tz = F(0x80) * CARF(0x50);
            effect.velocity.z = tz;
            dot += tz * tz;
            v4 = lbl_8006D0B4(dot);
            effect.velocity.x += (f32)(v4 * ((f32)fn_1_584AC() / F(0x24) - F(0x1c)));
            effect.velocity.y += (f32)(v4 * ((f32)fn_1_584AC() / F(0x24) - F(0x1c)));
            effect.velocity.z += (f32)(v4 * ((f32)fn_1_584AC() / F(0x24) - F(0x1c)));
            fn_1_58F50(&effect);
        }
        v2 += 0x5c;
    } while (--v3 > 0);
}
/* fzgx:end fn_1_6A7A4 */

/* fzgx:begin fn_1_6C87C noprologue */
#include "types.h"
#include "rel/main_rel/effect_car.h"

typedef struct { f32 x, y, z; } Fn1_6C87CVec;

typedef struct Fn1_6C87CCar {
    u8 pad_00[0x18];
    s16 unk_18;
    u8 pad_1a[0x22];
    Fn1_6C87CVec unk_3c;
    Fn1_6C87CVec unk_48;
    u8 pad_54[0x64];
    u8 unk_b8[0x30];
} Fn1_6C87CCar;

typedef struct Fn1_6C87CWork {
    u8 pad_00[0xc];
    s16 unk_0c;
    u8 pad_0e[0x2];
    s32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u16 unk_1a;
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2c;
    u8 pad_30[0x4];
    u32 unk_34;
    u8 pad_38[0x4];
    Fn1_6C87CVec unk_3c;
    Fn1_6C87CVec unk_48;
    u8 pad_54[0x34];
    f32 unk_88;
    f32 unk_8c;
    u8 pad_90[0x1c];
    u16 unk_ac;
    u8 pad_ae[0x3a];
} Fn1_6C87CWork;

extern f32 fn_1_8652C(int);
extern u16 fn_1_584AC(void);
extern u32 fn_1_58C4(void);
extern s16 camera_get_mode(void);
extern s16 fn_1_58F50(const void *);
extern void *memset(void *dest, int value, u32 size);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern u32 lbl_801A66A0;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const Fn1_6C87CVec fzgx_pool_dir_init = {0.0f, 0.1f, 1.5f};
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
}
#pragma section code_type ".text"

#define RANDF() ((f32)fn_1_584AC() / 32767.0f)
#define CLAMP(v, lo, hi) ((v) < (lo) ? (lo) : (v) > (hi) ? (hi) : (v))

static inline f64 jitter(f32 scale) {
    return scale * (RANDF() - 0.5);
}

// Spawn speed-dependent trail particles behind a car.
void fn_1_6C87C(Fn1_6C87CCar *car, Fn1_6C87CVec *dir, f32 arg2) {
    f32 speed;
    f32 z, y, x;
    Fn1_6C87CWork work;
    Fn1_6C87CVec pos;
    f32 spread;
    f32 t;
    f32 half;
    f32 push;
    f32 bright;
    u8 n;

    speed = fn_1_8652C(car->unk_18);
    if (fn_1_584AC() % 3 != 0) {
        return;
    }
    if ((fn_1_58C4() >= 2 || car->unk_18 != camera_get_mode()) && (lbl_801A66A0 & 1)) {
        return;
    }
    if (speed < 100.0f) {
        if (fn_1_584AC() % 3 != 0) {
            return;
        }
    } else if (fn_1_584AC() % 4 == 0) {
        return;
    }

    memset(&work, 0, sizeof(work));
    work.unk_18 = car->unk_18;
    work.unk_0c = 13;
    work.unk_1a = 0xffff;
    work.unk_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x168);
    pos = fzgx_pool_dir_init;
    lbl_8006DC6C(car->unk_b8);
    x = *(volatile f32 *)&car->unk_3c.x; /* Locked-cache column: retain the initial load order. */
    y = car->unk_3c.y;
    z = car->unk_3c.z;
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
    lbl_8006E1B0(&pos, &pos);

    if (speed < 500.0f) {
        n = 1;
    }
    if (500.0f <= speed && speed < 800.0f) {
        n = 2;
    }
    if (800.0f <= speed && speed < 1000.0f) {
        n = 3;
    }
    if (1000.0f <= speed) {
        n = 5;
    }

    while (n != 0) {
        work.unk_3c = pos;
        work.unk_48 = car->unk_48;
        work.unk_10 = 60.0f * (0.2f + (f32)(2.0f * RANDF()));
        work.unk_10 *= CLAMP(1.0 - speed / 1250.0f, 0.4, 1.0);
        spread = -(arg2 / 300.0f) + CLAMP(speed / 1250.0f, 0.2f, 0.8);
        work.unk_48.x += jitter(spread);
        work.unk_48.z += jitter(spread);
        push = speed / 2500.0f;
        work.unk_48.x += (f32)(dir->x * push);
        work.unk_48.y += (f32)(dir->y * push);
        work.unk_48.z += (f32)(dir->z * push);
        work.unk_3c.x -= work.unk_48.x;
        work.unk_3c.y -= work.unk_48.y;
        work.unk_3c.z -= work.unk_48.z;
        work.unk_28 = 0.1 + CLAMP(speed / 5000.0f, 0.0, 0.2);
        work.unk_2c = (12.0 + (f64)(-0.16 * arg2)) + (f64)(RANDF() * CLAMP(0.05 * speed, 5.0, 50.0));
        t = 0.8f + (f32)(0.2f * RANDF());
        bright = 119.0 - (f64)(2.5 * arg2);
        work.unk_1c = (bright * (0.5f * (1.0f + t))) / 255.0f;
        work.unk_20 = (bright * t) / 255.0f;
        work.unk_24 = (bright * t) / 255.0f;
        work.unk_88 = 0.0003 * RANDF();
        work.unk_8c = 0.02 + speed / 1000.0f;
        work.unk_ac = 0x222;
        fn_1_58F50(&work);
        n--;
    }
}
/* fzgx:end fn_1_6C87C */

/* fzgx:begin fn_1_6CF3C noprologue */
#include "types.h"

struct fn_1_6CF3C_Vec { f32 x, y, z; };
struct fn_1_6CF3C_Arg0 {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1A[2];
    f32 unk_1C, unk_20, unk_24;
    u8 pad_28[0x14];
    struct fn_1_6CF3C_Vec unk_3C;
    struct fn_1_6CF3C_Vec unk_48;
    u8 pad_54[0x64];
    f32 unk_B8[12];
};
struct fn_1_6CF3C_lbl_1_rodata_2D70 {
    u8 pad_0[0x1C];
    f32 unk_1C;
    u8 pad_20[0x4];
    f32 unk_24;
    u8 pad_28[0x18];
    f64 unk_40;
    f32 unk_48;
    u8 pad_4C[0x18];
    f32 unk_64;
    f64 unk_68;
    u8 pad_70[0x4];
    f32 unk_74;
    u8 pad_78[0x18];
    f32 unk_90;
    f32 unk_94;
    u8 pad_98[0x20];
    f32 unk_B8;
    u8 pad_BC[0x14];
    f64 unk_D0;
    f32 unk_D8;
    u8 pad_DC[0x10];
    f32 unk_EC;
    u8 pad_F0[0x18];
    f64 unk_108;
    u8 pad_110[0xB0];
    f64 unk_1C0;
    u8 pad_1C8[0x38];
    f32 unk_200;
    u8 pad_204[0x4];
    f64 unk_208;
    f32 unk_210;
    u8 pad_214[0x4];
    f64 unk_218;
    f32 unk_220;
    u8 pad_224[0x4];
    f64 unk_228;
    f32 unk_230;
};
extern f32 fn_1_8652C(int);
extern f32 lbl_8006D0B4(f32);
extern s16 fn_1_58F50(const void *);
extern struct fn_1_6CF3C_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern u32 fn_1_584AC(void);
extern void lbl_8006D5F0(f32, void *, void *);
#define lbl_8006D5F0(a, b, c) lbl_8006D5F0((c), (a), (b))
extern void *memset(void *, int, u32);
extern void lbl_8006DD14(const void *, void *);

const u32 fzgx_pool_table_0[7] = {0x0, 0xBF800000, 0x41C80000, 0x41700000, 0x41000000, 0x43160000, 0x41200000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_1c(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 0.5f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_20[1] = {0x3E000000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_24(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 32767.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_28[6] = {0x41F00000, 0x41A00000, 0x44960000, 0x3E19999A, 0x43300000, 0x80000000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_40(void) { /* Preserve this shared literal-pool slot. */ volatile f64 x; x = 4503599627370496.0; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_48(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 255.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_4C[6] = {0x42CC0000, 0x3FE99999, 0x9999999A, 0x3FCCCCCD, 0x40400000, 0x3C23D70A};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_64(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 0.6f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_68(void) { /* Preserve this shared literal-pool slot. */ volatile f64 x; x = 0.3; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_70[1] = {0x3F333333};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_74(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 0.2f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_78[6] = {0x3ECCCCCD, 0x3DCCCCCD, 0x3FC00000, 0x0, 0x40000000, 0x0};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_90(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 0.8f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_94(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 1.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_98[8] = {0x42AA0000, 0x3E800000, 0x0, 0x0, 0x0, 0x42C80000, 0x40600000, 0x41B80000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_b8(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 60.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_BC[5] = {0x40800000, 0x34000000, 0x43080000, 0x3CF5C28F, 0x0};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_d0(void) { /* Preserve this shared literal-pool slot. */ volatile f64 x; x = 0.5; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_d8(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 0.3f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_DC[4] = {0x43000000, 0x43600000, 0x43FA0000, 0x3F6E147B};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_ec(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 5.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_F0[6] = {0x40000000, 0x3D4CCCCD, 0x3DA3D70A, 0x3F666666, 0x3FD33333, 0x40000000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_108(void) { /* Preserve this shared literal-pool slot. */ volatile f64 x; x = 0.2; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_110[44] = {0xBFD33333, 0x33333333, 0xBFF00000, 0x0, 0x0, 0x0, 0x403E0000, 0x0, 0x40080000, 0x0, 0x3A83126F, 0x3B03126F, 0x3FF33333, 0x461C4000, 0x453B8000, 0x43360B61, 0x3F109091, 0x3F30B0B1, 0x4066C16C, 0x20000000, 0x40140000, 0x0, 0x3FE3851E, 0xB851EB85, 0x46800000, 0x0, 0x3DCCCCCD, 0x3FC00000, 0x44480000, 0x447A0000, 0x3FA99999, 0x9999999A, 0x40280000, 0x0, 0xBFC47AE1, 0x47AE147B, 0x405DC000, 0x0, 0x40040000, 0x0, 0x3FF00000, 0x0, 0x449C4000, 0x0};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_1c0(void) { /* Preserve this shared literal-pool slot. */ volatile f64 x; x = 0.4; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_1C8[14] = {0x43960000, 0x0, 0x3FC99999, 0xA0000000, 0x451C4000, 0x459C4000, 0x3FB99999, 0x9999999A, 0x40490000, 0x0, 0x3F33A92A, 0x30553261, 0x3F947AE1, 0x47AE147B};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_200(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 1.2f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_204[1] = {0x0};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_208(void) { /* Preserve this shared literal-pool slot. */ volatile f64 x; x = 0.6; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_210(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 44.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_214[1] = {0x0};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_218(void) { /* Preserve this shared literal-pool slot. */ volatile f64 x; x = 1.3; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_220(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 0.0005f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_224[1] = {0x0};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_228(void) { /* Preserve this shared literal-pool slot. */ volatile f64 x; x = 0.003; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_230(void) { /* Preserve this shared literal-pool slot. */ volatile f32 x; x = 20000.0f; }
#pragma section code_type ".text"

#pragma fp_contract on
static inline f32 fn_1_6CF3C_rand(void) {
    return (f32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
}
static inline s16 fn_1_6CF3C_clamps(f32 x, s16 lo, s16 hi) {
    if ((s16)x < lo) return lo;
    if ((s16)x > hi) return hi;
    return (s16)x;
}
static inline f32 fn_1_6CF3C_clampf(f32 x, f32 lo, f32 hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}
static inline f64 fn_1_6CF3C_clampd(f64 x, f64 lo, f64 hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}

void fn_1_6CF3C(struct fn_1_6CF3C_Arg0 *arg0, struct fn_1_6CF3C_Vec *arg1, f32 arg2, f32 arg3) {
    struct fn_1_6CF3C_lbl_1_rodata_2D70 *p_lbl_1_rodata_2D70;
    s16 v0;
    u32 v1;
    f32 v2;
    f64 v3;
    f64 v4;
    f64 v7;
    f32 v6;
    f64 v5;
    f32 v8;
    s16 v10;
    f32 v11;
    f32 v12;
    f64 v13;
    f32 v14;
    u8 v15;
    f32 v21;
    f64 v22;
    f64 v23;
    f64 v24;
    s16 v25;
    f32 v27;
    f32 v_scale;
    f32 v_random_scale;
    struct { u16 a[116]; } loc_8;
    f32 t0;
    f32 t2;
    f32 v16;
    u32 t5;
    u32 t6;
    u32 t7;
    u32 t8;
    u32 t10;
    u32 t11;

    t0 = fn_1_8652C(arg0->unk_18);
    memset(&loc_8, 0, 232);
    v0 = arg0->unk_18;
    loc_8.a[12] = v0;
    v1 = (0x10000 - 1);
    loc_8.a[6] = 15;
    v7 = 0.3 + (f32)(1.2f * arg2);
    v5 = 0.6 * arg2;
    v6 = 5.0f;
    loc_8.a[13] = v1;
    v15 = 2;
    while (v15) {
        v16 = arg0->unk_48.y;
        t2 = arg0->unk_48.x * arg0->unk_48.x;
        t2 = __fmadds(v16, v16, t2);
        t2 = lbl_8006D0B4(__fmadds(arg0->unk_48.z, arg0->unk_48.z, t2));
        if (t2 > v6) {
            lbl_8006D5F0(&arg0->unk_48, &arg0->unk_48, v6);
        }
        *(struct fn_1_6CF3C_Vec *)((u8 *)&loc_8 + 60) = arg0->unk_3C;
        *(struct fn_1_6CF3C_Vec *)((u8 *)&loc_8 + 72) = arg0->unk_48;
        lbl_8006DD14(arg0->unk_B8, (u8 *)&loc_8 + 184);
        *(struct fn_1_6CF3C_Vec *)((u8 *)&loc_8 + 148) = arg0->unk_3C;
        v21 = (arg2 < 0.3f ? 0.3f : (arg2 > 0.6f ? 0.6f : arg2));
        t2 = (f32)(60.0f * (f32)(0.5f + (f32)(0.5f * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f))));
        t2 *= v21;
        *(s32 *)((u8 *)&loc_8 + 16) = (s32)t2;
        v22 = arg3 * (((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f) - 0.5);
        *(f32 *)((u8 *)&loc_8 + 72) = (f32)((f64)*(f32 *)((u8 *)&loc_8 + 72) + v22);
        v23 = arg3 * (((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f) - 0.5);
        *(f32 *)((u8 *)&loc_8 + 76) = (f32)((f64)*(f32 *)((u8 *)&loc_8 + 76) + v23);
        v24 = arg3 * (((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f) - 0.5);
        *(f32 *)((u8 *)&loc_8 + 80) = (f32)((f64)*(f32 *)((u8 *)&loc_8 + 80) + v24);
        t2 = (f32)(v7 < 0.2 ? 0.2 : (v7 > 1.3 ? 1.3 : v7));
        lbl_8006D5F0(arg1, arg1, t2);
        *(f32 *)((u8 *)&loc_8 + 72) += arg1->x;
        *(f32 *)((u8 *)&loc_8 + 76) += arg1->y;
        *(f32 *)((u8 *)&loc_8 + 80) += arg1->z;
        *(f32 *)((u8 *)&loc_8 + 60) -= arg0->unk_48.x;
        *(f32 *)((u8 *)&loc_8 + 64) -= arg0->unk_48.y;
        *(f32 *)((u8 *)&loc_8 + 68) -= arg0->unk_48.z;
        *(f32 *)((u8 *)&loc_8 + 160) = (f32)(v5 < 0.2 ? 0.2 : (v5 > 0.4 ? 0.4 : v5));
        v25 = (s16)(44.0f * arg2) < 6 ? 6 : ((s16)(44.0f * arg2) > 18 ? 18 : (s16)(44.0f * arg2));
        loc_8.a[86] = v25;
        v27 = 0.8f + (f32)(0.2f * ((f32)(fn_1_584AC() & 0xFFFF) / 32767.0f));
        *(f32 *)((u8 *)&loc_8 + 28) = (f32)(arg0->unk_1C * (f32)(0.5f * (f32)(1.0f + v27))) / 255.0f;
        *(f32 *)((u8 *)&loc_8 + 32) = (f32)(arg0->unk_20 * v27) / 255.0f;
        *(f32 *)((u8 *)&loc_8 + 36) = (f32)(arg0->unk_24 * v27) / 255.0f;
        v27 = (f32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
        *(f32 *)((u8 *)&loc_8 + 136) = 0.0005f * v27;
        *(f32 *)((u8 *)&loc_8 + 140) = (f32)(0.003 + (f32)(t0 / 20000.0f));
        fn_1_58F50(&loc_8);
        v15--;
    }
}
/* fzgx:end fn_1_6CF3C */

/* fzgx:begin fn_1_6D488 */
#include "dolphin/hw_regs.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
    s = 1.1920928955078125e-07f;
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table8[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table10[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table22[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
#pragma section code_type ".text"
struct Sig_fn_1_867CC_fn_1_867CC_Arg1 { u32 unk_0; u32 unk_4; u32 unk_8; };
struct fn_1_6D488_Arg0 { u8 pad_0[0x18]; s16 unk_18; };
extern s16 camera_get_mode(void);
extern u32 fn_1_867CC(u32, struct Sig_fn_1_867CC_fn_1_867CC_Arg1 *);
extern u8 *memset(u8 *, int, u32);
extern u32 fn_1_58C4(void);
extern u32 fn_1_584AC(void);
extern s32 fn_1_66B8(void *, f32);
extern u8 fn_1_86634(int);
extern s16 fn_1_59078(void *);
extern s16 fn_1_58F50(const void *);
extern void lbl_8006DC6C(void *);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void lbl_8006E1B0(void *, void *);
#pragma opt_loop_invariants off
#pragma opt_propagation off
void fn_1_6D488(struct fn_1_6D488_Arg0 *arg0) {
    void * lab_t1;
    u16 count;
    struct { u32 a[58]; } loc_20;
    struct Sig_fn_1_867CC_fn_1_867CC_Arg1 loc_14;
    struct { f32 x,y,z; } loc_8;
    f32 z;
    f32 y;
    fn_1_867CC(arg0->unk_18, &loc_14);
    memset((u8 *)&loc_20, 0, 232);
    *(s16 *)((u8 *)&loc_20 + 24) = arg0->unk_18;
    *(u16 *)((u8 *)&loc_20 + 12) = 17;
    *(u16 *)((u8 *)&loc_20 + 26) = 65535;
    loc_20.a[2] |= 0x40000;
    if (fn_1_58C4() >= 2 || arg0->unk_18 != (s16)camera_get_mode()) count = 1;
    else count = 3;
    while (count) {
        *(s16 *)((u8 *)&loc_20 + 0x54) = fn_1_584AC();
        *(s16 *)((u8 *)&loc_20 + 0x56) = fn_1_584AC();
        *(s16 *)((u8 *)&loc_20 + 0x5a) = (s32)(768.0f + (f32)(768.0f * ((f32)(u16)fn_1_584AC() / 32767.0f)));
        *(s16 *)((u8 *)&loc_20 + 0x5c) = (s32)(768.0f + (f32)(768.0f * ((f32)(u16)fn_1_584AC() / 32767.0f)));
        if (!fn_1_66B8(&loc_14, 4.0f)) break;
        lbl_8006DC6C((u8 *)arg0 + 0xb8);
        {
            struct { f32 *base; } cache;
            f32 x = *(f32 *)&loc_14.unk_0;
            y = *(f32 *)&loc_14.unk_4;
            z = *(f32 *)&loc_14.unk_8;
            cache.base = (f32 *)LC_BASE;
            cache.base[3] = x;
            cache.base[7] = y;
            cache.base[11] = z;
        }
        mathutil_mtxA_rotate_y(*(s16 *)((u8 *)&loc_20 + 0x56));
        mathutil_mtxA_rotate_x(*(s16 *)((u8 *)&loc_20 + 0x54));
        {
            struct { f32 x,y,z; } velocity = {0.0f, 0.0f, -2.0f};
            lab_t1 = (u8 *)&loc_20 + 0x3c;
            lbl_8006E1B0(&velocity, lab_t1);
        }
        *(f32 *)((u8 *)&loc_20 + 0x28) = 4.0f;
        if ((s8)fn_1_86634(arg0->unk_18) != -1) fn_1_59078(&loc_20);
        else fn_1_58F50(&loc_20);
        count--;
    }
}
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_6D488 */

/* fzgx:begin fn_1_6D6A8 */
extern void fn_1_6F90C(void *arg0, void *arg1);
extern s16 fn_1_72318(void);
extern void fn_1_71D0C(void *arg0, void *arg1);

extern void *lbl_801A6410;
extern void fn_1_46B4(u32 value, void *field, u8 *data, s32 code);
extern u32 fn_1_4630(u32 value, u32 size, u8 *data, s32 code);
extern void fn_1_862D4(s16 value, void *result);
extern void fn_1_58E3C(void *entry);
extern u32 fn_1_58C4(void);
extern s8 lbl_1_bss_6C878[];
extern struct fn_1_6F404_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern void * fn_1_868C0(s8);
extern u32 fn_1_71024(void *, void *, u32, f32);
extern u32 fn_1_7099C(void *, void *, u32, f32, f32);
extern u32 fn_1_71768(void *, void *);
extern u32 fn_1_702A0(void *, void *, u32, u32);
extern u32 fn_80008C20(void *, void *, void *);
extern u32 lbl_8006E1C0(void *, void *);
extern u32 fn_1_584AC(void);
extern u32 fn_1_6FD58(void *, void *, f32, f32);
extern u32 fn_1_A33F0(u32, f32);
extern u32 fn_1_6D7BC(void *, void *, f32);
extern u32 fn_1_A5594(u32, void *);
extern u32 fn_1_714A8(void *, void *, u32, f32);

struct Fn1_6D6A8Car {
    u8 pad_00[0x18];
    s16 field_18;
};

struct Fn1_6D6A8Work {
    u8 pad_00[0x8];
    u32 field_08;
    s16 field_0c;
    u8 pad_0e[0xa];
    s16 field_18;
    u16 field_1a;
    f32 field_1c;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    u8 pad_2c[0x8];
    u32 field_34;
    u8 pad_38[0x4];
    f32 field_3c[3];
    u8 pad_48[0x68];
    u16 field_b0;
    u8 pad_b2[0x36];
};

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table42[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
#pragma section code_type ".text"

// Spawn the car effect with a randomised brightness.
void fn_1_6D6A8(struct Fn1_6D6A8Car *car) {
    struct Fn1_6D6A8Work work;
    f32 t;
    f32 ratio;
    f32 scale;

    memset(&work, 0, sizeof(work));
    work.field_18 = car->field_18;
    work.field_0c = 0xe;
    work.field_1a = 0xffff;
    work.field_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x88);
    work.field_08 |= 0x40000;
    fn_1_867CC(car->field_18, work.field_3c);
    work.field_28 = 4.0f;
    work.field_b0 = 0;

    ratio = (f32)(u16)fn_1_584AC() / 32767.0f;
    scale = 0.2f * ratio;
    scale = 0.8f + scale;
    work.field_1c = (255.0f * (0.5f * (1.0f + scale))) / 255.0f;
    work.field_20 = (85.0f * scale) / 255.0f;
    work.field_24 = 0.0f;
    fn_1_59078(&work);
}
/* fzgx:end fn_1_6D6A8 */

/* fzgx:begin fn_1_6DD68 noprologue */
#include "types.h"
#include "rel/main_rel/effect_car.h"

typedef struct { f32 x, y, z; } Fn1_6DD68Vec;

typedef struct Fn1_6DD68Car {
    u8 pad_00[0x18];
    s16 unk_18;
    u8 pad_1a[0x22];
    Fn1_6DD68Vec unk_3c;
    Fn1_6DD68Vec unk_48;
    u8 pad_54[0x64];
    u8 unk_b8[0x30];
} Fn1_6DD68Car;

typedef struct Fn1_6DD68Work {
    u8 pad_00[0xc];
    s16 unk_0c;
    u8 pad_0e[0xa];
    s16 unk_18;
    s16 unk_1a;
    u8 pad_1c[0x18];
    u32 unk_34;
    u8 pad_38[0x4];
    Fn1_6DD68Vec unk_3c;
    Fn1_6DD68Vec unk_48;
    u8 pad_54[0x94];
} Fn1_6DD68Work;

extern f32 fn_1_8652C(int);
extern u16 fn_1_584AC(void);
extern u32 fn_1_58C4(void);
extern s16 camera_get_mode(void);
extern s16 fn_1_58F50(const void *);
extern void *memset(void *dest, int value, u32 size);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern void fn_8006E2B0(void *, void *);
extern u32 lbl_8006E1C0(void *, void *);
extern u32 lbl_801A66A0;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const Fn1_6DD68Vec fzgx_pool_ofs_init = {0.0f, 0.1f, 0.0f};
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
}
#pragma section code_type ".text"

static inline f32 clampf(f32 lo, f32 hi, f32 v) {
    if (v < lo) {
        return lo;
    }
    if (v > hi) {
        return hi;
    }
    return v;
}

static inline f64 jitter(f32 scale) {
    return scale * ((f32)fn_1_584AC() / 32767.0f - 0.5);
}

static inline void vscale(Fn1_6DD68Vec *src, Fn1_6DD68Vec *dst, f32 s) {
    dst->x = src->x * s;
    dst->y = src->y * s;
    dst->z = src->z * s;
}

// Write the translation column of the current matrix in the locked cache.
static inline void set_translation(Fn1_6DD68Vec *v) {
    f32 x = *(volatile f32 *)&v->x; /* Locked-cache column: retain the initial load order. */
    f32 y = v->y;
    f32 z = v->z;
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

// Spawn exhaust/spark particles behind a car, more of them the farther the camera is.
void fn_1_6DD68(Fn1_6DD68Car *car, u32 unused, u32 count) {
    Fn1_6DD68Work work;
    Fn1_6DD68Vec pos;
    Obj_1_data_2A7E0_At3C *obj;
    f32 dist;
    f32 rise;
    f32 ratio;
    f32 spread;
    u8 n;

    obj = lbl_1_data_2A7E0.unk_3C;
    dist = fn_1_8652C(car->unk_18);
    if (0.0f == dist) {
        return;
    }
    if (dist < 100.0f) {
        if ((u16)fn_1_584AC() % 3 != 0) {
            return;
        }
    } else if ((u16)fn_1_584AC() % 4 == 0) {
        return;
    }
    if (!((fn_1_58C4() < 2 && car->unk_18 == camera_get_mode()) || !(lbl_801A66A0 & 1))) {
        return;
    }

    memset(&work, 0, sizeof(work));
    work.unk_18 = car->unk_18;
    work.unk_0c = 20;
    work.unk_1a = 3;
    work.unk_34 = obj->unk_1584;
    ratio = (f32)fn_1_584AC() / 32767.0f;
    {
        Fn1_6DD68Vec ofs = fzgx_pool_ofs_init;
        ofs.x = ratio - 0.5;
        pos = ofs;
    }
    lbl_8006DC6C(car->unk_b8);
    set_translation(&car->unk_3c);
    lbl_8006E1B0(&pos, &pos);

    if (dist < 500.0f) {
        n = 1;
    }
    if (500.0f <= dist && dist < 800.0f) {
        n = 2;
    }
    if (800.0f <= dist) {
        n = count;
    }

    while (n != 0) {
        work.unk_3c = pos;
        vscale(&car->unk_48, &work.unk_48, 1.2f);
        fn_8006E2B0(&work.unk_48, &work.unk_48);
        spread = clampf(0.2f, 2.5f, dist / 400.0f);
        work.unk_48.x += jitter(spread);
        rise = 0.1 + dist / 2000.0f;
        work.unk_48.z += jitter(spread);
        work.unk_48.y += rise;
        lbl_8006E1C0(&work.unk_48, &work.unk_48);
        work.unk_3c.x = work.unk_3c.x - work.unk_48.x;
        work.unk_3c.y = work.unk_3c.y - work.unk_48.y;
        work.unk_3c.z = work.unk_3c.z - work.unk_48.z;
        fn_1_58F50(&work);
        n--;
    }
}
/* fzgx:end fn_1_6DD68 */

/* fzgx:begin fn_1_6E140 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
    s = 1.1920928955078125e-07f;
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table8[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table10[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table22[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0xC0000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 768.0f;
}
static const u32 fzgx_pool_table28[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_T;

typedef struct {
    u8 pad_00[0x0C];
    s16 unk_0C;
    u8 pad_0E[2];
    u32 unk_10;
    u8 pad_14[6];
    s16 unk_1A;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[4];
    Vec3_T unk_3C;
    Vec3_T unk_48;
    u8 pad_54[4];
    s16 unk_58;
    u8 pad_5A[0x8A];
} Loc_T;

typedef struct {
    u8 pad_0[0xE8];
    u32 unk_E8;
} Tgt_T;

extern s16 fn_1_58F50(const void *);
extern u32 fn_1_584AC(void);
extern u32 fn_1_58C4(void);
extern u8 * memset(u8 *, int, u32);

static inline f32 fn_1_6E140_operand(f32 right, f32 left) { return left + right; }
static inline f32 fn_1_6E140_operand_(f32 right, f32 left) { return left + right; }
#pragma opt_propagation off
void fn_1_6E140(Vec3_T *arg0, Vec3_T *arg1, f32 arg2) {
    f32 u;
    f32 t;
    f32 v;
    f32 w;

    if (fn_1_58C4() >= 3) {
        return;
    }
{
    Loc_T x;
    memset((u8 *)&x, 0, 0xE8);
    x.unk_1A = 3;
    x.unk_0C = 22;
    x.unk_34 = ((Tgt_T *)(u8 *)lbl_1_bss_38458->unk_8)->unk_E8;
    x.unk_3C = *arg0;
    x.unk_48 = *arg1;
    x.unk_3C.x = x.unk_3C.x - x.unk_48.x;
    x.unk_3C.y = x.unk_3C.y - x.unk_48.y;
    x.unk_3C.z = x.unk_3C.z - x.unk_48.z;
    t = (f32)(u32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
    w = (f32)(0.2f * t);
    u = 0.8f + w;
    v = arg2 * u;
    x.unk_2C = 5.0f * v;
    x.unk_28 = 3.0f * v;
    t = (f32)(u32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
    w = (f32)(0.2f * t);
    u = 0.8f + w;
    x.unk_1C = (255.0f * (0.5f * (1.0f + u))) / 255.0f;
    x.unk_20 = (224.0f * u) / 255.0f;
    x.unk_24 = (176.0f * u) / 255.0f;
    x.unk_58 = fn_1_584AC();
    x.unk_10 = 22;
    fn_1_58F50(&x);
}
}
#pragma opt_propagation reset
/* fzgx:end fn_1_6E140 */

/* fzgx:begin fn_1_6E320 noprologue */
#include "types.h"
#include "rel/main_rel/effect.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} EffVec;

typedef struct {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1A[0x3C - 0x1A];
    EffVec pos;
    u8 pad_48[0xB4 - 0x48];
    f32 unk_B4;
    u8 unk_B8[0x30];
} EffCar;

typedef struct {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[0x10 - 0xE];
    s32 unk_10;
    u8 pad_14[0x18 - 0x14];
    s16 unk_18;
    s16 unk_1A;
    u8 pad_1C[0x28 - 0x1C];
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0x3C - 0x30];
    EffVec unk_3C;
    EffVec unk_48;
    u8 pad_54[0x9C - 0x54];
    f32 unk_9C;
    u8 pad_A0[0xB8 - 0xA0];
    u8 unk_B8[0x30];
} EffParticle;

extern f32 fn_1_8652C(int);
extern u32 fn_1_584AC(void);
extern s32 fn_1_6EC0(u8);
extern s16 camera_get_entry_field_0xa4(u32);
extern s16 camera_get_mode(void);
extern s32 fn_1_58C4(void);
extern s16 fn_1_59078(Obj_1_bss_6C84C_Target *);
extern s16 fn_1_58F50(const void *);
extern u8 *memset(u8 *, int, u32);
extern void fn_8006F1F0(EffVec *, EffVec *, EffVec *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DD14(void *, void *);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[3] = {0x00000000, 0x3DCCCCCD, 0x40000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

static inline f32 CLAMP(f32 x, f32 lo, f32 hi) {
    return x < lo ? lo : (x > hi ? hi : x);
}

static inline f32 CLAMP2(f32 x, f32 lo, f32 hi) {
    if (x < lo) {
        return lo;
    }
    if (x > hi) {
        return hi;
    }
    return x;
}

#pragma fp_contract off
s16 fn_1_6E320(EffCar *car, EffVec *offset, u8 mode) {
    EffParticle part;
    EffVec pos;
    f32 speed;
    f32 ratio;
    f32 scale;
    f32 diff;
    f64 rnd;
    f32 fade;
    f32 clamped;

    speed = fn_1_8652C(car->unk_18);
    memset((u8 *)&part, 0, sizeof(part));
    part.unk_1A = 1;
    part.unk_C = 25;
    part.unk_18 = car->unk_18;
    diff = 1.8f - speed / 800.0f;
    part.unk_10 = (s32)(60.0f * (0.5f + (f32)(u16)fn_1_584AC() / 32767.0f) / 2.0f * CLAMP(diff, 0.2f, 1.8f));
    pos.x = car->pos.x + offset->x;
    pos.y = car->pos.y + offset->y;
    pos.z = car->pos.z + offset->z;
    if (mode == 1) {
        EffVec up = {0.0f, 1.0f, 0.0f};
        fn_8006F1F0(&car->pos, &up, &pos);
        lbl_8006DB74(part.unk_B8);
    } else {
        part.unk_48.z = 0.05f;
        lbl_8006DD14(car->unk_B8, part.unk_B8);
        if (fn_1_6EC0(0) != 0 && camera_get_entry_field_0xa4(0) == 0) {
            part.unk_9C -= 5.0f;
            part.unk_48.z = 0.0f;
        }
    }
    part.unk_3C.x -= part.unk_48.x;
    part.unk_3C.y -= part.unk_48.y;
    part.unk_3C.z -= part.unk_48.z;
    part.unk_28 = 2.0f;
    ratio = speed / 800.0f;
    scale = CLAMP(ratio, 0.4f, 1.8f);
#pragma fp_contract off
    rnd = 0.33333334f * (0.8f + (f64)(0.2 * ((f32)(u16)fn_1_584AC() / 32767.0f)));
    part.unk_2C = rnd * scale;
#pragma fp_contract on
    fade = speed / 1200.0f;
    car->unk_B4 = 0.5 * CLAMP2(fade, 0.0f, 1.0f);
    if (car->unk_18 == camera_get_mode() && (u32)fn_1_58C4() == 1) {
        return fn_1_59078((Obj_1_bss_6C84C_Target *)&part);
    }
    return fn_1_58F50(&part);
}
/* fzgx:end fn_1_6E320 */

/* fzgx:begin fn_1_6ED40 */
#include "rel/main_rel/car_test.h"

extern void fn_1_6F90C(void *arg0, void *arg1);
extern s16 fn_1_72318(void);
extern void fn_1_71D0C(void *arg0, void *arg1);

extern void *lbl_801A6410;
extern void fn_1_46B4(u32 value, void *field, u8 *data, s32 code);
extern u32 fn_1_4630(u32 value, u32 size, u8 *data, s32 code);
extern void fn_1_862D4(s16 value, void *result);
extern void fn_1_58E3C(void *entry);
extern u32 fn_1_58C4(void);
extern s8 lbl_1_bss_6C878[];
extern struct fn_1_6F404_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern void * fn_1_868C0(s8);
extern u32 fn_1_71024(void *, void *, u32, f32);
extern u32 fn_1_7099C(void *, void *, u32, f32, f32);
extern u32 fn_1_71768(void *, void *);
extern u32 fn_1_702A0(void *, void *, u32, u32);
extern u32 fn_80008C20(void *, void *, void *);
extern u32 lbl_8006E1C0(void *, void *);
extern u32 fn_1_584AC(void);
extern u32 fn_1_6FD58(void *, void *, f32, f32);
extern u32 fn_1_A33F0(u32, f32);
extern u32 fn_1_6D7BC(void *, void *, f32);
extern u32 fn_1_A5594(u32, void *);
extern u32 fn_1_714A8(void *, void *, u32, f32);


/* begin game/main_rel/car_test_types.h (deltawave784/windows-and-types@cf9407c75) */
#ifndef GAME_MAIN_REL_CAR_TEST_TYPES_H
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn183D28Vec3;

extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);

#endif  // GAME_MAIN_REL_CAR_TEST_TYPES_H

/* end game/main_rel/car_test_types.h */

struct fn_1_6ED40_Arg0 {
 u8 pad_0[0x18]; s16 unk_18;
 u8 pad_1A[0x22]; f32 unk_3C, unk_40, unk_44;
 u8 pad_48[0x70]; u8 unk_B8[1];
};
struct EffectPacket6ED40 {
 u8 pad_0[0xc]; s16 kind; u8 pad_E[2]; s32 life;
 u8 pad_14[4]; s16 id, flag; f32 r,g,b,size,speed; u8 pad_30[4]; u32 owner;
 u8 pad_38[4]; Fn183D28Vec3 pos; Fn183D28Vec3 vel;
 u8 pad_54[0x34]; f32 angle, rate; u8 pad_90[0x1c]; s16 texture;
 u8 pad_AE[0x3a];
};
extern f32 fn_1_8652C(int);
extern u32 fn_1_584AC(void);
extern s16 fn_1_58F50(const void *);
extern u8 *memset(u8 *,int,u32);
extern void *lbl_8006DC6C(void *);
extern void lbl_8006E1B0(Fn183D28Vec3 *,Fn183D28Vec3 *);

/* Primer: reproduces the retail TU literal pool (lbl_1_rodata_2D70) layout. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const Fn183D28Vec3 fzgx_pool_offset_init = {0.0f, 0.1f, 1.5f};
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
}
#pragma section code_type ".text"

static inline f32 rand_unit(void) {
 return (f32)(u16)fn_1_584AC()/32767.0f;
}

#pragma opt_propagation off
void fn_1_6ED40(struct fn_1_6ED40_Arg0 *arg0, void *arg1) {
 f32 v20, v4, v6, v9, v12, v19;
 u8 v2;
 struct EffectPacket6ED40 loc_14;
 Fn183D28Vec3 loc_8;
 f32 color, spread;
 f64 clamp;
 f64 random;
 f32 red;
 f32 *dir = (f32 *)arg1;
 v20=fn_1_8652C(arg0->unk_18);
 if (v20 < 300.0f) return;
 memset((u8 *)&loc_14,0,232);
 loc_14.id=arg0->unk_18;
 loc_14.kind=27;
 loc_14.flag=1;
 loc_14.owner=*(u32 *)((u8 *)lbl_1_bss_38458->unk_8+0xb0);
 loc_8=fzgx_pool_offset_init;
 lbl_8006DC6C(arg0->unk_B8);
 {
 f32 z;
 f32 y;
 f32 x;
 /* Volatile preserves the retail translation-column load order. */
 x=*(volatile f32 *)&arg0->unk_3C;
 y=arg0->unk_40;
 z=arg0->unk_44;
 *(f32 *)(0xe0000000+0xc)=x;
 *(f32 *)(0xe0000000+0x1c)=y;
 *(f32 *)(0xe0000000+0x2c)=z;
 }
 lbl_8006E1B0(&loc_8,&loc_8);
 v2=1;
 while(v2) {
 v4=v20/1000.0f;
 v6=v20/1250.0f;
 v19=0.1f+v4;
 v9=v20/5000.0f;
 v12=v20/25.0f;
 loc_14.pos=loc_8;
 loc_14.life=(s32)(60.0f*(0.2f+((f32)(u16)fn_1_584AC()/32767.0f)));
 loc_14.life*=v4 < 0.0 ? 0.0 : v4 > 1.0 ? 1.0 : v4;
 clamp=v6 < 0.2f ? 0.2f : v6 > 0.8 ? 0.8 : v6;
 spread=clamp;
 loc_14.vel.x+=(f64)((f64)spread*(((f32)(u16)fn_1_584AC()/32767.0f)-0.5));
 loc_14.vel.z+=(f64)((f64)spread*(((f32)(u16)fn_1_584AC()/32767.0f)-0.5));
 loc_14.vel.x+=(f32)(dir[0]*v19);
 loc_14.vel.y+=(f32)(dir[1]*v19);
 loc_14.vel.z+=(f32)(dir[2]*v19);
 loc_14.pos.x-=loc_14.vel.x;
 loc_14.pos.y-=loc_14.vel.y;
 loc_14.pos.z-=loc_14.vel.z;
 clamp=v9 < 0.0 ? 0.0 : v9 > 0.2 ? 0.2 : v9;
 loc_14.size=0.1+clamp;
 clamp=v12 < 10.0 ? 10.0 : v12 > 40.0 ? 40.0 : v12;
 random=rand_unit();
 random*=clamp;
 loc_14.speed=30.0+random;
 color=0.8f+(f32)(0.2f*((f32)(u16)fn_1_584AC()/32767.0f));
 loc_14.r=(136.0f*(0.5f*(1.0f+color)))/255.0f;
 loc_14.g=(136.0f*color)/255.0f;
 loc_14.b=(136.0f*color)/255.0f;
 loc_14.angle=0.0003*((f32)(u16)fn_1_584AC()/32767.0f);
 loc_14.rate=(f32)(0.02+v4);
 loc_14.texture=182;
 fn_1_58F50(&loc_14);
 v2--;
 }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_6ED40 */

/* fzgx:begin fn_1_6F288 noprologue */
#include "types.h"

extern s32 fn_1_864E8(s16 arg0);
extern void fn_1_867CC(s16 arg0, void *arg1);
extern s16 fn_1_58F50(const void *arg0);
extern u16 fn_1_584AC(void);
extern void *memset(void *dest, int value, u32 size);

struct EffectCar {
    u8 pad_00[0x18];
    s16 field_18;
    u8 pad_1a[0x1a];
    u32 field_34;
};

struct EffectData {
    u8 pad_00[0x08];
    u32 field_1c;
    u16 field_20;
    u8 pad_22[0x0a];
    s16 field_2c;
    u16 field_2e;
    u8 pad_30[0x1c];
    u32 field_4c;
    u8 pad_50[0x20];
    s16 field_70;
    u8 pad_72[0x3e];
    f32 field_b0;
    u8 pad_b4[0x48];
};

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table42[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
#pragma section code_type ".text"
void fn_1_6F288(struct EffectCar *arg0) {
    s32 result;
    u8 temp[0xc];
    struct EffectData data;
    f32 scale;

    result = fn_1_864E8(arg0->field_18);
    fn_1_867CC(arg0->field_18, temp);
    memset(&data, 0, 0xe8);
    data.field_2c = arg0->field_18;
    data.field_20 = 0x1c;
    data.field_2e = 0xffff;
    data.field_1c |= 0x2000;

    if (result & 8) {
        data.field_4c = arg0->field_34;
        data.field_b0 = 2.5f;
        fn_1_58F50(&data);
        data.field_b0 = -2.5f;
        fn_1_58F50(&data);
    } else {
        data.field_4c = arg0->field_34;
        data.field_b0 = 2.5f;
        scale = 1280.0f * ((f32)fn_1_584AC() / 32767.0f);
        data.field_70 = 4096.0f + scale;
        fn_1_58F50(&data);
        data.field_b0 = -2.5f;
        scale = 1280.0f * ((f32)fn_1_584AC() / 32767.0f);
        data.field_70 = 4096.0f + scale;
        fn_1_58F50(&data);
    }
}
/* fzgx:end fn_1_6F288 */

/* fzgx:begin fn_1_6F404 */
struct fn_1_6F404_lbl_1_rodata_2D70 {
    f32 unk_0;
    u8 pad_4[0x14];
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    f32 unk_28;
    u8 pad_2C[0x48];
    f32 unk_74;
    u8 pad_78[0x4];
    f32 unk_7C;
    u8 pad_80[0x10];
    f32 unk_90;
    u8 pad_94[0x18];
    f32 unk_AC;
    f32 unk_B0;
    u8 pad_B4[0x24];
    f32 unk_D8;
    u8 pad_DC[0x1BC];
    f32 unk_298;
    u8 pad_29C[0x74];
    u32 unk_310;
    u32 unk_314;
    u32 unk_318;
    f32 unk_31C;
    f32 unk_320;
};

void fn_1_6F404(void *arg0, void *arg1) {
    struct fn_1_6F404_lbl_1_rodata_2D70 *tbl;
    u32 sp[3];
    u16 rnd;
    f32 var_f31;
    f32 temp_f0;
    f32 temp_f1;
    void *temp_r30;
    void *temp_r27;
    void *unused;

    unused = arg1;
    tbl = &lbl_1_rodata_2D70;
    temp_r30 = (void *)(*(void **)((u8 *)(arg0) + 56));
    temp_r27 = (void *)(fn_1_868C0((s8)((s8) (*(s16 *)((u8 *)(arg0) + 24)))));
    if ((s16) (*(s16 *)((u8 *)(arg0) + 92)) == 0xA) {
        fn_1_71024((void *)(arg0), (void *)(arg1), (u32)(0x37U), (f32)(tbl->unk_31C));
        fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(0U), (f32)(tbl->unk_18), (f32)(tbl->unk_320));
    }
    if ((s16) (*(s16 *)((u8 *)(arg0) + 92)) == 5) {
        fn_1_71024((void *)(arg0), (void *)(arg1), (u32)(0x37U), (f32)(tbl->unk_31C));
        fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(0U), (f32)(tbl->unk_18), (f32)(tbl->unk_320));
        fn_1_71768((void *)(arg0), (void *)(arg1));
        fn_1_702A0((void *)(arg0), (void *)(arg1), (u32)(0x14U), (u32)(1U));
    }
    if (!((*(s32 *)((u8 *)(temp_r27) + 912)) & 0x01000000) && !((*(s32 *)((u8 *)(temp_r30) + 1420)) & 0x10)) {
        if (!((*(s32 *)((u8 *)(temp_r30) + 0)) & 2)) {
            temp_f1 = *(f32 *)((u8 *)(temp_r30) + 380);
            if (temp_f1 > tbl->unk_320) {
                temp_f0 = temp_f1 / tbl->unk_298;
                sp[0] = tbl->unk_310;
                sp[1] = tbl->unk_314;
                sp[2] = tbl->unk_318;
                var_f31 = tbl->unk_0;
                if (temp_f0 < var_f31) {
                    var_f31 = tbl->unk_0;
                } else if (temp_f0 > tbl->unk_74) {
                    var_f31 = tbl->unk_74;
                } else {
                    var_f31 = temp_f0;
                }
                fn_80008C20((void *)((u8 *)(temp_r30) + 0x7C), (void *)(arg1), (void *)((u8 *)(arg0) + 0x48));
                lbl_8006E1C0((void *)(sp), (void *)(sp));
                rnd = (s32)(u16) fn_1_584AC();
                if ((rnd % 6) == 0) {
                    fn_1_6FD58((void *)(arg0), (void *)(sp), (f32)(var_f31), (f32)(tbl->unk_1C));
                }
                fn_1_A33F0((u32)((u32) (*(s16 *)((u8 *)(temp_r30) + 4))), (f32)(tbl->unk_1C * var_f31));
                if (((u16) (*(u16 *)((u8 *)(temp_r30) + 1248)) < 0x32U)) {
                    rnd = (s32) fn_1_584AC();
                    if ((rnd % 10) == 0) {
                        fn_1_702A0((void *)(arg0), (void *)(sp), (u32)(1U), (u32)(0U));
                    }
                }
            }
        }
        if ((*(s32 *)((u8 *)(temp_r30) + 1420)) & 0x80) {
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 80) == 0) {
                fn_1_6D7BC((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_AC));
                fn_1_6D7BC((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_AC));
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
                fn_1_6FD58((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_D8), (f32)(tbl->unk_90));
                if ((s8) (*(u8 *)((u8 *)(temp_r30) + 1141)) >= 0) {
                    fn_1_A5594((u32)(0xA9092A00U), (void *)((u8 *)(arg0) + 0x3C));
                }
            }
        } else if ((s8) (*(u8 *)((u8 *)(temp_r30) + 1141)) != -1) {
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                if ((s8) (*(u8 *)((u8 *)(temp_r30) + 1141)) >= 0) {
                    fn_1_A5594((u32)(0xA9092A00U), (void *)((u8 *)(arg0) + 0x3C));
                }
                fn_1_6D7BC((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_AC));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                fn_1_714A8((void *)(arg0), (void *)(arg1), (u32)(0x16U), (f32)(tbl->unk_B0));
            }
        } else {
            rnd = (s32) fn_1_584AC();
            if ((rnd % 10) == 0) {
                fn_1_6D7BC((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_AC));
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 20) == 0) {
                fn_1_6FD58((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_D8), (f32)(tbl->unk_90));
            }
        }
    }
}
/* fzgx:end fn_1_6F404 */

/* fzgx:begin fn_1_6F8D0 */
void fn_1_6F8D0(void *arg0, void *arg1) {
    struct EffectData {
        u8 pad_000[0x58c];
        u32 field_58c;
    };
    struct EffectCar {
        u8 pad_00[0x38];
        struct EffectData *field_38;
        u8 pad_3c[0x76];
        u16 field_b2;
    };
    struct EffectCar *self = (struct EffectCar *)arg0;

    if ((self->field_38->field_58c & 0x10) != 0 && self->field_b2 == 0) {
        fn_1_6F90C(arg0, arg1);
    }
}
/* fzgx:end fn_1_6F8D0 */

/* fzgx:begin fn_1_6F90C noprologue */
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

struct EffectCarData {
    u32 flags;
    s16 field_4;
    u8 pad_6[0x475 - 6];
    s8 field_475;
};

struct EffectCar {
    u8 pad_00[0x38];
    struct EffectCarData *data;
    Vec3f pos;
    u8 pad_48[0x5c - 0x48];
    u16 field_5c;
    u8 pad_5e[0xb2 - 0x5e];
    u16 field_b2;
};

/* Pool primer: reproduces the TU literal pool layout ahead of this function. */
#pragma section RX ".fzgxpool"

static const u32 fzgx_pool_table_000[6] = {
    0x00000000, 0xBF800000, 0x41C80000, 0x41700000, 0x41000000, 0x43160000,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer_018(f32 *f) {
    f[0] = 10.0f;
}
static const u32 fzgx_pool_table_01C[2] = {0x3F000000, 0x3E000000};
__declspec(section ".fzgxpool") void fzgx_pool_primer_024(f32 *f) {
    f[0] = 32767.0f;
}
static const u32 fzgx_pool_table_028[4] = {0x41F00000, 0x41A00000, 0x44960000, 0x3E19999A};
__declspec(section ".fzgxpool") void fzgx_pool_primer_038(f32 *f, s32 n) {
    f[0] = (f32)n;
}
static const u32 fzgx_pool_table_040[7] = {
    0x43300000, 0x00000000, 0x437F0000, 0x42CC0000, 0x3FE99999, 0x9999999A, 0x3FCCCCCD,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer_05C(f32 *f) {
    f[0] = 3.0f;
}
static const u32 fzgx_pool_table_060[13] = {
    0x3C23D70A, 0x3F19999A, 0x3FD33333, 0x33333333, 0x3F333333, 0x3E4CCCCD, 0x3ECCCCCD,
    0x3DCCCCCD, 0x3FC00000, 0x00000000, 0x40000000, 0x00000000, 0x3F4CCCCD,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer_094(f32 *f) {
    f[0] = 1.0f;
}
static const u32 fzgx_pool_table_098[21] = {
    0x42AA0000, 0x3E800000, 0x00000000, 0x00000000, 0x00000000, 0x42C80000, 0x40600000,
    0x41B80000, 0x42700000, 0x40800000, 0x34000000, 0x43080000, 0x3CF5C28F, 0x00000000,
    0x3FE00000, 0x00000000, 0x3E99999A, 0x43000000, 0x43600000, 0x43FA0000, 0x3F6E147B,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer_0EC(f32 *f) {
    f[0] = 5.0f;
}
static const u32 fzgx_pool_table_0F0[36] = {
    0x40000000, 0x3D4CCCCD, 0x3DA3D70A, 0x3F666666, 0x3FD33333, 0x40000000, 0x3FC99999,
    0x9999999A, 0xBFD33333, 0x33333333, 0xBFF00000, 0x00000000, 0x00000000, 0x00000000,
    0x403E0000, 0x00000000, 0x40080000, 0x00000000, 0x3A83126F, 0x3B03126F, 0x3FF33333,
    0x461C4000, 0x453B8000, 0x43360B61, 0x3F109091, 0x3F30B0B1, 0x4066C16C, 0x20000000,
    0x40140000, 0x00000000, 0x3FE3851E, 0xB851EB85, 0x46800000, 0x00000000, 0x3DCCCCCD,
    0x3FC00000,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer_180(f32 *f) {
    f[0] = 800.0f;
}
static const u32 fzgx_pool_table_184[102] = {
    0x447A0000, 0x3FA99999, 0x9999999A,
    0x40280000, 0x00000000, 0xBFC47AE1, 0x47AE147B,
    0x405DC000, 0x00000000, 0x40040000, 0x00000000,
    0x3FF00000, 0x00000000, 0x449C4000, 0x00000000,
    0x3FD99999, 0x9999999A, 0x43960000, 0x00000000,
    0x3FC99999, 0xA0000000, 0x451C4000, 0x459C4000,
    0x3FB99999, 0x9999999A, 0x40490000, 0x00000000,
    0x3F33A92A, 0x30553261, 0x3F947AE1, 0x47AE147B,
    0x3F99999A, 0x00000000, 0x3FE33333, 0x33333333,
    0x42300000, 0x00000000, 0x3FF4CCCC, 0xCCCCCCCD,
    0x3A03126F, 0x00000000, 0x3F689374, 0xBC6A7EFA,
    0x469C4000, 0x00000000, 0x3F800000, 0x3F000000,
    0x42080000, 0x00000000, 0x40240000, 0x00000000,
    0x00000000, 0x00000000, 3221225472u, 0x44400000,
    0x00000000, 0x00000000, 0x00000000, 0x41800000,
    0x45800000, 0x40C00000, 0x44E38E39, 0x42EE0000,
    0x424C0000, 0x00000000, 0x3DCCCCCD, 0x00000000,
    0x40200000, 0x43C80000, 0x44FA0000, 0x43300000,
    0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000,
    0x3F800000, 0x00000000, 0x3FE66666, 0x00000000,
    0x3FD55555, 0x60000000, 0x3FE99999, 0xA0000000,
    0x00000000, 0xBF000000, 0x3FA66666, 0xBF99999A,
    0x44BB8000, 0x00000000, 0x3FD99999, 0xA0000000,
    0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000,
    0x40440000, 0x00000000, 3223322624u, 0x44A00000,
    0x00000000, 0x3ECCCCCD, 0x3F800000,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer_31C(f32 *f) {
    f[0] = 2.7f;
    f[1] = 50.0f;
}

extern u32 lbl_801A63C0;

extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_58C4(void);
extern u32 fn_1_6FD58(void *, void *, f32, f32);
extern u32 fn_1_7099C(void *, void *, u32, f32, f32);
extern u32 fn_1_71024(void *, void *, u32, f32);
extern u32 fn_1_71768(void *, void *);
extern u32 fn_1_A5594(u32, void *);
extern void fn_1_681C(u8, Vec3f *);
extern u32 fn_1_702A0(void *, void *, u32, u32);
extern void fn_1_A2D84(u32);
extern void game_camera_set_shake(s16, s16, s32, const Vec3f *);
extern void lbl_8006D5F0(Vec3f *, Vec3f *, f32);

#define EFFECT_RAND() \
    (lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB, (s32)((lbl_801A63C0 >> 16) & 0x7FFF))

static inline f32 effect_distance(Vec3f *a, Vec3f *b) {
    f32 dx = a->x;
    f32 dy = a->y;
    f32 dz = a->z;
    f32 sum;

    dx -= b->x;
    dy -= b->y;
    dz -= b->z;

    sum = dx * dx;
    sum += dy * dy;
    sum += dz * dz;
    return lbl_8006D0B4(sum);
}

static inline f32 effect_clamp(f32 v, f32 lo, f32 hi) {
    f32 r;
    if (v < lo) {
        r = lo;
    } else if (v > hi) {
        r = hi;
    } else {
        r = v;
    }
    return r;
}

void fn_1_6F90C(struct EffectCar *self, void *arg1) {
    struct EffectCarData *data = self->data;
    Vec3f shake;
    u32 count;
    u32 i;
    f32 scale;
    f32 min;
    f32 t;
    f32 a;
    f32 b;

    if (data->flags & 1) {
        return;
    }
    self->field_5c = 15;
    self->field_b2 = 1;
    if (data->field_475 >= 0) {
        Vec3f dir = {0.0f, 0.0f, 0.0f};
        dir.x = EFFECT_RAND() / 32767.0f;
        dir.y = EFFECT_RAND() / 32767.0f;
        dir.z = EFFECT_RAND() / 32767.0f;
        shake = dir;
        lbl_8006D5F0(&shake, &shake, 3.0f);
        game_camera_set_shake(data->field_475, data->field_4,
                              72.0f * (1.0f + EFFECT_RAND() / 32767.0f), &shake);
        fn_1_A2D84(0xA9093000);
    } else {
        fn_1_A5594(0xA9092F00, &self->pos);
    }
    fn_1_71024(self, arg1, 0x37, 5.7f);
    fn_1_702A0(self, arg1, 0x14, 1);
    if (data->field_475 != -1) {
        Vec3f pos;

        count = fn_1_58C4();
        fn_1_681C(0, &pos);
        min = effect_distance(&self->pos, &pos);
        for (i = 1; i < count; i++) {
            fn_1_681C(i, &pos);
            if (min < effect_distance(&self->pos, &pos)) {
                min = min;
            } else {
                min = effect_distance(&self->pos, &pos);
            }
        }
        t = 50.0f * (min / 800.0f);
        scale = effect_clamp(t, 1.0f, 50.0f);
    } else {
        scale = 1.0f;
    }
    if (data->flags & 0x40000000) {
        fn_1_71024(self, arg1, 0x37, 2.7f);
        fn_1_7099C(self, arg1, 0, 10.0f, 50.0f);
        fn_1_71768(self, arg1);
        fn_1_702A0(self, arg1, 0x14, 1);
    }
    a = 5.0f * scale;
    b = 50.0f * scale;
    fn_1_7099C(self, arg1, 0, a, b);
    fn_1_7099C(self, arg1, 0, a, b);
    fn_1_7099C(self, arg1, 0, a, b);
    fn_1_6FD58(self, arg1, 1.0f, 1.0f);
    fn_1_6FD58(self, arg1, 1.0f, 1.0f);
    fn_1_6FD58(self, arg1, 1.0f, 1.0f);
}
/* fzgx:end fn_1_6F90C */

/* fzgx:begin fn_1_6FD58 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
    s = 1.1920928955078125e-07f;
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table8[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table10[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table22[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0xC0000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 768.0f;
}
static const u32 fzgx_pool_table28[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table32[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table34[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table40[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
static const u32 fzgx_pool_table42[3] = {0x00000000, 0x3ECCCCCD, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.700000047683716f;
    s = 50.0f;
}
static const u32 fzgx_pool_table44[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep44(void) { const u32 *volatile cp; cp = fzgx_pool_table44; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime45(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 72.0f;
    s = 5.699999809265137f;
    d = 0.10000000149011612;
    d = 1.399999976158142;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_80008C20_fn_80008C20_Vec;

typedef struct {
    u32 a;
    u32 b;
} Struct_1_6FD58_pair48;

typedef struct {
    u8 pad_00[0x18];
    s16 field_18;
    u16 field_1a;
    f32 field_1c;
    f32 field_20;
    f32 field_24;
    u8 pad_28[0x14];
    f32 field_3c;
    f32 field_40;
    f32 field_44;
    Struct_1_6FD58_pair48 field_48;
    u32 field_50;
    u8 pad_54[0x64];
    u8 field_b8[0x30];
} Struct_1_6FD58;

extern u8 * memset(u8 *, int, u32);
extern u32 fn_1_584AC(void);
extern u32 fn_1_6CF3C(void *, Sig_fn_80008C20_fn_80008C20_Vec *, f32, f32);
extern void lbl_8006DD14(u32, void *);

#pragma opt_strength_reduction off
#pragma opt_dead_assignments off
#pragma opt_lifetimes on
void fn_1_6FD58(Struct_1_6FD58 *arg0, Sig_fn_80008C20_fn_80008C20_Vec *arg1, f32 arg2, f32 arg3) {
    Struct_1_6FD58 s;
    s32 i;
    f32 scale;
    f64 m;

    memset((u8 *)&s, 0, sizeof(s));
    s.field_18 = arg0->field_18;
    s.field_1a = 0xFFFF;
    s.field_1c = 136.0f;
    s.field_20 = 136.0f;
    s.field_24 = 0.0f;
    s.field_48 = arg0->field_48;
    s.field_50 = arg0->field_50;
    lbl_8006DD14((u32)((u8 *)arg0 + 0xb8), (void *)&s.field_b8);
    for (i = 0; i < 2; i++) {
        s.field_3c = arg0->field_3c + ((u16)fn_1_584AC() / 32767.0f - 0.5);
        s.field_40 = arg0->field_40 + ((u16)fn_1_584AC() / 32767.0f - 0.5);
        s.field_44 = arg0->field_44 + ((u16)fn_1_584AC() / 32767.0f - 0.5);
        m = 0.5 * ((u16)fn_1_584AC() / 32767.0f);
        scale = arg2 * (0.1f * (m + 0.5));
        m = 0.5 * ((u16)fn_1_584AC() / 32767.0f);
        fn_1_6CF3C(&s, arg1, scale, arg3 * (1.4f * (m + 0.5)));
    }
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

#pragma opt_strength_reduction reset
/* fzgx:end fn_1_6FD58 */

/* fzgx:begin fn_1_6FFA0 noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn6FFA0Vec;

typedef struct Fn6FFA0Car {
    u8 pad_00[0x18];
    s16 unk_18;
    u8 pad_1a[0x9e];
    u8 unk_b8[4];
} Fn6FFA0Car;

typedef struct Fn6FFA0Work {
    u8 pad_00[0xc];
    s16 unk_0c;
    u8 pad_0e[2];
    u32 unk_10;
    u8 pad_14[4];
    s16 unk_18;
    u16 unk_1a;
    u8 pad_1c[0xc];
    f32 unk_28;
    f32 unk_2c;
    u8 pad_30[0xc];
    Fn6FFA0Vec unk_3c;
    u8 pad_48[0xc];
    s16 unk_54;
    s16 unk_56;
    u8 pad_58[2];
    s16 unk_5a;
    s16 unk_5c;
    u8 pad_5e[0x8a];
} Fn6FFA0Work;

extern void *memset(void *dest, int value, u32 size);
extern void fn_1_867CC(s16 arg0, void *arg1);
extern u32 fn_1_58C4(void);
extern s16 camera_get_mode(void);
extern u16 fn_1_584AC(void);
extern s32 fn_1_66B8(void *arg0, f32 arg1);
extern void lbl_8006DC6C(void *arg0);
extern void mathutil_mtxA_rotate_y(s16 angle);
extern void mathutil_mtxA_rotate_x(s16 angle);
extern void lbl_8006E1B0(Fn6FFA0Vec *arg0, Fn6FFA0Vec *arg1);
extern s16 fn_1_59078(void *arg0);
extern u32 lbl_801A63C0;
/* Set the translation column of the current matrix (locked cache). */
static inline void fn_1_6FFA0_set_translate(f32 x, f32 y, f32 z) {
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table42[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
static const u32 fzgx_pool_table44[14] = {0, 0x3ECCCCCD, 0x3F800000, 0x402CCCCD, 0x42480000, 0, 0, 0, 0x42900000, 0x40B66666, 0x3FB99999, 0xA0000000, 0x3FF66666, 0x60000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep44(void) { const u32 *volatile cp; cp = fzgx_pool_table44; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

/* Inline LCG used by the effect code: next 15-bit random value. */
#define FN6FFA0_RAND() \
    (lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB, (s32)((lbl_801A63C0 >> 16) & 0x7FFF))

#pragma opt_loop_invariants off
#pragma opt_propagation off
void fn_1_6FFA0(Fn6FFA0Car *car, u32 arg1, u32 arg2) {
    Fn6FFA0Vec pos;
    Fn6FFA0Vec dir;
    Fn6FFA0Work work;
    Fn6FFA0Vec tmp;
    register f32 *matrix;
    Fn6FFA0Vec *velocity;
    u16 n;
    u32 random;

    fn_1_867CC(car->unk_18, &pos);
    memset(&work, 0, sizeof(work));
    work.unk_18 = car->unk_18;
    work.unk_0c = 0x21;
    work.unk_1a = 0xffff;
    work.unk_10 = arg2;
    if (fn_1_58C4() >= 2 || car->unk_18 != camera_get_mode()) {
        n = 2;
    } else {
        n = 3;
    }
    goto setup; /* fzgx-allow: S1 shared loop-entry setup is laid out after the loop in retail */
loop:
    for (; n != 0; n--) {
        work.unk_28 = 0.2f;
        random = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        lbl_801A63C0 = random;
        work.unk_2c = 1.2f * (0.5f + (f32)(0.5f * ((f32)(s32)((random >> 16) & 0x7fff) / 32767.0f)));
        work.unk_54 = fn_1_584AC();
        work.unk_56 = fn_1_584AC();
        work.unk_5a = 256.0f + (f32)(1024.0f * ((f32)fn_1_584AC() / 32767.0f));
        work.unk_5c = 256.0f + (f32)(1024.0f * ((f32)fn_1_584AC() / 32767.0f));
        if (fn_1_66B8(&pos, 4.0f) == 0) {
            return;
        }
        lbl_8006DC6C(car->unk_b8);
        {
            {
                f32 fzgx_lc0_z;
                f32 fzgx_lc0_y;
                f32 fzgx_lc0_x;
                fzgx_lc0_x = *(volatile f32 *)&(pos.x); /* fzgx-allow: S2 preserve locked-cache column load order */
                fzgx_lc0_y = (pos.y);
                fzgx_lc0_z = (pos.z);
                matrix = (f32 *)0xE0000000; /* fzgx-allow: A2 locked-cache current matrix address */
                matrix[3] = fzgx_lc0_x;
                matrix[7] = fzgx_lc0_y;
                matrix[11] = fzgx_lc0_z;
            }
        }
        mathutil_mtxA_rotate_y(work.unk_56);
        mathutil_mtxA_rotate_x(work.unk_54);
        {
            Fn6FFA0Vec tmp = {0.0f, 0.0f, 0.0f};

            tmp.z = 3.0f * -((f32)FN6FFA0_RAND() / 32767.0f);
            dir = tmp;
        }
        lbl_8006E1B0(&dir, velocity);
        fn_1_59078(&work);
    }
    return;
setup:
    velocity = &work.unk_3c;
    goto loop; /* fzgx-allow: S1 return from shared loop-entry setup */
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_6FFA0 */

/* fzgx:begin fn_1_702A0 noprologue */
#include "types.h"
#include "rel/main_rel/effect_car.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const unsigned long fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
    s = 1.1920928955078125e-07f;
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const unsigned long fzgx_pool_table8[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const unsigned long fzgx_pool_table10[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const unsigned long fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const unsigned long fzgx_pool_table22[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const unsigned long fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const unsigned long fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0xC0000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const unsigned long *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 768.0f;
}
static const unsigned long fzgx_pool_table28[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const unsigned long *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const unsigned long fzgx_pool_table30[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const unsigned long *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const unsigned long fzgx_pool_table32[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const unsigned long *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const unsigned long fzgx_pool_table34[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const unsigned long *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const unsigned long fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const unsigned long *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const unsigned long fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const unsigned long *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const unsigned long fzgx_pool_table40[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const unsigned long *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
static const unsigned long fzgx_pool_table42[3] = {0x00000000, 0x3ECCCCCD, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const unsigned long *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.700000047683716f;
    s = 50.0f;
}
static const unsigned long fzgx_pool_table44[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep44(void) { const unsigned long *volatile cp; cp = fzgx_pool_table44; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime45(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 72.0f;
    s = 5.699999809265137f;
    d = 0.10000000149011612;
    d = 1.399999976158142;
}
static const unsigned long fzgx_pool_table46[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep46(void) { const unsigned long *volatile cp; cp = fzgx_pool_table46; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime47(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 256.0f;
    s = 1024.0f;
}
static const unsigned long fzgx_pool_table48[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep48(void) { const unsigned long *volatile cp; cp = fzgx_pool_table48; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime49(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05999999865889549f;
}
static const unsigned long fzgx_pool_table50[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep50(void) { const unsigned long *volatile cp; cp = fzgx_pool_table50; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime51(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.03;
    s = 0.003000000026077032f;
}
static const unsigned long fzgx_pool_table52[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep52(void) { const unsigned long *volatile cp; cp = fzgx_pool_table52; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

struct fn_1_702A0_lbl_1_rodata_2D70 {
    u8 pad_0[0x1C]; f32 unk_1C;
    u8 pad_20[4]; f32 unk_24;
    u8 pad_28[0x10]; f64 unk_38; f64 unk_40; f32 unk_48;
    u8 pad_4C[0x24]; f32 unk_70; f32 unk_74; f32 unk_78;
    u8 pad_7C[0x14]; f32 unk_90; f32 unk_94;
    u8 pad_98[0x20]; f32 unk_B8;
    u8 pad_BC[0x14]; f64 unk_D0;
    u8 pad_D8[0x18]; f32 unk_F0;
    u8 pad_F4[0x12C]; f32 unk_220;
    u8 pad_224[0x5C]; f32 unk_280;
    u8 pad_284[0xE4]; f32 unk_368;
    u8 pad_36C[4]; f64 unk_370; f32 unk_378;
};
struct fn_1_702A0_lbl_801A63C0 { u32 unk_0; };
extern struct fn_1_702A0_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern struct fn_1_702A0_lbl_801A63C0 lbl_801A63C0;
extern void *memset(void *, int, u32);
extern u16 fn_1_584AC(void);
extern s16 fn_1_59078(void *);
extern s16 fn_1_58F50(const void *);
extern void lbl_8006D5F0(void *, void *, f32);
struct Vec702A0 { f32 x, y, z; };
struct CarData702A0 { u32 flags; u8 pad4[0x471]; s8 unk475; };
struct Car702A0 {
    u8 pad0[0x18]; s16 unk18; u8 pad1a[0x1e];
    struct CarData702A0 *unk38;
    struct Vec702A0 unk3c, unk48;
};
struct Effect702A0 {
    u8 pad0[0xc]; s16 unkc; u8 pade[2]; s32 unk10;
    u8 pad14[4]; s16 unk18; u16 unk1a;
    f32 unk1c, unk20, unk24, unk28; u32 unk2c, unk30, unk34, unk38;
    struct Vec702A0 unk3c, unk48;
    u8 pad54[6]; s16 unk5a, unk5c, unk5e;
    u8 pad60[0x28]; f32 unk88, unk8c;
    u8 pad90[0x58];
};
static inline s32 rand702A0(struct fn_1_702A0_lbl_801A63C0 *unused) {
    struct fn_1_702A0_lbl_801A63C0 *p = &lbl_801A63C0;
    p->unk_0 = p->unk_0 * 0x676A4B6B + 0x33CB;
    return (p->unk_0 >> 16) & 0x7fff;
}
#define u702(x,bias) ((f32)(u32)(x))
#define s702(x,bias) ((f32)(s32)(x))
void fn_1_702A0(void *arg0, void *arg1, u8 count_arg, u8 arg3) {
    struct fn_1_702A0_lbl_1_rodata_2D70 *p_lbl_1_rodata_2D70;
    struct fn_1_702A0_lbl_801A63C0 *p_lbl_801A63C0;
    struct Car702A0 *self = arg0;
    struct CarData702A0 *v0 = self->unk38;
    u8 arg2 = count_arg;
    struct Effect702A0 loc_8;
    f32 v21;
    f32 v20;
    f32 v19;
    f32 v18;
    f32 v17;
    f32 v16;
    f64 v15;
    f32 v14;
    f64 v13;
    f32 v12;
    f64 v11;
    f32 v10;
    f32 v8;
    f32 v6;
    f32 v4;
    f64 v40;
    f32 v22;
    f32 f0;
    p_lbl_1_rodata_2D70 = (struct fn_1_702A0_lbl_1_rodata_2D70 *)&lbl_1_rodata_2D70;
    if ((v0->flags & 1) == 0) {
        memset(&loc_8, 0, 232);
        loc_8.unk18 = self->unk18;
        loc_8.unkc = 31;
        loc_8.unk1a = 0xffff;
        switch (rand702A0(&lbl_801A63C0) % 5) {
        case 0: loc_8.unk34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 456); break;
        case 1: loc_8.unk34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 464); break;
        case 2: loc_8.unk34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 472); break;
        case 3: loc_8.unk34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 480); break;
        case 4: loc_8.unk34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 488); break;
        }
        arg2 = (u8)arg2;
        v4 = 32767.0f;
        p_lbl_801A63C0 = (struct fn_1_702A0_lbl_801A63C0 *)&lbl_801A63C0;
        v6 = 0.5f;
        v8 = 2.0f;
        v10 = 60.0f;
        v11 = 0.5;
        v12 = 0.4f;
        v14 = 0.06f;
        v15 = 0.03;
        v16 = 0.2f;
        v17 = 0.8f;
        v18 = 51.0f;
        v19 = 1.0f;
        v20 = 255.0f;
        v21 = 0.0005f;
        v22 = 0.003f;
        while ((u8)arg2) {
            loc_8.unk3c = self->unk3c;
            loc_8.unk48 = self->unk48;
            loc_8.unk10 = (s32)(v10 * (v8 + (f32)(v6 * (u702(fn_1_584AC(), v40) / v4))));
            loc_8.unk48.x += (f64)(v12 * (u702(fn_1_584AC(), v40) / v4 - v11));
            loc_8.unk48.y += (f64)(v12 * (u702(fn_1_584AC(), v40) / v4 - v11));
            loc_8.unk48.z += (f64)(v12 * (u702(fn_1_584AC(), v40) / v4 - v11));
            lbl_8006D5F0(arg1, arg1, 0.7f);
            loc_8.unk48.x += ((struct Vec702A0 *)arg1)->x;
            loc_8.unk48.y += ((struct Vec702A0 *)arg1)->y;
            loc_8.unk48.z += ((struct Vec702A0 *)arg1)->z;
            loc_8.unk3c.x -= self->unk48.x;
            loc_8.unk3c.y -= self->unk48.y;
            loc_8.unk3c.z -= self->unk48.z;
            loc_8.unk5a = (s16)(v6 * (s702(rand702A0(p_lbl_801A63C0), v13) * (s702(rand702A0(p_lbl_801A63C0), v13) / v4)));
            loc_8.unk5c = (s16)(v6 * (s702(rand702A0(p_lbl_801A63C0), v13) * (s702(rand702A0(p_lbl_801A63C0), v13) / v4)));
            loc_8.unk5e = (s16)(v6 * (s702(rand702A0(p_lbl_801A63C0), v13) * (s702(rand702A0(p_lbl_801A63C0), v13) / v4)));
            f0 = v14 * (s702(rand702A0(p_lbl_801A63C0), v13) / v4);
            loc_8.unk28 = f0 < v15 ? v15 : v14 * (s702(rand702A0(p_lbl_801A63C0), v13) / v4) > v14 ? v14 : v14 * (s702(rand702A0(p_lbl_801A63C0), v13) / v4);
            f0 = v17 + (f32)(v16 * (u702(fn_1_584AC(), v40) / v4));
            loc_8.unk1c = (f32)(v6 * (v19 + f0)) * v18 / v20;
            loc_8.unk20 = v18 * f0 / v20;
            loc_8.unk24 = v20 * f0 / v20;
            loc_8.unk88 = v21 * (u702(fn_1_584AC(), v40) / v4);
            loc_8.unk8c = v22;
            if (v0->unk475 != -1 && (u8)arg3) fn_1_59078(&loc_8);
            else fn_1_58F50(&loc_8);
            arg2--;
        }
    }
}
/* fzgx:end fn_1_702A0 */

/* fzgx:begin fn_1_71024 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect_car.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
}
#pragma section code_type ".text"

typedef struct Fn1_71024Vec {
    f32 x, y, z;
} Fn1_71024Vec;

typedef struct Fn1_71024Car {
    u8 pad_00[0x18];
    s16 unk_18;
    u8 pad_1a[0x1e];
    u8 *unk_38;
    Fn1_71024Vec pos;
    Fn1_71024Vec vel;
} Fn1_71024Car;

typedef struct Fn1_71024Work {
    u8 pad_00[0xc];
    s16 unk_0c;
    u8 pad_0e[0x2];
    s32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u16 unk_1a;
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2c;
    u8 pad_30[0x4];
    u32 unk_34;
    u8 pad_38[0x4];
    Fn1_71024Vec pos;
    Fn1_71024Vec vel;
    u8 pad_54[0x4];
    u16 unk_58;
    u8 pad_5a[0x5a];
    f32 unk_b4;
    u8 pad_b8[0x30];
} Fn1_71024Work;

extern void *memset(void *dest, int value, u32 size);
extern u16 fn_1_584AC(void);
extern s16 fn_1_59078(void *arg0);
extern u32 fn_1_58C4(void);
extern void fn_1_681C(u8 index, Fn1_71024Vec *pos);
extern f32 lbl_8006D0B4(f32);

static inline f32 fn_1_71024_dist(Fn1_71024Car *car, Fn1_71024Vec *p) {
    f32 dx = car->pos.x;
    f32 dy = car->pos.y;
    f32 dz = car->pos.z;
    f32 sq;
    dx -= p->x;
    dy -= p->y;
    dz -= p->z;
    sq = dx * dx;
    sq += dy * dy;
    sq += dz * dz;
    return lbl_8006D0B4(sq);
}
/* Random offset in [-1, 1]. */
static inline f64 fn_1_71024_jitter(void) {
    return 2.0 * ((f32)fn_1_584AC() / 32767.0f - 0.5);
}

static inline f32 fn_1_71024_clamp(f32 v, f32 lo, f32 hi) {
    return (v < lo) ? lo : ((v > hi) ? hi : v);
}

#define FN_1_71024_DIST(car, p) fn_1_71024_dist(car, &(p))
#define FN_1_71024_SCALE(d) (10.0f * ((d) / 800.0f))

void fn_1_71024(Fn1_71024Car *car, Fn1_71024Vec *vel, u32 count, f32 scale) {
    Fn1_71024Vec point;
    Fn1_71024Work work;
    u8 *owner;
    f32 ratio;
    f32 s;
    f32 t;
    f32 r;
    f32 min;
    u32 n;
    u32 i;

    owner = car->unk_38;
    memset(&work, 0, sizeof(work));
    work.unk_1a = 0xffff;
    work.unk_18 = car->unk_18;
    work.unk_0c = 0x22;
    if (fn_1_584AC() % 2) {
        work.unk_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x50);
    } else {
        work.unk_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x58);
    }
    work.pos.x = car->pos.x + fn_1_71024_jitter();
    work.pos.y = car->pos.y + fn_1_71024_jitter();
    work.pos.z = car->pos.z + fn_1_71024_jitter();
    work.vel = car->vel;
    work.vel.x += (f32)(0.5f * vel->x);
    work.vel.y += (f32)(0.5f * vel->y);
    work.vel.z += (f32)(0.5f * vel->z);
    work.pos.x -= work.vel.x;
    work.pos.y -= work.vel.y;
    work.pos.z -= work.vel.z;

    ratio = (f32)fn_1_584AC() / 32767.0f;
    s = 0.2f * ratio;
    s = 0.8f + s;
    work.unk_2c = scale * s;
    work.unk_28 = 0.2f * s;

    ratio = (f32)fn_1_584AC() / 32767.0f;
    s = 0.2f * ratio;
    s = 0.8f + s;
    work.unk_1c = (255.0f * (0.5f * (1.0f + s))) / 255.0f;
    work.unk_20 = (136.0f * s) / 255.0f;
    work.unk_24 = 0.0f;

    work.unk_58 = fn_1_584AC();
    ratio = (f32)fn_1_584AC() / 32767.0f;
    s = 0.2f * ratio;
    s = 0.8f + s;
    work.unk_10 = (s16)(s * (f32)count);

    if ((s8)owner[0x475] != -1) {
        n = fn_1_58C4();
        fn_1_681C(0, &point);
        min = FN_1_71024_DIST(car, point);
        for (i = 1; i < n; i++) {
            fn_1_681C(i, &point);
            if (min < FN_1_71024_DIST(car, point)) {
                min = min;
            } else {
                min = FN_1_71024_DIST(car, point);
            }
        }
        /* clamp 10 * min / 800 to [1, 10] */
        r = 1.0f;
        r = (FN_1_71024_SCALE(min) < r) ? r
          : (FN_1_71024_SCALE(min) > 10.0f) ? 10.0f
          : FN_1_71024_SCALE(min);
        work.unk_b4 = r;
    } else {
        work.unk_b4 = 1.0f;
    }
    fn_1_59078(&work);
}
/* fzgx:end fn_1_71024 */

/* fzgx:begin fn_1_714A8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect_car.h"
#include "dolphin/hw_regs.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect_car.h"
#include "dolphin/hw_regs.h"

/* begin game/main_rel/effect_car_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_EFFECT_CAR_TYPES_H
#define GAME_MAIN_REL_EFFECT_CAR_TYPES_H

// Types (and the externs that name them) of effect_car.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


struct fn_1_72318_EffectCar {
    u8 pad_18[0x18];
    s16 field_18;
    u8 pad_1a[0x1e];
    u32 field_38;
    u8 pad_3c[0x7c];
    u8 field_b8;
};

struct fn_1_6F404_lbl_1_rodata_2D70 {
    f32 unk_0;
    u8 pad_4[0x14];
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    f32 unk_28;
    u8 pad_2C[0x48];
    f32 unk_74;
    u8 pad_78[0x4];
    f32 unk_7C;
    u8 pad_80[0x10];
    f32 unk_90;
    u8 pad_94[0x18];
    f32 unk_AC;
    f32 unk_B0;
    u8 pad_B4[0x24];
    f32 unk_D8;
    u8 pad_DC[0x1BC];
    f32 unk_298;
    u8 pad_29C[0x74];
    u32 unk_310;
    u32 unk_314;
    u32 unk_318;
    f32 unk_31C;
    f32 unk_320;
};

typedef struct Fn1_714A8Vec {
    f32 x;
    f32 y;
    f32 z;
} Fn1_714A8Vec;

struct Fn1_714A8Car {
    u8 pad_00[0x38];
    u8 *field_38;
    f32 field_3c;
    f32 field_40;
    f32 field_44;
    Fn1_714A8Vec field_48;
};

extern struct fn_1_6F404_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern void fn_1_714A8(struct Fn1_714A8Car *car, f32 *axis, u32 arg2, f32 size);

#endif  // GAME_MAIN_REL_EFFECT_CAR_TYPES_H

/* end game/main_rel/effect_car_types.h */

extern void *memset(void *dest, int value, u32 size);
extern void *lbl_801A6410;
extern void fn_1_867CC(s16 arg0, void *arg1);
extern u16 fn_1_584AC(void);
extern s16 fn_1_59078(void *arg0);
extern u32 fn_1_864E8(int index);
extern s16 fn_1_58F50(const void *source);
extern u32 lbl_1_rodata_314C[13];
extern void lbl_8006DC6C(void *arg0, u32 arg1);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void fn_1_6F90C(void *arg0, void *arg1);
extern s16 fn_1_72318();
extern void fn_1_71D0C(void *arg0, void *arg1);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 fn_1_4630();
extern void fn_1_862D4(s16 value, void *result);
extern s16 fn_1_58E3C(void *source);
extern u32 fn_1_58C4(void);
extern s8 lbl_1_bss_6C878[];
extern void *fn_1_868C0(s8 index);
extern u32 fn_1_71024(void *, void *, u32, f32);
extern u32 fn_1_7099C(void *, void *, u32, f32, f32);
extern u32 fn_1_71768(void *, void *);
extern u32 fn_1_702A0(void *, void *, u32, u32);
extern u32 fn_80008C20(void *, void *, void *);
extern u32 lbl_8006E1C0(void *, void *);
extern u32 fn_1_6FD58(void *, void *, f32, f32);
extern void fn_1_A33F0(s32 id, f32 level);
extern u32 fn_1_6D7BC(void *, void *, f32);
extern u32 fn_1_A5594(u32, void *);

struct Fn1_714A8Work {
    u8 pad_00[0xc];
    s16 field_0c;
    u8 pad_0e[0x2];
    u32 field_10;
    u8 pad_14[0x6];
    u16 field_1a;
    f32 field_1c;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2c;
    u8 pad_30[0x4];
    u32 field_34;
    u8 pad_38[0x4];
    f32 field_3c;
    f32 field_40;
    f32 field_44;
    Fn1_714A8Vec field_48;
    u8 pad_54[0x4];
    u16 field_58;
    u8 pad_5a[0x8e];
};

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table42[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
#pragma section code_type ".text"

// Spawn a jittered car effect: random position offset, velocity pushed along the
// supplied axis, randomised size and colour.
void fn_1_714A8(struct Fn1_714A8Car *car, f32 *axis, u32 arg2, f32 size) {
    u8 *state;
    struct Fn1_714A8Work work;
    f32 ratio;
    f32 scale;
    f32 push;

    state = car->field_38;
    memset(&work, 0, sizeof(work));
    work.field_1a = 0xffff;
    work.field_0c = 0x16;
    work.field_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x168);

    work.field_3c = car->field_3c + (f64)(2.0 * (((f32)(u16)fn_1_584AC() / 32767.0f) - 0.5));
    work.field_40 = car->field_40 + (f64)(2.0 * (((f32)(u16)fn_1_584AC() / 32767.0f) - 0.5));
    work.field_44 = car->field_44 + (f64)(2.0 * (((f32)(u16)fn_1_584AC() / 32767.0f) - 0.5));

    work.field_48 = car->field_48;
    work.field_48.x += (f32)(0.2f * axis[0]);
    work.field_48.x += (f32)(0.2f * axis[0]);
    work.field_48.x += (f32)(0.2f * axis[0]);
    work.field_3c -= work.field_48.x;
    work.field_40 -= work.field_48.y;
    work.field_44 -= work.field_48.z;

    ratio = (f32)(u16)fn_1_584AC() / 32767.0f;
    scale = 0.2f * ratio;
    scale = 0.8f + scale;
    work.field_2c = size * scale;
    work.field_28 = 0.5f * scale;

    ratio = (f32)(u16)fn_1_584AC() / 32767.0f;
    scale = 0.2f * ratio;
    scale = 0.8f + scale;
    work.field_1c = (255.0f * (0.5f * (1.0f + scale))) / 255.0f;
    work.field_20 = (136.0f * scale) / 255.0f;
    work.field_24 = 0.0f;

    work.field_58 = (u32)fn_1_584AC();
    work.field_10 = arg2;
    if ((s8)state[0x475] != -1) {
        fn_1_59078(&work);
    } else {
        fn_1_58F50(&work);
    }
}
/* fzgx:end fn_1_714A8 */

/* fzgx:begin fn_1_71CA0 */
void fn_1_71CA0(void *arg0, void *arg1, u16 arg2) {
    if (arg2 == 0xb4) {
        ((struct {
            u8 pad[0x58];
            s16 field_58;
        } *)arg0)->field_58 = fn_1_72318();
    }
    if (arg2 == 0xaa) {
        fn_1_71D0C(arg0, arg1);
    }
}
/* fzgx:end fn_1_71CA0 */

/* fzgx:begin fn_1_72318 noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"

extern void fn_1_867CC(s16 arg0, void *arg1);
extern u32 lbl_1_rodata_314C[13];
extern void lbl_8006DC6C(void *arg0, u32 arg1);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern s16 fn_1_59078(void *arg0);
extern void *memset(void *dest, int value, u32 size);

struct EffectCar {
    u8 pad_18[0x18];
    s16 field_18;
    u8 pad_1a[0x1e];
    u32 field_38;
    u8 pad_3c[0x7c];
    u8 field_b8;
};

struct EffectWorkData {
    u8 pad_00[0xc];
    s16 field_0c;
    u8 pad_0e[0xa];
    s16 field_18;
    u16 field_1a;
    u8 pad_1c[0x1c];
    u32 field_38;
    u32 field_3c;
    u32 field_40;
    u32 field_44;
    u8 pad_48[0x14];
    s16 field_5c;
    u8 pad_5e[0x8a];
};

#pragma opt_propagation off
s16 fn_1_72318(struct EffectCar *arg0) {
    f32 vec[3];
    struct EffectWorkData data;
    u32 lab_t0;
    f32 v0, v1, v2;

    lab_t0 = arg0->field_18;

    fn_1_867CC(lab_t0, vec);
    memset(&data, 0, sizeof(data));

    data.field_18 = arg0->field_18;
    data.field_0c = 0x25;
    data.field_38 = arg0->field_38;
    data.field_1a = 0xffff;
    lbl_8006DC6C(&arg0->field_b8, data.field_38);

    v2 = vec[0];
    v1 = vec[1];
    v0 = vec[2];

    // These are effect-engine scratch registers used to pass the generated vector.
    // fzgx-allow: A2 hardware scratch register addresses are encoded by the target.
    *(volatile f32 *)(LC_BASE + 0xC) = v2;
    // fzgx-allow: A2 hardware scratch register addresses are encoded by the target.
    *(volatile f32 *)(LC_BASE + 0x1C) = v1;
    // fzgx-allow: A2 hardware scratch register addresses are encoded by the target.
    *(volatile f32 *)(LC_BASE + 0x2C) = v0;

    data.field_3c = lbl_1_rodata_314C[0];
    data.field_40 = lbl_1_rodata_314C[1];
    data.field_44 = lbl_1_rodata_314C[2];
    lbl_8006E1B0(&data.field_3c, &data.field_3c);

    data.field_5c = 0x100;
    return fn_1_59078(&data);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_72318 */

/* fzgx:begin fn_1_723E0 noprologue */
#include "types.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "types.h"

/* begin game/main_rel/car_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_CAR_TYPES_H
#define GAME_MAIN_REL_CAR_TYPES_H

// Types (and the externs that name them) of car.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    u8 pad0[0x1c];
    void *field_1c;
} CarObject;

typedef struct {
    u8 pad0[0x12];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    void *field_28;
    u8 pad2c[0x8];
    void *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} EventNode;

typedef struct {
    u8 pad0[0x24];
    void *field_24;
} EventData;

typedef struct {
    u8 pad0[0x8];
    EventData *field_8;
    void *field_c;
} EventObject;

struct fn_1_7F954_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_7FA04_lbl_801A6410 {
    u32 unk_0;
};

typedef struct {
    u8 pad0[0x40];
    void *value;
} ResourceHolder;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} RawVec3;

/* begin game/vec3.h (deltawave784/fzgx, CC0) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */

typedef struct {
    u8 _pad_000[0x7c];
    Vec3 field_07c;
    u8 _pad_088[0xc4];
    Vec3 field_14c;
} Fn184644Object;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Triple;

typedef struct Fn195158Object Fn195158Object;

struct Fn195158Object {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

struct TargetObj {
    char pad[0x60];
    char field_0x60[0xc];
    f32 field_0x6c;
    char pad2[0xc];
    f32 field_0x7c;
};

struct ModelItem {
    u32 flags;
    char pad[0x1c];
};

struct Model {
    char pad[0x18];
    u16 count;
    char pad2[0x26];
    struct ModelItem items[1];
};

typedef struct {
    u32 entries[41];
} FnTable;

typedef struct {
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
} Fn1_8F45C_Object;

typedef struct {
    s32 active;
    s32 entries[5];
} Fn1_8F494_Object;

typedef struct {
    u8 pad_0[0x148];
    u8 pad_148[0x20];
    u8 pad_168[0x40];
    u8 pad_1a8[0x20];
    u8 pad_1c8[0x20];
    u8 pad_1e8[0x20];
    u8 entries[0x14][0x20];
} Fn1_8F5A4_Object;

typedef struct Fn195158Data Fn195158Data;

struct Fn195158Data {
    u8 unk_00[0x08];
    Fn195158Object *unk_08;
};

typedef struct Fn195158Car Fn195158Car;

struct Fn195158Car {
    u8 unk_00[0xA0];
    s16 unk_A0;
    s16 unk_A2;
    s16 unk_A4;
    u8 unk_A6[0x02];
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    u8 unk_BC[0x94];
    Fn195158Data *unk_150;
};

typedef struct Fn935E4Slot {
    u8 pad0[0xa];
    u16 field_a;
} Fn935E4Slot;

typedef struct Fn935E4Node {
    u8 pad0[0xa];
    u16 field_a;
    u8 pad_c[6];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    u8 pad27[1];
    Fn935E4Slot *field_28;
    u8 pad2c[8];
    Fn935E4Slot *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} Fn935E4Node;

typedef struct {
    u8 pad0[0x12];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    void *field_28;
    u8 pad2c[8];
    void *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} Node;

typedef struct Fn935E4Car {
    u8 pad0[0x1c];
    Fn935E4Node *field_1c;
} Fn935E4Car;

typedef struct {
    u8 pad0[0x24];
    void *field_24;
    f32 field_28;
    f32 field_2c;
} OutData;

typedef struct {
    u8 pad0[0x1c];
    Node *field_1c;
    u8 pad20[0x128];
    u16 field_148;
    u8 pad14a[6];
    OutData *field_150;
    void *field_154;
} Owner;

typedef struct Fn1967A8Resource Fn1967A8Resource;

struct Fn1967A8Resource {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

typedef struct Fn196968Object Fn196968Object;

struct Fn196968Object {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};

typedef struct Fn1969E8Owner Fn1969E8Owner;

struct Fn1969E8Owner {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};

typedef struct Fn196BC0Object Fn196BC0Object;

struct Fn196BC0Object {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};

typedef struct Fn196A68Object Fn196A68Object;

struct Fn196A68Object {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};

typedef struct CarR29 {
    u8 unk_00[0x14];
    f32 unk_14;
} CarR29;

/* game/vec3.h: inlined above */

typedef struct fn_1_8D210_car {
    f32 position[6];
    f32 scale_z;
    f32 scale_y;
    f32 scale_x;
    f32 field_24;
    u16 field_28;
    u16 field_2a;
    u16 field_2c;
    u16 field_2e;
    u16 field_30;
    u16 field_32;
    u32 field_34;
    u8 field_38;
    u8 field_39;
    u8 field_3a;
    u8 pad_3b;
    u32 field_3c;
    u8 field_40;
    u8 pad_41[3];
    f32 field_44;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s16 field_54;
    u8 pad_56[2];
    s32 field_58;
    u8 field_5c[4];
    u32 field_60;
} fn_1_8D210_car;

typedef s32 (*fn_1_8D210_callback)(u32);

typedef struct {
    u8 pad[0x15];
    u8 code;
} State;

typedef struct {
    u8 pad[4];
    State *state;
} fn_1_8E3A4_Object;

typedef struct {
    u8 pad_0[0x400];
    u8 mtx[0x70];
    u8 mtx2[0x30];
} CamObj;

typedef struct {
    u8 pad_0[0x118];
    u32 unk_118;
    u32 unk_11C;
    u8 pad_120[0x20];
    s32 unk_140;
    f32 unk_144;
    f32 unk_148;
    f32 unk_14C;
    f32 unk_150;
} CarSound;

typedef struct {
    u32 flags;
    u8 pad_4[0x498];
    CarSound *sound;
} fn_1_85F90_Car;

extern s32 fn_1_8D210(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg, s32 enable);
extern void fn_1_95158(Fn195158Car *car);
extern s32 fn_1_97174(EventNode *arg0, s32 arg1, void *arg2);
extern void fn_1_93734(CarObject *arg0, void *arg1);
extern Fn1967A8Resource *fn_1_41518(void *arg0);
extern void fn_1_41C18(Fn1967A8Resource *arg0, void *arg1);
extern void fn_1_41F58(Fn1967A8Resource *arg0, s32 arg1, void (*arg2)(void), void *arg3);
extern u16 fn_1_96968(Fn196968Object *object, void *arg1);
extern u16 fn_1_969E8(Fn1969E8Owner *owner, void *arg1);
extern u16 fn_1_96BC0(Fn196BC0Object *object, void *arg1);
extern u16 fn_1_96A68(Fn196A68Object *object, void *arg1);
extern CarR29 *fn_80071268(void *, void *);
extern void lbl_8006E1F0(Vec3f *, f32, f32, f32);
extern void lbl_8006E2C0(Vec3f *, f32, f32, f32);
extern void fn_8006E250(Vec3f *, Vec3f *);
extern void fn_1_B81C(Vec3f *, Vec3f *, s32);
extern void lbl_8006DBAC(Vec3 *a);
extern void fn_1_8E3A4(fn_1_8E3A4_Object *obj);
extern f32 lbl_8006D534(Vec3 *a, Vec3 *b);
extern Triple lbl_1_rodata_3BE8;
extern void fn_1_55210(struct Model *);
/* retail takes (obj, idx, mask, mask2) (fn_1_8F198 passes all four); non-prototype until fn_1_8F45C passes its own four through */
extern void fn_1_8E7D0();
extern void fn_1_966A0(Fn1_8F494_Object *obj);
extern void fn_1_8F5A4(Fn1_8F5A4_Object *obj);
extern void fn_1_968FC(Fn1_8F5A4_Object *obj);
extern void fn_1_943F8(Fn935E4Car *, f32, void *);

#endif  // GAME_MAIN_REL_CAR_TYPES_H

/* end game/main_rel/car_types.h */

typedef struct {
    f32 x, y, z;
} EffVec;

typedef struct {
    u8 pad_0[0xC];
    s16 type;
    u8 pad_E[0x18 - 0xE];
    s16 id;
    u16 unk_1A;
    f32 r;
    f32 g;
    f32 b;
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0x48 - 0x30];
    EffVec unk_48;
    u8 pad_54[0x94 - 0x54];
    EffVec unk_94;
    u8 pad_A0[0xE8 - 0xA0];
} EffectParam;

typedef struct {
    u8 pad_0[0x18];
    s16 id;
} EffectCar;

extern u32 lbl_801A66A0;
extern void fn_1_862D4(int, Triple *);
extern s32 fn_1_58C4(void);
extern s16 camera_get_mode(void);
extern u32 fn_1_584AC(void);
extern s16 fn_1_58F50(const void *);
extern void *memset(void *, int, u32);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table42[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
static const u32 fzgx_pool_table44[0x36] = {
    0x00000000, 0x3ECCCCCD, 0x3F800000, 0x402CCCCD, 0x42480000,
    0x00000000, 0x00000000, 0x00000000, 0x42900000, 0x40B66666,
    0x3FB99999, 0xA0000000, 0x3FF66666, 0x60000000, 0x00000000,
    0x00000000, 0x00000000, 0x43800000, 0x44800000, 0x00000000,
    0x00000000, 0x00000000, 0x3D75C28F, 0x00000000, 0x3F9EB851,
    0xEB851EB8, 0x3B449BA6, 0x00000000, 0x3DCCCCCD, 0x00000000,
    0x41100000, 0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x3FB33333,
    0x43480000, 0x435C0000, 0x43570000, 0x43700000, 0x3FA66666,
    0x40733333, 0x3F000000, 0xBFA66666, 0x40733333, 0x3F000000,
    0x00000000, 0x40733333, 0xBF800000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x40A00000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep44(void) { const u32 *volatile cp; cp = fzgx_pool_table44; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

void fn_1_723E0(EffectCar *car)
{
    Triple pos;
    EffectParam param;
    u16 count;
    f32 v;

    if (lbl_801A66A0 % 5 != 0) {
        return;
    }
    fn_1_862D4(car->id, &pos);
    memset(&param, 0, sizeof(param));
    param.id = car->id;
    param.type = 0x27;
    param.unk_1A = 0xFFFF;
    if ((u32)fn_1_58C4() >= 2 || car->id != camera_get_mode()) {
        count = 1;
    } else {
        count = 1;
    }
    while (count) {
        EffVec a = {0.0f, 1.0f, 0.0f};
        EffVec b = {0.0f, -0.07f, 0.0f};

        param.unk_94 = a;
        param.unk_48 = b;
        param.unk_28 = 0.0f;
        param.unk_2C = 13.0f;
        v = 0.8f + (f32)(0.2f * ((u16)fn_1_584AC() / 32767.0f));
        param.r = 140.0f * v / 255.0f;
        param.g = 70.0f * v / 255.0f;
        param.b = 20.0f * (0.5f * (1.0f + v)) / 255.0f;
        fn_1_58F50(&param);
        count--;
    }
}
/* fzgx:end fn_1_723E0 */
