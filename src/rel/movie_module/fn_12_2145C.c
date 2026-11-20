#include "types.h"


/* --- rel/movie_module/fn_12_2145C.c --- */
extern struct fn_12_2145C_lbl_12_bss_6990 lbl_12_bss_6990;

struct fn_12_2145C_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};
struct fn_12_2145C_lbl_12_bss_6990 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

u32 fn_12_2145C(struct fn_12_2145C_Arg0 *arg0) {
    lbl_12_bss_6990.unk_0 = arg0->unk_0;
    lbl_12_bss_6990.unk_4 = arg0->unk_4;
    lbl_12_bss_6990.unk_8 = ((arg0->unk_8 + 31) & ~0x1F);
    lbl_12_bss_6990.unk_C = arg0->unk_C;
    lbl_12_bss_6990.unk_10 = arg0->unk_10;
    lbl_12_bss_6990.unk_14 = arg0->unk_14;
    lbl_12_bss_6990.unk_18 = ((arg0->unk_18 + 31) & ~0x1F);
    return arg0->unk_18;
}

/* --- rel/movie_module/fn_12_214B0.c --- */
typedef struct MovieInner {
    void *value;
} MovieInner;

typedef struct Movie {
    u8 pad_0000[0x1b74];
    MovieInner *inner;
} Movie;

extern const f64 lbl_12_rodata_A70;
extern const f32 lbl_12_rodata_A68;
extern const f32 lbl_12_rodata_A64;
extern const f32 lbl_12_rodata_A6C;

extern f64 fn_80088558(Movie *movie, f64 value);
extern void fn_8004BBC8(void *value, int minutes, int seconds);

void fn_12_214B0(Movie *movie, int value) {
    f32 elapsed;
    f32 scaled;
    int minutes;
    int seconds;

    elapsed = (f32)fn_80088558(movie, (f64)value);
    scaled = elapsed - lbl_12_rodata_A68;
    scaled = lbl_12_rodata_A64 * scaled;
    minutes = (int)(lbl_12_rodata_A6C * scaled);
    seconds = (int)scaled - minutes * 100;
    fn_8004BBC8(movie->inner->value, minutes, seconds);
}

/* --- rel/movie_module/fn_12_21554.c --- */
/* --- rel/movie_module/fn_12_21554.c --- */


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
