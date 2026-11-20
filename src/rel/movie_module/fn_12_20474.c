#include "types.h"


/* --- rel/movie_module/fn_12_20474.c --- */
extern void ADXT_Pause(void *arg0, int arg1);
extern void fn_12_309B8(void *arg0, int arg1);

typedef struct MovieModule {
    u8 pad_0000[0x50];
    int field_0050;
    u8 pad_0054[0xf0c];
    u8 field_0f60[1];
    u8 pad_0f61[0xc13];
    void *field_1b74;
} MovieModule;

int fn_12_20474(MovieModule *arg0) {
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
