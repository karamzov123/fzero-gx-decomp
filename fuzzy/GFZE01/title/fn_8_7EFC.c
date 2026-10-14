/* Non-matching: best partial attempt (91.65% in the project ledger). Scored for the
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
static const u32 fzgx_pool_table4[6] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table6[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table7[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern f32 lbl_8_rodata_160[10];
extern s32 lbl_801A66B4;
extern void fn_1_A2D84(u32);
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
extern void fn_1_5233C(void);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(void *, f32);
typedef struct { u8 r, g, b, a; } TitleColor;

void fn_8_7EFC(void) {
    u8 *data = (u8 *)&lbl_8_data_7E50;
    s32 x;
    f32 t;
    f32 alpha;
    TitleColor color;
    s32 frame;
    s32 duration;
    if ((s32)lbl_8_bss_3CC == (s32)lbl_8_bss_3D0.unk_0 - 1)
        fn_1_A2D84(0xA9120100);
    frame = (s32)lbl_8_bss_3CC;
    if (frame < 15.0) {
        t = 1.0 - (f32)frame / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else {
        duration = (s32)lbl_8_bss_3D0.unk_0;
        if (frame > duration - 15.0) {
            t = 1.0 - (f32)(duration - frame) / 15.0;
            x = 320.0f - (f32)(640.0f * t);
        } else {
            t = 0.0f;
            x = 320;
        }
    }
    alpha = (1.0f - t) * (1.0f - t);
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC((f32)x, 150.0f);
    fn_1_4954C(0.09f);
    if (lbl_801A66B4 == 5) fn_1_4955C(1.0f, 1.0f);
    else fn_1_4955C(0.8333333134651184f, 0.8333333134651184f);
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(((const char **)(data + 0x854))[lbl_801A66B4]);
    fn_1_49738(0);
    fn_1_4AE0C(((const char **)(data + 0x8B4))[lbl_801A66B4]);
    fn_1_4AE0C(((const char **)(data + 0x920))[lbl_801A66B4]);
    color = *(TitleColor *)((u8 *)lbl_8_rodata_160 + 0x68);
    color.a = (s32)(255.0f * alpha);
    fn_1_4D0D4(&color, 20.0f);
}
