#include "types.h"

typedef struct MovieContext {
    int state;
    void *movie;
    u8 _pad[4];
    int kind;
} MovieContext;

static inline u32 swap_movie_word(u32 value) {
    u32 low = (u16)value;

    return (low << 24) | ((low << 8) & 0xff0000) | ((value >> 8) & 0xff00) | (value >> 24);
}

#pragma peephole on
int fn_12_32834(MovieContext *self, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
    case -1: case 0: case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    *result = swap_movie_word(*(u32 *)(movie + 0x80));
    return 1;
}
#pragma peephole reset
