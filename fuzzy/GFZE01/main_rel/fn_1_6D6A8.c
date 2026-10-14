/* Non-matching: best partial attempt (88.41% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/effect.h"
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
    s = 85.0f;
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
    s = 255.0f;
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
#pragma section code_type ".text"

extern u8 * memset(u8 *, int, u32);
extern u32 fn_1_584AC(void);

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} Sig_1_867CC;

extern void fn_1_867CC(void *, Sig_1_867CC *);

typedef struct {
    u8 pad_88[0x88];
    u32 unk_88;
} Target_1_6D6A8;

typedef struct {
    u8 lab_pad[8];
    u8 pad_0[0x18];
    u16 unk_18;
} Car_1_6D6A8;

typedef struct {
    u8 pad_0[8];
    u32 unk_8;
    u8 pad_E[0xA];
    s16 unk_C;
    s16 unk_18;
    u16 unk_1A;
    f32 unk_1C;
    f32 unk_24;
    f32 unk_20;
    f32 unk_28;
    u8 pad_2C[8];
    u32 unk_34;
    u8 pad_38[4];
    Sig_1_867CC unk_3C;
    u8 pad_48[0x68];
    u16 unk_B0;
    u8 pad_B2[0x36];
} State_1_6D6A8;

void fn_1_6D6A8(Car_1_6D6A8 *arg0)
{
    f32 s;
    f32 t;
    State_1_6D6A8 state;
    f32 u;

    memset((u8 *)&state, 0, sizeof(state));
    state.unk_C = 14;
    state.unk_18 = arg0->unk_18;
    state.unk_1A = 65536 - 1;
    state.unk_34 = ((Target_1_6D6A8 *)lbl_1_bss_38458->unk_8)->unk_88;
    state.unk_8 |= 0x40000;
    fn_1_867CC(&state, &state.unk_3C);
    state.unk_28 = 4.0f;
    state.unk_B0 = 0;
    t = (f32)((u32)fn_1_584AC() & ~0xffffu) / 32767.0f;
    state.unk_24 = 0.0f;
    s = 0.20000000298023224f * t;
    u = 0.800000011920929f + s;
    state.unk_20 = (255.0f * u) / 85.0f;
    state.unk_1C = (85.0f * (0.5f * (1.0f + u))) / 85.0f;
    fn_1_59078((Obj_1_bss_6C84C_Target *)&state);
}
