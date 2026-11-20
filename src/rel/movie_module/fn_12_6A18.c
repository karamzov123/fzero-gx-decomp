#include "types.h"


/* --- rel/movie_module/fn_12_6A18.c --- */
typedef struct MovieValues {
    u32 value_14;
    u32 value_18;
    u32 value_1c;
} MovieValues;

typedef struct MovieModule {
    u8 pad[0x14];
    MovieValues values;
} MovieModule;

extern int fn_12_6C78(MovieModule *module);
extern int fn_12_6D5C(int arg0, int arg1);

int fn_12_6A18(MovieModule *module, MovieValues *result) {
    if (fn_12_6C78(module)) {
        return fn_12_6D5C(0, 0xff020201);
    }
    *result = module->values;
    return 0;
}

/* --- rel/movie_module/fn_12_6A88.c --- */
// fn_12_6A88: empty in retail (single blr).
void fn_12_6A88(void) {
}

/* --- rel/movie_module/fn_12_6A8C.c --- */
// fn_12_6A8C: empty in retail (single blr).
void fn_12_6A8C(void) {
}
