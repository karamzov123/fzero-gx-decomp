#include "types.h"


/* --- rel/movie_module/fn_12_2AD10.c --- */
extern int fn_12_24990(void *module);
extern int fn_12_24A88(int value, int code);
extern void fn_12_2D7DC(void *module, int value, int argument);

int fn_12_2AD10(void *module, int argument) {
    if (fn_12_24990(module)) {
        return fn_12_24A88(0, 0xff000145);
    }
    fn_12_2D7DC(module, 0x1e, argument);
    return 0;
}

/* --- rel/movie_module/fn_12_2AD78.c --- */
struct MovieModule {
    char pad_4c[0x4c];
    int value;
};

int fn_12_2AD78(struct MovieModule *module) {
    module->value = 3;
    return 0;
}
