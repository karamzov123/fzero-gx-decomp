/* Non-matching: best partial attempt (98.89% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
extern f64 lbl_12_rodata_60[12];
typedef struct MovieState {
    int pad0;
    int value;
    int width;
    int height;
} MovieState;
typedef struct MovieData {
    int mode;
    int value;
    int width;
    int height;
    int pad10;
    int field14;
    int field18;
    int pad1c;
    int pad20;
    int field24;
    int field28;
} MovieData;
typedef struct MovieArgs {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int pad[4];
} MovieArgs;
extern int fn_12_3074(MovieData *, void *);
extern void fn_12_309C(MovieState *, MovieData *, void *);
extern void fn_12_3C17C(MovieArgs *, int, void *, int, int);
void fn_12_D88(MovieState *state, MovieData *data, int arg, void *arg3) {
    u32 lab_v;
    int half;
    int height;
    int width;
    MovieArgs local;
    struct { char *value; } pool;
    int value;
    pool.value = (char *)lbl_12_rodata_60;
    value = data->mode;
    if (state->value == 0) {
        state->value = fn_12_3074(data, ((0x60) + (pool.value)));
    }
    switch (value) {
    case 3:
        switch (state->value) {
        case 0x11:
        case 0x101:
            local.a = data->value;
            local.b = data->field14;
            local.c = data->field24;
            local.d = data->width;
            local.e = data->field18;
            local.f = data->field28;
            width = state->width == 0 ? data->width : state->width;
            height = state->height;
            if (height == 0) {
                height = data->height;
            }
            switch (state->value) {
            case 0x11:
            case 0x31:
            case 0x41:
            case 0xf1:
            case 0x1001:
                half = 0;
                (void) half;  /* fzgx: keeps the web at its definition */
                break;
            case 0x21:
            case 0x101:
                half = 1;
                break;
            default:
                fn_12_309C(0, 0, pool.value);
                half = 0;
                break;
            }
            if (half == 1) {
                height /= 2;
            }
            fn_12_3C17C(&local, arg, arg3, width, height);
            break;
        case 0x21:
        case 0x31:
        case 0x41:
        case 0xf1:
        case 0x1001:
        default:
            fn_12_309C(state, data, ((0x1c8) + (pool.value)));
            break;
        }
        break;
    case 1:
    case 2:
    default:
        fn_12_309C(state, data, ((0x1f8) + (pool.value)));
        break;
    }
}
