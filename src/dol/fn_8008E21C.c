#include "types.h"


/* --- dol/fn_8008E21C.c --- */
/* --- dol/fn_8008E21C.c --- */
struct Sig_fn_8008E718_fn_8008E718_Arg0 {
    u32 unk_0;
};

struct fn_8008E21C_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_c;
    u32 unk_10;
    u32 unk_14;
};

extern u32 memcpy(u32, u32, u32);
extern void fn_8008E718(struct Sig_fn_8008E718_fn_8008E718_Arg0 *);
extern void fn_8008E73C(u32);

s32 fn_8008E21C(struct fn_8008E21C_Arg0 *arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    if (arg2 > arg0->unk_14) {
        v0 = -1;
    } else {
        fn_8008E73C((u32)arg0 + 24);
        v1 = arg0->unk_c - (arg0->unk_4 - arg0->unk_8);
        if (v1 >= arg2) {
            memcpy(arg0->unk_4, arg1, arg2);
            arg0->unk_4 += arg2;
        } else {
            memcpy(arg0->unk_4, arg1, v1);
            memcpy(arg0->unk_8, arg1 + v1, arg2 - v1);
            arg0->unk_4 = arg0->unk_8 + arg2 - v1;
        }
        v2 = arg0->unk_8;
        v0 = arg0->unk_c;
        if (v0 == arg0->unk_4 - v2) {
            arg0->unk_4 = v2;
        }
        arg0->unk_14 -= arg2;
        arg0->unk_10 += arg2;
        fn_8008E718((struct Sig_fn_8008E718_fn_8008E718_Arg0 *)((u8 *)arg0 + 24));
        v0 = 0;
    }
    return v0;
}

/* --- dol/fn_8008E324.c --- */
extern u32 fn_8008E76C(u32, u32, u32);

struct fn_8008E324_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

void fn_8008E324(struct fn_8008E324_Arg0 *arg0, u32 arg1, u32 arg2) {
    u32 v0;
    arg0->unk_8 = arg1;
    *(u32 *)((u8 *)(u32)arg0 + 12) = arg2;
    *(u32 *)((u8 *)(u32)arg0 + 0) = *(u32 *)((u8 *)(u32)arg0 + 8);
    v0 = *(u32 *)((u8 *)(u32)arg0 + 8);
    *(u32 *)((u8 *)(u32)arg0 + 4) = v0;
    *(u32 *)((u8 *)(u32)arg0 + 16) = 0;
    *(u32 *)((u8 *)(u32)arg0 + 20) = *(u32 *)((u8 *)(u32)arg0 + 12);
    fn_8008E76C(((u32)arg0 + 24), v0, arg2);
}

/* --- dol/fn_8008E374.c --- */
struct fn_8008E374_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};

u32 fn_8008E374(struct fn_8008E374_Arg0 *arg0) {
    return arg0->unk_10;
}
