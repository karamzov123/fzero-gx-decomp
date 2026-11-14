#include "types.h"

typedef struct MovieContext {
    int state;
    void *movie;
    u8 _pad[4];
    int kind;
} MovieContext;

static inline u8 fn_12_3256C_array_read(u8 *array, s32 index) { return array[index]; }
int fn_12_3256C(MovieContext *self, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
case -1: case 0: case 1: {

        ok = 0;
    
} break;
default: {

        ok = 1;
    
} break;
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

    *result = fn_12_3256C_array_read(movie, 0xb1);
    return 1;
}

