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
extern void fn_800739E0(s16 arg0, s32 arg1, s32 arg2);
extern void fn_80073D60(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);

#pragma opt_dead_assignments off
/* Reloads the saved state so intervening calls cannot elide its reads. */
static inline volatile u32 fn_1_103B00_array_read(volatile u32 *array, s32 index) { return array[index]; }
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
#pragma opt_loop_invariants on
static inline void fn_1_103B00_call_fn_800738E0(s32 a0, s32 a1, s32 a2) { fn_800738E0(a0, a1, a2); }
#pragma opt_propagation off
/* The callback state is volatile because setters run before its writeback. */
u32 fn_1_103B00(volatile Fn_1_103B00_State *arg0) {
    u32 fzgx_value___;
    struct { u16 value; } fzgx_value__;
    u32 fzgx_value_;
    s8 fzgx_value;
    f64 weighted;
    f32 normalized;
    void *handle;
    struct { f64 value; } scale;
    f32 scaled;
    u32 state_34;
    u32 state_30;
    u32 state_2C;
    u32 state_28_in;
    u32 state_24;
    u32 state_20;
    u32 state_1C_in;
    u32 state_14;
    u32 state_10_in;
    u32 state_0C;
    u32 state_28;
    u32 state_1C;
    u32 state_18;
    u32 state_10;
    u16 sample;
    Fn_1_103B00_Literals *pool;
    volatile u32 saved[11]; /* fzgx-allow: S2 retail snapshots callback state across calls */
    f32 values[6];
    u32 lab_t4;

    pool = (Fn_1_103B00_Literals *)&lbl_1_rodata_78D0;
    state_18 = arg0->unk_18;
    state_0C = arg0->unk_0C;
    state_10_in = arg0->unk_10;
    state_14 = arg0->unk_14;
    state_1C_in = arg0->unk_1C;
    state_20 = arg0->unk_20;
    state_24 = arg0->unk_24;
    state_28_in = arg0->unk_28;
    state_2C = arg0->unk_2C;
    state_30 = arg0->unk_30;
    state_34 = arg0->unk_34;
    saved[0] = state_0C;
    saved[1] = state_10_in;
    saved[2] = state_14;
    saved[3] = state_18;
    saved[4] = state_1C_in;
    saved[5] = state_20;
    saved[6] = state_24;
    saved[7] = state_28_in;
    saved[8] = state_2C;
    saved[9] = state_30;
    saved[10] = state_34;

    handle = (void *)lbl_1_bss_38458->unk_8;
    handle = *(void **)((u8 *)handle + 8);
    handle = *(void **)((u8 *)handle + 0xD8);
    fn_80073778((*(void **)((u8 *)handle + 0x24)), state_18);

    scaled = (2.0f) * lbl_1_bss_85290;
    scale.value = (0.0);
    if (!(scaled < scale.value)) {
        scale.value = (3.0);
        if (!(scaled > scale.value)) {
            scale.value = scaled;
        }
    }

    sample = (u16)fn_1_584AC();
    values[1] = (0.0f);
    values[2] = (0.0f);
    values[3] = (0.0f);
    values[5] = (0.0f);
    normalized = (f32)sample / (32767.0f);
    weighted = ((f64)normalized - (0.5)) * scale.value;
    values[0] = (f32)weighted;
    values[4] = (f32)weighted;
    state_28 = fn_1_103B00_array_read(saved, 7);
    fn_80073A58(state_28, values, 1);

    state_10 = fn_1_103B00_array_read(saved, 1);
    fn_800745A4(state_10, 1, 4, 0x3C, 0, 0x7D);
    state_1C = fn_1_103B00_array_read(saved, 4);
    fn_1_103B00_call_fn_800738E0(state_1C, state_10, state_18);
    fn_800739E0(state_1C, 0, 0);
    lab_t4 = state_28;
    fn_80073D60(0, 1, 0, state_1C, lab_t4);

    arg0->unk_0C = fn_1_103B00_array_read(saved, 0);
    fzgx_value_ = state_10 + 1;
    arg0->unk_10 = fzgx_value_;
    arg0->unk_14 = fn_1_103B00_array_read(saved, 2);
    fzgx_value___ = state_18;
    arg0->unk_18 = fzgx_value___;
    fzgx_value_ = state_1C + 1;
    fzgx_value = fzgx_value_;
    arg0->unk_1C = fzgx_value;
    arg0->unk_20 = fn_1_103B00_array_read(saved, 5);
    arg0->unk_24 = fn_1_103B00_array_read(saved, 6);
    arg0->unk_28 = fn_1_103B00_array_read(saved, 2) + 1;
    arg0->unk_2C = fn_1_103B00_array_read(saved, 8);
    arg0->unk_30 = fn_1_103B00_array_read(saved, 9);
    fzgx_value__.value = fn_1_103B00_array_read(saved, 10);
    arg0->unk_34 = fzgx_value__.value;
    return (u32)state_0C;
}
#pragma opt_propagation reset

#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset

#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset

