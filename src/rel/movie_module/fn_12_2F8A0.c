#include "types.h"


/* --- rel/movie_module/fn_12_2F730.c --- */
/* --- rel/movie_module/fn_12_2F730.c --- */
typedef int (*movie_callback_fn)(void *, int, int, int);
typedef struct {
    void *unk_0;
    movie_callback_fn fn_4;
} movie_callback_t;

int fn_12_2F730(movie_callback_t **arg0);

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

int fn_12_2F7AC(movie_hook_table *arg0, movie_hook_table *arg1);

/* --- rel/movie_module/fn_12_2F8A0.c --- */
// fn_12_2F8A0: returns a constant.
int fn_12_2F8A0(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2F8A8.c --- */
extern void fn_12_24A88(void *arg0, int arg1);

void fn_12_2F8A8(void *arg0) {
    fn_12_24A88(arg0, 0xFF000601);
}

/* --- rel/movie_module/fn_12_2F8D0.c --- */
void fn_12_2F8D0(void *arg0) {
    fn_12_24A88(arg0, 0xFF000601);
}

/* --- rel/movie_module/fn_12_2F8F8.c --- */

void fn_12_2F8F8(void *arg) {
    fn_12_24A88(arg, 0xff000601);
}

/* --- rel/movie_module/fn_12_2F920.c --- */
/* --- rel/movie_module/fn_12_2F920.c --- */

void fn_12_2F920(void *arg0) {
    fn_12_24A88(arg0, 0xff000601u);
}

/* --- rel/movie_module/fn_12_2F948.c --- */
// fn_12_2F948: returns a constant.
int fn_12_2F948(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2F950.c --- */
// fn_12_2F950: returns a constant.
int fn_12_2F950(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2F958.c --- */
// fn_12_2F958: returns a constant.
int fn_12_2F958(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2F960.c --- */
// fn_12_2F960: returns a constant.
int fn_12_2F960(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_2F968.c --- */
// fn_12_2F968: returns a constant.
int fn_12_2F968(void) {
    return 0;
}
