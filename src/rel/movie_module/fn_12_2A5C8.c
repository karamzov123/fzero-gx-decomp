#include "types.h"


/* --- rel/movie_module/fn_12_2A5C8.c --- */
extern int fn_12_24990(void *arg0, int arg1);
extern int fn_12_24A88(int arg0, u32 arg1);
extern int fn_12_CAE4(int arg0, int arg1, int arg2);

typedef struct MovieModule {
    unsigned char _pad[0x1b30];
    void *field_1b30;
} MovieModule;

int fn_12_2A5C8(MovieModule *arg0, int arg1, int arg2) {
    int result;

    if (arg0 == 0) {
        result = 0;
    } else if (fn_12_24990(arg0, arg1)) {
        return fn_12_24A88(0, 0xff000181);
    } else {
        result = *(int *)arg0->field_1b30;
    }

    if (arg1 == 5) {
        arg2 = 0;
    }
    if (fn_12_CAE4(result, arg1, arg2)) {
        return fn_12_24A88((int)arg0, 0xff000f12);
    }
    return 0;
}

/* --- rel/movie_module/fn_12_2A674.c --- */
typedef struct MovieSize {
    s32 value0;
    s32 value1;
    s32 value2;
    s16 value3;
    s16 value4;
} MovieSize;

void fn_12_2A674(int arg0, int arg1, int arg2, MovieSize *out) {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;

    a = (arg1 + 15) / 16;
    b = a << 4;
    c = (b + 31) / 32;
    d = b / 2;
    e = (d + 31) / 32;
    out->value4 = c << 5;
    out->value3 = e << 5;
    f = (arg2 + 15) / 16;
    g = f << 4;
    h = g / 2;
    out->value2 = arg0;
    out->value0 = out->value2 + g * (c << 5);
    out->value1 = out->value0 + h * (e << 5);
}
