/* Non-matching: best partial attempt (79.26% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/title/operation.h"

extern void fn_1_A2D84(u32);
extern void fn_8_CC4C(u32, u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f64, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(u32 *, f32);
extern u32 lbl_801A66B4;
extern void fn_1_5233C(void);
extern f32 lbl_8_rodata_160[10];

#define POOL ((u8 *)lbl_8_rodata_160)

void fn_8_71A8(void) {
    const char **fmt = (const char **)&lbl_8_data_7E50;
    s32 c;
    u32 v;
    u32 w;
    f32 k;
    f32 t;
    f32 sq;

    if ((s32)lbl_8_bss_3CC == (s32)lbl_8_bss_3D0.unk_0 - 1) {
        fn_1_A2D84(0xA9120A00);
    }
    if ((f64)(s32)lbl_8_bss_3CC < 15.0) {
        k = (f32)(1.0 - (f64)(f32)(s32)lbl_8_bss_3CC / 15.0);
        c = (s32)(320.0f + (f32)(640.0f * k));
    } else if ((f64)(s32)lbl_8_bss_3CC > (f64)(s32)lbl_8_bss_3D0.unk_0 - 15.0) {
        k = (f32)(1.0 - (f64)(f32)((s32)lbl_8_bss_3D0.unk_0 - (s32)lbl_8_bss_3CC) / 15.0);
        c = (s32)(320.0f - (f32)(640.0f * k));
    } else {
        k = 0.0f;
        c = 0x140;
    }
    t = 1.0f - k;
    sq = t * t;
    if ((s32)lbl_8_bss_3D0.unk_0 > (s32)lbl_8_bss_3CC
        && (s32)lbl_8_bss_3CC > (s32)lbl_8_bss_3D0.unk_0 - 180) {
        fn_8_CC4C(0x1B7, 0xB1);
    }
    fn_1_49410();
    fn_1_495B0(0x80000000 /* fzgx-allow: A1 retail immediate */);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC((f32)c, 150.0f);
    fn_1_4954C(0.09f);
    if ((s32)lbl_801A66B4 == 5) {
        fn_1_4955C(1.0f, 1.0f);
    } else {
        fn_1_4955C(0.8333333f, 0.8333333f);
    }
    fn_1_495A0(sq);
    fn_1_4D0A0();
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(((const char **)((u8 *)fmt + 0x43C))[(s32)lbl_801A66B4]);
    fn_1_49738(0);
    fn_1_4AE0C(((const char **)((u8 *)fmt + 0x494))[(s32)lbl_801A66B4]);
    fn_1_4AE0C(((const char **)((u8 *)fmt + 0x4F4))[(s32)lbl_801A66B4]);
    w = *(u32 *)(POOL + 0x50);
    *((u8 *)&w + 3) = (u8)(255.0f * sq);
    v = w;
    fn_1_4D0D4(&v, 20.0f);
}
