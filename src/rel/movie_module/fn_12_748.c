#include "types.h"


/* --- rel/movie_module/fn_12_748.c --- */
typedef struct MovieModule {
    u8 pad30[0x30];
    int value;
} MovieModule;

int fn_12_748(MovieModule *self) {
    return self->value;
}

/* --- rel/movie_module/fn_12_750.c --- */
typedef struct Fn12750Object {
    u8 _pad30[0x30];
    u32 value;
} Fn12750Object;

void fn_12_750(Fn12750Object *self, u32 value) {
    self->value = value;
}
