#include "types.h"


/* --- dol/fn_80050F64.c --- */
// fn_80050F64: returns a constant.
int fn_80050F64(void) {
    return 96;
}

/* --- dol/fn_80050F6C.c --- */
// fn_80050F6C: returns a constant.
int fn_80050F6C(void) {
    return 16;
}

/* --- dol/fn_80050F74.c --- */
struct fn_80050F74_Arg0 {
    u8 pad_0[0x345];
    u8 unk_345;
};

u32 fn_80050F74(struct fn_80050F74_Arg0 *arg0) {
    u32 v0;
    v0 = (u32)arg0;
    if ((s8)arg0->unk_345 == 0) {
    v0 = 0;
    return v0;
    }
    v0 = *(u32 *)((u8 *)v0 + 904);
    return v0;
}
