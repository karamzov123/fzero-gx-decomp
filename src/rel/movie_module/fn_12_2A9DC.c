#include "types.h"


/* --- rel/movie_module/fn_12_2A9DC.c --- */
/* --- rel/movie_module/fn_12_2A9DC.c --- */
typedef struct MovieEntry {
    int type;
    char pad[4];
    int priority;
    char tail[0x6c];
} MovieEntry;

typedef struct MovieManager {
    char pad0[0x7c];
    int flag_a;
    int flag_b;
    char pad1[0xb0];
    int count;
    MovieEntry entries[1];
} MovieManager;

typedef struct MovieObject {
    char pad[0x1b30];
    MovieManager *manager;
} MovieObject;

extern void fn_12_24970(void *);
extern void fn_12_24950(void *);

MovieEntry *fn_12_2A9DC(MovieObject *movie, int *result) {
    MovieEntry *best;
    int selected;
    MovieEntry *entry;
    MovieManager *manager;
    int count;
    int i;
    int scratch;
    int replace;

    fn_12_24970(&scratch);
    manager = movie->manager;
    best = 0;
    selected = 0;
    count = manager->count;
    entry = manager->entries;
    *result = 0;
    for (i = 0; i < count; i++) {
        if (entry->type == 2 || entry->type == 4) {
            selected++;
            if (best == 0) {
                replace = 1;
            } else if (best->priority > entry->priority) {
                replace = 1;
            } else {
                replace = 0;
            }
            if (replace) {
                best = entry;
            }
        }
        entry++;
    }
    if (selected == 1) {
        if (manager->flag_a != 0) {
            *result = 1;
        } else if (manager->flag_b == 0) {
            best = 0;
        }
    }
    fn_12_24950(&scratch);
    return best;
}

/* --- rel/movie_module/fn_12_2AAD4.c --- */
struct fn_12_2AAD4_Arg0 {
    u32 unk_0;
};

u32 fn_12_2AAD4(struct fn_12_2AAD4_Arg0 *arg0) {
    if ((u32)arg0 == 0) { return (u32)arg0; }
    if ((s32)arg0->unk_0 == 4) {
    arg0->unk_0 = 2;
    return (u32)arg0;
    }
    arg0->unk_0 = 0;
}

/* --- rel/movie_module/fn_12_2AB00.c --- */
struct fn_12_2AB00_Arg0 {
    u32 unk_0;
};

u32 fn_12_2AB00(struct fn_12_2AB00_Arg0 *arg0) {
    if ((u32)arg0 == 0) { return (u32)arg0; }
    if ((s32)arg0->unk_0 == 4) {
    arg0->unk_0 = 3;
    return (u32)arg0;
    }
    arg0->unk_0 = 0;
}

/* --- rel/movie_module/fn_12_2AB2C.c --- */
void fn_12_2AB2C(int *value) {
    if (value != 0) {
        *value = 4;
    }
}

/* --- rel/movie_module/fn_12_2AB40.c --- */
void fn_12_2AB40(int *arg0) {
    if (arg0 != 0) {
        *arg0 = 2;
    }
}

/* --- rel/movie_module/fn_12_2AB54.c --- */
void fn_12_2AB54(int* value) {
    if (value != 0) {
        *value = 0;
    }
}

/* --- rel/movie_module/fn_12_2AB68.c --- */
typedef struct MovieEntry_u1 {
    int used;
    u8 pad[0x74];
} MovieEntry_u1;

typedef struct MovieList {
    u8 pad[0x134];
    int count;
    MovieEntry_u1 entries[1];
} MovieList;

typedef struct MovieObject_u1 {
    u8 pad[0x1b30];
    MovieList *list;
} MovieObject_u1;

struct MovieContext {
    u32 words[2];
};


MovieEntry_u1 *fn_12_2AB68(MovieObject_u1 *movie) {
    struct MovieContext context;
    int i;
    MovieList *list;
    MovieEntry_u1 *entry;
    int count;

    fn_12_24970(&context);
    list = movie->list;
    count = list->count;
    entry = list->entries;
    i = 0;
    while (i < count) {
        if (entry->used == 0) {
            entry->used = 1;
            break;
        }
        i++;
        entry++;
    }
    if (i == count) {
        entry = 0;
    }
    fn_12_24950(&context);
    return entry;
}

/* --- rel/movie_module/fn_12_2ABF0.c --- */
typedef struct MovieObject_u2 MovieObject_u2;
typedef struct MovieState MovieState;
typedef struct MovieEntry_u2 MovieEntry_u2;


struct MovieObject_u2 {
    u8 _pad_1b30[0x1b30];
    MovieState *state;
};

struct MovieEntry_u2 {
    int type;
    u8 _pad_74[0x74];
};

struct MovieState {
    u8 _pad_7c[0x7c];
    int status;
    u8 _pad_134[0xb4];
    int count;
    u8 entries[1];
};

int fn_12_2ABF0(MovieObject_u2 *movie) {
    MovieState *state;
    MovieEntry_u2 *entry;
    int count;
    int result;
    u8 value[8];

    fn_12_24970(value);
    state = movie->state;
    result = 0;
    count = state->count;
    entry = (MovieEntry_u2 *)state->entries;
    while (count > 0) {
        if (entry->type == 2 || entry->type == 4) {
            result++;
        }
        entry++;
        count--;
    }
    if (state->status == 1 && result == 0) {
        result = -1;
    }
    fn_12_24950(value);
    return result;
}

/* --- rel/movie_module/fn_12_2AC80.c --- */
typedef struct MovieObject_u3 MovieObject_u3;
typedef struct MovieState_u3 MovieState_u3;

struct MovieObject_u3 {
    u8 _pad_1b30[0x1b30];
    MovieState_u3 *state;
};

struct MovieState_u3 {
    u8 _pad_80[0x80];
    int value;
};

void fn_12_2AC80(MovieObject_u3 *movie, int value) {
    movie->state->value = value;
}

/* --- rel/movie_module/fn_12_2AC8C.c --- */
struct MovieModule {
    char pad_1b30[0x1b30];
    struct MovieState_u4 *state;
};

struct MovieState_u4 {
    char pad_7c[0x7c];
    int value;
};

int fn_12_2AC8C(struct MovieModule *module) {
    return module->state->value;
}

/* --- rel/movie_module/fn_12_2AC98.c --- */
/* --- rel/movie_module/fn_12_2AC98.c --- */
typedef struct MovieModule_u5 {
    u8 pad_0000[0x1b30];
    struct MovieState_u5 *state;
} MovieModule_u5;

typedef struct MovieState_u5 {
    u8 pad_0000[0x7c];
    int field_007c;
} MovieState_u5;

void fn_12_2AC98(MovieModule_u5 *module) {
    module->state->field_007c = 1;
}

/* --- rel/movie_module/fn_12_2ACA8.c --- */
typedef struct MovieModule_u5 MovieModule_u5;

extern int fn_12_24990(MovieModule_u5 *module, const char *name);
extern int fn_12_24A88(int value, u32 address);
extern void fn_12_2D7DC(MovieModule_u5 *module, int value, const char *name);

int fn_12_2ACA8(MovieModule_u5 *module, const char *name) {
    if (fn_12_24990(module, name)) {
        return fn_12_24A88(0, 0xff000146);
    }

    fn_12_2D7DC(module, 0x1d, name);
    return 0;
}
