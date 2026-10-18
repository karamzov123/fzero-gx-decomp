#include "types.h"

typedef int (*movie_callback_fn)(void *, int, int, int);
typedef struct {
    void *unk_0;
    movie_callback_fn fn_4;
} movie_callback_t;

int fn_12_2F730(movie_callback_t **arg0) {
    struct { int result; int i; } fzgx_copy_state;
    movie_callback_t ** p;
    fzgx_copy_state.result = 0;
    p = arg0;
    fzgx_copy_state.i = fzgx_copy_state.result;
    do {
        movie_callback_t *entry = *p;
        if (entry == 0) {
            break;
        }
        fzgx_copy_state.result = entry->fn_4(0, 0, 0, 0);
        if (fzgx_copy_state.result != 0) {
            break;
        }
        fzgx_copy_state.i++;
        p++;
    } while (fzgx_copy_state.i < 15);
    return fzgx_copy_state.result;
}
