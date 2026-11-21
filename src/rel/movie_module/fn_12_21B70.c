#include "types.h"


/* --- rel/movie_module/fn_12_21B70.c --- */
/* --- rel/movie_module/fn_12_21B70.c --- */
typedef struct MovieModule_u0 MovieModule_u0;
typedef void (*MovieCallback)(MovieModule_u0 *, void *, void *);

struct MovieModule_u0 {
    u8 _pad[0x1c84];
    struct {
        u8 _pad0[4];
        MovieCallback callback;
    } *ops;
};

extern int fn_12_24990(MovieModule_u0 *);
extern void fn_12_24A88(int, u32);
extern int fn_12_2D73C(MovieModule_u0 *, int);

void fn_12_21B70(MovieModule_u0 *module, void *arg0, void *arg1) {
    if (fn_12_24990(module) != 0) {
        fn_12_24A88(0, 0xff0001a1);
    } else if (fn_12_2D73C(module, 6) != 0) {
        module->ops->callback(module, arg0, arg1);
    }
}

/* --- rel/movie_module/fn_12_21C00.c --- */
typedef struct MovieModule_u1_u0 MovieModule_u1_u0;
typedef struct MovieObject_u0 MovieObject_u0;
typedef struct MovieObjectVtable_u0 MovieObjectVtable_u0;

struct MovieObjectVtable_u0 {
    u8 _pad0[0x18];
    int (*read)(MovieObject_u0 *, int, u32, void *);
    int (*get)(MovieObject_u0 *, int, void *);
    u8 _pad1[4];
    int (*read_count)(MovieObject_u0 *, int);
};

struct MovieObject_u0 {
    MovieObjectVtable_u0 *vtable;
};

struct MovieModule_u1_u0 {
    u8 _pad0[0x1144];
    int enabled;
    u8 _pad1[0xc];
    MovieObject_u0 *movie;
};

extern void fn_12_24970(u32 *);
extern void fn_12_24950(u32 *);

int fn_12_21C00(MovieModule_u1_u0 *modules, int index) {
    int (*fzgx_live)(MovieObject_u0 *, int);
    u32 state;
    int out2[2];
    int out1[2];
    int result;
    MovieObject_u0 *movie;
    u32 extra;
    MovieModule_u1_u0 *module;

    module = (MovieModule_u1_u0 *)((u8 *)modules + index * 0x74);
    extra = result = 0;
    movie = module->movie;
    if (module->enabled != 0 && movie != 0) {
        fn_12_24970(&state);
        fzgx_live = movie->vtable->read_count;
        result = fzgx_live(movie, 1);
        movie->vtable->read(movie, 1, 0x7fffffff, out1);
        if (out1[1] < result) {
            movie->vtable->read(movie, 1, 0x7fffffff, out2);
            movie->vtable->get(movie, 1, out2);
        } else {
            out2[0] = 0;
            out2[1] = 0;
        }
        movie->vtable->get(movie, 1, out1);
        result = out1[1];
        extra = out2[1];
        fn_12_24950(&state);
    }
    return result + (int)extra;
}

/* --- rel/movie_module/fn_12_21D30.c --- */
/* --- rel/movie_module/fn_12_21D30.c --- */
/* --- rel/movie_module/fn_12_21D30.c --- */
struct fn_12_21D30_E116_u32 { u32 unk_0; u8 pad_4[0x70]; };
struct fn_12_21D30_Arg0 {
    u8 pad_0[0x114C];
    struct fn_12_21D30_E116_u32 unk_114C[1];
};

u32 fn_12_21D30(struct fn_12_21D30_Arg0 *arg0, u32 arg1) {
    return arg0->unk_114C[arg1].unk_0;
}

/* --- rel/movie_module/fn_12_21D40.c --- */
void fn_12_21D40(void *base, int index, int value) {
    u8 *p = (u8 *)base;
    int offset = index * 0x74;
    p += offset;
    *(int *)(p + 0x114c) = value;
}

/* --- rel/movie_module/fn_12_21D50.c --- */
typedef struct MovieEntry {
    int value;
    char unk04[0x70];
} MovieEntry;

typedef struct MovieModule_u1 {
    char unk0000[0x1148];
    MovieEntry entries[1];
} MovieModule_u1;

int fn_12_21D50(MovieModule_u1 *module, int index) {
    return module->entries[index].value;
}

/* --- rel/movie_module/fn_12_21D60.c --- */
typedef struct MovieEntry_u1 {
    int value;
    u8 padding[0x70];
} MovieEntry_u1;

typedef struct MovieModule_u1_u1 {
    u8 padding[0x1148];
    MovieEntry_u1 entries[1];
} MovieModule_u1_u1;

void fn_12_21D60(MovieModule_u1_u1 *module, int index, int value) {
    module->entries[index].value = value;
}

/* --- rel/movie_module/fn_12_21D70.c --- */
typedef struct MovieRecord {
    u8 padding00[0x1144];
    int status;
    u8 padding1148[0x44];
    void *resource;
} MovieRecord;

typedef struct MovieModule_u2 {
    u8 padding00[0x44];
    int active;
} MovieModule_u2;

extern int fn_12_2F210(MovieModule_u2 *module, void *resource, int size, void *argument, int flags);

int fn_12_21D70(MovieModule_u2 *module, int index, void *argument) {
    int result = 0;
    MovieRecord *entry = (MovieRecord *)((u8 *)module + index * 0x74);

    if (entry->status == 0) {
        result = fn_12_2F210(module, entry->resource, 0xc, argument, 0);
    }

    module->active = 1;
    return result;
}
