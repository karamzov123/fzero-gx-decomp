#include "types.h"


/* --- rel/movie_module/fn_12_21DD4.c --- */
extern int fn_12_2F210(void *module, void *movie, int command, int value, int flags);

int fn_12_21DD4(void *module, int index, int value) {
    u8 *entry = (u8 *)module + index * 0x74;

    if (*(s32 *)(entry + 0x1144) == 0) {
        return fn_12_2F210(module, *(void **)(entry + 0x118c), 0xb, value, 0);
    }
    return 0;
}

/* --- rel/movie_module/fn_12_21E20.c --- */
typedef struct MovieEntry {
    char unk00[0x2c];
    int value;
    char unk30[0x44];
} MovieEntry;

typedef struct MovieModule {
    char unk0000[0x1148];
    MovieEntry entries[1];
} MovieModule;

void fn_12_21E20(MovieModule *module, int index, int delta) {
    if (module->entries[index].value < 0) {
        return;
    }
    module->entries[index].value += delta;
}

/* --- rel/movie_module/fn_12_21E40.c --- */
extern int fn_12_24A88(void *module, int movie);

int fn_12_21E40(void *module, int index, int *movie_id) {
    u8 *entry = (u8 *)module + index * 0x74;

    *movie_id = 0;
    if (*(s32 *)(entry + 0x1144) == 0) {
        return fn_12_24A88(module, 0xff000000 + 0x401);
    }

    *movie_id = *(s32 *)(entry + 0x1154);
    return 0;
}
