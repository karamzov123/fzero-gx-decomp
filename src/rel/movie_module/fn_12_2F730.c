#include "types.h"


/* --- rel/movie_module/fn_12_2F730.c --- */
/* --- rel/movie_module/fn_12_2F730.c --- */
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

/* --- rel/movie_module/fn_12_2F7AC.c --- */
typedef struct {
    int (*m_callback)(int, int, int, int);
} movie_object;

typedef struct {
    movie_object *m_objs[15];
} movie_hook_table;

typedef struct {
    int result;
    int index;
} loop_state;

int fn_12_2F7AC(movie_hook_table *arg0, movie_hook_table *arg1) {
    loop_state s;
    movie_object **table = arg1->m_objs;

    s.result = 0;
    s.index = s.result;
    *arg0 = *arg1;
    do {
        movie_object *obj = *table;
        if (obj == NULL) {
            break;
        }
        s.result = obj->m_callback(0, 0, 0, 0);
        if (s.result != 0) {
            break;
        }
        s.index++;
        table++;
    } while (s.index < 15);
    return s.result;
}

/* --- rel/movie_module/fn_12_2F8A0.c --- */
// fn_12_2F8A0: returns a constant.
int fn_12_2F8A0(void);

/* --- rel/movie_module/fn_12_2F8A8.c --- */
extern void fn_12_24A88(void *arg0, int arg1);

void fn_12_2F8A8(void *arg0);

/* --- rel/movie_module/fn_12_2F8D0.c --- */
void fn_12_2F8D0(void *arg0);

/* --- rel/movie_module/fn_12_2F8F8.c --- */

void fn_12_2F8F8(void *arg);

/* --- rel/movie_module/fn_12_2F920.c --- */
/* --- rel/movie_module/fn_12_2F920.c --- */

void fn_12_2F920(void *arg0);

/* --- rel/movie_module/fn_12_2F948.c --- */
// fn_12_2F948: returns a constant.
int fn_12_2F948(void);

/* --- rel/movie_module/fn_12_2F950.c --- */
// fn_12_2F950: returns a constant.
int fn_12_2F950(void);

/* --- rel/movie_module/fn_12_2F958.c --- */
// fn_12_2F958: returns a constant.
int fn_12_2F958(void);

/* --- rel/movie_module/fn_12_2F960.c --- */
// fn_12_2F960: returns a constant.
int fn_12_2F960(void);

/* --- rel/movie_module/fn_12_2F968.c --- */
// fn_12_2F968: returns a constant.
int fn_12_2F968(void);
