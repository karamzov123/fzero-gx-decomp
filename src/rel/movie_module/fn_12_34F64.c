#include "types.h"


/* --- rel/movie_module/fn_12_34F64.c --- */
extern void fn_8004B1DC(void);

void fn_12_34F64(void) {
    fn_8004B1DC();
}

/* --- rel/movie_module/fn_12_34F84.c --- */
extern void fn_8004B4E0(int, int);

void fn_12_34F84(int arg) {
    fn_8004B4E0(arg, 0);
}

/* --- rel/movie_module/fn_12_34FA8.c --- */
extern void fn_8004A550(void *);

void fn_12_34FA8(void *arg) {
    if (arg != 0) {
        fn_8004A550(arg);
    }
}

/* --- rel/movie_module/fn_12_34FD0.c --- */
extern u32 fn_8004AEE4(void);

u32 fn_12_34FD0(void) {
    u32 t0;
    t0 = fn_8004AEE4();
    return ((u32)__cntlzw((4 - t0)) >> 5);
}

/* --- rel/movie_module/fn_12_34FFC.c --- */
// fn_12_34FFC: returns a constant.
int fn_12_34FFC(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_35004.c --- */
// fn_12_35004: returns a constant.
int fn_12_35004(void) {
    return 0;
}

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
