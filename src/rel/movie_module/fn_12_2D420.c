#include "types.h"


/* --- rel/movie_module/fn_12_2D420.c --- */
typedef struct MovieModuleSubState {
    u8 pad_0[0xda4];
    s32 field_da4;
    s32 field_da8;
} MovieModuleSubState;

typedef struct MovieModuleState {
    u8 pad_0[0x2908];
    MovieModuleSubState *field_2908;
} MovieModuleState;

void fn_12_2D420(MovieModuleState *arg0, u32 arg1, u32 arg2) {
    MovieModuleSubState *state;

    state = arg0->field_2908;
    if (state == 0) {
        return;
    }
    if (state->field_da4 < 0) {
        state->field_da4 = arg1;
    }
    if (state->field_da8 >= 0) {
        return;
    }
    state->field_da8 = arg2;
}

/* --- rel/movie_module/fn_12_2D450.c --- */
typedef struct MovieModuleState_u1 {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
} MovieModuleState_u1;

void fn_12_2D450(MovieModuleState_u1 *state) {
    state->field_0 = 0;
    state->field_4 = 0;
    state->field_8 = -3;
    state->field_c = 1;
}

/* --- rel/movie_module/fn_12_2D470.c --- */
typedef struct MovieModuleState_u2 {
    u8 pad_0[0x78];
    s32 field_78;
    u8 pad_7c[0x8c];
    s32 field_108;
    u8 field_10c[1];
} MovieModuleState_u2;

extern s32 fn_12_24990(MovieModuleState_u2 *state);
extern s32 fn_12_24A88(s32 arg0, u32 arg1);

s32 fn_12_2D470(MovieModuleState_u2 *state, void **out0, u32 *out1) {
    if (fn_12_24990(state)) {
        return fn_12_24A88(0, 0xff00011c);
    }
    if (state->field_78) {
        *out0 = &state->field_10c[0];
        *out1 = state->field_108;
    } else {
        *out0 = 0;
        *out1 = 0;
    }
    return 0;
}
