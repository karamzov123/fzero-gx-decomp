#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_common.h"

typedef struct {
    u8 pad_0[0x0C];
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
} Fn_1_103B00_State;

typedef struct {
    u8 pad_0[0x18];
    f32 zero_f32;
    u8 pad_1C[0x14];
    f32 two_f32;
    u8 pad_34[0x34];
    f64 zero_f64;
    f64 three_f64;
    f32 max_f32;
    u8 pad_7C[4];
    f64 half_f64;
    f64 int_base_f64;
} Fn_1_103B00_Literals;

extern const Fn_1_103B00_Literals lbl_1_rodata_78D0;
extern u32 fn_1_584AC(void);
extern void fn_80073778(void *arg0, s32 arg1);
extern void fn_80073A58(s32 arg0, void *arg1, s8 arg2);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_800738E0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_800739E0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80073D60(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);

void fn_1_103B00(Fn_1_103B00_State *arg0) {
    f32 values[6];
    /* fzgx-allow: retail keeps this save area addressable across the inlined float
     * conversions; the volatile stops MWCC folding the stores into registers. */
    volatile u32 saved[11];
    union {
        f64 value;
        u32 words[2];
    } converted;
    Fn_1_103B00_Literals *pool;
    void *handle;
    u32 state_10;
    u32 state_18;
    u32 state_1C;
    u32 state_28;
    f32 scaled;
    f64 scale;
    u16 sample;
    f32 normalized;
    f64 weighted;

    pool = (Fn_1_103B00_Literals *)&lbl_1_rodata_78D0;
    state_18 = arg0->unk_18;
    saved[0] = arg0->unk_0C;
    saved[1] = arg0->unk_10;
    saved[2] = arg0->unk_14;
    saved[3] = state_18;
    saved[4] = arg0->unk_1C;
    saved[5] = arg0->unk_20;
    saved[6] = arg0->unk_24;
    saved[7] = arg0->unk_28;
    saved[8] = arg0->unk_2C;
    saved[9] = arg0->unk_30;
    saved[10] = arg0->unk_34;

    handle = (void *)lbl_1_bss_38458->unk_8;
    handle = *(void **)((u8 *)handle + 8);
    handle = *(void **)((u8 *)handle + 0xD8);
    handle = *(void **)((u8 *)handle + 0x24);
    fn_80073778(handle, state_18);

    scaled = pool->two_f32 * lbl_1_bss_85290;
    scale = pool->zero_f64;
    if (!(scaled < scale)) {
        scale = pool->three_f64;
        if (!(scaled > scale)) {
            scale = scaled;
        }
    }

    sample = (u16)fn_1_584AC();
    converted.words[0] = 0x43300000;
    converted.words[1] = sample;
    values[1] = pool->zero_f32;
    values[2] = pool->zero_f32;
    values[3] = pool->zero_f32;
    values[5] = pool->zero_f32;
    normalized = (f32)(converted.value - pool->int_base_f64) / pool->max_f32;
    weighted = ((f64)normalized - pool->half_f64) * scale;
    values[0] = (f32)weighted;
    values[4] = (f32)weighted;
    state_28 = saved[7];
    fn_80073A58(state_28, values, 1);

    state_10 = saved[1];
    fn_800745A4(state_10, 1, 4, 0x3C, 0, 0x7D);
    state_1C = saved[4];
    fn_800738E0(state_1C, state_10, state_18);
    fn_800739E0(state_1C, 0, 0);
    fn_80073D60(0, 1, 0, state_1C, state_28);

    arg0->unk_0C = saved[0];
    arg0->unk_10 = state_10 + 1;
    arg0->unk_14 = saved[2];
    arg0->unk_18 = state_18;
    arg0->unk_1C = state_1C + 1;
    arg0->unk_20 = saved[5];
    arg0->unk_24 = saved[6];
    arg0->unk_28 = saved[2] + 1;
    arg0->unk_2C = saved[8];
    arg0->unk_30 = saved[9];
    arg0->unk_34 = saved[10];
}
