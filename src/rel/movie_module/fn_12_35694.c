#include "types.h"


/* --- rel/movie_module/fn_12_35694.c --- */
extern u32 MWSFSVM_Error(u32, ...);
extern u32 fn_12_3A36C(u32);
extern u32 fn_12_8D4(u32);
extern u32 lbl_12_rodata_1934;

u32 fn_12_35694(u32 arg0) {
    u32 v0;
    u32 t0, t1, t2;
    t0 = fn_12_3A36C(arg0);
    v0 = t0;
    if ((s32)t0 == 0) {
    v0 = (u32)&lbl_12_rodata_1934;
    t1 = MWSFSVM_Error((u32)v0);
    v0 = t1;
    v0 = 0;
    } else {
    v0 = *(u32 *)((u8 *)arg0 + 168);
    t2 = fn_12_8D4(v0);
    v0 = t2;
    }
    return v0;
}

/* --- rel/movie_module/fn_12_356E8.c --- */
typedef struct MovieModuleState {
    u8 pad_a8[0xa8];
    void *value_a8;
} MovieModuleState;

extern void fn_12_8DC(void *);

void fn_12_356E8(MovieModuleState *self) {
    fn_12_8DC(self->value_a8);
}
