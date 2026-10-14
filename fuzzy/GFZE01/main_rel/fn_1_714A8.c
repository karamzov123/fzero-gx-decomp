/* Non-matching: best partial attempt (90.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
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
    s = 1.1920928955078125e-07f;
    s = 255.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
}
#pragma section code_type ".text"

struct fn_1_714A8_arg0 {
    u8 pad_00[0x38];
    u32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    u32 unk_48;
    u32 unk_4C;
    u32 unk_50;
};

struct fn_1_714A8_loc {
    u8 pad_00[0x0C];
    s16 unk_0C;
    u8 pad_0E[0x02];
    u32 unk_10;
    u8 pad_14[0x06];
    u16 unk_1A;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0x04];
    u32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    u8 pad_54[0x04];
    s16 unk_58;
    u8 pad_5A[0x8E];
};

extern u32 fn_1_584AC(void);
extern u8 * memset(u8 *, int, u32);
extern u32 fn_1_59078(void *);
extern u32 fn_1_58F50(const void *);

#pragma opt_propagation off
#pragma opt_dead_assignments on
void fn_1_714A8(u32 arg0, void *arg1, u32 arg2, f32 arg3) {
    f32 fzgx_live__;
    f32 fzgx_live_;
    f64 fzgx_live;
    struct fn_1_714A8_arg0 *a0 = (struct fn_1_714A8_arg0 *)arg0;
    struct fn_1_714A8_loc s;
    u32 v0;
    f32 k;
    f32 r;
    f64 d;

    v0 = a0->unk_38;
    memset((u8 *)&s, 0, 232);
    s.unk_1A = (s16)(0x10000 - 1);
    s.unk_0C = 22;
    s.unk_34 = *(u32 *)((u8 *)lbl_1_bss_38458->unk_8 + 0x168);

    d = (f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5;
    d = 2.0 * d;
    s.unk_3C = (f32)((f64)a0->unk_3C + d);

    d = (f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5;
    d = 2.0 * d;
    s.unk_40 = (f32)((f64)a0->unk_40 + d);

    d = (f32)(fn_1_584AC() & 0xFFFF) / 32767.0f - 0.5;
    s.unk_44 = (f32)((f64)a0->unk_44 + (2.0 * d));

    *(u32 *)&s.unk_48 = a0->unk_48;
    *(u32 *)&s.unk_4C = a0->unk_4C;
    *(u32 *)&s.unk_50 = a0->unk_50;
    k = 0.2f * *(f32 *)arg1;
    s.unk_48 = s.unk_48 + k;
    s.unk_40 = s.unk_40 - s.unk_4C;
    s.unk_44 = s.unk_44 - s.unk_50;
    s.unk_48 = s.unk_48 + k;
    s.unk_48 = s.unk_48 + k;
    fzgx_live__ = s.unk_3C;
    fzgx_live_ = fzgx_live__;
    fzgx_live = fzgx_live_;
    s.unk_3C = fzgx_live - s.unk_48;

    k = (f32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
    r = 0.2f * k;
    r = 0.8f + r;
    s.unk_2C = arg3 * r;
    s.unk_28 = 0.5f * r;

    k = (f32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
    r = 0.2f * k;
    r = 0.8f + r;
    s.unk_24 = 0.0f;
    s.unk_20 = (255.0f * r) / *(f32 *)&a0->unk_48;
    s.unk_1C = (*(f32 *)&a0->unk_48 * (0.5f * (0.5f + r))) / *(f32 *)&a0->unk_48;

    s.unk_58 = (s16)fn_1_584AC();
    s.unk_10 = arg2;
    if (*(s8 *)((u8 *)v0 + 0x475) != -1) {
        fn_1_59078(&s);
    } else {
        fn_1_58F50(&s);
    }
}
#pragma opt_dead_assignments reset

#pragma opt_propagation reset

