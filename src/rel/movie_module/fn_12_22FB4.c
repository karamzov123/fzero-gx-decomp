#include "types.h"


/* --- rel/movie_module/fn_12_22FB4.c --- */
// fn_12_22FB4: empty in retail (single blr).
void fn_12_22FB4(void) {
}

/* --- rel/movie_module/fn_12_22FB8.c --- */
// fn_12_22FB8: empty in retail (single blr).
void fn_12_22FB8(void) {
}

/* --- rel/movie_module/fn_12_22FBC.c --- */
typedef struct MovieState {
    u8 pad_0[0x1a8];
    s32 value_1a8;
    u8 pad_1ac[4];
    s32 count_1b0;
    s32 index_1b4;
    s32 entries_1b8[1];
} MovieState;

typedef struct MovieModule {
    u8 pad_cc0[0xcc0];
    MovieState state;
} MovieModule;

extern void fn_12_24970(void *arg);
extern void fn_12_24950(void *arg);

s32 fn_12_22FBC(MovieModule *module, s32 *out_entry, s32 *out_value) {
    u8 local[8];
    MovieState *state = &module->state;
    s32 result;

    fn_12_24970(local);
    if (state->count_1b0 - state->index_1b4 <= 0) {
        result = 0;
        *out_entry = -1;
    } else {
        result = 1;
        *out_value = state->value_1a8;
        *out_entry = state->entries_1b8[state->index_1b4 % 32];
        state->index_1b4++;
    }
    fn_12_24950(local);
    return result;
}
