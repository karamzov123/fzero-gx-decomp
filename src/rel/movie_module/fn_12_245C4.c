#include "types.h"


/* --- rel/movie_module/fn_12_245C4.c --- */
typedef struct MovieBuffer {
    u8 data[0x894];
} MovieBuffer;

typedef struct MovieData {
    u8 pad_00[0x0c];
    MovieBuffer buffer;
} MovieData;

typedef struct MovieModule {
    u8 pad_00[0x78];
    MovieBuffer buffer;
    u8 pad_90c[0x2908 - 0x90c];
    MovieData *movie;
} MovieModule;

extern int fn_12_24E94(MovieModule *self);
extern void fn_12_24570(void *data);

void fn_12_245C4(MovieModule *self) {
    MovieBuffer *copy;

    if (self->movie == 0) {
        copy = 0;
    } else if (fn_12_24E94(self) > 0) {
        copy = 0;
    } else {
        copy = &self->movie->buffer;
    }

    if (copy != 0) {
        self->buffer = *copy;
        fn_12_24570(self->buffer.data);
        *(u32 *)((u8 *)self + 0x930) = *(u32 *)((u8 *)self + 0x9c);
        *(u32 *)((u8 *)self + 0x934) = *(u32 *)((u8 *)self + 0xa0);
        *(u32 *)((u8 *)self + 0x938) = *(u32 *)((u8 *)self + 0xa4);
    }
}

/* --- rel/movie_module/fn_12_24670.c --- */
extern void fn_12_57F0(void *work, void *arg, int size);

int fn_12_24670(MovieModule *self, void *arg, int size) {
    int copy_size;
    MovieBuffer *copy;

    if (*(s32 *)self->buffer.data != 0) {
        return 0;
    }

    copy_size = 0x800;
    if (size < 0x800) {
        copy_size = size;
    }
    fn_12_57F0((u8 *)self + 0x10c, arg, copy_size);
    *(u32 *)((u8 *)self + 0x108) = copy_size;
    fn_12_24570(self->buffer.data);
    *(u32 *)((u8 *)self + 0x930) = *(u32 *)((u8 *)self + 0x9c);
    *(u32 *)((u8 *)self + 0x934) = *(u32 *)((u8 *)self + 0xa0);
    *(u32 *)((u8 *)self + 0x938) = *(u32 *)((u8 *)self + 0xa4);

    if (self->movie == 0) {
        copy = 0;
    } else if (fn_12_24E94(self) > 0) {
        copy = 0;
    } else {
        copy = (MovieBuffer *)((u8 *)self->movie + 0x0c);
    }
    if (copy != 0) {
        *copy = self->buffer;
    }
    return 1;
}

/* --- rel/movie_module/fn_12_24760.c --- */
extern void *fn_12_3310C(void);
extern int fn_12_32EAC(void *movie, u32 *result);
extern void fn_12_330E0(void *movie);

u32 fn_12_24760(void) {
    void *movie;
    u32 result;

    movie = fn_12_3310C();
    if (movie == 0) {
        return 0;
    }
    if (fn_12_32EAC(movie, &result) == 0) {
        result = 0;
    }
    fn_12_330E0(movie);
    return result;
}
