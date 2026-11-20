#include "types.h"


/* --- rel/movie_module/fn_12_9730.c --- */
typedef struct MovieModule {
    u8 _pad0[0x318];
    u32 field_318;
    u32 field_31c;
    u32 field_320;
} MovieModule;

void fn_12_9730(MovieModule *module) {
    module->field_318 = 0x400;
    module->field_320 = 0x400;
    module->field_31c = 0x400;
}

/* --- rel/movie_module/fn_12_9744.c --- */
typedef struct MovieState {
    u8 _pad10[0x10];
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1c;
} MovieState;

void fn_12_9744(MovieState *movie) {
    movie->field_10 = 0;
    movie->field_14 = 0;
    movie->field_18 = 0;
    movie->field_1c = 0;
}
