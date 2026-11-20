#include "types.h"


/* --- rel/movie_module/fn_12_26B18.c --- */
typedef struct MovieObject {
    unsigned char pad_0[0xef8];
    int field_ef8;
    int field_efc;
} MovieObject;

typedef struct MovieData {
    unsigned char pad_0[0x14];
    int field_14;
    int field_18;
} MovieData;

extern int fn_12_2ABF0(void *);
extern MovieData *fn_12_2A9DC(void *, int *);
extern void fn_12_269E4(void *, MovieData *, MovieData **);

int fn_12_26B18(MovieObject *movie, MovieData **out) {
    int local;
    MovieData *data;

    if (fn_12_2ABF0(movie) == -1) {
        *out = 0;
        return 0;
    }

    data = fn_12_2A9DC(movie, &local);
    if (data == 0) {
        *out = 0;
        return 0;
    }

    fn_12_269E4(movie, data, out);
    movie->field_ef8 = (*out)->field_14;
    movie->field_efc = (*out)->field_18;
    return 0;
}

/* --- rel/movie_module/fn_12_26BB4.c --- */
extern void fn_12_24A88(int, int);

void fn_12_26BB4(int arg0) {
    fn_12_24A88(arg0, 0xff000f0d);
}
