#include "types.h"


/* --- rel/movie_module/fn_12_2FB5C.c --- */
struct MovieModule {
    u8 pad_0x1c48[0x1c48];
    void *field_0x1c48;
};

extern void fn_12_21D70(struct MovieModule *, void *, void *);

void fn_12_2FB5C(struct MovieModule *module, void *arg) {
    fn_12_21D70(module, module->field_0x1c48, arg);
}

/* --- rel/movie_module/fn_12_2FB84.c --- */
typedef struct Sig_fn_12_2DEF0_MovieEntry {
    u8 pad_0[0x14];
    s32 value_14;
    s32 value_18;
} Sig_fn_12_2DEF0_MovieEntry;

struct fn_12_2FB84_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
};
extern int fn_12_21DD4(void *, int, int);
extern int fn_12_2DEF0(void *, Sig_fn_12_2DEF0_MovieEntry *);

s32 fn_12_2FB84(void *arg0, Sig_fn_12_2DEF0_MovieEntry **arg1) {
    s32 temp_r3;

    if ((u32) ((*(s32 *)((u8 *)(arg0) + 72)) - 3) > 1U) {
        (*(Sig_fn_12_2DEF0_MovieEntry **)((u8 *)(arg1) + 0)) = (Sig_fn_12_2DEF0_MovieEntry *)(NULL);
        return 0;
    }
    temp_r3 = fn_12_21DD4((void *)(arg0), *(s32 *)((u8 *)(arg0) + 7240), (s32)(arg1));
    if (temp_r3 != 0) {
        return temp_r3;
    }
    if (fn_12_2DEF0((void *)(arg0), (Sig_fn_12_2DEF0_MovieEntry *)(*(Sig_fn_12_2DEF0_MovieEntry **)((u8 *)(arg1) + 0))) == 0) {
        (*(Sig_fn_12_2DEF0_MovieEntry **)((u8 *)(arg1) + 0)) = (Sig_fn_12_2DEF0_MovieEntry *)(NULL);
        return 0;
    }
    return 0;
}

/* --- rel/movie_module/fn_12_2FC18.c --- */
extern void fn_12_24A88(int, int);

void fn_12_2FC18(int arg0) {
    fn_12_24A88(arg0, 0xff000701);
}
