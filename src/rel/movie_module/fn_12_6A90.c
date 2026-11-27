#include "types.h"

/* --- rel/movie_module/fn_12_6A90.c --- */
typedef struct MovieModule_u1 {
    s32 state;
} MovieModule_u1;

typedef struct MovieError {
    void (*callback)(void *, s32);
    void *argument;
    s32 error;
} MovieError;

extern u32 lbl_12_bss_4DB0;
extern u32 lbl_12_bss_4DB8[2];

static inline s32 report_error(s32 unused, s32 error) {
    MovieError *handler = (MovieError *)lbl_12_bss_4DB8[0];
    handler->error = error;
    if (handler->callback != 0) {
        handler->callback(handler->argument, error);
    }
    return error;
}

s32 fn_12_6A90(MovieModule_u1 *module) {
    s32 invalid;
    lbl_12_bss_4DB0 = (u32)module;
    if (module == 0) {
        invalid = -1;
    } else if (module->state == 1) {
        invalid = -1;
    } else {
        invalid = 0;
    }
    if (invalid != 0) {
        return report_error(0, 0xff020103);
    }
    module->state = 1;
    return 0;
}
