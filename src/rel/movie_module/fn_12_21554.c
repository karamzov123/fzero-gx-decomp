#include "types.h"


/* --- rel/movie_module/fn_12_21554.c --- */
typedef struct MovieInner {
    void *value;
} MovieInner;

typedef struct Movie {
    u8 pad_0000[0x1b74];
    MovieInner *inner;
} Movie;

extern void fn_8004BED0(void *value);

void fn_12_21554(Movie *movie) {
    fn_8004BED0(movie->inner->value);
}

/* --- rel/movie_module/fn_12_2157C.c --- */
typedef struct MovieModule {
    char _pad[0x1b74];
    void *movie;
} MovieModule;

extern void fn_8004BF0C(void *movie);

void fn_12_2157C(MovieModule *self) {
    fn_8004BF0C(*(void **)self->movie);
}
