#include "types.h"

typedef void (*MovieCallback)(void *, s32);

typedef struct MovieModule {
    s32 state;
    MovieCallback callback;
    void *argument;
} MovieModule;

typedef struct MovieError {
    MovieCallback callback;
    void *argument;
    s32 error;
} MovieError;

extern u32 lbl_12_bss_4DB8[2];
extern u32 lbl_12_bss_4DB0;

static inline s32 check_module(MovieModule *module) {
    s32 invalid;
    invalid = -1;
    if (module == NULL) {
        invalid = -1;
    } else if (module->state == 1) {
        invalid = -1;
    } else {
        invalid = 0;
    }
    return invalid;
}

static inline s32 report_error(s32 unused, s32 error) {
    MovieError *handler = (MovieError *)lbl_12_bss_4DB8[0];
    handler->error = error;
    if (handler->callback != 0) {
        handler->callback(handler->argument, error);
    }
    return error;
}

s32 fn_12_6CA8(MovieModule *module, MovieCallback callback, void *argument) {
    s32 invalid;

    if (module == 0) {
        MovieError *handler = (MovieError *)lbl_12_bss_4DB8[0];
        handler->callback = callback;
        handler->argument = argument;
    } else {
        lbl_12_bss_4DB0 = (u32)module;

        invalid = check_module(module);
        if (invalid != 0) {
            return report_error(0, 0xFF020101);
        }

        module->callback = callback;
        module->argument = argument;
    }
    return 0;
}
