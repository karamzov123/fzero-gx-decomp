#include "types.h"


/* --- rel/movie_module/fn_12_2AC98.c --- */
typedef struct MovieModule {
    u8 pad_0000[0x1b30];
    struct MovieState *state;
} MovieModule;

typedef struct MovieState {
    u8 pad_0000[0x7c];
    int field_007c;
} MovieState;

void fn_12_2AC98(MovieModule *module) {
    module->state->field_007c = 1;
}

/* --- rel/movie_module/fn_12_2ACA8.c --- */
typedef struct MovieModule MovieModule;

extern int fn_12_24990(MovieModule *module, const char *name);
extern int fn_12_24A88(int value, u32 address);
extern void fn_12_2D7DC(MovieModule *module, int value, const char *name);

int fn_12_2ACA8(MovieModule *module, const char *name) {
    if (fn_12_24990(module, name)) {
        return fn_12_24A88(0, 0xff000146);
    }

    fn_12_2D7DC(module, 0x1d, name);
    return 0;
}
