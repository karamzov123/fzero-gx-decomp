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

MovieEntry *fn_12_2A9DC(MovieObject *movie, int *result);

/* --- rel/movie_module/fn_12_2AAD4.c --- */
struct fn_12_2AAD4_Arg0 {
    u32 unk_0;
};

u32 fn_12_2AAD4(struct fn_12_2AAD4_Arg0 *arg0);

/* --- rel/movie_module/fn_12_2AB00.c --- */
struct fn_12_2AB00_Arg0 {
    u32 unk_0;
};

u32 fn_12_2AB00(struct fn_12_2AB00_Arg0 *arg0);

/* --- rel/movie_module/fn_12_2AB2C.c --- */
void fn_12_2AB2C(int *value);

/* --- rel/movie_module/fn_12_2AB40.c --- */
void fn_12_2AB40(int *arg0);

/* --- rel/movie_module/fn_12_2AB54.c --- */
void fn_12_2AB54(int* value);

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


MovieEntry_u1 *fn_12_2AB68(MovieObject_u1 *movie);

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

int fn_12_2ABF0(MovieObject_u2 *movie);

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

void fn_12_2AC80(MovieObject_u3 *movie, int value);

/* --- rel/movie_module/fn_12_2AC8C.c --- */
struct MovieModule {
    char pad_1b30[0x1b30];
    struct MovieState_u4 *state;
};

struct MovieState_u4 {
    char pad_7c[0x7c];
    int value;
};

int fn_12_2AC8C(struct MovieModule *module);

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

void fn_12_2AC98(MovieModule_u5 *module);

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
