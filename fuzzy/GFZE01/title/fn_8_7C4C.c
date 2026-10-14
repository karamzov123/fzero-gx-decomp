/* Non-matching: best partial attempt (89.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/title/operation.h"

extern s32 lbl_801A66B4;
extern void fn_1_5233C(void);
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
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(u32 *, f32);

/* Integer word the unit reads out of the shared pool. */
static const u32 kPoolWord[1] = {0x00000000};

void fn_8_7C4C(void) {
    u8 *data = (u8 *)&lbl_8_data_7E50;
    const char *const *msg0 = (const char *const *)(data + 0x738);
    const char *const *msg1 = (const char *const *)(data + 0x7B0);
    const char *const *msg2 = (const char *const *)(data + 0x824);
    s32 col;
    f32 t;
    u32 slots[2];

    if ((s32)lbl_8_bss_3CC == (s32)lbl_8_bss_3D0.unk_0 - 1) {
        fn_1_A2D84(0xA9120900);
    }

    if ((f64)(s32)lbl_8_bss_3CC < 15.0) {
        t = (f32)(1.0 - (f64)(f32)(s32)lbl_8_bss_3CC / 15.0);
        col = (s32)(320.0f + (f32)(640.0f * t));
    } else if ((f64)(s32)lbl_8_bss_3D0.unk_0 - 15.0 >= (f64)(s32)lbl_8_bss_3CC) {
        t = (f32)(1.0 - (f64)(f32)((s32)lbl_8_bss_3D0.unk_0 - (s32)lbl_8_bss_3CC) / 15.0);
        col = (s32)(320.0f - (f32)(640.0f * t));
    } else {
        t = 0.0f;
        col = 320;
    }

    fn_1_49410();
    t = (1.0f - t) * (1.0f - t);
    fn_1_495B0(0x80000000); /* fzgx-allow: A1 retail constant for fn_1_495B0 */
    fn_1_49590(0.3f);
    fn_1_495C8(9);
    fn_1_496FC((f32)col, 150.0f);
    fn_1_4954C(0.09f);
    if (lbl_801A66B4 == 5) {
        fn_1_4955C(1.0f, 1.0f);
    } else {
        fn_1_4955C(0.8333333f, 0.8333333f);
    }
    fn_1_495A0(t);
    fn_1_4D0A0();
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(msg0[lbl_801A66B4]);
    fn_1_49738(0);
    fn_1_4AE0C(msg1[lbl_801A66B4]);
    fn_1_4AE0C(msg2[lbl_801A66B4]);
    slots[0] = kPoolWord[0];
    ((u8 *)&slots[1])[-1] = (u8)(s32)(255.0f * t);
    slots[1] = slots[0];
    fn_1_4D0D4(&slots[1], 20.0f);
}
