#include "types.h"


/* --- rel/movie_module/fn_12_2DEF0.c --- */
typedef struct MovieEntry {
    u8 pad_0[0x14];
    s32 value_14;
    s32 value_18;
} MovieEntry;

extern int fn_12_2DEB0(void *arg0, s32 value_14, s32 value_18);

int fn_12_2DEF0(void *arg0, MovieEntry *entry) {
    if (entry == 0) {
        return 0;
    }
    return fn_12_2DEB0(arg0, entry->value_14, entry->value_18);
}

/* --- rel/movie_module/fn_12_2DF28.c --- */
extern u32 fn_12_24990(u32, u32);
extern u32 fn_12_24A88(u32, u32);
extern u32 lbl_12_rodata_E10;

struct fn_12_2DF28_Arg1 {
    u32 unk_0;
};

s32 fn_12_2DF28(u32 arg0, struct fn_12_2DF28_Arg1 *arg1) {
    u32 v0;
    u32 v1;
    u32 t0, t1;
    arg1->unk_0 = -1;
    t0 = fn_12_24990(arg0, (u32)arg1);
    v0 = t0;
    if ((s32)t0 != 0) {
    v0 = 0;
    t1 = fn_12_24A88(v0, (0xFF000000 + 283));
    v0 = t1;
    } else {
    v1 = *(u32 *)((u8 *)arg0 + 2336);
    if ((s32)v1 == 0) {
    v0 = 0;
    } else {
    v0 = 0;
    *(u32 *)((u8 *)(u32)arg1 + 0) = *(u32 *)((u8 *)&lbl_12_rodata_E10 + (v1 << 2));
    }
    }
    return v0;
}
