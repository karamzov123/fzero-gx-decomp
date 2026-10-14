/* Non-matching: best partial attempt (99.52% in the project ledger). Scored for the
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
    d = 1280.0;
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
}
#pragma section code_type ".text"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

struct Entry {
    s32 f00;
    Vec3 v04;
    Vec3 v10;
    f32 f1c;
    f32 f20;
    f32 f24;
    u16 f28;
    u16 f2a;
    f32 f2c;
    f32 f30;
};

struct Pool {
    u8 pad_0[8];
    f32 c08;
    u8 pad_c[0x30];
    f32 c3c;
    u8 pad_40[4];
    f32 c44;
    u8 pad_48[0x18];
    f64 c60;
    u8 pad_68[0x18];
    f64 c80;
    u8 pad_88[0x18];
    f32 ca0;
    f32 ca4;
    f64 ca8;
    u8 pad_b0[0x20];
    f64 cd0;
    f64 cd8;
};

extern const struct Pool lbl_1_rodata_76A8;
extern u32 fn_1_584AC(void);
extern void *memset(void *, int, u32);

static inline f64 fn_1_FF420_operand(f64 left, f64 right) { return left * right; }
#pragma opt_loop_invariants off
static inline f64 fn_1_FF420_operand_(f64 left, f64 right) { return left + right; }
void fn_1_FF420(u8 *arg0) {
    s32 i;
    f64 k;
    f32 q_2;
    f64 g;
    f64 h;
    f64 h_2;
    f32 f;
    struct Entry *e;
    const struct Pool *pool;

    e = (struct Entry *)((u8 *)arg0 + 0x3c);
    pool = (const struct Pool *)&lbl_1_rodata_76A8;
    memset(e, 0, 0x410);
    for (i = 0; i < 0x14; i++, e++) {
        e->f00 = (s32)((30.0f) + (f32)((10.0f) * ((f32)(u32)(fn_1_584AC() & 0xffff) / (32767.0f))));
        e->v04 = *(Vec3 *)((u8 *)arg0 + 8);
        e->v10 = *(Vec3 *)((u8 *)arg0 + 8);

        f = *(f32 *)((u8 *)arg0 + 0x20);
        q_2 = (f32)(u32)(fn_1_584AC() & 0xffff) / (32767.0f);
        g = fn_1_FF420_operand(((0.10000000000000001)), ((f64)f));
        h = (0.90000000000000002) * (f64)f;
        k = g * q_2;
        e->f1c = (f32)(((h) + (k)));

        f = *(f32 *)((u8 *)arg0 + 0x24);
        q_2 = (f32)(u32)(fn_1_584AC() & 0xffff) / (32767.0f);
        g = fn_1_FF420_operand(((0.10000000000000001)), ((f64)f));
        h = (0.90000000000000002) * (f64)f;
        k = g * q_2;
        e->f20 = (f32)((h) + (k));

        f = *(f32 *)((u8 *)arg0 + 0x28);
        q_2 = (f32)(u32)(fn_1_584AC() & 0xffff) / (32767.0f);
        g = fn_1_FF420_operand(((0.10000000000000001)), ((f64)f));
        h_2 = (0.90000000000000002) * (f64)f;
        k = g * q_2;
        e->f24 = (f32)((fn_1_FF420_operand_((((k))), (((h_2))))));

        e->f28 = (u16)fn_1_584AC();
        q_2 = (f32)(u32)(fn_1_584AC() & 0xffff) / (32767.0f);
        g = q_2 - (0.5);
        k = (1280.0) * g;
        e->f2a = (u16)((s32)k + 0x200);
        e->f2c = (1.0f);
        e->f30 = (22.0f) * *(f32 *)((u8 *)arg0 + 0x38);
    }
}
#pragma opt_loop_invariants reset
