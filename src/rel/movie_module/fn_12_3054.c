#include "types.h"


/* --- rel/movie_module/fn_12_3054.c --- */
extern void fn_12_2F04(void);

void fn_12_3054(void) {
    fn_12_2F04();
}

/* --- rel/movie_module/fn_12_3074.c --- */
// fn_12_3074: returns a constant.
int fn_12_3074(void) {
    return 17;
}

/* --- rel/movie_module/fn_12_307C.c --- */
extern u32 lbl_12_bss_C;

u32 fn_12_307C(void) {
    return lbl_12_bss_C;
}

/* --- rel/movie_module/fn_12_308C.c --- */
extern u32 lbl_12_bss_10[300];

u32 fn_12_308C(void) {
    return lbl_12_bss_10[5];
}

/* --- rel/movie_module/fn_12_309C.c --- */
typedef void (*Fn12Callback)(u32, u32);

void fn_12_309C(u32 a, u32 b, u32 c) {
    Fn12Callback callback;
    u32 count;
    u32 value;

    callback = (Fn12Callback)lbl_12_bss_10[2];
    count = lbl_12_bss_10[4];
    value = lbl_12_bss_10[3];
    lbl_12_bss_10[4] = count + 1;
    if (callback != 0) {
        callback(value, c);
    }
}

/* --- rel/movie_module/fn_12_30E8.c --- */
extern void fn_12_48A0(void *arg);
extern void fn_12_354C(void *arg);

typedef struct MovieModule {
    u32 field_00;
    u8 pad_04[0x1c];
    void *field_20;
    u8 pad_24[8];
    void *field_2c;
} MovieModule;

void fn_12_30E8(MovieModule *movie) {
    if (movie != 0) {
        void *arg0 = movie->field_20;
        void *arg1 = movie->field_2c;

        movie->field_00 = 0;
        fn_12_48A0(arg0);
        fn_12_354C(arg1);
        lbl_12_bss_10[0]--;
    }
}
