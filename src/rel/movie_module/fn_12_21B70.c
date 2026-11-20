#include "types.h"


/* --- rel/movie_module/fn_12_21B70.c --- */
typedef struct MovieModule MovieModule;
typedef void (*MovieCallback)(MovieModule *, void *, void *);

struct MovieModule {
    u8 _pad[0x1c84];
    struct {
        u8 _pad0[4];
        MovieCallback callback;
    } *ops;
};

extern int fn_12_24990(MovieModule *);
extern void fn_12_24A88(int, u32);
extern int fn_12_2D73C(MovieModule *, int);

void fn_12_21B70(MovieModule *module, void *arg0, void *arg1) {
    if (fn_12_24990(module) != 0) {
        fn_12_24A88(0, 0xff0001a1);
    } else if (fn_12_2D73C(module, 6) != 0) {
        module->ops->callback(module, arg0, arg1);
    }
}

/* --- rel/movie_module/fn_12_21C00.c --- */
typedef struct MovieModule_u1 MovieModule_u1;
typedef struct MovieObject MovieObject;
typedef struct MovieObjectVtable MovieObjectVtable;

struct MovieObjectVtable {
    u8 _pad0[0x18];
    int (*read)(MovieObject *, int, u32, void *);
    int (*get)(MovieObject *, int, void *);
    u8 _pad1[4];
    int (*read_count)(MovieObject *, int);
};

struct MovieObject {
    MovieObjectVtable *vtable;
};

struct MovieModule_u1 {
    u8 _pad0[0x1144];
    int enabled;
    u8 _pad1[0xc];
    MovieObject *movie;
};

extern void fn_12_24970(u32 *);
extern void fn_12_24950(u32 *);

int fn_12_21C00(MovieModule_u1 *modules, int index) {
    int (*fzgx_live)(MovieObject *, int);
    u32 state;
    int out2[2];
    int out1[2];
    int result;
    MovieObject *movie;
    u32 extra;
    MovieModule_u1 *module;

    module = (MovieModule_u1 *)((u8 *)modules + index * 0x74);
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
