#include "types.h"


/* --- dol/fn_800583DC.c --- */
extern u32 fn_800576DC(void);
extern u32 fn_80057728(u32);

void fn_800583DC(u32 arg0) {
    fn_80057728(arg0);
    *(u32 *)((u8 *)arg0 + 12) = 0;
    *(u32 *)((u8 *)arg0 + 16) = *(u32 *)((u8 *)arg0 + 32);
    *(u32 *)((u8 *)arg0 + 20) = 0;
    *(u32 *)((u8 *)arg0 + 24) = 0;
    *(u32 *)((u8 *)arg0 + 40) = 0;
    *(u32 *)((u8 *)arg0 + 44) = 0;
    *(u32 *)((u8 *)arg0 + 48) = 0;
    *(u32 *)((u8 *)arg0 + 52) = 0;
    fn_800576DC();
}

/* --- dol/fn_80058434.c --- */
/* --- dol/fn_80058434.c --- */
struct fn_80058434_Arg0 {
    u8 pad_0[0x38];
    u32 unk_38;
    u32 unk_3C;
};

void fn_80058434(struct fn_80058434_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_38 = arg1;
    arg0->unk_3C = arg2;
}

/* --- dol/fn_80058440.c --- */
struct fn_80058440_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

u32 fn_80058440(struct fn_80058440_Arg0 *arg0) {
    return arg0->unk_8;
}

/* --- dol/fn_80058448.c --- */
extern u32 memset(u32, u32, u32);

u32 fn_80058448(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0, t1, t2;
    t0 = fn_80057728(arg0);
    v0 = t0;
    v1 = arg1;
    v2 = arg2;
    if (arg0 != 0) {
    v0 = arg0;
    v1 = 0;
    v2 = 64;
    t1 = memset(v0, v1, v2);
    v0 = t1;
    *(u32 *)((u8 *)arg0 + 4) = 0;
    }
    t2 = fn_800576DC();
    v0 = t2;
    return v0;
}
