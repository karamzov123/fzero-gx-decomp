#include "types.h"


/* --- rel/movie_module/fn_12_2B188.c --- */
extern int fn_12_24990(void);
extern void fn_12_24A88(int arg0, u32 arg1);
extern void fn_12_226D0(void *arg0, void *arg1);

void fn_12_2B188(void *arg0, void *arg1) {
    if (fn_12_24990()) {
        fn_12_24A88(0, 0xff000139);
    } else {
        fn_12_226D0(arg0, arg1);
    }
}

/* --- rel/movie_module/fn_12_2B1E8.c --- */
struct MovieModule {
    char pad_960[0x960];
    int value_960;
};

extern void fn_12_24A88(int value, u32 code);
extern void fn_12_2F210(struct MovieModule *module, int value, int size, void *data, int flags);

void fn_12_2B1E8(struct MovieModule *module, void *data) {
    if (fn_12_24990()) {
        fn_12_24A88(0, 0xff000137);
    } else {
        module->value_960 = 0;
        fn_12_2F210(module, 6, 12, data, 0);
    }
}
