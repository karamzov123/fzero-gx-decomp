#include "types.h"


/* --- dol/fn_8007A23C.c --- */
extern u32 deallocate_from_fixed_pools(u32, u32);
extern u32 fn_8007A710(u32, u32);

void fn_8007A23C(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    if (arg1 != 0) {
    v0 = *(u32 *)((u8 *)arg1 + -4);
    v1 = v0;
    if ((v0 & 0x1) == 0) {
    v1 = *(u32 *)((u8 *)v1 + 8);
    } else {
    v1 = (*(u32 *)((u8 *)arg1 + -8) & ~0x7);
    v1 -= 8;
    }
    if (v1 <= 68) {
    deallocate_from_fixed_pools(arg0, arg1);
    } else {
    fn_8007A710(arg0, arg1);
    }
    }
}

/* --- dol/fn_8007A294.c --- */
extern u32 fn_8007A440(u32, u32);
extern u32 fn_8007AA7C(void);

u32 fn_8007A294(u32 arg0, u32 arg1) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if (arg1 == 0) {
    v0 = 0;
    } else {
    if (arg1 > (u32)-49) {
    v0 = 0;
    } else {
    if (arg1 <= 68) {
    t0 = fn_8007A440(v0, arg1);
    v0 = t0;
    } else {
    t1 = fn_8007AA7C();
    v0 = t1;
    }
    }
    }
    return v0;
}
