#include "types.h"

/* --- rel/movie_module/fn_12_3412C.c --- */
extern void fn_12_21AE4(void *);

typedef struct MovieModule_u1 {
    u8 pad_00[0x40];
    void *field_40;
} MovieModule_u1;

void fn_12_3412C(MovieModule_u1 *self) {
    fn_12_21AE4(self->field_40);
}

/* --- rel/movie_module/fn_12_34150.c --- */
typedef struct MovieModule_u2 {
    u8 pad[0x40];
    void *movie;
} MovieModule_u2;

extern void fn_12_21B70(void *movie);

void fn_12_34150(MovieModule_u2 *module) {
    fn_12_21B70(module->movie);
}

/* --- rel/movie_module/fn_12_34174.c --- */
/* --- rel/movie_module/fn_12_34174.c --- */
extern void fn_12_219E8(void *);

void fn_12_34174(MovieModule_u1 *self) {
    fn_12_219E8(self->field_40);
}

/* --- rel/movie_module/fn_12_34198.c --- */
extern void fn_12_21A64(void *);

void fn_12_34198(MovieModule_u1 *module) {
    fn_12_21A64(module->field_40);
}
