#include "types.h"

/* --- rel/movie_module/fn_12_3412C.c --- */
/* --- rel/movie_module/fn_12_340D4.c --- */
typedef struct MovieModule {
    u8 pad_00[0x54];
    void *field_54;
} MovieModule;

extern int fn_12_3A36C(MovieModule *, void *);
extern char lbl_12_rodata_12B0[46];
extern void MWSFSVM_Error(char *, ...);

void fn_12_340D4(MovieModule *self, void *value);

/* --- rel/movie_module/fn_12_3412C.c --- */
extern void fn_12_21AE4(void *);

typedef struct MovieModule_u1 {
    u8 pad_00[0x40];
    void *field_40;
} MovieModule_u1;

void fn_12_3412C(MovieModule_u1 *self) {
    fn_12_21AE4(self->field_40);
}

/* --- rel/movie_module/fn_12_34150.c --- */
typedef struct MovieModule_u2 {
    u8 pad[0x40];
    void *movie;
} MovieModule_u2;

extern void fn_12_21B70(void *movie);

void fn_12_34150(MovieModule_u2 *module) {
    fn_12_21B70(module->movie);
}

/* --- rel/movie_module/fn_12_34174.c --- */
/* --- rel/movie_module/fn_12_34174.c --- */
extern void fn_12_219E8(void *);


void fn_12_34174(MovieModule_u1 *self) {
    fn_12_219E8(self->field_40);
}

/* --- rel/movie_module/fn_12_34198.c --- */
extern void fn_12_21A64(void *);

void fn_12_34198(MovieModule_u1 *module) {
    fn_12_21A64(module->field_40);
}

/* --- rel/movie_module/fn_12_341BC.c --- */
// fn_12_341BC: empty in retail (single blr).
void fn_12_341BC(void);

/* --- rel/movie_module/fn_12_341C0.c --- */
// fn_12_341C0: empty in retail (single blr).
void fn_12_341C0(void);

/* --- rel/movie_module/fn_12_341C4.c --- */
extern void fn_8004EC14(void);

void fn_12_341C4(void);

/* --- rel/movie_module/fn_12_341E4.c --- */
typedef struct MovieState {
    u8 pad0[0x40];
    void *field40;
    u8 pad44[0x2c];
    s8 state70;
    s8 state71;
} MovieState;

extern char lbl_12_rodata_12E0[43];
extern int fn_12_23280(void *value);
extern char lbl_12_rodata_130C[42];

void fn_12_341E4(MovieState *movie, int value);

/* --- rel/movie_module/fn_12_3428C.c --- */
extern u32 fn_800567EC(u32);

struct fn_12_3428C_Arg0 {
    u8 pad_0[0x4C];
    u32 unk_4C;
};

void fn_12_3428C(struct fn_12_3428C_Arg0 *arg0);

/* --- rel/movie_module/fn_12_342B8.c --- */
extern u32 fn_80056C20(void);

u32 fn_12_342B8(void);
