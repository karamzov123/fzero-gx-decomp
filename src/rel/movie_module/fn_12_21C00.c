#include "types.h"

typedef struct MovieModule MovieModule;
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

struct MovieModule {
    u8 _pad0[0x1144];
    int enabled;
    u8 _pad1[0xc];
    MovieObject *movie;
};

extern void fn_12_24970(u32 *);
extern void fn_12_24950(u32 *);

#pragma opt_propagation off


int fn_12_21C00(MovieModule *modules, int index) {
    int (*fzgx_live)(MovieObject *, int);
    u32 state;
    int out2[2];
    int out1[2];
    int result = 0;
    MovieObject *movie;
    u32 extra;
    MovieModule *module;

    module = (MovieModule *)((u8 *)modules + index * 0x74);
    extra = result;
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
#pragma opt_propagation reset


