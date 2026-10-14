/* Non-matching: best partial attempt (97.14% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_27884_Arg0 {
    u8 pad_0[0x1B30];
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
    u8 *p = (u8 *)movie + 0xd54;
    int *flag = (int *)((u8 *)movie + 0xda4);
    int state = I(movie, 0x2910);
    if (state < 0) return 0;
    if (*flag != 0) return 0;
    if (fn_12_332DC(state, I(movie, 0x2914), I(p, 0x20), I(p, 0x24)) != 0) return 0;
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
#pragma peephole off
static inline int check_state(void *data, int mode) {
    int result = 0;
    switch (I(data, 0x74)) {
    case 1: break;
    case 2:
        if (mode == 2 || mode == 3) result = 1;
        break;
    case 3:
        if (mode == 3) result = 1;
        break;
    case 4: break;
    }
    return result;
}
#pragma peephole reset
static inline int check_time(MovieModule *movie, int mode, void *data) {
    int time;
    int duration;
    u8 *p = (u8 *)movie + 0xcc0;
    MovieCallback callback;
    struct { int value; } state;
    int value;
    if (I(movie, 0xda4) == 0) time = 0;
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
int fn_12_27884(MovieModule *arg0, int *arg1) {
    int state;
    void *data;
    void *v0;
    void * data_2;
    int v4;
    int v3;
    int b;
    v0 = (void *)arg0->unk_1B30;
    if ((int)fn_12_2D73C((u8 *)arg0, 47) == 1) return 1;
    if ((int)fn_12_2D73C((u8 *)arg0, 39) == 1) return 0;
    if (U(v0, 0x130) != 0) return 0;
    v3 = I(v0, 0xa4);
    if (ready(arg0)) v4 = 1;
    else if (missing(arg0, v3)) v4 = 1;
    else if (check_input(arg0, arg1, v3)) v4 = 1;
    else {
        data = (void *)arg0->unk_1B30;
        if (check_state(data, v3)) v4 = 1;
        else if (check_time(arg0, v3, data)) v4 = 1;
        else v4 = 0;
    }
    data_2 = (void *)arg0->unk_1B30;
    state = I(data_2, 0x74);
    if (I(data_2, 0xe0) != 0) {
{
    int a;
        fn_12_A9C4(*(void **)data_2, &a, &b);
        if (a == 0 && b == 1) state = 2;
        if (a == 1) state = 5;
}
    }
    if (v4 == 1) {
        if (I(v0, 0xa4) == 1 || I(v0, 0xa4) == 2) state = 2;
    } else {
        if (state == 2) state = 3;
        else if (state == 3) state = 5;
    }
    I(data_2, 0x74) = state;
    return v4;
}
