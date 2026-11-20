#include "types.h"


/* --- rel/movie_module/fn_12_2E374.c --- */
typedef u32 (*fn_12_2E374_Fn0)(u32, u32, u32, u32);

extern u32 lbl_12_rodata_E10;
extern u32 lbl_12_rodata_E34;
extern void fn_12_24A88(void *, int);

void fn_12_2E374(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t1;
    v0 = *(u32 *)((u8 *)arg0 + 0);
    v1 = (v0 << 3);
    v2 = (v0 << 2);
    v3 = *(u32 *)((u8 *)&lbl_12_rodata_E10 + v2);
    if (*(u32 *)((u8 *)((u8 *)&lbl_12_rodata_E34 + v1) + (*(u32 *)((u8 *)arg0 + 4) << 2)) == 0) {
    v3 = 0;
    fn_12_24A88((void *)v3, (0xFF000000 + 545));
    v3 = 0;
    *(u32 *)((u8 *)arg1 + 0) = v3;
    *(u32 *)((u8 *)arg2 + 0) = 1;
    } else {
    t1 = ((fn_12_2E374_Fn0)*(u32 *)((u8 *)((u8 *)&lbl_12_rodata_E34 + v1) + (*(u32 *)((u8 *)arg0 + 4) << 2)))(v3, arg0, arg1, arg2);
    v3 = t1;
    }
}

/* --- rel/movie_module/fn_12_2E41C.c --- */
typedef struct MovieModuleEntry {
    u8 padding[0xcc0];
    s32 value;
} MovieModuleEntry;

void fn_12_2E41C(MovieModuleEntry *base, s32 value, s32 index) {
    base = (MovieModuleEntry *)((u8 *)base + (index << 2));
    base->value = value;
}

/* --- rel/movie_module/fn_12_2E42C.c --- */
extern void fn_12_332DC(void);

void fn_12_2E42C(void) {
    fn_12_332DC();
}

/* --- rel/movie_module/fn_12_2E44C.c --- */
struct fn_12_2E44C_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
};
struct fn_12_2E44C_Arg1 {
    u32 unk_0;
};
struct fn_12_2E44C_Arg2 {
    u32 unk_0;
};

s32 fn_12_2E44C(struct fn_12_2E44C_Arg0 *arg0, struct fn_12_2E44C_Arg1 *arg1, struct fn_12_2E44C_Arg2 *arg2) {
    u32 v0;
    u32 v1;
    v0 = arg0->unk_48;
    v1 = (u32)arg0;
    if ((s32)v0 != 4) {
    if ((s32)v0 != -4) {
    if ((s32)v0 != 6) {
    if ((s32)v0 != -6) {
    v1 = -1;
    arg1->unk_0 = v1;
    v1 = 0;
    arg2->unk_0 = 1;
    return v1;
    }
    }
    }
    }
    v1 = 1;
    return v1;
}
