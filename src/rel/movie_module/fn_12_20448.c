#include "types.h"


/* --- rel/movie_module/fn_12_20448.c --- */
extern void ADXT_Stop(void *arg0);

typedef struct MovieModule {
    u8 pad_0000[0x1b74];
    void *field_1b74;
} MovieModule;

int fn_12_20448(MovieModule *arg0) {
    ADXT_Stop(*(void **)arg0->field_1b74);
    return 0;
}

/* --- rel/movie_module/fn_12_20474.c --- */
/* --- rel/movie_module/fn_12_20474.c --- */
extern void ADXT_Pause(void *arg0, int arg1);
extern void fn_12_309B8(void *arg0, int arg1);

typedef struct MovieModule_u1 {
    u8 pad_0000[0x50];
    int field_0050;
    u8 pad_0054[0xf0c];
    u8 field_0f60[1];
    u8 pad_0f61[0xc13];
    void *field_1b74;
} MovieModule_u1;

int fn_12_20474(MovieModule_u1 *arg0) {
    void *movie_module = (u8 *)arg0 + 0xf60;
    void *movie;
    void *movie_data;

    movie_data = arg0->field_1b74;
    movie = *(void **)movie_data;
    *(int *)((u8 *)movie_data + 0x2c) = 0;
    if (arg0->field_0050 != 1) {
        ADXT_Pause(movie, 0);
        fn_12_309B8(movie_module, 0);
    }
    return 0;
}

/* --- rel/movie_module/fn_12_204D4.c --- */
// fn_12_204D4: returns a constant.
int fn_12_204D4(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_204DC.c --- */
extern u32 lbl_12_bss_6990[8];
extern u32 fn_12_2B348(void);
extern u32 lbl_12_bss_7C64[137];
extern void fn_8004CAC8(void *arg0);

typedef struct MovieModule_u2 {
    u8 pad_0000[0x1b74];
    void *movie_data;
} MovieModule_u2;

typedef struct MovieData {
    void *movie;
    void *movie_controller;
    u32 field_0008;
    u32 field_000c;
    u32 field_0010;
    u32 field_0014;
    u32 field_0018;
    u32 field_001c;
    u32 field_0020;
} MovieData;

typedef struct MovieHeader {
    u32 field_0008;
    u32 field_000c;
    u32 field_0010;
    u32 field_0014;
    u32 field_0018;
    u32 field_001c;
    u32 field_0020;
} MovieHeader;

typedef struct MovieControllerVtable {
    u8 pad_0000[0xc];
    void (*field_000c)(void *self);
} MovieControllerVtable;

typedef struct MovieController {
    MovieControllerVtable *vtable;
} MovieController;

int fn_12_204DC(MovieModule_u2 *arg0) {
    MovieData *movie_data;
    void *movie;
    MovieController *movie_controller;
    int result;

    movie_data = (MovieData *)arg0->movie_data;
    movie = movie_data->movie;
    movie_controller = (MovieController *)movie_data->movie_controller;
    if (movie == 0) {
        return 0;
    }

    *(MovieHeader *)lbl_12_bss_6990 = *(MovieHeader *)((u8 *)movie_data + 8);

    result = fn_12_2B348();
    if (result != 1) {
        fn_8004CAC8(movie);
        result = 0;
    } else {
        ADXT_Stop(*(void **)arg0->movie_data);
        lbl_12_bss_7C64[128] = (u32)movie;
        result = 0;
    }

    movie_controller->vtable->field_000c(movie_controller);
    return result;
}
