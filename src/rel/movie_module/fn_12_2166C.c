#include "types.h"


/* --- rel/movie_module/fn_12_215A4.c --- */
typedef struct MovieModule {
    u8 pad_0[0x1b74];
    void **movie;
} MovieModule;

extern void fn_8004BF68(void *);

void fn_12_215A4(MovieModule *this);

/* --- rel/movie_module/fn_12_215CC.c --- */
/* --- rel/movie_module/fn_12_215CC.c --- */
typedef struct MovieModule_u1 {
    u8 pad_0[0x1b74];
    void *field_1b74;
} MovieModule_u1;

extern void ADXT_SetOutPan(void *);

void fn_12_215CC(MovieModule_u1 *movie);

/* --- rel/movie_module/fn_12_215F4.c --- */
extern u32 lbl_12_rodata_A78;
extern u32 strncmp(u32, void *, u32);

struct fn_12_215F4_Arg2 {
    u32 unk_0;
};

u32 fn_12_215F4(u32 arg0, u32 arg1, struct fn_12_215F4_Arg2 *arg2);

/* --- rel/movie_module/fn_12_2166C.c --- */
// fn_12_2166C: returns a constant.
int fn_12_2166C(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_21674.c --- */
extern void fn_12_24A88(void *arg0, s32 arg1);

void fn_12_21674(void *arg0) {
    fn_12_24A88(arg0, (s32)0xff000a01);
}

/* --- rel/movie_module/fn_12_2169C.c --- */
/* --- rel/movie_module/fn_12_2169C.c --- */

void fn_12_2169C(void *arg0) {
    fn_12_24A88(arg0, 0xff000a01);
}

/* --- rel/movie_module/fn_12_216C4.c --- */
void fn_12_216C4(void *arg0) {
    fn_12_24A88(arg0, 0xFF000A01);
}
