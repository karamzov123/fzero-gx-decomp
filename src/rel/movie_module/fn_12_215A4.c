#include "types.h"


/* --- rel/movie_module/fn_12_215A4.c --- */
typedef struct MovieModule {
    u8 pad_0[0x1b74];
    void **movie;
} MovieModule;

extern void fn_8004BF68(void *);

void fn_12_215A4(MovieModule *this) {
    fn_8004BF68(*this->movie);
}

/* --- rel/movie_module/fn_12_215CC.c --- */
/* --- rel/movie_module/fn_12_215CC.c --- */
typedef struct MovieModule_u1 {
    u8 pad_0[0x1b74];
    void *field_1b74;
} MovieModule_u1;

extern void ADXT_SetOutPan(void *);

void fn_12_215CC(MovieModule_u1 *movie) {
    ADXT_SetOutPan(*(void **)movie->field_1b74);
}

/* --- rel/movie_module/fn_12_215F4.c --- */
extern u32 lbl_12_rodata_A78;
extern u32 strncmp(u32, void *, u32);

struct fn_12_215F4_Arg2 {
    u32 unk_0;
};

u32 fn_12_215F4(u32 arg0, u32 arg1, struct fn_12_215F4_Arg2 *arg2) {
    u32 v0;
    u32 t0;
    arg2->unk_0 = 288;
    v0 = arg0;
    if ((s32)arg1 < 288) {
    v0 = 0;
    } else {
    if (*(u8 *)((u8 *)v0 + 0) != 128) {
    v0 = 0;
    } else {
    if (*(u8 *)((u8 *)v0 + 1) != 0) {
    v0 = 0;
    } else {
    v0 += 282;
    t0 = strncmp(v0, &lbl_12_rodata_A78, 6);
    v0 = t0;
    v0 = ((u32)__cntlzw(v0) >> 5);
    }
    }
    }
    return v0;
}

/* --- rel/movie_module/fn_12_2166C.c --- */
// fn_12_2166C: returns a constant.
int fn_12_2166C(void);

/* --- rel/movie_module/fn_12_21674.c --- */
extern void fn_12_24A88(void *arg0, s32 arg1);

void fn_12_21674(void *arg0);

/* --- rel/movie_module/fn_12_2169C.c --- */
/* --- rel/movie_module/fn_12_2169C.c --- */

void fn_12_2169C(void *arg0);

/* --- rel/movie_module/fn_12_216C4.c --- */
void fn_12_216C4(void *arg0);
