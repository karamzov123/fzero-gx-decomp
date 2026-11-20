#include "types.h"
#include "ppc_ops.h"


/* --- rel/movie_module/fn_12_CAE4.c --- */
typedef s32 MovieCallback;

typedef struct MovieObject {
    u8 pad_0000[0x188];
    s32 state;
    u8 pad_018c[4];
    MovieCallback callbacks[1];
} MovieObject;

typedef struct MovieManager {
    u8 pad_0000[0x54];
    s32 count;
    MovieObject *objects;
} MovieManager;

extern void fn_12_CBC4(void);
extern u32 lbl_12_bss_528C[25];
extern u32 lbl_12_bss_5280[3];
extern s32 fn_12_A660(s32, s32);

s32 fn_12_CAE4(MovieObject *movie, s32 index, MovieCallback callback) {
    MovieCallback *callbacks = 0;
    MovieManager *manager;
    s32 count;
    MovieObject *object;
    s32 i;
    s32 result;
    MovieCallback value;

    value = callback;
    if (index == 8 && callback == 0) {
        value = (s32)fn_12_CBC4;
    }
    if (movie == 0) {
        manager = (MovieManager *)lbl_12_bss_528C;
        count = manager->count;
        object = manager->objects;
        for (i = 0; i < count; i++) {
            if (object->state == 2) {
                object->callbacks[index] = value;
            }
            object = (MovieObject *)((u8 *)object + 0x2000);
        }
        callbacks = (MovieCallback *)lbl_12_bss_528C;
    } else {
        lbl_12_bss_5280[0] = (u32)movie;
        if (movie == 0) {
            result = -1;
        } else if (movie->state != 2) {
            result = -1;
        } else {
            result = 0;
        }
        if (result != 0) {
            return fn_12_A660(0, 0xff030202);
        }
        callbacks = movie->callbacks;
    }
    callbacks[index] = value;
    return 0;
}

/* --- rel/movie_module/fn_12_CBC4.c --- */
// fn_12_CBC4: empty in retail (single blr).
void fn_12_CBC4(void) {
}

/* --- rel/movie_module/fn_12_CBC8.c --- */
extern void fn_12_20178(u32);

s32 fn_12_CBC8(u32 arg0) {
    u32 v0;
    s32 v1;
    s32 t0;
    u32 movie;

    movie = arg0;
    lbl_12_bss_5280[0] = movie;
    if (movie == 0) {
        t0 = -1;
    } else if (*(s32 *)((u8 *)movie + 392) != 2) {
        t0 = -1;
    } else {
        t0 = 0;
    }
    if (t0 != 0) {
        return fn_12_A660(0, 0xFF030201);
    }
    fn_12_20178(movie);
    if ((lbl_12_bss_528C[18] & 0x10000000) != 0) {
        v1 = 0;
        for (v0 = 256; v0 != 0; v0--) {
            ppc_dcbi((void *)movie, v1);
            v1 += 32;
        }
    }
    *(u32 *)((u8 *)movie + 392) = 1;
    return 0;
}

/* --- rel/movie_module/fn_12_CCB0.c --- */
typedef struct MovieData {
    u8 unk_90[0x90];
    u32 unk_120;
    u32 unk_124;
} MovieData;

void fn_12_CCB0(const MovieData *movie, u32 *first, u32 *second) {
    *first = movie->unk_120;
    *second = movie->unk_124;
}
