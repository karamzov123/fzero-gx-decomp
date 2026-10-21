#include "types.h"
typedef struct Sig_fn_12_2FE60_Int64Pair {
    s64 a;
    s64 b;
} Sig_fn_12_2FE60_Int64Pair;

typedef struct Sig_fn_12_2FE60_State {
    s32 enabled;
    s32 mode;
    s32 active;
    s32 follow;
    s32 count;
    s32 index;
    s32 history[60];
    Sig_fn_12_2FE60_Int64Pair input;
    Sig_fn_12_2FE60_Int64Pair external;
    Sig_fn_12_2FE60_Int64Pair output;
    Sig_fn_12_2FE60_Int64Pair period;
    Sig_fn_12_2FE60_Int64Pair tolerance;
    Sig_fn_12_2FE60_Int64Pair initial;
    Sig_fn_12_2FE60_Int64Pair resume;
    s64 anchorExternal;
    s64 anchorInput;
    s64 maximum;
    s32 resyncs;
    s32 positive;
    s32 negative;
    s32 resets;
    s32 jumps;
    s32 average;
    s32 adjusted;
    s32 maxInactive;
    s32 minInactive;
    s32 maxActive;
    s32 minActive;
} Sig_fn_12_2FE60_State;

extern u8 lbl_12_bss_1B740[];
extern u32 lbl_12_bss_6988;
extern const f64 lbl_12_rodata_1020;
extern const f64 lbl_12_rodata_1018;
extern char lbl_12_rodata_1028[117];
extern void *memset(void *, int, u32);
extern f64 fn_80079D74(s64);
extern int sprintf(char *, const char *, ...);
extern char *fn_80083DB0(char *, const char *);

static inline s32 fn_12_2FE60_average(Sig_fn_12_2FE60_State *state) {
    s32 i;
    s32 sum = 0;
    for (i = 0; i < state->count; i++) {
        sum += state->history[i];
    }
    return sum / state->count;
}

extern s64 __div2i(s64, s64);

static inline void fn_12_2FE60_magnitude(s64 *result, s64 value) {
    *result = value < 0 ? -value : value;
}

static inline s32 fn_12_2FE60_print(char *buffer, Sig_fn_12_2FE60_State *state, s64 out, s32 rounded, s64 time, s64 scale) {
    s64 in = state->input.a;
    s64 maximum = state->maximum;
    return sprintf(buffer, lbl_12_rodata_1028, state,
        (s32)(time / scale), rounded, (s32)(time >> 32), (s32)time, (s32)(time & 0x7FFFFFFF),
        (s32)maximum, (s32)in, (s32)out, (s32)(in - out), (s32)(maximum - out),
        state->maxInactive, state->minInactive, state->maxActive, state->minActive,
        state->mode, state->active, state->resets, state->jumps, state->resyncs,
        state->positive, state->negative, state->average, state->adjusted, lbl_12_bss_6988);
}

static inline s32 fn_12_2FE60_floor(f64 value) {
    if ((s32)value > value) {
        return (s32)value - 1;
    } else {
        return (s32)value;
    }
}

static inline void fn_12_2FE60_shift(Sig_fn_12_2FE60_State *state, s32 amount, s32 i) {
    for (; i < state->count; i++) {
        state->history[i] -= amount;
    }
}

static inline s64 fn_12_2FE60_abs(s64 value) {
    if (value < 0) {
        return -value;
    } else {
        return value;
    }
}

void fn_12_2FE60(Sig_fn_12_2FE60_State *state, Sig_fn_12_2FE60_Int64Pair *arg1, Sig_fn_12_2FE60_Int64Pair *arg2, Sig_fn_12_2FE60_Int64Pair *arg3, f32 arg4) {
    char buffer[256];
    s64 out;
    s32 rounded;
    s64 time;
    s64 scale;
    f64 denom;
    f64 value;
    s64 in;
    s64 maximum;
    s32 length;
    u8 *p_lbl_12_bss_1B740 = (u8 *)&lbl_12_bss_1B740;
    s64 position;
    s64 magnitude;
    s32 difference;
    s64 mean;
    s64 limit;
    s64 steps;
    s32 i;
    s64 adjustment;
    s32 sum;
    s32 delta;

    if (arg2->b == 1 || state->enabled == 0) {
        *arg3 = *arg1;
        return;
    }

    arg1->a = state->maximum > arg1->a ? state->maximum : arg1->a;
    if (state->mode == 1) {
        state->active = 0;
    } else if (state->active == 0) {
        if (arg1->a > state->maximum) {
            s64 offset;
            state->active = 1;
            if (state->anchorExternal == -1) {
                offset = arg1->b * state->initial.a / state->initial.b;
            } else {
                offset = arg1->b * state->resume.a / state->resume.b;
            }
            state->anchorExternal = arg2->a;
            state->anchorInput = arg1->a + offset;
            memset(state->history, 0, 0xF0);
            state->index = 0;
            state->resets++;
        } else if (state->follow == 0) {
            state->active = 1;
        }
    }
    state->maximum = state->maximum > arg1->a ? state->maximum : arg1->a;

    if (state->anchorExternal == -1) {
        position = 0;
    } else {
        position = state->anchorInput + (arg2->a - state->anchorExternal) * arg1->b / arg2->b;
    }

    if (state->active == 0) {
        if (state->maximum < position) {
            if (state->follow != 0) {
                state->anchorExternal = arg2->a;
                state->anchorInput = state->maximum;
            } else {
                state->anchorExternal = arg2->a;
                state->anchorInput = state->output.a;
            }
            state->resyncs++;
        }
    } else if (state->follow == 1) {
        s64 displacement = arg1->a - position;
        s64 toleranceLimit;
        difference = (s32)displacement;
        magnitude = displacement < 0 ? -displacement : displacement;
        toleranceLimit = __div2i(arg1->b * state->tolerance.a, state->tolerance.b);
        if (magnitude > toleranceLimit) {
            state->anchorExternal = arg2->a;
            state->anchorInput = arg1->a;
            memset(state->history, 0, 0xF0);
            state->index = 0;
            state->resets++;
            state->jumps++;
        } else {
            state->history[state->index++ % state->count] = difference;
            mean = fn_12_2FE60_average(state);
            state->average = mean;
            state->adjusted = mean;
            limit = arg1->b * state->period.a / state->period.b;
            magnitude = mean < 0 ? -mean : mean;
            if (limit < magnitude) {
                if (limit < mean) {
                    steps = mean * 2 / limit - 1;
                    state->positive += (s32)steps;
                } else {
                    steps = mean * 2 / limit + 1;
                    state->negative += (s32)-steps;
                }
                adjustment = steps * limit / 2;
                state->anchorExternal = arg2->a;
                state->anchorInput = position + adjustment;
                fn_12_2FE60_shift(state, (s32)adjustment, 0);
                state->adjusted = fn_12_2FE60_average(state);
            }
        }
    }

    if (state->anchorExternal == -1) {
        position = 0;
    } else {
        position = state->anchorInput + (arg2->a - state->anchorExternal) * arg1->b / arg2->b;
    }
    arg3->a = position;
    arg3->b = arg1->b;
    if (arg3->a < state->output.a) {
        *arg3 = state->output;
    }
    state->input = *arg1;
    state->external = *arg2;
    state->output = *arg3;
    delta = (s32)(arg1->a - arg3->a);
    if (state->active == 0) {
        state->maxInactive = state->maxInactive > delta ? state->maxInactive : delta;
        state->minInactive = state->minInactive < delta ? state->minInactive : delta;
    } else {
        state->maxActive = state->maxActive > delta ? state->maxActive : delta;
        state->minActive = state->minActive < delta ? state->minActive : delta;
    }
    *(void **)(p_lbl_12_bss_1B740 + 0x10) = state;
    if (*(u32 *)(p_lbl_12_bss_1B740 + 4) != 0) {
        scale = state->external.b;
        denom = fn_80079D74(scale);
        time = state->external.a;
        value = lbl_12_rodata_1020 * (fn_80079D74(time) / denom) + lbl_12_rodata_1018;
        if ((s32)value > value) {
            rounded = (s32)value - 1;
        } else {
            rounded = (s32)value;
        }
        out = state->output.a;
        in = state->input.a;
        maximum = state->maximum;
        length = sprintf(buffer, lbl_12_rodata_1028, state,
            (s32)(time / scale), rounded, (s32)(time >> 32), (s32)time, (s32)(time & 0x7FFFFFFF),
            (s32)maximum, (s32)in, (s32)out, (s32)(in - out), (s32)(maximum - out),
            state->maxInactive, state->minInactive, state->maxActive, state->minActive,
            state->mode, state->active, state->resets, state->jumps, state->resyncs,
            state->positive, state->negative, state->average, state->adjusted, lbl_12_bss_6988);
        fn_80083DB0(*(char **)(p_lbl_12_bss_1B740 + 0xC), buffer);
        *(char **)(p_lbl_12_bss_1B740 + 0xC) += length;
        if (*(u32 *)(p_lbl_12_bss_1B740 + 0xC) >=
            *(u32 *)(p_lbl_12_bss_1B740 + 4) + *(u32 *)p_lbl_12_bss_1B740 - 0x400) {
            *(u32 *)(p_lbl_12_bss_1B740 + 0xC) = *(u32 *)(p_lbl_12_bss_1B740 + 8);
        }
    }
}
