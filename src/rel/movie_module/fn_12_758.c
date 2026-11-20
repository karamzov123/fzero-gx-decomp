#include "types.h"


/* --- rel/movie_module/fn_12_758.c --- */
extern void fn_12_34A8(void *);

typedef struct MovieModule {
    u8 pad2c[0x2c];
    void *value;
} MovieModule;

void fn_12_758(MovieModule *self) {
    fn_12_34A8(self->value);
}

/* --- rel/movie_module/fn_12_77C.c --- */
extern void fn_12_34C4(void *value);

void fn_12_77C(MovieModule *self) {
    fn_12_34C4(self->value);
}

/* --- rel/movie_module/fn_12_7A0.c --- */
typedef struct Fn127A0Object {
    u8 _pad20[0x20];
    void *value;
} Fn127A0Object;

extern void fn_12_365C(void *value);

void fn_12_7A0(Fn127A0Object *self) {
    fn_12_365C(self->value);
}
