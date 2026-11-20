#include "types.h"


/* --- rel/movie_module/fn_12_35060.c --- */
typedef struct MovieModule {
    u8 pad[0xa8];
    void *field_a8;
} MovieModule;

extern void fn_12_49EC(void *);

void fn_12_35060(MovieModule *self) {
    fn_12_49EC(self->field_a8);
}

/* --- rel/movie_module/fn_12_35084.c --- */
extern void fn_12_758(void *, int *, int *, int *);

void fn_12_35084(MovieModule *self, int *out_a, int *out_b, int *out_c) {
    int value_a;
    int value_b;
    int value_c;

    fn_12_758(self->field_a8, &value_a, &value_b, &value_c);
    if (value_c == 1) {
        *out_c = 1;
    } else {
        *out_c = 0;
    }
    *out_a = value_a;
    *out_b = value_b;
}

/* --- rel/movie_module/fn_12_35108.c --- */
extern u32 fn_12_77C(u32, u32, u32, u32);

struct fn_12_35108_Arg0 {
    u8 pad_0[0xA8];
    u32 unk_A8;
};

void fn_12_35108(struct fn_12_35108_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    fn_12_77C(arg0->unk_A8, arg1, arg2, ((u32)__cntlzw((1 - arg3)) >> 5));
}

/* --- rel/movie_module/fn_12_35138.c --- */
extern void fn_12_7A0(void *arg);

void fn_12_35138(MovieModule *self) {
    fn_12_7A0(self->field_a8);
}
