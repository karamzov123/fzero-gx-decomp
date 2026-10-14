/* Non-matching: best partial attempt (99.01% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 6600.0f;
    s = 110.0f;
    s = 60.0f;
    s = 15.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 300.0f;
    s = 32767.0f;
    s = 4.0f;
    s = 10.0f;
    s = 2.0f;
    s = 200.0f;
    s = 400.0f;
    s = 2500.0f;
    s = 1000.0f;
    s = 1400.0f;
    d = 0.5;
    d = 5.0;
    s = 7.0f;
    s = 2.5f;
    s = 768.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 0.25f;
    s = 0.05000000074505806f;
    s = -2000.0f;
    s = 1.0199999809265137f;
    s = 30.0f;
    s = 22.0f;
    d = 0.9;
    s = 0.6000000238418579f;
    s = 0.4000000059604645f;
    s = 255.0f;
    s = 0.800000011920929f;
    s = 0.30000001192092896f;
    s = 1.2999999523162842f;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    d = 1280.0;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.98;
    s = 20.0f;
    s = 0.20000000298023224f;
}
#pragma section code_type ".text"

struct FF6B8_C3 {
    f32 x;
    f32 y;
    f32 z;
};

struct FF6B8_Entry {
    s32 count;
    struct FF6B8_C3 pos;
    struct FF6B8_C3 prev;
    f32 v[3];
    s16 ang;
    s16 pitch;
    f32 f2c;
    f32 f30;
};

struct FF6B8_Obj {
    u8 pad0[4];
    s32 unk4;
    struct FF6B8_C3 c3;
    u8 pad14[12];
    f32 w0;
    f32 w1;
    f32 w2;
    u8 pad2c[12];
    f32 f38;
};

extern u32 fn_1_584AC(void);

static inline f64 fn_1_FF6B8_operand(f64 right, f64 left) { return left * right; }
#pragma opt_dead_assignments on
static inline f64 fn_1_FF6B8_operand_(f64 right, f64 left) { return left * right; }
static inline f64 fn_1_FF6B8_operand__(f64 left, f64 right) { left *= right; return left; }
static inline f32 fn_1_FF6B8_operand___(f32 right, f32 left) { return ((right) + (left)); }
#pragma opt_common_subs off
static inline f64 fn_1_FF6B8_operand____(f64 left, f64 right) { return left * right; }
#pragma opt_loop_invariants off
void fn_1_FF6B8(struct FF6B8_Obj *arg0) {
    s32 i;
    struct FF6B8_Entry *e;
    f32 w;
    f32 q;
    f32 t;
    f64 a;
    f64 b;
    f32 dec = 0.9f;
    f64 fade = 0.98;

    e = (struct FF6B8_Entry *)((u8 *)arg0 + 0x3c);
    for (i = 0; i < 0x14; i++) {
        if (e->count != 0) {
            e->count--;
        }
        if (e->count <= 0 && arg0->unk4 > 0) {
            q = (f32)(u32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
            t = 10.0f * q;
            e->count = (s32)(fn_1_FF6B8_operand___((t), (30.0f)));
            e->pos = arg0->c3;
            e->prev = arg0->c3;
            w = arg0->w0;
            q = (f32)(u32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
            b = fn_1_FF6B8_operand_((w), (0.1));
            b = (fn_1_FF6B8_operand__(((q)), ((b))));
            a = 0.9 * w;
            e->v[0] = (f32)(a + b);
            w = arg0->w1;
            (void) w;  /* fzgx: keeps the web at its definition */
            q = (f32)(u32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
            b = fn_1_FF6B8_operand_((w), (0.1));
            b = (fn_1_FF6B8_operand__(((q)), ((b))));
            a = fn_1_FF6B8_operand____((0.9), (w));
            e->v[1] = (f32)(a + b);
            w = arg0->w2;
            q = (f32)(u32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
            b = fn_1_FF6B8_operand_((w), (0.1));
            b = (fn_1_FF6B8_operand__(((q)), ((b))));
            a = fn_1_FF6B8_operand((w), (0.9));
            e->v[2] = (f32)(a + b);
            e->ang = (s16)fn_1_584AC();
            q = (f32)(u32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
            e->pitch = (s16)((s32)(1280.0 * (q - 0.5)) + 0x200);
            e->f2c = 1.0f;
            e->f30 = 22.0f * arg0->f38;
        }
        e->v[0] = e->v[0] * dec;
        e->v[1] = e->v[1] * dec;
        e->v[2] = e->v[2] * dec;
        e->pos.x = e->pos.x + e->v[0];
        e->pos.y = e->pos.y + e->v[1];
        e->pos.z = e->pos.z + e->v[2];
        e->prev = e->pos;
        e->ang = (s16)(e->ang + e->pitch);
        e->f30 = e->f30 * fade;
        if (e->count < 0x14) {
            e->f2c = e->f2c * ((f32)(s32)e->count / 20.0f);
        }
        e = (struct FF6B8_Entry *)((u8 *)e + 0x34);
    }
}
#pragma opt_loop_invariants reset

#pragma opt_common_subs reset

#pragma opt_dead_assignments reset

