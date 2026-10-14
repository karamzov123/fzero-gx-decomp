/* Non-matching: best partial attempt (99.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f64 s; volatile f32 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f32 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
}
#pragma section code_type ".text"

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Sig_fn_1_862D4_Triple;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Sig_fn_8006FA24_Vec;

typedef struct EffectWork {
    u8 unk_0;
    u8 pad_01[0xF];
    s32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u8 pad_1a[0x2];
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2c;
    u8 pad_30[0xC];
    f32 unk_3c;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4c;
    f32 unk_50;
    u8 pad_54[0x34];
    f32 unk_88;
    f32 unk_8c;
    u8 pad_90[0x4];
    f32 unk_94;
    f32 unk_98;
    f32 unk_9c;
    u8 pad_a0[0x12];
    u16 unk_b2;
    u8 pad_b4[0x4];
    Sig_fn_8006FA24_Vec unk_b8;
} EffectWork;

extern void fn_1_862D4(int, Sig_fn_1_862D4_Triple *);
extern void fn_1_8636C(int, void *);
extern void fn_8006FA24(f32, Sig_fn_8006FA24_Vec *, Sig_fn_8006FA24_Vec *, Sig_fn_8006FA24_Vec *);

void fn_1_5C83C(EffectWork *self) {
    Sig_fn_1_862D4_Triple loc_8;
    f32 loc_14[12];
    f32 t;

    self->unk_0 = 2;
    fn_1_862D4(self->unk_18, &loc_8);
    fn_1_8636C(self->unk_18, loc_14);
    t = 1.0f - self->unk_88;
    self->unk_48 *= t;
    self->unk_4c *= t;
    self->unk_50 *= t;
    self->unk_3c += self->unk_48;
    self->unk_40 += self->unk_4c;
    self->unk_44 += self->unk_50;
    if (self->unk_b2 != 0) {
        self->unk_94 += (f32)(0.2f * self->unk_48);
        self->unk_98 += (f32)(0.2f * self->unk_4c);
        self->unk_9c += (f32)(0.2f * self->unk_50);
    }
    fn_8006FA24(0.05f, &self->unk_b8, (Sig_fn_8006FA24_Vec *)loc_14, &self->unk_b8);
    self->unk_88 += (f32)(0.05f * (self->unk_8c - self->unk_88));
    self->unk_28 += (f32)(0.2f * (self->unk_2c - self->unk_28));
    if ((f64)self->unk_10 < 24.0) {
        t = 1.0f - 1.0f / (f32)(self->unk_10 + 1);
        self->unk_1c *= t;
        self->unk_20 *= t;
        self->unk_24 *= t;
    }
}
