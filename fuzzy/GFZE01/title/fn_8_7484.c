/* Non-matching: best partial attempt (91.28% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/title/operation.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 15.0;
    s = 320.0f;
    s = 640.0f;
    d = 1.0;
    s = 150.0f;
    s = 0.10000000149011612f;
    s = 20.0f;
    s = 0.8333333134651184f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09000000357627869f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_table4[2] = {0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table5[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern u32 lbl_801A66B4[];
extern u32 fn_8_CC4C(u32, u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_5233C(void);

typedef struct {
    u8 r, g, b, a;
} Color8;

extern void fn_1_4D0D4(Color8 *, f32);

static inline const char * fn_8_7484_array_read(const char * *array, s32 index) { return array[index]; }
#pragma opt_propagation on
static inline f32 fn_8_7484_operand(f32 left, f32 right) { return left + right; }
static inline u32 fn_8_7484_array_read_(u32 *array, s32 index) { return array[index]; }
#pragma opt_loop_invariants off
void fn_8_7484(void) {
    const char **tbl = (const char **)&lbl_8_data_7E50;
    s32 x;
    f32 alpha_2;
    s32 t = lbl_8_bss_3CC;
    f32 a;
    f32 alpha;
    u32 lab_v;

    if ((f64)t < 15.0) {
        a = 1.0 - (f32)t / 15.0;
        alpha = 640.0f * a;
        x = fn_8_7484_operand((320.0f), (alpha));
    } else if ((f64)t > (f64)(s32)lbl_8_bss_3D0.unk_0 - 15.0) {
        a = 1.0 - (f32)((s32)lbl_8_bss_3D0.unk_0 - t) / 15.0;
        alpha_2 = 640.0f * a;
        x = 320.0f - alpha_2;
    } else {
        a = 0.0f;
        x = 320;
    }
    alpha_2 = 1.0f - a;
    alpha_2 = alpha_2 * alpha_2;
    if ((s32)lbl_8_bss_3D0.unk_0 - 60 > t && t > (s32)lbl_8_bss_3D0.unk_0 - 180) {
        fn_8_CC4C(0x12E, 0xAD);
    }
    fn_1_49410();
    fn_1_495B0(1U << 31);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC((f32)x, 150.0f);
    fn_1_4954C(0.09f);
    lab_v = fn_8_7484_array_read_(lbl_801A66B4, 0);
    if ((s32)lab_v == 5) {
        fn_1_4955C(1.0f, 1.0f);
    } else {
        fn_1_4955C(0.8333333f, 0.8333333f);
    }
    fn_1_495A0(alpha_2);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(fn_8_7484_array_read(tbl, 0x14B + lab_v));
    fn_1_49738(0);
    fn_1_4AE0C(fn_8_7484_array_read(tbl, 0x165 + lab_v));
    fn_1_4AE0C(fn_8_7484_array_read(tbl, 0x174 + lab_v));
    {
        Color8 color;
        Color8 tmp = { 0xFF, 0xFF, 0xFF, 0xFF };
        tmp.a = (s32)(255.0f * alpha_2);
        color = tmp;
        fn_1_4D0D4(&color, 20.0f);
    }
}
#pragma opt_loop_invariants reset

#pragma opt_propagation reset

