#include "types.h"


/* --- rel/movie_module/fn_12_21DD4.c --- */
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

/* --- rel/movie_module/fn_12_21E94.c --- */
typedef struct MovieObject MovieObject;
typedef int (*MovieCallback)(MovieObject *, int);

typedef struct MovieVtable {
    char padding[0x24];
    MovieCallback callback;
} MovieVtable;

struct MovieObject {
    MovieVtable *vtable;
};

typedef struct MovieModule_u1 {
    char padding0[0x1154];
    MovieObject *object;
    char padding1[0x18];
    int value;
    int delta;
} MovieModule_u1;

extern void fn_12_24970(void *movie);
extern void fn_12_24950(void *movie);

int fn_12_21E94(MovieModule_u1 *module, int index) {
    char movie[8];
    MovieModule_u1 *entry;
    int value;
    int delta;

    entry = (MovieModule_u1 *)((char *)module + index * 0x74);
    fn_12_24970(movie);
    value = entry->value;
    delta = entry->delta;
    if (value == 0 && delta != 0) {
        value = delta + entry->object->vtable->callback(entry->object, 1);
    }
    if (value < 0) {
        value = 0x7fffffff;
    }
    fn_12_24950(movie);
    return value;
}

/* --- rel/movie_module/fn_12_21F28.c --- */
struct MovieEntry_u2 {
    int value;
    char padding[0x70];
};

struct MovieModule_u2 {
    char padding[0x1174];
    struct MovieEntry_u2 entries[1];
};

int fn_12_21F28(struct MovieModule_u2 *module, int index) {
    return module->entries[index].value;
}

/* --- rel/movie_module/fn_12_21F38.c --- */
/* --- rel/movie_module/fn_12_21F38.c --- */
typedef struct MovieEntry_u3 {
    int value;
    u8 pad[0x70];
} MovieEntry_u3;

typedef struct MovieModule_u3 {
    u8 pad[0x115c];
    MovieEntry_u3 entries[1];
} MovieModule_u3;

int fn_12_21F38(MovieModule_u3 *module, int index) {
    return module->entries[index].value;
}

/* --- rel/movie_module/fn_12_21F48.c --- */
typedef struct MovieObject_u3 {
    u8 pad[0x1168];
    void *movie;
    void *stream;
} MovieObject_u3;

typedef struct MovieState {
    u8 data[4];
} MovieState;


void fn_12_21F48(u8 *module, int index, void *movie, void *stream) {
    MovieState state;
    MovieObject_u3 *entry;

    entry = (MovieObject_u3 *)(module + index * 0x74);
    fn_12_24970(&state);
    entry->movie = movie;
    entry->stream = stream;
    fn_12_24950(&state);
}

/* --- rel/movie_module/fn_12_21FA4.c --- */
typedef struct MovieEntry_u4 {
    u8 pad[0x1168];
    int value1;
    int value2;
} MovieEntry_u4;

typedef struct MovieModule_u4 {
    u8 pad[1];
} MovieModule_u4;


void fn_12_21FA4(MovieModule_u4 *module, int index, int *value1, int *value2) {
    MovieEntry_u4 *entry = (MovieEntry_u4 *)((u8 *)module + index * 0x74);
    u8 movie_data[8];

    fn_12_24970(movie_data);
    *value1 = entry->value1;
    *value2 = entry->value2;
    fn_12_24950(movie_data);
}
