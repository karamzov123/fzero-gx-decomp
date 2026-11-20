#include "types.h"


/* --- rel/movie_module/fn_12_2F1B4.c --- */
typedef struct MovieEntry {
    int field_0;
    char unk_4[0x40];
} MovieEntry;

typedef struct MovieModuleState {
    char unk_0[0x1aac];
    MovieEntry entries[1];
} MovieModuleState;

int fn_12_2F1B4(MovieModuleState *state, int index) {
    return state->entries[index].field_0 != 0;
}

/* --- rel/movie_module/fn_12_2F1D0.c --- */
struct fn_12_2F1D0_E68_u32 { u32 unk_0; u8 pad_4[0x40]; };
struct fn_12_2F1D0_Arg0 {
    u8 pad_0[0x1AA4];
    struct fn_12_2F1D0_E68_u32 unk_1AA4[1];
};

u32 fn_12_2F1D0(struct fn_12_2F1D0_Arg0 *arg0, u32 arg1) {
    return arg0->unk_1AA4[arg1].unk_0;
}

/* --- rel/movie_module/fn_12_2F1E0.c --- */
struct MovieSlot {
    int value;
    char pad[0x40];
};

struct Movie {
    char pad[0x1aa4];
    struct MovieSlot slots[1];
};

void fn_12_2F1E0(struct Movie *movie, int index, int value) {
    movie->slots[index].value = value;
}

/* --- rel/movie_module/fn_12_2F1F0.c --- */
struct fn_12_2F1F0_E68_u32 { u32 unk_0; u8 pad_4[0x40]; };
struct fn_12_2F1F0_Arg0 {
    u8 pad_0[0x1AA0];
    struct fn_12_2F1F0_E68_u32 unk_1AA0[1];
};

u32 fn_12_2F1F0(struct fn_12_2F1F0_Arg0 *arg0, u32 arg1) {
    return arg0->unk_1AA0[arg1].unk_0;
}
