#include "types.h"


/* --- rel/movie_module/fn_12_38D94.c --- */
/* --- rel/movie_module/fn_12_38D94.c --- */
extern void MWSFSVM_Error(void *, ...);

void fn_12_38D94(void *arg0, void *arg1) {
    MWSFSVM_Error(arg1);
}

/* --- rel/movie_module/fn_12_38DBC.c --- */
extern u32 lbl_12_bss_1BAAC[1131];

u32 *fn_12_38DBC(void) {
    return lbl_12_bss_1BAAC;
}

/* --- rel/movie_module/fn_12_38DC8.c --- */
typedef struct Sig_fn_12_3A384_Fn12_3A384_Object {
    u8 _pad[0x44];
    u32 value;
} Sig_fn_12_3A384_Fn12_3A384_Object;

struct fn_12_38DC8_Arg0 {
    u8 pad_0[0x134];
    u32 unk_134;
};
extern f64 lbl_12_rodata_24C8;
extern f64 lbl_12_rodata_24D0;
extern void fn_12_3A384(Sig_fn_12_3A384_Fn12_3A384_Object *, u32, u32);


void fn_12_38DC8(Sig_fn_12_3A384_Fn12_3A384_Object *arg0) {
    s32 temp_r5;

    temp_r5 = *(s32 *)((u8 *)(arg0) + 308);
    fn_12_3A384((Sig_fn_12_3A384_Fn12_3A384_Object *)(arg0), (u32)((u32) (s32) ((*(f64 *)((u8 *)(&lbl_12_rodata_24C8) + 0)) * (f64) temp_r5)), (u32)((u32) temp_r5));
}

/* --- rel/movie_module/fn_12_38E24.c --- */
typedef struct MovieVTable MovieVTable;
typedef struct Movie Movie;

struct MovieVTable {
    u8 pad[0x3c];
    void (*update)(Movie *, void *);
};

struct Movie {
    MovieVTable *vtable;
    u8 pad_004[0x10c];
    void *resource;
    u8 pad_114[4];
    u32 loaded;
    u32 value0;
    u32 value1;
    u32 value2;
};

extern int fn_12_3A36C(void *);
extern u8 lbl_12_rodata_24D8[128];
extern void *fn_12_39CA4(void *);
extern u8 lbl_12_rodata_2480[72];
extern int fn_8004F818(void *, void *, void *, u32 *, u32 *, u32 *);

void fn_12_38E24(Movie *movie, void *arg1, void *arg2) {
    u32 value0;
    u32 value2;
    u32 value1;

    if (fn_12_3A36C(movie) == 0) {
        MWSFSVM_Error(lbl_12_rodata_24D8);
    } else {
        movie->vtable->update(movie, fn_12_39CA4(movie));
        if (fn_8004F818(arg1, arg2, movie->resource, &value0, &value1, &value2) == 0) {
            movie->value0 = value0;
            movie->value1 = value1;
            movie->value2 = value2;
            movie->loaded = 1;
        } else {
            MWSFSVM_Error(lbl_12_rodata_2480);
        }
        movie->loaded = 1;
    }
}
