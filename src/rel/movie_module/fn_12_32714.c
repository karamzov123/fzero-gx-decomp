#include "types.h"

typedef struct MovieContext {
    int state;
    void *movie;
    u8 _pad[4];
    int kind;
} MovieContext;

static inline s16 swap_movie_value(s16 value) {
    return (s16)(u16)(((((value << 8) & 0xff00)) | (((value >> 8) & 0xff))));
}

int fn_12_32714(MovieContext *self, s32 *result) {
    s32 kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;
    s16 value;

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
        kind_ok = (s16)(0);
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = (s16)(1);
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

    value = *(s16 *)(movie + 0x88);
    *result = swap_movie_value(value);
    return 1;
}
