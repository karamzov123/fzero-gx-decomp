/* Non-matching: best partial attempt (92.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/stcoli.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table5[52] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 80.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

typedef struct {
    u8 pad_00[0x10];
    u16 unk_10;
    u16 unk_12;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 unk_20[0xC2];
    u8 unk_E2;
} Unk_2D888;

typedef struct {
    u32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30;
    u8 unk_34[0x24];
} Cmd_2D888;

extern f32 lbl_1_rodata_26F8[22];
extern u32 fn_1_4060(void);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_4954C(f32 arg0);
extern void fn_1_495C8(u8 arg0);
extern void fn_1_495B0(u32 arg0);
extern void fn_1_49590(f32 arg0);
extern void fn_1_495A0(f32 arg0);
extern void fn_1_4955C(f32 arg0, f32 arg1);
extern void fn_1_496FC(f32 arg0, f32 arg1);
extern s32 fn_1_4AEE8(u32 arg0);
extern void fn_1_4AF10(void *arg0);
extern void fn_1_4A0D8(const char *arg0);
extern u32 fn_1_50A90(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
extern u32 __cvt_fp2unsigned(f32 arg0);

#pragma opt_strength_reduction off
#pragma opt_lifetimes on
void fn_1_2D888(Unk_2D888 *arg0, u32 lab_unused0) {
    f32 s;
    f32 t;
    f32 u;
    f32 p45;
    f32 half;
    u32 w;
    u32 y;
    u32 z;
    u32 n45;
    u32 n18;
    Cmd_2D888 cmd;

    if (arg0->unk_E2 == 0) {
        fn_1_4060();
        return;
    }
    s = 10.0f * arg0->unk_1C;
    if (s > 1.0f) {
        s = 1.0f;
    }
    t = 1.25f * (arg0->unk_1C - 0.1f);
    if (t < 0.0f) {
        t = 0.0f;
    }
    u = 10.0f * (arg0->unk_1C - 0.9f);
    if (u < 0.0f) {
        u = 0.0f;
    }
    fn_1_49410();
    fn_1_495FC();
    fn_1_4954C(0.0006f);
    fn_1_495C8(1);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.4f);
    fn_1_495A0(u);
    fn_1_4955C(0.8f, 0.8f);
    fn_1_496FC((f32)(u32)arg0->unk_10, (f32)(u32)arg0->unk_12);
    w = fn_1_4AEE8(0);
    fn_1_4AF10(arg0->unk_20);
    fn_1_4AEE8(w);
    fn_1_496FC((f32)(u32)arg0->unk_10, (f32)(u32)arg0->unk_12 + arg0->unk_18 - 45.0f);
    fn_1_4955C(1.0f, 1.0f);
    fn_1_4A0D8((const char *)lbl_1_data_61D4);
    y = __cvt_fp2unsigned(arg0->unk_14 * t);
    z = __cvt_fp2unsigned(arg0->unk_18 * t);
    p45 = 45.0f * s;
    cmd = *(Cmd_2D888 *)&lbl_1_rodata_26F8;
    cmd.unk_0C = (f32)(u32)arg0->unk_10;
    cmd.unk_0C = 0.0008f;
    half = 0.0007999999797903001f * arg0->unk_18;
    cmd.unk_08 = ((half) + ((f32)(s16)(arg0->unk_12 - 10)));
    cmd.unk_30 = 10;
    cmd.unk_2C = arg0->unk_1C;
    cmd.unk_00 = 2;
    n45 = __cvt_fp2unsigned(p45);
    n18 = __cvt_fp2unsigned(18.0f * s);
    fn_1_50A90(&cmd, n18, n45, y, z);
}
#pragma opt_lifetimes reset

#pragma opt_strength_reduction reset

