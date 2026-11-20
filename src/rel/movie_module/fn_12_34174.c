#include "types.h"


/* --- rel/movie_module/fn_12_34174.c --- */
extern void fn_12_219E8(void *);

typedef struct MovieModule {
    u8 pad_00[0x40];
    void *field_40;
} MovieModule;

void fn_12_34174(MovieModule *self) {
    fn_12_219E8(self->field_40);
}

/* --- rel/movie_module/fn_12_34198.c --- */
extern void fn_12_21A64(void *);

void fn_12_34198(MovieModule *module) {
    fn_12_21A64(module->field_40);
}

/* --- rel/movie_module/fn_12_341BC.c --- */
// fn_12_341BC: empty in retail (single blr).
void fn_12_341BC(void) {
}

/* --- rel/movie_module/fn_12_341C0.c --- */
// fn_12_341C0: empty in retail (single blr).
void fn_12_341C0(void) {
}

/* --- rel/movie_module/fn_12_341C4.c --- */
extern void fn_8004EC14(void);

void fn_12_341C4(void) {
    fn_8004EC14();
}

/* --- rel/movie_module/fn_12_341E4.c --- */
typedef struct MovieState {
    u8 pad0[0x40];
    void *field40;
    u8 pad44[0x2c];
    s8 state70;
    s8 state71;
} MovieState;

extern int fn_12_3A36C(MovieState *movie);
extern char lbl_12_rodata_12E0[43];
extern void MWSFSVM_Error(const char *message, ...);
extern int fn_12_23280(void *value);
extern char lbl_12_rodata_130C[42];

void fn_12_341E4(MovieState *movie, int value) {
    if (fn_12_3A36C(movie) == 0) {
        MWSFSVM_Error(lbl_12_rodata_12E0);
    } else {
        void *field = movie->field40;

        if (movie->state70 == 1 && value == 0) {
            movie->state71 = 1;
        }
        if ((s8)movie->state70 == 0 && value == 1 &&
            fn_12_23280(field) != 0) {
            MWSFSVM_Error(lbl_12_rodata_130C);
        }
        movie->state70 = value;
    }
}

/* --- rel/movie_module/fn_12_3428C.c --- */
extern u32 fn_800567EC(u32);

struct fn_12_3428C_Arg0 {
    u8 pad_0[0x4C];
    u32 unk_4C;
};

void fn_12_3428C(struct fn_12_3428C_Arg0 *arg0) {
    if (arg0->unk_4C != 0) {
    fn_800567EC(arg0->unk_4C);
    }
}

/* --- rel/movie_module/fn_12_342B8.c --- */
extern u32 fn_80056C20(void);

u32 fn_12_342B8(void) {
    u32 t0;
    t0 = fn_80056C20();
    return ((u32)__cntlzw((3 - t0)) >> 5);
}
