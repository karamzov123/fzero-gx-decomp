#include "types.h"


/* --- rel/movie_module/fn_12_2F200.c --- */
struct MovieItem {
    int value;
    char pad[0x40];
};

struct Movie {
    char pad[0x1aa0];
    struct MovieItem items[1];
};

void fn_12_2F200(struct Movie *movie, int index, int value) {
    movie->items[index].value = value;
}

/* --- rel/movie_module/fn_12_2F210.c --- */
typedef u32 (*fn_12_2F210_Fn0)(u32, u32, u32, u32);

struct fn_12_2F210_arg0_1A90_E68 {
    u8 pad_0[0x1C];
    fn_12_2F210_Fn0 *unk_1C;
    u8 pad_20[0x24];
};

struct fn_12_2F210_Arg0 {
    u8 pad_0[0x1A90];
    struct fn_12_2F210_arg0_1A90_E68 unk_1A90[1];
};

u32 fn_12_2F210(struct fn_12_2F210_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    fn_12_2F210_Fn0 *callbacks;

    callbacks = arg0->unk_1A90[arg1].unk_1C;
    if (callbacks == 0) {
        return 0;
    }
    return callbacks[arg2]((u32)arg0, arg3, arg4, 0);
}
