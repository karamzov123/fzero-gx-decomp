#include "types.h"

typedef struct MovieTimeCode {
    int valid;
    u8 pad_04[0x1C];
    int value;
    int scale;
} MovieTimeCode;
typedef struct MovieDecodeTimer {
    u8 pad_00[0x94];
    MovieTimeCode current;
    u8 pad_bc[0x28];
    MovieTimeCode output_start;
} MovieDecodeTimer;
struct fn_12_27884_Arg0 {
    u8 pad_0[0xCC0];
    MovieDecodeTimer timer;
    u8 pad_dcc[0x1B30 - 0xDCC];
    u32 unk_1B30;
};
typedef struct fn_12_27884_Arg0 MovieModule;
#define I(p, o) (*(int *)((u8 *)(p) + (o)))
#define U(p, o) (*(u32 *)((u8 *)(p) + (o)))
extern int fn_12_332DC(int, int, int, int);
extern u32 fn_12_2D73C(u8 *, int);
extern int fn_12_A374(int, int, int);
extern void fn_12_2EDAC(void *, int);
extern int fn_12_2ED74(void *, int);
extern int fn_12_2DAB4(MovieModule *);
extern int fn_12_2E714(MovieModule *, int *, int *);
extern int fn_12_A9C4(void *, int *, int *);
typedef int (*MovieCallback)(MovieModule *, int, int, int);

static inline int ready(MovieModule *movie) {
    MovieDecodeTimer *timer = &movie->timer;
    MovieTimeCode *current = &timer->current;
    MovieTimeCode *output_start = &timer->output_start;
    if (I(movie, 0x2910) < 0) return 0;
    if (output_start->valid != 0) return 0;
    if (fn_12_332DC(I(movie, 0x2910), I(movie, 0x2914), current->value, current->scale) != 0) return 0;
    return 1;
}
#pragma peephole off
static inline int missing(MovieModule *movie, int mode) {
    int value;
    switch (mode) {
    case 1: value = I(movie, 0x9a8); break;
    case 2: value = I(movie, 0x9ac); break;
    case 3: value = I(movie, 0x9b0); break;
    default: return 1;
    }
    if (value == 0) return 1;
    return 0;
}
#pragma peephole reset

static inline int check_input(MovieModule *movie, int *input, int mode) {
    int result;
    if (mode != 3) return 0;
    if ((int)fn_12_2D73C((u8 *)movie, 7) != 0) return 0;
    result = fn_12_A374(input[0], input[1], I(movie, 0x914) * I(movie, 0x918));
    if (0 != result) I(movie, 0x95c)++;
    return result;
}
static inline int check_state(MovieModule *movie, int mode) {
    void *work = (void *)movie->unk_1B30;
    int state = I(work, 0x74);
    int result = 0;
    switch (state) {
    case 2:
        if (mode == 2 || mode == 3) result = 1;
        break;
    case 3:
        if (mode == 3) result = 1;
        break;
    case 4:
        result = 0;
        break;
    case 5:
    default:
        break;
    }
    return result;
}
static inline int check_time(MovieModule *movie, int mode) {
    void *data = (void *)movie->unk_1B30;
    int time;
    int duration;
    u8 *p = (u8 *)movie + 0xcc0;
    MovieCallback callback;
    struct { int value; } state;
    int value;
    if (I(p, 0xe4) == 0) time = 0;
    else time = I(p, 0x120) + (I(p, 0xb4) - I(p, 0x104));
    callback = *(MovieCallback *)(p + 0x18);
    duration = I(p, 0xb8);
    if (callback != 0) return callback(movie, mode, time, duration);
    if (mode == 1) fn_12_2EDAC(p, time);
    if (mode == 1 || mode == 2) time = fn_12_2ED74(p, time);
    if (fn_12_2DAB4(movie) <= 1000 && I(data, 0x84) >= I(movie, 0xa38)) return 0;
    fn_12_2E714(movie, &state.value, &value);
    if (state.value < 0) return 0;
    time -= duration * I(movie, 0xa48) / I(movie, 0xa4c);
    if (fn_12_332DC(state.value, value, time, duration) != 0) return 0;
    I(data, 0x84)++;
    return 1;
}
static inline void update_pic_stat(MovieModule *movie, void *v0, int skip) {
    void *work = (void *)movie->unk_1B30;
    void *decoder = *(void **)work;
    int state = I(work, 0x74);
    if (I(work, 0xe0) != 0) {
        int a;
        int b;
        fn_12_A9C4(decoder, &a, &b);
        if (a == 0 && b == 1) state = 2;
        if (a == 1) state = 5;
    }
    if (skip == 1) {
        if (I(v0, 0xa4) == 1 || I(v0, 0xa4) == 2) state = 2;
    } else {
        if (state == 2) state = 3;
        else if (state == 3) state = 5;
    }
    I(work, 0x74) = state;
}

#pragma opt_propagation off
int fn_12_27884(MovieModule *arg0, int *arg1) {
    void *v0;
    int v4;
    int v3;
    v0 = (void *)arg0->unk_1B30;
    if ((int)fn_12_2D73C((u8 *)arg0, 47) == 1) return 1;
    if ((int)fn_12_2D73C((u8 *)arg0, 39) == 1) return 0;
    if (U(v0, 0x130) != 0) return 0;
    v3 = I(v0, 0xa4);
    if (ready(arg0)) v4 = 1;
    else if (missing(arg0, v3)) v4 = 1;
    else if (check_input(arg0, arg1, v3)) v4 = 1;
    else if (check_state(arg0, v3)) v4 = 1;
    else if (check_time(arg0, v3)) v4 = 1;
    else v4 = 0;
    update_pic_stat(arg0, v0, v4);
    return v4;
}
#pragma opt_propagation reset
