#include "types.h"


/* --- rel/movie_module/fn_12_3A968.c --- */
typedef struct MovieObject {
    u8 pad[0x60];
    s32 value;
} MovieObject;

void fn_12_3A968(MovieObject *self, s32 value) {
    self->value = value;
}

/* --- rel/movie_module/fn_12_3A970.c --- */
extern u32 fn_12_38DBC(u32);

void fn_12_3A970(u32 arg0) {
    u32 t0;
    t0 = fn_12_38DBC(arg0);
    *(u32 *)((u8 *)t0 + 84) = arg0;
}
