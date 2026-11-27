#include "types.h"
#pragma dont_inline on

/* --- rel/movie_module/fn_12_3500C.c --- */
// fn_12_3500C: empty in retail (single blr).
void fn_12_3500C(void) {
}

/* --- rel/movie_module/fn_12_35010.c --- */
// fn_12_35010: empty in retail (single blr).
void fn_12_35010(void) {
}

/* --- rel/movie_module/fn_12_35014.c --- */
// fn_12_35014: empty in retail (single blr).
void fn_12_35014(void) {
}

/* --- rel/movie_module/fn_12_35018.c --- */
typedef struct MovieModule {
    u8 pad_a8[0xa8];
    void *field_a8;
} MovieModule;

extern void fn_12_49AC(void *);

void fn_12_35018(MovieModule *self) {
    fn_12_49AC(self->field_a8);
}

/* --- rel/movie_module/fn_12_3503C.c --- */
extern void fn_12_4980(void *);

struct Fn12_3503C_Context {
    u8 pad_a8[0xa8];
    void *field_a8;
};

void fn_12_3503C(struct Fn12_3503C_Context *self) {
    fn_12_4980(self->field_a8);
}
