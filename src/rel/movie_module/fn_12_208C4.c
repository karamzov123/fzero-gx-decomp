#include "types.h"

extern int fn_12_2D73C(void *, int);
extern int fn_12_206B8(void *, void *);
extern u32 fn_12_2B348(void);
extern u32 lbl_12_bss_7C64[137];
extern int fn_12_24A88(void *, int);
extern void fn_8004BE90(void *, int);
extern void fn_8004ED18(void *, int);
extern void *fn_8004CD70(u32, u32, u32);
extern void *fn_80058498(u32, u32, u32);
extern void fn_8004C794(void *, void *);
extern void ADXT_Pause(void *, int);
extern void fn_12_309B8(void *, int);
extern void fn_12_205BC(void);
extern void fn_12_2E41C(void *, void (*)(void), int);
extern void fn_12_2D7DC(void *, int, int);
extern void fn_12_215CC(void);
extern void fn_12_215A4(void);
extern void fn_12_2157C(void);
extern void fn_12_21554(void);
extern void fn_12_214B0(void);

typedef struct MovieData {
    void *movie;
    void *field_0004;
    u32 field_0008;
    u32 field_000c;
    u32 field_0010;
    u32 field_0014;
    u32 field_0018;
    u32 field_001c;
    u32 field_0020;
} MovieData;

typedef struct Movie {
    u8 pad_0000[0xc];
    u32 field_000c;
} Movie;

typedef struct MovieModule {
    u8 pad_0000[0x50];
    int field_0050;
    u8 pad_0054[0xf0c];
    u8 field_0f60[1];
    u8 pad_0f61[0xc13];
    MovieData *field_1b74;
    u8 pad_1b78[0x10c];
    void *field_1c84;
    u8 pad_1c88[0xb84];
    MovieData field_280c;
    u8 pad_2830[0x88];
    void *field_28b8;
    void *field_28bc;
    void *field_28c0;
    void *field_28c4;
    void *field_28c8;
    void *field_28cc;
} MovieModule;

#pragma opt_propagation off
int fn_12_208C4(MovieModule *arg0) {
    void **fzgx_value;
    struct { Movie *value; } movie;
    struct { MovieData *value; } movie_data;
    void *movie_handle;
    int result;

    if (fn_12_2D73C(arg0, 6) == 0) {
        return 0;
    }
    movie_data.value = &arg0->field_280c;
    arg0->field_1b74 = movie_data.value;
    result = fn_12_206B8(arg0, movie_data.value);
    if (result != 0) {
        return result;
    }
    if ((int)fn_12_2B348() != 1) {
        movie.value = (Movie *)fn_8004CD70(movie_data.value->field_0014,
                                     movie_data.value->field_0020,
                                     movie_data.value->field_001c);
    } else {
        movie.value = (Movie *)((u32 *)(lbl_12_bss_7C64))[128];
    }
    if (movie.value == 0) {
        movie.value = 0;
    } else {
        fn_8004BE90(movie.value, 0);
        fn_8004ED18(movie.value, 1);
    }
    if (movie.value == 0) {
        return fn_12_24A88(arg0, 0xff000c04);
    }
    movie_handle = fn_80058498(movie_data.value->field_0010,
                               movie_data.value->field_0008,
                               movie_data.value->field_000c);
    if (movie_handle == 0) {
        return fn_12_24A88(arg0, 0xff000c05);
    }
    movie_data.value->movie = movie.value;
    movie_data.value->field_0004 = movie_handle;
    arg0->field_1c84 = &arg0->field_28b8;
    fzgx_value = &arg0->field_28b8;
    *fzgx_value = (void *)movie.value->field_000c;
    arg0->field_28bc = (void *)fn_12_215CC;
    arg0->field_28c0 = (void *)fn_12_215A4;
    arg0->field_28c4 = (void *)fn_12_2157C;
    arg0->field_28c8 = (void *)fn_12_21554;
    arg0->field_28cc = (void *)fn_12_214B0;
    fn_8004C794(movie.value, movie_handle);
    movie_data.value = arg0->field_1b74;
    movie_handle = movie_data.value->movie;
    *(u32 *)((u8 *)movie_data.value + 0x2c) = 1;
    ADXT_Pause(movie_handle, 1);
    fn_12_309B8(arg0->field_0f60, 1);
    fn_12_2E41C(arg0, fn_12_205BC, 2);
    fn_12_2D7DC(arg0, 15, 2);
    return 0;
}
#pragma opt_propagation reset
