#include "types.h"


/* --- rel/movie_module/fn_12_2DA6C.c --- */
typedef struct MovieModule {
    u8 pad_0[0x48];
    u32 value;
} MovieModule;

extern int fn_12_24990(MovieModule *module);
extern void fn_12_24A88(int arg0, int arg1);

u32 fn_12_2DA6C(MovieModule *module);

/* --- rel/movie_module/fn_12_2DAB4.c --- */
typedef struct MovieModule_u1 {
    u8 pad_0[0xf28];
    int value;
} MovieModule_u1;

int fn_12_2DAB4(MovieModule_u1 *module) {
    return module->value;
}

/* --- rel/movie_module/fn_12_2DABC.c --- */
typedef struct MovieModule_u2 MovieModule_u2;
typedef void (*MovieCallback)(MovieModule_u2 *, int *, int *);

struct MovieModule_u2 {
    union {
        struct {
            u8 pad_0[0x94c];
            int field_94c;
            u8 pad_950[0x5a8];
            int field_ef8;
            int field_efc;
            u8 pad_f00[8];
            int field_f08;
            int field_f0c;
        } fields;
        struct {
            u8 pad_cc0[0xcc0];
            MovieCallback callbacks[16];
        } callback_data;
    } data;
};

extern void fn_12_24970(int *arg0);
extern int fn_12_2D73C(MovieModule_u2 *module, int arg0);
extern void fn_12_2E6AC(MovieModule_u2 *module, int *arg0, int *arg1);
extern void fn_12_24950(int *arg0);
extern int fn_12_332DC(int state, int time, int arg2, int arg3);

int fn_12_2DABC(MovieModule_u2 *module) {
    int work[3];
    int state;
    int time;
    int index;
    struct { MovieCallback value; } callback;

    state = module->data.fields.field_ef8;
    time = module->data.fields.field_efc;
    if (module->data.fields.field_94c == 0) {
        return 1;
    }
    if (state == -5) {
        return 0;
    }
    if (module->data.fields.field_f08 == -5) {
        fn_12_24970(&work[0]);
        index = fn_12_2D73C(module, 15);
        callback.value = module->data.callback_data.callbacks[index];
        if (callback.value == 0) {
            callback.value = fn_12_2E6AC;
        }
        callback.value(module, &work[2], &work[1]);
        fn_12_24950(&work[0]);
    } else {
        work[2] = module->data.fields.field_f08;
        work[1] = module->data.fields.field_f0c;
    }
    state += (time * 2000) / 59940;
    if (fn_12_332DC(state, time, work[2], work[1]) != 0) {
        return 1;
    }
    return 0;
}
