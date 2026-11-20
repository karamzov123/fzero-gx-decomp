#include "types.h"


/* --- rel/movie_module/fn_12_2E9E4.c --- */
/* --- rel/movie_module/fn_12_2E9E4.c --- */
typedef struct MovieModuleState {
    u8 padding_000[0x10c];
    u32 field_10c;
    u32 field_110;
} MovieModuleState;

void fn_12_2E9E4(MovieModuleState *state, u32 value1, u32 value2) {
    state->field_10c = value1;
    state->field_110 = value2;
}

/* --- rel/movie_module/fn_12_2E9F0.c --- */
struct fn_12_2E9F0_Arg0 {
    u8 pad_0[0xE4];
    u32 unk_E4;
};
struct fn_12_2E9F0_Arg2 {
    u32 unk_0;
};

extern u32 UTY_MulDiv(u32, u32, u32);
extern u32 lbl_12_bss_1B730;
extern u32 lbl_12_bss_1B734;

u32 fn_12_2E9F0(struct fn_12_2E9F0_Arg0 *arg0, u32 arg1, struct fn_12_2E9F0_Arg2 *arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0;
    arg2->unk_0 = arg0->unk_E4;
    v1 = (u32)arg2;
    v2 = (u32)arg0;
    if ((s32)arg2->unk_0 != 0) {
    v0 = *(u32 *)((u8 *)v2 + 260);
    v1 = *(u32 *)((u8 *)v2 + 264);
    } else {
    v3 = *(u32 *)((u8 *)v2 + 220);
    if ((s32)v3 >= 0) {
    v1 = *(u32 *)((u8 *)v2 + 224);
    v0 = v3;
    } else {
    v2 = -1;
    return v2;
    }
    }
    v2 = v0;
    t0 = UTY_MulDiv(v2, arg1, v1);
    v2 = t0;
    lbl_12_bss_1B734 = v0;
    lbl_12_bss_1B730 = v2;
    return v2;
}

/* --- rel/movie_module/fn_12_2EA6C.c --- */
typedef struct MovieModuleState_u1 {
    u8 padding_000[0x118];
    int field_118;
} MovieModuleState_u1;

extern u32 lbl_12_bss_1B73C;
extern u32 lbl_12_bss_1B738;

int fn_12_2EA6C(MovieModuleState_u1 *state, int value) {
    int result;

    if (state->field_118 < 0) {
        return -1;
    }

    result = UTY_MulDiv(state->field_118, value, 0x57e4);
    lbl_12_bss_1B73C = state->field_118;
    lbl_12_bss_1B738 = result;
    return result;
}
