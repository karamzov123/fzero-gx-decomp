#include "types.h"

extern u8 lbl_8_rodata_160[];
extern u32 lbl_8_bss_2A8;
extern u32 lbl_801A66B4;
extern u8 lbl_8_data_9B8C[0x18];

extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(u32 *, f32);
extern void fn_1_5233C(void);
extern void fn_8_C9A8(s32, s32, f32);

struct fn_8_B138_state {
    u8 pad_0[0x28];
    f32 unk_28;
    u8 pad_2C[4];
    f32 unk_30;
    f32 unk_34;
    u8 pad_38[0xEC];
    s32 unk_124;
    s32 unk_128;
};

void fn_8_B138(void) {
    struct fn_8_B138_state *state;
    u8 *pool;
    s32 current;
    s32 limit;
    s32 target;
    f32 blend;
    f32 alpha;
    u32 copy;
    u32 color;

    state = (struct fn_8_B138_state *)&lbl_8_bss_2A8;
    pool = (u8 *)&lbl_8_rodata_160;
    current = state->unk_124;
    if ((f64)current < *(f64 *)(pool + 0x0)) {
        blend = (f32)(*(f64 *)(pool + 0x10) - ((f64)current / *(f64 *)(pool + 0x0)));
        target = (s32)((f32)(*(f32 *)(pool + 0xC) * blend) + *(f32 *)(pool + 0x8));
    } else {
        limit = state->unk_128;
        if ((f64)current <= ((f64)limit - *(f64 *)(pool + 0x0))) {
            blend = *(f32 *)(pool + 0x34);
            target = 0x140;
        } else {
            blend = (f32)(*(f64 *)(pool + 0x10) - ((f64)(limit - current) / *(f64 *)(pool + 0x0)));
            target = (s32)(*(f32 *)(pool + 0x8) - (f32)(*(f32 *)(pool + 0xC) * blend));
        }
    }

    alpha = *(f32 *)(pool + 0x38) - blend;
    alpha = alpha * alpha;
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(*(f32 *)(pool + 0x3C));
    fn_1_495C8(9);
    fn_1_496FC((f32)target, *(f32 *)(pool + 0x110));
    fn_1_4954C(*(f32 *)(pool + 0x40));
    fn_1_4955C(*(f32 *)(pool + 0x24), *(f32 *)(pool + 0x24));
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(*(f32 *)(pool + 0x44));
    fn_1_4AE0C(*(const char **)(lbl_8_data_9B8C + (lbl_801A66B4 << 2)));
    fn_1_49738(0);
    color = *(u32 *)(pool + 0x15C);
    ((u8 *)&color)[3] = (u8)(*(f32 *)(pool + 0x48) * alpha);
    copy = color;
    fn_1_4D0D4(&copy, *(f32 *)(pool + 0x20));
    state->unk_28 = *(f32 *)(pool + 0x38);
    state->unk_30 = *(f32 *)(pool + 0x34);
    state->unk_34 = *(f32 *)(pool + 0x124);
    fn_8_C9A8(0, 0, *(f32 *)(pool + 0x124));
}
