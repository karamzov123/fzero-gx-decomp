#include "types.h"


/* --- rel/movie_module/fn_12_34C4.c --- */
typedef struct MovieState {
    u32 unk0;
    u32 active;
    u32 unk8;
    u32 value4;
    u32 value5;
} MovieState;

void fn_12_34C4(MovieState *self, u32 value4, u32 value5, u32 value8) {
    self->unk8 = value8;
    self->value4 = value4;
    self->value5 = value5;
    self->active = 1;
}

/* --- rel/movie_module/fn_12_34DC.c --- */
typedef struct MovieModuleObject {
    int field_0;
    int field_4;
} MovieModuleObject;

int fn_12_34DC(MovieModuleObject *module) {
    return module->field_4;
}

/* --- rel/movie_module/fn_12_34E4.c --- */
extern void fn_12_3B65C(void *);

void fn_12_34E4(void *arg0, void *arg1, void *arg2) {
    fn_12_3B65C(arg2);
}
